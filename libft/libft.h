/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:13:45 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 20:48:22 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include<stdlib.h>
# include"ft_printf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *ptr);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putuns_fd(unsigned int n, int fd);
void	ft_putnbrx(unsigned int n, char x);
void	ft_put0x(unsigned long n, char x);
int		ft_nbrlen(long long nbr, int base);
void	ft_putnstr(char *s, int n);
void	ft_bzero(void *ptr, size_t n);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
int		ft_printf(const char *str, ...);

#endif
