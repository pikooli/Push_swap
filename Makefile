


all:
	cd DirChecker; make; cp checker ..
	cd DirPush_swap; make; cp push_swap ..
clean: 
	cd DirChecker; make clean
	cd DirPush_swap; make clean

fclean:
	cd DirChecker; make fclean
	cd DirPush_swap; make fclean
	rm -rf checker
	rm -rf push_swap
re:	
	make fclean
	make 
test: 
	make all
	./push_swap -v 2 1 3 6 5 8
	
test1:
	make all
	./push_swap -v 3 2 1
test2: 
	make all
	./push_swap -v 3 2 1 9 10
test3: 
	make all
	./push_swap -v 3 -1  2 1 9 10 -4 

ra:	
	make all
	./push_swap -v 3 1 2	
