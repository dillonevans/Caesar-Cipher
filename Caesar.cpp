#include <iostream>
#include <string>
#include <fstream>
#include "Cipher.h"

//Method Prototypes
void prompt();
void process(std::string inputFile, std::string outputFile, int key);

int main()
{
    prompt();    
    return 0;
}

//Prompt the user for input
void prompt()
{
    std::string in, out;
    int key;
    std::cout << "Enter the name of the input file >> ";
    std::cin >> in;
    std::cout << "Enter the name of the output file >> ";
    std::cin >> out;
    std::cout <<"Enter the numeric encryption key >> ";
    std::cin >> key;   
    process(in, out, key); 
}

//Encrypt the file specified by the user
void process(std::string inputFile, std::string outputFile, int key)
{
    char cur;
    std::string text;
    Cipher cipher;
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);

    while (std::getline(in, text))
    {
       for (char c : text)
       {
           cur = cipher.shift(key, (int)c);
           out << cur;
           std::cout << cur;
       }
       out << "\n";
    }
    in.close();
    out.close();
}
