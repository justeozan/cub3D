#ifndef CUB3D_H
# define CUB3D_H

/*=================INCLUDES=================*/

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

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

# define ERR_MALLOC		"Error\nMemory allocation failed."
# define ERR_ARGS		"Error\nWrong args format: ./cub3D <map_name.cub>."
# define ERR_FILE		"Error\nBad fd."
# define ERR_FILE_EMPTY	"Error\nFile is empty."
# define ERR_SPRITES	"Error\nTexture(s) file(s) missing or has bad format."
# define ERR_COLOR		"Error\nInvalid color format."
# define ERR_MAP		"Error\nInvalid map format."
# define ERR_DATA		"Error\nColor or Texture is missing."


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


typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixel;
	int		len_line;
	int		endian;
}	t_img;

typedef struct s_colors
{
	int	floor;
	int	ceiling;
}	t_colors;

typedef struct s_sprites
{
	char	*path;
	int		len_line;
	int		bit_per_pixel;
}	t_sprites;

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
	t_img		img;
	t_colors	colors;
	t_sprites	sprites[4];
	t_map		mappy;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	char		**file;
	// char		**map;
	int		height;
	int		width;
}	t_data;

/*=================FUNCTIONS=================*/

/* ________________ DEBUG ________________ */

/*                 debug.c                 */

void	print_file(char **file);
void	print_data(t_data *data);
// void	print_matrix(t_matrix **matrix, int height);
void	print_map(char **map, int height);

/* ________________ INIT ________________ */

/*                 debug.c                 */

t_data	*init_struct();
void	init_mlx(t_mlx *mlx);

/* _______________ PARSING _______________ */

/**
 * @file	---- parse_colors.c ----
 * @brief	Parse the colors of the map file
*/
void	parse_colors(t_data *data, char *line);


/**
 * @file	---- parse_file.c ----
 * @brief	Parse the map file
*/
char	**get_file(int fd);

void	replace_space_by_wall(char **map, int height, int width);


/**
 * @file	---- parse_map.c ----
 * @brief	Parse the map of the map file
*/
void	get_map(t_data *data, char **file);

/**
 * @file	---- parse_textures.c ----
 * @brief	Parse the textures of the map file
*/
void	parse_texture(t_data *data, char *line);

/**
 * @file	---- parse_utils.c ----
 * @brief	Parse the textures of the map file
*/
int		count_line(char **file);

/**
 * @file	---- parsing.c ----
 * @brief	Parse the map file
*/
void	parse(int ac, char	**args, t_data *data);

/*             error.c             */

void	print_error_msg(char *str);
void	ft_exit(char *str, int error_code);

#endif
