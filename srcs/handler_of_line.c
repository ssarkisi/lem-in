/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_of_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:36:23 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/27 18:36:24 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*add_new_room(t_lemin *l, char *line, int f, t_data *d)
{
	t_lemin		*new;

	new = NULL;
	if (f == 1 || f == 2)
		new = get_new_lemin_start_end(f, l, d);
	else if (f == 3)
		new = get_new_lemin(line);
	if (l)
		new->next = l;
	return (new);
}

void			realloc_link(t_lemin *r1, t_lemin *r2)
{
	int			i;
	t_lemin		**ret;

	i = 0;
	ret = (t_lemin**)malloc(sizeof(t_lemin*) * (r1->link_count + 2));
	while (i < r1->link_count)
	{
		ret[i] = r1->link[i];
		i++;
	}
	ret[i] = r2;
	i++;
	ret[i] = NULL;
	free(r1->link);
	r1->link = ret;
	r1->link_count++;
}

void			set_link(t_lemin *r1, t_lemin *r2)
{
	realloc_link(r1, r2);
	realloc_link(r2, r1);
}

void			add_new_link(t_lemin *l, char *line)
{
	char		**r;
	t_lemin		*r1;
	t_lemin		*r2;

	r = ft_strsplit(line, '-');
	r1 = NULL;
	while (l != NULL)
	{
		if (ft_strcmp(l->room, r[0]) == 0)
			r1 = l;
		if (ft_strcmp(l->room, r[1]) == 0)
			r2 = l;
		l = l->next;
	}
	set_link(r1, r2);
	free(r[0]);
	free(r[1]);
	free(r);
}

t_lemin			*handler_of_line(t_data *d, t_lemin *l, char *line, int f)
{
	static int		start = 0;
	static int		end = 0;
	static int		room = 0;
	static int		link = 0;

	if (f == 1 || f == 2 || f == 3)
	{
		if (f == 1 && start == 0 && link == 0)
			start++;
		else if (f == 2 && end == 0 && link == 0)
			end++;
		else if (f == 3 && link == 0)
			room++;
		else
			error(d->ant_count, l, d, line);
		l = add_new_room(l, line, f, d);
	}
	else if (f == 4 && start == 1 && end == 1)
	{
		add_new_link(l, line);
		link++;
	}
	else
		error(d->ant_count, l, d, line);
	return (l);
}
