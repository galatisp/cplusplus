#include <iostream>
int main()
{
    

    int myInt;
int result = scanf("%d", &myInt);

if (result == EOF) {
    /* ... you're not going to get any input ... */
}
if (result == 0) {
    while (fgetc(stdin) != '\n') // Read until a newline is found
        ;
}

printf("myInt =%d\n", myInt);
    


   
}