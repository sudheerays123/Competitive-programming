#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;for(ll t = 1; t <= test; t++)
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
#define N 2005

vector<bool> visited(N,false);
vi color(N,-1);
vi adj[N];
bool homo = false;

void dfs(ll s , ll c){

    if(visited[s]) return;
    visited[s] = true;

    color[s] = c;

    for(auto u : adj[s]) {

        if(color[u] == color[s]){
            homo = true;
            return;
        }

        dfs(u,c == 1 ? 2 : 1);
    }
}

int main() {

    fast;

    tc{

        ll n,m;
        cin in n in m;

        fo(i,1,m){
            ll a,b;
            cin in a in b;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        fo(i,1,n){
            if(visited[i] == true) continue;

            homo = false;
            dfs(i,1);

            if(homo == true) break;
        }

        cout out "Scenario #" out t out ":" nextline;
        if(homo == true) cout out "Suspicious bugs found!\n";
        else cout out "No suspicious bugs found!\n";

        fill(visited.begin(),visited.end(),false);
        fill(color.begin(),color.end(),-1);
        fo(i,1,n) adj[i].clear();

    }

    return 0;
}
