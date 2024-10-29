#include <Classe_Configuracao.hpp>
#include <Variaveis_Globais.hpp>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

namespace fs = std::filesystem;

extern void Reativacao_De_Janela_Novo_Projeto(void);
extern void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)());
extern void Loading_Element_Grafico(GtkWidget *window_recebido, bool Estado_Do_Carregamento);
extern void Configurando_Projeto_Para_Abrir(const char *Modo_Escolhido_Para_Inicializacao_De_Paginas, bool Abertura_De_Sites);

GtkWidget *window_Projeto_Acesso_Ou_Criacao;
GtkWidget *Caixa_De_Input_Criacao;

GtkWidget *Caixa_De_Input_Nome_Do_Projeto;
GtkWidget *Input_Nome_Do_Projeto;
GtkWidget *Label_Nome_Do_Projeto;

GtkWidget *Botao_De_Prosseguir_Com_Criacao;
GtkWidget *Caixa_De_Botao_Com_Prosseguir_Criacao;

const char *Projeto_Escolhido_Por_Clique;
const char *Pasta_De_Copia;
const char *Caminho_Da_Pasta;
const char *Nome_Do_Modelo_De_Projeto;

static void Criacao_De_Botoes(const char *Texto_Interno, void (*Funcao_De_Ativacao_Quando_Botao_FOR_Clicado)(GtkWidget *widget, gpointer data), GtkWidget *Local_Onde_Vai_Ficar) {
	GtkWidget *Botao_De_Linguagem_Modelo;
	Botao_De_Linguagem_Modelo = gtk_button_new_with_label(Texto_Interno);
	gtk_box_pack_start(GTK_BOX(Local_Onde_Vai_Ficar), Botao_De_Linguagem_Modelo, TRUE, TRUE, 0);

	gtk_widget_set_name(Botao_De_Linguagem_Modelo, "Botao_De_Opcoes_De_Projetos_Existentes");

	char *Data_Para_Passar_Texto_Interno = g_strdup(Texto_Interno);

	g_signal_connect(Botao_De_Linguagem_Modelo, "clicked", G_CALLBACK(Funcao_De_Ativacao_Quando_Botao_FOR_Clicado), (gpointer)Data_Para_Passar_Texto_Interno);
}

static void Configurando_Janela(void) {
	gtk_window_set_title(GTK_WINDOW(window_Projeto_Acesso_Ou_Criacao), "Criando novo projeto");
	gtk_window_set_resizable(GTK_WINDOW(window_Projeto_Acesso_Ou_Criacao), true);
	gtk_window_resize(GTK_WINDOW(window_Projeto_Acesso_Ou_Criacao), 500, 700);
	gtk_window_move(GTK_WINDOW(window_Projeto_Acesso_Ou_Criacao), Posicao_X, Posicao_Y - 100);
}

static void Carregamento_De_Copias_De_Arquivos_Modelo(const std::string &comando) {
	if (Tipo_De_Acesso_Sendo_Feito == "Remocao") {
		fs::path dir_path(Localizacao_Do_Projeto);

		try {
			fs::remove_all(dir_path);
		} catch (const fs::filesystem_error &e) {
			std::cerr << "Erro ao remover a pasta: " << e.what() << std::endl;
		}
	} else {
		if (Tipo_De_Acesso_Sendo_Feito == "Criacao") {
			std::system(comando.c_str());
		}

		Configurando_Projeto_Para_Abrir(Nome_Do_Modelo_De_Projeto, Configuracao_Universal.Abrir_Paginas_Com_Projeto);
	}

	Loading_Element_Grafico(window_Projeto_Acesso_Ou_Criacao, false);
}

