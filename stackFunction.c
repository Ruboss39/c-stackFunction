#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''                                                                                   ''
''                           Copyright Calculinc (C)                                 ''
''                                                                                   ''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
**/

struct node {
    //struct data d;
    int val;
    char c_val;
    struct node *next;
};
struct data {
    char name[50];
    double val;
    double val2;
};
struct node *initializeList(int startLen,char *input);
void printList(struct node *node);
void printListv2(struct node *node);
struct node *append(struct node *node,char charValue);
void insertAt(struct node *node, struct node *n, int indx);
void deleteList(struct node *node);
void flipList(struct node *node);
void removeAt(struct node *node,int index);
int getLength(struct node *node);
char *stacToArray(struct node *node);

void printList(struct node *node) {
    if(node != NULL) {
        int len = node -> val;
        for(int i = 0; i<=len; i++) {
            printf("%c",node->c_val);
            if (node->next == NULL) {
                break;
            }
            node = node -> next;
        }
    }
}

int getLength(struct node *node) {
    int i = 0;
    while(node->next != NULL) {
        node = node->next;
        i++;
    }
    return i+1;
}

struct node * append(struct node *node,char charValue) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new ->c_val = charValue;
    new ->next = node;
    new ->val = (node->val) + 1;
    return new;
}

void flipList(struct node *node) {
    struct node *returnN = node;
    struct node *flippedList = initializeList(1,"0");
    int len = node->val;
    for(int i = 0; i <= len; i++) {
        flippedList = append(flippedList,node->c_val);
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }
    removeAt(flippedList,0);
    deleteList(returnN->next);
    *returnN = *flippedList;
}

void deleteList(struct node *node) {
    if(node != NULL) {
        deleteList(node->next);
    } 
    free(node);
}

void insertAt(struct node *node, struct node *n, int indx) {
    struct node *start = node;
    int len = (node->val);
    for(int i = len-1; i >=0 ; i--) {
        if(i == indx) {
            if (indx ==0) {
                node->next = n;
                n->next = NULL;
            } else if(indx == len-1) {
                n->next = start;
                n->val = (start->val)+ 1;
                start = n;
                break;
            } else {
                n->next = node->next;
                node->next = n;
            }
            start->val +=1;
            break;
        } else {
            node = node->next;
        }
    }
}

void removeAt(struct node *node,int index) {
    struct node *start = node;
    struct node *prev = node;
    int len = node->val;
    if (len-1 == 0) {
        free(node);
    } else {
        for (int i =len-1; i >=0; i--) {
            if (index == i) {
                if(i == len-1) {
                    (start->next->val)--;
                    *start = *(start->next);
                    break;
                } else if (i==0) {
                    prev->next = NULL;
                } else {
                    prev->next = node->next;
                }
                free(node);
                (start->val)--;
                break;
            } else {
                if(node->next == NULL){
                    break;
                }
                prev = node;
                node = node->next;
            }
        }
    }
}

struct node *initializeList(int startLen,char *input) {
    if (startLen <0) {
        return NULL;
    } else {
        struct node *nPointer = NULL;
        for (int i = 1; i<=startLen; i++) {
            struct node *new = (struct node*)malloc(sizeof(struct node));
            new -> val = i;
            new -> next = nPointer;
            new->c_val = input[i-1];
            nPointer = new;
        }
        return nPointer;
    }
}