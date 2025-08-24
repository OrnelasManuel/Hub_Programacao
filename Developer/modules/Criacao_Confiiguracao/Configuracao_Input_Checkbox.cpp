#include <Variaveis_Globais.hpp>
#include <gtk/gtk.h>
#include <vector>

void Construcao_De_Opcoes_De_Configuracao_Input_Checkbox(GtkWidget *Caixa_Opcoes_Configuracao, std::vector<GtkWidget *> &Conjunto_input) {
	for (const auto &item : Criacao_De_Configuracao_JSON["Configuracoes_Do_Tipo_Checkbox_Introducao"]) {
		std::string Texto_Dentro_Do_Label = item.value("Nome", "");
		std::string Nome_Da_Classe_Da_Opcao = item.value("Classe_Do_Elemento", "");
		bool Valor_Boleano_De_Grupo = Configuracao_Universal_JSON[item.value("Nome_Da_Configuracao", "")];

		GtkWidget *Caixa_De_Checkbox_Modelo_Configuracao = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		GtkWidget *Checkbox_Modelo_Configuracao = gtk_check_button_new();
		GtkWidget *Label_Modelo_Configuracao = gtk_label_new((Texto_Dentro_Do_Label + ": ").c_str());

		Conjunto_input.push_back(Checkbox_Modelo_Configuracao);

		gtk_widget_set_name(Caixa_De_Checkbox_Modelo_Configuracao, "Inputs_Padrao_Configuracoes");
		gtk_widget_set_name(Checkbox_Modelo_Configuracao, Nome_Da_Classe_Da_Opcao.c_str());
		gtk_widget_set_name(Label_Modelo_Configuracao, "Label_De_Texto_Das_Configuracoes_Com_Input");

		gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Modelo_Configuracao), Label_Modelo_Configuracao, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_De_Checkbox_Modelo_Configuracao), Checkbox_Modelo_Configuracao, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(Caixa_Opcoes_Configuracao), Caixa_De_Checkbox_Modelo_Configuracao, FALSE, FALSE, 0);

		if (Valor_Boleano_De_Grupo) {
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Checkbox_Modelo_Configuracao), TRUE);
		}
	}
}