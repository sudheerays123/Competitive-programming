#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
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

ll n;
vi dist(100005,INF);
vector<pair<ll,ll>> adj[100005];

void dijkstra(ll s){

	vector<bool> visited(100005);
	priority_queue<pair<ll,ll>> q;

	dist[s] = 0;
	q.push({0,s});

	while(!q.empty()){

		ll a = q.top().second;
		q.pop();

		if(visited[a] == true) continue;
		visited[a] = true;

		for(auto u : adj[a]){

			ll b = u.first;
			ll w = u.second;

			if(dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				q.push(mp(-dist[b],b));
			}
		}
	}
}


int main() {
	
	ll m;
	cin in n in m;

	fo(i,0,m-1){
		ll u,v,x;
		cin in u in v in x;
		adj[u-1].pb(mp(v-1,x));
		adj[v-1].pb(mp(u-1,x));
	}

	dijkstra(0);

	if(dist[n-1] == INF ) cout out "-1";
	else cout out dist[n-1];

	return 0;
}
