gcc -shared -fPIC -o libhello.so hello.c
gcc -g -o Test test.c -I ./ -L ./ -lhello
source profile.sh