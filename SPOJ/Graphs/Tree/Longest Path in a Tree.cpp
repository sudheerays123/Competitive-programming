#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
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
#define N 10005

vector<bool> visited(N,false);
vi depth(N,0);
vi adj[N];

void dfs(ll s){

    if(visited[s]) return;
    visited[s] = true;

    for(auto u : adj[s]){
        if(visited[u] == true) continue;
        depth[u] = depth[s]+1;
        dfs(u);
    }
}

int main() {

    fast;

    ll n;
    cin in n;

    fo(i,1,n-1){
        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    depth[1] = 0;
    dfs(1);

    ll next , maxdepth = 0;
    fo(i,1,n){
        if(depth[i] > maxdepth){
            maxdepth = depth[i];
            next = i;
        }
    }

    fill(depth.begin(),depth.end(),0);
    fill(visited.begin(),visited.end(),false);

    dfs(next);

    maxdepth = 0;

    fo(i,1,n) mmax(maxdepth,depth[i]);

    cout out maxdepth;

    return 0;
}
