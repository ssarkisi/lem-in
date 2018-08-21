/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:18:23 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/27 19:18:24 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*find_start_room(t_lemin *l)
{
	while (l)
	{
		if (l->start == 1)
			return (l);
		l = l->next;
	}
	return (NULL);
}

t_lemin			*find_end_room(t_lemin *l)
{
	while (l)
	{
		if (l->end == 1)
			return (l);
		l = l->next;
	}
	return (NULL);
}

char			*set_room_name(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] != ' ')
		i++;
	ret = ft_strnew(i);
	i = 0;
	while (line[i] != ' ')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

t_lemin			*get_new_lemin(char *line)
{
	t_lemin		*new;

	if (line != NULL && line[0] != '\0')
	{
		new = malloc(sizeof(t_lemin));
		new->print = 0;
		new->label = 0;
		new->step = 2147483647;
		new->start = 0;
		new->end = 0;
		new->room = set_room_name(line);
		new->ant = 0;
		new->link = NULL;
		new->link_count = 0;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

t_lemin			*get_new_lemin_start_end(int f, t_lemin *l, t_data *d)
{
	t_lemin		*new;
	char		*s;
	int			f1;

	while (get_next_line(g_fd, &s) > 0 && (f1 = check_line(s, d)))
	{
		if (f1 == 5)
			free_line(s);
		else if (f1 != 3)
			error(-1, l, d, s);
		else if (f1 == 3)
			break ;
	}
	if (s == NULL || s[0] == '\0')
		error(-1, l, d, s);
	new = get_new_lemin(s);
	if (f == 2)
		new->step = 0;
	if (f == 1)
		new->start = 1;
	if (f == 2)
		new->end = 1;
	free_line(s);
	return (new);
}
