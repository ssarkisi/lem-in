/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_d_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:44:20 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/03/13 14:44:21 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_d_data(t_data *d)
{
	int		i;

	i = 0;
	while (d->data != NULL && d->data[i] != NULL)
	{
		free_line(d->data[i]);
		i++;
	}
	free_line(d->data[i]);
	free(d->data);
}

void			free_line(char *line)
{
	if (line && line != NULL)
		free(line);
}

void			free_all(t_lemin *l, t_data *d, char *line)
{
	free_t_lemin(l);
	free_t_data(d);
	free_line(line);
}

void			realloc_d_data(t_data *d, char *line)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	while (d->data != NULL && d->data[++i] != NULL)
		i++;
	ret = (char**)(malloc(sizeof(char*) * (i + 2)));
	i = -1;
	while (d->data != NULL && d->data[++i] != NULL)
	{
		j = -1;
		ret[i] = malloc(sizeof(char) * (ft_strlen(d->data[i]) + 1));
		while (d->data[i][++j] != '\0')
			ret[i][j] = d->data[i][j];
		ret[i][j] = '\0';
	}
	j = -1;
	ret[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[++j] != '\0')
		ret[i][j] = line[j];
	ret[i][j] = '\0';
	ret[i + 1] = NULL;
	free_d_data(d);
	d->data = ret;
}
