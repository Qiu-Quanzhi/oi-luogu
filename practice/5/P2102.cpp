#include <cstdio>
using namespace std;
const char dx[4] = {-1, 1, 0, 0}, dy[4]={0, 0, 1, -1};
char n,m;
char f[100][100];
//void print();
void input(){
    scanf("%d %d",&n,&m);
}
bool check(char x, char y, char k){
    if (x>=n||y>=m)return false;
    for (char i=0,nx=x+dx[i],ny=y+dy[i];i<4;i++,nx=x+dx[i],ny=y+dy[i]){
        if (nx>=n||ny>=m||nx<0||ny<0)continue;
            if (f[nx][ny]==k)return false;
    }
    return true;
}
void fill(char x, char y, char k){
    char i=0;

    for (;check(x+i,y+i,k)&&check(x,y+i,k);i++){
        bool better=false;
        for (char j='A';j<k;j++){
            if (check(x,y+i+1,j)){better=true;break;}
        }
        if (better||f[x][y+i+1]){i++;break;}
    }
    for (char l=x;l<x+i;l++)
        for (char j=y;j<y+i;j++)
            f[l][j]=k;
    // if(i)
    //     print();
    // printf("\n%d %d %c",x,y,k);
}
void solve(){
    for (char i=0;i<n;i++){
        for (char j=0;j<m;j++)
            for (char k='A';k<='D'&&!f[i][j];k++)
                fill(i,j,k);
    }
}
void print(){
    for (char i=0;i<n;i++){
        for (char j=0;j<m;j++)
            if(f[i][j])
                printf("%c",f[i][j]);
            else
                printf("#");
        printf("\n");
    }
}
int main(){
    //freopen("my.out","w",stdout);
    input();
    //for (n=1;n<=100;n++)
    //for (m=1;m<=100;m++){
    //memset(f,0,sizeof(f));
    solve();
    print();
    //printf("\n\n");
    //}
}