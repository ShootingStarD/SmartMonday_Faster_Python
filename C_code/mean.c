#include <stdio.h>
#include <time.h>

// Function to calculate the mean of an array
double calculate_mean(int *array, int length)
{
    long long sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (double)sum / length;
}

int main()
{
    const int length_of_list = 1000000;
    int my_list[length_of_list];
    const int num_runs = 100; // Number of runs to average the time

    // Populate the list
    for (int i = 0; i < length_of_list; i++)
    {
        my_list[i] = i;
    }

    // Measure computation time over multiple runs
    double total_time = 0;
    for (int run = 0; run < num_runs; run++)
    {
        clock_t start = clock();

        // Calculate the sum and mean
        calculate_mean(my_list, length_of_list);

        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    double mean_value = calculate_mean(my_list, length_of_list);
    // Calculate the mean time taken
    double mean_time = total_time / num_runs;
    printf("Mean value is : %f \n", mean_value);

    printf("Mean time taken: %f ms\n", mean_time * 1000);

    return 0;
}
