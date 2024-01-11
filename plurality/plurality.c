#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and votes count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool votes(string name);
void print_winner(int q, int b, int p);

int main(int argc, string argv[])
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
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int votesr_count = get_int("Number of voters: ");

    // Loop over all votesrs
    for (int i = 0; i < votesr_count; i++)
    {
        string name = get_string("votes: ");

        // Check for invalid votes
        if (!votes(name))
        {
            printf("Invalid votes.\n");
        }
    }

    // Display winner of election
    print_winner(candidates[0].votes, candidates[1].votes, candidates[2].votes);
}

// Update votes totals given a new votes
bool votes(string name)
{
    // TODO
    if (strcmp(candidates[0].name, name) == 0)
    {
        candidates[0].votes += 1;
        return true;
    }

    else if (strcmp(candidates[1].name, name) == 0)
    {
        candidates[1].votes += 1;
        return true;
    }

    else if (strcmp(candidates[2].name, name) == 0)
    {
        candidates[2].votes += 1;
        return true;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(int q, int b, int p)
{
    // TODO
    if (q >= b && q >= p)
    {
        printf("%s\n", candidates[0].name);
    }

    if (b >= p && b >= q)
    {
        printf("%s\n", candidates[1].name);
    }

    if (p >= q && p >= b)
    {
        printf("%s\n", candidates[2].name);
    }
    return;
}
