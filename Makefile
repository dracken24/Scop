# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 09:13:13 by dracken24         #+#    #+#              #
#    Updated: 2023/02/08 11:51:39 by dracken24        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS),Windows_NT)
    TARGET = windows
else ifeq ($(shell uname), Darwin)
   	TARGET = mac
else
    TARGET = linux
endif

# ------------------------------- Variables --------------------------------- #

INCLUDE_PATH	= ./includes/

P_OBJS 			= ./objs/
P_SRCS			= ./srcs/
P_CLASS			= ./srcs/class/

FILES			= $(P_SRCS)main.cpp \
				$(P_CLASS)Scop.cpp \
				$(P_CLASS)Mesh.cpp \
				$(P_CLASS)Texture.cpp \
				$(P_SRCS)others/keyGestion.cpp \

OBJS			= $(patsubst $(P_SRCS)%.cpp, $(P_OBJS)%.o, $(FILES))

CC				= c++

NAME			= Scop

# ------------------------------- Compilation -------------------------------- #

all: signat msg_in $(TARGET) $(NAME) msg_out execute

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

# ---------------------------- Recompile Headers ----------------------------- #

$(P_OBJS)main.o: $(P_SRCS)main.cpp $(INCLUDE_PATH)class/Scop.hpp
	@mkdir -p $(P_OBJS)
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"
	
$(P_OBJS)class/Scop.o: $(P_SRCS)class/Scop.cpp $(INCLUDE_PATH)class/Scop.hpp
	@mkdir -p $(P_OBJS)class
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

$(P_OBJS)class/Mesh.o: $(P_SRCS)class/Mesh.cpp $(INCLUDE_PATH)utils.hpp
	@mkdir -p $(P_OBJS)class
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

$(P_OBJS)class/Texture.o: $(P_SRCS)class/Texture.cpp $(INCLUDE_PATH)utils.hpp
	@mkdir -p $(P_OBJS)class
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

$(P_OBJS)others/keyGestion.o: $(P_SRCS)others/keyGestion.cpp $($(INCLUDE_PATH)utils.hpp $(INCLUDE_PATH)class/Scop.hpp)
	@mkdir -p $(P_OBJS)others
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

# --------------------------------- Init IOS --------------------------------- #

windows:
    # Commands to build for Windows

mac:
CFLAGS	= -Wall -Wextra -Werror -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -std=c++17 -g \
		-lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

linux:
CFLAGS	= -Wall -Wextra -Werror -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -std=c++17 -g \
		-lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

# --------------------------------- Execute ---------------------------------- #

execute:
	@./$(NAME)

# ----------------------------------- Git ------------------------------------ #

COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

# --------------------------------- Messages --------------------------------- #

msg_in:
	@echo $L"COMPILATION DE Scop EN COURS..."$W

msg_out:
	@echo $L"\nScop READY !!!\n"$W

signat:
	@echo "$G\n\|/~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~\|/"
	@echo " |             ---------------------------------------------             |"
	@echo " |             *--*    $LPROJET:Scop     PAR: NADESJAR$G    *--*             |"
	@echo " |             ---------------------------------------------             |"
	@echo "/|\~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~/|\ \n$W"
	
# ---------------------------------- Colors ---------------------------------- #

L	= $(shell tput -Txterm setaf 5)
R	= $(shell tput -Txterm setaf 1)
G	= $(shell tput -Txterm setaf 2)
C	= $(shell tput -Txterm setaf 6)
W	= $(shell tput -Txterm setaf 7)

# ---------------------------------- Clean ----------------------------------- #

clean:	
	@rm -fr $(P_OBJS)

fclean: clean
	@echo $G"                                    BYE BYE !!!"$W
	@rm -f $(NAME)

re: fclean all

.PHONY: all msg_in msg_out clean fclean re signat git execute
