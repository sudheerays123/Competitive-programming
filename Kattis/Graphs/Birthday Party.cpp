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
#define N 105

vector<vector<bool>> adj(N,vector<bool>(N,false));
vector<bool> visited(N,false);
ll cnt = 0;
ll p,c;

void dfs(ll s){

    if(visited[s] == true ) return;
    visited[s] = true;

    cnt++;

    fo(i,0,p-1) if(adj[s][i] == true) dfs(i);

}

int main() {

    fast;

    while(true){

        cin in p in c;

        if(p+c == 0) break;

        fo(i,1,c){

            ll a,b;
            cin in a in b;

            adj[a][b] = true;
            adj[b][a] = true;
        }

        bool breakable = false;

        fo(i,0,p-1){
            fo(j,0,p-1){
                if(adj[i][j] == true){

                    adj[i][j] = false;
                    adj[j][i] = false;

                    cnt = 0;
                    visited.clear();
                    visited.resize(p+5,false);

                    dfs(0);

                    adj[i][j] = true;
                    adj[j][i] = true;

                    if(cnt != p){
                        breakable = true;
                        break;
                    }
                }
            }
            if(breakable == true) break;
        }

        if(breakable == false) cout out "NO\n";
        else cout out "YES\n";

        fo(i,0,p-1){
            fo(j,0,p-1){
                adj[i][j] = false;
            }
        }
    }

    return 0;
}
