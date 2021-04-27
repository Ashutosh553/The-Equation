/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10, B = 50;
const ll one = 1;

ll a[N];
ll sum[B][2], min_sum[B];

int main() {
	fast_cin();
	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cout << "Case #" << t << ": ";
		int n; ll m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int b = 0; b < B; ++b) {
			sum[b][0] = sum[b][1] = 0;
			for (int i = 1; i <= n; ++i) {
				if (!(a[i] & (one << b))) {
					sum[b][1] += (one << b);
				} else {
					sum[b][0] += (one << b);
				}
			}
			min_sum[b] = min(sum[b][0], sum[b][1]);
			if (b > 0) {
				min_sum[b] += min_sum[b - 1];
			}
		}
		if (min_sum[B - 1] > m) {
			cout << -1 << '\n';
			continue;
		}
		ll ans_sum = 0, k = 0;
		for (int b = B - 1; b >= 0; --b) {
			if (ans_sum + sum[b][1] + (b > 0 ? min_sum[b - 1] : 0) <= m) {
				ans_sum += sum[b][1];
				k |= (one << b);
			} else {
				ans_sum += sum[b][0];
			}
		}
		cout << k << '\n';
	}
}