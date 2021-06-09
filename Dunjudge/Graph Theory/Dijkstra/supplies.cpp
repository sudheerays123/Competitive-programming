#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
#define ll long long
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
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vi dist(1005,INF);
vector<pair<ll,ll>> adj[1005];
ll n;

void dijkstra(ll s){

	fo(i,0,n-1) dist[i] = INF;

	vector<bool> visited(1005,false);
	priority_queue<pair<ll,ll>> q;

	q.push({0,s});
	dist[s] = 0;

	while(!q.empty()){

		ll a = q.top().second;
		q.pop();

		if(visited[a] == true) continue;
		visited[a] = true;

		for(auto i : adj[a]){
			ll b = i.first;
			ll w = i.second;

			if(dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				q.push(mp(-dist[b],b));
			}
		}
	}
}

int main(){

    ll m,start,end;
    cin in n in m in start in end;

    fo(i,0,m-1){
    	ll u,v,c;
    	cin in u in v in c;

    	adj[u].pb(mp(v,c));
    } 

    dijkstra(start);

    ll going = dist[end];

    dijkstra(end);

    ll coming = dist[start];

    ll total = going + coming;

    if(going != INF && coming != INF) cout out total;
    else cout out -1;

    return 0;
}
