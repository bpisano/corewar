/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:53:56 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:11:58 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>

# define BUFF_SIZE 2

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strrealloc(char *ptr, size_t size);
void				ft_strdel(char	**as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *c));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_str_is_empty(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_abs(const int n);
int					ft_sqrt(unsigned int n);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isgraph(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isxdigit(int c);
char				*ft_itoa_base(int ni, int base);
int					ft_str_is_alpha(char const *s);
int					ft_str_is_lowercase(char const *s);
int					ft_str_is_numeric(char const *s);
int					ft_str_is_printable(char const *s);
int					ft_str_is_uppercase(char const *s);
char				*ft_strcapitalize(char *s);
int					ft_strcasecmp(char const *s1, char const *s2);
char				*ft_strcasestr(char const *haystack, char const *needle);
size_t				ft_strlcpy(char *dst, char const *src, size_t size);
char				*ft_strlowcase(char *s);
char				*ft_strndup(char const *s, size_t n);
int					ft_strncasecmp(char const *s1, char const *s2, size_t n);
char				*ft_strupcase(char *s);
void				ft_lst_push_back(t_list **lst, t_list *new);
t_list				*ft_lstpopi(t_list **lst, unsigned int index);
t_list				*ft_lstat(t_list **lst, unsigned int index);
int					ft_lstlen(t_list *lst);
char				*ft_strset(char c, size_t size);
char				*ft_ctos(char c);
void				ft_putwchar(wchar_t c);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwstr(wchar_t *str);
void				ft_putwstr_fd(wchar_t *str, int fd);
size_t				ft_wcharlen(wint_t c);
size_t				ft_wstrlen(const wchar_t *str);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrset(wchar_t c, size_t size);
wchar_t				*ft_wctos(wchar_t c);
wchar_t				*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2);
wchar_t				*ft_wstrcat(wchar_t *s1, const wchar_t *s2);
wchar_t				*ft_wstrcpy(wchar_t *dst, const wchar_t *src);
wchar_t				*ft_wstrdup(const wchar_t *s1);
wchar_t				*ft_wstrsub(const wchar_t *s1, unsigned int start,
		size_t size);
wchar_t				*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len);
void				ft_wstrdel(wchar_t **as);
wchar_t				*ft_strtowchr(const char *str);
int					get_next_line(const int fd, char **line);
size_t				ft_tablen(char **tab);
int					ft_printf(const char *restrict format, ...);

#endif
