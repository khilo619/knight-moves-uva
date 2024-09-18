#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define ld long double
#define Yes cout << "YES\n"
#define No  cout << "NO\n"
using namespace std;
#define IO freopen("intput.txt","r",stdin); freopen("Ou.txt","w",stdout); 
const int MX = 2e5 + 1 , MOD = 1e9 + 7;
#define all(v) v.begin() , v.end()
#define rall(v) v.rbegin() , v.rend()
#define nl '\n'

void solve()
{
    ll n; int m , q;
    cin >> n >> m >> q;

    vector < ll > t ( m );
    for(auto& i : t)
            cin >> i;
                    sort( all( t ) );
    while(q--){
        ll x;
        cin >> x;
        
        if( t[ 0 ] > x ){
            cout << t[ 0 ] - 1;
        }
        else if( t[ m - 1 ] < x ){
            cout << n - t[ m - 1 ];
        }
        else{
            auto a = lower_bound( all(t) , x ) - t.begin();
            auto b = lower_bound( all(t) , x ) - t.begin() - 1;
            cout << ( t[ a ] - t[ b ] ) / 2;
        }
        cout << nl;
    }
}

int main()
{
   FIO
   #ifndef ONLINE_JUDGE 
   IO
   #endif  
   int tt = 1;
   cin >> tt;
   while(tt--){
     solve();
   } 
   return 0;
}
