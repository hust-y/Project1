#include<stdio.h>
int main(void)//�������۲��Ƿ��ܹ��������أ���������������ǰ��һ�������ﵽ���ϳ��ص�Ŀ��
{
    int type;
    char* s;
    scanf(" %s%d", &s, &type);
    switch (type)
    {
    case 0:
        if (strcmp(s, "back") == 0)
            return 0;
        else
        {
            type++;
        }
    case 1:
    case 2:
        if (strcmp(s, "back") == 0)
        {
            type--;
            printf("�ѳ���\n");
        }
        else
            type++;
    case 3:
        if (strcmp(s, "back") == 0)
        {
            type--;
            printf("�ѳ���\n");
        }
    }
    printf("%d", type);
}