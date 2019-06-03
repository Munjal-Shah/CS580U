#include <stdio.h>
#include <string.h>
#define INT_SIZE sizeof(int) * 8
int myStrStr(char *haystack, char *needle, char *buffer){
    int i=0, j=0, isSub=0;
    memset(&buffer[0], 0, 255);
    while ( '\0' != haystack[i] && '\0' != needle[j] ){
        if (haystack[i] != needle[j]){
            ++i;
            j=0;
        }
        else{
            buffer[j] = needle[j];
            ++i;
            ++j;
        }
    }
    if (  '\0' == needle[j]){
        isSub = 1;
    }
    return isSub;
}

void binaryArray(int n, int array[], int size){
    int i,j;
    for (i=0; i<size; ++i){
        array[size-i-1] = (n >> i) & 1;
    }
}

void binaryPrinter(int array[], int size){
    int i;
    for (i=0;i<size; ++i)
        printf("%d", array[i]);
}

unsigned int countOnes(int num){
    int ones = 0;
    for(int i=0; i<INT_SIZE; i++)
    {
        if (num & 1)
            ones++;        
        num >>= 1;
    }
    return ones;
}