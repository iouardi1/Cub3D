/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achedmi <achedmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:43:29 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/11/06 23:26:48 by achedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LIB_H
# define CUB_LIB_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <float.h>
# include <sys/errno.h>
# define BUFFER_SIZE 13

//extra functionns

int				ft_in_charset(char *str, char *charset);
char			*ft_strchrset(char *str, char *charset);

//libft
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			*ft_realloc(void *ptr, size_t ptr_size, size_t add_size);
int				wc(const char *s, char c);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
unsigned int	ft_atou(const char *str);
unsigned long	ft_atoul(const char *str);
void			ft_bzero(void	*s, size_t	n);
int				ft_toupper( int c);
int				ft_tolower(int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *str, int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(const	char	*s);
size_t			ft_strlcat(char	*dst, const	char	*src, size_t	dstsize);
size_t			ft_strlcpy(char	*dst, const	char	*src, size_t	dstsize);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void	*));
void			ft_lstclear(t_list **lst, void (*del)(void	*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));
//---------------

//get next line
char			*handel_the_shit(char **saved);
char			*free_it(char **target);
char			*handel_the_shit(char **saved);
char			*get_next_line(int fd);
//-------------

#endif