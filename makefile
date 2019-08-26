all: terminal cd pwd mv cat

terminal: terminaal.c
	gcc terminaal.c -o terminal -lpthread

cd: cd.c
	gcc cd.c -o cd -lpthread

pwd: pwd.c
	gcc pwd.c -o pwd
mv: mv.c
	gcc mv.c -o mv
cat: cat.c
	gcc cat.c -o cat
clean:rm -f terminal cd pwd mv cat

