/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:24:00 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:24:11 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	def_image1(t_program *prog, int loop)
{
	if (loop <= 13)
	prog->glob.collect = prog->img.collect[0];
	else if (loop <= 26)
	prog->glob.collect = prog->img.collect[1];
	else if (loop <= 39)
	prog->glob.collect = prog->img.collect[2];
	else if (loop <= 51)
	prog->glob.collect = prog->img.collect[3];
	else if (loop <= 63)
	prog->glob.collect = prog->img.collect[4];
	else if (loop <= 76)
	prog->glob.collect = prog->img.collect[5];
	else if (loop <= 88)
	prog->glob.collect = prog->img.collect[6];
	else if (loop > 88)
	prog->glob.collect = prog->img.collect[7];
}

static void	def_image2(t_program *prog, int loop)
{
	prog->glob.empty = prog->img.empty;
	prog->glob.wall = prog->img.wall;
	if (loop >= 95)
		prog->glob.player = prog->img.player[1];
	else if (loop < 95)
		prog->glob.player = prog->img.player[0];
	if (loop >= 50)
		prog->glob.trap = prog->img.trap[0];
	else if (loop < 50)
		prog->glob.trap = prog->img.trap[1];
	if (prog->p.count_collect != 0)
		prog->glob.exit = prog->img.exit[0];
	else
		prog->glob.exit = prog->img.exit[1];
}

static void	put_to_window(t_program *prog, int x, int y)
{
	int	w;
	int	h;

	w = y * 52;
	h = x * 52;
	mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.empty, w, h);
	if (prog->glob.map[x][y] == '1')
		mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.wall, w, h);
	if (prog->glob.map[x][y] == 'P')
		mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.player, w, h);
	if (prog->glob.map[x][y] == 'C')
		mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.collect, w, h);
	if (prog->glob.map[x][y] == 'T')
		mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.trap, w, h);
	if (prog->glob.map[x][y] == 'E')
		mlx_put_image_to_window(prog->mlx, prog->win, prog->glob.exit, w, h);
}

void	put_image(t_program *prog)
{
	static int	loop;
	int			x;
	int			y;

	if (loop >= 100)
		loop = 0;
	def_image1(prog, loop);
	def_image2(prog, loop);
	loop++;
	x = -1;
	while (++x < prog->glob.map_d.line)
	{
		y = -1;
		while (++y < prog->glob.map_d.column)
			put_to_window(prog, x, y);
	}
}
