#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
#define tc ll test;cin>>test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 10000
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
#define N 1001

vi dx = {1,-1,0,0};
vi dy = {0,0,1,-1};

ll n,m;
vector<vector<char>> grid(N,vector<char>(N));

ll bfs(){

    queue<pll> q;
    vector<vi> gkill(n+5,vi(m+5,INF));

    q.push({1,1});
    gkill[1][1] = 0;

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;

        q.pop();

        fo(i,0,3){
            ll aa = a + dx[i];
            ll bb = b + dy[i];

            if(aa >= 1 && aa <= n && bb >= 1 && bb <=m && gkill[aa][bb] > gkill[a][b]){
                gkill[aa][bb] = gkill[a][b] + (grid[aa][bb] != grid[a][b]);
                q.push(mp(aa,bb));
            }
        }
    }

    return gkill[n][m];
}

int main() {

    fast;

    tc{
        cin in n in m;
        fo(i,1,n){
            fo(j,1,m) {
                cin in grid[i][j];
            }
        }

        cout out bfs() nextline;
    }

    return 0;
}
