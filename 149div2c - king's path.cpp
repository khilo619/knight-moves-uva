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

vector < vector < int > > dist = {
    {1 ,  -1} , {1 ,  0} , {1 ,  1},
    {0 ,  -1} , {0 ,  0} , {0 ,  1},
    {-1 , -1} , {-1 , 0} , {-1 , 1}
};

void solve()
{

     ll x1 , y1 , x2 , y2;
     cin >> x1 >> y1 >> x2 >> y2;
     int n;
     cin >> n;

     set< pair < ll , ll > > pts;

     while(n--){
        ll r , a , b;
        cin >> r >> a >> b;
        for(int i = a ; i <= b ; i++)
            pts.insert( { r , i } );
     }

     queue < pair < ll , ll > > q;
     map < pair < ll , ll > , int > vis;
     q.push( { x1 , y1 } );
     vis[ q.front() ] = 1;
     int minmoves = 0;

     while(! q.empty()){
        int sz = q.size();
        while(sz--){
            auto node = q.front();
            q.pop();  
            for(auto& d : dist){
                ll rn = node. first + d[ 0 ];
                ll cn = node.second + d[ 1 ];
                if(! vis[ { rn , cn } ] && pts.count( { rn , cn } )){
                    q.push( { rn , cn } );
                    vis[ { rn , cn } ] = 1;
                }
            }
            if(node.first == x2 && node.second == y2){
                cout << minmoves;
                return;
            }
        }
        minmoves++;
     }
     cout << -1;
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
