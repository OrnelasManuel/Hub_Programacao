#include <Classe_Configuracao.hpp>
#include <Variaveis_Globais.hpp>
#include <fstream>
#include <gtk/gtk.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <unistd.h>

extern void Estilizacao_De_Conteudo(void);
extern void Reativacao_De_Janela_Index(void);
extern void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)());

using json = nlohmann::json;

GtkWidget *window_Configuracoes;

GtkWidget *Caixa_De_Input_Caminho_Da_Pasta_Principal;
GtkWidget *Input_Caminho_Da_Pasta_Principal;
GtkWidget *Label_Caminho_Da_Pasta_Principal;

GtkWidget *Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto;
GtkWidget *Checkbox_Abrir_Paginas_Do_Projeto;
GtkWidget *Label_Abrir_Paginas_Do_Projeto;
bool Liberacao_De_Checagem_Abrir_Paginas_Do_Projeto = true;

GtkWidget *Caixa_De_Input_Fonte_Padrao_De_Programa;
GtkWidget *Input_Fonte_Padrao_De_Programa;
GtkWidget *Label_Fonte_Padrao_De_Programa;

GtkWidget *Caixa_De_Input_Fonte_Saudacao_De_Programa;
GtkWidget *Input_Fonte_Saudacao_De_Programa;
GtkWidget *Label_Fonte_Saudacao_De_Programa;

GtkWidget *Caixa_De_Input_Cor_Da_Fonte;
GtkWidget *Input_Cor_Da_Fonte;
GtkWidget *Label_Cor_Da_Fonte;

GtkWidget *Caixa_De_Input_Cor_Da_Borda;
GtkWidget *Input_Cor_Da_Borda;
GtkWidget *Label_Cor_Da_Borda;

GtkWidget *Caixa_De_Input_Cor_De_Fundo_Da_Janela;
GtkWidget *Input_Cor_De_Fundo_Da_Janela;
GtkWidget *Label_Cor_De_Fundo_Da_Janela;

GtkWidget *Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial;
GtkWidget *Checkbox_Imagens_Aparecendo_Como_Princial;
GtkWidget *Label_Imagens_Aparecendo_Como_Princial;
bool Liberacao_De_Checagem_Imagens_Aparecendo_Como_Princial = true;

GtkWidget *Caixa_De_Input_Tamanho_Da_Fonte;
GtkWidget *Input_Tamanho_Da_Fonte;
GtkWidget *Label_Tamanho_Da_Fonte;

GtkWidget *Botao_De_Salvar_Alteracoes;
GtkWidget *Botao_De_Restaurar_Alteracoes;
GtkWidget *Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao;

GtkWidget *Caixa_De_Opcoes_De_Configuracao;

std::ifstream Arquivo_Estilizacao("./data/Estilizacao.json");
json Estilizacao_Configuracao_JSON = json::parse(Arquivo_Estilizacao);
Configuracao_Estilo Estilizacao_Configuracao(Estilizacao_Configuracao_JSON);

std::ifstream Arquivo_Padrao("./data/Configuracoes.json");
json Padrao_Configuracao_JSON = json::parse(Arquivo_Padrao);
Configuracao_Padrao Padrao_Configuracao(Padrao_Configuracao_JSON);

