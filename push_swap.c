/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:54 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 21:25:24 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/push_swap.h"

int	main(int argc, char *argv[])
{
	int	sizea;
	int	sizeb;

	t_stacks.stack_a = ft_calloc(argc, sizeof(int));
	t_stacks.stack_b = ft_calloc(argc, sizeof(int));
	if (!t_stacks.stack_a || !t_stacks.stack_b)
		return (-1);
	if (argc > 1024 || argc == 1)
		return (1);
	sizea = make_stack(argv, t_stacks.stack_a, argc);
	if (sizea == -1)
		return (1);
	if (is_sorted(t_stacks.stack_a, sizea))
		return (0);
	sizeb = (argc - 1) - sizea;
	if (sizea == 2 || sizea == 3)
		sort_2_3(t_stacks.stack_a, sizea);
	else if (sizea == 4 || sizea == 5)
		sort_5(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
	if (sizea > 5)
		sort_6_to_ends(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
	free(t_stacks.stack_a);
	free(t_stacks.stack_b);
}
