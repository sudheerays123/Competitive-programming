#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
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
#define N 5005

int main() {

    fast;

    ll n,k,d;
    cin in n in k in d;

    vi dp(n+5);
    vi dp1(n+5);

    // dp[i] = number of ways to make sum i with using all the numbers less than or equal to k
    // dp1[i] = number of ways to make sum equal to i with using all the numbers less than or equal to d-1

    // base case :

    dp[0] = 1;
    dp[1] = 1;
    
    dp1[0] = 1;
    if(d != 1 ) dp1[1] = 1;
    else dp1[1] = 0;

    // recurrence relation :

    fo(i,2,n){

        fo(j,max(i-k,0ll),i-1){
            dp[i] += dp[j];
            dp[i] %= MOD;
        }

        fo(j,max(i-d+1,0ll),i-1){
            dp1[i] += dp1[j];
            dp1[i] %= MOD;
        }

    }

    // answer :

    ll x = dp[n] - dp1[n];
    x += MOD;
    x %= MOD;

    cout out x;

    return 0;
}
