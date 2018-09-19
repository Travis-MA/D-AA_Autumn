#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using std::cout;
using std::endl;
using std::cin;

double y;

double get_min(double x){
    double gee_x = 35*pow(x,6) + 36*pow(x,5) + 9*pow(x,2) + 8*x - 2*y;
    double gee_dif_x = 210*pow(x,5) + 180*pow(x,4) + 18*x + 8;
    double x_plus = x - gee_x/gee_dif_x;

    if(x_plus - x < 0.000001 && x_plus - x > 0 || (x - x_plus < 0.000001 && x - x_plus > 0)){

        return x_plus;

    }else if(x_plus < 0){
        return 0;
    }else if(x_plus > 100){
        return 100;
    }else{
        //cout << "loop: "<< x_plus << endl;
        get_min(x_plus);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    double return_vel[t];
    for(int k = 0; k<t; k++){
        y = 0;
        cin >> y;
        double x = get_min(50.0);
        //cout << "x: " << x << " hh: " <<std::setprecision(10)<< 5*pow(x,7) << endl;
        double min_vel = 5*pow(x,7) + 6*pow(x,6) + 3*pow(x,3) + 4*pow(x,2) -2*x*y;
        return_vel[k] = min_vel;
    }

    for(int k = 0; k<t; k++){
        
        printf("Case ");
        printf("%d",k+1);
        printf(": ");
        printf("%.4f\n", return_vel[k]); 
        
        
    }

}
