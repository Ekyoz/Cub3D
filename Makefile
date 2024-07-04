# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atresall <bpoyet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 12:10:27 by atresall          #+#    #+#              #
#    Updated: 2024/06/06 19:25:32 by atresall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------- NAME --------#
PROJECT_NAME		= "Cube 3D"
NAME				= "cube3d"

#-------- FILES --------#

HEADER_FILES			= cube3d structs define
SRC_FILES		    	= main init loop
TEST_FILES  			=

FILE_PARSER_DIR 	    = parser/
FILE_PARSER 		    = parser

FILE_RAYCASTING_DIR		= raycasting/
FILE_RAYCASTING			= create_rays rays_collisions dda

FILE_RENDER_DIR			= render/
FILE_RENDER				= floor_celling rays_render

FILE_HOOKS_DIR			= hooks/
FILE_HOOKS				= keyboard mouse

FILE_PLAYER_DIR			= player/
FILE_PLAYER				= player move rotate

FILE_COLORS_DIR			= colors/
FILE_COLORS				= lerp rgb

FILE_MATH_DIR			= maths/
FILE_MATH				= vectors deg_rad direction others

DIR_LIST				= $(FILE_PARSER_DIR) $(FILE_RAYCASTING_DIR) $(FILE_HOOKS_DIR) $(FILE_PLAYER_DIR) $(FILE_MATH_DIR) $(FILE_RENDER_DIR) $(FILE_COLORS_DIR)

SRC_FILES			+= $(addprefix $(FILE_PARSER_DIR), $(FILE_PARSER))
SRC_FILES			+= $(addprefix $(FILE_RAYCASTING_DIR), $(FILE_RAYCASTING))
SRC_FILES			+= $(addprefix $(FILE_HOOKS_DIR), $(FILE_HOOKS))
SRC_FILES			+= $(addprefix $(FILE_PLAYER_DIR), $(FILE_PLAYER))
SRC_FILES			+= $(addprefix $(FILE_MATH_DIR), $(FILE_MATH))
SRC_FILES			+= $(addprefix $(FILE_RENDER_DIR), $(FILE_RENDER))
SRC_FILES			+= $(addprefix $(FILE_COLORS_DIR), $(FILE_COLORS))

#-------- LIBS --------#

LIBFT_DIR			= $(INCLUDE_DIR)/LibFT
LIBFT_ARCHIVE		= $(LIBFT_DIR)/libft.a

GNL_DIR				= $(INCLUDE_DIR)/GNL
GNL_ARCHIVE			= $(GNL_DIR)/libgnl.a

MLX_DIR				= $(INCLUDE_DIR)/mlx-mac
MLX_ARCHIVE			= $(MLX_DIR)/libmlx.a

LIB_LIST			= $(LIBFT_DIR) $(GNL_DIR) $(MLX_DIR)
LIB_LIST_ARCHIVE	= $(ARCHIVE_NAME) $(LIBFT_ARCHIVE) $(GNL_ARCHIVE) $(MLX_ARCHIVE)

#-------- FLAGS --------#
CFLAGS 				= -Wall -Wextra -g3
CFLAGS_DEBUG		= -Wall -Wextra -g3
CFLAGS_TEST			= -g3
INCLUDES			= -I$(MLX_DIR)
LIBFLAGS			= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
VFALGS				= -s --leak-check=full --track-origins=yes --show-leak-kinds=all

#------------------------------------------------------------------------------#
#----------------------------- DON'T TOUCH BELOW -----------------------------#
#------------------------------------------------------------------------------#

#-------- NAMES --------#
ARCHIVE_NAME		= $(OUT)/lib$(NAME).a
RUN_NAME			= $(NAME)
DEBUG_NAME 			= $(OUT)/debug.out
TEST_NAME			= $(OUT)/test.out

#-------- DIR --------#

SRC_DIR				= srcs
TEST_DIR 			= test
INCLUDE_DIR			= include
OUT					= .objs

#----RULES DIRS----#
SRC_OUT_DIR			= $(OUT)/run
DEBUG_OUT_DIR		= $(OUT)/debug
TEST_OUT_DIR		= $(OUT)/test

DIRS				= $(SRC_OUT_DIR) $(DEBUG_OUT_DIR) $(TEST_OUT_DIR)
HEADERS				= $(addprefix $(INCLUDE_DIR)/, $(addsuffix .h, $(HEADER_FILES)))

#-------- SETTINGS --------#

CC					= cc
OBJF				= .cache_exists
INCLUDE 			= $(INCLUDES) -I$(INCLUDE_DIR) $(addprefix -I, $(addsuffix /$(INCLUDE_DIR), $(LIB_LIST)))
INCLUDE_RUN			= -L. $(ARCHIVE_NAME)
RM					= rm -rf
AR					= ar rcs
COUNTER				= 0

#-------- COLORS --------#

