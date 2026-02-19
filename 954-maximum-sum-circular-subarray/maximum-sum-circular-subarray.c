#include <stdio.h>
#include <math.h>

// Helper function to find max of two numbers
int max(int a, int b) { return (a > b) ? a : b; }
// Helper function to find min of two numbers
int min(int a, int b) { return (a < b) ? a : b; }

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int maxSoFar = nums[0], currentMax = 0;
    int minSoFar = nums[0], currentMin = 0;

    for (int i = 0; i < numsSize; i++) {
        // Standard Kadane's for Max Subarray
        currentMax = max(nums[i], currentMax + nums[i]);
        maxSoFar = max(maxSoFar, currentMax);

        // Standard Kadane's for Min Subarray
        currentMin = min(nums[i], currentMin + nums[i]);
        minSoFar = min(minSoFar, currentMin);

        totalSum += nums[i];
    }

    // Edge Case: If all numbers are negative, maxSoFar will be the 
    // largest single element. We return that instead of 0.
    if (maxSoFar < 0) {
        return maxSoFar;
    }

    // Return the better of the two: Normal Max or Circular Max
    return max(maxSoFar, totalSum - minSoFar);
}