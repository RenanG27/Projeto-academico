#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include "meuconio.h"
#include <stdlib.h>
#include <string.h>



//structs

struct TPlivros{
	int id_livro, ano_pub, status;
	char titulo[30];
};

struct TPautores{
	int id_autor, status;
	char nome[30], nacionalidade[30];
};

struct TPdata{
	int dia, mes ,ano;
};

struct TPemprestimos{
	TPdata dev, emp;
	int id_emprestimo, id_livro, id_pessoa, status;
};

struct TPpessoas{
	int id_pessoa, status;
	char nome[30], telefone[16], endereco[30];
};

struct TPlivro_autor{
	int id_livro, id_autor, status;
};

//INTERFACE

void MolduraInicial(int CI, int LI, int CF, int LF, int CorT, int CorF){
    int i;
    textcolor(CorT);
    textbackground(CorF);
    gotoxy(CI,LI);    printf("%c",201);
    gotoxy(CF,LI);    printf("%c",187);
    gotoxy(CI,LF);    printf("%c",200);
    gotoxy(CF,LF);     printf("%c",188);
    for(i=CI+1; i<CF; i++)
    {
        gotoxy(i,LI);    printf("%c",205);
        Sleep(10);
        gotoxy(i,LF);    printf("%c",205);
    }
    for(i=LI+1; i<LF; i++)
    {
        gotoxy(CI,i);    printf("%c",186);
        Sleep(10);
        gotoxy(CF,i);    printf("%c",186);
    }
    textcolor(7);
    textbackground(0);
}

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF){
    int i;
    textcolor(CorT);
    textbackground(CorF);
    gotoxy(CI,LI);    printf("%c",201);
    gotoxy(CF,LI);    printf("%c",187);
    gotoxy(CI,LF);    printf("%c",200);
    gotoxy(CF,LF);     printf("%c",188);
    for(i=CI+1; i<CF; i++)
    {
        gotoxy(i,LI);    printf("%c",205);
        gotoxy(i,LF);    printf("%c",205);
    }
    for(i=LI+1; i<LF; i++)
    {
        gotoxy(CI,i);    printf("%c",186);
        gotoxy(CF,i);    printf("%c",186);
    }
    textcolor(7);
    textbackground(0);
}

void MolduraCRUD() {
	Moldura(1,1,80,25,15,1);
    Moldura(2,2,79,4,14,2);
    textcolor(15);
    gotoxy(28,3);
    printf("ALGORITIMOS DE PROGRAMACAO");
}

void PainelPrincipal(void){
    clrscr();
    Moldura(1,1,80,25,15,1);
    Moldura(2,2,79,4,14,2);
    textcolor(15);
    gotoxy(28,3);
    printf("ALGORITIMOS DE PROGRAMACAO");
    Moldura(2,5,30,21,13,3);
    Moldura(31,5,79,21,11,5);
    Moldura(2,22,79,24,12,4);
    textcolor(10);
    gotoxy(4,23);
    printf("Mensagens:");
}

void red () {
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

//Verificação dos caracteres do input

int verifica_caracter(char verificar[100],int i=6){
	int TL = 0,pos=0,veri=1;
	TL = strlen(verificar);
	while(verificar[pos] != '\0' && veri == 1){ // Verificando todas as posições da string
		if(verificar[pos] > 47 && verificar[pos] < 58){ // Se for valor numerico de 0 a 9 
			veri = 1;
			pos++;
		}
		else
			veri = 0;
	}
	if(pos < TL || TL==0){ // Se menor, nao valido
		gotoxy(4,i);
		printf("Digito invalido.");
		getch();
		return 1;
	}
	else
		return 0;
}

//MENUS PRINCIPAIS

int menu_inicial(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Livros");
    gotoxy(4, 9);
    printf("[B]-Autores");
    gotoxy(4, 10);
    printf("[C]-Livro-Autor");
    gotoxy(4, 11);
    printf("[D]-Clientes");
    gotoxy(4, 12);
    printf("[E]-Emprestimos");
    gotoxy(4, 13);
    printf("[F]-Relatorios");
    gotoxy(4, 14);
    printf("[ESC]-Sair");
    gotoxy(4, 15);
    printf("Opcao Desejada:");

    return toupper(getche());
}

int menu_livros(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE Livros");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Cadastro");
    gotoxy(4, 9);
    printf("[B]-Exclusao"); // levar para menu de exclusao
    gotoxy(4, 10);
    printf("[C]-Alteracao"); // levar para alteração de livros
   	gotoxy(4, 11);
    printf("[D]-Consulta");	
   	gotoxy(4, 12);
    printf("[E]-Ordenacao");	// levar para ordenaçao de livros
    gotoxy(4, 13);
    printf("[F]-Exibir dados");	// levar para ordenaçao de livros
    gotoxy(4, 14);
    printf("[ESC]-Sair");
    gotoxy(4, 14);
    printf("Opcao Desejada:");

    return toupper(getche());
}

int menu_autores(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE Autores");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Cadastro ");
    gotoxy(4, 9);
    printf("[B]-Exclusao "); // levar para menu de exclusao
    gotoxy(4, 10);
    printf("[C]-Alteracao "); // levar para alteração de Autores
   	gotoxy(4, 11);
    printf("[D]-Consulta ");	
   	gotoxy(4, 12);
    printf("[E]-Ordenacao ");	// levar para ordenaçao de Autores
    gotoxy(4, 13);
    printf("[F]-Exibir dados");	// levar para ordenaçao de livros
    gotoxy(4, 14);
    printf("[ESC]-Sair");
    gotoxy(4, 15);
    printf("Opcao Desejada:");

    return toupper(getche());
}

int menu_livro_autor(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE Livro-Autor");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Cadastro ");
    gotoxy(4, 9);
    printf("[B]-Exclusao"); // levar para menu de exclusao
    gotoxy(4, 10);
    printf("[C]-Consulta");	
   	gotoxy(4, 11);
    printf("[D]-Ordenacao");
    gotoxy(4, 12);
    printf("[E]-Exibir");
    gotoxy(4, 13);
    printf("[ESC]-Sair");
    gotoxy(4, 14);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_clientes(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE Cliente");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Cadastro");
    gotoxy(4, 9);
    printf("[B]-Exclusao"); // levar para menu de exclusao
    gotoxy(4, 10);
    printf("[C]-Alteracao"); // levar para alteração de Cliente
   	gotoxy(4, 11);
    printf("[D]-Consulta");	
   	gotoxy(4, 12);
    printf("[E]-Ordenacao");	// levar para ordenaçao de Cliente
    gotoxy(4, 13);
    printf("[F]-Exibir Dados");
    gotoxy(4, 14);
    printf("[ESC]-Sair");
    gotoxy(4, 15);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_emprestimos(){
    system("cls");
    PainelPrincipal();
    red();
    gotoxy(4, 6);
    printf("MENU DE Emprestimo");
    yellow();
    gotoxy(4, 8);
    printf("[A]-Cadastro");
    gotoxy(4, 9);
    printf("[B]-Exclusao"); // levar para menu de exclusao
    gotoxy(4, 10);
    printf("[C]-Alteracao"); // levar para alteração de Emprestimo
   	gotoxy(4, 11);
    printf("[D]-Consulta");	
   	gotoxy(4, 12);
    printf("[E]-Ordenacao");	// levar para ordenaçao de Emprestimo
    gotoxy(4, 13);
    printf("[F]-Exibir");	// levar para ordenaçao de Emprestimo
    gotoxy(4, 14);
    printf("[ESC]-Sair");
    gotoxy(4, 15);
    printf("Opcao Desejada:");

    return toupper(getch());
}

int menu_relatorios(){
	system("cls");
	MolduraCRUD();
	red();
	gotoxy(4, 6);
	printf("MENU RELATORIOS");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Autores que comecam com uma determinada letra, ordenados por nacionalidade");
	gotoxy(4, 9);
	printf("[B]-Livros com Titulos que contenham uma determinada palavra");
	gotoxy(4, 10);
	printf("[C]-Emprestimos de uma pessoa especifica");
	gotoxy(4, 11);
	printf("[D]-Dados de livros de um autor especifico");
	gotoxy(4,12);
	printf("[E]-Emprestimos separados por pessoa");
	gotoxy(4,13);
	printf("[ESC]-Voltar");
	gotoxy(4, 14);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

////////////menus ordenacao//////////////////

char menu_ordena_livros() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU ORDENACAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Id");
	gotoxy(4, 9);
	printf("[B]-Titulo");
	gotoxy(4, 10);
	printf("[C]-Ano de Publi");
	gotoxy(4, 11);
	printf("[ESC]-Voltar");
	gotoxy(4, 12);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

char menu_ordena_autores() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU ORDENACAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Id");
	gotoxy(4, 9);
	printf("[B]-Nome");
	gotoxy(4, 10);
	printf("[C]-Nacionalidade");
	gotoxy(4, 11);
	printf("[ESC]-Voltar");
	gotoxy(4, 12);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

char menu_ordena_clientes() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU ORDENACAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Id");
	gotoxy(4, 9);
	printf("[B]-Nome");
	gotoxy(4, 10);
	printf("[C]-Endereco");
	gotoxy(4, 11);
	printf("[ESC]-Voltar");
	gotoxy(4, 12);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}
char menu_ordena_livro_autor() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU ORDENACAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Titulo do livro");
	gotoxy(4, 9);
	printf("[B]-Nome do Autor");
	gotoxy(4, 10);
	printf("[ESC]-Voltar");
	gotoxy(4, 11);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

char menu_ordena_emprestimos() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU ORDENACAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Id");
	gotoxy(4, 9);
	printf("[ESC]-Voltar");
	gotoxy(4, 10);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}
