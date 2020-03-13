/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:31:05 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/27 20:44:42 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 1
# define MAX_LONG 9223372036854775807

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);
long			ft_atol(const char *str);
char			*ft_itoa(int nbr);
char			*ft_itoa_base(int nbr, int base);

void			ft_bzero(void *b, size_t n);
void			*ft_dup(void const *content, size_t content_size);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
unsigned int	ft_strcntfirstchar(char *str, const char *charset);
unsigned int	ft_strcntlastchar(char *str, const char *charset);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcapitalize(char *str);
char			**ft_strsplit(char const *s, char c);

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddend(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstsort(t_list **begin_list, int (*cmp)());
size_t			ft_lstsize(t_list *begin_list);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

int				ft_abs(int nb);
int				ft_sqrt(int nb);
int				ft_isprime(int nb);
long			ft_power(int nb, int power);
size_t			ft_fact(int nb);

void			ft_swap(int *a, int *b);
void			ft_foreach(int *tab, int length, void (*f)(int));

void			ft_sort_bubble(int *arr, int n);
void			ft_sort_quick(int *arr, int low, int high);
void			ft_sort_select(int *arr, int n);

int				get_next_line(const int fd, char **line);

#endif
