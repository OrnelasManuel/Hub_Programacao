#include <Variaveis_Globais.hpp>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <windows.h>

bool Validador_De_Abertura_De_Sites;

static void Configuracoes_Projeto_CPP_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/108joth4N6yvUPeh46T_bcd23-YvYKTpdSQu8W3-6UNM/edit?tab=t.0#heading=h.nsq0wihpi6j4\"");
	system("start chrome \"https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit?tab=t.0#heading=h.nsq0wihpi6j4\"");
	system("start chrome \"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_CMD_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit?tab=t.0#heading=h.nsq0wihpi6j4\"");
	system("start chrome \"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_Front_End_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4\"");
	system("start chrome \"https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1\"");
	system("start chrome \"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_Java_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_Node_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/1fIwWykk_FFsTEligQ2M3L2RSN8H6D_dZTbj_0xGZqw8/edit?tab=t.0#heading=h.ckv6il383iz1\"");
	system("start chrome \"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_React_Sendo_Aberto(void) {

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1\"");
	system("start chrome \"https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4\"");
	system("start chrome \"https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1\"");
	system("start chrome \"https://chat.openai.com/\"");
}

static void Configuracoes_Projeto_React_Native_Sendo_Aberto(void) {

	system("\"C:\\Users\\Usuario\\Desktop\\Expo Go.lnk\"");

	system("start chrome --profile-directory=\"Profile 1\" --new-window "
	       "\"https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1\"");
	system("start chrome \"https://docs.google.com/document/d/1STMRhPOrALFh3drE6-NJ2TWVyhkshEV3qN2uCZTbbdc/edit?tab=t.0\"");
	system("start chrome \"https://chat.openai.com/\"");
}

void Configurando_Projeto_Para_Abrir(const char *Modo_Escolhido_Para_Inicializacao_De_Paginas, bool Abertura_De_Sites) {
	std::string Comando_De_Abertura_Vs_Code = "start cmd /c \"cd /d " + Localizacao_Do_Projeto + " && start /MAX code .";
	std::string Comando_De_Abertura_Explorador_De_Arquivo = "start cmd /c \"cd /d " + Localizacao_Do_Projeto + " && start .";

	Validador_De_Abertura_De_Sites = Abertura_De_Sites;

	system(Comando_De_Abertura_Vs_Code.c_str());
	system(Comando_De_Abertura_Explorador_De_Arquivo.c_str());

	if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "ReactJs") == 0) {
		if (std::filesystem::exists(Localizacao_Do_Projeto + "\\client") && std::filesystem::is_directory(Localizacao_Do_Projeto + "\\client")) {
			std::string Comando_De_Inicializacao_De_Servidor_Client = "start cmd /k \"cd /d " + Localizacao_Do_Projeto + "\\client && npm start\"";
			system(Comando_De_Inicializacao_De_Servidor_Client.c_str());
		}

		if (std::filesystem::exists(Localizacao_Do_Projeto + "\\server") && std::filesystem::is_directory(Localizacao_Do_Projeto + "\\server")) {
			std::string Comando_De_Inicializacao_De_Servidor_Server = "start cmd /k \"cd /d " + Localizacao_Do_Projeto + "\\server && npm start\"";
			system(Comando_De_Inicializacao_De_Servidor_Server.c_str());
		}
	}

	if (Validador_De_Abertura_De_Sites) {
		std::string Local_Com_Configuracoes_De_Site = Localizacao_Do_Projeto + "\\Config.json";

		std::ifstream Arquivo_Pacote_De_Sites(Local_Com_Configuracoes_De_Site.c_str());

		if (Arquivo_Pacote_De_Sites) {
			json Pacote_De_Sites_JSON = json::parse(Arquivo_Pacote_De_Sites);

			Arquivo_Pacote_De_Sites.close();

			int Vezes_Reproduzidas = 0;

			for (const auto &item : Pacote_De_Sites_JSON) {
				std::string Nome_Do_Site = item;
				std::string Comando_Para_Abrir;

				if (Vezes_Reproduzidas == 0) {
					Comando_Para_Abrir = "start chrome --profile-directory=\"Profile 1\" --new-window \"" + Nome_Do_Site + "\"";
				} else {
					Comando_Para_Abrir = "start chrome \"" + Nome_Do_Site + "\"";
				}
				system(Comando_Para_Abrir.c_str());

				Vezes_Reproduzidas = Vezes_Reproduzidas + 1;
				std::cout << "Item: " << Nome_Do_Site << std::endl;
			}
		} else {
			if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "ReactJs") == 0) {
				Configuracoes_Projeto_React_Sendo_Aberto();
			} else if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "React_Native") == 0) {
				Configuracoes_Projeto_React_Native_Sendo_Aberto();
			} else if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "NodeJs") == 0) {
				Configuracoes_Projeto_Node_Sendo_Aberto();
			} else if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "Front_End") == 0) {
				Configuracoes_Projeto_Front_End_Sendo_Aberto();
			} else if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "CMD") == 0) {
				Configuracoes_Projeto_CMD_Sendo_Aberto();
			} else if (strcmp(Modo_Escolhido_Para_Inicializacao_De_Paginas, "CPP") == 0) {
				Configuracoes_Projeto_CPP_Sendo_Aberto();
			}
		}
	}
}