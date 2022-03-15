/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:06:25 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:27:25 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_width(int i, char c)
{
	if (t_flags.is_dot && t_flags.precision == 0)
		c = ' ';
	while (i > 0)
	{
		write (1, &c, 1);
		i--;
	}
}

void	print_signal(void)
{
	if (t_flags.is_signal)
		write (1, "+", 1);
	if (t_flags.is_space)
		write (1, " ", 1);
}

int	ft_printf_strlen(const char *ptr)
{
	int	c;

	if (!ptr)
		return (6);
	c = 0;
	while (*ptr != '\0')
	{
		c++;
		ptr++;
	}
	return (c);
}

void	print_uns(unsigned int u)
{
	int	size;

	if (t_flags.is_dot && t_flags.precision == 0 && u == 0)
		return ;
	size = ft_nbrlen((long long )u, 10);
	if (size < t_flags.precision)
	{
		print_width((t_flags.precision - size), '0');
	}
	ft_putuns_fd(u, 1);
}
