#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input;
    while(1) {
        input = readline(">> ");
        if(input == NULL) {
            printf("Fin du programme.\n");
            exit(0);
        }
        add_history(input); // sinon peut pas retrouver le bail en faisant fleche du haut
        printf("Vous avez entré : %s\n", input);
        free(input);
    }
    return 0;
}

// compiler avec -lreadline