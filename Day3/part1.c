#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isNum(char a)
{
    bool ret = false;
    for(char i = '0'; i <= '9'; i++)
    {
        if(a == i)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

// find start and end of a number within string and return number
unsigned findNumber(char *line, int idx)
{
    char num[4];
    unsigned s_ind = idx, n_ind = 0, number;
    
    // finding start of the number
    // printf("Checking %c\n", line[idx]);
    while(isNum(line[idx]) && idx >= 0)
    {
        idx--;
    }
    if(s_ind != idx)
    {
        idx++;
        while(isNum(line[idx]))
        {
            num[n_ind] = line[idx];
            idx++;
            n_ind++;
        }
        num[n_ind]=0;
        sscanf(num, "%u", &number);
        // printf("NUMBER: %d\n", number);
        return number;
    }
    else
        return 0;
}



unsigned mod(int liczba, unsigned m)
{
    if(liczba >= 0)
        return liczba % m;
    else
        return m + liczba;
}

int main()
{
    FILE *file;
    // Open a file in read mode
    file = fopen("input.txt", "r");
    char line[3][150];
    unsigned long sum = 0;
    fgets(line[0], 150, file);
    fgets(line[1], 150, file);
    int index = 2;
    unsigned n;
    // if (isNum('a'))
    //     printf("Liczba\n");
    while(fgets(line[index], 150, file))
    {
        // printf("Index: %d\n", index);
        n = strlen(line[index]);
        unsigned id = mod(index-1, 3);
        // printf("Id: %d\n", id);
        for(unsigned j = 0; j < n; j++)
        {
            // putchar(line[id][j]);
            if(line[id][j] != '.' && (!isNum(line[id][j])) && line[id][j] != '\n')
            {
                // printf("\nFound character: %c\n", line[id][j]);
                unsigned number;
                for(int k = -1; k <= 1; k++)
                {
                    unsigned old_num;
                    for(int l = -1; l <= 1; l++)
                    {
                        // printf("j=%u, k=%d, l=%d\n", j, k, l);
                        // printf("%s\n", line[mod(id+k,3)]);
                        number = findNumber(line[mod(id+k,3)], (int)j+l);
                        if(number && number != old_num)
                        {
                            // printf("Number found: %u\n", number);
                            old_num = number;
                            sum+= number;
                            // break;
                        }
                    }
                }
            }       
        }
        index = (index+1) % 3;
    }
    printf("Sum of numbers with adjacent symbol is: %lu\n", sum);
    return 0;
}