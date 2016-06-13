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

class I_Empresa : public Gtk::Window
{
public:
   I_Empresa(void);
   
private:
   void on_btn_gravar_clicked(void);
   void on_btn_sair_clicked(void);

   Gtk::Frame frame_top;
   Gtk::VBox vbox_top, vbox_cadastros;
   Gtk::HBox hbox_regimeTributacao;
   Gtk::ButtonBox bbox;
   
   Gtk::Label lbl_cnpj, lbl_inscricaoEstadual, lbl_inscricaoMunicipal,
      lbl_nomeEmpresa, lbl_nomeFantasia, lbl_endereco, lbl_telefone,
      lbl_email, lbl_regimeTributacao, lbl_tipoEmpresa;
   Gtk::Entry txt_cnpj, txt_inscricaoEstadual, txt_inscricaoMunicipal,
      txt_nomeEmpresa, txt_nomeFantasia, txt_endereco, txt_telefone,
      txt_email;
   Gtk::RadioButton radio_regimeTributacao_sim, radio_regimeTributacao_nao;
   Gtk::ComboBox combo_tipoEmpresa;
   Gtk::Button btn_gravar, btn_sair;
};

#endif // RIBANCEIRA_I_EMPRESA_HH
