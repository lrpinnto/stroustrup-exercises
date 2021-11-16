//CHAPTER 17 EX 07

#include <iostream>

char* cinarray(std::istream& is)
{
    char* string {nullptr};
    char* intermediate {nullptr};
    int counter {0};
    for (char c ; is.get(c); )
    {
        if(c=='!') 
        {
            if(string) string[counter]=0; //check for nullpointer
            break;
        }
        else
        {
            delete[] intermediate;
            intermediate = new char[counter];
            for(int i = 0 ; i < counter; i++)
                intermediate[i]=string[i];
            delete[] string; //attempt to delete old memory allocation before new assignment
            string = new char[++counter];
            for(int i = 0 ; i < counter-1; i++)
                string[i]=intermediate[i];
            string[counter-1]=c;
        }
    }
    delete[] intermediate;
    return string;
}

int main()
{
    std::cout<<"input a string of characters and end it with !.\n";
    char* array {cinarray(std::cin)};
    std::cout<<array;
    delete[] array;
}