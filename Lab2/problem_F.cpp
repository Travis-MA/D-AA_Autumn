#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
struct Boy{
    double x, w;
};
Boy boy_list[500010];
int n;

double vel(double p){
    double length = 0;
    for(int i = 0; i<n; i++){
        length += pow(fabs(boy_list[i].x - p), 3.00) * boy_list[i].w;
    }
    //cout << "length:  " << length  << " p: " << p << endl;
    return length;
}

double solve(double l,double r){  

    double mid = 0;
    double mmid = 0;

    while(r-l>1e-12){  
        mid  = (l + r)/2;  
        mmid = (mid + r)/2;  
        if( vel(mid) > vel(mmid) ) { 
            l = mid;  
        }else {
            r = mmid;  
        }
    }

    double ans = (mid + mmid)/2;
    return ans; //> vel(r, n) ? l : r;  
}  


int main(){
    //std::ios::sync_with_stdio(false);
    //cout.setf(ios::fixed,ios::floatfield);
    //cout.precision(0);

    int t;
    scanf("%d" , &t);
    double ans_list[t];
    for(int k = 0; k<t; k++){

        scanf("%d" , &n);
        double max_length = 0;
        for(int i = 0; i<n; i++) {
            scanf("%lf%lf",&boy_list[i].x, &boy_list[i].w);
        }   
        
        //max_length = boy_list[n-1].x;
        double x = solve(boy_list[0].x, boy_list[n-1].x);
        ans_list[k] = vel(x);
        //ans_list[k] = 12387435678297378766.6237867;
    }

    for(int k = 0; k<t; k++){
        printf("Case #%d: %.0f\n",k+1, ans_list[k]);
        //cout << "Case #" << k+1 << ": " << ans_list[k]+0.5 << endl;
    }
}




