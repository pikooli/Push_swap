


all:
	@cd DirChecker; make; cp checker .. ; make clean
	@cd DirPush_swap; make; cp push_swap ..; make clean
	@echo "finish make all"
clean: 
	@cd DirChecker; make clean
	@cd DirPush_swap; make clean
	@echo "finish clean"

fclean:
	@cd DirChecker; make fclean
	@cd DirPush_swap; make fclean
	@rm -rf checker
	@rm -rf push_swap
	@echo "finish fclean"
re:	
	@make fclean
	@make 
test: 
	./push_swap -v 2 1 3 6 5 8
	
test1:
	./push_swap -v 3 2 1
test2: 
	./push_swap -v 3 2 1 9 10
test3: 
	./push_swap -v 3 -1  2 1 9 10 -4 
test4: 
	./push_swap -v 3 2147483647 -1  2 1 9 10 -4 -2147483648 0 
test5: 
	./push_swap -v 3 2147483647 -1  2 1 9 10 -4 -2147483648 0 99 11 -20 -50 
test6: 
	./push_swap -v 3 2147483647 77 88 -99 -1  2 1 9 10 -4 -2147483648 0 99 11 -20 -50 
test7: 
	./push_swap -v 3 2147483647 77 88 -99 100 21 -7 -1  2 1 9 10 -4 -2147483648 0 99 11 -20 -50 

testall:
	@make test
	@make test1
	@make test2
	@make test3
	@make test4
	@make test5	
	@make test6	
	@make test7	


ra:	
	make all
	./push_swap -v 3 1 2	
