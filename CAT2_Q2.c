/*
NAME:STEPHEN GITHINJI
REG NO:CT101/G/26434/25
*/
#include <stdio.h>

int main() {
    float hours, rate, grosspay, tax, netpay;
    
    printf("Enter hours worked in a week:");
    scanf ("%f", &hours);
    
    printf("Enter hourly wage:");
    scanf("%f", &rate);
    
    if (hours <= 40) {
        grosspay = hours * rate;
    }else {
        grosspay = (40 * rate) + ((hours - 40) * rate * 1.5);
    }
    
    if (grosspay <= 600) { tax = grosspay * 0.15;}
     else {
         tax = (600 * 0.15) + ((grosspay - 600) * 0,20);
     }
     netpay = grosspay - tax;
     
     printf("\nGross Pay: $%.2f\n", grosspay);
     printf("Taxes: $%.2f\n", tax);
     printf("Net Pay: $%.2f\n", netpay);
    
    

    return 0;
}