////////////menus alteracao//////////////////
char menu_altera_livros() {
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("O QUE DESEJA ALTERAR?");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Titulo");
	gotoxy(4, 9);
	printf("[B]-Ano de Publi");
	gotoxy(4, 10);
	printf("[C]-Tudo");
	gotoxy(4, 11);
	printf("[ESC]-Voltar");
	gotoxy(4, 12);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

char menu_altera_autores() {
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("O QUE DESEJA ALTERAR?");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Nome");
	gotoxy(4, 9);
	printf("[B]-Nacionalidade");
	gotoxy(4, 10);
	printf("[C]-Tudo");
	gotoxy(4, 11);
	printf("[ESC]-Voltar");
	gotoxy(4, 12);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

char menu_altera_clientes() {
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("O QUE DESEJA ALTERAR?");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Nome");
	gotoxy(4, 9);
	printf("[B]-Telefone");
	gotoxy(4, 10);
	printf("[C]-Endereco");
	gotoxy(4, 11);
	printf("[D]-Tudo");
	gotoxy(4, 12);
	printf("[ESC]-Voltar");
	gotoxy(4, 13);
	printf("Opcao Desejada:");
	
	return toupper(getch());
}
	
char menu_altera_emprestimos() {
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("O QUE DESEJA ALTERAR?");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Data de Emprestimo");
	gotoxy(4, 9);
	printf("[B]-Data de Devolucao");
	gotoxy(4, 12);
	printf("[ESC]-Voltar");
	gotoxy(4, 13);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}
///////menus exclusao///////////////

char menu_exclusao() {
	
	system("cls");
	PainelPrincipal();
	red();
	gotoxy(4, 6);
	printf("MENU EXCLUSAO");
	yellow();
	gotoxy(4, 8);
	printf("[A]-Logica");
	gotoxy(4, 9);
	printf("[B]-Fisica");
	gotoxy(4, 10);
	printf("[ESC]-Voltar");
	gotoxy(4, 11);
	printf("Opcao Desejada:");
	
	return toupper(getche());
}

int verificar_data_emp(char data[], TPemprestimos &emp, int &i) {
	int x,y,diaI,mesI,anoI;
	char dia[2],mes[2],ano[4];
	
	if(data[2] == 47 && data[5] == 47) {
		for(x=0;x<2;x++) 
			dia[x] = data [x];
		
		mes[0] = data[3];
		mes[1] = data[4];
			
		y=0;
		for(x=6;x<=9;x++)
			ano[y++] = data[x];
			
		diaI = atoi(dia);
		mesI = atoi(mes);
		anoI = atoi(ano);
		if((diaI<=0 && diaI>31) && (mesI <= 0 && mesI > 12) && anoI<2000) {
			gotoxy(4,i++);
			printf("Data invalida.");
		}
		else {
			emp.emp.dia = diaI;
			emp.emp.mes = mesI;
			emp.emp.ano = anoI;
			
			return 1;
		}
	}
	else {
		gotoxy(4,i++);
		printf("Data invalida.");
	}
	return 0;
}

int verificar_data_dev(char data[], TPemprestimos &emp,int &i) {
	int x,y,diaI,mesI,anoI,tam;
	char dia[2],mes[2],ano[4];
	
	if(data[2] == 47 && data[5] == 47) {
		for(x=0;x<2;x++) 
			dia[x] = data [x];
		
		mes[0] = data[3];
		mes[1] = data[4];
			
		y=0;
		for(x=6;x<=9;x++)
			ano[y++] = data[x];
			
		diaI = atoi(dia);
		mesI = atoi(mes);
		anoI = atoi(ano);
		if((diaI<=0 && diaI>31) && (mesI <= 0 && mesI > 12) && anoI<2000) {
			gotoxy(4,i++);
			printf("Data invalida.");
		}
		else {
			emp.dev.dia = diaI;
			emp.dev.mes = mesI;
			emp.dev.ano = anoI;
			return 1;
		}
	}
	else {
		gotoxy(4,i++);
		printf("Data invalida.");
	}
	return 0;
}

int verifica_dev_maior(TPemprestimos emp) {
	int x;
	if(emp.dev.ano>emp.emp.ano){
		x=1;
	}
	else{
		if(emp.dev.mes>emp.emp.mes){
			x=1;
		}
		else{
			if(emp.dev.dia>emp.emp.dia){
				x=1;
			}
			else{
				x=0;
			}
		}
	}
	return x;
}

//BUSCAS

int busca_id_livro(FILE *PtrLv, int id){//Busca Exaustiva e Logica
	TPlivros lv;
	//fseek(PtrAluno,0,0);
	rewind(PtrLv);
	fread(&lv,sizeof(TPlivros),1,PtrLv);
	while (!feof(PtrLv) && (id!=lv.id_livro || !lv.status))
		fread(&lv,sizeof(TPlivros),1,PtrLv);
	
	if (id==lv.id_livro) {
		return ftell(PtrLv)-sizeof(TPlivros);
	}	
	else
		return -1;
}
 
int busca_id_autores(FILE *PtrAut,int id) {
	TPautores aut;
	rewind(PtrAut);
	
	fread(&aut,sizeof(TPautores),1,PtrAut);
	while(!feof(PtrAut) && (id!=aut.id_autor || !aut.status)) {
		fread(&aut,sizeof(TPautores),1,PtrAut);
	}
	if(id==aut.id_autor) 
		return ftell(PtrAut) - sizeof(TPautores);
	else
		return -1;	
	
}

int busca_id_pessoa(FILE *PtrPes, int id){
	TPpessoas pes;
	rewind(PtrPes);
	
	fread(&pes,sizeof(TPpessoas),1,PtrPes);
	while(!feof(PtrPes) && (id!=pes.id_pessoa || !pes.status))
		fread(&pes,sizeof(TPpessoas),1,PtrPes);
	
	if(id==pes.id_pessoa)
		return ftell(PtrPes) - sizeof(TPpessoas);
	else
		return -1;
}

int busca_id_livro_autor(FILE *PtrLA, int id_livro, int id_autor) {
	TPlivro_autor livro_autor;
	rewind(PtrLA);
	
	fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	while(!feof(PtrLA) && (livro_autor.id_livro != id_livro || livro_autor.id_autor != id_autor)) {
		fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	}
	if(livro_autor.id_livro == id_livro && livro_autor.id_autor == id_autor)
		return ftell(PtrLA) - sizeof(TPlivro_autor);
	else
		return -1;
}

int busca_livro_em_livro_autor(int id_livro) {
	FILE *PtrLA = fopen("LivroAutor.dat","rb");
	TPlivro_autor livro_autor;
	int pos;
	
	rewind(PtrLA);
	fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	while(!feof(PtrLA) && (id_livro!=livro_autor.id_livro || !livro_autor.status))
		fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	
	pos = ftell(PtrLA)-sizeof(TPlivro_autor);
	
	fclose(PtrLA);
	
	if(livro_autor.id_livro == id_livro && livro_autor.status)
		return pos;
		
	else
		 return -1;
}

int busca_autor_em_livro_autor(int id_autor) {
	FILE *PtrLA = fopen("LivroAutor.dat","rb");
	TPlivro_autor livro_autor;
	int pos;
	
	rewind(PtrLA);
	fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	while(!feof(PtrLA) && (id_autor!=livro_autor.id_autor || !livro_autor.status))
		fread(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
	
	pos = ftell(PtrLA)-sizeof(TPlivro_autor);
	
	fclose(PtrLA);
	
	if(livro_autor.id_autor == id_autor && livro_autor.status)
		return pos;
		
	else
		 return -1;
}

void insercao_direta_livros(int TL){
	FILE *Ptr = fopen("Livros.dat","rb+");
	TPlivros lv1,lv2, aux;
	int x,y;

	for(x=TL-1;x>0;x--) {
		
		for(y=x-1;y>=0;y--) {
			
			fseek(Ptr,x*sizeof(TPlivros),0);
			fread(&lv1,sizeof(TPlivros),1,Ptr);
			
			fseek(Ptr,y*sizeof(TPlivros),0);
			fread(&lv2,sizeof(TPlivros),1,Ptr);
			
			if(lv2.id_livro>lv1.id_livro) {
				
				fseek(Ptr,x*sizeof(TPlivros),0);
				fwrite(&lv2,sizeof(TPlivros),1,Ptr);
				
				fseek(Ptr,y*sizeof(TPlivros),0);
				fwrite(&lv1,sizeof(TPlivros),1,Ptr);
			}
		}	
	}
	fclose(Ptr);	
}

int busca_id_emprestimo(int id_emprestimos){
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	TPemprestimos emp;
	
	rewind(PtrEmp);
	fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	while(!feof(PtrEmp) && (id_emprestimos!=emp.id_emprestimo || !emp.status))
		fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
		
	fclose(PtrEmp);
		
	if(emp.id_emprestimo==id_emprestimos)
		return ftell(PtrEmp) - sizeof(TPemprestimos);
	else 
		return -1;	
}

int busca_id_livro_emprestimo(int id_livro){
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	TPemprestimos emp;
	
	rewind(PtrEmp);
	fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	while(!feof(PtrEmp) && (emp.id_livro!=id_livro|| !emp.status))
		fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
		
	fclose(PtrEmp);
		
	if(emp.id_livro==id_livro)
		return ftell(PtrEmp) - sizeof(TPemprestimos);
	else 
		return -1;	
}

int busca_livro_em_emprestimo(int id_livro, int &fisica) {
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	
	TPemprestimos emp;
	int pos;
	
	fisica=0;
	
	rewind(PtrEmp);
	fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	while(!feof(PtrEmp) && id_livro!=emp.id_livro)
		fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	
	pos = ftell(PtrEmp)-sizeof(TPemprestimos);
	
	fclose(PtrEmp);
	
	if(emp.id_livro == id_livro && emp.status) 
		return pos;
	else 
		 return -1;
}

int busca_pessoa_em_emprestimo(int id_pessoa) {
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	
	TPemprestimos emp;
	int pos;
	
	rewind(PtrEmp);
	fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	while(!feof(PtrEmp) && (id_pessoa!=emp.id_pessoa || !emp.status))
		fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
	pos = ftell(PtrEmp)-sizeof(TPemprestimos);
	
	fclose(PtrEmp);
	if(emp.id_pessoa == id_pessoa)
		return pos;
	else
		 return -1;
}

//LIVROS

void cadastro_livros() {
	TPlivros lv;
	FILE *PtrLv = fopen("Livros.dat","ab+");
	int i=6,TL;
	char op='S', ver_caracter[100];
	
	system("cls");
	MolduraCRUD();
	
	gotoxy(4,i++);
	printf("Digite o Id do livro:");
	fflush(stdin);
	gets(ver_caracter); // Le o valor em uma string
	
	while(verifica_caracter(ver_caracter,i) == 1 ) {
		system("cls");
		MolduraCRUD();
		gotoxy(4,6);
		printf("Digite o Id do livro:");
		fflush(stdin);
		gets(ver_caracter);
	}
	
	while(op=='S' && verifica_caracter(ver_caracter) == 0) {
		i=7;
		lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
		gotoxy(4,i);
		if ( busca_id_livro(PtrLv,lv.id_livro) == -1) {
			
			printf("Digite o titulo:");
			fflush(stdin);
			gets(lv.titulo);
			i++;
			while(stricmp(lv.titulo,"\0")==0) {
				gotoxy(4,i);
				printf("Campo vazio.");
				i++;
				gotoxy(4,i);
				printf("Digite o titulo novamente:");
				fflush(stdin);
				gets(lv.titulo);
				i++;
			}
			gotoxy(4,i++);
			printf("Digite o ano de publicacao:");
			fflush(stdin);
			gets(ver_caracter); // Le o valor em uma string
			while(verifica_caracter(ver_caracter,i) == 1 ) {
				i++;
				gotoxy(4,i++);
				printf("Digite o ano de publicacao novamente:");
				fflush(stdin);
				gets(ver_caracter);
			}
			lv.ano_pub = atoi(ver_caracter);
			i++;
			lv.status=1;
			
			fwrite(&lv,sizeof(TPlivros),1,PtrLv);
		
			i++;
			gotoxy(4,i);
			
			printf("Livro cadastrado!");
			
		}
		else {
			i=7;
			gotoxy(4,i);

			printf("Livro ja Cadastrado!");
		}
		
		i++;
		gotoxy(4,i);
		printf("Deseja cadastrar outro livro (S/N)?");
		op = toupper(getche());
		
		i++;
		gotoxy(4,i);
		
		system("cls");
		MolduraCRUD();
		
		if(op=='S') {
			gotoxy(4,6);
			printf("Digite o Id do outro livro:");
			fflush(stdin);
			gets(ver_caracter); // Le o valor em uma string
		}
	}
	TL=ftell(PtrLv)/sizeof(TPlivros);
	
	fclose(PtrLv);
			
	insercao_direta_livros(TL);
}

void cadastro_livro_autor() {
	TPlivros lv;
	TPautores aut;
	TPlivro_autor livro_autor;
	
	FILE *PtrLv = fopen("Livros.dat","rb+");
	FILE *PtrAut = fopen("Autores.dat","rb+");
	FILE *PtrLA = fopen("LivroAutor.dat","ab+");
	
	int i=6,TL;
	char op='S', ver_caracter[100];
	
	while(op=='S') {
		system("cls");
		MolduraCRUD();
		
		gotoxy(4,i++);
		printf("Digite o Id do livro:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
		
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o Id do livro:");
			fflush(stdin);
			gets(ver_caracter);
		}
		lv.id_livro = atoi(ver_caracter);
		
		while(busca_id_livro(PtrLv,lv.id_livro) == -1) {
			gotoxy(4,i++);
			printf("Livro nao cadastrado.");
			getch();
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Digite o Id do livro:");
			fflush(stdin);
			gets(ver_caracter);
			
			while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Digite o Id do livro:");
			fflush(stdin);
			gets(ver_caracter);
			}
			lv.id_livro = atoi(ver_caracter);
		}
		system("cls");
		MolduraCRUD();
		gotoxy(4,6);
		printf("Digite o Id do autor:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
		
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o Id do autor:");
			fflush(stdin);
			gets(ver_caracter);
		}
		aut.id_autor = atoi(ver_caracter);
		
		while(busca_id_autores(PtrAut,aut.id_autor) == -1) {
			gotoxy(4,i++);
			printf("Autor nao cadastrado.");
			getch();
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Digite o Id do autor:");
			fflush(stdin);
			gets(ver_caracter);
			
			while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Digite o Id do autor:");
			fflush(stdin);
			gets(ver_caracter);
			}
			aut.id_autor = atoi(ver_caracter);
		}
		
		aut.id_autor = atoi(ver_caracter);
		
		system("cls");
		MolduraCRUD();
		i=6;
		
		if(busca_id_livro_autor(PtrLA, lv.id_livro, aut.id_autor) != -1) {
			gotoxy(4,i++);
			printf("Ja cadastrado.");
			getch();
		}
		else {
			
			livro_autor.id_livro = lv.id_livro;
			livro_autor.id_autor = aut.id_autor;
			livro_autor.status = 1;
			fwrite(&livro_autor,sizeof(TPlivro_autor),1,PtrLA);
			gotoxy(4,i++);
			printf("Cadastro realizado.");
			getch();
		}
		i++;
		gotoxy(4,i);
		printf("Deseja cadastrar outro livro-autor (S/N)?");
		op = toupper(getche());
		
		i++;
		gotoxy(4,i);
		
		system("cls");
		MolduraCRUD();
		
	}
	fclose(PtrLv);
	fclose(PtrAut);
	fclose(PtrLA);
}

void consulta_livro_autor(){
	FILE *PtrLA = fopen("LivroAutor.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrAut = fopen("Autores.dat","rb");
	TPlivro_autor la;
	TPlivros lv;
	TPautores aut;
	int i=6, pos;
	char op='S', ver_caracter[100];;
	system("cls");
	MolduraCRUD();
	if(PtrLA==NULL){
		gotoxy(4,6);
		printf("Erro de abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do livro:");
		fflush(stdin);
		gets(ver_caracter); 
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o id do livro:");
			fflush(stdin);
			gets(ver_caracter);
		}
		la.id_livro = atoi(ver_caracter);
		while(op=='S'){
			i=7;
			pos=busca_id_livro(PtrLv,la.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Livro nao cadastrado");
			}	
			else{
				gotoxy(4,i++);
				printf("Digite o id do Autor:");
				fflush(stdin);
				gets(ver_caracter); 
			
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					system("cls");
					MolduraCRUD();
					gotoxy(4,6);
					printf("Digite o id do Autor:");
					fflush(stdin);
					gets(ver_caracter);
				}
				if(verifica_caracter(ver_caracter) == 0){
					i=7;
					la.id_autor = atoi(ver_caracter); // converte o valor para inteiro
					pos=busca_id_autores(PtrAut,la.id_autor);
					if(pos==-1){
						gotoxy(4,i++);
						printf("Autor nao cadastrado");
					}
					else{
						system("cls");
						MolduraCRUD();
						pos = busca_id_livro(PtrLv,la.id_livro);
						fseek(PtrLv,pos,0);
						fread(&lv,sizeof(TPlivros),1,PtrLv);
						gotoxy(4,i++);
						printf("Livro: %s",lv.titulo);
						pos = busca_id_autores(PtrAut,la.id_autor);
						fseek(PtrAut,pos,0);
						fread(&aut,sizeof(TPautores),1,PtrAut);
						gotoxy(4,i++);
						printf("Autor: %s",aut.nome);
						i+=2;
						gotoxy(4,i);
					}	
				}
			}
			gotoxy(4,++i);
			printf("Deseja consultar outro Livro Autor (S/N)?");
			op = toupper(getch());
			system("cls");
			MolduraCRUD();
			if(op=='S'){
				gotoxy(4,6);
				printf("Digite o id do Livro:");
				fflush(stdin);
				gets(ver_caracter);  // Lendo em string
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					system("cls");
					MolduraCRUD();
					gotoxy(4,6);
					printf("Digite o id do livro:");
					fflush(stdin);
					gets(ver_caracter);
				}
				la.id_livro = atoi(ver_caracter);
			}
			
		}
	}
	fclose(PtrLA);
	fclose(PtrLv);
	fclose(PtrAut);
}

