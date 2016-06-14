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

#ifndef RIBANCEIRA_G_EMPRESA_HH
#define RIBANCEIRA_G_EMPRESA_HH

#include "Empresa.hh"
#include "ConexaoSingleton.hh"

#include <vector>

using namespace std;

class G_Empresa
{
public:
   G_Empresa(const vector<string>& dadosBD, const Empresa& empresa);

   void criarEmpresa(const Empresa& empresa);
   void alterarEmpresa(const Empresa& empresa);
   Empresa selecionarEmpresa(const string& nome);
   bool removerEmpresa(int cnpj);

private:
   ConexaoSingleton& conexao = ConexaoSingleton::instancia();
   Empresa empresa;
};

#endif //RIBANCEIRA_G_EMPRESA_HH
