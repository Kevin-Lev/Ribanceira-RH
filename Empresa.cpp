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

#include "Empresa.hh"

using namespace std;

TipoEmpresa::TipoEmpresa(void)
{
   if (tipos.size() == 0) {
      // TODO pegar os tipos cadastrados no BD e inserir no vetor
      
   }
}

void TipoEmpresa::adicionarTipo(string tipo)
{
   if (tipos.insert(tipo).second) {
      // TODO inserir tipo no BD
      
   }
}

void TipoEmpresa::removerTipo(string tipo)
{
   int tamanhoAnterior = tipos.size();
   tipos.erase(tipo);
   if (tipos.size() < tamanhoAnterior) {
      // TODO remover item do BD

   }
}


