#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

int place[500002];
int l,n,m;


bool check(int mid){
    int step = 1;
    int pivots = 0;
    int i = 0;
    int twist = 0;
    while(i<n+2){
        if(place[i] - place[pivots] > mid || place[n+1] - place[pivots] == mid){
            int new_pivots = i-1;
            cout << "pivots: " << new_pivots << endl;
            i--;
            if(new_pivots == pivots){
                return false;
            }
            twist += place[new_pivots] - place[pivots];
            pivots = new_pivots;
            
            step++;
            if(step > m){
                return false;
            }
        }
        i++;
    }
    cout << "step: " << step << endl;
    if(step <= n){
        return true;
    }
    
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
