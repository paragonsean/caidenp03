#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5 // 5 threads to handle 20 elements
#define ELEMENTS_PER_THREAD 4 // Each thread processes 4 elements

// Global array and result storage
int array[20] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2};
int partial_sums[NUM_THREADS] = {0}; // Array to store partial sums

// Thread function
void* ComputeSum(void* threadid) {
    long tid = (long)threadid; // Thread ID
    int start_index = tid * ELEMENTS_PER_THREAD;
    int end_index = start_index + ELEMENTS_PER_THREAD;

    // Compute sum of elements assigned to this thread
    for (int i = start_index; i < end_index; i++) {
        partial_sums[tid] += array[i];
    }

    printf("Thread %ld calculated sum: %d\n", tid, partial_sums[tid]);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads to compute partial sums
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, ComputeSum, (void*)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Compute the total sum from partial sums
    int total_sum = 0;
    for (t = 0; t < NUM_THREADS; t++) {
        total_sum += partial_sums[t];
    }

    printf("Total sum of array elements: %d\n", total_sum);
    return 0;
}