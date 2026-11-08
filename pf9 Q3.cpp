#include <stdio.h>
int main(){
    int readings[7] = {12, 18, 25, 10, 30, 15, 20};
    int *ptr = readings;
    int *linkedMeter = NULL;
    int total = 0;
    int highest;
    int highestDay = 1;
    int threshold;
    printf("===== SMART METER MEMORY INSPECTOR =====\n");
    printf("\nDaily Readings and Memory Addresses:\n");
    for (int i = 0; i < 7; i++){
        printf("Day %d: %d units | Address: %p\n",
               i + 1, *(ptr + i), (void *)(ptr + i));
    }
    printf("\nMemory Address Differences:\n");
    for (int i = 0; i < 6; i++){
        printf("Day %d to Day %d: %td bytes\n",
               i + 1, i + 2,
               (char *)(ptr + i + 1) - (char *)(ptr + i));
    }
    printf("\nExplanation:\n");
    printf("Each reading is stored in an integer variable.\n");
    printf("Therefore, consecutive addresses are separated\n");
    printf("by sizeof(int) bytes.\n");
    highest = *ptr;
    for (int i = 0; i < 7; i++){
        total += *(ptr + i);
        if (*(ptr + i) > highest){
            highest = *(ptr + i);
            highestDay = i + 1;
        }
    }
    printf("\n===== WEEKLY ANALYSIS =====\n");
    printf("Weekly Total: %d units\n", total);
    printf("Highest Consumption: %d units\n", highest);
    printf("Highest Consumption Day: Day %d\n", highestDay);
    printf("\nEnter peak tariff threshold: ");
    scanf("%d", &threshold);
    for (int i = 0; i < 7; i++){
        if (*(ptr + i) > threshold){
            *(ptr + i) = *(ptr + i) * 2;
        }
    }
    printf("\n===== ADJUSTED READINGS =====\n");
    for (int i = 0; i < 7; i++){
        printf("Day %d: %d units\n", i + 1, *(ptr + i));
    }
    printf("\n===== LINKED METER CHECK =====\n");
    if (linkedMeter == NULL){
        printf("Linked meter is not assigned.\n");
        printf("Pointer cannot be dereferenced safely.\n");
    }
    linkedMeter = ptr + 2;
    if (linkedMeter != NULL){
        printf("\nLinked meter is now assigned to Day 3.\n");
        printf("Linked Meter Reading: %d units\n", *linkedMeter);
        printf("Linked Meter Address: %p\n",
               (void *)linkedMeter);
    }
    return 0;
}

