// === Bibliotecas ===

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 #include <locale.h>
 #include <unistd.h>
 
// === Constante ===
 
 #define MAX 9999

// === Declara��o das fun��es ===

 void menu();
 void cadastrar();
 void alterar();
 void buscaPorID();
 void buscaPorNome();
 void remover();
 void listarCad();

// === Declara��o da Struct ===

struct cliente{
	
  char nome[30];
  char setor[30];
  int idade;
  int codigo;
  int telefone;
  int ativo;
  
}Cliente[MAX]; // Suporta at� 9999 cadastros

//Fun��o para busca linear por string (usada no menu na fun��o buscaPorNome)


int buscaNome(struct cliente *Cliente, int N, char *elem_nome){
	
  int i;

  for(i = 0; i < N; i++){
    //setbuf(stdin, 0);
	 
    //printf("debug: texto.:\"%s\", Cliente[i].nome.: \"%s\"", elem_nome, Cliente[i].nome);
    if(strcmp(elem_nome, Cliente[i].nome) == 0){
    	
      return i; //nome encontrado
    }
  }
  return -1; //nome n�o encontrado
}
 

// === Fun��o para o Menu

void menu(){
	
  setlocale(LC_ALL,"Portuguese");
  int num;
  
  //loop de repeti��o do menu caso escolha op��o invalida
  
  do{
    system("cls");
    printf("\n ===|  SISTEMA DE CADASTRO    | ===");
    printf("\n ===|  1 - Cadastrar          | ===");
    printf("\n ===|  2 - Alterar cadastro   | ===");
    printf("\n ===|  3 - Pesquisar por nome | ===");
    printf("\n ===|  4 - Pesquisar por ID   | ===");
    printf("\n ===|  5 - Remover cadastro   | ===");
    printf("\n ===|  6 - Listar cadastro    | ===");
    printf("\n ===|  0 - Sair do sistema    | ===\n");
    printf("\n Digite sua op��o: ");
    scanf("%d",&num);
    
    switch(num){
      case 1:
        cadastrar(); 
        break;
      case 2:
        alterar();
        break;
      case 3:
        buscaPorNome();
        break;
      case 4:
        buscaPorID();
        break;
      case 5:
        remover();
        break;
      case 6:
        listarCad();
        break;
    }
  }while(num != 0);
  
  system("cls");
  printf("\n Saindo do sistema...\n");
  sleep(3);
}
 
// === Fun��o para cadastrar ===

void cadastrar(){
	
  char nome[30];
  char setor[30];
  int ID; 
  int i;
  int resp; 

  system("cls");

  for(i = 0; i < MAX; i++){
    setbuf(stdin, 0);
    system("cls");

    if(Cliente[i].ativo == 0){
    
      printf("=== CADASTRAMENTO ===\n");
      setbuf(stdin, 0);
      printf("Informe seu nome: ");
      setbuf(stdin, 0);
      gets(Cliente[i].nome); 
      printf("Informe sua idade: ");
      setbuf(stdin, 0);
      scanf("%d", &Cliente[i].idade);
      printf("Informe seu telefone: ");
      setbuf(stdin, 0);
      scanf("%d", &Cliente[i].telefone);
      printf("Informe seu setor: ");
      setbuf(stdin, 0);
      gets(Cliente[i].setor);

      srand(time(NULL));
      ID = rand()%10000;
      Cliente[i].codigo = ID;
      
      Cliente[i].ativo = 1;
      setbuf(stdin, 0);
      
      printf("\n Processando ...\n");
      sleep(3);
      printf("\n Cadastro realizado com sucesso! \n");
      
      printf("\nDeseja continuar? [1(SIM)/0(NAO)]: ");
      setbuf(stdin, 0);
      scanf("%d", &resp);
      
      if(resp == 1){
      	
        continue;
        system("cls");
        
      }else if(resp == 0) {
      	
          system("cls"); 
      }
      
      break;  
	   
    }
    
  }
  
}
 
// === Fun��o para alterar cadastro ===

