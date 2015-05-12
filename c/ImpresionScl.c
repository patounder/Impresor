
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[21];
};
static const struct sqlcxp sqlfpn =
{
    20,
    "./pc/ImpresionScl.pc"
};


static unsigned int sqlctx = 55328907;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,31,0,0,
5,0,0,1,47,0,4,902,0,0,1,0,0,1,0,2,3,0,0,
24,0,0,2,0,0,29,1475,0,0,0,0,0,1,0,
39,0,0,3,0,0,31,1480,0,0,0,0,0,1,0,
54,0,0,4,157,0,3,1554,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,
81,0,0,5,56,0,2,1575,0,0,1,1,0,1,0,1,3,0,0,
100,0,0,6,0,0,29,1584,0,0,0,0,0,1,0,
115,0,0,7,157,0,3,1590,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,
142,0,0,8,0,0,29,1613,0,0,0,0,0,1,0,
};


/*  Version  FAC_DES_MAS ImpresionScl.pc  7.000   */
/***************************************************************************
iNivel :   (de mayor a menor prioridad)
 0   Msg Oracle                         \n\tError Oracle (%s): %s\n
     vDTrazasLog("nombre de funcion",
                 "mensaje de error (%s/%s)",
                 LOG00,
                 param1,
                 param2);
 1   Msg Errores graves y leves         \n\tError (%s): %s\n
     vDTrazasLog("nombre de funcion",
                 "mensaje de error (%s/%s)",
                 LOG01,
                 param1,
                 param2);
 2   Msg Avisos                         \n\tAviso (%s): %s\n
     vDTrazasLog("nombre de funcion",
                 "mensaje de aviso (%s/%s)",
                 LOG02,
                 param1,
                 param2);
 3   Msg Trazas                         \n%s
     vDTrazasLog("",
                 "mensaje o (%s/%s)",
                 LOG03,
                 param1,
                 param2);
 4   Msg Trazas menor prioridad         \n%s
     vDTrazasLog("",
                 "mensaje o (%s/%s)",
                 LOG04,
                 param1,
                 param2);

vDTrazasLog ("funcion main", szformato,iNivel,msj1,msj2,...,msjn);

si se quiere imprimir a un archivo hacer open al fd: stStatus.LogFile

por parametro se setea stStatus.LogNive¬
que indica hasta que nivel se imprimiran los mensajes (<=)
igual a 4 se imprime todo ...

***************************************************************************/


/***********************************************************************
Prog    : NUEVO FORMATO DE ARCHIVO DE IMPRESION DOCUMENTOS FACTURACION
Fecha   : Fri May 24 12:28:50 2002
Autor   :
********************************************************************** */
#include "ImpresionScl.h"
#include <utils.h>

char szUsage[]= "\n\t**********************************************************************"
                "\n\tDescripcion:[ImpresionScl]"
                "\n\t\tProceso de Impresion."
                "\n\t**********************************************************************"
                "\n\tModo de Uso:"
                "\n\t\tImpresionScl -u Usuario/Password"
                "\n\t\t\t\t-c Ciclo Facturacion"
                "\n\t\t\t\t-t Tipo Documento"
                "\n\t\t\t\t-d Codigo Despacho"
                "\n\t\t\t\t-s Numero de Secuencia"
                "\n\t\tOPCIONES:"
                "\n\t\t\t\t-n [Numero Proceso] "
                "\n\t\t\t\t-l [LogNivel] "
                "\n\t\t\t\t-r Reproceso "
                "\n\t\t\t\t-i [CodIdioma] "
                "\n\t\t\t\t-y [Cliente inicio] "
                "\n\t\t\t\t-z [cliente termino] "
                "\n\t\t\t\t-b [Fecha inicio] "
                "\n\t\t\t\t-e [Fecha termino] "
                "\n\t\t\t\t-g [Bytes a alocatear] "
                "\n\t\t\t\t-m Memoria compartida "
                "\n\t\t\t\t-p [Numero Proceso para Clasificacion de Anomalias] "
                "\n\t\t\t\t-j [Numero de Job] "
                "\n"
                "\n\tEjemplo: "
                "nohup $XPF_EXE/ImpresionScl -u / -c 51101 -l 5 -t 2 -d DESNO -s 1&";


/****************************************************************************/
/*           Variables de Retorno de Oracle-Pro-C                           */
/****************************************************************************/
/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

/*  */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


/***********************************************************************************/
int COD_PROCESO = NRO_COD_PROCESO ;

int  iSecProceso=0;
int  iFlagSecReProc=FALSE;
long lNroJob=0;

int CargInfGenComun(ST_INFGENERAL * pstInformGeneral,
                    ST_CICLOFACT * pstCicloFact,
                    LINEACOMANDO * pstLineaComando,
                    int Cod_Formulario)
{
	strcpy (szModulo, "CargInfGenComun");

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

/*--------------------------------------------------------------------------------
    OBTENCION DEL IDIOMA DE LA OPERADORA
  -------------------------------------------------------------------------------*/
    if ( !ObtieneIdiomaOperadora(pstInformGeneral) )
    {
        vDTrazasLog(szModulo, "Error en ejecucion de ObtieneIdiomaOperadora ", LOG01);
        return(FALSE);
    }
    vDTrazasLog(szModulo,"\t\t ObtieneIdiomaOperadora:szIdiomaOper(%s)",LOG04, pstInformGeneral->szIdiomaOper);

    /*-----------------------------------------------------------------------------
      OBTENCION DE CICLO DE FACTURACION :
    -----------------------------------------------------------------------------*/
    if ( pstLineaComando->lCodCiclFact )
    {
        if ( !flg_mc )
        {
	        if ( !bfnCargaCod_Plantarif(&pstPlanes.stPlanesTarifarios, &pstPlanes.iNumRegPlanTarif) )
	        {
	            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCod_Plantarif ", LOG01);
	            return(FALSE);
	        }
            if ( !GetCiclFact(pstCicloFact,pstLineaComando->lCodCiclFact) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de GetCiclFact ", LOG01);
                return(FALSE);
            }
            if ( !bfnCargaGedPar() )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaGedPar ", LOG01);
                return(FALSE);
            }
            if ( !bfnCargaMinutosPlanes(&stMinutosPlanes.stMinPlan,&stMinutosPlanes.iNumRegs ) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaMinutosPlanes ", LOG01);
                return(FALSE);
            }
            if ( !CargaMinutoAdicional(pstLineaComando->lCodCiclFact) ) /* PGG SOPORTE - 82815 - 16-03-2009 */
            {
                vDTrazasLog(szModulo, "Error en ejecucion de CargaMinutoAdicional", LOG01);
                return(FALSE);
            }
            if ( !CargaNumOrden (&stNumOrdenes.stNumOrden, &stNumOrdenes.iNumRegs, Cod_Formulario) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de CargaNumOrden ", LOG01);
                return(FALSE);
            }
        }
        else
        {
	        if ( !bfnCargaCod_Plantarif_MC(&pstPlanes.stPlanesTarifarios, &pstPlanes.iNumRegPlanTarif) )
	        {
	            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCod_Plantarif_MC ", LOG01);
	            return(FALSE);
	        }
            if ( !GetCiclFact_MC(pstCicloFact,pstLineaComando->lCodCiclFact) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de GetCiclFact_MC ", LOG01);
                return(FALSE);
            }
            if ( !bfnCargaMinutosPlanes_MC(&stMinutosPlanes.stMinPlan,&stMinutosPlanes.iNumRegs) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaDatDominio_MC ", LOG01);
                return(FALSE);
            }
            if ( !bfnCargaGedPar_MC() )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaGedPar_MC ", LOG01);
                return(FALSE);
            }
            if ( !CargaMinutoAdicional_MC() )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de CargaMinutoAdicional_MC", LOG01);
                return(FALSE);
            }
            if ( !CargaNumOrden_MC(&stNumOrdenes.stNumOrden, &stNumOrdenes.iNumRegs) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de CargaNumOrden_MC ", LOG01);
                return(FALSE);
            }
        }

        vDTrazasLog(szModulo,"\t\t GetCiclFact:szFec_Emision(%s)",LOG04, pstCicloFact->szFec_Emision);

        /*-----------------------------------------------------------------------------
         OBTENCION DEL NUMERO DE PROCESO DEL CICLO :
        -----------------------------------------------------------------------------*/
        if(!lNroJob)
        {
            if ( !GetNumProcesoCiclo(pstLineaComando) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion de GetNumProcesoCiclo ", LOG01);
                return(FALSE);
            }
        }
        else
        {
            pstLineaComando->lNumProceso=pstLineaComando->lCodCiclFact;
        }
        vDTrazasLog(szModulo,  "\t\tNumero de Proceso  [%ld]" ,LOG05,pstLineaComando->lNumProceso);

        /*---------------------------------------------------------------------------
         OBTENCION DEL LOS NUMEROS DE ORDEN DE GRUPOS, SUBGRUPOS Y CONCEPTOS
          ---------------------------------------------------------------------------*/
        if ( !CargaArrastre(pstLineaComando->lCodCiclFact) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de CargaArrastre", LOG01);
        }
        
        
        /*---------------------------------------------------------------------------
         OBTENCION DEL CONFIGURACION DE REGISTROS B4001
        ---------------------------------------------------------------------------*/
        if ( !bfnCargaConfB4001(&pstConfB4001.stRegB4001, &pstConfB4001.iNumReg))
        {
            vDTrazasLog(szModulo, "Error en ejecucion de CargaConfB4001", LOG01);
        }
        
        /*---------------------------------------------------------------------------
         OBTENCION DEL CONFIGURACION DE REGISTROS TIPO D
        ---------------------------------------------------------------------------*/
        if ( !bfnCargaRegistrosTipoD(&pstConfTipRegD.stRegTipD, &pstConfTipRegD.iNumReg))
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaRegistrosTipoD", LOG01);
        }
        
    }
    else
    {
        sprintf(pstCicloFact->fec_desde,"%8.8s\n","20010101");
        sprintf(pstCicloFact->fec_hasta,"%8.8s\n","20010101");
        sprintf(pstCicloFact->szFec_Emision,"%8.8s\n","20010101");
    }

    if ( !bfnCargaPrimCateg () )
    {
        vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaPrimCateg ", LOG01);
        return(FALSE);
    }


    /*-----------------------------------------------------------------------------
      CARGADO DE FORMATO DECIMALES :
      -----------------------------------------------------------------------------*/
    if ( !bGetParamDecimales () )
    {
        vDTrazasError(szModulo, "\n\n\tError obtencion de parametros Decimales ", LOG01 );
        return (FALSE);
    }

    /*-----------------------------------------------------------------------------
      OBTENCION DEL MULTIIDIOMA :
      -----------------------------------------------------------------------------*/
    if ( !CargaMultiIdiomas(&stGrpMultiidiomas.stGrpIdiomas, &stGrpMultiidiomas.iNumRegs) )
    {
        vDTrazasLog(szModulo, "Error en ejecucion de CargaMultiIdiomas ", LOG01);
        return(FALSE);
    }

    if ( !flg_mc )
    {
        if ( !bfnCargaCodImptoFact(&pstImptosFact) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCodImptoFact ", LOG01);
            return(FALSE);
        }
        if ( !bfnCargaCodImptoCateg(&pstCatImpues) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCodImptoCateg ", LOG01);
            return(FALSE);
        }
        if ( !bfnCargaOperadores(&stOperadores.stOper,&stOperadores.iNumRegs) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaOperadores ", LOG01);
            return(FALSE);
        }
    }
    else
    {
        if ( !bfnCargaCodImptoFact_MC(&pstImptosFact) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCodImptoFact_MC ", LOG01);
            return(FALSE);
        }
        if ( !bfnCargaCodImptoCateg_MC(&pstCatImpues) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaCodImptoCateg_MC ", LOG01);
            return(FALSE);
        }
        if ( !bfnCargaOperadores_MC(&stOperadores.stOper,&stOperadores.iNumRegs) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaOperadores_MC ", LOG01);
            return(FALSE);
        }
    }

    if ( !bGetDatosGener(&stDatosGener, szSysDate) )
    {
        vDTrazasError(szModulo, "\n\n\tError obtencion de datos FA_DATOSGENER ", LOG01 );
        return (FALSE);
    }

    return(TRUE);
}
/***********************************************************************************/
	int CargaInfCliente(
	                   ST_FACTCLIE          * FacCli,
	                   LINEACOMANDO         * Param,
	                   ST_MENSAJES          * Mensajes,
	                   ST_MENSAJES_NOCICLO  * Mensajes_NoCiclo,
	                   STSALDO_ANTERIOR     * Saldo,
	                   ST_CICLOFACT         * CicloFact,
	                   ST_CUOTAS            * pstFaCuotas,
	                   ST_INFGENERAL        * pstInfGeneral,
	                   DETALLEOPER          * pst_MascaraOper
	                   )
	{
	
	    int CantMsj;
	    char *szModulo="CargaInfCliente";
	
	    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);
	
	    /*-----------------------------------------------------------------------------
	      GET CUOTAS
	      -----------------------------------------------------------------------------*/
	    if ( Param->lCodCiclFact )
	    {
	        if ( !GetCuotas(pstFaCuotas,Param->lCodCiclFact,FacCli->lCodCliente,FacCli->szFecVencimie) )/*RA-0134 agrega parametro a llamda de cuotas*/
	        {
	            vDTrazasLog(szModulo,  "GetCuotas retorno NOOK" ,LOG01);
	        }
	
	        /*  -----------------------------------------------------------------------------
	            SALDO ANT CONCEPTO
	            -----------------------------------------------------------------------------*/
	        if ( !SaldoAntConcepto(Saldo, FacCli->lCodCliente, CicloFact ) )
	        {
	            vDTrazasLog(szModulo,  "SaldoAntConcepto retorno NOOK" ,LOG04);
	        }
	
		    /*-----------------------------------------------------------------------------
		      GET FOLIO
		      -----------------------------------------------------------------------------*/
	        if ( !CargaFolioCtc(FacCli,pstFaCuotas,Saldo) )
	        {
	            vDTrazasLog(szModulo,  "CargaFolioCtc retorno NOOK" ,LOG01);
	            return(FALSE);
	        }
	    }
	    /*-----------------------------------------------------------------------------
	      GET DIRECCION
	      -----------------------------------------------------------------------------*/
	    if ( !GetDireccion(FacCli) )
	    {
	        vDTrazasLog(szModulo,  "GetDireccion retorno NOOK" ,LOG01);
	        return(FALSE);
	    }
	    /*-----------------------------------------------------------------------------
	      GET MENSAJES CLIENTE
	      -----------------------------------------------------------------------------*/
	    if ( BuscaMascara(pst_MascaraOper,"A2000",FacCli->iCodTipDocum) )
	    {
	        if ( !iGetMensajesCliente(FacCli->lCodCliente,
	                                  FacCli->szCod_Idioma,
	                                  Mensajes,
	                                  &CantMsj,
	                                  pst_MascaraOper->iCodFormulario,
	                                  pst_MascaraOper->szIndFacturado) )
	        {
	            vDTrazasLog(szModulo,  "iGetMensajesCliente retorno NOOK:CantMsj(%d)" ,LOG01,CantMsj);
	            return(FALSE);
	        }
	    }
	    if ( BuscaMascara(pst_MascaraOper,"A2300",FacCli->iCodTipDocum) )
	    {
	        if ( !iGetMensajesNoCiclo(Mensajes_NoCiclo,FacCli->lNumProceso) )
	        {
	            vDTrazasLog(szModulo,  "iGetMensajesNoCiclo retorno NOOK" ,LOG01);
	            return(FALSE);
	        }
	    }
	    /*-----------------------------------------------------------------------------
	      GET CODIGO SERVICIO
	      -----------------------------------------------------------------------------*/
	    if ( !CargaCodigoServicio( FacCli, pstInfGeneral, pst_MascaraOper->szServicio) )
	    {
	        vDTrazasLog("CargaInfCliente",  "CargaCodigoServicio retorno NOOK" ,LOG01);
	        return(FALSE);
	    }
	
	    return(TRUE);
	}
