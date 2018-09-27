#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

typedef struct Terms{
    int coef;
    int expo;
}Term;


void Print(list<Term> polynomial){
    int len = polynomial.size();
    int cout = 0;
    bool hp = false;
    for(list<Term>::iterator iter = polynomial.begin(); iter != polynomial.end(); iter++){
        
        int coef = iter->coef;
        int expo = iter->expo;
        
        if(coef > 0){
            if(cout != 0){
                hp = true; printf("+");
            }
            if(coef == 1){
                if(expo == 0){
                    hp = true; printf("%d",1);
                }else if(expo == 1){
                    hp = true; printf("x");
                }else{
                    hp = true; printf("x^%d",expo);
                }
            }else{
                if(expo == 0){
                    hp = true; printf("%d",coef);
                }else if(expo == 1){
                    hp = true; printf("%dx",coef);
                }else{
                    hp = true; printf("%dx^%d", coef, expo);
                }
            } 
            
        }

        if(coef < 0){
            if(coef == -1){
                if(expo == 0){
                    hp = true; printf("%d",-1);
                }else if(expo == 1){
                    hp = true; printf("-x");
                }else{
                    hp = true; printf("-x^%d",expo);
                }
            }else{
                if(expo == 0){
                    hp = true; printf("%d",coef);
                }else if(expo == 1){
                    hp = true; printf("%dx",coef);
                }else{
                    hp = true; printf("%dx^%d", coef, expo);
                }
            } 
            
        }
        
        cout++;
    }
    if(hp == false) printf("%d",0);

    printf("\n");
}

list<Term> merge(list<Term> polynomial_A, list<Term> polynomial_B){
    int start = 0;
    int k = 0;
    list<Term>::iterator iter_A = polynomial_A.begin();
    list<Term>::iterator iter_B = polynomial_B.begin();
    list<Term> ans;
    int acont = 0;
    int bcont = 0;

    while(iter_A != polynomial_A.end() && iter_B != polynomial_B.end()){
        
        if(iter_A->expo > iter_B->expo){
            ans.push_back(*iter_B);
            iter_B++;
            bcont++;
        }else{
            ans.push_back(*iter_A);
            iter_A++;
            acont++;
        }
        
    }

    while(acont < polynomial_A.size()){
        ans.push_back(*iter_A);
        iter_A++;
        acont++;
    }

    while(bcont < polynomial_B.size()){
        ans.push_back(*iter_B);
        iter_B++;
        bcont++;
    }

    //cout << "finish" << endl;
    list<Term>::iterator iter =ans.begin();
    while(iter != ans.end()){
        Term now = *iter;
        iter++;
        Term next = *iter;
        if(now.expo == next.expo){
            ans.erase(iter);
            iter--;
            iter->coef = now.coef + next.coef;
        }
        
    }

    return ans;
}



int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k<t; k++){
        int n;
        scanf("%d", &n);
        int coef1[n];
        int expo1[n];
        list <Term> polynomial_A;
        for(int i = 0; i<n; i++) {
            scanf("%d", &coef1[i]);
            scanf("%d", &expo1[i]);
        }
        
        for(int i = 0; i<n; i++){
            Term term;
            term.coef = coef1[i];
            term.expo = expo1[i];
            
            polynomial_A.push_back(term);
        }
       
        int m;
        scanf("%d", &m);
        int coef2[m];
        int expo2[m];
        list <Term> polynomial_B;
        //cout << "m: " << m << endl;
        for(int i = 0; i<m; i++) {
            scanf("%d", &coef2[i]);
            scanf("%d", &expo2[i]);
        }

        for(int i = 0; i<m; i++){
            Term term;
            term.coef = coef2[i];
            term.expo = expo2[i];
            
            polynomial_B.push_back(term);
        
        }
        Print(merge(polynomial_A, polynomial_B));
    }
}