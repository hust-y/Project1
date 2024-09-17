#include <stdio.h>

int purchase(int price,int number);

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
	if (number == 0)
	{
		printf("售罄\n");
	}
	else
	{
		do
		{
			number = purchase(price, number);
			printf("%c\n", article);
		} while (number > 0);
	}
	return 0;
}
int purchase(int price, int number)
{
	int cash;
	int money = 0;
	while (money < price)
	{
		scanf("%d", &cash);
		if (cash == 2 ||cash == 1 || cash == 5)
		{
			money += cash;
		}
		else
		{

			do
			{
				printf("请投入1元，2元或5元\n");
				scanf("%d", &cash);
			} while (cash != 2 && cash != 1 && cash != 5);
			money += cash;
		}
	}
	int balance = money - price;
	printf("%d\n", balance);
	number = number - 1;
	return  number;
}