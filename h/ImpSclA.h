#ifndef _ImpSclA_
#define _ImpSclA_

/*  Version  FAC_DES_MAS ImpSclA.h  6.000   */
/*#include <ImpSclSt.h>*/
#include <ImpSclFnc.h>
#include <shared_memory.h>
#define DEF_VAL_CONVERSION  1.0

int iNumTerminales;/*AFGS - 38935*/

int Put_A1000(FILE *, ST_FACTCLIE *,ST_CICLOFACT *, char * );
int Put_A1010(FILE *, ST_FACTCLIE *, char *, long);
int Put_A1100(FILE *, ST_FACTCLIE *, STSALDO_ANTERIOR *, ST_CUOTAS *, char *, ST_BALANCE *);
int Put_A1120(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, ST_CICLOFACT *sthFa_CicloFact, char *zsBufferImpresionArchivo, long lCodCiclFact);       /* P-COL-05011 20050809 */
int Put_A1130(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo);          /* P-COL-05011 20050809 */
int Put_A1150(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo, long lCodCiclFact) ;
int Put_A1200(FILE *, ST_FACTCLIE *, STSALDO_ANTERIOR *, ST_CUOTAS *, char *, ST_BALANCE *);
int Put_A1250(FILE *Fd_ArchImp, ST_CUOTAS *pstFaCuotas, char *zsBufferImpresionArchivo); /* P-ECU-05021 */
int Put_A1300(FILE *, ST_FACTCLIE *, char *);
int Put_A1400(FILE *, ST_FACTCLIE *, char *);
int Put_A1500(FILE *, ST_FACTCLIE *, char *);
int Put_A1700(FILE *, long , ST_CICLOFACT *, char *);
int Put_A1800(FILE *, ST_TABLA_ACUM *, STSALDO_ANTERIOR *, ST_CUOTAS *, char *, double dFact_Conversion); /* P-TMM-03075 */
int Put_A1900(FILE          *Fd_ArchImp, 
		      ST_TABLA_ACUM *sthTablaAcum, 
		      STSALDO_ANTERIOR *SaldoTot, 
		      ST_CUOTAS     *pstFaCuotas,  
		      char          *zsBufferImpresionArchivo, 
		      DETALLEOPER   *pst_MascaraOper, 
		      int            esNoCiclo,     /* se agrega ind nociclo */
		      ST_FACTCLIE   *FactDocuClie,
		      PROM_TRANFICOCLIE *pstPromTrafClie);
int Put_A1950(FILE *, PROM_TRANFICOCLIE *, char *, int);
int Put_A1960(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, ST_CICLOFACT *sthFa_CicloFact, char *zsBufferImpresionArchivo);
int Put_A2000(FILE *, ST_MENSAJES *, char *);
int Put_A2100(FILE *, ST_TABLA_ACUM , char *, double dFact_Conversion); /* P-TMM-03075 */
int Put_A2200(FILE *Fd_ArchImp, STSALDO_ANTERIOR *SaldoTot, ST_CUOTAS *pstFaCuotas, char *zsBufferImpresionArchivo, double dFact_Conversion); /* P-TMM-03075 */
int Put_A2400(FILE *, ST_FACTCLIE *, STSALDO_ANTERIOR *, ST_CUOTAS *, char *, ST_BALANCE *);
int Put_A2500(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, int iFlagMascaraA2600,int iFlagMascaraA2700, char *zsBufferImpresionArchivo);
int Put_A2600(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, long lNumVenta,int iCodConcepto,long lNumAbonado, char *pszDesConcepto, long lColumna,char *zsBufferImpresionArchivo);        /* P-COL-05011 20050811 */
int Put_A2700(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, int iCodConcepto, int iColumna, char *zsBufferImpresionArchivo);
int Put_A2800(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie,DET_TRANSACCIONES *pstDetTrans, char *zsBufferImpresionArchivo);

int ifnCmpTipDocum(const void *cad1,const void *cad2);
BOOL bfnCargaTipDocum (TIPDOC **pstTipDoc, int *iNumTipDocum);
static int ifnOpenTipDocums(void);
static BOOL bfnFetchTipDocums (TIPDOC_HOSTS *pstHost,int *piNumFilas);
static int ifnCloseTipDocums(void);
void vfnPrintTipDocums (TIPDOC *pstTipDoc, int iNumTipDocs);
BOOL bfnFindTipDocum (int iCodTipDocum, TIPDOC *pstTipDoc );


int ifnCmpOficinas2(const void *cad1,const void *cad2);
BOOL bfnCargaOficinas2 (OFICINA2 **pstOficinas2, int *iNumOficinas);
static int ifnOpenOficinas2 (void);
static BOOL bfnFetchOficinas2 (OFICINA_HOSTS2 *pstHost,int *piNumFilas);
int ifnCloseOficinas2 (void);
void vfnPrintOficinas2 (OFICINA2 *pstOficina, int iNumOficinas);
BOOL bfnFindOficina2 (char *szCodOficina, OFICINA2 *pstOficina );

int ifnCmpVendedores(const void *cad1,const void *cad2);
BOOL bfnCargaVendedores (VENDEDOR **pstVendedor, int *iNumVendedores);
static int ifnOpenVendedores(void);
static BOOL bfnFetchVendedores (VENDEDOR_HOSTS *pstHost,int *piNumFilas);
static int ifnCloseVendedores(void);
void vfnPrintVendedores (VENDEDOR *pstCodVend, int iNumVendedores);
BOOL bfnFindVendedores (long lCodigoVendedor, VENDEDOR *pstCodVende, long lCodCiclFact);

int ifnCmpOperadoras(const void *cad1,const void *cad2);
BOOL bfnFindOperadora (char *szCodOper, OPERADORA *pstOper );
BOOL bfnCargaOperadora (OPERADORA **pstOper, int *iNumOperadoras);
static int ifnOpenOperadoras (void);
static BOOL bfnFetchOperadoras (OPERADORA_HOSTS *pstHost,int *piNumFilas);
int ifnCloseOperadoras (void);
void vfnPrintOperadoras (OPERADORA *pstOper, int iNumOper);

extern int PutCaratula(ST_FACTCLIE *,FILE *,ST_MENSAJES *,ST_MENSAJES_NOCICLO *,STSALDO_ANTERIOR *,ST_CUOTAS *, ST_CICLOFACT *, DETALLEOPER *,char *, ST_BALANCE *,DET_TRANSACCIONES *, PROM_TRANFICOCLIE *, long, int);
extern int iGetMensajesCliente (long , char *, ST_MENSAJES * , int *, int , char * );
extern int iUpdateFactDocu (long , ST_FACTCLIE *, ST_ACUMMTO *);
extern int iUpdateFactDocu_MC (long , ST_FACTCLIE *, STSALDO_ANTERIOR *, ST_CUOTAS *, ST_BALANCE * ,char *,int,int);
extern int UnloadMensajes ( char * , char * , int  , LINEACOMANDO * );
extern int GetDireccion(ST_FACTCLIE *);
extern int SaldoAntConcepto(STSALDO_ANTERIOR  * , long , ST_CICLOFACT *);
extern int iCargaFechaSuspension(long lCodCateg, char *sFVencim, char *sFecSuspen);	

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

