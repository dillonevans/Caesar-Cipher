#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using std::string;

class Cipher
{
    public: 
    char shift(int key, int value);
};
#endif