/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:03 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:25:18 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	make_stack(char *argv[], int stack[], int argc)
{
	int	a;
	int	b;

	a = 0;
	b = argc - 1;
	while (a < b)
	{
		if (ft_atoi(argv[(b - a)]) >= 2147483648)
		{
			write(1, "Error1\n", 7);
			return (-1);
		}
		stack[a] = ft_atoi(argv[(b - a)]);
		if (!is_duplicated(stack, (a - 1), stack[a])
			|| !is_number(argv[(b - a)]))
		{
			write(2, "Error2\n", 7);
			return (-1);
		}
		a++;
	}
	return (a);
}
