
NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

OBJS_DIR = .obj/
OBJS_BONUS_DIR = $(OBJS_DIR)checker/
SRC_DIR = src/
LIBFT_DIR = $(SRC_DIR)libft/
PS_DIR = $(SRC_DIR)push_swap/
CHECKER_DIR = $(SRC_DIR)checker/

SRCS = push_swap.c arg_checker.c stack_free.c stack_utils.c swap.c rotate.c push.c \
		reverse_rotate.c find.c get_cheapest.c sort.c init.c stack_a.c stack_b.c \
		moves.c

SRCS_BONUS = checker.c 

HEADERS = ./src/libft/include/libft.h ./src/libft/include/ft_printf.h \
		./src/libft/include/get_next_line.h include/push_swap.h \

HEADERS_BONUS = ./src/libft/include/libft.h ./src/libft/include/ft_printf.h \
		./src/libft/include/get_next_line.h include/push_swap.h include/checker.h \

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(SRCS_BONUS:.c=.o))

.SILENT : 

all : libft obj $(NAME)

bonus : libft obj obj_bonus $(BONUS)

obj : 
	@mkdir -p $(OBJS_DIR)

obj_bonus :
	@mkdir -p $(OBJS_BONUS_DIR)

libft : 
	@make --no-print-directory -C $(LIBFT_DIR)	

$(BONUS) : $(OBJS_BONUS)
	@echo "$(Red)Check de la norme :${NC}"
# @norminette $(CHECKER_DIR) $(HEADERS)
	@echo "$(Red)Compilation du checker ...${NC}"
	$(CC) $^ $(CFLAGS) $(LIBFT_DIR)libft.a -o $(BONUS) && sleep 0.3
	@echo "$(Green)\r------Compilation finie !-------${NC}" 

$(NAME) : $(OBJS)
	@echo "$(Red)Check de la norme :${NC}"
	@norminette $(LIBFT_DIR) $(PS_DIR) $(HEADERS)
	@echo "$(Red)Compilation de push_swap ...${NC}"
	$(CC) $^ $(CFLAGS) $(LIBFT_DIR)libft.a -o $(NAME) && sleep 0.3
	@echo "$(Green)\r------Compilation finie !-------${NC}" 

sus:
	@echo "$(IRed)           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        $(NC)"
	@echo "$(IRed)        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     $(NC)"
	@echo "$(IRed)        ⣼⣿⠋       ⢀⣀⣀⠈⢻⣿⣿⡄    $(NC)"
	@echo "$(IRed)       ⣸⣿⡏   ⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   $(NC)"
	@echo "$(IRed)       ⣿⣿⠁  ⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ $(NC)"
	@echo "$(IRed)  ⣀⣤⣴⣶⣶⣿⡟   ⢸⣿⣿⣿⣆          ⣿⣷ $(NC)"
	@echo "$(IRed) ⢰⣿⡟⠋⠉⣹⣿⡇   ⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ $(NC)"
	@echo "$(IRed) ⢸⣿⡇  ⣿⣿⡇    ⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ $(NC)"
	@echo "$(IRed) ⣸⣿⡇  ⣿⣿⡇     ⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇  $(NC)"
	@echo "$(IRed) ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  $(NC)"
	@echo "$(IRed)  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   $(NC)"
	@echo "$(IRed)       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   $(NC)"
	@echo "$(IRed)       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   $(NC)"
	@echo "$(IRed)       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    $(NC)"
	@echo "$(IRed)       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              $(NC)"
	@echo "$(White)         ░█▀▀░█░█░█▀▀$(NC)"
	@echo "$(White)         ░▀▀█░█░█░▀▀█$(NC)"
	@echo "$(White)         ░▀▀▀░▀▀▀░▀▀▀$(NC)"

$(OBJS_DIR)%.o : $(PS_DIR)%.c $(HEADERS) Makefile $(LIBFT_DIR)Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(CHECKER_DIR)%.c $(HEADERS_BONUS) Makefile $(LIBFT_DIR)Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean
	@rm -rf $(OBJS_DIR)

fclean :
	cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean
	rm -rf $(OBJS_DIR) $(NAME)

re : fclean
	$(MAKE) all

.PHONY : all clean fclean re obj obj_bonus sus libft bonus

# COLORS =======================================================================

# Reset
NC=\033[0m

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m

# Underline
UBlack=\033[4;30m
URed=\033[4;31m
UGreen=\033[4;32m
UYellow=\033[4;33m
UBlue=\033[4;34m
UPurple=\033[4;35m
UCyan=\033[4;36m
UWhite=\033[4;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

# High Intensity
IBlack=\033[0;90m
IRed=\033[0;91m
IGreen=\033[0;92m
IYellow=\033[0;93m
IBlue=\033[0;94m
IPurple=\033[0;95m
ICyan=\033[0;96m
IWhite=\033[0;97m

# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m

# High Intensity backgrounds
On_IBlack=\033[0;100m
On_IRed=\033[0;101m
On_IGreen=\033[0;102m
On_IYellow=\033[0;103m
On_IBlue=\033[0;104m
On_IPurple=\033[0;105m
On_ICyan=\033[0;106m
On_IWhite=\033[0;107m
