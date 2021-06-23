#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
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
#define N 1000005

vi adj[N];
bool possible = true;
vector<bool> visited(N,false);

void bfs(ll s ,ll st){

    queue<pair<ll,ll>> q;

    if(visited[s]){
        possible = false;
        return;
    }

    q.push({s,st});
    visited[s] = true;

    while(!q.empty()){

        ll a = q.front().first;
        ll t = q.front().second;

        q.pop();

        if(t == 0) continue;

        for(auto u : adj[a]){
            if(visited[u] == false){
                visited[u] = true;
                q.push({u,t-1});
            }
        }
    }
}

int main() {

    fast;

    tc{

        ll n,r,m;
        cin in n in r in m;

        fo(i,0,r-1){
            ll a,b;
            cin in a in b;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        fo(i,0,m-1){

            ll city , strength;
            cin in city in strength;

            if(possible == true ) bfs(city,strength);
        }

        fo(i,1,n) {
            if(visited[i] == false){
                possible = false;
                break;
            }
        }

        if(possible == true) cout out "Yes\n";
        else cout out "No\n";

        possible = true;
        visited.clear(); visited.resize(N);
        fo(i,1,n) adj[i].clear();
    }

    return 0;
}
