#include <stdio.h>
int main(void){
    int i, tableOf;
    scanf("%d", &tableOf);
    for (i = 0; i < 11; i++){
        printf("%dx%d = %d\n", i, tableOf, i * tableOf);
    }
    return 0;
}
