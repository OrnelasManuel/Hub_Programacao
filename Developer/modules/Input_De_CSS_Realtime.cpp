#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>

extern void Estilizacao_De_Conteudo(void);

extern std::string String_CSS;

static void Ao_Modificar_Texto(GtkTextBuffer *buffer, gpointer user_data) {
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(buffer, &start, &end);

	gchar *Valor_Input_De_CSS_Convertendo = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

	String_CSS = Valor_Input_De_CSS_Convertendo;

	GtkCssProvider *Folha_CSS_Principal = gtk_css_provider_new();
	gtk_css_provider_load_from_data(Folha_CSS_Principal, String_CSS.c_str(), -1, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(Folha_CSS_Principal), GTK_STYLE_PROVIDER_PRIORITY_USER);

	g_object_unref(Folha_CSS_Principal);
	g_free(Valor_Input_De_CSS_Convertendo);
}

void Input_Realtime_CSS(void) {
	GtkWidget *Janela_De_CSS = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(Janela_De_CSS, "CSS_Rum_Time");
	gtk_window_set_title(GTK_WINDOW(Janela_De_CSS), "CSS Realtime");
	gtk_window_set_default_size(GTK_WINDOW(Janela_De_CSS), 750, 600);
	gtk_window_set_position(GTK_WINDOW(Janela_De_CSS), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(Janela_De_CSS), TRUE);

	int x_atual, y_atual;

	gtk_window_get_position(GTK_WINDOW(Janela_De_CSS), &x_atual, &y_atual);
	gtk_window_move(GTK_WINDOW(Janela_De_CSS), x_atual / 1.3, y_atual);

	std::string Texto_Dentro_Do_Label = "CSS";
	std::string Nome_Da_Classe_Da_Opcao = "Input_De_CSS_Rum_Time";

	std::string Valor_De_Texto_Ja_Possuido = String_CSS;
	// std::string Valor_De_Texto_Ja_Possuido = "";

	GtkWidget *Caixa_De_Scroll = gtk_scrolled_window_new(NULL, NULL);
	GtkWidget *Caixa_De_Texto = gtk_text_view_new();
	GtkTextBuffer *Buffer_Do_Caixa_Texto = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Caixa_De_Texto));
	GtkWidget *Caixa_De_Input_De_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *Label_De_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(Caixa_De_Scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

	gtk_text_buffer_set_text(Buffer_Do_Caixa_Texto, Valor_De_Texto_Ja_Possuido.c_str(), -1);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(Caixa_De_Texto), GTK_WRAP_WORD_CHAR);

	gtk_container_add(GTK_CONTAINER(Caixa_De_Scroll), Caixa_De_Texto);

	gtk_widget_set_name(Caixa_De_Input_De_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Texto, Nome_Da_Classe_Da_Opcao.c_str());
	gtk_widget_set_name(Label_De_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

	g_signal_connect(Buffer_Do_Caixa_Texto, "changed", G_CALLBACK(Ao_Modificar_Texto), NULL);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Label_De_Modelo_Configuracao, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Caixa_De_Scroll, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(Janela_De_CSS), Caixa_De_Input_De_Modelo_Configuracao);

	Estilizacao_De_Conteudo();

	gtk_widget_show_all(Janela_De_CSS);
}