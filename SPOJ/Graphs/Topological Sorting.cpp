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
#define N 105

int main() {

    fast;

    tc{

        ll n,m,s,t;
        cin in n in m in s in t;

        vi adj[n+5];
        vi indegree(n+5,0);

        fo(i,1,m){
            ll a,b;
            cin in a in b;

            adj[a].pb(b);
            indegree[b]++;
        }

        queue<ll> q;
        vi dp(n+5,0);

        q.push(s);
        dp[s] = 1;

        while(!q.empty()){

            ll a = q.front();
            q.pop();

            for(auto u : adj[a]){
                dp[u] += dp[a];
                dp[u] %= MOD;

                indegree[u]--;
                if(indegree[u] == 0) q.push(u);
            }
        }

        cout out dp[t]%MOD nextline;
    }

    return 0;
}
