#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    Node* mergedList = NULL;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = merge(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = merge(list1, list2->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitList(Node* head, Node** front, Node** back) {
    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Function to perform Merge Sort on a linked list
void mergeSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* front;
    Node* back;

    splitList(*head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *head = merge(front, back);
}

// Function to insert a new node at the beginning of the linked list
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    // Display the original linked list
    printf("Original ");
    display(head);

    // Perform Merge Sort
    mergeSort(&head);

    // Display the sorted linked list
    printf("Sorted ");
    display(head);

    // Free the memory allocated for the linked list
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
