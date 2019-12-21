import sys
print('================ Seja bem vindo ao Sistema de Cadastro ===========')

lista = []
#  Função para cadastrar.
def Cadastro():
    quantidade = int(input("\nQuantos clientes voce ira cadastrar: "))
    for i in range(quantidade):
        nome = str(input("\nNome: "))
        idade = int(input("Idade: "))
        sexo = str(input("Sexo: "))
        lista.append([nome, idade, sexo])
    Menu()

#  Função para mostrar os clientes cadastrados.
def Mostrar_Dados():
    if len(lista) == 0:
        print('''
+--------------------------------------
- Você não possui clientes cadastrados.
+--------------------------------------''')
        Menu()
    else:
        while True:
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
            Menu()


#  Função para excluir clientes.
def Excluir():
    if len(lista) == 0:
        print('''
+--------------------------------------
- Você não possui clientes cadastrados.
+--------------------------------------''')
    else:
        for x in range(len(lista)):
            print(f'\nCliente: {x}')
            print(f'''+--------------------------------
- Nome:  {lista[x][0]}
- Idade: {lista[x][1]}
- Sexo:  {lista[x][2]}
+--------------------------------''')
        print('=-='*40)
        print('''
+-------------------------------------------
- Escolha o cliente que você que excluir.
- Exemplo: Cliente 0    digite o numero 0
+-------------------------------------------''')
        excluir = int(input('Escolha o cliente: '))
        lista.remove(lista[excluir])
    Menu()


#  Função mostrar o menu de opções.
def Menu():
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
        print('''
+-----------------------------------
- Obrigado por usar nosso sistema :)
+-----------------------------------''')
        sys.exit()
    else:
        print('''
+------------------------------------------
Opss!!! algo deu errado tente novamente.
+------------------------------------------''')
        Menu()

Menu()
