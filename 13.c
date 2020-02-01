#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define OUT 0
#define IN 1
int main(int argc, const char * argv[]){
	long nc = 0;
	long nw = 0;
	long tempnc = 0;
	int words[25];

	char c = getchar();

	memset(words, 0, sizeof(words));
	int state = OUT;
	while (c != EOF){
		if(isalpha(c) || c == '-'){
			nc++;
			tempnc++;
		}
		
		if(c == ' ' || c == '\n' || c == '\t'){
			if(nw > 0){
				words[tempnc]++;
				tempnc = 0;
			}
			state = OUT;
		}else if(state == OUT){
			state = IN;
			nw++;
		}

		c = getchar();
	}

	printf("\nThere are %ld characters and %ld words\n\n", nc, nw);

	//horizontal
	for(int i = 0; i < 25; i++){
		printf("%d: ", i);
		for(int j = 0; j < words[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	//vertical
	int hiNumbr = 0;
	for(int i = 0; i < 25; i++){
		printf("%d ", i);
		if(words[i] > hiNumbr)
			hiNumbr = words[i]; //get the highest count in the array
	}
	for(int j = 1; j < hiNumbr+1; j++){
		printf("\n");
		for(int i = 0; i < 25; i++){
			if(words[i] >= j)
				printf((i > 9) ? "*  " : "* ");
			else
				printf((i > 9) ? "   " : "  ");
		}
	}
	printf("\n\n");
	return 0;
}
