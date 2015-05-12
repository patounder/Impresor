#ifndef _ImpSclSt_
#define _ImpSclSt_

/*  Version  FAC_DES_MAS ImpSclSt.h  7.000  */
#include <errores.h>
#include <GenFA.h>
#include <geora.h>
#include <malloc.h>
#include <memory.h>
#include <ORAcarga.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/timeb.h>

#define iBALANCE_ANTERIOR 1
#define iPAGOS_RECIBIDOS 2
#define iPAGOS_REVERTIDOS 3
#define iAJUSTE_CREDITO 4
#define iMISCELANEA 5
#define iCARGOS_MES 6
#define iTOTAL_FACTURA 7
#define iTOTAL_PAGAR 8

#define MAX_BYTE_A1000 900
#define MAX_BYTE_A1150 150
#define MAX_BYTE_A1010 300
#define MAX_BYTE_A1100 150
#define MAX_BYTE_A1200 100
/*#define MAX_BYTE_A1300 150*/
/* #define MAX_BYTE_A1300 222 P-ECU-12002F2*/
#define MAX_BYTE_A1300 300       /* PGG - 191131 - 3-01-2013 - Se agranda el buffer para el registro A1300 */
#define MAX_BYTE_A1400 300
#define MAX_BYTE_A1410 300
#define MAX_BYTE_A1420 300
#define MAX_BYTE_A1430 300
#define MAX_BYTE_A1500 300
#define MAX_BYTE_A1120 300
#define MAX_BYTE_A1130 300
#define MAX_BYTE_A1250 300
#define MAX_BYTE_A1700 300
#define MAX_BYTE_A1800 155
#define MAX_BYTE_A1900 450 /* ECU-10012 */
#define MAX_BYTE_A1950 200 
#define MAX_BYTE_A1960 20  /*P-ECU-12002F2*/
#define MAX_BYTE_A2000 100
#define MAX_BYTE_A2100 50
#define MAX_BYTE_A2200 50
#define MAX_BYTE_A2300 300
#define MAX_BYTE_A2400 500
#define MAX_BYTE_A2500 500
#define MAX_BYTE_A2600 500
#define MAX_BYTE_A2700 500
#define MAX_BYTE_A2800 150
#define szCODINFORME_GENERAR "IMPRES"

#define szCODPLANTARIFARIO_NULL "   "

#define szPROC_EST_RUN           "SUB PROCESO EN EJECUCION"
#define szPROC_EST_ERR           "SUB PROCESO TERMINO CON ERROR"
#define szPROC_EST_OK            "SUB PROCESO TERMINO OK"

#define szVersionActual         "7.000"
#define szUltimaModificacion    "19-MAR-2004"

#define szCONCEP_FACTURABLE     "FA"
#define szCONCEP_NO_FACTURABLE  "NF"

#define iCONCEP_FACTURABLE      1
#define iCONCEP_NO_FACTURABLE   0

#define SEPARADOR_01           59 /*;*/
#define SEPARADOR_02           58 /*:*/
#define CUOTA_VENCIDA           1
#define CUOTA_PORVENCER         2

#define NO_FACTURABLE       99999
#define COD_GRUPO_CUOTA     18
#define COD_GRUPO_SALDANT   101

/*
#define REG_1000        "A1000%08.8ld%1.1d%05.5d%015.15ld%-12.12s%-6.6s%-8.8s%-8.8s%-8.8s%-8.8s%-1.1s%-5.5s%-3.3s%-30.30s%012.12ld%-10.10s%-5.5s%-40.40s%-40.40s%-10.10s%015.4f%-1.1s%-8.8s%05.5d%-8.8s%-15.15s\n\0"
*/

/*P-ECU-10004BE*/
/*#define REG_1000        "A1000%08.8ld%1.1d%05.5d%015.15ld%-12.12s%-6.6s%-8.8s%-8.8s%-8.8s%-8.8s%-1.1s%-5.5s%-3.3s%-30.30s%012.12ld%-10.10s%-5.5s%-40.40s%-40.40s%-10.10s%015.4f%-1.1s%-8.8s%05.5d%-8.8s%-15.15s%-1.1s%-255.255s%-255.255s%-4.4ld%-9.9ld%-1.1s%-2.2d\n\0"*/
/*P-ECU-10004BE*/

/* ECU-10012 */
/*#define REG_1000        "A1000%08.8ld%1.1d%05.5d%015.15ld%-12.12s%-6.6s%-8.8s%-8.8s%-8.8s%-8.8s%-1.1s%-5.5s%-3.3s%-30.30s%012.12ld%-10.10s%-5.5s%-40.40s%-40.40s%-10.10s%015.4f%-1.1s%-8.8s%05.5d%-8.8s%-15.15s%-1.1s%-255.255s%-255.255s%-4.4ld%-9.9ld%-1.1s%-2.2d%-8.8s\n\0"*/
/* ECU-10012 */

/*ECU-12002-F2*/
#define REG_1000        "A1000%08.8ld%1.1d%05.5d%015.15ld%-12.12s%-6.6s%-8.8s%-8.8s%-8.8s%-8.8s%-1.1s%-5.5s%-3.3s%-30.30s%012.12ld%-10.10s%-5.5s%-40.40s%-40.40s%-10.10s%015.4f%-1.1s%-8.8s%05.5d%-8.8s%-15.15s%-1.1s%-255.255s%-255.255s%-4.4ld%-9.9ld%-1.1s%-2.2d%-8.8s%1s%-50.50s\n\0"
/*ECU-12002-F2*/

#define REG_1010        "A1010%08.8ld%1.1d%-5.5s%-50.50s%-20.20s%-3.3s%-40.40s%06.6ld%-40.40s\n\0"
#define REG_1100        "A1100%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f\n"
#define REG_1200        "A1200%015.4f%015.4f%015.4f%015.4f%1.1d%015.4f\n\0"
/* #define REG_1300        "A1300%-20.20s%-90.90s%-15.15s%010.10d%-10.10s%2s\n\0" */
#define REG_1300        "A1300%-20.20s%-90.90s%-15.15s%010.10d%-10.10s%2s%-50.50s%-20.20s\n\0" /*P-ECU-12002F2*/
#define REG_1400        "A1400%-250.250s\n\0"
#define REG_1410        "A1410%-250.250s\n\0"
#define REG_1420        "A1420%-250.250s\n\0"
#define REG_1430        "A1430%-250.250s\n\0"
#define REG_1500        "A1500%-250.250s\n\0"
#define REG_INI1700     "A1700\0"
#define REG_1700        "%06.6d%08.8ld%08.8ld%08.8ld%015.4f\0"
#define REG_FIN1700     "%8.8ld%08.8ld%015.4f\n\0"
#define REG_1800        "A1800%1.1d%05.5d%-50.50s%015.4f%-12.12s%015.4f%015.4f%015.4f%1.1d%-5.5s%-5.5s%05.2f\n" 
/* ECU-10012 */
/*#define REG_1900      "A1900%010.10d%-50.50s%015.4f%-12.12s%07.7d%06.6ld%06.6ld%06.6ld%015.4f%015.4f%-12.12s%-12.12s%015.4f%-100.100s%015.4f%015.4f%015.4f%015.4f%015.4f%-20.20s\n"*/
/*#define REG_1900        "A1900%010.10d%-50.50s%015.4f%-12.12s%07.7d%06.6ld%06.6ld%06.6ld%015.4f%015.4f%-12.12s%-12.12s%015.4f%-100.100s%015.4f%015.4f%015.4f%015.4f%015.4f%-20.20s%015.4f%010.10ld\n"*/
/* ECU-10012 */
/*ECU-12002-F2*/
#define REG_1900        "A1900%010.10d%-50.50s%015.4f%-12.12s%07.7d%06.6ld%06.6ld%06.6ld%015.4f%015.4f%-12.12s%-12.12s%015.4f%-100.100s%015.4f%015.4f%015.4f%015.4f%015.4f%-20.20s%015.4f%010.10ld%015.2f\n"
/*ECU-12002-F2*/
#define REG_1950        "A1950%9.9ld%5.5s%015.4f%015.4f%015.4f%6.6ld%6.6ld%6.6ld%6.6ld%6.6ld%6.6ld\n"
#define REG_1960        "A1960%-15.15s\n"  /*P-ECU-12002F2*/
#define REG_1890        "A1890%1.1d%05.5d%-50.50s%1.1d%-5.5s%-5.5s\n"
#define REG_1999        "A1999\n"
#define REG_2000        "%8.8d%02.2d%03.3d%5.5s\0"
#define REG_INI2000     "A2000\0"
#define REG_2100        "A2100%015.4f%-12.12s\n\0"
#define REG_2200        "A2200%015.4f\n\0"
#define REG_2300        "A2300%-200.200s\n\0"
#define REG_2400        "A2400%-150.150s%-70.70s%-20.20s%-30.30s%-30.30s\n\0"
#define REG_2400_Ingles "A2400%-300.300s\n\0"
#define REG_2600        "A2600%10.10ld%-50.50s%-25.25s%20.20ld\n\0"
#define REG_2500        "A2500%010.10d%-50.50s%015.4f%12.12ld%07.7d%06.6ld%06.6ld%06.6ld%015.4f%015.4f%12.12ld%12.12ld%015.4f%-100.100s%015.4f%015.4f%015.4f%015.4f%015.4f\n"
#define REG_2700        "A2700%010.10d%-50.50s%015.4f%12.12ld%07.7d%06.6ld%06.6ld%06.6ld%015.4f%015.4f%12.12ld%12.12ld%015.4f%-100.100s%015.4f%015.4f%015.4f%015.4f%015.4f\n"

