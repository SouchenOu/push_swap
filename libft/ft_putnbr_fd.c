/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:08:19 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:07:38 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<unistd.h>

unsigned int	test(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = n * -1;
	}
	else
		nb = n;
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			str[11];
	char			*ptr;
	int				c;
	unsigned int	nb;

	c = 0;
	ptr = &str[0];
	nb = test(n, fd);
	while (nb > 9)
	{
		*(ptr + c) = (nb % 10) + 48;
		nb = nb / 10;
		c++;
	}
	*(ptr + c) = nb + 48;
	while (c >= 0)
	{
		write(fd, &*(ptr + c), 1);
		c--;
	}
}
