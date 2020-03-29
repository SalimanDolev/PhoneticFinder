#include "PhoneticFinder.hpp"
#include "iostream"
#include <string>
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
using namespace std;

bool check_equals(char a , char b){
    if(a==b) return true;
    //checks the d / t 
    if((a == 'd' && b== 't') || (a=='t' && b=='d')) return true;
    //checks the v / w
    if((a == 'v' && b== 'w') || (a=='w' && b=='v')) return true;
    //checks the b / f /p
    if((a == 'b' && b== 'f') || (a=='b' && b=='p')) return true;
    if((a == 'f' && b== 'p') || (a=='f' && b=='b')) return true;
    if((a == 'p' && b== 'f') || (a=='p' && b=='b')) return true;
    //checks the c / k /q
    if((a == 'c' && b== 'k') || (a=='c' && b=='q')) return true;
    if((a == 'k' && b== 'c') || (a=='k' && b=='q')) return true;
    if((a == 'q' && b== 'c') || (a=='q' && b=='k')) return true;
    //checks the z / s
    if((a == 'z' && b== 's') || (a=='s' && b=='z')) return true;
    //checks the o / u
    if((a == 'o' && b== 'u') || (a=='u' && b=='o')) return true;
    //checks the i / y
    if((a == 'i' && b== 'y') || (a=='y' && b=='i')) return true;
    //checks the g / j
    if((a == 'g' && b== 'j') || (a=='j' && b=='g')) return true;
    return false;
}

bool checks_lower_upper(string a, string b){
    if (a.compare(b)!=0) return false;
    else return true;
}

bool checkIfFullWord (string text, int i){
    if(text.size() == i) return true; 
    if(text.at(i) != ' ' ) {return false;}
    else  {return true;}
}

string phonetic::find(string text,string word){
    if ( text == "" || text ==" ") throw out_of_range("The text is empty");
    string tmp = text;
    string word_tmp = word;

    std::transform (text.begin(), text.end(), text.begin(), ::tolower);
    std::transform (word.begin(), word.end(), word.begin(), ::tolower);
    
    int counter = 0;
    for (int i = 0; i < text.size(); i++)
    {   
        if(text.at(i)!= ' '){
            for (int j = 0; j < word.size(); j++)
            {
                if(check_equals(text.at(i),word.at(j))== true){  
                    counter++;i++;
                }
                else break;
            }
            // checks if the size of the words are the same
            // checks if all is upper or lower
                if(counter == word.size() && checkIfFullWord(text,i) == true) {
                    string ans = tmp.substr(i-counter,counter);
                    return ans;
                }
            counter =0;
        }
    }
    throw out_of_range("The Word is not in te text");
};