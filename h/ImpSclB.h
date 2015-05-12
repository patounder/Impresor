#ifndef _ImpSclB_
#define _ImpSclB_

/*  Version  FAC_DES_MAS ImpSclB.h  6.000   */
#include <ImpSclFnc.h>
#include <shared_memory.h>

#define NUMFILAS 100000
#define NUMHOST  30000
int  iContRegSS=0;

typedef struct 
{
    long  lNum_Abonado   [NUMFILAS]   ;
    int   iTip_serv      [NUMFILAS]   ;
    char  szCod_categoria[NUMFILAS][2];
    int   iCod_concepto  [NUMFILAS]   ;
    char  szDes_concepto [NUMFILAS][61];
    char  szFec_altacen  [NUMFILAS][9];
    char  szFec_bajabd   [NUMFILAS][9];
} SERVSUPLPLANES;


/* Fin P-ECU-12024*/
int OpenConceptos(long ,long ,char *, int ,DETALLEOPER *, int);
int FetchConceptos(ST_DETCONSUMO_HOST *pstConcTrafico, long *plNumFilas);
int CloseConceptos(void);

int ifnOpenPromosClie(long, long, long);
int ifnFetchPromosClie(PROM_CLIE_HOST * pst_PromClieHost, int *iCantPromos);
int ifnClosePromosClie(void);

int hay_b2000_b3000(FILE *,int ,int ,int, int,int *,int *,char *);
int put_b1000(ST_ABONADO *,FILE *,int , int , long,char *);
int put_b1200(FILE *Fd_ArchImp,int iRegConcep, ST_FACTCLIE *pst_Cliente, long lCodCiclFact, char * buffer);
int put_b2000_b3000(FILE *,int ,int , int *,int *,char *);
int put_b4001(FILE *,int,char *,ST_FACTCLIE *);
int put_b4002(FILE *,int,char *);
int put_b4003(FILE *,int,char *);
int put_b4004(FILE *,int,char *);
int put_b4005(FILE *,int,char *);
int put_b4006(FILE *,STSALDO_ANTERIOR *,int,char *);
int put_b4007(FILE *,rg_cuotas *,int ,int , int, long, char *);
int put_b4008(FILE *,int,char * ); 
int put_b5000(FILE *,DET_TRANSACCIONES *,int , int ,int ,int ,char *);
int put_b5010(FILE *,DET_MOVIM_CLIE  *, int,char *);
int put_b5020(FILE *,DET_PAGOS_CLIE  *, int, char *);
int put_b5030(FILE *,DET_MOVIM_CLIE  *, int,char *);
int put_b5040(FILE *,DET_PAGOS_CLIE  *, int, char *);
int put_b1300(FILE *Fd_ArchImp,int iRegConcep,char * buffer);
int put_b1500(FILE *Fd_ArchImp,int iRegConcep,char * buffer);

extern int bfnCargaPromTraficoClie(long, long, long, PROM_CLIE **, int *);

extern int CargaAbonadosdelCliente(ST_FACTCLIE * ,ST_ABONADO * ,LINEACOMANDO *  ,DETALLEOPER *);
extern int CargaConceptosDelCliente (ST_FACTCLIE    *, LINEACOMANDO   *, ST_INFGENERAL  *, DETALLEOPER    *);
extern int CargaFolioCtc(ST_FACTCLIE * , ST_CUOTAS * ,  STSALDO_ANTERIOR *);
extern int GetCuotas(ST_CUOTAS * pstFaCuotas,long lCicloFact,long lCodCliente, char *szFec_Vencimi);/*RA-134*/
extern int GetNumProcesoCiclo(LINEACOMANDO *);
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
extern BOOL bfnTrataFactTrafico (ST_ABONADO *,ST_FACTCLIE *,FILE *, int , char *,DETALLEOPER *,int, BOOL  );
extern int CargaCodigoServicio(ST_FACTCLIE *,ST_INFGENERAL *,char *);
extern BOOL bfnBuscaCategImpto(int iCodConcepto, int *iCodCategoria, double dPrcImpto);

extern int ifnPreparaConsCuot (void);

extern int iNumTerminales; /*AFGS - 38935*/

extern int iCargaServSuplan ( long lIndOrdenTotal, long lCodCiclFact, long lCod_cliente);

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

