//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 2, 2020.
//Problem Set 3 --> runoff.c --> cs50 --> Harvard X
//I only implemnet functions' body as exercise.

#include <cs50.h>
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
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
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
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
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
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
  //checks if vote is valid
  bool is_valid;
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(name, candidates[i].name) == 0)
    {
      preferences[voter][rank] = i;
      is_valid = true; 
      break;
    }
    else
    {
      is_valid = false;
    }
  }
  return is_valid;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
      if (candidates[i].eliminated == false)
      {
        candidates[preferences[i][0]].votes++;
      }
      if (candidates[i].eliminated == true)
      {
        for (int j = 1; j < candidate_count; j++)
        {
          if (candidates[preferences[i][j]].eliminated == false)
          {
            candidates[preferences[i][j]].votes++;
          }
        } 
      }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // sorting candidates[]
    bool have_we_winner;
    int swap;
    while (swap > 0)
    {
      int i;
      swap = 0;
      for (i = 0; i < candidate_count; i++)
      {
        if (candidates[i + 1].votes > candidates[i].votes)
        {
          candidate aux = candidates[i];
          candidates[i] = candidates[i + 1];
          candidates[i + 1] = aux;
          swap++;
        }
      }
    }
    // print winner
    if (candidates[0].votes > voter_count / 2)
    {
      printf("%s\n", candidates[0].name);
      have_we_winner = true;
    }
    else
    {
      have_we_winner = false;
    }
    return have_we_winner;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // take the last candidate from candidates[]
    int c = candidate_count - 1;
    while (candidates[c].eliminated == true && c >= 0)
    {
      c--;
    }
    return candidates[c].votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // checks if was tied
    bool was_tied;
    int c = candidate_count - 2;
    while (candidates[c].votes == min && c >= 0)
    {
      c--;
    }
    if (c == 0)
    {
      was_tied = true;
      printf("true");
    }
    else
    {
      was_tied = false;
    }
    return was_tied;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // take candidate(s) in last place
    int c = candidate_count - 1;
    while (candidates[c].votes == min && c >=0)
    {
      candidates[c].eliminated = true;
      c--;
    }
}
