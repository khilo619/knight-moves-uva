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

int bfs( vector < vector < int > >& adj , int st , vector < int >& time ){
    int vis[ 505 ]{ 0 };
    queue < int > q;
    int cost = 0;
    q.push( st );
    vis[ st ] = 1;
    while( !q.empty() ){
        int node = q.front(); q.pop();
        cost += time[ node ];
        for(auto& i : adj[ node ])
            if( !vis[ i ] ){
                vis[ i ] = 1;
                q.push( i );
        } 
    }
    return cost;
}
void solve()
{
    int v , e , cc = 1;
    while( cin >> v >> e , (e + v) ){
        int total_time = 0;
        vector < int > time ( v + 1 );
        for(int i = 1 ; i <= v ; i++){
            cin >> time[ i ];
            total_time += time[ i ];
        }

        vector < vector < int > > in( v + 1 ) , out( v + 1 );
        for(int i = 0 ; i < e ; i++){
            int x , y;
            cin >> x >> y;
            in [ y ].push_back( x );
            out[ x ].push_back( y );
        }

        int Q;
        cin >> Q;
        cout << "Case #" << cc++ << ":\n";
        while( Q-- ){
            int j;
            cin >> j;
            int maxtime = total_time - bfs( in , j , time );
            int mintime = bfs( out , j , time ) - time[ j ];  
            cout << maxtime - mintime << '\n';   
        }
        cout << '\n';
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
