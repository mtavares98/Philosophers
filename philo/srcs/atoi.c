/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:24:02 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:41:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = -1;
	while ((str[++i] > 8 && str[i] < 14) || str[i] == 32)
		;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (0);
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	while (str[i] && ((str[i] > 8 && str[i] < 14) || str[i++] == 32))
		;
	if (str[i])
		return (0);
	return (num);
}
