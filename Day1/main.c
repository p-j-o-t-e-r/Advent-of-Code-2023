#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char numbers[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

typedef struct {
    unsigned idx;
    char number;
} num_where;


num_where findDigitFromString(char *str, unsigned len, unsigned idx)
{
    num_where ret;
    bool f;
    for(unsigned j = 0; j < 9; j++)
    {
        unsigned n = strlen(numbers[j]);
        f = true;
        for(unsigned k = 0; k < n; k++)
        {
            if(str[idx+k] != numbers[j][k]) 
            {
                f = false;
                break;
            }
        }

        if(f)
        {
            ret.idx = idx;
            j++;
            ret.number = j+'0';
            printf("\nret.number = %c\n", ret.number);
            printf("ret.idx = %u\n", ret.idx);
            return ret;
        }
    }
    
    
}

char findDigitL(char *str, unsigned len)
{
    num_where ret1, ret2;
    ret2.idx = -1;
    ret1.idx = -1;
    for(unsigned i = 0; i < len; i++)
    {
        for(char digit = '1'; digit <= '9'; digit++)
        {
            // printf("sprawdzam %c %c\n", digit, str[i]);
            if(str[i] == digit)
            {
                ret1.idx = i;
                ret1.number = digit;
                // printf("Z lewej cyfra: %c, na %u\n", digit, i);
                break;
            }
        }
    }
    for(unsigned i = 0; i < len; i++)
    {
        ret2 = findDigitFromString(str, len, i);
        if (ret2.idx != -1) break;
    }
    if(ret2.idx != 1)
    {
        if(ret1.idx < ret2.idx) 
        {
            return ret1.number;
        }
        else 
        {
            return ret2.number;
        }
    }
    
}

char findDigitR(char *str, unsigned len)
{
    num_where ret1, ret2;
    ret2.idx = -1;
    ret1.idx = -1;
    bool found = false;
    for(unsigned i = len-2; i >= 0; i--)
    {
        for(char digit = '1'; digit <= '9'; digit++)
        {
            if(str[i] == digit)
            {
                // printf("%c %c\n", str[i], digit);

                ret1.idx = i;
                ret1.number = digit;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    printf("ret1.number = %c\n", ret1.number);
    for(unsigned i = len-2; i >= 0; i--)
    {
        ret2 = findDigitFromString(str, len, i);
        if(ret2.idx != -1) break;
    }
    if(ret2.idx != -1)
    {
        if(ret1.idx > ret2.idx) 
        {
            return ret1.number;
        }
        else 
        {
            return ret2.number;
        }
    }
    else return 0;
}



int main()
{
    FILE *file;
    // Open a file in read mode
    file = fopen("input.txt", "r");
    char line[100];
    unsigned long sum = 0;
    while(fgets(line, 100, file)) {
        unsigned len = (unsigned)strlen(line);
        unsigned number;
        char str_num[3];
        printf("%s", line);
        str_num[0] = findDigitL(line, len);
        printf("Searched in left: %c\n", str_num[0]);
        str_num[1] = findDigitR(line, len);
        printf("Searched in right: %c\n", str_num[1]);
        str_num[2]=0;
        sscanf(str_num, "%u", &number);
        // printf(">>>%u<<<\n", number);
        sum+=number;
    }
    printf("The sum is: %u\n", sum);

    // for(int i =0;i<9;i++) printf("%s", numbers[i]);
    return 0;
}