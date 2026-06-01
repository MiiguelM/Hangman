#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getword(char *filename, char *word) {
    FILE *file = fopen(filename, "r");

    int total = 0;
    char temp[50];
    while (fgets(temp, 50, file)) {
        total++;
    }
    int chosen = rand() % total;
    rewind(file);

    for (int i = 0; i <= chosen; i++) {
        fgets(word, 50, file);
    }
    word[strcspn(word, "\n")] = 0;

    fclose(file);
}

int main(){
    char word[50];
    char state[50];
    char letter;
    int lives = 5;
    int option = -1;
    srand(time(NULL));

    while(option != 0){
    printf("\n\nHangman started\n");
    printf("\nSelect an option:\n");
    printf("\n1 - Fruits\n");
    printf("2 - Objects of kitchen\n");
    printf("0 - Exit\n");
    printf("\n--> ");

    if (scanf("%d", &option) == 0){
        while(getchar() != '\n');
        printf("\nInvalid input, please try again.\n");
        continue;
    }

    switch (option){
    case 1:
        printf("\nYou select 'Fruits' let's play!\n");
        getword("Fruits.txt", word);

        for (int i = 0; i < strlen(word); i++){
            state[i] = '_';
        }
        state[strlen(word)] = '\0';

        for (int i = 0; i < strlen(word); i++){
            printf("_ ");
        }
        
        lives = 5;
        while (lives > 0 && strchr(state, '_')) {
            printf("\nEnter one letter: ");
            scanf(" %c", &letter);
        
            if (strchr(word, letter)) {
                for (int i = 0; i < strlen(word); i++) {
                    if (word[i] == letter) {
                    state[i] = letter;
                    }
                }
            } else {
                lives--;
                printf("\nWrong letter! Lives remaining: %d", lives);
                if (lives == 0) {
                    printf("\n\nYour lives are 0. Try again!");
                }
            }
        }
        
        break;
    case 2:
        printf("\n You select 'Objects of kitchen' lest's play!\n");
        FILE *Objects = fopen("Objects.txt", "r");
        fclose(Objects);
        break;
    case 0:
        printf("\nExiting...");
        break;
    default:
        printf("Invalid option, please try again.\n");
        break;
    }
}
}