#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
	char ch;
	struct node *next;
}Node, *ptrNode;

ptrNode getPhrase();
ptrNode reverseLetters(ptrNode);
int compare(ptrNode,ptrNode);

int main(){
	ptrNode phrase, s1, s2;

	printf("Type a phrase. (To stop, press 'Enter' only): ");
	phrase = getPhrase();

	while(phrase != NULL){
		s1 = reverseLetters(phrase);
		s2 = reverseLetters(s1);
		if(compare(s1,s2) == 0)
			printf("is palindrome\n");
		else
			printf("is not palindrome\n");
		printf("Type a phrase. (To stop, press 'Enter' only): ");
		phrase = getPhrase();
	}
	return 0;
}

ptrNode getPhrase(){
	ptrNode top = NULL, last, np;
	char c = getchar();
	while(c != '\n'){
		np = (ptrNode) malloc(sizeof(Node));
		np->ch = c;
		np->next = NULL;
		if(top == NULL)
			top = np;
		else
			last->next = np;
		last = np;
		c = getchar();
	}
	return top;
}

ptrNode reverseLetters(ptrNode top){
	ptrNode rev = NULL, np;
	char c;
	while(top != NULL){
		c = top->ch;
		if(isalpha(c)){
			np = (ptrNode) malloc(sizeof(Node));
			np->ch = tolower(c);
			np->next = rev;//lo añade al principio
			rev = np;
		}
		top = top->next;
	}
	return rev;
}

int compare(ptrNode s1, ptrNode s2){
	while(s1 != NULL){
		if(s1->ch < s2->ch)
			return -1;
		else if(s1->ch > s2->ch)
			return 1;
		s1 = s1->next;
		s2 = s2->next;
	}
	return 0;
}