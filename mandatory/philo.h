/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:58:01 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/20 11:07:36 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				all_ate;
	int				died;
	long long		time_start;
	pthread_t		doc;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	struct s_philos	*philos;
}				t_data;

typedef struct s_philos
{
	int				id;
	int				times_eaten;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	arceus;
	t_data			*data;
}				t_philos;

/* ------ft_fnctns------ */
int					ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
int					check_num(char **argv);
long long			get_time(void);

/* ------inits------ */
t_philos			*philo_init(t_data *data);
int					structs_init(t_data *data, int argc, char **argv);
pthread_mutex_t		*forks_init(int num_philo);

/* ------mutex------ */
void				mutex_init(pthread_mutex_t *mutex);
void				mutex_destroy(pthread_mutex_t *mutex);
void				mutex_lock(pthread_mutex_t *mutex);
void				mutex_unlock(pthread_mutex_t *mutex);

/* ------utils------ */
int					error_message(char c);
int					verifs(t_data *d);
int					verifs2(t_data *d);
void				print_msg(char *msg, t_philos *p);
void				print_error(char *str);

/* ------routine------ */
void				*ft_routine(void *arg);
int					grab_forks(t_philos *philos);
int					eating(t_philos *phi);
int					sleeping(t_philos *phi);
int					thinking(t_philos *philos);

/* ------mntrng------ */
void				*ft_doc_watch(void *arg);
int					check_philo_dead(t_data *data);
int					check_philo_ate(t_data *data);

/* ------thread------ */
void				ft_thread(t_data *data);
void				ft_thread_join(t_data *data);

#endif
