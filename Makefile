
HEP = helpers/

MGR = manage_graphics/

MAS = manage_assets/

SRCS = main.c ${MGR}map.c ${MGR}put_images.c ${MGR}get_width_height.c \
	${MGR}display_string.c ${MGR}define_images.c  \
	${HEP}display_msg.c ${HEP}str_functions.c ${HEP}ft_strcmp.c \
	${HEP}ft_split.c ${HEP}ft_itoa.c ${MAS}player_moves.c ${MAS}enemy_moves.c

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -Imlx -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : re clean all
