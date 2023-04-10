#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../encryption.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

// end of transmission in case input exceeds 1024 chars so it's possible to know where the input ends.
constexpr char endoftransmission {static_cast<char>(4)};

// Simple client/server program. Sender encrypts and sends a single buffer which is then received, decrypted and logged by the receiver.
// Needs to be reworked to handle input larger than 1024 chars but for now it's working as intended. If input is larger than 1024 there is loss of information
// both the client and the server need to input the same key in order for the messages to be decrypted

#define long int
std::ostringstream receive(const std::string& message, std::string key)
{
    const int nchar = 2*sizeof(long);    // 64 bits
    const int kchar = 2*nchar;           // 128 bits

    while (key.size()<kchar) key += '0'; // pad key
    std::istringstream inf(message);
    std::ostringstream outf;
    if (!inf || !outf) std::runtime_error("bad file name");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];    
    char outbuf[nchar+1];
    outbuf[nchar]=0; // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(std::ios_base::hex ,std::ios_base::basefield); // use hexadecimal input

    while (inf>>inptr[0]>>inptr[1]) {
        decipher(inptr,outptr,k);
        outf<<outbuf;
    }
    return outf;
}
#undef long

int main()
{
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSock < 0)
        throw std::runtime_error("Error: Unable to create socket");

    int port = 80000; // 80000 seems like a good default choice. 

    // set up address structure
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);

    // bind the socket to the address and port
    if (bind(serverSock, (struct sockaddr*)&serverAddress,sizeof(serverAddress))<0)
        throw std::runtime_error("Error: could not bind socket to port");

    // listen for incoming connections
    if (listen(serverSock, 5)<0)
        throw std::runtime_error("Error: could not listen on socket");

    std::string key;
    std::cout << "Please input the key for decryption:";
    if(!(std::cin >> key)) throw std::runtime_error("Wrong input");

    std::ofstream log_file("receiver_log_file.txt",std::ios_base::app);
    
    std::cout << "Server listening on port " << port << std::endl;

    // accept incoming connections and handle them
    while (true)
    {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressSize = sizeof(clientAddress);
        int clientSock = accept(serverSock, (struct sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSock < 0)
        {
            std::cerr << "Error: could not accept incoming connection" << std::endl;
            continue;
        }
        
        // receive a message from the client
        char buffer[1024];
        int numBytes = recv(clientSock, buffer, sizeof(buffer),0);
        if (numBytes < 0)
        {
            std::cerr << "Error: could not receive message from client" << std::endl;
            continue;
        }

        // print the message received from the client

        // check if buffer is the the last of the message
        auto arrayIter {std::find(std::begin(buffer),std::end(buffer),endoftransmission)};
        if(arrayIter!=std::end(buffer))
        { 
            *arrayIter=' ';
        }
        
        buffer[numBytes] = '\0';
        std::ostringstream oss = receive(buffer,key);

        // log the contents to the file

        auto current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char time_string[100];
        std::strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", std::localtime(&current_time));
        log_file << time_string << " - " << oss.str() << std::endl;

        std::cout << "Message received from client and logged to file." << std::endl;

        std::string response = "OK!";

        // send a response from the server
        if (send(clientSock, response.c_str(),response.length(),0)<0)
        {
            std::cerr << "Error: could not send response to client"<<std::endl;
            continue;
        }
        
        // close the connection to the client
        close(clientSock);
    }

    //  close the server socket
    close(serverSock);
    // close the log file
    log_file.close();
}