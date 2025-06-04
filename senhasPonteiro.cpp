#include <iostream>
using namespace std;

struct No
{
	int dado;
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

void enqueue(Fila *f, int v)
{	
	No *no = new No;
	no->dado = v;
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
		delete no;
	}
	return ret;
}

int main(int argc, char** argv)
{
	Fila *senhasGeradas;
	senhasGeradas = init();
	
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	
	int ultimaSenha = 0;
	int option;
	
	do{
		
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
				if(!isEmpty(senhasGeradas)){
					cout << "Ainda ha senhas aguardando atendimento." << endl;
					option = -1;
				}
				break;
			case 1:
				ultimaSenha++;
				enqueue(senhasGeradas, ultimaSenha);
				cout << "Senha gerada: " << ultimaSenha << endl;
				break;
			case 2:
				if (!isEmpty(senhasGeradas)) {
                    int senhaAtendida = dequeue(senhasGeradas);
                    enqueue(senhasAtendidas, senhaAtendida);
                    cout << "Atendendo senha: " << senhaAtendida << endl;
                } else {
                    cout << "Nenhuma senha para atender!" << endl;
                }
				break;
			default:
				cout << "Escolha uma opcao!" << endl;
		}
	}while(option != 0);
	
	
	return 0;
}
