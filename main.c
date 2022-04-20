/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:24:30 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/22 16:55:59 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(t_program *prog)
{
	write(1, "YOU WIN\n", 8);
	ft_close(prog);
}

void	game_over(t_program *prog)
{
	write(1, "GAME OVER\n", 10);
	ft_close(prog);
}

int	ft_close(t_program *prog)
{
	if (prog != NULL)
	{
		if (prog->t.x != NULL)
			free(prog->t.x);
		if (prog->t.y != NULL)
			free(prog->t.y);
		if (prog->glob.map != NULL)
			free(prog->glob.map);
		if (prog->glob.str != NULL)
			free(prog->glob.map);
	}
	exit(0);
	return (0);
}

int	render(t_program *prog)
{
	mlx_clear_window (prog->mlx, prog->win);
	put_image(prog);
	ft_put_moves(prog);
	if (prog->frame >= 15)
	{
		enemy_moves(prog);
		prog->frame = 0;
	}
	prog->frame += 1;
	return (0);
}

int	main(int ac, char **av)
{
	t_program	prog;

	if (ac != 2)
		put_error_msg(-3, NULL);
	map_checker(&prog, av[1]);
	if (close(prog.glob.fd) != 0)
		put_error_msg(-5, &prog);
	prog.p.count_collect = prog.glob.c;
	prog.p.count_moves = 0;
	prog.mlx = mlx_init();
	prog.win = mlx_new_window(prog.mlx, prog.glob.map_d.column * 52, \
		prog.glob.map_d.line * 52, "Runaway");
	define_images(&prog);
	mlx_loop_hook(prog.mlx, render, &prog);
	mlx_hook(prog.win, 17, 1L << 5, ft_close, &prog);
	mlx_key_hook(prog.win, player_moves, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
