#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll n;
vi adj[100005];

ll longestPath(){

    queue<ll> nodep;
    vi dist(n+5,-INF);
    vi indegree(n+5,0);

    fo(i,0,n-1){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }

    fo(i,0,n-1){
        if(indegree[i] == 0){
            nodep.push(i);
            dist[i] = 0;
        }
    }

    while(!nodep.empty()){

        ll a = nodep.front();
        nodep.pop();

        for(auto k : adj[a]){

            mmax(dist[k],dist[a]+1);

            indegree[k]--;
            if(indegree[k] == 0) nodep.push(k);

        }
    }

    ll maxpath = -INF;
    fo(i,0,n-1) mmax(maxpath,dist[i]);

    return maxpath;

}

int main() {

    ll m;
    cin in n in m;

    fo(i,0,m-1){
        ll x,y;
        cin in x in y;
        adj[x-1].pb(y-1);
    }

    cout out longestPath();

    return 0;
}