#define GLS_PROCINIT        "Proceso Iniciado"
#define GLS_PROCFINOK       "Proceso Terminado OK"
#define GLS_PROCFINNOOK     "Proceso Terminado NO OK"

#define COD_TIP_IMPRE       1
#define COD_INFORME         "IMPRES"
#define NRO_COD_PROCESO_JOB  850
#define NRO_COD_PROCESO     5000
#define MAX_TRAZAPROC       100
#define COD_INTERFACT       330

#define MAX_GRUPOS          700
#define MAX_LARGOGRUPO      100

#define PIE_TIPOLLAMADA     "D2222"
#define PIE_ABONADO         "D1111"

#define BUFF_ABONADO                       20000

#define BUFF_CLIENTE                       5000
#define COD_SERVICIO                        3
#define iLOGNIVEL_DEF                       3

#define MAX_CONCEPTOS_LOCAL_HOST            20000
#define MAX_TRANSCLIE                       20000
#define MAX_PROMCLIE                        5000

#define MAX_CONCEPTOS_LOCAL                 135000 /* Peticion especial para un cliente con 130000 conceptos 9-12-2006 */

#define MAX_CUOTAS_LOCAL                    5000 /* Inc 90876 PPV 24/05/2009 */ /* 2500 -> 5000 Inc 171796 LIA 23/06/2011 */
#define MAX_LINEAS_MENSAJES                 50
#define MAX_SALDOS                          5000
#define MAX_REGISTROS_POR_TIPOS             200 /* rao 1500 */
#define MAX_TIPOS_REGISTROS                 3 /* A, B y D */
#define OK                                  TRUE
#define SQLOK                               0
#define FLUSH                               "flush_archivo"

#define NUMREG                              150
#define MAX_BYTES_REGISTRO                  250
#define MAX_BYTES_BUFFER                    ( MAX_BYTES_REGISTRO + 1 ) * NUMREG

#define MAX_ARRASTRE_ESTRUCTURA             70000
#define MAX_ARRASTRE_CURSOR                 10000
#define MAX_FAD_PARAMETROS                  1001
#define MAX_MINUTOADICIONAL                 8001
#define MAX_TIPOS_LD                        10

#define CARGOS_BASICOS                      1
#define CARGOS_VARIOS                       2
#define TRAFICO                             3
#define ARRIENDO_VENTA                      4
#define COBRANZA                            5
#define SALDO_ANTERIOR                      6
#define CUOTAS_PAGARES                      7
#define IMPUESTOS                           8
#define NO_EXISTE_PLAN                      "                              "

#define iIND_IMPRIME_TRAFICO_SI             1
#define iIND_TABLA_CARRIER                  4
#define iIND_TABLA_INTERZONA_ESPECIAL       2

#define DIREC_NOCICLO_NPROC                 67
#define MONTO_ESCRITO_PREFIJO               106
#define MONTO_ESCRITO_POSFIJO               107
#define MONTO_ESCRITO_MONEDA                108

#define CODIGO_DESPACHO_LOCUTORIO           115 /* PGG SOPORTE 20-02-2007 MA-37695 */

#define iTIPLLAMADAS_LOCALES                1
#define iTIPLLAMADAS_INTERZONA              2
#define iTIPLLAMADAS_ESPECIALES             3
#define iTIPLLAMADAS_CARRIER                4
#define iTIPLLAMADAS_ROAMING                5
#define iTIPLLAMADAS_LDI                    6
#define iTIPLLAMADAS_ESPECIALES_DATA        7
#define iTIPLLAMADAS_TARIFA_ADICIONAL       8

#define iDIRECCION_FACTURACION              0
#define iDIRECCION_OPERADORA                1
#define iDIRECCION_PLAZA                    2
#define iDIRECCION_CORRESPONDENCIA          3
#define iDIRECCION_SUCURSAL                 4

#define iTIPO_CONCEPTO_CARRIER              4

#define COD_ABONADO                         "D1000"
#define COD_CARRIERS                        "D3004"
#define COD_ESPECIALES                      "D3003"
#define COD_INTERZONA                       "D3002"
#define COD_LDI                             "D3006"
#define COD_ESPECIALES_DATA                 "D3007"
#define COD_TARIFA_ADICIONAL                "D3008"
#define COD_LOCALES                         "D3001"
#define COD_INTERCOMPANIA                   "D3010"
#define COD_MENSAJEPREMIMUN                 "D3011"


#define COD_MASK_WHERE_LOCALES              61
#define COD_MASK_WHERE_INTERZONA            62
#define COD_MASK_WHERE_LDI                  63
#define COD_MASK_WHERE_ESPECIALES           64
#define COD_MASK_WHERE_ESPECIALESDATA       65

#define COD_MASK_INDAGRUPACION              76

#define COD_MASK_SERVICIO                   11
#define COD_MASK_FORMULARIO                 12
#define COD_MASK_CLIENTESXFILE              13

#define COD_MASK_LOCAL                      22
#define COD_MASK_ESPECIALES                 23
#define COD_MASK_INTERZONA                  24
#define COD_MASK_ROAMING                    25
#define COD_MASK_CARRIER                    26
#define COD_MASK_LDI                        27

#define COD_ROAMING                         "D3005"
#define COD_TIPOLLAMADA                     "D2000"

#define MAX_CONCEPTOS_TAR                   100
#define COD_MASK_INDFACTURADO               52

#define EMPRESA                             "E"
#define INDIVIDUAL                          "I"

extern int     COD_PROCESO ;

char    szModulo [50];

int     iGPrimCateg;

char    szformato_fecha[22];
char    szformato_hora[9];
char    szNumDecimal[21];
char    szhIdiomaOper [6];
int     iCodAbonoCel;
char    szAplica_Cod_Autorizacion[2];

typedef struct TagAutorizFolio
{
    char    szCodAutorizacion [11];
    char    szFechaVencimiento[10];
    char    szFechaInicio     [10]; /* ECU-10012 */
}AUTORIZ_FOLIO;


typedef struct tagOrden
{
    char    szKey[60];
    int     iPosicion;
}ST_ORDEN;

typedef struct tagOrdenado
{
    int      iNumRegs;
    ST_ORDEN *stOrden ;
}ST_ORDENADO;


/************************************************************************/
/*  Estructura para recoger los datos por la linea de comandos.         */
/************************************************************************/

typedef struct stFa_DetLlamadas
{
    char    szSec_Empa          [30];
    char    szSec_Cdr            [6];
    char    szFecIniTasa        [16];
    char    szTieIniLlam         [7];
    char    szNumMovil1         [20];
    char    szNumMovil2         [20];
    double  dImpLocal1              ;
    double  dImpLarga2              ;
    char    szCodFranHoraSoc     [6];
    char    szCodAlm             [4];

    char    szDesMovil2         [31];
    char    szDurLocal1          [7];
    char    szDurLarga2          [7];
    char    szIndEntSal1         [6];

    double  dMto_Real               ;
    double  dMto_Dcto               ;
    int     iDur_Real               ;
    int     iDur_Dcto               ;
    int     iCod_Carg               ;
    char    szCodFCob            [6];
    double  dValorUndad             ;
}DETLLAMADAS;

