#include <Includes_Geral.hpp>

extern void Index_Grafico(void);

int main(int argc, char **argv) {
	int status;

	Aplicacao_Global = gtk_application_new("sistemadevvendas.com.br", G_APPLICATION_DEFAULT_FLAGS);

	g_signal_connect(Aplicacao_Global, "activate", G_CALLBACK(Index_Grafico), NULL);

	status = g_application_run(G_APPLICATION(Aplicacao_Global), argc, argv);

	g_object_unref(Aplicacao_Global);

	return status;
}