static void Configuracao_De_Projeto(void) {

	GtkEntry *Input_Nome_Do_Projeto_Convertendo;
	const gchar *Valor_Input_Nome_Do_Projeto_Convertendo;

	std::string Copiar_Arquivos_Para_Nova_Localizacao;

	if (Tipo_De_Acesso_Sendo_Feito == "Criacao") {
		Input_Nome_Do_Projeto_Convertendo = GTK_ENTRY(Input_Nome_Do_Projeto);
		Valor_Input_Nome_Do_Projeto_Convertendo = gtk_entry_get_text(Input_Nome_Do_Projeto_Convertendo);
		Localizacao_Do_Projeto = Configuracao_Universal.Caminho_Pasta_Principal + "\\" + Caminho_Da_Pasta + "\\" + Valor_Input_Nome_Do_Projeto_Convertendo;

		Copiar_Arquivos_Para_Nova_Localizacao = std::string("xcopy \"") + ".\\models\\" + Pasta_De_Copia + "\" \"" + Configuracao_Universal.Caminho_Pasta_Principal + "\\" +
		                                        Caminho_Da_Pasta + "\\" + Valor_Input_Nome_Do_Projeto_Convertendo + "\" /E /I /Y";
	} else if (Tipo_De_Acesso_Sendo_Feito == "Acesso" || Tipo_De_Acesso_Sendo_Feito == "Remocao") {
		Localizacao_Do_Projeto = Configuracao_Universal.Caminho_Pasta_Principal + "\\" + Caminho_Da_Pasta + "\\" + Projeto_Escolhido_Por_Clique;
	}

	gtk_container_remove(GTK_CONTAINER(window_Projeto_Acesso_Ou_Criacao), Caixa_De_Input_Criacao);

	Loading_Element_Grafico(window_Projeto_Acesso_Ou_Criacao, true);

	std::thread Copiar_Pasta(Carregamento_De_Copias_De_Arquivos_Modelo, Copiar_Arquivos_Para_Nova_Localizacao);
	Copiar_Pasta.detach();
}

static void Salvando_Nome_Da_Pasta_Do_Projeto(GtkWidget *widget, gpointer data) {
	if (data != NULL) {
		const char *Nome_Da_Pasta_Recebido = (const char *)data;
		Projeto_Escolhido_Por_Clique = Nome_Da_Pasta_Recebido;
		Configuracao_De_Projeto();
	}
}