typedef struct stFa_DetCelularAgrupado
{
    int     iNum_OrdenGr           ;
    int     iNum_OrdenSubGr        ;
    int     iCodGrupo              ;
    int     iCodSubGrupo           ;
    int     iCriterio              ;
    char    szCodRegistro    [6]   ;
    int     iTipo_Llamada          ;

    DETLLAMADAS *stDetLlamadas     ;
    int     iCantLlamadas          ;
}DETCELULAR_AGRUP;


typedef struct stFa_DetCelular
{
    DETCELULAR_AGRUP *stAgrupacion ;
    int     iCantEstructuras       ;
}DETCELULAR;


typedef struct stFa_DetLlamadas_Hosts
{
    char    szSec_Empa        [TAM_HOSTS_PEQ] [30];
    char    szSec_Cdr         [TAM_HOSTS_PEQ]  [6];
    char    szFecIniTasa      [TAM_HOSTS_PEQ] [16];
    char    szTieIniLlam      [TAM_HOSTS_PEQ]  [7];
    char    szNumMovil1       [TAM_HOSTS_PEQ] [20];
    char    szNumMovil2       [TAM_HOSTS_PEQ] [20];
    double  dImpLocal1        [TAM_HOSTS_PEQ]     ;
    double  dImpLarga2        [TAM_HOSTS_PEQ]     ;
    char    szCodFranHoraSoc  [TAM_HOSTS_PEQ]  [6];
    char    szCodAlm          [TAM_HOSTS_PEQ]  [4];

    char    szDesMovil2       [TAM_HOSTS_PEQ] [31];
    char    szDurLocal1       [TAM_HOSTS_PEQ]  [7];
    char    szDurLarga2       [TAM_HOSTS_PEQ]  [7];
    char    szIndEntSal1      [TAM_HOSTS_PEQ]  [6];

    double  dMto_Real         [TAM_HOSTS_PEQ]     ;
    double  dMto_Dcto         [TAM_HOSTS_PEQ]     ;
    int     iDur_Real         [TAM_HOSTS_PEQ]     ;
    int     iDur_Dcto         [TAM_HOSTS_PEQ]     ;
    int     iCod_Carg         [TAM_HOSTS_PEQ]     ;
    char    szCodFCob         [TAM_HOSTS_PEQ] [6] ;
    double  dValorUndad       [TAM_HOSTS_PEQ]     ;
}DETLLAMADAS_HOSTS;

typedef struct tagTipDoc
{
    char    szDesTipDocum     [41];
    int     iCodTipDocum          ;
}TIPDOC;


typedef struct tagOTipDocum
{
    int     iNumTipDocum;
    TIPDOC  *stTipDocum;
}TIPDOCUM;


typedef struct tagTipDoc_Hosts
{
    char    szDesTipDocum     [TAM_HOSTS_PEQ][40];
    int     iCodTipDocum      [TAM_HOSTS_PEQ]    ;
}TIPDOC_HOSTS;


typedef struct tagCodCli
{
    char    szNomApoderado	[40];
    long    lCodCliente         ;
    char    szCodServicio   [4];
    char    szFecDesde      [12];
    char    szFecHasta      [12];
}CODCLI;


typedef struct tagCodCliente
{
    int         iNumCodClientes;
    CODCLI      *stTipDocum;
}CODCLIENTE;


typedef struct tagCodCli_Hosts
{
    char    szNomApoderado    [TAM_HOSTS_PEQ][40];
    long    lCodCliente       [TAM_HOSTS_PEQ]    ;
    char    szCodServicio     [TAM_HOSTS_PEQ] [4];
    char    szFecDesde        [TAM_HOSTS_PEQ][12];
    char    szFecHasta        [TAM_HOSTS_PEQ][12];
}CODCLI_HOSTS;

/* ESTRUCTURAS PARA CARGA DE DATOS OFICINAS  */
typedef struct tagOficina2
{
    char    szCodOficina       [3];
    char    szDesOficina      [41];
}OFICINA2;

typedef struct tagOficina_Hosts2
{
    char    szCodOficina      [TAM_HOSTS_PEQ] [3];
    char    szDesOficina      [TAM_HOSTS_PEQ][41];
}OFICINA_HOSTS2;

typedef struct tagOficinas2
{
    int         iNumOficinas;
    OFICINA2    *stOficina;
}OFICINAS2;


/* ESTRUCTURAS PARA CARGA DE DATOS OPERADORAS */
typedef struct tagOperadora
{
    char    szCodOperadora[6];
    long    lCodClienteOperadora;
    char    szNomOperadora[51];
    char    szNumIdenTRib[21];
    char    szDireccion [301];
}OPERADORA;

typedef struct tagOperadora_Hosts
{
    char    szCodOperadora      [100]  [6];
    long    lCodClienteOperadora[100]     ;
    char    szNomOperadora      [100] [51];
    char    szNumIdenTRib       [100] [21];
    char    szDireccion         [100][301];
}OPERADORA_HOSTS;

typedef struct tagOperadora2
{
    int         iNumOperadoras;
    OPERADORA   *stOperadora;
}OPERADORAS;

typedef struct tagVendedor
{
    char    szNomVendedor[41];
    long    lCodVendedor    ;
}VENDEDOR;

typedef struct tagVendedores
{
    int         iNumVendedores;
    VENDEDOR    *stVendedores;
}VENDEDORES;

typedef struct tagVendedor_Hosts
{
    char    szNomVendedor[TAM_HOSTS_PEQ][41];
    long    lCodVendedor [TAM_HOSTS_PEQ];
}VENDEDOR_HOSTS;

typedef struct tagDocPeriodo
{
    char    szCodOperadora [6];
    char    szCodOficina   [3];
    int     iCodTipDocum      ;
    char    szDesTipDocum [41];
    char    szPrefPlaza   [11];
    long    lNumFolio         ;
    char    szFecEmision  [11];
    double  dTotFactura      ;
}DOCPERIODO;

typedef struct tagDocsPeriodo
{
    int        iNumRegs;
    DOCPERIODO *stDocPeriodo;
}DOCSPERIODO;

typedef struct tagDocsPeriodo_Host
{
    char    szCodOperadora [TAM_HOSTS_PEQ] [6];
    char    szCodOficina   [TAM_HOSTS_PEQ] [3];
    int     iCodTipDocum   [TAM_HOSTS_PEQ]    ;
    char    szDesTipDocum  [TAM_HOSTS_PEQ][41];
    char    szPrefPlaza    [TAM_HOSTS_PEQ][11];
    long    lNumFolio      [TAM_HOSTS_PEQ]    ;
    char    szFecEmision   [TAM_HOSTS_PEQ][11];
    double  dTotFactura    [TAM_HOSTS_PEQ]    ;
}DOCPERIODO_HOSTS;

typedef struct tagPago
{
    double  dMonto           ;
    char    szFecha   [9]    ;
    char    szDecrip [41]    ;
    char    szModPago[21]    ;
    int     iTipPago         ;
    char    szCodOperadora[6];
    int     iCodTipDocum     ;
}PAGO;


typedef struct tagPagos
{
    int       iNumRegs;
    PAGO      *stPago;
}PAGOS;


typedef struct tagPagos_Hosts
{
    double  dMonto        [TAM_HOSTS_PEQ];
    char    szFecha       [TAM_HOSTS_PEQ][9];
    char    szDecrip      [TAM_HOSTS_PEQ][41];
    char    szModPago     [TAM_HOSTS_PEQ][21];
    int     iTipPago      [TAM_HOSTS_PEQ];
    char    szCodOperadora[TAM_HOSTS_PEQ][6];
    int     iCodTipDocum  [TAM_HOSTS_PEQ];
}PAGO_HOSTS;

typedef struct {
    int     cod_ciclo;
    char    fec_desde     [9];
    char    fec_hasta     [9];
    char    szFec_Emision [9];
    char    szMesCiclo_0  [7];
    char    szMesCiclo_1  [7];
    char    szMesCiclo_2  [7];
    char    szMesCiclo_3  [7];
    char    szMesCiclo_4  [7];
    char    szMesCiclo_5  [7];
    int     iIndTasador;
    char    szFec_Desde   [9];
    char    szFec_Hasta   [9];
} ST_CICLOFACT ;

typedef struct
{
    double   dTotFactura ;
    double   dTotCuotas  ;
    double   dTotPagar   ;
    double   dTotSaldoAnt;
}ST_ACUMMTO;

