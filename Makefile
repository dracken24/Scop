# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:22:35 by nadesjar          #+#    #+#              #
#    Updated: 2023/02/08 04:47:25 by nadesjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VULKAN_SDK_PATH			= /home/dracken24/Documents/Vulkan/x86_64
STB_INCLUDE_PATH		= /home/dracken24/Documents/myPackages/stb
TINYOBJ_INCLUDE_PATH 	= /home/dracken24/Documents/myPackages/vcpkg/packges/tinyobjloader_x64-linux

P_OBJS 			= ./objs/
P_SRCS			= ./srcs/
P_CLASS			= ./srcs/class/

FILES			= $(P_SRCS)main.cpp \

OBJS			= $(patsubst $(P_SRCS)%.cpp, $(P_OBJS)%.o, $(FILES))

CC				= c++

CFLAGS			= -Wall -Wextra -Werror -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -std=c++17

# CFLAGS			= -std=c++17 -g -I$(VULKAN_SDK_PATH)/include -I$(STB_INCLUDE_PATH) -I$(TINYOBJ_INCLUDE_PATH) \
# 				-Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable

LDFLAGS			= -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo
# LDFLAGS 		= -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

NAME			= DrackenLib

# ------------------------------- Compilation -------------------------------- #

all: signat msg_in $(NAME) msg_out execute

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) /Users/nadesjar/Desktop/prog/42_en_cours/Scop/lib/glfw/include -o $(NAME) $(OBJS) $(LDFLAGS) 

$(P_OBJS)%.o:	$(P_SRCS)%.cpp
	@mkdir -p $(P_OBJS)
	@$(CC) $(CFLAGS) -I. -c $< -o $@ $(LDFLAGS)
	@printf "$G■"

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
	@echo $L"COMPILATION DE DrackenLib EN COURS..."$W

msg_out:
	@echo $L"\nDrackenLib READY !!!\n"$W

signat:
	@echo "$G\n\|/~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~\|/"
	@echo " |             ---------------------------------------------             |"
	@echo " |             *--*  $LPROJET: DrackenLib  PAR: NADESJAR$G  *--*             |"
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