/*************************************************************/
/*  Funcione Generales                                      */
/************************************************************/

/*****************************************************************************/
/*  Rutina que recupera informacion del periodo de facturacion desde la      */
/*  tabla FA_CICLFACT.                                                       */
/*****************************************************************************/

/*-----------------------------------------------------------------------------
EL PROCESO DEBE PODER DEFINIR CIERTOS PARAMETROS QUE ESPECIFICARAN LOS REGISTROS
QUE ESTE PROCESARA, LOS PARAMETROS SON:
1. CICLO
2. COD_IDIOMA
3. TIPO DE DOCUMENTO
4. CODIGO DE DESPACHO.
5. CLIENTE PUNTUAL PARA REPROCESO (PASANDO EL IND_ORDENTOTAL)
-----------------------------------------------------------------------------*/
int CheckParamEntrada(int argc, char * const argv[], LINEACOMANDO * StParam)
{
    char * psztmp = "";
    char opt[] = "u:c:l:s:i:t:d:y:z:n:b:e:g:j:x:m:r:p:";
    char szaux[10];
    char szUsuario[63] = "";
    int  bOptUsuario;
    int  bOptNoCiclo = FALSE;
    int  bOptNumProc = FALSE;
    int  iOpt = 0;
    int  LargoCodDesp = 0;
    extern  char * optarg;

    char *szModulo="CheckParamEntrada";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(StParam,0,sizeof(LINEACOMANDO));
    StParam->iReproceso=FALSE;
    StParam->lNum_SecuInfo = 0;
    StParam->lProceso= 0;

/*   D-P-ECU-07052-FAC  Nro de Job   */
    lNroJob = 0;


    while ( (iOpt = getopt(argc,argv,opt)) != EOF )
    {
        switch ( iOpt )
        {
            case 'u':
                /*-------------------------------------
                  USUARIO DE CONEXION ORACLE:
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    strcpy(szUsuario, optarg);
                    bOptUsuario = TRUE;
                }
                break;
            case 'c':
                /*-------------------------------------
                  1: CICLO A PROCESAR :
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    strcpy(szaux,optarg);
                    StParam->lCodCiclFact = atol(szaux);
                }
                printf("\n******* Ciclo Facturacion %ld *******\n", StParam->lCodCiclFact);
                break;
            case 'l':
                /*-------------------------------------
                  NIVEL DE LOG :
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    stStatus.LogNivel = (atoi (optarg) > 0)? atoi (optarg):iLOGNIVEL_DEF ;
                }
                printf("\n******* NIVEL DE LOG %d *******\n", stStatus.LogNivel);
                break;
            case 's':
                if ( _strlen (optarg) )
                {
                    StParam->lNum_SecuInfo = atol(optarg);
                }
                printf("\n******* Numero de Secuencia %ld *******\n", StParam->lNum_SecuInfo);
                break;
            case 'i':
                /*-------------------------------------
                  CODIGO DE IDIOMA A PROCESAR
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    strcpy(StParam->szCodIdioma, optarg);
                }
                printf("\n******* Codigo de Idioma %s *******\n", StParam->szCodIdioma);
                break;
            case 't':
                /*-------------------------------------
                  TIPO DE DOCUMENTO:
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    StParam->iCodTipDocum = (atoi(optarg)>0)?atoi(optarg):1;
                }
                printf("\n******* Tipo Documento %d *******\n", StParam->iCodTipDocum);
                break;
            case 'd':
                /*-------------------------------------
                  CODIGO DE DESPACHO
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    if ( _strlen(optarg) > 5 )
                    {
                        LargoCodDesp = 1;
                    }
                    strcpy(StParam->szCodDespacho, optarg);
                    bOptUsuario = TRUE;
                }
                printf("\n******* Codigo Despacho %s *******\n", StParam->szCodDespacho);
                break;
            case 'y':
                /*-------------------------------------
                  CODIGO DE CLIENTE INICIO
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    StParam->cod_clienteinic = (atoi(optarg)>0)?atoi(optarg):1;
                }
                printf("\n******* Cliente Inicio %ld *******\n", StParam->cod_clienteinic);
                break;
            case 'z':
                /*-------------------------------------
                  CODIGO DE CLIENTE TERMINO
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    StParam->cod_clientefina = (atoi(optarg)>0)?atoi(optarg):1;
                }
                printf("\n******* Cliente Termino %ld *******\n", StParam->cod_clientefina);
                break;
            case 'n':
                /*-------------------------------------
                  NO CICLO / proceso :
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    StParam->lProceso = atol(optarg);
                    bOptNoCiclo = TRUE;
                    if ( StParam->lProceso )
                    {
                        bOptNumProc = TRUE;
                        vDTrazasLog(szModulo,"Opcion -n despues StParam->lProceso = [%ld]", LOG02, StParam->lProceso);
                    }
                }
                printf("\n******* Numero Proceso %ld *******\n", StParam->lProceso);
                break;
            case 'b':
                /*-------------------------------------
                  FECHA DE INGRESO INICIO
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    strcpy(StParam->szFecIngBegin, optarg);
                    bOptNoCiclo = TRUE;
                }
                printf("\n******* Fecha Inicio %s *******\n", StParam->szFecIngBegin);
                break;
            case 'e':
                /*-------------------------------------
                  FECHA DE INGRESO TERMINO
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    strcpy(StParam->szFecIngEnd, optarg);
                    bOptNoCiclo = TRUE;
                }
                printf("\n******* Fecha Termino %s *******\n", StParam->szFecIngEnd);
                break;
            case 'g':
                /*-------------------------------------
                  CANTIDAD DE BYTES A ALOCAR EN MEMORIA
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    total_regs=atoi(optarg);
                }
                printf("\n******* Bytes a alocatear %d *******\n", total_regs);
                break;
            case 'j':
                /*-------------------------------------
                  JOB a PROCESAR :
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    lNroJob = atol(optarg);
                    COD_PROCESO= NRO_COD_PROCESO_JOB ;
                    printf("\n******* Simulacion de Impresion JOB Nro %ld *******\n", lNroJob);
                }
                break;
            case 'x':
                /*-------------------------------------
                  Secuencia de Proceso:
                  -------------------------------------*/
                if ( _strlen (optarg) )
                {
                    iSecProceso = atoi(optarg);
                    iFlagSecReProc=TRUE;
                    printf("\n******* Impresion JOB Nro %ld Secuencia %d *******\n", lNroJob, iSecProceso);
                }
                break;
            case 'm':
                /*-------------------------------------
                  OPCION PARA MEMORIA COMPARTIDA:
                  -------------------------------------*/
                flg_mc=TRUE;
                printf("\n******* Impresion modo Memoria Compartida *******\n");
                break;
            case 'r':
                /*-------------------------------------
                  SI SE DESEA HACER UN REPROCESO :
                  -------------------------------------*/
                StParam->iReproceso=TRUE;
                printf("\n******* Reproceso *******\n");
                break;
        }
    }

    if ( stStatus.LogNivel <= 0 )
        stStatus.LogNivel = iLOGNIVEL_DEF;

    /*-----------------------------------------------------------------------------
      VERIFIACION DE PARAMETROS MANDATORIOS :
      -----------------------------------------------------------------------------*/
    if ( !bOptUsuario )
    {
        fprintf (stderr, "\n\t#Falta usuario/password en parametros de entrada:\n%s\n", szUsage);
        return(2);
    }
    else
    {
        if ( (psztmp=(char *)strstr (szUsuario,"/"))==(char *)NULL )
        {
            fprintf (stderr,"\n\tUsuario Oracle no Valido\n%s\n",szUsage);
            return(3);
        }
        else
        {
            strncpy (StParam->szUser,szUsuario,psztmp-szUsuario);
            strcpy  (StParam->szPass, psztmp+1)                 ;
            fprintf (stderr,"\n\tStParam->szUser [%s]\n",StParam->szUser);
            fprintf (stderr,"\n\tStParam->szpass [%s]\n",StParam->szPass);
        }
    }

    if ( bOptNoCiclo )
    {
        if ( bOptNumProc )
        {
            StParam->iTipoCiclo = 1;
            if ( StParam->lProceso == 0 )
            {
                fprintf (stderr, "\n\t#Falta Numero de proceso en earametros de entrada:\n%s\n", szUsage);
                return(1);
            }
        }
    }
    else
    {
        StParam->iTipoCiclo = 0;
        if ( StParam->lCodCiclFact == 0 )
        {
            fprintf (stderr, "\n\t#Falta codigo de ciclo parametros de entrada:\n%s\n", szUsage);
            return(1);
        }
        if ( StParam->lNum_SecuInfo == 0 )
        {
            fprintf (stderr, "\n\t#Falta Numero de secuencia en parametros de entrada:\n%s\n", szUsage);
            return(1);
        }

        if ( StParam->lCodCiclFact < 1000 || StParam->lCodCiclFact > 999999 )
        {
            fprintf (stderr, "\n\t# Ciclo de Facturacion Invalido:\n%s\n", szUsage);
            return(1);
        }

        if ( StParam->iCodTipDocum < 0 || StParam->iCodTipDocum > 99 )
        {
            fprintf (stderr, "\n\t# Tipo de Documento Invalido:\n%s\n", szUsage);
            return(1);
        }

        if ( LargoCodDesp == 1 )
        {
            fprintf (stderr, "\n\t# Codigo de Despacho Invalido:\n%s\n", szUsage);
            return(1);
        }
    }
    return(0);
}
/**************************************************************************************/


