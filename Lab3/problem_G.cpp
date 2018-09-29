#include<iostream>
#include<stdio.h>
#include<list>
#include<queue> 
#include<vector>
using namespace std;
int n, mid;

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k<t; k++){
        scanf("%d",&n);
        priority_queue< int > big;
        priority_queue< int ,vector< int >,greater< int > > small; 
        int new1, new2;
        for(int i = 0; i<n/2 + 1; i++){
            if(i == 0){
                scanf("%d",&mid);
                printf("%d ",mid);
            }else{
                scanf("%d%d", &new1, &new2);
                if(new1 < mid && new2 > mid){
                    big.push(new1);
                    small.push(new2);
                }else if(new1 >= mid && new2 <= mid){
                    big.push(new2);
                    small.push(new1);
                }else if(new1 >= mid && new2 >= mid){
                    small.push(new1);
                    small.push(new2);
                    big.push(mid);
                    int temp = small.top();
                    small.pop();
                    mid = temp; 
                }else if(new1 < mid && new2 < mid){
                    big.push(new1);
                    big.push(new2);
                    small.push(mid);
                    int temp = big.top();
                    big.pop();
                    mid = temp;
                }
                printf("%d ",mid);
            }
        }
        printf("\n"); 
    }
}