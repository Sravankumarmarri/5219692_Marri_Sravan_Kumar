#include <stdio.h>
#include <stdlib.h>

// Function to find two indices
int* icecreamParlor(int m, int cost_count, int* cost, int* result_count) {
    // Allocate memory for result (2 indices)
    int* result = (int*)malloc(2 * sizeof(int));
    *result_count = 2;

    // Simple hashmap using array (value to index)
    // Since cost[i] <= 10^4 in HackerRank constraints
    int maxCost = 10000;
    int* map = (int*)calloc(maxCost + 1, sizeof(int));

    for (int i = 0; i < cost_count; i++) {
        int c = cost[i];
        int complement = m - c;

        if (complement >= 0 && map[complement] > 0) {
            // Found the pair
            result[0] = map[complement]; // stored index
            result[1] = i + 1;           // current index (1-based)
            free(map);
            return result;
        }

        // Store current value with 1-based index
        map[c] = i + 1;
    }

    free(map);
    return result;
}
