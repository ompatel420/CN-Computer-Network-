#include <stdio.h>
#include <string.h>

int main(){
    char data[100], stuffed[200], destuffed[100];
    int i, j = 0, k = 0, count = 0;

    printf("Enter data: ");
    scanf("%s", data);

    strcpy(stuffed, "01111110");
    j = strlen(stuffed);

    for (i = 0; i < strlen(data); i++){
        stuffed[j++] = data[i];

        if (data[i] == '1'){
            count++;
            if (count == 5){
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else{
            count = 0;
        }
    }

    strcpy(stuffed + j, "01111110");
    printf("\nAfter Bit Stuffing: %s", stuffed);
    count = 0;
    j = 0;
    for (i = 8; i < strlen(stuffed) - 8; i++){
        destuffed[j++] = stuffed[i];

        if (stuffed[i] == '1'){
            count++;
            if (count == 5){
                i++;
                count = 0;
            }
        }
        else{
            count = 0;
        }
    }

    destuffed[j] = '\0';
    printf("\nAfter Bit Destuffing: %s\n", destuffed);
    return 0;
}