#include <shared_memory.h> 
#include "ImpSclFnc.h"
#include "ImpSclA.h"

/*FUNCION PARA IR A BUSCAR EL SEMAFORO*/
int crear_semaforo(int id_tabla)
{
    int ret;
    key_t llave;
    char archivo_llave[255];
    memset(archivo_llave,'\0',sizeof(archivo_llave));
    if(getenv("XPF_CFG"))
    {
        sprintf(archivo_llave,"%s/%s",getenv("XPF_CFG"),"datos_ImpScl.txt");
    }

    printf("archivo_llave  : %s\n " , archivo_llave); 

    id_tabla = id_tabla + 10;
    llave = ftok(archivo_llave,id_tabla);
    if (llave == -1)
    {
        vDTrazasLog(szModulo,"NO CONSIGO CLAVE PARA SEMAFORO" ,LOG03);
        printf("No consigo clave para semaforo : \n");
        exit(0);
    }

    printf("LLAVE : %d\n",llave);
    ret = semget(llave,1,0600);
    if (ret == -1)
    {
        vDTrazasLog(szModulo,"NO CONSIGO ID PARA SEMAFORO" ,LOG04); 
        printf("No consigo Id para Semaforo\n");
    }
    vDTrazasLog(szModulo,"SEMAFORO CREADO" ,LOG04);
    printf("Semaforo Creado\n");
    return ret;
}

int valor_semaforo(int sem_id)
{
    int ret=semctl(sem_id,0,GETVAL,0);
    return ret;
}

int lock(int sem_id)
{
    int ret = 0;
    operaciones[0].sem_num =  0;
    operaciones[0].sem_op  = -1;
    operaciones[0].sem_flg =  0;

    while(ret==0)
    {
        ret=valor_semaforo(sem_id);
        if (ret==1)
        {
            printf("Cambiando a Rojo\n");
            semop(sem_id,operaciones,1);
            return 0;
        }
    }
}

int Unlock(int sem_id)
{
    int ret = 1;
    operaciones[0].sem_num =  0;
    operaciones[0].sem_op  =  1;
    operaciones[0].sem_flg =  0;

    while(ret==1)
    {
        ret=valor_semaforo(sem_id);
        if (ret==0)
        {
            printf("Semaforo en Rojo , cambiando a Verde \n");
            semop(sem_id,operaciones,1);
            return 0;
        }
        else
            if (ret==1)
            {
                printf("Semaforo ya esta en Verde \n");
                return 1;
            }
    }
}

int get_cliente (int sem_id,int total_regs)
{
    int i;
    printf ("TOTAL DE REGISTROS %d\n:" , total_regs);
    lock(sem_id);
    for (i=0; i<total_regs; i++)
    {
        if (st_factclie_mc[i].iestado==0)
        {
            st_factclie_mc[i].iestado = 1 ;
            Unlock(sem_id);
            printf ("Cliente: [%ld] Estado : [%d]\n",st_factclie_mc[i].lCodCliente, st_factclie_mc[i].iestado);
            FacturaCliente_mc = st_factclie_mc[i];
            return i;
        }	
    }
    Unlock(sem_id);
    return -1;
}


int get_registro (int sem_id)
{
    int i;
    lock(sem_id);
    for (i=0; i<1000; i++)
    {
        if (memoria[0].concatenador[i].marcador==0)
        {
            memoria[0].concatenador[i].marcador = 1 ;
            Unlock(sem_id);
            return i;
        }
        if (i==999)
            i=0;
    }
    Unlock(sem_id);
    return -1;
}


int marca_cliente_facturado(int sem_id,int puntero)
{
     lock(sem_id);
     st_factclie_mc[puntero].iestado = 2 ;
     Unlock(sem_id);
     vDTrazasLog(szModulo,"MARCO CLIENTE COMO FACTURADO: [%ld]" ,LOG04, st_factclie_mc[puntero].lCodCliente);
     printf("Marco Cliente Como Facturado\n");
     return 0;
}


void muestra_registro()
{
    printf(" %s" ,FacturaCliente_mc.szRowid);
    printf(" %ld",FacturaCliente_mc.lIndOrdenTotal);
    printf(" %ld",FacturaCliente_mc.lCodCliente);
    printf(" %ld",FacturaCliente_mc.lNum_Folio);
    printf(" %s" ,FacturaCliente_mc.szNumCtc);
    printf(" %s" ,FacturaCliente_mc.szFecEmision);
    printf(" %s" ,FacturaCliente_mc.szFecVencimie);
    printf(" %d" ,FacturaCliente_mc.iCodTipDocum); 
    printf(" %ld",FacturaCliente_mc.lNumProceso);
    printf(" %s" ,FacturaCliente_mc.szCodGenArch);
    printf(" %s" ,FacturaCliente_mc.szNomHeader);
    printf(" %d" ,FacturaCliente_mc.iCodPrioridad);
    printf(" %s" ,FacturaCliente_mc.szCodDespacho);
    printf(" %f" ,FacturaCliente_mc.dTotFactura);
    printf(" %s" ,FacturaCliente_mc.szRut_Cliente);
    printf(" %s" ,FacturaCliente_mc.szNombre_Clie);
    printf(" %s" ,FacturaCliente_mc.szCod_Idioma);
    printf(" %s" ,FacturaCliente_mc.szIndDebito);
    printf(" %s" ,FacturaCliente_mc.szPrefPlaza);
    printf(" %s" ,FacturaCliente_mc.szCodOperadora);
    printf(" %s" ,FacturaCliente_mc.szCodPlaza);
    printf(" %f" ,FacturaCliente_mc.dTotCargosMes);
    printf(" %f" ,FacturaCliente_mc.dImpSaldoAnt);
    printf(" %f" ,FacturaCliente_mc.dTotPagar);
    printf(" %f" ,FacturaCliente_mc.dTotCuotas);
    printf(" %s" ,FacturaCliente_mc.szCod_Oficina);
    printf(" %ld",FacturaCliente_mc.lCodVendedor);
    printf(" %s" ,FacturaCliente_mc.szNomUsuarora);
    printf(" %d" ,FacturaCliente_mc.iCodOperPlaza);
    printf(" %d\n",FacturaCliente_mc.iestado);
}

