/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:36:34 by rnakai            #+#    #+#             */
/*   Updated: 2021/01/30 09:05:34 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			ft_bzero(void *s, size_t n);
char			*ft_strchr(const char *str, int ch);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar_fd(char ch, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int num, int fd);
char			**ft_split(char const *s, char c);

void			ft_perror(char *str);

#endif
