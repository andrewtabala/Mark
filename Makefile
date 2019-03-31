NAME = game

all: install

install:
	gcc 	-fsanitize=address -g \
		 -I /usr/local/include \
	     -I /Users/ikovalenko/Library/Frameworks/SDL2.framework/Headers \
	     -I /Users/ikovalenko/Library/Frameworks/SDL2_mixer.framework/Headers \
	     -F/Users/ikovalenko/Library/Frameworks \
		-framework SDL2 \
		-framework SDL2_mixer \
		src/maincode/main.c \
		src/maincode/drawland.c \
		src/maincode/keyactions.c \
		src/maincode/load_levels.c \
		src/funcs/itoa.c \
		src/maincode/menu.c \
		src/maincode/bullet.c \
		src/maincode/textinitialize.c \
		src/maincode/init.c \
		src/maincode/move.c \
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
