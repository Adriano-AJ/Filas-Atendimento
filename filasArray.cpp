#include <iostream>
using namespace std;

#define MAX 100

struct Fila
{
	float nos[MAX];
	int ini;
	int fim;
};

Fila* init()
{
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f)
{
	return (f->ini == f->fim);
}

int incrementa(int i)
{
	return (i == MAX?0:++i);
}

int count(Fila *f)
{
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim)
	{
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

int enqueue(Fila *f, float v)
{
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar)
	{
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
	return (podeEnfileirar);
}

float dequeue(Fila *f)
{
	float ret;
	if (isEmpty(f))
	{
		ret = -1;
	}
	else
	{
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

void freeFila(Fila *f)
{
	delete(f);
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
		
	freeFila(senhasGeradas);
	freeFila(senhasAtendidas);
	
	return 0;
}
