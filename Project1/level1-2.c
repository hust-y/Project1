#include <stdio.h>

int main(void)
{
	printf("�������ܼ�\n");
	int price;
	int cash;
	int money = 0;
	scanf("%d", price);
	while (money < price)
	{
		scanf("%d", &cash);
		if (cash == 2 || cash == 1 || cash == 5)
		{
			money += cash;
		}
		else
		{

			do
			{
				printf("��Ͷ��1Ԫ��2Ԫ��5Ԫ\n");
				scanf("%d", &cash);
			} while (cash != 2 && cash != 1 && cash != 5);
			money += cash;
		}
	}
	int balance = money - price;
	printf("%d\n", balance);
	return 0;
}