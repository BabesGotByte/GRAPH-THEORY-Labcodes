#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


main() {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll inc[5][6]= {{1,1,1,0,0,0},
               {1,0,0,0,1,0},
               {0,0,1,1,0,0},
               {0,1,0,1,1,1},
               {0,0,0,0,0,1}};



stack<int> s;
s.push(0);
int i,j;
int vis[5];
for(i=0;i<5;i++)
vis[i]=-1;

vis[0]=1;
cout<<"The edges of our spanning tree are : ";
while(!s.empty())
{
    int x=s.top();
    s.pop();
    
    for(i=0;i<6;i++)
    {   int z;
        if(inc[x][i]==1)
        {
            for(j=0;j<5;j++)
            {
               if(j!=x and inc[j][i]==1)
               z=j;
            }
            
            if(vis[z]==-1)
            {
                vis[z]=1;
                s.push(z);
                cout<<"e"<<i<<" ";
            }
            
        }
        
        
    }
    
}


}