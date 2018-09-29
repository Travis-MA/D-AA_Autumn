#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

int place[500002];
int l,n,m;


bool check(int mid){
    int man = 1;
    int pivot = place[0];
    for(int i = 0; i<(n+2); i++){
        for(int i = 0; i<(n+2); i++){
            if((place[i+1] - pivot) > mid && (place[i] - pivot) <= mid){
                man++;
                pivot = place[i];
                if(man > m){
                    return false;
                }
                break;
            }
        }
    }
   return true;
   
}



double solve(int l, int r){
    int mid;
    while(r - l >= 0){
        mid = (l + r)/2;
        cout << "mid: " << mid << " r: " << r << " l: " << l << endl;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
        
    }
    cout <<  " r: " << r << " l: " << l << endl;
    return l;
}

int main(){
    
    while(cin >> l){
        cin >> n;
        cin >> m;

        place[0] = 0;
        place[n + 1] = l;

        for(int i = 0; i<n; i++){
            cin >> place[i + 1];
        }

        sort(place, place+(n+2));

        cout << solve(0,l) << endl;
        
    }
}