static void Salvamento_De_Alteracoes(void) {
	Arquivo_Padrao.close();
	Arquivo_Estilizacao.close();

	std::ofstream Arquivo_Padrao_Atualizado("./data/Configuracoes.json");
	std::ofstream Arquivo_Estilizacao_Atualizado("./data/Estilizacao.json");

	GtkEntry *Input_Caminho_Da_Pasta_Principal_Convertendo = GTK_ENTRY(Input_Caminho_Da_Pasta_Principal);
	const gchar *Valor_Input_Caminho_Da_Pasta_Principal_Convertendo = gtk_entry_get_text(Input_Caminho_Da_Pasta_Principal_Convertendo);

	GtkToggleButton *Checkbox_Abrir_Paginas_Do_Projeto_Convertendo = GTK_TOGGLE_BUTTON(Checkbox_Abrir_Paginas_Do_Projeto);
	gboolean Estado_De_Checkbox_Abrir_Paginas_Do_Projeto = gtk_toggle_button_get_active(Checkbox_Abrir_Paginas_Do_Projeto_Convertendo);
	bool Boleano_Convertido_Checkbox_Abrir_Paginas_Do_Projeto = (Estado_De_Checkbox_Abrir_Paginas_Do_Projeto == TRUE);
	if (Boleano_Convertido_Checkbox_Abrir_Paginas_Do_Projeto) {
		Liberacao_De_Checagem_Abrir_Paginas_Do_Projeto = true;
	} else {
		Liberacao_De_Checagem_Abrir_Paginas_Do_Projeto = false;
	}

	GtkEntry *Input_Fonte_Padrao_De_Programa_Convertendo = GTK_ENTRY(Input_Fonte_Padrao_De_Programa);
	const gchar *Valor_Input_Fonte_Padrao_De_Programa_Convertendo = gtk_entry_get_text(Input_Fonte_Padrao_De_Programa_Convertendo);

	GtkEntry *Input_Fonte_Saudacao_De_Programa_Convertendo = GTK_ENTRY(Input_Fonte_Saudacao_De_Programa);
	const gchar *Valor_Input_Fonte_Saudacao_De_Programa_Convertendo = gtk_entry_get_text(Input_Fonte_Saudacao_De_Programa_Convertendo);

	GtkEntry *Input_Cor_Da_Fonte_Convertendo = GTK_ENTRY(Input_Cor_Da_Fonte);
	const gchar *Valor_Input_Cor_Da_Fonte_Convertendo = gtk_entry_get_text(Input_Cor_Da_Fonte_Convertendo);

	GtkEntry *Input_Cor_Da_Borda_Convertendo = GTK_ENTRY(Input_Cor_Da_Borda);
	const gchar *Valor_Input_Cor_Da_Borda_Convertendo = gtk_entry_get_text(Input_Cor_Da_Borda_Convertendo);

	GtkEntry *Input_Cor_De_Fundo_Da_Janela_Convertendo = GTK_ENTRY(Input_Cor_De_Fundo_Da_Janela);
	const gchar *Valor_Input_Cor_De_Fundo_Da_Janela_Convertendo = gtk_entry_get_text(Input_Cor_De_Fundo_Da_Janela_Convertendo);

	GtkToggleButton *Checkbox_Imagens_Aparecendo_Como_Princial_Convertendo = GTK_TOGGLE_BUTTON(Checkbox_Imagens_Aparecendo_Como_Princial);
	gboolean Estado_De_Checkbox_Imagens_Aparecendo_Como_Princial = gtk_toggle_button_get_active(Checkbox_Imagens_Aparecendo_Como_Princial_Convertendo);
	bool Boleano_Convertido_Checkbox_Imagens_Aparecendo_Como_Princial = (Estado_De_Checkbox_Imagens_Aparecendo_Como_Princial == TRUE);
	if (Boleano_Convertido_Checkbox_Imagens_Aparecendo_Como_Princial) {
		Liberacao_De_Checagem_Imagens_Aparecendo_Como_Princial = true;
	} else {
		Liberacao_De_Checagem_Imagens_Aparecendo_Como_Princial = false;
	}

	GtkEntry *Input_Tamanho_Da_Fonte_Convertendo = GTK_ENTRY(Input_Tamanho_Da_Fonte);
	const gchar *Valor_Input_Tamanho_Da_Fonte_Convertendo = gtk_entry_get_text(Input_Tamanho_Da_Fonte_Convertendo);
	int Valor_Em_Numero_Input_Tamanho_Da_Fonte_Convertendo = std::stoi(Valor_Input_Tamanho_Da_Fonte_Convertendo);

	Padrao_Configuracao_JSON["Caiminho_Do_Local_Com_Linguagens"] = Valor_Input_Caminho_Da_Pasta_Principal_Convertendo;
	Padrao_Configuracao_JSON["Abrir_Paginas_Com_Projeto"] = Boleano_Convertido_Checkbox_Abrir_Paginas_Do_Projeto;

	Estilizacao_Configuracao_JSON["Fonte_Padrao_De_Programa"] = Valor_Input_Fonte_Padrao_De_Programa_Convertendo;
	Estilizacao_Configuracao_JSON["Fonte_Saudacao_De_Programa"] = Valor_Input_Fonte_Saudacao_De_Programa_Convertendo;
	Estilizacao_Configuracao_JSON["Cor_Da_Fonte"] = Valor_Input_Cor_Da_Fonte_Convertendo;
	Estilizacao_Configuracao_JSON["Cor_Da_Borda"] = Valor_Input_Cor_Da_Borda_Convertendo;
	Estilizacao_Configuracao_JSON["Cor_De_Fundo_Da_Janela"] = Valor_Input_Cor_De_Fundo_Da_Janela_Convertendo;
	Estilizacao_Configuracao_JSON["Imagens_Ilustrativas_De_Linguagem"] = Boleano_Convertido_Checkbox_Imagens_Aparecendo_Como_Princial;
	Estilizacao_Configuracao_JSON["Tamanho_De_Fonte"] = Valor_Em_Numero_Input_Tamanho_Da_Fonte_Convertendo;

	Arquivo_Padrao_Atualizado << Padrao_Configuracao_JSON.dump(4);
	Arquivo_Estilizacao_Atualizado << Estilizacao_Configuracao_JSON.dump(4);

	Arquivo_Padrao_Atualizado.close();
	Arquivo_Estilizacao_Atualizado.close();

	Estilizacao_De_Conteudo();
}

