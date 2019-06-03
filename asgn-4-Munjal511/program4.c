#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int filter_initial(char *infile, char *outfile, char letter) {
/********************************************************************/
/*    Replace this line with all your code  */                                         
/********************************************************************/

	FILE * fin;
    FILE * fout;
    int flag = 0;
    int count = 0;
    fin = fopen(infile, "r");
	
	if (fin == NULL)
       return 0;

    if (outfile == NULL)
        flag = 1;

    //read line by line
    const size_t line_size = 300;
    char* line = malloc(line_size);
	fout = fopen(outfile, "w");
    while (fgets(line, line_size, fin) != NULL)  {
        if (line[0] == letter ){
            ++count;				
			
            if (flag == 0)
                fputs (line, fout);
            else
                printf("%s\n",line);
        }
    }
    free(line);
    fclose(fin);
	if (fout != NULL)
	{
		fclose(fout);
	}
    return count;	
}

/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE BELOW                 */
/********************************************************************/
int main(){
    printf("\n\t=========Test#1: Filter Initial Letter===========\n\n");
    assert(29 == filter_initial("names.txt", "filtered.txt", 'A'));
    assert(23 == filter_initial("names.txt", "filtered.txt", 'B'));
    assert(30 == filter_initial("names.txt", "filtered.txt", 'C'));
    printf("\n\t=========Test#1 Passed===========\n\n");
    printf("\n\t=========Test#2: Verify Output File===========\n\n");
    assert(30 == filter_initial("filtered.txt", NULL, 'C'));
    printf("\n\t=========Test#2 passed if names are printed above.===========\n\n");
    printf("\n\t=========Please remember to check with Valgrind.===========\n\n");
}