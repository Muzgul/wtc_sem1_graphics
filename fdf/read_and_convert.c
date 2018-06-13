#include "header.h"

void    read_save(int fd, mlx_ctrl *my_mlx)
{
    int     **int_array;
    int     i;
    char    **raw_data;

    raw_data = read_to_array(fd);
    i = 0;
    int_array = (int **)malloc(sizeof(int *) * row_count((void **)raw_data));
    while (raw_data[i] != NULL)
    {
        int_array[i] = convert_row(raw_data[i]);
        i++;
    }
    my_mlx->map = int_array;
    my_mlx->map_w = split_and_count(*raw_data, ' ');
    my_mlx->map_h = row_count((void **)raw_data);
}

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

    array_length = row_count((void **)array);
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

void    print_array(mlx_ctrl *my_mlx)
{
    int i;
    int j;

    i = 0;
    while (i < my_mlx->map_h)
    {
        j = 0;
        while (j < my_mlx->map_w)
        {
            ft_putnbr(my_mlx->map[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

//Count number of rows; If not initialised then return 0;
int     row_count(void  **array)
{
    int i;

    if (array == NULL || *array == NULL)
        return (0);
    i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}

int     split_and_count(char *line, char c)
{
    int i;
    char **temp;

    temp = ft_strsplit(line, c);
    i = row_count((void **)temp);
    free(temp);
    return (i);
}

int     *convert_row(char *row)
{
    int i;
    char **temp;
    int *int_row;

    i = 0;
    temp = ft_strsplit(row, ' ');
    int_row = (int *)malloc(sizeof(int) * row_count((void **)temp));
    while (temp[i] != NULL)
    {
        int_row[i] = ft_atoi(temp[i]);
        i++;
    }
    free(temp);
    return (int_row);
}