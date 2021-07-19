// simulates a plurality-type election using command-line arguments as the candidates

#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char* name;
    int votes;
    int eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
int vote(int voter, int rank, char* name);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main(int argc, char* argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    int d;
    for (d = 0; d < candidate_count; d++)
    {
        candidates[d].name = argv[d + 1];
        candidates[d].votes = 0;
        candidates[d].eliminated = 0;
    }

    int voter_count;
	printf("Number of voters: ");
	scanf("%i", voter_count);
	
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    int l;
    for (l = 0; l < voter_count; l++)
    {

        // Query for each rank
        int j;
        for (j = 0; j < candidate_count; j++)
        {
            char name[50];
			printf("Rank %i: ", j + 1);
			scanf("%s", name);

            // Record vote, unless it's invalid
            if (!vote(l, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (1)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        int won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        int tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
        	int i;
            for (i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        int i;
        for (i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
int vote(int voter, int rank, char* name)
{
    // TODO
    int k;
    for(k = 0; k < candidate_count; k++) {
        if(strcmp(candidates[k].name, name) == 0) {
            preferences[voter][rank] = k; // k = candidate index
            return 1;
        }
    }
    return 0;
}
// The first call here is to a function called tabulate, which should look at all of the voters’ preferences and compute the current vote totals,
// by looking at each voter’s top choice candidate who hasn’t yet been eliminated.
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    int i;
    for(i = 0; i < voter_count; i++) {
    	int k;
        for(k = 0; k < candidate_count; k++) {
            if(candidates[preferences[i][k]].eliminated == 0) {
                candidates[preferences[i][k]].votes++; //
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    // TODO
    int max_votes = 0;
    char* winner;
    int i;
    for(i = 0; i < candidate_count; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = candidates[i].name;
        }
    }
    if(max_votes > voter_count * .5) {
        printf("%s\n", winner);
        return 1;
    }
    return 0;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min_votes;
    int i;
    for(i = 0; i < candidate_count; i++) {
        if(candidates[i].votes < min_votes && candidates[i].eliminated == 0) {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    // TODO
    int count = 0;
    int contenders = 0;
    int i;
    for(i = 0; i < candidate_count;i++) {
        if(candidates[i].votes == min && candidates[i].eliminated == 0) {
            count++;
        }
        if(candidates[i].eliminated == 0) {
            contenders++;
        }
    }
    if(count == contenders) {
        return 1;
    }
    return 0;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    int i;
    for(i = 0; i < candidate_count; i++) {
        if(candidates[i].votes == min) {
            candidates[i].eliminated = 1;
        }
    }
    return;
}

