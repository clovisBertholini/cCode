#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
int main(void)
{
    float fahr, cel;
    cel = LOWER;
    printf("CELSIUS\tFAHRENHEIT\n");
    while (cel <= UPPER)
    {
        fahr = ((9.0 / 5.0) * cel) + 32;
        printf("%.0f\t\t%.1f\n", cel, fahr);
        cel += STEP;
    }
}
