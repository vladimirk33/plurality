#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Invalid usage.\n");
        return 1;
    }

    else if (argc > 10)
    {
        printf("Invalid usage. (MAX)\n");
        return 1;
    }

    candidate_count = argc - 1;

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voters_number = get_int("Number of voters: ");

    for (int i = 0; i < voters_number; i++)
    {
        string name = get_string("Vote: ");
        vote(name);
    }

    print_winner();
}



bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    printf("Invalid vote.\n");
    return false;
}

void print_winner(void)
{
    int max = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}