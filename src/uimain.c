#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 200


// Displays the main menu options

void mainMenu()
{
    printf ("Welcome to Tokenizer\n");
    printf ("Tokenize a string\n");
    printf ("2. History \n");
    printf ("3. Exit \n");
}

// Handles tokenization of user input and adds it to history
void handleTokenization(char * user_input, List * history){
    char ** tokens;
    printf("what should I remember? \n");
    fgets(user_input, MAX, stdin);
    tokens = tokenize(user_input);
    print_tokens(tokens);
    add_history(history, user_input);
    free_tokens(tokens);
}

//Handles displaying token history
void handleHistory(List * history){
    printf("Tokens: \n");
    print_history(history);
}

int main ()
{
    char user_input [MAX];
    List * history = init_history();

    while (user_input[0] != '3'){
        displayMenu();
        fgets(user_input, MAX, stdin); // get user input

        //add switch cases here for user input
    }
    free_history(history;
    return 0)
}

