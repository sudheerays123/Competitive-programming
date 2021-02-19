#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
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
#define N 5005

int main() {

    ll n;
    cin in n;

    vi bfs(n+5);
    fo(i,0,n-1) cin in bfs[i];

    vi dfs(n+5);
    fo(i,0,n-1) cin in dfs[i];

    if(dfs[1] != bfs[1]){
        cout out "-1";
        return 0;
    }

    cout out 2*(n-1) - 1 nextline;

    fo(i,1,n-1) cout out dfs[i-1] space dfs[i] nextline;
    fo(i,2,n-1) cout out "1 " out bfs[i] nextline;

    return 0;
}
