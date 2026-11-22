#include <stdio.h>
#include <string.h>

int main(){
    char data[100], stuffed[200], destuffed[100];
    int i, j = 0, k = 0, count = 0;

    printf("Enter the data bit string: ");
    scanf("%s", data);

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

    stuffed[j] = '\0';
    printf("\nAfter Bit Stuffing: %s", stuffed);
    count = 0;

    for (i = 0; i < strlen(stuffed); i++){
        destuffed[k++] = stuffed[i];

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

    destuffed[k] = '\0';
    printf("\nAfter Bit Destuffing: %s\n", destuffed);
    return 0;
}