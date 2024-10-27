#include <Variaveis_Globais.hpp>
#include <iostream>
#include <string>

int Posicao_X, Posicao_Y;

std::string Localizacao_Do_Projeto, Tipo_De_Acesso_Sendo_Feito;

nlohmann::json Configuracao_Universal_JSON;
nlohmann::json Criacao_De_Configuracao_JSON;

Converter_Json_De_Configuracoes Configuracao_Universal;
Converter_Json_De_Criacao_De_Configuracao Criacao_De_Configuracao;