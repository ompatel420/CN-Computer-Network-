#include <stdio.h>
#include <string.h>

int main(){
    char code[20][100];
    int n, i, j, k, count, min = 100;

    printf("Enter number of codewords: ");
    scanf("%d", &n);

    printf("Enter codewords:\n");

    for (i = 0; i < n; i++)
        scanf("%s", code[i]);

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            count = 0;
            for (k = 0; k < strlen(code[i]); k++){
                if (code[i][k] != code[j][k])
                    count++;
            }

            if (count < min)
                min = count;
        }
    }

    printf("Minimum Hamming Distance = %d\n", min);
    return 0;
}