/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:06:48 by imhaimou          #+#    #+#             */
/*   Updated: 2018/05/15 01:06:59 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int b);
int					ft_count_word(char *s, char c);
int					ft_len_base(long long nb, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);
int					ft_size(char *str, char c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
size_t				ft_strlen(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, char *src, int nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, char *to_find, size_t n);
char				*ft_strrchr(const char *s, int c);
int					ft_space(int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_trim_space(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *s1);
void				print_hex(int nb);
void				sort_int_tab(int *tab, unsigned int size);
void				revwstr(char *s);
int					pgcd(int a, int b);
int					get_next_line(const int fd, char **line);

#endif
