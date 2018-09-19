#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>

using namespace std;

int n,k;
struct Score{
    int up,down;
};
Score gpa[100000];
double line[100000];

bool check(double x){
    double sum=0;
    for(int i = 0; i<n; i++) line[i] = gpa[i].up - x*gpa[i].down;
    sort(line, line+n);
    for(int i = n-1; i>=k; i--) sum += line[i];
    
    if(sum>0) return true;
    else return false;
    
}

double solve(double l,double r){
    double mid;
    while(r - l > 0.000001){
        mid = (l + r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    return mid;
}

int main(){
    
    while(cin >> n){
        cin >> k;
        double max_gpa = 0;
        for(int i = 0; i<n; i++)scanf("%d",&gpa[i].down);

        for(int i = 0; i<n; i++){
            int score;
            scanf("%d", &score); 
            gpa[i].up = score * gpa[i].down;
            max_gpa = max(1.0*gpa[i].up/gpa[i].down, max_gpa);
        }

        printf("%.3f\n", solve(0, max_gpa));
    }
    return 0;
}