#include <Classe_Configuracao.hpp>
#include <Variaveis_Globais.hpp>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <unistd.h>
#include <vector>

extern void Estilizacao_De_Conteudo(void);
extern void Reativacao_De_Janela_Index(void);
extern void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)());
extern void Atribuicao_De_Valores_Em_Variaveis_Globais(void);

extern void Construcao_De_Opcoes_De_Configuracao_Input_Texto(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<GtkWidget *> &Conjunto_input);
extern void Construcao_De_Opcoes_De_Configuracao_Input_Numero(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<GtkWidget *> &Conjunto_input);
extern void Construcao_De_Opcoes_De_Configuracao_Input_Checkbox(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<GtkWidget *> &Conjunto_input);
extern void Construcao_De_Opcoes_De_Configuracao_Input_Select(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<std::vector<std::string>> &Conjunto_input);
extern void Construcao_De_Opcoes_De_Configuracao_Input_Click(GtkWidget *Caixa_Opcoes_Configuracao);

using json = nlohmann::json;

static GtkWidget *window_Configuracoes;

static GtkWidget *Botao_De_Salvar_Alteracoes;
static GtkWidget *Botao_De_Restaurar_Alteracoes;
static GtkWidget *Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao;

static GtkWidget *Caixa_De_Opcoes_De_Configuracao;

static std::vector<GtkWidget *> Conjunto_Inputs_De_Texto;
static std::vector<GtkWidget *> Conjunto_Inputs_De_Numero;
static std::vector<GtkWidget *> Conjunto_Inputs_De_Checkbox;
static std::vector<std::vector<std::string>> Conjunto_Inputs_De_Select;

static void Removendo_Salvamentos_De_Itens_E_Reabrindo_Index(void) {
	Conjunto_Inputs_De_Texto.clear();
	Conjunto_Inputs_De_Numero.clear();
	Conjunto_Inputs_De_Checkbox.clear();
	Conjunto_Inputs_De_Select.clear();

	Elementos_Invisiveis.clear();
	Reativacao_De_Janela_Index();
}

static void Salvamento_De_Alteracoes(void) {
	for (size_t index = 0; index < Conjunto_Inputs_De_Texto.size(); ++index) {
		GtkWidget *Input_De_Texto = Conjunto_Inputs_De_Texto[index];
		GtkEntry *Input_De_Texto_Convertendo = GTK_ENTRY(Input_De_Texto);
		const gchar *Valor_Input_De_Texto_Convertendo = gtk_entry_get_text(Input_De_Texto_Convertendo);

		Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Texto[index]] = Valor_Input_De_Texto_Convertendo;
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Numero.size(); ++index) {
		GtkWidget *Input_De_Numero = Conjunto_Inputs_De_Numero[index];
		GtkEntry *Input_De_Numero_Convertendo = GTK_ENTRY(Input_De_Numero);
		const gchar *Valor_Input_De_Numero_Convertendo = gtk_entry_get_text(Input_De_Numero_Convertendo);
		int Valor_Em_Numero_Input_De_Numero_Convertendo = std::stoi(Valor_Input_De_Numero_Convertendo);

		Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Numero[index]] = Valor_Em_Numero_Input_De_Numero_Convertendo;
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Checkbox.size(); ++index) {
		GtkWidget *Input_De_Checkbox = Conjunto_Inputs_De_Checkbox[index];
		GtkToggleButton *Input_De_Checkbox_Convertendo = GTK_TOGGLE_BUTTON(Input_De_Checkbox);
		gboolean Valor_Input_De_Checkbox_Convertendo = gtk_toggle_button_get_active(Input_De_Checkbox_Convertendo);
		bool Boleano_Convertido_Input_De_Checkbox = (Valor_Input_De_Checkbox_Convertendo == TRUE);

		Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Checkbox[index]] = Boleano_Convertido_Input_De_Checkbox;
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Select.size(); ++index) {
		Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Select[index]] = Conjunto_Inputs_De_Select[index];
	}

	Configuracao_Universal.Atualizar_Configuracoes(Configuracao_Universal_JSON);

	gtk_container_remove(GTK_CONTAINER(window_Configuracoes), Caixa_De_Opcoes_De_Configuracao);
	Removendo_Salvamentos_De_Itens_E_Reabrindo_Index();
}

