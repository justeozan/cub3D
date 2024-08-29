/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:52:13 by ozasahin          #+#    #+#             */
/*   Updated: 2024/08/29 18:11:25 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*===========================================*/
/*             TABLE OF CONTENTS             */
/*===========================================*/

/*
1. INCLUDES
2. COLORS
3. ERROR MESSAGES
   3.1 MALLOC ERROR
   3.2 ARGS ERRORS
   3.3 FILE ERRORS
   3.4 SPRITES ERRORS
   3.5 COLOR ERRORS
   3.6 MAP ERRORS
   3.7 DATA ERRORS
   3.8 INIT ERRORS
4. VALUES
5. ENUM
6. STRUCTURES
7. FUNCTIONS
   6.1 CLOSE PROGRAM
   6.2 DEBUG
   6.3 GAME LOOP
   6.4 INIT
   6.5 KEY HANDLER
   6.6 PARSING
*/

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*===========================================*/
/*                  COLORS                   */
/*===========================================*/

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

/*===========================================*/
/*              ERROR MESSAGES               */
/*===========================================*/

//MALLOC ERROR

# define ERR_MALLOC		"Error\nMemory allocation failed."

//ARGS ERRORS

# define ERR_ARGS		"Error\nWrong args format: ./cub3D <map_name.cub>."
# define ERR_ARGS_1		"Error\nWrong file extension: .cub needed."
# define ERR_ARGS_2		"Error\nWrong Screen resolution format."

//FILE ERRORS

# define ERR_FILE		"Error\nBad fd."
# define ERR_FILE_1		"Error\nFile has bad format."
# define ERR_FILE_2		"Error\nFile is empty."
# define ERR_FILE_3		"Error\nFile has something after the map."
# define ERR_FILE_4		"Error\nMap in file is not in right place."
# define ERR_FILE_5		"Error\nMap is not present in the file."

//SPRITES ERRORS

# define ERR_SPRITES	"Error\nSprite has bad format."
# define ERR_SPRITES_2	"Error\nSprite missing"
# define ERR_SPRITES_3	"Error\nSprite with bad extension."
# define ERR_SPRITES_4	"Error\nSaving sprites failed."
# define ERR_SPRITES_5	"Error\nMultiple Same Cardinal point in file."
# define ERR_SPRITES_6	"Error\nSprite has a bad Cardinal point: <NO.SO.WE.EA>."

//COLOR ERRORS

# define ERR_COLOR		"Error\nInvalid color format."
# define ERR_COLOR_2	"Error\nColor is double."
# define ERR_COLOR_3	"Error\nColor value is missing."
# define ERR_COLOR_4	"Error\nColor value is not between 0-255."
# define ERR_COLOR_5	"Error\nColor is null."
# define ERR_COLOR_F	"Error\nFloor color is missing in data structure."
# define ERR_COLOR_C	"Error\nCeiling color is missing in data structure."

//MAP ERRORS

# define ERR_MAP		"Error\nInvalid map format."
# define ERR_MAP_2		"Error\nNumber of player is not 1."
# define ERR_MAP_3		"Error\nMap empty."
# define ERR_MAP_4		"Error\nThe map is not closed."
# define ERR_MAP_5		"Error\nInvalid character in the map."
# define ERR_MAP_6		"Error\nSeveral maps in one."
# define ERR_MAP_7		"Error\nA 0 is not surrounded by walls."
# define ERR_MAP_8		"Error\nA bad character is in the wall."
# define ERR_MAP_9		"Error\nMap is too big."

//DATA ERRORS

# define ERR_DATA		"Error\nColor or Texture is missing."

//INIT ERRORS

# define ERR_INIT		"Error\nAn initialization failed."
# define ERR_INIT_1		"Error\nMlx initialization failed."
# define ERR_INIT_2		"Error\nImage initialization failed."
# define ERR_INIT_3		"Error\nImage address initialization failed."
# define ERR_INIT_4		"Error\nSprites references initialization failed."
# define ERR_INIT_5		"Error\nSprites address initialization failed."
# define ERR_INIT_6		"Error\nPlayer position don't finded."
# define ERR_INIT_7		"Error\nPlayer direction don't finded."

