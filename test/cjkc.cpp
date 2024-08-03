#include <cstdio>
#include <cstring>
#define maxn 1000005
using namespace std;

using LL = long long;

char s[maxn];
int cnt[maxn], rk[maxn], oldrk[maxn], sa[maxn], id[maxn], height[maxn];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1), m = 26;
    for(int i=1; i<=n; i++) cnt[rk[i] = s[i] - 'a'] ++;
    for(int i=1; i<=m; i++) cnt[i] += cnt[i - 1];
    for(int i=n; i>=1; i--) sa[cnt[rk[i]]--] = i;
    for(int k=1; ; k<<=1)
    {
        int cur = 0;
        for(int i=n-k+1; i<=n; i++) id[++cur] = i;
        for(int i=1; i<=n; i++)
            if(sa[i] > k)
                id[++cur] = sa[i] - k;
        memset(cnt, 0, sizeof(int) * (m + 1));
        for(int i=1; i<=n; i++) cnt[rk[i]] ++;
        for(int i=1; i<=m; i++) cnt[i] += cnt[i - 1];
        for(int i=n; i>=1; i--) sa[cnt[rk[id[i]]]--] = id[i];
        int p = 0;
        memcpy(oldrk, rk, sizeof(int) * (n + 1));
        for(int i=1; i<=n; i++)
            rk[sa[i]] = oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + k] == oldrk[sa[i - 1] + k]? p: ++p;
        if(p == n) break;
        m = p;
    }
    for(int i=1, k=0; i<=n; i++)
    {
        if(rk[i] == 1) { k = height[1] = 0; continue; }
        if(k) k --;
        int j = sa[rk[i] - 1];
        while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k ++;
        height[rk[i]] = k;
    }
    for(int i=1; i<=n; i++)
        printf("%d ", --sa[i]);
    putchar('\n');
    for(int i=1; i<=n; i++)
        printf("%d ", height[i]);
    return 0;
}