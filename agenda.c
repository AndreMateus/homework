#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
#define MEX 30
#define VERIE 122
#define VERID 124
#define IDINICIAL 3
#define LINHA 121 
#define POSINOME 12
#define POSITEL  52
#define POSIEMAIL 90
#define TAMANHO 30

void inicia(FILE *arquivo, char nomearquivo[MAX]);
int menu(FILE *arquivo, char nomearquivo[MAX]);
int inserir(FILE *arquivo, char nomearquivo[MAX]);
int colocaid(FILE *arquivo, char nomearquivo[MAX]);
int remover(FILE *arquivo, char nomearquivo[MAX]);
int pesq(FILE *arquivo, char nomearquivo[MAX]);
int modifica(FILE *arquivo, char nomearquivo[MAX]);
int ondeescrever(FILE *arquivo, char nomearquivo[MAX]);

struct Dados{
  char nome[MEX];
  char tel[MEX];
  char email[MEX];
  int proximo;
  };
struct Dados dados;

int main(int argc, char *argv[])
 {
  FILE *arquivo;
  
  inicia(arquivo, argv[1]);
  menu(arquivo, argv[1]);
}

void inicia(FILE *arquivo, char nomedoarquivo[MAX])
{
 int entrada, n;
 char c;
   arquivo = fopen(nomedoarquivo, "r");

   if (arquivo == NULL)
      {
       arquivo = fopen(nomedoarquivo, "w");
       fclose(arquivo); 
      } 

  arquivo = fopen(nomedoarquivo, "a+");

   if (arquivo == NULL)
      {
       while (arquivo == NULL)
        { 
         printf("ERROR, mude o diretorio do arquivo, ou entre com um diretorio diferente para a criacao correta do arquivo.");
      printf("\nPara tentar de novo entre com 1\nPara sair digite 0");
   	 printf("\nEntrada:");
   	 scanf("%d", &entrada);
         if (entrada == 0)
            exit(0);
 	   if (entrada == 1)
   	      {	 
      	       n = 0;
               c = getchar();

   		  while (c != '\n')
   		   {
      		    nomedoarquivo[n] = c;
      		    c = getchar();
     		    n++;
    		   }

                nomedoarquivo = '\0';
          	arquivo = fopen(nomedoarquivo, "a+");
              }
           }
        }  
   fclose(arquivo);
   printf("\33[H\33[2J");
   printf("\nBem-vindo a agenda 2280 versao 1.0\n");
}




int menu(FILE *arquivo, char nomearquivo[MAX])
 {
  int number;
  number = MAX;

     while((number != 1) && (number != 2) && (number != 3) && (number != 4) && (number != 0))
      {
       printf("\nMenu agenda 2280\n");
       printf("Para inserir um novo contato entre com  1\n");
       printf("Para remover um contato entre com       2\n");
       printf("Para pesquisar um contato entre com     3\n");
       printf("Para modificar um contato entre com     4\n");
       printf("Para sair entre com                     0\n");
       printf("Entrada:");
       fflush(stdin);
       scanf("%d", &number);

           while((number != 1) && (number != 2) && (number != 3) && (number != 4) && (number!= 0))
            {
             printf("\33[H\33[2J");
             printf("***Entrada invalida***\n");
             printf("Para inserir um novo contato entre com  1\n");
             printf("Para remover um contato entre com       2\n");
             printf("Para pesquisar um contato entre com     3\n");
             printf("Para modificar um contato entre com     4\n");
             printf("Para sair entre com                     0\n");
             printf("Entrada:");
             scanf("%d", &number); 
             getchar();
            } 

        printf("\33[H\33[2J");
   
            if (number == 1)
         	number = inserir(arquivo, nomearquivo);
     	    if (number == 2)
         	number = remover(arquivo, nomearquivo);
     	    if (number == 3)
         	number = pesq(arquivo, nomearquivo);
     	    if (number == 4)
       	        number =  modifica(arquivo, nomearquivo);
            if (number == 0)
        	exit(0);
        }
   }

