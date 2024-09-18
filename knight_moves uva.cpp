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
    {-2, 1}, {-1, 2}, {1, 2}  , {2 , 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};


int BFS (int r , int c , int tr , int tc){
    int visted [ 9 ][ 9 ] {0};
    queue < pair < int , int > > q;
    q.push({r , c});
    visted [ r ][ c ] = 1;
    int minmoves = 0;
    while(! q.empty()){
        int sz = q.size();
        while(sz--){
            auto node = q.front();
            q.pop();
            if(node.first == tr && node.second == tc){
                return minmoves;
            }
            for(auto &d : dist){
                int nr = node.first  + d [ 0 ];
                int nc = node.second + d [ 1 ];
                bool edges = nr > 0 && nr < 9 && nc > 0 && nc < 9;
                if(! visted[ nr ][ nc ] && edges){
                    visted [ nr ][ nc ] = 1;
                    q.push({nr , nc});
                }
            }
        }
        minmoves++;
    }
    return -1;
}

// void solve()
// {
     
// }

int main()
{
   FIO
   #ifndef ONLINE_JUDGE 
   IO
   #endif  
   int tt = 1;
   // cin >> tt;
   // while(tt--){
   //   solve();
   // } 
   string s1 , s2;
    while(cin >> s1 >> s2){
        int ans =  BFS (s1[0] - 'a' + 1 , s1[1] - '0' , s2[0] - 'a' + 1 , s2[1] - '0');
        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves." << nl;
    }  
   return 0;
}
