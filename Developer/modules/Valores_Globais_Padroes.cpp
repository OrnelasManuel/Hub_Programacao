#include <Variaveis_Globais.hpp>
#include <cstdlib>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

static void Salvar_As_Configuracoes(json Arquivo_Usado_Como_JSON) {
	Converter_Json_De_Configuracoes Padrao_Configuracao(Arquivo_Usado_Como_JSON);

	Configuracao_Universal_JSON = Arquivo_Usado_Como_JSON;

	Configuracao_Universal = Padrao_Configuracao;
}

static void Salvar_As_Criacoes_De_Configuracoes(json Arquivo_Usado_Como_JSON) {
	Converter_Json_De_Criacao_De_Configuracao Criacao_De_Configuracao_Para_Salvar(Arquivo_Usado_Como_JSON);

	Criacao_De_Configuracao_JSON = Arquivo_Usado_Como_JSON;

	Criacao_De_Configuracao = Criacao_De_Configuracao_Para_Salvar;
}

void Atribuicao_De_Valores_Em_Variaveis_Globais(void) {

	std::ifstream Arquivo_Padrao("./data/Configuracoes.json");
	std::ifstream Arquivo_Criacao_De_Configuracao("./data/Configuracoes_Criacao.json");

	try {
		json Padrao_Configuracao_JSON = json::parse(Arquivo_Padrao);

		Arquivo_Padrao.close();

		Salvar_As_Configuracoes(Padrao_Configuracao_JSON);

	} catch (const json::parse_error &e) {
		Arquivo_Padrao.close();

		system("xcopy \".\\backup\\Configuracoes.json\" \".\\data\\\" /Y");

		std::ifstream Arquivo_Padrao_Copiado("./data/Configuracoes.json");

		json Padrao_Configuracao_JSON = json::parse(Arquivo_Padrao_Copiado);

		Salvar_As_Configuracoes(Padrao_Configuracao_JSON);
	}

	try {

		json Criacao_De_Configuracao_Para_Salvar_JSON = json::parse(Arquivo_Criacao_De_Configuracao);

		Arquivo_Criacao_De_Configuracao.close();

		Salvar_As_Criacoes_De_Configuracoes(Criacao_De_Configuracao_Para_Salvar_JSON);

	} catch (const json::parse_error &e) {
		Arquivo_Criacao_De_Configuracao.close();

		system("xcopy \".\\backup\\Configuracoes_Criacao.json\" \".\\data\\\" /Y");

		std::ifstream Arquivo_Criacao_De_Configuracao_Copiado("./data/Configuracoes_Criacao.json");

		json Criacao_De_Configuracao_Para_Salvar_JSON = json::parse(Arquivo_Criacao_De_Configuracao);

		Arquivo_Criacao_De_Configuracao.close();

		Salvar_As_Criacoes_De_Configuracoes(Criacao_De_Configuracao_Para_Salvar_JSON);
	}
}