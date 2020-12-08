#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
	int preco;
	int valor;
};

bool cmp(item a,item b)
{
	if(a.valor != b.valor)
		return a.valor > b.valor;
	else
		return a.preco < b.preco;
}

int refari_rapido(item v[],int n,int qnt_pecas)
{
	int qntd;
	int resultado;
	qntd = qnt_pecas;
	resultado = 0;
	sort(v,v+n,cmp);
	
	for(int i = 0;i < n; i++)
	{
		if(qntd >= v[i].preco)
		{
			resultado = resultado + v[i].valor;
			qntd = qntd - v[i].preco;
		}
	}
	
	return resultado;
}

int main()
{
	item v[49]; //peças 0-50
	int o; // orçamento 0-1000
	int qnt_pecas; // peças 0-50
	
	//verificação 0-1000
	do
    {
        cin >> o;
    } while (! (o >=0 && o <=1000 ));
    
    //verificação 0-50
	do
    {
        cin >> qnt_pecas;
    } while (! (qnt_pecas >=0 && qnt_pecas <=50 ));
	
	for(int i = 0;i < qnt_pecas;i++)
	{
		// entrada do preco e do valor
		cin >> v[i].preco >> v[i].valor;
	}
	cout << refari_rapido(v, qnt_pecas, o)<< endl;
	return 0;
}