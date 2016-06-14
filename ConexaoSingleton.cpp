/*Copyright (C) 2016  Alessandra H. Iriguti <alehairi@gmail.com>, Pedro Garozi <pedrohentorres@gmail.com>

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

#include "ConexaoSingleton.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

ConexaoSingleton& ConexaoSingleton::instancia(void)
{
   static ConexaoSingleton instancia;
   return instancia;
}

void ConexaoSingleton::conectar(vector<string> dadosConexao)
{
   conexao.connect(dadosConexao[0].c_str(), dadosConexao[1].c_str(), dadosConexao[2].c_str(), dadosConexao[3].c_str(), dadosConexao[4].stoi());
}

void ConexaoSingleton::executar(string query)
{
   conexao.query().exec(query);
