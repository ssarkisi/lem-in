/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:07:05 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/03/04 15:07:07 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			**get_la(int ants, t_lemin *l)
{
	int			i;
	t_lemin		**la;
	t_lemin		*start;

	i = 0;
	la = (t_lemin**)malloc(sizeof(t_lemin) * (ants + 1));
	start = find_start_room(l);
	while (i <= ants)
	{
		la[i] = start;
		i++;
	}
	return (la);
}

void			make_step(t_lemin **la, int n, int best)
{
	la[n]->ant = 0;
	la[n] = la[n]->link[best];
	if (la[n]->end == 1)
		la[n]->ant++;
	else
		la[n]->ant = 1;
	la[n]->print = 1;
	if (g_print_flag == 1)
		ft_putstr(" ");
	g_print_flag = 1;
	add_to_print(la[n], n);
}

void			next_step(t_lemin **la, int n)
{
	int			i;
	int			best;

	i = -1;
	best = 0;
	while (la[n]->link[++i] != NULL)
		if (la[n]->link[i]->ant == 0)
		{
			best = i;
			break ;
		}
	i = -1;
	while (la[n]->link[++i] != NULL)
	{
		if (la[n]->link[i]->ant == 0 && la[n]->link[best]->step >
			la[n]->link[i]->step && la[n]->link[i]->step != 2147483647)
			best = i;
		if (la[n]->link[i]->end == 1)
		{
			best = i;
			break ;
		}
	}
	if (la[n]->link[best]->ant == 0 || la[n]->link[best]->end == 1)
		make_step(la, n, best);
}

void			move_ants(int ants, t_lemin *l)
{
	int			i;
	t_lemin		**la;
	t_lemin		*end;

	la = get_la(ants, l);
	end = find_end_room(l);
	while (end->ant < ants)
	{
		g_print_flag = 0;
		i = 1;
		while (i <= ants)
		{
			if (la[i]->end == 0)
				next_step(la, i);
			i++;
		}
		ft_putstr("\n");
	}
	free(la);
}