void muestra_registro_mc()
{
    int i;
    for(i=0 ; i<15 ; i++)
    {
        printf(" %s\n" ,st_factclie_mc[i].szRowid);
        printf(" %ld\n",st_factclie_mc[i].lIndOrdenTotal);
        printf(" %ld\n",st_factclie_mc[i].lCodCliente);
        printf(" %ld\n",st_factclie_mc[i].lNum_Folio);
        printf(" %s\n" ,st_factclie_mc[i].szNumCtc);
        printf(" %s\n" ,st_factclie_mc[i].szFecEmision);
        printf(" %s\n" ,st_factclie_mc[i].szFecVencimie);
        printf(" %d\n" ,st_factclie_mc[i].iCodTipDocum); 
        printf(" %ld\n",st_factclie_mc[i].lNumProceso);
        printf(" %s\n" ,st_factclie_mc[i].szCodGenArch);
        printf(" %s\n" ,st_factclie_mc[i].szNomHeader);
        printf(" %d\n" ,st_factclie_mc[i].iCodPrioridad);
        printf(" %s\n" ,st_factclie_mc[i].szCodDespacho);
        printf(" %f\n" ,st_factclie_mc[i].dTotFactura);
        printf(" %s\n" ,st_factclie_mc[i].szRut_Cliente);
        printf(" %s\n" ,st_factclie_mc[i].szNombre_Clie);
        printf(" %s\n" ,st_factclie_mc[i].szCod_Idioma);
        printf(" %s\n" ,st_factclie_mc[i].szIndDebito);
        printf(" %s\n" ,st_factclie_mc[i].szPrefPlaza); 
        printf(" %s\n" ,st_factclie_mc[i].szCodOperadora);
        printf(" %s\n" ,st_factclie_mc[i].szCodPlaza);
        printf(" %f\n" ,st_factclie_mc[i].dTotCargosMes);
        printf(" %f\n" ,st_factclie_mc[i].dImpSaldoAnt);
        printf(" %f\n" ,st_factclie_mc[i].dTotPagar);
        printf(" %f\n" ,st_factclie_mc[i].dTotCuotas);
        printf(" %s\n" ,st_factclie_mc[i].szCod_Oficina);
        printf(" %ld\n",st_factclie_mc[i].lCodVendedor);
        printf(" %s\n" ,st_factclie_mc[i].szNomUsuarora);
        printf(" %d\n" ,st_factclie_mc[i].iCodOperPlaza);
        printf(" %d\n",st_factclie_mc[i].iestado);
    }
}

int unir_a_memoria(int max,int id_tabla)
{
    key_t Clave;
    int Id_Memoria=0;
    int size = 0 ;
    
   char archivo_llave[255];
   memset(archivo_llave,'\0',sizeof(archivo_llave));
   if(getenv("XPF_CFG"))
   {
       sprintf(archivo_llave,"%s/%s",getenv("XPF_CFG"),"datos_ImpScl.txt");
   }
    printf("archivo_llave  : %s\n " , archivo_llave); 
    printf("FUNCION PARA UNIRSE A MEMORIA COMPARTIDA...\n");
    Clave = ftok (archivo_llave, id_tabla);
    
    if (Clave == -1)
    {
        vDTrazasLog(szModulo,"NO CONSIGO CLAVE PARA MEMORIA COMPARTIDA" ,LOG03);
        printf("No consigo clave para memoria compartida \n");
        return -1;
    } 
    
    printf("CLAVE DE MEMORIA OBTENIDA...%d\n",Clave);

    if (id_tabla==1)
    {
        vDTrazasLog(szModulo,"BUSCANDO IDENTIFICADOR PARA TABLA MEMORIA" ,LOG06);
        printf("Buscando Identificador para Tabla MEMORIA, ");
        size = sizeof(MEMORIA);
        printf("Size %d \n",size);
        Id_Memoria = shmget (Clave, size , 0600 );
    }
    if (id_tabla==2)
    {
        vDTrazasLog(szModulo,"BUSCANDO IDENTIFICADOR PARA TABLA CLIENTE" ,LOG06);
        printf("Buscando Identificador para Tabla CLIENTES, ");
        size = (sizeof(ST_FACTCLIE) * max);
        printf("Size %d \n",size);
        Id_Memoria = shmget (Clave, size , 0600 );
    }
    if (id_tabla==3)
    {
        vDTrazasLog(szModulo,"BUSCANDO IDENTIFICADOR PARA TABLA NUM ORDEN" ,LOG06);
        printf("Buscando Identificador para Tabla NUM ORDEN, ");
        size = (sizeof(NUMORDEN_MC) * max);
        printf("Size %d \n",size);
        Id_Memoria = shmget (Clave, size , 0600 );
    }

    printf("IDENTIFICADOR OBTENIDO  :  %d\n",Id_Memoria);

    if (Id_Memoria==-1)
    {
        printf("\tLLave : %d\n", Clave);
        printf("\tSIZE %d\n",size);
        vDTrazasLog(szModulo,"NO CONSIGO ID PARA MEMORIA COMPARTIDA. Error Nro: [%d]" ,LOG03, errno);
        printf("\tNo consigo Id para memoria compartida. Error Nro: [%d] \n", errno);
        return(-2);
    }


    if (id_tabla==1)
    {
        memoria = (MEMORIA *)shmat (Id_Memoria,(char *)0, 0);
        if (memoria == NULL)
        {
            vDTrazasLog(szModulo,"NO CONSIGO MEMORIA PARA TABLAS ESTATICAS. Error Nro: [%d]" ,LOG03, errno);
            printf("No consigo memoria compartida para tabla MEMORIA. Error Nro: [%d]\n", errno);
            return -3;
        }
    }
    if (id_tabla==2)
    {
        st_factclie_mc = (ST_FACTCLIE *)shmat (Id_Memoria,(char *)0, 0);
        if (st_factclie_mc == NULL)
        {
            vDTrazasLog(szModulo,"NO CONSIGO MEMORIA PARA TABLA CLIENTES. Error Nro: [%d]" ,LOG03, errno);
            printf("No consigo memoria compartida para tabla CLIENTES. Error Nro: [%d]\n", errno);
            return -3;
        }
    }
    if (id_tabla==3)
    {
        numorden = (NUMORDEN_MC *)shmat (Id_Memoria,(char *)0, 0);
        if (numorden == NULL)
        {
            vDTrazasLog(szModulo,"NO CONSIGO MEMORIA PARA TABLA NUMORDEN_MC. Error Nro: [%d]" ,LOG03, errno);
            printf("No consigo memoria compartida para tabla NUMORDEN_MC. Error Nro: [%d]\n", errno);
            return -3;
        }
    }

    printf("IDENTIFICADOR DE MEMORIA : %d\n",Id_Memoria);
    return Id_Memoria;
}


int separacion_de_memoria(int id_tabla)
{
    if(id_tabla==1)
    {
        vDTrazasLog("SEPARACION DE MEMORIA","LIBERANDO TABLA MEMORIA" ,LOG06);
        printf("LIBERANDO TABLA MEMORIA \n");
        shmdt ((char *)memoria);
    }
    if(id_tabla==2)
    {
        vDTrazasLog("SEPARACION DE MEMORIA","LIBERANDO TABLA CLIENTE" ,LOG06);
        printf("LIBERANDO TABLA CLIENTES \n");
        shmdt ((char *)st_factclie_mc);
    }
    return 0;
}

void muestra_parametros()
{
    int i;
    for (i=0; i<memoria[0].st_parametros_reg; i++)
    {
        printf(" %d" ,memoria[0].st_parametros[i].cod_parametros);
        printf(" %s" ,memoria[0].st_parametros[i].des_parametro);
        printf(" %s" ,memoria[0].st_parametros[i].tip_parametro);
        printf(" %d" ,memoria[0].st_parametros[i].val_numerico);
        printf(" %s" ,memoria[0].st_parametros[i].val_caracter);
        printf(" %s" ,memoria[0].st_parametros[i].val_fecha);
        printf(" %d\n",memoria[0].st_parametros[i].val_cantidad);
    }
}

void muestra_parametros_ged()
{
    printf(" %s",  memoria[0].st_parametros_ged.szformato_fecha);
    printf(" %s",  memoria[0].st_parametros_ged.szformato_hora);
    printf(" %s",  memoria[0].st_parametros_ged.szNumDecimal);
    printf(" %s",  memoria[0].st_parametros_ged.szIdiomaOper);
    printf(" %d\n",memoria[0].st_parametros_ged.iCodAbonoCel);
}

