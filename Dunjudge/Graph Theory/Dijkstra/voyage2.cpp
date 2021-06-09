#include <iostream>
#include<vector>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
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

vi dist(200005,INF);
vi adj[200005];
ll n;

void dijkstra(ll s){

    priority_queue<pair<ll,ll>> q;
    vector<bool> visited(n+5,false);

    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){

        ll a= q.top().second;
        q.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            if(dist[a]+1 < dist[u]){
                dist[u] = dist[a]+1;
                q.push({-dist[u],u});
            }
        }
    }

}

int main() {

    ll m;
    cin in n in m;


    fo(i,0,m-1){
        ll u,v;
        cin in u in v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }

    dijkstra(0);

    if(dist[n-1] == 2 ) cout out "POSSIBLE";
    else cout out "IMPOSSIBLE";

    return 0;
}
