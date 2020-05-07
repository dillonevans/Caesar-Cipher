#include "Cipher.h"
#include <iostream>
#include <ostream>

//Shifts the current character by the encryption key
char Cipher::shift(int key, int value)
{
    char output = ' ';
    int min = 32, max = 126, difference = 0;
    
    key %= (max-min);

    if (value < min || value > max)
    {
        output = (char)value;
        return output;
    }

    value+= key;   

    if (isalpha((char)value))
    {
        if (value > max)
        {
            difference = value - max - 1;
            value = min + difference;
            output = (char)value;
        }
        else if (value < min)
        {
            difference = min - value - 1;
            value = max - difference;
            output = (char)value;
        }
    }

    if (value > max)
    {
        value -= 95;
    }
    if (value < min)
    {
        value += 95;
    }

    output = (char)value;
    return output;
}