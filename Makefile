OBJ = menu.o client.o

client: $(OBJ)
	clang -o client client.o menu.o \
	`mysql_config --cflags --libs`


menu.o: menu.h
client.o: menu.h
clean: 
	-rm $(OBJ) client
.PHONY: clean