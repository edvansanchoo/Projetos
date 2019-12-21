import os
import sys


lista = []
#  Função para cadastrar.
def Cadastro():
    # para poder limpar a tela 
    os.system('clear')
    quantidade = int(input("\nQuantos clientes voce ira cadastrar: "))
    # for para contralar a quantidade de clientes que sera cadastrado.
    for i in range(quantidade):
        # para poder limpar a tela
        os.system('clear')
        nome = str(input("\nNome: "))
        idade = int(input("Idade: "))
        sexo = str(input("Sexo: "))
        # adicionando os dados a lista.
        lista.append([nome, idade, sexo])
        print('''
+--------------------------------------
- Cadastro finalizado com sucesso.
+--------------------------------------''')
        # para poder continuar.
        nada = input('\nAperte a tecle ENTER')
    # volta ao menu de opções.
    Menu()

#  Função para mostrar os clientes cadastrados.
def Mostrar_Dados():
    # para limpar a tela
    os.system('clear')
    if len(lista) == 0:
        print('''
+--------------------------------------
- Você não possui clientes cadastrados.
+--------------------------------------''')
        # para poder continuar.
        nada = input('\nAperte a tecle ENTER')
        Menu()
    else:
        # para poder limpar a tela.
        os.system('clear')
        while True:
            # listando os dados dos clientes.
            print('=-='*40)
            print("\nDodos dos usuarios: ")
            for x in range(len(lista)):
                print(f'\nCliente: {x}')
                print(f'''+--------------------------------
- Nome:  {lista[x][0]}
- Idade: {lista[x][1]}
- Sexo:  {lista[x][2]}
+--------------------------------''')
            print('=-='*40)
            # para poder continuar.
            nada = input('\nAperte a tecle ENTER')
            # para voltar ao menu de opções.
            Menu()


#  Função para excluir clientes.
def Excluir():
    # para poder limpar a tela.
    os.system('clear')
    if len(lista) == 0:
        print('''
+--------------------------------------
- Você não possui clientes cadastrados.
+--------------------------------------''')
        # para poder continuar.
        nada = input('\nAperte a tecle ENTER')
    else:
        # para poder limpar a tela.
        os.system('clear')
        # ira listar todos os clientes que foram cadastrados 
        # para que o usuario possa escolher qual ele ira excliuir.
        for x in range(len(lista)):
            print(f'\nCliente: {x}')
            print(f'''+--------------------------------
- Nome:  {lista[x][0]}
- Idade: {lista[x][1]}
- Sexo:  {lista[x][2]}
+--------------------------------''')
        print('=-='*40)
        # explicação de como funciona a parte de excluir.
        print('''
+-------------------------------------------
- Escolha o cliente que você que excluir.
- Exemplo: Cliente 0    digite o numero 0
+-------------------------------------------''')
        excluir = int(input('Escolha o cliente: '))
        #  ira excluir o clente que foi escolhido.
        lista.remove(lista[excluir])
    Menu()


#  Função mostrar o menu de opções.
def Menu():
    # para poder limpar a tela.
    os.system('clear')
    print('\n================ Seja bem vindo ao Sistema de Cadastro ===========\n')
    operacao = int(input('''
Menu:
+-------------------------------
- [1] Cadastro
- [2] Listar clientes
- [3] Excluir
- [4] Sair
+-------------------------------
Operação: '''))
    if operacao == 1:
        Cadastro()
    elif operacao == 2:
        Mostrar_Dados()
    elif operacao == 3:
        Excluir()
    elif operacao == 4:
        os.system('clear')
        print('''
+-----------------------------------
- Obrigado por usar nosso sistema :)
+-----------------------------------''')
        sys.exit()
    else:
        os.system('clear')
        print('''
+------------------------------------------
Opss!!! algo deu errado tente novamente.
+------------------------------------------''')
        Menu()

Menu()
