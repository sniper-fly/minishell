/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:22:48 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 12:43:39 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*exception_handler(void)
{
	char	*return_value;

	if (!(return_value = (char *)ft_calloc(12, sizeof(char))))
		return (NULL);
	return_value[0] = '-';
	return_value[1] = '2';
	return_value[2] = '1';
	return_value[3] = '4';
	return_value[4] = '7';
	return_value[5] = '4';
	return_value[6] = '8';
	return_value[7] = '3';
	return_value[8] = '6';
	return_value[9] = '4';
	return_value[10] = '8';
	return_value[11] = '\0';
	return (return_value);
}

/*
** In second parameter, enter (the number of digit - 1), that is digit idx.
*/

static void	fill_num_ch(char *ptr, int current_digit_idx,
						int num, int minus_flag)
{
	if (minus_flag == 1)
	{
		ptr[0] = '-';
		minus_flag = 0;
	}
	if (num < 10)
		ptr[current_digit_idx] = num + '0';
	else
	{
		fill_num_ch(ptr, current_digit_idx - 1, num / 10, minus_flag);
		ptr[current_digit_idx] = (num % 10) + '0';
	}
}

char		*ft_itoa(int num)
{
	int		tmp;
	int		digit;
	char	*ch_array;
	int		minus_flag;

	if (num == INT_MIN)
		return (exception_handler());
	minus_flag = 0;
	if (num < 0)
	{
		num *= -1;
		minus_flag = 1;
	}
	tmp = num;
	digit = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digit++;
	}
	if (!(ch_array = (char *)ft_calloc(digit + minus_flag + 1, sizeof(char))))
		return (NULL);
	fill_num_ch(ch_array, digit + minus_flag - 1, num, minus_flag);
	return (ch_array);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	printf("%s", ft_itoa(INT_MAX));
** 	printf("\n");
** 	printf("%d", INT_MAX);
** 	printf("\n");
** 	printf("%s", ft_itoa(INT_MIN + 1));
** 	printf("\n");
** 	printf("%d", INT_MIN + 1);
** 	printf("\n");
** 	printf("%s", ft_itoa(INT_MIN + 0));
** 	printf("\n");
** 	printf("%d", INT_MIN + 0);
** 	printf("\n");
** 	printf("%s", ft_itoa(0));
** 	printf("\n");
** 	printf("%s", ft_itoa(-0));
** 	printf("\n");
** 	printf("%s", ft_itoa(-9));
** 	return (0);
** }
*/
