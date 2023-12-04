#include<stdio.h>
#include<string.h>
#include<stdbool.h>

static const unsigned r_max = 12;
static const unsigned g_max = 13;
static const unsigned b_max = 14;

static const unsigned r_len = 3;
static const unsigned g_len = 5;
static const unsigned b_len = 4;

int main()
{
    FILE *file;
    // Open a file in read mode
    file = fopen("input.txt", "r");
    char line[200];
    unsigned long sum = 0;
    while(fgets(line, 200, file)) {
        // printf("%s", line);
        unsigned len = (unsigned)strlen(line);
        // printf("Length of line: %u\n", len);
        char number[3];
        // char color;
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
                number[0] = 0;
                number[1] = 0;
                number[2] = 0;
                break;
            case ' ':
                if(n_ind != 0)
                {
                    number[n_ind] = 0;
                    // printf("Number thats being checked: %s\n", number);
                    space = true;
                }
                break;
            // case ';':
            //     break;
            default:
                for(char d = '0'; d <= '9' ; d++)
                {
                    if(line[i] == d)
                    {
                        // printf("nr found: %c\n", d);
                        number[n_ind] = line[i];
                        n_ind++;
                        break;
                    }
                }
                
                if(space)
                {
                    // printf("Color: %c\n", color);
                    switch (line[i])
                    {
                    case 'r':
                        sscanf(number, "%u", &nr);
                        if(nr > r_max)
                        {
                            printf("Busted red, nr: %d\n", nr);
                            br = true;
                        }
                        i+=r_len;
                        space=false;
                        n_ind = 0;
                        number[0] = 0;
                        number[1] = 0;
                        number[2] = 0;
                        break;
                    case 'g':
                        sscanf(number, "%u", &nr);
                        // printf("Found green, nr: %d\n", nr);
                        if(nr > g_max)
                        {
                            printf("Busted green, nr: %d\n", nr);
                            br = true;
                        }
                        i+=g_len;
                        space=false;
                        n_ind = 0;
                        number[0] = 0;
                        number[1] = 0;
                        number[2] = 0;
                        break;
                    case 'b':
                        sscanf(number, "%u", &nr);
                        // printf("Found blue, nr: %d\n", nr);
                        if(nr > b_max)
                        {
                            printf("Busted blue, nr: %d\n", nr);
                            br = true;
                        }
                        i+=b_len;
                        space=false;
                        n_ind = 0;
                        number[0] = 0;
                        number[1] = 0;
                        number[2] = 0;
                        break;
                    default:
                        break;
                    }
                }
            
            }
        }
        if(!br)
        {
            printf("Valid game number: %u\n", gamenr);
            sum += gamenr;
            // printf("Sum change: %u\n", sum);
        }
        // else
        // {
        //     printf("Invalid game number: %u\n", gamenr);
        // }
    }
    printf("Sum of numbers of valid games is: %u\n", sum);
    return 0;
}