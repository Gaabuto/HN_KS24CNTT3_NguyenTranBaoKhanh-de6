#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Book {
    char bookTitle[MAX_LEN];
} Book;

typedef struct BookStack {
    Book book;
    struct BookStack* next;
} BookStack;

typedef struct BookQueueNode {
    Book book;
    struct BookQueueNode* next;
} BookQueueNode;

typedef struct closedQueue{
    BookQueueNode* front;
    BookQueueNode* rear;
} closedQueue;


void printScreen() {
    printf("======E-BOOK READER MANAGER=====");
    printf("\n1. Mo sach moi");
    printf("\n2. Dong sach hien tai");
    printf("\n3. Xem sach dang doc gan nhat");
    printf("\n4. Lich su dong sach");
    printf("\n5. Khoi phuc sach");
    printf("\n6. Hien thi cac sach dang mo");
    printf("\n7. Thoat");
    printf("\n===============================");
    printf("\nMoi ban nhap lua chon:");
}

int isEmptyStack(BookStack* top) {
    return top == NULL;
}

int isQueueEmpty(closedQueue* q) {
    return q->front == NULL;
}

BookStack* pop(BookStack** top) {
    if (isEmptyStack(*top)) return NULL;
    BookStack* temp = *top;
    *top = (*top)->next;
    return temp;
}

void push(BookStack** top, Book book) {
    BookStack* newNode = (BookStack*)malloc(sizeof(BookStack));
    newNode->book = book;
    newNode->next = *top;
    *top = newNode;
}

void enqueue(closedQueue* q, Book book) {
    BookQueueNode* newNode = (BookQueueNode*)malloc(sizeof(BookQueueNode));
    newNode->book = book;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int isDuplicateName(BookStack* head, const char* name) {
    BookStack* current = head;
    while (current != NULL) {
        if (strcmp(current->book.bookTitle, name) == 0) return 1;
        current = current->next;
    }
    return 0;
}

Book inputBook(BookStack* head) {
    Book book;
    while (1) {
        printf("Nhap ten sach: ");
        getchar();
        fgets(book.bookTitle, MAX_LEN, stdin);
        book.bookTitle[strcspn(book.bookTitle, "\n")] = '\0';
        if (isDuplicateName(head, book.bookTitle)) {
            printf("Sach da ton tai! Nhap ten khac.\n");
        } else {
            return book;
        }
    }
}

void addBook(BookStack** head) {
    Book newBook = inputBook(*head);
    push(head, newBook);
    printf("Mo sach thanh cong!\n");
}

void closeBook(BookStack** head, closedQueue* q) {
    if (isEmptyStack(*head)) {
        printf("Khong co sach nao dang mo.\n");
        return;
    }
    BookStack* closed = pop(head);
    enqueue(q, closed->book);
    free(closed);
    printf("Dong sach thanh cong.\n");
}

void viewClosedBook(BookStack* head) {
    if (isEmptyStack(head)) {
        printf("Khong co sach dang doc.\n");
    } else {
        printf("Sach dang doc gan nhat: %s\n", head->book.bookTitle);
    }
}

void viewRecentHistory(closedQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Chua co sach nao duoc dong.\n");
        return;
    }
    printf("Lich su sach da dong:\n");
    BookQueueNode* current = q->front;
    while (current != NULL) {
        printf("- %s\n", current->book.bookTitle);
        current = current->next;
    }
}

void printStack(BookStack* head) {
    if (isEmptyStack(head)) {
        printf("Khong co sach dang mo.\n");
        return;
    }
    while (head != NULL) {
        printf("- %s\n", head->book.bookTitle);
        head = head->next;
    }
}

int main() {
    int choice;
    BookStack* stack = NULL;
    closedQueue queue = {NULL, NULL};

    do {
        printScreen();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(&stack);
                break;
            case 2:
                closeBook(&stack, &queue);
                break;
            case 3:
                viewClosedBook(stack);
                break;
            case 4:
                viewRecentHistory(&queue);
                break;
            case 6:
                printStack(stack);
            case 7:
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 7);
    printf("Thoat chuong trinh. Byeee!\n");
    return 0;
}
