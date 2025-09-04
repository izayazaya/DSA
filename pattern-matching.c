/*
    ooooo  .oooooo..o       .o.       ooooo       .o.       ooooo   ooooo 
    `888' d8P'    `Y8      .888.      `888'      .888.      `888'   `888' 
     888  Y88bo.          .8"888.      888      .8"888.      888     888  
     888   `"Y8888o.     .8' `888.     888     .8' `888.     888ooooo888  
     888       `"Y88b   .88ooo8888.    888    .88ooo8888.    888     888  
     888  oo     .d8P  .8'     `888.   888   .8'     `888.   888     888  
    o888o 8""88888P'  o88o     o8888o o888o o88o     o8888o o888o   o888o 
*/

#include <stdio.h>
// #include <string.h> --- doing this without this library!!!

// Original implementation of strstr function

char* originalStrStr(const char *str1,const char *str2){
    const char *a;
    const char *b;

    b = str2;

    if(*b == 0){
        return (char *) str1;
    }

    for(; *str1 != 0; str1++){
        if(*str1 != *b){
            continue;
        }

        a = str1;
        while(1){
            if(*b == 0){
                return (char *) str1;
            }
            if(*a++ != *b++){
                break;
            }
        }
        b = str2;
    }
    return NULL;
}

// Function to count how many occurences of the substring in a given string

int countSubstring(const char *str1, const char *str2){
    int count = 0;
    const char *a = str1;
    while(a = originalStrStr(a, str2)){
        count++;
        a++;
    }
    return count;
}

char* originalStrCpy(char *str1, const char *str2){
    if(str1 == NULL || str2 == NULL){
        return NULL;
    }

    char *a = str1;

    while((*str1++ = *str2++));

    return a;
} 

int main(void){
    char string[100] = "String Pattern Matching Exercise in Data Structures and Algorithms";
    char find[50] = "ing";
    char *p;

    p = originalStrStr(string, find);

    if(p){
        printf("Substring found!\n");
        printf("The substring \"%s\" appears %i times\n", find, countSubstring(string, find));
    }else{
        printf("Substring not found!\n");
    }

    return 0;
}

// It is 6:50 PM and I know I don't have enough time to figure out how to replace, insert and
// delete select substrings from a string.
