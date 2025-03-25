/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:39:36 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/24 12:28:38 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_floor_ceil(t_map *map)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < map->height)
	{
		j = 0;
		if (i < (map->height / 2))
			color = 0xFFB347;
		else
			color = 0xFFFFFFFF;
		while (j < map->width)
			mlx_put_pixel(map->img, j++, i, color);
		i++;
	}
}

void	set_rays_angle(t_map *map)
{
	int		i;
	double	fr_angle;
	double	agl;
	double	distance1;

	i = 0;
	map->rays_number = map->width;
	fr_angle = map->player.rot_angle - (FOV / 2);
	draw_floor_ceil(map);
	while (i < map->rays_number)
	{
		if (i == 0)
			agl = fr_angle;
		else
			agl += ANGLE;
		map->ray[i].ray_angle = agl;
		ray_look_direction(&map->ray[i].ray_angle, &map->ray[i]);
		map->ray[i].distance = horizontal_distance(map, map->ray[i]);
		distance1 = vertical_distance(map, map->ray[i]);
		if (map->ray[i].distance > distance1)
			map->ray[i].distance = distance1;
		render_wall(map, map->ray[i], i);
		i++;
	}
}
