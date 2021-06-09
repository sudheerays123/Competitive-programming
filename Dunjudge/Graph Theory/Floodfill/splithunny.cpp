#include <bits/stdc++.h>
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

vector<vector<char>> grid(100+5,vector<char>(100+5));
vector<vector<bool>> visited(105,vector<bool> (105,false));
ll n,m;

void dfs(ll x , ll y){

    if(visited[x][y] == true || grid[x][y] == '.') return;
    visited[x][y] = true;

    if(x!=0) dfs(x-1,y);
    if(x != n-1) dfs(x+1,y);
    if(y != 0) dfs(x,y-1);
    if(y != m-1) dfs(x,y+1);
}

int main() {

   cin in n in m;

   fo(i,0,n-1){
       fo(j,0,m-1){
           cin in grid[i][j];
       }
   }

    ll ans = 0;

    fo(i,0,n-1){
       fo(j,0,m-1){
           if(visited[i][j] == true || grid[i][j] == '.') continue;
           ans++;
           dfs(i,j);
       }
   }

   cout out "Oh, bother. There are " out ans out " pools of hunny.";

   return 0;
}
