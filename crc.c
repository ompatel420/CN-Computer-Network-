#include <stdio.h>
#include <string.h>

int main(){
    char data[100], divisor[30], temp[150], code[150];
    int i, j, n, m;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator bits: ");
    scanf("%s", divisor);

    n = strlen(data);
    m = strlen(divisor);

    strcpy(temp, data);

    for (i = 0; i < m - 1; i++)
        temp[n + i] = '0';

    temp[n + m - 1] = '\0';

    for (i = 0; i < n; i++){
        if (temp[i] == '1'){
            for (j = 0; j < m; j++){
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    strcpy(code, data);
    strncat(code, temp + n, m - 1);

    printf("CRC Remainder = %s\n", temp + n);
    printf("Transmitted Codeword = %s\n", code);
    return 0;
}