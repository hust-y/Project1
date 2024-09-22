#include <stdio.h>
#include<string.h>

int m(int type, char* s);

int main(void)
{
    char s[5];
    char art[5];
    int chan[5], num[5], pri[5],stop;
    int type = 0;
    int mem = 0;
    int channel = 0;
    int memoryn[3] = { 0 };//记忆各种参量n代表购货数量，p代表购货价格，c代表购货通道(不是输入的位置而是数组的位置也就是代表【】内的值)，m代表支付金额
    int memoryp[3] = { 0 };
    int memoryc[3] = { 0 };
    int memorym[3] = { 0 };
    int total = 0;
    int money = 0;

    printf("请依次输入货物，通道，数量，价格，以摆放货物或输入END,以停止放置货物;或输入back以撤回（注意请不要在一个通道中放置不同种货物）\n");
    a: switch (mem)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4: {
        scanf(" %s", &s);
        if (strcmp(s, "back") == 0 && type > 0)
        {
            mem--;
            type = m(type, s);
            goto a;
        }
        else if (strcmp(s, "back") == 0 && type == 0)
        {
            printf("已达撤回上限\n");
            goto a;
        }
        else if (strcmp(s,"END") == 0)
        {
            stop = mem;
            type = m(type, s);
            mem = 5;
            goto a;
        }
        else
        {
            stop = mem;
            type = m(type, s);
            scanf("%d%d%d", &chan[mem], &num[mem], &pri[mem]);
            mem++;
            goto a;
        }
    }
    case 5: {
        printf("请依次输入货物，通道，数量，以购买；或输入END停止购买;或输入back撤回\n");
        scanf(" %s", &s);
        while (strcmp(s, "END") != 0)
        {
            if (strcmp(s, "back") == 0 && type > 0 && memoryc[2] == 0)//撤回END
            {
                mem = stop;
                type = m(type, s);
                goto a;
            }
            else if (strcmp(s, "back") == 0 && type == 0)
            {
                printf("已达撤回上限\n");
                scanf(" %s", &s);
            }
            else if (strcmp(s, "back") == 0 && type > 0 && memoryc[2] != 0)//在选货状态下可以撤回的情况
            {
                
                total -= memoryn[2] * memoryp[2];
                num[memoryc[2]] += memoryn[2];//回复货物数量
                for (int i = 0; i < 2; i++)//释放
                {
                    memoryc[i + 1] = memoryc[i];
                    memoryp[i + 1] = memoryp[i];
                    memoryn[i + 1] = memoryn[i];
                }
                memoryc[0] = 0;
                memoryp[0] = 0;
                memoryn[0] = 0;
                type = m(type, s);
            }
            else//正常选货
            {
                scanf("%d%d", &channel, &memoryn[2]);
                for (int i = 0; i < 5; i++)//购买
                {
                    if (channel == chan[i] && memoryn[2] <= num[i])
                    {
                        type = m(type, s);
                        for (int i = 0; i < 2; i++)//储存
                        {
                            memoryc[i] = memoryc[i + 1];
                            memoryp[i] = memoryp[i + 1];
                            memoryn[i] = memoryn[i + 1];
                        }
                        memoryc[2] = i;
                        num[i] -= memoryn[2];
                        total += memoryn[2] * pri[i];
                        scanf(" %s", &s);
                    }
                    else if (channel == chan[i] && memoryn[2] > num[i])//提醒货物售罄
                    {
                        printf("货物不足\n");
                        scanf(" %s", &s);
                    }
                }
            }
        }
        mem++;
        printf("您共消费%d元，请投币1元，2元或5元付款\n", total);
        goto a;
    }
    case 6: {
        while (money < total)
        {
            scanf(" %s", s);
            if (strcmp(s, "back") == 0 && type > 0 && money == 0)//撤回END
            {
                mem = 5;
                type = m(type, s);
                goto a;
            }
            else if (strcmp(s, "back") == 0 && type == 0)
            {
                printf("已达撤回上限\n");
            }
            else if (strcmp(s, "back") == 0 && type > 0 && money != 0)//在购买状态下可以撤回的情况
            {
                printf("退出零钱%d\n", memorym[2]);
                money -= memorym[2];
                for (int i = 0; i < 2; i++)//释放
                {
                    memorym[i + 1] = memorym[i];
                }
                memorym[0] = 0;
                type = m(type, s);
            }
            else
            {
                switch (s[0])
                {
                case '1':
                case '2':
                case '5': {
                    for (int i = 0; i < 2; i++)
                    {
                        memorym[i] = memorym[i + 1];
                    }
                    memorym[2] = (int)s[0] - '0';
                    type = m(type, s);
                    money += memorym[2];
                    continue;
                }
                default:
                    printf("请投入硬币\n");
                }
            }
        }
        int balance = money - total;
        printf("%d\n", balance);
        mem++;
        goto a;
    }
    case 7: {
        printf("是否想要继续购买，如果是请输入yes,如果不是输入END\n");
        scanf(" %s", s);
        if (strcmp(s, "yes") == 0) 
        {
            mem = 5;
            goto a;
        }
        else if (strcmp(s,"END") == 0)
        {
            printf("谢谢惠顾\n");
            return 0;
        }
        else
            printf("请输入合法字符\n");
    }
    }
}

int m(int type, char* s)//计数，观察是否能够连续撤回，但不允许撤回两步前进一步进而达到不断撤回的目的
{
    switch (type)
    {
    case 0:
        if (strcmp(s, "back") == 0)
            return 0;
        else
        {
            type++;
            return type;
        }
    case 1:
    case 2:
        if (strcmp(s, "back") == 0)
        {
            type--;
            printf("已撤回\n");
            return type;
        }
        else
        {
            type++;
            return type;
        }
    case 3:
        if (strcmp(s, "back") == 0)
        {
            type--;
            printf("已撤回\n");
            return type;
        }
        return type;
    }
}