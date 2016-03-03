#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Gato.h"
#include "Evaluador.h"
#include "NodoTrinario.h"

using namespace std;

//Escribe los datos del objeto gato (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios gatos en un solo archivo
void escribir(string nombre_archivo, Gato*gato, int posicion)
{
    ofstream out(nombre_archivo.c_str(), ios::in);
    if(!out.is_open()){
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*45);
    out.write((char*)&gato->edad,4);
    out.write((char*)gato->nombre.c_str(),20);
    out.write((char*)gato->raza.c_str(),20);
    out.write((char*)&gato->sexo,1);
    out.close();
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion);

    in.seekg(posicion*45);
    int edad;
    char nombre[20];
    char raza[20];
    char sexo;
    in.read((char*)&edad,4);
    in.read((char*)nombre,20);
    in.read((char*)raza,20);
    in.read((char*)&sexo,1);
    Gato *gato = new Gato(edad,sexo,nombre,raza);
    return gato;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
    double cant_gatos=0, acum = 0;

    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    cant_gatos = in.tellg()/45;

    for(int i =0; i <cant_gatos; i++){
        acum +=leer(nombre_archivo, i)->edad;
    }
    return acum/cant_gatos;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    int mayor = 0;
    for(set<int>::iterator temp = mi_set.begin(); temp != mi_set.end(); temp++){
        if(*temp > mayor){
            mayor = *temp;
        }
    }
    return mayor;
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;

    int size_a = a.size();
    int ac1=0;

    while(ac1 != size_a){
        resultado.insert(a.front());
        a.pop();
        ac1++;
    }

    int size_b = b.size();
    int ac2=0;

    while(ac2 != size_b){
        resultado.insert(b.top());
        b.pop();
        ac2++;
    }
    return resultado;
}

//Devuelve true si buscada (dada) existe en mi_mapa (dado), de lo contrario devuelve false
//Se debe de buscar en las llaves y en los valores almacenados en cada vector del mapa
bool existe(map<string,vector<string> >mi_mapa, string buscada)
{
    return false;
}

//Devuelve el valor mayor almacenado en el arbol con raiz dada
int getMayor(NodoTrinario* raiz)
{
    return -1;
}

//Busca y reemplaza dado los valores buscado y reemplazo en el arbol con raiz dada
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo)
{

}

char retener3Bits(char bytes)
{
    char retener = 7;
    char acumular = bytes&retener;
    return acumular;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

