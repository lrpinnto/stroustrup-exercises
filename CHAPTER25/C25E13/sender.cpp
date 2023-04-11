#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../encryption.h"
#include <iomanip>
#include <sstream>

// Use TEA (25.5.6) to communicate "securely" between 2 computers

// end of transmission in case input exceeds 1024 chars so it's possible to know where the input ends.
constexpr char endoftransmission {static_cast<char>(4)};  // To be added at the end of every output

// Simple client/server program. Sender encrypts and sends a message which is then received, decrypted and logged by the receiver.
// both the client and the server need to input the same key in order for the messages to be decrypted

#define long int
std::ostringstream send()
{
    const int nchar = 2*sizeof(long);    // 64 bits
    const int kchar = 2*nchar;           // 128 bits

    std::string key;
    std::string input;

    std::cout<<"Please input a secure key (no spaces), if left blank it will generate a random 10 char key for you: ";
    char c;
    if(!(std::cin.get(c))) throw std::runtime_error("Wrong input");
    if(std::isalpha(c))
    {
        std::cin.putback(c);
        std::cin >> key;
    }
    else
    {
        for (size_t i = 0; i < 10; i++)
            key.push_back(32+rand()%(128-32)); // random 10 char string
    }
    std::cout<<"The key is "<<key<<std::endl;

    std::cout << "Please enter your input message: (CTRL+D to end)\n";
    char getChar;
    while(std::cin.get(getChar))
        input+=getChar;
    while (key.size()<kchar) key += '0'; // pad key
    std::istringstream inf(input);
    std::ostringstream outf;
    if (!inf || !outf) throw std::runtime_error("bad input");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long outptr[2];
    char inbuf[nchar];
    unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf); 
    int count = 0;

    while (inf.get(inbuf[count])) {
        outf << std::hex;    // use hexadecimal output
        if (++count == nchar) {
            encipher(inptr,outptr,k);
            // pad with leading zeros:
            outf << std::setw(8) << std::setfill('0') << outptr[0] << ' '
                << std::setw(8) << std::setfill('0') << outptr[1] << ' ';
            count = 0;
        }
    }

    if (count) { // pad
        while(count != nchar) inbuf[count++] = '0'; 
        encipher(inptr,outptr,k);
        outf << outptr[0] << ' ' << outptr[1] << ' ';
    }

    outf<<endoftransmission;

    return outf;
}
#undef long

int main()
{
    srand(time(0));
    std::ostringstream oss = send();

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        throw std::runtime_error("Error: Unable to create socket");

    std::string serverAddress = "127.0.0.1"; // localhost but can/should be changed for real distance communication
    int serverPort = 80000; // 80000 seems like a good default choice. 

    // set up address structure
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(serverAddress.c_str());
    server.sin_port = htons(serverPort);

    //connect to the server

    if (connect(sock, (struct sockaddr*)&server,sizeof(server))<0)
        throw std::runtime_error("Error: could not connect to the server");
    
    std::string message = oss.str(); 

    // send the message
    if (send(sock,message.c_str(), message.length(),0)<0)
        throw std::runtime_error("Error: could not send message");
    
    // receive a response
    char buffer[1024];
    int numBytes = recv(sock,buffer,sizeof(buffer),0);
    if (numBytes < 0)
        throw std::runtime_error("Error: could not receive response");
    
    // print response
    buffer[numBytes] = '\0';
    std::cout << "Server response: " << buffer << std::endl;

    close(sock);
}