static void Ativacao_De_Aplicacao(void) {
	Caixa_De_Input_Criacao = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_name(window_Projeto_Acesso_Ou_Criacao, "Corpo_Da_Janela");
	gtk_widget_set_name(Caixa_De_Input_Criacao, "Caixa_De_Inicio_Conjunto");

	GtkWidget *Caixa_De_Input_Criacao_Com_Funcionamento_De_Scroll = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *Div_Com_Scroll = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_name(Caixa_De_Input_Criacao_Com_Funcionamento_De_Scroll, "Caixa_De_Inicio_Conjunto");
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(Div_Com_Scroll), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);

	Criar_Botao_Sessao_Anterior(window_Projeto_Acesso_Ou_Criacao, Caixa_De_Input_Criacao, Reativacao_De_Janela_Novo_Projeto);

	Configurando_Janela();

	if (Tipo_De_Acesso_Sendo_Feito == "Criacao") {

		Botao_De_Prosseguir_Com_Criacao = gtk_button_new_with_label("Continuar");
		Caixa_De_Botao_Com_Prosseguir_Criacao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

		Caixa_De_Input_Nome_Do_Projeto = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		Input_Nome_Do_Projeto = gtk_entry_new();
		Label_Nome_Do_Projeto = gtk_label_new("Nome do projeto: ");

		gtk_widget_set_name(Botao_De_Prosseguir_Com_Criacao, "Botoes_De_Acao_Individual");
		gtk_widget_set_name(Caixa_De_Botao_Com_Prosseguir_Criacao, "Caixa_De_Inicio_Conjunto");
		gtk_widget_set_name(Caixa_De_Input_Nome_Do_Projeto, "Conjunto_Label_Input_Criacao_De_Projeto_Nome");
		gtk_widget_set_name(Label_Nome_Do_Projeto, "Label_De_Texto_Das_Configuracoes_Com_Input");

		g_signal_connect(Botao_De_Prosseguir_Com_Criacao, "clicked", G_CALLBACK(Configuracao_De_Projeto), NULL);

		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Nome_Do_Projeto), Label_Nome_Do_Projeto, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Nome_Do_Projeto), Input_Nome_Do_Projeto, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Criacao), Caixa_De_Input_Nome_Do_Projeto, TRUE, FALSE, 0);

		gtk_box_pack_end(GTK_BOX(Caixa_De_Botao_Com_Prosseguir_Criacao), Botao_De_Prosseguir_Com_Criacao, FALSE, FALSE, 0);
		gtk_box_pack_end(GTK_BOX(Caixa_De_Input_Criacao), Caixa_De_Botao_Com_Prosseguir_Criacao, FALSE, FALSE, 0);
	}
	if (Tipo_De_Acesso_Sendo_Feito == "Acesso" || Tipo_De_Acesso_Sendo_Feito == "Remocao") {
		std::string Caminho_Para_Obter_Pastas = Configuracao_Universal.Caminho_Pasta_Principal + "\\" + Caminho_Da_Pasta;

		int Quantia_De_Pastas = 0;

		for (const auto &entry : fs::directory_iterator(Caminho_Para_Obter_Pastas)) {
			if (entry.is_directory()) {
				std::string Nome_Da_Pasta_Encontrada = entry.path().filename().string();
				const char *Nome_Da_Pasta_Encontrada_Convertida = Nome_Da_Pasta_Encontrada.c_str();
				if (Nome_Da_Pasta_Encontrada != "Bibliotecas" && Nome_Da_Pasta_Encontrada != "MSYS2") {
					Quantia_De_Pastas += 1;
				}
			}
		}

		for (const auto &entry : fs::directory_iterator(Caminho_Para_Obter_Pastas)) {
			if (entry.is_directory()) {
				std::string Nome_Da_Pasta_Encontrada = entry.path().filename().string();
				const char *Nome_Da_Pasta_Encontrada_Convertida = Nome_Da_Pasta_Encontrada.c_str();
				if (Nome_Da_Pasta_Encontrada != "Bibliotecas" && Nome_Da_Pasta_Encontrada != "MSYS2") {
					if (Quantia_De_Pastas <= 5) {
						Criacao_De_Botoes(Nome_Da_Pasta_Encontrada_Convertida, Salvando_Nome_Da_Pasta_Do_Projeto, Caixa_De_Input_Criacao);
					} else {
						Criacao_De_Botoes(Nome_Da_Pasta_Encontrada_Convertida, Salvando_Nome_Da_Pasta_Do_Projeto, Caixa_De_Input_Criacao_Com_Funcionamento_De_Scroll);
					}
				}
			}
		}

		if (Quantia_De_Pastas > 5) {
			gtk_container_add(GTK_CONTAINER(Div_Com_Scroll), Caixa_De_Input_Criacao_Com_Funcionamento_De_Scroll);
			gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Criacao), Div_Com_Scroll, TRUE, TRUE, 0);
		}
	}

	gtk_container_add(GTK_CONTAINER(window_Projeto_Acesso_Ou_Criacao), Caixa_De_Input_Criacao);

	gtk_widget_show_all(window_Projeto_Acesso_Ou_Criacao);
}

void Acesso_Ou_Criacao_De_Projeto_App(GtkWidget *window_recebido, const char *Pasta_De_Copia_Recebido, const char *Caminho_Da_Pasta_Recebida) {
	window_Projeto_Acesso_Ou_Criacao = window_recebido;
	Pasta_De_Copia = Pasta_De_Copia_Recebido;
	Nome_Do_Modelo_De_Projeto = Caminho_Da_Pasta_Recebida;
	Caminho_Da_Pasta = Caminho_Da_Pasta_Recebida;
	Ativacao_De_Aplicacao();
}