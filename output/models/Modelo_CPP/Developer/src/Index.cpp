#include <Variaveis_Globais.hpp>
#include <cstdlib>
#include <ctime>
#include <gtk/gtk.h>
#include <iostream>
#include <pango/pango.h>

extern void Novo_Projeto_Grafico(GtkWidget *window_recebido);
extern void Configuracao_Grafico(GtkWidget *window_recebido);
extern void Estilizacao_De_Conteudo(void);

// Criacao de Elementos
GtkApplication *Aplicacao;
GtkWidget *window;
GtkWidget *Texto_De_Entrada;
GtkWidget *Botao_De_Novo_Projeto;
GtkWidget *Botao_De_Projeto_Existente;
GtkWidget *Botao_De_Acesso_Rapido;
GtkWidget *Botao_De_Configuracao;
GtkWidget *Caixa_De_Inicio;
//---------------------------------------------------------------------------------------

int Posicao_X, Posicao_Y;

static void Novo_Projeto(GtkWidget *Widget, gpointer data) {
	gtk_container_remove(GTK_CONTAINER(window), Caixa_De_Inicio);
	Novo_Projeto_Grafico(window);
}

static void Projeto_Existente(GtkWidget *Widget, gpointer data) { g_print("Em desenvolvimento\n Obrigado por testar e experimentar"); }

static void Acesso_Rapido(GtkWidget *Widget, gpointer data) { g_print("Em desenvolvimento\n Obrigado por testar e experimentar"); }

static void Configuracoes(GtkWidget *Widget, gpointer data) {
	gtk_container_remove(GTK_CONTAINER(window), Caixa_De_Inicio);
	Configuracao_Grafico(window);
}

static int Escolha_Aleatoria(int Numero_Sorvetado_Maximo) {
	srand(static_cast<unsigned>(time(0)));
	int numeroAleatorio = rand() % Numero_Sorvetado_Maximo; // Gera um número aleatório entre 0 e (maximo - 1)
	return numeroAleatorio;
}

static void Ativacao_De_Elementos(void) {
	const char *Emoji_Aleatorio[] = {"😉", "😎", "😁", "😃", "😄", "😊", "🙂", "😆", "😌", "😏"};
	const char *Frase_Aleatoria[] = {"Bem-vindo de volta!", "Olá novamente!",     "Bom te ver de volta!",  "Que bom que voltou!",     "Olá!",
	                                 "Vamos trabalhar!",    "Bem-vindo de novo!", "De volta ao trabalho!", "Vamos ao que interessa!", "Pronto para mais uma?"};

	gchar *Testo_De_Entrada_Texto = g_strdup_printf("%s\n\n%s", Frase_Aleatoria[Escolha_Aleatoria(10)], Emoji_Aleatorio[Escolha_Aleatoria(10)]);

	Texto_De_Entrada = gtk_label_new(Testo_De_Entrada_Texto);
	Botao_De_Novo_Projeto = gtk_button_new_with_label("Novo Projeto");
	Botao_De_Projeto_Existente = gtk_button_new_with_label("Projeto Existente");
	Botao_De_Acesso_Rapido = gtk_button_new_with_label("Acesso Rapido");
	Botao_De_Configuracao = gtk_button_new_with_label("Configuracoes");
	Caixa_De_Inicio = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
}

static void Definindo_Ids(void) {
	gtk_widget_set_name(window, "Corpo_Da_Janela");
	gtk_widget_set_name(Texto_De_Entrada, "Texto_De_Saudacao");
	gtk_widget_set_name(Caixa_De_Inicio, "Caixa_De_Inicio_Conjunto");
	gtk_widget_set_name(Botao_De_Novo_Projeto, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Botao_De_Projeto_Existente, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Botao_De_Acesso_Rapido, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Botao_De_Configuracao, "Botoes_De_Acao_Individual");
}

static void Configurando_Janela(void) {
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	gtk_window_resize(GTK_WINDOW(window), 500, 500);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Hub de Programacao");
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_icon_from_file(GTK_WINDOW(window), "Aplication_Images/Hub_Icon.ico", NULL);
}

static void Indentacao_Do_Conteudo(void) {
	gtk_box_pack_start(GTK_BOX(Caixa_De_Inicio), Texto_De_Entrada, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Inicio), Botao_De_Novo_Projeto, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Inicio), Botao_De_Projeto_Existente, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Inicio), Botao_De_Acesso_Rapido, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Inicio), Botao_De_Configuracao, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(window), Caixa_De_Inicio);
}

static void Acao_De_Botoes(void) {
	g_signal_connect(Botao_De_Novo_Projeto, "clicked", G_CALLBACK(Novo_Projeto), NULL);
	g_signal_connect(Botao_De_Projeto_Existente, "clicked", G_CALLBACK(Projeto_Existente), NULL);
	g_signal_connect(Botao_De_Acesso_Rapido, "clicked", G_CALLBACK(Acesso_Rapido), NULL);
	g_signal_connect(Botao_De_Configuracao, "clicked", G_CALLBACK(Configuracoes), NULL);
}

static void Ativacao_De_Aplicacao() {
	// Ativacao de Elementos
	Ativacao_De_Elementos();
	//---------------------------------------------------------------------------------------

	// Definicao de ids de Elementos
	Definindo_Ids();
	//---------------------------------------------------------------------------------------

	// Configuracoes de Janela
	Configurando_Janela();
	//---------------------------------------------------------------------------------------

	// Acao de botão quando clicado
	Acao_De_Botoes();
	//---------------------------------------------------------------------------------------

	// Estilos do conteudo
	Estilizacao_De_Conteudo();

	gtk_widget_set_valign(Texto_De_Entrada, GTK_ALIGN_CENTER);
	gtk_label_set_justify((GtkLabel *)Texto_De_Entrada, GTK_JUSTIFY_CENTER);
	//---------------------------------------------------------------------------------------

	// Indentacao de elementos
	Indentacao_Do_Conteudo();
	//---------------------------------------------------------------------------------------

	gtk_widget_show_all(window);
}

void Reativacao_De_Janela_Index(void) {
	gtk_window_move(GTK_WINDOW(window), Posicao_X, Posicao_Y);

	Ativacao_De_Aplicacao();
}

void Index_Grafico(GtkApplication *Aplicacao_Recebida, gpointer user_data) {
	Aplicacao = Aplicacao_Recebida;
	window = gtk_application_window_new(Aplicacao);
	Ativacao_De_Aplicacao();
	gtk_window_get_position(GTK_WINDOW(window), &Posicao_X, &Posicao_Y);
}