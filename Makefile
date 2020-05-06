

all:
	cd Checker; make; cp checker ..
	cd Push_swap; make; cp push_swap ..
clean: 
	cd Checker; make clean.
	cd Push_swap; make clean

fclean: clean
	rm checker
	rm push_swap

	
