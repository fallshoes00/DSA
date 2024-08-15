#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // �w�qQueue���̤j�e�q

typedef struct {
    int data[MAX_SIZE];  // �s��Queue��Array
    int front;           // ���VFront��Pointer
    int rear;            // ���Vrear��Pointer
    int size;            // �O��Queue��Size
} Queue;

// ��l��Queue
void init(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// �ˬdQueue�O�_����
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// �ˬdQueue�O�_�w��
bool isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// ��^Queue���j�p
int size(Queue* queue) {
    return queue->size;
}

// �N�����[�JQueue
bool enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue�w���A�L�k�[�J�selement\n");
        return false;
    }
    // Queue�̪�data���������O��pointer�O�_����MAX_SIZE�A�ӬO�ݲֿn��size�O�_����W��
    //�]���u�n�S���N�i�H�`���ϥΡA�Ĥ@��dequeue�N�O�ᱼ��0���A�U���N�O�ᱼ��1���A...�ᱼ��99���A�A�^�k���0��
    queue->rear = (queue->rear + 1) % MAX_SIZE;  
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

// �qQueue��������
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue�O�Ū��A�L�k����element�C\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;  // front���H��A�P�ɥ�%MAX_SIZE�קK�]�X�harray�~��
    queue->size--;
    return value;
}

// �d��Queue�Y��������
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue�O�Ū��A�L�k�d��front�C\n");
        return -1;
    }
    return queue->data[queue->front];
}

// �M��Queue
void clear(Queue* queue) {
    init(queue);
}

// Traverse queue and print
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue�O�Ū��A�L�k�M���C\n");
        return;
    }

    int index = queue->front;
    printf("Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}


int main() {
    Queue queue;
    init(&queue);

    enqueue(&queue, 10);
    traverse(&queue);
    enqueue(&queue, 20);
    traverse(&queue);
    enqueue(&queue, 30);
    traverse(&queue);

    printf("Front of Queue: %d\n", front(&queue));
    printf("Size of Queue: %d\n", size(&queue));

    dequeue(&queue);
    printf("Front element of Queue (after remove): %d\n", front(&queue));
    printf("Is queue empty? Ans: %s\n", isEmpty(&queue) ? "Yes" : "No");

    clear(&queue);
    printf("Is queue empty(after clear)? Ans: %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}