int ondeescrever(FILE *arquivo, char nomearquivo[MAX])
 {
   int posiv, posicao, linha;
   char a;

   posicao = 0;
   linha = 0;
   posiv = POSINOME + 2;
   arquivo = fopen(nomearquivo, "r+");
   fseek(arquivo, posiv, 0);
   a = getc(arquivo);
   posicao = linha * LINHA;
   linha ++; 

         while ((a != EOF) && ( a != ' '))
  	  { 
  	    posicao = linha * LINHA; 
 	    posiv = posicao + POSINOME + 2;
	    fseek(arquivo, posiv, 0);
	    a = getc(arquivo);
  	    linha ++;
          } 
  
  fclose(arquivo);

  return(posicao);
 }


int inserir(FILE *arquivo, char nomearquivo[MAX])
{ 
 int entrada, n, posicao;
 char c;
 entrada = 1;

      while (entrada != 0)
       {
      	arquivo = fopen(nomearquivo, "r+");
      	fseek(arquivo, 0, 0);
      	posicao = ondeescrever(arquivo, nomearquivo);
      	fseek(arquivo, posicao, 0);

      	printf("**Adicao de contatos**\n\n");
      	printf("Digite o Nome:");
      	fprintf(arquivo,"ID:    Nome:");  
      	n = 0;
      	c = getchar();
      	c = getchar();

        	while (c != '\n')
           	 { 
          	  dados.nome[n] = c;
          	  c = getchar();
          	  n++;
                 }

       dados.nome[n] = '\0';
       n = (strlen(dados.nome));
       fputs(dados.nome, arquivo);

        	for (n; n != MEX; n++)
            	    fprintf(arquivo, " ");
         
        printf("\nDigite o Telefone:");
        fprintf(arquivo, " Telefone:");
        n = 0;
        c = getchar();

               while (c != '\n')
           	{
            	 dados.tel[n] = c;
            	 c = getchar();
           	 n++;
           	}
//stdio_ext fpurge(stdin);
       dados.tel[n] = '\0';
       n = (strlen(dados.tel));
       fputs(dados.tel, arquivo);
 
           	for (n; n != MEX; n++)
               	    fprintf(arquivo, " ");
  
       printf("\nDigite o E-mail:");
       fprintf(arquivo," E-mail:");
       n = 0;
       c = getchar();
 
         	while (c != '\n')
         	 {
             	  dados.email[n] = c;
   	   	  c = getchar();
   	   	  n++;
  	    	 }
 
       dados.email[n] = '\0';
       fputs(dados.email, arquivo);
       n = (strlen(dados.email));
 
          	for (n; n != MEX; n++)
              	    fprintf(arquivo, " ");
 
       fprintf(arquivo, "\n");
       fclose(arquivo);
       printf("\33[H\33[2J");
       printf("Contato adicionado com sucesso!\n");
       printf("\nPara adicionar mais contatos digite 1\n");
       printf("\nPara retornar ao menu digite        0\n");
       printf("\nEntrada:");
       scanf("%d", &entrada);
       printf("\33[H\33[2J");
     }
  n = colocaid(arquivo, nomearquivo);
    if (entrada == 0)
       return(MEX);
}



int colocaid(FILE *arquivo, char nomearquivo[MAX])
{ 
 int  id, verid, verie;
 char c;

   arquivo = fopen(nomearquivo, "r+");
   verie = VERIE;
   id = 0;
   verid = IDINICIAL;
   fseek(arquivo, verid, 0);
   fprintf(arquivo, "%d", id);
   fseek(arquivo, verie, 0);
   c = getc(arquivo);
   verid = VERID;
   verie = verie + VERIE;
    
     while (c != EOF)
      {
       fseek(arquivo, verid, 0);
       id = id ++;
       fprintf(arquivo, "%d", id);
       fseek(arquivo, verie, 0);
       c = getc(arquivo);
       verie = verie + VERIE;
       verid = verid + VERID - IDINICIAL;
      }

   fclose(arquivo);
   return(id);
} 




