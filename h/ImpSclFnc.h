#ifndef _ImpSclFnc_
#define _ImpSclFnc_

/*  Version  FAC_DES_MAS ImpSclFnc.h  7.000   */
#include <ImpSclSt.h>

char szPlan[4];
char sDescPlanTarif[100];

extern int      BuscaAbonado(ST_ABONADO *,int *,long );
extern int      CalculaDigVerif (double , int *  );
extern int      FillCodIdioma(char *);
extern int      FormatoHora(long , int  , char *);
extern int      RecupParam( int *, char *[], char *, int ) ;
extern int      RetPos(char *, ST_TABLA  *);
extern BOOL     bEscribeEnArchivo(FILE *, char * , char * );
extern BOOL     bfnInsertar_FadCTLImpres(ST_ACUMMTO *, LINEACOMANDO *, ST_INFGENERAL *, char *);
extern int      bfnAcumulaMontos(ST_ACUMMTO *, double, double, double, double );
extern int      bfnElimina_FadCTLImpres(LINEACOMANDO *);
extern int      FormateaDireccion(char *,char *);
extern int      iMakeDir(char *);
extern BOOL     bfnActualiza_ProcImpresion(LINEACOMANDO, BOOL );
extern BOOL     bfnActualiza_TrazaProceso(LINEACOMANDO, BOOL);
extern BOOL     bfnChequeaEstado (LINEACOMANDO *);
extern BOOL     bfnActualizaRegprocImpres (LINEACOMANDO);
extern BOOL     bfnOrdenaImpresionRC (ST_TABLA_ACUM  *, ST_TABLA_ORDEN *, int);

extern int      ObtieneIdiomaOperadora(ST_INFGENERAL *);

extern BOOL     CargaMultiIdiomas (GRPMULTIIDIOMA **, int *);
extern int      OpenMultiIdiomas ( void );
extern BOOL     FetchMultiIdiomas (GRPMULTIIDIOMAS_HOSTS *,int *);
extern int      CloseMultiIdiomas(void);
extern int      ifnCmpGrpMulti (const void *,const void *);
extern BOOL     BuscaMultiIdiomas (char *, GRPMULTIIDIOMA * );
extern void     vfnPrintGrpMulti (GRPMULTIIDIOMA *, int );

extern int      iGetMensajesNoCiclo(ST_MENSAJES_NOCICLO * ,long );
extern int      Open_MensNoCiclo ( long );
extern int      Fetch_MensNoCiclo (ST_MENSAJES_NOCICLO * );
extern int      Close_MensNoCiclo(void);
/* extern int      BuscaMascara(DETALLEOPER *,char *,int ,int); */
extern BOOL     BuscaMascara(DETALLEOPER *pstMascaraOper, char *szCodRegistro, int iTipDocum);

extern int      BuscaCodInterfact(long ,long,LINEACOMANDO *);
extern int      ChequeaInterfact(LINEACOMANDO );
extern int      busca_arrastre(char *,int *,int *);
extern int      CargaArrastre( long );
extern int      CargaFadParametros( void );
extern int      GargaGedParametros( void );
extern int      OpenFactDocuClie (LINEACOMANDO *);
extern int      FetchFactDocuClie( int * , int * );
extern int      CloseFactDocuClie (void);
extern int      buscaMinutoAdicional(char *,char *);
extern int      CargaMinutoAdicional( long ); /* PGG SOPORTE - 82815 - 16-03-2009 */
extern BOOL     bfnReg_Padre(LINEACOMANDO *ParEntrada);
extern BOOL     bfnCargaGedPar_MC();
extern BOOL     CargaNumOrden (NUMORDEN **, int *, int );
extern int      OpenNumOrden ( int );
extern BOOL     FetchNumOrden (NUMORDENES_HOSTS *,int *);
extern int      CloseNumOrden(void);
extern int      ifnCmpNumOrden (const void *,const void *);
extern BOOL     BuscaNumOrden (int , NUMORDEN *);
extern void     vfnPrintNumOrden (NUMORDEN *, int );
extern BOOL     CargaEstructuraInicial(NUMORDEN *, int );
extern int      szfnObtieneCod_autorizacion (LINEACOMANDO *);


int             ifnCmpCodCliente(const void *,const void *);
BOOL            bfnCargaGedPar();
BOOL            bfnCargaMinutosPlanes_MC(MINPLAN **, int *);

int             ifnCmpCod_PlanTarif(const void *,const void *);
BOOL            bfnCargaCod_Plantarif (PLAN_TARIFARIO **, int *);
int      		ifnOpenCod_Plantarif(void);
BOOL     		bfnFetchCod_Plantarif(PLAN_TARIFARIO_HOSTS *, int *);
int      		ifnCloseCod_Plantarif(void);
void            vfnPrintCod_PlanTarif (PLAN_TARIFARIO *, int );
BOOL            bfnFindCod_PlanTarif (char *, PLAN_TARIFARIO *);

char            *ltrim(char *s);
char            *rtrim(char *s);
char            *alltrim(char *s);

void            vfnPrintPagos (PAGO *, int );
int      		ifnClosePagos(void);
static BOOL     bfnFetchPagos (PAGO_HOSTS *,int *);
static int      ifnOpenPagos(long lCodCliente, long lCicloFact);

