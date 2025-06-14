// Longer Syntax
#include <bits/stdc++.h> 

void search(int row, int col, vector<vector<int>>& arr, int n, 
string &move, vector<string> &ans, vector<vector<int>> &vis)
{
    if(row == n-1 && col == n-1){
        ans.push_back(move);
        return;
    }

    //down
    if(row+1<n && !vis[row+1][col] && arr[row+1][col]==1){
        vis[row][col] = 1;
        move.push_back('D');
        search(row+1, col, arr, n, move, ans, vis);
        vis[row][col] = 0;
        move.pop_back();
    }

    //left
    if(col-1>=0 && !vis[row][col-1] && arr[row][col-1]==1){
        vis[row][col] = 1;
        move.push_back('L');
        search(row, col-1, arr, n, move, ans, vis);
        vis[row][col] = 0;
        move.pop_back();
    }

    //right
    if(col+1<n && !vis[row][col+1] && arr[row][col+1]==1){
        vis[row][col] = 1;
        move.push_back('R');
        search(row, col+1, arr, n, move, ans, vis);
        vis[row][col] = 0;
        move.pop_back();
    }

    //upper
    if(row-1>=0 && !vis[row-1][col] && arr[row-1][col]==1){
        vis[row][col] = 1;
        move.push_back('U');
        search(row-1, col, arr, n, move, ans, vis);
        vis[row][col] = 0;
        move.pop_back();
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    string move;
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n,0));
    if(arr[0][0] == 1) {
        vis[0][0] = 1;
        search(0, 0, arr, n, move, ans, vis);
    } 
    return ans;
}


// Shorter Syntax
#include <bits/stdc++.h> 

void search(int row, int col, vector<vector<int>>& arr, int n, 
string &move, vector<string> &ans, vector<vector<int>> &vis, vector<int> &di, 
vector<int>& dj)
{
    if(row == n-1 && col == n-1){
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for(int i=0; i<4; i++){
        int nextRow = row + di[i];
        int nextCol = col + dj[i];
        if(nextRow>=0 && nextRow<n && nextCol>=0 && nextCol<n && 
        !vis[nextRow][nextCol] && arr[nextRow][nextCol]==1)
        {
            vis[row][col] = 1;
            move.push_back(dir[i]);
            search(nextRow, nextCol, arr, n, move, ans, vis, di, dj);
            vis[row][col] = 0;
            move.pop_back();
        }
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    string move;
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n,0));
    vector<int> di = {+1, 0, 0, -1};
    vector<int> dj = {0, -1, +1, 0};
    if(arr[0][0] == 1) {
        vis[0][0] = 1;
        search(0, 0, arr, n, move, ans, vis, di, dj);
    }    
    return ans;
}