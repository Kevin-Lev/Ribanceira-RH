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

#include "G_Empresa.hh"

#include <iostream>
#include <sstream>
#include <mysql++/mysql++.h>


G_Empresa::G_Empresa(const vector<string>& dadosBD, const Empresa& empresa)
   : dadosBD(5, "")
{
   this->empresa = empresa;
   conexao.conectar(dadosBD);
}

void G_Empresa::criarEmpresa(const Empresa& empresa)
{
   string delim1("'"), delim2("', ");
   stringstream query("insert into `Empresa` (`cnpj`, `nome_mp`, `nome_fnt`, `insc_esad`, `insc_mun`, `tipo`, `ender_emp`, `fone_emp`, `email_emp`, `regime_trib`) values (");

   query << delim1 << empresa.getCnpj() << delim
	 << delim1 << empresa.getInscricaoEstadual() << delim
	 << delim1 << empresa.getInscricaoMunicipal() << delim
	 << delim1 << empresa.getNomeEmpresa() << delim
	 << delim1 << empresa.getNomeFantasia() << delim
	 << delim1 << empresa.getEndereco() << delim
	 << delim1 << empresa.getTelefone() << delim
	 << delim1 << empresa.getEmail() << delim
	 << delim1 << empresa.getTipoEmpresa() << delim
	 << delim1 << empresa.getRegimeTributacao << "');";

   conexao.executar(query.str());
}

void G_Empresa::setEmpresa(int cnpj, int est, int mun, string nomeE, string nomeF, string end, string tel, string email, string tipo, string regime)
{
   empresa.setCnpj(cnpj);
   empresa.setInscricaoEstadual(est);
   empresa.setInscricaoMunicipal(mun);
   empresa.setNomeEmpresa(nomeE);
   empresa.setNomeFantasia(nomeF);
   empresa.setEndereco(end);
   empresa.setTelefone(tel);
   empresa.setEmail(email);
   empresa.setTipoEmpresa(tipo);
   empresa.setRegimeTributacao(regime);
}

//TESTE
int main(int argc, char* argv[]) 
{
   Empresa empresa;
  
   vector<string> dados(5, "");
   dados[0] = argv[1], dados[1] = argv[2], dados[2] = argv[3], dados[3] = argv[4], dados[4] = argv[5];
   G_Empresa controle(dados, empresa);
   controle.setEmpresa(101, 1000, 9090, "Empresa", "Fantasia", "Elm street", "606060", "empresa@gmail.com", "tipo", "regime");
   controle.criarEmpresa(empresa);
}

   