typedef struct {
   int       iItem             [9];
   double    dMonto            [9];
   char      szDescrip     [9][50];
   int       iPos              [9];
}ST_BALANCE;

typedef struct {
    char   szRowid        [19];
    int    iCodCliente        ;
    int    iCod_Concepto      ;
    int    iNumCuota          ;
    int    iSecCuota          ;
    double dMtoCuota          ;
    long   lNum_Folio         ;
    char   szNum_FolioCtc [13];
    char   szFec_Emision  [11];
    int    iInd_Facturado     ;
    int    iCod_TipDocum      ; /* SAAM-20070423 P-ECU-060354 RF127 */
    char   szDes_Cuota    [50];
    char   szFechaEfectiva[9] ;
    char   szPrefPlaza    [11];
    long   lNumAbonado        ;
	long   l_Num_Secuenci    ;
    long   l_Cod_Vendedor_Ag ;
    char   sz_Letra         [2] ;
    long   l_Cod_Centremi    ;
    long   l_Columna         ;
    char   sz_IndAcelerada [2]; /* P-ECU-12019  */    
}rg_cuotas;

typedef struct {
    long  lCod_Cliente       ;
    long  lNum_Secuenci      ;
    long  lNum_Folio         ;
    char  szNum_FolioCtc [13];
    char  szDes_Saldo    [41];
    int   iCod_Tipdoc        ;
    double dTotalSaldoAnt    ;
    char  szFechaEfectiva[9] ;
    long  lNumAbonado        ;
}rg_fa_factsaldoant;

typedef struct {
    char    szFec_Emision [9];
    double  dTotalSaldo       ;
    int     iNum_RegSaldo     ;
    rg_fa_factsaldoant stReg[MAX_SALDOS];
}STSALDO_ANTERIOR;

typedef struct {
    char    szUser          [50];   /*  Usuario Unix                        */
    char    szPass          [50];   /*  Password Oracle de Usuario Unix     */
    char    szUsuaOra       [50];   /*  Usuario Oracle                      */
    char    szDirLogs     [1024];   /*  Directorio de Archivos Log's y Err  */
    char    szDirDats     [1024];   /*  Directorio de Archivos Log's y Err  */
    char    szFDetLlam    [1024];   /*  Archivo de Detalle de Llamadas      */
    char    szFormato      [255];   /*  Formato Nombre Archivo              */
    long    lCodCiclFact        ;   /*  Codigo de Ciclo a Procesar          */
    long    lNumProceso         ;   /*  Numero de Proceso de Facturacion    */
    double  dValDolar           ;   /*  Valor de Dolar a Fecah de Emision   */
    int     iNivLog             ;   /*  Nivel de Log para Proceso           */
    int     szFecEmision    [20];   /*  Fecha de Emison de la Factura       */
    int     szFecDesdeLlam  [20];   /*  Fecha Inicio del Periodo Tasacion   */
    int     szFecHastaLlam  [20];   /*  Fecha Termino del Periodo Tasacion  */
    char    szCodIdioma      [6];   /*  Directorio de Archivos Log's y Err  */
    int     iCodTipDocum        ;
    char    szCodDespacho    [6];
    int     iReproceso          ;
    long    cod_clienteinic     ;
    long    cod_clientefina     ;
    long    lProceso            ;
    long    lNum_SecuInfo       ;
    char    szFecIngBegin    [9];
    char    szFecIngEnd      [9];
    int     iTipoCiclo          ;
    int     iCodSalida          ;
    int     iCodEntrada         ;
}LINEACOMANDO;

typedef struct{
    double     dTotalCuotas_venci           ;
    int        iNum_RegCuotas_venci         ;
    rg_cuotas  stReg_venci[MAX_CUOTAS_LOCAL];
    double     dTotalCuotas_pven            ;
    int        iNum_RegCuotas_pven          ;
    rg_cuotas  stReg_pven [MAX_CUOTAS_LOCAL];
    double     dTotalCuotas                 ;
}ST_CUOTAS;

typedef struct {
    char    direccion_fact   [251];
    char    direccion_corr   [251];
}ST_DIR;


typedef struct tagDetAbonMovimClie
{
    char	szFecTrans 	   [9]  ;
    int 	iCodTipDocum        ;
    char	szCodOficina   [3]  ;
    char	szCodPlaza	   [11] ;
    long	lNumFolio           ;
    long    lNumCuota			;
    long    lNumTotalCuota      ;
    double  dMontoDetDebe       ;
	double	dMontoDetHaber      ;
	double	dMontoDetSaldo      ;
	char    szCodRegistro    [6];
    long   	lNumFolioRel       ;
    char   	szPrefPlazaRel[11] ; 
	char    sz_IndAcelerada[2] ; //##@@
    double  dMtoTotal;			 //##@@
}DET_ABON_MOVIM_CLIE;

typedef struct tagDetAbonPagosClie
{
    char	szFecTrans 	   [9]  ;
    int 	iCodTipDocum        ;
    char	szCodOficina   [3]  ;
    char	szCodPlaza	   [11] ;
    long	lNumFolio           ;
    long    lNumCuota			;
    long    lNumTotalCuota      ;
    double  dMontoDetDebe       ;
	double	dMontoDetHaber      ;
	double	dMontoDetSaldo      ;
	char    szCodRegistro    [6];
    long   	lNumFolioRel       ;
    char   	szPrefPlazaRel[11] ;
	char    sz_IndAcelerada[2] ;
    double  dMtoTotal;
}DET_ABON_PAGOS_CLIE;

typedef struct tagSumaAcum
{
     long lNum_Folio;
     char szPrefPlaza[11];
     int iSecCuota;
     int iNumCuota;
     double dMtoCuota;
     double dMontoTotalDeuda;
     double dSaldoPendiente;
     long lNum_Folio_Rel;
     char szPrefPlaza_Rel[11];
     int iNumCuota_iSecCuota;
     char sz_IndAcelerada[2];
	 int iCod_TipDocum;
}SUMAACUM;

typedef struct tagDetMovimClie
{
    long	lCantReg            ;
    long 	lNumAbonado         ;
    double  dMontoDetDebe       ;
	double	dMontoDetHaber      ;
	DET_ABON_MOVIM_CLIE *stDetAbonMovimClie;
}DET_MOVIM_CLIE;

typedef struct tagDetPagosClie
{
    long	lCantReg            ;
    long 	lNumAbonado         ;
    double  dMontoDetDebe       ;
	double	dMontoDetHaber      ;
	DET_ABON_PAGOS_CLIE *stDetAbonPagosClie;
}DET_PAGOS_CLIE;

typedef struct tagResMovimClie
{
    char	szCodOficina   [3] ;
    int 	iCodTipDocum       ;
    char	szCodPlaza	   [11];
    long	lNumFolio          ;
    char	szFecTrans 	   [9] ;
    double  dTotalFactura      ;
    long   	lNumFolioRel       ;
    char   	szPrefPlazaRel[11] ;
}RES_MOVIM_CLIE;

typedef struct tagResPagosClie
{
    int 	iCodTipDocum       ;
    double  dTotalResDebe      ;
	double	dTotalResHaber     ;
}RES_PAGOS_CLIE;

typedef struct tagMovimClie
{
    int     iNumRegResMov;
    int     iNumRegDetMov;	
    RES_MOVIM_CLIE  *stResMovimClie;
    DET_MOVIM_CLIE  *stDetMovimClie;
}MOVIM_CLIE;

typedef struct tagPagosClie
{
    int     iNumRegResPag;
    int     iNumRegDetPag;
    RES_PAGOS_CLIE  *stResPagosClie;
    DET_PAGOS_CLIE  *stDetPagosClie;
}PAGOS_CLIE;

typedef struct tagDetTransacciones
{
    char    szFecDesde       [9]    ;
    char    szFecHasta       [9]    ;
    double  dTotalTransDebe          ;
	double	dTotalTransHaber         ;
	double	dTotalTransSaldo         ;
    MOVIM_CLIE  stMovimClie;
    PAGOS_CLIE  stPagosClie;
}DET_TRANSACCIONES;

typedef struct tagProm_Clie
{
	int 	iCodCargo;
	char	szTipoDcto[6];
	char	szCodDcto [6];
	double	dMtoReal;
	double	dMtoFact;
	double	dMtoDcto;
	long    lDurReal;
	long    lDurFact;
	long    lDurDcto;
	long    lCantLlamReal;
	long    lCantLlamFact;
	long    lCantLlamDcto;
}PROM_CLIE;

