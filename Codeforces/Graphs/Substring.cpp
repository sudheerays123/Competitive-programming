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

int main() {

    fast;

    ll n,m;
    cin in n in m;

    vi indegree(n+5,0);
    vi adj[n+5];

    string s;
    cin in s;

    fo(i,1,m){
        ll a,b;
        cin in a in b;

        indegree[b]++;
        adj[a].pb(b);
    }

    queue<ll> q;
    vector<vi> dp(n+5,vi(26,0));
    // dp[i][j] = maximum number of occurrences of letter j when we end at i

    fo(i,1,n) {
        if(indegree[i] == 0) {
            q.push(i);
            dp[i][s[i-1]-'a'] = 1;
        }
    }

    ll cnt = 0;

    while(!q.empty()){
        ll a = q.front();
        q.pop();
        cnt++;

        for(auto u : adj[a]){
            fo(j,0,25){
                mmax(dp[u][j],dp[a][j]+(s[u-1]-'a' == j));
            }

            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    ll ans = 1;

    fo(i,1,n){
        fo(j,0,25){
            mmax(ans,dp[i][j]);
        }
    }

    if(cnt == n) cout out ans;
    else cout out "-1";

    return 0;
}
