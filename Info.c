#include "assets.h"

void MostraInfo(guitar *member, int *TAM, int flag){
    if(member)
        for(int i = 0; i < *TAM; i++){
            printf("\nTAM: %d\n", *TAM);
            if(!flag)
                printf("\nID: %d\nNome: %s\nValor: %d\u20AC\nPreco dia: %d\u20AC\nEstado: %d", member[i].id, member[i].nome, member[i].pdia, member[i].valor, member[i].state);
            else{
                if(member[i].state == 1)
                    printf("\nID: %d\nNome: %s\nValor: %d\u20AC\nPreco dia: %d\u20AC\n", member[i].id, member[i].nome, member[i].pdia, member[i].valor);
            }
        }   
    getch();
}

void MostraGuitarra(guitar *member){
    printf("\nID: %d\nNome: %s\nValor: %d\u20AC\nPreco dia: %d\u20AC\nEstado: %d\n", member->id, member->nome, member->valor, member->pdia, member->state);
    getch();
}

void GuitarraAluguer(guitar *member){
    printf("\nNome: %s\nValor: %d euros\nPreco dia: %d euros\n", member->nome, member->valor, member->pdia);
    getch();
}

void MostraData(pAlu pointer){

    printf("Data de Inicio: %d/%d/%d\n", pointer->inicio.dia, pointer->inicio.mes, pointer->inicio.ano);
    
    if(pointer->fim.ano == 0){
        printf("\nFim previsto!\n");
        printf("Data de Fim: %d/%d/%d", pointer->fim_m.dia, pointer->fim_m.mes, pointer->fim_m.ano);
        _getch();
        }
    else{
        printf("Data de Fim: %d/%d/%d\n", pointer->fim.dia, pointer->fim.mes, pointer->fim.ano);
        printf("Atraso: %d", diferenca(&pointer->fim_m, &pointer->fim));
        }
}

void HistoricoGuitarra(pCli pointer){
    pAlu aux;
    int ID, iter = 1;

    printf("Introduza ID da Guitarra: ");
    scanf("%d", &ID);

    while(pointer){
        aux = pointer->al;

        if(aux != NULL){
            while(aux != NULL){
                if(ID == aux->guitar->id){
                    printf("\nAluguer Num %d\n", iter);
                    printf("Nome: %s", pointer->nome);
                    MostraGuitarra(aux->guitar);
                    MostraData(aux);
                }
                aux = aux->prox;
            }
        }
        pointer = (pCli) pointer->prox;
    }
    _getch();
}

void InfoCliente(pCli pointer){
    pAlu aux;

    while(pointer){
        printf("\nNome: %s\nNIF: %d\nBanido: %d\n", pointer->nome, pointer->nif, pointer->banido);
        
        aux = pointer->al;
        
        if(aux != NULL){
            while (aux != NULL){
            GuitarraAluguer(aux->guitar);
            printf("Data de Inicio: %d/%d/%d\nData de Fim prevista: %d/%d/%d\n", aux->inicio.dia,
                                                                        aux->inicio.mes, aux->inicio.ano, 
                                                                        aux->fim_m.dia, aux->fim_m.mes, 
                                                                        aux->fim_m.ano);
            getch();
            aux = aux->prox;
            }
        }
        
        pointer = (pCli)pointer->prox;
    }
    getch();
}

void InfoBanidos(pCli pointer){
    pAlu aux;

    while(pointer){
        if(pointer->banido == true){
            printf("Nome: %s\nNIF: %d\n", pointer->nome, pointer->nif);
            switch(pointer->rban){
                case 1:printf("Razao: Atraso!\n");
                break;
                case 2:printf("Razao: Dano do equipamento!\n");
                break;
                default: break;
            }
        }
    }
}

void InfoClienteSolo(pCli pointer, int *NIF){
    pAlu aux;

    while(pointer){
        printf("\nNome: %s\nNIF: %d\nBanido: %d\n", pointer->nome, pointer->nif, pointer->banido);
        
        aux = pointer->al;
        if(aux){
            while (aux != NULL){
            MostraGuitarra(aux->guitar);
            printf("Data de Inicio: %d/%d/%d\nData de Fim: %d/%d/%d\n", aux->inicio.dia,
                                                                        aux->inicio.mes, aux->inicio.ano, 
                                                                        aux->fim.dia, aux->fim.mes, 
                                                                        aux->fim.ano);
            aux = aux->prox;
            }
        }
        
        pointer = (pCli)pointer->prox;
    }
    getch();
}

void ListaAluguer(pCli pointer){
    pAlu aux = NULL;

    while(pointer != NULL){
        if(pointer->al != NULL){
            aux = pointer->al;
      
            while(aux != NULL){
                if(aux->prox == NULL){
                MostraGuitarra(aux->guitar);
                MostraData(aux); 
                }  
                aux = aux->prox;
            }
        }

        pointer = pointer->prox;
    }

    printf("Fim!");
    getch();
}