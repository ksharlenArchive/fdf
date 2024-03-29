/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:53:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/31 15:28:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_listfdf		*beg;
	t_mlx			mlx;

	if (fdf_valid_arg(argc, argv) == SUCCESS)
	{
		beg = NULL;
		if ((beg = fdf_read_file(FDF_MAP)))
		{
			fdf_parsing_map(beg, &mlx.map);
			fdf_list_delete(&beg);
			fdf_work_window(&mlx);
			fdf_del_map(&mlx.map.map);
			fdf_del_height_ptr(&mlx.map.height_not_zero);
		}
	}
	return (0);
}
