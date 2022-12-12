#include "listasEncadeada.cpp"

void menuPrincipal();
void menuManutencao();
void menuPesquisa();
void pesquisaLinhaPorOrigemDestino(TipoLista *lista);
void pesquisaLinhaPorCodigo(TipoLista *lista);
void insereLinha(TipoLista *lista);
void incluirParada(TipoListaLinha *lista);
void alterarParada(TipoLista *lista);
void eliminarParada(TipoLista *lista);
void eliminarLinha(TipoLista *lista);
    

void cadastraLinhasTeste(TipoListaLinha *lista){
    TipoLinha parada;
    TipoRota linha1, linha2, linha3;

    //Cadastro da Contijo
    linha1.companhia = "CONTIJO";
    linha1.id = "00721";
    criaListaVaziaD(&linha1.cidades);
    //Cadastro das paradas da linha
    parada.id = 1;
    parada.nome = "SJE";
    parada.valor_passagem = 8.0;
    parada.saida = "23:59";
    insereItemUltimoD(&linha1.cidades, parada);

    parada.id = 2;
    parada.nome = "GHS";
    parada.valor_passagem = 17.0;
    parada.saida = "00:30";
    insereItemUltimoD(&linha1.cidades, parada);
    
    parada.id = 3;
    parada.nome = "SMI";
    parada.valor_passagem = 30.5;
    parada.saida = "02:25";
    insereItemUltimoD(&linha1.cidades, parada);

    parada.id = 4;
    parada.nome = "ITA";
    parada.valor_passagem = 10.5;
    parada.saida = "03:05";
    insereItemUltimoD(&linha1.cidades, parada);

    parada.id = 5;
    parada.nome = "BH";
    parada.valor_passagem = 41.0;
    parada.saida = "05:30";
    insereItemUltimoD(&linha1.cidades, parada);

    insereListaUltimo(lista, &linha1);

    //Cadastro da Saritur
    linha2.companhia = "SARITUR";
    linha2.id = "00121";
    criaListaVaziaD(&linha2.cidades);
    //Cadastro das paradas da linha
    parada.id = 1;
    parada.nome = "SJE";
    parada.valor_passagem = 13.0;
    parada.saida = "00:15";
    insereItemUltimoD(&linha2.cidades,parada);

    parada.id = 2;
    parada.nome = "GHS";
    parada.valor_passagem = 19.0;
    parada.saida = "00:50";
    insereItemUltimoD(&linha2.cidades,parada);

    parada.id = 3;
    parada.nome = "ITA";
    parada.valor_passagem = 23.4;
    parada.saida = "04:05";
    insereItemUltimoD(&linha2.cidades,parada);

    parada.id = 4;
    parada.nome = "BH";
    parada.valor_passagem = 17.0;
    parada.saida = "05:30";
    insereItemUltimoD(&linha2.cidades,parada);

    insereListaUltimo(lista, &linha2);


    //Cadastro da Transjoelma
    linha3.companhia = "Transjoelma";
    linha3.id = "00632";
    criaListaVaziaD(&linha3.cidades);
    //Cadastro das paradas da linha
    parada.id = 1;
    parada.nome = "SJE";
    parada.valor_passagem = 7.0;
    parada.saida = "00:15";
    insereItemUltimoD(&linha3.cidades,parada);

    parada.id = 2;
    parada.nome = "GHS";
    parada.valor_passagem = 12.0;
    parada.saida = "00:50";
    insereItemUltimoD(&linha3.cidades,parada);

    parada.id = 3;
    parada.nome = "ITA";
    parada.valor_passagem = 17.4;
    parada.saida = "04:05";
    insereItemUltimoD(&linha3.cidades,parada);

    parada.id = 4;
    parada.nome = "BH";
    parada.valor_passagem = 30.0;
    parada.saida = "05:30";
    insereItemUltimoD(&linha3.cidades,parada);

    insereListaUltimo(lista, &linha3);
    
}
