#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

char text[MAX_LINES][MAX_LENGTH];
int lineCount = 0;


void addLine(const char *line) {
    if (lineCount >= MAX_LINES) {
        printf("Text buffer is full! Cannot add more lines.\n");
        return;
    }
    strncpy(text[lineCount], line, MAX_LENGTH - 1);
    text[lineCount][MAX_LENGTH - 1] = '\0'; 
    lineCount++;
    printf("Line added.\n");
}


void deleteLine() {
    if (lineCount == 0) {
        printf("No lines to delete.\n");
        return;
    }
    lineCount--;
    printf("Last line deleted.\n");
}


void displayText() {
    if (lineCount == 0) {
        printf("Text is empty.\n");
        return;
    }

    printf("\n--- Text Content ---\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, text[i]);
    }
    printf("--------------------\n");
}

int main() {
    int choice;
    char line[MAX_LENGTH];

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Add Line\n");
        printf("2. Delete Last Line\n");
        printf("3. Display Text\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter a line of text: ");
                fgets(line, MAX_LENGTH, stdin);
                line[strcspn(line, "\n")] = 0; 
                addLine(line);
                break;
            case 2:
                deleteLine();
                break;
            case 3:
                displayText();
                break;
            case 4:
                printf("Exiting text editor...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
