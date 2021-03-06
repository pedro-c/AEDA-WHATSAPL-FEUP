#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Grupo.h"

/**
* @brief Fun��o que atualiza a data
* ser� usada para a fun��o de getNumMsg3dias()
* @param d Data
*/
void atualData(Data d);

/**
* @brief Classe Utilizador.
* Cada Utilizador tem como unico o seu login e tem que ter como obrigatorio maior de 18 anos.
* A Classe Utilizador permite ter conversas e grupos com aqueles que apenas fazem parte do seu grupo de amigos.
* Esta Classe permite a gestao e a criacao de novos objectos Grupo, Conversa e Mensagens.
*/
class Utilizador
{
private:
  bool visibilidade; /**< membro privado que representa a visibilidade, 1 - publico e 0 - privado */
  string login; /**< membro privado que representa login (unico para cada utilizador que existe) */
  string nome; /**< membro privado que representa o nome */
  string email; /**< membro privado que representa o email */
  int telemovel; /**< membro privado que representa o telemovel */
  Data dataAdesao; /**< membro privado que representa a data de adesao (criacao do utilizador) */
  Data ultimoAcesso; /**< membro privado que representa a data do ultimo acesso */
  int idade; /**< membro privado que representa a idade */
  vector<Utilizador *> amigos; /**< membro privado que representa os amigos*/
  vector<Conversa *> conversas; /**< membro privado que representa as conversas */
  vector<Grupo *> grupos; /**< membro privado que representa os grupos de conversas */
public:
  /**
  * @brief Construtor Utilizador;
  */
  Utilizador();
  /**
  * @brief Destrutor Utilizador;
  */
  ~Utilizador();
  /**
  * @brief Construtor classe Utilizador
  * @param visibilidade do utilizador
  * @param login do utilizador
  * @param nome do utilizador
  * @param email do utilizador
  * @param dataAdesao data de adesao do utilizador
  * @param telemovel do utilizador
  * @param idade do utilizador
  */
  Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao,Data ultimoAcesso, int telemovel, int idade);
  
  /*****************************************************************
  *                             GETS                               *
  *****************************************************************/

  /**
  *@brief Funcao que retorna o nome do Utilizador
  *@return nome
  */
  string getNome() const;
  /**
  *@brief Funcao que retorna o email do Utilizador
  *@return email
  */
  string getEmail() const;
  /**
  *@brief Funcao que retorna o login do Utilizador
  *@return login
  */
  string getLogin() const;
  /**
  *@brief Funcao que retorna o telemovel do Utilizador
  *@return telemovel
  */
  int getTelemovel()const;
  /**
  *@brief Funcao que retorna a idade do Utilizador
  *@return idade
  */
  int getIdade() const;
  /**
  *@brief Funcao que retorna a visibilidade do Utilizador
  *@return visibilidade
  */
  bool getVisibilidade() const;
  /**
  *@brief Funcao que retorna a data de adesao do Utilizador
  *@return dataAdesao
  */
  Data getDataAdesao() const;
  /**
  *@brief Funcao que retorna um vector de Utilizadores que sao os amigos do Utilizador
  *@return amigos
  */
  /**
  *@brief Funcao que retorna a data do ultimo acesso do Utilizador
  *@return ultimoAcesso
  */
  Data getUltimoAcesso() const;

  vector<Utilizador *> getAmigos() const;
  /**
  *@brief Funcao que retorna um apontador para um Utilizador dos amigos com um determinado login
  *@param login login do Utilizador pertencente aos amigo do Utilizador
  *@return Utilizador*
  */
  Utilizador * getAmigo(string login) const;
  /**
  *@brief Funcao que retorna um apontador para um Grupo dos grupos de conversa de indice i
  *@param i posicao nos grupos do utilizador
  *@return Grupo*
  */
  Grupo* getGrupo(int i) const;
  /**
  *@brief Funcao que retorna os grupos do utilizador
  *@return grupos
  */
  vector<Grupo *> getGrupos() const;
  /**
  *@brief Funcao que retorna a conversa na posicao i
  *@param i posicao da conversa
  *@return conversas[i]
  */
  Conversa* getConversa(int i) const;

  /**
  * @brief Funcao que retorna as conversas de um utilizador
  * @return vector<Conversa*>
  */
  vector<Conversa *> getConversas() const;
  /**
  *@brief Funcao que retorna o nome destinatario da Conversa
  *@param c conversa
  *@return string (nome destinatario)
  */
  string getDestinatarioConversa(Conversa *c) const;
  /**
  * @brief Funcao que retorna um vector com os grupos do meu circulo de amigos.
  * Esta funcao retira os grupos repetidos e os grupos que ja incluem o utilizador atual.
  *
  * @return vector<Grupo *> gruposAmigos
  */
  vector<Grupo *> getGruposAmigos() const;
  /**
  * @brief Funcao que retorna o numero de mensagens enviadas durante os ultimos 3 dias
  *
  */
  int getNumMsg3dias() const;

  /*****************************************************************
  *                             SETS                               *
  *****************************************************************/

  /**
  * @brief Funcao que altera o login de um utilizador
  * @param l novo login do utilizador
  */
  void setLogin(string l);
  /**
  * @brief Funcao que altera o nome de um utilizador
  * @param n novo nome do utilizador
  */
  void setNome(string n);
  /**
  * @brief Funcao que altera o email de um utilizador
  * @param e novo email do utilizador
  */
  void setEmail(string e);
  /**
  * @brief Funcao que altera a idade do Utilizador
  * lanca a excep��o IdadeInsuficiente se for < 18
  * @param i nova idade
  */
  void setIdade(int i);
  /**
  * @brief Funcao que altera a visibilidade de um utilizador
  * @param v nova visibilidade do utilizador
  */
  void setVisibilidade(bool v);
  /**
  * @brief Funcao que altera o telemovel de um utilizador
  * @param t novo telemovel do utilizador
  */
  void setTelemovel(int t);
  /**
  * @brief Funcao que altera a data de adesao de um utilizador
  * @param d dia de adesao
  * @param m mes de adesao
  * @param a ano de adesao
  */
  void setData(int d, int m, int a);
  /**
   * @brief Funcao que altera a data de acesso de um utilizador
   * @param d dia do ultimo acesso
   * @param m dia do ultimo acesso
   * @param a dia do ultimo acesso
   */
   void setDataAcesso(int d, int m, int a);

  /*****************************************************************
  *                             ADDS                               *
  *****************************************************************/

  /**
  * @brief Funcao que adiciona um utilizador aos amigos do utilizador
  * @param u utilizador a adicionar
  */
  void addAmigosAux(Utilizador *u);
  /**
  * @brief Funcao que adiciona um utilizador como amigos
  * chama a funcao addAmigosAux para adicionar o utilizador u aos meus amigos
  * e para eu ser adicionado aos amigos de u
  * @param u utilizador a adicionar
  */
  void addAmigo(Utilizador &u);
  /**
  * @brief Funcao que adiciona um grupo aos grupos do utilizador
  * se o grupo nao pertencer aos meus grupos
  * @param g grupo a adicionar
  * @return bool true - adicionado , false - j� existe (n�o adicionado)
  */
  bool addGrupo(Grupo *g);
  /**
  * @brief Funcao que adiciona uma conversa as conversas do utilizador
  * se a conversa j� n�o existir
  * @param c conversa a adicionar
  */
  void addConversa(Conversa *c);

  /**
  * @brief Funcao que adiciona um utilizador u a um grupo g, por iniciativa propria do moderador (sem pedido de adesao)
  * Esta funcao chama a funcao adicionarMembro da classe grupo e coloca no vetor de grupos de u o novo grupo a que foi adicionado.
  *
  * @param u utilizador a adicionar
  * @param g grupo a adicionar
  * @param d data de adicionado
  *
  * @return bool , true - adicionado , false - nao adicionado
  */
  bool adicionaMembro(Utilizador *u, Grupo *g, Data d);

  /*****************************************************************
  *                            REMOVER                             *
  *****************************************************************/

  /**
  *@brief Funcao que retira o utilizador u dos amigos do utilizador
  *@param u utilizador a remover
  */
  void removerAmigoAux(Utilizador *u); //eliminar um amigo
                                       /**
                                       *@brief Funcao que remove u dos meus amigos e eu dos amigos de u
                                       * usando a fun~cao removerAmigoAux
                                       *@param u utilizador a remover
                                       */
  void removerAmigo(Utilizador &u); //remove u dos meus amigos, e remove-me dos amigos de u
                                    /**
                                    * @brief Funcao que remove um utilizador u de um grupo g
                                    * @param u utilizador a remover
                                    * @param g grupo onde u vai ser removeido
                                    * @param diaAtual data em que foi removido
                                    * return bool , true - removido , false - nao removido
                                    */
  bool removerMembro(Utilizador *u, Grupo *g, Data diaAtual);
  /**
  * @brief Funcao que remove a conversa c das conversas do utilizador
  * @param c conversa a remover
  */
  void removerConversa(Conversa *c);

  /*****************************************************************
  *                           IMPRIMIR                             *
  *****************************************************************/

  /**
  *@brief Funcao que imprime no ecra as definicoes do utilizador
  */
  void imprimirDefinicoes() const;
  /**
  *@brief Funcao que imprime no ecra o perfil do utilizador
  * com as informa��es do mesmo dependendo da visibilidade.
  */
  void imprimirUtilizador() const;
  /**
  *@brief Funcao que imprime no ecra os amigos do utilizador
  */
  void imprimirAmigos() const;
  /**
  *@brief Funcao que imprime no ecra os grupos do utilizador
  */
  void imprimirGrupos() const;
  /**
  *@brief Funcao que imprime no ecra as conversas do utilizador
  */
  void imprimirConversas() const;
  /**
  *@brief Funcao que imprime no ecra todos os grupos (n�o repetidos)
  * de todos os amigos do utilizador incluindo os do proprio
  */
  void imprimirGruposAmigos() const;

  /*****************************************************************
  *                         OPERADORES                             *
  *****************************************************************/

  /**
  * @brief overloading do operador == que compara o utilzador e u
  * @param u utilizador com quem se vai comparar
  * @return bool , true - se tiverem o mesmo login
  */
  bool operator==(const Utilizador&u)const;
  /**
  * @brief overloading do operador < que compara o utilzador e u
  * @param u utilizador com quem se vai comparar
  * @return bool , true - se o numero de mensagens enviadas nos ultimos 3 dias pelo utilizador 
  * for maior do que o utilizador u e, em caso de empate, se o numero de grupos a que pertence
  * for maior
  */
  bool operator<(const Utilizador &u) const;
  /**
  * @brief overloading do operador << do utilizador
  * @param out ostream de saida
  * @param u utilizador a imprimir
  * @return out
  */
  friend ostream & operator<<(ostream & out, const Utilizador & u);

  /*****************************************************************
  *                             SAIR                               *
  *****************************************************************/

  /**
  * @brief Funcao que me remove a conversa c das minhas conversas
  * e c das conversas do destinatario da mesma
  * @param c conversa a eliminar
  */
  void sairConversa(Conversa * c);
  /**
  * @brief Funcao que remove o grupo g dos meus grupos
  * @param g grupo a remover
  */
  void sairGrupo(Grupo *g);

  /*****************************************************************
  *                           OUTROS                               *
  *****************************************************************/

  /**
  * @brief Funcao que cria uma conversa com o utilizador u e adiciona-a as conversas
  * de ambos os participantes
  * @param u utilizador que participa na conversa
  * @return retorna a conversa criada
  */
  Conversa *criarConversa(Utilizador *u);
  /**
  * @brief Funcao que adiciona uma mensagem a uma conversa
  * @param sms mensagem a adicionar
  * @param c conversa a que vai ser adicionada a mensagem
  */
  void enviarMensagem(Mensagem *sms, Conversa *c);
  /**
  * @brief Funcao que adiciona um pedido de adesao do utilizador ao grupo g
  * @param g grupo a que o utilizador quer aderir
  */
  void pedirAdesao(Grupo *g);
  /**
  * @brief Funcao que cria um grupo e o adiciona aos grupos do utilizador
  * @param titulo titulo do grupo
  * @param dataAtual data da criacao do grupo
  * @return Grupo * grupo criado
  */
  Grupo *criarGrupo(string titulo, Data dataAtual);
  /**
  * @brief Funcao que envia uma mensagem para um grupo
  * @param sms mensagem que se quer enviar
  * @param g grupo para o qual se quer enviar a mensagem
  */
  void enviarMensagemGrupo(Mensagem *sms, Grupo *g);

  /**
  * @brief Funcao que aceita um utilizador num grupo.
  * O utilizador atual pode aceitar um pedido de adesao de um utilizador a um dado grupo, desde que o utilizador atual seja o moderador do grupo.
  * Chama a classe pedidoAdesao da classe grupo.
  *
  * @param u Utilizador que efetuou o pedido de adesao
  * @param g Grupo ao qual se quer juntar
  * @param d Data em que se juntou ao grupo
  *
  * @return True se bem sucedido ou false se nao.
  */
  bool aceitaMembro(Utilizador *u, Grupo *g, Data d);

  /**
  * @brief Funcao que rejeita um utilizador num grupo.
  * O utilizador atual pode rejeitar um pedido de adesao de um utilizador a um dado grupo, desde que o utilizador atual seja o moderador do grupo.
  * Chama a funcao pedidoAdesao da classe grupo.
  *
  * @param u Utilizador que efetuou o pedido de adesao
  * @param g Grupo ao qual se quer juntar
  * @param d Data em que se tentou juntar ao grupo
  *
  * @return True se bem sucedido ou false se nao.
  */
  bool rejeitaMembro(Utilizador *u, Grupo *g, Data d);

  /**
  * @brief Funcao que bloqueia um utilizador de um grupo.
  * O utilizador atual pode bloquear outro utilizador de um dado grupo, desde que o utilizador atual seja o moderador do grupo.
  * Esta funcao chama a funcao bloquearMembro da classe grupo.
  *
  * @param u Utilizador que vai ser bloqueado
  * @param g Grupo em questao
  * @param diaAtual Data do acontecimento
  *
  * @return True se bem sucedido ou false se nao.
  */
  bool bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);

  /**
  * @brief Funcao que desbloqueia um utilizador de um grupo.
  * O utilizador atual pode desbloquear outro utilizador de um dado grupo, desde que o utilizador atual seja o moderador do grupo.
  * Esta funcao chama a funcao desbloquearMembro da classe grupo.
  *
  * @param u Utilizador que vai ser desbloqueado
  * @param g Grupo em questao
  * @param diaAtual Data do acontecimento
  *
  * @return True se bem sucedido ou false se nao.
  */
  bool desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);

  /**
  * @brief Funcao que retorna o grupo escolhido pelo utilizador.
  * Antes desta fun��o � feito um print dos grupos do circulo de amigos do utilizador com numeros.
  * A partir dai o utilizador escolhe um grupo que � devolvido pela funcao.
  *
  * @param i Posicao no vetor gruposAmigos
  *
  * @return grupo escolhido
  */
  Grupo *escolheGruposAmigos(int i) const;

  /**
  * @ brief Funcao que imprime no ecras as informa��es do utilizador
  * @param linha Posicao no vetor
  * @param novo
  * @ return void
  */
  void escreveUtilizador(string linha, bool novo);

  /**
  * @ brief Funcao que indica se o utilizador est� inativo � mais de 1 mes.
  *
  * @ return booleano
  */
  int inativo() const;
};

#endif /* SRC_UTILIZADOR_H_ */