/*===========================================*/
/*                  VALUES                   */
/*===========================================*/

# define PI	3.14159265358979323846

// 3840
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH	800
# endif

// 2160
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT	800
# endif

// # ifndef FOV
// #  define FOV	60
// # endif

# ifndef PLANE_FOV
#  define PLANE_FOV 0.649408
# endif

# ifndef PLAYER_STEP_SIZE
#  define PLAYER_STEP_SIZE 0.050
# endif

# ifndef PLAYER_ROT_SPEED
#  define PLAYER_ROT_SPEED	0.032
# endif

/*===========================================*/
/*                   ENUM                    */
/*===========================================*/

/***************************************
 * @brief	Enum for the garbage collector id
 * @param	DATA: data structure
 * @param	MATRIX: matrix structure
 * @param	TMP: temporary structure
 * @note	Start at 1.
 ***************************************/
typedef enum e_gc_id
{
	DATA = 0,
	MAP,
	SPRITES,
	MLX,
	TMP
}	t_gc_id;

typedef enum e_cardinal
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}	t_cardinal;

/*===========================================*/
/*                STRUCTURES                 */
/*===========================================*/

typedef struct s_fvector
{
	float	x;
	float	y;
}	t_fvector;

typedef struct s_dvector
{
	double	x;
	double	y;
}	t_dvector;

typedef struct s_ivector
{
	int	x;
	int	y;
}	t_ivector;

typedef struct s_ray
{
	t_ivector	map_pos;
	t_ivector	step_direction;
	t_dvector	true_pos;
	t_dvector	dir;
	t_dvector	delta_dist;
	t_dvector	side_dist;
}	t_ray;

typedef struct s_dda
{
	double		dist;
	t_cardinal	cardinal;
}	t_dda;

typedef struct s_pixel_column
{
	int		x_sprite;
	int		y_sprite;
	int		y_start;
	int		y_end;
	int		height;
	int		color;
}	t_pixel_column;

/***************************************
 * @brief	Structure for the colors of the floor and ceiling of the game
 * @param	floor: int contain (r * 256 * 256) + (g * 256) + b
 * @param	ceiling: int contain (r * 256 * 256) + (g * 256) + b
***************************************/
typedef struct s_colors
{
	int	floor;
	int	ceiling;
}	t_colors;

/***************************************
 * @brief	Structure for the sprites data
 * @param	path: path to the sprite texture
 * @param	len_line: length of the line
 * @param	bit_per_pixel: ?
***************************************/
typedef struct s_sprites
{
	t_cardinal		cardinal;
	void			*reference;
	// unsigned char	*pixels;
	char			*path;
	unsigned char	*addr;
	int				x;
	int				y;
	int				len_line;
	int				bit_per_pixel;
	int				endian;
}	t_sprites;

/***************************************
 * @brief	Structure for the map data
 * @param	content: the map
 * @param	height: height of the map
 * @param	width: width of the map
***************************************/
typedef struct s_map
{
	char	**content;
	int		height;
	int		width;
}	t_map;

/***************************************
 * @brief	Structure for the mlx data
 * @param	mlx_ptr: mlx pointer
 * @param	win_ptr: window pointer
 * @param	width: width of the window
 * @param	height: height of the window
 * @note	The width and height are the resolution of the window
***************************************/
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_mlx;

/***************************************
 * @brief	Structure for the image data
 * @param	img_ptr: image pointer
 * @param	addr: address of the image, the first pixel of image array
 * @param	bit_per_pixel: bit per pixel
 * @param	len_line: length of the line
 * @param	endian: endian, means the order of the bytes
***************************************/
typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixel;
	int		len_line;
	int		endian;
}	t_image;

/***************************************
 * @brief	Structure for the player data
 * @param	dir: the direction of the player
 * @param	pos: the position of the player
 * @param	plane: ?
 * @param	movement: ?
 * @note	all the values are in double, for better precision.
***************************************/
typedef struct s_player
{
	double		dir_angle;
	t_cardinal	cardinal;
	t_dvector	dir;
	t_dvector	pos;
	t_dvector	plane;
	t_dvector	movement;
}	t_player;