int CargInfGenAviPag(LINEACOMANDO   * pstLineaComando,
                     ST_INFGENERAL  * sthFa_InfGeneral,
                     DETALLEOPER    * pst_MascaraOper)
{

    char *szModulo="CargInfGenAviPag";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);
    /*-----------------------------------------------------------------------------
      INSERCION DE MENSAJES EN ARCHIVO DE TEXTO :
      -----------------------------------------------------------------------------*/
    if ( !UnloadMensajes(sthFa_InfGeneral->szPathDir,
                         pst_MascaraOper->szIndFacturado,
                         pst_MascaraOper->iCodFormulario,
                         pstLineaComando) )
    {
        vDTrazasLog(szModulo,"Fallo funcion UnloadMensajes ",LOG01);
        return(FALSE);
    }

    return(1);
}
/****************************************************************************************************/
int Procesa_AviPag(ST_FACTCLIE          * FactDocuClie,
                   FILE                 * Fd_ArchImp,
                   ST_MENSAJES          * Mensajes,
                   ST_MENSAJES_NOCICLO  * Mensajes_NoCiclo,
                   STSALDO_ANTERIOR     * SaldoTot,
                   ST_CUOTAS            * pstFaCuotas,
                   ST_CICLOFACT         * sthFa_CicloFact,
                   ST_ABONADO           * Abonado,
                   DETALLEOPER          * stMascaraOper,
                   char                 * zsBufImpArch,
                   ST_BALANCE           * stBalance,
                   DET_TRANSACCIONES 	* pstDetTrans,
                   long                 lCodCiclFact,
                   char                 * szCod_Despacho,
                   BOOL                 Flag_ExisCarrier,
                   int                  esCiclo)
{
    struct timeb      tpi;

    char *szModulo="Procesa_AviPag";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG06, szModulo);


    ftime(&tpi);
    vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx PutCaratula= %ld.%d",LOG03, tpi.time,tpi.millitm);

    if ( !PutCaratula(FactDocuClie, Fd_ArchImp, Mensajes,Mensajes_NoCiclo, SaldoTot, pstFaCuotas,sthFa_CicloFact,stMascaraOper,zsBufImpArch,stBalance,pstDetTrans, lCodCiclFact, esCiclo) )
    {
        vDTrazasLog(szModulo,"Fallo funcion PutCaratula ",LOG01);
        return(FALSE);
    }

    ftime(&tpi);
    vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx PutCaratula= %ld.%d",LOG03, tpi.time,tpi.millitm);

       
    if ((lCodCiclFact) && (strcmp(sthFadParametros.val_caracter[CODIGO_DESPACHO_LOCUTORIO], szCod_Despacho ) != 0))
/*FIN 84510 CJG*/
    {
        vDTrazasLog(szModulo,"Ind_tasador (%d)",LOG04,sthFa_CicloFact->iIndTasador);

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx PutDetConsu= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !PutDetConsu(Abonado							
                         ,Fd_ArchImp                        
                         ,pstFaCuotas                       
                         ,SaldoTot                          
                         ,FactDocuClie                      
                         ,zsBufImpArch                      
                         , stMascaraOper                    
                         ,pstDetTrans                       
                         , sthFa_CicloFact->iIndTasador     
                         , lCodCiclFactAux
                         , Flag_ExisCarrier) )              
        {                                                   
            vDTrazasLog(szModulo,"Fallo funcion PutDetConsu ",LOG01);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx PutDetConsu= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }
    return(1);
}


/***********************************************************************************/
int Modulo_AVIPAG(ST_ABONADO           * Abonado,
                  ST_FACTCLIE          * FactDocuClie,
                  LINEACOMANDO         * ParEntrada,
                  ST_CICLOFACT         * sthFa_CicloFact,
                  ST_INFGENERAL        * sthFa_InfGeneral,
                  ST_CUOTAS            * pstFaCuotas,
                  FILE                 * Fd_ArchImp,
                  ST_MENSAJES          * Mensajes,
                  ST_MENSAJES_NOCICLO  * Mensajes_NoCiclo,
                  STSALDO_ANTERIOR     * SaldoTot,
                  DETALLEOPER          * sthDetalleOper,
                  CONCEPTOS_TAR        * stConceptosTar,
                  char                 * zsBufImpArch,
                  ST_BALANCE           * stBalance,
                  DET_TRANSACCIONES    * pstDetTrans)
{
    int i;
    struct timeb      tpi;
    BOOL Flag_ExisCarrier;

    char *szModulo="Modulo_AVIPAG";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG06, szModulo);

    /*-----------------------------------------------------------------------------
       CARGADO DE CONCEPTOS DEL CLIENTE :
       -----------------------------------------------------------------------------*/

    ftime(&tpi);
    vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx CargaConceptosDelCliente= %ld.%d",LOG03, tpi.time,tpi.millitm);
    if ( !CargaConceptosDelCliente(FactDocuClie,ParEntrada,sthFa_InfGeneral,sthDetalleOper) )
    {
        vDTrazasLog(szModulo,"\n\tFallo Conceptos",LOG01);
        return(FALSE);
    }
    ftime(&tpi);
    vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx CargaConceptosDelCliente= %ld.%d",LOG03, tpi.time,tpi.millitm);


    if ( ParEntrada->lCodCiclFact )
    {
        if ( stStatus.LogNivel >= LOG06 )
        {
            vDTrazasLog(szModulo,"\n",LOG06);
            for ( i=0;i<stFaDetCons.iNumReg;i++ )
            {
                vDTrazasLog(szModulo,"Salida Consumos|%ld|%s|%d|%d|%d|%d|%.4f|%.4f|%ld|",LOG06,
                            stFaDetCons.stDetConsumo[i].lNumAbonado,
                            stFaDetCons.stDetConsumo[i].szNum_Celular,
                            stFaDetCons.stDetConsumo[i].iCodGrupo,
                            stFaDetCons.stDetConsumo[i].iCodSubGrupo,
                            stFaDetCons.stDetConsumo[i].iCodConcepto,
                            stFaDetCons.stDetConsumo[i].iCod_TipSubGrupo,
                            stFaDetCons.stDetConsumo[i].dTotalFacturableNet,
                            stFaDetCons.stDetConsumo[i].dTotalFacturableImp,
                            stFaDetCons.stDetConsumo[i].lSeg_Consumo);
            }
            vDTrazasLog(szModulo,"\n",LOG06);
        }

        vDTrazasLog(szModulo,"\n\t\tCantidad Abonados     : [%ld]",LOG04, Abonado->CantidadAbonados);

        if ( !bObtieneMascara(Abonado,stConceptosTar,sthDetalleOper) )
        {
            vDTrazasLog(szModulo,"Fallo funcion bObtieneMascara ",LOG01);
            return(FALSE);
        }
    }

    /*-----------------------------------------------------------------------------
      INVOCACION A FUNCION QUE PROCESA (IMPRIME) LOS REGISTROS :
      -----------------------------------------------------------------------------*/

    Flag_ExisCarrier = FALSE;
    Flag_ExisCarrier = ValidaCarrier();

    if ( !Procesa_AviPag(FactDocuClie, 
    					 Fd_ArchImp, 
    					 Mensajes,
    					 Mensajes_NoCiclo, 
    					 SaldoTot, 
    					 pstFaCuotas,
    					 sthFa_CicloFact,
    					 Abonado,
    					 sthDetalleOper,
    					 zsBufImpArch,
    					 stBalance,
    					 pstDetTrans, 
    					 ParEntrada->lCodCiclFact, 
    					 ParEntrada->szCodDespacho, 
    					 Flag_ExisCarrier, ParEntrada->iTipoCiclo) ) /* PGG SOPORTE 20-02-2007 MA-37695 Se agrega un parametro mas */
    {
        return(FALSE);
    }


    if ( !ifnLiberaDetCons() )
    {
        vDTrazasLog(szModulo,"Fallo funcion ifnLiberaDetCons ",LOG01);
        return(FALSE);
    }
    return(1);
}

