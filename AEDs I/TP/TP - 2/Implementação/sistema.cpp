#include "sistema.hpp"

bool carregaArquivo(ListaSequencial *listaSequencial){
    ifstream arquivo;
    arquivo.open(NOME_ARQUIVO, fstream::binary); // Abre o arquivo em modo binario, ou cria se não existir

    if (arquivo.fail()){ // Se falhar
        arquivo.clear(); //Fecha
        return false;
    }

    bool primeiraLinha = true;

    while (arquivo.peek() != ifstream::traits_type::eof()){ // Enquanto o arquivo não for vazio
        if (primeiraLinha){
            arquivo >> codigoPedido;
            primeiraLinha = false;
        }
        else{
            Pedido pedido;
            arquivo.read((char *)&pedido, sizeof(Pedido)); // Lê a Struct dos pedidos
            inserirLista(listaSequencial, pedido);         // Insere o pedido que pegou do arquivo na lista sequencial
        }
    }
    arquivo.clear(); // Fecha após carregado
    return true;
}

bool salvaArquivo(ListaSequencial *listaSequencial){
    ofstream arquivo;
    arquivo.open(NOME_ARQUIVO, ofstream::trunc | fstream::binary); // Abre o arquivo em modo trunc(vazio) e em modo Binário
    
    if (arquivo.fail()){ // Se falhar
        arquivo.clear(); //Fecha
        return false;
    }

    arquivo << codigoPedido;

    for (int i = 0; i < listaSequencial->tamanho; i++){
        Pedido pedido = listaSequencial->pedidos[i];
        arquivo.write((char *)&pedido, sizeof(Pedido));
    }
    return true;
}

void formataDecimal(){
    cout.precision(2);
    cout << fixed;
}

void adicionaCardapio(int codigo, char nome[], double valor){
    int index = codigo - 1; // insere-se n° acima de 0, mas por se tratar de um vetor que inicia em 0, sempre deve-se diminuir 1
    menu[index].codigo = codigo; // codigo = index
    strcpy(menu[index].nome, nome); // copia para o campo nome da struct o que tá no parametro nome, 
    menu[index].valor = valor;
}

void insereProdutos(){  // Cadastra os Produtos no Cardápio/Menu
    adicionaCardapio(1, "Açaí Copo 300ml", 12.50);
    adicionaCardapio(2, "Açaí Copo 500ml", 15.50);
    adicionaCardapio(3, "Açaí Copo 750ml", 18.50);
    adicionaCardapio(4, "Hambúrguer Assado", 8.50);
    adicionaCardapio(5, "Fritas", 6.50);
    adicionaCardapio(6, "Refrigerante 3L", 13.50);
    adicionaCardapio(7, "Coxinha de Frango com catupiry", 4.50);
    adicionaCardapio(8, "Torta de Frango com catupiry", 6.50);
    adicionaCardapio(9, "Pão de Queijo", 2.50);
    adicionaCardapio(10, "Café 200ml", 0.50);
}

void Menu(){
    formataDecimal();
    insereProdutos();
    cout << " *********************************************************************\n";
    cout << " **                       PÁGINA DE PEDIDOS                         **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " **                           DELIVERY                              **\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " **                  1. Incluir pedido                              **\n";
    cout << " **                                                                 **\n";
    cout << " **                  2. Listar pedidos                              **\n";
    cout << " **                                                                 **\n";
    cout << " **                  3. Ver o menu                                  **\n";
    cout << " **                                                                 **\n";
    cout << " **                  4. Consultar pedido                            **\n";
    cout << " **                                                                 **\n";
    cout << " **                  5. Imprimir lista de entregas                  **\n";
    cout << " **                                                                 **\n";
    cout << " **                  6. Lançar entrega                              **\n";
    cout << " **                                                                 **\n";
    cout << " **                  7. Sair                                        **\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << "\n\nOpção: ";
}   

bool verificaCodigoProduto(int codigoProduto){ // Verifica se existe produto com o código
    if (codigoProduto < 1 || codigoProduto > MAX_PRODUTOS_CARDAPIO){
        cout << "Não existe nenhum produto com esse código\n";
        Sleep(1000);
        system("cls");
        return false;
    }
    return true;
}

void incluirPedido(ListaSequencial *listaSequencial){ //1° opção
    if (!VerificaListaCheia(*listaSequencial)){
        Pedido pedido;
        criaItemPedido(&pedido);
        bool incluido = inserirLista(listaSequencial, pedido);
        if (incluido)cout << "Pedido incluido com sucesso\n";
        else cout << "ERRO ao incluir pedido.\n";
    }
    else cout << "Máximo de pedidos atingido\n";
    Sleep(1000);
}

