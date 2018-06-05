#include "assets.h"

void main()
{
    int op1, op2, NIF;
    int TAM = 0;
    guitar *arr = LeGuitarras(&TAM);
    pCli list = LeClientes(arr, &TAM);

    do
    {
        op1 = display();
        switch (op1)
        {
        case 1:
            op2 = displayGuitarras();
            switch (op2)
            {
            case 1:
                arr = Nova_guitarra(&TAM, arr, true);
                break;
            case 2:
                HistoricoGuitarra(list);
                break;
            case 3:
                MostraInfo(arr, &TAM, false);
                break;
            case 4:
                MostraInfo(arr, &TAM, true);
                break;
            case 5:
                break;
            }
            break;
        case 2:
            op2 = displayClientes();
            switch (op2)
            {
            case 1:
                list = NovoCliente(list);
                break;
            case 2:
                NIF = getNIF();
                list = RemoverCliente(list, &NIF);
                break;
            case 3:
                NIF = getNIF();
                InfoClienteSolo(list, &NIF);
                break;
            case 4:
                InfoCliente(list);
                break;
            case 5:
                break;
            case 7:
                break;
            }
            break;
        case 3:
            op2 = displayAlugueres();
            switch (op2)
            {

            case 1:
                NIF = getNIF();
                NovoAluguer(list, arr, &TAM, &NIF);
                break;
            case 2:
                NIF = getNIF();
                ConcluirAlguer(list, &NIF);
                break;
            case 3:
                ListaAluguer(list);
                break;
            case 4:
                break;
            }
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (op1 != 4);

    GravaGuitarras(arr, &TAM);
    GravaClientes(list);
    freeGuitar(arr);
    freeClientes(list);
}