typedef struct tagProm_TraficoClie
{
    int         iNumPromClie;
    PROM_CLIE  *stPromocionesClie;
}PROM_TRANFICOCLIE;

typedef struct tagDetTransaccionesClieHost
{
	char    szRowId          [MAX_TRANSCLIE][19] ;
	long 	lNumAbonado      [MAX_TRANSCLIE]     ;
	int 	iIndDetalle      [MAX_TRANSCLIE]     ;
	int 	iCodTipDocum     [MAX_TRANSCLIE]     ;
	char	szCodOficina     [MAX_TRANSCLIE][3]  ;
	char	szCodPlaza	     [MAX_TRANSCLIE][11] ;
	long	lNumFolio        [MAX_TRANSCLIE]     ;
	char	szFecTrans 	     [MAX_TRANSCLIE][9] ;
	long	lNumCuota        [MAX_TRANSCLIE]     ;
	long	lNumTotalCuota   [MAX_TRANSCLIE]     ;
	double  dMontoDebe       [MAX_TRANSCLIE]     ;
	double	dMontoHaber      [MAX_TRANSCLIE]     ;
	double	dMontoSaldo    	 [MAX_TRANSCLIE]     ;
	double	dMontoAjuste     [MAX_TRANSCLIE]     ;
	double	dMontoTotBalance [MAX_TRANSCLIE]     ;
	int		iIndPago         [MAX_TRANSCLIE]     ;
	char    szCodRegistro    [MAX_TRANSCLIE][6]  ;
	char    szCodOrigen      [MAX_TRANSCLIE][6]  ;
	int		iIndCaratula     [MAX_TRANSCLIE]     ;
	long   	lNumFolioRel     [MAX_TRANSCLIE]     ;
    char   	szPrefPlazaRel   [MAX_TRANSCLIE][11] ;
	char    sz_IndAcelerada  [MAX_TRANSCLIE][2]  ;
}DET_TRANSACCIONES_CLIE_HOST;

typedef struct tagPromClieHost
{
	int 	iCodCargo     [MAX_PROMCLIE];
	char	szTipoDcto    [MAX_PROMCLIE][6];
	char	szCodDcto     [MAX_PROMCLIE][6];
	double	dMtoReal      [MAX_PROMCLIE];
	double	dMtoFact      [MAX_PROMCLIE];
	double	dMtoDcto      [MAX_PROMCLIE];
	long    lDurReal      [MAX_PROMCLIE];
	long    lDurFact      [MAX_PROMCLIE];
	long    lDurDcto      [MAX_PROMCLIE];
	long    lCantLlamReal [MAX_PROMCLIE];
	long    lCantLlamFact [MAX_PROMCLIE];
	long    lCantLlamDcto [MAX_PROMCLIE];
}PROM_CLIE_HOST;


/* DINAMISMO 14/12/2006 Desde aca */

typedef struct {
    int     iNum_OrdenGr         [MAX_CONCEPTOS_LOCAL_HOST];
    int     iNum_OrdenConc       [MAX_CONCEPTOS_LOCAL_HOST];
    int     iCodGrupo            [MAX_CONCEPTOS_LOCAL_HOST];
    char    szGlosaGrupo         [MAX_CONCEPTOS_LOCAL_HOST][51];
    int     iNum_OrdenSubGr      [MAX_CONCEPTOS_LOCAL_HOST];
    int     iCodSubGrupo         [MAX_CONCEPTOS_LOCAL_HOST];
    char    szGlosaSubGrupo      [MAX_CONCEPTOS_LOCAL_HOST][51];
    int     iCod_TipSubGrupo     [MAX_CONCEPTOS_LOCAL_HOST];
    long    lNumAbonado          [MAX_CONCEPTOS_LOCAL_HOST];
    int     iCod_Producto        [MAX_CONCEPTOS_LOCAL_HOST];
    int     iCodConcepto         [MAX_CONCEPTOS_LOCAL_HOST];
    int     iColumna             [MAX_CONCEPTOS_LOCAL_HOST];
    char    szDes_Concepto       [MAX_CONCEPTOS_LOCAL_HOST][61];
    int     iCodTipConce         [MAX_CONCEPTOS_LOCAL_HOST];
    long    lSeg_Consumo         [MAX_CONCEPTOS_LOCAL_HOST];
    int     iNum_Unidades        [MAX_CONCEPTOS_LOCAL_HOST];
    double  dTotalFacturableNet  [MAX_CONCEPTOS_LOCAL_HOST];
    double  dTotalFacturableImp  [MAX_CONCEPTOS_LOCAL_HOST];
    char    szNum_Celular        [MAX_CONCEPTOS_LOCAL_HOST][20+1];
    char    szCod_Nivel          [MAX_CONCEPTOS_LOCAL_HOST][4];
    char    szFec_Pago           [MAX_CONCEPTOS_LOCAL_HOST][11];
    char    szCod_CargoBasico    [MAX_CONCEPTOS_LOCAL_HOST][4];
    char    szTip_ConcNoFact     [MAX_CONCEPTOS_LOCAL_HOST][6];
    char    szCod_PlanTarif      [MAX_CONCEPTOS_LOCAL_HOST][4];
    char    szFec_FinContrato    [MAX_CONCEPTOS_LOCAL_HOST][11];
    long    lSeg_ConsumoReal     [MAX_CONCEPTOS_LOCAL_HOST];
    long    lSeg_ConsumoDcto     [MAX_CONCEPTOS_LOCAL_HOST];
    double  dTotalFacturableReal [MAX_CONCEPTOS_LOCAL_HOST];
    double  dTotalFacturableDcto [MAX_CONCEPTOS_LOCAL_HOST];
    long    lCntLlamReal         [MAX_CONCEPTOS_LOCAL_HOST];
    long    lCntLlamDcto         [MAX_CONCEPTOS_LOCAL_HOST];
    long    lCntLlamFAct         [MAX_CONCEPTOS_LOCAL_HOST];
    double  dImpValUnitario      [MAX_CONCEPTOS_LOCAL_HOST];
    char    szGlsDescrip         [MAX_CONCEPTOS_LOCAL_HOST][100];
    int     iCodConcerel         [MAX_CONCEPTOS_LOCAL_HOST];
    int     iColumnaRel          [MAX_CONCEPTOS_LOCAL_HOST];
    double  dPrcImpuesto         [MAX_CONCEPTOS_LOCAL_HOST];
    double  dImpMontoBase        [MAX_CONCEPTOS_LOCAL_HOST];
    int     iTipConcep           [MAX_CONCEPTOS_LOCAL_HOST];
    int     iNivelImpresion      [MAX_CONCEPTOS_LOCAL_HOST];
    char    szTipUnidad          [MAX_CONCEPTOS_LOCAL_HOST][10];
    char    szTipGrupo           [MAX_CONCEPTOS_LOCAL_HOST][10];
    long    lNumVenta            [MAX_CONCEPTOS_LOCAL_HOST];
    char    szDesPlanTarif       [MAX_CONCEPTOS_LOCAL_HOST] [50];
    double  dSumDescuentos       [MAX_CONCEPTOS_LOCAL_HOST];
    long    lCantDescuentos      [MAX_CONCEPTOS_LOCAL_HOST];        
}ST_DETCONSUMO_HOST;

/*  modificacion para manejo dinamico */

typedef struct {
    int     iNum_OrdenGr         ;
    int     iNum_OrdenConc       ;
    int     iCodGrupo            ;
    char    szGlosaGrupo         [51];
    int     iNum_OrdenSubGr      ;
    int     iCodSubGrupo         ;
    char    szGlosaSubGrupo      [51];
    int     iCod_TipSubGrupo     ;
    long    lNumAbonado          ;
    int     iCod_Producto        ;
    int     iCodConcepto         ;
    int     iColumna             ;
    char    szDes_Concepto       [61];
    int     iCodTipConce         ;
    long    lSeg_Consumo         ;
    int     iNum_Unidades        ;
    double  dTotalFacturableNet  ;
    double  dTotalFacturableImp  ;
    char    szNum_Celular        [20+1];
    char    szCod_Nivel          [4];
    char    szFec_Pago           [11];
    char    szCod_CargoBasico    [4];
    char    szTip_ConcNoFact     [6];
    char    szCod_PlanTarif      [4];
    char    szFec_FinContrato    [11];
    long    lSeg_ConsumoReal     ;
    long    lSeg_ConsumoDcto     ;
    double  dTotalFacturableReal ;
    double  dTotalFacturableDcto ;
    long    lCntLlamReal         ;
    long    lCntLlamDcto         ;
    long    lCntLlamFAct         ;
    double  dImpValUnitario      ;
    char    szGlsDescrip         [100];
    int     iCodConcerel         ;
    int     iColumnaRel          ;
    double  dPrcImpuesto         ;
    double  dImpMontoBase        ;
    int     iTipConcep           ;
    int     iNivelImpresion      ;
    char    szTipUnidad          [10];
    char    szTipGrupo           [10];
    long    lNumVenta            ;
    double  dSumDescuentos       ;
    long    lCantDescuentos      ;
}STDETCONSUMO;

