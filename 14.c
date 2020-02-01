#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define OUT 0
#define IN 1
int main(int argc, const char * argv[]){
	long nc = 0;
	long nw = 0;

	char c = getchar();

	int words[26] = {};

	int state = OUT;
	while (c != EOF){
		if(c != '\n' && isalpha(c)){
			c = tolower(c);
			nc++;
			words[c-97]++;
		}

		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			nw++;
		}

		c = getchar();
	}

	printf("\nThere are %ld characters and %ld words\n\n", nc, nw);
	printf("\nNumbers correspond by letter, e.g. (a=1)\n");
	//horizontal
	for(int i = 0; i < 26; i++){
		printf("%d: ", i+1);
		for(int j = 0; j < words[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//vertical
	int hiNumbr = 0;
	for(int i = 0; i < 26; i++){
		printf("%d ", i+1);
		if(words[i] > hiNumbr)
			hiNumbr = words[i]; //get the highest count in the array
	}
	for(int j = 1; j < hiNumbr+1; j++){
		printf("\n");
		for(int i = 0; i < 26; i++){
			if(words[i] >= j)
				printf((i > 9) ? "*  " : "* ");
			else
				printf((i > 9) ? "   " : "  ");
		}
	}
	printf("\n\n");
	return 0;
}
