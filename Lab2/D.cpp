#include<iostream>
#include<cstdio>
using namespace std;

int room_num;
int date_start;
int date_end;
int room_table[1000010];
int modified;



int main(){

    int n;
    while(cin >> n){
        //cout << "while: " << endl;
        int m;
        scanf("%d", &m);
        
        //cout << "n: " << n << " m: " << m << endl;
        for(int i = 0; i<n; i++) scanf("%d", room_table+i);

        modified = 0;
        bool bk = false;
        for(int i = 0; i<m; i++){

            scanf("%d%d%d", &room_num, &date_start, &date_end);
            if(bk == false){
                for(int j = date_start-1; j<date_end ;j++){
                    room_table[j] -= room_num;
                    if(room_table[j]<0){
                        modified = i+1;
                        bk = true;
                        break;
                    }
                }
            } 
        }
        
        if(modified == 0) printf("%d\n",0);
        else printf("%d\n%d\n",-1,modified);  
        
        
    }

    return 0;
}