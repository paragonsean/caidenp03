#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void calculate_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("The sum of the first %d natural numbers is: %d\n", n, sum);
}

void calculate_sum_of_cubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    printf("The sum of the cubes of the first %d natural numbers is: %d\n", n, sum);
}

int main() {
    int n = 10; // Change to 3 for n=3

    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("Failed to fork for child 1");
        exit(1);
    }

    if (pid1 == 0) {
        // Child 1: Calculate the sum of the first n natural numbers
        calculate_sum(n);
        exit(0);
    }

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("Failed to fork for child 2");
        exit(1);
    }

    if (pid2 == 0) {
        // Child 2: Calculate the sum of the cubes of the first n natural numbers
        calculate_sum_of_cubes(n);
        exit(0);
    }

    // Parent process waits for both child processes to complete
    wait(NULL);
    wait(NULL);

    printf("Parent process: Both child processes completed.\n");
    return 0;
}