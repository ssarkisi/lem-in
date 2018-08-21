/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:39:27 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/27 18:39:28 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_room(char *line)
{
	int		i;

	i = 0;
	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	if (ft_count_char(line, ' ') != 2)
		return (-2);
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] == '-')
			return (-3);
		i++;
	}
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && !(line[i + 1] >= '0' && line[i + 1] <= '9'))
			return (-4);
		i++;
	}
	return (1);
}

int				check_link(char *line)
{
	int		i;

	i = 0;
	if (ft_count_char(line, '-') != 1)
		return (-1);
	if (line[0] == '-')
		return (-2);
	if (ft_count_char(line, ' ') != 0)
		return (-3);
	while (line[i] != '-')
		i++;
	if (line[++i] == '\0')
		return (-3);
	return (1);
}

int				check_count(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int				check_line(char *line, t_data *d)
{
	int		f;

	f = -1;
	realloc_d_data(d, line);
	if (check_count(line) == 1)
		f = 0;
	else if (ft_strcmp(line, "##start") == 0)
		f = 1;
	else if (ft_strcmp(line, "##end") == 0)
		f = 2;
	else if (check_room(line) == 1)
		f = 3;
	else if (check_link(line) == 1)
		f = 4;
	else if (line[0] == '#')
		f = 5;
	else if (line[0] == '\0')
		f = -1;
	if (f == 3)
		f = check_room_data(line, d, -1);
	else if (f == 4)
		f = check_link_data(line, d, 0, 0);
	return (f);
}

int				check_line2(char *line, t_data *d)
{
	int		f;

	f = -1;
	if (check_count(line) == 1)
		f = 0;
	else if (ft_strcmp(line, "##start") == 0)
		f = 1;
	else if (ft_strcmp(line, "##end") == 0)
		f = 2;
	else if (check_room(line) == 1)
		f = 3;
	else if (check_link(line) == 1)
		f = 4;
	else if (line[0] == '#')
		f = 5;
	else if (line[0] == '\0')
		f = -1;
	if (f == 3)
		f = check_room_data(line, d, -1);
	else if (f == 4)
		f = check_link_data(line, d, 0, 0);
	return (f);
}
