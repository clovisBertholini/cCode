#include <stdio.h>
int main(void){
    int boxes, matches;
    scanf("%d", &boxes);
    scanf("%d", &matches);
    printf("%d\n%d\n", boxes/matches, boxes%matches);
    return 0;
}
