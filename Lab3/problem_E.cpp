#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int k = 0; k<t; k++){
        int n, m, e;
        scanf("%d%d%d",&n, &m, &e);

        list<int> planet;

        for(int i = 0; i<n; i++){
            if(i != e){
                planet.push_back(i+1);
            }else{
                planet.push_back(-1);
            }
        }

        
        

        list<int>::iterator iter = planet.begin();
        bool stop = false;
        /*
        while(iter != planet.end()){
            cout << *iter << endl;
            iter++;
        }*/
        iter = planet.begin();

        while(1){
            //cout << "\nstart: " << *iter << endl;
            if(stop == true) break;
            if(n <= 1){
                printf("Yes\n");
                break;
            }

            for(int i = 0; i<m; i++){
                iter++;
                if(iter == planet.end()) {
                    iter = planet.begin();
                } 
            }
            //cout << "now iter: " << *iter << endl;

            if(*iter == -1 && n > 1){
                stop = true;
                printf("No\n");
                break;
            }else{
                //cout << "erase: " << *iter << endl;
                	
                iter = planet.erase(iter);
                if(iter == planet.end()){
                    iter = planet.begin();
                }
                n--;
            }
        
            
        }
    }
}


