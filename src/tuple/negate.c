/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:56:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	negate(t_tuple a)
{
	return (
		tuple(
			-a.x,
			-a.y,
			-a.z,
			-a.w));
}
