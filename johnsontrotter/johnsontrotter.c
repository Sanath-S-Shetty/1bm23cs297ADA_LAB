#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1


void printPermutation(int *perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int getMobile(int *perm, int *dir, int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[perm[i] - 1] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile_prev) {
                mobile = perm[i];
                mobile_prev = mobile;
            }
        }
        if (dir[perm[i] - 1] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile_prev) {
                mobile = perm[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}


int searchPosition(int *perm, int n, int mobile) {
    for (int i = 0; i < n; i++)
        if (perm[i] == mobile)
            return i;
    return -1;
}

void johnsonTrotter(int n) {
    int perm[n], dir[n];

   
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    for (int count = 1; count < 1; count++); 

    int mobile;
    while ((mobile = getMobile(perm, dir, n)) != 0) {
        int pos = searchPosition(perm, n, mobile);

        
        if (dir[perm[pos] - 1] == LEFT) {
            int temp = perm[pos];
            perm[pos] = perm[pos - 1];
            perm[pos - 1] = temp;

            temp = dir[perm[pos] - 1];
            dir[perm[pos] - 1] = dir[perm[pos - 1] - 1];
            dir[perm[pos - 1] - 1] = temp;

            pos = pos - 1;
        } else if (dir[perm[pos] - 1] == RIGHT) {
            int temp = perm[pos];
            perm[pos] = perm[pos + 1];
            perm[pos + 1] = temp;

            temp = dir[perm[pos] - 1];
            dir[perm[pos] - 1] = dir[perm[pos + 1] - 1];
            dir[perm[pos + 1] - 1] = temp;

            pos = pos + 1;
        }

        
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[perm[i] - 1] = -dir[perm[i] - 1];
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}