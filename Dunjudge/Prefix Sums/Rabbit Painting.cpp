#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
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
#define N 200005

int main() {

    ll r,c;
    cin in r in c;

    vector<vi> grid(r+5,vi(c+5));
    vector<vi> presum(r+5,vi(c+5));

    fo(i,1,r){
        fo(j,1,c){
            cin in grid[i][j];

            if(i == 1) presum[i][j] = grid[i][j];
            presum[i][j] = max(presum[i-1][j] + grid[i][j],grid[i][j]);
        }
    }

    ll ans = 0;

    fo(i,1,r){

        vi pre(c+5);
        fo(j,1,c){
            if(j == 1) pre[j] = presum[i][j];
            else pre[j] = max(presum[i][j] + pre[j-1],presum[i][j]);

            mmax(ans,pre[j]);
        }
    }

    cout out ans;

    return 0;
}
