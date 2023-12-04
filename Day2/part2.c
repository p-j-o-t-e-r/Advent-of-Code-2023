#include<stdio.h>
#include<string.h>
#include<stdbool.h>

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
        bool space = false;
        unsigned nr;
        unsigned r_max = 0;
        unsigned g_max = 0;
        unsigned b_max = 0;
        for(unsigned i = 0; i < len; i++)
        {
            switch (line[i])
            {
            case ':':
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
                            r_max = nr;
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
                            g_max = nr;
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
                            b_max = nr;
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
        sum += r_max*b_max*g_max;
    }
    printf("Sum: %u\n", sum);
    return 0;
}