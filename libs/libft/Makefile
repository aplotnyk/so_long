# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 16:05:40 by aplotnyk          #+#    #+#              #
#    Updated: 2024/02/25 19:13:37 by aplotnyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = 	libft/libft.h \
			get_next_line.h \
			ft_printf.h

SRC_DIR = libft
OBJ_DIR = obj

SRC_FILES = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line_bonus.c \
	ft_putchar.c \
	ft_putptr.c \
	ft_putunsint.c \
	ft_printf.c \
	ft_puthex.c \
	ft_putstr.c	\
	ft_putnbr.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# OBJECTS = obj/$(SOURCES_LIBFT:.c=.o)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# .c.o:
# 	cc $(CFLAGS) -c -I $< -o ${<:.c=.o}
	
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
