all:
	flex compilator.l
	bison -d compilator.y
	gcc lex.yy.c y.tab.c -ll
clean:
