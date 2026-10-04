#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	for(int i = 2; i < a; i++)
	{
		if(a % i == 0)
		{
			cout << "F";
			return 0;
		}
	}
	if(a < 2) cout << "F";
	else cout << "T";
	return 0;
}
