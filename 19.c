#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

int cgetline(char line[], int maxLine);
void reverse(char to[], char from[]);

int main(){
    int len;
    char line[MAXLINE];
    char final[MAXLINE];

    while((len = cgetline(line, MAXLINE)) > 0){
        reverse(final, line);
        printf("%s\n", final);
    }
    return 0;
}

int cgetline(char s[], int lim){
    int c, i;
    
    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void reverse(char to[], char from[]){
    int i = 0;

    while((to[i] = from[(strlen(from) - 1)-i]) && i > -1)
        i++;
}