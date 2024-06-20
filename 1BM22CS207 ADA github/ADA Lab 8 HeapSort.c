#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Heapify function
void heapify(int arr[], int n, int i) {
    int temp, maximum, left_index, right_index;

    maximum = i;
    left_index = 2 * i + 1;
    right_index = 2 * i + 2;

    if (left_index < n && arr[left_index] > arr[maximum])
        maximum = left_index;

    if (right_index < n && arr[right_index] > arr[maximum])
        maximum = right_index;

    if (maximum != i) {
        temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr, n, maximum);
    }
}

// HeapSorting function
void heapsort(int arr[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Driver code
int main() {
    int n, ch;
    int arr[14500]; // Adjust array size based on maximum expected input

    clock_t start, end;

    printf("Heapsort Algorithm\n");

    while (1) {
        printf("\n 1: Time taken for manual entry of N node elements\n");
        printf(" 2: Time taken to display sorting time 7500 to 14500 elements\n");
        printf(" 3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);

                printf("Enter the node elements: \n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);

                printf("Original Array : ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");

                start = clock();
                heapsort(arr, n);
                end = clock();

                printf("Array after performing heap sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\nTime taken to sort %d numbers is %f secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                n = 7500;
                while (n <= 14500) {
                    for (int i = 0; i < n; i++) {
                        arr[i] = n - i;
                    }
                    start = clock();
                    heapsort(arr, n);
                    end = clock();

                    // Dummy loop to create delay
                    for (int j = 0; j < 500000; j++) {
                        int temp = 38 / 600;
                    }

                    printf("Time taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n = n + 1000;
                }
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
