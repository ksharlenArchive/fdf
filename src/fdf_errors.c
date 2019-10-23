/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:44:16 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/23 23:06:13 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char *g_fdf_errors[] = {
	"window_error",
	"image_error",
	"xpm_image_error",
	"xpm_file_to_image_error"
};

void	fdf_err_str(const int err)
{
	ft_printf("%s: %s\n", PROG_NAME, g_fdf_errors[err]);
}

void	fdf_err_ext(const int err)
{
	fdf_err_str(err);
	exit(EXIT_FAILURE);
}