void criaItemPedido(Pedido *pedido){ //criei isso pra alterar o pedido, que seria um objeto criado na função anterior
    pedido->codigo = ++codigoPedido;
    insereProdutos(pedido);//pedido aqui é um ponteiro então posso passar direto
    cout << "Distância para entrega (km): ";
    cin >> pedido->distancia;
    system("cls");
}

void insereProdutos(Pedido *pedido){
    int opcao = 1;
    do{
        if (opcao == 1){
            int codigoProduto;
            verCardapio();
            cout << "\n\nCódigo do produto que deseja adicionar: ";
            cin >> codigoProduto;
            cin.ignore();
            if (verificaCodigoProduto(codigoProduto)){
                pedido->codprodutos[pedido->totalprodutos] = codigoProduto;
                Produto produtoCardapio = menu[codigoProduto - 1];
                cout << produtoCardapio.nome << " adicionado(a) ao Pedido\n";//mensagem de confirmação
                pedido->totalprodutos++; //incremento no total de pedidos
                pedido->valorPedido += produtoCardapio.valor; //adição ao valor do pedido
                Sleep(1000);
                system("cls");
            }
            else{
                cout << "Produto não cadastrado!";
                system("pause");
            }
        }
        if (pedido->totalprodutos < MAX_PRODUTOS){
            cout << "Deseja adicionar outro produto?\n";
            cout << "1 - Sim\n";
            cout << "2 - Não\n";
            cin >> opcao;
            system("cls");
        }
        else{
            cout << "Número máximo de produtos atingido\n";
            Sleep(1000);
            return;
        }
    } while (opcao != 2);
}

void listarPedidos(ListaSequencial listaSequencial){ // 2° opção
    if (!VerificaListaVazia(listaSequencial)){
        imprimeLista(listaSequencial);
        system("pause");
    }
    else cout << "Nenhum pedido cadastrado\n";
    Sleep(1000);
}

void verCardapio(){ // 3° opção
    cout << "Menu:\n";
    for (int i = 0; i < MAX_PRODUTOS_CARDAPIO; i++){
        Produto produto = menu[i];
        cout << "\tCódigo: " << produto.codigo << endl;
        cout << "\tNome: " << produto.nome << endl;
        cout << "\tValor do produto: R$" << produto.valor << endl;
        cout << '\n';
    }
    //system("pause");
}

void consultarPedido(ListaSequencial listaSequencial){
    if (!VerificaListaVazia(listaSequencial)){
        int codigo;
        cout << "Consulta pedido\n";
        cout << "Código do pedido: ";
        cin >> codigo;
        cin.ignore();
        system("cls");
        for (int i = 0; i < TamanhoLista(listaSequencial); i++){
            if (listaSequencial.pedidos[i].codigo == codigo){
                imprimePedido(listaSequencial.pedidos[i]);
                system("pause");
                return;
            }
        }
        cout << "Pedido não encontrado\n";
        Sleep(1000);
    }
    else cout << "Nenhum pedido cadastrado\n";
        Sleep(1000);
}

void listaParaPilha(Pilha *pilha, ListaSequencial listaSequencial){
    InicializaPilha(pilha); // Cria uma pilha para receber os pedidos
    for (int i = 0; i < TamanhoLista(listaSequencial); i++) Empilha(pilha, listaSequencial.pedidos[i]); //pilha e lista possuem pedido, sendo possível a conversão
}

void imprimirListaEntrega(Pilha *pilha, ListaSequencial listaSequencial){ // 5° opção
    if (!VerificaListaVazia(listaSequencial)){
        listaParaPilha(pilha, listaSequencial);
        *pilha = OrdenaPilha(*pilha);
        cout << "Lista de entregas a serem feitas:\n";
        imprimePilha(*pilha);
        system("pause");
    }
    else{
        cout << "Nenhum pedido cadastrado\n";
        Sleep(1000);
    }
}

void lancarEntrega(Pilha *pilha, ListaSequencial *listaSequencial){ // 6° opção
    listaParaPilha(pilha, *listaSequencial);
    *pilha = OrdenaPilha(*pilha);
    Pedido pedido = TopoPilha(*pilha);

    bool entregue = Desempilha(pilha);

    if (entregue){
        ListaRemove(listaSequencial, pedido);
        cout << "Pedido entregue com sucesso\n";
    }
    else cout << "Sem pedidos para entregar\n";
    Sleep(1000);
}