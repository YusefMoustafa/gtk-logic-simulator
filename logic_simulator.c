#include <gtk/gtk.h>
#include <stdlib.h> // for atoi

GtkWidget *entry_a, *entry_b, *entry_c;
GtkWidget *label_d, *label_e, *label_x;

void compute_logic(GtkWidget *widget, gpointer data) {
    const gchar *text_a = gtk_entry_get_text(GTK_ENTRY(entry_a));
    const gchar *text_b = gtk_entry_get_text(GTK_ENTRY(entry_b));
    const gchar *text_c = gtk_entry_get_text(GTK_ENTRY(entry_c));

    int A = atoi(text_a);
    int B = atoi(text_b);
    int C = atoi(text_c);

    A = A ? 1 : 0;
    B = B ? 1 : 0;
    C = C ? 1 : 0;

    int D = A && B;
    int E = A && C;
    int X = D || E;

    char buffer[50];

    sprintf(buffer, "D (A ∧ B): %d", D);
    gtk_label_set_text(GTK_LABEL(label_d), buffer);

    sprintf(buffer, "E (A ∧ C): %d", E);
    gtk_label_set_text(GTK_LABEL(label_e), buffer);

    sprintf(buffer, "X (D ∨ E): %d", X);
    gtk_label_set_text(GTK_LABEL(label_x), buffer);
}

int main(int argc, char *argv[]) {
    GtkWidget *window, *grid, *label_a, *label_b, *label_c, *button;

    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Two-Level Logic Simulator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
    gtk_widget_set_size_request(window, 300, 220);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 8);
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create input labels and entries
    label_a = gtk_label_new("Input A:");
    label_b = gtk_label_new("Input B:");
    label_c = gtk_label_new("Input C:");
    entry_a = gtk_entry_new();
    entry_b = gtk_entry_new();
    entry_c = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), label_a, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_a, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_b, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_b, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_c, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_c, 1, 2, 1, 1);

    // Compute button
    button = gtk_button_new_with_label("Compute");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(compute_logic), NULL);

    // Output labels
    label_d = gtk_label_new("D (A ∧ B): 0");
    label_e = gtk_label_new("E (A ∧ C): 0");
    label_x = gtk_label_new("X (D ∨ E): 0");

    gtk_grid_attach(GTK_GRID(grid), label_d, 0, 4, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), label_e, 0, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), label_x, 0, 6, 2, 1);

    // Show everything
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
