#include <stdio.h>
#include <stdlib.h>

#define LETTERS 26
#define WORDLEN 10

int len, len_1, count_del, found_del;
char saveword[WORDLEN];

typedef struct node{
    int is_word;
    struct node *branch[LETTERS];
}trienode;

trienode *getnode(){
    trienode *newnode = (trienode *)malloc(sizeof(trienode));
    newnode->is_word = 0;
    for(int i = 0; i < LETTERS; i++){
        newnode->branch[i] = NULL;
    }
    return newnode;
}

trienode *insert(trienode *root, char word[]){
    if(root == NULL){
        root = getnode();
    }
    trienode *savestate = root;
    for(int i = 0; i < WORDLEN; i++){
        if(word[i] == '\0'){
            break;
        }
        if(root->branch[word[i] - 'a'] == NULL){
            root->branch[word[i] - 'a'] = getnode();
        }
        root = root->branch[word[i] - 'a'];
    } 
    if(root->is_word == 0){
        root->is_word = 1;
        printf("Inserted Successfully.\n");
    }
    else{
        printf("Duplicate insertion.\n");
    }
    return savestate;
}

void display_1(trienode *root, char prefix[]){
    if(root == NULL){
        printf("Empty trie.\n");
    }
    for(int i = 0; i < LETTERS; i++){
        if(root->branch[i] != NULL){
            saveword[len_1++] = i + 'a'; 
            if(root->branch[i]->is_word == 1){
                printf("%s", prefix);
                for(int j = 0; j < len_1; j++){
                    printf("%c", saveword[j]);
                }
                printf("\n");
            }
            display_1(root->branch[i], prefix);
        }
    }
    len_1--;
}


void search_prefix(trienode *root, char word[]){
    if(root == NULL){
        printf("Empty trie.\n");
    }
    int i = 0;
    while(root != NULL && i < WORDLEN){
        if(word[i] == '\0'){
            break;
        }
        else{
            root = root->branch[word[i] - 'a'];
        }
        i++;
    }
    if(root == NULL){
        printf("No words with this prefix found\n");
    }
    else if(root->is_word == 1){
        printf("%s\n", word);
        display_1(root, word);
    }
    else{
        display_1(root, word);
    }
}

int is_empty(trienode *temp){
    for(int i = 0; i < LETTERS; i++){
        if(temp->branch[i] != NULL){
            return 0;
        }
    }
    return 1;
}

trienode *delete_node(trienode *root, char word[], int size){
    if(root == NULL){
        return NULL;
    }
    if(count_del == size){
        if(root->is_word == 1){
            found_del = 1;
            root->is_word = 0;
            if(is_empty(root)){
                free(root);
                root = NULL;
            }
            return root;    
        }
    }
    int index = word[count_del++] - 'a';
    root->branch[index] = delete_node(root->branch[index], word, size);
    if(is_empty(root) && root->is_word == 0){
        free(root);
        root = NULL;
    }
    return root;
}

/*void display(trienode *root){
    if(root == NULL){
        printf("Empty trie.\n");
    }
    for(int i = 0; i < LETTERS; i++){
        if(root->branch[i] != NULL){
            saveword[len++] = i + 'a'; 
            if(root->branch[i]->is_word == 1){
                for(int j = 0; j < len; j++){
                    printf("%c", saveword[j]);
                }
                printf("\n");
            }
            display(root->branch[i]);
        }
    }
    len--;
}*/

int main(){
    int ch, i;
    char word[WORDLEN];
    trienode *dictionary = NULL;
    do{
        printf("Options: 1. Insert 2. Delete 3. Display 4. Search Prefix 5. Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the word:");
                scanf("%s", word);
                dictionary = insert(dictionary, word);
                break;
            case 2:
                found_del = 0;
                count_del = 0;
                i = 0;
                printf("Enter the word to delete:");
                scanf("%s", word);
                while(word[i] != '\0'){
                    i++;
                }
                dictionary = delete_node(dictionary, word, i);
                if(found_del == 0){
                    printf("Not found.\n");
                }
                else{
                    printf("Found and Deleted.\n");
                }
                break;
            case 3:
                len_1 = 0;
                display_1(dictionary, "\0");
                break;
            case 4:
                len_1 = 0;
                printf("Enter the prefix you want to search:");
                scanf("%s", word);
                search_prefix(dictionary, word);
                break;
        }
    }while(ch != 5);
    return 0;
}