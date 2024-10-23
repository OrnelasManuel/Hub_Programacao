#include <Classe_Configuracao.hpp>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Estilizacao_De_Conteudo(void) {
	std::ifstream Arquivo_Estilizacao("./data/Estilizacao.json");

	json Estilizacao_Configuracao_JSON = json::parse(Arquivo_Estilizacao);

	Configuracao_Estilo Estilizacao_Configuracao(Estilizacao_Configuracao_JSON);

	Arquivo_Estilizacao.close();

	// Criacao de Folha CSS
	GtkCssProvider *Folha_CSS_Principal = gtk_css_provider_new();
	//---------------------------------------------------------------------------------------

	// Criacao de string CSS
	std::string String_CSS = "#Corpo_Da_Janela {"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "color: " +
	                         Estilizacao_Configuracao.Cor_Da_Fonte +
	                         ";"
	                         "}"

	                         "#Texto_De_Saudacao *{"
	                         "margin-top: 25px;"
	                         "}"

	                         "#Texto_De_Saudacao {"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte_Grande) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Saudacao_De_Programa +
	                         "';"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         "; "
	                         "color: " +
	                         Estilizacao_Configuracao.Cor_Da_Fonte +
	                         "; "
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes {"
	                         "box-shadow: none;"
	                         "border: 1px solid " +
	                         Estilizacao_Configuracao.Cor_Da_Borda +
	                         ";"
	                         "margin: 10px;"
	                         "border-radius: 0px;"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes label {"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "color: " +
	                         Estilizacao_Configuracao.Cor_Da_Fonte +
	                         ";"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Padrao_De_Programa +
	                         "';"
	                         "padding: 25px;"
	                         "margin: 0;"
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes *{"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "eventbox{"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "#Botoes_De_Acao_Individual {"
	                         "padding: 0;"
	                         "border: 1px solid " +
	                         Estilizacao_Configuracao.Cor_Da_Borda +
	                         ";"
	                         "margin: 10px;"
	                         "border-radius: 0px;"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "#Botoes_De_Acao_Individual label {"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "color: " +
	                         Estilizacao_Configuracao.Cor_Da_Fonte +
	                         ";"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Padrao_De_Programa +
	                         "';"
	                         "padding: 0;"
	                         "margin: 0;"
	                         "background-repeat: no-repeat;"
	                         "background-position: left;"
	                         "background-size: contain;"
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto {"
	                         "padding: 0;"
	                         "border: 0px solid " +
	                         Estilizacao_Configuracao.Cor_Da_Borda +
	                         ";"
	                         "margin: 0;"
	                         "border-radius: 0px;"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto > button{"
	                         "padding: 0;"
	                         "border: 1px solid " +
	                         Estilizacao_Configuracao.Cor_Da_Borda +
	                         ";"
	                         "margin: 10px;"
	                         "border-radius: 0px;"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "}"

	                         "#Label_De_Texto_Das_Configuracoes_Com_Input {"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Padrao_De_Programa +
	                         "';"
	                         "}"

	                         "#Inputs_Padrao_Configuracoes {"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Padrao_De_Programa +
	                         "';"
	                         "}"

	                         "#Caixa_De_Opcoes_De_Configuracoes {"
	                         "margin: 0 20px;"
	                         "}"

	                         "#Conjunto_Label_Input_Criacao_De_Projeto_Nome {"
	                         "margin: 0 20px;"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
	                         "px;"
	                         "font-family: '" +
	                         Estilizacao_Configuracao.Fonte_Padrao_De_Programa +
	                         "';"
	                         "}"

	                         "#Caixa_De_Inicio_Conjunto label {"
	                         "background-color: " +
	                         Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela +
	                         ";"
	                         "margin: 0;"
	                         "color: " +
	                         Estilizacao_Configuracao.Cor_Da_Fonte +
	                         ";"
	                         "padding: 0;"
	                         "background-repeat: no-repeat, no-repeat;"
	                         "background-position: left top, right bottom; "
	                         "background-size: contain, contain;"
	                         "}"

	                         "#Input_De_Caminho_Das_Configuracoes{"
	                         "font-size: " +
	                         std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte_Pequeno) +
	                         "px;"
	                         "}"

	                         "#Botoes_De_Acao_Individual label{"
	                         "padding: 10px;"
	                         "}";

	//---------------------------------------------------------------------------------------

	if (Estilizacao_Configuracao.Imagens_Ilustrativas_De_Linguagem) {
		String_CSS += "#Botoes_De_Acao_Individual_ReactJs label {background-image: url('./Aplication_Images/ReactJs.png'), "
		              "url('./Aplication_Images/ReactJs.png')"
		              "; }"
		              "#Botoes_De_Acao_Individual_NodeJs label {background-image: url('./Aplication_Images/NodeJs.png'), "
		              "url('./Aplication_Images/NodeJs.png')"
		              "; }"
		              "#Botoes_De_Acao_Individual_Front_End label {background-image: url('./Aplication_Images/Front_End.png'), "
		              "url('./Aplication_Images/Front_End.png')"
		              "; }"
		              "#Botoes_De_Acao_Individual_CMD label {background-image: url('./Aplication_Images/CMD.png'), "
		              "url('./Aplication_Images/CMD.png')"
		              "; }"
		              "#Botoes_De_Acao_Individual_CPP label {background-image: url('./Aplication_Images/CPP.png'), "
		              "url('./Aplication_Images/CPP.png')"
		              "; }";
	} else {
		String_CSS += "#Botoes_De_Acao_Individual_ReactJs label {background-image: none;}"
		              "#Botoes_De_Acao_Individual_NodeJs label {background-image: none;}"
		              "#Botoes_De_Acao_Individual_Front_End label {background-image: none;}"
		              "#Botoes_De_Acao_Individual_CMD label {background-image: none;}"
		              "#Botoes_De_Acao_Individual_CPP label {background-image: none;}"
		              "#Caixa_De_Inicio_Conjunto button label {"
		              "font-size: " +
		              std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte) +
		              "px;"
		              "}";
	}

	// Adicionando Estilos a Folha CSS
	gtk_css_provider_load_from_data(Folha_CSS_Principal, String_CSS.c_str(), -1, NULL);
	//---------------------------------------------------------------------------------------

	// Estilizacao de elementos
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(Folha_CSS_Principal), GTK_STYLE_PROVIDER_PRIORITY_USER);
	//---------------------------------------------------------------------------------------

	// Limpeza de memoria
	g_object_unref(Folha_CSS_Principal);
	//---------------------------------------------------------------------------------------
}