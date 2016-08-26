#include <stdio.h>
#include <string.h>

#define MaxCandidates 7
#define MaxNameLength 30

typedef struct{
	char name[MaxNameLength];
	int numVotes;
}PersonData;

typedef struct{
	int valid, spoilt;
}VoteCount;

int main(){

	void initialize(PersonData[], int, FILE *);
	VoteCount processVotes(PersonData[], int, FILE *, FILE *);
	void printResults(PersonData[], int, VoteCount, FILE *);

	PersonData candidate[MaxNameLength + 1];
	VoteCount count;

	FILE *in = fopen("input2.txt","r");
	FILE *out = fopen("results.txt","w");

	initialize(candidate, MaxCandidates, in);
	count = processVotes(candidate, MaxCandidates, in, out);
	printResults(candidate, MaxCandidates, count, out);

	fclose(in);
	fclose(out);

	return 0;
}

void initialize(PersonData person[], int max, FILE *in){
	char lastName[MaxNameLength];

	for(int i = 1; i <= max; i++){
		fscanf(in,"%s %s",person[i].name,lastName);
		strcat(person[i].name, " ");
		strcat(person[i].name, lastName);
		person[i].numVotes = 0;
	}
}

VoteCount processVotes(PersonData person[], int max, FILE *in, FILE *out){
	VoteCount tmp;
	tmp.valid = tmp.spoilt = 0;

	int v;
	fscanf(in,"%d",&v);
	while(v != 0){
		if( (v < 1) || (v > max) ){
			fprintf(out,"Invalid vote: %d\n",v);
			tmp.spoilt++;
		}else{
			person[v].numVotes++;
			tmp.valid++;
		}
		fscanf(in,"%d",&v);
	}
	return tmp;
}

int getLargest(PersonData person[], int lo, int hi){
	int big = lo;
	for(int i = lo + 1; i <= hi; i++)
		if(person[i].numVotes > person[big].numVotes)
			big = i;
	return big;
}

void printResults(PersonData person[], int max, VoteCount c, FILE *out){
	int getLargest(PersonData[], int, int);
	fprintf(out,"\nNumer of voters: %d\n",c.valid + c.spoilt);
	fprintf(out,"Number of valid votes: %d\n",c.valid);
	fprintf(out,"Number of spoilt Votes: %d\n",c.spoilt);
	fprintf(out,"\nCandidate	Score\n\n");

	for(int i = 1; i <= max; i++)
		fprintf(out,"%-15s %3d\n",person[i].name,person[i].numVotes);

	fprintf(out,"\nThe winner(s)\n");

	int win = getLargest(person, 1, max);
	int winningVote = person[win].numVotes;
	for(int i = 1; i <= max; i++)
		if(person[i].numVotes == winningVote)
			fprintf(out,"%s\n",person[i].name);
}