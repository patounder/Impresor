#ifndef _ImpresionScl_
#define _ImpresionScl_

/*  Version  FAC_DES_MAS ImpresionScl.h  7.000   */ 
#include <ImpSclFnc.h>
#include <shared_memory.h>

#define TABLA_MEMORIA  1
#define TABLA_CLIENTES 2
#define TABLA_NUMORDEN 3
#define TABLA_CODCLI   4

/***************************************************************************
                  Definicion de Funciones Prototipos
***************************************************************************/
/************************************************************************
                  FUNCIONES DE MEMORIA COMPARTIDA           
*************************************************************************/
extern BOOL CargaNumOrden_MC(NUMORDEN **, int *);
extern int separacion_de_memoria(int );
extern int unir_a_memoria(int ,int );
extern int crear_semaforo(int );
extern int get_cliente (int ,int );
extern int marca_cliente_facturado(int ,int );
extern void muestra_registro();
extern void muestra_registro_mc();
extern BOOL bfnCargaOperadores_MC(CODOPER **pstOper, int *iNumOperadores);

extern void muestra_parametros();
extern void muestra_parametros_ged();
extern void muestra_plan_tarifario();
extern void muestra_oficina_hosts2();
extern void muestra_vendedor_hosts2();
extern void muestra_tipdoc();
extern void muestra_ciclofact();
extern void muestra_operadora_hosts();
extern void muestra_conceptos_tar();
extern void muestra_codcli_hosts();
extern void muestra_detalleoper();
extern void muestra_minutoadicional();
extern void muestra_tabla_comandos();
extern int CargaFadParametrosMC();
extern int CargaFadParametros_GED_MC();
extern int bCargaMascaraOperadora_MC(DETALLEOPER *);
extern int GetCiclFact_MC(ST_CICLOFACT * ,long );
extern int bfnCargaCod_Plantarif_MC (PLAN_TARIFARIO **, int *);
extern int CargaMinutoAdicional_MC();
extern int bfnCargaOficinas2_MC(OFICINA2 **, int *);
extern int bfnCargaOperadora_MC(OPERADORA **, int *);
extern int bfnCargaTipDocum_MC (TIPDOC **, int *);
extern int bfnCargaVendedores_MC(VENDEDOR **, int *);
extern int bCargaConceptosTar_MC(CONCEPTOS_TAR *);

/***************************************************************************
                prototipos de ImpSclA
***************************************************************************/

extern int PutCaratula(ST_FACTCLIE *,FILE *,ST_MENSAJES *,ST_MENSAJES_NOCICLO *,STSALDO_ANTERIOR *,ST_CUOTAS *,ST_CICLOFACT *,DETALLEOPER *,char *,ST_BALANCE *,DET_TRANSACCIONES 	*, PROM_TRANFICOCLIE *, long, int);
extern int iGetMensajesCliente (long , char *, ST_MENSAJES * , int *, int , char *);

extern int iUpdateFactDocu (long , ST_FACTCLIE *, ST_ACUMMTO *);
extern int iUpdateFactDocu_MC (long , ST_FACTCLIE *, STSALDO_ANTERIOR *, ST_CUOTAS *, ST_BALANCE *,char *,int ,int);

extern int UnloadMensajes (char * , char * , int  , LINEACOMANDO *);
extern int GetDireccion(ST_FACTCLIE *);
extern int SaldoAntConcepto(STSALDO_ANTERIOR  * , long , ST_CICLOFACT *);
extern BOOL bfnCargaTipDocum (TIPDOC **, int *);
extern BOOL bfnCargaOficinas2 (OFICINA2 **, int *);
extern BOOL bfnCargaOperadora (OPERADORA **, int *);

