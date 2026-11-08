#include <stdio.h>
void displayHall1(int (*ptr)[4], int rows){
    printf("\n========== HALL 1 ==========\n");
    for (int i = 0; i < rows; i++){
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 4; j++){
            if (*(*(ptr + i) + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }
        printf("\n");
    }
}
int countVacantHall1(int (*ptr)[4], int rows){
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 4; j++){
            if (*(*(ptr + i) + j) == 0)
                count++;
        }
    }
    return count;
}
void displayHall2(int *ptr[], int sizes[], int rows){
    printf("\n========== HALL 2 ==========\n");
    for (int i = 0; i < rows; i++){
        printf("Row %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++){
            if (*(ptr[i] + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }
        printf("\n");
    }
}
int countVacantHall2(int *ptr[], int sizes[], int rows){
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < sizes[i]; j++){
            if (*(ptr[i] + j) == 0)
                count++;
        }
    }
    return count;
}
void bookSeat(int *ptr[], int sizes[], int rows){
    int row, seat;
    printf("\nEnter row number (1-3): ");
    scanf("%d", &row);
    if (row < 1 || row > rows){
        printf("Error: Invalid row number!\n");
        return;
    }
    printf("Enter seat number (1-%d): ", sizes[row - 1]);
    scanf("%d", &seat);
    if (seat < 1 || seat > sizes[row - 1]){
        printf("Error: Invalid seat number for this row!\n");
        return;
    }
    if (*(ptr[row - 1] + seat - 1) == 1){
        printf("Error: This seat is already booked!\n");
        return;
    }
    *(ptr[row - 1] + seat - 1) = 1;
    printf("\nSeat booked successfully!\n");
}
int main(){
    int hall1[3][4] ={
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 1}
    };
    int frontRow[3] = {1, 0, 1};
    int middleRow[5] = {0, 1, 0, 0, 1};
    int backRow[7] = {1, 0, 0, 1, 0, 0, 1};
    int *hall2[] = {frontRow, middleRow, backRow};
    int rowSizes[] = {3, 5, 7};
    int (*rowPtr)[4] = hall1;
    displayHall1(rowPtr, 3);
    printf("Vacant seats in Hall 1: %d\n",countVacantHall1(rowPtr, 3));
    displayHall2(hall2, rowSizes, 3);
    printf("Vacant seats in Hall 2: %d\n",countVacantHall2(hall2, rowSizes, 3));
    bookSeat(hall2, rowSizes, 3);
    printf("\n===== UPDATED HALL 2 =====\n");
    displayHall2(hall2, rowSizes, 3);
    printf("Updated vacant seats in Hall 2: %d\n",countVacantHall2(hall2, rowSizes, 3));
    return 0;
}

