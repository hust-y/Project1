#include <stdio.h>

void purchase(int price);

int main(void)
{
	char art[5];
	int chan[5], num[5], pri[5];
	for (int i = 0; i < 5 ; i++)//���û���
	{
		printf("������������ͨ�����������۸��԰ڷŻ��������s,��ֹͣ���û��ע���벻Ҫ��һ��ͨ���з��ò�ͬ�ֻ��\n");
		scanf(" %c", &art[i]);
		if (art[i] == 's')
			break;
		else
			scanf("%d%d%d", &chan[i], &num[i], &pri[i]);
	}
	a : printf("������������ͨ�����������Թ��򣻻�����sֹͣ����\n");
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
				printf("���ﲻ��\n");
				scanf(" %c", &article);
			}
		}
	}
	printf("��������%dԪ����Ͷ��1Ԫ��2Ԫ��5Ԫ����\n", total);
	purchase(total);
	printf("�ѹ��ϣ�����y,�Լ������򡣻�������s�˳�\n");
    char judge;
	scanf(" %c", &judge);
	if (judge == 'y')
		goto a;
	else if (judge == 's')
	{
		printf("лл�ݹ�\n");
		return 0;
	}
	else
		printf("������Ϸ��ַ�\n");
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
				printf("��Ͷ��1Ԫ��2Ԫ��5Ԫ\n");
				scanf("%d", &cash);
			} while (cash != 2 && cash != 1 && cash != 5);
			money += cash;
		}
	}
	int balance = money - price;
	printf("%d\n", balance);
}