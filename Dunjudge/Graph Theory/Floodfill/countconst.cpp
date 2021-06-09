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

vector<vector<bool>> visited(1005, vector<bool>(1005));
vector<vector<char>> grid(1005, vector<char>(1005));
ll h, w;

void dfs(ll x , ll y) {

	if (visited[x][y] == true) return;
	visited[x][y] = true;

	if (x != h - 1 && grid[x + 1][y] == '*') dfs(x + 1, y);
	if (x != 0 && grid[x - 1][y] == '*') dfs(x - 1, y);
	if (y != 0 && grid[x][y - 1] == '*') dfs(x, y - 1);
	if (y != w - 1 && grid[x][y + 1] == '*') dfs(x, y + 1);

}

int main() {

	cin in h in w;

	fo(i, 0, h - 1) {
		fo(j, 0, w - 1) {
			cin in grid[i][j];
		}
	}


	ll count = 0;

	fo(i, 0, h - 1) {
		fo(j, 0, w - 1) {
			if (visited[i][j] == true || grid[i][j] == 'x') continue;
			count++;
			dfs(i, j);
		}
	}

	cout out count;


	return 0;
}
