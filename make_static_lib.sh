gcc -c hello.c
ar crv libhello.a hello.o
gcc -g -o Test test.c -L . -I ./ -lhello