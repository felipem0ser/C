#include <iostream>
#include <cstring> // strlen e strcmp

using namespace std;

#define m 29 // galinheiro

struct galinha
{
	char nome[30];
	char ovos[30];
	char peso[30];
	int status;

};

int hashing_duplo(int k, int i)
{
	int h1, h2;
	h1 = k % m;
	h2 = 1 + (k % (m - 1));
	return (h1 + i * h2) % m;
}

int calcula_chave(galinha info)
{
	int k;
	k = 0;
	for(int i = 0; i < (int)strlen(info.nome); i++)
	{
		k = k + (int)info.nome[i];
	}
	return k; // soma das letras
};
              

int hash_insert(galinha info, galinha tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info);// k- info 
	i=0;
	do
	{
		j=hashing_duplo(k,i);// mesmo que serch 
		if(tabela[j].status != 1)// tabela de j ==-1
		{
			tabela[j]=info;
			tabela[j].status = 1; // marcando como ocupada
			return j;
		}
		i++;
	}while(i<m);
	
	return -1;
}

int hash_search( galinha info, galinha tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info); // tem que ser a mesma funcao da insert 
	i=0; // nao tem colisao 
	do
	{
		j=hashing_duplo(k,i);// mesmo que insert, se for diferente e tiver colisao da ruim. 
		if(strcmp(info.nome, tabela[j].nome) == 0  && tabela[j].status == 1)// o1 e para informar qu estava ocupado 
			return j;
		i++;
	}while(i < m && tabela[j].status != 0);
	
	return -1;
}
int hash_search_remove( galinha info, galinha tabela[])
{
	int i;// numero de colisoes 
	int j;// posicoes 
	int k;// chave 
	k=calcula_chave(info); // tem que ser a mesma funcao da insert 
	i=0; // nao tem colisao
	do
	{
		j=hashing_duplo(k,i);// mesmo que insert, se for diferente e tiver colisao da ruim. 
		if(strcmp(info.nome, tabela[j].nome) == 0 && strcmp(info.peso, tabela[j].peso) == 0&& tabela[j].status == 1)// o1 e para informar qu estava ocupado 
			return j;
		i++;
	}while(i < m && tabela[j].status != 0);
	
	return -1;
}


void hash_remove(galinha info, galinha tabela[])
{
	int posicao; // posicao da info removida
	posicao = hash_search_remove(info, tabela);
	if(posicao != -1){
		tabela[posicao].status = 2;
		cout<<"Galinha removida \n"; 
	}
	else {
		cout<<"Galinha nao registrada"<<endl; 
	}
}

void init(galinha tabela[])
{
	for(int i = 0; i<m; i++)
		tabela[i].status = 0; // inicialmente todas as posicoes vazias
}




int main()
{
	galinha tabela[m];
	init (tabela);
	int op;
	char nome[30], ovos[30], peso[30];
	galinha info;

	for(int i = 1000; i > 0; i--)
	{
		cin >> op;
		if (op == 1) // cadastro
		{
			cin.ignore();
			cin.getline(nome, 30);
			cin.getline(ovos, 30);
			cin.getline(peso, 30);
		

			strcpy(info.nome, nome);
			strcpy(info.ovos, ovos);
			strcpy(info.peso, peso);
		

			int ins = hash_insert(info, tabela);
			if(ins != -1)
			{
				cout << "Galinha inserida" << endl;	// inseri na posicao
			}
			else
			{
				cout << "Galinha nao inserida" << endl; // estava lotada.
			}



		}
		else if (op == 2) // pesquiisa
		{

			cin.ignore();
			cin.getline(nome, 30);
			

			strcpy(info.nome, nome);


			int busca;
			busca = hash_search(info, tabela);
			if(busca != -1)
			{
				cout<<tabela[busca].nome<<endl;
				cout<<tabela[busca].ovos<<endl;
				cout<<tabela[busca].peso<<endl;
			
				
			}
			else
			{
				cout << "Galinha nao existente" << endl;
			}

		}
		else if (op==3) // remocao
		{

			cin.ignore();
			cin.getline(nome,30);
			cin.getline (peso,30);
			strcpy(info.nome, nome);
			strcpy(info.peso,peso);
			hash_remove(info, tabela); 
			
		}
		else if (op==4)
			break;


	}

}