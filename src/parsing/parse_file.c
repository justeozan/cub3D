#include "../includes/cub3D.h"

static char *parse_line_map(char *str)
{
	int i;
	int j;
	int len;
	char *new_line;

	i = -1;
	len = 0;
	while (str[++i] && str[i] != '\n')
			len++;
	new_line = gc_malloc(sizeof(char) * len + 1, TMP);
	if (!new_line)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '\n')
		new_line[++j] = str[i];
	new_line[++j] = '\0';
	return (new_line);
}

static char *parse_line(char *str)
{
	int i;
	int j;
	int len;
	char *new_line;

	i = -1;
	len = 0;
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t')
			len++;
	new_line = gc_malloc(sizeof(char) * len + 3, TMP);
	if (!new_line)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '\n' && str[i] != ' ')
		new_line[++j] = str[i];
	new_line[++j] = ' ';
	while (str[++i] && str[i] != '\n')
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			new_line[++j] = str[i];
	new_line[++j] = '\0';
	return (new_line);
}

static int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static char **delete_whitespaces(char **file)
{
	int	i;
	int	j;
	int	line;

	i = -1;
	line = 0;
	while (file[++i])
	{
		while (ft_isempty(file[i]) > 0)
			i++;
		if (!file[i])
			break;
		j = 0;
		while (file[i][j] == ' ')
			j++;
		if (ft_isalpha(file[i][j]))
			file[line] = gc_strdup(parse_line(&file[i][j]), TMP);
		else
			file[line] = gc_strdup(parse_line_map(file[i]), TMP);
		line++;
	}
	file[line] = NULL;
	while (file[line])
		free(file[line++]);
	return (file);
}

char **get_file(int fd)
{
	char	**file;
	char	**tmp;
	int		capacity;
	int		i;
	
	capacity = 10;
	file = gc_malloc(sizeof(char *) * capacity, TMP);
	if (!file)
		return (NULL);
	i = 0;
	file[i] = (get_next_line(fd));
	while (file[i])
	{
		i++;
		if (i >= capacity - 1)
		{
			capacity *= 2;
			tmp = gc_realloc(file, sizeof(char *) * (capacity / 2), sizeof(char *) * capacity, TMP);
			if (!tmp)
				return (ft_exit(ERR_MALLOC, EXIT_FAILURE), NULL);
			file = tmp;
		}
		file[i] = get_next_line(fd);
	}
	return (delete_whitespaces(file));
}
