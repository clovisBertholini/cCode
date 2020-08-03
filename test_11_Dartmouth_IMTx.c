#include <stdio.h>
int main(void){
    int numberOfRobots, enginePower, resistance, weight, height;
    int armyPower = 0;
    scanf("%d", numberOfRobots);
    for (int i = 0; i < numberOfRobots; i++){
        scanf("%d%d%d%d", height, weight, resistance, enginePower);
        armyPower += (enginePower + resistance) * (weight - height);
    }
    printf("%d", armyPower);
    return 0;
}
