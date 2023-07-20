#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n, int num_buckets) {
    int i, j, k;
    int *bucket_sizes = (int*)calloc(num_buckets, sizeof(int));
    int **buckets = (int**)malloc(num_buckets * sizeof(int*));

    // Determine the range of numerical values in the array
    int min_val = array[0], max_val = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        }
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    // Divide the range into num_buckets equal parts
    float bucket_range = (max_val - min_val + 1) / (float)num_buckets;

    // Allocate memory for each bucket
    for (i = 0; i < num_buckets; i++) {
        bucket_sizes[i] = 0;
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    // Distribute values from the array to the buckets
    for (i = 0; i < n; i++) {
        j = (int)((array[i] - min_val) / bucket_range);
        buckets[j][bucket_sizes[j]++] = array[i];
    }

    // Sort the individual buckets
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            for (k = j + 1; k < bucket_sizes[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    // Append values from the buckets into the final sorted array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    // Free memory
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

int main() {
    int array[] = {22, 15, 28, 71, 10, 22, 18, 12, 26, 20};
    int n = sizeof(array) / sizeof(array[0]);
    int num_buckets = 4;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucket_sort(array, n, num_buckets);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}