void muestra_plan_tarifario()
{
    int i;
    for (i=0; i<memoria[0].plan_tarifario_reg; i++)
    {
        printf(" %s"  ,memoria[0].plan_tarifario[i].szCod_Plantarif);
        printf(" %s"  ,memoria[0].plan_tarifario[i].szDes_Plantarif);
        printf(" %ld" ,memoria[0].plan_tarifario[i].lMinutosPlan);
        printf(" %f"  ,memoria[0].plan_tarifario[i].dValorPlan);
        printf(" %d\n",memoria[0].plan_tarifario[i].iInd_Arrastre);
    }
}

void muestra_oficina_hosts2()
{
    int i;
    for (i=0; i<memoria[0].oficina_hosts2_reg; i++)
    {
        printf(" %s"  ,memoria[0].oficina_hosts2[i].szCodOficina);
        printf(" %s\n",memoria[0].oficina_hosts2[i].szDesOficina);
    }
}

void muestra_vendedor_hosts2()
{
    int i;
    for (i=0; i<memoria[0].vendedor_hosts_reg ; i++)
    {
        printf(" %ld",  memoria[0].vendedor_hosts[i].lCodVendedor);
        printf(" %s\n", memoria[0].vendedor_hosts[i].szNomVendedor);
    }
}

void muestra_tipdoc()
{
    int i;
    for (i=0; i<memoria[0].tipdoc_reg ;i++)
    {
        printf(" %d" ,memoria[0].tipdoc[i].iCodTipDocum);
        printf(" %s\n",memoria[0].tipdoc[i].szDesTipDocum);
    }
}

void muestra_ciclofact()
{
    printf(" %d"    ,memoria[0].st_ciclofact.cod_ciclo);
    printf(" %s"    ,memoria[0].st_ciclofact.fec_desde);
    printf(" %s"    ,memoria[0].st_ciclofact.fec_hasta);
    printf(" %s"    ,memoria[0].st_ciclofact.szFecEmision);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_0);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_1);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_2);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_3);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_4);
    printf(" %s"    ,memoria[0].st_ciclofact.szMesCiclo_5);
    printf(" %d\n"  ,memoria[0].st_ciclofact.iIndTasador);
}

void muestra_operadora_hosts()
{
    int i ;
    for (i=0; i<memoria[0].operadora_hosts_reg ; i++)
    {
        printf(" %s",memoria[0].operadora_hosts[i].szCodOperadora);
        printf(" %ld",memoria[0].operadora_hosts[i].lCodClienteOperadora);
        printf(" %s",memoria[0].operadora_hosts[i].szNomOperadora);
        printf(" %s",memoria[0].operadora_hosts[i].szNumIdenTRib);
        printf(" %s\n",memoria[0].operadora_hosts[i].szDireccion);
    }
}

void muestra_conceptos_tar()
{
    int i;
    for (i=0; i<memoria[0].conceptos_tar_reg ; i++)
    {
        printf(" %d"  ,memoria[0].conceptos_tar[i].iCodConcepto);
        printf(" %d"  ,memoria[0].conceptos_tar[i].iIndTabla);
        printf(" %d\n",memoria[0].conceptos_tar[i].iNumConceptos);
    }
}


void muestra_detalleoper()
{
    int i,x;
    printf(" %s"  ,memoria[0].detalleoper.szWhere_Local);
    printf(" %s"  ,memoria[0].detalleoper.szWhere_Interzona);
    printf(" %s"  ,memoria[0].detalleoper.szWhere_LDI);
    printf(" %s"  ,memoria[0].detalleoper.szWhere_Especiales);
    printf(" %s"  ,memoria[0].detalleoper.szWhere_Especiales_data);
    printf(" %s"  ,memoria[0].detalleoper.szIndFacturado);
    printf(" %s"  ,memoria[0].detalleoper.szServicio);
    printf(" %d"  ,memoria[0].detalleoper.iCodFormulario);
    printf(" %d"  ,memoria[0].detalleoper.iCtesXArchivo);
    printf(" %d"  ,memoria[0].detalleoper.iIndLocal);
    printf(" %d"  ,memoria[0].detalleoper.iIndEspeciales);
    printf(" %d"  ,memoria[0].detalleoper.iIndInterzona);
    printf(" %d"  ,memoria[0].detalleoper.iIndRoaming);
    printf(" %d"  ,memoria[0].detalleoper.iIndCarrier);
    printf(" %d"  ,memoria[0].detalleoper.iIndLDI);
    printf(" %d"  ,memoria[0].detalleoper.iInd_Agrupacion);
    printf(" %d\n" ,memoria[0].detalleoper.iMaxRegImp[0]);  /* registros A */
    printf(" %d\n" ,memoria[0].detalleoper.iMaxRegImp[1]);  /* registros B */
    printf(" %d\n" ,memoria[0].detalleoper.iMaxRegImp[2]);  /* registros D */

    for ( i=0; i < MAX_TIPOS_REGISTROS ; i++ ) /* A, B y D */
    {
	    for ( x=0; x < memoria[0].detalleoper.iMaxRegImp[i] ; x++ )
	    {
	        printf(" %s"    ,memoria[0].detalleoper.szCodRegistro [memoria[0].detalleoper.iMaxRegImp[i]][x]) ;
	        printf(" %s\n"  ,memoria[0].detalleoper.szCodTipDocum [memoria[0].detalleoper.iMaxRegImp[i]][x]);
	    }
	}
}

void muestra_minutoadicional()
{
    int i;
    for (i=0; i<memoria[0].st_minutoadicional_reg ; i++)
    {
        printf(" %s"    ,memoria[0].st_minutoadicional[i].szCodPlan);
        printf(" %s"    ,memoria[0].st_minutoadicional[i].szLlaveMinutoAdicional);
        printf(" %f\n"  ,memoria[0].st_minutoadicional[i].dMtoAdicional);
    }
}

void muestra_parametros_mc()
{
    int i;
    for (i=0; i<memoria[0].st_parametros_reg; i++)
    {
        printf(" %d",  sthFadParametros.cod_parametro[i]);
        printf(" %s\n" ,  sthFadParametros.val_caracter[i]);
    }
}

void trae_valor_fadparametros_mc(int cod_parametro,char * resultado)
{
    int i;
    for (i=0; i<memoria[0].st_parametros_reg; i++)
    {
        if (cod_parametro==sthFadParametros.cod_parametro[i])
        {
            strcpy(resultado,sthFadParametros.val_caracter[i]);
        }
    }
}


int CargaFadParametrosMC()
{
     int i,j;
     int Cant;
     strcpy(szModulo,"CargaFadParametrosMC");
     vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);
     
     Cant = memoria[0].st_parametros_reg;
     vDTrazasLog  (szModulo, "\t**  Cantidad de Parametros a Cargar [%d]",LOG06,Cant);
     j=0;

     for (i=1 ; i < Cant; i++)
     {
          j = memoria[0].st_parametros[Cant-i].cod_parametros;
          sthFadParametros.cod_parametro[j]       = memoria[0].st_parametros[Cant-i].cod_parametros;
          strcpy(sthFadParametros.des_parametro[j], memoria[0].st_parametros[Cant-i].des_parametro);
          strcpy(sthFadParametros.tip_parametro[j], memoria[0].st_parametros[Cant-i].tip_parametro);
          sthFadParametros.val_numerico[j]        = memoria[0].st_parametros[Cant-i].val_numerico;
          strcpy(sthFadParametros.val_caracter[j] , memoria[0].st_parametros[Cant-i].val_caracter);
          strcpy(sthFadParametros.val_fecha[j]    , memoria[0].st_parametros[Cant-i].val_fecha);
          sthFadParametros.val_cantidad[j]        = memoria[0].st_parametros[Cant-i].val_cantidad;
     }
     return (TRUE);
}


