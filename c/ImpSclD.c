
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
           char  filnam[16];
};
static const struct sqlcxp sqlfpn =
{
    15,
    "./pc/ImpSclD.pc"
};


static unsigned int sqlctx = 1728667;


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
   unsigned char  *sqhstv[21];
   unsigned long  sqhstl[21];
            int   sqhsts[21];
            short *sqindv[21];
            int   sqinds[21];
   unsigned long  sqharm[21];
   unsigned long  *sqharc[21];
   unsigned short  sqadto[21];
   unsigned short  sqtdso[21];
} sqlstm = {12,21};

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

 static const char *sq0004 = 
"select COD_FACTURACION ,IND_TABLA  from TA_CONCEPFACT  union select COD_CONC\
FACT ,4  from FA_FACTCARRIERS            ";

 static const char *sq0006 = 
"select NOM_PARAMETRO ,VAL_PARAMETRO ,DES_PARAMETRO  from GED_PARAMETROS wher\
e NOM_PARAMETRO in (:b0,:b1)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,31,0,0,
5,0,0,1,0,0,17,76,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,2,0,0,17,303,0,0,1,1,0,1,0,1,97,0,0,
43,0,0,2,0,0,45,323,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
74,0,0,2,0,0,13,370,0,0,17,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,4,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,
5,0,0,2,5,0,0,
157,0,0,2,0,0,15,430,0,0,0,0,0,1,0,
172,0,0,1,0,0,45,458,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
203,0,0,3,0,0,17,1227,0,0,1,1,0,1,0,1,97,0,0,
222,0,0,3,0,0,45,1247,0,0,6,6,0,1,0,1,5,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,
261,0,0,3,0,0,13,1291,0,0,8,0,0,1,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,
3,0,0,2,4,0,0,2,5,0,0,
308,0,0,3,0,0,15,1349,0,0,0,0,0,1,0,
323,0,0,4,117,0,9,1381,0,0,0,0,0,1,0,
338,0,0,4,0,0,13,1392,0,0,2,0,0,1,0,2,3,0,0,2,3,0,0,
361,0,0,4,0,0,15,1413,0,0,0,0,0,1,0,
376,0,0,1,0,0,13,1431,0,0,21,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,
475,0,0,1,0,0,15,1499,0,0,0,0,0,1,0,
490,0,0,5,0,0,17,2123,0,0,1,1,0,1,0,1,97,0,0,
509,0,0,5,0,0,45,2142,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
540,0,0,5,0,0,13,2168,0,0,21,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,
639,0,0,5,0,0,15,2219,0,0,0,0,0,1,0,
654,0,0,6,115,0,9,2264,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
677,0,0,6,0,0,13,2278,0,0,3,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,
704,0,0,6,0,0,15,2311,0,0,0,0,0,1,0,
719,0,0,7,184,0,4,2393,0,0,7,5,0,1,0,2,4,0,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,
762,0,0,8,144,0,4,2438,0,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
};


/*  Version  FAC_DES_MAS ImpSclD.pc  6.000   */
#include <ImpSclD.h>
#include <utils.h>

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


    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

        long lhCodCliente;
        long lhNumAbonado;
        long lhNumProceso;
        char szhFormatoFecha[22] ;   /* EXEC SQL VAR szhFormatoFecha IS STRING(22); */ 

        char szhFormatoHora [9]  ;   /* EXEC SQL VAR szhFormatoHora IS STRING(9); */ 

        int  ihTipConce  ;
        char szhformato_fecha[22];
        char szhformato_hora[9];
        int  ihDValorCero=0;
        char szhDWhere     [513];
    /* EXEC SQL END DECLARE SECTION    ; */ 


int ifnPreparaConsTraf (void)
{
    char *szModulo="ifnPreparaConsTraf";

    char gszSufTablasCiclo[15]; /* ej: 150109_123 ciclo_job */

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char  szhSql[5000] = "";
    /* EXEC SQL END DECLARE SECTION; */ 


    if( lNroJob )
    {
        /* Modo JOB proforma */
        /* prepara sufijo para tablas ciclo+job */
        sprintf (gszSufTablasCiclo, "%ld_%ld", lCodCiclFactAux, lNroJob);
    }
    else
    {
        /*Modo Normal*/
        /* prepara sufijo para tablas ciclo */
        sprintf (gszSufTablasCiclo, "%ld", lCodCiclFactAux);
    }/* if (iEjecutaJob!=0) */

    sprintf(szhSql, "SELECT  SEC_EMPA, SEC_CDR, "
                      "\n\t  MAX(TO_CHAR(TO_DATE(DATE_START_CHARG || TIME_START_CHARG, 'YYYYMMDDHH24MISS'), :szhformato_fecha)), "
                      "\n\t  MAX(TO_CHAR(TO_DATE(TIME_START_CHARG,'HH24MISS'), :szhformato_hora)), "
                      "\n\t  MAX(A_SUSC_NUMBER), "
                      "\n\t  MAX(B_SUSC_NUMBER), "
                      "\n\t  SUM(DECODE(ind_billete,'01',MTO_FACT,0)), "
                      "\n\t  SUM(DECODE(ind_billete,'02',MTO_FACT,0)), "
                      "\n\t  MAX(COD_THOR),  "
                      "\n\t  MAX(COD_ALMA),  "
                      "\n\t  MAX(DES_DESTINO), "
                      "\n\t  MAX(DECODE(ind_billete,'01',TO_CHAR(DUR_FACT),'0')), "
                      "\n\t  MAX(DECODE(ind_billete,'02',TO_CHAR(DUR_FACT),'0')), "
                      "\n\t  MAX(COD_SENT), "
                      "\n\t  SUM(MTO_REAL), "
                      "\n\t  SUM(MTO_DCTO), "
                      "\n\t  SUM(DUR_REAL), "
                      "\n\t  SUM(DUR_DCTO), "
                      "\n\t  COD_CARG     , "
                      "\n\t  A.COD_FCOB   , "
                      "\n\t  0              "
                      "\n  FROM  PF_TOLTARIFICA_%s A "
                      "\nWHERE   A.NUM_CLIE = :lhCodCliente "
                      "\n  AND   A.NUM_ABON = :lhNumAbonado "
                      "\n  AND   EXISTS (SELECT 1 FROM GED_CODIGOS  G "
                                      "\n WHERE G.COD_MODULO  = 'FA' "
                                        "\n AND G.NOM_TABLA   = 'TABLA_LLAMADAS_TOL' "
                                        "\n AND G.NOM_COLUMNA = 'LLAMADAS_TOL' "
                                        "\n AND G.COD_VALOR   = A.COD_TCOR ) "
                      "\nGROUP BY SEC_EMPA,SEC_CDR,COD_CARG, A.COD_FCOB,0  "
                      ,gszSufTablasCiclo);

    vDTrazasLog(szModulo,"\t %s **\t\t%s\n**********************************",LOG06,szModulo,szhSql);

    /* EXEC SQL PREPARE QueryTolTarifica FROM :szhSql; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhSql;
    sqlstm.sqhstl[0] = (unsigned long )5000;
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


    if(SQLCODE != SQLOK)
    {
        vDTrazasLog(szModulo,"\t\tError en SQL-PREPARE %s **"
                                "\t\tError : [%s] [%d]  [%s] ",LOG01,szModulo,szhSql,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE %s **"
                                "\t\tError : [%s] [%d]  [%s] ",LOG01,szModulo,szhSql,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }
    /* EXEC SQL DECLARE Cur_TolTarifica CURSOR FOR QueryTolTarifica; */ 

    if(SQLCODE != SQLOK)
    {
        vDTrazasLog(szModulo,"\t\tError en SQL-DECLARE QueryTolTarifica **"
                                "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE QueryTolTarifica **"
                                "\t\tError : [%s] [%d]  [%s] ",LOG01,szhSql,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    return TRUE;
}

/****************************************************************************/
/* Funcion: BOOL bfnDetLlamRoaming (FACTDOC, int )                          */
/* Imprime Detalle de Llamadas Locales por Cliente, Abonado                 */
/****************************************************************************/
BOOL bfnDetLlamRoaming  ( ST_ABONADO *pst_Abonados
                        , ST_FACTCLIE *pst_Cliente
                        , int iIndice
                        , int iTipoLlamada
                        , FILE *fArchImp
                        , char *szBuffer
                        , int *bImprimioD1000
                        , int iTasador
                        , char *szhCodRegistro
                        , char *szhBufferCursor)
{
int             iSqlCodeDetRoaming     ;
DETROAMING      stDetRoaming           ;
char            szRegistro[150]        ;
char            szBuffer_local[25 ]="" ;
char            szMinutos[7+1];
int             bImprimioD2000 = FALSE;

    strcpy (szModulo, "bfnDetLlamRoaming");
    vDTrazasLog("","\n\t Entrada a %s"
                   "\n\t\t==> Cod. Cliente     [%ld]"
                   "\n\t\t==> Ind. OrdenTotal  [%ld]"
                   "\n\t\t==> Num. Abonado     [%ld]"
                   "\n\t\t==> Num. Celular     [%ld]"
                   "\n\t\t==> Indice           [%d]"
                   "\n\t\t==> Cod. Registro    [%s]"
                   "\n\t\t==> szhBufferCursor  [%s]"
                   ,LOG04
                   ,szModulo
                   ,pst_Cliente->lCodCliente
                   ,pst_Cliente->lIndOrdenTotal
                   ,pst_Abonados->lNumAbonado[iIndice]
                   ,pst_Abonados->lNumCelular[iIndice]
                   ,iIndice
                   ,szhCodRegistro
                   ,szhBufferCursor);

    memset(szBuffer_local,0,sizeof(szBuffer_local));

    /************************************************************************************/
    /*    Recupera Detalle de Llamadas Roaming                                          */
    /************************************************************************************/
    iSqlCodeDetRoaming = ifnOpenDetRoaming( pst_Cliente->lCodCliente,
                                            pst_Abonados->lNumAbonado[iIndice],
                                            pst_Cliente->lNumProceso,
                                            iTasador,
                                            szhBufferCursor);

    while (iSqlCodeDetRoaming)
    {
        memset(&stDetRoaming    , 0, sizeof (DETROAMING));

        iSqlCodeDetRoaming = ifnFetchDetRoaming(&stDetRoaming);

        if(iSqlCodeDetRoaming)  {
            if(iSqlCodeDetRoaming & !*bImprimioD1000)
            {
              put_D1000(pst_Abonados,fArchImp,iIndice,szBuffer);
              *bImprimioD1000 = TRUE;
            }

            if (!bImprimioD2000)
            {
                /******************************** ************/
                /* Escribe cabecera de tipo de registro      */
                /*********************************************/

                sprintf(szBuffer_local ,"%5s%013d%05d\n"
                                       ,COD_TIPOLLAMADA
                                       ,iTipoLlamada
                                       ,atoi(pst_Cliente->szCod_Idioma));
                bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
                bImprimioD2000=TRUE;
            }

            sprintf(szMinutos,"%7.7ld",stDetRoaming.lSegundos);
           sprintf(szRegistro   ,"%5s%05d%-20s%-8.8s%-6s%015.4f%-7s%06.6s%-20s%-20s%04d%015.4f%015.4f%-7s%-7s%-04.4s\n"
                                ,szhCodRegistro
                                ,stDetRoaming.iCodOperRoa
                                ,stDetRoaming.szNumMovil
                                ,stDetRoaming.szFecLlamada
                                ,stDetRoaming.szHraLlamada
                                ,stDetRoaming.dImporte
                                ,szMinutos
                                ,stDetRoaming.iIndEntSal
                                ,stDetRoaming.szNumDestino
                                ,stDetRoaming.szDesDestino
                                ,stDetRoaming.iCod_Carg
                                ,stDetRoaming.dImpLocal1
                                ,stDetRoaming.dImpLarga2
                                ,stDetRoaming.szDurLocal1
                                ,stDetRoaming.szDurLarga2 /*WAGC*/
                                ,stDetRoaming.szTipTraf);  /* MLA  MGA 123425 */

            bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);
        }
    }
    if(bImprimioD2000)
    {
        sprintf(szBuffer_local,"%s\n",PIE_TIPOLLAMADA);
        bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
    }

    if ((iSqlCodeDetRoaming != SQLOK) && (iSqlCodeDetRoaming != SQLNOTFOUND))
    {
        vDTrazasLog(szModulo,"\n\t\t\t** (bfnDetLlamRoaming) Fetch"
                             "\n\t\t IndOrdenTotal  [%ld]"
                             "\n\t\t Error Oracle   [%s]"
                             ,LOG01, pst_Cliente->lIndOrdenTotal,SQLERRM);
        vDTrazasError(szModulo,"\n\t\t\t** (bfnDetLlamRoaming) Fetch"
                               "\n\t\t IndOrdenTotal  [%ld]"
                               "\n\t\t Error Oracle   [%s]"
                               ,LOG01, pst_Cliente->lIndOrdenTotal,SQLERRM);
        return (FALSE);
    }

    if (!bfnCloseDetRoaming())
        return FALSE;

    return (TRUE);
}/*********************** FIN bfnDetLlamRoaming *****************************/


/************************************************************************/
/*  Funcion: int ifnOpenDetRoaming(long , long)                         */
/*  Funcion que Abre el cursor de  TA_LLAMADASROA                       */
/************************************************************************/
int ifnOpenDetRoaming(long lCodCliente, long lNumAbonado,long lNumProceso,int iTasador, char *szhBufferCursor)
{
    char szQry       [4000];
    char szAndCodLlam       [2100];
    char gszSufTablasCiclo[15]; /* ej: 150109_123 ciclo_job */

    memset(szQry,0,sizeof(szQry));

    lhCodCliente = lCodCliente;
    lhNumAbonado = lNumAbonado;
    lhNumProceso = lNumProceso;

    strcpy (szhFormatoFecha,szformato_fecha);
    strcpy (szhFormatoHora,szformato_hora);

    strcpy (szModulo, "ifnOpenDetRoaming");

    vDTrazasLog("","\n\t\t(%s) Abriendo Detalle Carrier "
                   "\n\t\t==> Cliente      [%ld]"
                   "\n\t\t==> Abonado      [%ld]"
                   "\n\t\t==> Num.Proceso  [%ld]"
                   "\n\t\t==> Ind.Tasador  [%d] "
                   "\n\t\t==> [%s] [%s]*"
                   "\n\t\t==> szhBufferCursor [%s]*"
                   ,LOG04,szModulo,lCodCliente,lNumAbonado,lNumProceso,iTasador, szhFormatoFecha,szhFormatoFecha,szhBufferCursor);

    if( lNroJob )
    {
        /* Modo JOB proforma */
        /* prepara sufijo para tablas ciclo+job */
        sprintf (gszSufTablasCiclo, "%ld_%ld", lCodCiclFactAux, lNroJob);
    }
    else
    {
        /*Modo Normal*/
        /* prepara sufijo para tablas ciclo */
        sprintf (gszSufTablasCiclo, "%ld", lCodCiclFactAux);
    }/* if (iEjecutaJob!=0) */

    if (strcmp(szhBufferCursor,"NULL")==0)
        strcpy(szAndCodLlam," ");
    else
        sprintf(szAndCodLlam,"\n AND COD_LLAM IN (%s) ",szhBufferCursor);

    sprintf(szQry,"\n SELECT  NVL(SEC_EMPA, ' '), NVL(SEC_CDR, ' '), NVL(MAX(COD_OPERA), ' '), "
                  "\n         NVL(MAX(A_SUSC_NUMBER), ' '), "
                  "\n         NVL(MAX(to_char(TO_DATE(DATE_START_CHARG,'YYYYMMDD'),:szhFormatoFecha)), ' ') FECHA, "
                  "\n         NVL(MAX(to_char(to_date(TIME_START_CHARG,'HH24MISS'),:szhFormatoHora)), ' ') HORA,  "
                  "\n         NVL(SUM(MTO_FACT), 0), "
                  "\n         NVL(SUM(DUR_FACT), 0), "
                  "\n         NVL(MAX(COD_SENT), ' '), "
                  "\n         NVL(MAX(B_SUSC_NUMBER), ' '), "
                  "\n         NVL(MAX(DES_DESTINO),'.'), "
                  "\n         NVL(COD_CARG, 0), "
                  "\n         SUM(DECODE(ind_billete,'01',MTO_FACT,0)), "
                  "\n         SUM(DECODE(ind_billete,'02',MTO_FACT,0)), "
                  "\n         MAX(DECODE(ind_billete,'01',TO_CHAR(DUR_FACT),'0')), "
                  "\n         MAX(DECODE(ind_billete,'02',TO_CHAR(DUR_FACT),'0')), "
                  "\n         B.TIP_TRAF "
                  "\n FROM    PF_TOLTARIFICA_%s , FA_REGDETLLAM_TD B "
                  "\n WHERE   NUM_CLIE = :lhCodCliente "
                  "\n   AND   NUM_ABON = :lhNumAbonado "
                  "\n   AND   COD_LLAM = B.VALOR "
                  "\n  AND   EXISTS (SELECT 1 FROM GED_CODIGOS G "
                  "\n               WHERE G.COD_MODULO  = 'FA' "
                  "\n               AND   G.NOM_TABLA   = 'TABLA_LLAMADAS_ROAMING' "
                  "\n               AND   G.NOM_COLUMNA = 'LLAMADAS_ROAM' "
                  "\n               AND   G.COD_VALOR   = COD_TCOR ) "
                  "%s" /* Configuracion del registro D */
                  "\n GROUP BY SEC_EMPA,SEC_CDR,COD_CARG, TIP_TRAF "
                  "\n ORDER BY FECHA, HORA",gszSufTablasCiclo, szAndCodLlam); /* MGA */

    vDTrazasLog(szModulo,"\t\tQRY cDetRoaming_Tol:[ %s ]",LOG05,szQry);

    /* EXEC SQL PREPARE sql_Cur_Roaming FROM :szQry; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )24;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szQry;
    sqlstm.sqhstl[0] = (unsigned long )4000;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-PREPARE sql_Cur_Roaming **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_Cur_Roaming **"
                      "\t\tError : [%s] [%d]  [%s] ",LOG01,szQry,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    /* EXEC SQL DECLARE cDetRoaming_Tol CURSOR FOR sql_Cur_Roaming; */ 

    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE cDetRoaming_Tol **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE cDetRoaming_Tol **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    /* EXEC SQL 
    	OPEN cDetRoaming_Tol 
    	USING :szhFormatoFecha
    	     ,:szhFormatoHora
    	     ,:lhCodCliente
    	     ,:lhNumAbonado; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )43;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhFormatoFecha;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhFormatoHora;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
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


    	     
    if (SQLCODE != SQLOK) {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN CURSOR cDetCarrier **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN CURSOR cDetCarrier **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    return TRUE;
}/*****************  Final de ifnOpenDetRoaming  ********************/

/************************************************************************/
/*  Funcion: int ifnFetchDetRoaming(DETROAMING*)                        */
/*  Funcion que realiza FETCH sobre TA_LLAMADASROA                      */
/************************************************************************/
int ifnFetchDetRoaming(DETROAMING *stDetRoaming)
{
    /* EXEC SQL BEGIN DECLARE SECTION ; */ 

        int     ihCodOperRoam      ;
        char    szhNumMovil    [16]; /* EXEC SQL VAR szhNumMovil   IS STRING(16); */ 

        char    szhFecLlamada  [22]; /* EXEC SQL VAR szhFecLlamada IS STRING(22); */ 

        char    szhHraLlamada  [9] ; /* EXEC SQL VAR szhHraLlamada IS STRING (9); */ 

        double  dhImporte          ;
        long    lhSegundos         ;
        char    szhIndEntSal   [6] ; /* EXEC SQL VAR szhIndEntSal  IS STRING (6); */ 

        char    szhNumDestino  [19]; /* EXEC SQL VAR szhNumDestino IS STRING(19); */ 

        char    szhDesDestino  [31]; /* EXEC SQL VAR szhDesDestino IS STRING(31); */ 

        char    szhSecEmpa     [31]; /* EXEC SQL VAR szhSecEmpa    IS STRING(31); */ 

        char    szhSecCdr      [7] ; /* EXEC SQL VAR szhSecCdr     IS STRING (7); */ 

        int     ihCodCarg          ;
        double  dhImpLocal1        ;
        double  dhImpLarga2        ;
        char    szhDurLocal1[10]; /* EXEC SQL VAR szhDurLocal1     IS STRING (10); */ 

        char    szhDurLarga2[10]; /* EXEC SQL VAR szhDurLarga2     IS STRING (10); */ 

        char    szhTipTraf[4]; /* EXEC SQL VAR szhTipTraf         IS STRING (4); */ 
 /*MLA 123425*/
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "ifnFetchDetRoaming");
    vDTrazasLog("","\n\tEntrada en %s", LOG04,szModulo);

    /* EXEC SQL FETCH cDetRoaming_Tol INTO
        :szhSecEmpa     ,
        :szhSecCdr      ,
        :ihCodOperRoam  ,
        :szhNumMovil    ,
        :szhFecLlamada  ,
        :szhHraLlamada  ,
        :dhImporte      ,
        :lhSegundos     ,
        :szhIndEntSal   ,
        :szhNumDestino  ,
        :szhDesDestino  ,
        :ihCodCarg      ,
        :dhImpLocal1    ,
        :dhImpLarga2    ,
        :szhDurLocal1   ,
        :szhDurLarga2   ,
        :szhTipTraf     ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )74;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)szhSecEmpa;
    sqlstm.sqhstl[0] = (unsigned long )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhSecCdr;
    sqlstm.sqhstl[1] = (unsigned long )7;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihCodOperRoam;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhNumMovil;
    sqlstm.sqhstl[3] = (unsigned long )16;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecLlamada;
    sqlstm.sqhstl[4] = (unsigned long )22;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhHraLlamada;
    sqlstm.sqhstl[5] = (unsigned long )9;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&dhImporte;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&lhSegundos;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)szhIndEntSal;
    sqlstm.sqhstl[8] = (unsigned long )6;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)szhNumDestino;
    sqlstm.sqhstl[9] = (unsigned long )19;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)szhDesDestino;
    sqlstm.sqhstl[10] = (unsigned long )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&ihCodCarg;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&dhImpLocal1;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&dhImpLarga2;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)szhDurLocal1;
    sqlstm.sqhstl[14] = (unsigned long )10;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)szhDurLarga2;
    sqlstm.sqhstl[15] = (unsigned long )10;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)szhTipTraf;
    sqlstm.sqhstl[16] = (unsigned long )4;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
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



    if(SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
    {
        vDTrazasLog (szModulo, "\n\t\t Error Oracle : %s - %s", LOG01,"Fetch=> PF_TOLTARIFICA", SQLERRM );
        vDTrazasError(szModulo,"\n\t\t Error Oracle : %s - %s", LOG01,"Fetch=> PF_TOLTARIFICA", SQLERRM );
        return FALSE;
    }

    if (SQLCODE == SQLOK)
    {
        stDetRoaming->iCodOperRoa   = ihCodOperRoam ;
        stDetRoaming->dImporte      = dhImporte;
        stDetRoaming->lSegundos     = (lhSegundos);

        sprintf(stDetRoaming->iIndEntSal   ,"%s\0",szhIndEntSal  );
        sprintf(stDetRoaming->szNumMovil   ,"%s\0",szhNumMovil  );
        sprintf(stDetRoaming->szFecLlamada ,"%s\0",szhFecLlamada);
        sprintf(stDetRoaming->szHraLlamada ,"%s\0",szhHraLlamada);
        sprintf(stDetRoaming->szNumDestino ,"%s\0",szhNumDestino);
        sprintf(stDetRoaming->szDesDestino ,"%s\0",szhDesDestino);
        stDetRoaming->iCod_Carg     = ihCodCarg;
        stDetRoaming->dImpLocal1  = dhImpLocal1;
        stDetRoaming->dImpLarga2  = dhImpLarga2;
        strcpy(stDetRoaming->szDurLocal1,  szhDurLocal1);
        strcpy(stDetRoaming->szDurLarga2,  szhDurLarga2);
        strcpy(stDetRoaming->szTipTraf,  szhTipTraf);  /* MLA   MGA  123425*/
    }
    else
        return FALSE;

    return TRUE;
}/****************  Final de ifnFetchDetRoaming    ******************/

