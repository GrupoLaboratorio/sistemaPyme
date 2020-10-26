#ifndef USUARIO_H
#define USUARIO_H


class Usuario{
	private:
		char nombreUser[25];
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
        char* getNombreUser(){return this->nombreUser;}
        const char* getNombreUser(char* nombAux){strcpy(nombAux, this->nombreUser);}
        int getPassword(){return password;}
        bool getEstado(){return estado;}
};

///--------------------------------- GLOBAL

void crearUsuario();

bool login();

void listarUsuarios();





#endif // USUARIO_H
