/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/16 15:40:35 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_wall(t_map map, int x, int y)
{
	int grid_x;
	int grid_y;

	grid_x = x * TILESIZE;
	grid_y = y * TILESIZE;

	if (grid_x < 0 || grid_x >= ft_strlen(map.cmap[0]) || grid_y < 0 || grid_y >= map.row)
		return (1);
	if (map.cmap[grid_y][grid_x] == '1')
	{
		// printf("walldetected at grid (%d, %d) ::::pos (%d, %d)\n", grid_x, grid_y, x, y);
    	return (1);
	}
	return (0);
}


int main(int ac, char **av)
{
	t_map	map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int	width;
	int height;
	int x =0 ;
	int y = 0;

	if (ac == 2)
	{
		if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
			return (write(1, "**Invalid Map Name**\n", 21), 1);
		map = parse(av[1]);
	}
	else
	{
		write(1, "**PARAMETERS ERROR**\n", 21);
		return(1);
	}
	width = ((ft_strlen(map.cmap[0]) - 1) * TILESIZE);
	height = (map.row * TILESIZE);
	map.width =width;
	map.height = height;
	mlx = mlx_init(width, height, "9yob3d", 1);
	if (!mlx)
        return (printf("mlx\n"), 1);
	img = mlx_new_image(mlx, width, height);
	if (!img)
        return (printf("img\n"), 1);
	map.mlx = mlx;
	map.img = img;
	draw_map(&map);

	// hadu initializations...
	//------------------------------
	map.player.move_x = map.player.x*TILESIZE + TILESIZE/2;
	map.player.move_y = map.player.y*TILESIZE + TILESIZE/2;
	if (map.player.direction == 'N')
		map.player.rot_angle = 3 * M_PI_2;
	else if (map.player.direction == 'S')
		map.player.rot_angle = M_PI_2;
	else if (map.player.direction == 'E')
		map.player.rot_angle = 0;
	else
		map.player.rot_angle = M_PI;
	draw_player(&map, img, 0);
	// hadi bax n drawi bzzf dyal reays
	set_rays_angle(&map);
	//-------------------------------
	mlx_key_hook(mlx, update_player_p, &map);
	mlx_loop(mlx);
	return (0);
}
