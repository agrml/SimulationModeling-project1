#include <stdio.h>
#include <time.h>

#define SIZE 10000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
// declare assembler "function"
unsigned long long timestamp(void);

int i;
double a[SIZE][SIZE];
double b[SIZE][SIZE];
double c[SIZE][SIZE];

enum {
    STEP = 8
};

int main(int argc, char **argv)
{
    // start to count CPU clock cycles
    unsigned long long timerCpu = timestamp();
    // clip current time
    clock_t timerUtc = clock();

    int j;
    for (i = 0; i < SIZE; i+=STEP) {
        for (j = 0; j < SIZE; j += STEP) {
            for (int ii = i; ii < MIN(i + STEP, SIZE); ii++) {
                for (int jj = j; jj < MIN(j + STEP, SIZE); jj++) {
                    a[ii][jj] = b[ii][jj] + c[ii][jj];
                }
            }
        }
    }

    printf("Virtual time used, CPU clock cycles:\t %llu\n", timestamp() - timerCpu);
    printf("Real time used, sec:\t\t\t %lf\n", ((double)(clock() - timerUtc)) / CLOCKS_PER_SEC);
    return 0;
}