typedef struct{
    int           iNumReg;
    double        dGravFactura;
    STDETCONSUMO *stDetConsumo;
}STDETCONSUMOS;


/* DINAMISMO 14/12/2006 hasta aca */


typedef struct{
    long lCodImptoFact;
}COD_IMPTOFACT;

typedef struct{
    int           iNumReg;
    COD_IMPTOFACT *stCodImptosFact;
}CODIMPTOSFACT;

typedef struct{
   long   lCodConcepto;
   int    iCodCategoria;
   double dPrcImpuesto;
   char   szFlagImpto[2];
   int    iCodTipImpto;
}CATIMPUES;

typedef struct{
   int       iNumRegs;
   CATIMPUES *stCatImpuesto;
}CATIMPUESTOS;

typedef struct tagOper
{
    int     iCodOperador;
    char    szDesOperador[31];
}CODOPER;

typedef struct tagOpers
{
    int     iNumRegs;
    CODOPER *stOper;
}CODOPERS;

typedef struct
{
   char szTolCodLlam[21];
   char szTolCodTDir[21];
   char szTolCodTHor[21];
   char szTolCodTHorAlta[21];
   char szTolCodTHorBaja[21];
   char szTolConCliente[21];
   char szTolCodOperador[21];
   char szTolCodTDia[21];
   char szTolCodSFran[21];
}GEDPARAMETROS;

typedef struct
{
   char szCod_Plan[6];
   char szCod_Thor[6];
   long lSeg_Inic;
   long lSeg_Adic;
   double dMto_Inic;
   double dMto_Adic;
}ST_DATOSDOMINIO;


typedef struct tagMinPlan
{
   char   szCod_Plan[6];
   char   szCod_Thor[6];
   long   lSeg_Inic;
   long   lSeg_Adic;
   double dMto_Inic;
   double dMto_Adic;
}MINPLAN;

typedef struct tagMinPlanes
{
    int       iNumRegs;
    MINPLAN   *stMinPlan;
}MINPLANES;

typedef struct tagMinPlan_Hosts
{
   char   szCod_Plan[TAM_HOSTS_PEQ][6];
   char   szCod_Thor[TAM_HOSTS_PEQ][6];
   long   lSeg_Inic [TAM_HOSTS_PEQ];
   long   lSeg_Adic [TAM_HOSTS_PEQ];
   double dMto_Inic [TAM_HOSTS_PEQ];
   double dMto_Adic [TAM_HOSTS_PEQ];
}MINPLAN_HOSTS;



typedef struct
{
    char     szRowid           [19];
    long     lIndOrdenTotal    ;
    long     lCodCliente       ;
    long     lNum_Folio        ;
    char     szNumCtc          [11+1];
    char     szFecEmision      [12];
    char     szFecVencimie     [12];
    int      iCodTipDocum      ;
    long     lNumProceso       ;
    char     szCodGenArch      [3];
    char     szNomHeader       [6];
    int      iCodPrioridad     ;
    char     szCodDespacho     [6];
    double   dTotFactura       ;
    char     szRut_Cliente     [21];
    char     szNombre_Clie     [91];
    int      iNumAbonados      ;
    int      iIndImprime       ;
    char     szCod_Idioma      [6];
    char     szDireccion       [9][301] ;
    char     szIndDebito       [2];
    char     szNumCtcPago      [11+1];
    char     szPrefPlaza       [11];
    char     szCodOperadora    [6];
    char     szCodPlaza        [6];
    double   dTotCargosMes     ;
    double   dImpSaldoAnt      ;
    double   dTotPagar         ;
    double   dTotCuotas        ;
    char     szNumIdentTrib    [12];
    char     szPlanTarif       [4];
    char     szCod_Oficina     [3];
    long     lCodVendedor      ;
    char     szNomUsuarora     [31];
    int      iCodOperPlaza         ;
    char     szCodMonedaImp    [3];
    double   dImpConversion    ;
    long     lNumSecuRel       ;
    char     szLetraRel        [2];
    int      iCodTipDocumRel   ;
    long     lCodVendedorAgRel ;
    long     lCodCentrRel      ;
    long     lNumVenta         ;
    long     lCodCategoria     ;
    char     szNomApoderado    [40];
    char     szCodZona         [15];
    int      iCodSisPago       ;
    int      iestado;
    
    /*P-ECU-10004BE*/
    char		 szTipDistribucion[2];
    char		 szEmailPrincipal[256];
    char		 szEmailAlterno[256];
    long		 lIdSegmento;
    char		 szFecAlta[12];
    /*P-ECU-10004BE*/        

	char     szCod_Autorizacion[11]; /*P-ECU-10039*/
	char     szCod_tipident [3]; /* Inc-pre-189124  */
} ST_FACTCLIE;

ST_FACTCLIE   FacturaCliente    [BUFF_CLIENTE];


typedef struct {
    long lhNumSecuenciaInforme;
    char szCodInformeGenerar[7];
    char szPathDir[1000];
    int  iContClientesProcesados;
    char szCOD_SERVICIO[4];
    int  iSecuencial;
    char szIdiomaOper       [6];

}ST_INFGENERAL;

/****************************************************************************/
/*  Estructuras para carga de descripciones de Orden                        */
/****************************************************************************/
typedef struct tagNumOrden
{
    int     iNum_OrdenGr    ;
    int     iNum_OrdenSubGr ;
    int     iNum_OrdenConc  ;
    int     iCodGrupo       ;
    int     iCodSubGrupo    ;
    int     iCodConcepto    ;
    char    szCodRegistro[6];
    int     iCodCriterio    ;
    int     iTipo_Llamada   ;
    int     iTipo_SubGrupo  ;
}NUMORDEN;

typedef struct tagNumOrdenes
{
    int     iNumRegs;
    NUMORDEN  *stNumOrden;
}NUMORDENES;

typedef struct tagNumOrdenes_Hosts
{
    int     iNum_OrdenGr    [TAM_HOSTS_PEQ];
    int     iNum_OrdenSubGr [TAM_HOSTS_PEQ];
    int     iNum_OrdenConc  [TAM_HOSTS_PEQ];
    int     iCodGrupo       [TAM_HOSTS_PEQ];
    int     iCodSubGrupo    [TAM_HOSTS_PEQ];
    int     iCodConcepto    [TAM_HOSTS_PEQ];
    char    szCodRegistro   [TAM_HOSTS_PEQ][6];
    int     iCodCriterio    [TAM_HOSTS_PEQ];
    int     iTipo_Llamada   [TAM_HOSTS_PEQ];
    int     iTipo_SubGrupo  [TAM_HOSTS_PEQ];
}NUMORDENES_HOSTS;

/****************************************************************************/


typedef struct {
    long        lNumAbonado       [BUFF_ABONADO];
    long        lNumCelular       [BUFF_ABONADO];
    int         iCodProducto      [BUFF_ABONADO];
    int         iIndDetFact       [BUFF_ABONADO];
    int         iIndInterzona     [BUFF_ABONADO];
    int         iIndRoaming       [BUFF_ABONADO];
    int         iIndCarrier       [BUFF_ABONADO];
    int         iIndEspeciales    [BUFF_ABONADO];
    int         iIndLdi           [BUFF_ABONADO];
    int         iIndLocalDestino  [BUFF_ABONADO];
    int         iIndLocal         [BUFF_ABONADO];
    double      dImpFacturable    [BUFF_ABONADO];
    char        sznom_usuario     [BUFF_ABONADO][21];
    char        sznom_apellido1   [BUFF_ABONADO][21];
    char        sznom_apellido2   [BUFF_ABONADO][21];
    int         CantidadAbonados;
    
    /*P-ECU-10012*/
    int			iIndDetLlam       [BUFF_ABONADO];
    /*P-ECU-10012*/
} ST_ABONADO;


