
NAME_PS = push_swap

NAME_CK = checker

CHECKER_DIRECTORY = ./DirChecker/

CHECKER = $(CHECKER_DIRECTORY)$(NAME_CK)

CC = gcc

LIBFT = $(LIBFT_DIRECTORY)libft.a

LIBFT_DIRECTORY = ./libft/

LIBFT_HEADER = $(LIBFT_DIRECTORY)includes/

LIBRARIES = -lft -L $(LIBFT_DIRECTORY)

INCLUDES = -I ./includes

FLAGS = -Wall -Wextra -Werror 

SOURCES_DIRECTORY = ./srcs/

SOURCES_LIST = 	ft_print.c\
				ft_check.c\
				ft_cmd.c\
				ft_direction.c\
				ft_free.c\
				ft_index.c\
				ft_init.c\
				ft_markup.c\
				ft_parse.c\
				ft_push.c\
				ft_rotate.c\
				ft_solve_a.c\
				ft_solve_b.c\
				ft_solve.c\
				ft_stack.c\
				ft_utils.c\
				ft_swap.c


SOURCES_LIST_PS = push_swap.c

OBJECTS_DIRECTORY = objects/

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))

OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))

OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))

# Number to test  

HUNDRED_POSI = 81 66 65 94 59 29 61 2 47 54 1 88 50 3 77 27 17 37 85 60 67 31 38 14 36 96 0 24 13 82 55 8 16 49 62 23 70 7 56 41 18 53 32 99 42 92 28 72 100 25 79 76 97 4 83 73 44 90 10 64 63 21 71 68 58 52 48 5 11 80 30 46 74 20 35 15 95 26 84 69 39 75 98 87 33 34 89 57 91 9 22 43 12 19 40 78 45 6 51 93 86

HUNDRED_MIX = -34 -38 -13 29 1 -27 45 -30 -15 19 -33 -50 38 15 22 14 -12 30 -7 -47 24 41 -29 7 -49 33 21 -2 -10 -16 43 -17 -45 5 -35 42 -26 -5 -32 -20 11 -4 16 46 10 31 -39 26 -46 -43 44 -11 32 -24 -40 50 35 9 -31 20 -19 -14 -21 -18 39 2 -6 34 -8 4 -48 36 17 -1 -44 23 27 -36 40 -9 47 -41 0 12 -28 37 -37 49 25 -42 48 18 6 -22 -3 -25 28 8 3 -23 13

FIVE_HUNDRED_POSI = 248 499 241 308 71 383 116 232 283 364 24 78 335 356 120 52 193 277 337 348 478 328 375 378 493 142 39 462 415 363 413 393 282 32 66 141 357 192 132 158 497 445 313 226 278 47 299 137 455 448 217 97 399 436 481 254 45 25 294 484 69 31 251 302 268 411 67 94 173 376 143 99 446 119 258 229 320 11 461 12 306 37 190 295 362 494 358 443 469 172 151 333 4 207 319 470 400 48 76 263 279 165 367 28 222 305 174 298 450 30 98 474 164 124 435 105 327 20 227 441 111 70 325 209 153 75 409 487 344 284 449 401 93 86 444 291 145 468 195 64 179 326 427 386 16 412 247 233 201 323 341 346 245 152 114 416 135 349 196 270 330 433 463 19 188 191 177 102 422 53 403 314 182 144 103 1 159 355 334 136 408 249 438 379 381 372 22 419 139 297 200 216 475 370 265 109 77 259 5 276 29 264 272 473 317 49 426 34 397 35 167 472 480 212 58 418 170 101 63 322 285 74 57 338 60 205 42 301 199 365 312 84 466 55 33 280 122 490 150 486 228 156 26 211 21 3 62 353 91 131 360 243 464 350 171 72 366 310 479 202 223 396 146 491 27 345 104 210 215 410 0 489 113 189 65 339 309 73 41 242 89 187 260 121 44 252 244 130 431 100 304 224 271 126 430 138 117 500 300 289 321 421 237 432 434 452 134 388 343 14 380 451 204 394 354 257 390 206 2 13 6 253 140 96 36 127 50 185 123 183 46 287 129 231 361 332 82 85 385 220 414 465 194 488 296 10 234 218 498 239 423 198 88 485 495 17 347 56 307 83 447 371 79 477 288 184 261 428 373 7 178 255 95 467 286 161 256 395 110 115 107 18 315 351 424 147 456 38 387 374 440 391 106 476 329 148 221 471 160 402 219 482 290 267 429 208 40 157 398 262 9 112 404 457 125 168 118 352 162 169 453 180 238 439 420 92 154 80 269 292 384 460 368 155 417 128 392 246 43 54 90 166 437 458 406 442 225 274 176 492 214 61 273 213 23 59 331 382 405 236 293 235 275 181 149 68 425 459 303 369 163 377 133 87 496 359 250 389 407 281 175 108 266 8 240 197 51 342 186 316 340 311 203 15 81 336 454 324 230 483 318