/************************************************************************/
/*  Funcion: int bfnClosseDetRoaming(void)                               */
/*  Funcion que cierra el cursor sobre TA_LLAMADASROA                   */
/************************************************************************/
BOOL bfnCloseDetRoaming( void )
{
    strcpy (szModulo, "bfnCloseDetRoaming");
    vDTrazasLog("","\n\tEntrada en %s", LOG04,szModulo);

    /* EXEC SQL CLOSE cDetRoaming_Tol ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )157;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(SQLCODE != SQLOK)
    {
        vDTrazasLog(szModulo, "\n\n\t Error al cerrar el Cursor DetRoaming: %s", LOG01, SQLERRM);
        vDTrazasError(szModulo, "\n\n\t Error al cerrar el Cursor DetRoaming: %s", LOG01, SQLERRM);
        return FALSE;
    }
    return TRUE;
}/***********************  bfnCloseDetRoaming   *********************/


/***********************************************************************************/
int  ifnOraOpenTraficoTolTarifica (long lCodCliente, long lNumAbonado)
{
    char *szModulo="ifnOraOpenTraficoTolTarifica";

    strcpy(szhformato_fecha, szformato_fecha); 
    strcpy(szhformato_hora , szformato_hora ); 
    lhCodCliente = lCodCliente;
    lhNumAbonado = lNumAbonado;

    vDTrazasLog  (szModulo, "\t\t %s "
                            "\t\t\t szformato_fecha    [%s]"
                            "\t\t\t szformato_hora     [%s]"
                            "\t\t\t lCodCliente        [%ld]"
                            "\t\t\t lNumAbonado        [%ld]"
                            ,LOG05,szModulo, szhformato_fecha,szhformato_hora,lhCodCliente,lhNumAbonado);
    /* EXEC SQL
        OPEN Cur_TolTarifica
       USING :szhformato_fecha
           , :szhformato_hora
           , :lhCodCliente
           , :lhNumAbonado; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )172;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhformato_fecha;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhformato_hora;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
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



    return  (SQLCODE);
}


/****************************************************************************/
/* Funcion: BOOL bfnDetLlamCelularTOL (FACTDOC, int, int )                     */
/* Detalle de Llamadas Locales, Interzona y Especiales or Cliente, Abonado  */
/****************************************************************************/
BOOL bfnDetLlamCelularTOL ( ST_ABONADO *pst_Abonados
                          , ST_FACTCLIE *pst_Cliente
                          , int iIndice
                          , FILE *fArchImp
                          , char *szBuffer
                          , int *bImprimioD1000
                          ,DETALLEOPER *pst_MascaraOper)
{

    char            szTipoRegistro[20];
    BOOL            bEscribe = TRUE;

    DETLLAMADAS       *pstDetLlamadasTemp;
    DETCELULAR_AGRUP  *stDetCelularTemp;
    static DETLLAMADAS_HOSTS stDetLlamHost;

    NUMORDEN    pstNumOrden;
    char        szRegistro[MAX_BYTES_REGISTRO+1];
    char        szBuffer_local[25];
    char        szDurReal[7+1];
    char        szDurDcto[7+1];
    int         iDurReal;
    int         iDurDcto;
    int         bImprimioD2000 = FALSE;
    int         iOra;
    int         iNumFilas = 0;
    int         iCont,i,j;
    int         ihCodCargo;
    long        lPosicion;
    double      dTotalLocal1Larga2;

    memset(&pstNumOrden, 0, sizeof(NUMORDEN));

    strcpy (szModulo, "bfnDetLlamCelularTOL");
    vDTrazasLog(szModulo, "\n\tEntrada en %s"
		                  "\n\t\t==> Cod_Cliente  [%ld]"
		                  "\n\t\t==> Num. Abonado [%ld]"
		                  "\n\t\t==> Num. Celular [%ld]"
		                  "\n\t\t==> Indice       [%d]"
		                  ,LOG04,szModulo
		                  ,pst_Cliente->lCodCliente
		                  ,pst_Abonados->lNumAbonado[iIndice]
		                  ,pst_Abonados->lNumCelular[iIndice]
		                  ,iIndice);

    iOra= ifnOraOpenTraficoTolTarifica ( pst_Cliente->lCodCliente, pst_Abonados->lNumAbonado[iIndice]);

    if (iOra != SQLOK)
    {
        vDTrazasLog (szModulo,"\n\nERROR(%s):"
                              "\n\tError al declarar cursor sobre DETCELULAR", LOG05,szModulo );
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\n%s: Antes del While Principal", LOG04,szModulo );
    while (iOra != SQLNOTFOUND)
    {
        iOra = ifnOraLeerTolTarifica(&stDetLlamHost,&iNumFilas);

        if (iOra != SQLOK  && iOra != SQLNOTFOUND)
        {
            vDTrazasLog (szModulo,"\n\n%s: Salida de FETCH sobre DETCELULAR", LOG05,szModulo );
            return (FALSE);
        }

        if (!iNumFilas)
            break;

        for (iCont = 0 ; iCont < iNumFilas ; iCont++)
        {
            if (bfnDeterminaGrupo(stDetLlamHost.iCod_Carg[iCont], &stDetCelular, &lPosicion, &pstNumOrden))
            {
                vDTrazasLog (szModulo,"\t(bfnDetLlamCelularTOL): Existe grupo... solo agrega llamada \n", LOG04 );

                /* valida mascara */
                if ( ( strcmp (pstNumOrden.szCodRegistro, COD_LOCALES)          == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_INTERZONA)        == 0 && pst_Abonados->iIndInterzona[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_LDI)              == 0 && pst_Abonados->iIndLdi[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_ESPECIALES)       == 0 && pst_Abonados->iIndEspeciales[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_ESPECIALES_DATA)  == 0 && pst_Abonados->iIndEspeciales[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_TARIFA_ADICIONAL) == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_INTERCOMPANIA)    == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_MENSAJEPREMIMUN)  == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_LOCALES)          == 0 && pst_Abonados->iIndLocal[iIndice] ) )
                {
                    stDetCelular.stAgrupacion[lPosicion].stDetLlamadas = (DETLLAMADAS*) realloc(stDetCelular.stAgrupacion[lPosicion].stDetLlamadas, sizeof(DETLLAMADAS)* (stDetCelular.stAgrupacion[lPosicion].iCantLlamadas + 1));
                    pstDetLlamadasTemp = &(stDetCelular.stAgrupacion[lPosicion].stDetLlamadas)[(stDetCelular.stAgrupacion[lPosicion].iCantLlamadas)];
                    memset(pstDetLlamadasTemp, 0, sizeof(DETLLAMADAS));

                    strcpy(pstDetLlamadasTemp->szSec_Empa           , stDetLlamHost.szSec_Empa[iCont]       );
                    strcpy(pstDetLlamadasTemp->szSec_Cdr            , stDetLlamHost.szSec_Cdr[iCont]    );
                    strcpy(pstDetLlamadasTemp->szFecIniTasa         , stDetLlamHost.szFecIniTasa[iCont] );
                    strcpy(pstDetLlamadasTemp->szTieIniLlam         , stDetLlamHost.szTieIniLlam[iCont] );
                    strcpy(pstDetLlamadasTemp->szNumMovil1          , stDetLlamHost.szNumMovil1[iCont]  );
                    strcpy(pstDetLlamadasTemp->szNumMovil2          , stDetLlamHost.szNumMovil2[iCont]  );
                    strcpy(pstDetLlamadasTemp->szCodFranHoraSoc     , stDetLlamHost.szCodFranHoraSoc[iCont] );
                    strcpy(pstDetLlamadasTemp->szCodAlm             , stDetLlamHost.szCodAlm[iCont]     );
                    strcpy(pstDetLlamadasTemp->szDesMovil2          , stDetLlamHost.szDesMovil2[iCont]  );
                    strcpy(pstDetLlamadasTemp->szDurLocal1          , stDetLlamHost.szDurLocal1[iCont]  );
                    strcpy(pstDetLlamadasTemp->szDurLarga2          , stDetLlamHost.szDurLarga2[iCont]  );
                    strcpy(pstDetLlamadasTemp->szIndEntSal1         , stDetLlamHost.szIndEntSal1[iCont] );
                    pstDetLlamadasTemp->dMto_Real  = stDetLlamHost.dMto_Real[iCont] ;
                    pstDetLlamadasTemp->dMto_Dcto  = stDetLlamHost.dMto_Dcto[iCont] ;
                    pstDetLlamadasTemp->iDur_Real  = stDetLlamHost.iDur_Real[iCont] ;
                    pstDetLlamadasTemp->iDur_Dcto  = stDetLlamHost.iDur_Dcto[iCont] ;
                    pstDetLlamadasTemp->iCod_Carg  = stDetLlamHost.iCod_Carg[iCont] ;
                    pstDetLlamadasTemp->dImpLocal1 = stDetLlamHost.dImpLocal1[iCont];
                    pstDetLlamadasTemp->dImpLarga2 = stDetLlamHost.dImpLarga2[iCont];
                    strcpy(pstDetLlamadasTemp->szCodFCob        , stDetLlamHost.szCodFCob[iCont]    );
                    pstDetLlamadasTemp->dValorUndad= stDetLlamHost.dValorUndad[iCont];

                    stDetCelular.stAgrupacion[lPosicion].iCantLlamadas++;
                }
            }
            else
            {
                if ( ( strcmp (pstNumOrden.szCodRegistro, COD_LOCALES)          == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_INTERZONA)        == 0 && pst_Abonados->iIndInterzona[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_LDI)              == 0 && pst_Abonados->iIndLdi[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_ESPECIALES)       == 0 && pst_Abonados->iIndEspeciales[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_ESPECIALES_DATA)  == 0 && pst_Abonados->iIndEspeciales[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_TARIFA_ADICIONAL) == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_INTERCOMPANIA)    == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_MENSAJEPREMIMUN)  == 0 && pst_Abonados->iIndLocal[iIndice] ) ||
                     ( strcmp (pstNumOrden.szCodRegistro, COD_LOCALES)          == 0 && pst_Abonados->iIndLocal[iIndice] ) )
                {
                    /* No existe el grupo, por lo que hay q crearlo y agregar el registro de llamadas */
                    vDTrazasLog (szModulo,"\t(bfnDetLlamCelularTOL): No Existe grupo. Lo crea y agrega llamada \n", LOG04 );

                    stDetCelular.stAgrupacion = (DETCELULAR_AGRUP*) realloc(stDetCelular.stAgrupacion, sizeof(DETCELULAR_AGRUP) * (stDetCelular.iCantEstructuras + 1) );
                    stDetCelularTemp = &(stDetCelular.stAgrupacion)[(stDetCelular.iCantEstructuras)];
                    memset(stDetCelularTemp, 0, sizeof(DETCELULAR_AGRUP));

                    stDetCelular.iCantEstructuras++;

                    stDetCelularTemp->iNum_OrdenGr      = pstNumOrden.iNum_OrdenGr  ;
                    stDetCelularTemp->iNum_OrdenSubGr   = pstNumOrden.iNum_OrdenSubGr;
                    stDetCelularTemp->iCodGrupo         = pstNumOrden.iCodGrupo     ;
                    stDetCelularTemp->iCodSubGrupo      = pstNumOrden.iCodSubGrupo  ;
                    stDetCelularTemp->iCriterio         = pstNumOrden.iCodCriterio  ;
                    stDetCelularTemp->iTipo_Llamada     = pstNumOrden.iTipo_Llamada ;
                    strcpy (stDetCelularTemp->szCodRegistro , pstNumOrden.szCodRegistro);
                    stDetCelularTemp->iCantLlamadas     = 1;

                    stDetCelularTemp->stDetLlamadas = (DETLLAMADAS *)malloc (sizeof(DETLLAMADAS));

                    if(stDetCelularTemp->stDetLlamadas == NULL)
                    {
                        vDTrazasLog (szModulo,"\n\nERROR(%s): En asignacion de memoria a stDetCelularTemp->stDetLlamadas.", LOG05,szModulo );
                        vDTrazasError (szModulo,"\n\nERROR(%s): En asignacion de memoria a stDetCelularTemp->stDetLlamadas.", LOG05,szModulo );
                        return (FALSE);
                    }

                    strcpy(stDetCelularTemp->stDetLlamadas->szSec_Empa        , stDetLlamHost.szSec_Empa[iCont]   );
                    strcpy(stDetCelularTemp->stDetLlamadas->szSec_Cdr         , stDetLlamHost.szSec_Cdr[iCont]  );
                    strcpy(stDetCelularTemp->stDetLlamadas->szFecIniTasa      , stDetLlamHost.szFecIniTasa[iCont]   );
                    strcpy(stDetCelularTemp->stDetLlamadas->szTieIniLlam      , stDetLlamHost.szTieIniLlam[iCont]   );
                    strcpy(stDetCelularTemp->stDetLlamadas->szNumMovil1       , stDetLlamHost.szNumMovil1[iCont]    );
                    strcpy(stDetCelularTemp->stDetLlamadas->szNumMovil2       , stDetLlamHost.szNumMovil2[iCont]    );
                    strcpy(stDetCelularTemp->stDetLlamadas->szCodFranHoraSoc  , stDetLlamHost.szCodFranHoraSoc[iCont]);
                    strcpy(stDetCelularTemp->stDetLlamadas->szCodAlm          , stDetLlamHost.szCodAlm[iCont]   );
                    strcpy(stDetCelularTemp->stDetLlamadas->szDesMovil2       , stDetLlamHost.szDesMovil2[iCont]    );
                    strcpy(stDetCelularTemp->stDetLlamadas->szDurLocal1       , stDetLlamHost.szDurLocal1[iCont]    );
                    strcpy(stDetCelularTemp->stDetLlamadas->szDurLarga2       , stDetLlamHost.szDurLarga2[iCont]    );
                    strcpy(stDetCelularTemp->stDetLlamadas->szIndEntSal1      , stDetLlamHost.szIndEntSal1[iCont]   );
                    stDetCelularTemp->stDetLlamadas->dMto_Real          = stDetLlamHost.dMto_Real[iCont]    ;
                    stDetCelularTemp->stDetLlamadas->dMto_Dcto          = stDetLlamHost.dMto_Dcto[iCont]    ;
                    stDetCelularTemp->stDetLlamadas->iDur_Real          = stDetLlamHost.iDur_Real[iCont]    ;
                    stDetCelularTemp->stDetLlamadas->iDur_Dcto          = stDetLlamHost.iDur_Dcto[iCont]    ;
                    stDetCelularTemp->stDetLlamadas->iCod_Carg          = stDetLlamHost.iCod_Carg[iCont]    ;
                    stDetCelularTemp->stDetLlamadas->dImpLocal1         = stDetLlamHost.dImpLocal1[iCont]   ;
                    stDetCelularTemp->stDetLlamadas->dImpLarga2         = stDetLlamHost.dImpLarga2[iCont]   ;

                    strcpy(stDetCelularTemp->stDetLlamadas->szCodFCob         , stDetLlamHost.szCodFCob[iCont]    );
                    stDetCelularTemp->stDetLlamadas->dValorUndad              = stDetLlamHost.dValorUndad[iCont];
                }
            }
        }
    }

    vDTrazasLog (szModulo,"\n\n(bfnDetLlamCelularTOL): Despues del While Principal", LOG04 );

    iOra=ifnOraCerrarTraficoTolTarifica();
    if (iOra != SQLOK)
    {
        vDTrazasLog (szModulo,"\n\nERROR(bfnDetLlamCelularTOL):\n\tError al cerrar el cursor", LOG05 );
        return (FALSE);
    }

    if (!bfnImprimeEstruc(&stDetCelular))
        vDTrazasLog (szModulo,"\nImpresion Con Error.", LOG05);

    if (!bfnOrdenaEstructuras(&stDetCelular))
        vDTrazasLog (szModulo,"\nOrdenamiento Con Error.", LOG05);

    if (!bfnImprimeEstruc(&stDetCelular))
        vDTrazasLog (szModulo,"\nImpresion Con Error.", LOG05);

    /* Recoriendo la estructura completa para llevarla al Punto DAT */
    for (i=0; i< stDetCelular.iCantEstructuras; i++)
    {
        for (j=0; j < stDetCelular.stAgrupacion[i].iCantLlamadas; j++)
        {
            if(!*bImprimioD1000)
            {
                put_D1000(pst_Abonados,fArchImp,iIndice,szBuffer);
                *bImprimioD1000 = TRUE;
            }

            if (!bImprimioD2000)
            {
                /* Escribe cabecera de tipo de registro      */
                sprintf(szBuffer_local ,"%5s%013d%05d\n"
                                       ,COD_TIPOLLAMADA
                                       ,stDetCelular.stAgrupacion[i].iTipo_Llamada
                                       ,atoi(pst_Cliente->szCod_Idioma));

                bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
                bImprimioD2000=TRUE;
            }

            /************************************************************************/
            /* Escribimos en buffer Validando Tamano del Buffer  o                  */
            /* Escribimos en Archivo y Limpiamos Buffer                             */
            /************************************************************************/

            iDurReal = stDetCelular.stAgrupacion[i].stDetLlamadas[j].iDur_Real;
            iDurDcto = stDetCelular.stAgrupacion[i].stDetLlamadas[j].iDur_Dcto;

            sprintf(szDurReal,"%7.7d",iDurReal);
            sprintf(szDurDcto,"%7.7d",iDurDcto);

            strcpy (szTipoRegistro, stDetCelular.stAgrupacion[i].szCodRegistro);

            dTotalLocal1Larga2=stDetCelular.stAgrupacion[i].stDetLlamadas[j].dImpLocal1 + stDetCelular.stAgrupacion[i].stDetLlamadas[j].dImpLarga2;

            if(BuscaMascara(pst_MascaraOper,szTipoRegistro,pst_Cliente->iCodTipDocum))
            {
                if ((strncmp(szTipoRegistro,COD_INTERCOMPANIA,_strlen(COD_INTERCOMPANIA))==0)||
                    (strncmp(szTipoRegistro,COD_MENSAJEPREMIMUN,_strlen(COD_MENSAJEPREMIMUN))==0))
                {
                    ihCodCargo = 0;
                }else{
                    ihCodCargo = stDetCelular.stAgrupacion[i].stDetLlamadas[j].iCod_Carg;
                }

                sprintf(szRegistro,"%-5s%-8.8s%-6s%-20s%-20s%015.4f%015.4f%-6s%-3s%-30s%-7s%-7s%-6s%015.4f%015.4f%-7s%-7s%04d%015.4f\n"
                                  ,szTipoRegistro
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szFecIniTasa
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szTieIniLlam
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szNumMovil1
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szNumMovil2
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].dImpLocal1
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].dImpLarga2
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szCodFranHoraSoc
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szCodAlm
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szDesMovil2
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szDurLocal1
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szDurLarga2
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].szIndEntSal1
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].dMto_Real
                                  ,stDetCelular.stAgrupacion[i].stDetLlamadas[j].dMto_Dcto
                                  ,szDurReal
                                  ,szDurDcto
                                  ,ihCodCargo
                                  ,dTotalLocal1Larga2);


                bEscribe= bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);

                if ( !bEscribe )
                    return (FALSE);
            }/* Buscamascara */
        }
    }

    if(bImprimioD2000)
    {
        sprintf(szBuffer_local,"%s\n",PIE_TIPOLLAMADA);
        bEscribe = bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
    }
    vFreeEstructuras(&stDetCelular);
    return (TRUE);
}/************************* FIN bfnDetLlamCelularTOL ***************************/


