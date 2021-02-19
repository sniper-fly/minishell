#include "parse.h"
#include "libft.h"

/*
** dstの末尾にchを一文字追加する
*/
char		*auto_resize_join(char *dst, int *buflen, char ch)
{
	int		dst_len;

	dst_len = ft_strlen(dst);
	dst = auto_resize_cpy(dst, dst_len, buflen, ch); //TODO:
	return (dst);
}
