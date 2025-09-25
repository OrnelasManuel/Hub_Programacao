#include <Classe_Configuracao.hpp>
#include <Variaveis_Globais.hpp>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
std::string String_CSS;

void Estilizacao_De_Conteudo(void) {
	// Criacao de Folha CSS
	GtkCssProvider *Folha_CSS_Principal = gtk_css_provider_new();
	//---------------------------------------------------------------------------------------
	// Criacao de string CSS formatada
	String_CSS = "#Corpo_Da_Janela {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "}\n\n"

	             "#Texto_De_Saudacao * {\n"
	             "    margin-top: 25px;\n"
	             "}\n\n"

	             "#Texto_De_Saudacao {\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte_Grande()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Saudacao() +
	             "';\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes {\n"
	             "    box-shadow: none;\n"
	             "    border: 1px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 10px;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes label {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Padrao() +
	             "';\n"
	             "    padding: 25px;\n"
	             "    margin: 0;\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto #Botao_De_Opcoes_De_Projetos_Existentes * {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "eventbox {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Botoes_De_Acao_Individual {\n"
	             "    padding: 0;\n"
	             "    border: 1px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 10px;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Botoes_De_Acao_Individual label {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Padrao() +
	             "';\n"
	             "    padding: 0;\n"
	             "    margin: 0;\n"
	             "    background-repeat: no-repeat;\n"
	             "    background-position: left;\n"
	             "    background-size: contain;\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto {\n"
	             "    padding: 0;\n"
	             "    border: 0px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 0;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto > button {\n"
	             "    padding: 0;\n"
	             "    border: 1px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 10px;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Label_De_Texto_Das_Configuracoes_Com_Input {\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Padrao() +
	             "';\n"
	             "}\n\n"

	             "#Inputs_Padrao_Configuracoes {\n"
	             "    margin-bottom: 5px;\n"
	             "}\n\n"

	             "#Input_De_CSS_Rum_Time {\n"
	             "    font-family: 'Consolas';\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte_Pequeno()) +
	             "px;\n"
	             "}\n\n"

	             "#Caixa_De_Opcoes_De_Configuracoes {\n"
	             "    margin: 0 20px;\n"
	             "}\n\n"

	             "#Conjunto_Label_Input_Criacao_De_Projeto_Nome {\n"
	             "    margin: 0 20px;\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Padrao() +
	             "';\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto label {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    margin: 0;\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "    padding: 0;\n"
	             "    background-repeat: no-repeat, no-repeat;\n"
	             "    background-position: left top, right bottom;\n"
	             "    background-size: contain, contain;\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes #Botao_De_Opcoes_De_Projetos_Existentes {\n"
	             "    box-shadow: none;\n"
	             "    border: 1px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 10px;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes #Botao_De_Opcoes_De_Projetos_Existentes label {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
	             "px;\n"
	             "    font-family: '" +
	             Configuracao_Universal.getFonte_Padrao() +
	             "';\n"
	             "    padding: 25px;\n"
	             "    margin: 0;\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes #Botao_De_Opcoes_De_Projetos_Existentes * {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes {\n"
	             "    padding: 0;\n"
	             "    border: 0px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 0;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes > button {\n"
	             "    padding: 0;\n"
	             "    border: 1px solid " +
	             Configuracao_Universal.getCor_Borda() +
	             ";\n"
	             "    margin: 10px;\n"
	             "    border-radius: 0px;\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes label {\n"
	             "    background-color: " +
	             Configuracao_Universal.getCor_Fundo_Janela() +
	             ";\n"
	             "    margin: 0;\n"
	             "    color: " +
	             Configuracao_Universal.getCor_Fonte() +
	             ";\n"
	             "    padding: 0;\n"
	             "    background-repeat: no-repeat, no-repeat;\n"
	             "    background-position: left top, right bottom;\n"
	             "    background-size: contain, contain;\n"
	             "}\n\n"

	             "#Caixa_De_Inicio_Conjunto_De_Opcoes button label {\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte_Pequeno()) +
	             "px;\n"
	             "}\n\n"

	             "#Input_De_Caminho_Das_Configuracoes, #Botao_Abrir_CSS_Das_Configuracoes > label{\n"
	             "    font-size: " +
	             std::to_string(Configuracao_Universal.getTamanho_Fonte_Pequeno()) +
	             "px;\n"
	             "}\n\n"

	             "#Botoes_De_Acao_Individual label {\n"
	             "    padding: 10px;\n"
	             "}\n\n";

	//---------------------------------------------------------------------------------------

	if (Configuracao_Universal.getImagens_Ilustrativas_Linguagem()) {
		for (const auto &item : Pastas_Existentes) {
			std::string Texto_Interno = item;
			std::string Tema_Do_Item_Formatado = Texto_Interno;

			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '-', '_');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '+', 'P');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), ' ', '_');

			String_CSS += "#Botoes_De_Acao_Individual_" + Tema_Do_Item_Formatado + " label {\n    background-image: url('./Aplication_Images/Icons_Projects/" +
			              Tema_Do_Item_Formatado +
			              ".png'), "
			              "url('./Aplication_Images/Icons_Projects/" +
			              Tema_Do_Item_Formatado +
			              ".png')"
			              ";\n}\n\n";
		}

	} else {
		for (const auto &item : Pastas_Existentes) {
			std::string Texto_Interno = item;
			std::string Tema_Do_Item_Formatado = Texto_Interno;

			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '-', '_');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '+', 'P');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), ' ', '_');

			String_CSS += "#Botoes_De_Acao_Individual_" + Tema_Do_Item_Formatado + " label {\n    background-image: none;\n}\n\n";
		}

		String_CSS += "#Caixa_De_Inicio_Conjunto_De_Opcoes button label {\n"
		              "font-size: " +
		              std::to_string(Configuracao_Universal.getTamanho_Fonte()) +
		              "px;\n"
		              "}\n\n";
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