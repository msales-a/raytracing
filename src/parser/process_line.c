/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:56:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 23:48:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	clear_arg_parsers_results(int argc, void ***results)
{
	int	index;

	index = 0;
	while (index < argc - 1)
		free((*results)[index++]);
	free(*results);
	*results = NULL;
}

bool	process_line(t_rt_data *data, char *line)
{
	char		**argv;
	int			argc;
	t_rt_parser	parser;
	void		**arg_parsed;
	bool		status;

	argv = ft_split(line, ' ');
	argc = count_strtoken(argv);
	arg_parsed = NULL;
	status = false;
	if (!argc
		|| !find_parser(argv[0], argc, &parser)
		|| !process_args(argc, argv, parser.arg_parsers, &arg_parsed)
		|| !parser.line_parser(data, arg_parsed)
		|| (status = true))
	{
		free_strtoken(&argv);
		if (arg_parsed)
			clear_arg_parsers_results(argc, &arg_parsed);
		return (status || !argc);
	}
	return (status);
}