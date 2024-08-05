#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct p
{
  int id;
  int mark;
} a[5000];
bool cmp(p a,p b)
{
  if (a.mark==b.mark)
    return a.id<b.id;
  else
    return a.mark>b.mark;
}
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for (int i=0; i<n; i++)
    scanf("%d %d",&a[i].id,&a[i].mark);
  sort(a,a+n,cmp);
  int f,x;
  for (int i=0; i<floor(m*1.5); f=a[i++].mark);
  for (int i=0; a[i].mark>=f; i++,x=i);
  printf("%d %d\n",f,x);
  for (int i=0; i<x; i++)
    printf("%d %d\n",a[i].id,a[i].mark);
}