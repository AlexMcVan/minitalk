# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 15:17:59 by amarie-c          #+#    #+#              #
#    Updated: 2021/12/10 15:41:39 by amarie-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client

SERVER	=	server

SRC_CLIENT = client.c

SRC_SERVER = server.c

HEADER	=	minitalk.h

OBJS_CLIENT	=	${SRC_CLIENT:.c=.o}
OBJS_SERVER=	${SRC_SERVER:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

all:		${SERVER} ${CLIENT}

.c.o:		${CC} ${CFLAGS} -c $< o ${<:.c=.o}

${CLIENT}:	${OBJS_CLIENT} ${HEADER}
				${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT}

${SERVER}:	${OBJS_SERVER} ${HEADER}
				${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER}

clean:	
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean:		clean
			${RM} ${CLIENT} ${SERVER}

re:			fclean all

.PHONY:		all bonus clean fclean re