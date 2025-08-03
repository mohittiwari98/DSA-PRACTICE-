//fractional knapsack prob
#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

int compareProfit(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->profit < item2->profit) return 1;
    return -1;
}

int compareWeight(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->weight > item2->weight) return 1;
    return -1;
}

int compareRatio(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    return -1;
}

float fractionalKnapsack(int n, int capacity, Item items[], int (*compare)(const void *, const void *)) {
    qsort(items, n, sizeof(Item), compare);
    float totalProfit = 0.0;
    int remainingCapacity = capacity;
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) break;
        if (items[i].weight <= remainingCapacity) {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            float fraction = (float)remainingCapacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            remainingCapacity = 0;
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("\nApproach 1: Largest Profit\n");
    float maxProfit = fractionalKnapsack(n, capacity, items, compareProfit);
    printf("Maximum profit: %.2f\n", maxProfit);

    printf("\nApproach 2: Smallest Weight\n");
    maxProfit = fractionalKnapsack(n, capacity, items, compareWeight);
    printf("Maximum profit: %.2f\n", maxProfit);

    printf("\nApproach 3: Largest Profit-to-Weight Ratio\n");
    maxProfit = fractionalKnapsack(n, capacity, items, compareRatio);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
