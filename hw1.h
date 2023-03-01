#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList(){
    Node*new=(Node*)malloc(sizeof(Node));
    new->next=NULL;
    scanf("%d",&new->size);
    new->data=(int*)malloc(sizeof(int)*(new->size));

    getchar();
    for(int i=0;i<(new->size);i++){
        scanf(" %d",&new->data[i]);
        //printf(" %d",new->data[i]);
        //printf("input");
    }
    return new;
}


void PrintList(Node* head){
    head=head->next;
    while(head!=NULL){
        for(int i=0;i<head->size;i++){
            printf("%d",head->data[i]);
            if(i!=head->size-1){
                printf(" ");
            }
            
        }
        printf("\n");
        head=head->next;
    }
}



void Merge(Node* head, int x, int y){
    Node*tempx=head;
    Node*tempx_pre=head;
    Node*tempy=head;
    for(int i=0;i<x;i++){ 
        tempx=tempx->next;
    }
    for(int i=0;i<y;i++){
        tempy=tempy->next;
    }

    int new_size=tempy->size+tempx->size;

    int *new_array=(int*)malloc(sizeof(int)*new_size);
    for(int i=0;i<tempy->size;i++){
        new_array[i]=tempy->data[i];
    }
    for(int i=tempy->size;i<new_size;i++){
        new_array[i]=tempx->data[i-(tempy->size)];
    }
    tempy->size=new_size;
    tempy->data=new_array;


    for(int i=1;i<x;i++){ 
        tempx_pre=tempx_pre->next;
    }
    tempx_pre->next=tempx->next;
    free(tempx);
}

void Cut(Node*head, int x, int y){
    Node*tempx=head;
    for(int i=0;i<x;i++){ 
        tempx=tempx->next;
    }

    Node*new=malloc(sizeof(Node));
    new->size=tempx->size-y;
    int *new_array=(int*)malloc(sizeof(int)*new->size);
    for(int i=0;i<tempx->size-y;i++){
        new_array[i]=tempx->data[i+y];
    }

    new->data=new_array;
    new->next=tempx->next;
    tempx->next=new;

    tempx->size=y;
}
#endif