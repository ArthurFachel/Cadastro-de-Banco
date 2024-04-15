  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  #define MAX_USERS 100
  #define MAX_NUMBERS 1


  typedef struct {
      char nome[50];
      int idade;
      char cpf[15];
      int depositos[MAX_NUMBERS];
  } Usuario;

  Usuario usuarios[MAX_USERS];
  int num_usuarios = 0;

  void iniciarCadastro();
  void depositar();
  void visualizareDepositos();
  void comecarContagem();


  int main() {
      int opcao;
           printf("\nComeçando Cadastro:\n\n");
      do {
          
          printf("\nTerminal:\n");
          printf("0 - Sair\n");
          printf("1 - Iniciar cadastro\n");
          printf("2 - Depositar\n");
          printf("3 - Visualizar Depositos\n");
          printf("Escolha uma opção\n: ");
          scanf("%d", &opcao);

          switch (opcao) {
              case 0:
                  printf("Encerrando o programa...\n");
                  break;
              case 1:
                  iniciarCadastro();
                  break;
              case 2:
                  depositar();
                  break;
              case 3:
                  visualizareDepositos();
                  break;


              default:
                  printf("Opção inválida!\n");
          }
      } while (opcao != 0);

      return 0;
  }

  void iniciarCadastro() {
      Usuario novoUsuario;
      printf("Nome: ");
      scanf("%s", novoUsuario.nome);
      printf("Idade: ");
      scanf("%d", &novoUsuario.idade);
      printf("CPF: ");
      scanf("%s", novoUsuario.cpf);

      usuarios[num_usuarios++] = novoUsuario;
  }

  void depositar() {
      char cpf[15];
      printf("Informe seu CPF: ");
      scanf("%s", cpf);

      int usuarioEncontrado = 0;
      for (int i = 0; i < num_usuarios; i++) {
          if (strcmp(usuarios[i].cpf, cpf) == 0) {
              usuarioEncontrado = 1;
              printf("Deposite o numero\n");

                  for (int j = 0; j < MAX_NUMBERS; j++) {
                      scanf("%d", &usuarios[i].depositos[j]);
                  }
              }  
      } 
      if (!usuarioEncontrado) {
          printf("CPF não encontrado.\n");
      }
  }

  void visualizareDepositos() {
      if (num_usuarios == 0) {
          printf("Nenhum usuário cadastrado ainda.\n");
          return;
      }
      for (int i = 0; i < num_usuarios - 1; i++) {
          for (int j = i + 1; j < num_usuarios; j++) {
              if (strcmp(usuarios[i].nome, usuarios[j].nome) > 0) {
                  Usuario temp = usuarios[i];
                  usuarios[i] = usuarios[j];
                  usuarios[j] = temp;
              }
          }
      }
      printf("Usuários e seus depositos:\n");
      for (int i = 0; i < num_usuarios; i++) {
          printf("Nome: %s, Idade: %d, CPF: %s, Deposito: $", usuarios[i].nome, usuarios[i].idade, usuarios[i].cpf);
          for (int j = 0; j < MAX_NUMBERS; j++) {
              printf("%d ", usuarios[i].depositos[j]);
          }
          printf("\n");
      }
  }

