#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // 定義Stack的最大容量

typedef struct {
    int data[MAX_SIZE];  // 存放Stack element的array
    int top;             // 指向Stack Top的指標
} Stack;

// 初始化Stack
void init(Stack* stack) {
    stack->top = -1;
}

// 檢查Stack是否empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 檢查Stack是否已滿
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Stack內的資料數量
int size(Stack* stack) {
    return stack->top + 1;
}

// 將data推入Stack
bool push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack已滿，無法Push。\n");
        return false;
    }
    stack->top += 1;
    stack->data[stack->top] = value;
    return true;
}

// 從Stack吐
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack為空，無法吐出元素。\n");
        return -1;  
    }

    return stack->data[(stack->top)--];
}

// 查看Top的element
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack為空，無法查看Top。\n");
        return -1; 
    }
    return stack->data[stack->top];
}

// 清空Stack
void clear(Stack* stack) {
    stack->top = -1;
}

// 在Stack中搜尋數值
int search(Stack* stack, int value) {
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] == value) {
            return i;  
        }
    }
    return -1;
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element of stack: %d\n", top(&stack));
    printf("Size of stack: %d\n", size(&stack));

    printf("Find element position '20': %d\n", search(&stack, 20));

    pop(&stack);
    printf("Top element of stack (After pop): %d\n", top(&stack));
    printf("Stack is empty? Ans:%s\n", isEmpty(&stack) ? "Yes" : "No");

    clear(&stack);
    printf("Stack is empty(After clear)? Ans: %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