int CargaFadParametros_GED_MC()
{
    strcpy(szModulo,"CargaFadParametros_GED_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);

    printf("Entrando a CargaFadParametros_GED_MC\n");
    strncpy(szformato_fecha,memoria[0].st_parametros_ged.szformato_fecha,strlen(memoria[0].st_parametros_ged.szformato_fecha));
    strncpy(szformato_hora, memoria[0].st_parametros_ged.szformato_hora,strlen(memoria[0].st_parametros_ged.szformato_hora));
    strncpy(szNumDecimal,   memoria[0].st_parametros_ged.szNumDecimal,strlen(memoria[0].st_parametros_ged.szNumDecimal));
    strncpy(szhIdiomaOper,  memoria[0].st_parametros_ged.szIdiomaOper,strlen(memoria[0].st_parametros_ged.szIdiomaOper));
    iCodAbonoCel=memoria[0].st_parametros_ged.iCodAbonoCel;

    /* Modificacin Proyecto Ecu-05002 Codigo de Autorizacin.
      Se agregan las lecturas de los campos para leer si aplica el codigo de autorizacion y leer el valor del 
      codigo de autorizacion.
    */        
    strcpy(szAplica_Cod_Autorizacion,memoria[0].st_parametros_ged.sAplica_Cod_Autorizacion);
    
    if (strcmp(szAplica_Cod_Autorizacion,"S") == 0)
    {
        strcpy(stAutorizFolio.szCodAutorizacion,memoria[0].st_parametros_ged.sCod_Autorizacion);
    }
    return (TRUE);
}


int bCargaMascaraOperadora_MC(DETALLEOPER *pst_MascaraOper)
{
    int i,x;

    vDTrazasLog("bCargaMascaraOperadora_MC","\n\t** Entrando a bCargaMascaraOperadora_MC" ,LOG06);

    pst_MascaraOper->iCodFormulario  = memoria[0].detalleoper.iCodFormulario;
    pst_MascaraOper->iCtesXArchivo   = memoria[0].detalleoper.iCtesXArchivo;
    pst_MascaraOper->iIndLocal       = memoria[0].detalleoper.iIndLocal;
    pst_MascaraOper->iIndInterzona   = memoria[0].detalleoper.iIndInterzona;
    pst_MascaraOper->iIndRoaming     = memoria[0].detalleoper.iIndRoaming;
    pst_MascaraOper->iIndCarrier     = memoria[0].detalleoper.iIndCarrier;
    pst_MascaraOper->iIndEspeciales  = memoria[0].detalleoper.iIndEspeciales;
    pst_MascaraOper->iIndLDI         = memoria[0].detalleoper.iIndLDI;
    pst_MascaraOper->iInd_Agrupacion = memoria[0].detalleoper.iInd_Agrupacion;

    strncpy(pst_MascaraOper->szWhere_Local    ,memoria[0].detalleoper.szWhere_Local,strlen(memoria[0].detalleoper.szWhere_Local));
    strncpy(pst_MascaraOper->szWhere_Interzona,memoria[0].detalleoper.szWhere_Interzona,strlen(memoria[0].detalleoper.szWhere_Interzona));
    strncpy(pst_MascaraOper->szWhere_LDI,memoria[0].detalleoper.szWhere_LDI,strlen(memoria[0].detalleoper.szWhere_LDI));
    strncpy(pst_MascaraOper->szWhere_Especiales,memoria[0].detalleoper.szWhere_Especiales,strlen(memoria[0].detalleoper.szWhere_Especiales));
    strncpy(pst_MascaraOper->szWhere_Especiales_data,memoria[0].detalleoper.szWhere_Especiales_data,strlen(memoria[0].detalleoper.szWhere_Especiales_data));
    strncpy(pst_MascaraOper->szServicio,memoria[0].detalleoper.szServicio,strlen(memoria[0].detalleoper.szServicio));
    strncpy(pst_MascaraOper->szIndFacturado,memoria[0].detalleoper.szIndFacturado,strlen(memoria[0].detalleoper.szIndFacturado));

    vDTrazasLog  (szModulo,"\n\t\t MascaraOperadora where:\n"
                           "\n\t\t Locales          [%s]"             
                           "\n\t\t Interzona        [%s]"             
                           "\n\t\t Ldi              [%s]"             
                           "\n\t\t Especiales       [%s]"             
                           "\n\t\t Data             [%s]"             
                           ,LOG04                                     
                           ,pst_MascaraOper->szWhere_Local            
                           ,pst_MascaraOper->szWhere_Interzona        
                           ,pst_MascaraOper->szWhere_LDI              
                           ,pst_MascaraOper->szWhere_Especiales       
                           ,pst_MascaraOper->szWhere_Especiales_data);

    vDTrazasLog  (szModulo,"\n\t\t Cantidad Total de Reagistros de Mascara previamente cargados [%d][%d][%d]:\n"
    						,LOG06,memoria[0].detalleoper.iMaxRegImp[0]
    						,memoria[0].detalleoper.iMaxRegImp [1]
    						,memoria[0].detalleoper.iMaxRegImp [2]);

    for ( i=0; i < MAX_TIPOS_REGISTROS ; i++ ) /* A, B y D */
    {
        pst_MascaraOper->iMaxRegImp[i] = memoria[0].detalleoper.iMaxRegImp[i];
	    for ( x=0; x < pst_MascaraOper->iMaxRegImp[i] ; x++ )
	    {
	        strncpy(pst_MascaraOper->szCodRegistro [i][x],
	        		memoria[0].detalleoper.szCodRegistro[i][x],
	        		strlen(memoria[0].detalleoper.szCodRegistro[i][x]));
	        strncpy(pst_MascaraOper->szCodTipDocum [i][x],
	        		memoria[0].detalleoper.szCodTipDocum[i][x],
	        		strlen(memoria[0].detalleoper.szCodTipDocum[i][x]));
	    }
	}


    return TRUE;
}

int GetCiclFact_MC(ST_CICLOFACT * pstCicFact,long lCodCiclFact)
{
    vDTrazasLog("GetCiclFact_MC","Entrando en GetCiclFact_MC",LOG06);

    printf("Entrando en GetCiclFact_MC\n");
    strcpy (szModulo, "GetCiclFact_MC");
    vDTrazasLog(szModulo,"\t** Entrando en %s"
                         "\t*** Inicio de Ciclo de Facturacion (%ld)***"
                         ,LOG04,szModulo,lCodCiclFact);

    pstCicFact->cod_ciclo = memoria[0].st_ciclofact.cod_ciclo;
    strncpy(pstCicFact->fec_desde,memoria[0].st_ciclofact.fec_desde,strlen(memoria[0].st_ciclofact.fec_desde));
    strncpy(pstCicFact->fec_hasta,memoria[0].st_ciclofact.fec_hasta,strlen(memoria[0].st_ciclofact.fec_hasta));
    strncpy(pstCicFact->szFec_Emision,memoria[0].st_ciclofact.szFecEmision,strlen(memoria[0].st_ciclofact.szFecEmision));
    strncpy(pstCicFact->szMesCiclo_0,memoria[0].st_ciclofact.szMesCiclo_0,strlen(memoria[0].st_ciclofact.szMesCiclo_0));
    strncpy(pstCicFact->szMesCiclo_1,memoria[0].st_ciclofact.szMesCiclo_1,strlen(memoria[0].st_ciclofact.szMesCiclo_1));
    strncpy(pstCicFact->szMesCiclo_2,memoria[0].st_ciclofact.szMesCiclo_2,strlen(memoria[0].st_ciclofact.szMesCiclo_2));
    strncpy(pstCicFact->szMesCiclo_3,memoria[0].st_ciclofact.szMesCiclo_3,strlen(memoria[0].st_ciclofact.szMesCiclo_3));
    strncpy(pstCicFact->szMesCiclo_4,memoria[0].st_ciclofact.szMesCiclo_4,strlen(memoria[0].st_ciclofact.szMesCiclo_4));
    strncpy(pstCicFact->szMesCiclo_5,memoria[0].st_ciclofact.szMesCiclo_5,strlen(memoria[0].st_ciclofact.szMesCiclo_5));
    pstCicFact->iIndTasador=memoria[0].st_ciclofact.iIndTasador;
    strncpy(pstCicFact->szFec_Desde,memoria[0].st_ciclofact.szFec_Desde,strlen(memoria[0].st_ciclofact.szFec_Desde));
    strncpy(pstCicFact->szFec_Hasta,memoria[0].st_ciclofact.szFec_Hasta,strlen(memoria[0].st_ciclofact.szFec_Hasta));
    
    strcpy(szFec_Desde,pstCicFact->szFec_Desde);
    strcpy(szFec_Hasta,pstCicFact->szFec_Hasta);

    vDTrazasLog("GetCiclFact_MC","Saliendo en GetCiclFact_MC",LOG06);
    printf("Saliendo en GetCiclFact_MC\n");
    return(TRUE);
}

int bfnCargaCod_Plantarif_MC (PLAN_TARIFARIO **pstCodPlanTarif, int *iNumCodPlanes)
{
    int  iNumFilas;
    PLAN_TARIFARIO  *pstCodPlanTarifTemp;
    int iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Planes tarifarios ", LOG06);

    *iNumCodPlanes = 0;
    *pstCodPlanTarif = NULL;

    iNumFilas = memoria[0].plan_tarifario_reg;

    *pstCodPlanTarif =(PLAN_TARIFARIO*) realloc(*pstCodPlanTarif,(int)(((*iNumCodPlanes)+iNumFilas)*sizeof(PLAN_TARIFARIO)));

    if (!*pstCodPlanTarif)
    {
        vDTrazasLog (szExeName,"\n\t\t* No se pudo reservar memoria]",LOG03);
        return FALSE;
    }

    pstCodPlanTarifTemp = &(*pstCodPlanTarif)[(*iNumCodPlanes)];
    memset(pstCodPlanTarifTemp, 0, (int)(sizeof(PLAN_TARIFARIO)*iNumFilas));
    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        strcpy( pstCodPlanTarifTemp[iCont].szCod_Plantarif,memoria[0].plan_tarifario[iCont].szCod_Plantarif);
        strcpy( pstCodPlanTarifTemp[iCont].szDes_Plantarif,memoria[0].plan_tarifario[iCont].szDes_Plantarif);
        strcpy( pstCodPlanTarifTemp[iCont].szTip_Plantarif,memoria[0].plan_tarifario[iCont].szTip_Plantarif);
        pstCodPlanTarifTemp[iCont].lMinutosPlan   = memoria[0].plan_tarifario[iCont].lMinutosPlan;
        pstCodPlanTarifTemp[iCont].dValorPlan     = memoria[0].plan_tarifario[iCont].dValorPlan;
        pstCodPlanTarifTemp[iCont].iInd_Arrastre  = memoria[0].plan_tarifario[iCont].iInd_Arrastre;
    }
    (*iNumCodPlanes) += iNumFilas;
    printf("Numero de filas %d\n",iNumFilas);
  
    vDTrazasLog (szExeName,"\n\t\t* Codigos de Planes Tarifarios cargados [%ld]", LOG06, *iNumCodPlanes);

    qsort((void*)*pstCodPlanTarif, *iNumCodPlanes, sizeof(PLAN_TARIFARIO),ifnCmpCod_PlanTarif);
 
    vfnPrintCod_PlanTarif (*pstCodPlanTarif, *iNumCodPlanes);

    return (TRUE);
}


