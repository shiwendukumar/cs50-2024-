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
bool vote(string name);
void print_winner(void);

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

    int voter_count = get_int("Number of voters: ");

    // Loop over all votesrs
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("votes: ");

        // Check for invalid votes
        if (!vote(name))
        {
            printf("Invalid votes.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update votes totals given a new votes
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int highest = 0;

    // calculating the highest count
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        if (candidates[i].votes > candidates[i + 1].votes)
        {
            if (highest < candidates[i].votes)
            {
                highest = candidates[i].votes;
            }
        }

        else
        {
            if (highest < candidates[i + 1].votes)
            {
                highest = candidates[i + 1].votes;
            }
        }
    }

    //   printing the name (or names) of the winner (or winners)
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == highest)
        {
            printf("%s\n", candidates[j].name);
        }
    }
}
