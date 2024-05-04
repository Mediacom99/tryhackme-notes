/*
 *  @Author Edoardo Bertoli
 *
 *  Print to stdout the lenghts of each word and the number of words with that length
 *  in the input given to stdin.
 *  Words are made of 0-9 a-z A-Z in ASCII table.
 *
 */


#include <stdio.h>

#define MAX_WORD_LEN 256 
#define IN 1
#define OUT 0
#define HIST 2
#define NO_HIST 3

void print_hist(int* arr, int len, int flag)
{
    int temp;
    for(int i = 0; i < len; ++i)
    {
        temp = arr[i];
        if(temp != 0)
        {
            printf("%d ", i);
            printf("\t\t%d\n", temp);
        }
    }
    return;
}

/*
void print_arr(int* arr, int len)
{
    int temp;
    printf("[");
    for(int i = 0; i < len; ++i)
    {
        printf("%d,",arr[i]);
    }
    printf("]\n\n");

    return;
}
*/

void fill_zeroes(int* arr, int len)
{ 
    for(int i = 0; i < len; ++i)
    {
        arr[i] = 0;
    }
    return;
}

int not_valid(int c)
{
    // If you are outside chars used in words return true, otherwise return false
    if(c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
    {
        return 1;
    }else{
        return 0;
    }
}


int main(void)
{
    
    int hist[MAX_WORD_LEN]; 
    int wl = 0; // word length counter
    int state = OUT; //check if inside a word or not
    int c; //current char holder

    fill_zeroes(hist, MAX_WORD_LEN);
    while((c = getchar())!= EOF)
    {
        if(not_valid(c))
        {
            state = OUT;
            if(wl > 0 && wl < MAX_WORD_LEN) hist[wl]+=1;
            wl = 0;
        }
        else
        {
            state = IN;
            ++wl;
        }
    }

   // print_arr(hist, MAX_WORD_LEN);
    printf("Word length:\tHow many:\n");
    print_hist(hist, MAX_WORD_LEN,NO_HIST);
    return 0;
}