static void Restauracao_Para_Padrao(void) {
	Arquivo_Estilizacao.close();
	std::ofstream Arquivo_Estilizacao_Atualizado("./data/Estilizacao.json");
	std::ofstream Arquivo_Padrao_Atualizado("./data/Configuracoes.json");

	Padrao_Configuracao_JSON["Caiminho_Do_Local_Com_Linguagens"] = "C:\\Users\\Usuario\\Desktop\\Temp\\Programacao";
	Padrao_Configuracao_JSON["Abrir_Paginas_Com_Projeto"] = true;

	Estilizacao_Configuracao_JSON["Fonte_Padrao_De_Programa"] = "Consolas";
	Estilizacao_Configuracao_JSON["Fonte_Saudacao_De_Programa"] = "Comic Sans MS";
	Estilizacao_Configuracao_JSON["Cor_Da_Fonte"] = "white";
	Estilizacao_Configuracao_JSON["Cor_Da_Borda"] = "white";
	Estilizacao_Configuracao_JSON["Cor_De_Fundo_Da_Janela"] = "black";
	Estilizacao_Configuracao_JSON["Imagens_Ilustrativas_De_Linguagem"] = true;
	Estilizacao_Configuracao_JSON["Tamanho_De_Fonte"] = 25;

	Arquivo_Padrao_Atualizado << Padrao_Configuracao_JSON.dump(2);
	Arquivo_Estilizacao_Atualizado << Estilizacao_Configuracao_JSON.dump(2);

	Arquivo_Padrao_Atualizado.close();
	Arquivo_Estilizacao_Atualizado.close();

	Estilizacao_De_Conteudo();
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

static void Ativacao_De_Elementos(void) {
	Botao_De_Salvar_Alteracoes = gtk_button_new_with_label("Salvar");
	Botao_De_Restaurar_Alteracoes = gtk_button_new_with_label("Restaurar");
	Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

	Caixa_De_Input_Caminho_Da_Pasta_Principal = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Caminho_Da_Pasta_Principal = gtk_entry_new();
	Label_Caminho_Da_Pasta_Principal = gtk_label_new("Pasta principal: ");

	Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Checkbox_Abrir_Paginas_Do_Projeto = gtk_check_button_new();
	Label_Abrir_Paginas_Do_Projeto = gtk_label_new("Abrir sites: ");

	Caixa_De_Input_Fonte_Padrao_De_Programa = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Fonte_Padrao_De_Programa = gtk_entry_new();
	Label_Fonte_Padrao_De_Programa = gtk_label_new("Fonte princial: ");

	Caixa_De_Input_Fonte_Saudacao_De_Programa = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Fonte_Saudacao_De_Programa = gtk_entry_new();
	Label_Fonte_Saudacao_De_Programa = gtk_label_new("Fonte saudacao: ");

	Caixa_De_Input_Cor_Da_Fonte = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Cor_Da_Fonte = gtk_entry_new();
	Label_Cor_Da_Fonte = gtk_label_new("Cor da fonte: ");

	Caixa_De_Input_Cor_Da_Borda = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Cor_Da_Borda = gtk_entry_new();
	Label_Cor_Da_Borda = gtk_label_new("Cor das bordas: ");

	Caixa_De_Input_Cor_De_Fundo_Da_Janela = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Cor_De_Fundo_Da_Janela = gtk_entry_new();
	Label_Cor_De_Fundo_Da_Janela = gtk_label_new("Cor de fundo: ");

	Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Checkbox_Imagens_Aparecendo_Como_Princial = gtk_check_button_new();
	Label_Imagens_Aparecendo_Como_Princial = gtk_label_new("Imagens: ");

	Caixa_De_Input_Tamanho_Da_Fonte = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	Input_Tamanho_Da_Fonte = gtk_entry_new();
	Label_Tamanho_Da_Fonte = gtk_label_new("Tamanho da Fonte: ");

	Caixa_De_Opcoes_De_Configuracao = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
}

static void Definindo_Valores_Padrao_De_Input(void) {
	gtk_entry_set_text(GTK_ENTRY(Input_Caminho_Da_Pasta_Principal), Padrao_Configuracao.Caminho_Pasta_Principal.c_str());
	if (Padrao_Configuracao.Abrir_Paginas_Com_Projeto && Liberacao_De_Checagem_Abrir_Paginas_Do_Projeto) {
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Checkbox_Abrir_Paginas_Do_Projeto), TRUE);
	}

	gtk_entry_set_text(GTK_ENTRY(Input_Fonte_Padrao_De_Programa), Estilizacao_Configuracao.Fonte_Padrao_De_Programa.c_str());
	gtk_entry_set_text(GTK_ENTRY(Input_Fonte_Saudacao_De_Programa), Estilizacao_Configuracao.Fonte_Saudacao_De_Programa.c_str());

	gtk_entry_set_text(GTK_ENTRY(Input_Cor_Da_Fonte), Estilizacao_Configuracao.Cor_Da_Fonte.c_str());
	gtk_entry_set_text(GTK_ENTRY(Input_Cor_Da_Borda), Estilizacao_Configuracao.Cor_Da_Borda.c_str());
	gtk_entry_set_text(GTK_ENTRY(Input_Cor_De_Fundo_Da_Janela), Estilizacao_Configuracao.Cor_De_Fundo_Da_Janela.c_str());

	gtk_entry_set_text(GTK_ENTRY(Input_Tamanho_Da_Fonte), std::to_string(Estilizacao_Configuracao.Tamanho_Da_Fonte).c_str());
	if (Estilizacao_Configuracao.Imagens_Ilustrativas_De_Linguagem && Liberacao_De_Checagem_Imagens_Aparecendo_Como_Princial) {
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Checkbox_Imagens_Aparecendo_Como_Princial), TRUE);
	}
}