int CargaMinutoAdicional_MC()
{
    int i;
    vDTrazasLog ("CargaMinutoAdicional_MC","Entrando a CargaMinutoAdicional_MC",LOG06);
    printf("Entrando a CargaMinutoAdicional_MC\n");
    strcpy (szModulo, "CargaMinutoAdicional_MC");
    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    for (i=0; i<memoria[0].st_minutoadicional_reg ; i++)
    {
        strncpy(sthMinutoAdicional.szCodPlan[i],memoria[0].st_minutoadicional[i].szCodPlan,strlen(memoria[0].st_minutoadicional[i].szCodPlan));
        strncpy(sthMinutoAdicional.szLlaveMinutoAdicional[i],memoria[0].st_minutoadicional[i].szLlaveMinutoAdicional,strlen(memoria[0].st_minutoadicional[i].szLlaveMinutoAdicional));
        sthMinutoAdicional.dMtoAdicional[i]=memoria[0].st_minutoadicional[i].dMtoAdicional;
    }
    sthMinutoAdicional.iCantidadMinutoAdicional=memoria[0].st_minutoadicional_reg;

     return (TRUE);
}

int bfnCargaOficinas2_MC(OFICINA2 **pstOfici2, int *iNumOficinas)
{
    int  iNumFilas;
    OFICINA2 *pstOficinasTemp;
    int  iCont;

    vDTrazasLog ("bfnCargaOficinas2_MC","\n Entrando a bfnCargaOficinas2_MC",LOG06);
    printf("Entrando en funcion bfnCargaOficinas2_MC\n");

    vDTrazasLog (szExeName,"\n\t* Carga Oficinas MC", LOG06);

    *iNumOficinas = 0;
    *pstOfici2 = NULL;

    iNumFilas = memoria[0].oficina_hosts2_reg;
    *pstOfici2 =(OFICINA2*) realloc(*pstOfici2,(((*iNumOficinas)+iNumFilas)*sizeof(OFICINA2)));

    if (!*pstOfici2)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
        "Error bfnCargaOficinas2", "no se pudo reservar memoria");
        return (FALSE);
    }

    pstOficinasTemp = &(*pstOfici2)[(*iNumOficinas)];
    memset(pstOficinasTemp, 0, sizeof(OFICINA2)*iNumFilas);
    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        strcpy(pstOficinasTemp[iCont].szCodOficina  ,alltrim(memoria[0].oficina_hosts2[iCont].szCodOficina));
        strcpy(pstOficinasTemp[iCont].szDesOficina  ,alltrim(memoria[0].oficina_hosts2[iCont].szDesOficina));
    }
    (*iNumOficinas) += iNumFilas;

    vDTrazasLog (szExeName,"\n\t\t* Oficinas cargadas MC [%ld]", LOG06, *iNumOficinas);

    qsort((void*)*pstOfici2, *iNumOficinas, sizeof(OFICINA2),ifnCmpOficinas);

    vfnPrintOficinas2 (*pstOfici2, *iNumOficinas);

    return (TRUE);
}

