#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b, i;
	cin >> a >> b;
	for(i = 1; i <= b; i++)
	{
		int c = 1;
		while(a >= c * pow(10, i)) c *= 10;
		cout << a / c % 10;
	}
	return 0;
}
