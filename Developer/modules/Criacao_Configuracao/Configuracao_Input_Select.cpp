#include <Variaveis_Globais.hpp>
#include <algorithm>
#include <gtk/gtk.h>
#include <vector>

static std::vector<std::string> Valor_De_Select_Ja_Possuido;
static std::vector<std::vector<std::string>> *Global_Conjunto_input = nullptr;

struct Opcao_Clicada {
	std::string Nome_Da_Opcao;
	GtkWidget *Caixa_Da_Opcao;
};

static void Atualizar_Conjunto_De_Select(void) {
	Global_Conjunto_input->clear();
	Global_Conjunto_input->push_back(Valor_De_Select_Ja_Possuido);
}

static void Excluir_Opcao_Select(GtkWidget *widget, gpointer data) {
	Opcao_Clicada *Dados = static_cast<Opcao_Clicada *>(data);
	Valor_De_Select_Ja_Possuido.erase(std::remove(Valor_De_Select_Ja_Possuido.begin(), Valor_De_Select_Ja_Possuido.end(), Dados->Nome_Da_Opcao), Valor_De_Select_Ja_Possuido.end());
	gtk_widget_destroy(Dados->Caixa_Da_Opcao);
	Atualizar_Conjunto_De_Select();
}

static void Exibir_Opcoes_Select(GtkWidget *button, gpointer Caixa_Da_Opcao) {
	if (gtk_widget_get_visible(GTK_WIDGET(Caixa_Da_Opcao))) {
		gtk_widget_hide(GTK_WIDGET(Caixa_Da_Opcao));
	} else {
		gtk_widget_show(GTK_WIDGET(Caixa_Da_Opcao));
	}
}

static void Adicionar_Opcao_Select(std::string Nome_Opcao, GtkWidget *Caixa_De_Select_Com_Opcoes_Selecionadas, bool Construcao_Inicial = false) {
	if (std::find(Valor_De_Select_Ja_Possuido.begin(), Valor_De_Select_Ja_Possuido.end(), Nome_Opcao) == Valor_De_Select_Ja_Possuido.end()) {
		Valor_De_Select_Ja_Possuido.push_back(Nome_Opcao);
		GtkWidget *Opcao_Atual = gtk_button_new_with_label(Nome_Opcao.c_str());
		GtkWidget *Caixa_De_Opcao_E_Botao_De_Remocao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		Opcao_Clicada *Dados = new Opcao_Clicada{Nome_Opcao, Caixa_De_Opcao_E_Botao_De_Remocao};
		gtk_widget_set_name(Opcao_Atual, "Opcao_Individual_Select");
		gtk_widget_set_name(Caixa_De_Opcao_E_Botao_De_Remocao, "Caixa_De_Opcao_E_Botao_De_Remocao");
		gtk_box_pack_start(GTK_BOX(Caixa_De_Opcao_E_Botao_De_Remocao), Opcao_Atual, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Select_Com_Opcoes_Selecionadas), Caixa_De_Opcao_E_Botao_De_Remocao, TRUE, TRUE, 0);
		g_signal_connect(Opcao_Atual, "clicked", G_CALLBACK(Excluir_Opcao_Select), Dados);
		Atualizar_Conjunto_De_Select();
	} else if (Construcao_Inicial) {
		GtkWidget *Opcao_Atual = gtk_button_new_with_label(Nome_Opcao.c_str());
		GtkWidget *Caixa_De_Opcao_E_Botao_De_Remocao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		Opcao_Clicada *Dados = new Opcao_Clicada{Nome_Opcao, Caixa_De_Opcao_E_Botao_De_Remocao};
		gtk_widget_set_name(Opcao_Atual, "Opcao_Individual_Select");
		gtk_widget_set_name(Caixa_De_Opcao_E_Botao_De_Remocao, "Caixa_De_Opcao_E_Botao_De_Remocao");
		gtk_box_pack_start(GTK_BOX(Caixa_De_Opcao_E_Botao_De_Remocao), Opcao_Atual, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Select_Com_Opcoes_Selecionadas), Caixa_De_Opcao_E_Botao_De_Remocao, TRUE, TRUE, 0);
		g_signal_connect(Opcao_Atual, "clicked", G_CALLBACK(Excluir_Opcao_Select), Dados);
		Atualizar_Conjunto_De_Select();
	}
}

