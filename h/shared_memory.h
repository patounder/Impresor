#ifndef _shared_memory_
#define _shared_memory_

#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/shm.h>

#include <ImpSclSt.h>


#define MAX_COD_CONCEPTOS                 20

/*Definicion de MAX nuevos para estructuras de carga en memoria*/
#define MAX_PLTARIF     1000
#define MAX_OFHOST      1000
#define MAX_VENHOST     100000
#define MAX_TIPDOC      100
#define MAX_OPERHOST    100
#define MAX_TIPOS_LD    10 

struct sembuf operaciones[1];

typedef struct{
    int  cod_parametros ;
    char des_parametro[1024];
    char tip_parametro[32];
    int  val_numerico;
    char val_caracter[512];
    char val_fecha[9];
    int  val_cantidad;
}ST_PARAMETROS_M;


typedef struct{
    char szformato_fecha[22];
    char szformato_hora[9];
    char szNumDecimal[21];
    char szIdiomaOper[6];
    int  iCodAbonoCel;
    char sAplica_Cod_Autorizacion[2];
    char sCod_Autorizacion[10];
    char szFecVencimiento[10];
}ST_PARAMETROS_GED_M;


typedef struct{
    char   szCod_Plantarif[4];
    char   szDes_Plantarif[31];
    char   szTip_Plantarif[2];
    long   lMinutosPlan;
    double dValorPlan;
    int    iInd_Arrastre;
}PLAN_TARIFARIO_M;


typedef struct{
    char szCodOficina[3];
    char szDesOficina[41];
}OFICINA_HOSTS2_M;

typedef struct{
    long lCodVendedor;
    char szNomVendedor[41];
}VENDEDOR_HOSTS_M;

typedef struct{
    int  iCodTipDocum;
    char szDesTipDocum[41];
}TIPDOC_M;

typedef struct{
    int  cod_ciclo;
    char fec_desde[9];
    char fec_hasta[9];
    char szFecEmision[9];
    char szMesCiclo_0[7];
    char szMesCiclo_1[7];
    char szMesCiclo_2[7];
    char szMesCiclo_3[7];
    char szMesCiclo_4[7];
    char szMesCiclo_5[7];
    int  iIndTasador;
    char szFec_Desde[9];
    char szFec_Hasta[9];    
}ST_CICLOFACT_M;

typedef struct{
    char szCodOperadora [6];
    long lCodClienteOperadora;
    char szNomOperadora[51];
    char szNumIdenTRib[21];
    char szDireccion[301];
}OPERADORA_HOSTS_M;

typedef struct{
    int iCodConcepto;
    int iIndTabla;
    int iNumConceptos;
}CONCEPTOS_TAR_M;


typedef struct{
    int   iCodFormulario;
    int   iCtesXArchivo;
    char  szIndFacturado[2];
    int   iIndLocal;
    int   iIndInterzona;
    int   iIndRoaming;
    int   iIndCarrier;
    int   iIndEspeciales;
    int   iIndLDI;
    char  szWhere_Local[513];
    char  szWhere_Interzona[513];
    char  szWhere_LDI[513];
    char  szWhere_Especiales[513];
    char  szWhere_Especiales_data[513];
    char  szServicio[3+1];
    int   iInd_Agrupacion;
    char  szCodRegistro   [MAX_TIPOS_REGISTROS][MAX_REGISTROS_POR_TIPOS][6]; /* N° tipo + max registros  */
    char  szCodTipDocum   [MAX_TIPOS_REGISTROS][MAX_REGISTROS_POR_TIPOS][6]; /* N° tipo + max registros  */
    int   iMaxRegImp      [MAX_TIPOS_REGISTROS];                         /* N° tipo max   */
}DETALLEOPER_M;


typedef  struct{
    char   szCodPlan              [6];
    char   szLlaveMinutoAdicional [7];
    double dMtoAdicional             ;
}ST_MINUTOADICIONAL_M;

typedef struct {
    char   szUser          [50];
    char   szPass          [50];
    char   szUsuaOra       [50];
    char   szDirLogs     [1024];
    char   szDirDats     [1024];
    char   szFDetLlam    [1024];
    char   szFormato      [255];
    long   lCodCiclFact        ;
    long   lNumProceso         ;
    double dValDolar           ;
    int    iNivLog             ;
    int    szFecEmision    [20];
    int    szFecDesdeLlam  [20];
    int    szFecHastaLlam  [20];
    char   szCodIdioma      [6];
    int    iCodTipDocum        ;
    char   szCodDespacho    [6];
    int    iReproceso          ;
    long   cod_clienteinic     ;
    long   cod_clientefina     ;
    long   lProceso            ;
    long   lNum_SecuInfo       ;
    char   szFecIngBegin    [9];
    char   szFecIngEnd      [9];
    int    iTipoCiclo          ;
    int    iCodSalida          ;
    int    iCodEntrada         ;
    char    szHostId        [21];
}LINEACOMANDO_M;

typedef struct{
    int  itip_docum;
    char szcod_despacho[6];
    char szpath[512];
}DIRECTORIO;

typedef struct{
    char szupdate[1024];
    char sznomarchivo[512];
    int  itipdocum;
    char szCod_Despacho[6];
    char szCod_Zona[16];
    int  marcador;
    int  bueno;
}CONCATENADOR;

typedef struct{
    long lCodConcepto;
}ST_CONCIMPTOFACT_MC;

typedef struct{
    long   lCodConcepto;
    int    iCodCategoria;
    double dPrcImpuesto;
    char   szFlagImpto[2];
    int    iCodTipImpto;
}CATIMPUES_M;

