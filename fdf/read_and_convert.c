#include "header.h"

int     **read_to_array(int fd)
{
    char    *line;
    char    **raw;
    int     **grid;

    line = NULL;
    while (get_next_line(fd, &line) == 1)
    {
        ft_putendl(line);
    }

    return NULL;
}

int     **add_to_array(int **array, int *row)
{
    int i;

    i = row_count(array);
    if (i == -1)
        return (NULL);
    
    
}

int     row_count(int **array)
{
    int i;

    if (array == NULL)
        return (-1);
    i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}