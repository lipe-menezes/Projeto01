// FILIPE BISPO DA SILVA MENEZES    UC21200457

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<iostream>
#include <locale.h>
#define MAX_LENGTH 500


struct piloto{
	char nome[100];
	int idade, id;
	char sexo;
	char pais[30];
};


struct circuito {
	char cirPista[50];
	char cirPais[50];
	int codigo;
	float cirTamanho;
};

struct melhor_volta {
    int identificacaoP;
    int identificacaoC;
    char nome[100], equipe[50];
    int dia, mes, ano, min, seg, mil;
};

struct rel_VoltaPiloto {
    int Cpiloto, Ccircuito;
    struct melhor_volta melhor;
};

void le_valida_piloto (struct piloto * piloto, struct piloto pilotos_cadastrados[]);
void le_valida_circuito(struct circuito * circuito, int qnt_circuitos);
void consulta_simples(struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos);
void le_valida_melhor_volta(struct rel_VoltaPiloto * relacao, struct melhor_volta * novo, struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos);
void consulta_nome(struct piloto pilotos_cadastrados[], int qnt_pilotos);
void consulta_PilotoXCircuito (struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos);
void consulta_tempo(struct rel_VoltaPiloto relacoes[], int qnt_relacoes);

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
    int resposta, respostaC;
    int qnt_pilotos = 0;
    int qnt_circuitos = 0;
    int qnt_relacoes = 0;
	struct piloto pilotos_cadastrados[MAX_LENGTH];
	struct circuito circuitos_cadastrados[MAX_LENGTH];
	struct rel_VoltaPiloto relacoes[MAX_LENGTH];

    struct piloto p;
    struct piloto * piloto = &p;
    struct circuito c;
    struct circuito * circuito = &c;
    struct rel_VoltaPiloto r;
    struct rel_VoltaPiloto * relacao = &r;
    struct melhor_volta m;
    struct melhor_volta * melhor_volta = &m;


	while (1) {
        do {
        	printf("Seja Bem vindo\n\n");
        	printf("Escolha a opção desejada para prosseguir.\n\n");
            printf("--------MENU--------\n");
            printf("1 - Cadastrar um piloto \n");
            printf("2 - Cadastrar um circuito \n");
            printf("3 - Cadastrar melhor volta \n");
            printf("4 - Puxar relatório \n");
            printf("5 - Encerrar o programa\n");
            printf("\nInforme sua opção: ");
            scanf("%d", &resposta);
        } while(resposta > 5 || resposta < 1);

            switch(resposta){
                case 1:
                    le_valida_piloto(piloto, pilotos_cadastrados);
                    pilotos_cadastrados[qnt_pilotos].idade = piloto->idade;
                    pilotos_cadastrados[qnt_pilotos].id = piloto->id;
                    pilotos_cadastrados[qnt_pilotos].sexo = piloto->sexo;
                    strcpy(pilotos_cadastrados[qnt_pilotos].nome, piloto->nome);
                    strcpy(pilotos_cadastrados[qnt_pilotos].pais, piloto->pais);
                    qnt_pilotos += 1;
                    break;
                case 2:
                    le_valida_circuito(circuito, qnt_circuitos);
                    circuitos_cadastrados[qnt_circuitos].codigo = circuito->codigo;
                    circuitos_cadastrados[qnt_circuitos].cirTamanho = circuito->cirTamanho;
                    strcpy(circuitos_cadastrados[qnt_circuitos].cirPais, circuito->cirPais);
                    strcpy(circuitos_cadastrados[qnt_circuitos].cirPista, circuito->cirPista);
                    qnt_circuitos += 1;
                    break;
                case 3:
                    le_valida_melhor_volta(relacao, melhor_volta, relacoes, qnt_relacoes, pilotos_cadastrados, qnt_pilotos, circuitos_cadastrados, qnt_circuitos);
                    relacoes[qnt_relacoes].Ccircuito = relacao->Ccircuito;
                    relacoes[qnt_relacoes].Cpiloto = relacao->Cpiloto;
                    relacoes[qnt_relacoes].melhor.ano = relacao->melhor.ano;
                    relacoes[qnt_relacoes].melhor.dia = relacao->melhor.dia;
                    relacoes[qnt_relacoes].melhor.mes = relacao->melhor.mes;
                    relacoes[qnt_relacoes].melhor.min = relacao->melhor.min;
                    relacoes[qnt_relacoes].melhor.seg = relacao->melhor.seg;
                    relacoes[qnt_relacoes].melhor.mil = relacao->melhor.mil;
                    strcpy(relacoes[qnt_relacoes].melhor.nome, relacao->melhor.nome);
                    strcpy(relacoes[qnt_relacoes].melhor.equipe, relacao->melhor.equipe);
                    qnt_relacoes += 1;
                    break;
                case 4:
                    system("pause");
                    
                    while (1) {
                        do {
                            printf("--------MENU--------\n");
                            printf("1 - Consulta simples \n");
                            printf("2 - Pesquisar pilotos \n");
                            printf("3 - Consultar circuito X piloto \n");
                            printf("4 - consulta por tempo \n");
                            printf("5 - Voltar \n");
                            printf("Informe sua opção: \n");
                            scanf("%d", &respostaC);
                        } while(respostaC > 5 || respostaC < 1);

                        switch(respostaC) {
                            case 1:
                                consulta_simples(relacoes, qnt_relacoes, pilotos_cadastrados, qnt_pilotos, circuitos_cadastrados, qnt_circuitos);
                                break;
                            case 2:
                                consulta_nome(pilotos_cadastrados, qnt_pilotos);
                                break;
                            case 3:
                                consulta_PilotoXCircuito(relacoes, qnt_relacoes, pilotos_cadastrados, qnt_pilotos, circuitos_cadastrados, qnt_circuitos);
                                break;
                            case 4:
                                consulta_tempo(relacoes, qnt_relacoes);
                                break;
                        }
                        system("cls");
                        if (respostaC == 5) break;
                    }
                    break;

                case 5:
                    return 0;
            }
            system("cls");
	}
}

