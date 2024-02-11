#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <climits>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))	;
#define sd(i) scanf("%d", &i)
#define Max(a,b) (a < b ? b : a)
#define Min(a,b) (a > b ? b : a)
#define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
 void build( int initial[], int tree[],int v,int l,int r)
{
    int m=(l+r)/2;
    if(l==r) tree[v]=initial[l];
     else{
        build(initial,tree,(2*v)+1,l,m);
        build(initial,tree,(2*v)+2,m+1,r);
        tree[v]=tree[1+(2*v)]<tree[1+(2*v)+1] ? tree[1+(2*v)] : tree[1+(2*v)+1]; 
     }
}
void update(int tree[], int dif,  int index, int l, int r,int v ) {
    tree[v] += dif;
    int m=(l+r)/2;
    if(l != r) {
    if(index <= m) update(tree, dif, index, l, m, (v*2)+1);
    else update(tree, dif, index, m+1, r, (v*2)+2);
    }
}

int sum(int tree[],int v, int s,int e,int l, int r)
{
    if(l==s && r==e) return tree[v];
    if(s>e) return INT_MAX;
    int m=(l+r)/2;
    return sum(tree,(v*2)+1,s,Min(m,e), l, m) < sum(tree,(v*2)+2,Max(s,1+m),e , 1+(m),r) ? sum(tree,(v*2)+1,s,Min(m,e), l, m) : sum(tree,(v*2)+2,Max(s,1+m),e , 1+(m),r); 
}

int main()
{
tcase{
int n,ele;
scanf("%d %d", &n, &ele);
int init[n+1];
for(int i=1;i<=n;i++)
    scanf("%d",&init[i]);
int tree[4*n];
for(int i=0;i<2*n;i++)
    tree[i]=INT_MAX;
build(init,tree,0,1,n);
printf("Case %d:\n", casee);
for(int i = 0; i <ele; i++) {
  int l, r;
 scanf("%d %d", &l, &r);
 printf("%d\n", sum(tree,0,l,r,1,n));
}
// for(int i=0;i<=2*n;i++)
//     printf("%d ",tree[i]);
//     printf("\n");
// while(1) {
//      printf("0 to break, 1 update, 2 for sum from l to r\n");
//      int k;
//      scanf("%d", &k);
//      if(!k) break;
//      if(k == 1) {
//     int ind , val;
//     scanf("%d %d", &ind, &val);
//     int dif = val - init[ind];
//     update(tree, dif, ind, 1, n, 0 );
//      } else if(k == 2) {
//         int l, r;
//         scanf("%d %d", &l, &r);
//         printf("%d\n", sum(tree,0,l,r,1,n));
//      }
// }
// for(int i=0;i<=2*n;i++)
//     printf("%d ",tree[i]);
}
return 0;
}