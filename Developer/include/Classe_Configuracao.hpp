// ConfiguracaoFonte.h
#ifndef Classe_Configuracao
#define Classe_Configuracao

#include <iostream>
#include <nlohmann/json.hpp> // Certifique-se de incluir a biblioteca JSON correta
#include <string>
#include <vector>

using json = nlohmann::json;

class Converter_Json_De_Configuracoes {
  public:
	Converter_Json_De_Configuracoes(void) {}

	Converter_Json_De_Configuracoes(json Configuracao_Recebida) {
		Caminho_Pasta_Principal = Configuracao_Recebida["Caiminho_Do_Local_Com_Linguagens"];

		Fonte_Padrao_De_Programa = Configuracao_Recebida["Fonte_Padrao_De_Programa"];
		Fonte_Saudacao_De_Programa = Configuracao_Recebida["Fonte_Saudacao_De_Programa"];
		Cor_Da_Fonte = Configuracao_Recebida["Cor_Da_Fonte"];
		Cor_Da_Borda = Configuracao_Recebida["Cor_Da_Borda"];
		Cor_De_Fundo_Da_Janela = Configuracao_Recebida["Cor_De_Fundo_Da_Janela"];

		Imagens_Ilustrativas_De_Linguagem = Configuracao_Recebida["Imagens_Ilustrativas_De_Linguagem"];
		Abrir_Paginas_Com_Projeto = Configuracao_Recebida["Abrir_Paginas_Com_Projeto"];

		Tamanho_Da_Fonte = Configuracao_Recebida["Tamanho_De_Fonte"];
		Tamanho_Da_Fonte_Pequeno = Tamanho_Da_Fonte * 0.5;
		Tamanho_Da_Fonte_Grande = Tamanho_Da_Fonte * 1.5;
	}

	std::string Fonte_Padrao_De_Programa;
	std::string Fonte_Saudacao_De_Programa;
	std::string Cor_Da_Fonte;
	std::string Cor_Da_Borda;
	std::string Cor_De_Fundo_Da_Janela;
	std::string Caminho_Pasta_Principal;

	bool Imagens_Ilustrativas_De_Linguagem;
	bool Abrir_Paginas_Com_Projeto;

	int Tamanho_Da_Fonte;
	int Tamanho_Da_Fonte_Pequeno;
	int Tamanho_Da_Fonte_Grande;
};

class Converter_Json_De_Criacao_De_Configuracao {
  public:
	Converter_Json_De_Criacao_De_Configuracao(void) {}

	Converter_Json_De_Criacao_De_Configuracao(json Configuracao_Recebida) {
		Configuracoes_Do_Tipo_Texto = Configuracao_Recebida["Configuracoes_Do_Tipo_Texto"];
		Configuracoes_Do_Tipo_Numero = Configuracao_Recebida["Configuracoes_Do_Tipo_Numero"];
		Configuracoes_Do_Tipo_Checkbox = Configuracao_Recebida["Configuracoes_Do_Tipo_Checkbox"];
	}

	std::vector<std::string> Configuracoes_Do_Tipo_Texto;
	std::vector<std::string> Configuracoes_Do_Tipo_Numero;
	std::vector<std::string> Configuracoes_Do_Tipo_Checkbox;
};

#endif // Classe_Configuracao