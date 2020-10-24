#ifndef USUARIO_H
#define USUARIO_H


class Usuario{
	private:
		char nombreUser[15];
		int password;
		bool estado;
	public:
//		Usuario();
//		virtual ~Usuario();
        void setNombreUser();
        void setPassword();
        void setActivo(){this->estado = true;}
        void setInactivo(){this->estado = false;}
        void ingresarUsuario();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        const char* getNombreUser(){return this->nombreUser;}
        int getPassword(){return this->password;}
        bool getEstado(){return this->estado;}
};

///--------------------------------- GLOBAL

void crearUsuario();

bool login();





#endif // USUARIO_H
