#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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
    char tried[27] = "";
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
        tried[0] = '\0';
        while (lives > 0 && strchr(state, '_')) {
            printf("\n\nEnter one letter: ");
            scanf(" %c", &letter);

            if (!isalpha(letter)) {
                printf("Please enter a letter only!\n");
                continue;
            }

            if (strchr(tried, letter)) {
                printf("You already tried this letter!\n");
            } else {
                int len = strlen(tried);
                tried[len] = letter;
                tried[len + 1] = '\0';
            
            if (strchr(word, letter)) {
                for (int i = 0; i < strlen(word); i++) {
                    if (word[i] == letter) {
                        state[i] = letter;
                    }
                }
            } else {
                lives--;
            }
        }
        printf("\n%s\n", state);
        printf("\nLives: %d\n", lives);
        printf("Tried: %s\n", tried);

    }

    if (lives == 0) {
        printf("\nYour lives are 0. Try again!\nReturning to menu...\n");
    } else {
        printf("\nCongratulations! You guessed the word: %s\nReturning to menu...", word);
    }
                      
    break;
    case 2:
        printf("\n You select 'Objects of kitchen' lest's play!\n");
        getword("Objects.txt", word);
        
        for (int i = 0; i < strlen(word); i++){
            state[i] = '_';
        }

        state[strlen(word)] = '\0';

        for (int i = 0; i < strlen(word); i++){
            printf("_ ");
        }

        lives = 5;
        tried[0] = '\0';
        while (lives > 0 && strchr(state, '_')){
            printf("\nEnter one letter: ");
            scanf(" %c", &letter);

            if (!isalpha(letter)){
                printf("Please enter a letter only!\n");
                continue;
            }

            if (strchr(tried, letter)){
                printf("You already tried this letter!\n");
            } else {
                int len = strlen(tried);
                tried[len] = letter;
                tried[len + 1] = '\0'; 
            
             if (strchr(word, letter)){
                for (int i = 0; i < strlen(word); i++){
                    if (word[i] == letter ){
                        state[i] = letter;
                    }
                }
             } else {
                lives--;
             }
            } 
            printf("\n%s\n", state);
            printf("\nLives: %d\n", lives);
            printf("Tried: %s\n", tried);
        }
        
        if (lives == 0){
            printf("\nYour lives are 0. Try again!\nReturning to menu...\n");
        } else{
            printf("\nCongratulations! You guessed the word: %s\nReturning to menu...\n", word);
        }
        
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