//função para criar novo piloto
void le_valida_piloto (struct piloto * piloto, struct piloto pilotos_cadastrados[]) {
    system("cls");

    int jaExiste, x;

    do {
        jaExiste = 0;
        printf("\n\nCÓDIGO DE IDENTIFICAÇÃO DO PILOTO: ");
        scanf("%d", &piloto->id);

        for (x = 0; x < MAX_LENGTH; x++) {
            if (pilotos_cadastrados[x].id == piloto->id) {
                printf("\nCÓDIGO JÁ EXISTENTE\n");
                jaExiste = 1;
            }
        }

    } while (piloto->id < 100 || piloto->id > 499 || jaExiste == 1);

    fflush(stdin);

    printf("NOME COMPLETO: ");
    scanf("%[^\n]s", &piloto->nome);
    printf("IDADE: ");
    scanf("%d", &piloto->idade);
    fflush(stdin);

    do {
        printf("SEXO: ");
        scanf("%c", &piloto->sexo);
        fflush(stdin);
    } while (piloto->sexo != 'm' && piloto->sexo != 'f');

    printf("PAÍS DE ORIGEM: ");
    scanf("%[^\n]s", &piloto->pais);
}
//função para validar o codigo sequencial
void le_valida_circuito(struct circuito * circuito, int qnt_circuitos){
    system("pause");

    int x, valida_pais = 0;
    char paises[50][100] = {
        {"Brasil"},
        {"Estados Unidos"},
        {"Canadá"},
        {"Inglaterra"},
        {"França"},
    };

    char string[20];

    circuito->codigo = qnt_circuitos + 1;
    fflush(stdin);
    printf("\nNOME DO CIRCUITO: ");
    scanf("%[^\n]s", &circuito->cirPista);
    fflush(stdin);

    do {
        printf("\nPAÍS DO CIRCUITO: ");
        scanf("%[^\n]s", &circuito->cirPais);
        fflush(stdin);

        for (x = 0; x < 50; x++) {
            if (strcmp(circuito->cirPais, paises[x]) == 0) {
                valida_pais = 1;
            }
        }

        if (valida_pais == 0) 
		printf("\nINVÁLIDO\n PAÍSES DISPONÍVEIS:\nBrasil\nEspanha\nEstados Unidos\nCanadá\nArábia Saudita\nMônaco\nItália\nInglaterra\nFrança\n");

    } while(valida_pais == 0);

    fflush(stdin);
    printf("\nTAMANHO EM KM: ");
    scanf("%f", &circuito->cirTamanho);

}

