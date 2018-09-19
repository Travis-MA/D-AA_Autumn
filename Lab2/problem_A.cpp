#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string ans_list[t];
    for(int k = 0; k<t; k++){
        int n;
        cin >> n;
        int m;
        cin >> m;
        int hight_char[n];

        for(int i = 0; i<n; i++){
            int hight;
            cin >> hight;
            hight_char[i] = hight;
        }

        int start = 0;
        int end = n;
        bool have = false;
        
        while (start <= end) {
            int middle = (start + end)/2;
            if (m > hight_char[middle]){
                start = middle+1;
                continue;
            }else if (m < hight_char[middle]){
                end = middle-1;
                continue;
            }else{
                have = true;
                break;
            }
        }
            
        if(have == true){
            ans_list[k] = "YES";
        }else{
            ans_list[k] = "NO";
        }
        
    }

    for(int k = 0; k<t; k++){
        cout << ans_list[k] << endl;
    }
}
