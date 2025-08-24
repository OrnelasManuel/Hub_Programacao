#include <Includes_Geral.hpp>

extern void Estilizacao_De_Conteudo(void);

// Criacão de Elementos
GtkWidget *Minha_Label_Inicial;
GtkWidget *Caixa_Principal;

//---------------------------------------------------------------------------------------

static int Escolha_Aleatoria(int Numero_Sorvetado_Maximo) {
	srand(static_cast<unsigned>(time(0)));
	int numeroAleatorio = rand() % Numero_Sorvetado_Maximo;
	return numeroAleatorio;
}

static void Ativacao_De_Elementos(void) {

	const char *Emoji_Aleatorio[] = {"😉", "😎", "😁", "😃", "😄", "😊", "🙂", "😆", "😌", "😏"};
	const char *Frase_Aleatoria[] = {"Bem-vindo de volta!", "Olá novamente!",     "Bom te ver de volta!",  "Que bom que voltou!",     "Olá!",
	                                 "Vamos trabalhar!",    "Bem-vindo de novo!", "De volta ao trabalho!", "Vamos ao que interessa!", "Pronto para mais uma?"};

	gchar *Texto_De_Entrada = g_strdup_printf("%s\n\n%s", Frase_Aleatoria[Escolha_Aleatoria(10)], Emoji_Aleatorio[Escolha_Aleatoria(10)]);

	Minha_Label_Inicial = gtk_label_new(Texto_De_Entrada);
}

static void Definindo_Ids(void) { gtk_widget_set_name(Window_Global, "Corpo_Da_Janela"); }

static void Configurando_Janela(void) {
	gtk_window_set_default_size(GTK_WINDOW(Window_Global), 500, 500);
	gtk_window_resize(GTK_WINDOW(Window_Global), 500, 500);
	gtk_window_set_position(GTK_WINDOW(Window_Global), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(Window_Global), "Sistema de Vendas");
	gtk_window_set_resizable(GTK_WINDOW(Window_Global), TRUE);
	gtk_window_set_icon_from_file(GTK_WINDOW(Window_Global), "Aplication_Images/Sistem_Icon.ico", NULL);
}

static void Acao_De_Botoes(void) {
	// g_signal_connect(Botao_De_Novo_Projeto, "clicked", G_CALLBACK(Novo_Projeto), NULL);
}

static void Indentacao_Do_Conteudo(void) {
	Caixa_Principal = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

	gtk_box_pack_start(GTK_BOX(Caixa_Principal), Minha_Label_Inicial, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(Window_Global), Caixa_Principal);
}

static void Ativacao_De_Aplicacao() {
	// Ativacao de Elementos
	Ativacao_De_Elementos();
	//---------------------------------------------------------------------------------------

	// Definicao de ids de Elementos
	Definindo_Ids();
	//---------------------------------------------------------------------------------------

	// Configuracoes de Janela
	Configurando_Janela();
	//---------------------------------------------------------------------------------------

	// Acao de botão quando clicado
	Acao_De_Botoes();
	//---------------------------------------------------------------------------------------

	// Estilos do conteudo
	Estilizacao_De_Conteudo();
	//---------------------------------------------------------------------------------------

	// Indentacao de elementos
	Indentacao_Do_Conteudo();
	//---------------------------------------------------------------------------------------

	gtk_widget_show_all(Window_Global);
}

void Reativacao_De_Janela_Index(void) {
	gtk_window_move(GTK_WINDOW(Window_Global), Posicao_X, Posicao_Y);

	Ativacao_De_Aplicacao();
}

void Index_Grafico(void) {
	Window_Global = gtk_application_window_new(Aplicacao_Global);
	Ativacao_De_Aplicacao();
	gtk_window_get_position(GTK_WINDOW(Window_Global), &Posicao_X, &Posicao_Y);
}