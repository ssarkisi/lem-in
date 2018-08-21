/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:28:41 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/03/13 14:28:42 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_t_data(t_data *d)
{
	int		i;

	i = 0;
	if (d != NULL)
	{
		while (d->data[i] != NULL)
		{
			free_line(d->data[i]);
			i++;
		}
		free_line(d->data[i]);
		free(d->data);
		free(d);
	}
}

t_data			*get_t_data(void)
{
	t_data		*d;

	d = (t_data*)malloc(sizeof(t_data));
	d->data = malloc(sizeof(char*) * 1);
	d->data[0] = NULL;
	return (d);
}

void			print_d_data(t_data *d)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (d && d->data != NULL)
		while (d->data[n] != NULL)
			n++;
	if (d && d->data != NULL)
	{
		while (n > (i + 1))
		{
			ft_putstr(d->data[i]);
			ft_putstr("\n");
			i++;
		}
		if (check_line2(d->data[i], d) == 4 || check_line2(d->data[i], d) == 5)
			printf("%s\n", d->data[i]);
		ft_putstr("\n");
	}
}
