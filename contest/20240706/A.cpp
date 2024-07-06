#include <cstdio>
int n,ans;
char a[100][101];int b[100][100];
inline void input(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%s",a[i]);
}
int scan(int xx,int xy,int yx,int yy){
    if (xx<0||xx>=n||xy<0||xy>=n||yx<0||yx>=n||yy<0||yy>=n)return 0;
    if (!(a[xx][xy]&&a[xx][yy]&&a[yx][xy]&&a[yx][yy]))return 0;
    for (int i=1;xx+i<yx;i++)
        if (a[xx+i][xy]!=a[yx-i][yy]||a[xx][xy+i]!=a[yx][yy-i])
            return 0;
    return scan(xx-1,yy-1,yx+1,yy+1)+1;
}
int judge(int x,int y){
    int tmp=0;
    if (x>0&&y>0&&x<n-1&&y<n-1)
        if (a[x][y])
            tmp+=scan(x-1,y-1,x+1,y+1);
    if (x<n-1&&y<n-1)
        if (a[x][y]&&a[x][y+1]&&a[x+1][y]&&a[x+1][y+1])
            tmp+=scan(x-1,y-1,x+2,y+2)+1;
    return tmp;
}
inline void init(){
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]-='0';
}
inline void solve(){
    init();
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-1;j++)
            ans+=judge(i,j);
}
inline void output(){
    printf("%d",ans);
}
int main(){
    input();
    solve();
    output(); 
}