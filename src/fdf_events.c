/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:41:37 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/25 19:40:01 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#undef MLX_PTR
#undef MLX_WIN
#define MLX_PTR	mlx->mlx_ptr.mlx_ptr
#define MLX_WIN mlx->mlx_ptr.mlx_win

static int	key_press(int key, t_mlx *mlx)
{
	if (key == FDF_ESC)
		exit(EXIT_SUCCESS);
	else if (key == FDF_NUM_KEY_PLS)
		mlx->map.scale *= FDF_ZOOM_IN;
	else if (key == FDF_NUM_KEY_SUB)
		mlx->map.scale *= FDF_ZOOM_OUT;
	else if (key == FDF_LEFT_ARROW)
		mlx->map.shift_x -= FDF_SHIFT;
	else if (key == FDF_RIGHT_ARROW)
		mlx->map.shift_x += FDF_SHIFT;
	else if (key == FDF_UP_ARROW)
		mlx->map.shift_y -= FDF_SHIFT;
	else if (key == FDF_DOWN_ARROW)
		mlx->map.shift_y += FDF_SHIFT;
	fdf_work_frame(mlx);
	return (SUCCESS);
}

static int	red_button(void *param)
{
	P_UNUSED(param);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	P_UNUSED(x);
	P_UNUSED(y);
	P_UNUSED(param);
	if (button == FDF_LEFT_BUTTON)
		;
	else if (button == FDF_RIGHT_BUTTON)
		;
	else if (button == FDF_MIDDLE_BUTTON)
		;
	else if (button == FDF_SCROLL_DOWN)
		;
	else if (button == FDF_SCROLL_UP)
		;
	else if (button == FDF_SCROLL_LEFT)
		;
	else if (button == FDF_SCROLL_RIGHT)
		;
	return (SUCCESS);
}

static int	mouse_mov(int x, int y, void *param)
{
	P_UNUSED(x);
	P_UNUSED(y);
	P_UNUSED(param);
	return (SUCCESS);
}

void		fdf_events(t_mlx *mlx)
{
	mlx_hook(MLX_WIN, FDF_KEY_PRESS, FDF_NOT_WORK, key_press, mlx);
	mlx_hook(MLX_WIN, FDF_RED_BUTTON, FDF_NOT_WORK, red_button, NULL);
	mlx_hook(MLX_WIN, FDF_MOUSE_BUTTON_PRESS, FDF_NOT_WORK, mouse_press, NULL);
	mlx_hook(MLX_WIN, FDF_MOUSE_MOVEMENT, FDF_NOT_WORK, mouse_mov, NULL);
	mlx_loop(MLX_PTR);
}
