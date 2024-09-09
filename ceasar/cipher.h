#ifndef CIPHER_H
#define CIPHER_H

#include <wchar.h>

extern const wchar_t* customAlphabet;

wchar_t numberToLetter(int number);
int letterToNumber(wchar_t letter);
int shift(int number, int shiftValue);
wchar_t* encrypt(const wchar_t* message, int shiftValue);
wchar_t* decrypt(const wchar_t* message, int shiftValue);

#endif // CIPHER_H