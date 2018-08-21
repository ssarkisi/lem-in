/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notnumbercount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:43:04 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/11 15:43:05 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_notnumbercount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			count++;
		i++;
	}
	return (count);
}
