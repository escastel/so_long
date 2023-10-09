NAME = libft.a

FILES = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_tolower.c \
ft_toupper.c \
ft_memcpy.c \
ft_strncmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_memmove.c \
ft_strchr.c \
ft_strrchr.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_strtrim.c \
ft_itoa.c \
ft_split.c \
get_next_line_bonus.c \
get_next_line_utils_bonus.c \
ft_printf.c \
ft_putptr.c \
ft_puthexa.c \
ft_putunsignbr.c \
ft_count_unsignb.c \
ft_putnbr.c \
ft_count_nb.c \
ft_putstr.c \
ft_putchar.c 

FILES_BONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c 

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(OBJECTS): $(FILES)
	gcc $(FLAGS) -c $(FILES)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	
bonus: $(OBJECTS_BONUS) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all

.PHONY : all clean fclean re bonus
