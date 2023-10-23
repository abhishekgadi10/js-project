#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
int canReach(char **board,int n,int m){
    
    vector<vector<int>> vis(n,vector<int> (m,0));
    queue<pair<int,int>> q;
        q.push({0,0});
        int r,c;
        int x,y;
        int ans=0;
        vis[0][0]=1;
        while(!q.empty()){
            r=q.front().first;
            c=q.front().second;
            q.pop();
            ans++;
            for(int z=0;z<4;z++){
                y=r+row[z];
                x=c+col[z];
                if(y>-1 && y<n && x>-1 && x<m && board[y][x]=='O' && !vis[y][x]){
                    vis[y][x]=1;
                    q.push({y,x});
                }
                
            }
        }
        return ans;
}

int main()
{
    int nRows,nCols;
    cin >>nRows>>nCols;
    char** board=new char*[nRows];
    
    for(int i=0;i<nRows;i++){
        board[i]=new char[nCols];
        for(int j=0;j<nCols;j++){
            cin>>board[i][j];
        }
    }
    
    cout<<canReach(board,nRows,nCols);
    
    return 0;
}