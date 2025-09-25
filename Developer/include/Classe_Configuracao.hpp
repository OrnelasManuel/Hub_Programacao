// ConfiguracaoFonte.h
#ifndef Classe_Configuracao
#define Classe_Configuracao

#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp> // Certifique-se de incluir a biblioteca JSON correta
#include <string>
#include <vector>

extern void Estilizacao_De_Conteudo(void);

using json = nlohmann::json;

class Converter_Json_De_Configuracoes {
  private:
	std::string Fonte_Padrao_De_Programa;
	std::string Fonte_Saudacao_De_Programa;
	std::string Cor_Da_Fonte;
	std::string Cor_Da_Borda;
	std::string Cor_De_Fundo_Da_Janela;
	std::string Caminho_Pasta_Principal;

	std::vector<std::string> Temas_De_Projetos;
	std::vector<std::string> Temas_De_Projetos_Desativados;

	bool Imagens_Ilustrativas_De_Linguagem;
	bool Abrir_Paginas_Com_Projeto;

	int Tamanho_Da_Fonte;
	int Tamanho_Da_Fonte_Pequeno;
	int Tamanho_Da_Fonte_Grande;

  public:
	Converter_Json_De_Configuracoes(void) {}

	Converter_Json_De_Configuracoes(json Configuracao_Recebida) {
		Caminho_Pasta_Principal = Configuracao_Recebida["Caiminho_Do_Local_Com_Linguagens"];
		Fonte_Padrao_De_Programa = Configuracao_Recebida["Fonte_Padrao_De_Programa"];
		Fonte_Saudacao_De_Programa = Configuracao_Recebida["Fonte_Saudacao_De_Programa"];
		Cor_Da_Fonte = Configuracao_Recebida["Cor_Da_Fonte"];
		Cor_Da_Borda = Configuracao_Recebida["Cor_Da_Borda"];
		Cor_De_Fundo_Da_Janela = Configuracao_Recebida["Cor_De_Fundo_Da_Janela"];

		Temas_De_Projetos = Configuracao_Recebida["Temas_De_Projetos"];
		Temas_De_Projetos_Desativados = Configuracao_Recebida["Temas_De_Projetos_Desativados"];

		Imagens_Ilustrativas_De_Linguagem = Configuracao_Recebida["Imagens_Ilustrativas_De_Linguagem"];
		Abrir_Paginas_Com_Projeto = Configuracao_Recebida["Abrir_Paginas_Com_Projeto"];

		Tamanho_Da_Fonte = Configuracao_Recebida["Tamanho_De_Fonte"];
		Tamanho_Da_Fonte_Pequeno = Tamanho_Da_Fonte * 0.5;
		Tamanho_Da_Fonte_Grande = Tamanho_Da_Fonte * 1.5;
	}

	//-----------------------------------------------------------------------------------------------//

	void Atualizar_Configuracoes(json &Configuracao_Recebida, bool Atualizar_Arquivo = true) {

		Caminho_Pasta_Principal = Configuracao_Recebida["Caiminho_Do_Local_Com_Linguagens"];
		Fonte_Padrao_De_Programa = Configuracao_Recebida["Fonte_Padrao_De_Programa"];
		Fonte_Saudacao_De_Programa = Configuracao_Recebida["Fonte_Saudacao_De_Programa"];
		Cor_Da_Fonte = Configuracao_Recebida["Cor_Da_Fonte"];
		Cor_Da_Borda = Configuracao_Recebida["Cor_Da_Borda"];
		Cor_De_Fundo_Da_Janela = Configuracao_Recebida["Cor_De_Fundo_Da_Janela"];

		Temas_De_Projetos = Configuracao_Recebida["Temas_De_Projetos"];
		Temas_De_Projetos_Desativados = Configuracao_Recebida["Temas_De_Projetos_Desativados"];

		Imagens_Ilustrativas_De_Linguagem = Configuracao_Recebida["Imagens_Ilustrativas_De_Linguagem"];
		Abrir_Paginas_Com_Projeto = Configuracao_Recebida["Abrir_Paginas_Com_Projeto"];

		Tamanho_Da_Fonte = Configuracao_Recebida["Tamanho_De_Fonte"];
		Tamanho_Da_Fonte_Pequeno = Tamanho_Da_Fonte * 0.5;
		Tamanho_Da_Fonte_Grande = Tamanho_Da_Fonte * 1.5;

		if (Atualizar_Arquivo == true) {
			std::ofstream Arquivo_Padrao_Atualizado("./data/Configuracoes.json");
			Arquivo_Padrao_Atualizado << Configuracao_Recebida.dump(4);
			Arquivo_Padrao_Atualizado.close();

			Estilizacao_De_Conteudo();
		}
	}

