#include<stdlib.h>
#include<stdio.h>


//Os seguintes algoritmos criam a matriz esparsa;
struct lista{                 
	int valores;
	int coluna;
	struct lista*prox;
};

struct linha{
	int numlin;
	struct lista*linhaa;
	struct linha*proxi;
	
};


void criadordematriz(int linha ,int coluna,int valor,struct linha*vetorial);
void Buscadordemembro(struct linha*mem,int i , int j);
void somalinha(struct linha*man);
void somacoluna(struct linha*mem,int nummembros);
void excluimatriz(struct linha*m,int tam);

main(){
	int comando,linhas,colunas,notnulo,linhha,coluuna,valorr,mm,nn,m,n,notnulo2;
	int i = 0 ; // contadorA
	

	printf("                             Matriz Esparsa em C                          \n");
	printf("Digite o numero do item desejado para iniciar o comando sobre a Matriz:\n\n1-Criacao da Matriz mxn\n2-Exclucao da matriz\n3-Consulta dos valores de uma posicao (i, j) da matriz\n4-Consulta da soma dos valores de cada linha da matriz\n5-Consulta da soma dos valores de cada coluna da matriz\n6-Atribuicao de um valor na posicao (i, j) da matriz\n");
	scanf("%d",&comando);
	while(comando!=1){
		system("cls");
		printf("O valor entrado deve corresponder a operacao de Criacao da Matriz mxn,\npois a matriz ainda nao foi criada\npor favor digite um valor correspondente a uma operacao\n");
		scanf("%d",&comando);
	}//criou-se um tipo de menu para o usu�rio
	
		system("cls");
		printf("Por favor entre com o tamanho da matriz mxn\nsendo m = numero de linhas e n = numero de colunas\nsepare o par m,n usando espaco:\n");
		scanf("%d%d",&linhas,&colunas);
		printf("Insira agora o numero de valores nao nulos que a matriz esparsa possui: ");
		scanf("%d",&notnulo);
				
		printf("\n\nEntre com os valores nao nulos que pertencem a matriz esparsa\nInsira-os no seguinte formato ,separando-os por espaco,\"valor,linha,coluna\"\nAperte enter para inserir cada membro:\n\n");
		struct linha*vet = (struct linha*)malloc(sizeof(struct linha));
		struct lista*vett = (struct lista*)malloc(sizeof(struct lista));
				
		scanf("%d",&valorr);
		scanf("%d",&linhha);
		scanf("%d",&coluuna);
		//ir� atribuir os valores a cada componente da estrutura;
		vett->coluna = coluuna; //aloca a coluna do primeiro membro na primeira posi��o do vetor de listas vet;
		vett->valores = valorr;
		vett->prox = NULL; // aterra a lista;
		vet->proxi = NULL; //aterra o vetor de listas;
		vet->numlin = linhha;
		vet->linhaa = vett; // atribui um novo membro no "vetor" de listas;
		
		//ir� inserir novos membros;
		for(i;i<notnulo-1;i++){
			printf("Entre com o valor do proximo membro ,inserindo-o no seguinte formato:\n \"valor,linha,coluna\"\n\n");
			scanf("%d",&valorr);
			scanf("%d",&linhha);
			scanf("%d",&coluuna);
			criadordematriz(linhha,coluuna,valorr,vet);
		}
	
		system("cls");
		printf("\aOs valores foram armazendos com sucesso!");
		
do{
	printf("\n\nDigite o numero do proximo comando e 0 para sair :\n\n2-Exclucao da matriz\n3-Consulta dos valores de uma posicao (i, j) da matriz\n4-Consulta da soma dos valores de cada linha da matriz\n5-Consulta da soma dos valores de cada coluna da matriz\n6-Atribuicao de um valor na posicao (i, j) da matriz\n ");
	scanf("%d",&comando);	
	system("cls");
	if(comando == 2){
		
		excluimatriz(vet,colunas);
		system ("pause");
	}
	if(comando == 3){
		printf("Entre com os valores mxn do membro a ser procurado, separando m e n por espaco:\n");
		scanf("%d%d",&mm,&nn);
		if(mm>linhas || nn>colunas){ // caso o membro n�o exista na matriz;
			printf("\a O membro procurado nao existe na matriz!");
		}
		Buscadordemembro(vet,mm , nn); //chama a fun�ao que localiza e imprime o membro buscado;
		system ("pause");
	}
	if(comando == 4){
		
		somalinha(vet);
		system ("pause");
	}
	if(comando == 5){
		
		somacoluna(vet,notnulo);
		system ("pause");
		
	}
	if(comando == 6){
		printf("Insira agora o numero de valores nao nulos que a matriz esparsa possui: ");
		scanf("%d",&notnulo2);
		//come�o do comando 6 --> atribui��o de valores na posi��o ij da matriz.		
		//ir� inserir novos membros;
		for(i;i<notnulo;i++){
			printf("Entre com o valor do proximo membro ,inserindo-o no seguinte formato:\n \"valor,linha,coluna\"\n\n");
			scanf("%d%d%d",&valorr,&linhha,&coluuna);
			criadordematriz(linhha,coluuna,valorr,vet);
		}
		system("cls");
		printf("\aOs valores foram armazendos com sucesso!\n");
		
		system("pause");
		
	}
	
} while(comando != 0);
	

	
}



