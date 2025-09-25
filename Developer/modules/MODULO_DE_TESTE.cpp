#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>

extern void Estilizacao_De_Conteudo(void);

GtkWidget *window_Teste;    /*Variavel window*/
GtkWidget *Texto_De_Teste;  /*Variavel Texto*/
GtkWidget *Botao_De_Teste;  /*Variavel Botao*/
GtkWidget *Caixa_De_Teste;  /*Variavel Container*/
GtkWidget *Select_De_Teste; /*Variavel Select*/

// extern void Construcao_De_Opcoes_De_Configuracao_Input_Select(GtkWidget *Caixa_Opcoes_Configuracao);

static void Acao_Botao(void) { std::cout << "Botao clicado!" << std::endl; }

static void Alteracao_Select(GtkComboBox *widget, gpointer user_data) {
	std::cout << "Botao clicado!" << std::endl;

	const gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
	if (text != NULL) {
		g_print("Selecionado: %s\n", text);
		g_free((gchar *)text); // liberar memória alocada pelo GTK
	}
}

static void Texto(void) {
	Texto_De_Teste = gtk_label_new("Ola Teste");
	gtk_widget_set_name(Texto_De_Teste, "Texto_De_Saudacao");
	gtk_box_pack_start(GTK_BOX(Caixa_De_Teste), Texto_De_Teste, TRUE, TRUE, 0);
}
static void Botao(void) {
	Botao_De_Teste = gtk_button_new_with_label("Novo Projeto");
	gtk_widget_set_name(Botao_De_Teste, "Botoes_De_Acao_Individual");
	gtk_box_pack_start(GTK_BOX(Caixa_De_Teste), Botao_De_Teste, TRUE, TRUE, 0);
	g_signal_connect(Botao_De_Teste, "clicked", G_CALLBACK(Acao_Botao), NULL);
}

static void Select(void) {
	Select_De_Teste = gtk_combo_box_text_new();
	gtk_widget_set_name(Select_De_Teste, "Select_De_Teste_Conjunto");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(Select_De_Teste), "Opcao 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(Select_De_Teste), "Opcao 2");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(Select_De_Teste), "Opcao 3");
	gtk_box_pack_start(GTK_BOX(Caixa_De_Teste), Select_De_Teste, TRUE, TRUE, 0);
	g_signal_connect(Select_De_Teste, "changed", G_CALLBACK(Alteracao_Select), NULL);
}

static void Ativacao(void) {
	Texto();
	Botao();
	Select();
	// Construcao_De_Opcoes_De_Configuracao_Input_Select(Caixa_De_Teste);
}

void MODULO_DE_TESTE(GtkWidget *window_recebido) {
	window_Teste = window_recebido;
	Caixa_De_Teste = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	gtk_widget_set_name(window_Teste, "Corpo_Da_Janela");
	gtk_widget_set_name(Caixa_De_Teste, "Caixa_De_Teste_Conjunto");
	gtk_window_set_default_size(GTK_WINDOW(window_Teste), 500, 500);
	gtk_window_resize(GTK_WINDOW(window_Teste), 500, 500);
	gtk_window_set_position(GTK_WINDOW(window_Teste), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window_Teste), "Hub de Programacao");
	gtk_window_set_resizable(GTK_WINDOW(window_Teste), FALSE);
	gtk_window_set_icon_from_file(GTK_WINDOW(window_Teste), "Aplication_Images/Hub_Icon.ico", NULL);
	gtk_widget_set_valign(Texto_De_Teste, GTK_ALIGN_CENTER);
	gtk_label_set_justify((GtkLabel *)Texto_De_Teste, GTK_JUSTIFY_CENTER);

	Ativacao();

	Estilizacao_De_Conteudo();

	gtk_container_add(GTK_CONTAINER(window_Teste), Caixa_De_Teste);
	gtk_widget_show_all(window_Teste);
}