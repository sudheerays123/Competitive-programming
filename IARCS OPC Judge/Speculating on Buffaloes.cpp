#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
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
#define N 705

int main() {

    ll n,k;
    cin in n in k;

    vi buffalo(n+5);
    fo(i,1,n) cin in buffalo[i];

    k /= 2;

    vector<vi> dp(k+5,vi(n+5));

    // dp[i][j] = maximum profit possible if we consider the first j days and Ramu is willing to buy and sell i times ( willing to travel i*2 times )

    // base case :

    fo(i,0,k) dp[i][0] = 0;
    fo(j,1,n) dp[0][j] = 0;

    // recurrence relation :

    fo(i,1,k){
        fo(j,2,n){

            dp[i][j] = dp[i][j-1];

            fo(buy,1,j-1){
                mmax(dp[i][j], buffalo[j]-buffalo[buy] + dp[i-1][buy-1]);
            }
        }
    }

    // answer :

    cout out dp[k][n];

    return 0;
}
