#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <= _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i >= _##i; --i)
#define mem(f,x) memset(f,x,sizeof(f))
//========================================================================
string s1, s2;
int f[1000005];
int main()
{
	cin >> s1;
	cin >> s2;
	f[0] = -1;
	int k = -1;
	FOR(i, 1, (int)s2.size() - 1) {
		while (k != -1 && s2[k + 1] != s2[i]) k = f[k];
		if (s2[k + 1] == s2[i]) k++;
		f[i] = k;
	}
	k = -1;
	FOR(i, 0, (int)s1.size() - 1) {
		while (k != -1 && s2[k + 1] != s1[i]) k = f[k];
		if (s2[k + 1] == s1[i]) k++;
		if (k == (int)s2.size() - 1) {
			cout << (i - k) + 1 << endl;
			k = f[k];
		}
	}
	FOR(i, 0, (int)s2.size() - 1) cout << f[i] + 1 << " ";
	cout << endl;
	return 0;
}