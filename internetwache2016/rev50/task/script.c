#include <stdio.h>

int main(void)
{
    int array[] = {73,86,121,78,53,85,51,88,41,90,85,77,89,67,115};
    int i;
    int value;

    printf("flag = ");
    for(i = 0; i < 15; i++)
    {
        value = array[i]^i;
        printf("%c", (char)value);
    }

}
