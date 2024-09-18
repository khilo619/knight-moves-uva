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
    int n , m , k , t;
    cin >> n >> m >> k >> t;
    string ans[3] = { "Carrots" , "Kiwis" , "Grapes" };
    vector < pair < int , int > > v;
    for(int i = 0 ; i < k ; i++){
        int a , b;
        cin >> a >> b;
        a--; b--;
        v.emplace_back( a , b );
    }
    sort( all( v ) );
    while(t--){
        int x , y;
        cin >> x >> y;
        x--; y--;
        pair < int , int > p = { x , y };
        auto low = lower_bound( all(v) , p ) - v.begin();
        if( v[ low ] == p ){
            cout << "Waste" << nl;
            continue;
        }
        cout << ans[ ( m * x + y - low ) % 3 ] << nl;   
    }
}

int main()
{
   FIO
   #ifndef ONLINE_JUDGE 
   IO
   #endif  
   int tt = 1;
   // cin >> tt;
   while(tt--){
     solve();
   } 
   return 0;
}
