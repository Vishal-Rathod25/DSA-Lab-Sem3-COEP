#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ----------- Bubble Sort ------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// ----------- Insertion Sort ------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ----------- Generate Random Array ------------
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // random numbers up to 9999
    }
}

int main() {
    srand(time(NULL)); // random seed

    int sizes[] = {1000, 2000, 5000, 10000, 20000};  // test input sizes
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("datafiles/sort_times.txt", "w");
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "# Size    Bubble    Insertion\n");

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int *arr1 = malloc(n * sizeof(int));
        int *arr2 = malloc(n * sizeof(int));

        // generate same random array for both algorithms
        generateArray(arr1, n);
        for (int i = 0; i < n; i++) arr2[i] = arr1[i];

        // Bubble sort timing
        clock_t start = clock();
        bubbleSort(arr1, n);
        clock_t end = clock();
        double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;

        // Insertion sort timing
        start = clock();
        insertionSort(arr2, n);
        end = clock();
        double insertion_time = (double)(end - start) / CLOCKS_PER_SEC;

        // Print + save
        printf("Size %d -> Bubble: %.5f sec, Insertion: %.5f sec\n",
               n, bubble_time, insertion_time);
        fprintf(fp, "%d %.5f %.5f\n", n, bubble_time, insertion_time);

        free(arr1);
        free(arr2);
    }

    fclose(fp);
    printf("\nResults saved to sort_times.txt\n");
    return 0;
}
