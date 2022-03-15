/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:20:12 by souchen           #+#    #+#             */
/*   Updated: 2022/03/11 19:48:55 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header/checker.h"
#include<string.h>

void	tester(int sizea, int sizeb, int argc)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer != NULL)
	{
		if (validation_action(buffer) == 0)
		{
			write(2, "Error\n", 7);
			free(buffer);
			exit(1);
		}
		if (ft_strncmp(buffer, "s", 1) == 0)
			do_swap_sa_sb(buffer, sizea, sizeb);
		else if (ft_strncmp(buffer, "r", 1) == 0)
			do_rotate_ra_rb(buffer, sizea, sizeb);
		else
		{
			sizea = do_push_pa_pb(buffer, sizea, sizeb);
			sizeb = (argc - 1) - sizea;
		}
		free(buffer);
		buffer = get_next_line(0);
	}
	free (buffer);
}

int	main(int argc, char *argv[])
{
	int		sizea;
	int		sizeb;

	s_check.stack_a = ft_calloc(argc, sizeof(int));
	s_check.stack_b = ft_calloc(argc, sizeof(int));
	sizea = make_stack(argv, s_check.stack_a, argc);
	if (sizea < 0)
	{
		free (s_check.stack_a);
		free (s_check.stack_b);
		write(2, "Error\n", 7);
		return (-1);
	}
	sizeb = (argc - 1) - sizea;
	tester(sizea, sizeb, argc);
	if (is_sorted(s_check.stack_a, sizea) && argc > 1)
		write(1, "OK\n", 4);
	else if (!is_sorted(s_check.stack_a, sizea) && argc > 1)
		write(1, "KO\n", 4);
	free (s_check.stack_a);
	free (s_check.stack_b);
	return (0);
}
