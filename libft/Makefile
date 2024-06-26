# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:45:50 by ppaquet           #+#    #+#              #
#    Updated: 2024/05/05 16:17:28 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar crs

SRCS = \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_tolower.c \
ft_toupper.c \
\
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_putendl_fd.c \
ft_itoa.c \
ft_striteri.c \
ft_strmapi.c \
ft_split.c \
\
ft_alloc.c \
ft_dlstnew.c \
ft_dlstlast.c \
ft_dlstfirst.c \
ft_dlstsize.c \
ft_dlstadd_back.c \
ft_dlstadd_front.c \
ft_dlstdel_one.c \
ft_dlst_detach.c \
ft_dlst_clear.c \
ft_free.c \

SRCS_BONUS = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS_BONUS)

$(OBJS_BONUS):
	$(CC) $(CFLAGS) -c $(SRCS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re