/***************************************
 * @brief	Structure for the keys data
 * @param	w: key W
 * @param	a: key A
 * @param	s: key S
 * @param	d: key D
 * @param	left: key left
 * @param	right: key right
***************************************/
typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

/***************************************
 * @brief	Structure for the data of the game,
 * @param	no: path to the north texture
 * @param	so: path to the south texture
 * @param	we: path to the west texture
 * @param	ea: path to the east texture
 * @param	f: path to the floor texture
 * @param	c: path to the ceiling texture
 * @param	file: the map file (with no whitespaces)
 ***************************************/
typedef struct s_data
{
	t_colors	colors;
	t_sprites	sprites[4];
	t_map		map;
	t_mlx		mlx;
	t_image		img;
	t_player	player;
	t_keys		keys;
}	t_data;

/*===========================================*/
/*                 FUNCTIONS                 */
/*===========================================*/

/*---------------------------------*/
/*              Debug              */
/*---------------------------------*/

void	print_file(char **file);
void	print_player_infos(t_player *player);
void	print_all_infos(t_data *data);

/*---------------------------------*/
/*          Close program          */
/*---------------------------------*/

int		after_mlx_init(int i);
t_data	*set_get_data(t_data *data);
void	ft_exit(char *str);
int		close_program(void);

/*---------------------------------*/
/*         game_loop/frame         */
/*---------------------------------*/

void	draw_floor_ceiling(t_data *data, t_image img);
void	print_col(t_data *data, t_dda *wall_ray, t_ray *ray, int x);

/*---------------------------------*/
/*         game_loop/player        */
/*---------------------------------*/

void	init_player(t_data *data, t_player *player);
void	modif_player(t_data *data);
double	to_rad(int degree);
void	process_player_dir(t_player *player);
void	process_player_plane(t_player *player);
void	process_player_movement(t_player *player);

/*---------------------------------*/
/*      game_loop/ray_casting      */
/*---------------------------------*/

void	init_ray(t_ray *ray, t_player player, double camera_x);
void	init_ray_dda(t_ray *r);
void	init_wall_dda(t_map *map, t_ray *ray, t_dda *wall_ray);

/*---------------------------------*/
/*             game_loop           */
/*---------------------------------*/

void	ray_casting(t_data *data);
int		game_loop(t_data *data);
void	game_event_loop(t_data *data);

/*---------------------------------*/
/*               Init              */
/*---------------------------------*/

void	init_image(t_image *img, t_mlx mlx);
void	init_mlx(t_mlx *mlx);
t_data	*init_struct(void);
void	init_sprites(t_data *data, t_mlx *mlx);

/*---------------------------------*/
/*           Key handler           */
/*---------------------------------*/

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

/*---------------------------------*/
/*              Parsing            */
/*---------------------------------*/

void	parse_colors(t_data *data, char *line);
void	check_file_format(char **file);
int		get_height_file(char *file);
char	**get_file(int fd, char *av);
void	replace_space_by_wall(char **map, int height, int width);
void	get_map(t_data *data, char **file);
void	parse_sprites(t_data *data, char *line);
void	parse(char	**av, t_data *data);

#endif /* CUBE3D_H */

/*
-> Before update close_program and close all mlx pointers.
 LEAK SUMMARY:
definitely lost: 1,291 bytes in 28 blocks
indirectly lost: 544 bytes in 4 blocks
possibly lost: 0 bytes in 0 blocks
still reachable: 92,461 bytes in 99 blocks
suppressed: 0 bytes in 0 blocks
-> After.
 LEAK SUMMARY:
LEAK SUMMARY:
definitely lost: 643 bytes in 22 blocks
indirectly lost: 0 bytes in 0 blocks
possibly lost: 0 bytes in 0 blocks
still reachable: 0 bytes in 0 blocks
suppressed: 0 bytes in 0 blocks

*/