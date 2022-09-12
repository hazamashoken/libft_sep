# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 10:06:54 by tliangso          #+#    #+#              #
#    Updated: 2022/09/12 20:13:54 by tliangso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC	=	./

SRC		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
			ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c

EXTRA	=

SRCS	= ${addprefix ${DIRSRC}, ${SRC}}

BONUS_SRCS = ${addprefix ${DIRSRC}, ${BONUS}}

EXTRA_SRCS = ${addprefix ${DIRSRC}, ${EXTRA}}

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

EXRTA_OBJS = ${EXTRA_SRCS:.c=.o}

HEAD	= .

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
			ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

extra:	${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS}
			ar rc ${NAME} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

.PHONY:		all	clean	fclean	re
