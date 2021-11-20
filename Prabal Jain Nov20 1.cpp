int MAX = 5;
class Solution{
    
    public:
    bool visited[5][5];
    string ans;
    vector<string> sol;
    bool check(int x, int y,int n,vector<vector<int>> &m){
        if(x==n or y==n or x==-1 or y==-1 or visited[x][y]==1 or m[x][y]==0)
        return false;
        else return true;
    }
    void rec(int x, int y,int n,vector<vector<int>> &m ){
        //cerr << x << ' ' << y << '\n';
        if(x==n-1 and y==n-1){
            sol.push_back(ans);
        }
        
        visited[x][y]=1;
        
        if(check(x+1,y,n,m)){
            ans+= 'D';
            rec(x+1,y,n,m);
            ans.pop_back();

            visited[x+1][y] = 0;
        }
        if(check(x,y-1,n,m)){
            ans+= 'L';
            rec(x,y-1,n,m);
            ans.pop_back();

            visited[x][y-1] = 0;
        }
        if(check(x,y+1,n,m)){
            ans+= 'R';
            rec(x,y+1,n,m);
            ans.pop_back();

            visited[x][y+1] = 0;
        }
        if(check(x-1,y,n,m)){
            ans+= 'U';
            rec(x-1,y,n,m);
            ans.pop_back();

            visited[x-1][y] = 0;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if (!m[0][0]) return sol;
        
        memset(visited, false, sizeof(visited));
        rec(0,0,n,m);
        return sol;
    }
};
