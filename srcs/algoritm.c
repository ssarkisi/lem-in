/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:51:03 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/28 12:51:05 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			step_back(t_lemin *l)
{
	l->label = 0;
}

void			finder(t_lemin *l)
{
	int		i;

	i = 0;
	if (l->end == 1 && l->link == NULL)
		return ;
	while (l->link[i] != NULL)
	{
		if (l->link[i]->start == 0 && l->link[i]->label == 0 &&
			l->link[i]->step > (l->step + 1) && l->link[i]->link_count > 1)
		{
			l->link[i]->step = l->step + 1;
			l->link[i]->label = 1;
			finder(l->link[i]);
		}
		else
		{
			l->link[i]->label = 0;
		}
		i++;
	}
	i = 0;
}

void			mark_roads(t_lemin *l)
{
	t_lemin		*end;

	end = find_end_room(l);
	end->step = 0;
	finder(end);
}
