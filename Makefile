


all:
	@cd DirChecker; make; cp checker ..
	@cd DirPush_swap; make; cp push_swap ..
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
	@make all
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
test4: 
	make all
	./push_swap -v 3 2147483647 -1  2 1 9 10 -4 -2147483648 0 
test5: 
	make all
	./push_swap -v 3 -1  2 1 9 10 -4 
test6: 
	make all
	./push_swap -v 3 -1  2 1 9 10 -4 
test7: 
	make all
	./push_swap -v 3 -1  2 1 9 10 -4 

testall:
	make test
	make test1
	make test2
	make test3
	make test4
	


ra:	
	make all
	./push_swap -v 3 1 2	
