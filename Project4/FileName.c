#include<stdio.h>
int main(void)//计数，观察是否能够连续撤回，但不允许撤回两步前进一步进而达到不断撤回的目的
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
            printf("已撤回\n");
        }
        else
            type++;
    case 3:
        if (strcmp(s, "back") == 0)
        {
            type--;
            printf("已撤回\n");
        }
    }
    printf("%d", type);
}