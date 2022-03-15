/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:11:13 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:28:42 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putuns_fd(unsigned int n, int fd)
{
	char			str[11];
	char			*ptr;
	int				c;

	c = 0;
	ptr = &str[0];
	while (n > 9)
	{
		*(ptr + c) = (n % 10) + 48;
		n = n / 10;
		c++;
	}
	*(ptr + c) = n + 48;
	while (c >= 0)
	{
		write(fd, &*(ptr + c), 1);
		c--;
	}
}
