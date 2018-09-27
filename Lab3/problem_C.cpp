#include<iostream>
#include<cstdio>
#include<list>
#include<string.h>
using namespace std;

int main(){
    
    while(1){
        int num;
        scanf("%d", &num);
        if(num == 0) break;
        char people[53];
        scanf("%s", people);
        list<char> buffer;
        list<char> nbuffer;
        int nob = 0;
       

        for(int i = 0; i<52; i++){
            bool second = false;
            bool nsecond = false;
            char pivots = people[i];
            if(pivots  >= 'A' && pivots <= 'Z'){
                
                list<char>::iterator iter = buffer.begin();
                while(iter != buffer.end()){
                    if(pivots == *iter){
                        buffer.erase(iter);
                        second = true;
                        num++;
                        break;
                    }
                    iter++;
                }

                
                list<char>::iterator niter = nbuffer.begin();
                while(niter != nbuffer.end()){
                    if(pivots == *niter){
                        buffer.erase(niter);
                        nsecond = true;
                        break;
                    }
                    niter++;
                }

                if(num<=0){
                    if(second == false && nsecond == false){
                        nbuffer.push_back(pivots);
                        nob++;
                    }

                }else{
                    if(second == false && nsecond == false){
                        buffer.push_back(pivots);
                        num--;
                    }
                } 
                

            }else{
                break;
            }
        }
    printf("%d\n",nob);   
    }
}