/****************************************************************************/
/* Funcion: BOOL bfnDetLlamCarrier                                          */
/* Imprime Detalle de Llamadas Carrier por Cliente, Abonado                 */
/****************************************************************************/
BOOL bfnDetLlamCarrier  ( ST_ABONADO *pst_Abonados
                        , ST_FACTCLIE *pst_Cliente
                        , int iIndice
                        , int iTipoLlamada
                        , FILE *fArchImp
                        , char *szBuffer
                        , int *bImprimioD1000
                        , char *szhCodRegistro
                        , char *szhBufferCursor)
{

    int             iSqlCodeDetCarrier;
    DETCARRIER      stDetCarrier;
    DETCARRIER      stDetCarrierAnt;
    BOOL            bEscribe = TRUE ;
    char            szRegistro[MAX_BYTES_REGISTRO+1];
    char            szBuffer_local[25 ]="";
    char            szMinutosTasados[7+1];
    int             bImprimioD2000 = FALSE;
/* SAAM-20050428 Nuevas Variables PAN-5001*/
    long            lhSegundosTotal;
    double          dhNetoTotal;
    BOOL            bPrimeraVez=TRUE;

    strcpy (szModulo, "bfnDetLlamCarrier");

    lhSegundosTotal = 0;
    dhNetoTotal = 0.0;

    vDTrazasLog("","\n\t Entrada a %s"
                   "\n\t\t==> Cod. Cliente     [%ld]"
                   "\n\t\t==> Ind. OrdenTotal  [%ld]"
                   "\n\t\t==> Num. Abonado     [%ld]"
                   "\n\t\t==> Num. Celular     [%ld]"
                   "\n\t\t==> Indice           [%d]"
                   "\n\t\t==> Cod. Registro    [%s]"
                   "\n\t\t==> szhBufferCursor  [%s]"
                   ,LOG04,szModulo
                   ,pst_Cliente->lCodCliente
                   ,pst_Cliente->lIndOrdenTotal
                   ,pst_Abonados->lNumAbonado[iIndice]
                   ,pst_Abonados->lNumCelular[iIndice]
                   ,iIndice
                   ,szhCodRegistro
                   ,szhBufferCursor);
    memset(szBuffer_local,0,sizeof(szBuffer_local));


    /* if ( ifnOpenRegistrosTipoD() ) MLA 123425
        return (FALSE); */

    /************************************************************************************/
    /*    Recupera Detalle de Llamadas Carrier                                          */
    /************************************************************************************/
    iSqlCodeDetCarrier = ifnOpenDetCarrier ( pst_Cliente->lCodCliente,
                                             pst_Abonados->lNumAbonado[iIndice],
                                             pst_Cliente->lNumProceso,
                                             szhBufferCursor);

    memset(&stDetCarrierAnt , 0, sizeof (DETCARRIER));

    while (iSqlCodeDetCarrier)
    {
        memset(&stDetCarrier    , 0, sizeof (DETCARRIER));

        iSqlCodeDetCarrier = ifnFetchDetCarrier(&stDetCarrier);

        if(iSqlCodeDetCarrier)
        {
            if(iSqlCodeDetCarrier & !*bImprimioD1000)
            {
              put_D1000(pst_Abonados,fArchImp,iIndice,szBuffer);
              *bImprimioD1000 = TRUE;
            }

            if (!bImprimioD2000)
            {
                /********************************************/
                /* Escribe cabecera de tipo de registro     */
                /********************************************/
                sprintf(szBuffer_local ,"%5s%013d%05d\n"
                                       ,COD_TIPOLLAMADA
                                       ,iTipoLlamada
                                       ,atoi(pst_Cliente->szCod_Idioma));

                bEscribe = bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);

                bImprimioD2000=TRUE;
            }

            sprintf(szMinutosTasados,"%7.7ld",stDetCarrier.lSegundos);

            /* SAAM-20050429 Se incluye lgica para poner un registro de totales*/
            if (((stDetCarrierAnt.iCodOperCarr != stDetCarrier.iCodOperCarr) || (strcmp(stDetCarrierAnt.szCodTrafico,stDetCarrier.szCodTrafico)!=0)) && !bPrimeraVez )
            {
                if (bfnObtieneTotalporTipoTrafico(pst_Cliente->lCodCliente
                                                 ,pst_Abonados->lNumAbonado[iIndice]
                                                 ,lCodCiclFactAux
                                                 ,stDetCarrierAnt.iCodOperCarr
                                                 ,stDetCarrierAnt.szCodTrafico
                                                 ,&lhSegundosTotal
                                                 ,&dhNetoTotal) != TRUE)
                {
                    vDTrazasLog(szModulo,"\n\t\t** bfnObtieneTotalporTipoTrafico"
                                "\n\t\t lCodCliente   [%ld]"
                                "\n\t\t lNumAbonado   [%ld]"
                                "\n\t\t lCodCiclFact  [%ld]"
                                "\n\t\t ihCodOperCarr [%ld]"
                                "\n\t\t szhCodTrafico [%s]"
                                "\n\t\t Sin valores Totalizados por portador y Tipo de Tr�fico"
                                "\n\t\t Se asumen valores cero (0)"
                                ,LOG04
                                ,pst_Cliente->lCodCliente
                                ,pst_Abonados->lNumAbonado[iIndice]
                                ,lCodCiclFactAux
                                ,stDetCarrierAnt.iCodOperCarr
                                ,stDetCarrierAnt.szCodTrafico);
                    lhSegundosTotal = 0;
                    dhNetoTotal = 0.0;
                }
                vDTrazasLog (szModulo, "\n\t\t Fuera de la funcion bfnObtieneTotalporTipoTrafico"
                                       "\n\t\t lhSegundosTotal    [%ld]"
                                       "\n\t\t dhNetoTotal        [%f]"
                                       , LOG05,lhSegundosTotal, dhNetoTotal);

                sprintf(szMinutosTasados,"%7.7ld",lhSegundosTotal);

                sprintf(szRegistro,"%5s%05d%30.30s%-3.3s%-8.8s%-6s%-20s%-20s%-7s%015.4f%015.4f\n"
                                  ,szhCodRegistro
                                  ,stDetCarrierAnt.iCodOperCarr
                                  ,szfnBuscaDescPortadora(stDetCarrierAnt.iCodOperCarr)
                                  ,szfnBuscaTipoTraficoLD(stDetCarrierAnt.szCodTrafico)
                                  ," "
                                  ," "
                                  ," "
                                  ," "
                                  ,szMinutosTasados
                                  ,dhNetoTotal
                                  ,dhNetoTotal);
                /* 20050509 */
                bEscribe=bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);
            }
            else /* 20050509: Si es la primera vez... */
            {
                bPrimeraVez = FALSE;
            }

            sprintf(szRegistro,"%5s%05d%30.30s%-3.3s%-8.8s%-6s%-20s%-20s%-7s%015.4f%015.4f\n"
                              ,szhCodRegistro
                              ,stDetCarrier.iCodOperCarr
                              ,szfnBuscaDescPortadora(stDetCarrier.iCodOperCarr)
                              ,szfnBuscaTipoTraficoLD(stDetCarrier.szCodTrafico)
                              ,stDetCarrier.szFecLlamada
                              ,stDetCarrier.szHraLlamada
                              ,stDetCarrier.szNumDestino
                              ,stDetCarrier.szDesDestino
                              ,szMinutosTasados
                              ,stDetCarrier.dNeto
                              ,stDetCarrier.dNeto);
                              /*,stDetCarrier.szTipTraf); MLA 123425*/

            /* 20050509: Copia el detalle actual para posteriores comparaciones */
            memcpy(&stDetCarrierAnt, &stDetCarrier,sizeof(DETCARRIER));

            bEscribe=bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);
        }
        else
        {
        /* 20050509: Si es el ultimo registro, se imprime el subtotal para este registro */
            if(sqlca.sqlerrd[2]!=0) /* Si se ha realizado procesamiento de algun registro*/
            {
                if (bfnObtieneTotalporTipoTrafico(pst_Cliente->lCodCliente
                                                 ,pst_Abonados->lNumAbonado[iIndice]
                                                 ,lCodCiclFactAux
                                                 ,stDetCarrierAnt.iCodOperCarr
                                                 ,stDetCarrierAnt.szCodTrafico
                                                 ,&lhSegundosTotal
                                                 ,&dhNetoTotal) != TRUE)
                {
                    vDTrazasLog(szModulo,"\n\t\t** bfnObtieneTotalporTipoTrafico"
                                         "\n\t\t lCodCliente   [%ld]"
                                         "\n\t\t lNumAbonado   [%ld]"
                                         "\n\t\t lCodCiclFact  [%ld]"
                                         "\n\t\t ihCodOperCarr [%ld]"
                                         "\n\t\t szhCodTrafico [%s]"
                                         "\n\t\t Sin valores Totalizados por portador y Tipo de Tr�fico"
                                         "\n\t\t Se asumen valores cero (0)"
                                         ,LOG04
                                         ,pst_Cliente->lCodCliente
                                         ,pst_Abonados->lNumAbonado[iIndice]
                                         ,lCodCiclFactAux
                                         ,stDetCarrierAnt.iCodOperCarr
                                         ,stDetCarrierAnt.szCodTrafico);
                    lhSegundosTotal = 0;
                    dhNetoTotal = 0.0;
                }
                vDTrazasLog (szModulo, "\n\t\t Fuera de la funcion bfnObtieneTotalporTipoTrafico"
                                       "\n\t\t lhSegundosTotal    [%ld]"
                                       "\n\t\t dhNetoTotal        [%f]" , LOG05,lhSegundosTotal, dhNetoTotal);

                sprintf(szMinutosTasados,"%7.7ld",lhSegundosTotal);

                sprintf(szRegistro,"%5s%05d%30.30s%-3.3s%-8.8s%-6s%-20s%-20s%-7s%015.4f%015.4f\n"
                                  ,szhCodRegistro
                                  ,stDetCarrierAnt.iCodOperCarr
                                  ,szfnBuscaDescPortadora(stDetCarrierAnt.iCodOperCarr)
                                  ,szfnBuscaTipoTraficoLD(stDetCarrierAnt.szCodTrafico)
                                  ," "
                                  ," "
                                  ," "
                                  ," "
                                  ,szMinutosTasados
                                  ,dhNetoTotal
                                  ,dhNetoTotal);

                bEscribe=bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);
            } /* if(sqlca.sqlerrd[2]!=0) */
        }
    }

    if(bImprimioD2000)
    {
        sprintf(szBuffer_local   ,"%s\n",PIE_TIPOLLAMADA);

        bEscribe = bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
    }

    if ((iSqlCodeDetCarrier != SQLOK) && (iSqlCodeDetCarrier != SQLNOTFOUND))    {
        vDTrazasLog(szModulo,"\n\t\t** Fetch"
                    "\n\t\t IndOrdenTotal  [%ld]"
                    "\n\t\t Error Oracle   [%s]"
                    ,LOG01, pst_Cliente->lIndOrdenTotal,SQLERRM);
        vDTrazasError(szModulo,"\n\t\t** Fetch"
                    "\n\t\t IndOrdenTotal  [%ld]"
                    "\n\t\t Error Oracle   [%s]"
                    ,LOG01, pst_Cliente->lIndOrdenTotal,SQLERRM);
        return (FALSE);
    }

    if (!bfnCloseDetCarrier())
        return FALSE;

    return (TRUE);
}/************************** FIN bfnDetLlamCarrier **************************/


