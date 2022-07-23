/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:04:04 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/24 00:07:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef unsigned long	t_lu;
typedef struct s_gen	t_gen;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_gen
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_time_to_eat;
	int			have_last_arg;
};

struct s_philo
{
	pthread_mutex_t	*mutex;
	pthread_t		philo;
	int				id;
	int				*is_dead;
	t_gen			*gen;
	t_table			*table;
};

struct s_table
{
	int	id;
	int	fork;
};

t_lu	get_time(t_lu start);
void	thread_creation(t_philo *p);
int		check_num_times_to_eat(t_gen gen);
void	eating(t_philo *philo, t_lu start, int is_taken);
t_table	*create_table(int philo_num);
t_table	*create_table(int philo_num);
t_gen	create_gen(int ac, char **av);
t_philo	*create_philo(t_gen *gen, t_table *table, pthread_mutex_t *mutex, \
int *is_dead);
int		ft_atoi(char *str);

#endif