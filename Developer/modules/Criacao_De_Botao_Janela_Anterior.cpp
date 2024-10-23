#include <gtk/gtk.h>

// Estrutura para manter o contexto
struct Contexto_De_Ativacao {
	GtkWidget *window;
	GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar;
	void (*Funcao_De_Ativacao_De_Pagina_Anterior)();
};

// Função de callback
static void Voltar_Para_Pagina_Anterior(GtkWidget *widget, gpointer data) {
	Contexto_De_Ativacao *contexto = (Contexto_De_Ativacao *)data;
	gtk_container_remove(GTK_CONTAINER(contexto->window), contexto->Caixa_Onde_O_Botao_Vai_Ficar);
	contexto->Funcao_De_Ativacao_De_Pagina_Anterior();
	g_free(contexto); // Libera a memória do contexto
}

// Função para criar o botão
void Criar_Botao_Sessao_Anterior(GtkWidget *window_recebido, GtkWidget *Caixa_Onde_O_Botao_Vai_Ficar, void (*Funcao_De_Ativacao)()) {
	GtkWidget *Botao_De_Voltar_Para_Outra_Pagina;
	GtkWidget *Caixa_De_Botao_De_Voltar_Para_Outra_Pagina;

	// Criação da estrutura de contexto
	Contexto_De_Ativacao *contexto = (Contexto_De_Ativacao *)g_malloc(sizeof(Contexto_De_Ativacao));
	contexto->window = window_recebido;
	contexto->Caixa_Onde_O_Botao_Vai_Ficar = Caixa_Onde_O_Botao_Vai_Ficar;
	contexto->Funcao_De_Ativacao_De_Pagina_Anterior = Funcao_De_Ativacao;

	// Criação do botão
	Botao_De_Voltar_Para_Outra_Pagina = gtk_button_new_with_label("<-");
	Caixa_De_Botao_De_Voltar_Para_Outra_Pagina = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

	gtk_widget_set_name(Botao_De_Voltar_Para_Outra_Pagina, "Botoes_De_Acao_Individual");
	gtk_widget_set_name(Caixa_De_Botao_De_Voltar_Para_Outra_Pagina, "Caixa_De_Inicio_Conjunto");

	gtk_box_pack_start(GTK_BOX(Caixa_De_Botao_De_Voltar_Para_Outra_Pagina), Botao_De_Voltar_Para_Outra_Pagina, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(Caixa_Onde_O_Botao_Vai_Ficar), Caixa_De_Botao_De_Voltar_Para_Outra_Pagina, FALSE, FALSE, 0);

	// Conectando o sinal de clique ao callback
	g_signal_connect(Botao_De_Voltar_Para_Outra_Pagina, "clicked", G_CALLBACK(Voltar_Para_Pagina_Anterior), contexto);
}