/***************Modificacion *******************************************************/
/* Ahora se procesa un abonado a la vez , la invocacion de esta funcion se realiza */
/*  en   PutDetConsu ( Aviso de Pago)                                              */
/***********************************************************************************/
BOOL bfnTrataFactTrafico (ST_ABONADO *pst_Abonados
                         ,ST_FACTCLIE *pst_Cliente
                         ,FILE *fArchImp
                         , int iCont
                         , char *szBuffer
                         ,DETALLEOPER *pstMascaraOper
                         ,int iTasador
                         ,BOOL Flag_ExisCarrier)
{
    BOOL  bRes    = TRUE     ;
    BOOL  bPrimerAgrupado    = FALSE     ;
    BOOL  bImprime           = FALSE     ;
    char  szBuffer_local[100];
    char  szBuffer_Cursor[2048];
    char  szCodRegistro[6];
    int   iImpD1000 = FALSE;
    int   iIdxConfD = 0;
    int   iPosicionAux = -1;
    int   iCantValor = 0;

    strcpy (szModulo, "bfnTrataFactTrafico");
    vDTrazasLog(szModulo,"\n\t Entrada en %s "
                         "\n\t**(bfnTrataFactTrafico) IndOrdenTotal  [%ld]"
                         "\n\t**(bfnTrataFactTrafico) iCont <>-1?    [%d] "
                         ,LOG05,szModulo, pst_Cliente->lIndOrdenTotal, iCont);

    /*P-ECU-10012, se agrega iIndDetLlam */
    vDTrazasLog  (szModulo,"\t\tChequeo Indicadores  \n"
                     "\t\t iIndLocal       [%d]\n"
                     "\t\t iIndInterzona   [%d]\n"
                     "\t\t iIndLdi         [%d]\n"
                     "\t\t iIndRoaming     [%d]\n"
                     "\t\t iIndCarrier     [%d]\n"
                     "\t\t iIndEspeciales  [%d]\n"
                     "\t\t iIndLocalDestino[%d]\n"
                     "\t\t iIndDetLlam     [%d]\n" 
                     ,LOG04
                     ,pst_Abonados->iIndLocal[iCont]
                     ,pst_Abonados->iIndInterzona[iCont]
                     ,pst_Abonados->iIndLdi[iCont]
                     ,pst_Abonados->iIndRoaming[iCont]
                     ,pst_Abonados->iIndCarrier[iCont]
                     ,pst_Abonados->iIndEspeciales[iCont]
                     ,pst_Abonados->iIndLocalDestino[iCont]
                     ,pst_Abonados->iIndDetLlam[iCont]);

    if (iCont == -1) return bRes;

    for (iIdxConfD=0;iIdxConfD<pstConfTipRegD.iNumReg;iIdxConfD++)
    {
        strcpy(szCodRegistro,pstConfTipRegD.stRegTipD[iIdxConfD].szCodRegistro);

        if (iPosicionAux == pstConfTipRegD.stRegTipD[iIdxConfD].iPosicion || iPosicionAux == -1)
        {
            iPosicionAux = pstConfTipRegD.stRegTipD[iIdxConfD].iPosicion;

            if (iCantValor>0)
            {
                strcat(szBuffer_Cursor,"','");
            }else{
                memset(szBuffer_Cursor,0,sizeof(szBuffer_Cursor));
                strcpy(szBuffer_Cursor,"'");
            }

            strcat(szBuffer_Cursor,pstConfTipRegD.stRegTipD[iIdxConfD].szCodValor);

            if (iIdxConfD+1 == pstConfTipRegD.iNumReg)
            {
                strcat(szBuffer_Cursor,"'");
                bImprime = TRUE;
            }

            if (iIdxConfD+1 < pstConfTipRegD.iNumReg)
            {
                if (iPosicionAux != pstConfTipRegD.stRegTipD[iIdxConfD+1].iPosicion)
                {
                    strcat(szBuffer_Cursor,"'");
                    bImprime = TRUE;
                }
            }
            iCantValor++;
        }

        if (bImprime)
        {
            iCantValor = 0;
            iPosicionAux = -1;
            bImprime = FALSE;

				/*P-ECU-10012 SOLO SE DEBE IMPRIMIR LOS DETALLES DE LLAMADAS TOL Y CARRIER SI IND_DETALLE>0*/
				if ( pst_Abonados->iIndDetLlam[iCont] > 0 )
					{
            if (strcmp(pstConfTipRegD.stRegTipD[iIdxConfD].szCodTipLlam,"TOL")==0 && !bPrimerAgrupado)
            {
                if (pstMascaraOper->iInd_Agrupacion == 0) /* Sin agrupacion */
                {
                    vDTrazasLog(szModulo,"\t\t Sin Agrupacion\n", LOG05);
                    if (bRes  && (pst_Abonados->iIndLocal[iCont]      == iIND_IMPRIME_TRAFICO_SI ))
                    {
                        bRes = bfnDetLlamCelular(pst_Abonados,pst_Cliente, iCont, iTIPLLAMADAS_LOCALES,fArchImp,szBuffer,&iImpD1000,szCodRegistro,szBuffer_Cursor);
                    }
                }
                else /* Es Con Agrupacion*/
                {
                    vDTrazasLog(szModulo,"\t\t Con Agrupacion\n", LOG05);
                    bRes = bfnDetLlamCelularTOL(pst_Abonados,pst_Cliente, iCont,fArchImp,szBuffer,&iImpD1000,pstMascaraOper);
                    bPrimerAgrupado = TRUE;
                }
            }

            if (strcmp(pstConfTipRegD.stRegTipD[iIdxConfD].szCodTipLlam,"CAR")==0)
            {
                if (Flag_ExisCarrier && bRes  && (pst_Abonados->iIndCarrier[iCont]    == iIND_IMPRIME_TRAFICO_SI ))
                {
                    bRes = bfnDetLlamCarrier(pst_Abonados,pst_Cliente, iCont,iTIPLLAMADAS_CARRIER,fArchImp,szBuffer,&iImpD1000,szCodRegistro,szBuffer_Cursor);

                }
            }
					}
					
            if (strcmp(pstConfTipRegD.stRegTipD[iIdxConfD].szCodTipLlam,"ROA")==0)
            {
                if (bRes  && (pst_Abonados->iIndRoaming[iCont]    == iIND_IMPRIME_TRAFICO_SI ))
                {
                    bRes = bfnDetLlamRoaming(pst_Abonados,pst_Cliente, iCont,iTIPLLAMADAS_ROAMING,fArchImp,szBuffer,&iImpD1000,iTasador,szCodRegistro,szBuffer_Cursor);
                }
            }
        }/*Fin BImprime*/

    }/*End For*/

    if (iImpD1000)
    {
        sprintf(szBuffer_local,"%5s\n" ,PIE_ABONADO);
        bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
    }

    return (bRes);
} /***********************  FIN bfnTrataFactTrafico  *************************/


int put_D1000(ST_ABONADO *pst_Abonados,FILE *fArchImp, int iCont, char *szBuffer)
{
char  szBuffer_local[100];
      sprintf(szBuffer_local,"%-5s%08ld%-20ld%-20s%-20s%-20s\n"
                              ,COD_ABONADO
                              ,pst_Abonados->lNumAbonado[iCont]
                              ,pst_Abonados->lNumCelular[iCont]
                              ,pst_Abonados->sznom_usuario[iCont]
                              ,pst_Abonados->sznom_apellido1[iCont]
                              ,pst_Abonados->sznom_apellido2[iCont]);

      bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
      return (1);
}

