//
// Created by Samuel Vieira on 06/10/20.
//

#include <iostream>
#include <fstream>

#include "DoubleLinkedList.h"

using namespace std;

long ipToLong(string ip){
    int idx = 0;
    long datoFinal= 0, dato = 0;
    while (idx < ip.size()){
        if (ip[idx]!= '.' && ip[idx]!=':'){
            dato = dato*10 + ip[idx]-'0';
        }
        else{
            datoFinal = datoFinal*1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal * 10000 + dato;
    return datoFinal;
}

int main() {
    DoubleLinkedList lista;
    string sMes, sTiempo, sIp, sFalla, fechaHora, sDia;
    long lKey, inicioBusqueda, finBusqueda;
    Info bit;

    ifstream archEnt;
    archEnt.open("bitacora.txt");

    while(archEnt >> sMes) {
        archEnt >> sDia >> sTiempo >> sIp;
        fechaHora = sMes + " " + sDia + " " + sTiempo;
        getline(archEnt, sFalla);
        lKey = ipToLong(sIp);

        bit.key = lKey;
        bit.fechaHora = fechaHora;
        bit.mensajeError = sFalla;

        lista.addFirst(bit);
    }
    archEnt.close();

    lista.sort();
    lista.print();

    cout << "Ingrese el rango de los IPs donde desea hacer la busqueda." << endl;
    cin >> inicioBusqueda >> finBusqueda;

    lista.search(inicioBusqueda, finBusqueda);

    lista.sendToFile();
}