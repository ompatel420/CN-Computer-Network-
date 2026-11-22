#include <stdio.h>

int main(){
    char data[10][9], checksum[9];
    int n, i, j, sum = 0, value;

    printf("Enter number of data words: ");
    scanf("%d", &n);

    printf("Enter 8-bit binary data:\n");

    for (i = 0; i < n; i++){
        scanf("%8s", data[i]);
        value = 0;
        for (j = 0; j < 8; j++)
            value = value * 2 + (data[i][j] - '0');

        sum += value;
    }

    while (sum > 255)
        sum = (sum & 255) + (sum >> 8);

    value = (~sum) & 255;

    for (i = 7; i >= 0; i--){
        checksum[i] = (value % 2) + '0';
        value /= 2;
    }
    checksum[8] = '\0';
    printf("\nChecksum = %s\n", checksum);
    return 0;
}