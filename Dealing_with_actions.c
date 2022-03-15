/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dealing_with_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:23:00 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:24:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	calculate_actions(int position_a, int position_b, int sizea, int sizeb)
{
	int	nb_actions;

	nb_actions = 0;
	if (position_a >= sizea / 2)
		nb_actions = (sizea - 1) - position_a;
	else if (position_a < sizea / 2)
		nb_actions = position_a + 1;
	if (position_b >= sizeb / 2)
		nb_actions += (sizeb - 1) - position_b;
	else if (position_b < sizeb / 2)
		nb_actions += position_b + 1;
	return (nb_actions);
}
