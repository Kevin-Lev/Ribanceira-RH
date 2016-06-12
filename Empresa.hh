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

#ifndef RIBANCEIRA_EMPRESA_HH
#define RIBANCEIRA_EMPRESA_HH

#include <set>
#include <string>

using namespace std;

class G_Empresa; //forward declaration

class TipoEmpresa
{
   friend class G_Empresa;

public:
   TipoEmpresa(void);
   
   string setTipo(string tipo) { this->tipoEmpresa = tipo; }
   string getTipo(void) { return tipoEmpresa; }
   
private:
   void adicionarTipo(string tipo);
   void removerTipo(string tipo);

   static set<string> tipos;
   string tipoEmpresa;
};



class Empresa
{
   friend class G_Empresa;

public:
   int getCnpj(void) { return cnpj; }
   int getInscricaoEstadual(void) { return inscricaoEstadual; }
   int getInscricaoMunicipal(void) { return inscricaoMunicipal; }
   string getNomeEmpresa(void) { return nomeEmpresa; }
   string getNomeFantasia(void) { return nomeFantasia; }
   string getEndereco(void) { return endereco; }
   string getTelefone(void) { return telefone; }
   string getEmail(void) { return email; }
   bool getRegimeTributacao(void) { return regimeTributacao; }
   string getTipoEmpresa(void) { return tipoEmpresa.getTipo(); }
   
private:
   void setCnpj(int cnpj) { this->cnpj = cnpj; }
   void setInscricaoEstadual(int inscricao) { this->inscricaoEstadual = inscricao; }
   void setInscricaoMunicipal(int inscricao) { this->inscricaoMunicipal = inscricao; }
   void setNomeEmpresa(string nome) { this->nomeEmpresa = nome; }
   void setNomeFantasia(string nome) { this->nomeFantasia = nome; }
   void setEndereco(string endereco) { this->endereco = endereco; }
   void setTelefone(string telefone) { this->telefone = telefone; }
   void setEmail(string email) { this->email = email; }
   void setRegimeTributacao(bool regime) { this->regimeTributacao = regime; }
   void setTipoEmpresa(string tipo) { this->tipoEmpresa.setTipo(tipo); }

   int cnpj;
   int inscricaoEstadual;
   int inscricaoMunicipal;
   string nomeEmpresa;
   string nomeFantasia;
   string endereco;
   string telefone;
   string email;
   bool regimeTributacao;
   TipoEmpresa tipoEmpresa;
};

#endif //RIBANCEIRA_EMPRESA_HH
