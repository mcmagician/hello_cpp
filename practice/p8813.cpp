#include <iostream>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	const long long LIMIT = 1000000000;
	if (a == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	long long res = 1;
	for (long long i = 1; i <= b; i++)
	{
		if (res > LIMIT / a)
		{
			cout << -1 << endl;
			return 0;
		}
		res *= a;
	}
	cout << res << endl;
	return 0;
}