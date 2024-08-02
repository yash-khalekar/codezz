#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main() {
    FILE *f1;
    char filename[100];
    char ch;

    // Take input from user for the name of the file
    printf("Enter Name Of File: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        perror("Error reading filename");
        exit(EXIT_FAILURE);
    }

    // Remove the newline character if present
    filename[strcspn(filename, "\n")] = '\0';

    // Open the file
    f1 = fopen(filename, "r");

    // Check if file exists
    if (f1 == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Reading Data From File:\n");
    // Print the read data from file
    while ((ch = fgetc(f1)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(f1);

    return 0;
}
