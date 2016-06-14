//Desenvolvido por Christian Takashi Nakata

#ifndef RIBANCEIRA_I_EMPRESA_HH
#define RIBANCEIRA_I_EMPRESA_HH

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/combobox.h>
#include <gtkmm/entry.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/window.h>

class I_Salario : public Gtk::Window
{
  public:
    I_Salario(void);
      
  private:
    void on_btn_gravar_clicked(void);
    void on_btn_sair_clicked(void);
//parte adicionada
    void on_button_clicked(void);
         
    Gtk::Frame frame_top;
    Gtk::VBox vbox_top, vbox_cadastros;
    Gtk::ButtonBox bbox;
                        
    Gtk::Label lbl_baseSalarial;
    Gtk::Entry txt_baseSalarial; 
    Gtk::Button btn_gravar, btn_sair,
                btn_box;
};

#endif // RIBANCEIRA_I_EMPRESA_HH)))}))
