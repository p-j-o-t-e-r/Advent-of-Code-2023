#include<stdio.h>
#include<string.h>
#include<stdbool.h>

static const unsigned r_max = 12;
static const unsigned g_max = 13;
static const unsigned b_max = 14;

static const unsigned r_len = 3;
static const unsigned g_len = 5;
static const unsigned b_len = 4;

// function clearing the number;
void clear(char *number)
{
    number[0]=0;
    number[1]=0;
    number[2]=0;
}

int main()
{
    FILE *file;
    // Open a file in read mode
    file = fopen("input.txt", "r");
    char line[200];
    unsigned long sum = 0;
    while(fgets(line, 200, file)) {
        unsigned len = (unsigned)strlen(line);
        char number[3];
        unsigned n_ind = 0;
        bool space = false, br = false;
        unsigned nr;
        unsigned gamenr;
        for(unsigned i = 0; i < len; i++)
        {
            if(br)
            {
                break;
            }
            switch (line[i])
            {
            case ':':
                number[n_ind]=0;
                sscanf(number, "%u", &gamenr);
                n_ind = 0;
                clear(number);
                break;
            case ' ':
                if(n_ind != 0)
                {
                    number[n_ind] = 0;
                    space = true;
                }
                break;
            default:
                for(char d = '0'; d <= '9' ; d++)
                {
                    if(line[i] == d)
                    {
                        number[n_ind] = line[i];
                        n_ind++;
                        break;
                    }
                }
                
                if(space)
                {
                    switch (line[i])
                    {
                    case 'r':
                        sscanf(number, "%u", &nr);
                        if(nr > r_max)
                        {
                            br = true;
                        }
                        i+=r_len;
                        space=false;
                        n_ind = 0;
                        clear(number);
                        break;
                    case 'g':
                        sscanf(number, "%u", &nr);
                        if(nr > g_max)
                        {
                            br = true;
                        }
                        i+=g_len;
                        space=false;
                        n_ind = 0;
                        clear(number);
                        break;
                    case 'b':
                        sscanf(number, "%u", &nr);
                        if(nr > b_max)
                        {
                            br = true;
                        }
                        i+=b_len;
                        space=false;
                        n_ind = 0;
                        clear(number);
                        break;
                    default:
                        break;
                    }
                }
            
            }
        }
        if(!br)
        {
            sum += gamenr;
        }
    }
    printf("Sum of numbers of valid games is: %u\n", sum);
    return 0;
}