//Desenvolvido por Christian Takashi Nakata

#include "I_ConvencaoColetiva.hh"

#include <iostream>
#include <gtkmm/application.h>

using namespace std;

I_ConvencaColetiva::I_ConvencaColetiva(void)
   : lbl_categoria("Categoria"),
     lbl_nomeSindicato("Nome do Sindicato"),
     lbl_data("Data"),
     btn_gravar("Gravar"),
     btn_sair("Sair")
{
   set_title("I_ConvencaColetiva");
   set_border_width(10);

   add(frame_top);
   frame_top.add(vbox_top);

   vbox_top.pack_start(vbox_cadastros);
   vbox_top.pack_start(bbox);

   vbox_cadastros.pack_start(lbl_categoria);
   vbox_cadastros.pack_start(txt_categoria);
   vbox_cadastros.pack_start(lbl_nomeSindicato);
   vbox_cadastros.pack_start(txt_nomeSindicato);
   vbox_cadastros.pack_start(lbl_data);
   vbox_cadastros.pack_start(txt_data);
   
   bbox.add(btn_gravar);
   bbox.add(btn_sair);

   btn_sair.signal_clicked().connect(sigc::mem_fun(*this, &I_ConvencaColetiva::on_btn_sair_clicked));

   show_all_children();
}

void I_ConvencaColetiva::on_btn_gravar_clicked(void)
{
   // TODO chamar controladora(G_Empresa) para fazer insercao no BD
   cout << "Gravando dados" << endl;
}

void I_ConvencaColetiva::on_btn_sair_clicked(void)
{
   this->hide();
}

// TESTE
int main(int argc, char* argv[])
{
   auto app = Gtk::Application::create(argc, argv, "teste");

   I_ConvencaColetiva telaConvColetiva;
   telaConvColetiva.set_default_size(400, 240);
   return app->run(telaConvColetiva);
}
