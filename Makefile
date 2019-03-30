NAME = game

all: install

install:
	gcc  -I /usr/local/include \
		main.c \
		img.c \
		drawland.c \
		keyactions.c \
		load_levels.c \
		itoa.c \
		menu.c \
		bullet.c \
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
