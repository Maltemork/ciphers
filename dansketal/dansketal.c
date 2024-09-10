#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* numbers[] = {
    "nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni",
    "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"
};

const char* tens[] = {
    "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"
};

// Function to convert a number to its Danish representation
char* convertNumberToDanish(long long number) {
    // Handle numbers from 0 to 19
    if (number < 20) {
        return strdup(numbers[number]);
    } 
    // Handle numbers from 20 to 99
    else if (number < 100) {
        int tensDigit = number / 10;
        int onesDigit = number % 10;
        if (onesDigit == 0) {
            return strdup(tens[tensDigit - 2]);
        } else {
            // Allocate memory for the result string
            char* result = malloc(strlen(numbers[onesDigit]) + strlen("og") + strlen(tens[tensDigit - 2]) + 1);
            if (result == NULL) {
                return NULL;
            }
            // Construct the result string
            if (onesDigit == 1) {
                strcpy(result, "enog");
            } else {
                strcpy(result, numbers[onesDigit]);
                strcat(result, "og");
            }
            strcat(result, tens[tensDigit - 2]);
            return result;
        }
    } 
    // Handle numbers from 100 to 999
    else if (number < 1000) {
        int hundredsDigit = number / 100;
        int remainder = number % 100;
        // Allocate memory for the result string
        char* result = malloc(strlen(numbers[hundredsDigit]) + strlen(" hundrede") + 1);
        if (result == NULL) {
            return NULL;
        }
        // Construct the result string
        if (hundredsDigit == 1) {
            strcpy(result, "et hundrede");
        } else {
            strcpy(result, numbers[hundredsDigit]);
            strcat(result, " hundrede");
        }
        if (remainder > 0) {
            char* remainderStr = convertNumberToDanish(remainder);
            if (remainderStr == NULL) {
                free(result);
                return NULL;
            }
            result = realloc(result, strlen(result) + strlen(" ") + strlen(remainderStr) + 1);
            if (result == NULL) {
                free(remainderStr);
                return NULL;
            }
            strcat(result, " ");
            strcat(result, remainderStr);
            free(remainderStr);
        }
        return result;
    } 
    // Handle numbers from 1000 to 999999
    else if (number < 1000000) {
        int thousandsDigit = number / 1000;
        int remainder = number % 1000;
        char* thousandsStr = convertNumberToDanish(thousandsDigit);
        if (thousandsStr == NULL) {
            return NULL;
        }
        char* result = malloc(strlen(thousandsStr) + strlen(" tusinde") + 1);
        if (result == NULL) {
            free(thousandsStr);
            return NULL;
        }
        if (thousandsDigit == 1) {
            strcpy(result, "et tusinde");
        } else {
            strcpy(result, thousandsStr);
            strcat(result, " tusinde");
        }
        free(thousandsStr);
        if (remainder > 0) {
            char* remainderStr = convertNumberToDanish(remainder);
            if (remainderStr == NULL) {
                free(result);
                return NULL;
            }
            result = realloc(result, strlen(result) + strlen(" ") + strlen(remainderStr) + 1);
            if (result == NULL) {
                free(remainderStr);
                return NULL;
            }
            strcat(result, " ");
            strcat(result, remainderStr);
            free(remainderStr);
        }
        return result;
    } 
    // Handle numbers from 1000000 to 999999999
    else if (number < 1000000000) {
        int millionsDigit = number / 1000000;
        int remainder = number % 1000000;
        char* millionsStr = convertNumberToDanish(millionsDigit);
        if (millionsStr == NULL) {
            return NULL;
        }
        char* result = malloc(strlen(millionsStr) + strlen(" million") + (millionsDigit > 1 ? 2 : 0) + 1);
        if (result == NULL) {
            free(millionsStr);
            return NULL;
        }
        if (millionsDigit == 1) {
            strcpy(result, "en million");
        } else {
            strcpy(result, millionsStr);
            strcat(result, " million");
            if (millionsDigit > 1) {
                strcat(result, "er");
            }
        }
        free(millionsStr);
        if (remainder > 0) {
            char* remainderStr = convertNumberToDanish(remainder);
            if (remainderStr == NULL) {
                free(result);
                return NULL;
            }
            result = realloc(result, strlen(result) + strlen(" ") + strlen(remainderStr) + 1);
            if (result == NULL) {
                free(remainderStr);
                return NULL;
            }
            strcat(result, " ");
            strcat(result, remainderStr);
            free(remainderStr);
        }
        return result;
    } 
    // Handle numbers from 1000000000 to 999999999999
    else if (number < 1000000000000) {
        int billionsDigit = number / 1000000000;
        int remainder = number % 1000000000;
        char* billionsStr = convertNumberToDanish(billionsDigit);
        if (billionsStr == NULL) {
            return NULL;
        }
        char* result = malloc(strlen(billionsStr) + strlen(" milliard") + (billionsDigit > 1 ? 2 : 0) + 1);
        if (result == NULL) {
            free(billionsStr);
            return NULL;
        }
        if (billionsDigit == 1) {
            strcpy(result, "en milliard");
        } else {
            strcpy(result, billionsStr);
            strcat(result, " milliard");
            if (billionsDigit > 1) {
                strcat(result, "er");
            }
        }
        free(billionsStr);
        if (remainder > 0) {
            char* remainderStr = convertNumberToDanish(remainder);
            if (remainderStr == NULL) {
                free(result);
                return NULL;
            }
            result = realloc(result, strlen(result) + strlen(" ") + strlen(remainderStr) + 1);
            if (result == NULL) {
                free(remainderStr);
                return NULL;
            }
            strcat(result, " ");
            strcat(result, remainderStr);
            free(remainderStr);
        }
        return result;
    } 
    // Handle numbers from 1000000000000 to 100000000000000
    else if (number <= 100000000000000) {
        int trillionsDigit = number / 1000000000000;
        int remainder = number % 1000000000000;
        char* trillionsStr = convertNumberToDanish(trillionsDigit);
        if (trillionsStr == NULL) {
            return NULL;
        }
        char* result = malloc(strlen(trillionsStr) + strlen(" billion") + (trillionsDigit > 1 ? 2 : 0) + 1);
        if (result == NULL) {
            free(trillionsStr);
            return NULL;
        }
        if (trillionsDigit == 1) {
            strcpy(result, "en billion");
        } else {
            strcpy(result, trillionsStr);
            strcat(result, " billion");
            if (trillionsDigit > 1) {
                strcat(result, "er");
            }
        }
        free(trillionsStr);
        if (remainder > 0) {
            char* remainderStr = convertNumberToDanish(remainder);
            if (remainderStr == NULL) {
                free(result);
                return NULL;
            }
            result = realloc(result, strlen(result) + strlen(" ") + strlen(remainderStr) + 1);
            if (result == NULL) {
                free(remainderStr);
                return NULL;
            }
            strcat(result, " ");
            strcat(result, remainderStr);
            free(remainderStr);
        }
        return result;
    } else {
        return NULL; // Handle numbers greater than 100 trillion if needed
    }
}

// Function to capitalize the first letter of a string
void capitalize(char* str) {
    if (str != NULL && strlen(str) > 0) {
        str[0] = toupper(str[0]);
    }
}

void printMenu() {
    printf("========================================\n");
    printf("||                                    ||\n");
    printf("||      Danish Number Converter       ||\n");
    printf("||                                    ||\n");
    printf("========================================\n");
    printf("|| 1. Convert a number                ||\n");
    printf("|| 2. Exit                            ||\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main() {
    long long number;
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number up to 100 trillion: ");
                scanf("%lld", &number);
                char* danishNumber = convertNumberToDanish(number);
                if (danishNumber != NULL) {
                    capitalize(danishNumber);
                    printf("The number in Danish is: \n%s.\n", danishNumber);
                    free(danishNumber);
                } else {
                    printf("Error converting number.\n");
                }
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 2);
    return 0;
}