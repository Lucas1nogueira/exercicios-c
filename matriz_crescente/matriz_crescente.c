#include <stdio.h>

int main () {
  int matriz[3][3] = {};
  int x=0;
  int vet[9] = {};
  
  printf("--- Matriz 3x3 ---\n\n");
  
  for(int b=0; b<3; b++){
    for(int c=0; c<3; c++){
      printf("Insira o elemento para lin %d e col %d: ", b, c);
      scanf("%d", &matriz[b][c]);
    }
  }
  
  printf("\nMatriz original:");
  
  for(int b=0; b<3; b++){
    printf("\n");
    for(int c=0; c<3; c++){
      printf("%d ", matriz[b][c]);
    }
  }
  
  int f=0;
  
  for(int b=0; b<3; b++){
    for(int c=0; c<3; c++){
      vet[f]=matriz[b][c];
      f++;
    }
    f++;
  }
  
  for(int b=0; b<9; b++){
    for(int c=0; c<9; c++){
      if(vet[b]<vet[c]){
        x = vet[b];
        vet[b] = vet[c];
        vet[c] = x;
      }
    }
  }
  
  printf("\n\nMatriz crescente:\n");
  
  int y=0;
  while(y!=9){
    for(int z=0; z<3; z++){
      printf("%d ", vet[y]);
      y++;
    }
    printf("\n");
  }
  
  return 0;
}
