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
#define N 100005

vector<bool> visited(N,false);
vi adj[N];

void dfs(ll s){
    if(visited[s] == true) return;
    visited[s] = true;

    for(auto u : adj[s]) dfs(u);
}

int main() {

    fast;

    tc{
        ll n,m;
        cin in n in m;

        fo(i,1,m){
            ll a,b;
            cin in a in b;

            adj[a+1].pb(b+1);
            adj[b+1].pb(a+1);
        }

        ll cnt = 0;

        fo(i,1,n){
            if(visited[i] == true) continue;
            cnt++;
            dfs(i);
        }

        cout out cnt nextline;

        fill(visited.begin(),visited.end(),false);
        fo(i,1,n) adj[i].clear();
    }

    return 0;
}
