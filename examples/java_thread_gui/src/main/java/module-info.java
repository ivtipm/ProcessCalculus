module zabgu.java_thread_gui {
    requires javafx.controls;
    requires javafx.fxml;


    opens zabgu.java_thread_gui to javafx.fxml;
    exports zabgu.java_thread_gui;
}