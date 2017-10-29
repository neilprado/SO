#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

void main(){
  int srce, dstn, size;
  char src[50], dst[50], buffer[50];

  write (1, "Insira o nome do arquivo de origem: ", 36);
  size = read(0, src, 50);
  src[size-1] = '\0';

  write (1, "Insira o nome do arquivo de destino: ", 37);
  size = read(0, dst, 50);
  dst[size-1] = '\0';

  srce = open(src, O_RDONLY);

  if (srce < 0){
    write (1, "Falha! Impossivel ler o arquivo.", 32);
    exit(1);
  }else{
    dstn = open(dst, O_CREAT | O_EXCL | O_RDWR, 777);
    if (dstn < 0){
      write (1, "Falha! O arquivo ja existe.", 27);
      exit(1);
    }else{
      do{
        size = read(srce, buffer, 50);
        write(dstn, buffer, size);
      }while(size > 0);
    }
  }
  close (dstn);
  close (srce);
}
