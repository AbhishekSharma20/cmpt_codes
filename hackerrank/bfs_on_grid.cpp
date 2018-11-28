/******************************************************************************
Given a Grid of size MxN with value 1 => plants, 0=> empty space, 2=> initial position
Can you tell the minimum moves to boundary. valid moves are up, down, lef, right. 
*******************************************************************************/

#include <iostream>
#include<queue>
#include<utility>

using namespace std;

bool isSafe(vector<vector<int> >a, vector<vector<int> > visited, int i, int j){
    int X = a.size();
    int Y = a[0].size();
    return  i>=0 && j>=0 && i<X && j <Y && !visited[i][j] && !(a[i][j] == 1);   
}

bool isBoundary(int i, int j, vector<vector<int> > a){
    i == a.size()-1 || j == a[0].size() - 1;
}

int bfs(vector<vector<int> >a,  int i, int j){
    vector<vector<int> > visited(a.size(), vector<int>(a[0].size(),0)); 
    queue<pair<int, int> > q;
    q.push(make_pair(i,j));
    visited[i][j] = 1;
    q.push(make_pair(-1,-1));
    int depth = 0;
    pair<int,int> tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        cout<<tmp.first<<" "<<tmp.second<<endl;
        if(tmp.first == -1 && tmp.second == -1){
            depth++;
            q.push(make_pair(-1,-1));
            continue;
        }
        if(isBoundary(tmp.first,tmp.second, a)){
            return depth;
        }
        visited[tmp.first][tmp.second] = true;
        if(isSafe(a, visited, tmp.first+1,tmp.second)){ q.push(make_pair(tmp.first+1,tmp.second));  }
        if(isSafe(a, visited, tmp.first-1,tmp.second)){ q.push(make_pair(tmp.first-1,tmp.second));  }
        if(isSafe(a, visited, tmp.first,tmp.second+1)){ q.push(make_pair(tmp.first,tmp.second+1));  }
        if(isSafe(a, visited, tmp.first,tmp.second-1)){ q.push(make_pair(tmp.first,tmp.second-1));  }
        
    }
    return -1;
    
}

int main()
{
    vector<vector<int> > grid(4,vector<int>(5,0) );
    grid[0][1] = grid[0][2] = grid[0][0] = grid[0][4] = 1;
    grid[1][0] = grid[1][4] = 1;
    grid[2][2] = grid[2][4] = 1;
    grid[3][2] = grid[3][0] = grid[3][3] = 1;
    grid[1][2] = 2;
    
    cout<< bfs(grid,1,2)<<endl;

    return 0;
}
