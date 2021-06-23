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
#define N 10005

vector<bool> visited(N,false);
ll c = 0;
vi adj[N];

void dfs(ll s){

    if(visited[s]) return;
    visited[s] = true;

    c++;

    for(auto u : adj[s]) dfs(u);
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    fo(i,1,m){
        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    if(c == n && m == n-1) cout out "YES";
    else cout out "NO";

    return 0;
}
