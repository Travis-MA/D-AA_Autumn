#include<iostream>
#include<string>
using std::string;

int threeD_print(int l, int w, int h){

    int H_strait = 3 + 2 * (h-1) - 2 * w;
    int H_tilt = 2 * w;
    int L_total = 2 * (w+l) + 1;
    int L_dot_max = H_tilt;
    int L_notdot_max = L_total - L_dot_max;

    for(int H = 0; H < H_tilt; H++){
        string print;

        for(int L = 0; L < L_total; L++){
            if(L < ( L_dot_max-H )){
                print.append(".");
            }else{
                
                if(H%2 == 0){   // H is odd
                    if(L%2 == 0){  //L is odd
                        print.append("+");
                    }else{
                        if(L >= L_total-H){
                            print.append(".");
                        }else{
                            print.append("-");
                        }
                    }
                }else{
                    if(L%2 == 0){
                        if(L >= L_total-H){
                            print.append("|");
                        }else{
                            print.append(".");
                        }
                    }else{
                        print.append("/");
                    }
                }  
            }
        }
        std::cout << print << std::endl;
    }

    for(int H = 0; H < H_strait; H++){
        string print;

        for(int L = 0; L < L_total; L++){
            
            if(H%2 == 0){   // H is odd
                if(L%2 == 0){  //L is odd
                    print.append("+");
                }else{
                    if(L < L_notdot_max){
                        print.append("-");
                    }else{
                        print.append(".");
                    }
                }
            }else{
                if(L%2 == 0){  //L is odd
                    print.append("|");
                }else{
                    if(L < L_notdot_max){
                        print.append(".");
                    }else{
                        print.append("/");
                    }
                }
            }
        }
        std::cout << print << std::endl;
    }

    for(int H = 0; H < H_tilt; H++){
        string print;
        
        for(int L = 0; L < L_total; L++){
            
            if(L < ( L_total-H-1 )){
                
                if(H%2 == 0){   // H is odd
                    if(L%2 == 0){  //L is odd
                        print.append("|");
                    }else{
                        if(L >= L_notdot_max){
                            print.append("/");
                        }else{
                            print.append(".");
                        }
                    }
                }else{
                    if(L%2 == 0){
                        print.append("+");
                    }else{
                        if(L >= L_notdot_max){
                            print.append(".");
                        }else{
                            print.append("-");
                        }
                    }
                }    
            }else{
                print.append(".");
            }
        }
        std::cout << print << std::endl;
    }
    return 0;
}
int main(int argc, char *argv[]){
    int t = 0; //  The test case's num
    std::cin >> t;
    int dimension[t][3];

    for(int i = 0; i < t; i++){
        int l;
        int w;
        int h;
        std::cin >> l;
        std::cin >> w;
        std::cin >> h;
        dimension[i][0] = l;
        dimension[i][1] = w;
        dimension[i][2] = h;
    }

    for(int i = 0; i < t; i++){
        threeD_print(dimension[i][0],dimension[i][1],dimension[i][2]);
    }

}
    