void exibe_livro_autor() {
	system("cls");
	FILE *PtrLA = fopen("LivroAutor.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrAut = fopen("Autores.dat","rb");
	TPlivro_autor la;
	TPlivros lv;
	TPautores aut;
	int i=2, pos;
	
	gotoxy(4,2);
	if(PtrLA == NULL) {
		printf("Erro de Abertura.");
	}
	else {
		rewind(PtrLA);
		fread(&la,sizeof(TPlivro_autor),1,PtrLA);
		while (!feof(PtrLA))
		{	
			if(la.status){
				pos = busca_id_livro(PtrLv,la.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				pos = busca_id_autores(PtrAut,la.id_autor);
				fseek(PtrAut,pos,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Autor: %s",aut.nome);
				i+=2;
				gotoxy(4,i);
			}			
			fread(&la,sizeof(TPlivro_autor),1,PtrLA);
		}
	}
	fclose(PtrLA);
	fclose(PtrLv);
	fclose(PtrAut);
	getch();
}


//EXLUSAO/////////////////////////////////

void exclusao_logica_livros() {
	TPlivros lv;
	FILE *PtrLv = fopen("Livros.dat","rb+");
	int pos, i=6, a , fisica;
	char op='S', ver_caracter[100];
	system("cls");
	MolduraCRUD();
	if(PtrLv == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do livro que deseja excluir:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do livro que deseja excluir: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			a=1;
			i=7;
			lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_livro(PtrLv,lv.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				if(busca_livro_em_livro_autor(lv.id_livro)!=-1) {
					gotoxy(4,i++);
					printf("Livro cadastrado em tabela Livro Autor, nao eh possivel realizar a exclusao.");
					getch();
					system("cls");
					MolduraCRUD();
					a=0;
				}
				if(busca_livro_em_emprestimo(lv.id_livro, fisica)!=-1 ) {
					gotoxy(4,i++);
					printf("Livro cadastrado em tabela Emprestimos, nao eh possivel realizar a exclusao.");
					getch();
					system("cls");
					MolduraCRUD();
					a=0;
				}
				if(a==1) {
					gotoxy(4,i++);
					printf("Dados encontrados:");
					fseek(PtrLv,pos,0);
					fread(&lv,sizeof(TPlivros),1,PtrLv);
					gotoxy(4,i++);
					printf("Id: %d",lv.id_livro);
					gotoxy(4,i++);
					printf("Titulo: %s",lv.titulo);
					gotoxy(4,i++);
					printf("Ano de Publicacao: %d",lv.ano_pub);
					gotoxy(4,i++);
					printf("Deseja excluir os dados acima (S/N)?");
					op = toupper(getch());
					system("cls");
					MolduraCRUD();
					if(op=='S'){
						lv.status = 0;
						fseek(PtrLv,pos,0);
						fwrite(&lv,sizeof(TPlivros),1,PtrLv);
						gotoxy(4,6);
						printf("Dados excluidos!");
						getch();
					}
				}	
			}
			gotoxy(4,6);
			printf("Deseja excluir  outro livro (S/N)?");
			op = toupper(getch());
			if(op=='S'){
				system("cls");
				MolduraCRUD();
				gotoxy(4,6);
				printf("Qual id do livro que deseja excluir:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrLv);
}

void exclusao_fisica_livros() {
	FILE *PtrLv = fopen("Livros.dat","rb+");
	TPlivros aux;
	int pos, i=6;
	
	system("cls");
	MolduraCRUD();
	if(PtrLv == NULL) {
		gotoxy(4,i++);
		printf("Erro de abertura");
	}
	else { //se der tempo fazer exibir os livros a ser excluido
		gotoxy(4,i++);
		printf("Deseja excluir os dados com status 0");
		gotoxy(4,i++);
		printf("permanentemente [S]/[N] ?");
		if(toupper(getche()) == 'S') {
			FILE *PtrTemp = fopen("Temp.dat","wb");
			
			rewind(PtrLv);
			fread(&aux,sizeof(TPlivros),1,PtrLv);
			
			while(!feof(PtrLv)) {
				if(aux.status) {
					fwrite(&aux,sizeof(TPlivros),1,PtrTemp);
				}
				fread(&aux,sizeof(TPlivros),1,PtrLv);
			}
			fclose(PtrLv);
			fclose(PtrTemp);
			remove("Livros.dat");
			rename("Temp.dat","Livros.dat");
			gotoxy(4,i);
			printf("Livros excluidos!");
			getch();
		}
		else {
			fclose(PtrLv);
		}
	}
}

void exclusao_livros() {
	int op;
	op = menu_exclusao();
	while(op!=27) {
		switch(op) {
			case 'A': 
					exclusao_logica_livros();
					break;
			case 'B': 
					exclusao_fisica_livros();
					break;
		}
		op = menu_exclusao();
		
	}
	
}

void exclusao_logica_autores() {
	TPautores aut;
	FILE *PtrAut = fopen("Autores.dat","rb+");
	int pos, i=6;
	char op='S', ver_caracter[100];
	system("cls");
	MolduraCRUD();
	if(PtrAut == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do autor que deseja excluir:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do autor que deseja excluir: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_autores(PtrAut,aut.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{	
					if(busca_autor_em_livro_autor(aut.id_autor)!=-1) {
						gotoxy(4,i++);
						printf("Autor cadastrado em tabela Livro Autor, nao eh possivel realizar a exclusao.");
						getch();
						system("cls");
						MolduraCRUD();
					}
					else {
						gotoxy(4,i++);
						printf("Dados encontrados:");
						fseek(PtrAut,pos,0);
						fread(&aut,sizeof(TPautores),1,PtrAut);
						gotoxy(4,i++);
						printf("Id: %d",aut.id_autor);
						gotoxy(4,i++);
						printf("Nome: %s",aut.nome);
						gotoxy(4,i++);
						printf("Nacionalidade: %s",aut.nacionalidade);
						gotoxy(4,i++);
						printf("Deseja excluir os dados acima (S/N)?");
						op = toupper(getch());
						system("cls");
						MolduraCRUD();
						if(op=='S'){
							aut.status = 0;
							fseek(PtrAut,pos,0);
							fwrite(&aut,sizeof(TPautores),1,PtrAut);
							gotoxy(4,6);
							printf("Dados excluidos!");
							getch();
						}
					}	
			}
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Deseja excluir  outro autor (S/N)?");
			op = toupper(getch());
			if(op=='S'){
				system("cls");
				MolduraCRUD();
				gotoxy(4,6);
				printf("Qual id do autor que deseja excluir:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrAut);
}

void exclusao_fisica_autores(){
	TPautores aut;
	FILE *PtrAut = fopen("Autores.dat","rb+");
	char op;
	system("cls");
	MolduraCRUD();
	if (PtrAut==NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		gotoxy(4,6);
		printf("Deseja excluir os dados com status 0");
		gotoxy(4,7);
		printf("Permanentemente (S/N)?");
		if(toupper(getche())=='S'){
			FILE *PtrTemp = fopen("Temp.dat","wb");
			
			rewind(PtrAut);
			fread(&aut,sizeof(TPautores),1,PtrAut);
			while(!feof(PtrAut)){
				if(aut.status){
					fwrite(&aut,sizeof(TPautores),1,PtrTemp);					
				}
				fread(&aut,sizeof(TPautores),1,PtrAut);
			}
			fclose(PtrAut);
			fclose(PtrTemp);
			remove("Autores.dat");
			rename("Temp.dat","Autores.dat");
			gotoxy(4,8);
			printf("Autores Excluidos!");
			getch();
		}
		else
			fclose(PtrAut);
	}
}

void exclusao_autores() {
	int op;
	op = menu_exclusao();
	while(op!=27) {
		switch(op) {
			case 'A': 
					exclusao_logica_autores();
					break;
			case 'B': 
					exclusao_fisica_autores();
					break;
		}
		op = menu_exclusao();
		
	}
	
}

void exclusao_logica_clientes(){
	TPpessoas pes;
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	int pos, i=6;
	char op='S', ver_caracter[100];
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura!");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do cliente que deseja apagar:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do cliente que deseja excluir:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos = busca_id_pessoa(PtrPes, pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado!");
			}
			else{
				if(busca_pessoa_em_emprestimo(pes.id_pessoa)!=-1){
					gotoxy(4,i++);
					printf("Cliente cadastrado em tabela Emprestimo, nao eh possivel realizar a exclusao.");
					getch();
					system("cls");
					MolduraCRUD();
				}
				else{
					gotoxy(4,i++);
					printf("Dados Encontrados:");
					fseek(PtrPes,pos,0);
					fread(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Id: %d", pes.id_pessoa);
					gotoxy(4,i++);
					printf("Nome: %s", pes.nome);
					gotoxy(4,i++);
					printf("Telefone: %s", pes.telefone);
					gotoxy(4,i++);
					printf("Endereco: %s", pes.endereco);
					gotoxy(4,i++);
					printf("Deseja excluir o dados acima (S/N)?");
					op = toupper(getch());
					system("cls");
					MolduraCRUD();
					if(op=='S'){
						pes.status=0;
						fseek(PtrPes,pos,0);
						fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
						gotoxy(4,i++);
						printf("Cliente excluido com sucesso!");
					}
				}
			}
			gotoxy(4,7);
			printf("Deseja excluir outro cliente (S/N)?");
			op = toupper(getch());
			if(op=='S'){
				system("cls");
				MolduraCRUD();
				gotoxy(4,6);
				printf("Qual id do cliente que deseja excluir:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrPes);
}

void exclusao_fisica_clientes(){
	TPpessoas pes;
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		gotoxy(4,6);
		printf("Deseja apagar todos os dados com status 0");
		gotoxy(4,7);
		printf("Permanentemente (S/N)?");
		if(toupper(getche())=='S'){
			FILE *PtrTemp = fopen("Temp.dat","wb");
			rewind(PtrPes);
			
			fread(&pes,sizeof(TPpessoas),1,PtrPes);
			while(!feof(PtrPes)){
				if(pes.status){
					fwrite(&pes,sizeof(TPpessoas),1,PtrTemp);
				}
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
			}
			
			fclose(PtrPes);
			fclose(PtrTemp);
			remove("Pessoas.dat");
			rename("Temp.dat","Pessoas.dat");
			gotoxy(4,8);
			printf("Dados excluidos!");
			getch();
		}
		else
			fclose(PtrPes);
	}
}

void exclusao_clientes() {
	int op;
	op = menu_exclusao();
	while(op!=27) {
		switch(op) {
			case 'A': 
					exclusao_logica_clientes();
					break;
			case 'B': 
					exclusao_fisica_clientes();
					break;
		}
		op = menu_exclusao();
		
	}
	
}

void exclusao_logica_livro_autor(){
	TPlivro_autor la;
	TPlivros lv;
	TPautores aut;
	FILE *PtrLA = fopen("LivroAutor.dat","rb+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrAut = fopen("Autores.dat","rb");
	int pos, pos2, i=6;
	char op='S', ver_caracter[100];
	
	system("cls");
	MolduraCRUD();
	if(PtrLA == NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do livro que deseja apagar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do livro que deseja apagar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		
		la.id_livro = atoi(ver_caracter);
		gotoxy(4,i++);
		printf("Digite o id do autor que deseja apagar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			i++;
			gotoxy(4,i++);
			printf("Qual o id do autor que deseja apagar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		
		la.id_autor = atoi(ver_caracter);
		
		while(op == 'S' && la.id_livro>0 && la.id_autor>0){
			pos=busca_id_livro_autor(PtrLA, la.id_livro, la.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Livro Autor nao cadastrado");
			}
			else{
				gotoxy(4,i++);
				printf("Dados Encontrados:");
				fseek(PtrLA,pos,0);
				fread(&la,sizeof(TPlivro_autor),1,PtrLA);
				pos2=busca_id_livro(PtrLv, la.id_livro);
				fseek(PtrLv,pos2,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				fseek(PtrLA,pos,0);
				fread(&la,sizeof(TPlivro_autor),1,PtrLA);
				pos2=busca_id_livro(PtrLv, la.id_autor);
				fseek(PtrAut,pos2,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Autor: %s",aut.nome);
				
				gotoxy(4,i++);
				printf("Deseja excluir os dados acima(S/N)?");
				op = toupper(getche());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					la.status=0;
					fseek(PtrLA,pos,0);
					fwrite(&la,sizeof(TPlivro_autor),1,PtrLA);
					gotoxy(4,i++);
					printf("Dados excluidos com sucesso");
					getche();
				}
			}
			gotoxy(4,i++);
			printf("Deseja excluir outro Livro Autor(S/N)?");
			op = toupper(getche());
			if(op=='S') {
				system("cls");
				MolduraCRUD();
				i=6;
				gotoxy(4,i++);
				printf("Digite o id do livro que deseja apagar:");
				fflush(stdin);
				gets(ver_caracter);
			
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					system("cls");
					MolduraCRUD();
					gotoxy(4,6);
					printf("Qual o id do livro que deseja apagar:");
					fflush(stdin);
					gets(ver_caracter);
				}
				
				la.id_livro = atoi(ver_caracter);
				gotoxy(4,i++);
				printf("Digite o id do autor que deseja apagar:");
				fflush(stdin);
				gets(ver_caracter);
			
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					i++;
					gotoxy(4,i++);
					printf("Qual o id do autor que deseja apagar:");
					fflush(stdin);
					gets(ver_caracter);
				}
		
				la.id_autor = atoi(ver_caracter);
			}
		}
	}
	fclose(PtrLv);
	fclose(PtrAut);
	fclose(PtrLA);
}

void exclusao_fisica_livro_autor(){
	TPlivro_autor la;
	FILE *PtrLA = fopen("LivroAutor.dat","rb+");
	int pos, pos2, i=6;
	
	system("cls");
	MolduraCRUD();
	if(PtrLA == NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Deseja apgar todos os arquivos com status 0");
		gotoxy(4,i++);
		printf("Permanentemente (S/N)?");
		
		if(toupper(getch()) == 'S'){
			rewind(PtrLA);
			FILE *PtrTemp = fopen("Temp.dat","wb");
			fread(&la,sizeof(TPlivro_autor),1,PtrLA);
			while(!feof(PtrLA)){
				if(la.status)
					fwrite(&la,sizeof(TPlivro_autor),1,PtrTemp);
				
				fread(&la,sizeof(TPlivro_autor),1,PtrLA);
			}
			fclose(PtrLA);
			fclose(PtrTemp);
			remove("LivroAutor.dat");
			rename("Temp.dat","LivroAutor.dat");
			gotoxy(4,i);
			printf("Dados excluidos!");
			getch();
		}
		else
			fclose(PtrLA);
		}
}

void exclusao_livro_autor() {
	int op;
	op = menu_exclusao();
	while(op!=27) {
		switch(op) {
			case 'A': 
					exclusao_logica_livro_autor();
					break;
			case 'B': 
					exclusao_fisica_livro_autor();
					break;
		}
		op = menu_exclusao();
		
	}
	
}

////////////////Alteracao///////////////////////

void altera_titulo_livros() {
	
	system("cls");
	MolduraCRUD();
	TPlivros lv;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrLv = fopen("Livros.dat","rb+");
	
	
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do livro que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do livro que deseja alterar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_livro(PtrLv,lv.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Livro:");
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Id: %d",lv.id_livro);
				gotoxy(4,i++);
				printf("Titulo: %s",lv.titulo);
				gotoxy(4,i++);
				printf("Ano de Publicacao: %d",lv.ano_pub);
				gotoxy(4,i++);
				printf("Deseja alterar o Titulo?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Titulo: ");
					fflush(stdin);
					gets(lv.titulo);
					while(stricmp(lv.titulo,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Titulo: ");
						fflush(stdin);
						gets(lv.titulo);
					}
					gotoxy(4,i++);
					fseek(PtrLv,pos,0);
					fwrite(&lv,sizeof(TPlivros),1,PtrLv);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro titulo (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do livro que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrLv);
}

void altera_ano_pub_livros() {
	
	system("cls");
	MolduraCRUD();
	TPlivros lv;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrLv = fopen("Livros.dat","rb+");
	
	
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do livro que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do livro que deseja alterar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_livro(PtrLv,lv.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Livro:");
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Id: %d",lv.id_livro);
				gotoxy(4,i++);
				printf("Titulo: %s",lv.titulo);
				gotoxy(4,i++);
				printf("Ano de Publicacao: %d",lv.ano_pub);
				gotoxy(4,i++);
				printf("Deseja alterar o ano de publicacao?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Ano Publicacao: ");
					fflush(stdin);
					gets(ver_caracter);
	
					while(verifica_caracter(ver_caracter,i) == 1 ) {
						system("cls");
						MolduraCRUD();
						gotoxy(4,6);
						printf("Ano Publicacao:");
						fflush(stdin);
						gets(ver_caracter);
					}
					lv.ano_pub = atoi(ver_caracter);
					gotoxy(4,i++);
					fseek(PtrLv,pos,0);
					fwrite(&lv,sizeof(TPlivros),1,PtrLv);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro id (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do livro que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrLv);
}

void altera_tudo_livros() {
	
	system("cls");
	MolduraCRUD();
	TPlivros lv;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrLv = fopen("Livros.dat","rb+");
	
	
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do livro que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do livro que deseja alterar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_livro(PtrLv,lv.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Livro:");
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Id: %d",lv.id_livro);
				gotoxy(4,i++);
				printf("Titulo: %s",lv.titulo);
				gotoxy(4,i++);
				printf("Ano de Publicacao: %d",lv.ano_pub);
				gotoxy(4,i++);
				printf("Deseja alterar o Id?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;		
					gotoxy(4,i++);
					printf("Titulo: ");
					fflush(stdin);
					gets(lv.titulo);
					while(stricmp(lv.titulo,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Titulo: ");
						fflush(stdin);
						gets(lv.titulo);
					}
					gotoxy(4,i++);
					printf("Ano Publicacao: ");
					fflush(stdin);
					gets(ver_caracter);
					
					while(verifica_caracter(ver_caracter,i) == 1 ) {
						i++;
						gotoxy(4,i++);
						printf("Ano Publicacao: ");
						fflush(stdin);
						gets(ver_caracter);
					}
					lv.ano_pub = atoi(ver_caracter);
					gotoxy(4,i++);
					fseek(PtrLv,pos,0);
					fwrite(&lv,sizeof(TPlivros),1,PtrLv);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro id (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do livro que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrLv);
}

void altera_livros(){
	int op;
	op = menu_altera_livros();;
	while(op!=27) {
		switch(op) {
			case 'A': 
					altera_titulo_livros();
					break;
			case 'B': 
					altera_ano_pub_livros();
					break;
			case 'C': 
					altera_tudo_livros();
					break;
		}
		op = menu_altera_livros();
		
	}
}

void altera_nome_autores() {
	system("cls");
	MolduraCRUD();
	TPautores aut;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrAut = fopen("Autores.dat","rb+");
	
	
	if(PtrAut == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do autor que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do autor que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter,i) == 0){
			i=7;
			aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_autores(PtrAut,aut.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Autor:");
				fseek(PtrAut,pos,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Id: %d",aut.id_autor);
				gotoxy(4,i++);
				printf("Nome: %s",aut.nome);
				gotoxy(4,i++);
				printf("Nacionalidade: %s",aut.nacionalidade);
				gotoxy(4,i++);
				printf("Deseja alterar o Nome?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Nome: ");
					fflush(stdin);
					gets(aut.nome);
					
					while(stricmp(aut.nome,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nome: ");
						fflush(stdin);
						gets(aut.nome);
					}
					gotoxy(4,i++);
					fseek(PtrAut,pos,0);
					fwrite(&aut,sizeof(TPautores),1,PtrAut);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro nome (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do autor que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrAut);
}

void altera_nacionalidade_autores() {
	system("cls");
	MolduraCRUD();
	TPautores aut;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrAut = fopen("Autores.dat","rb+");
	
	
	if(PtrAut == NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do autor que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do autor que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter,i) == 0){
			i=7;
			aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_autores(PtrAut,aut.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Autor:");
				fseek(PtrAut,pos,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Id: %d",aut.id_autor);
				gotoxy(4,i++);
				printf("Nome: %s",aut.nome);
				gotoxy(4,i++);
				printf("Nacionalidade: %s",aut.nacionalidade);
				gotoxy(4,i++);
				printf("Deseja alterar a Nacionalidade?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Nacionalidade: ");
					fflush(stdin);
					gets(aut.nacionalidade);
					while(stricmp(aut.nacionalidade,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nacionalidade: ");
						fflush(stdin);
						gets(aut.nacionalidade);
					}
					gotoxy(4,i++);
					fseek(PtrAut,pos,0);
					fwrite(&aut,sizeof(TPautores),1,PtrAut);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro nome (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do autor que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrAut);
}

void altera_tudo_autores() {
	system("cls");
	MolduraCRUD();
	TPautores aut;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrAut = fopen("Autores.dat","rb+");
	
	
	if(PtrAut == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do autor que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do autor que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_autores(PtrAut,aut.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados Autor:");
				fseek(PtrAut,pos,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Id: %d",aut.id_autor);
				gotoxy(4,i++);
				printf("Nome: %s",aut.nome);
				gotoxy(4,i++);
				printf("Nacionalidade: %s",aut.nacionalidade);
				gotoxy(4,i++);
				printf("Deseja alterar tudo?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Nome: ");
					fflush(stdin);
					gets(aut.nome);
					while(stricmp(aut.nome,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nome: ");
						fflush(stdin);
						gets(aut.nome);
					}
					gotoxy(4,i++);
					printf("Nacionalidade: ");
					fflush(stdin);
					gets(aut.nacionalidade);
					while(stricmp(aut.nacionalidade,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nacionalidade: ");
						fflush(stdin);
						gets(aut.nacionalidade);
					}
					gotoxy(4,i++);
					fseek(PtrAut,pos,0);
					fwrite(&aut,sizeof(TPautores),1,PtrAut);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro nome (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do autor que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrAut);
}

void alteracao_autores(){
	int op;
	op = menu_altera_autores();;
	while(op!=27) {
		switch(op) {
			case 'A': 
					altera_nome_autores();
					break;
			case 'B': 
					altera_nacionalidade_autores();
					break;
			case 'C': 
					altera_tudo_autores();
					break;
		}
		op = menu_altera_autores();
		
	}
}

void altera_nome_clientes() {
	TPpessoas pes;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
		getche();
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do cliente que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do cliente que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter,i) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_pessoa(PtrPes,pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados cliente:");
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPautores),1,PtrPes);
				gotoxy(4,i++);
				printf("Id: %d",pes.id_pessoa);
				gotoxy(4,i++);
				printf("Nome: %s",pes.nome);
				gotoxy(4,i++);
				printf("Telefone: %s",pes.telefone);
				gotoxy(4,i++);
				printf("Endereco: %s",pes.endereco);
				gotoxy(4,i++);
				printf("Deseja alterar o Nome?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Nome: ");
					fflush(stdin);
					gets(pes.nome);
					
					while(stricmp(pes.nome,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nome: ");
						fflush(stdin);
						gets(pes.nome);
					}
					gotoxy(4,i++);
					fseek(PtrPes,pos,0);
					fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro nome (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do cliente que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrPes);
}

void altera_telefone_clientes() {
	TPpessoas pes;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
		getche();
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do cliente que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do cliente que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter,i) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_pessoa(PtrPes,pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados cliente:");
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPautores),1,PtrPes);
				gotoxy(4,i++);
				printf("Id: %d",pes.id_pessoa);
				gotoxy(4,i++);
				printf("Nome: %s",pes.nome);
				gotoxy(4,i++);
				printf("Telefone: %s",pes.telefone);
				gotoxy(4,i++);
				printf("Endereco: %s",pes.endereco);
				gotoxy(4,i++);
				printf("Deseja alterar o Telefone?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Telefone: ");
					fflush(stdin);
					gets(ver_caracter);
	
					while(verifica_caracter(ver_caracter,i) == 1 ) {
						system("cls");
						MolduraCRUD();
						gotoxy(4,6);
						printf("Telefone: ");
						fflush(stdin);
						gets(ver_caracter);
					}
					strcpy(pes.telefone,ver_caracter);
					gotoxy(4,i++);
					fseek(PtrPes,pos,0);
					fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro Telefone (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do cliente que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrPes);
}

void altera_endereco_clientes() {
	TPpessoas pes;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
		getche();
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do cliente que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do cliente que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter,i) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_pessoa(PtrPes,pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados cliente:");
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPautores),1,PtrPes);
				gotoxy(4,i++);
				printf("Id: %d",pes.id_pessoa);
				gotoxy(4,i++);
				printf("Nome: %s",pes.nome);
				gotoxy(4,i++);
				printf("Telefone: %s",pes.telefone);
				gotoxy(4,i++);
				printf("Endereco: %s",pes.endereco);
				gotoxy(4,i++);
				printf("Deseja alterar o Endereco?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Endereco: ");
					fflush(stdin);
					gets(pes.endereco);
					
					while(stricmp(pes.nome,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Endereco: ");
						fflush(stdin);
						gets(pes.endereco);
					}
					gotoxy(4,i++);
					fseek(PtrPes,pos,0);
					fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro Endereco (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do cliente que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrPes);
}

void altera_tudo_clientes() {
	system("cls");
	MolduraCRUD();
	TPpessoas pes;
	int i=6,pos;
	char op='S', ver_caracter[100];
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	
	
	if(PtrPes == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Qual o id do cliente que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do cliente que deseja alterar: ");
			fflush(stdin);
			gets(ver_caracter);
		}
		
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_pessoa(PtrPes,pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado");
				getch();
			}
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados cliente:");
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Id: %d",pes.id_pessoa);
				gotoxy(4,i++);
				printf("Nome: %s",pes.nome);
				gotoxy(4,i++);
				printf("Telefone: %s",pes.telefone);
				gotoxy(4,i++);
				printf("Endereco: %s",pes.endereco);
				gotoxy(4,i++);
				printf("Deseja alterar Tudo?(S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					i=6;
					gotoxy(4,i++);
					printf("Nome: ");
					fflush(stdin);
					gets(pes.nome);
					while(stricmp(pes.nome,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Nome: ");
						fflush(stdin);
						gets(pes.nome);
					}
					gotoxy(4,i++);
					printf("Telefone: ");
					fflush(stdin);
					gets(ver_caracter);
	
					while(verifica_caracter(ver_caracter,i) == 1 ) {
						i++;
						gotoxy(4,i++);
						printf("Telefone: ");
						fflush(stdin);
						gets(ver_caracter);
					}
					strcpy(pes.telefone,ver_caracter);
					gotoxy(4,i++);
					printf("Endereco: ");
					fflush(stdin);
					gets(pes.endereco);
					while(stricmp(pes.endereco,"\0")==0) {
						gotoxy(4,i++);
						printf("Campo vazio.");
						getch();
						gotoxy(4,i++);
						printf("Endereco: ");
						fflush(stdin);
						gets(pes.endereco);
					}
					gotoxy(4,i++);
					fseek(PtrPes,pos,0);
					fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Registro Alterado");
					getch();
					
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i);
			printf("Deseja alterar outro cliente (S/N)?");
			op = toupper(getche());
			if(op=='S') {
				gotoxy(4,6);
				printf("Qual o id do cliente que deseja alterar:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
			
		}
	}
	fclose(PtrPes);
}

void alteracao_clientes(){
	int op;
	op = menu_altera_clientes();
	while(op!=27) {
		switch(op) {
			case 'A': 
					altera_nome_clientes();
					break;
			case 'B': 
					altera_telefone_clientes();
					break;
			case 'C': 
					altera_endereco_clientes();
					break;
			case 'D': 
					altera_tudo_clientes();
					break;
		}
		op = menu_altera_clientes();
		
	}
}


void altera_data_emp(){
	FILE *PtrEmp = fopen("Emprestimos.dat","rb+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	int i=6, pos, pos2;
	char op='S', ver_caracter[100], string_data[8];
	
	system("cls");
	MolduraCRUD();
	if (PtrEmp == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do emprestimo que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			i=6;
			system("cls");
			MolduraCRUD();
			gotoxy(4,i++);
			printf("Digite o id do emprestimo que deseja alterar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		emp.id_emprestimo = atoi(ver_caracter);
		while(emp.id_emprestimo>0 && op=='S'){
			pos2=busca_id_emprestimo(emp.id_emprestimo);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Emprestimos nao cadastrado!");
				getch();
			}
			else{
				gotoxy(4,i++);
				printf("Dados encontrados:");
				fseek(PtrEmp,pos2,0);
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
				gotoxy(4,i++);
				printf("Id: %d",emp.id_emprestimo);
				pos = busca_id_livro(PtrLv,emp.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Cliente: %s",pes.nome);
				gotoxy(4,i++);
				printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
				gotoxy(4,i++);
				printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
				gotoxy(4,++i);
				printf("Deseja alterar a data de devolucao (S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					gotoxy(4,i++);
					printf("Digite a nova data do emprestimo (DD/MM/AA):");
					fflush(stdin);
					gets(string_data);
					while(!verificar_data_emp(string_data,emp,i)) {
						i++;
						gotoxy(4,i++);
						printf("Digite a data do emprestimo novamente (DD/MM/AA):");
						fflush(stdin);
						gets(string_data);
					}
					fseek(PtrEmp,pos2,0);
					if(verifica_dev_maior(emp)){
						fwrite(&emp,sizeof(TPemprestimos),1,PtrEmp);
						printf("Alteracao Realizada");
					}
					else{
						gotoxy(4,i++);
						printf("Data de devolucao anterior a data de emprestimo.");
					}
					getch();
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Deseja alterar outro emprestimo (S/N)?");
			op=toupper(getche());
			if(op=='S'){
				i=6;
				system("cls");
				MolduraCRUD();
				gotoxy(4,i++);
				printf("Digite o id do emprestimo:");
				fflush(stdin);
				gets(ver_caracter);
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					i=6;
					system("cls");
					MolduraCRUD();
					gotoxy(4,i++);
					printf("Digite o id do emprestimo que deseja alterar:");
					fflush(stdin);
					gets(ver_caracter);
				}
				emp.id_emprestimo = atoi(ver_caracter);
			}
		}
		
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
}

void altera_data_dev(){
	FILE *PtrEmp = fopen("Emprestimos.dat","rb+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	int i=6, pos, pos2;
	char op='S', ver_caracter[100], string_data[8];
	
	system("cls");
	MolduraCRUD();
	if (PtrEmp == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do emprestimo que deseja alterar:");
		fflush(stdin);
		gets(ver_caracter);
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			i=6;
			system("cls");
			MolduraCRUD();
			gotoxy(4,i++);
			printf("Digite o id do emprestimo que deseja alterar:");
			fflush(stdin);
			gets(ver_caracter);
		}
		emp.id_emprestimo = atoi(ver_caracter);
		while(emp.id_emprestimo>0 && op=='S'){
			pos2=busca_id_emprestimo(emp.id_emprestimo);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Emprestimos nao cadastrado!");
				getch();
			}
			else{
				gotoxy(4,i++);
				printf("Dados encontrados:");
				fseek(PtrEmp,pos2,0);
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
				gotoxy(4,i++);
				printf("Id: %d",emp.id_emprestimo);
				pos = busca_id_livro(PtrLv,emp.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Cliente: %s",pes.nome);
				gotoxy(4,i++);
				printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
				gotoxy(4,i++);
				printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
				gotoxy(4,++i);
				printf("Deseja alterar a data de devolucao (S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					gotoxy(4,i++);
					printf("Digite a nova data de devolucao (DD/MM/AA):");
					fflush(stdin);
					gets(string_data);
					while(!verificar_data_dev(string_data,emp,i)) {
						i++;
						gotoxy(4,i++);
						printf("Digite a data de devolucao novamente (DD/MM/AA):");
						fflush(stdin);
						gets(string_data);
					}
					fseek(PtrEmp,pos2,0);
					if(verifica_dev_maior(emp)){
						fwrite(&emp,sizeof(TPemprestimos),1,PtrEmp);
						printf("Alteracao Realizada");
					}
					else{
						gotoxy(4,i++);
						printf("Data de devolucao anterior a data de emprestimo.");
					}
					getch();
				}
			}
			system("cls");
			MolduraCRUD();
			i=6;
			gotoxy(4,i++);
			printf("Deseja alterar outra data de devolução (S/N)?");
			op=toupper(getche());
			if(op=='S'){
				i=6;
				system("cls");
				MolduraCRUD();
				gotoxy(4,i++);
				printf("Digite o id do emprestimo:");
				fflush(stdin);
				gets(ver_caracter);
				while(verifica_caracter(ver_caracter,i) == 1 ) {
					i=6;
					system("cls");
					MolduraCRUD();
					gotoxy(4,i++);
					printf("Digite o id do emprestimo que deseja alterar:");
					fflush(stdin);
					gets(ver_caracter);
				}
				emp.id_emprestimo = atoi(ver_caracter);
			}
		}
		
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
}

void alteracao_emprestimos(){
	int op;
	op = menu_altera_emprestimos();;
	while(op!=27) {
		switch(op) {
			case 'A': 
					altera_data_emp();
					break;
			case 'B': 
					altera_data_dev();
					break;
		}
		op = menu_altera_emprestimos();
		
	}
}

//Ordenações//////////////////////////////

void ordena_id_livro(){//Ordenação Bolh
	TPlivros lv1,lv2;
	int TL, x, y;
	FILE *PtrLv = fopen("Livros.dat","rb+");
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrLv,0,2);
		TL=ftell(PtrLv)/sizeof(TPlivros);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrLv,x*sizeof(TPlivros),0);
				fread(&lv1,sizeof(TPlivros),1,PtrLv);
				
				fseek(PtrLv,y*sizeof(TPlivros),0);
				fread(&lv2,sizeof(TPlivros),1,PtrLv);
				
				if(lv1.id_livro>lv2.id_livro){
					fseek(PtrLv,x*sizeof(TPlivros),0);
					fwrite(&lv2,sizeof(TPlivros),1,PtrLv);
					
					fseek(PtrLv,y*sizeof(TPlivros),0);
					fwrite(&lv1,sizeof(TPlivros),1,PtrLv);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrLv);
}

void ordena_titulo_livro(){//Ordenação Bolh
	TPlivros lv1,lv2;
	int TL, x, y;
	FILE *PtrLv = fopen("Livros.dat","rb+");
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrLv,0,2);
		TL=ftell(PtrLv)/sizeof(TPlivros);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrLv,x*sizeof(TPlivros),0);
				fread(&lv1,sizeof(TPlivros),1,PtrLv);
				
				fseek(PtrLv,y*sizeof(TPlivros),0);
				fread(&lv2,sizeof(TPlivros),1,PtrLv);
				
				if(stricmp(lv1.titulo,lv2.titulo)>0){
					fseek(PtrLv,x*sizeof(TPlivros),0);
					fwrite(&lv2,sizeof(TPlivros),1,PtrLv);
					
					fseek(PtrLv,y*sizeof(TPlivros),0);
					fwrite(&lv1,sizeof(TPlivros),1,PtrLv);
				}
			}
		}
	gotoxy(32,6);
	printf("Ordenacao realizada.");
	getch();
	
	fclose(PtrLv);
	
}

void ordena_ano_pub_livro(){//Ordenação Bolh
	TPlivros lv1,lv2;
	int TL, x, y;
	FILE *PtrLv = fopen("Livros.dat","rb+");
	if(PtrLv == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrLv,0,2);
		TL=ftell(PtrLv)/sizeof(TPlivros);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrLv,x*sizeof(TPlivros),0);
				fread(&lv1,sizeof(TPlivros),1,PtrLv);
				
				fseek(PtrLv,y*sizeof(TPlivros),0);
				fread(&lv2,sizeof(TPlivros),1,PtrLv);
				
				if(lv1.ano_pub>lv2.ano_pub){
					fseek(PtrLv,x*sizeof(TPlivros),0);
					fwrite(&lv2,sizeof(TPlivros),1,PtrLv);
					
					fseek(PtrLv,y*sizeof(TPlivros),0);
					fwrite(&lv1,sizeof(TPlivros),1,PtrLv);
				}
			}
		}
		
	//gotoxy(32,6);
//	printf("Ordenacao realizada.");
//	getch();
	
	fclose(PtrLv);
}

void ordena_livros(){//Ideia: colocar após a ordenação o exibir_livros ou exibir uma mensagem que a ordenação foi concluida com sucesso
	int op;
	op = menu_ordena_livros();
	while(op!=27) {
		switch(op) {
			case 'A': 
					ordena_id_livro();
					break;
			case 'B': 
					ordena_titulo_livro();
					break;
			case 'C': 
					ordena_ano_pub_livro;
					break;
		}
		op = menu_ordena_livros();
		
	}
	
}

void ordena_id_autor(){
	TPautores aut1, aut2;
	FILE *PtrAut = fopen("Autores.dat","rb+");
	int TL, x, y;
	if (PtrAut == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		fseek(PtrAut,0,2);
		TL=ftell(PtrAut)/sizeof(TPautores);
		for(x=0;x<TL-1;x++){
			for(y=x+1;y<TL;y++){
				fseek(PtrAut,x*sizeof(TPautores),0);
				fread(&aut1,sizeof(TPautores),1,PtrAut);
				
				fseek(PtrAut,y*sizeof(TPautores),0);
				fread(&aut2,sizeof(TPautores),1,PtrAut);
				if(aut1.id_autor>aut2.id_autor){
					fseek(PtrAut,x*sizeof(TPautores),0);
					fwrite(&aut2,sizeof(TPautores),1,PtrAut);
					
					fseek(PtrAut,y*sizeof(TPautores),0);
					fwrite(&aut1,sizeof(TPautores),1,PtrAut);
				}
			}
		}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrAut);
}

void ordena_nome_autor(){
	TPautores aut1, aut2;
	FILE *PtrAut = fopen("Autores.dat","rb+");
	int TL, x, y;
	if (PtrAut == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		fseek(PtrAut,0,2);
		TL=ftell(PtrAut)/sizeof(TPautores);
		for(x=0;x<TL-1;x++){
			for(y=x+1;y<TL;y++){
				fseek(PtrAut,x*sizeof(TPautores),0);
				fread(&aut1,sizeof(TPautores),1,PtrAut);
				
				fseek(PtrAut,y*sizeof(TPautores),0);
				fread(&aut2,sizeof(TPautores),1,PtrAut);
				if(stricmp(aut1.nome,aut2.nome)>0){
					fseek(PtrAut,x*sizeof(TPautores),0);
					fwrite(&aut2,sizeof(TPautores),1,PtrAut);
					
					fseek(PtrAut,y*sizeof(TPautores),0);
					fwrite(&aut1,sizeof(TPautores),1,PtrAut);
				}
			}
		}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrAut);
}

void ordena_nacionalidade_autor(){
	TPautores aut1, aut2;
	FILE *PtrAut = fopen("Autores.dat","rb+");
	int TL, x, y;
	if (PtrAut == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		fseek(PtrAut,0,2);
		TL=ftell(PtrAut)/sizeof(TPautores);
		for(x=0;x<TL-1;x++){
			for(y=x+1;y<TL;y++){
				fseek(PtrAut,x*sizeof(TPautores),0);
				fread(&aut1,sizeof(TPautores),1,PtrAut);
				
				fseek(PtrAut,y*sizeof(TPautores),0);
				fread(&aut2,sizeof(TPautores),1,PtrAut);
				if(stricmp(aut1.nacionalidade,aut2.nacionalidade)>0){
					fseek(PtrAut,x*sizeof(TPautores),0);
					fwrite(&aut2,sizeof(TPautores),1,PtrAut);
					
					fseek(PtrAut,y*sizeof(TPautores),0);
					fwrite(&aut1,sizeof(TPautores),1,PtrAut);
				}
			}
		}
//		gotoxy(32,6);
//		printf("Ordenacao realizada.");
//		getch();
	}
	fclose(PtrAut);
}

void ordena_autores() {//Ideia: colocar após a ordenação o exibir_autores ou exibir uma mensagem que a ordenação foi concluida com sucesso
	int op;
	op = menu_ordena_autores();
	while(op!=27) {
		switch(op) {
			case 'A': 
					ordena_id_autor();
					break;
			case 'B': 
					ordena_nome_autor();
					break;
			case 'C': 
					ordena_nacionalidade_autor();
					break;
		}
		op = menu_ordena_autores();
		
	}
}

void ordena_id_cliente(){//Ordenação Bolh
	TPpessoas pes1,pes2;
	int TL, x, y;
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrPes,0,2);
		TL=ftell(PtrPes)/sizeof(TPpessoas);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrPes,x*sizeof(TPpessoas),0);
				fread(&pes1,sizeof(TPpessoas),1,PtrPes);
				
				fseek(PtrPes,y*sizeof(TPpessoas),0);
				fread(&pes2,sizeof(TPpessoas),1,PtrPes);
				
				if(pes1.id_pessoa>pes2.id_pessoa){
					fseek(PtrPes,x*sizeof(TPpessoas),0);
					fwrite(&pes2,sizeof(TPpessoas),1,PtrPes);
					
					fseek(PtrPes,y*sizeof(TPpessoas),0);
					fwrite(&pes1,sizeof(TPpessoas),1,PtrPes);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrPes);
}

void ordena_nome_cliente(){//Ordenação Bolh
	TPpessoas pes1,pes2;
	int TL, x, y;
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrPes,0,2);
		TL=ftell(PtrPes)/sizeof(TPpessoas);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrPes,x*sizeof(TPpessoas),0);
				fread(&pes1,sizeof(TPpessoas),1,PtrPes);
				
				fseek(PtrPes,y*sizeof(TPpessoas),0);
				fread(&pes2,sizeof(TPpessoas),1,PtrPes);
				
				if(stricmp(pes1.nome,pes2.nome)>0){
					fseek(PtrPes,x*sizeof(TPpessoas),0);
					fwrite(&pes2,sizeof(TPpessoas),1,PtrPes);
					
					fseek(PtrPes,y*sizeof(TPpessoas),0);
					fwrite(&pes1,sizeof(TPpessoas),1,PtrPes);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrPes);
}

void ordena_endereco_cliente(){//Ordenação Bolh
	TPpessoas pes1,pes2;
	int TL, x, y;
	FILE *PtrPes = fopen("Pessoas.dat","rb+");
	if(PtrPes == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrPes,0,2);
		TL=ftell(PtrPes)/sizeof(TPpessoas);
		for(x=0;x<TL-1;x++)
			for(y=x+1;y<TL;y++){
				fseek(PtrPes,x*sizeof(TPpessoas),0);
				fread(&pes1,sizeof(TPpessoas),1,PtrPes);
				
				fseek(PtrPes,y*sizeof(TPpessoas),0);
				fread(&pes2,sizeof(TPpessoas),1,PtrPes);
				
				if(stricmp(pes1.endereco,pes2.endereco)>0){
					fseek(PtrPes,x*sizeof(TPpessoas),0);
					fwrite(&pes2,sizeof(TPpessoas),1,PtrPes);
					
					fseek(PtrPes,y*sizeof(TPpessoas),0);
					fwrite(&pes1,sizeof(TPpessoas),1,PtrPes);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrPes);
}

void ordena_clientes() {//Ideia: colocar após a ordenação o exibir_autores ou exibir uma mensagem que a ordenação foi concluida com sucesso
	int op;
	op = menu_ordena_clientes();
	while(op!=27) {
		switch(op) {
			case 'A': 
					ordena_id_cliente();
					break;
			case 'B': 
					ordena_nome_cliente();
					break;
			case 'C': 
					ordena_endereco_cliente();
					break;
		}
		op = menu_ordena_clientes();
		
	}
}
void ordena_titulo_livro_autor() {
	FILE *PtrLA = fopen("LivroAutor.dat","rb+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	TPlivro_autor livro_autor1,livro_autor2;
	TPlivros lv1,lv2;
	int x,y,TL,pos;
	
	if(PtrLA == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrLA,0,2);
		TL=ftell(PtrLA)/sizeof(TPlivro_autor); // TAMANHO LOGICO DO LIVRO-AUTOR
		
		for(x=0;x<TL-1;x++) // PERCORRENDO LIVRO-AUTOR
			for(y=x+1;y<TL;y++){
				fseek(PtrLA,x*sizeof(TPlivro_autor),0); // POSICIONANDO NA POSIÇÃO
				fread(&livro_autor1,sizeof(TPlivro_autor),1,PtrLA); // LENDO NA POSIÇÃO
				rewind(PtrLv); // POSICIONANDO NO COMEÇO
				pos = busca_id_livro(PtrLv, livro_autor1.id_livro); 
				fseek(PtrLv,pos,0);
				fread(&lv1,sizeof(TPlivros),1,PtrLv);
				
				fseek(PtrLA,y*sizeof(TPlivro_autor),0);
				fread(&livro_autor2,sizeof(TPlivro_autor),1,PtrLA);
				rewind(PtrLv);
				pos = busca_id_livro(PtrLv, livro_autor2.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv2,sizeof(TPlivros),1,PtrLv);
				            
				if(stricmp(lv1.titulo,lv2.titulo)>0){
					fseek(PtrLA,x*sizeof(TPlivro_autor),0);
					fwrite(&livro_autor2,sizeof(TPlivro_autor),1,PtrLA);
					
					fseek(PtrLA,y*sizeof(TPlivro_autor),0);
					fwrite(&livro_autor1,sizeof(TPlivro_autor),1,PtrLA);
					rewind(PtrLA);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrLA);
	fclose(PtrLv);
}

void ordena_nome_livro_autor() {
	FILE *PtrLA = fopen("LivroAutor.dat","rb+");
	FILE *PtrAut = fopen("Autores.dat","rb");
	TPlivro_autor livro_autor1,livro_autor2;
	TPautores aut1,aut2;
	int x,y,TL,pos;
	
	if(PtrLA == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura");
	}
	else{
		fseek(PtrLA,0,2);
		TL=ftell(PtrLA)/sizeof(TPlivro_autor); // TAMANHO LOGICO DO LIVRO-AUTOR
		
		for(x=0;x<TL-1;x++) // PERCORRENDO LIVRO-AUTOR
			for(y=x+1;y<TL;y++){
				fseek(PtrLA,x*sizeof(TPlivro_autor),0); // POSICIONANDO NA POSIÇÃO
				fread(&livro_autor1,sizeof(TPlivro_autor),1,PtrLA); // LENDO NA POSIÇÃO
				rewind(PtrAut); // POSICIONANDO NO COMEÇO
				pos = busca_id_autores(PtrAut, livro_autor1.id_autor); 
				fseek(PtrAut,pos,0);
				fread(&aut1,sizeof(TPautores),1,PtrAut);
				
				fseek(PtrLA,y*sizeof(TPlivro_autor),0);
				fread(&livro_autor2,sizeof(TPlivro_autor),1,PtrLA);
				rewind(PtrAut);
				pos = busca_id_autores(PtrAut, livro_autor2.id_autor);
				fseek(PtrAut,pos,0);
				fread(&aut2,sizeof(TPautores),1,PtrAut);
				            
				if(stricmp(aut1.nome,aut2.nome)>0){
					fseek(PtrLA,x*sizeof(TPlivro_autor),0);
					fwrite(&livro_autor2,sizeof(TPlivro_autor),1,PtrLA);
					
					fseek(PtrLA,y*sizeof(TPlivro_autor),0);
					fwrite(&livro_autor1,sizeof(TPlivro_autor),1,PtrLA);
					rewind(PtrLA);
				}
			}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrLA);
	fclose(PtrAut);
}
void ordenar_livro_autor() {//Ideia: colocar após a ordenação o exibir_autores ou exibir uma mensagem que a ordenação foi concluida com sucesso
	int op;
	op = menu_ordena_livro_autor();
	while(op!=27) {
		switch(op) {
			case 'A': 
					ordena_titulo_livro_autor();
					break;
			case 'B': 
					ordena_nome_livro_autor();
					break;
		}
		op = menu_ordena_livro_autor();
		
	}
}

void consulta_livros() {
	TPlivros lv;
	int pos,i=6;
	char op='S', ver_caracter[100];
	FILE *PtrLv = fopen("Livros.dat","rb");
	system("cls");
	MolduraCRUD();
	if(PtrLv==NULL){
		gotoxy(4,6);
		printf("Erro de abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do livro:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o id do livro:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			lv.id_livro = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_livro(PtrLv,lv.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Livro nao cadastrado");
			}	
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados encontrados:");
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Id: %d",lv.id_livro);
				gotoxy(4,i++);
				printf("Titulo: %s",lv.titulo);
				gotoxy(4,i++);
				printf("Ano de Publicacao: %d",lv.ano_pub);
			}
			gotoxy(4,++i);
			printf("Deseja consultar outro livro (S/N)?");
			op = toupper(getch());
			system("cls");
			MolduraCRUD();
			if(op=='S'){
				gotoxy(4,6);
				printf("Digite o id do livro:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrLv);
}

void ordena_id_emprestimos(){
	TPemprestimos emp1, emp2;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb+");
	int TL, x, y;

	if (PtrEmp == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
		getch();
	}
	else{
		fseek(PtrEmp,0,2);
		TL=ftell(PtrEmp)/sizeof(TPemprestimos);
		for(x=0;x<TL-1;x++){
			for(y=x+1;y<TL;y++){
				fseek(PtrEmp,x*sizeof(TPemprestimos),0);
				fread(&emp1,sizeof(TPemprestimos),1,PtrEmp);
				
				fseek(PtrEmp,y*sizeof(TPemprestimos),0);
				fread(&emp2,sizeof(TPemprestimos),1,PtrEmp);
				if(emp1.id_emprestimo>emp2.id_emprestimo){
					fseek(PtrEmp,x*sizeof(TPemprestimos),0);
					fwrite(&emp2,sizeof(TPemprestimos),1,PtrEmp);
					
					fseek(PtrEmp,y*sizeof(TPemprestimos),0);
					fwrite(&emp1,sizeof(TPemprestimos),1,PtrEmp);
				}
			}
		}
		gotoxy(32,6);
		printf("Ordenacao realizada.");
		getch();
	}
	fclose(PtrEmp);
}

void ordenar_emprestimos() {
	int op;
	op = menu_ordena_emprestimos();
	while(op!=27) {
		switch(op) {
			case 'A': 
					ordena_id_emprestimos();
					break;
//			case 'B': 
//					ordena_nome_livro_autor();
//					break;
		}
		op = menu_ordena_emprestimos();
		
	}
}
void exibe_livros() {
	system("cls");
	FILE *PtrLv = fopen("Livros.dat","rb");
	TPlivros lv;
	int i=6, c=4;
	
	gotoxy(4,2);
	if(PtrLv == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	else {
		rewind(PtrLv);
		fread(&lv,sizeof(TPlivros),1,PtrLv);
		red();
		gotoxy(c,4);
		printf("ID");
		gotoxy(c+=8,4);
		printf("TITULO");
		gotoxy(c+=30,4);
		printf("ANO PUB.");
		yellow();
		
		while (!feof(PtrLv))
		{	
			c=4;
			if(lv.status){
				gotoxy(c,i);
				printf("%d",lv.id_livro);
				gotoxy(c+=8,i);
				printf("%s",lv.titulo);
				gotoxy(c+=30,i);
				printf("%d",lv.ano_pub);
				i++;
			}			
			fread(&lv,sizeof(TPlivros),1,PtrLv);
		}
	}
	fclose(PtrLv);
	getch();
}

//AUTORES

void cadastro_autores() {
	FILE *PtrAut = fopen("Autores.dat", "ab+");
	TPautores aut;
	int pos,i=6;   
	char op='S', ver_caracter[100];
	
	system("cls");
	MolduraCRUD();
	
	gotoxy(4,i++);
	printf("Digite o Id do Autor:");
	fflush(stdin);
	gets(ver_caracter);
	
	while(verifica_caracter(ver_caracter,i) == 1 ) {
		system("cls");
		MolduraCRUD();
		gotoxy(4,6);
		printf("Digite o Id do autor:");
		fflush(stdin);
		gets(ver_caracter);
	} // Le o valor em uma string
	
	while(op=='S' && verifica_caracter(ver_caracter) == 0){
		//busca id
		//verificaçao de status
		i=7;
		aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
		gotoxy(4,i);
		if ( busca_id_autores(PtrAut,aut.id_autor) == -1) {
			
			printf("Digite o nome:");
			fflush(stdin);
			gets(aut.nome);
			i++;
			while(stricmp(aut.nome,"\0")==0) {
				gotoxy(4,i);
				printf("Campo vazio.");
				i++;
				gotoxy(4,i);
				printf("Digite o nome novamente:");
				fflush(stdin);
				gets(aut.nome);
				i++;
			}
			gotoxy(4,i);
			printf("Digite a nacionalidade:");
			fflush(stdin);
			gets(aut.nacionalidade);
			i++;
			while(stricmp(aut.nacionalidade,"\0")==0) {
				gotoxy(4,i);
				printf("Campo vazio.");
				i++;
				gotoxy(4,i);
				printf("Digite a nacionalidade novamente:");
				fflush(stdin);
				gets(aut.nacionalidade);
				i++;
			}
			aut.status=1;
			
			fwrite(&aut,sizeof(TPautores),1,PtrAut);
			
			i++;
			gotoxy(4,i);
			
			printf("Autor cadastrado!");
		}
		else {
			i=7;
			gotoxy(4,i);

			printf("Autor ja Cadastrado!");
		}
		
		i++;
		gotoxy(4,i);
		printf("Deseja cadastrar outro autor (S/N)?");
		op = toupper(getche());
		
		i++;
		gotoxy(4,i);
		
		system("cls");
		MolduraCRUD();
		
		if(op=='S') {
			gotoxy(4,6);
			printf("Digite o Id do outro autor:");
			fflush(stdin);
			gets(ver_caracter); // Le o valor em uma string
		}
	}
	fclose(PtrAut);
}

void exibe_autores() {
	system("cls");
	FILE *PtrAut = fopen("Autores.dat","rb+");
	TPautores aut;
	int i=6, c=4;
	
	gotoxy(4,2);
	if(PtrAut == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	else {
		rewind(PtrAut);
		fread(&aut,sizeof(TPautores),1,PtrAut);
		red();
		gotoxy(c,4);
		printf("ID");
		gotoxy(c+=8,4);
		printf("NOME");
		gotoxy(c+=30,4);
		printf("Nacio.");
		yellow();
		
		while (!feof(PtrAut))
		{	
			c=4;
			if(aut.status){
				gotoxy(c,i);
				printf("%d",aut.id_autor);

				gotoxy(c+=8,i);
				printf("%s",aut.nome);

				gotoxy(c+=30,i);
				printf("%s",aut.nacionalidade);
				i++;
			}			
			fread(&aut,sizeof(TPautores),1,PtrAut);
		}
	}
	fclose(PtrAut);
	getch();
}

void consulta_autores() {
	TPautores aut;
	int pos,i=6;
	char op='S', ver_caracter[100];
	FILE *PtrAut = fopen("Autores.dat","rb");
	system("cls");
	MolduraCRUD();
	if(PtrAut==NULL){
		gotoxy(4,6);
		printf("Erro de abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do autor:");
		fflush(stdin);
		gets(ver_caracter); 
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o id do autor:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			aut.id_autor = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_autores(PtrAut,aut.id_autor);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Autor nao cadastrado");
			}	
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados encontrados:");
				fseek(PtrAut,pos,0);
				fread(&aut,sizeof(TPautores),1,PtrAut);
				gotoxy(4,i++);
				printf("Id: %d",aut.id_autor);
				gotoxy(4,i++);
				printf("Nome: %s",aut.nome);
				gotoxy(4,i++);
				printf("Nacionalidade: %s",aut.nacionalidade);
			}
			gotoxy(4,++i);
			printf("Deseja consultar outro autor (S/N)?");
			op = toupper(getch());
			system("cls");
			MolduraCRUD();
			if(op=='S'){
				gotoxy(4,6);
				printf("Digite o id do autor:");
				fflush(stdin);
				gets(ver_caracter);  // Lendo em string
			}
		}
	}
	fclose(PtrAut);
}

//EXECUTAR

void executar_livros() {
	int op;
	
	op = menu_livros();
	
	while(op!=27) {
		switch(op) {
			case 'A': 
					cadastro_livros();
					break;
			case 'B': 
					exclusao_livros();
					break;
			case 'C': 
					altera_livros();
					break;
			case 'D': 
					consulta_livros();
					break;
			case 'E': 
					ordena_livros();
					break;
			case 'F': 
					exibe_livros();
					break;
		}
		op = menu_livros();
	}
	
}

void executar_autores() {
	int op;
	
	op = menu_autores();
	
	while(op!=27) {
		switch(op) {
			case 'A': 
					cadastro_autores();
					break;
			case 'B': 
					exclusao_autores();
					break;
			case 'C': 
					alteracao_autores();
					break;
			case 'D': 
					consulta_autores();
					break;
			case 'E': 
					ordena_autores();
					break;
			case 'F': 
					exibe_autores();
					break;
		}
		op = menu_autores();
	}
	
}

void executar_livro_autor() {
	int op;
	
	op = menu_livro_autor();
	
	while(op!=27) {
		switch(op) {
			case 'A': 
					cadastro_livro_autor();
					break;
			case 'B': 
					exclusao_livro_autor();
					break;
			case 'C': 
					consulta_livro_autor();
					break;
			case 'D': 
					ordenar_livro_autor();
					break;
			case 'E': 
					exibe_livro_autor();
					break;
		}
		op = menu_livro_autor();
	}
}

void cadastro_clientes(){
	TPpessoas pes;
	FILE *PtrPes = fopen("Pessoas.dat","ab+");
	int i=6;
	char op='S', ver_caracter[100];
	
	system("cls");
	MolduraCRUD();
	gotoxy(4,i++);
	printf("Digite o id do cliente:");
	fflush(stdin);
	gets(ver_caracter);
	
	while(verifica_caracter(ver_caracter,i) == 1 ) {
		system("cls");
		MolduraCRUD();
		gotoxy(4,6);
		printf("Digite o Id do cliente:");
		fflush(stdin);
		gets(ver_caracter);
	}
	
	while(op=='S' && verifica_caracter(ver_caracter) == 0){
		i=7;
		pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
		if(busca_id_pessoa(PtrPes,pes.id_pessoa)==-1){
			gotoxy(4,i);
			printf("Digite o nome:");
			fflush(stdin);
			gets(pes.nome);
			i++;
			while(stricmp(pes.nome,"\0")==0) {
				gotoxy(4,i);
				printf("Campo vazio.");
				i++;
				gotoxy(4,i);
				printf("Digite o nome novamente:");
				fflush(stdin);
				gets(pes.nome);
				i++;
			}
			gotoxy(4,i++);
			printf("Digite o telefone:");
			fflush(stdin);
			gets(ver_caracter); // Le o valor em uma string
			while(verifica_caracter(ver_caracter,i) == 1 ) {
				i++;
				gotoxy(4,i++);
				printf("Digite o telefone novamente:");
				fflush(stdin);
				gets(ver_caracter);
			}
			strcpy(pes.telefone,ver_caracter);
			gotoxy(4,i);
			printf("Digite o endereco:");
			fflush(stdin);
			gets(pes.endereco);
			i++;
			while(stricmp(pes.endereco,"\0")==0) {
				gotoxy(4,i);
				printf("Campo vazio.");
				i++;
				gotoxy(4,i);
				printf("Digite o endereco novamente:");
				fflush(stdin);
				gets(pes.endereco);
				i++;
			}
			pes.status=1;
			
			fwrite(&pes,sizeof(TPpessoas),1,PtrPes);
			
			i++;
			gotoxy(4,i);
			printf("Cliente cadastrado!");
		}
		else{
			i++;
			gotoxy(4,i);
			printf("Id ja cadastrado!");
		}
		i++;
		gotoxy(4,i);
		printf("Deseja cadastrar outro cliente (S/N)?");
		op=toupper(getche());
		
		system("cls");
		MolduraCRUD();
		if(op == 'S'){
			gotoxy(4,6);
			printf("Digite o id do cliente:");
			fflush(stdin);
			gets(ver_caracter); // Le o valor em uma string
		}
	}
	fclose(PtrPes);
}

void exibe_clientes() {
	system("cls");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	TPpessoas pes;
	int i=6, c=4;
	
	gotoxy(4,2);
	if(PtrPes == NULL) {
		printf("Erro ao abrir o arquivo.");
	}
	else {
		rewind(PtrPes);
		fread(&pes,sizeof(TPpessoas),1,PtrPes);
		red();
		gotoxy(c,4);
		printf("ID");
		gotoxy(c+=8,4);
		printf("NOME");
		gotoxy(c+=30,4);
		printf("FONE");
		gotoxy(c+=18,4);
		printf("ENDERECO");
		yellow();
		
		while (!feof(PtrPes))
		{	
			c=4;
			if(pes.status){
				gotoxy(c,i);
				printf("%d",pes.id_pessoa);
				gotoxy(c+=8,i);
				printf("%s",pes.nome);
				gotoxy(c+=30,i);
				printf("%s",pes.telefone);
				gotoxy(c+=18,i);
				printf("%s",pes.endereco);
				i++;
			}			
			fread(&pes,sizeof(TPpessoas),1,PtrPes);
		}
	}
	fclose(PtrPes);
	getch();
}

void consulta_clientes() {
	TPpessoas pes;
	int pos,i=6;
	char op='S', ver_caracter[100];
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	system("cls");
	MolduraCRUD();
	if(PtrPes==NULL){
		gotoxy(4,6);
		printf("Erro de abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do cliente:");
		fflush(stdin);
		gets(ver_caracter); 
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o id do autor:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			pes.id_pessoa = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_pessoa(PtrPes,pes.id_pessoa);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Cliente nao cadastrado");
			}	
			else{
				i++;
				gotoxy(4,i++);
				printf("Dados encontrados:");
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Id: %d",pes.id_pessoa);
				gotoxy(4,i++);
				printf("Nome: %s",pes.nome);
				gotoxy(4,i++);
				printf("Telefone: %s",pes.telefone);
				gotoxy(4,i++);
				printf("Endereco: %s",pes.endereco);
			}
			gotoxy(4,++i);
			printf("Deseja consultar outro cliente (S/N)?");
			op = toupper(getch());
			system("cls");
			MolduraCRUD();
			if(op=='S'){
				gotoxy(4,6);
				printf("Digite o id do cliente:");
				fflush(stdin);
				gets(ver_caracter);  // Lendo em string
			}
		}
	}
	fclose(PtrPes);
}

void executar_clientes() {
	int op;
	
	op = menu_clientes();
	
	while(op!=27) {
		switch(op) {
			case 'A': 
					cadastro_clientes();
					break;
			case 'B': 
					exclusao_clientes();
					break;
			case 'C': 
					alteracao_clientes();
					break;
			case 'D': 
					consulta_clientes();
					break;
			case 'E': 
					ordena_clientes();
					break;
			case 'F': 
					exibe_clientes();
					break;
		}
		op = menu_clientes();
	}
	
}



void cadastro_emprestimos(){
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	FILE *PtrEmp = fopen("Emprestimos.dat","ab+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	
	int pos, i=6;
	char op='S', ver_caracter[100], string_data[8],string_data2[8];
	
	system("cls");
	MolduraCRUD();
	gotoxy(4,i++);
	printf("Digite o id do emprestimo:");
	gets(ver_caracter);
	while(verifica_caracter(ver_caracter,i) == 1 ) {
		i=6;
		system("cls");
		MolduraCRUD();
		gotoxy(4,i++);
		printf("Digite o id do emprestimo:");
		gets(ver_caracter);
	}
	emp.id_emprestimo = atoi(ver_caracter);
	while(emp.id_emprestimo>0 && op=='S'){
		pos=busca_id_emprestimo(emp.id_emprestimo);
		if(pos!=-1){
			gotoxy(4,i++);
			printf("Emprestimos ja cadastrado!");
			getch();
		}
		else{
			gotoxy(4,i++);
			printf("Digite o id do livro:");
			gets(ver_caracter);
			while(verifica_caracter(ver_caracter,i) == 1 ) {
				i++;
				gotoxy(4,i++);
				printf("Digite o id do livro novamente:");
				gets(ver_caracter);
			}
			emp.id_livro = atoi(ver_caracter);
			pos=busca_id_livro(PtrLv,emp.id_livro);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Livro nao cadastrado!");
				getch();
			}
			else{
				pos=busca_id_livro_emprestimo(emp.id_livro);
				if(pos!=-1){
					gotoxy(4,i++);
					printf("Este livro ja foi emprestado");
					getch();
				}
				else{
					gotoxy(4,i++);
					printf("Digite o id da pessoa:");
					gets(ver_caracter);
					while(verifica_caracter(ver_caracter,i) == 1 ) {
						i++;
						gotoxy(4,i++);
						printf("Digite o id da pessoa novamente:");
						gets(ver_caracter);
					}
					emp.id_pessoa = atoi(ver_caracter);
					pos=busca_id_pessoa(PtrPes,emp.id_pessoa);
					if(pos==-1){
						gotoxy(4,i++);
						printf("Pessoa nao cadastrada");
						getch();
					}
					else{
						gotoxy(4,i++);
						printf("Digite a data do emprestimo (DD/MM/AA):");
						fflush(stdin);
						gets(string_data);
						while(!verificar_data_emp(string_data,emp,i)) {
							i++;
							gotoxy(4,i++);
							printf("Digite a data do emprestimo novamente (DD/MM/AA):");
							fflush(stdin);
							gets(string_data);
						}
						gotoxy(4,i++);
						printf("Digite a data de devolucao (DD/MM/AA):");
						fflush(stdin);
						gets(string_data2);
						while(!verificar_data_dev(string_data2,emp,i)) {
							i++;
							gotoxy(4,i++);
							printf("Digite a data do devolucao novamente (DD/MM/AA):");
							fflush(stdin);
							gets(string_data2);
						}
						emp.status=1;
						
						if(verifica_dev_maior(emp)){
							fwrite(&emp,sizeof(TPemprestimos),1,PtrEmp);
							printf("Cadastro Realizado");
						}
						else{
							gotoxy(4,i++);
							printf("Data de devolucao anterior a data de emprestimo.");
						}
						getch();
					}
				}
			}
		}
		system("cls");
		MolduraCRUD();
		i=6;
		gotoxy(4,i++);
		printf("Deseja cadastrar outro emprestimo (S/N)?");
		op=toupper(getche());
		if(op=='S'){
			i=6;
			system("cls");
			MolduraCRUD();
			gotoxy(4,i++);
			printf("Digite o id do emprestimo:");
			gets(ver_caracter);
			while(verifica_caracter(ver_caracter,i) == 1 ) {
				i=6;
				system("cls");
				MolduraCRUD();
				gotoxy(4,i++);
				printf("Digite o id do emprestimo:");
				gets(ver_caracter);
			}
			emp.id_emprestimo = atoi(ver_caracter);
		}
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
}

void exibe_emprestimos(){
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	
	int i=2, pos, pos2;
	system("cls");
	if(PtrEmp == NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura");
		getch();
	}
	else{
		gotoxy(4,i++);
		printf("Emprestimos:");
		rewind(PtrEmp);
		fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
		while(!feof(PtrEmp)){
			if(emp.status){
				gotoxy(4,i++);
				printf("Id: %d",emp.id_emprestimo);
				pos = busca_id_livro(PtrLv,emp.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Cliente: %s",pes.nome);
				gotoxy(4,i++);
				printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
				gotoxy(4,i++);
				printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
				i+=1;
				printf("\n\n");
			}
			fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
		}
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
	getche();
}

void consulta_emprestimos() {
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	int pos,i=6;
	char op='S', ver_caracter[100];
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	system("cls");
	MolduraCRUD();
	if(PtrEmp==NULL){
		gotoxy(4,6);
		printf("Erro de abertura");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do emprestimo:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Digite o id do emprestimo:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			emp.id_emprestimo = atoi(ver_caracter); // converte o valor para inteiro
			pos=busca_id_emprestimo(emp.id_emprestimo);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Emprestimo nao cadastrado");
			}	
			else{
				fseek(PtrEmp,pos,0);
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
				if(emp.status){
					i++;
					gotoxy(4,i++);
					printf("Dados encontrados:");
			
					gotoxy(4,i++);
					printf("Id: %d",emp.id_emprestimo);
					pos = busca_id_livro(PtrLv,emp.id_livro);
					fseek(PtrLv,pos,0);
					fread(&lv,sizeof(TPlivros),1,PtrLv);
					gotoxy(4,i++);
					printf("Livro: %s",lv.titulo);
					pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
					fseek(PtrPes,pos,0);
					fread(&pes,sizeof(TPpessoas),1,PtrPes);
					gotoxy(4,i++);
					printf("Cliente: %s",pes.nome);
					gotoxy(4,i++);
					printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
					gotoxy(4,i++);
					printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
				}
			}
			gotoxy(4,++i);
			printf("Deseja consultar outro livro (S/N)?");
			op = toupper(getch());
			system("cls");
			MolduraCRUD();
			if(op=='S'){
				gotoxy(4,6);
				printf("Digite o id do livro:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrEmp);
}
void exclusao_logica_emprestimos(){
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb+");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	int pos, pos2, i=6;
	char op='S', ver_caracter[100];
	system("cls");
	MolduraCRUD();
	if(PtrPes == NULL){
		gotoxy(4,i);
		printf("Erro de Abertura!");
	}
	else{
		gotoxy(4,i++);
		printf("Digite o id do emprestimo que deseja apagar:");
		fflush(stdin);
		gets(ver_caracter); // Le o valor em uma string
	
		while(verifica_caracter(ver_caracter,i) == 1 ) {
			system("cls");
			MolduraCRUD();
			gotoxy(4,6);
			printf("Qual o id do emprestimo que deseja excluir:");
			fflush(stdin);
			gets(ver_caracter);
		}
		while(op=='S' && verifica_caracter(ver_caracter) == 0){
			i=7;
			emp.id_emprestimo = atoi(ver_caracter); // converte o valor para inteiro
			pos2 = busca_id_emprestimo(emp.id_emprestimo);
			if(pos==-1){
				gotoxy(4,i++);
				printf("Id nao cadastrado!");
				getch();
			}
			else{
				fseek(PtrEmp,pos2,0);
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
				gotoxy(4,i++);
				printf("Id: %d",emp.id_emprestimo);
				pos = busca_id_livro(PtrLv,emp.id_livro);
				fseek(PtrLv,pos,0);
				fread(&lv,sizeof(TPlivros),1,PtrLv);
				gotoxy(4,i++);
				printf("Livro: %s",lv.titulo);
				pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
				fseek(PtrPes,pos,0);
				fread(&pes,sizeof(TPpessoas),1,PtrPes);
				gotoxy(4,i++);
				printf("Cliente: %s",pes.nome);
				gotoxy(4,i++);
				printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
				gotoxy(4,i++);
				printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
				gotoxy(4,i++);
				printf("Deseja excluir o dados acima (S/N)?");
				op = toupper(getch());
				system("cls");
				MolduraCRUD();
				if(op=='S'){
					emp.status=0;
					fseek(PtrEmp,pos2,0);
					fwrite(&emp,sizeof(TPemprestimos),1,PtrEmp);
					gotoxy(4,i++);
					printf("Emprestimo excluido com sucesso!");
					getch();
				}
			}
				
			
			gotoxy(4,7);
			printf("Deseja excluir  outro emprestimo (S/N)?");
			op = toupper(getch());
			if(op=='S'){
				system("cls");
				MolduraCRUD();
				gotoxy(4,6);
				printf("Qual id do emprestimo que deseja excluir:");
				fflush(stdin);
				gets(ver_caracter); // Le o valor em uma string
			}
		}
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
}

void exclusao_fisica_emprestimos(){
	TPemprestimos emp;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb+");
	
	system("cls");
	MolduraCRUD();
	if(PtrEmp == NULL){
		gotoxy(4,6);
		printf("Erro de Abertura!");
	}
	else{
		gotoxy(4,6);
		printf("Deseja apagar todos os dados com status 0");
		gotoxy(4,7);
		printf("Permanentemente (S/N)?");
		if(toupper(getche())=='S'){
			FILE *PtrTemp = fopen("Temp.dat","wb");
			rewind(PtrEmp);
			
			fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
			while(!feof(PtrEmp)){
				if(emp.status){
					fwrite(&emp,sizeof(TPemprestimos),1,PtrTemp);
				}
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
			}
			
			fclose(PtrEmp);
			fclose(PtrTemp);
			remove("Emprestimos.dat");
			rename("Temp.dat","Emprestimos.dat");
			gotoxy(4,8);
			printf("Dados excluidos!");
			getch();
		}
		else
			fclose(PtrEmp);
	}
}

void exclusao_emprestimos() {
	int op;
	op = menu_exclusao();
	while(op!=27) {
		switch(op) {
			case 'A': 
					exclusao_logica_emprestimos();
					break;
			case 'B': 
					exclusao_fisica_emprestimos();
					break;
		}
		op = menu_exclusao();
		
	}
	
}

void executar_emprestimos() {
	int op;
	
	op = menu_emprestimos();
	
	while(op!=27) {
		switch(op) {
			case 'A': 
					cadastro_emprestimos();
					break;
			case 'B': 
					exclusao_emprestimos();
					break;
			case 'C': 
					alteracao_emprestimos();
					break;
			case 'D': 
      				consulta_emprestimos();
					break;
			case 'E': 
					ordenar_emprestimos();
					break;
			case 'F': 
					exibe_emprestimos();
					break;
		}
		op = menu_emprestimos();
	}
	
}

int verifica_termo(char aux_titulo[], char palavra[]) {
    int i=0,j=0,x=0,nPalavras=0,tam,igual=0,a;
    char titulo[30];
    
    
    tam = strlen(palavra);
    
    while(i<strlen(aux_titulo))
    {
        if(aux_titulo[i]==' '){
         if(x==tam) {
          igual=1;
   }
   j=0;
   x=0;
   i++;
        }else {
         if(tolower(aux_titulo[i])==tolower(palavra[j])) {
          x++;
   }
   j++;
         i++;
  }
    }
 if(x==tam) 
  igual=1;

 if(igual) 
  return 1;
 else
  return 0;
}

void relatorio_palavra_ano_pub(){ //falta separar o titulos dos livros em palavras para a comparação
	TPlivros lv;
	FILE *PtrLv = fopen("Livros.dat","rb");
	char palavra[20];
	int i=2;
	
	if(PtrLv==NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura!");
		getch();
	}
	else{	
		system("cls");
		gotoxy(4,i++);
		printf("Digite a palavra: ");
		fflush(stdin);
		gets(palavra);
		system("cls");
		gotoxy(4,i++);
		printf("Relatorio:");
		ordena_ano_pub_livro();//tive que tirar a mensagem de ordenação realizada
		rewind(PtrLv);
		fread(&lv,sizeof(TPlivros),1,PtrLv);
		while(!feof(PtrLv)){
			if(verifica_termo(lv.titulo,palavra)){
				if(lv.status){
				gotoxy(4,i++);
				printf("Id: %d",lv.id_livro);
				gotoxy(4,i++);
				printf("Titulo: %s",lv.titulo);
				gotoxy(4,i++);
				printf("Ano Pub: %d",lv.ano_pub);
				i+=2;
				}			
			}
			fread(&lv,sizeof(TPlivros),1,PtrLv);
		}
	}
	fclose(PtrLv);
	getch();
}

void relatorio_emprestimos_separados_pessoa(){
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	
	int i=2, a=4, pos;
	system("cls");
	if (PtrPes ==NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura");
	}
	else{
		rewind(PtrPes);
		fread(&pes,sizeof(TPpessoas),1,PtrPes);
		while(!feof(PtrPes)){
			if(pes.status){
				gotoxy(a,i++);
				printf("Id pessoa: %d",pes.id_pessoa);
				gotoxy(a,i++);
				printf("Cliente: %s",pes.nome);
				rewind(PtrEmp);
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
				while(!feof(PtrEmp)){
					if(emp.id_pessoa==pes.id_pessoa){
						if(emp.status){
							gotoxy(a,i++);
							printf("Id emprestimo: %d",emp.id_emprestimo);
							pos = busca_id_livro(PtrLv,emp.id_livro);
							fseek(PtrLv,pos,0);
							fread(&lv,sizeof(TPlivros),1,PtrLv);
							gotoxy(a,i++);
							printf("Livro: %s",lv.titulo);
							gotoxy(a,i++);
							printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
							gotoxy(a,i++);
							printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
							gotoxy(a,i++);
						}
					}
					fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
					printf("\n");
				}
			}
			if(i==30){
				a=40;
				i=1;
			}
			fread(&pes,sizeof(TPpessoas),1,PtrPes);
		}
	}
	
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
	getch();
}

void relatorio_livros_autor(){
	system("cls");
	FILE *PtrLA = fopen("LivroAutor.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrAut = fopen("Autores.dat","rb");
	TPlivro_autor la;
	TPlivros lv;
	TPautores aut;
	int i=2, pos,id;

	if(PtrLA == NULL) {
		gotoxy(4,i++);
		printf("Erro de Abertura.");
	}
	else {
		gotoxy(4,i++);
		printf("Digite o id do autor que procura:");
		scanf("%d",&id);
		pos=busca_autor_em_livro_autor(id);
		if(pos==-1){
			gotoxy(4,i++);
			printf("Esse autor nao tem livros vinculados");
		}
		else{
			rewind(PtrLA);
			fread(&la,sizeof(TPlivro_autor),1,PtrLA);
			while (!feof(PtrLA))
			{	if(la.status){
					if(id==la.id_autor){
							pos = busca_id_livro(PtrLv,la.id_livro);
							fseek(PtrLv,pos,0);
							fread(&lv,sizeof(TPlivros),1,PtrLv);
							gotoxy(4,i++);
							printf("Livro: %s",lv.titulo);
							pos = busca_id_autores(PtrAut,la.id_autor);
							fseek(PtrAut,pos,0);
							fread(&aut,sizeof(TPautores),1,PtrAut);
							gotoxy(4,i++);
							printf("Autor: %s",aut.nome);
							i+=2;
							gotoxy(4,i);
						}
					}				
				fread(&la,sizeof(TPlivro_autor),1,PtrLA);
			}
		}
		
	}
	fclose(PtrLA);
	fclose(PtrLv);
	fclose(PtrAut);
	getch();
}

void relatorio_emprestimo_pessoa_expecifica(){
	TPemprestimos emp;
	TPlivros lv;
	TPpessoas pes;
	FILE *PtrEmp = fopen("Emprestimos.dat","rb");
	FILE *PtrLv = fopen("Livros.dat","rb");
	FILE *PtrPes = fopen("Pessoas.dat","rb");
	int i=2,pos,id;
	
	system("cls");
	if(PtrEmp == NULL){
		gotoxy(2,i++);
		printf("Erro de Abertura");
	}
	else{
		gotoxy(2,i++);
		printf("Digite o id da pessoa que procura:");
		scanf("%d",&id);
		pos=busca_pessoa_em_emprestimo(id);
		if(pos==-1){
			gotoxy(2,i++);
			printf("Pessoa nao possui emprestimos");
		}
		else{
			rewind(PtrEmp);
			fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
			while(!feof(PtrEmp)){
				if(emp.status){
					if(emp.id_pessoa==id){
						gotoxy(4,i++);
						printf("Id: %d",emp.id_emprestimo);
						pos = busca_id_livro(PtrLv,emp.id_livro);
						fseek(PtrLv,pos,0);
						fread(&lv,sizeof(TPlivros),1,PtrLv);
						gotoxy(4,i++);
						printf("Livro: %s",lv.titulo);
						pos = busca_id_pessoa(PtrPes,emp.id_pessoa);
						fseek(PtrPes,pos,0);
						fread(&pes,sizeof(TPpessoas),1,PtrPes);
						gotoxy(4,i++);
						printf("Cliente: %s",pes.nome);
						gotoxy(4,i++);
						printf("Data de Emprestimo: %d/%d/%d",emp.emp.dia,emp.emp.mes,emp.emp.ano);
						gotoxy(4,i++);
						printf("Data de Devolucao: %d/%d/%d",emp.dev.dia,emp.dev.mes,emp.dev.ano);
					}
				}
				fread(&emp,sizeof(TPemprestimos),1,PtrEmp);
			}
		}
	}
	fclose(PtrEmp);
	fclose(PtrLv);
	fclose(PtrPes);
	getch();
}

void relatorio_letra_nacionalidade(){
	TPautores aut;
	FILE *PtrAut = fopen("Autores.dat","rb");
	int i=2;
	char letra;
	
	system("cls");
	if(PtrAut==NULL){
		gotoxy(4,i++);
		printf("Erro de Abertura!");
		getch();
	}
	else{
		printf("Digite a letra que deseja:");
		scanf(" %c",&letra);
		system("cls");
		gotoxy(4,i++);
		printf("Relatorio:");
		ordena_nacionalidade_autor();//tive que tirar a mensagem de ordenação realizada
		rewind(PtrAut);
		fread(&aut,sizeof(TPautores),1,PtrAut);
		while(!feof(PtrAut)){
				if(aut.nome[0]==letra){
					if(aut.status){
					gotoxy(4,i++);
					printf("Id: %d",aut.id_autor);
					gotoxy(4,i++);
					printf("Nome: %s",aut.nome);
					gotoxy(4,i++);
					printf("Nacionalidade: %s",aut.nacionalidade);
					i+=2;
					}			
				}
			fread(&aut,sizeof(TPautores),1,PtrAut);
		}
	}
	fclose(PtrAut);
	getch();
}

void executar_relatorios() {
	int op;
	op = menu_relatorios();
	while(op!=27) {
		switch(op) {
			case 'A': 
					relatorio_letra_nacionalidade();
					break;
			case 'B': 
					relatorio_palavra_ano_pub();
					break;
			case 'C': 
					relatorio_emprestimo_pessoa_expecifica();
					break;
			case 'D': 
					relatorio_livros_autor();
					break;
			case 'E': 
					relatorio_emprestimos_separados_pessoa();
					break;
		}
		op = menu_relatorios();
	}
}

void executar_principal(){
	int op;
	op = menu_inicial();
	while(op!=27) {
		switch(op) {
			case 'A': 
					executar_livros();
					break;
			case 'B': 
					executar_autores();
					break;
			case 'C': 
					executar_livro_autor();
					break;
			case 'D': 
					executar_clientes();
					break;
			case 'E': 
					executar_emprestimos();
					break;
			case 'F':
					executar_relatorios();
					break;
		}
		op = menu_inicial();
	}

}

int main(int argc, char *argv[]) {
	executar_principal();
	return 0;
}
