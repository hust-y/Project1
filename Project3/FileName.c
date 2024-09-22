#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//level1-1摆放货物
//只考虑一个货物一种通道
//处理不合理内容
int main()
{
    //定义货物种类，通道标号，货物单价和货物个数对应的变量
    char kind; char kindinspect;
    char goodsprint[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };//定义货物数组来处理不合理输入的货物类型
    int road;
    int price;
    int number;

setkind:
    printf("请输入货物种类(现有A-Z共26种货物)：");
    scanf(" %c", &kind);
    for (int i = 0; i < 26; i++)
    {
        char a = goodsprint[i];
        if (a == kind)
        {
            goto setroad;
        }
    }
    printf("不合理输入，请重试\n");
    goto setkind;

setroad:
    printf("请输入货物所在通道标号（现有1-5五个通道）：");
    scanf("%d", &road);
    if (road != 1 && road != 2 && road != 3 && road != 4 && road != 5)
    {
        printf("不合理输入，请重试\n");
        goto setroad;
    }
setprice:
    printf("请输入货物单价（单价为10元以下的正整数）：");
    scanf("%d", &price);
    if (price != 1 && price != 2 && price != 3 && price != 4 && price != 5
        && price != 6 && price != 7 && price != 8 && price != 9)
    {
        printf("错误输入，请重试");
        goto setprice;
    }
setnumber:
    printf("请输入货物个数(1到50的一个整数)：");
    scanf("%d", &number);

    if (number < 1 || number>50 || number != 1)
    {
    }
    //输出摆放结果
    printf("货物%c摆放在%d号通道，单价为%d元，摆放了%d个", kind, road, price, number);
    return 0;
}