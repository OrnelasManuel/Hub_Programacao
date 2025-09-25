#include <Variaveis_Globais.hpp>
#include <algorithm>
#include <gtk/gtk.h>
#include <iostream>
#include <string>

extern void Reativacao_De_Janela_Index(void);
extern void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)());
extern void Acesso_Ou_Criacao_De_Projeto_App(GtkWidget *window_recebido, std::string Pasta_De_Copia_Recebido, std::string Caminho_Da_Pasta_Recebida);

GtkWidget *window_Novo_Projeto;
GtkWidget *Caixa_De_Botoes;

static void Novo_Projeto_Modelo(GtkWidget *widget, gpointer data) {
	std::string *Tema_Do_Item = static_cast<std::string *>(data);
	std::string Tema_Do_Item_Formatado = *Tema_Do_Item;

	std::string Nome_Da_Pasta_Modelo = "Modelo_" + Tema_Do_Item_Formatado;

	gtk_container_remove(GTK_CONTAINER(window_Novo_Projeto), Caixa_De_Botoes);
	Acesso_Ou_Criacao_De_Projeto_App(window_Novo_Projeto, Nome_Da_Pasta_Modelo.c_str(), Tema_Do_Item_Formatado.c_str());
}

static void Criacao_De_Botoes(void) {
	for (const auto &item : Pastas_Existentes) {
		if (std::find(Configuracao_Universal.getTemas_Projetos_Desativados().begin(), Configuracao_Universal.getTemas_Projetos_Desativados().end(), item) ==
		    Configuracao_Universal.getTemas_Projetos_Desativados().end()) {
			// if (std::find(Configuracao_Universal_JSON["Temas_De_Projetos_Desativados"].begin(), Configuracao_Universal_JSON["Temas_De_Projetos_Desativados"].end(), item) ==
			// Configuracao_Universal_JSON["Temas_De_Projetos_Desativados"].end()) {
			std::string Texto_Interno = item;
			std::string Tema_Do_Item_Formatado = Texto_Interno;

			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '-', '_');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), '+', 'P');
			std::replace(Tema_Do_Item_Formatado.begin(), Tema_Do_Item_Formatado.end(), ' ', '_');

			std::string Id_Do_CSS = "Botoes_De_Acao_Individual_" + Tema_Do_Item_Formatado;
			std::string *Tema_Do_Item_Formatado_Para_Envio = new std::string(Tema_Do_Item_Formatado);

			GtkWidget *Botao_De_Linguagem_Modelo;
			Botao_De_Linguagem_Modelo = gtk_button_new_with_label(Texto_Interno.c_str());
			gtk_widget_set_name(Botao_De_Linguagem_Modelo, Id_Do_CSS.c_str());
			gtk_box_pack_start(GTK_BOX(Caixa_De_Botoes), Botao_De_Linguagem_Modelo, TRUE, TRUE, 0);
			g_signal_connect(Botao_De_Linguagem_Modelo, "clicked", G_CALLBACK(Novo_Projeto_Modelo), Tema_Do_Item_Formatado_Para_Envio);
		}
	}
}

static void Configurando_Janela(void) {
	if (Tipo_De_Acesso_Sendo_Feito == "Criacao") {
		gtk_window_set_title(GTK_WINDOW(window_Novo_Projeto), "Criando novo projeto");
	} else if (Tipo_De_Acesso_Sendo_Feito == "Acesso") {
		gtk_window_set_title(GTK_WINDOW(window_Novo_Projeto), "Acessando projeto existente");
	} else if (Tipo_De_Acesso_Sendo_Feito == "Remocao") {
		gtk_window_set_title(GTK_WINDOW(window_Novo_Projeto), "Removendo projeto existente");
	}
	gtk_window_set_resizable(GTK_WINDOW(window_Novo_Projeto), true);
	gtk_window_resize(GTK_WINDOW(window_Novo_Projeto), 500, 700);
	gtk_window_move(GTK_WINDOW(window_Novo_Projeto), Posicao_X, Posicao_Y - 100);
}

static void Ativacao_De_Aplicacao(void) {
	Caixa_De_Botoes = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_name(window_Novo_Projeto, "Corpo_Da_Janela");
	gtk_widget_set_name(Caixa_De_Botoes, "Caixa_De_Inicio_Conjunto_De_Opcoes");

	Criar_Botao_Sessao_Anterior(window_Novo_Projeto, Caixa_De_Botoes, Reativacao_De_Janela_Index);

	// Criacao de botoes
	Criacao_De_Botoes();
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