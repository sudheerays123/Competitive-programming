#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
#define print(x) for(auto i : x ) cout out i
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 2005

ll r,c;
vector<vi> bear(N,vi(N,INF));
vector<vector<char>> grid(N,vector<char>(N,'.'));

vi dx = {0,-1,0,+1};
vi dy = {-1,0,+1,0};

void bfs(ll x , ll y){

    queue<pair<ll,ll>> q;

    q.push({x,y});
    bear[x][y] = 0;

    while(!q.empty()){

        ll a = q.front().first;
        ll b = q.front().second;

        q.pop();

        fo(t,0,3){
            ll i = a + dx[t];
            ll j = b + dy[t];

            if(i >= 0 && i <= (r+1) && j >= 0 && j <= (c+1) && grid[i][j] == '.' && bear[i][j] > bear[a][b] + 2){
                bear[i][j] = bear[a][b] + 2;
                q.push({i,j});
            }
        }
    }
}

int main() {

    fast;

    cin in r in c;


    ll firex , firey , bearx , beary;

    fo(i,1,r){
        fo(j,1,c){
            cin in grid[i][j];

            if(grid[i][j] == 'F'){
                firex = i;
                firey = j;
            }
            if(grid[i][j] == 'B'){
                bearx = i;
                beary = j;
            }
        }
    }

    bfs(bearx,beary);

    ll ans = INF;

    fo(i,0,r+1){
        ll fire = abs(i-firex) + abs(0-firey);
        if(bear[i][0] != INF && bear[i][0] < fire){
            mmin(ans,bear[i][0]);
        }
    }
    fo(i,0,r+1){
        ll fire = abs(i-firex) + abs((c+1)-firey);
        if(bear[i][c+1] != INF && bear[i][c+1] < fire){
            mmin(ans,bear[i][c+1]);
        }
    }
    fo(j,0,c+1){
        ll fire = abs(0-firex) + abs(j-firey);
        if(bear[0][j] != INF && bear[0][j] < fire){
            mmin(ans,bear[0][j]);
        }
    }
    fo(j,0,c+1){
        ll fire = abs((r+1)-firex) + abs(j-firey);
        if(bear[r+1][j] != INF && bear[r+1][j] < fire){
            mmin(ans,bear[r+1][j]);
        }
    }

    if(ans == INF) cout out "-1";
    else cout out ans;

    return 0;
}
