#include "I_Salario.hh"

#include <iostream>
#include <gtkmm/application.h>

using namespace std;

I_Salario::I_Salario(void)
   : lbl_baseSalarial("Base Salarial:"),
     btn_box("Ocorrencias"),
     btn_gravar("Gravar"),
     btn_sair("Sair")
{
   set_title("I_Salario");
   set_border_width(10);

   add(frame_top);
   frame_top.add(vbox_top);

   vbox_top.pack_start(vbox_cadastros);
   vbox_top.pack_start(bbox);

   vbox_cadastros.pack_start(lbl_baseSalarial);
   vbox_cadastros.pack_start(txt_baseSalarial);

//parte adicionada
   btn_box.add_pixlabel("info.xpm","Ocorrencias");

   set_title("Ocorrencias");
   set_border_width(10);
      
   btn_box.signal_clicked().connect( sigc::mem_fun(*this, &I_Salario::on_btn_clicked) );

   add(btn_box);
//fim parte
   
   bbox.add(btn_gravar);
   bbox.add(btn_sair);

   btn_sair.signal_clicked().connect(sigc::mem_fun(*this, &I_Salario::on_btn_sair_clicked));

   show_all_children();
}

void I_Salario::on_btn_gravar_clicked(void)
{
   // TODO chamar controladora(G_Empresa) para fazer insercao no BD
   cout << "Gravando dados" << endl;
}

void I_Salario::on_btn_sair_clicked(void)
{
   this->hide();
}

void I_Salario::on_btn_clicked(void)
{
  cout << "teste ocorrencia" << endl;
}

// TESTE
int main(int argc, char* argv[])
{
   auto app = Gtk::Application::create(argc, argv, "teste");

   I_Salario telaSalario;
   telaSalario.set_default_size(400, 180);
   return app->run(telaSalario);
}
