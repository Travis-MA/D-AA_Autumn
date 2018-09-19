#include<iostream>
#include<string>
using std::string;

int * two_two(int x, int y, int z, int mode){
    static int dim[2];
    dim[0] = 2*x + 2*y;
    if(mode == 0) //standard
        dim[1] = 2*x + z;

    if(mode == 1) //strange
        dim[1] = 2*y + z;

    if(mode == 2) //triple
        dim[1] = x + y + z;
    
    return dim;
}

int * three_two(int x, int y, int z, int mode){
    static int dim[2];
    dim[0] = x + y + 2*z;
    if(mode == 0) //standard
        dim[1] = 2*x + y;

    if(mode == 1) //strange
        dim[1] = 2*y + x;

    if(mode == 2) //triple
        dim[1] = x + y + z;

    return dim;
}

int * three_two_strange(int x, int y, int z){
    static int dim[2];

    dim[0] = x + y + 3*z;
    dim[1] = x + y;

    return dim;
}

int main(int argc, char *argv[]){
    int t;
    std::cin >> t;
    string print_vel[t];

    for(int k = 0; k<t; k++){
        
        int a;
        std::cin >> a;
        int b;
        std::cin >> b;
        int c;
        std::cin >> c;
        int n;
        std::cin >> n;
        int m;
        std::cin >> m;

        int dimension[21][2];
        int count = 0;
        bool yes = false;

        for(int i = 0; i<3; i++){
            for(int mode = 0; mode<3; mode++){
                if(i == 0){
                    dimension[count][0] = two_two(a, b, c, mode)[0];
                    dimension[count][1] = two_two(a, b, c, mode)[1];
                    count++;
                }
                if(i == 1){
                    dimension[count][0] = two_two(b, c, a, mode)[0];
                    dimension[count][1] = two_two(b, c, a, mode)[1];
                    count++;
                }
                if(i == 2){
                    dimension[count][0] = two_two(a, c, b, mode)[0];
                    dimension[count][1] = two_two(a, c, b, mode)[1];
                    count++;
                }
            }
        }

        for(int i = 0; i<3; i++){
            for(int mode = 0; mode<3; mode++){
                if(i == 0){
                    dimension[count][0] = three_two(a, b, c, mode)[0];
                    dimension[count][1] = three_two(a, b, c, mode)[1];
                    count++;
                }
                if(i == 1){
                    dimension[count][0] = three_two(b, c, a, mode)[0];
                    dimension[count][1] = three_two(b, c, a, mode)[1];
                    count++;
                }
                if(i == 2){
                    dimension[count][0] = three_two(a, c, b, mode)[0];
                    dimension[count][1] = three_two(a, c, b, mode)[1];
                    count++;
                }
            }
        }

        for(int i = 0; i<3; i++){
            if(i == 0){
                dimension[count][0] = three_two_strange(a, b, c)[0];
                dimension[count][1] = three_two_strange(a, b, c)[1];
                count++;
            }
            if(i == 1){
                dimension[count][0] = three_two_strange(b, c, a)[0];
                dimension[count][1] = three_two_strange(b, c, a)[1];
                count++;
            }
            if(i == 2){
                dimension[count][0] = three_two_strange(a, c, b)[0];
                dimension[count][1] = three_two_strange(a, c, b)[1];
                count++;
            }
        }
        
        for(int i = 0; i<21; i++){
            if(dimension[i][0] <= n && dimension[i][1] <= m){
                yes = true;
                break;
            }
            if(dimension[i][0] <= m && dimension[i][1] <= n){
                yes = true;
                break;
            }
        }

        if(yes == true){
            print_vel[k] = "Yes";
        }else{
            print_vel[k] = "No";
        }
    }

    for(int k = 0; k<t; k++){
        std::cout << print_vel[k] << std::endl;
    }
}