int bfnCargaOperadora_MC(OPERADORA **pstOper, int *iNumOperadoras)
{
    int  iNumFilas;
    OPERADORA *pstOperadoraTemp;
    register int  iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Operadoras MC", LOG06);

    *iNumOperadoras = 0;
    *pstOper = NULL;
    
    iNumFilas = memoria[0].operadora_hosts_reg;
    *pstOper =(OPERADORA*) realloc(*pstOper,(((*iNumOperadoras)+iNumFilas)*sizeof(OPERADORA)));

    if (!*pstOper)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                "Error bfnCargaOperadora", "no se pudo reservar memoria");
        return (FALSE);
    }

    pstOperadoraTemp = &(*pstOper)[(*iNumOperadoras)];
    memset(pstOperadoraTemp, 0, sizeof(OPERADORA)*iNumFilas);
    
    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        strcpy(pstOperadoraTemp[iCont].szCodOperadora   ,alltrim(memoria[0].operadora_hosts[iCont].szCodOperadora));
        pstOperadoraTemp[iCont].lCodClienteOperadora    = memoria[0].operadora_hosts[iCont].lCodClienteOperadora;
        strcpy(pstOperadoraTemp[iCont].szNomOperadora   ,alltrim(memoria[0].operadora_hosts[iCont].szNomOperadora));
        strcpy(pstOperadoraTemp[iCont].szNumIdenTRib    ,alltrim(memoria[0].operadora_hosts[iCont].szNumIdenTRib));
        strcpy(pstOperadoraTemp[iCont].szDireccion  , alltrim(memoria[0].operadora_hosts[iCont].szDireccion));
    }
    
    (*iNumOperadoras) += iNumFilas;

    vDTrazasLog (szExeName,"\n\t\t* Operadoras cargadas MC [%ld]", LOG06, *iNumOperadoras);

    qsort((void*)*pstOper, *iNumOperadoras, sizeof(OPERADORA),ifnCmpOperadoras);

    vfnPrintOperadoras (*pstOper, *iNumOperadoras);

    return (TRUE);
}

int bfnCargaTipDocum_MC (TIPDOC **pstTipDoc, int *iNumTipDocs)
{
    int  iNumFilas;
    TIPDOC  *pstTipDocumTemp;
    int iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Tipos de Documentos y sus Descripciones MC", LOG06);

    *iNumTipDocs = 0;
    *pstTipDoc = NULL;

    iNumFilas=memoria[0].tipdoc_reg;
    *pstTipDoc =(TIPDOC*) realloc(*pstTipDoc,(((*iNumTipDocs)+iNumFilas)*sizeof(TIPDOC)));

    if (!*pstTipDoc)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaTipDocum", "no se pudo reservar memoria");
         return FALSE;
    }

    pstTipDocumTemp = &(*pstTipDoc)[(*iNumTipDocs)];
    memset(pstTipDocumTemp, 0, sizeof(TIPDOC)*iNumFilas);
    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        strcpy( pstTipDocumTemp[iCont].szDesTipDocum    ,memoria[0].tipdoc[iCont].szDesTipDocum);
        pstTipDocumTemp[iCont].iCodTipDocum     =  memoria[0].tipdoc[iCont].iCodTipDocum      ;
    }
    (*iNumTipDocs) += iNumFilas;

    vDTrazasLog (szExeName,"\n\t\t* Tipos de documentos cargados [%ld]", LOG06, *iNumTipDocs);

    qsort((void*)*pstTipDoc, *iNumTipDocs, sizeof(TIPDOC),ifnCmpTipDocum);

    vfnPrintTipDocums (*pstTipDoc, *iNumTipDocs);

    return (TRUE);
}


int bfnCargaVendedores_MC(VENDEDOR **pstVendedor, int *iNumVendedores)
{
    int    iNumFilas;
    VENDEDOR    *pstVendedorTemp;
    int iCont;

    strcpy (szModulo, "bfnCargaVendedores_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);     
    vDTrazasLog (szModulo,"\n\t* Carga Codigos de Vendedores y sus Nombres MC", LOG06);


    *iNumVendedores = 0;
    *pstVendedor = NULL;

    iNumFilas=memoria[0].vendedor_hosts_reg;
    printf("NUMERO DE FILAS VENDEDOR :  %d\n",iNumFilas);

    *pstVendedor =(VENDEDOR*) realloc(*pstVendedor,(((*iNumVendedores)+iNumFilas)*sizeof(VENDEDOR)));

    if (!*pstVendedor)
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaVendedores", "no se pudo reservar memoria");
        return FALSE;
    }

    pstVendedorTemp = &(*pstVendedor)[(*iNumVendedores)];
    memset(pstVendedorTemp, 0, sizeof(VENDEDOR)*iNumFilas);
    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        strcpy( pstVendedorTemp[iCont].szNomVendedor    ,memoria[0].vendedor_hosts[iCont].szNomVendedor);
        pstVendedorTemp[iCont].lCodVendedor     =        memoria[0].vendedor_hosts[iCont].lCodVendedor;
    }
    (*iNumVendedores) += iNumFilas;

    vDTrazasLog (szModulo,"\n\t\t* Codigos de Vendedores cargados [%ld]", LOG06, *iNumVendedores);

    qsort((void*)*pstVendedor, *iNumVendedores, sizeof(VENDEDOR),ifnCmpVendedores);

    vfnPrintVendedores(*pstVendedor, *iNumVendedores);

    return (TRUE);
}


int bCargaConceptosTar_MC(CONCEPTOS_TAR *pstConceptos)
{
    int i ;
    
    strcpy (szModulo, "bCargaConceptosTar_MC");
    vDTrazasLog (szModulo,"\n\t* Carga Conceptos de Tarificacion MC", LOG06);

    for(i=0;i < memoria[0].conceptos_tar_reg ; i++)
    {
        pstConceptos->iCodConcepto[i] = memoria[0].conceptos_tar[i].iCodConcepto;
        pstConceptos->iIndTabla   [i] = memoria[0].conceptos_tar[i].iIndTabla;
    }
    pstConceptos->iNumConceptos = memoria[0].conceptos_tar_reg;
    
    return TRUE;

}

int ManejoArchImp_MC(ST_FACTCLIE   *FactDocuClie,
                     LINEACOMANDO  *ParEntrada,
                     ST_INFGENERAL *sthFa_InfGeneral,
                     FILE          **Fd_ArchImp ,
                     char          *szNombreArchivo)
{
    char szCodIdioma[6];

    strcpy (szModulo, "ManejoArchImp_MC");
    vDTrazasLog(szModulo,"\n\t** Entrada en %s"
                         "\n\t->iSecuencial [%i]"
                         "\n\t->szPathDir [%s]"
                         ,LOG04, szModulo, sthFa_InfGeneral->iSecuencial, sthFa_InfGeneral->szPathDir);

    sthFa_InfGeneral->iSecuencial = 1;
    strcpy(szCodIdioma,ParEntrada->szCodIdioma); 
    FillCodIdioma(szCodIdioma);

    sprintf(szNombreArchivo,"%s/ImpScl_%2.2d_%s_%s_%12.12ld.out",sthFa_InfGeneral->szPathDir,FactDocuClie->iCodTipDocum,FactDocuClie->szCodDespacho,FactDocuClie->szCodZona,FactDocuClie->lIndOrdenTotal);
    printf("\tManejoArchImp-> Se crea Archivo [%s]\n",szNombreArchivo);

    if((*Fd_ArchImp = fopen(szNombreArchivo, "w")) == (FILE *)NULL)
    {
        vDTrazasLog(szModulo,"\n\t\tError al abrir archivo-> [%s]\n" ,LOG01,szNombreArchivo);
        vDTrazasError(szModulo,"\n\t\tError al abrir archivo-> [%s]\n" ,LOG01,szNombreArchivo);
        return FALSE;
    }
    return TRUE;
}


