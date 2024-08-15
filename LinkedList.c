#include <stdio.h>
#include <stdlib.h>

// 宣告Node結構，包含data和下一個node
struct Node {
    int data;
    struct Node* next;
};

// 插一個新node到Linked-list的Head(1. 新的Node的Next要指到舊的head  2. Head指到新的Node(Head給別人當)
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// 刪除Linked-list第一個data跟key相同的Node
void removeNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    // Head node剛好就是key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // 一直往下找
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 走到底了，沒找到就return
    if (temp == NULL) 
        return;
    else{// 刪除Node
        prev->next = temp->next;//把當前位子指的next，丟給前面一個的next。(因為要把temp清掉了)
        free(temp);
    }
}

// 搜尋Linked-list是否有key
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// 改第一次出現key value的node值
void modify(struct Node* head, int old_data, int new_data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == old_data) {
            current->data = new_data;
            return;
        }
        current = current->next;
    }
}

// Traverse
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 2);

    printf("Created Linked List: ");
    traverse(head);

    // 刪除data=1的Node
    removeNode(&head, 1);
    printf("Linked List after Deletion of 1: ");
    traverse(head);

    // 搜尋data=3的Node是否存在
    struct Node* search_result = search(head, 3);
    if (search_result != NULL)
        printf("Element 3 found in the list.\n");
    else
        printf("Element 3 not found in the list.\n");

    // 把Node值7改成10
    modify(head, 7, 10);
    printf("Linked List after modifying 7 to 10: ");
    traverse(head);

    return 0;
}