static void Restauracao_Para_Padrao(void) {
	Configuracao_Universal_JSON["Fonte_Padrao_De_Programa"] = "Consolas";
	Configuracao_Universal_JSON["Fonte_Saudacao_De_Programa"] = "Comic Sans MS";
	Configuracao_Universal_JSON["Cor_Da_Fonte"] = "white";
	Configuracao_Universal_JSON["Cor_Da_Borda"] = "white";
	Configuracao_Universal_JSON["Cor_De_Fundo_Da_Janela"] = "black";
	Configuracao_Universal_JSON["Caiminho_Do_Local_Com_Linguagens"] = "C:\\Users\\Usuario\\Desktop\\Temp\\Programacao";

	Configuracao_Universal_JSON["Temas_De_Projetos_Desativados"] = json::array();

	Configuracao_Universal_JSON["Imagens_Ilustrativas_De_Linguagem"] = true;
	Configuracao_Universal_JSON["Abrir_Paginas_Com_Projeto"] = true;

	Configuracao_Universal_JSON["Tamanho_De_Fonte"] = 30;

	for (size_t index = 0; index < Conjunto_Inputs_De_Texto.size(); ++index) {
		GtkWidget *Input_De_Texto = Conjunto_Inputs_De_Texto[index];
		GtkEntry *Input_De_Texto_Convertendo = GTK_ENTRY(Input_De_Texto);

		std::string Valor = Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Texto[index]];

		gtk_entry_set_text(Input_De_Texto_Convertendo, Valor.c_str());
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Numero.size(); ++index) {
		GtkWidget *Input_De_Numero = Conjunto_Inputs_De_Numero[index];
		GtkEntry *Input_De_Numero_Convertendo = GTK_ENTRY(Input_De_Numero);

		int Valor = Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Numero[index]];

		gtk_entry_set_text(Input_De_Numero_Convertendo, std::to_string(Valor).c_str());
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Checkbox.size(); ++index) {
		GtkWidget *Input_De_Checkbox = Conjunto_Inputs_De_Checkbox[index];
		GtkToggleButton *Input_De_Checkbox_Convertendo = GTK_TOGGLE_BUTTON(Input_De_Checkbox);

		bool Valor = Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Checkbox[index]];

		gtk_toggle_button_set_active(Input_De_Checkbox_Convertendo, Valor ? TRUE : FALSE);
	}

	for (size_t index = 0; index < Conjunto_Inputs_De_Select.size(); ++index) {
		Conjunto_Inputs_De_Select[index] = Configuracao_Universal_JSON[Criacao_De_Configuracao.Configuracoes_Do_Tipo_Select[index]];
	}
}

static void Ativacao_De_Elementos(void) {
	Botao_De_Salvar_Alteracoes = gtk_button_new_with_label("Salvar");
	Botao_De_Restaurar_Alteracoes = gtk_button_new_with_label("Restaurar");
	Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

	Caixa_De_Opcoes_De_Configuracao = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
}

static void Definindo_Ids(void) {
	gtk_widget_set_name(window_Configuracoes, "Corpo_Da_Janela");

	gtk_widget_set_name(Botao_De_Salvar_Alteracoes, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Botao_De_Restaurar_Alteracoes, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao, "Caixa_De_Inicio_Conjunto");

	gtk_widget_set_name(Caixa_De_Opcoes_De_Configuracao, "Caixa_De_Opcoes_De_Configuracoes");
}

static void Configurando_Janela(void) {
	gtk_window_set_title(GTK_WINDOW(window_Configuracoes), "Configuracoes");
	gtk_window_set_resizable(GTK_WINDOW(window_Configuracoes), false);
	gtk_window_resize(GTK_WINDOW(window_Configuracoes), 500, 700);
	gtk_window_move(GTK_WINDOW(window_Configuracoes), Posicao_X, Posicao_Y - 100);
}

static void Indentacao_Do_Conteudo(void) {
	gtk_box_pack_start(GTK_BOX(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao), Botao_De_Restaurar_Alteracoes, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao), Botao_De_Salvar_Alteracoes, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(window_Configuracoes), Caixa_De_Opcoes_De_Configuracao);
}

static void Acoes_Executaveis(void) {
	g_signal_connect(Botao_De_Salvar_Alteracoes, "clicked", G_CALLBACK(Salvamento_De_Alteracoes), NULL);
	g_signal_connect(Botao_De_Restaurar_Alteracoes, "clicked", G_CALLBACK(Restauracao_Para_Padrao), NULL);
}

static void Ativacao_De_Aplicacao(void) {
	// Ativando os elementos
	Ativacao_De_Elementos();
	//---------------------------------------------------------------------------------------

	// Definicao de ids de Elementos
	Definindo_Ids();
	//---------------------------------------------------------------------------------------

	// Configuracoes de Janela
	Configurando_Janela();
	//---------------------------------------------------------------------------------------

	// Acao de botão quando clicado
	Acoes_Executaveis();
	//---------------------------------------------------------------------------------------

	Criar_Botao_Sessao_Anterior(window_Configuracoes, Caixa_De_Opcoes_De_Configuracao, Removendo_Salvamentos_De_Itens_E_Reabrindo_Index);

	Construcao_De_Opcoes_De_Configuracao_Input_Texto(Caixa_De_Opcoes_De_Configuracao, Conjunto_Inputs_De_Texto);
	Construcao_De_Opcoes_De_Configuracao_Input_Numero(Caixa_De_Opcoes_De_Configuracao, Conjunto_Inputs_De_Numero);
	Construcao_De_Opcoes_De_Configuracao_Input_Checkbox(Caixa_De_Opcoes_De_Configuracao, Conjunto_Inputs_De_Checkbox);
	Construcao_De_Opcoes_De_Configuracao_Input_Select(Caixa_De_Opcoes_De_Configuracao, Conjunto_Inputs_De_Select);
	Construcao_De_Opcoes_De_Configuracao_Input_Click(Caixa_De_Opcoes_De_Configuracao);

	// Indentacao de elementos
	Indentacao_Do_Conteudo();
	//---------------------------------------------------------------------------------------

	gtk_widget_show_all(window_Configuracoes);
}

static void Deixar_Janela_Invisivel(void) {
	for (auto &index : Elementos_Invisiveis) {
		gtk_widget_hide(index);
	}
}

void Configuracao_Grafico(GtkWidget *window_recebido) {
	window_Configuracoes = window_recebido;
	Ativacao_De_Aplicacao();

	g_signal_connect(window_Configuracoes, "button-press-event", G_CALLBACK(Deixar_Janela_Invisivel), NULL);
	Deixar_Janela_Invisivel();
}