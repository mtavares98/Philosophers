/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:03:30 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/03 18:04:40 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philo *p, char *str, int is_eating)
{
	printf("%lu %i %s\n", get_time(p, is_eating), p->id, str);
}
