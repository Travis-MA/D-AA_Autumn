#include<iostream>

int main(int argc, char *argv[]){
    int t;
    std::cin >> t;
    
    int ans_vel[t];
    
    for(int k = 0; k<t; k++){
        int n;
        std::cin >> n;
        
        int number[n];

        for(int i = 0; i<n; i++){
            int num;
            std::cin >> num;
            number[i] = num;
        }
        
        int minus = number[0] - number[1];
        int max = number[0];

        for(int i = 1; i<n; i++){
            if(minus < max - number[i]){
                minus = max - number[i];
            }
            if(max < number[i]){
                max = number[i];
            }
        
        }
        ans_vel[k] = minus;
    }

    for(int k = 0; k<t; k++){
        std::cout << ans_vel[k] << std::endl;
    }
}