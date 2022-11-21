#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE (255)
#define ALPHABET_SIZE (26)

char saveword[MAXSIZE];

struct TrieNode
{

    struct TrieNode *children[ALPHABET_SIZE]; // pointer Array
    bool isEndOfWord;                         // denotes end of the word
};

// Initialise Default Node by setting the pointer Array to Null and End of World to False
struct TrieNode *getNode()
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// Function that returns the length of the Input
int my_strlen(char *string)
{
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

// Function to Insert the element into the Trie
void insert(struct TrieNode *root, char *key)
{
    if(root == NULL){
        root = getNode();
    }
    for(int i = 0; i < MAXSIZE; i++){
        if(key[i] == '\0'){
            break;
        }
        if(root->children[key[i] - 'a'] == NULL){
            root->children[key[i] - 'a'] = getNode();
        }
        root = root->children[key[i] - 'a'];
    }
    root->isEndOfWord = 1;
}

// Recursive Function to Print in Lexicographic order using DFS
void dfs_word(struct TrieNode *root, char *word, int *plent)
{
    if(root == NULL){
        return;
    }
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(root->children[i] != NULL){
            saveword[(*plent)++] = i + 'a'; 
            if(root->children[i]->isEndOfWord == 1){
                for(int j = 0; j < *plent; j++){
                    printf("%c", saveword[j]);
                }
                printf("\n");
            }
            dfs_word(root->children[i], word, plent);
        }
    }
    (*plent)--;
}

// Function to Display
void display(struct TrieNode *root)
{

    char word[MAXSIZE] = "";
    int length = 0;
    dfs_word(root, word, &length);
}


int main()
{
    int number_of_ele, i;

    // initialising root node
    struct TrieNode *root = getNode();
    char input[number_of_ele][MAXSIZE];

    // Number of input elements
    scanf("%d", &number_of_ele);
    for (i = 0; i < number_of_ele; i++)
    {
        scanf("%s\n", input[i]);
    }

    // Inserting Into the Trie
    for (int i = 0; i < number_of_ele; i++)
    {

        insert(root, input[i]);
    }

    display(root);
    return 0;
}