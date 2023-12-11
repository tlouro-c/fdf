/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:51:39 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/08 14:08:55 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define HEX 16
# define OCT 8
# define BIN 2

/* -------------------------------------------------------------------------- */
/*                               "is" functions                               */
/* -------------------------------------------------------------------------- */

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);
int				ft_isspace(int c);

/* -------------------------------------------------------------------------- */
/*                               "to" functions                               */
/* -------------------------------------------------------------------------- */

int				ft_tolower(int c);
int				ft_toupper(int c);

/* -------------------------------------------------------------------------- */
/*                              "utils" functions                             */
/* -------------------------------------------------------------------------- */

unsigned int	ft_rand(void);
void			ft_swap(int *a, int *b);
int				ft_abs(int n);

/* -------------------------------------------------------------------------- */
/*                             "sorting" functions                            */
/* -------------------------------------------------------------------------- */

void			ft_quick_sort(int *array, int size);

/* -------------------------------------------------------------------------- */
/*                             "string" functions                             */
/* -------------------------------------------------------------------------- */

size_t			ft_strlen(const char *s);
char			*ft_strrev(char *s);
char			*ft_strrchr(const char *s, int c);
int				ft_count_words(char const *s, int sep);
char			**ft_split(char const *s, int sep);
int				ft_putstr_fd(char *s, int fd);
int				ft_putchar(int c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);

/* -------------------------------------------------------------------------- */
/*                              "free" functions                              */
/* -------------------------------------------------------------------------- */

char			**ft_free_str_arr(char **array, int size);
char			*ft_free_str_return(char *s);

/* -------------------------------------------------------------------------- */
/*                        "ft_get_next_line function"                        */
/* -------------------------------------------------------------------------- */

char			*ft_get_next_line(int fd);

void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);

int				ft_atoi(const char *s);
long			ft_atol(const char *s);

float			ft_rad(float deg);

char			*ft_itoa(int value, char *buffer, int base);

int				ft_mini_printf(const char *format, ...);

#endif /* LIBFT_H */
