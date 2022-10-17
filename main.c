
#include <gtk/gtk.h>

#include <stdio.h>

static gboolean
button_press_callback (GtkWidget      *event_box,
                     GdkEventButton *event,
                     gpointer        data)
{
g_print ("Event box clicked at coordinates %f,%f\n",
         event->x, event->y);

// Returning TRUE means we handled the event, so the signal
// emission should be stopped (don’t call any further callbacks
// that may be connected). Return FALSE to continue invoking callbacks.
return TRUE;
}

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *button_box;
    GtkWidget *image;
    GtkWidget *event_box;



    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    GtkWidget *grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);

    image = gtk_image_new_from_file ("C:\\Users\\sebbe\\Desktop\\P0\\Billeder\\Danmark.jpg");
    event_box = gtk_event_box_new ();
    gtk_grid_attach (GTK_GRID(grid), event_box,0,0,2,1);

    gtk_container_add (GTK_CONTAINER (event_box), image);
    g_signal_connect (G_OBJECT (event_box),
                      "button_press_event",
                      G_CALLBACK (button_press_callback),
                      image);



    button = gtk_button_new_with_label("Plot");
    gtk_grid_attach(GTK_GRID(grid),button,0,2,1,2);

    button2 = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped (button2, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    g_signal_connect(window, "key-press-event", G_CALLBACK(activate), NULL);
    gtk_grid_attach(GTK_GRID(grid),button2,1,2,1,2);



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