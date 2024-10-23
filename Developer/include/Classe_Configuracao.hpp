// ConfiguracaoFonte.h
#ifndef Classe_Configuracao
#define Classe_Configuracao

#include <nlohmann/json.hpp> // Certifique-se de incluir a biblioteca JSON correta
#include <string>

using json = nlohmann::json;

class Configuracao_Estilo {
  public:
	Configuracao_Estilo(json Configuracao_Recebida) {
		Fonte_Padrao_De_Programa = Configuracao_Recebida["Fonte_Padrao_De_Programa"];
		Fonte_Saudacao_De_Programa = Configuracao_Recebida["Fonte_Saudacao_De_Programa"];
		Cor_Da_Fonte = Configuracao_Recebida["Cor_Da_Fonte"];
		Cor_Da_Borda = Configuracao_Recebida["Cor_Da_Borda"];
		Cor_De_Fundo_Da_Janela = Configuracao_Recebida["Cor_De_Fundo_Da_Janela"];

		Imagens_Ilustrativas_De_Linguagem = Configuracao_Recebida["Imagens_Ilustrativas_De_Linguagem"];

		Tamanho_Da_Fonte = Configuracao_Recebida["Tamanho_De_Fonte"];
		Tamanho_Da_Fonte_Pequeno = Tamanho_Da_Fonte * 0.5;
		Tamanho_Da_Fonte_Grande = Tamanho_Da_Fonte * 1.5;
	}

	std::string Fonte_Padrao_De_Programa;
	std::string Fonte_Saudacao_De_Programa;
	std::string Cor_Da_Fonte;
	std::string Cor_Da_Borda;
	std::string Cor_De_Fundo_Da_Janela;

	bool Imagens_Ilustrativas_De_Linguagem;

	int Tamanho_Da_Fonte;
	int Tamanho_Da_Fonte_Pequeno;
	int Tamanho_Da_Fonte_Grande;
};

class Configuracao_Padrao {
  public:
	Configuracao_Padrao(void) {}

	Configuracao_Padrao(json Configuracao_Recebida) {
		Caminho_Pasta_Principal = Configuracao_Recebida["Caiminho_Do_Local_Com_Linguagens"];
		Abrir_Paginas_Com_Projeto = Configuracao_Recebida["Abrir_Paginas_Com_Projeto"];
	}

	std::string Caminho_Pasta_Principal;
	bool Abrir_Paginas_Com_Projeto;
};

#endif // Classe_Configuracao