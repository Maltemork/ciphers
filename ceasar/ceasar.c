#include "ceasar.h"
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

const wchar_t* customAlphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅabcdefghijklmnopqrstuvwxyzæøå0123456789 .,!?";

void encryptMenu();
void decryptMenu();
void clearInputBuffer();
void startMenu();

int main()
{
    // Set locale to Danish UTF-8
    if (!setlocale(LC_ALL, "da_DK.utf8")) 
    {
        wprintf(L"Failed to set locale to da_DK.utf8\n");
        return 1;
    }

    wprintf(L"Welcome to the Ceasar encryptor.\n");
    wprintf(L"-----------------------------\n");

    while (1)
    {
        startMenu();
        char choice;
        scanf(" %c", &choice); // Note the space before %c to consume any leftover newline character
        clearInputBuffer();

        if (choice == 'e')
        {
            encryptMenu();
        }
        else if (choice == 'd')
        {
            decryptMenu();
        }
        else if (choice == 'q')
        {
            break;
        }
        else
        {
            wprintf(L"Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void encryptMenu()
{
    wprintf(L"\n");
    wprintf(L"----------Encryption---------\n");
    wprintf(L"\n");

    wprintf(L"Please enter a message to encrypt:\n");
    wchar_t message[2048]; // Increased buffer size
    fgetws(message, 2048, stdin);
    size_t len = wcslen(message);
    if (len > 0 && message[len - 1] == L'\n') {
        message[len - 1] = L'\0'; // Remove the newline character at the end
    } else {
        clearInputBuffer(); // Clear the input buffer if the message is too long
    }
    wprintf(L"Please enter a shift value:\n");
    int shiftValue;
    scanf("%d", &shiftValue);
    clearInputBuffer();
    wprintf(L"Encrypted message: %ls\n", encrypt(message, shiftValue));

    wprintf(L"\n");
    wprintf(L"--------Ended Encryption------\n");
    wprintf(L"\n");
}

void decryptMenu()
{
    wprintf(L"\n");
    wprintf(L"----------Decryption---------\n");
    wprintf(L"\n");

    wprintf(L"Please enter a message to decrypt:\n");
    wchar_t message[2048]; // Increased buffer size
    fgetws(message, 2048, stdin);
    size_t len = wcslen(message);
    if (len > 0 && message[len - 1] == L'\n') {
        message[len - 1] = L'\0'; // Remove the newline character at the end
    } else {
        clearInputBuffer(); // Clear the input buffer if the message is too long
    }
    wprintf(L"Please enter a shift value:\n");
    int shiftValue;
    scanf("%d", &shiftValue);
    clearInputBuffer();
    wprintf(L"Decrypted message: %ls\n", decrypt(message, shiftValue));

    wprintf(L"\n");
    wprintf(L"--------Ended Decryption------\n");
    wprintf(L"\n");
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void startMenu()
{
    wprintf(L"Please make a choice:\n");
    wprintf(L"Type (e) for encryption.\n");
    wprintf(L"Type (d) for decryption.\n");
    wprintf(L"Type (q) to quit.\n");
}