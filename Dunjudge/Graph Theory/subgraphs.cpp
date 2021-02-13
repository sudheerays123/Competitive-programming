#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define foo(i,a,b,d) for(ll i = a; i <= b; i+=d)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vector<bool> visited(1000005);
vi adj[1000005];	

void dfs(ll s) {

	if (visited[s] == true) return;
	visited[s] = true;

	for (auto u : adj[s]) dfs(u);
}

int main() {

	ll n, m;
	cin in n in m;

	fo(i, 0, m - 1) {
		ll u, v;
		cin in u in v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll count = 0;

	fo(i, 0, n - 1) {

		if (visited[i] == true) continue;
		count++;

		dfs(i);
	}

	cout out count;
	return 0;
}
