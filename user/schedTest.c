#include "types.h"
#include "stat.h"
#include "user.h"
#include "math.h"

#define DEBUG_MODE 1
#define RUN_MODE   0

// Function to calculate Armstrong numbers
int is_armstrong(int i) {
    // // Calculate the Armstrong numbers from 2 to the LIMIT
    int n = 2;
    int temp = 1;
    int digits = 0;
    int num_of_armstrong;

    for (int i = 2; i <= LIMIT; i++) {
        temp = 1;
        digits = 0;
        // Count the number of digits
        while (temp <= i) {
            digits++;
            temp *= 10;
        }

        // Zero sum for each calculation
        int sum = 0;
        temp = i;
        // Find each integer in the number and raise it to the power of digits
        while (temp > 0) {
            int d = temp % 10;
            temp /= 10;
            int result = pow(d, digits);
            sum += result;
        }
         // Check if the sum is equal to original number, if true number is an Armstrong number
        if (sum == i) {
            // printf("%d\n", i);
            numOfArmstrong++;
            // printf("Armstrong number is %d\n", numOfArmstrong);
        }
    }
    // printf("Armstrong number is %d\n", num_of_armstrong);
    // }
    return num_of_armstrong;
}

int main(int argc, char *argv[]) {
    int LIMIT = atoi(argv[1])


    // Set scheduler to debug
    set_sched_mode(DEBUG_MODE);

    // Create children with given priorities
    int priorities[8] = {0,0, 5,5, 10,10, 15,15};

    for (int i = 0; i < 8; i++) {
        int pid = priorities[i];
        if (pid == 0) {
            is_armstrong(i);
        }
    }

    // Reset scheduler to run
    set_sched_mode(RUN_MODE);

    return 0;
}
