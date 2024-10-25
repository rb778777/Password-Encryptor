#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void encrypt(char message[], int key) {
    key = key % 26;  

    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            
            char base = isupper(message[i]) ? 'A' : 'a';

            
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}


void decrypt(char message[], int key) {
    key = key % 26;  

    
    encrypt(message, -key);
}

int main() {
    char message[100];
    int key, choice;

    
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Enter your choice (1 or 2): ");

        if (scanf("%d", &choice) == 1 && (choice == 1 || choice == 2)) {
            break;  
        }

        printf("Invalid input. Please enter a valid choice (1 or 2).\n");

        while (getchar() != '\n');  
    }

    
    while (1) {
        printf("Enter the key (0 to 25): ");

        if (scanf("%d", &key) == 1 && (key >= 0 && key <= 25)) {
            break;  
        }

        printf("Invalid input. Please enter a valid key (0 to 25).\n");

        while (getchar() != '\n');  
    }

    if (choice == 1) {
       
        encrypt(message, key);
        printf("\nEncrypted message: %s\n", message);
    } else if (choice == 2) {
        
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}
