#include <iostream>
using namespace std;

struct No
{
	int dado = 0;
	No *prox;
};

struct Fila 
{
	No *ini;
	No *fim;
};

Fila *init()
{
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f)
{
	return (f->ini == NULL);
}

int count(Fila *f)
{
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL)
	{
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void enqueue(Fila *f)
{	
	No *no = new No;
	no->dado = ;
	no->prox = NULL;
	if (isEmpty(f))
	{
		f->ini = no;
	}
	else
	{
   	    f->fim->prox = no;		
	}
	f->fim = no;
	
	cout << "Senha gerada:" << no->dado << endl;
}

int dequeue(Fila *f)
{
	int ret;
	if (isEmpty(f))
	{
		ret = -1;
	}
	else
	{
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL)
		{
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void realizarAtendimento(Fila *f, Fila *sa){
	int valor = dequeue(f);
	enqueue(sa);
}

int main(int argc, char** argv)
{
	Fila *senhasGeradas;
	senhasGeradas = init();
	
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	
	do{
		int option;
	
		cout << "-------------------------------------" << endl;
		cout << "| MENU                               |" << endl;
		cout << "-------------------------------------" << endl;
		cout << "0 - Sair" << endl;
		cout << "1 - Gerar senha" << endl;
		cout << "2 - Realizar atendimento" << endl;
		cout << "--------------------------------------" << endl;
		cout << "- Quantidade de senhas em espera: " << (count(senhasGeradas)) <<endl;
		cout << "--------------------------------------" << endl;
		cin >> option;
		
		switch(option){
			case 0:
				cout << "0" << endl;
				break;
			case 1:
				enqueue(senhasGeradas);
				break;
			case 2:
				cout << "2" << endl;
				break;
			default:
				cout << "Escolha uma opcao!" << endl;
		}
	}while(isEmpty(senhasGeradas) != true);
	
	
	return 0;
}
