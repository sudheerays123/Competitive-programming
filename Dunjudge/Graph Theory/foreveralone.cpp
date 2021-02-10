#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
#define ll long long
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

int main(){

    ll n,m;
    cin in n in m;

    unordered_set<ll> s;

    fo(i,0,m-1){
    	ll u,v;
    	cin in u in v;

    	if(u != v){
    		s.insert(u);
    		s.insert(v);
    	}
    }

    cout out n - s.size();

    return 0;
}
