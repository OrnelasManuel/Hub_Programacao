#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>

extern void Reativacao_De_Janela_Index(void);
extern void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)());
extern void Acesso_Ou_Criacao_De_Projeto_App(GtkWidget *window_recebido, const char *Pasta_De_Copia_Recebido, const char *Caminho_Da_Pasta_Recebida);

GtkWidget *window_Novo_Projeto;
GtkWidget *Caixa_De_Botoes;

static void Criacao_De_Botoes(const char *Texto_Interno, const char *Id_Do_CSS, void (*Funcao_De_Ativacao_Quando_Botao_FOR_Clicado)()) {
	GtkWidget *Botao_De_Linguagem_Modelo;
	Botao_De_Linguagem_Modelo = gtk_button_new_with_label(Texto_Interno);
	gtk_widget_set_name(Botao_De_Linguagem_Modelo, Id_Do_CSS);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Botoes), Botao_De_Linguagem_Modelo, TRUE, TRUE, 0);
	g_signal_connect(Botao_De_Linguagem_Modelo, "clicked", G_CALLBACK(Funcao_De_Ativacao_Quando_Botao_FOR_Clicado), NULL);
}

static void Configurando_Janela(void) {
	gtk_window_set_title(GTK_WINDOW(window_Novo_Projeto), "Criando novo projeto");
	gtk_window_set_resizable(GTK_WINDOW(window_Novo_Projeto), true);
	gtk_window_resize(GTK_WINDOW(window_Novo_Projeto), 500, 700);
	gtk_window_move(GTK_WINDOW(window_Novo_Projeto), Posicao_X, Posicao_Y - 100);
}

static void Novo_Projeto_ReactJs(void) {
	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, "Modelo_React", "React");
}

static void Novo_Projeto_NodeJs(void) {
	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, "Modelo_Node", "Node");
}

static void Novo_Projeto_HCJ(void) {
	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, "Modelo_Site", "HTML CSS JS");
}

static void Novo_Projeto_CMD(void) {
	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, "Modelo_CMD", "CMD");
}

static void Novo_Projeto_CPP(void) {
	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, "Modelo_CPP", "C++");
}

static void Tester(void) { g_print("Testado"); }

static void Ativacao_De_Aplicacao(void) {
	Caixa_De_Botoes = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_name(window_Novo_Projeto, "Corpo_Da_Janela");
	gtk_widget_set_name(Caixa_De_Botoes, "Caixa_De_Inicio_Conjunto");

	Criar_Botao_Sessao_Anterior(window_Novo_Projeto, Caixa_De_Botoes, Reativacao_De_Janela_Index);

	// Criacao de botoes
	Criacao_De_Botoes("ReactJs", "Botoes_De_Acao_Individual_ReactJs", Novo_Projeto_ReactJs);
	Criacao_De_Botoes("NodeJs", "Botoes_De_Acao_Individual_NodeJs", Novo_Projeto_NodeJs);
	Criacao_De_Botoes("Front-End", "Botoes_De_Acao_Individual_Front_End", Novo_Projeto_HCJ);
	Criacao_De_Botoes("CMD", "Botoes_De_Acao_Individual_CMD", Novo_Projeto_CMD);
	Criacao_De_Botoes("C++", "Botoes_De_Acao_Individual_CPP", Novo_Projeto_CPP);
	//---------------------------------------------------------------------------------------

	// Configuracoes de Janela
	Configurando_Janela();
	//---------------------------------------------------------------------------------------

	gtk_container_add(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);

	gtk_widget_show_all(window_Novo_Projeto);
}

void Reativacao_De_Janela_Novo_Projeto(void) {
	gtk_window_move(GTK_WINDOW(window_Novo_Projeto), Posicao_X, Posicao_Y);

	Ativacao_De_Aplicacao();
}

void Novo_Projeto_Grafico(GtkWidget *window_recebido) {
	window_Novo_Projeto = window_recebido;
	Ativacao_De_Aplicacao();
}