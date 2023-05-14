# 链接
main : hello.o main.o
	g++ hello.o main.o -o main

# 预处理 -E .c -> .i
hello.i : hello.c hello.h
	g++ -E hello.c -o hello.i
main.i : main.c hello.h
	g++ -E main.c -o main.i

# 编译 -S .i -> .s
hello.s : hello.i
	g++ -S hello.i -o hello.s
main.s : main.i
	g++ -S main.i -o main.s

# 汇编 -c .s -> .o
hello.o : hello.s
	g++ -c hello.s -o hello.o
main.o : main.s
	g++ -c main.s -o main.o

clean :
	rm *.o *.s *.i