/************************************************************************/
/*  Funcion: int ifnOpenDetCarrier(long , long)                         */
/*  Funcion que Abre el cursor de  TA_LLAMADASROA                       */
/************************************************************************/
int ifnOpenDetCarrier(long lCodCliente, long lNumAbonado,long lNumProceso, char *szhBufferCursor)
{

    char szQry       [4000];
    char szAndCodOperador       [2100];
    memset(szQry,0,sizeof(szQry));

    lhCodCliente = lCodCliente;
    lhNumAbonado = lNumAbonado;
    lhNumProceso = lNumProceso;
    ihTipConce   = iTIPO_CONCEPTO_CARRIER;
    strcpy (szhFormatoFecha,szformato_fecha);
    strcpy (szhFormatoHora,szformato_hora);

    strcpy (szModulo, "ifnOpenDetCarrier");
    vDTrazasLog(szModulo,"\n\t Entrada en %s "
                         "\n\t\t==> Cliente         [%ld]"
                         "\n\t\t==> Abonado         [%ld]"
                         "\n\t\t==> Num.Proceso     [%ld]"
                         "\n\t\t==> szformato_hora  [%s]"
                         "\n\t\t==> ihTipConce      [%d]"
                         "\n\t\t==> szhBufferCursor [%s]"
                         ,LOG04,szModulo,lCodCliente,lNumAbonado,lNumProceso, szformato_hora, ihTipConce,szhBufferCursor);

    if (strcmp(szhBufferCursor,"NULL")==0)
        strcpy(szAndCodOperador," ");
    else
        sprintf(szAndCodOperador,"\n AND A.COD_OPERADOR IN (%s) ",szhBufferCursor);

    sprintf(szQry, "\n SELECT  NVL(A.COD_OPERADOR,0) , "
                   "\n         TO_CHAR(A.FEC_CALL,:szhFormatoFecha), "
                   "\n         TO_CHAR(to_date(A.HORA_CALL,'HH24MISS'),:szformato_hora), "
                   "\n         A.IND_ENTRADA      , "
                   "\n         A.DES_ENTRADA      , "
                   "\n         A.MINUTOS_TASADO   , "
                   "\n         A.ACUM_NETOLLAM    , "
                   "\n         A.COD_TRAFICO "
                   "\n FROM    FA_DETFORTAS   A , "
                   "\n         FA_ACUMFORTAS  B  "
                   "\n WHERE  B.COD_CLIENTE   = :lhCodCliente "
                   "\n AND    B.NUM_ABONADO   = :lhNumAbonado "
                   "\n AND    B.NUM_PROCESO   = :lhNumProceso "
                   "\n AND    B.COD_TIPCONCE  = :ihTipConce "
                   "\n AND    A.COD_CLIENTE   = B.COD_CLIENTE "
                   "\n AND    A.NUM_ABONADO   = B.NUM_ABONADO "
                   "\n AND    A.COD_PERIODO   = B.COD_PERIODO "
                   "\n AND    A.COD_OPERADOR  = B.COD_OPERADOR "
                   "\n AND    A.IND_ALQUILER  = B.IND_ALQUILER "
                   "\n AND    A.IND_ALQUILER  = B.IND_ALQUILER "
                   "%s" /* Configuracion del registro D */
                   "\n ORDER BY A.COD_OPERADOR,A.COD_TRAFICO,A.FEC_CALL,A.HORA_CALL",szAndCodOperador);

    vDTrazasLog(szModulo,"\t\tQRY cDetCarrier:[ %s ]",LOG05,szQry);

    /* EXEC SQL PREPARE sql_Cur_Carrier FROM :szQry; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )203;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szQry;
    sqlstm.sqhstl[0] = (unsigned long )4000;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-PREPARE sql_Cur_Carrier **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_Cur_Carrier **"
                      "\t\tError : [%s] [%d]  [%s] ",LOG01,szQry,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    /* EXEC SQL DECLARE cDetCarrier CURSOR FOR sql_Cur_Carrier; */ 

    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE cDetCarrier **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE cDetCarrier **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    /* EXEC SQL 
    	OPEN cDetCarrier 
       USING :szhFormatoFecha
           , :szformato_hora
           , :lhCodCliente
           , :lhNumAbonado
           , :lhNumProceso
           , :ihTipConce; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )222;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhFormatoFecha;
    sqlstm.sqhstl[0] = (unsigned long )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szformato_hora;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhNumProceso;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihTipConce;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
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


           
    if (SQLCODE != SQLOK) {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN CURSOR cDetCarrier **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN CURSOR cDetCarrier **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }
    return TRUE;
}/*****************  Final de ifnOpenDetCarrier  ********************/

/************************************************************************/
/*  Funcion: int ifnFetchDetCarrier(char *)                             */
/*  Funcion que realiza FETCH sobre FA_DETFORTAS                        */
/************************************************************************/

int ifnFetchDetCarrier(DETCARRIER * stDetCarrier)
{
/* EXEC SQL BEGIN DECLARE SECTION ; */ 

    char    szhFecLlamada       [11];   /* EXEC SQL VAR szhFecLlamada      IS STRING(11); */ 

    char    szhHraLlamada       [7] ;   /* EXEC SQL VAR szhHraLlamada      IS STRING(7); */ 

    int     lhCodOperCarr           ;
    char    szhIndEntrada       [21];   /* EXEC SQL VAR szhIndEntrada      IS STRING(21); */ 

    char    szhDesEntrada       [21];   /* EXEC SQL VAR szhDesEntrada      IS STRING(21); */ 

    long    lhMinTasado             ;
    double  dhNeto                  ;
    char    szhCodTrafico        [3];   /* EXEC SQL VAR szhCodTrafico      IS STRING(3); */ 

    short i_hIndEntrada     ;
    short i_hDesEntrada     ;
    short i_hMinTasado      ;
    short i_hdNeto          ;
/* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "ifnFetchDetCarrier");
    vDTrazasLog(szModulo,"\n\t Entrada en %s ", LOG06,szModulo);

    /* EXEC SQL FETCH cDetCarrier INTO
                :lhCodOperCarr                  ,
                :szhFecLlamada                  ,
                :szhHraLlamada                  ,
                :szhIndEntrada   :i_hIndEntrada ,
                :szhDesEntrada   :i_hDesEntrada ,
                :lhMinTasado     :i_hMinTasado  ,
                :dhNeto          :i_hdNeto      ,
                :szhCodTrafico                  ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )261;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCodOperCarr;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhFecLlamada;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhHraLlamada;
    sqlstm.sqhstl[2] = (unsigned long )7;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhIndEntrada;
    sqlstm.sqhstl[3] = (unsigned long )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)&i_hIndEntrada;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhDesEntrada;
    sqlstm.sqhstl[4] = (unsigned long )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)&i_hDesEntrada;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&lhMinTasado;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)&i_hMinTasado;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&dhNeto;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)&i_hdNeto;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)szhCodTrafico;
    sqlstm.sqhstl[7] = (unsigned long )3;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
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

/* SAAM-20050425 nueva asignacin PAN-5001 */

    if(SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)  {
        vDTrazasLog (szModulo, "\n\t\t Error Oracle : %s - %s", LOG01,"Fetch=> cDetCarrier", SQLERRM );
        vDTrazasError(szModulo, "\n\t\t Error Oracle : %s - %s", LOG01,"Fetch=> cDetCarrier", SQLERRM );
        return FALSE;
    }

    if (SQLCODE == SQLOK)  {
        stDetCarrier->iCodOperCarr         = lhCodOperCarr       ;
        sprintf(stDetCarrier->szFecLlamada ,"%s\0",szhFecLlamada);
        sprintf(stDetCarrier->szHraLlamada ,"%s\0",szhHraLlamada);
        sprintf(stDetCarrier->szCodTrafico ,"%s\0",szhCodTrafico);

        if (i_hIndEntrada == ORA_NULL)
            memset(stDetCarrier->szNumDestino,0, sizeof(stDetCarrier->szNumDestino));
        else
            strcpy(stDetCarrier->szNumDestino,szhIndEntrada);

        if (i_hDesEntrada == ORA_NULL)
            memset(stDetCarrier->szDesDestino,0, sizeof(stDetCarrier->szDesDestino));
       else
           strcpy(stDetCarrier->szDesDestino,szhDesEntrada);

        if (i_hMinTasado == ORA_NULL )
            stDetCarrier->lSegundos= 0;
        else
            stDetCarrier->lSegundos = (long)(lhMinTasado*60);

        if (i_hdNeto == ORA_NULL )
            stDetCarrier->dNeto = 0;
        else
            stDetCarrier->dNeto = dhNeto;
    }
    else
        return FALSE;

    return TRUE;
}/****************  Final de ifnFetchDetCarrier    ******************/


/************************************************************************/
/*  Funcion: int bfnCloseDetCarrier(void)                               */
/*  Funcion que cierra el cursor sobre FA_DETFORTAS                     */
/************************************************************************/
BOOL bfnCloseDetCarrier(void)
{
    strcpy (szModulo, "bfnCloseDetCarrier");
    vDTrazasLog(szModulo,"\n\t Entrada en %s ", LOG04,szModulo);

    /* EXEC SQL CLOSE cDetCarrier ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )308;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(SQLCODE != SQLOK) {
        vDTrazasLog(szModulo, "\n\n\t Error al cerrar el Cursor DetCarrier  : %s", LOG01, SQLERRM);
        vDTrazasError(szModulo, "\n\t\t Error Oracle : %s - %s", LOG01,"Fetch=> Fa_DetFortas", SQLERRM );
        return FALSE;
    }
    return TRUE;
}/***********************  bfnCloseDetCarrier   *********************/


/****************************************************************************/
/*  Funcion que carga tabla TA_CONCEPFACT UNION FA_FACTCARRIERS             */
/****************************************************************************/
BOOL bCargaConceptosTar(CONCEPTOS_TAR *pstConceptos)
{
    int i ;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int     ihCodConceptos[MAX_CONCEPTOS_TAR];
        int     ihIndTabla    [MAX_CONCEPTOS_TAR];
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "bCargaConceptosTar");

    /* EXEC SQL DECLARE Cursor_Conceptos CURSOR FOR
        SELECT COD_FACTURACION,IND_TABLA
          FROM TA_CONCEPFACT
        UNION
        SELECT COD_CONCFACT, 4
          FROM FA_FACTCARRIERS; */ 


    /* EXEC SQL OPEN Cursor_Conceptos; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0004;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )323;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    /* EXEC SQL FETCH Cursor_Conceptos INTO :ihCodConceptos,:ihIndTabla; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )100;
    sqlstm.offset = (unsigned int  )338;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)ihCodConceptos;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)ihIndTabla;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )sizeof(int);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
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



    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-FETCH Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-FETCH Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }


    pstConceptos->iNumConceptos = sqlca.sqlerrd[2];

    for(i=0;i < pstConceptos->iNumConceptos;i++)
    {
        pstConceptos->iCodConcepto[i] = ihCodConceptos[i];
        pstConceptos->iIndTabla   [i] = ihIndTabla    [i];

    }

    /* EXEC SQL CLOSE Cursor_Conceptos; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )361;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-CLOSE Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-CLOSE Cursor_Conceptos **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    return TRUE;

}


int  ifnOraLeerTolTarifica (DETLLAMADAS_HOSTS  *pstLlamadasHost, int * piNumFilas)
{
    /* EXEC SQL FETCH Cur_TolTarifica
        INTO
        :pstLlamadasHost->szSec_Empa        ,
        :pstLlamadasHost->szSec_Cdr         ,
        :pstLlamadasHost->szFecIniTasa      ,
        :pstLlamadasHost->szTieIniLlam      ,
        :pstLlamadasHost->szNumMovil1       ,
        :pstLlamadasHost->szNumMovil2       ,
        :pstLlamadasHost->dImpLocal1        ,
        :pstLlamadasHost->dImpLarga2        ,
        :pstLlamadasHost->szCodFranHoraSoc  ,
        :pstLlamadasHost->szCodAlm          ,
        :pstLlamadasHost->szDesMovil2       ,
        :pstLlamadasHost->szDurLocal1       ,
        :pstLlamadasHost->szDurLarga2       ,
        :pstLlamadasHost->szIndEntSal1      ,
        :pstLlamadasHost->dMto_Real         ,
        :pstLlamadasHost->dMto_Dcto         ,
        :pstLlamadasHost->iDur_Real         ,
        :pstLlamadasHost->iDur_Dcto         ,
        :pstLlamadasHost->iCod_Carg         ,
        :pstLlamadasHost->szCodFCob         ,
        :pstLlamadasHost->dValorUndad; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )376;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstLlamadasHost->szSec_Empa);
    sqlstm.sqhstl[0] = (unsigned long )30;
    sqlstm.sqhsts[0] = (         int  )30;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstLlamadasHost->szSec_Cdr);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstLlamadasHost->szFecIniTasa);
    sqlstm.sqhstl[2] = (unsigned long )16;
    sqlstm.sqhsts[2] = (         int  )16;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstLlamadasHost->szTieIniLlam);
    sqlstm.sqhstl[3] = (unsigned long )7;
    sqlstm.sqhsts[3] = (         int  )7;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstLlamadasHost->szNumMovil1);
    sqlstm.sqhstl[4] = (unsigned long )20;
    sqlstm.sqhsts[4] = (         int  )20;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstLlamadasHost->szNumMovil2);
    sqlstm.sqhstl[5] = (unsigned long )20;
    sqlstm.sqhsts[5] = (         int  )20;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstLlamadasHost->dImpLocal1);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )sizeof(double);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstLlamadasHost->dImpLarga2);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )sizeof(double);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstLlamadasHost->szCodFranHoraSoc);
    sqlstm.sqhstl[8] = (unsigned long )6;
    sqlstm.sqhsts[8] = (         int  )6;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstLlamadasHost->szCodAlm);
    sqlstm.sqhstl[9] = (unsigned long )4;
    sqlstm.sqhsts[9] = (         int  )4;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(pstLlamadasHost->szDesMovil2);
    sqlstm.sqhstl[10] = (unsigned long )31;
    sqlstm.sqhsts[10] = (         int  )31;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(pstLlamadasHost->szDurLocal1);
    sqlstm.sqhstl[11] = (unsigned long )7;
    sqlstm.sqhsts[11] = (         int  )7;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)(pstLlamadasHost->szDurLarga2);
    sqlstm.sqhstl[12] = (unsigned long )7;
    sqlstm.sqhsts[12] = (         int  )7;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)(pstLlamadasHost->szIndEntSal1);
    sqlstm.sqhstl[13] = (unsigned long )6;
    sqlstm.sqhsts[13] = (         int  )6;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)(pstLlamadasHost->dMto_Real);
    sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[14] = (         int  )sizeof(double);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)(pstLlamadasHost->dMto_Dcto);
    sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )sizeof(double);
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqharc[15] = (unsigned long  *)0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)(pstLlamadasHost->iDur_Real);
    sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )sizeof(int);
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqharc[16] = (unsigned long  *)0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)(pstLlamadasHost->iDur_Dcto);
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )sizeof(int);
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqharc[17] = (unsigned long  *)0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)(pstLlamadasHost->iCod_Carg);
    sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )sizeof(int);
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqharc[18] = (unsigned long  *)0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)(pstLlamadasHost->szCodFCob);
    sqlstm.sqhstl[19] = (unsigned long )6;
    sqlstm.sqhsts[19] = (         int  )6;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqharc[19] = (unsigned long  *)0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)(pstLlamadasHost->dValorUndad);
    sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[20] = (         int  )sizeof(double);
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqharc[20] = (unsigned long  *)0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
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



    if (SQLCODE == SQLOK)
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if (SQLCODE == SQLNOTFOUND)
            *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;

    return sqlca.sqlcode;
}

/***********************************************************************************/
BOOL bfnDeterminaGrupo(int iCodCargoHost,  DETCELULAR * pstDetCelular, long *lPosicion, NUMORDEN *pstNumOrden)
{
    int j;

    if (BuscaNumOrden (iCodCargoHost,pstNumOrden ))
    {
        if (pstDetCelular->iCantEstructuras == 0)
        {
            *lPosicion = 0;
            return (FALSE);
        }

        for (j=0; j < pstDetCelular->iCantEstructuras; j++)
        {

            if (    (pstDetCelular->stAgrupacion[j].iNum_OrdenGr    == pstNumOrden->iNum_OrdenGr) &&
                    (pstDetCelular->stAgrupacion[j].iNum_OrdenSubGr == pstNumOrden->iNum_OrdenSubGr) &&
                    (pstDetCelular->stAgrupacion[j].iCodGrupo       == pstNumOrden->iCodGrupo      ) &&
                    (pstDetCelular->stAgrupacion[j].iCodSubGrupo    == pstNumOrden->iCodSubGrupo   ))
            {
                *lPosicion = j;
                return (TRUE);
            }
        }
        return (FALSE);
    }

    vDTrazasLog  ("bfnDeterminaGrupo","\n\t** Indica que no existe el Grupo/Subgrupo al que se hace referencia ** ", LOG01);
    return (FALSE);
}


int ifnOraCerrarTraficoTolTarifica ()
{
    /* EXEC SQL CLOSE Cur_TolTarifica; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )475;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    return sqlca.sqlcode;

}

BOOL bfnOrdenaEstructuras (DETCELULAR * pstDetCelular)
{
    int i;

    for(i=0; i < pstDetCelular->iCantEstructuras; i++)
    {
        vDTrazasLog  ("OrdenaEstructura","\t\t pstDetCelular->stAgrupacion[%i].iCriterio [%i]",LOG05, i, pstDetCelular->stAgrupacion[i].iCriterio);
        switch(pstDetCelular->stAgrupacion[i].iCriterio)
        {
            case 0: /*Criterio de ordenamieto por default: DATE_START_CHARG||TIME_START_CHARG */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareDefault);
                break;
            case 1: /*Criterio de Ordenamiento : Campo szSec_Empa   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszSec_Empa);
                break;
            case 2: /*Criterio de Ordenamiento : Campo szSec_Cdr    */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszSec_Cdr);
                break;
            case 3: /*Criterio de Ordenamiento : Campo szFecIniTasa */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareDefault);
                break;
            case 4: /*Criterio de Ordenamiento : Campo szTieIniLlam */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszTieIniLlam);
                break;
            case 5: /*Criterio de Ordenamiento : Campo szNumMovil1  */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszNumMovil1);
                break;
            case 6: /*Criterio de Ordenamiento : Campo szNumMovil2  */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszNumMovil2);
                break;
            case 7: /*Criterio de Ordenamiento : Campo dImpLocal1   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnComparedImpLocal1);
                break;
            case 8: /*Criterio de Ordenamiento : Campo dImpLarga2   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnComparedImpLarga2);
                break;
            case 9: /*Criterio de Ordenamiento : Campo szCodFranHoraSoc */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszCodFranHoraSoc);
                break;
            case 10: /*Criterio de Ordenamiento : Campo szCodAlm    */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszCodAlm);
                break;
            case 11: /*Criterio de Ordenamiento : Campo szDesMovil2 */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszDesMovil2);
                break;
            case 12: /*Criterio de Ordenamiento : Campo szDurLocal1 */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszDurLocal1);
                break;
            case 13: /*Criterio de Ordenamiento : Campo szDurLarga2 */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszDurLarga2);
                break;
            case 14: /*Criterio de Ordenamiento : Campo szIndEntSal1*/
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareszIndEntSal1);
                break;
            case 15: /*Criterio de Ordenamiento : Campo dMto_Real   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnComparedMto_Real);
                break;
            case 16: /*Criterio de Ordenamiento : Campo dMto_Dcto   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnComparedMto_Dcto);
                break;
            case 17: /*Criterio de Ordenamiento : Campo iDur_Real   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareiDur_Real);
                break;
            case 18: /*Criterio de Ordenamiento : Campo iDur_Dcto   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareiDur_Dcto);
                break;
            case 19: /*Criterio de Ordenamiento : Campo iCod_Carg   */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareiCod_Carg);
                break;
            default: /*Criterio de ordenamieto por default: DATE_START_CHARG||TIME_START_CHARG */
                qsort((void*)pstDetCelular->stAgrupacion[i].stDetLlamadas, (int)pstDetCelular->stAgrupacion[i].iCantLlamadas, sizeof(DETLLAMADAS),ifnCompareDefault);
                break;
        }
    }

    /* Ordenamiento de estructura principal por grupo y subgrupo */

    qsort((void*)pstDetCelular->stAgrupacion, pstDetCelular->iCantEstructuras, sizeof(DETCELULAR_AGRUP), ifnCompareGrupoSubGrupo);
    vDTrazasLog (szExeName,"\nOrdenamiento Estruc. principal por Grupo. OK", LOG05);

    return (TRUE);
}


