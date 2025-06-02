// Wine Launcher
// @author Cooper Black (cooperblacks.github.io)

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_wine_installed(){if (system("which wine > /dev/null 2>&1") == 0) {return true;}else{return false;}}

void install_wine(){system("sudo apt update && sudo apt install -y wine");}

void run_exe_with_wine(const char *file){
    char command[256];
    snprintf(command, sizeof(command), "wine %s", file);
    system(command);
}

void show_wine_installation_gui(){
    GtkWidget *dialog;
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Install Wine");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "Wine is not installed!\nInstall the latest version to proceed.");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    install_wine();
}

void show_exe_selector_gui(){
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Select .exe file to run");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    dialog = gtk_file_chooser_dialog_new("Open File",
                                         GTK_WINDOW(window),
                                         action,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Open", GTK_RESPONSE_ACCEPT,
                                         NULL);
    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT){
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        run_exe_with_wine(filename);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    if(is_wine_installed()){show_exe_selector_gui();
    }else{show_wine_installation_gui();}
    return 0;
}

// Sweet and simple, eh?
