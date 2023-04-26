#include "main.h"

void loop()
{
	char *input;
	char **args;
	int status;

	status = 1;

	do
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s-$ ", cwd);
		input = kpsh_get_input();
		args = kpsh_split_strings(input);
		status = execute_command(args);

		free(input);
		free(args);

	} while (status);
}