void alterar(){
	
	int i;
    int nova_idade;
    int aux_idade = 0;
	int alterar;
	int resp;
    char texto[30];	
  
  do{
    system("cls");
    printf("\n === ALTERAR CADASTRO === \n");
    printf(" ==| 1 - Alterar nome     |== \n");
    printf(" ==| 2 - Alterar idade    |== \n");
    printf(" ==| 3 - Alterar telefone |== \n");
    printf(" ==| 4 - Alterar setor    |== \n");
    printf("\n Op��o.: ");
    scanf("%d", &alterar);
    
    printf("\nDigite o nome do cliente: ");
    setbuf(stdin, 0);
    gets(texto);
    
    
    i = buscaNome(Cliente, MAX, texto); // fun��o para obter o indice do elemento
    
    printf("\n === Alterando por nome === \n");
    switch(alterar){
    	
     case 1:
        	
          setbuf(stdin, 0);
          printf("\nInforme o novo nome: ");
          setbuf(stdin, 0);
          gets(Cliente[i].nome);
          sleep(2);
          printf("Nome alterado com sucesso!");
          
     break;

      case 2:
        
        printf("\nInforme a nova idade: ");
        setbuf(stdin,0);
        scanf("%d",&Cliente[i].idade);
        sleep(2);
        printf("Idade alterada com sucesso!");

      break;

        case 3:
      
          printf("\nInforme nome do novo telefone.: ");
          setbuf(stdin,0);
          scanf("%d",&Cliente[i].telefone);
          sleep(2);
          printf("Telefone alterado com sucesso!");

        break;
        
          case 4:
      
          printf("\nInforme nome do novo .: ");
          setbuf(stdin,0);
          gets(Cliente[i].setor);
          sleep(2);
          printf("Setor alterado com sucesso!");

          break;
           
      }
      
      printf("\n\nDeseja continuar? [1(SIM)/0(NAO)].: ");
      scanf("%d", &resp);

      if(resp == 1){
      	
        system("cls");
        continue;
        
      }else if(resp == 0){
      	
        system("cls"); 
    }
    
  }while(resp == 1);
  
}
 
 
// === Fun��o para pesquisar cadastro ===


void buscaPorNome(){
  char texto[30];
  int indice;
  int resp;
  

  do{
    system("cls");
    printf("\n === PESQUISA DE CADASTRO POR NOME === \n");
    printf("Digite o nome: ");
    setbuf(stdin, 0);
    gets(texto);

    indice = buscaNome(Cliente, MAX, texto);

    //printf("\n -----------DEBUG:  indice.: %d\n", indice + 1);
    
    if(indice != -1){
    	
        //printf("OK\n");
        
        if(Cliente[indice].ativo == 1){
            printf("\n -----------Cliente %d ------------------\n\n", indice + 1);
            printf("\t Nome:  %s \n",   Cliente[indice].nome);
            printf("\t Idade: %d \n",   Cliente[indice].idade);
            printf("\t Setor: %s \n",   Cliente[indice].setor);
            printf("\t Codigo: %d \n",  Cliente[indice].codigo);
            printf("\t Telefone: %d \n",Cliente[indice].telefone);
            printf("\n -----------------------------------------\n");
        } else{
        	
          printf("Cliente inativo\n");
          
      }
        
    }else {
    	
      printf("Cliente n�o encontrado!!\n");
    }

    printf("\nDeseja continuar? [1(SIM)/0(NAO)].: ");
    scanf("%d", &resp);

    if(resp == 1){
      system("cls");
      continue;
    }else if(resp == 0){
      system("cls"); 
    }
  }while(resp == 1);
}

// === Fun��o para pesquisar por n�mero cadastros ===

