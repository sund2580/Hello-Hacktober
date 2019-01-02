#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	long int a[t];
	for(int i=0;i<t;i++)
	{
		cin >> a[i];
		if(a[i]%2==0)
		{
			cout << a[i]-1 << " ";
		}
		else cout << a[i] << " ";
	}
}
