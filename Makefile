CC = cc
CFLAGS = -Wall -Werror -Wextra
USER = $(shell whoami)
NAME = so_long

SOURCES = ./sources/so_long.c ./sources/valid_map_check.c ./sources/valid_map_check2.c ./sources/utils.c ./sources/game_funcs.c \
		./sources/game_hooks.c ./sources/graphics.c ./sources/movement.c

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

OBJECTS = $(SOURCES:.c=.o)


all: MLX42 $(NAME)

$(NAME) : $(OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) ./libs/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42: brew-install
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

brew-install:
	@if ! command -v brew >/dev/null ; then \
		/bin/bash -c "$$(curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh)" ; \
	fi

clean:
	@rm -rf MLX42
	@cd libs && make fclean
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

