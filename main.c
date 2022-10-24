
#include <gtk/gtk.h>

#include <stdio.h>
void map(int *cheese);
static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;
static gboolean
button_press_callback (GtkWidget      *event_box,
                     GdkEventButton *event,
                     gpointer        data)
{
g_print ("Coordinates %f,%f\n",
         event->x, event->y);

    printf("hello");
// Returning TRUE means we handled the event, so the signal
// emission should be stopped (don’t call any further callbacks
// that may be connected). Return FALSE to continue invoking callbacks.
return TRUE;
}

void
print_hello (GtkWidget *button3)
{


    printf("Hello World\n");
    printf("hello2");

}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button_box;
    int cheese;




    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    GtkWidget *grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);



    button = gtk_button_new_with_label("open map");
    gtk_grid_attach(GTK_GRID(grid),button,0,2,3,2);
    g_signal_connect (button, "clicked", G_CALLBACK (map(&cheese)), window);

    button2 = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped (button2, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    g_signal_connect(window, "key-press-event", G_CALLBACK(activate), NULL);
    gtk_grid_attach(GTK_GRID(grid),button2,4,2,3,2);

    button3 = gtk_button_new_with_label("func");
    g_signal_connect_swapped (button2, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    g_signal_connect(window, "key-press-event", G_CALLBACK(print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid),button3,0,4,3,2);



    gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);



    return status;
}

void map(int *cheese){
    GtkWidget *image;
    GtkWidget *event_box;
    GtkWidget *window, *grid, *calculate;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    image = gtk_image_new_from_file ("C:\\Users\\sebbe\\Desktop\\P0\\Billeder\\Danmark.jpg");
    event_box = gtk_event_box_new ();
    gtk_grid_attach (GTK_GRID(grid), event_box,0,0,2,1);

    gtk_container_add (GTK_CONTAINER (event_box), image);
    g_signal_connect (G_OBJECT (event_box),
                      "button_press_event",
                      G_CALLBACK (button_press_callback),
                      image);

    gtk_widget_show_all(window);
    gtk_main();
}