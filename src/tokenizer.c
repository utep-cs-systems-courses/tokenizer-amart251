#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"


// Check if a character is a whitespace (space or tab)
int space_char(char c){
    return (c == ' ' || c == '\t');
}

// Check if a character is a non-whitespace and not a null terminator
int non_space_char(char c){
    return !space_char(c) && c != '\0';
}

// Find the starting point of the next token in the string
char *token_start(char *str){
    while (str != '\0'){
        if (non_space_char(*str)){
            return str;
        }
        str++;
    }
    return NULL;
}

// Find the end point of the current token in the string
char *token_terminator(char *token){
    while(non_space_char(*token)){
        token++;
    }
    return token;
}

// Count the number of tokens in the string
int count_tokens(char *str){
    int count = 0;
    char *token = token_start(str);
    while (token != NULL){
        count++;
        token = token_start(token_terminator(token));
    }
    return token;
}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    return NULL;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    return NULL;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    return NULL;
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    return NULL;
}
