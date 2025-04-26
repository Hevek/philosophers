/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:57:04 by restevez          #+#    #+#             */
/*   Updated: 2025/04/26 04:22:19 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define PHILO_H

/* Helpers */
# define FALSE			0
# define TRUE			0
/* Possible Actions */
# define THINK			'T'
# define EAT			'E'
# define SLEEP			'S'
/* States */
# define ALIVE			'alive'
# define DEAD			'deceased'

/* A magic table.
Holds the list of forks (table->forks),
and the list of knights (table->knights).
Also, is responsible for making the decisions
of who's worthy enough to pick up the forks. */
typedef struct s_table	t_table;
struct s_table
{
	t_forks				**forks;
	t_forks				**knights;
};

/* <Place explanation here> */
typedef struct s_forks	t_forks;
struct s_forks
{
	pthread_mutex_t		mutex;
};

/* <Place explanation here> */
typedef struct s_philo	t_philo;
struct s_philo
{
	size_t				id;
	size_t				last_ate;
	char				action;
};

/* Allowed Functions:

void *memset(void *s, int c, size_t n);

int printf(const char *format, ...);

void *malloc(size_t size);

void free(void *ptr);

ssize_t write(int fildes, const void *buf, size_t nbyte);

int usleep(useconds_t usec);

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
							void *(*start_routine) (void *), void *arg);

int pthread_detach(pthread_t thread);

int pthread_join(pthread_t thread, void **retval);

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
			const pthread_mutexattr_t *restrict attr);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);
*/

/* Created functions prototypes */
long long	get_current_time(void);

#endif
