#include <stdio.h>
int main(void)
{
    printf("Dear procrastinator,\n");
    printf("You still have to wait for %d days (%d minutes or %d seconds) before you can procrastinate!", 25-23, 60*24*(25-23), 60*(60*24*(25-23)));
}
