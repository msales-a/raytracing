/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 21:34:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	render(t_camera camera, t_canvas canvas, t_list *lst)
{
	int		x;
	int		y;
	double	w;
	double	h;
	t_intersection	record;

	y = canvas.height;
	while (--y >= 0)
	{
		x = -1;
		while (x++ < canvas.width - 1)
		{
			h = y / (double)(canvas.height - 1);
			w = x / (double)(canvas.width - 1);
			if (hit(get_ray(camera, w, h), lst, &record))
			{
				t_tuple k = divide(sum(normalize(record.normal), vector(1, 1, 1)), 2);
				write_pixel(canvas, x, y,
					(t_tuple_pixel)k);
			}
		}
	}
}