DEF_COLOR 			= \033[0;39m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
CYAN 				= \033[0;96m
RED 				= \033[0;31m
ORANGE 				= \033[0;33m
WHITE				= \033[0;00m
BOLD				= \033[1m

#-------- OBJECTS RUN --------#

OBJ			 		= $(addprefix $(SRC_OUT_DIR)/, $(addsuffix .o, $(SRC_FILES)))
OBJ_DEBUG			= $(addprefix $(DEBUG_OUT_DIR)/, $(addsuffix .o, $(SRC_FILES)))
OBJ_TEST			= $(addprefix $(TEST_OUT_DIR)/, $(addsuffix .o, $(TEST_FILES)))

$(OBJF):
			@mkdir -p $(DIRS)
			@for dirs in $(DIRS); do \
                    for dir in $(DIR_LIST); do \
                        mkdir -p $$dirs/$$dir; \
                    done; \
                done


define compile_object
			@echo "$(YELLOW)$(BOLD)Compiling: $(WHITE)$< $(DEF_COLOR)"
			@$(CC) $(1) $(INCLUDE) -c $< -o $@
			@printf "\033[A\033[K"
			@touch $@.updated
			$(eval COUNTER=$(shell expr $(COUNTER) + 1))
endef

$(SRC_OUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile | $(OBJF)
			$(call compile_object,$(CFLAGS))

$(DEBUG_OUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile | $(OBJF)
			$(call compile_object,$(CFLAGS_DEBUG))

$(TEST_OUT_DIR)/%.o: $(TEST_DIR)/%.c $(HEADERS) Makefile | $(OBJF)
			$(call compile_object,$(CFLAGS_TEST))

#-------- COMMANDS --------#

$(NAME): archive $(OBJ) $(HEADERS)
			@files=$$(find $(OUT) -name '*.updated'); \
			if [ -n "$$files" ]; then \
				$(CC) $(CFLAGS) $(OBJ) $(INCLUDE_RUN) -o $(RUN_NAME) $(LIBFLAGS); \
				echo "$(CYAN)$(BOLD)$(PROJECT_NAME)$(GREEN) a été compilé avec succès!$(DEF_COLOR) ($(YELLOW)$(BOLD)$(COUNTER)$(DEF_COLOR) $(WHITE)fichiers$(DEF_COLOR))"; \
				rm -f $$files; \
			else \
				echo "$(CYAN)$(BOLD)$(PROJECT_NAME)$(GREEN) est déjà à jour!$(DEF_COLOR)"; \
			fi

all: $(NAME)

lib:
			@for dir in $(LIB_LIST); do make --no-print-directory -C $$dir; done

#-------- RUN ---------#

archive:	lib $(OBJ) $(HEADERS)
			@$(AR) $(ARCHIVE_NAME) $(OBJ)
			@for archive in $(LIB_LIST_ARCHIVE); do ar -x $$archive; done
			@ar -qcs $(ARCHIVE_NAME) *.o
			@rm -rf *.o
			@rm -rf __.*

run: $(NAME)
			./$(RUN_NAME)

valgrind: $(NAME)
			valgrind $(VFALGS) ./$(RUN_NAME)

#------- DEBUG --------#

ar_debug:	lib $(OBJ_DEBUG) $(HEADERS)
			@$(AR) $(ARCHIVE_NAME) $(OBJ_DEBUG)
			@for archive in $(LIB_LIST_ARCHIVE); do ar -x $$archive; done
			@ar -qcs $(ARCHIVE_NAME) *.o
			@$(RM) *.o
			@$(RM) __.*

debug: ar_debug
			@$(CC) $(CFLAGS_DEBUG) $(OBJ_DEBUG) $(INCLUDE_RUN) -o $(DEBUG_NAME) $(LIBFLAGS)
			@echo "$(CYAN)$(BOLD)$(PROJECT_NAME)$(GREEN) a été compilé avec succès en version $(YELLOW)$(BOLD)DEBUG!$(DEF_COLOR)"

#------ TEST ------#

ar_test:	lib $(OBJ_TEST) $(HEADERS)
			@$(AR) $(ARCHIVE_NAME) $(OBJ_TEST)
			@for archive in $(LIB_LIST_ARCHIVE); do ar -x $$archive; done
			@ar -qcs $(ARCHIVE_NAME) *.o
			@$(RM) *.o
			@$(RM) __.*

test: ar_test
			@$(CC) $(CFLAGS_TEST) $(OBJ_TEST) $(INCLUDE_RUN) -o $(TEST_NAME) $(LIBFLAGS)
			@echo "$(CYAN)$(BOLD)$(PROJECT_NAME)$(GREEN) a été compilé avec succès en version $(YELLOW)$(BOLD)TEST!$(DEF_COLOR)"

#-------- CLEAN --------#
re:			fclean all
			@echo "$(GREEN)Nettoyage et recompilage de $(PROJECT_NAME)!$(DEF_COLOR)"
			./$(RUN_NAME)

clean:
			@$(RM) $(DIRS)
			@$(RM) $(OUT)
			@$(RM) $(RUN_NAME)
			@$(RM) $(DEBUG_NAME)
			@$(RM) $(TEST_NAME)
			@$(RM) *.o
			@$(RM) __.*
			@echo "$(ORANGE)Tous les fichier objets de $(CYAN)$(BOLD)$(PROJECT_NAME)$(ORANGE) ont été supprimé!$(DEF_COLOR)"

fclean:		clean
			@echo "$(RED)Tous les fichier executable de $(CYAN)$(BOLD)$(PROJECT_NAME)$(RED) ont été supprimé!$(DEF_COLOR)\n"
			@make clean --no-print-directory -C $(MLX_DIR)
			@for dir in $(LIB_LIST); do make fclean --no-print-directory -C $$dir; done
			@$(RM) $(ARCHIVE_NAME)

.PHONY:		all compile run archive valgrind ar_debug debug ar_test test lib re clean fclean
