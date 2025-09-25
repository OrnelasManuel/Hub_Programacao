#ifndef VARIAVEIS_GLOBAIS_HPP
#define VARIAVEIS_GLOBAIS_HPP
#include <Classe_Configuracao.hpp>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

extern int Posicao_X;
extern int Posicao_Y;

extern std::string Localizacao_Do_Projeto;
extern std::string Tipo_De_Acesso_Sendo_Feito;
extern std::string Style_CSS_Rum_Time;

extern std::vector<std::string> Pastas_Existentes;

extern std::vector<GtkWidget *> Elementos_Invisiveis;

extern nlohmann::json Configuracao_Universal_JSON;
extern nlohmann::json Criacao_De_Configuracao_JSON;

extern Converter_Json_De_Configuracoes Configuracao_Universal;
extern Converter_Json_De_Criacao_De_Configuracao Criacao_De_Configuracao;

#endif