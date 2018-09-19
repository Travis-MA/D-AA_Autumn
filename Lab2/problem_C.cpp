#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t; 
    cin >> t;
    int print_vel[t];
    for(int k = 0; k<t ;k++){
        int n;
        cin >> n;
        int m;
        cin >> m;
        int strength[n];
        for(int i = 0; i<n; i++){
            cin >> strength[i];
        }

        int times = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int pivod = strength[i];
                if(strength[j] == (m-pivod)){
                    times++;
                }
            }
        }

        print_vel[k] = times/2;
    }

    for(int k = 0; k<t; k++){
        cout << print_vel[k] << endl;
    }
}