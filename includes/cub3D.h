
#ifndef CUB3D_H
# define CUB3D_H

/*=================INCLUDES=================*/

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

/*=================COLORS=================*/

# define RESET	"\033[0m"
# define RED	"\033[0;31m"
# define WHITE	"\033[37m"
# define GREEN	"\033[32m"

/*=================ERROR MESSAGES=================*/

# define ERR_MALLOC "Error: Memory allocation failed with malloc."
# define ERR_ARGS "Error: args format: ./cub3D <map_name.cub>."
# define ERR_FILE "Error: bad fd."
# define ERR_TEXTURE "Error: texture(s) file(s) missing or has bad format."
# define COLOR_FORMAT_ERROR "Error: Invalid color format."



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
	DATA = 1,
	MATRIX,
	TEXTURE,
	TMP
}	t_gc_id;

/**
 * @brief Structure for the map of the game,
 * @param w: width of the matrix
 * @param h: height of the matrix
 */
typedef struct s_matrix
{
	int	w;
	int	h;
	int	x;
	int	y;
	int	wall;
	int	xproj;
	int	yproj;
	int	zproj;
}	t_matrix;

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
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_matrix	*matrix;
	char		**file;
}	t_data;

/*=================FUNTIONCS=================*/

// debug.c
void	print_structs(t_data *data, t_matrix *matrix);
void	print_file(char **file);

// check_map.c
bool	check_map(int ac, char	**args);

// PARSING

// parse_colors.c
void	parse_colors(t_data *data, char *line);

// error.c
void	parse_texture(t_data *data, char *line);

// error.c
void	print_error_msg(char *str);
void	ft_exit(char *str, int error_code);
t_data	*parse(int ac, char	**args);

#endif
