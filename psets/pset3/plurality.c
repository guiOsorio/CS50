// simulates a plurality-type election using command-line arguments as the candidates

#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char* name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(char* name);
void print_winner(void);

int main(int argc, char* argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    int i;
    for (i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
	printf("Number of voters: ");
	scanf("%i", voter_count);

    // Loop over all voters
    int j;
    for (j = 0; j < voter_count; j++)
    {
        char name[50];
		printf("Vote: ");
		scanf("%s", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(char* name)
{
    // TODO
    int k;
    for(k = 0; k < candidate_count; k++) {
        if(strcmp(candidates[k].name, name) == 0) {
            candidates[k].votes++;
            return 1;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_votes = 0;
	
	int i;
    for(i = 0; i < candidate_count; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

	int k;
    for(k = 0; k < candidate_count; k++) {
        if(candidates[k].votes == max_votes) {
            printf("%s\n", candidates[k].name);
        }
    }

    return;
}


