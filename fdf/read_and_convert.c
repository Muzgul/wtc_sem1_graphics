#include "header.h"

char     **read_to_array(int fd)
{
    char    *line;
    char    **raw_data;

    line = NULL;
    raw_data = NULL;
    while (get_next_line(fd, &line) == 1)
    {
        raw_data = add_to_array(raw_data, line);
    }
    return (raw_data);
}

//Take current row count, add1, free input array and return new one;
char    **add_to_array(char **array, char *row)
{
    int i;
    int array_length;
    char **new_array;

    array_length = row_count(array);
    new_array = (char **)malloc(sizeof(char *) * (array_length + 2));//Add one for new row and one for NULL placeholder
    i = 0;
    while (i < array_length)
    {
        new_array[i] = array[i];
        i++;   
    }
    new_array[i] = row;
    new_array[i + 1] = NULL;
    free(array);
    return (new_array);
}

void    print_array(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        ft_putendl(array[i]);
        i++;
    }
}

//Count number of rows; If not initialised then return 0;
int     row_count(char **array)
{
    int i;

    if (array == NULL || *array == NULL)
        return (0);
    i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}