NAME							=	cub3D

NAME_BONUS						=	cub3D_bonus

MANDATORY_SRCS_PATH				=	mandatory

BONUS_SRCS_PATH					=	bonus

MANDATORY_INCLUDES_PATH			=	mandatory/includes

BONUS_INCLUDES_PATH				=	bonus/includes

ihsan_VPATH					=	${MANDATORY_SRCS_PATH}/ihsan

ihsan_VPATH_BONUS				=	${BONUS_SRCS_PATH}/ihsan

KARIM_VPATH						=	${MANDATORY_SRCS_PATH}/karim

KARIM_VPATH_BONUS				=	${BONUS_SRCS_PATH}/karim

VPATH							=	${MANDATORY_SRCS_PATH} ${MANDATORY_INCLUDES_PATH} ${ihsan_VPATH} ${KARIM_VPATH} ${BONUS_SRCS_PATH} ${BONUS_INCLUDES_PATH} ${ihsan_VPATH_BONUS} ${KARIM_VPATH_BONUS}

CC								=	cc

CFLAGS							=	-Wall -Wextra -Werror #${DBGFLAGS}

DBGFLAGS						=	-g -fsanitize=address

MLXFLAGS						=	-framework OpenGL -framework AppKit

RM								=	rm -rf

LIBS							=	Lib/cub_lib.a Lib/libmlx.a

M_INCLUDES						=	$(addprefix ${MANDATORY_INCLUDES_PATH}/, cub.h global_includes.h settings.h parsing.h)

B_INCLUDES						=	$(addprefix ${BONUS_INCLUDES_PATH}/, cub_bonus.h global_includes_bonus.h settings_bonus.h parsing_bonus.h)

ihsan_SRCS					=	parsing.c \
								# ray_casting.c \
								utils.c \
								parsing_texures.c \
								parse_map_utils.c \
								ray_casting_utils.c \
								parsing_textures_utiles.c

KARIM_SRCS						=	envirement.c\
									keys_handlers.c\
									to_3d.c\
									mlx_init.c\
									movements.c\
									rotation.c\
									tools.c\
									wall_building_tools.c

ihsan_SRCS_BONUS				=	parsing_bonus.c \
									# ray_casting_bonus.c \
									# utils_bonus.c \
									# parsing_texures_bonus.c \
									# parse_map_utils_bonus.c \
									# ray_casting_utils_bonus.c \
									# parsing_textures_utiles_bonus.c

KARIM_SRCS_BONUS				=	envirement_bonus.c\
									keys_handlers_bonus.c\
									to_3d_bonus.c\
									mlx_init_bonus.c\
									movements_bonus.c\
									rotation_bonus.c\
									tools_bonus.c\
									wall_building_tools_bonus.c


MANDATORY_SRCS					=	main.c ${ihsan_SRCS} ${KARIM_SRCS}

MANDATORY_OBJS					=	$(addprefix M_OBJs/, $(MANDATORY_SRCS:.c=.o))

BONUS_SRCS						=	main_bonus.c ${ihsan_SRCS_BONUS} ${KARIM_SRCS_BONUS}

BONUS_OBJS						=	$(addprefix B_OBJs/, $(BONUS_SRCS:.c=.o))




all:							${NAME}

${NAME}:						${MANDATORY_OBJS} ${M_INCLUDES}

								@$(MAKE) -C ./lib
								$(CC) ${CFLAGS} ${MLXFLAGS} ${LIBS} ${MANDATORY_OBJS} -o ${NAME}


M_OBJs/%.o :					%.c ${M_INCLUDES}

								@mkdir -p M_OBJs
								$(CC) ${CFLAGS} -c $< -o $@





bonus:							${NAME_BONUS}

${NAME_BONUS} :					${BONUS_OBJS} ${B_INCLUDES}
								@$(MAKE) -C ./lib
								$(CC) ${CFLAGS} ${MLXFLAGS} ${LIBS} ${BONUS_OBJS} -o ${NAME_BONUS}

B_OBJs/%.o :					%.c ${B_INCLUDES}

								@mkdir -p B_OBJs
								$(CC) ${CFLAGS} -c $< -o $@


#*cleaning rules
re: fclean all

re_bonus: fclean bonus

fclean:		clean
			@${RM} ${NAME_BONUS}
			@${RM} ${NAME}
			@$(MAKE) fclean -C ./Lib

clean:
			@${RM} ${BONUS_OBJS}
			@${RM} ${MANDATORY_OBJS}


.PHONY:	clean fclean re re_bonus