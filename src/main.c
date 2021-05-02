/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 23:26:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt_data	rt;

	if (argc < 2)
		return (false);
	rt.resolution.width = 0;
	rt.resolution.height = 0;
	rt.cameras = NULL;
	rt.objects = NULL;
	process_file(argv[1], &rt);
	return (EXIT_SUCCESS);
}
