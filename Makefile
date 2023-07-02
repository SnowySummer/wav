# Available commands
#
#   - build : Build the main executable
#   - run   : Build and run the executable
#   - lib   : Build the library
#   - clean : Clean up


.PHONY : build run lib clean

build :
	@echo -n "\e[1;34m"
	@echo "###################"
	@echo "### Start build ###"
	@echo "###################"
	@echo -n "\e[0;33m"
	mkdir -p bin

	$(MAKE) -C src build


run :
	$(MAKE) build


	@echo "\e[1;34m"
	@echo "######################"
	@echo "### Launching test ###"
	@echo "######################"
	@echo -n "\e[0;37m"

	@$(MAKE) -s -C src run

lib :
	@echo -n "\e[1;34m"
	@echo "########################"
	@echo "### Building library ###"
	@echo "########################"

	@echo "\e[1;34m"
	@echo "-- 1/3 : Make library directory --"
	@echo -n "\e[0;33m"
	rm -rf lib
	mkdir -p lib

	@echo "\e[1;34m"
	@echo "-- 2/3 : Build library --"
	@echo -n "\e[0;33m"
	cp -r src lib
	$(MAKE) -s -C lib/src lib

	@echo "\e[1;34m"
	@echo "-- 3/3 : Setup library headers --"
	@echo -n "\e[0;33m"
	rm -rf lib/src/*.c
	rm -rf lib/src/Makefile
	mv lib/src lib/headers

clean :
	rm -rf bin
	rm -rf lib
	rm -rf data/*