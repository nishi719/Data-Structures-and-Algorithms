#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int* array;
    int front;
    int rear;
    int count;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue* queue) {
    queue->array = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->count == 0);
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return (queue->count == MAX_SIZE);
}

// Function to add an element to the circular queue
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Circular queue is full. Cannot enqueue item.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->count++;
}

// Function to remove an element from the circular queue
void dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty. Cannot dequeue item.\n");
        return;
    }

    printf("Dequeued element: %d\n", queue->array[queue->front]);

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->count--;
}

// Function to display the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue elements: ");
    int i;
    for (i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}

// Function to free the memory allocated for the circular queue
void destroyQueue(CircularQueue* queue) {
    free(queue->array);
    queue->array = NULL;
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 60);
    enqueue(&queue, 70);

    display(&queue);

    destroyQueue(&queue);

    return 0;
}
