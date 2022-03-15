/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:11 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:26:40 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	divide(unsigned long long nbr, int base)
{
	int	size;

	size = 1;
	while (nbr >= (unsigned long long)base)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

int	ft_nbrlen(long long nbr, int base)
{
	int					size;
	unsigned long long	n;

	if (base == 10 && nbr < 0)
		n = nbr * -1;
	else
		n = nbr;
	size = divide(n, base);
	return (size);
}
