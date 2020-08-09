#include <stdio.h>
int main(void){
    double celsius;
    scanf("%lf", &celsius);
    printf("%.1lf\n", celsius * 9.0 / 5.0 + 32.0);
}
