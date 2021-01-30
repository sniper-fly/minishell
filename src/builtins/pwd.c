#include <unistd.h>
#include "libft.h"
#include "constants.h"

void pwd(void)
{
	size_t size;
	char *current_working_dir;

	size = 0;
	while(1){
		size += 256;
		current_working_dir = malloc(sizeof(char)*size);	// TODO:mallocエラー処理
		if(getcwd(current_working_dir, size))	// when successed getcwd
			break;
		free(current_working_dir);
	}
	ft_putendl_fd(current_working_dir, STD_OUT);
	exit(0);
}