static void Definindo_Ids(void) {
	gtk_widget_set_name(window_Configuracoes, "Corpo_Da_Janela");

	gtk_widget_set_name(Botao_De_Salvar_Alteracoes, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Botao_De_Restaurar_Alteracoes, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao, "Caixa_De_Inicio_Conjunto");

	gtk_widget_set_name(Caixa_De_Opcoes_De_Configuracao, "Caixa_De_Opcoes_De_Configuracoes");

	gtk_widget_set_name(Caixa_De_Input_Caminho_Da_Pasta_Principal, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Fonte_Padrao_De_Programa, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Fonte_Saudacao_De_Programa, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Cor_Da_Fonte, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Cor_Da_Borda, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Cor_De_Fundo_Da_Janela, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial, "Inputs_Padrao_Configuracoes");
	gtk_widget_set_name(Caixa_De_Input_Tamanho_Da_Fonte, "Inputs_Padrao_Configuracoes");

	gtk_widget_set_name(Input_Caminho_Da_Pasta_Principal, "Input_De_Caminho_Das_Configuracoes");

	gtk_widget_set_name(Label_Caminho_Da_Pasta_Principal, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Abrir_Paginas_Do_Projeto, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Fonte_Padrao_De_Programa, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Fonte_Saudacao_De_Programa, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Cor_Da_Fonte, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Cor_Da_Borda, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Cor_De_Fundo_Da_Janela, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Imagens_Aparecendo_Como_Princial, "Label_De_Texto_Das_Configuracoes_Com_Input");
	gtk_widget_set_name(Label_Tamanho_Da_Fonte, "Label_De_Texto_Das_Configuracoes_Com_Input");
}

