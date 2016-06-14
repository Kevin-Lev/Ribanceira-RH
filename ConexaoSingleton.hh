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

#ifndef RIBANCEIRA_CONEXAOSINGLETON_HH
#define RIBANCEIRA_CONEXAOSINGLETON_HH

#include <vector>
#include <string>

using namespace std;

class ConexaoSingleton
{
public:
   static ConexaoSingleton& instancia(void);
   void executar(string query);
   void conectar(vector<string> dadosConexao);
   int i;
private:
   ConexaoSingleton() {};
   ConexaoSingleton(ConexaoSingleton const&); // Nao implementa para evitar uso indevido
   void operator=(ConexaoSingleton const&); // Nao implementa para evitar uso indevido

   mysqlpp::Connection conexao;
};

#endif //RIBANCEIRA_CONEXAOSINGLETON_HH
