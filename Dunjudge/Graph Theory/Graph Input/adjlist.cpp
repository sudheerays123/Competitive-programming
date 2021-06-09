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

int main() {

	ll n,m;
    cin in n in m;

    vi adj[n+5];

    fo(i,0,m-1) {
        ll u, v;
        cin in u in v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fo(i,1,n){
    	if(!adj[i].size()) {
    		cout << "\n";
    		continue;
    	}
        fo(j,0,adj[i].size()-1){
        	if(j != adj[i].size()-1) cout out adj[i][j] spacef;
        	else cout out adj[i][j];
        }
        cout nextline;
    }

	return 0;
}
