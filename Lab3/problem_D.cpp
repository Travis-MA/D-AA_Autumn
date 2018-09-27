#include<iostream>
#include<list>
#include<cstdio>
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

list<Term> diff(list<Term> term_list){


    list<Term>::iterator add_iter = term_list.begin();
    while(add_iter != term_list.end()){
        Term now = *add_iter;
        add_iter++;
        if(add_iter != term_list.end()){
            Term next = *add_iter;
            if(now.expo == next.expo){
                add_iter = term_list.erase(add_iter);
                add_iter--;
                add_iter->coef = now.coef + next.coef;
            }
        }else break;
    }
    
    list<Term>::iterator iter = term_list.begin();
    while(iter != term_list.end()){
        iter->coef = iter->coef * iter->expo;
        iter->expo = iter->expo - 1;
        iter++;
    }

    return term_list;
}


list<Term> merge(list<Term> sublist_A, list<Term> sublist_B){
    int start = 0;
    int k = 0;
    list<Term>::iterator iter_A = sublist_A.begin();
    list<Term>::iterator iter_B = sublist_B.begin();
    list<Term> ans;
    int acont = 0;
    int bcont = 0;

    while(iter_A != sublist_A.end() && iter_B != sublist_B.end()){
        
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

    while(acont < sublist_A.size()){
        ans.push_back(*iter_A);
        iter_A++;
        acont++;
    }

    while(bcont < sublist_B.size()){
        ans.push_back(*iter_B);
        iter_B++;
        bcont++;
    }

    return ans;

}

list<Term> expo_sort(list<Term> head){
    if(head.size() <= 1){
        return head;
    }
    int mid = head.size()/2;
    int cout = 0;
    list<Term> left;
    list<Term> right;
    list<Term>::iterator iter = head.begin();

    while(iter != head.end()){
        if(cout<mid) left.push_back(*iter);
        else right.push_back(*iter);
        iter++;
        cout++;
    }

    return merge(expo_sort(left), expo_sort(right));
} 



int main(){
    int t;
    scanf("%d", &t);
    
    for(int k = 0; k<t; k++){
        int n;
        scanf("%d", &n);
        list<Term> term_list;
        Term write;
        for(int i = 0; i<n; i++){
            scanf("%d", &write.coef);
            scanf("%d", &write.expo);
            term_list.push_back(write);
        }

        Print(diff(expo_sort(term_list)));

    }

}