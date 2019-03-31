NAME = game

all: install

install:
	gcc  -I /usr/local/include \
		src/maincode/main.c \
		src/maincode/img.c \
		src/maincode/drawland.c \
		src/maincode/keyactions.c \
		src/maincode/load_levels.c \
		src/funcs/itoa.c \
		src/maincode/menu.c \
		src/maincode/bullet.c \
		minilibx_macos/libmlx.a \
		-L /usr/local/lib \
		-framework OpenGL \
		-framework Appkit \
		-o $(NAME)
uninstall:
	rm -rf *.o
clean: uninstall
	rm -rf $(NAME)
reinstall: uninstall install
