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
vi adj[105];

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
            dist[i] = 1;
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

bool sufficientlyclose(string a , string b){

    // removing a letter

    if(a.size() - 1 == b.size()){

        fo(removedpos,0,a.size()-1){
            string u;
            fo(i,0,a.size()-1) if(i != removedpos) u.pb(a[i]);
            if(u == b) return true;
        }
    }

    // modifying a letter

    if(a.size() == b.size()) {

        ll cnt = 0 , pos;
        char r , rr;

        fo(i,0,a.size()-1){
            if(a[i] != b[i]) {
                cnt++;
                r = a[i];
                rr = b[i];
                pos = i;
            }
        }

        if(cnt > 1 || r > rr) return false;

        bool found = false;

        fo(i,pos+1,a.size()-1){
            if(a[i] == rr){
                found = true;
                break;
            }
        }

        return found;
    }

    return false;

}

int main() {

    cin in n;

    vector<string> a(n+5);
    fo(i,0,n-1) cin in a[i];

    fo(i,0,n-1){
        fo(j,0,n-1){
            if(i == j) continue;
            if(sufficientlyclose(a[i],a[j])){
                adj[i].pb(j);
            }
        }
    }

    cout out longestPath();

    return 0;
}
