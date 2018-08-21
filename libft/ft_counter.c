/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:43:53 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:43:54 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_counter(int num)
{
	static int	sum = 0;
	int			ret;

	ret = 0;
	if (num == -1)
	{
		return (ret);
	}
	else if (num == -2)
	{
		ret = sum;
		sum = 0;
	}
	else
		sum = sum + num;
	return (ret);
}
