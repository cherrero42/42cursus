# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cherrero <cherrero@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 22:14:31 by cherrero          #+#    #+#              #
#    Updated: 2023/02/04 15:58:59 by cherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = ./gnl
GNL = $(GNL_DIR)/gnl.a

SOURCE_DIR = .

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARGS = -2 776 -3 913 692 211 -4 876 561 973 996 414 640 66 460 289 772 473 83 496 611 290 56 636 486 390 284 268 302 758 158 61 583 476 736 313 532 130 884 680 370 334 704 564 761 36 835 614 450 347 904 119 847 616 416 713 579 184 859 767 176 831 152 836 78 976 682 924 792 834 216 135 805 684 210 411 697 874 618 377 156 921 246 197 979 986 766 456 438 634 590 374 260 833 764 441 301 974 15 399 785 610 387 528 401 897 957 87 492 111 550 213 821 773 464 389 394 710 170 38 225 151 665 514 685 502 22 1000 623 638 818 226 166 672 32 730 955 172 527 391 509 336 383 474 360 266 992 870 722 220 882 855 333 79 179 505 291 696 535 495 43 233 150 131 472 848 396 318 644 970 142 909 168 521 264 330 482 363 540 720 30 529 4 305 632 928 648 881 358 822 443 332 229 71 300 388 85 622 553 729 106 125 551 93 3 82 545 769 137 749 205 658 287 18 100 577 555 949 880 588 386 740 69 466 373 425 138 77 516 794 558 829 192 406 570 549 429 240 407 693 584 923 965 961 257 920 929 60 449 188 500 254 959 493 702 508 945 760 422 607 977 567 688 798 918 371 600 294 209 862 875 718 601 903 865 739 427 191 222 812 699 105 919 982 419 815 512 232 199 660 297 33 352 649 99 25 800 726 652 155 365 721 88 612 797 846 715 247 686 8 914 143 953 656 746 525 165 883 771 967 524 991 167 288 968 591 694 633 235 888 459 813 654 256 604 657 908 750 279 857 259 840 526 987 930 140 455 828 853 839 271 737 789 597 382 269 887 635 341 613 664 448 927 276 295 960 351 899 348 147 858 533 878 412 5 342 484 620 395 403 206 350 436 807 845 243 9 557 321 446 503 956 281 468 116 442 563 931 871 221 278 153 510 734 239 132 844 17 75 91 943 851 586 200 975 546 384 114 679 52 541 869 475 969 479 595 571 598 237 786 123 20 863 404 629 837 980 223 717 768 252 250 331 958 107 852 925 803 282 6 35 144 23 194 838 886 728 366 355 864 400 173 24 72 51 84 765 286 951 488 42 31 67 329 993 356 423 217 369 910 26 779 196 983 146 515 62 504 136 311 666 74 494 645 724 410 916 364 650 735 671 631 463 309 893 683 447 19 103 989 795 265 531 344 458 465 626 37 353 393 212 580 706 578 659 480 1 298 398 97 849 238 868 753 824 141 748 11 320 741 182 275 -5 109 81 453 174 101 241 139 619 523 354 94 936 415 816 763 262 743 303 663 461 2 602 112 647 605 375 892 161 872 823 380 417 667 543 944 128 978 842 402 219 145 574 830 127 65 589 428 328 134 310 948 129 63 906 418 984 825 655 242 307 733 346 122 497 963 49 345 810 255 911 186 40 201 596 86 889 891 676 185 157 121 606 934 933 489 50 641 46 224 190 520 643 705 92 181 922 324 566 559 905 293 646 817 990 432 -6 98 53 585 202 952 481

AR = ar -src

RM = rm -f

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SOURCES = $(SOURCE_DIR)/push_swap.c	$(SOURCE_DIR)/stack_op_1.c $(SOURCE_DIR)/stack_op_2.c $(SOURCE_DIR)/stack_op_3.c \
		  $(SOURCE_DIR)/stack_op_4.c $(SOURCE_DIR)/stack_mov_1.c $(SOURCE_DIR)/stack_mov_2.c \
		  $(SOURCE_DIR)/stack_mov_3.c $(SOURCE_DIR)/stack_sort_full_1.c $(SOURCE_DIR)/stack_sort_full_2.c $(SOURCE_DIR)/stack_sort_full_3.c
	
SOURCES_BONUS = $(SOURCE_DIR)/checker.c	$(SOURCE_DIR)/stack_op_1.c $(SOURCE_DIR)/stack_op_2.c $(SOURCE_DIR)/stack_op_3.c \
				$(SOURCE_DIR)/stack_op_4.c $(SOURCE_DIR)/stack_mov_1.c $(SOURCE_DIR)/stack_mov_2.c \
	  			$(SOURCE_DIR)/stack_mov_3.c $(SOURCE_DIR)/stack_sort_full_1.c $(SOURCE_DIR)/stack_sort_full_2.c $(SOURCE_DIR)/stack_sort_full_3.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

${NAME}: $(LIBFT) $(PRINTF) $(GNL) $(OBJECTS)
	${CC} ${CFLAGS} ${CFLAGS_DEBUGER} ${OBJECTS} $(LIBFT) $(PRINTF) $(GNL) -o ${NAME}
	@echo "$(NAME): $(GREEN)Creating $(NAME)...$(RESET)"
	
all: ${NAME}
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"

bonus: $(LIBFT) $(PRINTF) $(GNL) ${BONUS} 

${BONUS}: $(LIBFT) $(PRINTF) $(GNL) ${OBJECTS_BONUS}
	${CC} ${CFLAGS} ${CFLAGS_DEBUGER} ${OBJECTS_BONUS} $(LIBFT) $(PRINTF) $(GNL) -o ${BONUS}
	@echo "$(NAME): $(GREEN)Creating $(BONUS)...$(RESET)"

$(LIBFT):
	make -C $(LIBFT_DIR)
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"

$(PRINTF):
	make -C $(PRINTF_DIR)
	@echo "$(NAME): $(GREEN)Creating $(PRINTF)...$(RESET)"

$(GNL):
	make -C $(GNL_DIR)
	@echo "$(NAME): $(GREEN)Creating $(GNL)...$(RESET)"

test: $(NAME)
	clear
	$(SOURCE_DIR)/$(NAME) $(ARGS)

testbonus: $(NAME)
	clear
	$(SOURCE_DIR)/$(NAME) $(ARGS) | $(SOURCE_DIR)/$(BONUS) $(ARGS)
	
re:	fclean all

rebonus:	fclean bonus

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}
			make clean -C $(LIBFT_DIR)
			make clean -C $(PRINTF_DIR)
			make clean -C $(GNL_DIR)

fclean:		clean
			${RM} $(NAME) ${BONUS}
			make -C $(LIBFT_DIR) fclean
			make -C $(PRINTF_DIR) fclean
			make -C $(GNL_DIR) fclean
			@echo "$(NAME): $(RED)$(NAME) cleaned$(RESET)"

.PHONY: all, clean, fclean, re, bonus, test, rebonus
