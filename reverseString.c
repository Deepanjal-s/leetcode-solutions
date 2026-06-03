#include <stdio.h>

/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.*/

void reverseString(char* s, int sSize) {
    for(int i = 0,j = sSize - 1; i < j; i++,j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(){

    char arr[] = "myname";
    reverseString(arr,6);
    printf("%s",arr);

}