	//-----------------------------------------------------------------------------------------------//

	std::string &getFonte_Padrao() { return Fonte_Padrao_De_Programa; }
	std::string &getFonte_Saudacao() { return Fonte_Saudacao_De_Programa; }
	std::string &getCor_Fonte() { return Cor_Da_Fonte; }
	std::string &getCor_Borda() { return Cor_Da_Borda; }
	std::string &getCor_Fundo_Janela() { return Cor_De_Fundo_Da_Janela; }
	std::string &getCaminho_Pasta_Principal() { return Caminho_Pasta_Principal; }

	std::vector<std::string> &getTemas_Projetos() { return Temas_De_Projetos; }
	std::vector<std::string> &getTemas_Projetos_Desativados() { return Temas_De_Projetos_Desativados; }

	bool getImagens_Ilustrativas_Linguagem() { return Imagens_Ilustrativas_De_Linguagem; }
	bool getAbrir_Paginas_Projeto() { return Abrir_Paginas_Com_Projeto; }

	int getTamanho_Fonte() { return Tamanho_Da_Fonte; }
	int getTamanho_Fonte_Pequeno() { return Tamanho_Da_Fonte_Pequeno; }
	int getTamanho_Fonte_Grande() { return Tamanho_Da_Fonte_Grande; }

	//-----------------------------------------------------------------------------------------------//

	void setFonte_Padrao(std::string &valor) { Fonte_Padrao_De_Programa = valor; }
	void setFonte_Saudacao(std::string &valor) { Fonte_Saudacao_De_Programa = valor; }
	void setCor_Fonte(std::string &valor) { Cor_Da_Fonte = valor; }
	void setCor_Borda(std::string &valor) { Cor_Da_Borda = valor; }
	void setCor_Fundo_Janela(std::string &valor) { Cor_De_Fundo_Da_Janela = valor; }
	void setCaminho_Pasta_Principal(std::string &valor) { Caminho_Pasta_Principal = valor; }

	void setTemas_Projetos(std::vector<std::string> &valor) { Temas_De_Projetos = valor; }
	void setTemas_Projetos_Desativados(std::vector<std::string> &valor) { Temas_De_Projetos_Desativados = valor; }

	void setImagens_Ilustrativas_Linguagem(bool valor) { Imagens_Ilustrativas_De_Linguagem = valor; }
	void setAbrir_Paginas_Projeto(bool valor) { Abrir_Paginas_Com_Projeto = valor; }

	void setTamanho_Fonte(int valor) { Tamanho_Da_Fonte = valor; }
	void setTamanho_Fonte_Pequeno(int valor) { Tamanho_Da_Fonte_Pequeno = valor; }
	void setTamanho_Fonte_Grande(int valor) { Tamanho_Da_Fonte_Grande = valor; }
};

class Converter_Json_De_Criacao_De_Configuracao {
  public:
	Converter_Json_De_Criacao_De_Configuracao(void) {}

	Converter_Json_De_Criacao_De_Configuracao(json Configuracao_Recebida) {
		Configuracoes_Do_Tipo_Texto = Configuracao_Recebida["Configuracoes_Do_Tipo_Texto"];
		Configuracoes_Do_Tipo_Numero = Configuracao_Recebida["Configuracoes_Do_Tipo_Numero"];
		Configuracoes_Do_Tipo_Checkbox = Configuracao_Recebida["Configuracoes_Do_Tipo_Checkbox"];
		Configuracoes_Do_Tipo_Select = Configuracao_Recebida["Configuracoes_Do_Tipo_Select"];
	}

	std::vector<std::string> Configuracoes_Do_Tipo_Texto;
	std::vector<std::string> Configuracoes_Do_Tipo_Numero;
	std::vector<std::string> Configuracoes_Do_Tipo_Checkbox;
	std::vector<std::string> Configuracoes_Do_Tipo_Select;
};

#endif // Classe_Configuracao