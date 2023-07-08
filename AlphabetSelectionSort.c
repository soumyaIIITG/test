#include <stdio.h>
#include <string.h>

void insertionSort(char arr[][100], int n) {
    int i, j;
    char key[100];

    for (i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}

int main() {
    int n, i;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][100];
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    insertionSort(arr, n);

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
