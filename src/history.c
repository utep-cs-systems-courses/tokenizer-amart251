#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history()
{
    List *list = (List*) malloc(sizeof(List));
    list-> root = NULL;
    return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    Item *newitem = (Item*) malloc(sizeof(Item));
    newitem->id = 0;
    newitem->str = strdup(str);
    newitem->next = NULL;

    if (list -> root ==NULL){
        list -> root = newitem;
    }
    else{
        Item * current = list -> root;
        while (current -> next != NULL){
            current = current -> next;
        }
        current ->next = newitem;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *current = list -> root;
    while (current != NULL){
        if (current -> id == id){
            return current -> str;
        }
        current = current -> next;
    }
    return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item * current = list -> root;
    while (current != NULL) {
        printf("%s\n", current -> str);
        current = current -> next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
    Item * current = list -> root;
    while (current != NULL){
        Item * temp = current;
        current = current -> next;
        free (temp -> str);
        free (temp);
    }
    free(list);
}
