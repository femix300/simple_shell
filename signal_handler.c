#include "main.h"

/**
* signal_handler - Handles the signal interrupt.
* @n: The signal number.
*/
void signal_handler(int n)
{
	(void)(n);

	write(STDERR_FILENO, "\n$ ", 3);
}