void le_valida_melhor_volta(struct rel_VoltaPiloto * relacao, struct melhor_volta * novo, struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos) {
    system("cls");

    if (qnt_pilotos == 0) {
        printf("PILOTO NÃO CADASTRADO!\n");
        printf("VOLTANDO AO MENU...\n");
        
        return;
    }

    if (qnt_circuitos == 0) {
        printf("CIRCUITO NÃO CADASTRADO!\n");

        return;
    }

    int x, ok = 0, existe = 0;

    do {
        printf("IDENTIFICACÃO DO PILOTO: ");
        scanf("%d", &novo->identificacaoP);
        fflush(stdin);

        for (x = 0; x < qnt_pilotos; x++) {
            if (pilotos_cadastrados[x].id == novo->identificacaoP) {
                existe = 1;
                strcpy(novo->nome, pilotos_cadastrados[x].nome);
            }
        }

        if (novo->identificacaoP < 0) {
            printf("VOLTANDO PARA O MENU...");
            
            return;
        }
        if (existe == 0) printf("\nPILOTO INVÁLIDO\n");

    } while(existe == 0);

    existe = 0;

    do {
        printf("IDENTIFICACÃO DO CIRCUITO: ");
        scanf("%d", &novo->identificacaoC);
        fflush(stdin);

        for (x = 0; x < qnt_circuitos; x++) {
            if (circuitos_cadastrados[x].codigo == novo->identificacaoC) {
                existe = 1;
            }
        }
        if (novo->identificacaoC < 0) {
            printf("VOLTANDO PARA O MENU...");
            
            return;
        }
        if (existe == 0) printf("\nCIRCUITO INVALIDO\n");
        
    } while(existe == 0);

    fflush(stdin);
    printf("NOME DA EQUIPE: ");
    scanf("%[^\n]s", &novo->equipe);

 
    do {
        printf("DIA: ");
        scanf("%d", &novo->dia);
    } while (novo->dia < 0 || novo->dia > 31);
    do {
        printf("MÊS: ");
        scanf("%d", &novo->mes);
    } while (novo->mes < 0 || novo->mes > 12);

    printf("ANO: ");
    scanf("%d", &novo->ano);

    // TEMPO
    do {
        printf("MINUTOS: ");
        scanf("%d", &novo->min);
    } while(novo->min < 0 || novo->min > 60);

    do {
        printf("SEGUNDOS: ");
        scanf("%d", &novo->seg);
    } while(novo->seg < 0 || novo->seg > 60);

    do {
        printf("MILISSEGUNDOS: ");
        scanf("%d", &novo->mil);
    } while(novo->mil < 0 || novo->mil > 60);

    relacao->Ccircuito = novo->identificacaoC;
    relacao->Cpiloto = novo->identificacaoP;
    relacao->melhor.ano = novo->ano;
    relacao->melhor.dia = novo->dia;
    relacao->melhor.mes = novo->mes;
    relacao->melhor.min = novo->min;
    relacao->melhor.seg = novo->seg;
    relacao->melhor.mil = novo->mil;
    strcpy(relacao->melhor.nome, novo->nome);
    strcpy(relacao->melhor.equipe, novo->equipe);


    if (qnt_relacoes == 0) {
        printf("\nMELHOR VOLTA\n");
        printf("VOLTANDO AO MENU...\n");
        
        return;
    }

    for (x = 0; x < qnt_relacoes; x++) {
        if (relacoes[x].Ccircuito == relacao->Ccircuito && relacoes[x].Cpiloto == relacao->Cpiloto) {
            if (relacoes[x].melhor.dia != relacao->melhor.dia || relacoes[x].melhor.mes != relacao->melhor.mes || relacoes[x].melhor.ano != relacao->melhor.ano) {
                ok = 1;
            }
            else {
                if (relacao->melhor.min < relacoes[x].melhor.min) {
                    ok = 1;
                }
                else if (relacao->melhor.min == relacoes[x].melhor.min) {
                    if (relacao->melhor.seg < relacoes[x].melhor.seg) {
                        ok = 1;
                    }
                }
            }
        }
        else {
            printf("\nMELHOR VOLTA\n");
            printf("VOLTANDO AO MENU...\n");
            
        }

        if (ok == 1) {
            printf("\nMELHOR VOLTA\n");
            printf("VOLTANDO AO MENU...\n");
            
        }

    }
}

