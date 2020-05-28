/*
 * @Author: your name
 * @Date: 2020-04-24 12:23:18
 * @LastEditTime: 2020-04-24 13:01:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\problems\leetcode\32 c.c
 */
#include <stdlib.h>
#include <stdio.h>

int longestValidParentheses(char * s){
    int length;
    for (length = 0; s[length] != 0; length++);
    if (length == 0) return 0;
    int *str = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) str[i] = -1;
    
    for (int i = 0; i < length; i++){
        if (s[i] == ')'){
            for (int j = i; j >= 0; j--){
                if (s[j] == '(' && str[j] == -1){
                    str[i] = j; //随你赋值，只要别是-1就好啦
                    str[j] = i; //随你赋值，只要别是-1就好啦
                    break;
                }
            }
        }
    }
    int *index = (int*)malloc((length + 2) * sizeof(int));
    for (int i = 0; i < length; i++) index[i] = -1;

    int pointer = 1;
    for (int i = 0; i < length; i++){
        if (str[i] == -1){
            index[pointer++] = i;
        }
    }
    index[pointer] = length;

    int max = -1;
    for (int i = 0; i < length + 1; i++){
        int temp = index[i + 1] - index[i] - 1;
        if (temp > max) max = temp;
    }
    return max;
}

int main(){
    char str[2000];
    gets(str);
    printf("%d",longestValidParentheses(str));
    system("pause");
    return 0;
}