BOOL CargaNumOrden_MC(NUMORDEN **pstNumOrden, int *iNumRegs)
{
    int  iNumFilas;
    NUMORDEN *pstNumOrdenTemp;
    register int  iCont;

    strcpy (szModulo, "CargaNumOrden_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);    

    *iNumRegs = 0;
    *pstNumOrden = NULL;

    iNumFilas = memoria[0].iregs_numorden;

    *pstNumOrden =(NUMORDEN*) realloc(*pstNumOrden,(((*iNumRegs)+iNumFilas)*sizeof(NUMORDEN)));

    if (!*pstNumOrden)
    {
        vDTrazasLog (szExeName,"\n\t\t* No se pudo reservar memoria", LOG03);
        return (FALSE);
    }

    pstNumOrdenTemp = &(*pstNumOrden)[(*iNumRegs)];
    memset(pstNumOrdenTemp, 0, sizeof(NUMORDEN)*iNumFilas);

    for (iCont = 0 ; iCont < iNumFilas ; iCont++)
    {
        pstNumOrdenTemp[iCont].iNum_OrdenGr     = numorden[iCont].iNum_OrdenGr;
        pstNumOrdenTemp[iCont].iNum_OrdenSubGr  = numorden[iCont].iNum_OrdenSubGr;
        pstNumOrdenTemp[iCont].iNum_OrdenConc   = numorden[iCont].iNum_OrdenConc;
        pstNumOrdenTemp[iCont].iCodGrupo        = numorden[iCont].iCodGrupo;
        pstNumOrdenTemp[iCont].iCodSubGrupo     = numorden[iCont].iCodSubGrupo;
        pstNumOrdenTemp[iCont].iCodConcepto     = numorden[iCont].iCodConcepto;
        strcpy(pstNumOrdenTemp[iCont].szCodRegistro ,alltrim(numorden[iCont].szCodRegistro));
        pstNumOrdenTemp[iCont].iCodCriterio     = numorden[iCont].iCodCriterio;
        pstNumOrdenTemp[iCont].iTipo_Llamada    = numorden[iCont].iTipo_Llamada;
        pstNumOrdenTemp[iCont].iTipo_SubGrupo   = numorden[iCont].iTipo_SubGrupo;
    }

    (*iNumRegs) += iNumFilas;

    vDTrazasLog (szExeName,"\n\t\t* Numeros de Orden cargados [%ld]", LOG06, *iNumRegs);

    qsort((void*)*pstNumOrden, *iNumRegs, sizeof(NUMORDEN),ifnCmpNumOrden);

    vfnPrintNumOrden (*pstNumOrden, *iNumRegs);

    return (TRUE);
}

int ifnCmpMinPlanes2(const void *cad1,const void *cad2)
{
    int rc;
    return( (rc = strcmp  (((MINPLAN *)cad1)->szCod_Plan,
                           ((MINPLAN *)cad2)->szCod_Plan)) != 0)?rc:
    ( (rc = strcmp  (((MINPLAN *)cad1)->szCod_Thor,
                     ((MINPLAN *)cad2)->szCod_Thor)) != 0)?rc:0;
}/*************************** ifnCmpCod_PlanTarif *****************************/

void vfnPrintMinPlanes2 (MINPLAN *pstMinPlan, int iNumRegs)
{
    int i = 0;
    char *szModulo="vfnPrintMinPlanes";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Minutos Planes [%d]", LOG06, iNumRegs);

        for ( i=0;i<iNumRegs;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Cod Plan    [%s]"
                         "\n\t\t=> [%d]: Cod THor    [%s]"
                         "\n\t\t=> [%d]: Seg Inic    [%ld]"
                         "\n\t\t=> [%d]: Seg Adic    [%ld]"
                         "\n\t\t=> [%d]: Mto Inic    [%f]"
                         "\n\t\t=> [%d]: Mto Adic    [%f]"
                         ,LOG06
                         ,i, pstMinPlan[i].szCod_Plan
                         ,i, pstMinPlan[i].szCod_Thor
                         ,i, pstMinPlan[i].lSeg_Inic
                         ,i, pstMinPlan[i].lSeg_Adic
                         ,i, pstMinPlan[i].dMto_Inic
                         ,i, pstMinPlan[i].dMto_Adic );


        }
    }
}/*************************** vfnPrintMinPlanes *****************************/

BOOL bfnCargaMinutosPlanes_MC(MINPLAN **pstMinPlan, int *iNumRegs)
{
    int i;
    
    *iNumRegs = 0;
    *pstMinPlan = (MINPLAN *)NULL;
    
    MINPLAN *pstMinPlanTemp;
   
    strcpy(szModulo,"bfnCargaMinutosPlanes_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion\n%s - %d\n",LOG03,szModulo,memoria[0].iNumReg_DatDomin);
    i=0;
    while (i < memoria[0].iNumReg_DatDomin)
    {
        /*vDTrazasLog  (szModulo, "Cargado... - [%d]",LOG03,(*iNumRegs));*/
        
        *pstMinPlan =(MINPLAN*) realloc(*pstMinPlan,((*iNumRegs)+ 1 )*sizeof(MINPLAN));
        if (!*pstMinPlan)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaMinutosPlanes", "no se pudo reservar memoria");
            return FALSE;
        }
 
        pstMinPlanTemp = &(*pstMinPlan)[(*iNumRegs)];
        memset(pstMinPlanTemp, 0, (sizeof(MINPLAN)));
		strcpy( pstMinPlanTemp->szCod_Plan , memoria[0].stDat_Domin[i].szCod_Plan);
        strcpy( pstMinPlanTemp->szCod_Thor , memoria[0].stDat_Domin[i].szCod_Thor);
        pstMinPlanTemp->lSeg_Inic          = memoria[0].stDat_Domin[i].lSeg_Inic;
        pstMinPlanTemp->lSeg_Adic          = memoria[0].stDat_Domin[i].lSeg_Adic;
        pstMinPlanTemp->dMto_Inic          = memoria[0].stDat_Domin[i].dMto_Inic;
        pstMinPlanTemp->dMto_Adic          = memoria[0].stDat_Domin[i].dMto_Adic;
        
        i++;
        (*iNumRegs)=i;
        

	}
	vDTrazasLog  (szModulo, "Registros MinutosPlanes Cargados - [%d]",LOG03,(*iNumRegs));
	
	if ( *iNumRegs >0 )
    {
        qsort((void*)*pstMinPlan, *iNumRegs, sizeof(MINPLAN),ifnCmpMinPlanes2);
        vfnPrintMinPlanes2 (*pstMinPlan, *iNumRegs);
    }

    return (TRUE);
}

