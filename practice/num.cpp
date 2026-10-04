#include <iostream>
using namespace std;
int main()
{
    int a, i, sum = 0;
    cin >> a;
    for(i = 1; i <= 10000000; i *= 10) if(a / i % 10 == 1) sum++;
    cout << sum;
    return 0;
}
