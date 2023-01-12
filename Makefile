NAME							=	cub3D

MANDATORY_SRCS_PATH				=	mandatory

MANDATORY_INCLUDES_PATH			=	mandatory/includes

IHSAN_VPATH						=	${MANDATORY_SRCS_PATH}/ihsan

KARIM_VPATH						=	${MANDATORY_SRCS_PATH}/karim

VPATH							=	${MANDATORY_SRCS_PATH} ${MANDATORY_INCLUDES_PATH} ${IHSAN_VPATH} ${KARIM_VPATH}

CC								=	cc

CFLAGS							=	-Wall -Wextra -Werror

DBGFLAGS						=	-g -fsanitize=address

MLXFLAGS						=	-framework OpenGL -framework AppKit

RM								=	rm -rf

LIBS							=	Lib/cub_lib.a Lib/libmlx.a

M_INCLUDES						=	$(addprefix ${MANDATORY_INCLUDES_PATH}/, cub.h global_includes.h settings.h ihsan.h)

IHSAN_SRCS						=	parsing1.c \
									parsing.c \
									parsing2.c \
									parsing3.c \
									parsing4.c \
									parsing5.c


KARIM_SRCS						=	envirement.c\
									keys_handlers.c\
									to_3d.c\
									mlx_init.c\
									movements.c\
									rotation.c\
									tools.c\
									ray_casting.c\
									ray_casting1.c\
									wall_building_tools.c


MANDATORY_SRCS					=	main.c ${IHSAN_SRCS} ${KARIM_SRCS}

MANDATORY_OBJS					=	$(addprefix M_OBJs/, $(MANDATORY_SRCS:.c=.o))

all:							${NAME}

${NAME}:						${MANDATORY_OBJS} ${M_INCLUDES}

								@$(MAKE) -C ./lib
								$(CC) ${CFLAGS} ${MLXFLAGS} ${LIBS} ${MANDATORY_OBJS} -o ${NAME}


M_OBJs/%.o :					%.c ${M_INCLUDES}

								@mkdir -p M_OBJs
								$(CC) ${CFLAGS} -c $< -o $@



re: fclean all


fclean:		clean
			@${RM} ${NAME}
			@$(MAKE) fclean -C ./Lib

clean:
			@${RM} ${MANDATORY_OBJS}


.PHONY:	clean fclean re