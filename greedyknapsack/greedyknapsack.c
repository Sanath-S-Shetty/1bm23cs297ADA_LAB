#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item2->ratio > item1->ratio) return 1;
    else if (item2->ratio < item1->ratio) return -1;
    else return 0;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].value);
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].value / items[i].weight;

    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    int currWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currWeight + items[i].weight <= W) {
            currWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = W - currWeight;
            totalValue += items[i].ratio * remain;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}