/* aeo 22/Ago/2000 */
typedef struct {
    char   szCodInforme   [7] ;
    long   lNumSecuInfo       ;
    int    iCodTipImpres      ;
    int    iCodTipDocum       ;
    char   szCodDespacho  [6] ;
    char   szNomArchivo   [255];
    long   lNumClientes       ;
    double dTotFactura        ;
    double dTotCuotas         ;
    double dTotPagar          ;
    double dTotSaldoAnt       ;
    double dLla_Locales_Neto  ;
    double dLla_Interna_Neto  ;
    double dLla_Roaming_Neto  ;
    double dLla_LargaDI_Neto  ;
    double dLla_Especia_Neto  ;
} FADCTLIMPRES;

typedef struct {
    int     iCorrMensaje[MAX_LINEAS_MENSAJES];
    int     iNumLinea   [MAX_LINEAS_MENSAJES];
    int     iCantCaract [MAX_LINEAS_MENSAJES];
    char    zsCodIdioma [MAX_LINEAS_MENSAJES][6];
}ST_MENSAJES;

typedef struct {
    char    szMensajes     [MAX_LINEAS_MENSAJES][201];
    int     iCantLineas;
}ST_MENSAJES_NOCICLO;

typedef struct {
    int     iCodFactCiclo;
    int     iCodFactExenCiclo;
    int     iCodBoletaCiclo;
    int     iCodBoletaExenCiclo;
}DOCUM_CICLO;

typedef struct {
    char    szDes     [MAX_GRUPOS][MAX_LARGOGRUPO];
    int     iPosition [MAX_GRUPOS];
    int     iLastPosition;
}ST_TABLA;

typedef struct {
    int     iCodGrupo             [MAX_GRUPOS]    ;
    char    szDesGrupo            [MAX_GRUPOS][51];
    double  dCostoFacturaNeto     [MAX_GRUPOS]    ;
    long    lSegundos             [MAX_GRUPOS]    ;
    int     iUnidades             [MAX_GRUPOS]    ;
    int     iCodConcepto          [MAX_GRUPOS]    ;
    char    szDesConcepto         [MAX_GRUPOS][61];
    int     iFacturable           [MAX_GRUPOS]    ;
    char    szKey                 [MAX_GRUPOS][60];
    long    lCntLlamReal          [MAX_GRUPOS]    ;
    long    lCntLlamDcto          [MAX_GRUPOS]    ;
    long    lCntLlamFAct          [MAX_GRUPOS]    ;
    long    lSegundosReal         [MAX_GRUPOS]    ;
    long    lSegundosDcto         [MAX_GRUPOS]    ;
    double  dCostoFacturaReal     [MAX_GRUPOS]    ;
    double  dCostoFacturaDcto     [MAX_GRUPOS]    ;
    int     iCantidad                             ;
    long    lTotalSeg                             ;
    double  dTotalCosto                           ;
    double  dGravPrimeraCategoria [MAX_GRUPOS]    ;
    double  dGravSegundaCategoria [MAX_GRUPOS]    ;
    double  dPorcPrimeraCategoria [MAX_GRUPOS]    ;
    double  dPorcSegundaCategoria [MAX_GRUPOS]    ;
    int     iNivelImpresion       [MAX_GRUPOS]    ;
    char    szTipUnidad           [MAX_GRUPOS][10];
    char    szTipGrupo            [MAX_GRUPOS][10];
    double  dImpValUnitario       [MAX_GRUPOS]    ;
    long    lNumVenta             [MAX_GRUPOS]    ;
    char    szNum_Celular         [MAX_GRUPOS][20+1];
    double  dSumDescuentos        [MAX_GRUPOS]    ; /* ECU-10012 */
    long    lCantDescuentos       [MAX_GRUPOS]    ; /* ECU-10012 */  
    double  dPrcImpuesto          [MAX_GRUPOS]    ; /* Inc-pre-189124  */  
}ST_TABLA_ACUM;

typedef struct {
    char    szKey       [MAX_GRUPOS][60] ;
    int     iSocalo     [MAX_GRUPOS]     ;
}ST_TABLA_ORDEN;

/*************** agregado por NELSON CONTRERAS informar a nicolas ********/

typedef struct {
    int     iCodConcepto[MAX_CONCEPTOS_TAR];
    int     iIndTabla   [MAX_CONCEPTOS_TAR];
    int     iNumConceptos;
}CONCEPTOS_TAR;


/************************************************************************/
/* Estructura para recoger los datos de la tabla FA_LLAMADASROA         */
/************************************************************************/

typedef struct stFa_LlamadasRoa
{
    int             iCodOperRoa         ;
    char            szNumMovil      [16];
    char            szFecLlamada    [22];
    char            szHraLlamada     [9];
    double          dImporte            ;
    long            lSegundos           ;
    char            iIndEntSal       [6];
    char            szNumDestino    [19];
    char            szDesDestino    [31];
    char            szFiller         [2];
    int             iCod_Carg           ;
    double          dImpLocal1          ;
    double          dImpLarga2          ;
    char            szDurLocal1     [10];
    char            szDurLarga2     [10];
	char            szTipTraf       [4]; /* MLA 123425*/
} DETROAMING;

/************************************************************************/
/* Estructura para recoger los datos de la tabla FA_DETFORTAS.          */
/************************************************************************/

typedef struct stFa_DetFortas
{
    int             iCodOperCarr        ;
    char            szFecLlamada    [11];
    char            szHraLlamada     [7];
    char            szNumDestino    [21];
    char            szDesDestino    [21];
    long            lSegundos           ;
    double          dNeto               ;
    char            szCodTrafico     [4];
    char            szFiller         [2];
} DETCARRIER;

typedef struct stFa_FadParametros
{
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
    int   iMaxRegImp      [MAX_TIPOS_REGISTROS];                             /* N° tipo max   */
} DETALLEOPER;

typedef struct tagCodPlanTarif
{
    char    szCod_Plantarif  [4];
    char    szDes_Plantarif  [31];
    char    szTip_Plantarif  [2];
    long    lMinutosPlan;
    double  dValorPlan;
    int     iInd_Arrastre;
}PLAN_TARIFARIO;


typedef struct tagCodplan
{
    int         iNumRegPlanTarif;
    PLAN_TARIFARIO      *stPlanesTarifarios;
}PLAN_TARIF;


typedef struct tagRegB4001_Host
{
    int         iPosicion     [TAM_HOSTS_PEQ];
    char        szCodAgrullam [TAM_HOSTS_PEQ][6];
}REG_B4001_HOST;

typedef struct tagRegB4001
{
    int         iPosicion;
    char        szCodAgrullam[6];
}REG_B4001;

typedef struct tagConfB4001
{
    int         iNumReg;
    REG_B4001   *stRegB4001;
}CONF_B4001;

typedef struct tagRegTipD_Host
{
    int         iPosicion     [TAM_HOSTS_PEQ];
    char        szCodRegistro [TAM_HOSTS_PEQ][6];
    char        szCodTipLlam  [TAM_HOSTS_PEQ][4];
    char        szCodValor    [TAM_HOSTS_PEQ][6];
	char        szTipTraf     [TAM_HOSTS_PEQ][4]; /*MLA 123425*/
}REGTIP_D_HOST;

typedef struct tagRegTipD
{
    int         iPosicion;
    char        szCodRegistro[6];
    char        szCodTipLlam [6];
    char        szCodValor   [6];
	char        szTipTraf    [4]; /*MLA 123425*/
}REGTIP_D;

typedef struct tagConfRegTipD
{
    int           iNumReg;
    REGTIP_D      *stRegTipD;
}CONF_REGTIP_D;


typedef struct tagCodPlanTarif_Hosts
{
    char    szCod_Plantarif  [MAX_PLANTARIF][4];
    char    szDes_Plantarif  [MAX_PLANTARIF][31];
    char    szTip_Plantarif  [MAX_PLANTARIF][2];
    long    lMinutosPlan     [MAX_PLANTARIF];
    double  dValorPlan       [MAX_PLANTARIF];
    int     iInd_Arrastre    [MAX_PLANTARIF];
}PLAN_TARIFARIO_HOSTS;


