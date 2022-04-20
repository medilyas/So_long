/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:41 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:23:42 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_moves(t_program *prog)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(prog->p.count_moves);
	str = ft_strjoin("moves : ", moves);
	if (moves == NULL || str == NULL)
		put_error_msg(-1, prog);
	mlx_string_put(prog->mlx, prog->win, 0, 0, 0xFFFFFF, str);
	free(moves);
	free(str);
}
