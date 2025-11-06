/*
NAME: STEPHEN GITHINJI
REG NO: CT101/G/26434/25
*/
#include <stdio.h>
#include <stdlib.h>

void writeInputFile() {
    FILE *fptr;
    int num, i;
    
    fptr = fopen("input .txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing!\n");
        exit(1);
    }
    printf("Enter 10 intergers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }
    
    fclose(fptr);
    printf("\nData succesfully written to input.txt\n\n");
    
}

void processFiles() {
    FILE *fin, *fout;
    int num, count = 0, sum =0;
    float average;
    
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input,txt for reading!\n");
        exit(1);
    }
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing!\n");
        fclose(fin);
        exit(1);
    }
    while (fscanf(fin, "%d", &num) == 1)
    {
        sum += num;
        count++;
    }
    if ( count == 0) {
        printf("No Data found in input.txt!\n");
        fclose(fin);
        fclose(fout);
        return;
    }
    average = (float)sum / count;
    fprintf(fout, "Sum = %d\nAverage = %.2f\n", sum, average);
    
    fclose(fin);
    fclose(fout);
    
    printf("Results written to output.txt\n\n");
    
}
void displayFiles() {
    FILE *fptr;
    char ch;
    
    printf("Contents of input.txt:\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
    putchar(ch);
    fclose(fptr);
    
    printf("\nContents of output. txt:\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
        fclose(fptr);
}
int main() {
    writeInputFile();
    processFiles();
    displayFiles();
    return 0;
}