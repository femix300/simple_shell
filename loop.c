#include "main.h"

void loop()
{
	char *input;
	char **args;
	int status;

	do
	{
		getcwd(cwd, sizeof(cwd));
		my_printf("%s-$ ", cwd);
		fflush(stdout);
		input = kpsh_get_input();
		args = kpsh_split_strings(input);
		status = execute_command(args);

		free(input);
		free(args);

	} while (status);
}

