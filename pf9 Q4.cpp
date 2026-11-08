#include <stdio.h>
void wrongSwap(int a, int b){
    int temp;
    printf("\nInside wrongSwap():\n");
    printf("Address of a: %p\n", (void *)&a);
    printf("Address of b: %p\n", (void *)&b);
    temp = a;
    a = b;
    b = temp;
    printf("After swapping inside function:\n");
    printf("a = %d, b = %d\n", a, b);
}
void repairCounters(int *a, int *b){
    int temp;
    printf("\nInside repairCounters():\n");
    printf("Address of a: %p\n", (void *)&a);
    printf("Address stored in a: %p\n", (void *)a);
    printf("Address of b: %p\n", (void *)&b);
    printf("Address stored in b: %p\n", (void *)b);
    temp = *a;
    *a = *b;
    *b = temp;
}

void analyzeOccupancy(int daily[], int size,int *total, int *highest, int *lowest){
    *total = 0;
    *highest = *daily;
    *lowest = *daily;
    printf("\nInside analyzeOccupancy():\n");
    printf("Address of total parameter: %p\n", (void *)&total);
    printf("Address of original total: %p\n", (void *)total);
    printf("Address of highest parameter: %p\n", (void *)&highest);
    printf("Address of original highest: %p\n", (void *)highest);
    printf("Address of lowest parameter: %p\n", (void *)&lowest);
    printf("Address of original lowest: %p\n", (void *)lowest);
    for (int i = 0; i < size; i++){
        *total += *(daily + i);
        if (*(daily + i) > *highest){
            *highest = *(daily + i);
        }
        if (*(daily + i) < *lowest){
            *lowest = *(daily + i);
        }
    }
}

int main(){
    int wardA = 30;
    int wardB = 20;
    int x = 50;
    int y = 70;
    int daily[7] = {25, 30, 28, 35, 40, 32, 27};
    int total, highest, lowest;
    printf("===== WRONG SWAP: PASS BY VALUE =====\n");
    printf("\nBefore calling wrongSwap():\n");
    printf("x = %d, y = %d\n", x, y);
    printf("Address of x: %p\n", (void *)&x);
    printf("Address of y: %p\n", (void *)&y);
    wrongSwap(x, y);
    printf("\nAfter calling wrongSwap():\n");
    printf("x = %d, y = %d\n", x, y);
    printf("\n===== CORRECT SWAP: PASS BY ADDRESS =====\n");
    printf("\nBefore repair:\n");
    printf("Ward A = %d\n", wardA);
    printf("Ward B = %d\n", wardB);
    printf("Address of wardA: %p\n", (void *)&wardA);
    printf("Address of wardB: %p\n", (void *)&wardB);
    repairCounters(&wardA, &wardB);
    printf("\nAfter repair:\n");
    printf("Ward A = %d\n", wardA);
    printf("Ward B = %d\n", wardB);
    printf("\n===== WEEKLY OCCUPANCY ANALYSIS =====\n");
    analyzeOccupancy(daily, 7, &total, &highest, &lowest);
    printf("\nResults in main():\n");
    printf("Total Occupancy: %d\n", total);
    printf("Highest Occupancy: %d\n", highest);
    printf("Lowest Occupancy: %d\n", lowest);
    printf("\nAddresses in main():\n");
    printf("Address of total: %p\n", (void *)&total);
    printf("Address of highest: %p\n", (void *)&highest);
    printf("Address of lowest: %p\n", (void *)&lowest);
    return 0;
}