/***************************************************************************
                prototipos de ImpSclB
***************************************************************************/
extern int bfnCargaPromTraficoClie(long, long, long, PROM_CLIE **, int *);
extern int CargaAbonadosdelCliente(ST_FACTCLIE * ,ST_ABONADO * ,LINEACOMANDO * ,DETALLEOPER *);
extern int CargaConceptosDelCliente (ST_FACTCLIE *, LINEACOMANDO *, ST_INFGENERAL *, DETALLEOPER *);
extern int CargaFolioCtc(ST_FACTCLIE * , ST_CUOTAS * ,  STSALDO_ANTERIOR *);
extern int CloseConceptos(void);
extern int GetCuotas(ST_CUOTAS *,long ,long , char *);/*RA-134 se grega parametro ciclo*/
extern int PutDetConsu(ST_ABONADO             *Abonado,
		                FILE                   *Fd_ArchImp,
		                ST_CUOTAS              *pstFaCuotas,
		                STSALDO_ANTERIOR       *SaldoTot,
		                ST_FACTCLIE            *pst_Cliente,
		                char                   * buffer,
		                DETALLEOPER            *st_MascaraOper,
		                DET_TRANSACCIONES      *pstDetTrans,
		                int                    iTasador,
		                long                   lCodCiclFact,
		                BOOL                   Flag_ExisCarrier);
extern int Update_CuotaCredito (ST_FACTCLIE * ,ST_CUOTAS *);
extern int CargaCodigoServicio(ST_FACTCLIE *,ST_INFGENERAL *,char *);
extern int ifnPreparaConsCuot (void);
extern int GetNumProcesoCiclo(LINEACOMANDO *);

/***************************************************************************
                prototipos de ImpSclD
***************************************************************************/

extern BOOL     bCargaConceptosTar(CONCEPTOS_TAR *);
extern BOOL     bfnDetLlamCarrier (ST_ABONADO *,ST_FACTCLIE *,int , int ,FILE *, char *, int *);
extern BOOL     bfnDetLlamRoaming  ( ST_ABONADO *, ST_FACTCLIE *, int , int , FILE *, char *, int *, int );

extern BOOL     bfnCargaTipoTraficoLD();
extern int      ifnPreparaConsTraf (void);

/***************************************************************************
               PROTOTIPOS COMUNES
***************************************************************************/
int  iMakeDir(char *);
int  CargInfGenAviPag(LINEACOMANDO *, ST_INFGENERAL *, DETALLEOPER *);
BOOL bfnCargaVendedores (VENDEDOR **, int *);
int CargInfGenComun(ST_INFGENERAL *,ST_CICLOFACT *,LINEACOMANDO *,int);

int Modulo_AVIPAG(ST_ABONADO           *,
                  ST_FACTCLIE          *,
                  LINEACOMANDO         *,
                  ST_CICLOFACT         *,
                  ST_INFGENERAL        *,
                  ST_CUOTAS            *,
                  FILE                 *,
                  ST_MENSAJES          *,
                  ST_MENSAJES_NOCICLO  *,
                  STSALDO_ANTERIOR     *,
                  DETALLEOPER          *,
                  CONCEPTOS_TAR        *,
                  char                 *,
                  ST_BALANCE           *,
                  DET_TRANSACCIONES    *,
                  PROM_TRANFICOCLIE    *);

int Procesa_AviPag(ST_FACTCLIE          *,     
                   FILE                 *,     
                   ST_MENSAJES          *,     
                   ST_MENSAJES_NOCICLO  *,     
                   STSALDO_ANTERIOR     *,     
                   ST_CUOTAS            *,     
                   ST_CICLOFACT         *,     
                   ST_ABONADO           *,     
                   DETALLEOPER          *,     
                   char                 *,     
                   ST_BALANCE           *,     
                   DET_TRANSACCIONES 	*,
                   PROM_TRANFICOCLIE    *,     
                   long                  ,     
                   char                 *,     
                   BOOL                  ,     
                   int );                      
                                               
BOOL ValidaCarrier();

extern BOOL bfnCargaCodImptoFact_MC(CODIMPTOSFACT *);
extern BOOL bfnCargaCodImptoCateg_MC(CATIMPUESTOS *);


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




