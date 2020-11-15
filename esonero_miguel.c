//Esonero novembre Programmazione procedurale
#include <stdio.h> //aggiungo librerie
#include <string.h>
#include <stdlib.h>
#include <time.h>

char plaintextM[128];
char chiaveK[128];
char c[128];
char cifr_M[128];
int scelta= 0;
int x = 0;
time_t t;

int main(void)
{
printf("testo di max 128 caratteri:");
fgets(plaintextM, 128, stdin);
printf("il tuo testo è %s\n", plaintextM);

printf("il tuo testo è lungo%lu\n", strlen(plaintextM) - 1); // ho aggiunto -1 perché sempre mi viene un carattere di più

printf("scegli tra queste due opzioni (1) o (2)\n");
scanf("%d", &scelta);

getchar(); //serve per pulire il buffer, tutto ciò preso dalla tastiera che è nel "vuoto"

switch(scelta)
{
  case 1:
  if (scelta != 1 && scelta !=2)
  {
    return 0;
  }
  else
{
  inseriscitextK: printf("Devi inserire la stringa della chiaveK con quantità uguale o superiore a quella di plaintextM, ma inferiore di 128 caratteri.\n");
  fgets(chiaveK, 128, stdin);

  if(strlen(chiaveK) <= strlen(plaintextM))
  {
    printf("Deve superare i caratteri di plaintextM, riprova rieseguendo il programma\n"); goto inseriscitextK;// ho inserito il commando goto perché non mi viene in mente qualche altro modo per farlo tornare indietro
}
  else
  {
    printf("La tua stringa chiave è %s\n", chiaveK);

    for (x=0; x<strlen(plaintextM); x++)
    {
      c[x]=plaintextM[x] ^ chiaveK[x];
    }
    printf("La stringa cifrata è %x\n", c[(unsigned char)x]);

    for (x=0; x<strlen(plaintextM); x++)
    {
      cifr_M[x]= c[x] ^ chiaveK[x];
    }
    printf("La stringa M è %s\n", cifr_M);
  }
}
break;
case 2:
  printf(" La stringa della chiave sarà generata automaticamente\n");

  srand((unsigned)time(&t));

  for (x=0;x<strlen(plaintextM); x++)
  {
    chiaveK[x]= 30 + rand()% 96;
  }
  printf("la tua chiave generata automaticamente è %s \n", chiaveK);

  for (x=0;x<strlen(plaintextM); x++)
  {
    c[x]= plaintextM[x] ^ chiaveK[x];
  }
  printf("La stringa cifrata è %x\n", c[(unsigned char)x]);

  for (x=0; x<strlen(plaintextM); x++)
  {
    cifr_M[x]=c[x] ^ chiaveK[x];
  }
  printf("la stringa di M è %s\n", cifr_M);
  break;
default:; // uno dei due casi o niente e finisce
}
}
