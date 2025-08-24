#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>
#include <vector>

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

void Construcao_De_Opcoes_De_Configuracao_Input_Numero(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<GtkWidget *> &Conjunto_input) {
	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Numero_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		int Valor_De_Numero_Ja_Possuido = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];

		GtkWidget *Caixa_De_Input_De_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Input_De_Modelo_Configuracao = gtk_entry_new();
		GtkWidget *Label_De_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		Conjunto_input.push_back(Input_De_Modelo_Configuracao);

		gtk_widget_set_name(Caixa_De_Input_De_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Input_De_Modelo_Configuracao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_De_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Label_De_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Input_De_Modelo_Configuracao), Input_De_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Opcoes_Configuracao), Caixa_De_Input_De_Modelo_Configuracao, FALSE, FALSE, 0);

		gtk_entry_set_text(GTK_ENTRY(Input_De_Modelo_Configuracao), std::to_string(Valor_De_Numero_Ja_Possuido).c_str());

		g_signal_connect(Input_De_Modelo_Configuracao, "insert-text", G_CALLBACK(Validacao_De_Apenas_Numero), NULL);
	}
}