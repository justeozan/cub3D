#ifndef CUB3D_H
# define CUB3D_H

/*=================TABLE OF CONTENTS=================*/

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
5. STRUCTURES
6. FUNCTIONS
   6.1 DEBUG
   6.2 INIT
   6.3 PARSING
   6.4 ERROR HANDLING
*/

/*=================INCLUDES=================*/

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*=================COLORS=================*/

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

/*=================ERROR MESSAGES=================*/

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
# define ERR_FILE_4		"Error\nmap in file is not in right place."
# define ERR_FILE_5		"Error\nmap is not present in the file."

//SPRITES ERRORS

# define ERR_SPRITES	"Error\nSprite has bad format."
# define ERR_SPRITES_2	"Error\nSprite missing"
# define ERR_SPRITES_3	"Error\nSprite with bad extension."
# define ERR_SPRITES_4	"Error\nSaving sprites failed."
# define ERR_SPRITES_5	"Error\nMultiple Same Cardinal point in file."
# define ERR_SPRITES_6	"Error\nSprite has a bad Cardinal point, format needed: <NO.SO.WE.EA>."

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
# define ERR_MAP_2		"Error\nnumber of player is not 1."
# define ERR_MAP_3		"Error\nmap empty."
# define ERR_MAP_4		"Error\nThe map is not closed."
# define ERR_MAP_5		"Error\nInvalid character in the map."
# define ERR_MAP_6		"Error\nSeveral maps in one."

//DATA ERRORS

# define ERR_DATA		"Error\nColor or Texture is missing."

//INIT ERRORS

# define ERR_INIT		"Error\nAn initialization failed."
# define ERR_INIT_1		"Error\nMlx initialization failed."
# define ERR_INIT_2		"Error\nImage initialization failed."
# define ERR_INIT_3		"Error\nImage address initialization failed."
# define ERR_INIT_4		"Error\nSprites references initialization failed."
# define ERR_INIT_5		"Error\nSprites address initialization failed."

/*===================VALUES===================*/

# define SCREEN_WIDTH		3840
# define SCREEN_HEIGHT		2160

/*=================STRUCTURES=================*/

/**
 * @brief Enum for the garbage collector id
 * @param DATA: data structure
 * @param MATRIX: matrix structure
 * @param TMP: temporary structure
 * @note Start at 1.
 */
typedef enum e_gc_id
{
	DATA = 0,
	MAP,
	SPRITES,
	TMP
}	t_gc_id;

typedef enum e_cardinal
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST
}	t_cardinal;

/**
 * @brief Structure for the mlx data
 * @param mlx_ptr: mlx pointer
 * @param win_ptr: window pointer
 * @param width: width of the window
 * @param height: height of the window
 * @note The width and height are the resolution of the window
*/
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_mlx;

/**
 * @brief Structure for the image data
 * @param img_ptr: image pointer
 * @param addr: address of the image, the first pixel of image array
 * @param bit_per_pixel: bit per pixel
 * @param len_line: length of the line
 * @param endian: endian, means the order of the bytes
*/
typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixel;
	int		len_line;
	int		endian;
}	t_image;

/**
 * @brief Structure for the colors of the floor and ceiling of the game
 * @param floor: int contain (r * 256 * 256) + (g * 256) + b
 * @param ceiling: int contain (r * 256 * 256) + (g * 256) + b
*/
typedef struct s_colors
{
	int	floor;
	int	ceiling;
}	t_colors;

/**
 * @brief Structure for the sprites data
 * @param path: path to the sprite texture
 * @param len_line: length of the line
 * @param bit_per_pixel: ?
*/
typedef struct s_sprites
{
	t_cardinal	point;
	char		*path;
	void		*reference;
	char		*addr;
	int 		x;
	int			y;
	int			len_line;
	int			bit_per_pixel;
	int			endian;
}	t_sprites;

/**
 * @brief Structure for the map data
 * @param content: the map
 * @param height: height of the map
 * @param width: width of the map
*/
typedef struct s_map
{
	char	**content;
	int		height;
	int		width;
}	t_map;

/**
 * @brief Structure for the data of the game,
 * @param no: path to the north texture
 * @param so: path to the south texture
 * @param we: path to the west texture
 * @param ea: path to the east texture
 * @param f: path to the floor texture
 * @param c: path to the ceiling texture
 * @param file: the map file (with no whitespaces)
 */
typedef struct s_data
{
	t_mlx		mlx;
	t_image		img;
	t_colors	colors;
	t_sprites	sprites[4];
	t_map		mappy;
	char		**file;
}	t_data;

/*=================FUNCTIONS=================*/

/* ________________ DEBUG ________________ */

/*                 debug.c                 */

void	print_data(t_data *data);
void	print_file(char **file);
void	print_file_without_spaces(char **file);
void	print_map(char **map, int height);
void	print_all_infos(t_data *data);

/* ________________ INIT ________________ */

/*                 init_mlx.c                 */

t_data	*init_struct(void);

/*                 init_mlx.c                 */

void	init_sprites(t_data *data, t_mlx *mlx);

/*                 init_mlx.c                 */

void	init_mlx(t_mlx *mlx);
void	init_image(t_image *img, t_mlx mlx);

/* _______________ PARSING _______________ */

/**
 * @file	---- parse_colors.c ----
 * @brief	Parse the colors of the map file
 * @param data: the structure that contains all the data of the game
 * @param line: the line where the colors are
 * @note The color's lines are in the format "F 255,255,255" or "C 255,255,255"
*/
void	parse_colors(t_data *data, char *line);

/**
 * @file	---- parse_file_utils.c ----
 * @brief	Check the format of the map file (order of the elements)
 * @param	file: the entire file
 * @note	The order of the elements in the file must be:
 * 			1. Four textures
 * 			2. Two color
 * 			3. Map
*/
void	check_file_format(char **file);

/**
 * @file	---- parse_file.c ----
 * @brief	Parse the map file
 * @param	fd: the file descriptor
 * @return	The file without whitespaces, NULL if an error occured
*/
char	**get_file(int fd);

/**
 * @file	---- parse_map_utils.c ----
 * @brief	replace all the spaces in the map by walls
 * @param	map: the map checked
 * @param	height: the height of the map, means number of lines (start at 1)
 * @param	width: the width of the map, means number of characters in a line (start at 1)
*/
void	replace_space_by_wall(char **map, int height, int width);

/**
 * @file	---- parse_map.c ----
 * @brief	Parse the map of the map in file we received
 * @param	data: the structure that contains all the data of the game
 * @param	file: the file without whitespaces (!)
 * @note	Here we check if the map is valid, if there is only one player, if the map is closed, etc.
*/
void	get_map(t_data *data, char **file);

/**
 * @file	---- parse_textures.c ----
 * @brief	Parse the textures of the map file
 * @param	data: the structure that contains all the data of the game
 * @param	line: the line where the textures are
*/
void	parse_sprites(t_data *data, char *line);

/**
 * @file	---- parse_utils.c ----
 * @brief	Parse the textures of the map file
 * @param	file: the file without whitespaces
*/
// int		count_line(char **file);

/**
 * parsing.c ----
 * @brief	Parse the map file
*/
void	parse(char	**av, t_data *data);

/*             error.c             */

void	print_error_msg(char *str);
// void	ft_exit(char *str, int error_code);
void	ft_exit(char *str);

#endif