int remover(FILE *arquivo, char nomearquivo[MAX])
{
  int entrada, tamanho, id, posicao, espaco, d, posinome, positel, posiemail, linha;
  char candidato[LINHA];

    tamanho = colocaid(arquivo, nomearquivo); 
    entrada = MAX;
    arquivo = fopen(nomearquivo, "r+");
    posinome = POSINOME;
    positel = POSITEL;
    posiemail = POSIEMAIL;
	  
    printf("\33[H\33[2J");
    printf("**Remocao de contato**\n\n");
    printf("Para remover um contato eh necessario a do ID do contato.");

             while(entrada != 0)
         	{  
	   	 printf("\nPara realizar uma pesquisa por contato entre com 1");
	   	 printf("\nPara realizar a remocao entre com                2");
       	  	 printf("\nPara sair entre com                              0");
 	  	 printf("\n\nEntrada:");
	  	 scanf("%d", &entrada);
             	 printf("\33[H\33[2J");
                     if (entrada == 0)
                        return(MAX);
                     if (entrada == 1) 
                         d = pesq(arquivo, nomearquivo);
              	     if (entrada == 2)
              	       {
               	     	printf("\33[H\33[2J");
               		printf("**REMOCAO**\n");
              		printf("Entre com o ID do contato que deseja remover da agenda:");
               		scanf("%d", &id);
               		arquivo = fopen(nomearquivo, "r+");
               		linha = id * LINHA;      
               		fseek(arquivo, linha, 0);
               		fgets(candidato, LINHA, arquivo);
               		printf("Tem certeza que deseja remover o contato de ID:%d\n",id);
               		printf("\n%s\n",candidato);  
               		entrada = 22;

           		  while((entrada != 1) && (entrada != 2) && (entrada != 0))
              			{
              			 printf("Entre com 1 para SIM, 2 para NAO\n");
             		 	 printf("Entrada:");
               			 scanf("%d", &entrada);
               			      if(entrada == 1)
               				{
                			 posicao = linha + posinome;
                			 fseek(arquivo, posicao, 0);
                				for (espaco = 0; espaco != TAMANHO; espaco ++)
                    	   			     fprintf(arquivo, " ");
                 			 posicao = linha + positel;
                 			 fseek(arquivo, posicao, 0);
                        			for (espaco = 0; espaco != TAMANHO; espaco ++)
                            			    fprintf(arquivo, " ");
                 			 posicao = linha + posiemail;
                			 fseek(arquivo, posicao, 0);
                        			for (espaco = 0; espaco != TAMANHO; espaco ++)
                            			    fprintf(arquivo, " ");
                 			 printf("\33[H\33[2J");
                 			 printf("***REMOCAO REALIZADA***\nPara remover outro contato entre com 1");
                 			 printf("\nPara sair entre com 0");
                 			 printf("\nEntrada:");
                 			 scanf("%d", &entrada);
                 			 printf("\33[H\33[2J");
               			        } 

				      if (entrada == 0)
                    		         return(MAX);
				  		
               			      if(entrada == 2)
		                        {
                		         printf("\33[H\33[2J");
                 		         printf("***Remocao abortada***\nPara remover outro contato entre com 1");
                 		         printf("\nPara sair entre com 0");
                 		         printf("\nEntrada:"); 
		 			 scanf("%d", &entrada);
                 			 printf("\33[H\33[2J");
                 				if (entrada == 0)
                    				   return(MAX);
                 			}
                 	             printf("\33[H\33[2J");
                 	    	     printf("\nEntrada invalida\n");
                                   }
                        }
                }
       fclose(arquivo);
       return(MAX);
 }

