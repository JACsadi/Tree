#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
// #include <climits>
#include <limits.h>
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
int tree[300080];
int init[100011];
 void build(int v,int l,int r)
{
    int m=(l+r)/2;
    if(l==r) tree[v]=init[l];
     else{
        build((2*v)+1,l,m);
        build((2*v)+2,m+1,r);
        tree[v]=(tree[1+(2*v)] + tree[2+(2*v)]); 
     }
}
int sum(int v, int s,int e,int l, int r)
{
    if(l==s && r==e) return tree[v];
    if(s>e) return 0;
    int m=(l+r)/2;
    int a = sum((v*2)+1,s,Min(m,e), l, m);
    int b =  sum((v*2)+2,Max(s,1+m),e ,m+1,r);
    return a+b; 
}
void update(int dif,  int index, int l, int r,int v ) {
    tree[v] += dif;
    int m=(l+r)/2;
    if(l != r) {
    if(index <= m) update( dif, index, l, m, (v*2)+1);
    else update( dif, index, m+1, r, (v*2)+2);
    }
}

int main()
{
tcase{
int n,ele;
sd(n);sd(ele);
for(int i=1;i<=n;i++)
    scanf("%d",&init[i]);
build(0,1,n);
printf("Case %d:\n", casee);
// f(i,4*n) printf("%d - %d\n", i,tree[i]);
f(i,ele) {
 int a; sd(a);
 if(a == 1) {
    int b;
    sd(b);
    b++;
    printf("%d\n", init[b]);
    update(0-init[b],b,1,n,0);
    init[b] = 0;
 } else if(a==2) {
    int b,c; sd(b);sd(c);
    b++;
    update(c,b,1,n,0);
    init[b] += c;
 } else {
  int l, r;
 sd(l);sd(r);
 printf("%d\n", sum(0,l+1,r+1,1,n));
 }
}
}
return 0;
}