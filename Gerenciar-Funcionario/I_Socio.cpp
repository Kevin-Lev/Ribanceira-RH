//Desenvolvido por Christian Takashi Nakata

#include "I_Socio.hh"

#include <iostream>
#include <gtkmm/application.h>

using namespace std;

I_Socio::I_Socio(void)
   : lbl_papel("Papel:"),
     lbl_porcentagemLucro("Porcentagem de Lucro:"),
     btn_gravar("Gravar"),
     btn_sair("Sair")
{
   set_title("I_Socio");
   set_border_width(10);

   add(frame_top);
   frame_top.add(vbox_top);

   vbox_top.pack_start(vbox_cadastros);
   vbox_top.pack_start(bbox);

   vbox_cadastros.pack_start(lbl_papel);
   vbox_cadastros.pack_start(txt_papel);
   vbox_cadastros.pack_start(lbl_porcentagemLucro);
   vbox_cadastros.pack_start(txt_porcentagemLucro);
   
   bbox.add(btn_gravar);
   bbox.add(btn_sair);

   btn_sair.signal_clicked().connect(sigc::mem_fun(*this, &I_Socio::on_btn_sair_clicked));

   show_all_children();
}

void I_Socio::on_btn_gravar_clicked(void)
{
   // TODO chamar controladora(G_Empresa) para fazer insercao no BD
   cout << "Gravando dados" << endl;
}

void I_Socio::on_btn_sair_clicked(void)
{
   this->hide();
}

// TESTE
int main(int argc, char* argv[])
{
   auto app = Gtk::Application::create(argc, argv, "teste");

   I_Socio telaSocio;
   telaSocio.set_default_size(300, 180);
   return app->run(telaSocio);
}
