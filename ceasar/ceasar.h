#ifndef CEASAR_H
#define CEASAR_H

#include <wchar.h>

void clearInputBuffer();
void startMenu();
wchar_t numberToLetter(int number);
int letterToNumber(wchar_t letter);
int shift(int number, int shiftValue);
wchar_t* encrypt(const wchar_t* message, int shiftValue);
wchar_t* decrypt(const wchar_t* message, int shiftValue);

void encryptMenu();
void decryptMenu();
void clearInputBuffer();
void startMenu();

#endif // CEASAR_H