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
    int memoryn[3] = { 0 };//������ֲ���n������������p�������۸�c������ͨ��(���������λ�ö��������λ��Ҳ���Ǵ������ڵ�ֵ)��m����֧�����
    int memoryp[3] = { 0 };
    int memoryc[3] = { 0 };
    int memorym[3] = { 0 };
    int total = 0;
    int money = 0;

    printf("������������ͨ�����������۸��԰ڷŻ��������END,��ֹͣ���û���;������back�Գ��أ�ע���벻Ҫ��һ��ͨ���з��ò�ͬ�ֻ��\n");
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
            printf("�Ѵﳷ������\n");
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
        printf("������������ͨ�����������Թ��򣻻�����ENDֹͣ����;������back����\n");
        scanf(" %s", &s);
        while (strcmp(s, "END") != 0)
        {
            if (strcmp(s, "back") == 0 && type > 0 && memoryc[2] == 0)//����END
            {
                mem = stop;
                type = m(type, s);
                goto a;
            }
            else if (strcmp(s, "back") == 0 && type == 0)
            {
                printf("�Ѵﳷ������\n");
                scanf(" %s", &s);
            }
            else if (strcmp(s, "back") == 0 && type > 0 && memoryc[2] != 0)//��ѡ��״̬�¿��Գ��ص����
            {
                
                total -= memoryn[2] * memoryp[2];
                num[memoryc[2]] += memoryn[2];//�ظ���������
                for (int i = 0; i < 2; i++)//�ͷ�
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
            else//����ѡ��
            {
                scanf("%d%d", &channel, &memoryn[2]);
                for (int i = 0; i < 5; i++)//����
                {
                    if (channel == chan[i] && memoryn[2] <= num[i])
                    {
                        type = m(type, s);
                        for (int i = 0; i < 2; i++)//����
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
                    else if (channel == chan[i] && memoryn[2] > num[i])//���ѻ�������
                    {
                        printf("���ﲻ��\n");
                        scanf(" %s", &s);
                    }
                }
            }
        }
        mem++;
        printf("��������%dԪ����Ͷ��1Ԫ��2Ԫ��5Ԫ����\n", total);
        goto a;
    }
    case 6: {
        while (money < total)
        {
            scanf(" %s", s);
            if (strcmp(s, "back") == 0 && type > 0 && money == 0)//����END
            {
                mem = 5;
                type = m(type, s);
                goto a;
            }
            else if (strcmp(s, "back") == 0 && type == 0)
            {
                printf("�Ѵﳷ������\n");
            }
            else if (strcmp(s, "back") == 0 && type > 0 && money != 0)//�ڹ���״̬�¿��Գ��ص����
            {
                printf("�˳���Ǯ%d\n", memorym[2]);
                money -= memorym[2];
                for (int i = 0; i < 2; i++)//�ͷ�
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
                    printf("��Ͷ��Ӳ��\n");
                }
            }
        }
        int balance = money - total;
        printf("%d\n", balance);
        mem++;
        goto a;
    }
    case 7: {
        printf("�Ƿ���Ҫ�������������������yes,�����������END\n");
        scanf(" %s", s);
        if (strcmp(s, "yes") == 0) 
        {
            mem = 5;
            goto a;
        }
        else if (strcmp(s,"END") == 0)
        {
            printf("лл�ݹ�\n");
            return 0;
        }
        else
            printf("������Ϸ��ַ�\n");
    }
    }
}

int m(int type, char* s)//�������۲��Ƿ��ܹ��������أ���������������ǰ��һ�������ﵽ���ϳ��ص�Ŀ��
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
            printf("�ѳ���\n");
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
            printf("�ѳ���\n");
            return type;
        }
        return type;
    }
}