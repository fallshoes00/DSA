#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // 定義Queue的最大容量

typedef struct {
    int data[MAX_SIZE];  // 存放Queue的Array
    int front;           // 指向Front的Pointer
    int rear;            // 指向rear的Pointer
    int size;            // 記錄Queue的Size
} Queue;

// 初始化Queue
void init(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// 檢查Queue是否為空
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// 檢查Queue是否已滿
bool isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// 返回Queue的大小
int size(Queue* queue) {
    return queue->size;
}

// 將元素加入Queue
bool enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue已滿，無法加入新element\n");
        return false;
    }
    // Queue裡的data滿不滿不是看pointer是否指到MAX_SIZE，而是看累積的size是否頂到上限
    //因此只要沒滿就可以循環使用，第一次dequeue就是丟掉第0號，下次就是丟掉第1號，...丟掉第99號，再回歸到第0號
    queue->rear = (queue->rear + 1) % MAX_SIZE;  
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

// 從Queue移除元素
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue是空的，無法移除element。\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;  // front換人當，同時用%MAX_SIZE避免跑出去array外面
    queue->size--;
    return value;
}

// 查看Queue頭部的元素
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue是空的，無法查看front。\n");
        return -1;
    }
    return queue->data[queue->front];
}

// 清空Queue
void clear(Queue* queue) {
    init(queue);
}

// Traverse queue and print
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue是空的，無法遍歷。\n");
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
