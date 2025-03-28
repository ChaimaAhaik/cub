/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:17:04 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/25 10:26:02 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../MLX/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "../getnextline/get_next_line.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TILESIZE 32
#define OUT_OF_RANGE " numbers not whithin range required"
#define COMMAS_NUMBER " commas number or less/more than numbers required"
#define INVALID_TEXTURES " invalid textures"
#define NEWLINE_MAP " newline inside map lines"
#define PARSE_LINE " (parse_line)"
#define POSITION_OF_ZERO " invalid position(direction or 0)"
#define PLAYER_POSITION " invalid palyer's position"
#define PLAYER_NUMBER " More/Less than one player"
#define	WIDTH 1024
#define HEIGHT 1024
#define FOV (60 * (M_PI / 180))
#define RES 5
#define RAYS_NUMBER (1024)
#define ANGLE (FOV / (RAYS_NUMBER - 1))


typedef struct s_identifier
{
	char *identifier;
	int *colors;
	char *path;
	struct s_identifier *next;
} t_identifier;


typedef struct s_player
{
	int x;
	int y;
	int move_x;
	int move_y;
	char direction;
	int	move_speed;
	int	turn_direc;
	int	walk_direc;
	int	steeps;
	bool first_time;
	double	rot_angle;
	int	strafe_direc;

} t_player;

typedef struct s_ray
{
	double ray_angle;
	int ray_x;
	int ray_y;
	int down;
	int up;
	int right;
	int left;
	int x_h_wall;
	int y_h_wall;
	int x_v_wall;
	int y_v_wall;
	double step_y;
	double step_x;
	double distance;
	bool f_point_h;
	bool f_point_v;
} t_ray;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int	width;
	int	height;

	int	fd;
	int index;
	size_t row;
	char **cmap;
	char **splited;
	int rays_number;
	t_ray *ray;
	char **split_numbers;
	t_identifier *id;
	t_player player;
} t_map;


t_map parse(char *mapname);
int parse_line(char *line, int row, int rw, int len);
void bad_alloc(t_map* map);
void free_maps(t_map *map, int flag);
void fd_check(char* name, t_map *m, int flag);
void invalid_map(char *ms, t_map *map, t_identifier *new, char *line);
void parse_textures(char *filename, t_map* map);
void parse_map(char *filename, t_map* map);
void p_directions(t_map* map, int n_players);
void cub_lstadd_back(t_identifier **lst, t_identifier *new);
t_identifier	*cub_lstnew();
void free_splited(char **splited);
int ft_strcmp(char *dest, char *src);
int cub_atoi(char *str, int *err);
void parse_textures_util(t_map *map, int i,char* line);
t_identifier *free_linked_list(t_identifier *id, int flag);
char *convert_to_space(char *str);
void set_rays_angle(t_map *map);
double horizontal_distance(t_map *map, t_ray ray);
void ray_look_direction(double *angle, t_ray *ray);
double vertical_distance(t_map *map, t_ray ray);
int wall_existance(t_map *map, double x, double y);
void render_wall(t_map *map, t_ray ray, int x);
void alloc_check(t_map *map, t_identifier *new, char *line);
void invalid_map_2(char *message, t_map *map, char *line, char *pureline);
void	invalid_map_3(char *message, t_map *map, int flag);

void update_player_p(mlx_key_data_t key, void *param);
void	draw_filled_circle(mlx_image_t *img, int cx, int cy, int radius, int color);
void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
void	draw_tile_pixels(mlx_image_t *img, int x, int y, int color);
void	draw_map(t_map *map);
void draw_player(t_map *map, mlx_image_t *img);
int find_wall(t_map *map, double x, double y);
#endif


//max height and width of the window