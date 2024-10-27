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

using json = nlohmann::json;

GtkWidget *window_Configuracoes;

GtkWidget *Botao_De_Salvar_Alteracoes;
GtkWidget *Botao_De_Restaurar_Alteracoes;
GtkWidget *Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao;

GtkWidget *Caixa_De_Opcoes_De_Configuracao;

std::vector<GtkWidget *> Conjunto_Inputs_De_Texto;
std::vector<GtkWidget *> Conjunto_Inputs_De_Numero;
std::vector<GtkWidget *> Conjunto_Inputs_De_Checkbox;

static void Removendo_Salvamentos_De_Itens_E_Reabrindo_Index(void) {
	Conjunto_Inputs_De_Texto.clear();
	Conjunto_Inputs_De_Numero.clear();
	Conjunto_Inputs_De_Checkbox.clear();
	Reativacao_De_Janela_Index();
}

static void Validacao_De_Apenas_Numero(GtkEditable *editable, const gchar *text, gint length, gint *position) {
	std::string Valor_Padrao = "25";
	bool Teste_Se_Todos_Passaram = true;
	for (gint i = 0; i < length; i++) {
		if (!g_ascii_isdigit(text[i])) {
			Teste_Se_Todos_Passaram = false;
		}
	}

	if (!Teste_Se_Todos_Passaram) {
		gtk_entry_set_text(GTK_ENTRY(editable), Valor_Padrao.c_str());
	}
}

static void Construcao_De_Opcoes_De_Configuracao_Input_Texto(void) {

	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Texto_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		std::string Valor_De_Texto_Ja_Possuido = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];

		GtkWidget *Caixa_De_Input_De_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Input_De_Modelo_Configuracao = gtk_entry_new();
		GtkWidget *Label_De_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		Conjunto_Inputs_De_Texto.push_back(Input_De_Modelo_Configuracao);

		gtk_widget_set_name(Caixa_De_Input_De_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Input_De_Modelo_Configuracao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_De_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Label_De_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Input_De_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_De_Modelo_Configuracao, FALSE, FALSE, 0);

		gtk_entry_set_text(GTK_ENTRY(Input_De_Modelo_Configuracao), Valor_De_Texto_Ja_Possuido.c_str());
	}
}

static void Construcao_De_Opcoes_De_Configuracao_Input_Numero(void) {
	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Numero_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		int Valor_De_Numero_Ja_Possuido = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];

		GtkWidget *Caixa_De_Input_De_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Input_De_Modelo_Configuracao = gtk_entry_new();
		GtkWidget *Label_De_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		Conjunto_Inputs_De_Numero.push_back(Input_De_Modelo_Configuracao);

		gtk_widget_set_name(Caixa_De_Input_De_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Input_De_Modelo_Configuracao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_De_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Label_De_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Input_De_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_De_Modelo_Configuracao, FALSE, FALSE, 0);

		gtk_entry_set_text(GTK_ENTRY(Input_De_Modelo_Configuracao), std::to_string(Valor_De_Numero_Ja_Possuido).c_str());

		g_signal_connect(Input_De_Modelo_Configuracao, "insert-text", G_CALLBACK(Validacao_De_Apenas_Numero), NULL);
	}
}

static void Construcao_De_Opcoes_De_Configuracao_Input_Checkbox(void) {
	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Checkbox_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		bool Valor_Boleano_De_Grupo = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];

		GtkWidget *Caixa_De_Checkbox_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Checkbox_Modelo_Configuracao = gtk_check_button_new();
		GtkWidget *Label_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		Conjunto_Inputs_De_Checkbox.push_back(Checkbox_Modelo_Configuracao);

		gtk_widget_set_name(Caixa_De_Checkbox_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Checkbox_Modelo_Configuracao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Modelo_Configuracao), Label_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Modelo_Configuracao), Checkbox_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Checkbox_Modelo_Configuracao, FALSE, FALSE, 0);

		if (Valor_Boleano_De_Grupo) {
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Checkbox_Modelo_Configuracao), TRUE);
		}
	}
}

static void Salvamento_De_Alteracoes(void) {

	std::ofstream Arquivo_Padrao_Atualizado("./data/Configuracoes.json");

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

	Arquivo_Padrao_Atualizado << Configuracao_Universal_JSON.dump(4);

	Arquivo_Padrao_Atualizado.close();

	Atribuicao_De_Valores_Em_Variaveis_Globais();

	Estilizacao_De_Conteudo();
}

static void Restauracao_Para_Padrao(void) {
	std::ofstream Arquivo_Estilizacao_Atualizado("./data/Estilizacao.json");
	std::ofstream Arquivo_Padrao_Atualizado("./data/Configuracoes.json");

	Configuracao_Universal_JSON["Caiminho_Do_Local_Com_Linguagens"] = "C:\\Users\\Usuario\\Desktop\\Temp\\Programacao";
	Configuracao_Universal_JSON["Abrir_Paginas_Com_Projeto"] = true;

	Configuracao_Universal_JSON["Fonte_Padrao_De_Programa"] = "Consolas";
	Configuracao_Universal_JSON["Fonte_Saudacao_De_Programa"] = "Comic Sans MS";
	Configuracao_Universal_JSON["Cor_Da_Fonte"] = "white";
	Configuracao_Universal_JSON["Cor_Da_Borda"] = "white";
	Configuracao_Universal_JSON["Cor_De_Fundo_Da_Janela"] = "black";
	Configuracao_Universal_JSON["Imagens_Ilustrativas_De_Linguagem"] = true;
	Configuracao_Universal_JSON["Tamanho_De_Fonte"] = 25;

	Arquivo_Padrao_Atualizado << Configuracao_Universal_JSON.dump(2);
	Arquivo_Estilizacao_Atualizado << Configuracao_Universal_JSON.dump(2);

	Arquivo_Padrao_Atualizado.close();
	Arquivo_Estilizacao_Atualizado.close();

	Atribuicao_De_Valores_Em_Variaveis_Globais();

	Estilizacao_De_Conteudo();
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

	Construcao_De_Opcoes_De_Configuracao_Input_Texto();
	Construcao_De_Opcoes_De_Configuracao_Input_Numero();
	Construcao_De_Opcoes_De_Configuracao_Input_Checkbox();

	// Indentacao de elementos
	Indentacao_Do_Conteudo();
	//---------------------------------------------------------------------------------------

	gtk_widget_show_all(window_Configuracoes);
}

void Configuracao_Grafico(GtkWidget *window_recebido) {
	window_Configuracoes = window_recebido;
	Ativacao_De_Aplicacao();
}