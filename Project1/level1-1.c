#include <stdio.h>

int main(void)
{
	char article;
	int channel, price, number;
	scanf(" %c %d %d %d", &article,&channel,&price,&number);
	printf("%d: ", channel);
	for (int i = 0; i < number; i++)
	{
		printf("%c", article);
	}
	printf(" %d\n", price);
	return 0;
}