/* int ifnCompareTolTarifica (const void* cad1, const void* cad2) */

int ifnCompareszSec_Empa (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szSec_Empa, ((DETLLAMADAS *)cad2)->szSec_Empa) )  != 0 )?rc:0;
}
int ifnCompareszSec_Cdr (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szSec_Cdr, ((DETLLAMADAS *)cad2)->szSec_Cdr) )  != 0 )?rc:0;
}
int ifnCompareszTieIniLlam (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szTieIniLlam, ((DETLLAMADAS *)cad2)->szTieIniLlam) )  != 0 )?rc:0;
}
int ifnCompareszNumMovil1 (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szNumMovil1, ((DETLLAMADAS *)cad2)->szNumMovil1) )  != 0 )?rc:0;
}
int ifnCompareszNumMovil2 (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szNumMovil2, ((DETLLAMADAS *)cad2)->szNumMovil2) )  != 0 )?rc:0;
}
int ifnComparedImpLocal1 (const void* cad1, const void* cad2)
{
    return (int)( ((DETLLAMADAS  *)cad1)->dImpLocal1 - ((DETLLAMADAS  *)cad2)->dImpLocal1 );
}
int ifnComparedImpLarga2 (const void* cad1, const void* cad2)
{
    return (int)( ((DETLLAMADAS  *)cad1)->dImpLarga2 - ((DETLLAMADAS  *)cad2)->dImpLarga2 );
}
int ifnCompareszCodFranHoraSoc(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szCodFranHoraSoc, ((DETLLAMADAS *)cad2)->szCodFranHoraSoc) )  != 0 )?rc:0;
}


int ifnCompareszCodAlm(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szCodAlm, ((DETLLAMADAS *)cad2)->szCodAlm) )  != 0 )?rc:0;
}


int ifnCompareszDesMovil2(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szDesMovil2, ((DETLLAMADAS *)cad2)->szDesMovil2) )  != 0 )?rc:0;
}


int ifnCompareszDurLocal1(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szDurLocal1, ((DETLLAMADAS *)cad2)->szDurLocal1) )  != 0 )?rc:0;
}


int ifnCompareszDurLarga2(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szDurLarga2, ((DETLLAMADAS *)cad2)->szDurLarga2) )  != 0 )?rc:0;
}


int ifnCompareszIndEntSal1(const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szIndEntSal1, ((DETLLAMADAS *)cad2)->szIndEntSal1) )  != 0 )?rc:0;
}


int ifnComparedMto_Real(const void* cad1, const void* cad2)
{
    return (int)( ((DETLLAMADAS  *)cad1)->dMto_Real - ((DETLLAMADAS  *)cad2)->dMto_Real );
}


int ifnComparedMto_Dcto(const void* cad1, const void* cad2)
{
    return (int)( ((DETLLAMADAS  *)cad1)->dMto_Dcto - ((DETLLAMADAS  *)cad2)->dMto_Dcto );
}


int ifnCompareiDur_Real(const void* cad1, const void* cad2)
{
    return ( ((DETLLAMADAS  *)cad1)->iDur_Real - ((DETLLAMADAS  *)cad2)->iDur_Real );
}


int ifnCompareiDur_Dcto(const void* cad1, const void* cad2)
{
    return ( ((DETLLAMADAS  *)cad1)->iDur_Dcto - ((DETLLAMADAS  *)cad2)->iDur_Dcto );
}


int ifnCompareiCod_Carg(const void* cad1, const void* cad2)
{
    return ( ((DETLLAMADAS  *)cad1)->iCod_Carg - ((DETLLAMADAS  *)cad2)->iCod_Carg );
}


int ifnCompareDefault (const void* cad1, const void* cad2)
{
    int     rc = 0;
    return ( (rc = strcmp ( ((DETLLAMADAS *)cad1)->szFecIniTasa, ((DETLLAMADAS *)cad2)->szFecIniTasa) )  != 0 )?rc:0;
}


int ifnCompareGrupoSubGrupo(const void* cad1, const void* cad2)
{
    int     rc = 0;

    return  ((rc =  ((DETCELULAR_AGRUP *)cad1)->iCodGrupo -
                ((DETCELULAR_AGRUP *)cad2)->iCodGrupo) != 0)?rc:
        ((rc =  ((DETCELULAR_AGRUP *)cad1)->iCodSubGrupo -
                ((DETCELULAR_AGRUP *)cad2)->iCodSubGrupo) != 0)?rc:0;
}


/***********************************************************************************/
BOOL bfnImprimeEstruc(DETCELULAR * pstDetCelular)
{
    int i, j;
    i = 0;
    j = 0;

    if (stStatus.LogNivel >= LOG06)
    {
        for(i=0; i < pstDetCelular->iCantEstructuras; i++)
        {
            vDTrazasLog (szExeName,"\n=================================================================="
                                   "\n\t pstDetCelular->stAgrupacion[%i].iCodGrupo      :[%i]"
                                   "\n\t pstDetCelular->stAgrupacion[%i].iCodSubGrupo   :[%i]"
                                   "\n\t pstDetCelular->stAgrupacion[%i].iNum_OrdenGr   :[%i]"
                                   "\n\t pstDetCelular->stAgrupacion[%i].iNum_OrdenSubGr:[%i]"
                                   "\n\t pstDetCelular->iCantEstructuras                :[%i]"
                                  , LOG06, i, pstDetCelular->stAgrupacion[i].iCodGrupo
                                  , i, pstDetCelular->stAgrupacion[i].iCodSubGrupo
                                  , i, pstDetCelular->stAgrupacion[i].iNum_OrdenGr
                                  , i, pstDetCelular->stAgrupacion[i].iNum_OrdenSubGr
                                  , pstDetCelular->iCantEstructuras);

            for(j=0; j < pstDetCelular->stAgrupacion[i].iCantLlamadas; j++)
            {
                vDTrazasLog (szExeName,"\n------------------------------------------------------------------", LOG06);
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szSec_Empa      : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szSec_Empa   );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szSec_Cdr       : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szSec_Cdr    );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szFecIniTasa    : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szFecIniTasa     );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szTieIniLlam    : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szTieIniLlam     );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szNumMovil1     : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szNumMovil1      );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szNumMovil2     : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szNumMovil2      );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].dImpLocal1      : [%f] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].dImpLocal1       );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].dImpLarga2      : [%f] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].dImpLarga2       );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szCodFranHoraSoc: [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szCodFranHoraSoc );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szCodAlm        : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szCodAlm         );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szDesMovil2     : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szDesMovil2      );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szDurLocal1     : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szDurLocal1      );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szDurLarga2     : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szDurLarga2      );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].szIndEntSal1    : [%s] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].szIndEntSal1     );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].dMto_Real       : [%f] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].dMto_Real        );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].dMto_Dcto       : [%f] ", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].dMto_Dcto        );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].iDur_Real       : [%ld]", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].iDur_Real        );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].iDur_Dcto       : [%ld]", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].iDur_Dcto        );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].stDetLlamadas[%i].iCod_Carg       : [%ld]", LOG06, i, j, pstDetCelular->stAgrupacion[i].stDetLlamadas[j].iCod_Carg        );
                vDTrazasLog (szExeName,"\n\t\t pstDetCelular->stAgrupacion[%i].iCantLlamadas                     : [%d] ", LOG06, i, pstDetCelular->stAgrupacion[i].iCantLlamadas);
            }
        }
    }
    return  (TRUE);
}


void vFreeEstructuras (DETCELULAR * pstDetCelular)
{

    if (pstDetCelular->stAgrupacion != (DETCELULAR_AGRUP *)NULL)
    {
        free (pstDetCelular->stAgrupacion);
        pstDetCelular->stAgrupacion = (DETCELULAR_AGRUP*)NULL;
    }
    memset (&pstDetCelular->stAgrupacion,0,sizeof(DETCELULAR_AGRUP));
}


void vFreeEstructurasTAS (DETCELULAR_AGRUP * pstDetLlamadasTAS)
{
    if (pstDetLlamadasTAS->stDetLlamadas != (DETLLAMADAS *)NULL)
    {
        free (pstDetLlamadasTAS->stDetLlamadas);
        pstDetLlamadasTAS->stDetLlamadas = (DETLLAMADAS*)NULL;
    }
}


