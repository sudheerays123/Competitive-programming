#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
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
#define N 10005

vector<pair<ll,ll>> adj[N];

ll dijkstra(ll s , ll t){

    priority_queue<pair<ll,ll>> q;
    vector<bool> visited(N);
    vi dist(N,INF);

    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){

        ll a = q.top().second;
        q.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            ll w = u.second;

            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }
    }

    return dist[t];
}

int main() {

    tc{

        ll n;
        cin in n;

        map<string,ll> m;

        fo(i,1,n){
            string s;
            ll p;

            cin in s;
            m[s] = i;

            cin in p;
            fo(j,0,p-1){
                ll x,c;
                cin in x in c;

                adj[i].pb(mp(x,c));
            }
        }

        ll q;
        cin in q;

        while(q--){
            string first , second;
            cin in first in second;

            cout out dijkstra(m[first],m[second]) nextline ;
        }

        fo(i,1,n) adj[i].clear();
    }

    return 0;

}
