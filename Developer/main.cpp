#include <cstdlib>
#include <ctime>
#include <gtk/gtk.h>
#include <iostream>
#include <pango/pango.h>

extern void Index_Grafico(GtkApplication *Aplicacao_Recebida, gpointer user_data);

int main(int argc, char **argv) {
	GtkApplication *Aplicacao;
	int status;

	Aplicacao = gtk_application_new("manuelornelas.com.br", G_APPLICATION_DEFAULT_FLAGS);

	g_signal_connect(Aplicacao, "activate", G_CALLBACK(Index_Grafico), NULL);

	status = g_application_run(G_APPLICATION(Aplicacao), argc, argv);

	g_object_unref(Aplicacao);

	return status;
}