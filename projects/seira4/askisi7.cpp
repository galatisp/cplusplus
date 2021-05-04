#include <iostream>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#define N 10
using namespace std;


typedef int list[N];


int minimum(list a)
{
    int min = a[0];
    for (int i = 1; i< N; i++){
        if (a[i]<min) 
            min = a[i];
    }
  return min;  
}

int maximum(list a)
{
    int max = a[0];
    for (int i = 1; i< N; i++){
        if (a[i]>max) 
            max = a[i];
    }
    return max;
}

int main()
{

    list mylist;
    int num;

    cout << "Dose " << N <<" arithmous\n";

    for (int i = 0; i < N; i++)
    {
       cin >> mylist[i];
      
    }

    cout << "elaxistos :"<< minimum(mylist) << endl;

    cout << "megistos :"<< maximum(mylist) << endl;
}