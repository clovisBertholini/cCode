#include <stdio.h>
int main(void)
{
    int i;
    int tableOf = 8;
    for (i = 0; i < 11; i++){
        printf("%dx%d = %d\n", i, tableOf, i * tableOf);
    }
    return 0;
}
