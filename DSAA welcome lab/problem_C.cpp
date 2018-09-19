#include<iostream>
#include<string>
using std::string;

int main(int argc, char *argv[]){
    int t;
    std::cin >> t;
    string winner_array[t];

    for(int k = 0; k<t; k++){
        int x;
        std::cin >> x;
        int y;
        std::cin >> y;

        if(x == 1 && y == 1){
            winner_array[k] = "Bob";
        }else{
            winner_array[k] = "Alice";
        }

    }

    for(int k = 0; k<t; k++){
        std::cout << winner_array[k] << std::endl;
    }
}