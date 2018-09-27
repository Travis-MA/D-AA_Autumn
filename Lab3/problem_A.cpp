#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

int main(){
    int t, n, m, val1, val2;
    scanf("%d", &t);
    for(int k = 0; k<t; k++){
        scanf("%d", &n);
        scanf("%d", &m);
        list<int> list1;
        list<int> list2;
    
        for(int i = 0; i<n; i++){
            scanf("%d", &val1);
            list1.push_back(val1);
        }

        for(int i = 0; i<m; i++){
            scanf("%d", &val2);
            list2.push_back(val2);
        }
        
        list1.merge(list2);
        
        for(list<int>::iterator iter = list1.begin(); iter!=list1.end(); iter++){
            printf("%d ",*iter);
        }
        printf("\n");
    }
}
