#include "main.h"
/**
* my_loop - a function that loops through other shell functions
*
* Description: How to loop
* Return: nothing
*/

void my_loop(void)
{
	char *inp;
	char **args;
	int interger = 1, leng;
	int stat;
	
	if (isatty(STDIN_FILENO) != 1)
	interger = 0;
	
	signal(SIGINT, sit_hndl);

	do {
		if (interger != 0)
		{
		length = my_strileng("$ ");
		write(STDOUT_FILENO, "$ ", leng);
                }
		
                inp = my_read_line();
                if (inp == NULL)
                        return;
			
                args = _split_line(input);
                if (args == NULL)
                {
                        free(inp);
                        return;
                }
		
                status = _execute(args, input);

                /* Free input and arguments. */
                free(input);
                free(args);

        } while (stat == 1);
}

