#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
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
#define N 100005

ll n,c;
vi stall(N);

bool isPossible(ll dist){

    ll cnt = 1,rem = dist;

    fo(i,2,n){
        rem -= stall[i]-stall[i-1];
        if(rem <= 0){
            rem = dist;
            cnt++;
        }
    }

    return cnt >= c;
}

int main() {

    fast;

    tc{

        cin in n in c;

        fo(i,1,n) cin in stall[i];

        sort(stall.begin()+1,stall.begin()+n+1);

        ll low = 1;
        ll high = 1e18;
        ll ans;

        while(low <= high){
            ll mid = (low+high)/2;

            if(isPossible(mid) == true){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }

        cout out ans nextline;
    }

    return 0;
}
