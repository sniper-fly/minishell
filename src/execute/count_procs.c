#include "constants.h"
#include "struct/process.h"

int	count_procs(t_process *procs)
{
	int count;

	count = 0;
	while(procs[count].is_end != TRUE)
		++count;
	return count;
}

