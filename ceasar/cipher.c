#include "cipher.h"
#include <wchar.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

wchar_t numberToLetter(int number)
{
    if (number >= 0 && number < wcslen(customAlphabet))
    {
        return customAlphabet[number];
    }
    else
    {
        return L' ';
    }
}

int letterToNumber(wchar_t letter)
{
    const wchar_t* pos = wcschr(customAlphabet, letter);
    if (pos != NULL)
    {
        return pos - customAlphabet;
    }
    else
    {
        return -1;
    }
}

int shift(int number, int shiftValue) 
{
    int alphabetLength = wcslen(customAlphabet);
    int shiftedNumber = (number + shiftValue) % alphabetLength;
    if (shiftedNumber < 0)
    {
        shiftedNumber += alphabetLength;
    }
    return shiftedNumber;
}

wchar_t* encrypt(const wchar_t* message, int shiftValue)
{
    size_t length = wcslen(message);
    wchar_t* encryptedMessage = malloc((length + 1) * sizeof(wchar_t));
    if (!encryptedMessage) {
        wprintf(L"Memory allocation failed\n");
        return NULL;
    }

    for (size_t i = 0; i < length; i++)
    {
        int number = letterToNumber(message[i]);
        if (number != -1)
        {
            encryptedMessage[i] = numberToLetter(shift(number, shiftValue));
        }
        else
        {
            encryptedMessage[i] = message[i]; // Leave non-alphabet characters unchanged
        }
    }
    encryptedMessage[length] = L'\0';

    return encryptedMessage;
}

wchar_t* decrypt(const wchar_t* message, int shiftValue)
{
    size_t length = wcslen(message);
    wchar_t* decryptedMessage = malloc((length + 1) * sizeof(wchar_t));
    if (!decryptedMessage) {
        wprintf(L"Memory allocation failed\n");
        return NULL;
    }

    for (size_t i = 0; i < length; i++)
    {
        int number = letterToNumber(message[i]);
        if (number != -1)
        {
            decryptedMessage[i] = numberToLetter(shift(number, -shiftValue));
        }
        else
        {
            decryptedMessage[i] = message[i]; // Leave non-alphabet characters unchanged
        }
    }
    decryptedMessage[length] = L'\0';

    return decryptedMessage;
}