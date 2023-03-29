#include <stdio.h>
#include <stdlib.h>


// create the queue 

typedef struct student{
    int score;
    struct student *next;
}node;


typedef struct queue{
    struct student *front;
    struct student *rear;
}queue;

void enqueue(queue *q, int score){
    // declaim memory
    node *newnode = (node*)malloc(sizeof(node));
    newnode -> score = score;
    newnode -> next = NULL;
    if (q -> rear == NULL){
        q-> front = newnode;
    }
    else{
        q -> rear -> next = newnode;

    }
    q -> rear = newnode;
}

void dequeue(queue *q){
    if (q -> front == NULL){
        printf("the queue is empty\n");
    }else{
        printf("the %d was taken out\n",q->front-> score);
        q-> front = q->front ->next;
    }
}

void quprintf(queue *q){
    node *ptr = q-> front;
    if (ptr == NULL){
        printf("the queue is empty");
    }
    else {
        while(ptr != NULL){
        printf("the score is %d\n", ptr->score);
        ptr = ptr->next;}
    }
}


// 請看補充資料
int main(){
    queue q;
    q.front = NULL;
    q.rear = NULL;
    
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 70);
    enqueue(&q, 100);
    dequeue(&q);

    printf("\nfinal output is below\n");
    printf("---------------------------------\n");
    quprintf(&q);

    return 0;
}