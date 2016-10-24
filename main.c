#include <stdio.h>
#include <time.h>

#define SIZE 10000

// declare assembler "function"
unsigned long long timestamp(void);

int i;
double a[SIZE][SIZE];
double b[SIZE][SIZE];
double c[SIZE][SIZE];

int main(int argc, char **argv)
{
    // start to count CPU clock cycles
    unsigned long long timerCpu = timestamp();
    // clip current time
    clock_t timerUtc = clock();

    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) {
            a[i][j] = b[i][j] + c[i][j];
        }
    }

    printf("Virtual time used, CPU clock cycles:\t %llu\n", timestamp() - timerCpu);
    printf("Real time used, sec:\t\t\t %lf\n", ((double)(clock() - timerUtc)) / CLOCKS_PER_SEC);
    return 0;
}
