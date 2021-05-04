#include <stdio.h>
int main()
{
    int x;
    int *ptr;
    x = 5;
    ptr = &x;
    printf("Διεύθυνση=%p\t Περιεχόμενο=%d\n", ptr, *ptr);
    ptr++;
    printf("Διεύθυνση=%p\t Περιεχόμενο=%d\n", ptr, *ptr);
    return 0;
}