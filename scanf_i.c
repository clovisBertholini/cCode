#include <stdio.h>

const int NUMBERS = 10;
int main(void){
	int numbers[NUMBERS], i = 0;
	char answer;
	while (i < NUMBERS){
		printf("\nType an integer number: ");
		scanf("%i", &numbers[i]);
		do{
			getchar();
			printf("\nDo you want type another one s/n? ");
			answer = getchar();
		}while (answer != 'n' && answer != 'N' && answer != 's' && answer != 'S');
		if (answer == 'n' || answer == 'N'){
			++i;
			break;
		}
		++i;
	}
	for (int c = 0; c < i; ++c)
		printf("\nnumbers[%i] = %i", c, numbers[c]);
	printf("\n");
}