BOOL  bfnDetLlamCelular ( ST_ABONADO *pst_Abonados
                       , ST_FACTCLIE *pst_Cliente
                       , int iIndice
                       , int iTipoLlamada
                       , FILE *fArchImp
                       , char *szBuffer
                       , int *bImprimioD1000
                       , char *szCodRegistro
                       , char *szBuffer_Cursor)
{
    int             iSqlCodeDetLocal  = 0;
    BOOL            bEscribe = TRUE;
    char            szRegistro[MAX_BYTES_REGISTRO+1];
    char            szBuffer_local[25];
    char            szDurReal[7+1];
    char            szDurDcto[7+1];
    int             iDurReal;
    int             iDurDcto;
    int             bImprimioD2000 = FALSE;
    double          dTotalLocal1Larga2;

    DETLLAMADAS *pstDetLlamadasTemp;
    static DETLLAMADAS_HOSTS stDetLlamHost;
    int iNumFilas = 0;
    int iCont;
    int i;

    strcpy (szModulo, "bfnDetLlamCelular");
    vDTrazasLog("","\n\tEntrada en %s"
                   "\n\t\t==> Num. Abonado    [%ld]"
                   "\n\t\t==> Num. Celular    [%ld]"
                   "\n\t\t==> Indice          [%d]"
                   "\n\t\t==> Tipo Trafico    [%d]"
                   "\n\t\t==> Cod. Registro   [%s]"
                   "\n\t\t==> szBuffer_Cursor [%s]"
                   ,LOG04,szModulo
                   ,pst_Abonados->lNumAbonado[iIndice]
                   ,pst_Abonados->lNumCelular[iIndice]
                   ,iIndice
                   ,iTipoLlamada
                   ,szCodRegistro
                   ,szBuffer_Cursor);

    /************************************************************************************/
    /*    Recupera Detalle de Llamadas Locales                                          */
    /************************************************************************************/

    iSqlCodeDetLocal = ifnOpenDetCelular  ( pst_Cliente->lCodCliente
    									  , pst_Abonados->lNumAbonado[iIndice]
    									  , iTipoLlamada
    									  , szBuffer_Cursor);

    if (iSqlCodeDetLocal != SQLOK)
    {
        vDTrazasLog (szExeName,"\n\nERROR(bfnDetLlamCelular):"
                               "\n\tError al declarar cursor en funcion ifnOpenDetCelular TAS ", LOG05 );
        return (FALSE);
    }

    memset(szBuffer_local,0,sizeof(szBuffer_local));

    /*********************************************/
    /* Escribe cabecera de registros D           */
    /*********************************************/
    while (iSqlCodeDetLocal != SQLNOTFOUND)
    {
        memset(&stDetLlamadasTAS.stDetLlamadas    , 0, sizeof (DETLLAMADAS));

        iSqlCodeDetLocal = ifnFetchDetCelular(&stDetLlamHost,&iNumFilas);

        vDTrazasLog (szExeName,"\n\niSqlCodeDetLocal[%d]\n", LOG05, iSqlCodeDetLocal);

        if (iSqlCodeDetLocal != SQLOK  && iSqlCodeDetLocal != SQLNOTFOUND)
        {
            vDTrazasLog (szExeName,"\n\nERROR(bfnDetLlamCelular):"
                                   "\n\tError al  realizar el FETCH sobre DETCELULAR   [%d]", LOG05 , iSqlCodeDetLocal);
            return (FALSE);
        }

        if (!iNumFilas)
            break;

        vDTrazasLog (szExeName,"\n\nbfnDetLlamCelular:Paso el Fetch iNumFilas   [%d]\n", LOG05, iNumFilas);

        for (iCont = 0 ; iCont < iNumFilas ; iCont++)
        {
            stDetLlamadasTAS.stDetLlamadas = (DETLLAMADAS*) realloc(stDetLlamadasTAS.stDetLlamadas, (int)(sizeof(DETLLAMADAS)* (stDetLlamadasTAS.iCantLlamadas + 1)));
            if (!stDetLlamadasTAS.stDetLlamadas)
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnDetLlamCelular", "no se pudo reservar memoria");
                return FALSE;
            }
            pstDetLlamadasTemp = &(stDetLlamadasTAS.stDetLlamadas)[(stDetLlamadasTAS.iCantLlamadas)];
            memset(pstDetLlamadasTemp, 0, sizeof(DETLLAMADAS));

            strcpy(pstDetLlamadasTemp->szSec_Empa       , stDetLlamHost.szSec_Empa[iCont]       );
            strcpy(pstDetLlamadasTemp->szSec_Cdr        , stDetLlamHost.szSec_Cdr[iCont]    );
            strcpy(pstDetLlamadasTemp->szFecIniTasa     , stDetLlamHost.szFecIniTasa[iCont] );
            strcpy(pstDetLlamadasTemp->szTieIniLlam     , stDetLlamHost.szTieIniLlam[iCont] );
            strcpy(pstDetLlamadasTemp->szNumMovil1      , stDetLlamHost.szNumMovil1[iCont]  );
            strcpy(pstDetLlamadasTemp->szNumMovil2      , stDetLlamHost.szNumMovil2[iCont]  );
            strcpy(pstDetLlamadasTemp->szCodFranHoraSoc , stDetLlamHost.szCodFranHoraSoc[iCont] );
            strcpy(pstDetLlamadasTemp->szCodAlm         , stDetLlamHost.szCodAlm[iCont]     );

            strcpy(pstDetLlamadasTemp->szDesMovil2      , stDetLlamHost.szDesMovil2[iCont]   );
            strcpy(pstDetLlamadasTemp->szDurLocal1      , stDetLlamHost.szDurLocal1[iCont]   );
            strcpy(pstDetLlamadasTemp->szDurLarga2      , stDetLlamHost.szDurLarga2[iCont]   );
            strcpy(pstDetLlamadasTemp->szIndEntSal1     , stDetLlamHost.szIndEntSal1[iCont]  );
            strcpy(pstDetLlamadasTemp->szCodFCob        , stDetLlamHost.szCodFCob[iCont]     );

            pstDetLlamadasTemp->dMto_Real  = stDetLlamHost.dMto_Real[iCont] ;
            pstDetLlamadasTemp->dMto_Dcto  = stDetLlamHost.dMto_Dcto[iCont] ;
            pstDetLlamadasTemp->iDur_Real  = stDetLlamHost.iDur_Real[iCont] ;
            pstDetLlamadasTemp->iDur_Dcto  = stDetLlamHost.iDur_Dcto[iCont] ;
            pstDetLlamadasTemp->iCod_Carg  = stDetLlamHost.iCod_Carg[iCont] ;
            pstDetLlamadasTemp->dImpLocal1 = stDetLlamHost.dImpLocal1[iCont];
            pstDetLlamadasTemp->dImpLarga2 = stDetLlamHost.dImpLarga2[iCont];
            pstDetLlamadasTemp->dValorUndad= stDetLlamHost.dValorUndad[iCont];

            stDetLlamadasTAS.iCantLlamadas++;
        }
    }


    for (i=0; i< stDetLlamadasTAS.iCantLlamadas; i++)
    {
        if(!*bImprimioD1000)
        {
            put_D1000(pst_Abonados,fArchImp,iIndice,szBuffer);
            *bImprimioD1000 = TRUE;
        }

        if (!bImprimioD2000)
        {
            /******************************** ************/
            /* Escribe cabecera de tipo de registro      */
            /*********************************************/
            sprintf(szBuffer_local ,"%-5s%013d%05d\n",COD_TIPOLLAMADA,iTipoLlamada,atoi(pst_Cliente->szCod_Idioma));
            bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
            bImprimioD2000=TRUE;
        }

        /************************************************************************/
        /* Escribimos en buffer Validando Tamano del Buffer  o                  */
        /* Escribimos en Archivo y Limpiamos Buffer                             */
        /************************************************************************/

        iDurReal = stDetLlamadasTAS.stDetLlamadas[i].iDur_Real;
        iDurDcto = stDetLlamadasTAS.stDetLlamadas[i].iDur_Dcto;

        sprintf(szDurReal,"%7.7d",iDurReal);
        sprintf(szDurDcto,"%7.7d",iDurDcto);

        dTotalLocal1Larga2=stDetLlamadasTAS.stDetLlamadas[i].dImpLocal1 + stDetLlamadasTAS.stDetLlamadas[i].dImpLarga2;

        sprintf(szRegistro,"%-5s%-8.8s%-6s%-20s%-20s%015.4f%015.4f%-6s%-3s%-30s%-7s%-7s%-6s%015.4f%015.4f%-7s%-7s%04d%015.4f\n"
                            ,szCodRegistro
                            ,stDetLlamadasTAS.stDetLlamadas[i].szFecIniTasa
                            ,stDetLlamadasTAS.stDetLlamadas[i].szTieIniLlam
                            ,stDetLlamadasTAS.stDetLlamadas[i].szNumMovil1
                            ,stDetLlamadasTAS.stDetLlamadas[i].szNumMovil2
                            ,stDetLlamadasTAS.stDetLlamadas[i].dImpLocal1
                            ,stDetLlamadasTAS.stDetLlamadas[i].dImpLarga2
                            ,stDetLlamadasTAS.stDetLlamadas[i].szCodFranHoraSoc
                            ,stDetLlamadasTAS.stDetLlamadas[i].szCodAlm
                            ,stDetLlamadasTAS.stDetLlamadas[i].szDesMovil2
                            ,stDetLlamadasTAS.stDetLlamadas[i].szDurLocal1
                            ,stDetLlamadasTAS.stDetLlamadas[i].szDurLarga2
                            ,stDetLlamadasTAS.stDetLlamadas[i].szIndEntSal1
                            ,stDetLlamadasTAS.stDetLlamadas[i].dMto_Real
                            ,stDetLlamadasTAS.stDetLlamadas[i].dMto_Dcto
                            ,szDurReal
                            ,szDurDcto
                            ,stDetLlamadasTAS.stDetLlamadas[i].iCod_Carg
                            ,dTotalLocal1Larga2);

        bEscribe= bEscribeEnArchivo(fArchImp,szBuffer,szRegistro);

        if ( !bEscribe )
            return FALSE;

    }

    if(bImprimioD2000)
    {
        sprintf(szBuffer_local,"%s\n",PIE_TIPOLLAMADA);
        bEscribe = bEscribeEnArchivo(fArchImp,szBuffer,szBuffer_local);
    }

    if (!bfnCloseDetCelular())
            return (FALSE);

    vFreeEstructurasTAS(&stDetLlamadasTAS);
    return (TRUE);
}/************************* FIN bfnDetLlamCelularTAS ***************************/