static int      ifnCloseDocsPeriodo(void);
static BOOL     bfnFetchDocsPeriodo (DOCPERIODO_HOSTS *,int *);
static int      ifnOpenDocsPeriodo(long ,char *, char *);
int             ifnLlenarSeriesDeVenta( reg_entrada *pstEntrada ,int iCodConcepto);
BOOL            bfnObtieneVentaRelacionada(long ,char *,int ,long ,long ,long *);
int             ifnObtenerMontosTotalesCuota(rg_cuotas , double *, double *);
int             ifnObtenerSeriesFactMiscela(reg_entrada *);
BOOL            bfnEsMovMiscelaneo(int , int );
int             ifnAgruparCuotas(rg_cuotas *, int , rg_cuotas *);
static          int ifnOpenMinPlanes( void );
static          BOOL bfnFetchMinPlanes(MINPLAN_HOSTS *pstHost,int *piNumFilas);
static          int ifnCloseMinPlanes(void);
void            vfnPrintMinPlanes (MINPLAN *, int );
int             ifnCmpMinPlanes(const void *,const void *);
BOOL            bfnGetGedParam(char * , char *, char *);

extern int      OpenAbonado (long , long ,DETALLEOPER *);
extern int      FetchAbonado (ST_ABONADO *);
extern int      CloseAbonado(void);
extern BOOL     fnGrabaAnoProceso (long , long , int , char *);

extern int      iTotalizaImpuestoFactura(void);
extern BOOL     bfnCategImpto(int , int *,double );
extern int      ifnCmpCodImptos (const void *,const void *);

extern BOOL     bfnTotImptosCateg(int ,int , double *, double *);

BOOL            bfnCargaDetTransClie ( DET_TRANSACCIONES *pstDetTransClie,
                                       ST_CICLOFACT      *sthFa_CicloFact, 
                                       long              lCodCliente, 
                                       long              lNumProceso,
                                       long              lCodCiclFact);
static int      ifnOpenDetTransClie  ( ST_CICLOFACT        *sthFa_CicloFact,long lCodCliente, long lCodCiclFact);
static BOOL     bfnFetchDetTransClie ( DET_TRANSACCIONES_CLIE_HOST * pst_DetTransClie, long *lCantDetTrans);
static int      ifnCloseDetTransClie ( void);

extern BOOL     bfnCargaCodImptoFact(CODIMPTOSFACT *);
extern BOOL     bfnCargaCodImptoCateg(CATIMPUESTOS *);
extern BOOL     bfnPorcenImptosCateg(double *, double * );
extern BOOL     bfnTipoImpuesto(int , int *,double );
extern BOOL     bfnLimpiaFlag(CATIMPUESTOS *);
extern BOOL     bfnCargaUltsPagos (PAGO **, int *, long, long );
extern BOOL     bfnCargaMinutosPlanes (MINPLAN **, int *);
extern BOOL     bfnFindMinPlan (char *, char *, MINPLAN *);

extern BOOL     bfnCargaPrimCateg (void);
extern BOOL     bfnFindCod_Operador (int , CODOPER *);
extern BOOL     bfnCargaOperadores (CODOPER **, int *);

static int      ifnOpenOperadores(void);
static BOOL     bfnFetchOperadores (CODOPER_HOSTS *,int *);
static int      ifnCloseOperadores(void);
int             ifnCmpOperadores(const void *,const void *);
void            vfnPrintOperadores (CODOPER *, int );
static int      ifnOpenConfB4001(void);
static BOOL     bfnFetchConfB4001 (REG_B4001_HOST *,int *);
static int      ifnCloseConfB4001(void);
extern BOOL     bfnCargaConfB4001 (REG_B4001 **, int *);

static int      ifnOpenRegistrosTipoD(void);
static BOOL     bfnFetchRegistrosTipoD (REGTIP_D_HOST *,int *);
static int      ifnCloseRegistrosTipoD(void);
extern BOOL     bfnCargaRegistrosTipoD (REGTIP_D **, int *);


extern BOOL     bfnCargarDocsPeriodo (DOCPERIODO **, int *, long , char *,char *);

extern BOOL     bfnGetPlanTarifAbo(long , long , char *);
extern BOOL     bfnFolioRelacionado(int ,long ,char *,long *,char *);

int             CargaStringSuspension(long );
int             GetParam( int *, char **, char *,int );
int             iCargaFechaSuspensionSt();
void            trim (const char *, char *);

int             ifnLiberaDetCons (void);
extern BOOL     bfnUpdTrazaJob(long, int );

extern BOOL     bCargaMascaraOperadora(DETALLEOPER * ,int);
extern int 		GetCiclFact(ST_CICLOFACT * ,long );
extern int      ManejoArchImp( LINEACOMANDO *, ST_INFGENERAL *, DETALLEOPER *, FILE **, ST_ACUMMTO *, char *);

extern BOOL     bfnValidaDespHostID (long lCodCiclFact, char *szCodDespacho, char *szHostId);
extern int      ifnCmpOrden(const void *cad1,const void *cad2);
extern BOOL bObtieneMascara( ST_ABONADO *pst_Abonados,CONCEPTOS_TAR *stConceptosTar,DETALLEOPER    *pst_MascaraOper);

extern BOOL bfnValidaCiclFactClie (long lCodCliente, long *lCodCiclFact);

extern BOOL bfnValidaVentaConcVarios(long lNumVenta);

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

