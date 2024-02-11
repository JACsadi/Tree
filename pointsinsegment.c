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
typedef struct pair
{
   int a;
   int b;
} pair;
typedef struct node
{
    int val;
    int index;
    int count;
} node;
void merge(node arr[], int l, int m, int r) {
    if(l != r) {
        node L[m - l + 1], R[r - m];
        for(int i = l; i <= m; i++) {
            L[i-l].val = arr[i].val;
            L[i-l].index = arr[i].index;
            L[i-l].count = arr[i].count;
            }
        for(int i = m + 1; i <= r; i++) {
            R[i - m - 1].val = arr[i].val;
            R[i - m - 1].index = arr[i].index;
            R[i - m - 1].count = arr[i].count;
            }
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j] = L[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j] = R[j];
                 j++;
            } else if(L[i].val < R[j].val){
                arr[l+i+j] = L[i];
                 i++;
            } else {
                 arr[l+i+j] = R[j];
                 j++;
            }
        } 
    }
}
void sortttt(node arr[], int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr, l ,mid);
        sortttt(arr, mid + 1, r);
    }
    merge(arr,l,mid,r);
}
int main() {
    tcase {
        int n,m;sd(n);sd(m);
        pair qu[n];
        f(i,n) {
         sd(qu[i].a);
         sd(qu[i].b);
        }
        node arr[m];
        f(i,m) {
            sd(arr[i].val);
            arr[i].index = i;
            arr[i].count = 0;
        }   
        sortttt(arr,0,m-1);
        f(i,m) printf("%d ", arr[i].val);
        f(i,m) {
            int index = bs(arr,m,a);
            if(index ==)
        }
    }
}