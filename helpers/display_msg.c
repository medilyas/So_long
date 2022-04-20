/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:22:25 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:22:28 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *s)
{
	unsigned int	len;

	if (s != 0)
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
	}
}

void	put_error_msg(int m, t_program *prog)
{
	ft_putstr("Error\n");
	if (m == -1)
		ft_putstr("malloc error @_@!!\n");
	else if (m == 0)
		ft_putstr("The map must be rectangular!\n");
	else if (m == 1)
		ft_putstr("The map must be surrounded by 1 (walls)!\n");
	else if (m == 2)
		ft_putstr("Make sure there is 1'P and at least 1'E and 1'C.\n");
	else if (m == 3)
		ft_putstr("Sorry our Map only accepts 0, 1, C, E, P.\n");
	else if (m == 4)
		ft_putstr("Heeey!!! there is new line in the end of the map!\n");
	else if (m == 5)
		ft_putstr("No more than one player o_0*!!!\n");
	else if (m == -2)
		ft_putstr("Bad map description file (it should be .ber)!\n");
	else if (m == -3)
		ft_putstr("Can you explain to me where I'll find your map?\n");
	else if (m == -5)
		ft_putstr("The file descriptor doesn't close!\n");
	ft_close(prog);
}
