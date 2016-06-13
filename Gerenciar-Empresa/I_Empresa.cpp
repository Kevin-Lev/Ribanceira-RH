/*Copyright (C) 2016  Pedro Garozi <pedrohentorres@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "I_Empresa.hh"

#include <iostream>
#include <gtkmm/application.h>

using namespace std;

I_Empresa::I_Empresa(void)
   : lbl_cnpj("CNPJ:"),
     lbl_inscricaoEstadual("Inscrição Estadual:"),
     lbl_inscricaoMunicipal("Inscrição Municipal:"),
     lbl_nomeEmpresa("Nome Empresa:"),
     lbl_nomeFantasia("Nome Fantasia:"),
     lbl_endereco("Endereço:"),
     lbl_telefone("Telefone:"),
     lbl_email("E-mail:"),
     lbl_regimeTributacao("Regime de Tributação:"),
     lbl_tipoEmpresa("Tipo de Empresa"),
     frame_top("Cadastro de Empresas"),
     radio_regimeTributacao_sim("Sim"),
     radio_regimeTributacao_nao("Não"),
     btn_gravar("Gravar"),
     btn_sair("Sair")
{
   set_title("I_Empresas");
   set_border_width(10);

   add(frame_top);
   frame_top.add(vbox_top);

   vbox_top.pack_start(vbox_cadastros);
   vbox_top.pack_start(bbox);

   vbox_cadastros.pack_start(lbl_cnpj);
   vbox_cadastros.pack_start(txt_cnpj);
   vbox_cadastros.pack_start(lbl_inscricaoEstadual);
   vbox_cadastros.pack_start(txt_inscricaoEstadual);
   vbox_cadastros.pack_start(lbl_inscricaoMunicipal);
   vbox_cadastros.pack_start(txt_inscricaoMunicipal);
   vbox_cadastros.pack_start(lbl_nomeEmpresa);
   vbox_cadastros.pack_start(txt_nomeEmpresa);
   vbox_cadastros.pack_start(lbl_nomeFantasia);
   vbox_cadastros.pack_start(txt_nomeFantasia);
   vbox_cadastros.pack_start(lbl_endereco);
   vbox_cadastros.pack_start(txt_endereco);
   vbox_cadastros.pack_start(lbl_telefone);
   vbox_cadastros.pack_start(txt_telefone);
   vbox_cadastros.pack_start(lbl_email);
   vbox_cadastros.pack_start(txt_email);
   vbox_cadastros.pack_start(lbl_regimeTributacao);
   vbox_cadastros.pack_start(hbox_regimeTributacao);
   vbox_cadastros.pack_start(lbl_tipoEmpresa);
   vbox_cadastros.pack_start(combo_tipoEmpresa);

   
   hbox_regimeTributacao.pack_start(radio_regimeTributacao_sim);
   hbox_regimeTributacao.pack_start(radio_regimeTributacao_nao);

   bbox.add(btn_gravar);
   bbox.add(btn_sair);
   
   Gtk::RadioButtonGroup rbg_grupo = radio_regimeTributacao_sim.get_group();
   radio_regimeTributacao_nao.set_group(rbg_grupo);

   btn_gravar.signal_clicked().connect(sigc::mem_fun(*this, &I_Empresa::on_btn_gravar_clicked));
   btn_sair.signal_clicked().connect(sigc::mem_fun(*this, &I_Empresa::on_btn_sair_clicked));

   show_all_children();
}

void I_Empresa::on_btn_gravar_clicked(void)
{
   // TODO chamar controladora(G_Empresa) para fazer insercao no BD
   cout << "Gravando dados" << endl;
}

void I_Empresa::on_btn_sair_clicked(void)
{
   this->hide();
}

// TESTE
int main(int argc, char* argv[])
{
   auto app = Gtk::Application::create(argc, argv, "teste");

   I_Empresa telaEmpresa;
   telaEmpresa.set_default_size(750, 800);
   return app->run(telaEmpresa);
}
