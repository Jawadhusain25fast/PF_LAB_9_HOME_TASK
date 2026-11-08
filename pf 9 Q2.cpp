#include <stdio.h>
#define SIZE 10
int calculateTotal(int marks[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += marks[i];
    }
    return total;
}
int findHighest(int marks[], int size){
    int highest = marks[0];
    for (int i = 1; i < size; i++){
        if (marks[i] > highest){
            highest = marks[i];
        }
    }
    return highest;
}
int findLowest(int marks[], int size){
    int lowest = marks[0];
    for (int i = 1; i < size; i++){
        if (marks[i] < lowest){
            lowest = marks[i];
        }
    }
    return lowest;
}
int countPass(int marks[], int size, int threshold){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (marks[i] >= threshold){
            count++;
        }
    }
    return count;
}
int countTopScorers(int marks[], int size){
    int highest = findHighest(marks, size);
    int count = 0;
    for (int i = 0; i < size; i++){
        if (marks[i] == highest){
            count++;
        }
    }
    return count;
}
void displayReport(int marks[], int size, int threshold){
    int total = calculateTotal(marks, size);
    int highest = findHighest(marks, size);
    int lowest = findLowest(marks, size);
    int passed = countPass(marks, size, threshold);
    int topScorers = countTopScorers(marks, size);
    printf("\n========== MARKS REPORT ==========\n");
    printf("Class Total: %d\n", total);
    printf("Class Average: %.2f\n", (float)total / size);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Students Passed: %d\n", passed);
    printf("Students Sharing Top Marks: %d\n", topScorers);
    printf("==================================\n");
}
void applyBonus(int marks[], int size, int bonus){
    for (int i = 0; i < size; i++){
        marks[i] += bonus;
        if (marks[i] > 100){
            marks[i] = 100;
        }
    }
}
int main(){
    int marks[SIZE];
    int threshold, bonus;
    printf("Enter marks of 10 students (0-100):\n");
    for (int i = 0; i < SIZE; i++){
        do{
            printf("Enter marks for student %d: ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100){
                printf("Invalid marks! Enter marks between 0 and 100.\n");
            }
        } while (marks[i] < 0 || marks[i] > 100);
    }
    do{
        printf("\nEnter passing threshold (0-100): ");
        scanf("%d", &threshold);
        if (threshold < 0 || threshold > 100){
            printf("Invalid threshold! Try again.\n");
        }
    } while (threshold < 0 || threshold > 100);
    printf("\n*** ORIGINAL MARKS ANALYSIS ***\n");
    displayReport(marks, SIZE, threshold);
    do{
        printf("\nEnter moderation bonus (0-100): ");
        scanf("%d", &bonus);
        if (bonus < 0 || bonus > 100){
            printf("Invalid bonus! Try again.\n");
        }
    } while (bonus < 0 || bonus > 100);
    applyBonus(marks, SIZE, bonus);
    printf("\n*** MODERATED MARKS ANALYSIS ***\n");
    displayReport(marks, SIZE, threshold);
    return 0;
}

