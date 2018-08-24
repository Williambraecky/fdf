/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 08:10:53 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/24 16:44:43 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include "get_next_line.h"

# define LIB_CHAR_BIT 8
# define LIB_SCHAR_MIN -128
# define LIB_SCHAR_MAX 127
# define LIB_UCHAR_MAX 255
# define LIB_CHAR_MIN -128
# define LIB_CHAR_MAX 127
# define LIB_MB_LEN_MAX 16
# define LIB_SHRT_MIN -32768
# define LIB_SHRT_MAX 32767
# define LIB_USHRT_MAX 65535
# define LIB_INT_MIN -2147483648
# define LIB_INT_MAX 2147483647
# define LIB_UINT_MAX 4294967295
# define LIB_LONG_MIN -9223372036854775808L
# define LIB_LONG_MAX 9223372036854775807L
# define LIB_ULONG_MAX 18446744073709551615L

typedef struct s_list	t_list;
struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

void		*ft_arg_at(va_list list, size_t pos);

float		ft_ilerp(float start, float end, float target);
float		ft_lerp(float start, float end, float percent);

t_list		*ft_lstnew(const void *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *n);
void		ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_lstpushback(t_list **alst, const void *content,
		size_t content_size);
t_list		*ft_lstlast(t_list **alst);
void		ft_lstremoveif(t_list **alst, void *data_ref,
		int (*cmp)());
size_t		ft_lstlen(t_list *list);

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *b, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t t);
void		ft_memdel(void **ap);
void		ft_memswap(void *a, void *b, size_t len);

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t len);
size_t		ft_strlcat(char *s1, const char *s2, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strsub(const char *s1, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1);
char		**ft_strsplit(const char *s, char c);
void		ft_strrepl(char *str, char find, char repl);
size_t		ft_strfind(const char *str, char c);
char		*ft_strtoupper(char *str);
char		*ft_strtolower(char *str);
int			ft_strstartswith(const char *str, const char *find);
char		*ft_strshift(char *str, int shift);
char		*ft_strrev(char *str);
size_t		ft_splitlen(char **split);
int			ft_strisnumber(char *str);

void		ft_putchar_fd(int c, int fd);
void		ft_putchar(int c);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putstr(const char *str);
void		ft_putendl_fd(const char *str, int fd);
void		ft_putendl(const char *str);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
void		ft_putnstr_fd(const char *str, size_t len, int fd);
void		ft_putnstr(const char *str, size_t len);
void		ft_putnchar_fd(int c, int fd, size_t amount);
void		ft_putnchar(int c, size_t amount);

int			ft_atoi(const char *str);
char		*ft_itoa_base(ssize_t value, size_t basesize);
char		*ft_itoa(ssize_t n);
char		*ft_uitoa_base(size_t value, size_t basesize);
char		*ft_uitoa(size_t value);
char		ft_itoc_base(ssize_t value, size_t basesize);
char		ft_itoc(ssize_t value);
size_t		ft_intlen_base(ssize_t value, size_t basesize);
size_t		ft_intlen(ssize_t value);
size_t		ft_uintlen_base(size_t n, size_t basesize);
size_t		ft_uintlen(size_t n);
int			*ft_range(int min, int max);
int			ft_intmin(int len, ...);
int			ft_intmax(int len, ...);
int			ft_min(int i, int j);
int			ft_max(int i, int j);
int			ft_abs(int i);
void		ft_swapshort(short *a, short *b);
void		ft_swapint(int *a, int *b);
void		ft_swaplong(long *a, long *b);

int			ft_isalpha(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
void		ft_swapchar(char *c, char *d);

#endif
