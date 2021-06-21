
#include "priority_queue.h"
#include <iostream>

using namespace std;

int main(){

	
	Priority_Queue<int> pq;

	pq.insertar_elemento(15,5);
	pq.insertar_elemento(13,3);
	pq.insertar_elemento(22,2);
	pq.insertar_elemento(10,0);

	pq.print();

	cout << "Consulta maximo: " << pq.maximo() << endl;

	pq.insertar_elemento(32,2);
	pq.insertar_elemento(11,0);

	pq.print();

	cout << "Consulta maximo: " << pq.maximo() << endl;
	pq.extraer_max();

	cout << "Consulta maximo: " << pq.maximo() << endl;
	pq.extraer_max();

	cout << "Consulta maximo: " << pq.maximo() << endl;
	pq.extraer_max();

	cout << "Consulta maximo: " << pq.maximo() << endl;
	pq.extraer_max();

	pq.print();

	cout << "\n\n------ Caso Personas-------\n\n";
	struct persona {
		int edad;
		string condicion;

		persona(){
			this->edad = 0;
			this->condicion = "";
		}

		persona(int e, string c){
			this->edad = e;
			this->condicion = c;
		}

		~persona(){
		}

		void print(){
			cout << "--------" << "\npersona\nedad:" << this->edad << "\ncondicion: " << condicion << "\n--------" << endl;
		}
	};

	persona p1 = persona(34,"embarazada");
	persona p2 = persona(89, "adulto mayor");
	persona p3 = persona(18, "joven");
	persona p4 = persona(34, "joven");
	persona p0 = persona(88, "adulto mayor");

	Priority_Queue<persona> pq2;

	pq2.insertar_elemento(p1,1);
	pq2.insertar_elemento(p2,0);
	pq2.insertar_elemento(p3,2);
	pq2.insertar_elemento(p4,2);
	pq2.insertar_elemento(p0,0);

	persona p5 = pq2.extraer_max();
	p5.print();
	persona p6 = pq2.extraer_max();
	p6.print();
	persona p7 = pq2.extraer_max();
	p7.print();
	persona p8 = pq2.extraer_max();
	p8.print();
	persona p9 = pq2.extraer_max();
	p9.print();
	
	return 0;
}