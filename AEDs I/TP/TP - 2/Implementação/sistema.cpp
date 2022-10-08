#include "sistema.hpp"

bool carregaArquivo(ListaSequencial *listaSequencial)
{
    ifstream arquivo;
    arquivo.open(NOME_ARQUIVO, fstream::binary); // Abre o arquivo em modo binario, ou cria se não existir

    if (arquivo.fail()) // Se falhar
    {
        arquivo.clear(); // Fecha o arquivo
        return false;
    }

    bool primeiraLinha = true;

    while (arquivo.peek() != ifstream::traits_type::eof()) // Enquanto o arquivo nao for vazio
    {
        if (primeiraLinha)
        {
            arquivo >> codigoPedidoGlobal;
            primeiraLinha = false;
        }
        else
        {
            Pedido pedido;
            arquivo.read((char *)&pedido, sizeof(Pedido)); // Le a Struct dos pedidos completos
            Lista_Insere(listaSequencial, pedido);         // Insere o pedido que pegou do arquivo na lista encadeada
        }
    }

    arquivo.clear();
    return true;
}

void iniciaProdutos()
{
    adicionaProdutoCardapio(1, "Hamburguer", 12.50);
    adicionaProdutoCardapio(2, "Batata Frita", 15.00);
    adicionaProdutoCardapio(3, "Refrigerante 2L", 8.00);
    adicionaProdutoCardapio(4, "Açaí 500ml", 14.00);
    adicionaProdutoCardapio(5, "Açaí 300ml", 12.00);
}

void adicionaProdutoCardapio(int codigo, char nome[], float valor_produto)
{
    int index = codigo - 1;
    cardapio[index].codigo = codigo;
    strcpy(cardapio[index].nome, nome);
    cardapio[index].valor_produto = valor_produto;
}

void menu()
{
    cout << "#######################################################################################" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 SISTEMA DE DELIVERY                                 #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#######################################################################################" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 1 - Incluir Pedidos                                 #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 2 - Listar Pedidos                                  #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 3 - Ver Cardápio                                    #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 4 - Consultar Pedido                                #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 5 - Imprimir Lista de Entregas                      #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 6 - Lançar Entrega                                  #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#                                 7 - Sair                                            #" << endl;
    cout << "#                                                                                     #" << endl;
    cout << "#######################################################################################" << endl;
}

void incluirPedido(ListaSequencial *listaSequencial)
{
    if (!Lista_Cheia(*listaSequencial))
    {
        Pedido pedido;
        criaPedido(&pedido);
        bool incluido = Lista_Insere(listaSequencial, pedido);
        if (incluido)
        {
            cout << "Pedido incluido com Sucesso" << endl;
        }
        else
        {
            cout << "Falha ao incluir pedido" << endl;
        }
    }
    else
    {
        cout << "Máximo de pedidos atingidos" << endl;
    }
    Sleep(1000);
}

void criaPedido(Pedido *pedido)
{
    pedido->codigo = ++codigoPedidoGlobal;
    insereProdutos(pedido);
    cout << "Distância da entrega (metros): ";
    cin >> pedido->distancia;
    system("cls");
}

void insereProdutos(Pedido *pedido)
{
    int opcao = 1;
    do
    {
        if (opcao == 1)
        {
            int codigoProduto;
            cout << "Código do produto que deseja adicionar: ";
            cin >> codigoProduto;
            cin.ignore();
            if (validaCodigoProduto(codigoProduto))
            {
                pedido->produtos[pedido->total_produtos] = codigoProduto;
                Produto produtoCardapio = cardapio[codigoProduto - 1];
                cout << produtoCardapio.nome << " adicionado(a)" << endl;
                pedido->total_produtos++;
                pedido->valor_pedido += produtoCardapio.valor_produto;
                Sleep(1000);
                system("cls");
            }
            else
            {
                continue; // Pula o resto do código voltando para o início do loop
            }
        }
        if (pedido->total_produtos < MAX_PRODUTOS)
        {
            cout << "Deseja adicionar outro produto?" << endl;
            cout << "1-Sim" << endl;
            cout << "2-Não" << endl;
            cin >> opcao;
            system("cls");
        }
        else
        {
            cout << "Número máximo de produtos em um único pedido atingido" << endl;
            Sleep(1000);
            return; // Sai da função
        }
    } while (opcao != 2);
}

