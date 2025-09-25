#include <Variaveis_Globais.hpp>
#include <functional>
#include <gtk/gtk.h>
#include <iostream>
#include <string>
#include <unordered_map>

extern void Input_Realtime_CSS(void);

std::unordered_map<std::string, std::function<void()>> Funcoes_De_Click_Dinamicas = {{"Abrir_CSS", []() { Input_Realtime_CSS(); }}};

void Executor_De_Funcao_Dinamica(GtkWidget *widget, gpointer data) {
	std::string *Nome_Funcao = static_cast<std::string *>(data);
	Funcoes_De_Click_Dinamicas[*Nome_Funcao]();
}

void Construcao_De_Opcoes_De_Configuracao_Input_Click(GtkWidget *Caixa_Opcoes_Configuracao) {

	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Click_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		std::string *Funcao_Referente = new std::string(item.value("Funcao", ""));

		GtkWidget *Caixa_De_Input_De_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Botao_De_Acao = gtk_button_new_with_label("abrir");
		GtkWidget *Label_De_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		gtk_widget_set_name(Caixa_De_Input_De_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Botao_De_Acao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_De_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Label_De_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Botao_De_Acao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Opcoes_Configuracao), Caixa_De_Input_De_Modelo_Configuracao, FALSE, FALSE, 0);

		g_signal_connect(Botao_De_Acao, "clicked", G_CALLBACK(Executor_De_Funcao_Dinamica), Funcao_Referente);
	}
}