void buscaPorID(){
  setlocale(LC_ALL,"Portuguese");
  int i;
  int codpesquisa;
  int resp;

  system("cls");
  
  do{
    printf("\n === PESQUISA DE CADASTRO POR CODIGO === \n");
 
    printf("\n -----------Cliente  ------------------\n\n");
    for(i = 0; i < MAX; i++){
  	  if(Cliente[i].ativo == 1){
        printf("\t C�digo: %d\tNome:  %s\n", Cliente[i].codigo, Cliente[i].nome);

      }
    }
    printf("\n ---------------------------------------\n");
   
    printf("\n Informe o c�digo do cliente.: ");
    scanf("%d", &codpesquisa);
  
    for(i = 0; i < MAX; i++){
      if(Cliente[i].codigo == codpesquisa){
        
        if(Cliente[i].ativo == 1){
          printf("\n ------------Cliente %d ------------------\n\n", i+1);
          printf("\t Nome:  %s \n",   Cliente[i].nome);
          printf("\t Idade: %d \n",   Cliente[i].idade);
          printf("\t Setor: %s \n",   Cliente[i].setor);
          printf("\t Codigo: %d \n",  Cliente[i].codigo);
          printf("\t Telefone: %d \n",Cliente[i].telefone);
          printf("\n ------------------------------------------\n");
          
          printf("\nDeseja continuar? [1(SIM)/0(NAO)].: ");
          setbuf(stdin, 0);
          scanf("%d", &resp);
          
          if(resp == 1){
            system("cls");
            continue;
          }else if(resp == 0){
            system("cls"); 
          }
        }
      }
    }
    system("cls");
  }while(resp == 1);
}
  
// === Fun��o para exibir cadastros ===

void listarCad(){
  
  int i;
  char resp;
  char nome[30];
  char setor[30];
  char l;
  
  system("cls");
  
  printf("\tLISTA DE CADASTROS\n");
  
  for(i = 0; i < MAX; i++){
  	
  	if(Cliente[i].ativo == 1){
  			
  	printf("\n -----------Cliente %d ------------------\n\n", i+1);
  	printf("\t Nome:  %s \n",   Cliente[i].nome);
  	printf("\t Idade: %d \n",   Cliente[i].idade);
  	printf("\t Setor: %s \n",   Cliente[i].setor);
  	printf("\t Codigo: %d \n",  Cliente[i].codigo);
  	printf("\t Telefone: %d \n",Cliente[i].telefone);
  	printf("\n ---------------------------------------\n");
	  }
  }
  
   printf("\n Voltando ao menu ... ");
   setbuf(stdin, 0);
   getc(stdin);
   system("cls");
}

// === Fun��o para remover cadastro ===

void remover(){
 int i;
 int resp;
 int codpesquisa;
  
   system("cls");
  
  do{
  
    printf("\n ===== EXCLUS�O DE CADASTROS POR CODIGO ==== \n");
  	
    printf("\n -----------Cliente  ------------------\n\n");
    for(i = 0; i < MAX; i++){
  	  if(Cliente[i].ativo == 1){
        printf("\t C�digo: %d\tNome:  %s\n", Cliente[i].codigo, Cliente[i].nome);

      }
    }
    printf("\n ---------------------------------------\n");


    printf("\n Informe o c�digo do cliente que deseja excluir  \n");
  	printf("C�digo: ");
    scanf("%d", &codpesquisa);
  	
  	for( i = 0; i<MAX; i++){
      
      if(Cliente[i].codigo == codpesquisa){
  		  printf("\n -----------Cliente %d ------------------\n\n", i+1);
        printf("\t Nome:  %s \n",   Cliente[i].nome);
        printf("\t Idade: %d \n\n", Cliente[i].idade);
        printf("\t Setor: %s \n",   Cliente[i].setor);
        printf("\t Codigo: %d \n",  Cliente[i].codigo);
        printf("\t Telefone: %d \n", Cliente[i].telefone);
        printf(" ---------------------------------------\n");
        
        system("pause");
        system("cls");      
        printf("\n Processando...\n");
        sleep(2);
      
        Cliente[i].ativo = 0;
        printf("\n Exclus�o realizada com sucesso ! \n");
        printf("\nDeseja continuar? [1(SIM)/0(NAO)].: ");
        scanf("%d", &resp);	  	
      }
		}
   	system("cls");
  }while(resp == 1);
}



// === Fun��o Principal ===

int main(){
	
  // === Vari�veis ===
  
  // === C�digo ===
  
  // === Menu de op��es ===
  
  menu();
  
  
  
  return 0; 
}
