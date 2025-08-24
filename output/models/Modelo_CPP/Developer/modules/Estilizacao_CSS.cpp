#include <Includes_Geral.hpp>

using json = nlohmann::json;

void Estilizacao_De_Conteudo(void) {
	// Criacao de Folha CSS
	GtkCssProvider *Folha_CSS_Principal = gtk_css_provider_new();
	//---------------------------------------------------------------------------------------

	// Criacao de string CSS
	std::string String_CSS = "#Corpo_Da_Janela {"
	                         "background-color: black;"
	                         "color: white;"
	                         "}";

	//---------------------------------------------------------------------------------------

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