#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100


typedef struct Node {
    char content[MAX_LEN]
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof (Node));

    newNode->content = value;
    newNode->left = newNode->right = NULL;

    return newNode;
}




void printScreen() {
    printf("\n====GAME DECISION SIMULATOR====");
    printf("\n1. Bat dau tro choi");
    printf("\n2. Bat dau tra choi");
    printf("\n3. Bat dau tra choi");
    printf("\n4. Bat dau tra choi");
    printf("\n5. Thoat");
    printf("\nMoi ban nhap lua chon");
}

int main() {
    int choice;
    do {
        printScreen();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
                default:
                printf("Lua chon khong hop le");
                break;
        }
    }while (choice != 5);
    printf("Byee");
    return 0;

}