BOOL ValidaCarrier()
{
    int ihCant;

    ihCant = 0;

    /* EXEC SQL
    SELECT COUNT(1)
    INTO :ihCant
    FROM FA_FACTCARRIERS; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(1) into :b0  from FA_FACTCARRIERS ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCant;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( sqlca.sqlcode != SQLOK )
    {
        vDTrazasLog (szModulo,"Error Al Validar la Existencia de Carrier ",LOG01);
        return(FALSE);
    }

    if ( ihCant > 0 )
        return (TRUE);
    else
        return (FALSE);
}


int bfnMainProcess (LINEACOMANDO ParametrosEntrada)
{
    int  sem_id;
    int  retorno;
    int  iCantClie;
    int  iRegCliente;
    int  iSwBueno;
    char zsBufImpArch[MAX_BYTES_BUFFER ] = "";
    char Nombre_Arch[255];
    char archivo_temporal[512];
    char REGH1111[6];
    long pos1;
    int  rows_to_fetch  = BUFF_CLIENTE;
    int  rows_before    =  0;
    int  rows_this_time = BUFF_CLIENTE;
    char szDirectorio[255] = "";
    char szArchivoFinal[512];
    int  iCantLeido;
    int  iDescriptor;
    char szSecReProc[9];

    /*-----------------------------------------------------------------------------
      INVOCACION DE CARGAINFGENERAL DE FACTURACION :
      -----------------------------------------------------------------------------*/
    FILE *Fd_ArchImp=NULL;

    ST_INFGENERAL        sthFa_InfGeneral;
    ST_CICLOFACT         sthFa_CicloFact;
    ST_FACTCLIE          UnaFacturaCliente;
    STSALDO_ANTERIOR     SaldoAnt;
    ST_MENSAJES          sthFaMensajes;
    ST_MENSAJES_NOCICLO  sthFaMensajes_NoCiclo;
    ST_ABONADO           sthFa_Abonados;
    ST_CUOTAS            pstFaCuotas;
    CONCEPTOS_TAR        stConceptosTar;
    DETALLEOPER          stMascaraOper;
    ST_BALANCE           stBalance;
    ST_ACUMMTO           AcumMto;
    PLAN_TARIFARIO       sthPlanTarifario ;

    char *szModulo="bfnMainProcess";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(&sthDetArrastre  , 0, sizeof(ST_DETARRASTRE));
    memset(&pstDetTrans     , 0, sizeof(DET_TRANSACCIONES));
    memset(&sthCurArrastre  , 0, sizeof(ST_CURARRASTRE));
    memset(&sthPlanTarifario, 0, sizeof(PLAN_TARIFARIO));
    memset(&stBalance       , 0, sizeof(ST_BALANCE));
    memset(&AcumMto         , 0, sizeof(ST_ACUMMTO));
    memset(&AcumMto         , 0, sizeof(ST_ACUMMTO));
    memset(&sthDetArrastre  , 0, sizeof(ST_DETARRASTRE));
    memset(zsBufImpArch     , 0, sizeof(char *));
    memset(&sthFa_InfGeneral, 0, sizeof(ST_INFGENERAL));
    memset(&sthFadParametros, 0, sizeof(ST_PARAMETROS));
    memset(&sthFa_CicloFact , 0, sizeof(ST_CICLOFACT));
    memset(&pstConfB4001    , 0, sizeof(CONF_B4001));
    memset(&pstConfTipRegD  , 0, sizeof(CONF_REGTIP_D));


    if ( lNroJob )
    {
        sprintf(szSecReProc,"%02d",iSecProceso);
        vDTrazasLog(szModulo,"\nSecuencia de proceso [%d][%s]\n", LOG03,iSecProceso,szSecReProc );
    }
    /*-----------------------------------------------------------------------------
      CREACION DE DIRECTORIO REPOSITORIO PARA CICLO A PROCESAR :
      -----------------------------------------------------------------------------*/

    iCantClie = 0;
    iCantLeido = 0;

    igTipoCiclo = 0;
    igTipoCiclo = ParametrosEntrada.iTipoCiclo;

    if ( !flg_mc )
    {
        if ( !CargaFadParametros() )
        {
            vDTrazasLog(szModulo,  "CargaFadParametros retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !GargaGedParametros() )
        {
            vDTrazasLog(szModulo,  "GargaGedParametros retorno NOOK" ,LOG01);
            return(FALSE);
        }

    }
    else
    { /* MEMORIA COMPARTIDA */
        if ( !CargaFadParametrosMC() )
        {
            vDTrazasLog(szModulo,  "CargaFadParametros_MC desde MEMORIA COMPARTIDA retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !CargaFadParametros_GED_MC() )
        {
            vDTrazasLog(szModulo,  "CargaFadParametros_GED_MC desde MEMORIA COMPARTIDA retorno NOOK" ,LOG01);
            return(FALSE);
        }
    }


	/* correccion */
    strcpy(sthFadParametros.val_caracter[CODIGO_DESPACHO_LOCUTORIO], alltrim(sthFadParametros.val_caracter[CODIGO_DESPACHO_LOCUTORIO]));
    vDTrazasLog(szExeName,"\n CODIGO_DESPACHO_LOCUTORIO = %s\n",LOG05, sthFadParametros.val_caracter[CODIGO_DESPACHO_LOCUTORIO]);

    if ( strcmp(szAplica_Cod_Autorizacion,"S")==0 )
    {
        if ( !szfnObtieneCod_autorizacion(&ParametrosEntrada) )
        {
            vDTrazasLog(szModulo,  "szfnObtieneCod_autorizacion retorno NOOK" ,LOG01);
            return(FALSE);
        }
    }

    if ( !ParametrosEntrada.iTipoCiclo )
    {
        if ( !lNroJob )
        {
            sprintf(sthFa_InfGeneral.szPathDir,"%s/ImpresionScl",getenv("XPF_DAT"));
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            strcat(sthFa_InfGeneral.szPathDir,"/ciclo");
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            sprintf(sthFa_InfGeneral.szPathDir,"%s/%ld",sthFa_InfGeneral.szPathDir,ParametrosEntrada.lCodCiclFact);
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
        }
        else
        {
            sprintf(sthFa_InfGeneral.szPathDir,"%s/jobs",getenv("XPF_DAT"));
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            sprintf(sthFa_InfGeneral.szPathDir,"%s/%ld",sthFa_InfGeneral.szPathDir,lNroJob);
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            strcat(sthFa_InfGeneral.szPathDir,"/ImpresionScl");
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            strcat(sthFa_InfGeneral.szPathDir,"/ciclo");
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
            sprintf(sthFa_InfGeneral.szPathDir,"%s/%ld",sthFa_InfGeneral.szPathDir,ParametrosEntrada.lCodCiclFact);
            if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
            {
                vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
                return(FALSE);
            }
        }
    }
    else
    {
        sprintf(sthFa_InfGeneral.szPathDir,"%s%.*s\0",getenv("HOME"), sthFadParametros.val_cantidad[DIREC_NOCICLO_NPROC],
                sthFadParametros.val_caracter[DIREC_NOCICLO_NPROC]);
    }

    printf("\tDirectorio DAT     : [%s]\n",sthFa_InfGeneral.szPathDir);

    if ( iMakeDir(sthFa_InfGeneral.szPathDir)!=0 )
    {
        vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, sthFa_InfGeneral.szPathDir);
        return(FALSE);
    }

    /**************************************************************************************/

    if ( lNroJob )
    {
        sprintf(szDirectorio,"%s/jobs",getenv("XPF_LOG"));
        if ( iMakeDir(szDirectorio)!=0 )
        {
            vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
            return(FALSE);
        }
        sprintf(szDirectorio,"%s/%ld",szDirectorio,lNroJob);
        if ( iMakeDir(szDirectorio)!=0 )
        {
            vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
            return(FALSE);
        }
        sprintf(szDirectorio,"%s/ImpresionScl",szDirectorio);
        if ( iMakeDir(szDirectorio)!=0 )
        {
            vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
            return(FALSE);
        }
    }
    else
    {
        sprintf(szDirectorio,"%s/ImpresionScl",getenv("XPF_LOG"));
        if ( iMakeDir(szDirectorio)!=0 )
        {
            vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
            return(FALSE);
        }
    }
    /**************************************************************************************/

    iDescriptor = getpid();

    /**************************************************************************************/
    if ( !ParametrosEntrada.iTipoCiclo )
    {
        strcat(szDirectorio,"/ciclo");
        if ( iMakeDir(szDirectorio)!=0 )
        {
            vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
            return(FALSE);
        }
        sprintf(szDirectorio,"%s/%ld",szDirectorio,ParametrosEntrada.lCodCiclFact);
    }
    else
    {
        sprintf(szDirectorio,"%s/nociclo",szDirectorio);
    }

    if ( iMakeDir(szDirectorio)!=0 )
    {
        vDTrazasLog(szModulo,"Falla al crear el directorio [%s]",LOG01, szDirectorio);
        return(FALSE);
    }

    if ( !ParametrosEntrada.iTipoCiclo )
    {
        if ( !lNroJob )
        {
            if ( !flg_mc )
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s.log",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho);
            else
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d.log",szDirectorio,iDescriptor);
        }
        else
        {
            if ( !flg_mc )
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s_%s.log",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho,szSecReProc);
            else
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s.log",szDirectorio,iDescriptor,szSecReProc);
        }
    }
    else
    {
        sprintf(stStatus.LogName,"%s/ImpresionScl_%ld.log",szDirectorio,ParametrosEntrada.lProceso);
    }
    printf("\tArchivo de LOG     : [%s]\n",stStatus.LogName);

    if ( (stStatus.LogFile = fopen(stStatus.LogName,"wb")) == (FILE*)NULL )
    {
        fprintf( stderr, "\n ### Error: No puede abrirse el fichero de log %s\n", stStatus.LogName);
    }

    if ( !ParametrosEntrada.iTipoCiclo )
    {
        if ( !lNroJob )
        {
            if ( !flg_mc )
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s.err",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho);
            else
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d.err",szDirectorio,iDescriptor);
        }
        else
        {
            if ( !flg_mc )
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s_%s.err",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho,szSecReProc);
            else
                sprintf(stStatus.LogName,"%s/ImpresionScl_%d_%s.err",szDirectorio,iDescriptor,szSecReProc);
        }

    }
    else
    {
        sprintf(stStatus.LogName,"%s/ImpresionScl_%ld.err",szDirectorio,ParametrosEntrada.lProceso);
    }
    printf("\tArchivo de ERRORES : [%s]\n",stStatus.LogName);

    if ( (stStatus.ErrFile = fopen(stStatus.LogName,"wb")) == (FILE*)NULL )
    {
        fprintf( stderr, "\n ### Error: No puede abrirse el fichero de err %s\n", stStatus.LogName);
    }

    if ( !ParametrosEntrada.iTipoCiclo )
    {
        if ( !lNroJob )
        {
            if ( !flg_mc )
                sprintf(szgNombreArchivoAnomalias,"%s/Anomalias_%d_%s.log",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho);
            else
                sprintf(szgNombreArchivoAnomalias,"%s/Anomalias_%d.log",szDirectorio,iDescriptor);
        }
        else
        {
            if ( !flg_mc )
                sprintf(szgNombreArchivoAnomalias,"%s/Anomalias_%d_%s_%s.log",szDirectorio,ParametrosEntrada.iCodTipDocum,ParametrosEntrada.szCodDespacho, szSecReProc);
            else
                sprintf(szgNombreArchivoAnomalias,"%s/Anomalias_%d_%s.log",szDirectorio,iDescriptor,szSecReProc);
        }

    }
    else
    {
        sprintf(szgNombreArchivoAnomalias,"%s/Anomalias_%ld.log",szDirectorio,ParametrosEntrada.lProceso);
    }
    printf("\tArchivo de ANOMALIAS : [%s]\n",szgNombreArchivoAnomalias);

    if ( (fpAnomalias = fopen(szgNombreArchivoAnomalias,"wb")) == (FILE*)NULL )
    {
        fprintf( stderr, "\n ### Error: No puede abrirse el fichero de err %s\n", szgNombreArchivoAnomalias);
    }

    fprintf (stderr, "\tVersion [%s] con fecha [%s]\n",szVersionActual, szUltimaModificacion);
    vDTrazasLog (szModulo, "\nImpresionScl version " __DATE__ " " __TIME__ " TMM MC\n\nVersion [%s] con fecha [%s]\n",LOG03,szVersionActual, szUltimaModificacion); /* TM-200410241013 Homologado por PGonzalez 10-12-2004 */

    /**********************************************************/
    /* Carga Mascara de la operadora                          */
    /**********************************************************/
    memset(&stMascaraOper,0,sizeof(DETALLEOPER));

    if ( !flg_mc )
    {
        if ( !bCargaMascaraOperadora(&stMascaraOper,ParametrosEntrada.iCodTipDocum) )
        {
            vDTrazasLog(szModulo,  "bCargaMascaraOperadora retorno NOOK" ,LOG01);
            return(FALSE);
        }
    }
    else
        if ( !bCargaMascaraOperadora_MC(&stMascaraOper) )
    {
        vDTrazasLog(szModulo,  "bCargaMascaraOperadora_MC retorno NOOK" ,LOG01);
        return(FALSE);
    }

    lCodCiclFactAux = ParametrosEntrada.lCodCiclFact;

    if ( !ParametrosEntrada.iTipoCiclo )
    {
		/* rao agregar preparacion de consultas dinamicas */
		if (!ifnPreparaConsTraf ())
	    {
	        vDTrazasLog(szModulo,  "preparacion de consultas dinamicas de trafico retorno NOOK" ,LOG01);
	        return(FALSE);
	    }
		if (!ifnPreparaConsCuot ())
	    {
	        vDTrazasLog(szModulo,  "preparacion de consultas dinamicas de cuotas retorno NOOK" ,LOG01);
	        return(FALSE);
	    }
	}
    if ( !bfnCargaTipoTraficoLD() )
    {
        vDTrazasLog(szModulo,  "bfnCargaTipoTraficoLD retorno NOOK" ,LOG01);
        return(FALSE);
    }

    /*-----------------------------------------------------------------------------
    INVOCACION DE CARGA DE INFORMACION GENERAL DE FACTURACION :
    -----------------------------------------------------------------------------*/
    if ( !CargInfGenComun(&sthFa_InfGeneral,&sthFa_CicloFact,&ParametrosEntrada,stMascaraOper.iCodFormulario) )
    {
        vDTrazasLog(szModulo,  "CargInfGenComun retorno NOOK" ,LOG01);
        return(FALSE);
    }

    if ( !flg_mc ) 	
    {
        if ( !bfnCargaOficinas2 (&pstOficinas2.stOficina, &pstOficinas2.iNumOficinas) )
        {
            return(FALSE);
        }
        if ( !bfnCargaOperadora (&pstOperadoras.stOperadora, &pstOperadoras.iNumOperadoras) )
        {
            return(FALSE);
        }
        if ( !bfnCargaTipDocum (&pstTipDocum.stTipDocum, &pstTipDocum.iNumTipDocum) )
        {
            return(FALSE);
        }
        if ( !ParametrosEntrada.iTipoCiclo )
        {
            if ( !bfnCargaVendedores (&pstVendedores.stVendedores, &pstVendedores.iNumVendedores) )
            {
                vDTrazasLog(szModulo,  "bfnCargaVendedores retorno NOOK" ,LOG01);
                return(FALSE);
            }
            if ( !bCargaConceptosTar(&stConceptosTar) )
            {
                vDTrazasLog(szModulo,  "bCargaConceptosTar retorno NOOK" ,LOG01);
                return(FALSE);
            }
            if ( !CargInfGenAviPag(&ParametrosEntrada,&sthFa_InfGeneral, &stMascaraOper) )
            {
                vDTrazasLog(szModulo,  "CargInfGenAviPag retorno NOOK" ,LOG01);
                return(FALSE);
            }
        }
    }
    else
    { /*MEMORIA COMPARTIDA*/
        if ( !bfnCargaOficinas2_MC (&pstOficinas2.stOficina, &pstOficinas2.iNumOficinas) )
        {
            vDTrazasLog(szModulo,  "bfnCargaOficinas2_MC retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !bfnCargaOperadora_MC(&pstOperadoras.stOperadora, &pstOperadoras.iNumOperadoras) )
        {
            vDTrazasLog(szModulo,  "bfnCargaOperadora_MC retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !bfnCargaTipDocum_MC(&pstTipDocum.stTipDocum, &pstTipDocum.iNumTipDocum) )
        {
            vDTrazasLog(szModulo,  "bfnCargaTipDocum_MC retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !bfnCargaVendedores_MC(&pstVendedores.stVendedores, &pstVendedores.iNumVendedores) )
        {
            vDTrazasLog(szModulo,  "bfnCargaVendedores_MC retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !bCargaConceptosTar_MC(&stConceptosTar) )
        {
            vDTrazasLog(szModulo,  "bCargaConceptosTar_MC retorno NOOK" ,LOG01);
            return(FALSE);
        }
    }

    vDTrazasLog (szModulo,"\tTipo Ciclo [%ld]" ,LOG03, ParametrosEntrada.iTipoCiclo);

    /*-----------------------------------------------------------------------------
    CARGADO DE UN BUFFER DE CLIENTES: debe ser invocado hasta que no quede ninguno
    FacturaCliente
    -----------------------------------------------------------------------------*/
    if ( !flg_mc ) /* SIN MEMORIA COMPARTIDA */
    {
        memset(Nombre_Arch,0,_strlen(Nombre_Arch));
        sthFa_InfGeneral.iContClientesProcesados = 0;

        if ( !ManejoArchImp(&ParametrosEntrada,
                            &sthFa_InfGeneral,
                            &stMascaraOper,
                            &Fd_ArchImp,
                            &AcumMto,
                            Nombre_Arch) )
        {
            vDTrazasLog(szModulo,  "ManejoArchImp retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !OpenFactDocuClie(&ParametrosEntrada) )
        {
            vDTrazasLog(szModulo, "Error en ejecucion del iOpenFactDocuClie \n", LOG00);
            return (FALSE);
        }
        while ( rows_this_time == rows_to_fetch )
        {
            if ( !FetchFactDocuClie(&iCantClie,&iCantLeido) )
            {
                vDTrazasLog(szModulo, "Error en ejecucion del FetchFactDocuClie \n", LOG00);
                return (FALSE);
            }

            /*-----------------------------------------------------------------------------
              RECORRIDO SECUENCIAL DE CADA UNO DE LOS CLIENTES DEL BUFFER RECIEN RECUPERADO
              -----------------------------------------------------------------------------*/
            for ( iRegCliente=0;iRegCliente<iCantLeido;iRegCliente++ ) /* SAAM-20040615 se cambia variable de control */
            {
                sthFa_InfGeneral.iContClientesProcesados++;
                vDTrazasLog(szModulo,"\tlIndOrdenTotal(%ld)\n"
                					 "\tlNum_Folio    (%ld)\n"
                					,LOG04,FacturaCliente[iRegCliente].lIndOrdenTotal
                					,FacturaCliente[iRegCliente].lNum_Folio     );
                /*-----------------------------------------------------------------------------
                        PROCESAR CADA UNO DE LOS CLIENTES :
                -----------------------------------------------------------------------------*/
                UnaFacturaCliente=FacturaCliente[iRegCliente];
                /*-----------------------------------------------------------------------------
                  INVOCACION DE FUNCION CARGADO DE INFORMACION PROPIA DE CLIENTE :
                  -----------------------------------------------------------------------------*/
                if ( !CargaInfCliente(&UnaFacturaCliente,
                                      &ParametrosEntrada,
                                      &sthFaMensajes,
                                      &sthFaMensajes_NoCiclo,
                                      &SaldoAnt,
                                      &sthFa_CicloFact,
                                      &pstFaCuotas,
                                      &sthFa_InfGeneral,
                                      &stMascaraOper) )
                {
                    vDTrazasLog(szModulo,  "CargaInfCliente retorno NOOK" ,LOG01);
                    return(FALSE);
                }
                /*-----------------------------------------------------------------------------
                  CARGAABONADOSDECLIENTE
                  -----------------------------------------------------------------------------*/
                if ( !CargaAbonadosdelCliente(&UnaFacturaCliente,
                                              &sthFa_Abonados,
                                              &ParametrosEntrada,
                                              &stMascaraOper) )
                {
                    vDTrazasLog(szModulo,  "CargaAbonadosdelCliente retorno NOOK" ,LOG01);
                    return(FALSE);
                }
                /*-----------------------------------------------------------------------------
                   INVOCACION DE MODULO AVISO DE PAGO:
                -----------------------------------------------------------------------------*/
                if ( !Modulo_AVIPAG(&sthFa_Abonados,
                                    &UnaFacturaCliente,
                                    &ParametrosEntrada,
                                    &sthFa_CicloFact,
                                    &sthFa_InfGeneral,
                                    &pstFaCuotas,
                                    Fd_ArchImp,
                                    &sthFaMensajes,
                                    &sthFaMensajes_NoCiclo,
                                    &SaldoAnt,
                                    &stMascaraOper,
                                    &stConceptosTar,
                                    zsBufImpArch,
                                    &stBalance,
                                    &pstDetTrans) )
                {
                    vDTrazasLog(szModulo,  "Modulo_AVIPAG retorno NOOK" ,LOG01);
                    return(FALSE);
                }
                /*-----------------------------------------------------------------------------
                  UPDATE FACTDOCU
                  -----------------------------------------------------------------------------*/
                if ( !lNroJob ) /* SIN JOB */
                {
                    if ( iUpdateFactDocu(ParametrosEntrada.lCodCiclFact,
                                         &UnaFacturaCliente,
                                         &AcumMto) )
                    {
                        vDTrazasLog(szModulo,  "iUpdateFactDocu retorno OK" ,LOG04);
                        /* EXEC SQL COMMIT; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 1;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )24;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                    }
                    else
                    {
                        vDTrazasLog(szModulo,  "iUpdateFactDocu retorno NOOK" ,LOG01);
                        /* EXEC SQL ROLLBACK; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 1;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )39;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                        return(FALSE);
                    }
                }
                /*-----------------------------------------------------------------------------------------------------------
                 APERTURA DE ARCHIVO DE IMPRESION CORRESPONDIENTE
                 -----------------------------------------------------------------------------------------------------------*/
                if ( sthFa_InfGeneral.iContClientesProcesados >= stMascaraOper.iCtesXArchivo )
                {
                    vDTrazasLog(szModulo,  "sthFa_InfGeneral.iContClientesProcesados(%d) >= stMascaraOper.iCtesXArchivo (%d)" ,LOG04,sthFa_InfGeneral.iContClientesProcesados,stMascaraOper.iCtesXArchivo);
                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufImpArch, FLUSH) )
                    {
                        return(FALSE);
                    }
                }
                else
                {
                    vDTrazasLog(szModulo,  "sthFa_InfGeneral.iContClientesProcesados(%d) < stMascaraOper.iCtesXArchivo (%d)" ,LOG04,sthFa_InfGeneral.iContClientesProcesados,stMascaraOper.iCtesXArchivo);
                }
                if ( !ManejoArchImp(&ParametrosEntrada,
                                    &sthFa_InfGeneral,
                                    &stMascaraOper,
                                    &Fd_ArchImp,
                                    &AcumMto,
                                    Nombre_Arch) )
                {
                    vDTrazasLog(szModulo,  "ManejoArchImp retorno NOOK" ,LOG01);
                    return(FALSE);
                }
                if ( ParametrosEntrada.lCodCiclFact && !lNroJob ) /* CICLO Y SIN JOB */
                {
                    if ( !Update_CuotaCredito(&UnaFacturaCliente,&pstFaCuotas) )
                    {
                        vDTrazasLog(szModulo,  "Update_CuotaCredito retorno NOOK" ,LOG01);
                        return(FALSE);
                    }
                }
            } /* fin FOR */
            
            rows_this_time = iCantClie - rows_before;
            rows_before = iCantClie;
            
        } /* fin WHILE */
        vDTrazasLog(szModulo,"Total de Clientes Procesados [%d]" ,LOG03,iCantClie);

        if ( !CloseFactDocuClie() )
        {
            vDTrazasLog(szModulo,  "iCloseFactDocuClie retorno NOOK" ,LOG01);
        }

        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufImpArch, FLUSH) )
        {
            return(FALSE);
        }

        if ( ParametrosEntrada.lCodCiclFact ) /* CICLO */
        {
            if ( !bfnInsertar_FadCTLImpres(&AcumMto, &ParametrosEntrada, &sthFa_InfGeneral, Nombre_Arch) )
            {
                vDTrazasLog(szModulo,"Error en ejecucion de bfnInsertar_FadCTLImpres FINAL",LOG01);
                return(FALSE);
            }
        }
        else if ( !lNroJob ) /* SIN JOB */
        {
            vDTrazasLog(szModulo, "\tValor a Insertar en FA_INTERIMPRESION_TD", LOG06);
            vDTrazasLog(szModulo, "\t\t NUM_PROCESO [%ld]", LOG06,ParametrosEntrada.lProceso);
            vDTrazasLog(szModulo, "\t\t COD_CLIENTE [%ld]", LOG06,UnaFacturaCliente.lCodCliente);
            vDTrazasLog(szModulo, "\t\t FEC_ENVIO   [SYSDATE]", LOG06);
            vDTrazasLog(szModulo, "\t\t DIR_WEB     [dat]", LOG06);
            vDTrazasLog(szModulo, "\t\t COD_ESTADO  [1]", LOG06);
            vDTrazasLog(szModulo, "\t\t FEC_ULTMOD  [SYSDATE]", LOG06);
            vDTrazasLog(szModulo, "\t\t NOM_USUARIO [%s]", LOG06,UnaFacturaCliente.szNomUsuarora);

            /* EXEC SQL
            INSERT INTO FA_INTERIMPRESION_TD(
                                            NUM_PROCESO,
                                            COD_CLIENTE,
                                            FEC_ENVIO,
                                            DIR_WEB,
                                            COD_ESTADO,
                                            FEC_ULTMOD,
                                            NOM_USUARIO)
            VALUES(
                  :ParametrosEntrada.lProceso,
                  :UnaFacturaCliente.lCodCliente,
                  SYSDATE,
                  'dat',
                  '1',
                  SYSDATE,
                  :UnaFacturaCliente.szNomUsuarora); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 3;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "insert into FA_INTERIMPRESION_TD (NUM_PROCESO,COD\
_CLIENTE,FEC_ENVIO,DIR_WEB,COD_ESTADO,FEC_ULTMOD,NOM_USUARIO) values (:b0,:b1,\
SYSDATE,'dat','1',SYSDATE,:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )54;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(ParametrosEntrada.lProceso);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&(UnaFacturaCliente.lCodCliente);
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)(UnaFacturaCliente.szNomUsuarora);
            sqlstm.sqhstl[2] = (unsigned long )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            if ( sqlca.sqlcode != SQLOK )
            {
                vDTrazasLog(szModulo, "\tINSERT de FA_INTERIMPRESION_TD : %s ", LOG03, sqlca.sqlerrm.sqlerrmc);

                /* EXEC SQL
                DELETE FA_INTERIMPRESION_TD
                WHERE NUM_PROCESO = :ParametrosEntrada.lProceso; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "delete  from FA_INTERIMPRESION_TD  where NUM_\
PROCESO=:b0";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )81;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&(ParametrosEntrada.lProceso);
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqphsv = sqlstm.sqhstv;
                sqlstm.sqphsl = sqlstm.sqhstl;
                sqlstm.sqphss = sqlstm.sqhsts;
                sqlstm.sqpind = sqlstm.sqindv;
                sqlstm.sqpins = sqlstm.sqinds;
                sqlstm.sqparm = sqlstm.sqharm;
                sqlstm.sqparc = sqlstm.sqharc;
                sqlstm.sqpadto = sqlstm.sqadto;
                sqlstm.sqptdso = sqlstm.sqtdso;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                if ( sqlca.sqlcode != SQLOK )
                {
                    vDTrazasLog(szModulo, "\tError en DELETE de FA_INTERIMPRESION_TD : %s ", LOG02, sqlca.sqlerrm.sqlerrmc);
                    vDTrazasLog(szModulo, "\tError NRO PROCESO : %ld ", LOG02, ParametrosEntrada.lProceso);
                    return(FALSE);
                }
                /* EXEC SQL COMMIT; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )100;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                if ( sqlca.sqlcode != SQLOK )
                {
                    vDTrazasLog(szModulo, "\tError en COMMIT al INSERT de FA_INTERIMPRESION_TD : %s ", LOG02, sqlca.sqlerrm.sqlerrmc);
                    return(FALSE);
                }
                /* EXEC SQL
                INSERT INTO FA_INTERIMPRESION_TD(
                                                NUM_PROCESO,
                                                COD_CLIENTE,
                                                FEC_ENVIO,
                                                DIR_WEB,
                                                COD_ESTADO,
                                                FEC_ULTMOD,
                                                NOM_USUARIO)
                VALUES(
                      :ParametrosEntrada.lProceso,
                      :UnaFacturaCliente.lCodCliente,
                      SYSDATE,
                      'dat',
                      '1',
                      SYSDATE,
                      :UnaFacturaCliente.szNomUsuarora); */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "insert into FA_INTERIMPRESION_TD (NUM_PROCESO\
,COD_CLIENTE,FEC_ENVIO,DIR_WEB,COD_ESTADO,FEC_ULTMOD,NOM_USUARIO) values (:b0,\
:b1,SYSDATE,'dat','1',SYSDATE,:b2)";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )115;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&(ParametrosEntrada.lProceso);
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&(UnaFacturaCliente.lCodCliente);
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)(UnaFacturaCliente.szNomUsuarora);
                sqlstm.sqhstl[2] = (unsigned long )31;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqphsv = sqlstm.sqhstv;
                sqlstm.sqphsl = sqlstm.sqhstl;
                sqlstm.sqphss = sqlstm.sqhsts;
                sqlstm.sqpind = sqlstm.sqindv;
                sqlstm.sqpins = sqlstm.sqinds;
                sqlstm.sqparm = sqlstm.sqharm;
                sqlstm.sqparc = sqlstm.sqharc;
                sqlstm.sqpadto = sqlstm.sqadto;
                sqlstm.sqptdso = sqlstm.sqtdso;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                if ( sqlca.sqlcode != SQLOK )
                {
                    vDTrazasLog(szModulo, "\tError en INSERT FA_INTERIMPRESION_TD  : %s ", LOG02,  sqlca.sqlerrm.sqlerrmc);
                    return(FALSE);
                }
            }
            /* EXEC SQL COMMIT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 3;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )142;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            if ( sqlca.sqlcode != SQLOK )
            {
                vDTrazasLog(szModulo, "\tError en COMMIT al INSERT de FA_INTERIMPRESION_TD : %s ", LOG02, sqlca.sqlerrm.sqlerrmc);
                return(FALSE);
            }
        }
        return(TRUE);
    }
    else /* MEMORIA COMPARTIDA */
    {
        if ( memoria[0].flag_proceso!=1 )
        {
            vDTrazasLog (szModulo,"\n\t* No hay datos en memoria compartida", LOG06);
            return(FALSE);
        }
        else
        {
            id_memoria=0;
            vDTrazasLog (szModulo,"Unir a Memoria [%d][%d] TABLA_CLIENTES", LOG06,total_regs,TABLA_CLIENTES);
            vDTrazasLog (szModulo,"------------------------------------------------", LOG06);
            id_memoria=unir_a_memoria(total_regs,TABLA_CLIENTES);
            if ( id_memoria<0 )
            {
                vDTrazasLog (szModulo,"NO SE PUEDE CONECTAR A MEMORIA COMPARTIDA TABLA CLIENTES \n",LOG03);
                return(FALSE);
            }
            else
            {
                vDTrazasLog (szModulo,"IDENTIFACOR DE MEMORIA OBTENIDO TABLA CLIENTES:%d\n",LOG03,id_memoria);
            }

            sem_id=crear_semaforo(TABLA_CLIENTES);
            if ( sem_id==-1 )
            {
                vDTrazasLog (szModulo,"ERROR NO SE PUDO OBTENER IDENTIFICADOR DE SEMAFORO", LOG04);
                printf("ERROR NO SE PUDO OBTENER IDENTIFICADOR DE SEMAFORO ");
                return(FALSE);
            }
            else
            {
                vDTrazasLog (szModulo,"IDENTIFICADOR DE SEMAFORO OBTENIDO" ,LOG06);
                printf("IDENTIFICADOR DE SEMAFORO OBTENIDO : %d\n",sem_id);
            }

            while ( memoria[0].flag_proceso==1 )
            {
                if ( memoria[0].flag_proceso==2 )
                {
                    printf("CARGA INICIAL ENVIO KILL SIGNAL");
                    return(FALSE);
                }
                memset(&FacturaCliente_mc,0,sizeof(ST_FACTCLIE));
                retorno = 0;
                retorno=get_cliente(sem_id,total_regs);

                ParametrosEntrada.iCodTipDocum = FacturaCliente_mc.iCodTipDocum;
                memset(ParametrosEntrada.szCodDespacho,'\0',sizeof(ParametrosEntrada.szCodDespacho));
                strcpy(ParametrosEntrada.szCodDespacho,FacturaCliente_mc.szCodDespacho);

                if ( retorno!=-1 )
                {
                    if ( !ManejoArchImp_MC(&FacturaCliente_mc,
                                           &ParametrosEntrada,
                                           &sthFa_InfGeneral,
                                           &Fd_ArchImp,
                                           Nombre_Arch) )
                    {
                        vDTrazasLog(szModulo,  "ManejoArchImp_MC retorno NOOK" ,LOG01);
                        return(FALSE);
                    }

                    if ( !CargaInfCliente(&FacturaCliente_mc,
                                             &ParametrosEntrada,
                                             &sthFaMensajes,
                                             &sthFaMensajes_NoCiclo,
                                             &SaldoAnt,
                                             &sthFa_CicloFact,
                                             &pstFaCuotas,
                                             &sthFa_InfGeneral,
                                             &stMascaraOper) )
                    {
                        fnGrabaAnoProceso (FacturaCliente_mc.lCodCliente, ParametrosEntrada.lCodCiclFact,1,"No pudo cargar Informacion del Cliente");
                        vDTrazasLog(szModulo,  "CargaInfCliente retorno NOOK" ,LOG01);
                        return(FALSE);
                    }

                    if ( !CargaAbonadosdelCliente(&FacturaCliente_mc,&sthFa_Abonados,&ParametrosEntrada,&stMascaraOper) )
                    {
                        fnGrabaAnoProceso (FacturaCliente_mc.lCodCliente, ParametrosEntrada.lCodCiclFact,2,"No pudo cargar Informacion de sus Abonados");
                        vDTrazasLog(szModulo,  "CargaAbonadosdelCliente retorno NOOK" ,LOG01);
                        return(FALSE);
                    }
                    /*-----------------------------------------------------------------------------
                       INVOCACION DE MODULO AVISO DE PAGO:
                      -----------------------------------------------------------------------------*/
                    if ( !Modulo_AVIPAG(&sthFa_Abonados,
                                        &FacturaCliente_mc,
                                        &ParametrosEntrada,
                                        &sthFa_CicloFact,
                                        &sthFa_InfGeneral,
                                        &pstFaCuotas,
                                        Fd_ArchImp,
                                        &sthFaMensajes,
                                        &sthFaMensajes_NoCiclo,
                                        &SaldoAnt,
                                        &stMascaraOper,
                                        &stConceptosTar,
                                        zsBufImpArch,
                                        &stBalance,
                                        &pstDetTrans) )
                    {
                        vDTrazasLog(szModulo,  "Modulo_AVIPAG retorno NOOK" ,LOG01);
                        return(FALSE);
                    }

                    if ( ParametrosEntrada.lCodCiclFact && !lNroJob )
                    {
                        if ( !Update_CuotaCredito(&FacturaCliente_mc,&pstFaCuotas) )
                        {
                            fnGrabaAnoProceso (FacturaCliente_mc.lCodCliente, ParametrosEntrada.lCodCiclFact,3,"No pudo cargar Informacion de Cuotas");
                            vDTrazasLog(szModulo,  "Update_CuotaCredito retorno NOOK" ,LOG01);
                            return(FALSE);
                        }
                    }
                    vDTrazasLog(szModulo,"------------------------------------"
                    					 "---Validacion de Archivo Generado---"
                    					 "------------------------------------" ,LOG03);
                    pos1 = (_strlen(zsBufImpArch) - 6);
                    vDTrazasLog(szModulo,"Cantidad de caracteres [%ld]" ,LOG03, pos1);
                    memset(REGH1111,'\0',sizeof(REGH1111));
                    strncpy(REGH1111,zsBufImpArch+pos1,5);
                    memset(REGA1000,'\0',sizeof(REGA1000));
                    strncpy(REGA1000,zsBufImpArch,5);

                    vDTrazasLog(szModulo,"Primera Etiqueta (Debe ser A1000) [%s]"
                    					 "Ultima  Etiqueta (Debe ser H1111) [%s]",LOG03,REGA1000,REGH1111);

                    if ( strncmp(REGH1111,"H1111",5)==0 )
                        iSwBueno=0;
                    else
                        iSwBueno=1;
                        
                    /*INICIO 84510 CJG*/                        
                    if (strcmp(sthFadParametros.val_caracter[CODIGO_DESPACHO_LOCUTORIO], ParametrosEntrada.szCodDespacho ) == 0)
                    {
                    	vDTrazasLog(szModulo,"VALIDANDO ETIQUETA [%s] para codigo de despacho [%s]" ,LOG03, REGH1111,ParametrosEntrada.szCodDespacho);
                    	/* Homologacion incidencia 140145 no se valida etiqueta 
                          if ( strncmp(REGH1111,"A1999",5)==0 ) */
                               iSwBueno=0;
                    }	
                    /*FIN 84510 CJG*/

                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufImpArch, FLUSH) )
                    {
                        return(FALSE);
                    }

                    if ( iSwBueno!=0 )
                    {
                        vDTrazasLog(szModulo,"Archivo Erroneo",LOG03);
                        memset(szArchivoFinal,'\0',sizeof(szArchivoFinal));
                        memset(archivo_temporal,'\0',sizeof(archivo_temporal));
                        vDTrazasLog(szModulo,"Nombre de Archivo [%s]",LOG03,Nombre_Arch);
                        strcpy(szArchivoFinal,"mv ");
                        strcat(szArchivoFinal,Nombre_Arch);
                        strncpy(archivo_temporal,Nombre_Arch,_strlen(Nombre_Arch)-4);
                        strcat(archivo_temporal,".err");
                        strcat(szArchivoFinal," ");
                        strncat(szArchivoFinal,Nombre_Arch,_strlen(Nombre_Arch)-4);
                        strcat(szArchivoFinal,".err");
                        vDTrazasLog(szModulo,"Comando [%s*]",LOG03, szArchivoFinal);
                        fclose(Fd_ArchImp);
                        system(szArchivoFinal);
                        marca_cliente_facturado(sem_id,retorno);

                        fnGrabaAnoProceso (FacturaCliente_mc.lCodCliente, ParametrosEntrada.lCodCiclFact,4,"Concatenacion Incorrecta");
                        if ( !lNroJob ) /* Sin JOB */
                        {
                            if ( iUpdateFactDocu_MC(ParametrosEntrada.lCodCiclFact,&FacturaCliente_mc,&SaldoAnt,&pstFaCuotas,&stBalance,archivo_temporal,sem_id,1) )
                            {
                                vDTrazasLog(szModulo,  "iUpdateFactDocu retorno OK" ,LOG04);
                            }
                            else
                            {
                                vDTrazasLog(szModulo,  "iUpdateFactDocu retorno NOOK" ,LOG04);
                            }
                        }
                    }
                    else
                    {
                        vDTrazasLog(szModulo,"Archivo Correcto",LOG03);
                        memset(szArchivoFinal,'\0',sizeof(szArchivoFinal));
                        memset(archivo_temporal,'\0',sizeof(archivo_temporal));
                        vDTrazasLog(szModulo,"Nombre de Archivo [%s]",LOG03,Nombre_Arch);
                        strcpy(szArchivoFinal,"mv ");
                        strcat(szArchivoFinal,Nombre_Arch);
                        strncpy(archivo_temporal,Nombre_Arch,_strlen(Nombre_Arch)-4);
                        strcat(archivo_temporal,".tmp");
                        strcat(szArchivoFinal," ");
                        strncat(szArchivoFinal,Nombre_Arch,_strlen(Nombre_Arch)-4);
                        strcat(szArchivoFinal,".tmp");
                        vDTrazasLog(szModulo,"Comando [%s*]",LOG03, szArchivoFinal);
                        fclose(Fd_ArchImp);
                        system(szArchivoFinal);
                        marca_cliente_facturado(sem_id,retorno);
                        if ( iUpdateFactDocu_MC(ParametrosEntrada.lCodCiclFact,&FacturaCliente_mc,&SaldoAnt,&pstFaCuotas,&stBalance,archivo_temporal,sem_id,0) )
                        {
                            vDTrazasLog(szModulo,  "iUpdateFactDocu retorno OK" ,LOG04);
                        }
                        else
                        {
                            vDTrazasLog(szModulo,  "iUpdateFactDocu retorno NOOK" ,LOG04);
                        }
                    }
                    vDTrazasLog(szModulo,"------------------------------------------------------------------------------------------" ,LOG03);
                }
                else
                {
                    vDTrazasLog(szModulo,"NO HAY CLIENTES EN MEMORIA COMPARTIDA" ,LOG06);
                }
            }
            return(TRUE);
        }
    }
}
/************************************************************/

int main(int argc, char * argv[])
{
    LINEACOMANDO      StParametrosEntrada;
    struct timeb      tpi;
    struct timeb      tpt;
    flg_mc=FALSE;

    char *szModulo="main";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    /*-----------------------------------------------------------------------------
    LECTURA DE PARAMETROS DE ENTRADA :
    -----------------------------------------------------------------------------*/
    ftime(&tpi);
    printf("\nImpresionScl version " __DATE__ " " __TIME__ " ECU MC.\n\n Inicio = %ld.%d\n",tpi.time,tpi.millitm);
    if ( CheckParamEntrada(argc,argv,&StParametrosEntrada)!=0 )
    {
        if ( !flg_mc )
        {
            vDTrazasLog(szModulo,"CheckParamEntrada:error parametros",LOG01);
            return(FALSE);
        }
    }

    if ( lNroJob )
    {
        printf("\n******* Simulacion de Impresion JOB Nro %ld *******\n", lNroJob);
    }

    if ( flg_mc )
    {
        printf("EN MODALIDAD MEMORIA COMPARTIDA...\n");
        id_memoria=0;
        id_memoria=unir_a_memoria(5100,TABLA_MEMORIA);

        if ( id_memoria<0 )
        {
            printf("NO SE PUEDE OBTENER ID PARA MEMORIA COMPARTIDA TABLA MEMORIA \n");
            return(FALSE);
        }

        printf ("IDENTIFACOR DE MEMORIA OBTENIDO :%d\n",id_memoria);

        memset(&StParametrosEntrada,0,sizeof(LINEACOMANDO));
        memcpy(&StParametrosEntrada , &memoria[0].StParametrosEntrada,sizeof(LINEACOMANDO));

        id_numorden=0;
        printf("NUMERO DE REGISTOS NUM ORDEN : %d\n",memoria[0].iregs_numorden);
        id_numorden=unir_a_memoria(memoria[0].iregs_numorden,TABLA_NUMORDEN);

        if ( id_numorden<0 )
        {
            printf("NO SE PUEDE OBTENER ID PARA MEMORIA COMPARTIDA TABLA NUM ORDEN \n");
            return(FALSE);
        }

        printf ("IDENTIFACOR DE MEMORIA PARA TABLA NUM ORDEN ES :%d\n",id_numorden);
    }

    vDTrazasLog(szModulo,"CICLO(%d) USER(%s/%s) IDIOM(%s) TIPDO(%d) CODDE(%s) NUMPROC(%d) NUMSEC(%ld) NROJOB(%ld)",
                LOG03,
                StParametrosEntrada.lCodCiclFact,
                StParametrosEntrada.szUser,StParametrosEntrada.szPass,
                StParametrosEntrada.szCodIdioma,
                StParametrosEntrada.iCodTipDocum,
                StParametrosEntrada.szCodDespacho,
                StParametrosEntrada.lProceso,
                StParametrosEntrada.lNum_SecuInfo,
                lNroJob);

    /*-----------------------------------------------------------------------------
    CONEXION A ORACLE :
    -----------------------------------------------------------------------------*/
    if ( !bfnConnectORA(StParametrosEntrada.szUser,StParametrosEntrada.szPass) )
    {
        vDTrazasLog(szModulo,"Usuario/Passwd Invalido(%s/%s)",
                    LOG00,
                    StParametrosEntrada.szUser,
                    StParametrosEntrada.szPass);
        return(FALSE);
    }
    else
    {
        vDTrazasLog(szModulo,"Conectado a ORACLE:Usuario/Passwd (%s/%s)",
                    LOG03,
                    StParametrosEntrada.szUser,
                    StParametrosEntrada.szPass);
    }

    /*--------------------------------------------------------------------------------------
      TRAZA PROCESOS
      --------------------------------------------------------------------------------------*/
    if ( StParametrosEntrada.lCodCiclFact )
    {
        if ( !flg_mc )
        {
            strcpy(szgHostId,"");
            if ( lNroJob )
            {
                igOpcionRango=0;
                strcpy(szgHostId,"-1");
                lgCodClienteIni=0;
                lgCodClienteFin=0;
            }
            else
            {
                if ((ifnGetHostId(szgHostId))!=0)
                {
                    vDTrazasLog (szModulo,"No pudo obtener Host\n",LOG04);
                    igOpcionRango=0;
                    strcpy(szgHostId,"-1");
                    lgCodClienteIni=0;
                    lgCodClienteFin=0;
                }
                else
                {
                    vDTrazasLog (szModulo,"Host [%s]\n",LOG04,szgHostId);
                    if (strlen(StParametrosEntrada.szCodDespacho))
                    {
                       if (!bfnValidaDespHostID (StParametrosEntrada.lCodCiclFact, StParametrosEntrada.szCodDespacho, szgHostId))
                       {
	                    vDTrazasLog(szModulo,"Error Codigo de Despacho no configurado para el host [%s] ",LOG01, szgHostId);
	                    return(FALSE);
	                }
                     }                
                     igOpcionRango=1;
                     if (iGetRangosHost(szgHostId,StParametrosEntrada.lCodCiclFact,&lgCodClienteIni,&lgCodClienteFin))
                     {
                         vDTrazasLog(szModulo,"Error en ejecucion de iGetRangosHost ",LOG02);
                         return(FALSE);
                    }
                }
            }

            if ( !bfnChequeaProcesosPrevios(StParametrosEntrada.lCodCiclFact,COD_PROCESO, igOpcionRango,szgHostId ) )
            {
                vDTrazasLog(szModulo,"Error en ejecucion de bfnChequeaProcesosPrevios ",LOG02);
                return(FALSE);
            }

            if ( !bfnReg_Padre(&StParametrosEntrada) )
            {
                vDTrazasLog(szModulo,"Error en ejecucion de bfnReg_Padre ",LOG02);
                return(FALSE);
            }
            if ( !lNroJob )
            {
                if ( !bfnActualizaRegprocImpres(StParametrosEntrada) )
                {
                    vDTrazasLog(szModulo,"Error en ejecucion de bfnActualizaRegprocImpres ",LOG02);
                    return(FALSE);
                }
            }
        }
    }
    else
    {
        if ( !BuscaCodInterfact(StParametrosEntrada.lProceso,StParametrosEntrada.lNum_SecuInfo,&StParametrosEntrada) )
        {
            vDTrazasLog(szModulo,"Falla en la ejecucion de  BuscaCodInterfact ",LOG01);
            return(FALSE);
        }
        vDTrazasLog(szModulo,"Codigo Interfact : [%d] [%d] ",LOG04,StParametrosEntrada.iCodEntrada,StParametrosEntrada.iCodSalida);
        if ( !ChequeaInterfact(StParametrosEntrada) )
        {
            vDTrazasLog(szModulo,"Error en ejecucion de ChequeaInterfact ",LOG02);
            return(FALSE);
        }
    }

    if ( StParametrosEntrada.lCodCiclFact )
    {
        if ( !CargaStringSuspension(StParametrosEntrada.lCodCiclFact) )
        {
            vDTrazasLog(szModulo,  "CargaStringSuspension retorno NOOK" ,LOG01);
            return(FALSE);
        }
        if ( !iCargaFechaSuspensionSt() )
        {
            vDTrazasLog(szModulo,  "iCargaFechaSuspensionSt retorno NOOK" ,LOG01);
            return(FALSE);
        }
    }
    /*-----------------------------------------------------------------------------
    INVOCACION DE LA LOGICA DE PROCESO :
    -----------------------------------------------------------------------------*/
    if ( !bfnMainProcess(StParametrosEntrada) )
    {
        vDTrazasLog(szModulo, "FIN DE PROCESO NOOK", LOG01);
        if ( !lNroJob )
        {
            if ( StParametrosEntrada.lCodCiclFact )
            {
                if ( !bfnActualiza_ProcImpresion(StParametrosEntrada, FALSE) )
                {
                    vDTrazasLog(szModulo, "Falla en Actualizacion del estado de Proc. de Impresion", LOG01);
                }
            }
            if ( !bfnActualiza_TrazaProceso(StParametrosEntrada,FALSE) )
            {
                vDTrazasLog(szModulo, "Falla en actualizacion de traza de proceso", LOG01);
            }
        }
        else
        {
            vDTrazasLog (szModulo,"bfnUpdTrazaJob FALSE",LOG03);
            bfnUpdTrazaJob(StParametrosEntrada.lCodCiclFact, FALSE ) ;
        }
        return(FALSE);
    }

    if ( !flg_mc )
    {
        if ( !lNroJob )
        {
            if ( StParametrosEntrada.lCodCiclFact )
            {
                if ( !bfnActualiza_ProcImpresion(StParametrosEntrada, TRUE) )
                {
                    vDTrazasLog(szModulo, "Falla en Actualizacion del estado de Proc. de Impresion", LOG01);
                }
            }
            if ( !bfnActualiza_TrazaProceso(StParametrosEntrada,TRUE) )
            {
                vDTrazasLog(szModulo, "Falla en actualizacion de traza de proceso", LOG01);
            }
        }
        else
        {
            vDTrazasLog (szModulo,"bfnUpdTrazaJob TRUE",LOG03);
            bfnUpdTrazaJob(StParametrosEntrada.lCodCiclFact, TRUE ) ;
        }
    }

    ftime(&tpt);
    printf("Termino = %ld.%d\n",tpt.time,tpt.millitm);
    vDTrazasLog(szModulo, "FIN DE PROCESO OK", LOG02);
    return(0);
}  /******** main ************/



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



