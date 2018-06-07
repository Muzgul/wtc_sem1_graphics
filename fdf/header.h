#include "libft/libft.h"
#include "minilibx/mlx.h"

#ifndef HEADER_H
#define HEADER_H

//Type Declerations

typedef struct		mlx_control
{
	void    *mlx_ptr;
    void    *mlx_win;
    char    **map;
    void    *param;
    int     zoom;
}					mlx_ctrl;

//Function Declerations

char    **read_to_array(int fd);
char    **add_to_array(char **array, char *row);
int     row_count(char **array);
void    print_array(char **array);
void    draw_array(mlx_ctrl *my_mlx);
void    draw_row(void *mlx_ptr, char *row);
char    draw_point(void *mlx_ptr, char c);

void    new_window(mlx_ctrl *my_mlx, int res_x, int res_y, char *title);
int     key_hook(int keycode, void *param);
int     mouse_hook(int button, int x, int y, void *param);
void    run_loop(mlx_ctrl *my_mlx);
void    initialise_mlx(mlx_ctrl **my_mlx);


#endif