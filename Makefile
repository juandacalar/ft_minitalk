SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers

PRINTF = ft_printf/

LDFLAGS = -L$(PRINTF) -lftprintf

all:
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) server.c -o $(SERVER) $(LDFLAGS)
	@gcc $(FLAGS) client.c -o $(CLIENT) $(LDFLAGS)
	@echo "Server And Client Are Ready!"

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Both Server and Client have been cleaned"

re: fclean all