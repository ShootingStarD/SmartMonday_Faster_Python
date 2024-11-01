#include <stdio.h>
#include <time.h>

// Function to calculate the mean of an array
double calculate_mean_n_first_numbers(int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }
    return (double)sum / n;
}

int main()
{
    const int n = 1000000;
    const int num_runs = 100; // Number of runs to average the time

    // Measure computation time over multiple runs
    double total_time = 0;
    for (int run = 0; run < num_runs; run++)
    {
        clock_t start = clock();

        // Calculate the sum and mean
        calculate_mean_n_first_numbers(n);

        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    double mean_value = calculate_mean_n_first_numbers(n);
    // Calculate the mean time taken
    double mean_time = total_time / num_runs;
    printf("Mean value is : %f \n", mean_value);

    printf("Mean time taken: %f ms\n", mean_time * 1000);

    return 0;
}
