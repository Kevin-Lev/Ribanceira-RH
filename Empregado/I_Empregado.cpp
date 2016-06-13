#include "I_Empregado.hh"

#include <iostream>
#include <gtkmm/application.h>

using namespace std;

I_Empregado::I_Empregado(void)
   : lbl_PIS("PIS:"),
     lbl_sindicato("Sindicato"),
     btn_gravar("Gravar"),
     btn_sair("Sair")
{
   set_title("I_Empregado");
   set_border_width(10);

   add(frame_top);
   frame_top.add(vbox_top);

   vbox_top.pack_start(vbox_cadastros);
   vbox_top.pack_start(bbox);

   vbox_cadastros.pack_start(lbl_PIS);
   vbox_cadastros.pack_start(txt_PIS);
   vbox_cadastros.pack_start(lbl_sindicato);
   vbox_cadastros.pack_start(txt_sindicato);
   
   bbox.add(btn_gravar);
   bbox.add(btn_sair);

   btn_sair.signal_clicked().connect(sigc::mem_fun(*this, &I_Empregado::on_btn_sair_clicked));

   show_all_children();
}

void I_Empregado::on_btn_gravar_clicked(void)
{
   // TODO chamar controladora(G_Empresa) para fazer insercao no BD
   cout << "Gravando dados" << endl;
}

void I_Empregado::on_btn_sair_clicked(void)
{
   this->hide();
}

// TESTE
int main(int argc, char* argv[])
{
   auto app = Gtk::Application::create(argc, argv, "teste");

   I_Empregado telaEmpregado;
   telaEmpregado.set_default_size(300, 180);
   return app->run(telaEmpregado);
}
