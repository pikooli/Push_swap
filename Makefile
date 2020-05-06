

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

	
