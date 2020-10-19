#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente: public Persona {

	private:
        char razonSocial[50];
        char mail[50];
        int tipoCliente;
	public:
		Cliente();
		Cliente(char*, char*, int);
		//virtual ~Cliente();
		void cargarCliente();
		void mostrarCliente();
		bool guardarClienteDisco();


};

#endif // CLIENTE_H