void consulta_simples(struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos) {
    int resposta, chave, x;
    int mostrarR = 1, mostrarC = 1, mostrarP = 1;
    char r;

    do {
        system("cls");
        printf("CONSULTAR POR IDENTIFICAÇÃO INDIVIDUAL OU RELATÓRIO COMPLETO? \n");
        printf("1 - IDENTIFICAÇÃO \n");
        printf("2 - RELATÓRIO COMPLETO \n");
        printf("SUA ESCOLHA: ");
        scanf("%d", &resposta);
    } while(resposta != 1 && resposta != 2);

    system("cls");

    if (qnt_pilotos != 0 && resposta == 2) {

        printf("======== PILOTOS ========\n");
        for (x = 0; x < qnt_pilotos; x++) {
            printf("IDENTIFICAÇÃO: %d \n", pilotos_cadastrados[x].id);
            printf("NOME: %s \n", pilotos_cadastrados[x].nome);
            printf("IDADE: %d \n", pilotos_cadastrados[x].idade);
            printf("SEXO: %c \n", pilotos_cadastrados[x].sexo);
            printf("PAÍS: %s \n\n", pilotos_cadastrados[x].pais);
        }
    }

    if (qnt_circuitos != 0 && resposta == 2) {

        printf("======== CIRCUITOS ======== \n");
        for (x = 0; x < qnt_circuitos; x++) {
            printf("IDENTIFICAÇÃO: %d \n", circuitos_cadastrados[x].codigo);
            printf("NOME DA PISTA: %s \n", circuitos_cadastrados[x].cirPista);
            printf("PAÍS: %s \n", circuitos_cadastrados[x].cirPais);
            printf("TAMANHO: %.2f \n\n", circuitos_cadastrados[x].cirTamanho);
        }
    }

    if (qnt_relacoes != 0 && resposta == 2) {

        printf("======== RELACOES ======== \n");
        for (x = 0; x < qnt_relacoes; x++) {
            printf("IDENT. CIRCUITO: %d \n", relacoes[x].Ccircuito);
            printf("IDENT. PILOTO: %d \n", relacoes[x].Cpiloto);
            printf("DATA: %d/%d/%d \n", relacoes[x].melhor.dia, relacoes[x].melhor.mes, relacoes[x].melhor.ano);
            printf("TEMPO: \n  MINUTOS: %d \n  SEGUNDOS: %d \n  MILI: %d \n\n", relacoes[x].melhor.min, relacoes[x].melhor.seg, relacoes[x].melhor.mil);
        }
    }
    
    if (resposta == 1) {
        do {
            system("cls");

            printf("SELECIONE UMA OPÇÃO: \n");
            printf("1 - IDENTIFICAÇÃO DO PILOTO \n");
            printf("2 - IDENTIFICAÇÃO DO CIRCUITO \n");
            printf("3 - Fechar \n");
            printf("Sua escolha: ");
            scanf("%d", &resposta);
        } while(resposta < 1 && resposta > 3);

        switch(resposta) {
            case 1:
                system("cls");
                printf("Codigo do piloto: ");
                scanf("%d", &chave);

                system("cls");

                printf("======== PILOTOS ========\n");
                for (x = 0; x < qnt_pilotos; x++) {
                    if (pilotos_cadastrados[x].id == chave) {
                        printf("IDENTIFICACAO: %d \n", pilotos_cadastrados[x].id);
                        printf("NOME: %s \n", pilotos_cadastrados[x].nome);
                        printf("IDADE: %d \n", pilotos_cadastrados[x].idade);
                        printf("SEXO: %c \n", pilotos_cadastrados[x].sexo);
                        printf("PAÍS: %s \n\n", pilotos_cadastrados[x].pais);
                    }
                }

                break;

            case 2:
                system("cls");
                printf("Codigo do circuito: ");
                scanf("%d", &chave);

                printf("======== CIRCUITOS ======== \n");
                for (x = 0; x < qnt_circuitos; x++) {

                    if (circuitos_cadastrados[x].codigo == chave) {
                        printf("IDENTIFICACAO: %d \n", circuitos_cadastrados[x].codigo);
                        printf("NOME DA PISTA: %s \n", circuitos_cadastrados[x].cirPista);
                        printf("PAIS: %s \n", circuitos_cadastrados[x].cirPais);
                        printf("TAMANHO: %.2f \n\n", circuitos_cadastrados[x].cirTamanho);
                    }
                }
                break;
        }
    }

    fflush(stdin);
    printf("Digite algo para parar: ");
    scanf("%c", &r);
}

