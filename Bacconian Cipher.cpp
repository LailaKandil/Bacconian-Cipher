#include <iostream>
#include<cmath>
#include <string>

using namespace std;

string ab_binary(int n){
    string bin = "";
    for (int i = 1<< 4; i>0; i=i/2){
        if((i&n) !=0){
            bin += 'b'; //1
        }else{
            bin += 'a'; //0
        }
    }
    return bin;
}

char abToChar(string ab_binary){
    int num =0;
    for(int i = 0; i < ab_binary.length(); i++){
        if(ab_binary[i] == 'b'){ //1
            num += pow(2, ab_binary.length()-1-i);
        }
    }
    char c = 'A' + num;
    return c;
}

string encrypt_bacconian(string word){

    string encrypted = "";
    for (int i=0; i<word.length(); i++){
        char ch = word[i];
        int char_index = ch - 'A';
        encrypted += ab_binary(char_index) + " ";
    }
    return encrypted;
}

string decrypt_bacconian(string encryptedWord){
    string decrypted = "";
    // increment by 6 (we only need to enter the loop once for each 5 characters representing a&b and we need to skip the space in between)
    for (int i=0; i<encryptedWord.length(); i+=6){
        //substr takes the starting index and the desired length
        string encryptedChar= encryptedWord.substr(i, 5);
        char decryptedChar = abToChar(encryptedChar);
        decrypted += decryptedChar;
    }
    return decrypted;
}

int main() {
    cout << encrypt_bacconian("SAMY") <<endl;
    cout << decrypt_bacconian("baaba aaaaa abbaa bbaaa");

}