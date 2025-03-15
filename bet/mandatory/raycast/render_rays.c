/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/15 16:40:51 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void set_rays_angle(t_map *map)
{
	int i;
	int px;
	int py;
	int x;
	int y;
	double fr_angle;
	double agl;

	i = 0;
	fr_angle = map->player.rot_angle - FOV/2;
	px = map->player.move_x;
	py = map->player.move_y;
	while (i < RAYS_NUMBER - 1)
	{
		if (i == 0)
			agl = fr_angle;
		else
			agl += ANGLE;
		map->ray[i].ray_angle = agl;
		x = px + (cos(map->ray[i].ray_angle) * 30);
		y = py + (sin(map->ray[i].ray_angle) * 30);
		draw_line(map->img, px, py, x, y, 0xFF0000FF);
		i++;
	}
}