FIVE_HUNDRED_MIX = 237 -198 232 -211 122 191 -102 6 204 -165 113 -200 -199 -29 -31 161 149 -179 -232 -116 -50 241 179 -133 -215 -205 136 -144 -120 -4 -127 -147 -38 -3 -245 -22 162 37 -191 131 8 -220 -77 -112 21 -137 170 -169 228 15 187 156 13 44 -60 75 -222 -248 -13 74 135 150 -20 -213 126 -117 -194 117 -25 -201 -192 -124 -177 223 -92 82 246 -230 -1 121 -148 -19 196 99 -214 183 -96 -210 -90 -190 84 200 -225 51 -121 172 19 101 250 194 -55 25 -101 133 95 163 -203 106 -118 77 -218 180 79 224 130 72 60 -40 -224 -9 225 28 105 -26 57 -98 -229 181 206 92 114 -95 65 -109 -63 -234 127 66 -99 39 61 -36 220 -238 229 233 242 157 236 -227 -129 -142 -66 -47 243 216 20 -163 -174 87 -209 -28 46 159 53 -23 -93 3 90 -217 -145 247 50 -84 195 -69 213 208 9 -8 -188 -166 -74 1 175 -78 16 125 -138 27 119 -104 2 -241 -44 144 -134 168 -119 100 238 147 11 52 98 -111 -103 -91 22 5 40 80 -151 -68 123 -42 226 222 212 -139 73 240 12 -53 -131 164 -105 -61 -149 -126 102 -17 59 -237 -184 -172 -130 -182 186 -85 67 -41 -106 146 -161 110 -154 94 -193 -71 89 -30 -140 245 -108 -244 -73 -247 210 169 141 103 -2 -54 -15 209 10 -208 -176 198 152 192 158 217 142 91 215 176 193 -135 -16 178 219 148 -162 -34 -65 81 -231 97 185 -39 24 -83 7 -81 23 188 120 63 227 -235 -123 71 190 78 -6 -152 234 115 -171 111 244 109 -204 33 -11 221 -76 -97 -180 184 182 155 -158 201 -160 -14 -43 -185 -115 42 41 0 26 -113 58 93 -181 124 -136 43 -212 -150 154 69 29 -155 203 249 239 -156 14 96 -132 -49 -167 55 112 36 -27 -186 -170 139 -87 76 -195 -12 -178 -236 17 -24 -37 211 -206 -223 137 35 -7 143 -207 -70 -196 -75 153 165 -239 -146 -242 231 -86 -141 230 34 -58 45 54 -122 -94 31 -226 177 70 202 -35 30 -45 88 64 -114 -72 -175 -183 108 -125 -100 -128 116 107 -243 -48 -173 68 83 -228 -33 -197 140 104 167 129 -52 -88 160 197 47 189 -5 49 138 -219 118 -51 -250 -64 85 -10 -143 218 -62 -153 -89 -164 -79 173 128 -246 166 -21 -216 145 -57 -56 -46 -107 -187 32 -168 214 62 -82 248 132 -233 -67 151 -80 205 171 56 199 48 207 235 134 -157 -59 -202 38 -110 -189 -18 86 18 -32 -221 -249 -240 -159 4 174

FIVE = 1 5 2 4 3

TREE = 2 1 0

all: $(NAME_PS)

$(NAME_PS): $(LIBFT) $(NAME_CK) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) libft/objects/* $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(NAME_PS)
	@echo "$(NAME_PS) : $(GREEN)Compilation done.$(RESET)"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(NAME_CK):
	@$(MAKE) -sC $(CHECKER_DIRECTORY)
	@cp $(CHECKER) .

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) $(SOURCES_PS) -c
	@mv $(OBJECTS_LIST) $(OBJECTS_LIST_PS) $(OBJECTS_DIRECTORY)


clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(CHECKER_DIRECTORY) clean
	@rm -rf $(OBJECTS) $(OBJECTS_PS) $(OBJECTS_DIRECTORY)
	@echo "$(RED)Clean done.$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@$(MAKE) -sC $(CHECKER_DIRECTORY) fclean
	@rm -rf $(NAME_CK)
	@rm -rf $(NAME_PS) 
	@echo "$(RED)Fclean done.$(RESET)"

	
re: fclean all

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

100:
	./push_swap $(HUNDRED_POSI) | ./checker -v -c $(HUNDRED_POSI)

100M:
	./push_swap $(HUNDRED_MIX) | ./checker -v -c $(HUNDRED_MIX)

500:
	./push_swap $(FIVE_HUNDRED_POSI) | ./checker -v -c  $(FIVE_HUNDRED_POSI)
500M:
	./push_swap  $(FIVE_HUNDRED_MIX) | ./checker -v -c  $(FIVE_HUNDRED_MIX)

500c:
	./push_swap  $(FIVE_HUNDRED_POSI) | ./checker -c  $(FIVE_HUNDRED_POSI)
500Mc:
	./push_swap  $(FIVE_HUNDRED_MIX) | ./checker -c  $(FIVE_HUNDRED_MIX)

5:
	./push_swap  $(FIVE) | ./checker -v -c  $(FIVE)
3:
	./push_swap $(TREE) | ./checker -v -c  $(TREE)

# ARG="-v -c 3 2147483647 -1  2 1 9 10 -4 -2147483648 0 99 11 -20 -50"; ./push_swap $ARG | ./checker $ARG
# ARG="-v -c 1 2 3"; ./push_swap $ARG | ./checker $ARG
