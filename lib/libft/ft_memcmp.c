/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:39:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/06/30 16:17:54 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			idx;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	idx = 0;
	while (idx < len)
	{
		if (s1[idx] != s2[idx])
		{
			return (s1[idx] - s2[idx]);
		}
		idx++;
	}
	return (0);
}

/*
** #include <stdio.h>
** #include <string.h>
** int		main(void)
** {
** 	char str1[] = "abc\0defgh\0ijk";
**   char str2[] = "abc\0defgh\0ijz";
**   int ret;
**   ret = ft_memcmp(( void * )str1 , ( void * )str2 , 12 );
**   printf( "ret=%d\n" , ret ); // 0
**   ret = ft_memcmp(( void * )str2 , ( void * )str1
**                                  , sizeof( str1 ));
**   printf( "ret=%d\n" , ret ); // 1
**   ret = ft_memcmp(( void * )str1 , ( void * )str2
**                                  , sizeof( str1 ));
**   printf( "ret=%d\n\n" , ret ); // -1
**   char str3[] = "1234";
**   char str4[] = "12345";
**   ret = ft_memcmp(( void * )str3 , ( void * )str4
**                                  , strlen( str3 ));
**   printf( "ret=%d\n" , ret ); // 0
**   ret = ft_memcmp(( void * )str4 , ( void * )str3
**                                  , strlen( str4 ));
**   printf( "ret=%d\n" , ret ); // 1
**   ret = ft_memcmp(( void * )str3 , ( void * )str4
**                                  , strlen( str4 ));
**   printf( "ret=%d\n" , ret ); // -1
** 	return (0);
** }
*/
