#include <stdio.h>
int sqr(int a)
{
    return a*a;
}
void test(void)
{
    printf("Hello\n");
}
int main(void)
{
    test();
    printf("%d\n", sqr(20));
}