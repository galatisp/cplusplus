#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 19

double fact (double n) {
    if (n==0) return 1; else return fact(n-1) * n;
}

int main()
{
    double n, f;
    printf("Dose to n ");
    scanf("%lf", &n);
    f = fact(n);        
    printf("paragontiko = %lf\n", f);
    
   
  
}