typedef struct tagTipoTraficoLD
{
    char    szCod_TipoTraficoLD [20];
    char    szNom_TipoTraficoLD [20];
    char    szDes_TipoTraficoLD [50];
}TIPO_TRAFICO_LD;


/****************************************************************************/
/*  Estructuras para carga de descripciones de Multiidiomas                 */
/****************************************************************************/
typedef struct tagMultiIdioma
{
    char    szCod_Idioma_Grupos[6];
    char    szGlosa_Grupo     [51];
    char    szGlosa_Subgrp    [51];
}GRPMULTIIDIOMA;

typedef struct tagMultiIdiomas
{
    int     iNumRegs;
    GRPMULTIIDIOMA *stGrpIdiomas;
}GRPMULTIIDIOMAS;

typedef struct tagMultiIdioma_Hosts
{
    char szCod_Idioma_Grupos[TAM_HOSTS_PEQ][6];
    char szGlosa_Grupo      [TAM_HOSTS_PEQ][51];
    char szGlosa_Subgrp     [TAM_HOSTS_PEQ][51];
}GRPMULTIIDIOMAS_HOSTS;


/****************************************************************************/
typedef struct
{
   long  lCodCliente       [MAX_ARRASTRE_ESTRUCTURA];
   long  lNumAbonado       [MAX_ARRASTRE_ESTRUCTURA];
   char  szCodBolsa        [MAX_ARRASTRE_ESTRUCTURA][6];
   char  szFecTasa         [MAX_ARRASTRE_ESTRUCTURA][11];
   int   iCodCiclo         [MAX_ARRASTRE_ESTRUCTURA];
   double dValBolsa        [MAX_ARRASTRE_ESTRUCTURA];
   char  szIndUnidad       [MAX_ARRASTRE_ESTRUCTURA][6];
   double dValArrastre     [MAX_ARRASTRE_ESTRUCTURA];
   double dValExpirado     [MAX_ARRASTRE_ESTRUCTURA];
   double dValDisponible   [MAX_ARRASTRE_ESTRUCTURA];
   double dValConsumo      [MAX_ARRASTRE_ESTRUCTURA];
   double dValResto        [MAX_ARRASTRE_ESTRUCTURA];
   char   szLlaveArrastre  [MAX_ARRASTRE_ESTRUCTURA][17];
   int    iCantidadArrastre;
}ST_DETARRASTRE;

typedef struct
{
   long   lCodCliente       [MAX_ARRASTRE_CURSOR];
   long   lNumAbonado       [MAX_ARRASTRE_CURSOR];
   char   szCodBolsa        [MAX_ARRASTRE_CURSOR][6];
   char   szFecTasa         [MAX_ARRASTRE_CURSOR][11];
   int    iCodCiclo         [MAX_ARRASTRE_CURSOR];
   double dValBolsa         [MAX_ARRASTRE_CURSOR];
   char   szIndUnidad       [MAX_ARRASTRE_CURSOR][6];
   double dValArrastre      [MAX_ARRASTRE_CURSOR];
   double dValExpirado      [MAX_ARRASTRE_CURSOR];
   double dValDisponible    [MAX_ARRASTRE_CURSOR];
   double dValConsumo       [MAX_ARRASTRE_CURSOR];
   double dValResto         [MAX_ARRASTRE_CURSOR];
   char   szLlaveArrastre   [MAX_ARRASTRE_CURSOR][17];
   int   iCantidadArrastre;
}ST_CURARRASTRE;

typedef  struct
{
    int     cod_parametro[MAX_FAD_PARAMETROS];
    char    des_parametro[MAX_FAD_PARAMETROS][1024];
    char    tip_parametro[MAX_FAD_PARAMETROS][32];
    int     val_numerico [MAX_FAD_PARAMETROS];
    char    val_caracter [MAX_FAD_PARAMETROS][512];
    char    val_fecha    [MAX_FAD_PARAMETROS][9];
    int     val_cantidad [MAX_FAD_PARAMETROS];
}ST_PARAMETROS;

typedef  struct
{
    char    szCodPlan              [MAX_MINUTOADICIONAL][6];
    char    szLlaveMinutoAdicional [MAX_MINUTOADICIONAL][7];
    double  dMtoAdicional          [MAX_MINUTOADICIONAL];
    int     iCantidadMinutoAdicional;
}ST_MINUTOADICIONAL;

typedef struct tagOpers_Hosts
{
    int     iCodOperador  [TAM_HOSTS_PEQ];
    char    szDesOperador [TAM_HOSTS_PEQ][31];
}CODOPER_HOSTS;

/*---------------------------------------------------------------------------*/
/* Estructura de entrada a la funcion                                        */
/*---------------------------------------------------------------------------*/
typedef struct reg_entrada
{
    long   lCodCliente ;
    long   lNumVenta   ;
    long   lNumProceso ;
    long   lCodConcepto;
    int    iColumna    ;
    char   szDesConcepto[60+1];
    char   szTipoDocum[1+1]; /* SAAM-20070431 Nueva variable para la estructura ,  P-ECU-06034 */
}reg_entrada;

/*---------------------------------------------------------------------------*/
/* Estructura de salida de la funcion                                        */
/*---------------------------------------------------------------------------*/
typedef struct reg_salida
{
    char   szNumSerie[25+1]    	;
    long   lNumAbonado         	;
    long   lCodConcepto        	;
    char   szDesConcepto[60+1] 	;
    long   lNumCelular          ;
    struct reg_salida * sgte;
}reg_salida;

typedef struct reg_salida stSalida;

typedef struct Tag_St_Dias
{
    char    szCategoria  [10] [9];
    int     iDias        [10];
    int     iCantidadRegs;

}ESTRUCT_DIAS;


char SV_Categoria  [1024];
char SD_fecha      [1024];

typedef struct RegConcRel
{
    int	  iCodConcep;
    int		iCodConcepRel;
    long  lNumAbonadoAux;
}REG_CONCREL;

REG_CONCREL sthConcRel[MAX_CONCEPTOS_LOCAL];       
       



/* ************************************************************************* */
/* *                          Estructuras Globales                         * */
/* ************************************************************************* */

stSalida            *lstSalida;

NUMORDENES          stNumOrdenes;
GRPMULTIIDIOMAS     stGrpMultiidiomas;
ESTRUCT_DIAS        stDias;
AUTORIZ_FOLIO 		stAutorizFolio;
AUTORIZ_FOLIO		stAutorizFolio_E; /*P-ECU-10039*/

ST_DETARRASTRE      sthDetArrastre;
ST_CURARRASTRE      sthCurArrastre;
ST_PARAMETROS       sthFadParametros;
ST_MINUTOADICIONAL  sthMinutoAdicional;

TIPDOCUM         pstTipDocum;
CODCLIENTE       pstCodCliente;
OFICINAS2        pstOficinas2;
VENDEDORES       pstVendedores;
OPERADORAS       pstOperadoras;

PLAN_TARIF       pstPlanes;

CONF_B4001       pstConfB4001;
CONF_REGTIP_D	 pstConfTipRegD;

DET_TRANSACCIONES pstDetTrans;

PROM_TRANFICOCLIE pstPromTrafClie;

DETCELULAR_AGRUP stDetLlamadasTAS;

DETLLAMADAS      stDetLlamadas;
DETCELULAR       stDetCelular;

TIPO_TRAFICO_LD  stTipoTrafico[MAX_TIPOS_LD];

int              igTipoCiclo;
long             lgNum_Proceso;
char             szgNombreArchivoAnomalias[128];
FILE             *fpAnomalias;

CODIMPTOSFACT     pstImptosFact;
CATIMPUESTOS      pstCatImpues;
char              szFec_Desde   [9];
char              szFec_Hasta   [9];

GEDPARAMETROS     stGedParametros;

MINPLANES         stMinutosPlanes;

long              lCodCiclFactAux;

CODOPERS          stOperadores;

STDETCONSUMOS     stFaDetCons;
ST_ORDENADO       stOrden2DetConsumo;
ST_ORDENADO       stOrden2DetConsumo_Dctos;
ST_ORDENADO       stOrden2DetConsumo_Cargos;

int igUsoCalculo;
int igUsoMuestra;


/*************************************/
/*   D-P-ECU-07052-FAC  Nro de Job   */
/*************************************/
extern long lNroJob;
extern int  iSecProceso;
extern int  iFlagSecReProc;

/* HOST_ID */
char              szgHostId[11];
long              lgCodClienteIni;
long              lgCodClienteFin;
int               igOpcionRango;



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

