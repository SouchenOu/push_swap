/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:45:18 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:04:17 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/checker.h"

int	is_number(const char *nbr)
{
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!ft_isdigit(*nbr))
			return (0);
		nbr++;
	}
	return (1);
}

int	is_duplicated(int stack[], int position, int x)
{
	while (position >= 0)
	{
		if (stack[position] == x)
			return (0);
		position--;
	}
	return (1);
}

int	is_sorted(int a[], int sizea)
{
	sizea--;
	while ((sizea - 1) >= 0)
	{
		if (a[sizea] < a[sizea - 1])
			sizea--;
		else
			return (0);
	}
	return (1);
}

int	make_stack(char *argv[], int stack[], int argc)
{
	int	a;
	int	b;

	a = 0;
	b = argc - 1;
	while (a < b)
	{
		if ((ft_atoi(argv[b - a])) >= 2147483648)
		{
			return (-1);
		}
		stack[a] = ft_atoi(argv[(b - a)]);
		if (!is_duplicated(stack, (a - 1), stack[a])
			|| !is_number(argv[(b - a)]))
			return (-1);
		a++;
	}
	return (a);
}

int	validation_action(char *str)
{
	if ((ft_strncmp(str, "pa", 2) == 0) || (ft_strncmp(str, "pb", 2) == 0)
		|| (ft_strncmp(str, "sa", 2) == 0) || (ft_strncmp(str, "sb", 2) == 0)
		|| (ft_strncmp(str, "ra", 2) == 0) || (ft_strncmp(str, "rb", 2) == 0)
		|| (ft_strncmp(str, "rra", 3) == 0) || (ft_strncmp(str, "rrb", 3) == 0))
		return (1);
	else
		return (0);
}
