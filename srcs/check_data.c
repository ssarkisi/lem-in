/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:35:34 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/03/12 16:35:35 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char			*get_room_name(char *s)
{
	int		i;
	int		n;
	char	*ret;

	i = 0;
	n = 0;
	while (s[n] != ' ')
		n++;
	ret = ft_strnew(n);
	while (n > i)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int				get_room_xy(char *s, int f)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (s[i] != ' ')
		i++;
	i++;
	if (f == 1)
	{
		while (s[i] != ' ')
			i++;
		i++;
	}
	ret = ft_atoin(s, i);
	return (ret);
}

int				check_room_data(char *line, t_data *d, int n)
{
	char	*name;
	char	*name1;
	int		x;
	int		y;

	name = get_room_name(line);
	x = get_room_xy(line, 0);
	y = get_room_xy(line, 1);
	while (d->data[++n + 1] != NULL)
		if (check_room(d->data[n]) == 1)
		{
			name1 = get_room_name(d->data[n]);
			if (ft_strcmp(name1, name) == 0 || (x == get_room_xy(d->data[n], 0)
				&& y == get_room_xy(d->data[n], 1)))
			{
				free_line(name);
				free_line(name1);
				return (-1);
			}
			free_line(name1);
		}
	free_line(name);
	return (3);
}

int				check_link_data(char *line, t_data *d, int f1, int f2)
{
	char	**r;
	char	*name;
	int		n;

	n = 0;
	r = ft_strsplit(line, '-');
	while (d->data[n + 1] != NULL)
	{
		if (check_room(d->data[n]) == 1)
		{
			name = get_room_name(d->data[n]);
			if (ft_strcmp(name, r[0]) == 0)
				f1++;
			else if (ft_strcmp(name, r[1]) == 0)
				f2++;
			free_line(name);
		}
		n++;
	}
	free(r[0]);
	free(r[1]);
	free(r);
	if (f1 != 1 || f2 != 1)
		return (-1);
	return (4);
}
