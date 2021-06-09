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

    ll n1,n2,m1,m2;
    cin in n1 in n2 in m1 in m2;

    vi adj1[n1+5];
    vi indegree1(n1+5,0);
    set<ll> possible1[n1+5];

    vi adj2[n2+5];
    vi indegree2(n2+5,0);
    set<ll> possible2[n2+5];

    fo(i,1,m1){
        ll a,b;
        cin in a in b;

        indegree1[b]++;
        adj1[a].pb(b);
    }

    fo(i,1,m2){
        ll a,b;
        cin in a in b;

        indegree2[b]++;
        adj2[a].pb(b);
    }

    queue<ll> q1;

    q1.push(1);
    possible1[1].insert(0);

    while(!q1.empty()){
        ll a = q1.front();
        q1.pop();

        for(auto u : adj1[a]){
            for(auto r : possible1[a]){
                possible1[u].insert(r+1);
            }

            indegree1[u]--;
            if(indegree1[u] == 0) q1.push(u);
        }
    }

    queue<ll> q2;

    q2.push(1);
    possible2[1].insert(0);

    while(!q2.empty()){
        ll a = q2.front();
        q2.pop();

        for(auto u : adj2[a]){
            for(auto r : possible2[a]){
                possible2[u].insert(r+1);
            }

            indegree2[u]--;
            if(indegree2[u] == 0) q2.push(u);
        }
    }

    vector<bool> possible(2005,false);

    for(auto u : possible1[n1]){
        for(auto w : possible2[n2]){
            if(u+w <= 2001 ) possible[u+w] = true;
        }
    }

    ll q;
    cin in q;

    while(q--){
        ll x;
        cin in x;

        if(possible[x] == true) cout out "Yes\n";
        else cout out "No\n";
    }

    return 0;
}
