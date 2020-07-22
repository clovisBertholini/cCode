#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
int main(void)
{
    float fahr, cel;
    fahr = LOWER;
    printf("FAHRENHEIT\tCELSIUS\n");
    while (fahr <= UPPER)
    {
        cel = 5.0 * (fahr - 32.0) / 9.0;
        printf("%.0f\t\t%.1f\n", fahr, cel);
        fahr += STEP;
    }
}
