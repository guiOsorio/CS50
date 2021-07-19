#include <ctype.h>
// #include <cs50.h>
#include <stdio.h>
#include <string.h>

// this program mimicks a game of scrabble, prompting each player for a word, and determining the winner

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(void)
{
    // Get input words from both players
    char word1[50];
    printf("Player 1: ");
    scanf("%s", word1);
    char word2[50];
    printf("Player 2: ");
    scanf("%s", word2);

    // string word1 = get_string("Player 1: ");
    // string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2) printf("Player 1 wins!!\n");
    if(score1 < score2) printf("Player 2 wins!!\n");
    if(score1 == score2) printf("It is a tie :/\n");
}

int compute_score(char* word)
{
    // TODO: Compute and return score for string
    int total = 0;
    int i;
    for(i = 0; i < strlen(word); i++) {
        if(isupper(word[i]) || islower(word[i])) {
            if(isupper(word[i])) {
                word[i] += 32;
            }
            int index = word[i] - 97;
            total += POINTS[index];
        }
    }
    return total;
}
