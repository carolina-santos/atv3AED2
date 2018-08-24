//Carolina Gabriele Souza dos Santos - 102159

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
#define num_balde TAM

 
 typedef struct {
         int topo;
         float balde[TAM];
 }bucket;

void imprimeVetor(float vet[]){
    int i=0;
    for(i=0; i<TAM; i++)
        printf("%f ",vet[i]);
    printf("\n");
}

int maiorElemento(int vet[]){
  int max, i=0;
  max=vet[i];
      for(i=0;i<TAM;i++)
    {
     if(vet[i]>max)
      max=vet[i];
    }
    return max;
}

void contagem(int vet[]){
  int max = maiorElemento(vet);
  int contador[max],i,j,final[TAM],k=0;
    //inicia o contador com 0
     for(i=0;i<TAM;++i)
      contador[i]=0;
    //comulativo para os numeros iguais
     for(i=0;i<TAM;++i)
      contador[vet[i]]=contador[vet[i]]+1;
      

     for(i=0;i<=max;++i)
      for(j=1;j<=contador[i];j++){
          //final[k]=i;
          //k++;
          printf("%d ",i);
      }
}

void bubble (float vet[]) {
    int i, j;
    float aux;
    for (i = 1; i < TAM; i++) {
        for (j=0; j<TAM-1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j+1] = aux;
            }
        }
    }
   // imprimeVetor(vet);
}

void bucketSort(float vet[]){                                 
         bucket b[num_balde];                                      
         int i,j,k;                                                 
 for(i=0;i<num_balde;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
         
  for(i=0;i<TAM;i++){                          //verifica em que balde o elemento deve ficar
                 j=(num_balde)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(vet[i]>=j*10){
                                 b[j].balde[b[j].topo]=vet[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
         
  for(i=0;i<num_balde;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bubble(b[i].balde);
         
         i=0;
 for(j=0;j<num_balde;j++){                    //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         vet[i]=b[j].balde[k];
                         i++;
                 }
         }imprimeVetor(vet);
 }


int main (){
   
    float vet[TAM];
    int vet1[TAM];
    int i;
    srand((unsigned)time(NULL));
    clock_t tempo;

    for (i=0; i<TAM; i++){
      //vet1[i] = (rand()%TAM);
        vet[i] = (rand()%TAM);
        vet[i] = vet[i]/TAM;
        //vet[i] = i;
    }
    imprimeVetor(vet);
    //contagem(vet1);
    bucketSort(vet);
    printf("\n Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);    
    return 0;
}

