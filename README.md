----------------------------------------- Push_Swap ---------------------------------------------

You are given a list of number with no duplicata and you have to sort it by ascending order.

You have 2 stack, "a" content all number and "b" with nothing, the methode of implementing the stack is up to you. 

You only have restricted move to sort the stack :
      sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
          is only one or no elements).
          
      sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
          is only one or no elements).
          
      ss : sa and sb at the same time.
      
      pa : push a - take the first element at the top of b and put it at the top of a. Do
          nothing if b is empty.
          
      pb : push b - take the first element at the top of a and put it at the top of b. Do
          nothing if a is empty.
          
      ra : rotate a - shift up all elements of stack a by 1. The first element becomes
        the last one.
        
      rb : rotate b - shift up all elements of stack b by 1. The first element becomes
        the last one.
        
      rr : ra and rb at the same time.
      
      rra : reverse rotate a - shift down all elements of stack a by 1. The last element
        becomes the first one.
        
      rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
        becomes the first one.
        
      rrr : rra and rrb at the same time.

exemple : 
    
    2 1 3 >>> 1 2 3 
    move needed "sa" 
-----------------------------------------------------------------------------------------------------------------------------

To do this in the most effective way , I use the merge sort algorithme : 

The basic is to cut the stack in 2 part and merge it.
You keep in stack "a" the must number that already in ascendant order. (exemple : 1 3 4 9)
You push everything else in "b", you look at with number, in stack b, is optimal to be pushed in stack "a".
When everything is pushed back you just have to rotate stack "a" to get the final solution.

------------------------------------------------- Source --------------------------------------------------------------------
http://sdz.tdct.org/sdz/le-tri-fusion.html
https://en.wikipedia.org/wiki/Merge_sort
https://fr.wikipedia.org/wiki/Tri_fusion
https://hurna.io/fr/academy/algorithms/sort/merge_in_place.html