/*P-COL-05001 FC3  SCL - FACTURACIÔN - GAP IMPRESIÔN (2 Ô 1) 2005/06/24
Se agrega funcion bfnCargaGedPar_MC para rescatar los datos desde la memoria compartida
*/
BOOL bfnCargaGedPar_MC()
{
    strcpy(szModulo,"bfnCargaGedPar_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);

    memset(&stGedParametros,'\0',sizeof(stGedParametros));

    strcpy (stGedParametros.szTolCodLlam     ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_Llam    );
    strcpy (stGedParametros.szTolCodTDir     ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_TDir    );
    strcpy (stGedParametros.szTolCodTHor     ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_THor    );
    strcpy (stGedParametros.szTolCodTHorAlta ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_THor_Alta);
    strcpy (stGedParametros.szTolCodTHorBaja ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_THor_Baja);
    strcpy (stGedParametros.szTolConCliente  ,memoria[0].Parametros_Env.St_Par_Env.szTol_Con_Cliente );
    strcpy (stGedParametros.szTolCodOperador ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_Operador);
    strcpy (stGedParametros.szTolCodTDia     ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_TDia    );
    strcpy (stGedParametros.szTolCodSFran    ,memoria[0].Parametros_Env.St_Par_Env.szTol_Cod_SFran   );

    return (TRUE);
}

/*P-COL-05001 FC3  SCL - FACTURACIÔN - GAP IMPRESIÔN (2 Ô 1) 2005/05/30
Se agrega funcion bfnCargaCodImptoFact_MC para rescatar los datos desde la memoria compartida y dejarlos en una estructura
*/
BOOL bfnCargaCodImptoFact_MC(CODIMPTOSFACT *stImp_Fact)
{
    int i;

    memset(stImp_Fact,0,sizeof(stImp_Fact));

    strcpy(szModulo,"bfnCargaCodImptoFact_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entro en Open Cursor bfnCargaCodImptoFact_MC\n",LOG03);
    i=0;
    while (i < memoria[0].lNumConceptos)
    {
        stImp_Fact->stCodImptosFact =(COD_IMPTOFACT *) realloc(stImp_Fact->stCodImptosFact,(int)((stImp_Fact->iNumReg + 1) * sizeof(COD_IMPTOFACT)));
        stImp_Fact->stCodImptosFact->lCodImptoFact = memoria[0].st_concimptosfact[i].lCodConcepto;
        memset(stImp_Fact,0,sizeof(stImp_Fact) * i);
        i++;
    }

    stImp_Fact->iNumReg = memoria[0].lNumConceptos;
    return(TRUE);
 }


/*P-COL-05001 FC3  SCL - FACTURACIÔN - GAP IMPRESIÔN (2 Ô 1) 2005/06/02
Idem de la funcion anterior, salvo que esta es con categorias*/ 
BOOL bfnCargaCodImptoCateg_MC(CATIMPUESTOS *st_catImpuestos)
{
    int i,j;
    
    strcpy(szModulo,"bfnCargaCodImptoCateg_MC");

    vDTrazasLog(szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);
    vDTrazasLog(szModulo, "\t**  Cantidad de Categorias a Cargar [%ld]",LOG06,memoria[0].lCantCocImpos);
    
    memset(st_catImpuestos,0,sizeof(st_catImpuestos));
    st_catImpuestos->iNumRegs = memoria[0].lCantCocImpos;
    
    st_catImpuestos->stCatImpuesto =(CATIMPUES *) realloc(st_catImpuestos->stCatImpuesto,((st_catImpuestos->iNumRegs) * sizeof(CATIMPUES) ));
    
    if (st_catImpuestos->stCatImpuesto == NULL)
    {
        vDTrazasLog(szModulo, "\t**Error bfnCargaCodImptoCateg, No se pudo reservar memoria",LOG03);
        return FALSE;
    }
    
    memset(st_catImpuestos->stCatImpuesto, 0, (int)( st_catImpuestos->iNumRegs * sizeof(CATIMPUES)));

    for (i=0;i<memoria[0].lCantCocImpos;i++)
    {
        st_catImpuestos->stCatImpuesto[i].lCodConcepto    = memoria[0].stCocImptos[i].lCodConcepto;
        st_catImpuestos->stCatImpuesto[i].iCodCategoria   = memoria[0].stCocImptos[i].iCodCategoria;
        st_catImpuestos->stCatImpuesto[i].dPrcImpuesto    = memoria[0].stCocImptos[i].dPrcImpuesto;
        st_catImpuestos->stCatImpuesto[i].iCodTipImpto    = memoria[0].stCocImptos[i].iCodTipImpto;
        strcpy(st_catImpuestos->stCatImpuesto[i].szFlagImpto,"");
    }
    
    vDTrazasLog(szModulo,"\n\tConjunto de Categorias Impositivas"
                         "\t\tCONCEPTO|CATEGORIA|PORCENTAJE|TIPO IMPUESTO|FLAG",LOG06);
    for (j=0;j<st_catImpuestos->iNumRegs;j++)
    {
        vDTrazasLog(szModulo,"\t\t[%d] %ld|%d|%f|%d|%s|",LOG06,j
                                                        ,st_catImpuestos->stCatImpuesto[j].lCodConcepto 
                                                        ,st_catImpuestos->stCatImpuesto[j].iCodCategoria
                                                        ,st_catImpuestos->stCatImpuesto[j].dPrcImpuesto
                                                        ,st_catImpuestos->stCatImpuesto[j].iCodTipImpto
                                                        ,st_catImpuestos->stCatImpuesto[j].szFlagImpto);
    }
    return(TRUE);
}

/* P-COL-05011 PROCESO IMPRESIÔN - NUEVO GAP ADAPTACIONES A SCL TM Fecha: 04/08/2005
 * Carga datos de operadora en memoria compartida 
 */
BOOL bfnCargaOperadores_MC(CODOPER **pstOper, int *iNumOperadores)
{
    int     iCont;

    strcpy(szModulo,"bfnCargaOperadores_MC");
    vDTrazasLog  (szModulo, "\n\t**  Entrada a la funcion %s",LOG03,szModulo);
    vDTrazasLog  (szModulo, "\t**  Cantidad de Operadoras a Cargar [%ld]",LOG06,memoria[0].lCantOper);
    
    (*iNumOperadores) = (int)memoria[0].lCantOper;
    if ((*iNumOperadores) <= 0)
    {
        vDTrazasLog (szModulo,"\t** No se Cargaron Operadoras", LOG06);
        return(FALSE);
    }
    
    *pstOper =(CODOPER*) realloc(*pstOper,(int)(((*iNumOperadores))*sizeof(CODOPER)));
    
    if (!*pstOper)
    {
        vDTrazasLog (szModulo,"\tError en bfnCargaOperadores, No se pudo reservar memoria",LOG03);
        return FALSE;
    }
    
    memset(*pstOper, 0, (int)((*iNumOperadores)*sizeof(CODOPER)));

    for (iCont = 0 ; iCont < (*iNumOperadores) ; iCont++)
    {
        (*pstOper)[iCont].iCodOperador         = memoria[0].st_CodOper[iCont].iCodOperador;
        strcpy((*pstOper)[iCont].szDesOperador , memoria[0].st_CodOper[iCont].szDesOperador);
    }

    qsort((void*)*pstOper, *iNumOperadores, sizeof(CODOPER),ifnCmpOperadores);

    return(TRUE);
}


/******************************************************************************************/
/** Informacin de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisin                                            : */
/**  %PR% */
/** Autor de la Revisin                                : */
/**  %AUTHOR% */
/** Estado de la Revisin ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creacin de la Revisin                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/
