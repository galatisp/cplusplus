#include <iostream>
using namespace std;
int main()
{
    int a, sum = 0, n=0;
    cout << "Δώσε έναν αριθμό" << endl;
    cin >> a;

    while (a > 0)
    {
        sum += a;
        n++;
        cout << "Δώσε έναν άλλο αριθμό" << endl;
        cin >> a;
    }
    if (n > 0){
        cout << "Αθροισμα " << double (sum) << endl;
         cout << "Μέσος Όρος " << double (sum)/n << endl;
    }
    else{
       cout << "Δε δόθηκαν αριθμοί " << endl; 
    }
    
}