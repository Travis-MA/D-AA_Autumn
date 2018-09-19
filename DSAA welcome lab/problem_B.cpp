#include<iostream>
#include<string>
using std::string;

string movetime;

void hanoitower(int n){
    if(n == 1){
        move_time = move_time + 2;
    }else{
        hanoitower(n - 1);
        move_time++;            
        hanoitower(n - 1);
        move_time++;
        hanoitower(n - 1);
    }
}

int main(int argc, char *argv[]){
    int t = 0;
    std::cin >> t;
    int ans_array[t];

    for(int i = 0; i<t; i++){
        move_time = 0;
        int n = 0;
        std::cin >> n;
        hanoitower(n);
        ans_array[i] = move_time;
    }

    for(int i = 0; i<t; i++){
        std::cout << ans_array[i] << std::endl;
    }

}
