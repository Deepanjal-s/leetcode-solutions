// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwis

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    char* m;
    int i;
    int flag = 0;
    for(i = 0; s[i] != '\0'; i++){
        m[i] = s[i];
    }
    for(int j = i - 1,i = 0; j > 0 && s[i] == '\0'; j--,i++){
        if(m[j] == s[i]){
            flag = 1;
        }else{
            flag = 0;
        }
    }
    if(flag == 0){
        return false;
    }else{
        return true;
    }
}


int main(){

    
}