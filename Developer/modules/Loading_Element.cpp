#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>

GtkWidget *window_Loading_Element;
GtkWidget *Caixa_De_Loading_Element;
GtkWidget *Imagem_Loading_Element;

extern void Reativacao_De_Janela_Index(void);

static void Configurando_Janela(void) {
	gtk_window_set_title(GTK_WINDOW(window_Loading_Element), "Criando projeto ReactJs");
	gtk_window_set_resizable(GTK_WINDOW(window_Loading_Element), true);
	gtk_window_resize(GTK_WINDOW(window_Loading_Element), 500, 500);
	gtk_window_move(GTK_WINDOW(window_Loading_Element), Posicao_X, Posicao_Y);
}

static void Ativacao_De_Aplicacao(void) {
	Caixa_De_Loading_Element = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_name(window_Loading_Element, "Corpo_Da_Janela");
	gtk_widget_set_name(Caixa_De_Loading_Element, "Caixa_De_Inicio_Conjunto");

	// Criacao de botoes

	//---------------------------------------------------------------------------------------

	Imagem_Loading_Element = gtk_image_new_from_file("./Aplication_Images/Loading_Gif.gif");

	gtk_widget_set_name(Imagem_Loading_Element, "Imagem_De_Loading");

	gtk_box_pack_start(GTK_BOX(Caixa_De_Loading_Element), Imagem_Loading_Element, TRUE, FALSE, 0);

	// Configuracoes de Janela
	Configurando_Janela();
	//---------------------------------------------------------------------------------------

	gtk_container_add(GTK_CONTAINER(window_Loading_Element), Caixa_De_Loading_Element);

	gtk_widget_show_all(window_Loading_Element);
}

void Loading_Element_Grafico(GtkWidget *window_recebido, bool Estado_Do_Carregamento) {
	window_Loading_Element = window_recebido;
	if (Estado_Do_Carregamento) {
		Ativacao_De_Aplicacao();
	} else {
		gtk_container_remove(GTK_CONTAINER(window_Loading_Element), Caixa_De_Loading_Element);
		Reativacao_De_Janela_Index();
	}
}