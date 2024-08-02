#include <algorithm>
#include <iostream>
#include <cstring>
const int N=1e6;
char str[N];//原始字符串
int x[N];//x[i]表示位置i第一关键字的大小
int y[N];//y[i]表示第二关键字排名为i，其第一关键字的位置
int sa[N];//sa记录子串长度为k时的排名
int rk[N];
int height[N];
namespace algorithm{
    void counting_sort(int *first,int *last,int *result,int w){
		int cnt[w];
		memset(cnt,0,sizeof(cnt));
		for (auto i = first; i < last; ++i) ++cnt[*i];
		for (int i = 1; i <= w; ++i) cnt[i] += cnt[i - 1];
		for (auto i = last-1; i >= first; --i) *(result+cnt[*i]--) = i-first+1;
	}
}
void Get_SA(int n=std::strlen(str), char w='z'){//获取长度为n，最大值不超过m的sa数组
	int c[w];
	//使用计数排序初始化sa，如果m特别大可以考虑这部分用快速排序
    std::copy(str,str+n,x+1);
	algorithm::counting_sort(x+1,x+n+1,sa,w);
	//倍增处理不同位置的子串，当长度达到一定大时自然就成了后缀，进行若干次基数排序
	
    for (int k = 1; k <= n; k <<= 1) {//第n - k + 1到第n位是没有第二关键字的，所以排名在最前面
		int num = 0;
		
		for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
		//如果满足(sa[i]>k)，说明它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y
		for (int i = 1; i <= n; ++i) if (sa[i] > k) y[++num] = sa[i] - k;
		//基数排序，更新sa，即子串长度为k时的排名
		memset(c,0,sizeof(c));

		for (int i = 1; i <= n; ++i) ++c[x[i]];
		for (int i = 1; i <= w; ++i) c[i] += c[i - 1];
		for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i];
		//更新x，即记录位置为i长度为k的子串大小，此时的y已经没用了，这里是将x传递给y。
		std::swap(x,y);
		x[sa[1]] = 1;
		num = 1;//序数
		//因为sa[i]已经排好序了，所以可以按排名枚举，获取其大小
		//如果原来的第一，第二关键字都相同，则整体相同
		for (int i = 2; i <= n; ++i)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
		//如果大小值域达到n，就说明没有相同的字符串，接下来排序不会改变sa的值。
		if (num == n) break;//ok
		w = num;
    }
}
/*namespace reference
{
    void Get_SA(int n, int m){//获取长度为n，最大值不超过m的sa数组
	//使用计数排序初始化sa，如果m特别大可以考虑这部分用快速排序
    for (int i = 1; i <= n; ++i) ++c[x[i] = str[i]];
    for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
    for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
	//倍增处理不同位置的子串，当长度达到一定大时自然就成了后缀，进行若干次基数排序
	//x[i]表示位置i第一关键字的大小
	//y[i]表示第二关键字排名为i，其第一关键字的位置
	//sa记录子串长度为k时的排名
    for (int k = 1; k <= n; k <<= 1) {
		int num = 0;
		//第n - k + 1到第n位是没有第二关键字的，所以排名在最前面
		for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
		//如果满足(sa[i]>k)，说明它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y
		for (int i = 1; i <= n; ++i) if (sa[i] > k) y[++num] = sa[i] - k;
		//基数排序，更新sa，即子串长度为k时的排名
		for (int i = 1; i <= m; ++i) c[i] = 0;
		for (int i = 1; i <= n; ++i) ++c[x[i]];
		for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
		for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i];
		//更新x，即记录位置为i长度为k的子串大小，此时的y已经没用了，这里是将x传递给y。
		std::swap(x,y);
		x[sa[1]] = 1;
		num = 1;
		//因为sa[i]已经排好序了，所以可以按排名枚举，获取其大小
		//如果原来的第一，第二关键字都相同，则整体相同
		for (int i = 2; i <= n; ++i)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
		//如果大小值域达到n，就说明没有相同的字符串，接下来排序不会改变sa的值。
		if (num == n) break;
		m = num;
    }

}*/

// void Get_Height() {//获取height数组
//     int k = 0;
//     for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
// 	//枚举位置
//     for (int i = 1; i <= n; ++i){
//         if (rk[i] == 1) continue;//第一名height为0
//         if (k) --k;//h[i] >= h[i - 1] - 1;
//         int j = sa[rk[i] - 1];
//         while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) ++k;
//         height[rk[i]] = k;
//     }
// }
// } // namespace reference

int main(){
    char a[]="ababa";
    std::strcpy(str,a);
    Get_SA();
    // reference::Get_SA(std::strlen(str)-1,125);
    for (auto &&i : sa)
		if (i)
        	std::cout<<i<<" ";
}
 
// void Get_Height() {//获取height数组
//     int k = 0;
//     for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
// 	//枚举位置
//     for (int i = 1; i <= n; ++i){
//         if (rk[i] == 1) continue;//第一名height为0
//         if (k) --k;//h[i] >= h[i - 1] - 1;
//         int j = sa[rk[i] - 1];
//         while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) ++k;
//         height[rk[i]] = k;
//     }
// }