int pesq(FILE *arquivo, char nomearquivo[MAX])
{
 int tamanho, n, linha, nada, entrada, posinome, positel, posiemail;
 char c;
 char pesquisa[LINHA], pesquisado[LINHA];
 char *ponteiro;
   
   entrada = MAX;
   arquivo = fopen(nomearquivo, "r");
   fseek(arquivo, 0, 0);

     while (entrada != 0)
      {
 	printf("\33[H\33[2J");
 	printf("***Pesquisa***\n\n");
 	printf("Para pesquisar por nome digite:      1\n");
 	printf("Para pesquisar por telefone digite:  2\n");
 	printf("Para pesquisar por e-mail digite:    3\n");
 	printf("Para pesquisar todas as ocorrencias: 4\n");
 	printf("Para voltar digite:                  0\n\nEntrada:");
 	fflush(stdin);
 	scanf("%d", &entrada);
	  
	    if (entrada == 0)
    	       break;

 	printf("\33[H\33[2J");
 	printf("Entre com os dados da sua pesquisa\nEntrada:");
 	fflush(stdin);
 	n = 0;
  	c = getchar();
        c = getchar();

		while (c != '\n')
		  {
                    pesquisa[n] = c;
		    c = getchar();
                    n++;
		  }
 
		  pesquisa[n] = '\0';

 	tamanho = colocaid(arquivo, nomearquivo);
  	printf("Ocorrencia(s) de %s:\n\n", pesquisa);
  	linha = 0;
  	nada = 0;
  	posinome = POSINOME;
  	positel = POSITEL;
  	posiemail = POSIEMAIL;
        n = 0;
  		while (n <= tamanho)
  		 {
  		  fseek(arquivo, linha, 0);
 
			 if (entrada == 1)
   			    {
   			     fseek(arquivo, posinome, 0);
   			     fgets(pesquisado, TAMANHO, arquivo);
                            }

   			 if (entrada == 2)
   			    {
   			     fseek(arquivo, positel, 0);
   			     fgets(pesquisado, TAMANHO, arquivo);
   			    }

   			if (entrada == 3)
   			   {
   			    fseek(arquivo, posiemail, 0);
   			    fgets(pesquisado, TAMANHO, arquivo);
   			   }

   			if (entrada == 4)
    			   {
   			    fseek(arquivo, linha, 0);
   			    fgets(pesquisado, LINHA, arquivo);
   			   }

                    ponteiro = strcasestr(pesquisado, pesquisa);
   
			if (ponteiro != NULL)
   			   {
   			    nada ++;
   			    fseek(arquivo, linha, 0);
   			    fgets(pesquisado, LINHA, arquivo);
   			    printf("%s\n", pesquisado);
   			   }

  		   n ++;
   		   linha = n * LINHA;
   		   posinome = linha + POSINOME;
   		   positel = linha + POSITEL;
   		   posiemail = linha + POSIEMAIL;
  	         }

          if (nada == 0)
  	     printf("Nao foi encontrado nem uma ocorrencia de: %s na agenda.\n", pesquisa); 
       
       printf("\nPara realizar outra pesquisa digite 1");
       printf("\nPara voltar digite                  0");
       printf("\nEntrada:");
       scanf("%d", &entrada);
    }
 
  printf("\33[H\33[2J");
     
   if (entrada == 0)
      {
       fclose(arquivo);
       return(MAX);
      }
  }




