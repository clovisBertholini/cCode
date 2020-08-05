#include <stdio.h>
int main(void){
    char letter;
    int i, j;
    scanf("%c", &letter);
    for (i = 0; i < 5; i++){
        for (j = 0; j < 9; j++){
            if (i == 0 && j == 4)
                printf("%c", letter);
            else if (i == 1 && (j > 2 && j < 6))
                printf("%c", letter);
            else if (i == 2 && (j > 1 && j < 7))
                printf("%c", letter);
            else if (i == 3 && (j > 0 && j < 8))
                printf("%c", letter);
            else if (i == 4)
                printf("%c", letter);
            else
                printf("+");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