static void Configurando_Janela(void) {
	gtk_window_set_title(GTK_WINDOW(window_Configuracoes), "Configuracoes");
	gtk_window_set_resizable(GTK_WINDOW(window_Configuracoes), false);
	gtk_window_resize(GTK_WINDOW(window_Configuracoes), 500, 700);
	gtk_window_move(GTK_WINDOW(window_Configuracoes), Posicao_X, Posicao_Y - 100);
}

static void Indentacao_Do_Conteudo(void) {
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Caminho_Da_Pasta_Principal), Label_Caminho_Da_Pasta_Principal, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Caminho_Da_Pasta_Principal), Input_Caminho_Da_Pasta_Principal, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Caminho_Da_Pasta_Principal, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto), Label_Abrir_Paginas_Do_Projeto, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto), Checkbox_Abrir_Paginas_Do_Projeto, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Checkbox_Abrir_Paginas_Do_Projeto, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Fonte_Padrao_De_Programa), Label_Fonte_Padrao_De_Programa, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Fonte_Padrao_De_Programa), Input_Fonte_Padrao_De_Programa, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Fonte_Padrao_De_Programa, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Fonte_Saudacao_De_Programa), Label_Fonte_Saudacao_De_Programa, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Fonte_Saudacao_De_Programa), Input_Fonte_Saudacao_De_Programa, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Fonte_Saudacao_De_Programa, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_Da_Fonte), Label_Cor_Da_Fonte, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_Da_Fonte), Input_Cor_Da_Fonte, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Cor_Da_Fonte, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_Da_Borda), Label_Cor_Da_Borda, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_Da_Borda), Input_Cor_Da_Borda, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Cor_Da_Borda, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_De_Fundo_Da_Janela), Label_Cor_De_Fundo_Da_Janela, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Cor_De_Fundo_Da_Janela), Input_Cor_De_Fundo_Da_Janela, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Cor_De_Fundo_Da_Janela, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial), Label_Imagens_Aparecendo_Como_Princial, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial), Checkbox_Imagens_Aparecendo_Como_Princial, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Checkbox_Imagens_Aparecendo_Como_Princial, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Tamanho_Da_Fonte), Label_Tamanho_Da_Fonte, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Input_Tamanho_Da_Fonte), Input_Tamanho_Da_Fonte, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Input_Tamanho_Da_Fonte, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao), Botao_De_Restaurar_Alteracoes, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao), Botao_De_Salvar_Alteracoes, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(Caixa_De_Opcoes_De_Configuracao), Caixa_De_Botoes_Com_Funcao_Salvamento_Remocao, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(window_Configuracoes), Caixa_De_Opcoes_De_Configuracao);
}

static void Acoes_Executaveis(void) {
	g_signal_connect(Botao_De_Salvar_Alteracoes, "clicked", G_CALLBACK(Salvamento_De_Alteracoes), NULL);
	g_signal_connect(Botao_De_Restaurar_Alteracoes, "clicked", G_CALLBACK(Restauracao_Para_Padrao), NULL);
	g_signal_connect(Input_Tamanho_Da_Fonte, "insert-text", G_CALLBACK(Validacao_De_Apenas_Numero), NULL);
}

static void Ativacao_De_Aplicacao(void) {
	// Ativando os elementos
	Ativacao_De_Elementos();
	//---------------------------------------------------------------------------------------

	// Adicionando o valor existente dentro deles
	Definindo_Valores_Padrao_De_Input();
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

	Criar_Botao_Sessao_Anterior(window_Configuracoes, Caixa_De_Opcoes_De_Configuracao, Reativacao_De_Janela_Index);

	// Indentacao de elementos
	Indentacao_Do_Conteudo();
	//---------------------------------------------------------------------------------------

	gtk_widget_show_all(window_Configuracoes);
}

void Configuracao_Grafico(GtkWidget *window_recebido) {
	window_Configuracoes = window_recebido;
	Ativacao_De_Aplicacao();
}