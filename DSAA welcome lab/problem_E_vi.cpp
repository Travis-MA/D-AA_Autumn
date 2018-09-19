#include<iostream>
#include<string>
using std::string;

int main(int argc, char *argv[]){
    int t;
    std::cin >> t;
    int print_char[t];

    for(int k = 0; k<t; k++){

        int n;
        std::cin >> n;
        int number[n];
        int now_biggest;
        int prev_biggest = 0;
        int first_cout = 1;

        for(int i = 0; i<n; i++){
            int num;
            std::cin >> num;
            number[i] = num;
        }

        int biggest[n-1];

        for(int i = 0; i<n; i++){
            int father = number[i];
            int biggest_vel = father - number[i+1];

            for(int j = i+1; j<n; j++){
                int minus_vel = father - number[j];
                if(minus_vel >= biggest_vel){
                    biggest_vel = minus_vel;
                }
            }
            
            if(first_cout == 1){
                prev_biggest = biggest_vel;
            }

            if(biggest_vel >= prev_biggest){
                now_biggest = biggest_vel;
            }
            first_cout++;
        }

        print_char[k] =  now_biggest;
    }

    for(int k = 0; k<t; k++){
        std::cout << print_char[k] << std::endl;
    }
}