criadordematriz(int linha,int coluna,int valor,struct linha*vetorial){
	int j =0;
	int k;
	
	if( vetorial->numlin!=linha && vetorial->proxi==NULL && valor != 0){ //cria uma nova linha caso ela n�o exista;
			
		struct linha*novalin = (struct linha*)malloc(sizeof(struct linha));
		struct lista*novovett = (struct lista*)malloc(sizeof(struct lista));
		
		novovett->prox =NULL;
		novovett->valores = valor;
		novovett->coluna =coluna;
		novalin-> numlin = linha;
		novalin-> proxi = NULL;
		novalin->linhaa = novovett;
		
		vetorial->proxi=novalin; //faz o anterior apontar para o novo
		
		k = 8 ;
		
	}
	
	if(vetorial->numlin == linha && valor != 0 && k == 0){ //caso em que ser� inserido um membro em uma mesma linha
		struct lista*aux;
		aux = vetorial->linhaa;
		while(aux->prox !=NULL){ //procura o ultimo membro da lista(linha);
			aux=aux->prox;
		}
		struct lista*novovettt = (struct lista*)malloc(sizeof(struct lista));
		novovettt->prox =NULL;
		novovettt->valores = valor;
		novovettt->coluna =coluna;
		aux->prox = novovettt;
		
		k = 9;
	}
	
	if(vetorial->numlin!=linha && valor!=0 && k==0){ // inser��o comum // variavel k para controlar o armazenamento , evitando que um valor seja armazenado duas vezes
		struct linha*estagi;
		estagi = vetorial;
		while(estagi->numlin!=linha){ // primeiro busca a linha correta
			estagi = estagi->proxi;
		}
		if(estagi->numlin == linha){ //depois de encontra a linha procura a coluna
			struct lista*estagi2;
			estagi2 = vetorial->linhaa;
			while(estagi2->prox!=NULL){
				estagi2=estagi2->prox;
			}
			struct lista*novovetttt = (struct lista*)malloc(sizeof(struct lista)); //aloca o novo membro
			novovetttt->prox =NULL;
			novovetttt->valores = valor;
			novovetttt->coluna =coluna;
			estagi2->prox = novovetttt;
		}
		
		k = 10;
	}	
	
	if(valor == 0){
		printf("\a\a O valor nao foi inserido na matriz pois representa uma valor nulo.");
	}
	
	//printf("\n\n%d\n\n",k);
	
}

Buscadordemembro(struct linha*mem,int i , int j){
		struct linha*estagi;
		estagi = mem;
		while(estagi->numlin!=i && estagi!= NULL ){ // primeiro busca a linha correta
			estagi = estagi->proxi;
		}
		if(estagi == NULL){ //  caso o valor n�o esteja na matriz esparsa ele ser� o valor nulo!;
			printf("O  valor do membro buscado eh 0");
		}
		if(estagi->numlin == i){ //depois de encontra a linha procura a coluna
			struct lista*estagi2;
			estagi2 = mem->linhaa;
			while(estagi2->coluna!=j && estagi2 !=NULL){
				estagi2=estagi2->prox;
			}
			if(estagi2 == NULL){
				printf("O  valor do membro buscado eh 0");
			}
			
			printf("\nO mebro K%d-%d eh %d\n",i,j,estagi2->valores); // imprime o valor procurado
    	}
    	
}

somalinha(struct linha*man){ // fun��o que ir� somar os valores de uma mesma linha
	int p;
	int r;
	
	struct linha*aux;
	aux = man;
	struct lista*aux2;
	aux2 = aux->linhaa;
	
	while(aux!=NULL){
		p=0;
		r=0;
		while(aux2!=NULL){
			r = r + aux2->valores;
			aux2 = aux2->prox;
		}
	
		printf("\nA soma da linha %d eh %d\n",aux->numlin,r);
		aux = aux->proxi;
		if(aux!=NULL){
			aux2 = aux->linhaa;
		}
	}
	
}


somacoluna(struct linha*mem,int nummembros){ // fun��o que soma os valores de uma mesma coluna;
	int q=0;int j = 1;int w = 0;int r;
	
	struct linha*auxx;
	auxx = mem;
	struct lista*auxx2;
	auxx2 = auxx->linhaa;
	
	while(w<nummembros){
		while(auxx!=NULL){
			while(auxx2!=NULL){
				if(auxx2->coluna == j){
					r = q + auxx2->valores;
				}
				auxx2 = auxx2->prox;
			}
			auxx = auxx->proxi;
			if(auxx!=NULL){
				auxx2 = auxx->linhaa;
			}
		}
		printf("\nA soma da coluna %d eh %d\n",j,r);
		j++; // variaavel que indica o numero da coluna;
		w++;//variavel que percorre toda a matriz esparsa;
		auxx = mem;
		auxx2 = auxx->linhaa;
		
	}

	
}

void excluimatriz(struct linha*m,int tam){
	
	int i=0;
	struct lista *liberta;
	
	while(i<tam && m!=NULL){
		if(m->linhaa!=NULL){
			while(m->linhaa!=NULL){
   				liberta = m->linhaa;
   				m->linhaa = m->linhaa->prox;
   				free (liberta);
			}
		}
		m = m->proxi;
		i++;
	}
	free(m);
	
	printf("\a\a\n\nSUA MATRIZ FOI EXCLUIDA COM SUCESSO!!\n");
	
}
