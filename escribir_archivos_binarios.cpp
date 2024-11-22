#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <windows.h>
int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	string ruc, producto;
	int unidades;
	double precio;
	char aux;
	ofstream archivo;
	
	archivo.open("output.txt");
	
	cout << "RUC del cliente (X para terminar): ";
	cin >> ruc;
	while (ruc != "X") {
		cin.get(aux);
		cout << "Producto: ";
		getline(cin, producto);
		cout << "Unidades: ";
		cin >> unidades;
		cout << "Precio: ";
		cin >> precio;
		archivo << ruc << " " << unidades << " "
			<< precio << " " << producto << endl;
		cout << "RUC del cliente (X para terminar): ";
		cin >> ruc;  
	}
	archivo << "X";
	archivo.close();
	
	return 0;
}
