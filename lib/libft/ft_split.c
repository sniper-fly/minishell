/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:01:41 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/05 16:57:08 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *str, char ch)
{
	int		count;
	int		flag;
	int		idx;

	count = 0;
	flag = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != ch)
			flag = 0;
		else if (flag == 1)
		{
			idx++;
			continue;
		}
		else if (str[idx] == ch)
		{
			count++;
			flag = 1;
		}
		idx++;
	}
	return (str[0] ? count + 1 : 0);
}

static int	return_head2tail_or_delim2head(char *str, int idx, char ch)
{
	if (str[idx] != ch)
	{
		while (str[idx] != ch && str[idx] != '\0')
			idx++;
		return (idx - 1);
	}
	else
	{
		while (str[idx] == ch && str[idx] != '\0')
			idx++;
		return (idx);
	}
}

static void	all_free(char **db_ptr, int idx)
{
	int i;

	i = 0;
	while (i < idx)
		free(db_ptr[idx]);
	free(db_ptr);
	db_ptr = NULL;
}

static void	create_word_array(int words, char ch, char *str, char **db_ptr)
{
	int		idx;
	int		head;
	int		tail;

	idx = 0;
	head = 0;
	while (idx < words)
	{
		tail = return_head2tail_or_delim2head(str, head, ch);
		if (!(db_ptr[idx] = ft_substr(str, head, tail - head + 1)))
		{
			all_free(db_ptr, idx);
			return ;
		}
		head = return_head2tail_or_delim2head(str, tail + 1, ch);
		idx++;
	}
	db_ptr[idx] = NULL;
}

char		**ft_split(char const *str, char ch)
{
	char	*trimmed_str;
	int		words;
	char	**ret_db_ptr;
	char	divider[2];

	ft_strlcpy(divider, &ch, 2);
	if (!(trimmed_str = ft_strtrim(str, divider)))
		return (NULL);
	words = count_words(trimmed_str, ch);
	if (!(ret_db_ptr = (char **)malloc(sizeof(char *) * (words + 1))))
	{
		free(trimmed_str);
		return (NULL);
	}
	if (words == 0)
	{
		ret_db_ptr[0] = NULL;
		free(trimmed_str);
		return (ret_db_ptr);
	}
	create_word_array(words, ch, trimmed_str, ret_db_ptr);
	free(trimmed_str);
	return (ret_db_ptr);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	// char str[] = "hello  my name is hoge ";
** 	// char str[] = "hello  my  name i ";
** 	char str[] = "    ";
** 	// char str[] = "   hello  ";
** 	// char str[] = "";
** 	// char str[] = NULL;
** 	// char str[] = "      split       this for   me  !       ";
** 	// char str[] = "\0aaa\0bbb";
** 	char ch = ' ';
** 	// char ch = '\0';
** 	char **result;
** 	result = ft_split(str, ch);
** 	for (int i = 0; result[i] != NULL; i++)
** 	{
** 		ft_putstr_fd(result[i], 1);
** 		printf("\n");
** 	}
** 	return (0);
** }
*/