int modifica(FILE *arquivo, char nomearquivo[MAX])
{
 int entrada, id, posicao, espaco, d, posinome, positel, posiemail, linha, n;
 char candidato[LINHA], c;

 
   entrada = MAX;
   arquivo = fopen(nomearquivo, "r+");
   posinome = POSINOME;
   positel = POSITEL;
   posiemail = POSIEMAIL;

   printf("\33[H\33[2J");
   printf("**Edicao de contato**\n\n");
   printf("Para editar um contato eh necessario a do ID do contato.");
        
		while(entrada != 0)
		 {
		   printf("\nPara realizar uma pesquisa por contato entre com 1");
		   printf("\nPara realizar a edicao  entre com                2");
		   printf("\nPara sair entre com                              0");
		   printf("\n\nEntrada:");
		   scanf("%d", &entrada);
			if (entrada == 0)
			    return(MAX);
		   printf("\33[H\33[2J");
		      if (entrada == 1)
			    d = pesq(arquivo, nomearquivo);
		      if (entrada == 2)
			 {
			  printf("\33[H\33[2J");
			  printf("**EDICAO**\n");
			  printf("Entre com o ID do contato que deseja editar na agenda:");
			  scanf("%d", &id);
			  arquivo = fopen(nomearquivo, "r+");
			  linha = id * LINHA;
			  fseek(arquivo, linha, 0);
			  fgets(candidato, LINHA, arquivo);
			  printf("Tem certeza que deseja EDITAR o contato de ID:%d\n",id);
			  printf("\n%s\n",candidato);
			  entrada = 22;

				while((entrada != 1) && (entrada != 2) && (entrada != 0))
				 {
				  printf("\nDigite 1 para SIM");
				  printf("\nDigite 2 para NAO");
				  printf("\nEntrada:");
				  scanf("%d", &entrada);
					 if (entrada == 0)
					    return(MAX);
               

					 if(entrada == 1)
					   {
					    printf("\33[H\33[2J");
					    printf("\nPara editar o Nome digite     1");
					    printf("\nPara editar o Telefone digite 2");
					    printf("\nPara editar o E-mail digite   3");
					    printf("\nEntrada:");
					    scanf("%d", &entrada);
              
						   if (entrada == 1)
						     {
						      printf("\33[H\33[2J");
						      printf("Entre com o novo nome:");
						      n = 0; 
						      posicao = linha + posinome;
						      fseek(arquivo, posicao, 0);
								for (espaco = 0; espaco != TAMANHO; espaco ++)
								    fprintf(arquivo, " ");
						      fseek(arquivo, posicao, 0);
			 
						      c = getchar();
						      c = getchar();

								while (c != '\n')
								 {
								  dados.nome[n] = c;
								  c = getchar();
								  n++;
								 }

						     dados.nome[n] = '\0';
						     n = (strlen(dados.nome));
						     fputs(dados.nome, arquivo);

								   for (n; n != MEX; n++)
								       fprintf(arquivo, " ");

						     fclose(arquivo);
						    }                      		

						if(entrada == 2)
						  {
						    printf("\33[H\33[2J");
						    printf("Entre com o novo Telefone:");
						    n = 0;
						    posicao = linha + positel;
						    fseek(arquivo, posicao, 0);
							 for (espaco = 0; espaco != TAMANHO; espaco ++)
							      fprintf(arquivo, " ");
						    fseek(arquivo, posicao, 0);
				
						     c = getchar();
						     c = getchar();

							  while (c != '\n')
							   {
							    dados.tel[n] = c;
							    c = getchar();
							    n++;
							   }

						    dados.nome[n] = '\0';
						    n = (strlen(dados.tel));
						    fputs(dados.tel, arquivo);

							 for (n; n != MEX; n++)
							     fprintf(arquivo, " ");

						    fclose(arquivo);
						 }

						  if (entrada == 3)
						    {
						     printf("\33[H\33[2J");
						     printf("Entre com o novo E-mail");
						     n = 0;
						     posicao = linha + posiemail;
						     fseek(arquivo, posicao, 0);
							  for (espaco = 0; espaco != TAMANHO; espaco ++)
							       fprintf(arquivo, " ");

						     fseek(arquivo, posicao, 0);

						      c = getchar();
						      c = getchar();
					
							  while (c != '\n')
							   {
							    dados.email[n] = c;
							    c = getchar();
							    n++;
							    }

						     dados.nome[n] = '\0';
						     n = (strlen(dados.email));
						     fputs(dados.email, arquivo);

							for (n; n != MEX; n++)
							    fprintf(arquivo, " ");

						      fclose(arquivo);
						    }

						printf("\33[H\33[2J");
						printf("***EDICAO REALIZADA***\nPara editar outro contato entre com 1");
						printf("\nPara sair entre com 0");
						printf("\nEntrada:");
						scanf("%d", &entrada);
						printf("\33[H\33[2J");

							if (entrada == 0)
							   return(MAX);              
                                           } 

		       if(entrada == 2)
			 {
			  printf("\33[H\33[2J");
			  printf("***EDICAO abortada***\nPara editar outro contato entre com 1");
			  printf("\nPara sair entre com 0");
			  printf("Entrada:");
			  scanf("%d", &entrada);
			  printf("\33[H\33[2J");
		                if (entrada == 0)
                		    return(MAX); 
			 }

                  printf("\33[H\33[2J");
                  printf("\nEntrada invalida\n");
                }
             }
          }
        fclose(arquivo);
        return(MAX);
      }


/*void limpabuffer(void)
{
int valorlido = getchar();
while ((valorlido != '\n') && (valorlido != EOF))
valorLido = getchar();}
}
*/

