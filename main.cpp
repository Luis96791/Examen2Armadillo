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
    out.seekp(posicion);
    out.write(gato->nombre.c_str(), 20);
    out.write(gato->raza.c_str(), 20);
    out.write((char*)&gato->sexo, 4);
    out.write((char*)&gato->edad, 4);

    out.close();
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion);

    char nombre[20];
    char raza[20];
    char sexo;
    char edad;

    in.read((char*)&nombre, 20);
    in.read((char*)&raza, 20);
    in.read((char*)&sexo, 4);
    in.read((char*)&edad, 4);

    in.close();

    Gato *gato = new Gato(edad,sexo,raza,nombre);
    return gato;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
    return -1;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    return -1;
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;
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

char retener3Bits(char byte)
{
    return 0;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

