1.BFS模板
void BFS(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        取队首元素top；
        访问队首元素top；
        队首元素出队；
        top下一层的所有未入队的元素，入队尾，并设置为已入队；
    }
}

2.块的个数
const int maxn=100;
struct node{
    int x,y;
}Node;

int n,m;
int matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

bool judge(int x,int y){
    if(x>=n||x<0||y>=m||y<0)
        return false;
    if(matrix[x][y]==0||inq[x][y]==true)
        return false;
    
    return true;//该点满足条件
}

void BFS(int x,int y){
    queue<int> Q;
    Node.x=x,Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while(!Q.empty()){
        node top=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            if(judge(newx,newy)){
                Node.x=newx,Node.y=newy;
                Q.push(Node);
                inq[newx][newy]=true;
            }
        }
    }
}
int main()
{
    //读取矩阵略
    int ans=0;//存放块数
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(matrix[x][y]==1 && inq[x][y]==false){
                ans++;
                BFS(x,y);
            }
        }
    }
    cout<<ans;
}

3.迷宫最少步数

const int maxn=100;
struct node{
    int x,y;
    int step;//记录层数（步数）
}S,T,Node;//S为起点,T为终点///////////////////////////////

int n,m;
char maze[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

bool judge(int x,int y){
    if(x>=n||x<0||y>=m||y<0)

        return false;
    if(maze[x][y]=='*')//墙壁/////////////////////////////////
        return false;

    if(inq[x][y]==true)//已入队
        return false;
    
    return true;//该点满足条件
}

void BFS(int x,int y){
    queue<int> Q;
    Node.x=x,Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while(!Q.empty()){
        node top=Q.front();
        Q.pop();

        if(top.x==T.x && top.y==T.y)//到达终点////////////////////////////////
            return top.step;

        for(int i=0;i<4;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            if(judge(newx,newy)){
                
                Node.x=newx,Node.y=newy;
                Node.step=top.step+1;
                Q.push(Node);
                inq[newx][newy]=true;
            }
        }
    }
    return -1;//无法到达终点返回-1
}
int main()
{
    //读取矩阵略

    S.step=0;///////////////////////////////////
    cout<<BFS();
    return 0;
}