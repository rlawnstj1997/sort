#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	array<int, 10001> a = { 0 };

	int T,n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		a[n]++;
	}
	
	for (int i = 1; i < a.size(); i++)
	{
		for (int n = 0; n < a[i]; n++)
		{
			cout << i << '\n';
		}
	}
	cout << endl;
	
	
	return 0;
}
