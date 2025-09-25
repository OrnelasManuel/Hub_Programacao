#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>
#include <iostream>
#include <string>
#include <vector>

int Posicao_X, Posicao_Y;

std::string Localizacao_Do_Projeto, Tipo_De_Acesso_Sendo_Feito, Style_CSS_Rum_Time;

std::vector<std::string> Pastas_Existentes;

std::vector<GtkWidget *> Elementos_Invisiveis;

nlohmann::json Configuracao_Universal_JSON;
nlohmann::json Criacao_De_Configuracao_JSON;

Converter_Json_De_Configuracoes Configuracao_Universal;
Converter_Json_De_Criacao_De_Configuracao Criacao_De_Configuracao;