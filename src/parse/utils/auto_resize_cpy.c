#include "parse.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

# ifdef DEBUG //後で消す
# define RESIZE_BUF_LEN 10
# endif

/*
** dst = auto_resize_cpy(dst, i, buf_size, src[i]);
** このようにして、dstの容量を気にせずにイテレートしてコピーし続けられる。
** 容量が一杯になったら自動でdstをresizeしてくれる
** ただし、イテレートする過程で、dstが参照するアドレスは書き変わる場合があることに注意
** また、dstにはmallocで確保した配列しかいれることができない。
*/

char		*auto_resize_cpy(char *dst, int idx, int *buf_size, char src_ch)
{
	char	*resized_dst;
	int		i;

	if (idx < *buf_size - 2)
	{
		dst[idx] = src_ch;
			return (dst);
	}
	while (idx >= *buf_size - 2)
		*buf_size += RESIZE_BUF_LEN;
	resized_dst = ft_calloc(sizeof(char), *buf_size);
	if (resized_dst == NULL)
	{
		ft_perror(NULL);
		return (NULL); //TODO:これが起きたらセグフォする
	}
	i = 0;
	while (dst[i])
	{
		resized_dst[i] = dst[i];
		i++;
	}
	resized_dst[i] = src_ch;
	free(dst);
	return (resized_dst);
}
