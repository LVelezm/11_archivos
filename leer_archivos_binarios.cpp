#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include <windows.h>
int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	const int IGV = 21;
	string ruc, Producto;
	int unidades;
	double precio, neto, total, igv;
	char aux;
	ifstream archivo;
	int contador = 0;
	
	archivo.open("compras.txt");
	if (archivo.is_open()) {
		archivo >> ruc;
		while (ruc != "X") {
			archivo >> unidades >> precio;
			archivo.get(aux);
			getline(archivo, Producto);
			contador++;
			neto = unidades * precio;
			igv = neto * IGV / 100;
			total = neto + igv;
			cout << "Compra "<< contador << " .-" <<endl;
			cout << "   " << Producto << ": " << unidades
				<< " X " << fixed << setprecision(2)
				<< precio << " = " << neto << " - I.G.V.: "
				<< igv << " - Total: " << total << endl;
			archivo >> ruc;
		}
		archivo.close();
	}
	else{
		cout << "ERROR: No se ha podido abrir el archivo"
			<< endl;
	}
	return 0;
}
