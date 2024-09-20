#include <stdio.h>

void purchase(int price);

int main(void)
{
	char art[5];
	int chan[5], num[5], pri[5];
	for (int i = 0; i < 5 ; i++)//放置货物
	{
		printf("请依次输入货物，通道，数量，价格，以摆放货物或输入s,以停止放置货物（注意请不要在一个通道中放置不同种货物）\n");
		scanf(" %c", &art[i]);
		if (art[i] == 's')
			break;
		else
			scanf("%d%d%d", &chan[i], &num[i], &pri[i]);
	}
	a : printf("请依次输入货物，通道，数量，以购买；或输入s停止购买\n");
	char article;
	int channel, number;
	int total = 0;
	scanf(" %c", &article);
	while (article != 's')
	{
		scanf("%d%d", &channel, &number);
		for (int i = 0; i < 5; i++)
		{
			if (channel == chan[i] && number <= num[i])
			{
				num[i] -= number;
				total += number * pri[i];
				scanf(" %c", &article);
			}
			else if (channel == chan[i] && number > num[i])
			{
				printf("货物不足\n");
				scanf(" %c", &article);
			}
		}
	}
	printf("您共消费%d元，请投币1元，2元或5元付款\n", total);
	purchase(total);
	printf("已购毕，输入y,以继续购买。或者输入s退出\n");
    char judge;
	scanf(" %c", &judge);
	if (judge == 'y')
		goto a;
	else if (judge == 's')
	{
		printf("谢谢惠顾\n");
		return 0;
	}
	else
		printf("请输入合法字符\n");
}

void purchase(int price)
{
	int cash;
	int money = 0;
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
				printf("请投入1元，2元或5元\n");
				scanf("%d", &cash);
			} while (cash != 2 && cash != 1 && cash != 5);
			money += cash;
		}
	}
	int balance = money - price;
	printf("%d\n", balance);
}