int ifnOpenDetCelular(long lCodCliente, long lNumAbonado, int iTipLlam, char *szBufferCursor)
{
	char *szModulo="ifnOpenDetCelular";
    
    char    szWhere      [513] ;
    char    szCadenaSQL  [4100];
    char    szAndCodLlam [2100];

    char gszSufTablasCiclo[15]; /* ej: 150109_123 ciclo_job */

    vDTrazasLog(szModulo, "\n\t\t**  Entrada en %s "
                          "\n\t\t==> Cliente      [%ld]"
                          "\n\t\t==> Abonado      [%ld]"
                          "\n\t\t==> Tipo Llamada [%d]"
                          ,LOG04,szModulo,lCodCliente,lNumAbonado,iTipLlam);
    /********************************************************************/
    /*  Analiza el Tipo de Llamada a Imprimir y determina condiciones   */
    /********************************************************************/

    strcpy(szhformato_fecha, szformato_fecha); 
    strcpy(szhformato_hora , szformato_hora ); 

    lhCodCliente= lCodCliente;
    lhNumAbonado= lNumAbonado;

    memset(szWhere,0,sizeof(szWhere));
    memset(szCadenaSQL,0,sizeof(szCadenaSQL));

    vDTrazasLog(szModulo, "\t\t** Asume Tasador TOL"
                          "\t\t**  WHERE: COD_LLAM - PF_TOLTARIFICA[%s]\n"
                          ,LOG04, szBufferCursor);

    if( lNroJob )
    {
        /* Modo JOB proforma */
        /* prepara sufijo para tablas ciclo+job */
        sprintf (gszSufTablasCiclo, "%ld_%ld", lCodCiclFactAux, lNroJob);
    }
    else
    {
        /*Modo Normal*/
        /* prepara sufijo para tablas ciclo */
        sprintf (gszSufTablasCiclo, "%ld", lCodCiclFactAux);
    }/* if (iEjecutaJob!=0) */
 
    if (strcmp(szBufferCursor,"NULL")==0)
        strcpy(szAndCodLlam," ");
    else
        sprintf(szAndCodLlam,"\n AND A.COD_LLAM IN (%s) ",szBufferCursor);
/*
    sprintf(szCadenaSQL, " SELECT SEC_EMPA,SEC_CDR, "
                         "\n    MAX(to_char(TO_DATE(DATE_START_CHARG||TIME_START_CHARG,'YYYYMMDDHH24MISS'),:szhformato_fecha)), "
                         "\n    MAX(to_char(to_date(TIME_START_CHARG,'HH24MISS'),:szhformato_hora)), "
                         "\n    MAX(A_SUSC_NUMBER), "
                         "\n    MAX(B_SUSC_NUMBER), "
                         "\n    SUM(decode(ind_billete,'01',MTO_FACT,0)), "
                         "\n    SUM(decode(ind_billete,'02',MTO_FACT,0)), "
                         "\n    MAX(COD_THOR), "
                         "\n    MAX(COD_ALMA), "
                         "\n    MAX(DES_DESTINO), "
                         "\n    MAX(decode(ind_billete,'01',TO_CHAR(DUR_FACT),'0')),  "
                         "\n    MAX(decode(ind_billete,'02',TO_CHAR(DUR_FACT),'0')),  "
                         "\n    MAX(COD_SENT), "
                         "\n    SUM(MTO_REAL), "
                         "\n    SUM(MTO_DCTO), "
                         "\n    SUM(DUR_REAL), "
                         "\n    SUM(DUR_DCTO), "
                         "\n    COD_CARG     , "
                         "\n    A.COD_FCOB   , "
                         "\n    decode ((DUR_FACT/C.SEG_INIC),0,0, MTO_FACT/(DUR_FACT/C.SEG_INIC)) "
                         "\n FROM PF_TOLTARIFICA_%s A, TOL_ESTCOBRO C "
                         "\n WHERE A.NUM_CLIE = :lhCodCliente "
                         "\n AND A.NUM_ABON = :lhNumAbonado "
                         "%s"
                         "\n  AND   EXISTS (SELECT 1 FROM GED_CODIGOS G "
                         "\n                  WHERE G.COD_MODULO  = 'FA' "
                         "\n                  AND   G.NOM_TABLA   = 'TABLA_LLAMADAS_TOL' "
                         "\n                  AND   G.NOM_COLUMNA = 'LLAMADAS_TOL' "
                         "\n                  AND   G.COD_VALOR   = A.COD_TCOR ) "
                         "\n AND A.COD_OPERA = C.COD_OPERADOR "
                         "\n AND A.COD_PLAN  = C.COD_PLAN "                         
                          --"\n AND A.COD_AGRL  = C.COD_AGRULLAM " -- PGG - 19-11-2010 - HOMOLOGACION DE LA SOLUCION DE LA INC. 146691 EN PRODUCCION ECUADOR 
                         "\n AND A.COD_TDIA  = C.COD_TDIA "
                         "\n AND A.COD_SUBFRANJA = C.COD_SFRAN  "
                         "\n AND TO_DATE(A.DATE_START_CHARG||A.TIME_START_CHARG,'YYYYMMDDHH24MISS') BETWEEN C.FEC_INI_VIG AND C.FEC_TER_VIG "
                         "\n GROUP BY SEC_EMPA,SEC_CDR,COD_CARG,A.COD_FCOB, "
                         "\n       decode ((DUR_FACT/C.SEG_INIC),0,0, MTO_FACT/(DUR_FACT/C.SEG_INIC)), "
                         "\n       A.COD_TDIR, A.COD_OPERA, A.COD_MARCA, A.IND_IMPRESION  "
                         "\n ORDER BY MAX(DATE_START_CHARG||TIME_START_CHARG) "
                         ,gszSufTablasCiclo, szAndCodLlam);
*/

/* PGG - 19-01-2011 - 161951 - Correccion de la query para evitar lo reportado en esta incidencia */
		sprintf(szCadenaSQL, " SELECT SEC_EMPA,SEC_CDR, "
						"\n    MAX(to_char(TO_DATE(DATE_START_CHARG||TIME_START_CHARG,'YYYYMMDDHH24MISS'),:szhformato_fecha)), "
						"\n    MAX(to_char(to_date(TIME_START_CHARG,'HH24MISS'),:szhformato_hora)), "
						"\n    MAX(A_SUSC_NUMBER), "
						"\n    MAX(B_SUSC_NUMBER), "
						"\n    SUM(decode(ind_billete,'01',MTO_FACT,0)), "
						"\n    SUM(decode(ind_billete,'02',MTO_FACT,0)), "
						"\n    MAX(COD_THOR), "
						"\n    MAX(COD_ALMA), "
						"\n    MAX(DES_DESTINO), "
						"\n    MAX(decode(ind_billete,'01',TO_CHAR(DUR_FACT),'0')), "
						"\n    MAX(decode(ind_billete,'02',TO_CHAR(DUR_FACT),'0')), "
						"\n    MAX(COD_SENT), "
						"\n    SUM(MTO_REAL), "
						"\n    SUM(MTO_DCTO), "
						"\n    SUM(DUR_REAL), "
						"\n    SUM(DUR_DCTO), "
						"\n    COD_CARG     , "
						"\n    A.COD_FCOB   , "
						"\n    DECODE (DUR_FACT,0,0, MTO_FACT/DUR_FACT) "
						"\n FROM PF_TOLTARIFICA_%s A "
						"\n WHERE A.NUM_CLIE = :lhCodCliente "
						"\n AND A.NUM_ABON = :lhNumAbonado "
						"%s"
						"\n AND EXISTS (SELECT 1 FROM GED_CODIGOS G "
						"\n    WHERE G.COD_MODULO  = 'FA' "
						"\n    AND   G.NOM_TABLA   = 'TABLA_LLAMADAS_TOL' "
						"\n    AND   G.NOM_COLUMNA = 'LLAMADAS_TOL' "
						"\n    AND   G.COD_VALOR   = A.COD_TCOR ) "
						"\n AND EXISTS (SELECT 1 FROM TOL_ESTCOBRO C "
						"\n    WHERE C.COD_OPERADOR = A.COD_OPERA "
						"\n    AND C.COD_PLAN = A.COD_PLAN "
						"\n    AND C.COD_TDIA = A.COD_TDIA "
						"\n    AND C.COD_SFRAN = A.COD_SUBFRANJA "
						"\n    AND TO_DATE(A.DATE_START_CHARG||A.TIME_START_CHARG,'YYYYMMDDHH24MISS') BETWEEN C.FEC_INI_VIG AND C.FEC_TER_VIG) "
						"\n GROUP BY SEC_EMPA,SEC_CDR,COD_CARG,A.COD_FCOB, "
						"\n    DECODE(DUR_FACT,0,0, MTO_FACT/DUR_FACT), "
						"\n    A.COD_TDIR, A.COD_OPERA, A.COD_MARCA, A.IND_IMPRESION  "
						"\n ORDER BY MAX(DATE_START_CHARG||TIME_START_CHARG) "
						,gszSufTablasCiclo, szAndCodLlam);

        vDTrazasLog(szModulo,"\tifnDeclareDetCelularJob **"
                             "\t\t%s\n**********************************",LOG06,szCadenaSQL);

        /* EXEC SQL PREPARE QueryTolDetTarifica FROM :szCadenaSQL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 21;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )490;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
        sqlstm.sqhstl[0] = (unsigned long )4100;
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


        if(SQLCODE != SQLOK)
        {
            vDTrazasLog(szModulo,"\t\tError en SQL-PREPARE ifnOpenDetCelular **"
                                    "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
            vDTrazasError(szModulo,"\t\tError en SQL-PREPARE ifnOpenDetCelular **"
                                    "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
            return  (SQLCODE);
        }
        /* EXEC SQL DECLARE Cur_DetTolTarifica CURSOR FOR QueryTolDetTarifica; */ 

        if(SQLCODE != SQLOK)
        {
            vDTrazasLog(szModulo,"\t\tError en SQL-DECLARE ifnOpenDetCelular **"
                                    "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            vDTrazasError(szModulo,"\t\tError en SQL-DECLARE ifnOpenDetCelular **"
                                    "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
            return  (SQLCODE);
        }

        /* EXEC SQL 
        	OPEN Cur_DetTolTarifica
           USING :szhformato_fecha
               , :szhformato_hora
               , :lhCodCliente
               , :lhNumAbonado; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 21;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )509;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhformato_fecha;
        sqlstm.sqhstl[0] = (unsigned long )22;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhformato_hora;
        sqlstm.sqhstl[1] = (unsigned long )9;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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



    if (SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN CURSOR Cur_DetTolTarifica **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN CURSOR Cur_DetTolTarifica **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    return (SQLCODE);
}/*****************  Final de ifnOpenDetCelular  ********************/


int ifnFetchDetCelular(DETLLAMADAS_HOSTS  *pstLlamadasTASHost, int * piNumFilas)
{
    strcpy (szModulo, "ifnFetchDetCelular");

    vDTrazasLog(szModulo,"\n\t** Entrada en %s", LOG04,szModulo);

    /* EXEC SQL FETCH Cur_DetTolTarifica INTO
        :pstLlamadasTASHost->szSec_Empa       ,
        :pstLlamadasTASHost->szSec_Cdr        ,
        :pstLlamadasTASHost->szFecIniTasa     ,
        :pstLlamadasTASHost->szTieIniLlam     ,
        :pstLlamadasTASHost->szNumMovil1      ,
        :pstLlamadasTASHost->szNumMovil2      ,
        :pstLlamadasTASHost->dImpLocal1       ,
        :pstLlamadasTASHost->dImpLarga2       ,
        :pstLlamadasTASHost->szCodFranHoraSoc ,
        :pstLlamadasTASHost->szCodAlm         ,
        :pstLlamadasTASHost->szDesMovil2      ,
        :pstLlamadasTASHost->szDurLocal1      ,
        :pstLlamadasTASHost->szDurLarga2      ,
        :pstLlamadasTASHost->szIndEntSal1     ,
        :pstLlamadasTASHost->dMto_Real        ,
        :pstLlamadasTASHost->dMto_Dcto        ,
        :pstLlamadasTASHost->iDur_Real        ,
        :pstLlamadasTASHost->iDur_Dcto        ,
        :pstLlamadasTASHost->iCod_Carg        ,
        :pstLlamadasTASHost->szCodFCob        ,
        :pstLlamadasTASHost->dValorUndad      ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )540;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstLlamadasTASHost->szSec_Empa);
    sqlstm.sqhstl[0] = (unsigned long )30;
    sqlstm.sqhsts[0] = (         int  )30;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstLlamadasTASHost->szSec_Cdr);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstLlamadasTASHost->szFecIniTasa);
    sqlstm.sqhstl[2] = (unsigned long )16;
    sqlstm.sqhsts[2] = (         int  )16;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstLlamadasTASHost->szTieIniLlam);
    sqlstm.sqhstl[3] = (unsigned long )7;
    sqlstm.sqhsts[3] = (         int  )7;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstLlamadasTASHost->szNumMovil1);
    sqlstm.sqhstl[4] = (unsigned long )20;
    sqlstm.sqhsts[4] = (         int  )20;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstLlamadasTASHost->szNumMovil2);
    sqlstm.sqhstl[5] = (unsigned long )20;
    sqlstm.sqhsts[5] = (         int  )20;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstLlamadasTASHost->dImpLocal1);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )sizeof(double);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstLlamadasTASHost->dImpLarga2);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )sizeof(double);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstLlamadasTASHost->szCodFranHoraSoc);
    sqlstm.sqhstl[8] = (unsigned long )6;
    sqlstm.sqhsts[8] = (         int  )6;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstLlamadasTASHost->szCodAlm);
    sqlstm.sqhstl[9] = (unsigned long )4;
    sqlstm.sqhsts[9] = (         int  )4;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(pstLlamadasTASHost->szDesMovil2);
    sqlstm.sqhstl[10] = (unsigned long )31;
    sqlstm.sqhsts[10] = (         int  )31;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(pstLlamadasTASHost->szDurLocal1);
    sqlstm.sqhstl[11] = (unsigned long )7;
    sqlstm.sqhsts[11] = (         int  )7;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)(pstLlamadasTASHost->szDurLarga2);
    sqlstm.sqhstl[12] = (unsigned long )7;
    sqlstm.sqhsts[12] = (         int  )7;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)(pstLlamadasTASHost->szIndEntSal1);
    sqlstm.sqhstl[13] = (unsigned long )6;
    sqlstm.sqhsts[13] = (         int  )6;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)(pstLlamadasTASHost->dMto_Real);
    sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[14] = (         int  )sizeof(double);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)(pstLlamadasTASHost->dMto_Dcto);
    sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )sizeof(double);
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqharc[15] = (unsigned long  *)0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)(pstLlamadasTASHost->iDur_Real);
    sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )sizeof(int);
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqharc[16] = (unsigned long  *)0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)(pstLlamadasTASHost->iDur_Dcto);
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )sizeof(int);
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqharc[17] = (unsigned long  *)0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)(pstLlamadasTASHost->iCod_Carg);
    sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )sizeof(int);
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqharc[18] = (unsigned long  *)0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)(pstLlamadasTASHost->szCodFCob);
    sqlstm.sqhstl[19] = (unsigned long )6;
    sqlstm.sqhsts[19] = (         int  )6;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqharc[19] = (unsigned long  *)0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)(pstLlamadasTASHost->dValorUndad);
    sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[20] = (         int  )sizeof(double);
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqharc[20] = (unsigned long  *)0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
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



    vDTrazasLog  (szModulo,"\n\t** SQLCODE  : [%d] ",LOG05,SQLCODE);

    if (SQLCODE == SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t** Sale por if (SQLCODE == SQLOK) ",LOG05);
        *piNumFilas = TAM_HOSTS_PEQ;
    }
    else
    {
        if (SQLCODE == SQLNOTFOUND)
        {
            vDTrazasLog  (szModulo,"\n\t** Sale por if (SQLCODE == SQLNOTFOUND) ",LOG05);
            *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
        }
    }

    vDTrazasLog  (szModulo,"\n\t**  piNumFilas  : [%d] ",LOG05, *piNumFilas);

    return (SQLCODE);

}/********************  Final de ifnFetchDetCelular    ******************/


int bfnCloseDetCelular(void)
{
    strcpy (szModulo, "bfnCloseDetCelular");
    vDTrazasLog(szModulo,"\n\t** Entrada en %s", LOG04,szModulo);

    /* EXEC SQL CLOSE Cur_DetTolTarifica; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )639;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(SQLCODE != SQLOK)
    {
        vDTrazasLog(szModulo, "\n\t\t Error al cerrar el Cursor DetCelular : %s", LOG01, SQLERRM);
        vDTrazasError(szModulo, "ERROR EN CLOSE Cur_TolTarifica %s - %s", LOG01,"Close=>Fa_DetCelular", SQLERRM );
        return (FALSE);
    }

    return (TRUE);
}/*********************  bfnCloseDetCelular   ***********************/


/* Recupera Parametros de Tipo de LLamada Larga Distancia*/
BOOL bfnCargaTipoTraficoLD(void)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char szhCod_TipoTraficoLD [20];
        char szhNom_TipoTraficoLD [20];
        char szhDes_TipoTraficoLD [50];
        char szhNom_Parametro1    [14];
        char szhNom_Parametro2    [14];
    /* EXEC SQL END DECLARE SECTION; */ 


    int   iNumTipoTrafico;

    strcpy(szhNom_Parametro1,"LLAMADA_LD_03");
    strcpy(szhNom_Parametro2,"LLAMADA_LD_04");

    /* EXEC SQL DECLARE Cursor_TipoTrafico CURSOR FOR
    SELECT NOM_PARAMETRO,
           VAL_PARAMETRO,
           DES_PARAMETRO
      FROM GED_PARAMETROS
     WHERE NOM_PARAMETRO IN (:szhNom_Parametro2,:szhNom_Parametro1); */ 


    if (SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-DECLARE Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-DECLARE Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    /* EXEC SQL OPEN Cursor_TipoTrafico; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0006;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )654;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhNom_Parametro2;
    sqlstm.sqhstl[0] = (unsigned long )14;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhNom_Parametro1;
    sqlstm.sqhstl[1] = (unsigned long )14;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
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



    if (SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    iNumTipoTrafico = -1;
    for(;;)
    {
        /* EXEC SQL FETCH Cursor_TipoTrafico INTO :szhCod_TipoTraficoLD,
                                               :szhNom_TipoTraficoLD,
                                               :szhDes_TipoTraficoLD; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 21;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )677;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhCod_TipoTraficoLD;
        sqlstm.sqhstl[0] = (unsigned long )20;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhNom_TipoTraficoLD;
        sqlstm.sqhstl[1] = (unsigned long )20;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhDes_TipoTraficoLD;
        sqlstm.sqhstl[2] = (unsigned long )50;
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



        if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
        {
            vDTrazasLog  (szModulo,"\n\t**  Error en SQL-FETCH Cursor_TipoTrafico **"
                                   "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            vDTrazasError(szModulo,"\n\t**  Error en SQL-FETCH Cursor_TipoTrafico **"
                                   "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            return (FALSE);
        }
        if (SQLCODE == SQLNOTFOUND)
            break;

        if (iNumTipoTrafico == -1)
            iNumTipoTrafico = 0;

        strcpy(stTipoTrafico[iNumTipoTrafico].szCod_TipoTraficoLD,szhCod_TipoTraficoLD);
        strcpy(stTipoTrafico[iNumTipoTrafico].szNom_TipoTraficoLD,szhNom_TipoTraficoLD);
        strcpy(stTipoTrafico[iNumTipoTrafico].szDes_TipoTraficoLD,szhDes_TipoTraficoLD);
        iNumTipoTrafico++;
    }

    if (iNumTipoTrafico == -1)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-FETCH Cursor_Conceptos **"
                               "\n\t\t=> No existen los par�metros LLAMADA_LD_04 y LLAMADA_LD_03 en la tabla GED_PARAMETROS",LOG01);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-FETCH Cursor_Conceptos **"
                               "\n\t\t=> No existen los par�metros LLAMADA_LD_04 y LLAMADA_LD_03 en la tabla GED_PARAMETROS",LOG01);
        return (FALSE);
    }

    /* EXEC SQL CLOSE Cursor_TipoTrafico; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )704;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-CLOSE Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-CLOSE Cursor_TipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }
    return (TRUE);
}/*********************  bfnCargaTipoTraficoLD  ***********************/

/* SAAM-20050428 Busca Parametros de Tipo de LLamada Larga Distancia */
/* 20050509: Agregacion de alltrim() para comparacion de cadenas */
char *szfnBuscaTipoTraficoLD(char *s)
{
    int i;
    char  szhNom_TipoTraficoLD[20];
    char  szhCod_TipoTraficoLD[20];

    sprintf(szhCod_TipoTraficoLD,"LLAMADA_LD_%s",s);

    strcpy(szhNom_TipoTraficoLD,"NN");
    for(i=0;i<MAX_TIPOS_LD;i++)
    {
        if (strcmp(szhCod_TipoTraficoLD,alltrim(stTipoTrafico[i].szCod_TipoTraficoLD))==0)
        {
            szhNom_TipoTraficoLD[0] = '\0';
            strcpy(szhNom_TipoTraficoLD,alltrim(stTipoTrafico[i].szNom_TipoTraficoLD));
            break;
        }
    }
    /*s[0] = '\0'; */
    return(szhNom_TipoTraficoLD);
}/*********************  szfnBuscaTipoTraficoLD  ***********************/

BOOL bfnObtieneTotalporTipoTrafico(long   lCodCliente
                                  ,long   lNumAbonado
                                  ,long   lCodCiclFact
                                  ,int    iCodOperCarr
                                  ,char   *szCodTrafico
                                  ,long   *lSegundosTotal
                                  ,double *dNetoTotal)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long   lhCodCliente     ;
        long   lhNumAbonado     ;
        long   lhCodCiclFact    ;
        int    ihCodOperCarr    ;
        char   szhCodTrafico[20];
        long   lhSegundosTotal  ;
        double dhNetoTotal      ;
    /* EXEC SQL END DECLARE SECTION; */ 


    lhCodCliente = lCodCliente ;
    lhNumAbonado = lNumAbonado ;
    lhCodCiclFact = lCodCiclFact;
    ihCodOperCarr = iCodOperCarr;

    strcpy(szhCodTrafico,szCodTrafico);


    vDTrazasLog  (szModulo,"\n\t**  Parametros de bfnObtieneTotalporTipoTrafico\n"
                                   "lCodCliente         [%ld]\n"
                                   "lNumAbonado         [%ld]\n"
                                   "lCodCiclFact        [%ld]\n"
                                   "iCodOperCarr        [%d]\n"
                                   "szCodTrafico        [%s] \n"
                                   "szhCodTrafico       [%s] \n"
                                   "lSegundosTotal      [%ld]\n"
                                   "dNetoTotal          [%f] \n"
                                   ,LOG04
                                   ,lCodCliente
                                   ,lNumAbonado
                                   ,lCodCiclFact
                                   ,iCodOperCarr
                                   ,szCodTrafico
                                   ,szhCodTrafico
                                   ,lSegundosTotal
                                   ,dNetoTotal);

    /* EXEC SQL
    SELECT TOT_IMP_NETO, TOT_SEG_CONSUMIDO
    INTO
        :dhNetoTotal,
        :lhSegundosTotal
    FROM FA_SUBFORTAS_TO
    WHERE NUM_ABONADO  = :lhNumAbonado
      AND COD_PERIODO  = :lhCodCiclFact
      AND COD_OPERADOR = :ihCodOperCarr
      AND COD_TRAFICO  = :szhCodTrafico
      AND COD_CLIENTE  = :lhCodCliente; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TOT_IMP_NETO ,TOT_SEG_CONSUMIDO into :b0,:b1  from\
 FA_SUBFORTAS_TO where ((((NUM_ABONADO=:b2 and COD_PERIODO=:b3) and COD_OPERAD\
OR=:b4) and COD_TRAFICO=:b5) and COD_CLIENTE=:b6)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )719;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dhNetoTotal;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhSegundosTotal;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclFact;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&ihCodOperCarr;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhCodTrafico;
    sqlstm.sqhstl[5] = (unsigned long )20;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
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



    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en bfnObtieneTotalporTipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en bfnObtieneTotalporTipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        return (FALSE);
    }

    if (SQLCODE == SQLNOTFOUND)
    {
        vDTrazasLog  (szModulo,"\n\t**  Sin Informacion en bfnObtieneTotalporTipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Sin Informacion en bfnObtieneTotalporTipoTrafico **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        return (FALSE);
    }

    *lSegundosTotal = lhSegundosTotal;
    *dNetoTotal     = dhNetoTotal    ;

    return (TRUE);
}/*********************  bfnObtieneTotalporTipoTrafico  ***********************/

char *szfnBuscaDescPortadora(int iCodOperador)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int    ihCodOperador     ;
        char   szhDesOperador[31];
    /* EXEC SQL END DECLARE SECTION; */ 


    ihCodOperador = iCodOperador;

    /* EXEC SQL
    SELECT RTRIM(LTRIM(A.DES_OPERADOR))
    INTO
        :szhDesOperador
    FROM TA_OPERADORES A,
         GA_OPECARRIER B
    WHERE B.COD_OPERADOR = :ihCodOperador
      AND A.COD_OPERADOR = B.COD_OPERADOR; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select RTRIM(LTRIM(A.DES_OPERADOR)) into :b0  from TA_OPE\
RADORES A ,GA_OPECARRIER B where (B.COD_OPERADOR=:b1 and A.COD_OPERADOR=B.COD_\
OPERADOR)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )762;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhDesOperador;
    sqlstm.sqhstl[0] = (unsigned long )31;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodOperador;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
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



    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en szfnBuscaDescPortadora **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en szfnBuscaDescPortadora **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG04,SQLCODE,SQLERRM);
        return ("Portador Desconocido");
    }
    if (SQLCODE == SQLNOTFOUND)
        return ("Portador Sin Descripcin");

    return(szhDesOperador);
}/*********************  szfnBuscaDescPortadora  ***********************/


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