bool validaCodigoProduto(int codigoProduto)
{
    if (codigoProduto < 1 || codigoProduto > NUM_PRODUTOS_CARDAPIO) // Verifica se existe produto com o código
    {
        cout << "Não existem produto com esse código" << endl;
        Sleep(1000);
        system("cls");
        return false;
    }
    return true;
}

void listarPedidos(ListaSequencial listaSequencial)
{
    if (!Lista_Vazia(listaSequencial))
    {
        Lista_Imprime(listaSequencial);
        system("pause");
    }
    else
    {
        cout << "Nenhum Pedido Cadastrado" << endl;
        Sleep(1000);
    }
}

void verCardapio()
{
    cout << "Cardápio:" << endl;
    for (int i = 0; i < NUM_PRODUTOS_CARDAPIO; i++)
    {
        Produto produto = cardapio[i];
        cout << "\tCód. Produto: " << produto.codigo << endl;
        cout << "\tNome: " << produto.nome << endl;
        cout << "\tValor do Produto: " << produto.valor_produto << endl;
        cout << '\n';
    }
    system("pause");
}

void consultarPedido(ListaSequencial listaSequencial)
{
    if (!Lista_Vazia(listaSequencial))
    {
        cout << "Consulta Pedido" << endl;
        cout << "Código do pedido:";
        int codigo;
        cin >> codigo;
        cin.ignore();
        system("cls");
        for (int i = 0; i < Lista_Tamanho(listaSequencial); i++)
        {
            if (listaSequencial.pedidos[i].codigo == codigo)
            {
                imprimePedido(listaSequencial.pedidos[i], true);
                system("pause");
                return;
            }
        }
        cout << "Pedido não encontrado" << endl;
        Sleep(1000);
    }
    else
    {
        cout << "Nenhum Pedido Cadastrado" << endl;
        Sleep(1000);
    }
}

void imprimirListaEntrega(Pilha *pilha, ListaSequencial listaSequencial)
{
    if (!Lista_Vazia(listaSequencial))
    {
        listaParaPilha(pilha, listaSequencial);
        *pilha = Pilha_Ordena(*pilha);

        cout << "Lista de Entrega:\n"
             << endl;
        Pilha_Imprime(*pilha, false);
        system("pause");
    }
    else
    {
        cout << "Nenhum Pedido Cadastrado" << endl;
        Sleep(1000);
    }
}

void listaParaPilha(Pilha *pilha, ListaSequencial listaSequencial)
{
    Pilha_Inicializa(pilha); // Reseta a pilha
    for (int i = 0; i < Lista_Tamanho(listaSequencial); i++)
    {
        Pilha_Empilha(pilha, listaSequencial.pedidos[i]);
    }
}

void lancarEntrega(Pilha *pilha, ListaSequencial *listaSequencial)
{
    listaParaPilha(pilha, *listaSequencial);
    *pilha = Pilha_Ordena(*pilha);
    Pedido pedido = Pilha_Topo(*pilha);

    bool entregue = Pilha_Desempilha(pilha);
    if (entregue)
    {
        Lista_Remove(listaSequencial, pedido);
        cout << "Pedido Entregue com Sucesso" << endl;
    }
    else
    {
        cout << "Sem Pedidos para Entregar" << endl;
    }
    Sleep(1000);
}

bool salvaArquivo(ListaSequencial *listaSequencial)
{
    ofstream arquivo;
    arquivo.open(NOME_ARQUIVO, ofstream::trunc | fstream::binary); // Abre arquivo em modo trunc pra deixa-lo vazio e em modo binario

    if (arquivo.fail())
    {
        arquivo.clear();
        return false;
    }

    arquivo << codigoPedidoGlobal;

    for (int i = 0; i < listaSequencial->tamanho; i++)
    {
        Pedido pedido = listaSequencial->pedidos[i];
        arquivo.write((char *)&pedido, sizeof(Pedido)); // Escreve no arquivo a Struct do pedido completa
    }
    return true;
}