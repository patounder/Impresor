#ifndef _ImpSclD_
#define _ImpSclD_

/*  Version  FAC_DES_MAS ImpSclD.h  6.000   */
#include <ImpSclFnc.h>
#include <shared_memory.h>

BOOL  bfnCloseDetCarrier(void);
int   bfnCloseDetCelular(void);
BOOL  bfnCloseDetRoaming(void);
BOOL  bfnDetLlamCarrier (ST_ABONADO *,ST_FACTCLIE *,int , int ,FILE *, char *, int *, char *, char *);

BOOL  bfnDetLlamCelularTOL (ST_ABONADO *pst_Abonados,ST_FACTCLIE *pst_Cliente, int iIndice, FILE *fArchImp, char *szBuffer, int *bImprimioD1000, DETALLEOPER *pst_MascaraOper);

BOOL  bfnDetLlamCelular ( ST_ABONADO *pst_Abonados
                       , ST_FACTCLIE *pst_Cliente
                       , int iIndice
                       , int iTipoLlamada
                       , FILE *fArchImp
                       , char *szBuffer
                       , int *bImprimioD1000
                       , char *szCodRegistro
                       , char *szBuffer_Cursor);
BOOL  bfnDetLlamRoaming( ST_ABONADO *, ST_FACTCLIE *, int , int , FILE *, char *, int *, int, char *, char *);

int   ifnOraLeerTolTarifica (DETLLAMADAS_HOSTS  * pstLlamadasHost, int * piNumFilas);
int   ifnOraDeclaraTraficoTolTarifica (long lCodCliente, long lNumAbonado);
BOOL  bfnDeterminaGrupo(int iCodCargoHost,  DETCELULAR * pstDetCelular, long *lPosicion, NUMORDEN *pstNumOrden) ;
int   ifnOraCerrarTraficoTolTarifica ();
BOOL  bfnImprimeEstruc(DETCELULAR * pstDetCelular);
BOOL  bfnOrdenaEstructuras (DETCELULAR * pstDetCelular);

char  *szfnBuscaTipoTraficoLD(char *s);
BOOL  bfnObtieneTotalporTipoTrafico(long lCodCliente,long lNumAbonado,long lCodCiclFact,int iCodOperCarr,char *szCodTrafico,long *lSegundosTotal,double *dNetoTotal);
char  *szfnBuscaDescPortadora(int iCodOperador);

int ifnCompareszSec_Empa    (const void* cad1, const void* cad2);
int ifnCompareszSec_Cdr     (const void* cad1, const void* cad2);
int ifnCompareszTieIniLlam  (const void* cad1, const void* cad2);
int ifnCompareszNumMovil1   (const void* cad1, const void* cad2);
int ifnCompareszNumMovil2   (const void* cad1, const void* cad2);
int ifnComparedImpLocal1    (const void* cad1, const void* cad2);
int ifnComparedImpLarga2    (const void* cad1, const void* cad2);
int ifnCompareszCodFranHoraSoc  (const void* cad1, const void* cad2);
int ifnCompareszCodAlm      (const void* cad1, const void* cad2);
int ifnCompareszDesMovil2   (const void* cad1, const void* cad2);
int ifnCompareszDurLocal1   (const void* cad1, const void* cad2);
int ifnCompareszDurLarga2   (const void* cad1, const void* cad2);
int ifnCompareszIndEntSal1  (const void* cad1, const void* cad2);
int ifnComparedMto_Real     (const void* cad1, const void* cad2);
int ifnComparedMto_Dcto     (const void* cad1, const void* cad2);
int ifnCompareiDur_Real     (const void* cad1, const void* cad2);
int ifnCompareiDur_Dcto     (const void* cad1, const void* cad2);
int ifnCompareiCod_Carg     (const void* cad1, const void* cad2);
int ifnCompareDefault       (const void* cad1, const void* cad2);
int ifnCompareGrupoSubGrupo (const void* cad1, const void* cad2);

int ifnFetchDetCarrier(DETCARRIER * stDetCarrier);
int ifnFetchDetCelular(DETLLAMADAS_HOSTS  *pstLlamadasHost, int * piNumFilas);
int ifnFetchDetRoaming(DETROAMING *stDetRoaming);
int ifnOpenDetCarrier(long lCodCliente, long lNumAbonado,long lNumProceso, char *szhBufferCursor);
int ifnOpenDetCelular(long lCodCliente, long lNumAbonado, int iTipLlam, char *szBufferCursor);
int ifnOpenDetRoaming(long lCodCliente, long lNumAbonado,long lNumProceso,int, char *szhBufferCursor);

int put_D1000(ST_ABONADO *,FILE *, int, char *);

void vFreeEstructuras (DETCELULAR * pstDetCelular);
void vFreeEstructurasTAS (DETCELULAR_AGRUP * pstDetLlamadasTAS);

extern BOOL bfnTrataFactTrafico (ST_ABONADO *pst_Abonados,ST_FACTCLIE *pst_Cliente,FILE *fArchImp, int iCont, char *szBuffer,DETALLEOPER *pstMascaraOper,int iTasador, BOOL Flag_ExisCarrier);
extern int  ifnPreparaConsTraf (void);
extern BOOL bCargaConceptosTar(CONCEPTOS_TAR *);

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


