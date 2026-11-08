#include <stdio.h>
double calculateSubtotal(double price, int quantity);
double calculateDiscount(double total);
double calculateFinalBill(double total, double discount);
int comparePrices(double price1, double price2);
void displayReceipt(double p1, int q1, double sub1,
double p2, int q2, double sub2,double total, double discount,double finalBill, int comparison);
int main(){
    double price1,price2;
    int quantity1,quantity2;
    double subtotal1,subtotal2;
    double total,discount,finalBill;
    int comparison;
    printf("===== FAST KARACHI CANTEEN =====\n");
    printf("Enter price of Item 1: Rs. ");
    scanf("%lf",&price1);
    printf("Enter quantity of Item 1: ");
    scanf("%d",&quantity1);
    printf("Enter price of Item 2: Rs. ");
    scanf("%lf",&price2);
    printf("Enter quantity of Item 2: ");
    scanf("%d",&quantity2);
    if (price1<0||price2<0||quantity1 < 0 || quantity2 < 0){
        printf("\nInvalid input! Negative values are not allowed.\n");
        return 0;
    }
    subtotal1=calculateSubtotal(price1,quantity1);
    subtotal2=calculateSubtotal(price2,quantity2);
    total=subtotal1+subtotal2;
    discount=calculateDiscount(total);
    finalBill=calculateFinalBill(total, discount);
    comparison=comparePrices(price1,price2);
    displayReceipt(price1,quantity1,subtotal1,price2,quantity2,subtotal2,total,discount,finalBill,comparison);
    return 0;
}
double calculateSubtotal(double price,int quantity){
    return price*quantity;
}
double calculateDiscount(double total){
    if (total>1000){
        return total*0.10;
    }
    return 0;
}
double calculateFinalBill(double total,double discount){
    return total-discount;
}
int comparePrices(double price1, double price2){
    if (price1>price2){
        return 1;
    }
    else if (price2>price1){
        return 2;
    }
    else{
        return 0;
    }
}
void displayReceipt(double p1,int q1,double sub1,double p2,int q2,double sub2,double total,double discount,double finalBill,int comparison){
    printf("\n========== CUSTOMER RECEIPT ==========\n");
    printf("\nItem 1 Price:       Rs. %.2f",p1);
    printf("\nItem 1 Quantity:    %d", q1);
    printf("\nItem 1 Subtotal:    Rs. %.2f",sub1);
    printf("\n\nItem 2 Price:       Rs. %.2f",p2);
    printf("\nItem 2 Quantity:    %d", q2);
    printf("\nItem 2 Subtotal:    Rs. %.2f", sub2);
    printf("\n--------------------------------------");
    printf("\nCombined Total:     Rs. %.2f",total);
    printf("\nDiscount:           Rs. %.2f",discount);
    printf("\nFinal Bill:         Rs. %.2f",finalBill);
    printf("\n\n");
    if (comparison==1){
        printf("Item 1 has the higher unit price.");
    }
    else if (comparison==2){
        printf("Item 2 has the higher unit price.");
    }
    else{
        printf("Both items have equal unit prices.");
    }
    printf("\n======================================\n");
    printf("Thank you for visiting FAST Canteen!\n");
}