typedef struct
{
   char szTol_Cod_Llam[21];
   char szTol_Cod_TDir[21];
   char szTol_Cod_THor[21];
   char szTol_Cod_THor_Alta[21];
   char szTol_Cod_THor_Baja[21];
   char szTol_Con_Cliente[21];
   char szTol_Cod_Operador[21];
   char szTol_Cod_TDia[21];
   char szTol_Cod_SFran[21];
}ST_GEDPARAMETROS_ENV;

typedef struct
{
   int iNumReg;
   ST_GEDPARAMETROS_ENV St_Par_Env;
}ST_PARAM_ENV;


typedef struct{
    int                  st_parametros_reg;
    ST_PARAMETROS_M      st_parametros[MAX_FAD_PARAMETROS];
    int                  st_parametros_ged_reg;
    ST_PARAMETROS_GED_M  st_parametros_ged;
    int                  plan_tarifario_reg;
    PLAN_TARIFARIO_M     plan_tarifario[MAX_PLTARIF];
    int                  oficina_hosts2_reg;
    OFICINA_HOSTS2_M     oficina_hosts2[MAX_OFHOST];
    int                  vendedor_hosts_reg;
    VENDEDOR_HOSTS_M     vendedor_hosts[MAX_VENHOST];
    int                  tipdoc_reg;
    TIPDOC_M             tipdoc[MAX_TIPDOC];
    int                  st_ciclo_fact_reg;
    ST_CICLOFACT_M       st_ciclofact;
    int                  operadora_hosts_reg;
    OPERADORA_HOSTS_M    operadora_hosts[MAX_OPERHOST];
    int                  conceptos_tar_reg;
    CONCEPTOS_TAR_M      conceptos_tar[MAX_CONCEPTOS_TAR];
    int                  codcli_hosts_reg ;
    int                  detalleoper_reg;
    DETALLEOPER_M        detalleoper;
    int                  st_minutoadicional_reg;
    ST_MINUTOADICIONAL_M st_minutoadicional[MAX_MINUTOADICIONAL];
    long                 cantidad_clientes;
    LINEACOMANDO_M       StParametrosEntrada;
    int                  flag_proceso;
    int                  iregs_numorden;
    int                  num_directorios;
    DIRECTORIO           directorio[100];
    CONCATENADOR         concatenador[1000];
    long                 lNumConceptos;
    char                 sAplica_Cod_Autorizacion[2];
    char                 sCod_Autorizacion[10];
    ST_CONCIMPTOFACT_MC  st_concimptosfact[MAX_COD_CONCEPTOS];
    long                 lCantCocImpos;
    CATIMPUES_M          stCocImptos[200];
    ST_PARAM_ENV         Parametros_Env;
    ST_DATOSDOMINIO      stDat_Domin[5000];
    int                  iNumReg_DatDomin;
    CODOPER              st_CodOper[5000];
    long                 lCantOper;
}MEMORIA;

typedef struct 
{
    int   iNum_OrdenGr     ;
    int   iNum_OrdenSubGr  ;
    int   iNum_OrdenConc   ;
    int   iCodGrupo        ;
    int   iCodSubGrupo     ;
    int   iCodConcepto     ;
    char  szCodRegistro [6];
    int   iCodCriterio     ;
    int   iTipo_Llamada    ;
    int   iTipo_SubGrupo   ;
} NUMORDEN_MC;

NUMORDEN_MC *numorden;
MEMORIA *memoria;
ST_FACTCLIE *st_factclie_mc;
ST_FACTCLIE FacturaCliente_mc;

int flg_mc ;
int total_regs;
int id_memoria;
int id_numorden;
int id_codcli;
int id_concatenador;
char REGA1000[6];
int unir_a_memoria(int ,int );
int crear_semaforo(int id_tabla);
int get_cliente (int ,int );
int marca_cliente_facturado(int ,int );
void muestra_registro();
void muestra_registro_mc();


void muestra_parametros();
void muestra_parametros_ged();
void muestra_plan_tarifario();
void muestra_oficina_hosts2();
void muestra_vendedor_hosts2();
void muestra_tipdoc();
void muestra_ciclofact();
void muestra_operadora_hosts();
void muestra_conceptos_tar();
void muestra_codcli_hosts();
void muestra_detalleoper();
void muestra_minutoadicional();
void muestra_tabla_comandos();
int CargaFadParametrosMC();
int CargaFadParametros_GED_MC();
int bCargaMascaraOperadora_MC(DETALLEOPER *);
int GetCiclFact_MC(ST_CICLOFACT *,long );
int bfnCargaCod_Plantarif_MC (PLAN_TARIFARIO **, int *);
int CargaMinutoAdicional_MC();
int bfnCargaOficinas2_MC(OFICINA2 **, int *);
int bfnCargaOperadora_MC(OPERADORA **, int *);
int bfnCargaTipDocum_MC (TIPDOC **, int *);
int bfnCargaVendedores_MC(VENDEDOR **, int *);
int bCargaConceptosTar_MC(CONCEPTOS_TAR *);
extern int ManejoArchImp_MC(ST_FACTCLIE   *FactDocuClie,
                     LINEACOMANDO  *ParEntrada,
                     ST_INFGENERAL *sthFa_InfGeneral,
                     FILE          **Fd_ArchImp ,
                     char          *szNombreArchivo);
void trae_valor_fadparametros_mc(int ,char *);
BOOL CargaNumOrden_MC(NUMORDEN **, int * );
int get_registro (int );
void            vfnPrintMinPlanes2 (MINPLAN *, int );
int             ifnCmpMinPlanes2(const void *,const void *);

#endif
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


