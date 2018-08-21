/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:47:21 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/25 15:47:22 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_roads(t_lemin *l)
{
	t_lemin		*start;
	t_lemin		*end;
	int			i;

	i = 0;
	if (l)
	{
		start = find_start_room(l);
		end = find_end_room(l);
		if (start == NULL || end == NULL)
			return (-1);
		while (i < start->link_count)
		{
			if (start->link[i]->step < 2147483647 && start->link[i]->step >= 0)
				return (1);
			i++;
		}
	}
	return (-1);
}

void			free_t_lemin(t_lemin *l)
{
	t_lemin		*tmp;

	if (l != NULL)
		while (l)
		{
			tmp = l->next;
			free(l->room);
			free(l->link);
			free(l);
			l = tmp;
		}
}

void			read_ants_count(t_data *d)
{
	char		*line;
	int			ants_count;
	int			f;

	d->ant_count = -1;
	while (get_next_line(g_fd, &line) > 0 && line != NULL && line[0] != '\0')
	{
		f = check_line(line, d);
		if (f == 0)
		{
			ants_count = ft_atoi(line);
			free_line(line);
			d->ant_count = ants_count;
			return ;
		}
		else if (f == 5)
			free_line(line);
		else
		{
			free_line(line);
			break ;
		}
	}
}

void			error(int ant_c, t_lemin *l, t_data *d, char *line)
{
	int		n;

	if (ant_c < 0 || l == NULL || find_start_room(l) == NULL ||
		find_end_room(l) == NULL)
	{
		free_all(l, d, line);
		ft_putstr("ERROR\n");
		exit(0);
	}
	mark_roads(l);
	n = check_roads(l);
	if (n == -1 || ant_c == 2147483647)
	{
		free_all(l, d, line);
		ft_putstr("ERROR\n");
	}
	else
	{
		print_d_data(d);
		move_ants(ant_c, l);
		free_all(l, d, line);
	}
	exit(0);
}

int				main(int ac, char **av)
{
	char		*line;
	t_lemin		*l;
	int			f;
	t_data		*d;

	f = 0;
	g_fd = 0;
	if (ac == 2)
		g_fd = open(av[1], O_RDONLY);
	if (ac > 2)
		error(-1, NULL, NULL, NULL);
	d = get_t_data();
	read_ants_count(d);
	if (d->ant_count < 0)
		error(d->ant_count, NULL, d, NULL);
	while (get_next_line(g_fd, &line) > 0)
	{
		f = check_line(line, d);
		if (f != 5)
			l = handler_of_line(d, l, line, f);
		free_line(line);
	}
	error(d->ant_count, l, d, NULL);
	return (0);
}
