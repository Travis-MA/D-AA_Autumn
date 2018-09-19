#include<iostream>
#include<string>
#include <algorithm>
#include<time.h>

using std::string;


bool compare(string alg_name_str[], string article_str[], int n, int m){
    
    //bool thesame = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(alg_name_str[i] == article_str[j]){
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[]){
    int t = 0; //  The test case's num
    std::cin >> t; 
    string ans_list[t];//answer list

    for(int i = 0; i < t; i++){
        int n = 0; //The algorithm set num
        int m = 0; //The article word num
        std::cin >> n;

        string alg_name_str[n]; //The algorithm set string array
        
        
        for(int j = 0; j < n; j++){
            string alg_name;
            std::cin >> alg_name;
            transform(alg_name.begin(),alg_name.end(),alg_name.begin(),::tolower);
            alg_name_str[j] = alg_name;
        }

        std::cin >> m;
        string article_str[m]; //The article content
        
        for(int j = 0; j < m; j++){
            string article_word;
            std::cin >> article_word;
            transform(article_word.begin(),article_word.end(),article_word.begin(),::tolower);
            article_str[j] = article_word;
        }   

        if(compare(alg_name_str, article_str, n, m) == true){
            ans_list[i] = "Appeared";
        }else{
            ans_list[i] = "Not appeared";
        }

    }

    for(int i = 0; i < t; i++){
        std::cout << ans_list[i] << std::endl;
    }

return 0;
}
