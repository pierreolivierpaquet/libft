/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:46:35 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:33:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // printf()
# include <stdbool.h>

///	------------------------------------------------------- @section LINKED LIST

/// @brief Generic doubly linked list.
typedef struct s_dlist
{
	void			*content;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

///	@brief Generic linked list.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

///	@brief Garbage collector function (prototype).
typedef t_dlist	*(*t_gc)(void *, size_t n);

t_list	*ft_lstnew(void *content, t_gc func);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

///	------------------------------------------------- @section MEMORY ALLOCATION

///	@brief	Freeing (NULL safe) function pointer.
typedef void	*(*t_free)(void **, size_t size, bool track);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(void **to_free, size_t size, bool track);

/// @brief Type of memory allocation.
typedef enum e_alloc_type
{
	CALLOC,
	MALLOC
}	t_alloc_type;

# ifndef TRY_ALLOC
#  define TRY_ALLOC	10000
# endif

void	*ft_alloc(t_alloc_type type, size_t count, size_t size, t_gc func);
t_dlist	*ft_gc(void *newly_allocated, size_t size);
void	*ft_gc_destroy( void );

t_dlist	*ft_dlstnew(void *content, size_t size, t_gc func);
t_dlist	*ft_dlstlast(t_dlist *from);
t_dlist	*ft_dlstfirst(t_dlist *from);
size_t	ft_dlstsize(t_dlist	*from);
t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new_node);
t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new_node);

void	*ft_dlstdel_one(t_dlist **delete, t_free func);
void	*ft_dlst_detach(t_dlist **head, t_dlist *detach, t_free func);
void	ft_dlst_clear(t_dlist **head, t_free func);

///	----------------------------------------------------- @section ALPHA-NUMERIC

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, t_gc func);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_gc func);
char	*ft_strjoin(char const *s1, char const *s2, t_gc func);
char	*ft_strtrim(char const *s1, char const *set, t_gc func);
char	**ft_split(char const *s, char c, t_gc func);
char	*ft_itoa(int n, t_gc func);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char), t_gc func);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
