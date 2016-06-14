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
#include <cstdlib>
#include <mysql++/mysql++.h>


G_Empresa::G_Empresa(const vector<string>& dadosBD)
   : dadosBD(5, "")
{
   this->dadosBD = dadosBD;
}

void G_Empresa::criarEmpresa(const Empresa& empresa)
{
   mysqlpp::Connection conexao(dadosBD[0].c_str(), dadosBD[1].c_str(), dadosBD[2].c_str(),
			       dadosBD[3].c_str(), atoi(dadosBD[4].c_str()));
   cout << conexao.query("CREATE TABLE Empresa ( cnpj integer primary key, nome_empresa varchar(50));").exec() << endl;
}

//TESTE
int main(int argc, char* argv[])
{
   Empresa empresa;
   vector<string> dados(5, "");
   dados[0] = argv[1], dados[1] = argv[2], dados[2] = argv[3], dados[3] = argv[4], dados[4] = argv[5];
   G_Empresa controle(dados);
   controle.criarEmpresa(empresa);
}

   
