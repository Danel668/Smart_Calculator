CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -g -O0
TEST_LIBS = -lcheck -lm -lsubunit
#TEST_LIBS = -lcheck -lm

TEST = test

SRC_DIR = .
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_SRC_DIR)/test*.c)

INCLD_DIR = .
INCLD = $(wildcard $(INCLD_DIR)/*.h)

OBJ_DIR = $(SRC_DIR)/objs

MKDIR = mkdir -p

TEST_SRC_DIR = ./tests
TEST_INCLD_DIR = ./tests
TEST_OBJ_DIR = $(TEST_SRC_DIR)/test_objs

GCOV_DIR = $(SRC_DIR)/gcov_report
GCOV_OBJ_DIR = $(GCOV_DIR)/objs

TEST_OBJ = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
GCOV_OBJ = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GCOV_OBJ += $(GCOV_OBJ_DIR)/calc_controlller.o

RM = rm -f
RMDIR = rm -rf


all: clean install

install:
	cd ../front/SmartCalc/build && qmake ../ && make && make clean && rm -rf debug


uninstall:
	cd ../front/SmartCalc/build && rm -rf Makefile release Makefile.* *.Debug *.Release


dvi:
	open ../../README_RUS.md


dist:
	cd ../front/SmartCalc/build && mkdir -p ../dist && cp -R * ../dist && cp ../../../../README_RUS.md ../dist
	cd ../dist && tar cvzf SmartCalculator.tgz * && rm -rf Makefile release Makefile.* *.Debug *.Release


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLD)
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) -I$(INCLD_DIR) -c $< -o $@


$(SRC_DIR)/objs/calc_controlller.o:
	$(MKDIR) ./objs
	$(CC) $(FLAGS) -I../ -I. -c ../calc_controlller.c -o $(SRC_DIR)/objs/calc_controlller.o


$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c  $(TEST_INCLD)
	@$(MKDIR) $(@D)
	$(CC) $(FLAGS) -I$(INCLD_DIR) -I$(TEST_INCLD_DIR) -I../ -c $< -o $@


$(GCOV_OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLD)
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) $(GCOV_FLAGS) -I$(INCLD_DIR) -c $< -o $@


$(GCOV_OBJ_DIR)/calc_controlller.o:
	$(MKDIR) $(GCOV_OBJ_DIR)
	$(CC) $(FLAGS) $(GCOV_FLAGS) -I../ -I. -c ../calc_controlller.c -o $(GCOV_OBJ_DIR)/calc_controlller.o


test:
	gcc -Wall -Wextra -Werror -std=c11 c_stack.c calculate.c input_validation.c parser.c \
	To_Reverse_Polish_Notation.c ../calc_controlller.c  \
	tests/test_controller.c tests/test_calc.c \
	-o test -lcheck -lm -lsubunit
	./test


clean:
	$(RMDIR) $(OBJ_DIR)
	$(RM) $(TEST)
	$(RM) $(TEST_OBJ)
	$(RMDIR) $(TEST_OBJ_DIR)
	$(RM) -r $(GCOV_OBJ_DIR)
	$(RM) -r $(GCOV_DIR)


gcov_report: $(GCOV_OBJ) $(TEST_OBJ)
	$(CC) $(GCOV_FLAGS) $(GCOV_OBJ) $(TEST_OBJ) \
	-o $(GCOV_DIR)/test_coverage $(TEST_LIBS)
	./$(GCOV_DIR)/test_coverage;
	gcov $(GCOV_OBJ_DIR)/*.gcno;
	@mv *.gcov $(GCOV_OBJ_DIR);
	lcov -c -t "s21_calculator" -o $(GCOV_DIR)/report.info -d $(GCOV_OBJ_DIR) \
	--rc lcov_branch_coverage=1;
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/report.info --rc lcov_branch_coverage=1


