#include <iostream>
#include <string>
#include <fstream>
#include "Cipher.h"

using namespace std;

//Method Prototypes
void prompt();
void process(string inputFile, string outputFile, int key);


int main()
{
    prompt();    
    return 0;
}

//Prompt the user for input
void prompt()
{
    string in, out;
    int key;
    cout << "Enter the name of the input file >> ";
    cin >> in;
    cout << "Enter the name of the output file >> ";
    cin >> out;
    cout <<"Enter the numeric encryption key >> ";
    cin >> key;   
    process(in, out, key); 
}

//Encrypt the file specified by the user
void process(string inputFile, string outputFile, int key)
{
    char cur;
    string text;
    Cipher cipher;
    ifstream in(inputFile);
    ofstream out(outputFile);

    while (getline(in, text))
    {
       for (char c : text)
       {
           cur = cipher.shift(key, (int)c);
           out << cur;
           cout << cur;
       }
       out << "\n";
    }
    in.close();
    out.close();
}