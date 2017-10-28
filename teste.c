#include <unistd.h>
#include <fcntl.h>

void main (/* arguments */) {
  char teste[50];
  int test;

  write(1, "Digite seu nome: ", 20);
  read(0, teste, 50);
  write(1, teste, 50);
}