void consulta_nome(struct piloto pilotos_cadastrados[], int qnt_pilotos) {
    system("cls");
    fflush(stdin);

    char pesquisa[100], r;
    int x;

    printf("NOME QUE SERA BUSCADO: ");
    scanf("%[^\n]s", &pesquisa);

    if (qnt_pilotos != 0) {
        system("cls");
        printf("======== PILOTOS ========\n");
        for (x = 0; x < qnt_pilotos; x++) {
            if (strcmp(pilotos_cadastrados[x].nome, pesquisa) == 0) {
                printf("IDENTIFICAÇÃO: %d \n", pilotos_cadastrados[x].id);
                printf("NOME: %s \n", pilotos_cadastrados[x].nome);
                printf("IDADE: %d \n", pilotos_cadastrados[x].idade);
                printf("SEXO: %c \n", pilotos_cadastrados[x].sexo);
                printf("PAÍS: %s \n\n", pilotos_cadastrados[x].pais);
            }
        }
    }
    fflush(stdin);
    printf("Digite algo para parar: ");
    scanf("%c", &r);
}

void consulta_PilotoXCircuito (struct rel_VoltaPiloto relacoes[], int qnt_relacoes, struct piloto pilotos_cadastrados[], int qnt_pilotos, struct circuito circuitos_cadastrados[], int qnt_circuitos) {
    system("cls");

    char r;
    int cod, x, y;

    printf("IDENTIFICAÇÃO DO CIRCUITO: ");
    scanf("%d", &cod);

    if (qnt_relacoes != 0) {
        printf("===== PISTA =====\n");

        for (x = 0; x < MAX_LENGTH; x++) {
            if (circuitos_cadastrados[x].codigo == cod) {
                printf("IDENTIFICAÇÃO: %d \n", circuitos_cadastrados[x].codigo);
                printf("NOME DA PISTA: %s \n", circuitos_cadastrados[x].cirPista);
                printf("PAÍS: %s \n", circuitos_cadastrados[x].cirPais);
                printf("TAMANHO: %.2f \n\n", circuitos_cadastrados[x].cirTamanho);
            }
        }

        for (x = 0; x < MAX_LENGTH; x++) {
            if (relacoes[x].Ccircuito == cod) {

                for (y = 0; y < MAX_LENGTH; y++) {
                    if (pilotos_cadastrados[y].id == relacoes[x].Cpiloto) {

                        printf("CODIGO PILOTO: %d \n", pilotos_cadastrados[y].id);
                        printf("DATA: %d/%d/%d \n", relacoes[x].melhor.dia, relacoes[x].melhor.mes, relacoes[x].melhor.ano);
                        printf("TEMPO: \n   min: %d \n   seg: %d \n   mil: %d \n\n", relacoes[x].melhor.min, relacoes[x].melhor.seg, relacoes[x].melhor.mil);
                    }
                }
            }
        }
    }

    else printf("\nNENHUMA VOLTA REGISTRADA! \n");

    fflush(stdin);
    printf("Digite algo para parar: ");
    scanf("%c", &r);
}

void consulta_tempo(struct rel_VoltaPiloto relacoes[], int qnt_relacoes) {
    system("cls");

    int min, seg, mil, x, menor;
    char r;

    if (qnt_relacoes != 0) {
        do {
            printf("MINUTOS: ");
            scanf("%d", &min);
        } while(min < 0 || min > 60);

        do {
            printf("SEGUNDOS: ");
            scanf("%d", &seg);
        } while(seg < 0 || seg > 60);

        do {
            printf("MILISSEGUNDOS: ");
            scanf("%d", &mil);
        } while(mil < 0 || mil > 60);

        for (x = 0; x < MAX_LENGTH; x++) {
            menor = 0;

            if (relacoes[x].melhor.min != 0 && relacoes[x].melhor.seg != 0 && relacoes[x].melhor.mil != 0) {
                if (relacoes[x].melhor.min < min) menor = 1;
                else if (relacoes[x].melhor.min == min) {
                    if (relacoes[x].melhor.seg < seg) menor = 1;
                    else if (relacoes[x].melhor.seg == seg) {
                        if (relacoes[x].melhor.mil < mil) menor = 1;
                    }
                }
            }

            if (menor == 1) {
                printf("======================= \n");
                printf("CODIGO PILOTO: %d \n", relacoes[x].Cpiloto);
                printf("CODIGO DO CIRCUITO: %d \n", relacoes[x].Ccircuito);
                printf("NOME DO PILOTO: %s \n", relacoes[x].melhor.nome);
                printf("NOME DA EQUIPE: %s \n", relacoes[x].melhor.equipe);
                printf("TEMPO: \n   min: %d \n   seg: %d \n   mil: %d \n\n", relacoes[x].melhor.min, relacoes[x].melhor.seg, relacoes[x].melhor.mil);
            }
        }
    }

    else printf("\nNENHUMA VOLTA REGISTRADA! \n");

    fflush(stdin);
    printf("Digite algo para parar: ");
    scanf("%c", &r);
}
