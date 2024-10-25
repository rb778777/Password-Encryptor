#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to perform Caesar Cipher encryption
void encrypt(char message[], int key) {
    key = key % 26;  // Ensure key is within the range 0 to 25

    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            // Adjust for uppercase or lowercase letters
            char base = isupper(message[i]) ? 'A' : 'a';

            // Apply Caesar Cipher encryption
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

// Function to perform Caesar Cipher decryption
void decrypt(char message[], int key) {
    key = key % 26;  // Ensure key is within the range 0 to 25

    // Decryption is the same as encryption with a negative key
    encrypt(message, -key);
}

int main() {
    char message[100];
    int key, choice;

    // Get user input for message
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Validate the user's choice
    while (1) {
        printf("Choose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Enter your choice (1 or 2): ");

        if (scanf("%d", &choice) == 1 && (choice == 1 || choice == 2)) {
            break;  // Exit the loop if valid input
        }

        printf("Invalid input. Please enter a valid choice (1 or 2).\n");

        while (getchar() != '\n');  // Clear input buffer
    }

    // Validate the user's key
    while (1) {
        printf("Enter the key (0 to 25): ");

        if (scanf("%d", &key) == 1 && (key >= 0 && key <= 25)) {
            break;  // Exit the loop if valid input
        }

        printf("Invalid input. Please enter a valid key (0 to 25).\n");

        while (getchar() != '\n');  // Clear input buffer
    }

    if (choice == 1) {
        // Encrypt the message
        encrypt(message, key);
        printf("\nEncrypted message: %s\n", message);
    } else if (choice == 2) {
        // Decrypt the message
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}
