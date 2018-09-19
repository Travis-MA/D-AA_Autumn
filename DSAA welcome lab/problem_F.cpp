#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    string origin_letter;
    std::cin >> origin_letter;
    vector<char> indiv_letter;
    
     
    int len = origin_letter.length();
    for(int i = 0; i<len; i++){
        if(origin_letter[i] == 'a' || 
            origin_letter[i] == 'e' || 
            origin_letter[i] == 'i' || 
            origin_letter[i] == 'o' || 
            origin_letter[i] == 'u' || 
            origin_letter[i] == 'w' || 
            origin_letter[i] == 'y' ){
           
            origin_letter[i] = '_';
        }

        if(origin_letter[i] != '_'){
            bool new_letter = true;
            for(int j = 0; j<indiv_letter.size(); j++){
                if(indiv_letter.empty() == false){
                    if(origin_letter[i] == indiv_letter[j]){
                        cout << indiv_letter[j] << " : " << origin_letter[i] << endl;
                        new_letter = false;
                        break;
                    }
                }
            }

            if(new_letter == true){
                indiv_letter.push_back(origin_letter[i]);
            }
        }
         
     }


}