static void Adicionar_Opcao_Select_Por_Alteracao(GtkComboBoxText *combo, gpointer Caixa_Da_Opcao) {
	gchar *texto = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo));
	std::string Nome_Opcao(texto);

	Adicionar_Opcao_Select(Nome_Opcao, GTK_WIDGET(Caixa_Da_Opcao));
	gtk_widget_show_all(GTK_WIDGET(Caixa_Da_Opcao));
}

gboolean on_scroll_horizontal(GtkWidget *widget, GdkEventScroll *event, gpointer user_data) {
	GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW(user_data);
	GtkAdjustment *hadj = gtk_scrolled_window_get_hadjustment(sw);

	gdouble value = gtk_adjustment_get_value(hadj);
	gdouble step = gtk_adjustment_get_step_increment(hadj);

	if (event->direction == GDK_SCROLL_UP)
		gtk_adjustment_set_value(hadj, value - step); // roda pra baixo -> direita
	else if (event->direction == GDK_SCROLL_DOWN)
		gtk_adjustment_set_value(hadj, value + step); // roda pra cima -> esquerda

	return TRUE;
}

void Construcao_De_Opcoes_De_Configuracao_Input_Select(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<std::vector<std::string>> &Conjunto_input) {
	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Select_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		Valor_De_Select_Ja_Possuido = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];
		Global_Conjunto_input = &Conjunto_input;
		GtkWidget *Caixa_De_Select_Com_Opcoes_Selecionadas = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Caixa_Com_Scroll = gtk_scrolled_window_new(NULL, NULL);
		GtkWidget *Label_De_Select = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());
		GtkWidget *Sinal_De_Select = gtk_button_new_with_label("<");
		GtkWidget *Caixa_Label_Opcoes_Sinal = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Caixa_Select_E_Opcoes = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		GtkWidget *Select_De_Modelo_Configuracao = gtk_combo_box_text_new();

		gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(Caixa_Com_Scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_NEVER);

		gtk_widget_set_name(Caixa_De_Select_Com_Opcoes_Selecionadas, "Conjunto_De_Opcao_Select");
		gtk_widget_set_name(Label_De_Select, "Label_De_Texto_Das_Configuracoes_Com_Input");
		gtk_widget_set_name(Sinal_De_Select, "Sinal_De_Select");
		gtk_widget_set_name(Caixa_Select_E_Opcoes, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Select_De_Modelo_Configuracao, "Select_De_Modelo_Configuracao");

		Elementos_Invisiveis.push_back(Select_De_Modelo_Configuracao);

		for (const auto &valor : Valor_De_Select_Ja_Possuido) {
			g_print("Valor inicial selecionado: %s\n", valor.c_str());
			Adicionar_Opcao_Select(valor, Caixa_De_Select_Com_Opcoes_Selecionadas, true);
		}

		for (const auto &valor : Pastas_Existentes) {
			gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(Select_De_Modelo_Configuracao), valor.c_str());
		}

		g_signal_connect(Sinal_De_Select, "clicked", G_CALLBACK(Exibir_Opcoes_Select), Select_De_Modelo_Configuracao);
		g_signal_connect(Select_De_Modelo_Configuracao, "changed", G_CALLBACK(Adicionar_Opcao_Select_Por_Alteracao), Caixa_De_Select_Com_Opcoes_Selecionadas);

		gtk_box_pack_start(GTK_BOX(Caixa_Label_Opcoes_Sinal), Label_De_Select, FALSE, FALSE, 0);
		gtk_container_add(GTK_CONTAINER(Caixa_Com_Scroll), Caixa_De_Select_Com_Opcoes_Selecionadas);
		gtk_box_pack_start(GTK_BOX(Caixa_Label_Opcoes_Sinal), Caixa_Com_Scroll, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Label_Opcoes_Sinal), Sinal_De_Select, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Select_E_Opcoes), Caixa_Label_Opcoes_Sinal, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Select_E_Opcoes), Select_De_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Opcoes_Configuracao), Caixa_Select_E_Opcoes, FALSE, FALSE, 0);

		GtkWidget *Referencia_Scroll_De_Caixa_De_Scoll = gtk_bin_get_child(GTK_BIN(Caixa_Com_Scroll));
		gtk_widget_add_events(Referencia_Scroll_De_Caixa_De_Scoll, GDK_SCROLL_MASK);
		g_signal_connect(Referencia_Scroll_De_Caixa_De_Scoll, "scroll-event", G_CALLBACK(on_scroll_horizontal), Caixa_Com_Scroll);
	}
}