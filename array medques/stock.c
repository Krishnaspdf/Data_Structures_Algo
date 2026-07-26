#include <stdio.h>

// Function to calculate the maximum profit
int maxProfit(int prices[], int n)
{
    // Store the minimum price encountered so far
    int minPrice = prices[0];

    // Store the maximum profit
    int maxProfit = 0;

    // Traverse the array starting from the second day
    for (int i = 1; i < n; i++)
    {
        // If current price is lower than minimum price,
        // update the minimum price
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }

        // Calculate the profit if stock is sold today
        int profit = prices[i] - minPrice;

        // Update maximum profit if current profit is greater
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
    }

    // Return the maximum profit
    return maxProfit;
}

int main()
{
    // Input array representing stock prices
    int prices[] = {7, 1, 5, 3, 6, 4};

    // Calculate the number of elements
    int n = sizeof(prices) / sizeof(prices[0]);

    // Find the maximum profit
    int result = maxProfit(prices, n);

    // Display the result
    printf("Maximum Profit: %d\n", result);

    return 0;
}
