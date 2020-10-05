/*
 								SINETRAM
Desenvolva um sistema para controlar a venda de passagem estudantil. O administrador
cadastrado e inicializado com login=ADM e senha=123. O administrador cadastrar funcionário:
nome, matricula, endereço (rua, casa, bairro), telefone, login e senha. O administrador cadastrar
curso: Nome curso, sigla curso .O administrador cadastrar instituições de ensino (faculdade,
curso técnico, curso preparatório) : nome, endereço(rua, número ,bairro), CNPJ , telefone, o
curso que é oferecido ( o sistema exibe todos os cursos, é adicionado para instituição o curso).
O administrador cadastrar alunos: nome, matricula, curso e faculdade ( a faculdade é adicionada
automaticamente após preencher o curso e verificado se existe o curso para a
instituição),login(e-mail do aluno),senha(alfanumérico ). O administrador validar cadastro:
quando os alunos forem cadastrados receberam status de “INATIVO”, quando mais de um aluno
for cadastrado é iniciado uma fila de espera, que aparecerá para administrador e o
administrador irar liberar um ou todos os cadastros, logo os alunos receberão status “ATIVO”,
validando e liberando as funcionalidades do aluno no sistema. O administrador poderá realizar
venda de passagem: Pesquisar o aluno por matricula, o sistema lista os dados dos alunos(nome,
matricula, curso, instituição de ensino) , o aluno carregar o valor desejado, o sistema calcula e
exibe quantos créditos que é equivalente ao número de passagens , caso o valor não seja
totalizado na comprar dos créditos o restante ficar como saldo e será exibido ao aluno quando
necessário poderá ser adicionado a próxima recarga do aluno.

O funcionário poderá cadastrar aluno, realizar venda de passagens.
O aluno poderá logar no sistema e ver o total de créditos e o saldo caso tenha.

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Login{
	char usuario[30];
	char senha[30];
}Login;

typedef struct Contato{
	char rua[30];
	char casa[30];
	char bairro[30];
	char telefone[15];
}Contato;


typedef struct Funcionario{
	char nome[50];
	char matricula[30];
	Contato contato;
	Login login;
}Funcionario;

typedef struct Curso{
	char nome[30];
	char siglaCurso[20];
}Curso;

typedef struct Instituicao{
	char nome[30];
	Contato contato;
	char cnpj[20];
	Curso curso[20];
	int qtdCursosCadastrados;
}Instituicao;


typedef struct Aluno{
	char nome[30];
	char matricula[30];
	Curso curso;
	Instituicao instituicao;
	Login login;
	char status[20];
	float credito;
	float creditoDisponivel;
}Aluno;

// cadastro
void cadastrarFuncionario();
void cadastrarCurso();
void cadastrarInstituicao();
void cadastrarAluno();

//listagem de informações
void listarFuncionario();
void listarCurso();
void listarInstituicao();
void listarAluno();
void listarAlunoInativo();

//funcionalidades
void validarCadastro();
void vendaPassagem();
void saldoAluno();


//login
void loginFuncionario();
void loginADM();
void loginAluno();

// menu
void menuPrincipal();
void menuADM();
void menuFuncionario();
void menuAluno();

// variaveis

//variaveis para funcionario
Funcionario funcionario[30];
int tamanhoFuncionario = 0;

//variaveis para  curso
Curso curso[30];
int tamanhoCurso = 0;

//variaveis para Instituição
Instituicao instituicao[30];
int tamanhoInstituicao = 0;

//variaveis para Aluno
Aluno aluno[30];
int tamanhoAluno = 0;
int alunoAcessou;



main(){
	menuPrincipal();
}







// cadastro
void cadastrarFuncionario(){
	int op;
	
	do{
		system("cls");
		printf("\n=======================CADASTRO DE FUNCIONARIO==================\n");
		printf("\nDigite o nome: ");
		fflush(stdin);
		gets(funcionario[tamanhoFuncionario].nome);
		printf("\nDigite a matricula: ");
		fflush(stdin);
		gets(funcionario[tamanhoFuncionario].matricula);
		
		// guardando a matricula na variavel usuario para ser usaso no acesso.
		strcpy(funcionario[tamanhoFuncionario].login.usuario, funcionario[tamanhoFuncionario].matricula);
		system("cls");
		printf("\n=======================CADASTRO DE FUNCIONARIO==================\n");
		printf("\n===========================================");
		printf("\n\n*Seu usuario sera sua matricula\n");
		printf("\nUsuario: %s",funcionario[tamanhoFuncionario].login.usuario);
		printf("\nCrie uma senha: ");
		fflush(stdin);
		gets(funcionario[tamanhoFuncionario].login.senha);
		//atualizando a quantidade de funcionarios guardados.
		tamanhoFuncionario++;
		system("cls");
		printf("\n=======================CADASTRO DE FUNCIONARIO==================\n");
		printf("\n\nUsuario cadastrado com sucesso!\n");
		printf("\nO que deseja fazer: \n[ 1 ] Cadastrar outro Funcionario\n[ 0 ] Sar\n\n-->");
		scanf("%d",&op);
	}while(op != 0);
}


void cadastrarCurso(){
	int op;
	
	do{
		system("cls");
		printf("\n=======================CADASTRO DE CURSO==================\n");
		printf("\nNome do Curso: ");
		fflush(stdin);
		gets(curso[tamanhoCurso].nome);
		printf("\nSigla do Curso: ");
		fflush(stdin);
		gets(curso[tamanhoCurso].siglaCurso);
		
		//atualizando a quantidade de cursos guardados.
		tamanhoCurso++;
		system("cls");
		printf("\n=======================CADASTRO DE CURSO==================\n");
		printf("\n\nCurso cadastrado com sucesso!\n");
		printf("\nO que deseja fazer: \n[ 1 ] Cadastrar outro Curso\n[ 0 ] Sar\n\n-->");
		scanf("%d",&op);
	}while(op != 0);	
}

void cadastrarInstituicao(){
	int op, qtdCursos, i, codigoCurso;
	
	if(tamanhoCurso <= 0){
		system("cls");
		printf("\n=======================CADASTRAR DE INSTITUICAO==================\n");
		printf("\n\nNenhum Curso Cadastrado!\n");
		printf("\n\n");
		system("pause");
	}else{
		do{
			system("cls");
			printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
			printf("\nNome da Instituicao: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].nome);
			printf("\nCNPJ da Instituicao: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].cnpj);
			printf("\n====CONTATO=====\n");
			printf("\nRua: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].contato.rua);
			printf("\nCasa: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].contato.casa);
			printf("\nBairro: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].contato.bairro);
			printf("\nTelefone: ");
			fflush(stdin);
			gets(instituicao[tamanhoInstituicao].contato.telefone);
			
			//mostrando os cursos disponiveis;
			listarCurso();
			
			printf("\n\nQuantos voce ira cadastrar: ");
			scanf("%d",&qtdCursos);
			
			for(i = 0; i < qtdCursos; i++){
		
				printf("\nCodigo do Curso: ");
				scanf("%d",&codigoCurso);
				
				// verificando se o codigo escolhido do curso é valido.
				while(codigoCurso < 0 || codigoCurso >= tamanhoCurso){
					system("cls");
					printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
					printf("\nCodigo Invalido");
					printf("\n\n");
					system("pause");
					listarCurso();
					printf("\nCodigo do Curso: ");
					scanf("%d",&codigoCurso);
				}
				
				// guardando os cursos escolhidos.
				strcpy(instituicao[tamanhoInstituicao].curso[i].nome, curso[codigoCurso].nome);
				strcpy(instituicao[tamanhoInstituicao].curso[i].siglaCurso, curso[codigoCurso].siglaCurso);
			}
			
			// guarfando a quantidade de crusos cadastrados.
			instituicao[tamanhoInstituicao].qtdCursosCadastrados = qtdCursos;
			
			//atualizando a quantidade de cursos guardados.
			tamanhoInstituicao++;
			system("cls");
			printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
			printf("\n\nInstituicao cadastrada com sucesso!\n");
			printf("\nO que deseja fazer: \n[ 1 ] Cadastrar outra Instituicao\n[ 0 ] Sar\n\n-->");
			scanf("%d",&op);
		}while(op != 0);
	}
}
void cadastrarAluno(){
		int i, j, op, codigoCurso, achou = 0;
	
	if(tamanhoCurso <= 0){
		system("cls");
		printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
		printf("\nNenhum Curso Cadastrado!\n\n");
		system("pause");
	}else if(tamanhoInstituicao <= 0){
		system("cls");
		printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
		printf("\nNenhuma Instituicao Cadastrada!\n\n");
		system("pause");
	}else{
		do{
			system("cls");
			printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
			listarCurso();
			printf("\nCodigo do Curso: ");
			scanf("%d",&codigoCurso);
			
			// verificando se o codigo escolhido do curso é valido.
			while(codigoCurso < 0 || codigoCurso >= tamanhoCurso){
				system("cls");
				printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
				printf("\nCodigo Invalido");
				printf("\n\n");
				system("pause");
				listarCurso();
				printf("\nCodigo do Curso: ");
				scanf("%d",&codigoCurso);
			}
			
			for(i = 0; i < tamanhoInstituicao; i++){
				for(j = 0; j < instituicao[i].qtdCursosCadastrados; j++){
					if(strcmp(curso[codigoCurso].nome, instituicao[i].curso[j].nome)== 0){
						achou = 1;
						//guardando o nome da instituição.
						strcpy(aluno[tamanhoAluno].instituicao.nome, instituicao[i].nome);
						strcpy(aluno[tamanhoAluno].curso.nome, curso[codigoCurso].nome);
						break;
					}
				}
			}
			
			if(achou == 0){
				system("cls");
				printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
				printf("\nEste curso nao esta disponivel nesta Instituicao!\n\n");
				system("pause");
			}else{
				printf("\nNome do Aluno: ");
				fflush(stdin);
				gets(aluno[tamanhoAluno].nome);
				printf("\nMatricula: ");
				fflush(stdin);
				gets(aluno[tamanhoAluno].matricula);
				system("cls");
				printf("\n=======================CADASTRO DE INSTITUICAO==================\n");
				printf("\nCrie um usuario e senha de acesso!\n\n");
				printf("\n*O usuario deve ser um e-mail valido!");
				printf("\n*A senha deve ser alfanumerica!");
				printf("\n===================================================\n");
				printf("\nE-mail(usuario): ");
				fflush(stdin);
				gets(aluno[tamanhoAluno].login.usuario);
				printf("\nSenha(alfanumerica): ");
				fflush(stdin);
				gets(aluno[tamanhoAluno].login.senha);
				
				//atribuindo o status do aluno
				strcpy(aluno[tamanhoAluno].status, "INATIVO");
				
				//atualizando a quantidade de cursos guardados.
				tamanhoAluno++;
				system("cls");
				printf("\n=======================CADASTRO DE ALUNO==================\n");
				printf("\n\nAluno cadastrado com sucesso!\n\n");
				system("pause");
			}
			
			system("cls");
			printf("\n=======================CADASTRO DE ALUNO==================\n");
			printf("\nO que deseja fazer: \n[ 1 ] Cadastrar outro Curso\n[ 0 ] Sar\n\n-->");
			scanf("%d",&op);
		}while(op != 0);
	}
	
}

//listagem de informações
void listarFuncionario(){
	int i;
	if(tamanhoFuncionario <= 0){
		system("cls");
		printf("\n=======================LISTAGEM DE  FUNCIONARIO==================\n");
		printf("\n\nNenhum Funcionario Cadastrado!\n");
	}else{
		system("cls");
		printf("\n=======================LISTAGEM DE  FUNCIONARIO==================\n");
		for(i = 0; i < tamanhoFuncionario; i++){
			printf("\nCodigo --> %d",i);
			printf("\nNome: %s", funcionario[i].nome);
			printf("\nMatricula: %s", funcionario[i].matricula);
			printf("\nUsuario: %s", funcionario[i].login.usuario);
			printf("\nSenha: %s", funcionario[i].login.senha);
			printf("\n==============================================");
		}	
	}
	printf("\n\n");
	system("pause");
}
void listarCurso(){
	int i;
	if(tamanhoCurso <= 0){
		system("cls");
		printf("\n=======================LISTAGEM DE  CURSO==================\n");
		printf("\n\nNenhum Curso Cadastrado!\n");
	}else{
		system("cls");
		printf("\n=======================LISTAGEM DE  CURSO==================\n");
		for(i = 0; i < tamanhoCurso; i++){
			printf("\nCodigo --> %d",i);
			printf("\nNome do Curso: %s", curso[i].nome);
			printf("\nSigla do Curso: %s", curso[i].siglaCurso);
			printf("\n==============================================");
		}	
	}
	printf("\n\n");
	system("pause");
}
void listarInstituicao(){
	int i, j;
	
	if(tamanhoInstituicao <= 0){
		system("cls");
		printf("\n=======================LISTAGEM DE  INTITUICAO==================\n");
		printf("\n\nNenhuma Instituicao Cadastrada!\n");
	}else{
		system("cls");
		printf("\n=======================LISTAGEM DE  INTITUICAO==================\n");

		for(i = 0; i < tamanhoInstituicao; i++){
			printf("\nNome da Instituicao: %s", instituicao[i].nome);
			printf("\nCNPJ da Instituicao: %s",instituicao[i].cnpj);
			printf("\n====CONTATO=====\n");
			printf("\nRua: %s", instituicao[i].contato.rua);
			printf("\nCasa: %s",instituicao[i].contato.casa);
			printf("\nBairro: %s",instituicao[i].contato.bairro);
			printf("\nTelefone: %s",instituicao[i].contato.telefone);
			printf("\n========CURSOS==============\n");
			//lisrtando os cursos cadastrados.
			for(j = 0; j < instituicao[i].qtdCursosCadastrados; j++){
				printf("\nCodigo --> %d",j);
				printf("\nNome \t \t Sigla");
				printf("\n%s \t %s", instituicao[i].curso[j].nome, instituicao[i].curso[j].siglaCurso);
			}	
			printf("\n========================================");
		}
	}
	printf("\n\n");
	system("pause");
}
void listarAluno(){
	int i, j;
	
	if(tamanhoAluno <= 0){
		system("cls");
		printf("\n=======================LISTAGEM DE ALUNO==================\n");
		printf("\n\nNenhum Aluno Cadastrado!\n");
	}else{
		system("cls");
		printf("\n=======================LISTAGEM DE ALUNO==================\n");

		for(i = 0; i < tamanhoAluno; i++){
			printf("\nCodigo --> %d",i);
			printf("\nNome do Aluno: %s",aluno[i].nome);
			printf("\nMatricula: %s",aluno[i].matricula);
			printf("\nE-mail(usuario): %s",aluno[i].login.usuario);
			printf("\nSenha(alfanumerica): %s",aluno[i].login.senha);
			printf("\nInstituicao: %s",aluno[i].instituicao.nome);
			printf("\nCurso: %s", aluno[i].curso.nome);
			printf("\nStatus: %s", aluno[i].status);
			printf("\nCredito Disponivel: %.2f",aluno[i].credito);
			printf("\n===============================================");
		}
	}
	printf("\n\n");
	system("pause");
}

void listarAlunoInativo(){
	int i, j;
	
	if(tamanhoAluno <= 0){
		system("cls");
		printf("\n=======================LISTAGEM DE ALUNO==================\n");
		printf("\n\nNenhum Aluno Cadastrado!\n");
	}else{
		system("cls");
		printf("\n=======================LISTAGEM DE ALUNO==================\n");

		for(i = 0; i < tamanhoAluno; i++){
			if(strcmp(aluno[i].status, "INATIVO") == 0){
				printf("\nCodigo --> %d",i);
				printf("\nNome do Aluno: %s",aluno[i].nome);
				printf("\nMatricula: %s",aluno[i].matricula);
				printf("\nE-mail(usuario): %s",aluno[i].login.usuario);
				printf("\nSenha(alfanumerica): %s",aluno[i].login.senha);
				printf("\nInstituicao: %s",aluno[i].instituicao.nome);
				printf("\nCurso: %s", aluno[i].curso.nome);
				printf("\nStatus: %s", aluno[i].status);
				printf("\n===============================================");
			}
		}
	}
	printf("\n\n");
	system("pause");
}


//funcionalidades
void validarCadastro(){
	int codigoAluno, opcaoAtivo, i, op, situacao = 0;
	do {
		if(tamanhoAluno < 2){
			system("cls");
			printf("\n=======================VALIDACAO DE ALUNO==================\n");
			printf("\nQuantidade de Aluno Insuficiente para operacao!\n\n");
			situacao = 1;
			system("pause");
		}else{
			listarAlunoInativo();
			printf("\nVoce deseja Ativar\n[ 1 ] Todos os Alunos\n[ 2 ] Apenas um Aluno\n\n--> ");
			scanf("%d",&opcaoAtivo);
			
			if(opcaoAtivo == 1){
				for(i = 0; i < tamanhoAluno; i++){
					//ativando todos os alunos.
					strcpy(aluno[i].status, "ATIVO");
				}
			}else if(opcaoAtivo == 2){
				printf("\nCodigo do Aluno: ");
				scanf("%d",&codigoAluno);
				//certificando que o usuario escolha um aluno valido.
				while(codigoAluno < 0 || codigoAluno >= tamanhoCurso){
					system("cls");
					printf("\n=======================VALIDACAO DE ALUNO==================\n");
					printf("\nCodigo Invalido");
					printf("\n\n");
					system("pause");
					listarAlunoInativo();
					printf("\nCodigo do Aluno: ");
					scanf("%d",&codigoAluno);
				}
				// ativando apenas o aluno escolhido.
				strcpy(aluno[codigoAluno].status, "ATIVO");
			}		
		}
		
		if(situacao == 0){
			system("cls");
			printf("\n=======================VALIDACAO DE ALUNO==================\n");
			printf("\nO que deseja fazer: \n[ 1 ] Validar outro Aluno\n[ 0 ] Sar\n\n-->");
			scanf("%d",&op);
		}
	}while(op != 0);
}
void vendaPassagem(){
	
	int i, op, diaPassagem, alunoCredito, achouAluno = 0, semAluno = 0;
	float valorDesejado, valorPassagem, valorDiarioPassagem, valorRecarga, recargaPermitida, recarga;
	char matricula[30];
	
	do {
		if(tamanhoAluno <= 0){
			system("cls");
			printf("\n=======================VENDA DE PASSAGEM==================\n");
			printf("\nNenhum Aluno Cadastrado!\n\n");
			semAluno = 1;
			system("pause");
			break;
		}else{
			system("cls");
			printf("\n=======================VENDA DE PASSAGEM==================\n");
			printf("\nDigite a Matricula do Aluno: ");
			fflush(stdin);
			gets(matricula);
			
			for(i = 0; i < tamanhoAluno; i++){
				if(strcmp(matricula, aluno[i].matricula)== 0){
					// guardando o aluno;
					alunoCredito = i;
					achouAluno = 1;
					
					printf("\nNome: %s", aluno[i].nome);
					printf("\nMatricula: %s", aluno[i].matricula);
					printf("\nCurso: %s", aluno[i].curso);
					printf("\nInstituicao: %s", aluno[i].instituicao.nome);
					printf("\nCredito Disponivel: %.2f",aluno[i].credito);
					printf("\n==================================================================\n");
					break;
				}
			}
			
			if(achouAluno == 1){
				// calculo para saber quanto ele pode recarregar 
				diaPassagem = 25;
				valorPassagem = 3.80;
				valorDiarioPassagem = valorPassagem * 2;
				valorRecarga = valorDiarioPassagem * diaPassagem;
				recargaPermitida = valorRecarga - aluno[alunoCredito].credito;
				
				printf("\nVoce pode recarregar ate: %.2f Reais", valorRecarga);
				printf("\nVoce ainda pode recarregar: %.2f", recargaPermitida);
				printf("\n\nQuando deseja recarregar: ");
				scanf("%f",&recarga);
				
				// restringindo a recarga para que seja somente o valor permitido.
				while(recarga <= 0 || recarga > recargaPermitida){
					system("cls");
					printf("\n=======================VENDA DE PASSAGEM==================\n");
					printf("\nValor informado eh invalido!\n\n");
					system("pause");
					printf("\n\nVoce pode recarregar ate: %.2f Reais", valorRecarga);
					printf("\nVoce ainda pode recarregar: %.2f", recargaPermitida);
					printf("\n\nQuando deseja recarregar: ");
					scanf("%f",&recarga);
				}
				
				// adicionado a recarga ao aluno.
				aluno[alunoCredito].credito += recarga;
				// guardando o quando ele ainda pode recarregar;
				aluno[alunoCredito].creditoDisponivel = valorRecarga - aluno[alunoCredito].credito;
			}else{
				system("cls");
				printf("\n=======================VENDA DE PASSAGEM==================\n");
				printf("\nMatricula Invalida!\n\n");
				system("pause");
			}
					
		}

		if(semAluno == 0){
			system("cls");
			printf("\n=======================VENDA DE PASSAGEM==================\n");
			printf("\nO que deseja fazer: \n[ 1 ] Realizar outra Recarga\n[ 0 ] Sar\n\n-->");
			scanf("%d",&op);
		}
	}while(op != 0);
	
}

void saldoAluno(){
	system("cls");
	printf("\n===================CREDITO DO ALUNO===================\n");
	printf("\nNome: %s", aluno[alunoAcessou].nome);
	printf("\nCredito Atual: %.2f", aluno[alunoAcessou].credito);
	printf("\nAinda Pode Recarregar: %.2f", aluno[alunoAcessou].creditoDisponivel);
	printf("\n\n");
	system("pause");
}

//login
void loginADM(){
		Login aux, userADM;
	int logou = 1;
	
	strcpy(userADM.usuario, "ADM");
	strcpy(userADM.senha, "123");
	
	do{
		system("cls");
		printf("\n===================LOGIN ADM===================\n");
		printf("\nUsuario: ");
		fflush(stdin);
		gets(aux.usuario);
		printf("\nSenha: ");
		fflush(stdin);
		gets(aux.senha);
		
		if(strcmp(aux.usuario, userADM.usuario) == 0 && strcmp(aux.senha, userADM.senha)== 0){
			logou = 0;
			menuADM();
		}else{
			system("cls");
			printf("\n===================LOGIN ADM===================\n");
			printf("\nUsuario ou senha Invalidos");
			printf("\n\nDeseja tentar outra vez\n[ 1 ] Sim\n[ 0 ] Nao\n\n-->");
			scanf("%d",&logou);
			
		}
	}while(logou == 1);	
}

void loginFuncionario(){
	Login aux;
	int logou = 0, i;
	
	if(tamanhoFuncionario <= 0){
		system("cls");
		printf("\n===================LOGIN FUNCIONARIO===================\n");
		printf("\nNenhum Funcionario Cadastrado");
		printf("\n\n");
		system("pause");
	}else{
		do{
			system("cls");
			printf("\n===================LOGIN FUNCIONARIO===================\n");
			printf("\nUsuario: ");
			fflush(stdin);
			gets(aux.usuario);
			printf("\nSenha: ");
			fflush(stdin);
			gets(aux.senha);
			
			for(i = 0; i < tamanhoFuncionario; i++){
				if(strcmp(aux.usuario, funcionario[i].login.usuario) == 0 && strcmp(aux.senha, funcionario[i].login.senha) == 0){
					logou = 1;
					menuFuncionario();
					break;
				
				}
			}
			if(logou == 0){
				system("cls");
				printf("\n===================LOGIN FUNCIONARIO===================\n");
				printf("\nUsuario ou senha Invalidos");
				printf("\n\nDeseja tentar outra vez\n[ 1 ] Sim\n[ 0 ] Nao\n\n-->");
				scanf("%d",&logou);
				
			}
		}while(logou == 0);
	}
}
void loginAluno(){
	Login aux;
	int logou = 0, i;
	
	if(tamanhoAluno <= 0){
		system("cls");
		printf("\n===================LOGIN ALUNO===================\n");
		printf("\nNenhum Aluno Cadastrado");
		printf("\n\n");
		system("pause");
	}else{
		do{
			system("cls");
			printf("\n===================LOGIN ALUNO===================\n");
			printf("\nUsuario(E-mail): ");
			fflush(stdin);
			gets(aux.usuario);
			printf("\nSenha(alfanumerica): ");
			fflush(stdin);
			gets(aux.senha);
			
			for(i = 0; i < tamanhoAluno; i++){
				if(strcmp(aux.usuario, aluno[i].login.usuario) == 0 && strcmp(aux.senha, aluno[i].login.senha) == 0){
					logou = 1;
					alunoAcessou = i;
					menuAluno();
					break;
				
				}
			}
			if(logou == 0){
				system("cls");
				printf("\n===================LOGIN ALUNO===================\n");
				printf("\nUsuario ou senha Invalidos");
				printf("\n\nDeseja tentar outra vez\n[ 1 ] Sim\n[ 0 ] Nao\n\n-->");
				scanf("%d",&logou);
				
			}
		}while(logou == 0);
	}
}

// menu
void menuPrincipal(){
	int op;
	do{
		system("cls");
		printf("\n=======================MENU LOGIN==================\n");
		printf("\n[ 1 ] Login ADM\n[ 2 ] Login Funcionario\n[ 3 ] Login Aluno\n[ 0 ] Sair\n\n--> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				loginADM();
				break;
			case 2:
				loginFuncionario();
				break;
			case 3:
				loginAluno();
				break;
			case 0:
				exit(0);
				break;	
		}
	}while(op != 0);
}

void menuADM(){
	int op;
	do{
		system("cls");
		printf("\n=======================MENU ADM==================\n");
		printf("\n===============CADASTROS===============\n\n[  1 ] Cadastrar Funcionario\n[  2 ] Cadastrar Curso\n[  3 ] Cadastrar Aluno\n[  4 ] Cadastrar Instituicaon\n\n===============LISTAR===============\n\n[  5 ] Listar Funcionario\n[  6 ] Listar Curso\n[  7 ] Listar Aluno\n[  8 ] Listar Instituicao\n\n===============OPERACOES===============\n\n[  9 ] Validar Cadastro\n[ 10 ] Venda de Passagens\n[  0 ] Sair\n\n--> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarFuncionario();
				break;
			case 2:
				cadastrarCurso();
				break;
			case 3:
				cadastrarAluno();
				break;
			case 4:
				cadastrarInstituicao();
				break;
			case 5:
				listarFuncionario();
				break;
			case 6:
				listarCurso();
				break;
			case 7:
				listarAluno();
				break;
			case 8:
				listarInstituicao();
				break;
			case 9:
				validarCadastro();
				break;
			case 10:
				vendaPassagem();
				break;
			
			
		}
	}while(op != 0);
}
void menuFuncionario(){
	
	int op;
	do{
		system("cls");
		printf("\n=======================MENU FUNCIONARIO==================\n");
		printf("\n[ 1 ] Cadastrar Aluno\n[ 2 ] Listar Aluno\n[ 3 ] Venda de Passagens\n[ 0 ] Sair\n\n--> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarAluno();
				break;
			case 2:
				listarAluno();
				break;
			case 3:
				vendaPassagem();
				break;	
		}
	}while(op != 0);
}

void menuAluno(){
	int op;
	do{
		if(strcmp(aluno[alunoAcessou].status, "INATIVO") == 0){
			system("cls");
			printf("\n=======================MENU ALUNO==================\n");
			printf("\nVoce ainda não foi liberado para ter acesso!");
			printf("\nCaso tenha passodo 3 dias de espera, entre em contato com o SINETRAM");
			printf("\npara mais informacoes!");
			op = 0;
			printf("\n\n");
			system("pause");
		}else{
			system("cls");
			printf("\n=======================MENU ALUNO==================\n");
			printf("\n[ 1 ] Saldo de Passe\n[ 0 ] Sair\n\n--> ");
			scanf("%d",&op);
			switch(op){
				case 1:
				saldoAluno();	
					break;	
			}
		}
	}while(op != 0);
}




