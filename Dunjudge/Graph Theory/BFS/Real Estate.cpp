#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

    ll n,m,k;
    cin in n in m in k;

    vector<vector<char>> grid(n+5,vector<char>(m+5));

    queue<pair<ll,ll>> q;
    vector<vi> dist(n+5,vi(m+5,INF));

    fo(i,1,n){

        string s;
        cin in s;

        fo(j,1,m){
            grid[i][j] = s[j-1];

            if(grid[i][j] == '*') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vi dx = {0,-1,0,+1};
    vi dy = {-1,0,+1,0};

    while(!q.empty()){

        ll a = q.front().first;
        ll b = q.front().second;

        q.pop();

        fo(times,0,3){

            ll i = a + dx[times];
            ll j = b + dy[times];

            if(i >= 1 && i <= n && j >= 1 && j <= m && grid[i][j] == '.' && dist[i][j] > dist[a][b] + 1){
                dist[i][j] = dist[a][b] + 1;
                q.push({i,j});
            }
        }
    }

    ll cnt = 0;

    fo(i,1,n){
        fo(j,1,m){
            if(dist[i][j] <= k && grid[i][j] == '.'){
                cnt++;
            }
        }
    }

    cout out cnt;

    return 0;
}
