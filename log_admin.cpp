#include <stdio.h>
#include <string.h>
#include "login.h"

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

int login() {
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    int choice;

    // Input username and password
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if the username and password are correct
    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) {
        printf("Login successful!\n");

        // Show menu
        printf("\n");
        printf("Menu:\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. View users\n");
        printf("4. Exit\n");
        printf("\n");

        do {
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                   Statictic();
                    break;
                case 2:
                    printf("Delete user\n");
                    break;
                case 3:
                    printf("View users\n");
                    break;
                case 4:
                    printf("Exiting program.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 4);
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}

