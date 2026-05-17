#include <string.h>
#include <stdio.h>

int main(){
    int option = -1;

    while(option != 0){
    printf("\nHangman started, let's play!\n");
    printf("\nSelect an option:\n");
    printf("\n1 - Fruits\n");
    printf("2 - Objects of kitchen\n");
    printf("0 - Exit\n");
    printf("\n--> ");

    if (scanf("%d", &option) == 0){
        while(getchar() != '\n');
        printf("\nInvalid input, please try again");
        continue;
    }

    switch (option){
    case 1:
        printf("\nYou select 'Fruits' let's play!");
        FILE *Fruits = fopen("Fruits.txt", "r");
        fclose(Fruits);
        break;
    case 2:
        printf("\n You select 'Objects of kitchen' lest's play!");
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