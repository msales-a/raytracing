/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:41:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	cube(t_object **obj, t_cube_build params)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = cube_intersect;
	(*obj)->normal_at = cube_normal_at;
	(*obj)->color = params.color;
	add_transformation(*obj,
		scaling(params.half_size, params.half_size, params.half_size));
	add_transformation(*obj,
		translate(params.origin.x, params.origin.y, params.origin.z));
	add_transformation(*obj,
		from_to_rotation(vector(0, 1, 0), params.direction));
	return (true);
}
