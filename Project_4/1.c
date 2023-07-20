#include <stdio.h>
#include <stdlib.h>

#define N 2000 // number of values to be sorted
#define BUCKET_NUM 10 // number of buckets
#define RANGE 100 // range of numerical values in the array

int data[N+1], sortedData[N+1]; // data to be sorted, and data sorted
int bucket[BUCKET_NUM][N+1]; // bucket[i][0] stores the number of values in bucket i

void sort(int d[], int n) {
    int j, k, max, max_index, temp;
    for (j = n; j > 1; j--) {
        max = d[j];
        max_index = j;
        for (k = 1; k < j; k++) {
            if (d[k] > max) {
                max = d[k];
                max_index = k;
            }
        }
        temp = d[j];
        d[j] = max;
        d[max_index] = temp;
    }
}

int main() {
    int i, j, bucket_size, bucket_index;
    
    // generate N random integers in the range [0, RANGE-1]
    for (i = 1; i <= N; i++) {
        data[i] = rand() % RANGE;
    }

    // calculate bucket size and assign values to buckets
    bucket_size = RANGE / BUCKET_NUM;
    for (i = 1; i <= N; i++) {
        bucket_index = data[i] / bucket_size;
        bucket[bucket_index][++bucket[bucket_index][0]] = data[i];
    }

    // sort each bucket
    for (i = 0; i < BUCKET_NUM; i++) {
        sort(bucket[i], bucket[i][0]);
    }

    // concatenate sorted buckets into a single array
    int k = 1;
    for (i = 0; i < BUCKET_NUM; i++) {
        for (j = 1; j <= bucket[i][0]; j++) {
            sortedData[k++] = bucket[i][j];
        }
    }

    // print sorted array
    for (i = 1; i <= N; i++) {
        printf("sortedData[%d] = %d\n", i, sortedData[i]);
    }

    

	cout << "d[" << i << "]=" << sortedData[i] << endl;  
}