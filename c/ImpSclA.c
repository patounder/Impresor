
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
    "./pc/ImpSclA.pc"
};


static unsigned int sqlctx = 1728643;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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

 static const char *sq0001 = 
"select NVL(NUM_MES,:b0) ,NVL(NUM_MINREBA,:b0) ,NVL(NUM_MINADIC,:b0) ,NVL(MTO\
_FACTCICLO,:b0)  from FAT_CONMESCLIE where ((COD_CLIENTE=:b4 and NUM_MES<=:b5)\
 and NUM_MES>=:b6) order by NUM_MES desc             ";

 static const char *sq0016 = 
"select COD_CONCEPTO ,COD_CONCEREL ,NUM_ABONADO  from FA_FACTCONC_NOCICLO whe\
re ((IND_ORDENTOTAL=:b0 and COD_CONCEREL=:b1) and COD_TIPCONCE=2) union select\
 COD_CONCEPTO ,COD_CONCEREL ,NUM_ABONADO  from FA_HISTCONC_19010102 where ((IN\
D_ORDENTOTAL=:b0 and COD_CONCEREL=:b1) and COD_TIPCONCE=2)           ";

 static const char *sq0004 = 
"select A.CORR_MENSAJE ,B.NUM_LINEA ,C.CANT_CARACTLIN ,LTRIM(RTRIM(NVL(B.COD_\
IDIOMA,'1')))  from FA_MENSCICLO A ,FA_MENSAJES B ,FA_PARMENSAJE C where (((((\
(A.COD_CLIENTE=:b0 and A.COD_FORMULARIO=:b1) and B.COD_IDIOMA=:b2) and A.IND_F\
ACTURADO=:b3) and B.CORR_MENSAJE=A.CORR_MENSAJE) and A.COD_FORMULARIO=C.COD_FO\
RMULARIO) and A.COD_BLOQUE=C.COD_BLOQUE) order by A.CORR_MENSAJE,A.COD_BLOQUE,\
B.NUM_LINEA            ";

 static const char *sq0003 = 
"select B.CORR_MENSAJE ,B.NUM_LINEA ,C.CANT_CARACTLIN ,SUBSTR(B.DESC_MENSLIN,\
:b0,132) ,B.COD_IDIOMA  from FA_PARMENSAJE C ,FA_MENSAJES B ,(select unique CO\
RR_MENSAJE ,COD_BLOQUE ,COD_FORMULARIO  from FA_MENSCICLO where (((((COD_FORMU\
LARIO=:b1 and IND_FACTURADO=:b2) and COD_CLIENTE>:b3) and COD_BLOQUE>:b3) and \
CORR_MENSAJE>:b3) and COD_ORIGEN is  not null )) A where ((A.CORR_MENSAJE=B.CO\
RR_MENSAJE and A.COD_FORMULARIO=C.COD_FORMULARIO) and A.COD_BLOQUE=C.COD_BLOQU\
E) order by B.CORR_MENSAJE,B.NUM_LINEA            ";

 static const char *sq0002 = 
"select NVL(A.NUM_FOLIOCTC,' ') ,TO_CHAR(A.FEC_EFECTIVIDAD,:b0) ,A.NUM_SECUEN\
CI ,A.COD_TIPDOCUM ,A.NUM_FOLIO ,UPPER(B.DES_TIPDOCUM) ,sum((NVL(A.IMPORTE_DEB\
E,:b1)-NVL(A.IMPORTE_HABER,:b1)))  from CO_CARTERA A ,GE_TIPDOCUMEN B where ((\
(((A.COD_CLIENTE=:b3 and A.FEC_ANTIGUEDAD<=TO_DATE(:b4,:b0)) and (A.NUM_CUOTA=\
:b1 or A.NUM_CUOTA is null )) and A.IND_FACTURADO=:b7) and B.COD_TIPDOCUM=A.CO\
D_TIPDOCUM) and  not exists (select :b7  from CO_CODIGOS F where ((F.NOM_TABLA\
=:b9 and F.NOM_COLUMNA=:b10) and F.COD_VALOR=A.COD_TIPDOCUM))) group by NVL(NU\
M_FOLIOCTC,' '),A.FEC_EFECTIVIDAD,A.COD_CLIENTE,A.NUM_SECUENCI,A.COD_TIPDOCUM,\
A.NUM_FOLIO,B.DES_TIPDOCUM           ";

 static const char *sq0031 = 
"select distinct COD_TIPDOCUM ,DES_TIPDOCUM  from GE_TIPDOCUMEN            ";

 static const char *sq0032 = 
"select distinct COD_OFICINA ,DES_OFICINA  from GE_OFICINAS where COD_OFICINA\
>' '           ";

 static const char *sq0033 = 
"select distinct COD_VENDEDOR ,NOM_VENDEDOR  from VE_VENDEDORES where COD_VEN\
DEDOR>0           ";

 static const char *sq0035 = 
"select LTRIM(RTRIM(A.COD_OPERADORA_SCL)) ,A.COD_CLIENTE ,B.NOM_CLIENTE ,NVL(\
B.NUM_IDENTTRIB,'AAA') ,GE_FN_OBTIENE_DIRCLIE(COD_OPERADORA_SCL,12,0,3)  from \
GE_OPERADORA_SCL A ,GE_CLIENTES B where (A.COD_CLIENTE=B.COD_CLIENTE and A.COD\
_CLIENTE is  not null )           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,2,0,0,
5,0,0,5,0,0,17,181,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,5,0,0,45,218,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
47,0,0,5,0,0,13,230,0,0,2,0,0,1,0,2,4,0,0,2,3,0,0,
70,0,0,5,0,0,15,252,0,0,0,0,0,1,0,
85,0,0,6,86,0,4,531,0,0,3,2,0,1,0,1,97,0,0,2,5,0,0,1,3,0,0,
112,0,0,7,360,0,4,661,0,0,13,6,0,1,0,1,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
179,0,0,8,388,0,4,693,0,0,13,6,0,1,0,1,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
246,0,0,9,244,0,4,878,0,0,4,3,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
277,0,0,10,276,0,4,912,0,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
300,0,0,11,155,0,4,1085,0,0,5,3,0,1,0,2,5,0,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
335,0,0,1,207,0,9,1311,0,0,7,7,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
378,0,0,1,0,0,13,1323,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
409,0,0,1,0,0,13,1388,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
440,0,0,1,0,0,15,1429,0,0,0,0,0,1,0,
455,0,0,12,410,0,4,2415,0,0,3,2,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,
482,0,0,13,146,0,4,2438,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
509,0,0,14,226,0,4,2454,0,0,4,2,0,1,0,2,3,0,0,2,3,0,0,1,3,0,0,1,3,0,0,
540,0,0,15,67,0,4,2474,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
563,0,0,16,301,0,9,2512,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
594,0,0,16,0,0,13,2519,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,
621,0,0,17,118,0,5,2535,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
652,0,0,18,0,0,29,2546,0,0,0,0,0,1,0,
667,0,0,16,0,0,15,2548,0,0,0,0,0,1,0,
682,0,0,19,0,0,17,2576,0,0,1,1,0,1,0,1,97,0,0,
701,0,0,19,0,0,45,2591,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
728,0,0,19,0,0,13,2599,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,
755,0,0,20,118,0,5,2617,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
786,0,0,21,0,0,29,2628,0,0,0,0,0,1,0,
801,0,0,19,0,0,15,2631,0,0,0,0,0,1,0,
816,0,0,22,145,0,4,2638,0,0,3,2,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,
843,0,0,23,104,0,4,3162,0,0,4,2,0,1,0,1,4,0,0,1,4,0,0,2,97,0,0,2,97,0,0,
874,0,0,24,42,0,4,3177,0,0,2,1,0,1,0,1,4,0,0,2,97,0,0,
897,0,0,4,411,0,9,4221,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
928,0,0,4,0,0,13,4231,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
959,0,0,4,0,0,15,4252,0,0,0,0,0,1,0,
974,0,0,25,0,0,17,4286,0,0,1,1,0,1,0,1,97,0,0,
993,0,0,25,0,0,21,4296,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
1016,0,0,26,63,0,5,4301,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
1039,0,0,3,516,0,9,4472,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
1078,0,0,3,0,0,13,4481,0,0,5,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
1113,0,0,3,0,0,15,4508,0,0,0,0,0,1,0,
1128,0,0,27,60,0,4,4533,0,0,2,1,0,1,0,1,3,0,0,2,9,0,0,
1151,0,0,28,61,0,4,4554,0,0,2,1,0,1,0,1,3,0,0,2,9,0,0,
1174,0,0,29,60,0,4,4564,0,0,2,1,0,1,0,1,3,0,0,2,9,0,0,
1197,0,0,30,61,0,4,4574,0,0,2,1,0,1,0,1,97,0,0,2,9,0,0,
1220,0,0,2,659,0,9,4634,0,0,11,11,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1279,0,0,2,0,0,13,4641,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
9,0,0,2,4,0,0,
1322,0,0,2,0,0,15,4691,0,0,0,0,0,1,0,
1337,0,0,31,74,0,9,4777,0,0,0,0,0,1,0,
1352,0,0,31,0,0,13,4789,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
1375,0,0,31,0,0,15,4808,0,0,0,0,0,1,0,
1390,0,0,32,91,0,9,4965,0,0,0,0,0,1,0,
1405,0,0,32,0,0,13,4977,0,0,2,0,0,1,0,2,97,0,0,2,97,0,0,
1428,0,0,32,0,0,15,5022,0,0,0,0,0,1,0,
1443,0,0,33,94,0,9,5106,0,0,0,0,0,1,0,
1458,0,0,33,0,0,13,5118,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
1481,0,0,33,0,0,15,5137,0,0,0,0,0,1,0,
1496,0,0,34,80,0,4,5195,0,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
1519,0,0,35,266,0,9,5329,0,0,0,0,0,1,0,
1534,0,0,35,0,0,13,5340,0,0,5,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
1569,0,0,35,0,0,15,5363,0,0,0,0,0,1,0,
};


/* Version  FAC_DES_MAS ImpSclA.pc  7.000 */
#include <ImpSclA.h>
#include <utils.h>

/*-----------------------------------------------------------------------------*/
/* PGG SOPORTE 3-04-2008 - 64059 - Se modifica llamadas a la funcion           */
/* fnCnvDouble eliminando el parametro 1 (USOFACT) por USO0 (0)                */
/* Antes    : fnCnvDouble(stBalance->dMonto[iCARGOS_MES],1)                    */
/* Despues  : fnCnvDouble(stBalance->dMonto[iCARGOS_MES],USO0)                 */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
/* PGG SOPORTE 4-09-2008 - MA 70199 - Se modifica llamadas a la funcion        */
/* fnCnvDouble Cambiando el parametro USO0 por USOFACT en algunos casos.       */
/*-----------------------------------------------------------------------------*/

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


/* EXEC SQL BEGIN DECLARE SECTION; */ 

    int     ihNumMes_Ciclo0Cur ;
    int     ihNumMes_Ciclo5Cur ;
    long    lhCodClienteCur;
    char    szhFec_EmisionCur[9];

    char    szhIndFacturadoCur[2];
    int     ihCodFormDetalleCur;

    char    szhCodIdiomaCur[6];
    char    szhIndFacturCur[2];
    int     ihAValorCero =0;
    int     ihAValorUno  =1;
    char    szhAFormatoFecha[9];
    char    szhATabla[11];
    char    szhAColumna[13];
/* EXEC SQL END DECLARE SECTION; */ 


extern char    sDescPlanTarif[100];
extern char    szPlan[4];

    /* EXEC SQL DECLARE Cursor_ConsumosMes CURSOR FOR
        SELECT NVL(NUM_MES,:ihAValorCero),
               NVL(NUM_MINREBA,:ihAValorCero),
               NVL(NUM_MINADIC,:ihAValorCero),
               NVL(MTO_FACTCICLO,:ihAValorCero)
          FROM FAT_CONMESCLIE
         WHERE COD_CLIENTE = :lhCodClienteCur
           AND NUM_MES    <= :ihNumMes_Ciclo0Cur
           AND NUM_MES    >= :ihNumMes_Ciclo5Cur
         ORDER BY NUM_MES DESC; */ 


    /* EXEC SQL DECLARE Cursor_SaldoAnte CURSOR FOR
        SELECT NVL(A.NUM_FOLIOCTC,' '),
               TO_CHAR(A.FEC_EFECTIVIDAD,:szhAFormatoFecha),
               A.NUM_SECUENCI,
               A.COD_TIPDOCUM,
               A.NUM_FOLIO,
               UPPER(B.DES_TIPDOCUM),
               SUM(NVL(A.IMPORTE_DEBE,:ihAValorCero)-NVL(A.IMPORTE_HABER, :ihAValorCero))
          FROM CO_CARTERA A ,
               GE_TIPDOCUMEN B
          WHERE A.COD_CLIENTE     = :lhCodClienteCur
            AND A.FEC_ANTIGUEDAD <= TO_DATE (:szhFec_EmisionCur ,:szhAFormatoFecha)
            AND (A.NUM_CUOTA= :ihAValorCero OR A.NUM_CUOTA IS NULL)
            AND A.IND_FACTURADO   = :ihAValorUno
            AND B.COD_TIPDOCUM    = A.COD_TIPDOCUM
            AND NOT EXISTS ( SELECT :ihAValorUno
                               FROM CO_CODIGOS F
                              WHERE F.NOM_TABLA   = :szhATabla
                                AND F.NOM_COLUMNA = :szhAColumna
                                AND F.COD_VALOR   = A.COD_TIPDOCUM)
          GROUP BY NVL(NUM_FOLIOCTC,' ') ,
                   A.FEC_EFECTIVIDAD,
                   A.COD_CLIENTE    ,
                   A.NUM_SECUENCI   ,
                   A.COD_TIPDOCUM   ,
                   A.NUM_FOLIO      ,
                   B.DES_TIPDOCUM   ; */ 


    /* EXEC SQL DECLARE Cursor_FaMensajesCiclo CURSOR FOR
         SELECT B.CORR_MENSAJE,
                B.NUM_LINEA,
                C.CANT_CARACTLIN,
                SUBSTR(B.DESC_MENSLIN,:ihAValorUno,132),
                B.COD_IDIOMA
           FROM FA_PARMENSAJE C ,
                FA_MENSAJES B ,
                (SELECT UNIQUE CORR_MENSAJE, COD_BLOQUE, COD_FORMULARIO
                   FROM FA_MENSCICLO
                  WHERE COD_FORMULARIO = :ihCodFormDetalleCur
                    AND IND_FACTURADO  = :szhIndFacturadoCur
                    AND COD_CLIENTE    > :ihAValorCero
                    AND COD_BLOQUE     > :ihAValorCero  
                    AND CORR_MENSAJE   > :ihAValorCero
                    AND COD_ORIGEN IS NOT NULL) A
          WHERE A.CORR_MENSAJE   = B.CORR_MENSAJE
            AND A.COD_FORMULARIO = C.COD_FORMULARIO
            AND A.COD_BLOQUE     = C.COD_BLOQUE
        ORDER BY B.CORR_MENSAJE, B.NUM_LINEA; */ 


    /* EXEC SQL DECLARE Cursor_Mensajes CURSOR FOR
        SELECT A.CORR_MENSAJE  ,
               B.NUM_LINEA ,
               C.CANT_CARACTLIN,	
               LTRIM(RTRIM(NVL(B.COD_IDIOMA,'1')))
          FROM FA_MENSCICLO    A,
               FA_MENSAJES     B,
               FA_PARMENSAJE   C
         WHERE A.COD_CLIENTE   = :lhCodClienteCur
           AND A.COD_FORMULARIO= :ihCodFormDetalleCur
           AND B.COD_IDIOMA    = :szhCodIdiomaCur
           AND A.IND_FACTURADO = :szhIndFacturCur
           AND B.CORR_MENSAJE  = A.CORR_MENSAJE
           AND A.COD_FORMULARIO= C.COD_FORMULARIO
           AND A.COD_BLOQUE    = C.COD_BLOQUE
        ORDER BY A.CORR_MENSAJE ,
                 A.COD_BLOQUE   ,
                 B.NUM_LINEA ; */ 



/****************************************************************************/
/* Funcion Put_A1100                                                        */
/*  Descripcion : Imprime registro A1100 (Balance Anterior) en el archivo   */
/*                descrito por Fd_ArchImp.                                  */
/*  Entrada     : Fd_ArchImp, lCod_Cliente                                  */
/*      Salida      : Fd_ArchImp modificado                                 */
/*  Predecesor  : PutCaratula                                               */
/****************************************************************************/
int Put_A1100   ( FILE *Fd_ArchImp
                  , ST_FACTCLIE *FactDocuClie
                  , STSALDO_ANTERIOR *SaldoTot
                  , ST_CUOTAS *pstFaCuotas
                  , char *zsBufferImpresionArchivo
                  , ST_BALANCE *stBalance )
{
    int     i;
    double  dTotalAPagar;
    double  dTotalCuotas;
    char    buffer_local[MAX_BYTE_A1100];
    int     TotalRegs;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

         double  dhMonto[7];         /* [CANTIDAD_CAMPO_FATBALANCE] */
         int     ihItem[7];
         long    lhCod_Cliente;
         char  szhSql[1000] = "";    /* P-ECU-07052 */
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(buffer_local,0,sizeof(buffer_local));
    dTotalCuotas = pstFaCuotas->dTotalCuotas_pven;
    memset(stBalance, 0, sizeof (ST_BALANCE));
    lhCod_Cliente = FactDocuClie->lCodCliente;

	if ( lCodCiclFactAux || bfnValidaCiclFactClie (lhCod_Cliente, &lCodCiclFactAux) )
	{
	    if ( !lNroJob )
	    {
	         sprintf(szhSql, "SELECT  SUM(IMP_DOCUMENTO), COD_ITEM \n "
	                         "  FROM  FAT_BALANCE_%ld \n "
	                         "  WHERE COD_ITEM BETWEEN 1 AND 5 \n "
	                         "    AND COD_CLIENTE  = :lhCod_Cliente \n"
	                         "    AND COD_CICLFACT = :lhCodCiclFact \n"
	                         "  GROUP BY COD_ITEM ",lCodCiclFactAux);
	    }
	    else
	    {
	         sprintf(szhSql, "SELECT  SUM(IMP_DOCUMENTO), COD_ITEM \n "
	                         "  FROM  FAT_BALANCE_%ld_%ld \n "
	                         "  WHERE COD_ITEM BETWEEN 1 AND 5 \n "
	                         "    AND COD_CLIENTE  = :lhCod_Cliente \n"
	                         "    AND COD_CICLFACT = :lhCodCiclFact \n"
	                         "  GROUP BY COD_ITEM ", lCodCiclFactAux,lNroJob );
	
	         vDTrazasLog("Put_A1100","\n\t Parametros para JOB "
	                                 "\n\t====================="
	                                 "\n\t Ciclo Fact. => [%ld]"
	                                 "\n\t Nro. JOB    => [%ld]"
	                                ,LOG05, lCodCiclFactAux, lNroJob);
	    }
	
	    vDTrazasLog("Put_A1100","\n\t QUERY FAT_BALANCE : [%s] ",LOG06, szhSql);
	
	    /* EXEC SQL PREPARE Sel_FatBalance FROM :szhSql; */ 

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
     sqlstm.sqhstl[0] = (unsigned long )1000;
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


	
	    if( abs(SQLCODE) == 942 ) /* table or view does not exist */
	    {   /* se generan montos en 0 */
	        vDTrazasLog  ("Put_A1100","\n\t**  No se encuentra tabla de balance para el ciclo [%ld] se asume 0 **"
	        						 ,LOG04,lCodCiclFactAux);
		    stBalance->dMonto[iCARGOS_MES]       = 0.0;
		    stBalance->dMonto[iAJUSTE_CREDITO]   = 0.0;
		    stBalance->dMonto[iBALANCE_ANTERIOR] = 0.0;
		    stBalance->dMonto[iPAGOS_RECIBIDOS]  = 0.0;
		    stBalance->dMonto[iPAGOS_REVERTIDOS] = 0.0;
		    stBalance->dMonto[iMISCELANEA]       = 0.0;
		    stBalance->dMonto[iTOTAL_FACTURA]    = 0.0;
		    stBalance->dMonto[iTOTAL_PAGAR]      = 0.0;
	    }
		else 
		{
		    if( SQLCODE != SQLOK )
		    {
		        vDTrazasLog  ("Put_A1100","\n\t**  Error en SQL-PREPARE CURSOR Sel_FatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        vDTrazasError("Put_A1100","\n\t**  Error en SQL-PREPARE CURSOR Sel_FatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        return(FALSE);
		    }
		
		    /* EXEC SQL DECLARE Cur_SelFatBalance CURSOR FOR Sel_FatBalance; */ 

		
		    if( SQLCODE != SQLOK )
		    {
		        vDTrazasLog  ("Put_A1100","\n\t**  Error en SQL-DECLARE CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        vDTrazasError("Put_A1100","\n\t**  Error en SQL-DECLARE CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        return(FALSE);
		    }
		
		    /* EXEC SQL OPEN Cur_SelFatBalance USING :lhCod_Cliente, :lCodCiclFactAux; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 2;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )24;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqcmod = (unsigned int )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhCod_Cliente;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lCodCiclFactAux;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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


		
		    if (SQLCODE !=  SQLOK)
		    {
		        vDTrazasLog  ("Put_A1100","\n\t**  Error en SQL-OPEN CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        vDTrazasError("Put_A1100","\n\t**  Error en SQL-OPEN CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        return  (FALSE);
		    }
		
		
		    /* EXEC SQL FETCH Cur_SelFatBalance
		             INTO  :dhMonto, :ihItem; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 2;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )7;
      sqlstm.offset = (unsigned int  )47;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (         int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (unsigned char  *)dhMonto;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )sizeof(double);
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqharc[0] = (unsigned long  *)0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)ihItem;
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


		
		    if ( sqlca.sqlcode < SQLOK && sqlca.sqlcode != SQLNOTFOUND )
		    {
		        vDTrazasLog  ("Put_A1100","\n\t**  Error en Ejecucin CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		        vDTrazasError("Put_A1100","\n\t**  Error en Ejecucin CURSOR Cur_SelFatBalance **"
		                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		         return(FALSE);
		    }
		
		    TotalRegs = sqlca.sqlerrd[2];
		
	        vDTrazasLog  ("Put_A1100","\n\t**  Cantidad de registos obtenidos [%ld] **", LOG06,TotalRegs);
	        
		    for ( i=0;i<TotalRegs;i++ )
		    {
		        stBalance->dMonto[ihItem[i]] = dhMonto[i];
	        	vDTrazasLog  ("Put_A1100","\n\t**  Item %d monto [%f] [%f]**", LOG06,ihItem[i], dhMonto[i], stBalance->dMonto[ihItem[i]]);
		    }
		
		    /* EXEC SQL CLOSE Cur_SelFatBalance; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 2;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )70;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		}
	}
	else  /* no existe balance para el cliente */
	{
	    stBalance->dMonto[iCARGOS_MES]       = 0.0;
	    stBalance->dMonto[iAJUSTE_CREDITO]   = 0.0;
	    stBalance->dMonto[iBALANCE_ANTERIOR] = 0.0;
	    stBalance->dMonto[iPAGOS_RECIBIDOS]  = 0.0;
	    stBalance->dMonto[iPAGOS_REVERTIDOS] = 0.0;
	    stBalance->dMonto[iMISCELANEA]       = 0.0;
	    stBalance->dMonto[iTOTAL_FACTURA]    = 0.0;
	    stBalance->dMonto[iTOTAL_PAGAR]      = 0.0;
	}
	
    /*ACTUALIZAcion DE TOTAL FACTURA :*/
    FactDocuClie->dTotFactura = FactDocuClie->dTotCargosMes + stBalance->dMonto[iAJUSTE_CREDITO];

    dTotalAPagar =  FactDocuClie->dTotCargosMes +
                    stBalance->dMonto[iAJUSTE_CREDITO] +
                    stBalance->dMonto[iBALANCE_ANTERIOR] +
                    stBalance->dMonto[iPAGOS_RECIBIDOS] +
                    stBalance->dMonto[iPAGOS_REVERTIDOS] +
                    stBalance->dMonto[iMISCELANEA] +
                    /*SaldoTot->dTotalSaldo + 1.1 ec-0027 22-04-2006*/
                    dTotalCuotas;

    stBalance->dMonto[iCARGOS_MES]=FactDocuClie->dTotCargosMes;
    stBalance->dMonto[iTOTAL_FACTURA]=FactDocuClie->dTotFactura;
    stBalance->dMonto[iTOTAL_PAGAR]=dTotalAPagar;

    stBalance->dMonto[iCARGOS_MES]       = stBalance->dMonto[iCARGOS_MES] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iAJUSTE_CREDITO]   = stBalance->dMonto[iAJUSTE_CREDITO] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iBALANCE_ANTERIOR] = stBalance->dMonto[iBALANCE_ANTERIOR] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iPAGOS_RECIBIDOS]  = stBalance->dMonto[iPAGOS_RECIBIDOS] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iPAGOS_REVERTIDOS] = stBalance->dMonto[iPAGOS_REVERTIDOS] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iMISCELANEA]       = stBalance->dMonto[iMISCELANEA] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iTOTAL_FACTURA]    = stBalance->dMonto[iTOTAL_FACTURA] / FactDocuClie->dImpConversion; /* P-TMM-03075  */
    stBalance->dMonto[iTOTAL_PAGAR]      = stBalance->dMonto[iTOTAL_PAGAR] / FactDocuClie->dImpConversion; /* P-TMM-03075  */

    if ( stStatus.LogNivel >= 6 )
	{
	    for ( i=iBALANCE_ANTERIOR;i<=iTOTAL_PAGAR;i++ )
	    {
	    	vDTrazasLog  ("Put_A1100","\n\t** detalle Item %d monto [%f] **", LOG06,i, stBalance->dMonto[i]);
	    }
	} 
	
    sprintf(buffer_local,REG_1100,
            fnCnvDouble(stBalance->dMonto[iCARGOS_MES],USO0),
            fnCnvDouble(stBalance->dMonto[iAJUSTE_CREDITO],USO0),
            fnCnvDouble(stBalance->dMonto[iBALANCE_ANTERIOR],USO0),
            fnCnvDouble(stBalance->dMonto[iPAGOS_RECIBIDOS],USO0),
            fnCnvDouble(stBalance->dMonto[iPAGOS_REVERTIDOS],USO0),
            fnCnvDouble(stBalance->dMonto[iMISCELANEA],USO0),
            fnCnvDouble(stBalance->dMonto[iTOTAL_FACTURA],USO0),
            fnCnvDouble(stBalance->dMonto[iTOTAL_PAGAR],USO0));

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1100 *******************************/

/****************************************************************************/
/* Funcion Put_A1200                                                        */
/*  Descripcion : Imprime registro A1200 (Documentos Totales) en el archivo */
/*                descrito por Fd_ArchImp.                                  */
/*  Entrada     : Fd_ArchImp, estructuras FactDocuClie, SaldoTot y pstFaCuotas */
/*  Salida      : Fd_ArchImp modificado                                     */
/*  Predecesor  : PutCaratula                                               */
/****************************************************************************/
int Put_A1200   ( FILE *Fd_ArchImp
                  , ST_FACTCLIE *FactDocuClie
                  , STSALDO_ANTERIOR *SaldoTot
                  , ST_CUOTAS *pstFaCuotas
                  , char *zsBufferImpresionArchivo
                  , ST_BALANCE *stBalance)
{
    int     iDigVeriF_Total_Pagar = 0;
    double  dTotalAPagar  = 0.0;
    double  dTotalCuotas  = 0.0;
    char    buffer_local[MAX_BYTE_A1200];
    register int i = 0;
    double  dTotCuotPVen  = 0.0;

    double dSaldoPendienteEcuador=0.0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "Put_A1200");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    for ( i=0;i<pstFaCuotas->iNum_RegCuotas_pven;i++ )
    {
        if ( pstFaCuotas->stReg_pven[i].iInd_Facturado == 2 )
            dTotCuotPVen += pstFaCuotas->stReg_pven[i].dMtoCuota;
    }

    dTotalCuotas = dTotCuotPVen;

    vDTrazasLog(szModulo, "\n\t\tSUMA SaldoTot->dTotalSaldo                [%f] "
                          "\n\t\tSUMA stBalance->dMonto[iBALANCE_ANTERIOR] [%f] "
                          "\n\t\tSUMA FactDocuClie->dTotCargosMes          [%f]  "
                          "\n\t\tSUMA dTotalCuotas                         [%f] ",LOG05,
                          SaldoTot->dTotalSaldo,
                          stBalance->dMonto[iBALANCE_ANTERIOR],
                          FactDocuClie->dTotCargosMes,
                          dTotalCuotas);

    dSaldoPendienteEcuador = stBalance->dMonto[iAJUSTE_CREDITO] +
                             stBalance->dMonto[iBALANCE_ANTERIOR] +
                             stBalance->dMonto[iPAGOS_RECIBIDOS] +
                             stBalance->dMonto[iPAGOS_REVERTIDOS] +
                             stBalance->dMonto[iMISCELANEA];

    dTotalAPagar =  FactDocuClie->dTotCargosMes +
                    stBalance->dMonto[iAJUSTE_CREDITO] +
                    stBalance->dMonto[iBALANCE_ANTERIOR] +
                    stBalance->dMonto[iPAGOS_RECIBIDOS] +
                    stBalance->dMonto[iPAGOS_REVERTIDOS] +
                    stBalance->dMonto[iMISCELANEA] +
                    dTotalCuotas;
    dTotalAPagar =  fnCnvDouble(dTotalAPagar,USO0);
    if ( CalculaDigVerif(dTotalAPagar,&iDigVeriF_Total_Pagar) != TRUE )
    {
        iDigVeriF_Total_Pagar = 999;
    }

    FactDocuClie->dTotCargosMes = FactDocuClie->dTotCargosMes / FactDocuClie->dImpConversion;
    SaldoTot->dTotalSaldo       = SaldoTot->dTotalSaldo / FactDocuClie->dImpConversion;
    dTotalCuotas                = dTotalCuotas / FactDocuClie->dImpConversion;
    dTotalAPagar                = dTotalAPagar / FactDocuClie->dImpConversion;

    dSaldoPendienteEcuador = dSaldoPendienteEcuador / FactDocuClie->dImpConversion;
    vDTrazasLog(szModulo, "\n\tSaldo Pendiente de Ecuador:                 [%f] ",LOG05, dSaldoPendienteEcuador);
    sprintf(buffer_local,REG_1200,
            fnCnvDouble(FactDocuClie->dTotCargosMes,USO0),
            fnCnvDouble(dSaldoPendienteEcuador,USO0),
            fnCnvDouble(dTotalCuotas,USO0),
            dTotalAPagar,
            iDigVeriF_Total_Pagar,
            fnCnvDouble(SaldoTot->dTotalSaldo + FactDocuClie->dTotCargosMes,USO0));

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1200 ***********************************/


/*  P-ECU-05021 ADAPTAcion A IMPRESION FASE II - (2DA PARTE)
 *  Fecha: 29/11/2005
 *  Funcion:        Put_A1250
 *  Descripcion:    Impresion de cuotas vencidas del cliente (XE-200606260033: Cuotas por vencer).
 */
int Put_A1250   ( FILE *Fd_ArchImp
                  , ST_CUOTAS *pstFaCuotas
                  , char *zsBufferImpresionArchivo)
{
    register int i;
    char    buffer_local[MAX_BYTE_A1250];
    double dMontoTotalDeuda = 0.0; /* Valor total de deuda de financiamiento */
    double dSaldoPendiente  = 0.0; /* Saldo pendiente a la fecha */
    rg_cuotas stCuotasAgrup[MAX_CUOTAS_LOCAL];
    int    iNumCuotasAgrup  = 0;
    long   lNum_Folio_Rel;
    char   szPrefPlaza_Rel[11];

    memset(&stCuotasAgrup, 0, sizeof(stCuotasAgrup));
    lNum_Folio_Rel=0;
    szPrefPlaza_Rel[0]='\0';

    /* Recorrer la estructura de cuotas por vencer y enviarlas a impresion */
    vDTrazasLog("Put_A1250", "(Put_A1250): Numero de cuotas por vencer: [%d]", LOG03,pstFaCuotas->iNum_RegCuotas_pven);

    iNumCuotasAgrup = ifnAgruparCuotas(pstFaCuotas->stReg_pven, pstFaCuotas->iNum_RegCuotas_pven, stCuotasAgrup);
    vDTrazasLog("Put_A1250", "(Put_A1250): Numero de cuotas Agrupadas: [%d]", LOG03,iNumCuotasAgrup);

    for ( i=0;i<iNumCuotasAgrup;i++ )
    {
        if ( stCuotasAgrup[i].iInd_Facturado == 2 )
        {
            /* Obtencion del monto total de la deuda y del saldo pendiente  */
            ifnObtenerMontosTotalesCuota(stCuotasAgrup[i],&dMontoTotalDeuda,&dSaldoPendiente);

            vDTrazasLog("Put_A1250", "(Put_A1250): Monto Total deuda retornado: [%015.4f]\n"
                                     "(Put_A1250): Saldo Pendiente   retornado: [%015.4f]\n"
                                     "(Put_A1250): Tipo de Documento: [%d]\n"
                                     "(Put_A1250): Nota de Credito  : [%d]\n"
                                      , LOG03, dMontoTotalDeuda
                                      , dSaldoPendiente
                                      , stCuotasAgrup[i].iCod_TipDocum
                                      , stDatosGener.iCodNotaCre);

            memset(buffer_local,0,sizeof(buffer_local));

            /* SAAM-20070423 Se evalua tipo de documento asociado a cuota P-ECU-06034 RF127 */
            if ( stCuotasAgrup[i].iCod_TipDocum != stDatosGener.iCodNotaCre )
            {
                sprintf(buffer_local,"A1250%15.15ld%-10.10s%3.3d%3.3d%015.4f%015.4f%015.4f%1.1d%15.15s%-15.15s%2.2s\n\0"
                        ,stCuotasAgrup[i].lNum_Folio
                        ,stCuotasAgrup[i].szPrefPlaza
                        ,stCuotasAgrup[i].iSecCuota
                        ,stCuotasAgrup[i].iNumCuota
                        ,stCuotasAgrup[i].dMtoCuota
                        ,dMontoTotalDeuda
                        ,dSaldoPendiente
                        ,1
                        ," "
                        ," "
                        ," ");
            }
            else
            {
                if ( !bfnFolioRelacionado(stCuotasAgrup[i].iCodCliente,
                                          stCuotasAgrup[i].lNum_Folio,
                                          stCuotasAgrup[i].szPrefPlaza,
                                          &lNum_Folio_Rel,
                                          szPrefPlaza_Rel) )
                {
                    vDTrazasLog ("Put_A1250","\n\t\t* No se Puede Obtener Folio Relacionado", LOG01);
                    return (FALSE);
                }

                sprintf(buffer_local,"A1250%15.15ld%-10.10s%3.3d%3.3d%015.4f%015.4f%015.4f%1.1d%15.15ld%-15.15s%2.2d\n\0"
                        ,stCuotasAgrup[i].lNum_Folio
                        ,stCuotasAgrup[i].szPrefPlaza
                        ,stCuotasAgrup[i].iSecCuota
                        ,stCuotasAgrup[i].iNumCuota
                        ,stCuotasAgrup[i].dMtoCuota
                        ,dMontoTotalDeuda
                        ,dSaldoPendiente
                        ,0
                        ,lNum_Folio_Rel
                        ,szPrefPlaza_Rel
                        ,stCuotasAgrup[i].iNumCuota- stCuotasAgrup[i].iSecCuota);
            }

            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
        }
    }

    return(TRUE);
} /*****************************Final Put_A1250 ***********************************/

/***********************************************************************************/
/*  P-COL-05011 PROCESO IMPRESION - NUEVO GAP ADAPTAcionES A SCL TM
 *  Fecha: 09/08/2005
 *  Funcion:        Put_A1120
 *  Descripcion:    Impresion de los documentos emitidos en el periodo de facturacion del cliente.
 */

int Put_A1120(FILE *Fd_ArchImp
              , ST_FACTCLIE  *FactDocuClie
              , ST_CICLOFACT *sthFa_CicloFact
              , char *zsBufferImpresionArchivo
              , long lCodCiclFact)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCliente = 0L;
    char szhFecMinAlta[10]; /* EXEC SQL VAR szhFecMinAlta IS STRING(10); */ 

    char szhFecMenor[10] ="";
    /* EXEC SQL END   DECLARE SECTION; */ 

    int     i=0;
    char    buffer_local[MAX_BYTE_A1120];
    DOCSPERIODO stDocs;

    PAGOS   stPagos;

    memset(buffer_local,0,sizeof(buffer_local));
    memset (&stDocs, 0, sizeof(DOCSPERIODO));
    memset (&stPagos, 0, sizeof(stPagos));

    /* Obtener la menor fecha de alta del cliente */
    lhCodCliente = FactDocuClie->lCodCliente;
    strcpy(szhAFormatoFecha,"YYYYMMDD");

    /* EXEC SQL
    SELECT
    TO_CHAR(MIN(FEC_ALTA),:szhAFormatoFecha)
    INTO
    :szhFecMinAlta
    FROM
    GA_INFACCEL A
    WHERE
    A.COD_CLIENTE = :lhCodCliente; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(min(FEC_ALTA),:b0) into :b1  from GA_INFAC\
CEL A where A.COD_CLIENTE=:b2";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhAFormatoFecha;
    sqlstm.sqhstl[0] = (unsigned long )9;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhFecMinAlta;
    sqlstm.sqhstl[1] = (unsigned long )10;
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
        vDTrazasLog("Put_A1120", "[ERROR] (Put_A1120): Error en ejecucion de SELECT", LOG05);
        return(FALSE);
    }

    /* Si la menor fecha de alta < Fecha Desde la cual se generan las tasaciones */
    if ( strcmp(szhFecMinAlta,sthFa_CicloFact->fec_desde) < 0 )
    {
        /* La fecha menor sera Fecha Desde Cargos Basicos */
        strcpy(szhFecMenor,sthFa_CicloFact->fec_desde);
    }
    else
    {
        /* La fecha menor sera la menor fecha de alta */
        strcpy(szhFecMenor,szhFecMinAlta);
    }

    /* Consultar la tabla FA_HISTDOCU por los documentos del periodo definido */
    if ( !bfnCargarDocsPeriodo(&stDocs.stDocPeriodo, &stDocs.iNumRegs, FactDocuClie->lCodCliente, szhFecMenor,sthFa_CicloFact->fec_hasta) )
    {
        vDTrazasLog(szModulo, "Error en bfnCargarDocsPeriodo [%s]", LOG02,SQLERRM);
        return(FALSE);
    }

    for ( i=0; i < stDocs.iNumRegs; i++ )
    {
        memset(buffer_local,0,sizeof(buffer_local));
        sprintf(buffer_local,"A1120%-5.5s%-3.3s%5.5d%-40.40s%-10.10s%15.15ld%-8.8s%015.4f\n\0"
                , stDocs.stDocPeriodo[i].szCodOperadora
                , stDocs.stDocPeriodo[i].szCodOficina
                , stDocs.stDocPeriodo[i].iCodTipDocum
                , stDocs.stDocPeriodo[i].szDesTipDocum
                , stDocs.stDocPeriodo[i].szPrefPlaza
                , stDocs.stDocPeriodo[i].lNumFolio
                , stDocs.stDocPeriodo[i].szFecEmision
                , fnCnvDouble(stDocs.stDocPeriodo[i].dTotFactura,USO0));

        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
    }

    if ( !bfnCargaUltsPagos(&stPagos.stPago, &stPagos.iNumRegs, FactDocuClie->lCodCliente, lCodCiclFact) )
    {
        vDTrazasLog(szModulo, "Error en bfnCargaUltsPagos [%s]", LOG02,SQLERRM);
        return(FALSE);
    }

    for ( i=0; i < stPagos.iNumRegs; i++ )
    {
        if ( stPagos.stPago[i].iTipPago == 2 )  /* ECU-05021 */
        {
            memset(buffer_local,0,sizeof(buffer_local));
            sprintf(buffer_local,"A1120%-5.5s%-3.3s%5.5d%-40.40s%-10.10s%15.15ld%-8.8s%015.4f\n\0"
                    , stPagos.stPago[i].szCodOperadora
                    , " "
                    , stPagos.stPago[i].iCodTipDocum
                    , stPagos.stPago[i].szDecrip
                    , " "
                    , 0L
                    , stPagos.stPago[i].szFecha
                    , fnCnvDouble(stPagos.stPago[i].dMonto,USO0));

            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
        }
    }
    return(TRUE);
} /*************** fin Put_A1120 *************/

/*  P-COL-05011 PROCESO IMPRESION - NUEVO GAP ADAPTAcionES A SCL TM
 *  Fecha: 04/08/2005
 *  Funcion:        Put_A1130
 *  Descripcion:    Identificacion del documento de origen del documento actual.
 */

int Put_A1130(FILE *Fd_ArchImp
              , ST_FACTCLIE *FactDocuClie
              , char *zsBufferImpresionArchivo)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    szhCodOperadora[6];
    char    szhCodOficina  [3];
    int     ihCodTipDocum      =0;
    char    szhPrefPlaza   [11]="";
    long    lhNumFolio         =0L;
    char    szhFecEmision   [11] ="";
    double  dhTotFactura       =0.0;
    long    lhNumSecuRel       = 0L;
    char    szhLetraRel[2]     = "";
    int     ihCodTipDocumRel   = 0;
    long    lhCodVendedorAgRel = 0L;
    long    lhCodCentrRel      = 0L;
    /* EXEC SQL END   DECLARE SECTION; */ 


    char    buffer_local[MAX_BYTE_A1130];

    memset(buffer_local,0,sizeof(buffer_local));

    /* Si el documento actual tiene documento de origen, realizar su busqueda */
    if ( FactDocuClie->lNumSecuRel !=0 )
    {
        lhNumSecuRel       =  FactDocuClie->lNumSecuRel       ;
        strcpy(szhLetraRel ,  FactDocuClie->szLetraRel       );
        ihCodTipDocumRel   =  FactDocuClie->iCodTipDocumRel   ;
        lhCodVendedorAgRel =  FactDocuClie->lCodVendedorAgRel ;
        lhCodCentrRel      =  FactDocuClie->lCodCentrRel      ;
        strcpy(szhAFormatoFecha,"YYYYMMDD");

        vDTrazasLog("Put_A1130", "lhNumSecuRel       [%ld]\n"
                                 "szhLetraRel        [%s] \n"
                                 "ihCodTipDocumRel   [%d] \n"
                                 "lhCodVendedorAgRel [%ld]\n"
                                 "lhCodCentrRel      [%ld]\n"
                                 , LOG05,lhNumSecuRel
                                 , szhLetraRel
                                 , ihCodTipDocumRel
                                 , lhCodVendedorAgRel
                                 , lhCodCentrRel);

        /* EXEC SQL
        SELECT A.COD_OPERADORA,
               A.COD_OFICINA,
               A.COD_TIPDOCUM,
               A.PREF_PLAZA,
               A.NUM_FOLIO,
               TO_CHAR(A.FEC_EMISION,:szhAFormatoFecha),
               A.TOT_FACTURA
          INTO :szhCodOperadora,
               :szhCodOficina  ,
               :ihCodTipDocum  ,
               :szhPrefPlaza   ,
               :lhNumFolio     ,
               :szhFecEmision  ,
               :dhTotFactura
          FROM FA_HISTDOCU A,
               FA_TIPDOCUMEN B
         WHERE A.NUM_SECUENCI = :lhNumSecuRel
           AND A.COD_TIPDOCUM = B.COD_TIPDOCUMMOV
           AND A.COD_TIPDOCUM = :ihCodTipDocumRel
           AND A.COD_VENDEDOR_AGENTE = :lhCodVendedorAgRel
           AND A.LETRA               = :szhLetraRel
           AND A.COD_CENTREMI        = :lhCodCentrRel; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select A.COD_OPERADORA ,A.COD_OFICINA ,A.COD_TIPDOCUM\
 ,A.PREF_PLAZA ,A.NUM_FOLIO ,TO_CHAR(A.FEC_EMISION,:b0) ,A.TOT_FACTURA into :b\
1,:b2,:b3,:b4,:b5,:b6,:b7  from FA_HISTDOCU A ,FA_TIPDOCUMEN B where (((((A.NU\
M_SECUENCI=:b8 and A.COD_TIPDOCUM=B.COD_TIPDOCUMMOV) and A.COD_TIPDOCUM=:b9) a\
nd A.COD_VENDEDOR_AGENTE=:b10) and A.LETRA=:b11) and A.COD_CENTREMI=:b12)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )112;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhAFormatoFecha;
        sqlstm.sqhstl[0] = (unsigned long )9;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhCodOperadora;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodOficina;
        sqlstm.sqhstl[2] = (unsigned long )3;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipDocum;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhPrefPlaza;
        sqlstm.sqhstl[4] = (unsigned long )11;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhNumFolio;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szhFecEmision;
        sqlstm.sqhstl[6] = (unsigned long )11;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&dhTotFactura;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&lhNumSecuRel;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&ihCodTipDocumRel;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&lhCodVendedorAgRel;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)szhLetraRel;
        sqlstm.sqhstl[11] = (unsigned long )2;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&lhCodCentrRel;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
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



        if ( SQLCODE != SQLOK && SQLCODE!=SQLNOTFOUND )
        {
            vDTrazasLog("Put_A1130", "[ERROR] 1** (Put_A1130): Error en ejecucion de SELECT, Codigo: [%d]", LOG01,sqlca.sqlcode);
            return(FALSE);
        }

        if ( SQLCODE == SQLNOTFOUND )
        {
            /* EXEC SQL
            SELECT A.COD_OPERADORA,
                   A.COD_OFICINA,
                   A.COD_TIPDOCUM,
                   A.PREF_PLAZA,
                   A.NUM_FOLIO,
                   TO_CHAR(A.FEC_EMISION,:szhAFormatoFecha),
                   A.TOT_FACTURA
              INTO :szhCodOperadora,
                   :szhCodOficina  ,
                   :ihCodTipDocum  ,
                   :szhPrefPlaza   ,
                   :lhNumFolio     ,
                   :szhFecEmision  ,
                   :dhTotFactura
              FROM FA_FACTDOCU_NOCICLO A,
                   FA_TIPDOCUMEN B
             WHERE A.NUM_SECUENCI = :lhNumSecuRel
               AND A.COD_TIPDOCUM = B.COD_TIPDOCUMMOV
               AND B.IND_CICLO = 0
               AND A.COD_TIPDOCUM = :ihCodTipDocumRel
               AND A.COD_VENDEDOR_AGENTE = :lhCodVendedorAgRel
               AND A.LETRA               = :szhLetraRel
               AND A.COD_CENTREMI        = :lhCodCentrRel; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 13;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select A.COD_OPERADORA ,A.COD_OFICINA ,A.COD_TIPD\
OCUM ,A.PREF_PLAZA ,A.NUM_FOLIO ,TO_CHAR(A.FEC_EMISION,:b0) ,A.TOT_FACTURA int\
o :b1,:b2,:b3,:b4,:b5,:b6,:b7  from FA_FACTDOCU_NOCICLO A ,FA_TIPDOCUMEN B whe\
re ((((((A.NUM_SECUENCI=:b8 and A.COD_TIPDOCUM=B.COD_TIPDOCUMMOV) and B.IND_CI\
CLO=0) and A.COD_TIPDOCUM=:b9) and A.COD_VENDEDOR_AGENTE=:b10) and A.LETRA=:b1\
1) and A.COD_CENTREMI=:b12)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )179;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szhAFormatoFecha;
            sqlstm.sqhstl[0] = (unsigned long )9;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhCodOperadora;
            sqlstm.sqhstl[1] = (unsigned long )6;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)szhCodOficina;
            sqlstm.sqhstl[2] = (unsigned long )3;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipDocum;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szhPrefPlaza;
            sqlstm.sqhstl[4] = (unsigned long )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&lhNumFolio;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhFecEmision;
            sqlstm.sqhstl[6] = (unsigned long )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&dhTotFactura;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&lhNumSecuRel;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&ihCodTipDocumRel;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&lhCodVendedorAgRel;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)szhLetraRel;
            sqlstm.sqhstl[11] = (unsigned long )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         short *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)&lhCodCentrRel;
            sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
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
                vDTrazasLog("Put_A1130", "[ERROR] (Put_A1130): Error en ejecucion de SELECT, Codigo: [%d]", LOG01,sqlca.sqlcode);
                return(FALSE);
            }
        }

        sprintf(buffer_local,"A1130%-5.5s%-3.3s%5.5d%-10.10s%15.15ld%-8.8s%015.4f\n\0",
                szhCodOperadora,
                szhCodOficina  ,
                ihCodTipDocum  ,
                szhPrefPlaza   ,
                lhNumFolio     ,
                szhFecEmision  ,
                fnCnvDouble(dhTotFactura,USO0));

        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
    }
    return(TRUE);
}/*************** fin Put_A1130 *************/

/*P-COL-05001 FC3  SCL - FACTURAcion - GAP IMPRESION (2 O 1) 2005/05/17 Se
agrega funcion Put_A1150 para imprimir nuevo registro A1150 con informacion del ultimo pago.
Llama a funcion iCargarDatosUltimoPago que esta en ImpSclFnc.pc que rescata los datos del ultimo pago.
*/
int Put_A1150(FILE *Fd_ArchImp
              , ST_FACTCLIE *FactDocuClie
              , char *zsBufferImpresionArchivo
              , long lCodCiclFact)
{
    char    buffer_local[MAX_BYTE_A1150];
    PAGOS   stPagos;
    int i;
    memset (&stPagos, 0, sizeof(stPagos));

    if ( !bfnCargaUltsPagos(&stPagos.stPago, &stPagos.iNumRegs, FactDocuClie->lCodCliente, lCodCiclFact) )
    {
        vDTrazasLog(szModulo, "Error en bfnCargaUltsPagos [%s]", LOG02,SQLERRM);
        return(FALSE);
    }

    for ( i=0; i < stPagos.iNumRegs; i++ )
    {
        if ( stPagos.stPago[i].iTipPago == 1 || stPagos.stPago[i].iTipPago == 3 )  /* ECU-05021 */
        {
            memset(buffer_local,0,sizeof(buffer_local));
            sprintf(buffer_local,"A1150%-8.8s%-40.40s%015.4f%-80.80s%03.3d\n\0"
                    , stPagos.stPago[i].szFecha
                    , stPagos.stPago[i].szDecrip
                    , fnCnvDouble(stPagos.stPago[i].dMonto,USO0)
                    , stPagos.stPago[i].szModPago
                    , stPagos.stPago[i].iTipPago  );

            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
        }
    }
    return(TRUE);
}/*************** fin Put_A1150 *************/

/****************************************************************************/
/* Funcion Put_A1000                                                        */
/*  Descripcion : Imprime registro A1000 (Documento de Cliente) en el       */
/*                archivo descrito por Fd_ArchImp.                          */
/*  Entrada     : Fd_ArchImp, estructuras FactDocuClie y sthFa_CicloFact    */
/*  Salida      : Fd_ArchImp modificado                                     */
/*  Predecesor  : PutCaratula                                               */
/****************************************************************************/
int Put_A1000(FILE *Fd_ArchImp, ST_FACTCLIE *FactDocuClie, ST_CICLOFACT *sthFa_CicloFact, char *zsBufferImpresionArchivo)
{
    int     iDigVer;
    char    buffer_local[MAX_BYTE_A1000];
    TIPDOC  stTipDoc;
    char    sIndDoc_Cero[2];
    char    sFec_Suspension[12];
    char    sCodAutoriz[11];
    char    sAntiguedadCli[2]; /*P-ECU-10004BE*/

    /* Fecha de Vencimiento del codigo de autorizacion */
    char    szFecVenCod[10];
    /* Fecha de Inicio del codigo de autorizacion */    
    char    szFecIniCod[10]; /* ECU-10012 */
    /*Inicio P-ECU-12002F2*/
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    	long  lhCod_cliente;
			long  lNum_Proceso;
    	char  szhInd_envio[2];  /* EXEC SQL VAR szhInd_envio IS STRING(2); */ 

    	char  sDescMotivoSri[50];   /* scope change P-ECU-12002F2*/    	
    /* EXEC SQL END DECLARE SECTION; */ 

    /*Fin P-ECU-12002F2*/

    memset(buffer_local,0,sizeof(buffer_local));
    if ( CalculaDigVerif((double)FactDocuClie->lCodCliente,&iDigVer)!= TRUE )
    {
        iDigVer = 999;
    }

    if ( !bfnFindTipDocum (FactDocuClie->iCodTipDocum, &stTipDoc) )
        return (FALSE);

    vDTrazasLog  ("Put_A1000","\tFactDocuClie->lCodCliente  [%ld]",LOG05,FactDocuClie->lCodCliente);

    if ( (FactDocuClie->dTotFactura >= -0.00001) && (FactDocuClie->dTotFactura <= 0.00001) )
    {
        strcpy(sIndDoc_Cero,"1");
    }
    else
    {
        strcpy(sIndDoc_Cero,"0");
    }

    stFaDetCons.dGravFactura = 0;

    if ( !iCargaFechaSuspension(FactDocuClie->lCodCategoria, FactDocuClie->szFecVencimie, sFec_Suspension) )
    {
        strcpy (sFec_Suspension, " " );
    }
    vDTrazasLog("Put_A1000", "Fecha suspension [%s]\nTipo de distribución [%s]", LOG05,sFec_Suspension, FactDocuClie->szTipDistribucion);

    if ( strcmp(szAplica_Cod_Autorizacion,"S") == 0 )
    {
         /*P-ECU-10039*/
         if ( strcmp(FactDocuClie->szTipDistribucion, "E") == 0 )
         {
             strcpy(sCodAutoriz ,stAutorizFolio_E.szCodAutorizacion);
             strcpy(szFecVenCod ,stAutorizFolio_E.szFechaVencimiento);
             strcpy(szFecIniCod ,stAutorizFolio_E.szFechaInicio); /* ECU-10012 */             
         }
         else
         {
             strcpy(sCodAutoriz ,stAutorizFolio.szCodAutorizacion);
             strcpy(szFecVenCod ,stAutorizFolio.szFechaVencimiento);
             strcpy(szFecIniCod ,stAutorizFolio.szFechaInicio); /* ECU-10012 */        
    }
         /*P-ECU-10039*/
    }
    else
    {
        strcpy(sCodAutoriz ,"");
        strcpy(szFecVenCod ,"");
        strcpy(szFecIniCod ,""); /* ECU-10012 */        
    }
    
	vDTrazasLog("Put_A1000", "sCodAutoriz [%s]\nszFecVenCod[%s]", LOG05, sCodAutoriz, szFecVenCod);
	
    /*P-ECU-10004BE*/
    if (  atoi(FactDocuClie->szFecAlta)>=atoi(sthFa_CicloFact->fec_desde) && 
          atoi(FactDocuClie->szFecAlta)<=atoi(sthFa_CicloFact->fec_hasta) )
    	strcpy(sAntiguedadCli,"N");
    else
    	strcpy(sAntiguedadCli,"A");    	
    /*P-ECU-10004BE*/    

    /*Inicio P-ECU-12002F2*/
    lhCod_cliente=FactDocuClie->lCodCliente;
    lNum_Proceso=FactDocuClie->lNumProceso; 
    vDTrazasLog(szModulo, "Obteniendo Codigo de cliente [%ld] ", LOG05,lhCod_cliente);
    vDTrazasLog(szModulo, "Obteniendo Numero de proceso   [%ld] ", LOG05,lNum_Proceso);

    /* EXEC SQL 
    SELECT NVL(IND_ENVIOELECTRONICO ,'N')
		INTO :szhInd_envio
		FROM FA_AJUSTES
		WHERE COD_CLIENTE = :lhCod_cliente
		AND   NUM_FOLIO   = (SELECT NUM_FOLIOREL FROM FA_INTERFACT  WHERE NUM_PROCESO = :lNum_Proceso)
		AND   PREF_PLAZA  = (SELECT PREF_PLAZAREL FROM FA_INTERFACT  WHERE NUM_PROCESO = :lNum_Proceso); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(IND_ENVIOELECTRONICO,'N') into :b0  from FA_AJ\
USTES where ((COD_CLIENTE=:b1 and NUM_FOLIO=(select NUM_FOLIOREL  from FA_INTE\
RFACT where NUM_PROCESO=:b2)) and PREF_PLAZA=(select PREF_PLAZAREL  from FA_IN\
TERFACT where NUM_PROCESO=:b2))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )246;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhInd_envio;
    sqlstm.sqhstl[0] = (unsigned long )2;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCod_cliente;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lNum_Proceso;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lNum_Proceso;
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


		
   vDTrazasLog(szModulo, "Valor de envio electronico rescatado desde el SELECT  [%s]", LOG03,szhInd_envio);

    if ( SQLCODE != SQLOK && SQLCODE!=SQLNOTFOUND )
    {
        vDTrazasLog("Put_A1000", "[ERROR] 1** (Put_A1000): Error en ejecucion de SELECT a FA_AJUSTES, Codigo: [%d]", LOG01,sqlca.sqlcode);
        return(FALSE);
    }
    if ( SQLCODE  == SQLNOTFOUND ) {
    	vDTrazasLog(szModulo, "Dentro del SQLNOTFOUND: szhInd_envio [%s]", LOG03,szhInd_envio);
    	  strcpy(szhInd_envio,"N");
    }

    if (FactDocuClie->iCodTipDocum != 25 ) {
    	vDTrazasLog(szModulo, "No es Nota de credito , el indicador hInd_envio es null", LOG05);
    	  strcpy(szhInd_envio,"S");
    }
    

    vDTrazasLog(szModulo, "Valor a enviar ::: szhInd_envio [%s]", LOG03,szhInd_envio);
    /*Fin P-ECU-12002F2*/     

   /* Inicio Scope Changue Motivos NC P-ECU-12002F2 */
   
   if ( strcmp(FactDocuClie->szTipDistribucion, "E") == 0 )
   {
             
         /* EXEC SQL  
         SELECT DISTINCT  C.DES_VALOR 
         INTO :sDescMotivoSri    
         FROM GED_CODIGOS C , GE_JUSTIFICACION_DOCUM_SRI G , GE_DOCUMMOTIV_TO M   
         WHERE C.NOM_TABLA ='GE_JUSTIFICACION_DOCUM_VW'
         AND   C.NOM_COLUMNA = 'MOTIVO_SRI'
         AND   M.COD_JUSTIFICACION = G.VALOR_NC 
         AND   G.VALOR_SRI = C.COD_VALOR
         AND   M.NUM_PROCESO =:lNum_Proceso; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 13;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select distinct C.DES_VALOR into :b0  from GED_CODIG\
OS C ,GE_JUSTIFICACION_DOCUM_SRI G ,GE_DOCUMMOTIV_TO M where ((((C.NOM_TABLA='\
GE_JUSTIFICACION_DOCUM_VW' and C.NOM_COLUMNA='MOTIVO_SRI') and M.COD_JUSTIFICA\
CION=G.VALOR_NC) and G.VALOR_SRI=C.COD_VALOR) and M.NUM_PROCESO=:b1)";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )277;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)sDescMotivoSri;
         sqlstm.sqhstl[0] = (unsigned long )50;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&lNum_Proceso;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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


     
         if ( SQLCODE != SQLOK && SQLCODE!=SQLNOTFOUND )
         {
             vDTrazasLog("Put_A1000", "[ERROR] 1** (Put_A1000): Error en ejecucion de SELECT a Motivos de Ajuste del SRI, Codigo: [%d]", LOG01,sqlca.sqlcode);
             return(FALSE);
         }
         if ( SQLCODE  == SQLNOTFOUND ) {
         	vDTrazasLog(szModulo, "Dentro del SQLNOTFOUND: sDescMotivoSri [%s]", LOG03,sDescMotivoSri);
         	  strcpy(sDescMotivoSri," ");
         }
   }else
   { 
   	 strcpy(sDescMotivoSri," ");	
   }	
   
   
   /*  Fin Scope Changue Motivos NC P-ECU-12002F2 */
    

    sprintf(buffer_local,REG_1000,
            FactDocuClie->lCodCliente,
            iDigVer,
            FactDocuClie->iCodTipDocum,
            FactDocuClie->lNum_Folio,
            FactDocuClie->szNumCtc,
            FactDocuClie->szCodDespacho,
            sthFa_CicloFact->fec_desde,
            sthFa_CicloFact->fec_hasta,
            FactDocuClie->szFecEmision,
            FactDocuClie->szFecVencimie,
            FactDocuClie->szIndDebito,
            FactDocuClie->szCod_Idioma,
            szPlan,
            sDescPlanTarif,
            FactDocuClie->lIndOrdenTotal,
            FactDocuClie->szPrefPlaza,
            FactDocuClie->szCodPlaza,
            stTipDoc.szDesTipDocum,
            FactDocuClie->szNomApoderado,
            sCodAutoriz,
            fnCnvDouble(stFaDetCons.dGravFactura,USO0),
            sIndDoc_Cero,
            sFec_Suspension,
            iNumTerminales,
            szFecVenCod,
            FactDocuClie->szCodZona,
            /*P-ECU-10004BE*/
            FactDocuClie->szTipDistribucion,
            FactDocuClie->szEmailPrincipal,
            FactDocuClie->szEmailAlterno,
            FactDocuClie->lCodCategoria,
            FactDocuClie->lIdSegmento,
            sAntiguedadCli,
            FactDocuClie->iCodSisPago,
            /*P-ECU-10004BE*/
            szFecIniCod,  /* ECU-10012 */        
            szhInd_envio, /*P-ECU-12002F2*/
            sDescMotivoSri); /* scope change  P-ECU-12002F2*/


    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1000 ***********************************/


/****************************************************************************************/
/* Funcion Put_A1010                                                                    */
/*  Descripcion : Imprime registro A1010 (Documento de Operdora) en el archivo descrito */
/*            por Fd_ArchImp.                                                           */
/*  Entrada     : Fd_ArchImp, estructuras FactDocuClie                                  */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1010(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo, long lCodCicloFact)
{
    int     iDigVer;
    char    buffer_local[MAX_BYTE_A1010];
    char    szhNomVendedor[41];
    OFICINA2    stOfic;
    OPERADORA   stOper;
    VENDEDOR    stVendedor;

    vDTrazasLog ("Put_A1010","\tGE_OPERADORA_SCL (%s) ",LOG04,FactDocuClie->szCodOperadora);

    if ( !bfnFindOperadora (FactDocuClie->szCodOperadora, &stOper ) )
        return (FALSE);

    if ( !bfnFindOficina2 (FactDocuClie->szCod_Oficina, &stOfic) )
        return (FALSE);

    vDTrazasLog ("Put_A1010","\tFactDocuClie->lCodVendedor    [%ld] ",LOG04,FactDocuClie->lCodVendedor);

    if ( !bfnFindVendedores (FactDocuClie->lCodVendedor, &stVendedor, lCodCicloFact) )
        return (FALSE);

    strcpy(szhNomVendedor,stVendedor.szNomVendedor);

    memset(buffer_local,0,sizeof(buffer_local));
    if ( CalculaDigVerif((double)stOper.lCodClienteOperadora,&iDigVer)!= TRUE )
    {
        iDigVer = 999;
    }

    sprintf(buffer_local,REG_1010,
            stOper.lCodClienteOperadora,
            iDigVer,
            FactDocuClie->szCodOperadora,
            stOper.szNomOperadora,
            stOper.szNumIdenTRib,
            FactDocuClie->szCod_Oficina,
            stOfic.szDesOficina,
            FactDocuClie->lCodVendedor,
            szhNomVendedor);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1010 ***********************************/


/***************************************************************************************/
/* Funcion Put_A1300                                                                   */
/*  Descripcion : Imprime registro A1300 (Registro de Cliente) en el archivo descrito  */
/*            por Fd_ArchImp.                                                          */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                  */
/*      Salida      : Fd_ArchImp modificado                                            */
/*  Predecesor  : PutCaratula                                                          */
/***************************************************************************************/
int Put_A1300(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    int     i;
    char    szNum_Celular[21];
    char    sCodtipident [3];
    char    buffer_local[MAX_BYTE_A1300];
    /*Inicio P-ECU-12002F2*/
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    	long  lhCod_cliente;
    	long  lhNum_Venta;
    	int   iCod_TipDocu;
    	char  szhNom_retiraeq [51];				/* EXEC SQL VAR szhNom_retiraeq IS STRING(51); */ 

    	char  szhNum_ident_retiraeq[21];  /* EXEC SQL VAR szhNum_ident_retiraeq IS STRING(21); */ 

    	long  lhNum_Proceso;
    /* EXEC SQL END DECLARE SECTION; */ 

    /*Fin P-ECU-12002F2*/
        
    strcpy (szModulo, "Put_A1300");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(buffer_local,0,sizeof(buffer_local));

    /*Inicio P-ECU-12002F2*/
    iCod_TipDocu=FactDocuClie->iCodTipDocum;
    strcpy(szhNom_retiraeq,"");
    strcpy(szhNum_ident_retiraeq,"");                         
    
    if (  iCod_TipDocu == 1 ||  iCod_TipDocu == 48 ||  iCod_TipDocu == 18 ||  iCod_TipDocu == 53) 
    {
              lhCod_cliente=FactDocuClie->lCodCliente;
              lhNum_Venta=FactDocuClie->lNumVenta;
              lhNum_Proceso=FactDocuClie->lNumProceso;
              vDTrazasLog(szModulo, "Obteniendo Codigo de cliente - venta - proceso [%ld|%ld|%ld] ", LOG05,lhCod_cliente,lhNum_Venta,lhNum_Proceso);
              /* EXEC SQL 
              SELECT NVL(NOM_RETIRAEQ,''), NVL(NUM_IDENT_RETIRAEQ ,'')
          		INTO :szhNom_retiraeq, :szhNum_ident_retiraeq
          		FROM VE_DATOSRETIRAEQ_TO
          		WHERE COD_CLIENTE =  :lhCod_cliente
          		AND   NUM_VENTA = :lhNum_Venta
          		OR    NUM_VENTA = :lhNum_Proceso; */ 

{
              struct sqlexd sqlstm;
              sqlstm.sqlvsn = 12;
              sqlstm.arrsiz = 13;
              sqlstm.sqladtp = &sqladt;
              sqlstm.sqltdsp = &sqltds;
              sqlstm.stmt = "select NVL(NOM_RETIRAEQ,'') ,NVL(NUM_IDENT_RETI\
RAEQ,'') into :b0,:b1  from VE_DATOSRETIRAEQ_TO where ((COD_CLIENTE=:b2 and NU\
M_VENTA=:b3) or NUM_VENTA=:b4)";
              sqlstm.iters = (unsigned int  )1;
              sqlstm.offset = (unsigned int  )300;
              sqlstm.selerr = (unsigned short)1;
              sqlstm.cud = sqlcud0;
              sqlstm.sqlest = (unsigned char  *)&sqlca;
              sqlstm.sqlety = (unsigned short)4352;
              sqlstm.occurs = (unsigned int  )0;
              sqlstm.sqhstv[0] = (unsigned char  *)szhNom_retiraeq;
              sqlstm.sqhstl[0] = (unsigned long )51;
              sqlstm.sqhsts[0] = (         int  )0;
              sqlstm.sqindv[0] = (         short *)0;
              sqlstm.sqinds[0] = (         int  )0;
              sqlstm.sqharm[0] = (unsigned long )0;
              sqlstm.sqadto[0] = (unsigned short )0;
              sqlstm.sqtdso[0] = (unsigned short )0;
              sqlstm.sqhstv[1] = (unsigned char  *)szhNum_ident_retiraeq;
              sqlstm.sqhstl[1] = (unsigned long )21;
              sqlstm.sqhsts[1] = (         int  )0;
              sqlstm.sqindv[1] = (         short *)0;
              sqlstm.sqinds[1] = (         int  )0;
              sqlstm.sqharm[1] = (unsigned long )0;
              sqlstm.sqadto[1] = (unsigned short )0;
              sqlstm.sqtdso[1] = (unsigned short )0;
              sqlstm.sqhstv[2] = (unsigned char  *)&lhCod_cliente;
              sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
              sqlstm.sqhsts[2] = (         int  )0;
              sqlstm.sqindv[2] = (         short *)0;
              sqlstm.sqinds[2] = (         int  )0;
              sqlstm.sqharm[2] = (unsigned long )0;
              sqlstm.sqadto[2] = (unsigned short )0;
              sqlstm.sqtdso[2] = (unsigned short )0;
              sqlstm.sqhstv[3] = (unsigned char  *)&lhNum_Venta;
              sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
              sqlstm.sqhsts[3] = (         int  )0;
              sqlstm.sqindv[3] = (         short *)0;
              sqlstm.sqinds[3] = (         int  )0;
              sqlstm.sqharm[3] = (unsigned long )0;
              sqlstm.sqadto[3] = (unsigned short )0;
              sqlstm.sqtdso[3] = (unsigned short )0;
              sqlstm.sqhstv[4] = (unsigned char  *)&lhNum_Proceso;
              sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
              sqlstm.sqhsts[4] = (         int  )0;
              sqlstm.sqindv[4] = (         short *)0;
              sqlstm.sqinds[4] = (         int  )0;
              sqlstm.sqharm[4] = (unsigned long )0;
              sqlstm.sqadto[4] = (unsigned short )0;
              sqlstm.sqtdso[4] = (unsigned short )0;
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

 
          
              if ( SQLCODE != SQLOK && SQLCODE!=SQLNOTFOUND )
              {
                  vDTrazasLog("Put_A1300", "[ERROR] 1** (Put_A1300): Error en ejecucion de SELECT a VE_DATOSRETIRAEQ_TO, Codigo: [%d]", LOG01,sqlca.sqlcode);
                  return(FALSE);
              }
             if ( SQLCODE  == SQLNOTFOUND ) {
    	       strcpy(szhNom_retiraeq,"");
    	       strcpy(szhNum_ident_retiraeq,"");                         
             }        
    }       
    vDTrazasLog(szModulo, "Nom_retiraeq [%s] - Num_ident_retiraeq [%s] ", LOG03,szhNom_retiraeq,szhNum_ident_retiraeq);
    /*Fin P-ECU-12002F2*/ 
    

    for ( i=0;i < stFaDetCons.iNumReg ;i++ )
    {
        if ( strcmp(fnQuitaBlancos(stFaDetCons.stDetConsumo[i].szNum_Celular),"0") )
        {
            strcpy(szNum_Celular, stFaDetCons.stDetConsumo[i].szNum_Celular);
            break;
        }
    }

    vDTrazasLog(szModulo, "antes  de llenar el buffer ", LOG05);
    vDTrazasLog(szModulo, "FactDocuClie->lCodCliente    [%ld] ", LOG05, FactDocuClie->lCodCliente);
    vDTrazasLog(szModulo, "FactDocuClie->szCod_tipident [%s] ", LOG05, FactDocuClie->szCod_tipident);
    strcpy(sCodtipident,FactDocuClie->szCod_tipident);
    sprintf(buffer_local,REG_1300,
            FactDocuClie->szRut_Cliente,
            FactDocuClie->szNombre_Clie,
            szNum_Celular,
            FactDocuClie->iCodSisPago,
            "        ",
            sCodtipident, /* Inc-pre-189124  */
            szhNom_retiraeq,          /*P-ECU-12002F2*/
            szhNum_ident_retiraeq);   /*P-ECU-12002F2*/

    vDTrazasLog(szModulo, "buffer_local [%s] ", LOG05);
    vDTrazasLog(szModulo, "[%s] ", LOG05, buffer_local);
    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1300 ***********************************/


/****************************************************************************************/
/* Funcion Put_A1400                                                                    */
/*  Descripcion : Imprime registro A1400 (Registro de Direccion de Facturacion ) en el  */
/*            archivo descrito por Fd_ArchImp.                                          */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1400(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char        buffer_local[MAX_BYTE_A1400];

    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1400");
    vDTrazasLog(szModulo, "\tEntro a %s \n"
                          "Facturacion : [%s]"
                          , LOG05, szModulo,FactDocuClie->szDireccion[iDIRECCION_FACTURACION]);

    sprintf(buffer_local,REG_1400, FactDocuClie->szDireccion[iDIRECCION_FACTURACION]);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1400 ***********************************/


/**************************************************************************************/
/* Funcion Put_A1410                                                                  */
/*  Descripcion : Imprime registro A1410 (Registro de Direccion de Operadora ) en el  */
/*            archivo descrito por Fd_ArchImp.                                        */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                 */
/*      Salida      : Fd_ArchImp modificado                                           */
/*  Predecesor  : PutCaratula                                                         */
/**************************************************************************************/
int Put_A1410(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char        buffer_local[MAX_BYTE_A1410];

    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1410");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    sprintf(buffer_local,REG_1410, FactDocuClie->szDireccion[iDIRECCION_OPERADORA]);

    vDTrazasLog(szModulo, "Operadora : [%s]", LOG05,FactDocuClie->szDireccion[iDIRECCION_OPERADORA]);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1410 ***********************************/


/*************************************************************************************/
/* Funcion Put_A1420                                                                 */
/*  Descripcion : Imprime registro A1420 (Registro de Direccion de la plaza ) en el  */
/*            archivo descrito por Fd_ArchImp.                                       */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                */
/*      Salida      : Fd_ArchImp modificado                                          */
/*  Predecesor  : PutCaratula                                                        */
/*************************************************************************************/
int Put_A1420(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char        buffer_local[MAX_BYTE_A1420];

    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1420");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    vDTrazasLog(szModulo, "Plaza : [%s]", LOG05,FactDocuClie->szDireccion[iDIRECCION_PLAZA]);

    sprintf(buffer_local,REG_1420, FactDocuClie->szDireccion[iDIRECCION_PLAZA]);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/***************************************Final Put_A1420 ****************************************/


/****************************************************************************************/
/* Funcion Put_A1430                                                                    */
/*  Descripcion : Imprime registro A1430 (Registro de Direccion de la sucursal ) en el  */
/*            archivo descrito por Fd_ArchImp.                                          */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1430(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char        buffer_local[MAX_BYTE_A1430];

    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1430");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    vDTrazasLog(szModulo, "Sucursal : [%s]", LOG05,FactDocuClie->szDireccion[iDIRECCION_SUCURSAL]);

    sprintf(buffer_local,REG_1430, FactDocuClie->szDireccion[iDIRECCION_SUCURSAL]);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/***************************************Final Put_A1430 ****************************************/


/****************************************************************************************/
/* Funcion Put_A1500                                                                    */
/*  Descripcion : Imprime registro A1500 (Registro de Direccion Correspondencia) en el  */
/*            archivo descrito por Fd_ArchImp.                                          */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1500(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char        buffer_local[MAX_BYTE_A1500];

    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1500");
    vDTrazasLog(szModulo, "\tEntro a %s \n"
                          "Correspondencia : [%s]"
                          , LOG05, szModulo,FactDocuClie->szDireccion[iDIRECCION_CORRESPONDENCIA]);

    sprintf(buffer_local,REG_1500,  FactDocuClie->szDireccion[iDIRECCION_CORRESPONDENCIA]);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A1500 ***********************************/


/************************************************************************************/
/* Funcion Put_A1700                                                                */
/*  Descripcion : Imprime registro A1700 (Registro de Informacion Consumo) en el    */
/*            archivo descrito por Fd_ArchImp.                                      */
/*  Entrada     : Fd_ArchImp, lCodCliente y estructura sthFa_CicloFact              */
/*      Salida      : Fd_ArchImp modificado                                         */
/*  Predecesor  : PutCaratula                                                       */
/************************************************************************************/
int Put_A1700(FILE *Fd_ArchImp, long lCod_Cliente, ST_CICLOFACT *psthFaCiclFact, char *zsBufferImpresionArchivo)
{
    int i=0;
    int j;
    char    buffer_local[MAX_BYTE_A1700];
    long    lMin_Local_Max     =0;
    long    lMin_Adicio_Max    =0;
    double  dMto_FactCiclo_Max =0.0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long    lhMin_Local     ;
    long    lhMin_Adicio    ;
    int     ihNum_Mes       ;
    double  dhMto_FactCiclo ;
    /* EXEC SQL END DECLARE SECTION; */ 


    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "Put_A1700");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    sqlca.sqlcode = 0;

    lhCodClienteCur =lCod_Cliente;
    ihNumMes_Ciclo0Cur = atoi(psthFaCiclFact->szMesCiclo_0);
    ihNumMes_Ciclo5Cur = atoi(psthFaCiclFact->szMesCiclo_5);

    sqlca.sqlcode = 0;

    /* EXEC SQL OPEN Cursor_ConsumosMes; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )335;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhCodClienteCur;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihNumMes_Ciclo0Cur;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&ihNumMes_Ciclo5Cur;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog(szModulo, "Error en OPEN Cursor_ConsumosMes. Error [%d][%s] ", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    sprintf (buffer_local, REG_INI1700);

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    /* EXEC SQL FETCH Cursor_ConsumosMes
    INTO :ihNum_Mes,
         :lhMin_Local,
         :lhMin_Adicio,
         :dhMto_FactCiclo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )378;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihNum_Mes;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhMin_Local;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhMin_Adicio;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&dhMto_FactCiclo;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
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



    if ( sqlca.sqlcode == SQLNOTFOUND )
    {
        for ( j=1;j < 7 ;j++ )
        {
            sprintf (buffer_local, REG_1700 ,0,(long)0,(long)0,(long)0,0.0);    /*P-COL-05001 FC3  SCL - FACTURAcion - GAP IMPRESION (2 O 1) */
            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
        }
        sprintf (buffer_local, REG_FIN1700 ,(long)0,(long)0,0.0);
        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
        return(TRUE);
    }
    else
    {
        if ( lhMin_Local < 0 )
        {
            lhMin_Local = lhMin_Local * -1;
            vDTrazasLog(szModulo, "Monto MinLocal negativo Despues...[%ld]", LOG05, lhMin_Local);
        }

        if ( lhMin_Adicio < 0 )
        {
            lhMin_Adicio = lhMin_Adicio * -1;
            vDTrazasLog(szModulo, "Monto MinAdicional negativo Despues...[%ld]", LOG05, lhMin_Adicio);
        }
    }

    lMin_Local_Max=lhMin_Local;
    lMin_Adicio_Max=lhMin_Adicio;
    dMto_FactCiclo_Max=dhMto_FactCiclo;

    for ( i=1; i < 7; i++ )
    {
        if ( sqlca.sqlcode == SQLOK )
        {
            sprintf (buffer_local,REG_1700 ,
                     ihNum_Mes,
                     lhMin_Local,
                     lhMin_Adicio,
                     lhMin_Local + lhMin_Adicio,
                     fnCnvDouble(dhMto_FactCiclo,USO0));
            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
        }
        else
        {
            for ( j=i;j < 7 ;j++ )
            {
                sprintf (buffer_local, REG_1700 ,0,(long)0,(long)0,(long)0,0.0);   /*P-COL-05001 FC3  SCL - FACTURAcion - GAP IMPRESION (2 O 1) */
                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                    return(FALSE);
            }
            lMin_Local_Max=0;
            lMin_Adicio_Max=0;
            dMto_FactCiclo_Max=0;
            break;
        }

        /* EXEC SQL FETCH Cursor_ConsumosMes
        INTO    :ihNum_Mes,
        :lhMin_Local,
        :lhMin_Adicio,
        :dhMto_FactCiclo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )409;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihNum_Mes;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhMin_Local;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhMin_Adicio;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&dhMto_FactCiclo;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
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



        if ( lhMin_Local < 0 )
        {
            lhMin_Local = lhMin_Local * -1;
            vDTrazasLog(szModulo, "Monto MinLocal negativo Despues...[%ld]", LOG05, lhMin_Local);
        }

        if ( lhMin_Adicio < 0 )
        {
            lhMin_Adicio = lhMin_Adicio * -1;
            vDTrazasLog(szModulo, "Monto MinAdicional negativo Despues...[%ld]", LOG05, lhMin_Adicio);
        }

        if ( lMin_Local_Max < lhMin_Local )
        {
            lMin_Local_Max = lhMin_Local;
        }
        if ( lMin_Adicio_Max < lhMin_Adicio )
        {
            lMin_Adicio_Max = lhMin_Adicio;
        }
        if ( dMto_FactCiclo_Max < dhMto_FactCiclo )
        {
            dMto_FactCiclo_Max = dhMto_FactCiclo;
        }
    }

    sprintf (buffer_local,REG_FIN1700 ,
             lMin_Local_Max,
             lMin_Adicio_Max,
             fnCnvDouble(dMto_FactCiclo_Max,USO0));


    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    /* EXEC SQL CLOSE Cursor_ConsumosMes; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )440;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( sqlca.sqlcode != SQLOK )
    {
        vDTrazasError(szModulo, "Error en CLOSE Cursor_ConsumosMes. [%d][%s] ", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }
    return(TRUE);

}/*****************************Final Put_A1700 ***********************************/


/****************************************************************************************/
/* Funcion Put_A2000                                                                    */
/*  Descripcion : Imprime registro A2000 (Registro Bloque de Mensajes) en el archivo    */
/*            descrito por Fd_ArchImp.                                                  */
/*  Entrada     : Fd_ArchImp, estructura Mensajes                                       */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/

int Put_A2000(FILE *Fd_ArchImp, ST_MENSAJES *Mensajes, char *zsBufferImpresionArchivo)
{
    int     iIndice;
    char    szIdioma[10];
    char    buffer_local[MAX_BYTE_A2000];

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "Put_A2000");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    sprintf(buffer_local,REG_INI2000);
    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    for ( iIndice=0;iIndice < 4 ;iIndice++ )
    {
        strcpy(szIdioma, Mensajes->zsCodIdioma[iIndice]);
        FillCodIdioma(szIdioma);

        sprintf(buffer_local,REG_2000,
                Mensajes->iCorrMensaje[iIndice],
                Mensajes->iNumLinea[iIndice],
                Mensajes->iCantCaract[iIndice],
                szIdioma);

        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
    }

    sprintf(buffer_local,"\n\0");
    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);

}/*****************************Final Put_A2000 ***********************************/

/****************************************************************************************/
/* Funcion Put_A1800                                                                    */
/*  Descripcion : Imprime registro A1800 (Registro de Detalle Facturado Nivel 1) en el  */
/*            archivo descrito por Fd_ArchImp.                                          */
/*  Entrada     : Fd_ArchImp, estructuras FaDetConsumo y sthTablaAcum                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1800(FILE *Fd_ArchImp, ST_TABLA_ACUM *sthTablaAcum, STSALDO_ANTERIOR *SaldoTot, ST_CUOTAS *pstFaCuotas, char *zsBufferImpresionArchivo, double dFact_Conversion) /* P-TMM-03075 */
{
    int         i, ix, iAux;
    int         j;  /* PGG SOPORTE 64059 - 02-04-2008 */
    ST_TABLA    sthTabla;
    char        szElemento_1[50];
    char        szElemento_2[50];

    char        szFacturaSN_KeyAcum[60];    /* PGG SOPORTE 64059 - 02-04-2008 */
    ST_TABLA_ORDEN  pstTablaOrden;          /* PGG SOPORTE 64059 - 02-04-2008 */
    int         iCod_GrupoAnt;              /* PGG SOPORTE 64059 - 02-04-2008 */
    BOOL        Flg_CabeceraPie;            /* PGG SOPORTE 64059 - 02-04-2008 */

    int         iValor;
    char        szResultado[20];
    double      dTotalCuotas;
    char        buffer_local[MAX_BYTE_A1800];
    double      dTotalPrimeraCateg=0.0;
    double      dTotalSegundaCateg=0.0;
    double      dTotalNetoImpto=0.0;
    double      dResultadoAux=0.0;
    

    struct timeb    tpi;

    memset(&pstTablaOrden, 0, sizeof (ST_TABLA_ORDEN));     /* PGG SOPORTE 64059 - 02-04-2008 */
    memset(buffer_local,0,sizeof(buffer_local));
    memset(&sthTabla, 0, sizeof (ST_TABLA));

    strcpy (szModulo, "Put_A1800");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    sthTablaAcum->dTotalCosto=0;

    dTotalCuotas = pstFaCuotas->dTotalCuotas_pven;

    bfnLimpiaFlag(&pstCatImpues);

    for ( i = 0; i < stFaDetCons.iNumReg; i++ )
    {
        if ( strcmp(fnQuitaBlancos(stFaDetCons.stDetConsumo[i].szTip_ConcNoFact)," ") )
            strcpy(szElemento_1,"0");
        else
            strcpy(szElemento_1,"1");

        if ( strncmp(stFaDetCons.stDetConsumo[i].szTip_ConcNoFact," ",1)==0 )
        {
            strcpy(szFacturaSN_KeyAcum,szCONCEP_FACTURABLE);
        }
        else
        {
            strcpy(szFacturaSN_KeyAcum,szCONCEP_NO_FACTURABLE);
        }

        sprintf(szElemento_2,"%s|%05d|%05d|%05d|%05d|%05d",
                szFacturaSN_KeyAcum,
                stFaDetCons.stDetConsumo[i].iNum_OrdenGr,
                stFaDetCons.stDetConsumo[i].iNum_OrdenSubGr,
                stFaDetCons.stDetConsumo[i].iNum_OrdenConc,
                stFaDetCons.stDetConsumo[i].iCodGrupo,
                stFaDetCons.stDetConsumo[i].iCodConcepto);

        iValor = RetPos(szElemento_2, &sthTabla);

        strcpy(sthTablaAcum->szKey[iValor],szElemento_2);

        sthTablaAcum->lSegundos[iValor]          += stFaDetCons.stDetConsumo[i].lSeg_Consumo;
        sthTablaAcum->dCostoFacturaNeto[iValor]  += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
        sthTablaAcum->iCodGrupo[iValor]          =  stFaDetCons.stDetConsumo[i].iCodGrupo;

        strcpy(sthTablaAcum->szDesGrupo[iValor],stFaDetCons.stDetConsumo[i].szGlosaGrupo);

        if ( stFaDetCons.stDetConsumo[i].lSeg_Consumo > 0 )
            sthTablaAcum->lTotalSeg  += stFaDetCons.stDetConsumo[i].lSeg_Consumo;

        sthTablaAcum->iFacturable[iValor] = atoi(szElemento_1);

        if ( sthTablaAcum->iFacturable[iValor] == 1 )
            sthTablaAcum->dTotalCosto += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;

        sprintf(szResultado,"%12.12ld",stFaDetCons.stDetConsumo[i].lSeg_Consumo);

        if ( stFaDetCons.stDetConsumo[i].iCodTipConce !=1 )
        {
            ftime(&tpi);
            vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx bfnTotImptosCateg= %ld.%d",LOG03, tpi.time,tpi.millitm);

            if ( !bfnTotImptosCateg(stFaDetCons.stDetConsumo[i].iCodConcepto, stFaDetCons.stDetConsumo[i].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
                return(FALSE);
            }
            else
            {
                sthTablaAcum->dGravPrimeraCategoria[iValor]  += dTotalPrimeraCateg;
                sthTablaAcum->dGravSegundaCategoria[iValor]  += dTotalSegundaCateg;

            }

            ftime(&tpi);
            vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx bfnTotImptosCateg= %ld.%d",LOG03, tpi.time,tpi.millitm);
        }

        strcpy(sthTablaAcum->szTipGrupo [iValor] , stFaDetCons.stDetConsumo[i].szTipGrupo);
        strcpy(sthTablaAcum->szTipUnidad[iValor] , stFaDetCons.stDetConsumo[i].szTipUnidad);
        sthTablaAcum->iNivelImpresion   [iValor] = stFaDetCons.stDetConsumo[i].iNivelImpresion;

        strcpy(sthTablaAcum->szDesConcepto[iValor] , stFaDetCons.stDetConsumo[i].szDes_Concepto);
        sthTablaAcum->iCodConcepto   [iValor] = stFaDetCons.stDetConsumo[i].iCodConcepto;   
				sthTablaAcum->dPrcImpuesto   [iValor] = stFaDetCons.stDetConsumo[i].dPrcImpuesto; /* Inc-pre-189124  */  
        
        
    } /* Fin del For */


/* PGG SOPORTE Desde Aqui 64059 - 02-04-2008 */
    if ( !bfnOrdenaImpresionRC(sthTablaAcum, &pstTablaOrden, sthTabla.iLastPosition) )
    {
        vDTrazasLog(szModulo,"Funcion bfnOrdenaImpresionRC FALLO\n", LOG05);
        return (FALSE);
    }


/* PGG SOPORTE Desde Aqui 64059 -Chanchullo pa arreglar los montos - 02-04-2008  */
    iCod_GrupoAnt  = -666;
    iAux = 0;

    for ( i = 0; i<sthTabla.iLastPosition; i++ )
    {
        ix=pstTablaOrden.iSocalo[i];
        if ( iCod_GrupoAnt != sthTablaAcum->iCodGrupo[ix] )
        {
            iAux = ix;
        }
        else
        {
            sthTablaAcum->dGravPrimeraCategoria[iAux] += sthTablaAcum->dGravPrimeraCategoria[ix];
            sthTablaAcum->dGravSegundaCategoria[iAux] += sthTablaAcum->dGravSegundaCategoria[ix];
            sthTablaAcum->dCostoFacturaNeto[iAux]     += sthTablaAcum->dCostoFacturaNeto[ix]    ;
            sthTablaAcum->lSegundos[iAux]             += sthTablaAcum->lSegundos[ix];

        }
        iCod_GrupoAnt = sthTablaAcum->iCodGrupo[ix];

    }
/* PGG SOPORTE Hasta Aqui 64059 -Chanchullo pa arreglar los montos - 02-04-2008  */


    iCod_GrupoAnt  = -666;          /* PGG SOPORTE 64059 - 02-04-2008 */
    Flg_CabeceraPie = FALSE;        /* PGG SOPORTE 64059 - 02-04-2008 */

/*
    for (i = 0; i < sthTabla.iLastPosition; i++)
    { */
    for ( j=0; j<sthTabla.iLastPosition ;j++ )
    {
        i = pstTablaOrden.iSocalo[j];   /* PGG SOPORTE Hasta Aqui 64059 - 02-04-2008 */

        if ( sthTablaAcum->iFacturable[i] == 1 ) /* CONCEPTO FACTURABLE */
        {
            sprintf(szResultado,"%12.12ld",sthTablaAcum->lSegundos[i]);

            dTotalNetoImpto=sthTablaAcum->dCostoFacturaNeto[i] +
                            sthTablaAcum->dGravPrimeraCategoria[i] +
                            sthTablaAcum->dGravSegundaCategoria[i];


            if ( iCod_GrupoAnt != sthTablaAcum->iCodGrupo[i] )
            {
                if ( Flg_CabeceraPie )
                {
                    Flg_CabeceraPie = FALSE;
                    j--;
                    continue;
                }
                else
                {
                    
                    switch ( sthTablaAcum->iCodGrupo[i] )
                    {
                                           	
                        case COD_GRUPO_SALDANT:{
                                SaldoTot->dTotalSaldo = SaldoTot->dTotalSaldo / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(SaldoTot->dTotalSaldo,USOFACT),                  /* fnCnvDouble(SaldoTot->dTotalSaldo,igUsoCalculo), */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i],
                                        sthTablaAcum->dPrcImpuesto[i] ); /*Inc-pre-189124  */ 
                                        

                                buffer_local[_strlen(buffer_local)]=0;

                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);

                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                        case COD_GRUPO_CUOTA:{
                                dTotalCuotas = dTotalCuotas / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(dTotalCuotas,USOFACT),                  /* fnCnvDouble(dTotalCuotas,igUsoCalculo), */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT), /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT), /* fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i],
                                        sthTablaAcum->dPrcImpuesto[i] ); /*Inc-pre-189124  */ 
                                        
                                buffer_local[_strlen(buffer_local)]=0;

                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);

                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                        default:{
                                sthTablaAcum->dCostoFacturaNeto[i] = sthTablaAcum->dCostoFacturaNeto[i] / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[i],igUsoCalculo),  */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i],
                                        sthTablaAcum->dPrcImpuesto[i] ); /*Inc-pre-189124  */ 

                                buffer_local[_strlen(buffer_local)]=0;
                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);

                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                    }
                }
            }
            iCod_GrupoAnt = sthTablaAcum->iCodGrupo[i];
        }
    }


    iCod_GrupoAnt  = -666;          /* PGG SOPORTE 64059 - 02-04-2008 */
    Flg_CabeceraPie = FALSE;        /* PGG SOPORTE 64059 - 02-04-2008 */

/*
    for (i = 0; i < sthTabla.iLastPosition; i++)
    { */
    for ( j=0; j<sthTabla.iLastPosition ;j++ )
    {
        i = pstTablaOrden.iSocalo[j];   /* PGG SOPORTE Hasta Aqui 64059 - 02-04-2008 */

        if ( sthTablaAcum->iFacturable[i] == 0 ) /* CONCEPTO NO FACTURABLE */
        {
            sprintf(szResultado,"%12.12ld",sthTablaAcum->lSegundos[i]);

            dTotalNetoImpto=sthTablaAcum->dCostoFacturaNeto[i] +
                            sthTablaAcum->dGravPrimeraCategoria[i] +
                            sthTablaAcum->dGravSegundaCategoria[i];

            if ( iCod_GrupoAnt != sthTablaAcum->iCodGrupo[i] )
            {
                if ( Flg_CabeceraPie )
                {
                    Flg_CabeceraPie = FALSE;
                    j--;
                    continue;
                }
                else
                {

                    switch ( sthTablaAcum->iCodGrupo[i] )
                    {
                        case COD_GRUPO_SALDANT:{
                                SaldoTot->dTotalSaldo = SaldoTot->dTotalSaldo / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(SaldoTot->dTotalSaldo,USOFACT),                  /* fnCnvDouble(SaldoTot->dTotalSaldo,igUsoCalculo), */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i]);

                                buffer_local[_strlen(buffer_local)]=0;
                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);
                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                        case COD_GRUPO_CUOTA:{
                                dTotalCuotas = dTotalCuotas / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(dTotalCuotas,USOFACT),                  /* fnCnvDouble(dTotalCuotas,igUsoCalculo), */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i]);

                                buffer_local[_strlen(buffer_local)]=0;
                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);
                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                        default:{
                                sthTablaAcum->dCostoFacturaNeto[i] = sthTablaAcum->dCostoFacturaNeto[i] / dFact_Conversion;
                                sprintf(buffer_local,REG_1800,
                                        sthTablaAcum->iFacturable[i],
                                        sthTablaAcum->iCodGrupo[i],
                                        sthTablaAcum->szDesGrupo[i],
                                        fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[i],igUsoCalculo), */
                                        szResultado,
                                        fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[i],USOFACT),                  /* fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[i],igUsoCalculo), */
                                        fnCnvDouble(dTotalNetoImpto,USOFACT),                  /* fnCnvDouble(dTotalNetoImpto,igUsoCalculo), */
                                        sthTablaAcum->iNivelImpresion[i],
                                        sthTablaAcum->szTipUnidad[i],
                                        sthTablaAcum->szTipGrupo[i]);

                                buffer_local[_strlen(buffer_local)]=0;
                                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                                    return(FALSE);
                                memset(buffer_local,0,sizeof(buffer_local));
                                Flg_CabeceraPie = TRUE;
                                break;}
                    }
                }
            }
            iCod_GrupoAnt = sthTablaAcum->iCodGrupo[i];
        }
    }
/*
    if (Flg_CabeceraPie)
    {
        strcpy(buffer_local,REG_1999);
        buffer_local[_strlen(buffer_local)]=0;
        if (!bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local))
            return(FALSE);
        memset(buffer_local,0,sizeof(buffer_local));
    }
*/

    return(TRUE);
}/*****************************Final Put_A1800 ***********************************/



/****************************************************************************************/
/* Funcion Put_A1900                                                                    */
/*  Descripcion : Imprime registro A1900 (Registro de Detalle Facturado Nivel 2) en el  */
/*                archivo descrito por Fd_ArchImp.                                      */
/*  Entrada     : Fd_ArchImp, estructuras FaDetConsumo y sthTablaAcum                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1900 ( FILE      *Fd_ArchImp, 
		ST_TABLA_ACUM     *sthTablaAcum,  
		STSALDO_ANTERIOR  *SaldoTot, 
		ST_CUOTAS         *pstFaCuotas,  
		char              *zsBufferImpresionArchivo, 
		DETALLEOPER       *pst_MascaraOper, 
		int               esNoCiclo,     /* se agrega ind nociclo */
		ST_FACTCLIE       *FactDocuClie,/* se agrega cabecera documento */
		PROM_TRANFICOCLIE *pstPromTrafClie) 
{
    int             ix,i;
    char            szFacturaSN_KeyAcum[60];
    int             iFacturaSN_KeyAcum;
    char            szLlaveAcumulacion[60];
    ST_TABLA        sthTabla;
    int             iValor;
    char            szResultado[20];
    char            szResultadoReal[20];
    char            szResultadoDcto[20];
    double          dTotalCuotas;
    char            buffer_local[MAX_BYTE_A1900];
    int             iCod_GrupoAnt;
    BOOL            Flg_CabeceraPie;
    ST_TABLA_ORDEN  pstTablaOrden;
    long            lPosicionReal;
    double          dTotalPrimeraCateg=0.0;
    double          dTotalSegundaCateg=0.0;
    double          dTotalNetoImpto=0.0;
    double          dTotalPorcenPrimeraCateg=0.0;
    double          dTotalPorcenSegundaCateg=0.0;
    char            szLlaveAnterior[60];
    double          dValUnitario=0.0;
    BOOL            bIndEmiteCelular=FALSE;
    long            lNumVenta=0;
    char            szNumCelular [20+1];
    int 	      		iIndReg1950 = FALSE;
    double          dMontoDescConc=0.0;
    int             iIndOrdenTotal;
    int             iCodConceptoR; 
	  int             iColumnaR; 
	  long            lNumAbonadoR=0;
	  long            lCodClienteR=0;
	  int             iCodConceptoAux;
	  int             iCodTipConceAux;
	  int             iNumSecurel;
	  int             iIndOrdenAux;
    int             iCodCiclo;
    int             iCodConcepRel;
	  int             iCodConcep;
	  int             iContLeidos=0;
	  long            lNumAbonadoAux=0;
	  int             cont;
	  int             icolum;
	  char            sztablaConc[50] = "";
	  char            sztablaConcH[50]= "";
	  char            szhSqlAux[1000]= "";
	  int             iExisteCiclo;
    int             iDosAux=2; 
	 
  
    strcpy (szModulo, "	");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(&pstTablaOrden, 0, sizeof (ST_TABLA_ORDEN));
    memset(buffer_local,0,sizeof(buffer_local));
    memset(&sthTabla, 0, sizeof (ST_TABLA));

    dTotalCuotas = pstFaCuotas->dTotalCuotas_pven;

    if ( stFaDetCons.iNumReg <= 0 )
        return(TRUE);

    bfnLimpiaFlag(&pstCatImpues);

    strcpy(szLlaveAnterior,"                    ");
    iValor=0;
	
	/*Indicador de Emision de registro A1950*/
	if (BuscaMascara(pst_MascaraOper,"A1950",FactDocuClie->iCodTipDocum))
		iIndReg1950 = TRUE;		
	
    /* validacion de apertura por numero de celular (FACOVA) */
    if (esNoCiclo)
    {
    	vDTrazasLog(szModulo, "\tDocumento es no ciclo [%d][%ld] "
                            , LOG05, FactDocuClie->iCodTipDocum
                            , FactDocuClie->lNumVenta);
	/* para notas de credito de valida emision FACOVA del documento de origen */
	if ( FactDocuClie->iCodTipDocum == stDatosGener.iCodNotaCre )
	{

	
             if ( !bfnObtieneVentaRelacionada(FactDocuClie->lNumSecuRel      ,
                                              FactDocuClie->szLetraRel       ,
                                              FactDocuClie->iCodTipDocumRel  ,
                                              FactDocuClie->lCodVendedorAgRel,
                                              FactDocuClie->lCodCentrRel     ,
                                              &lNumVenta                  ) )
             {
                  vDTrazasLog(szModulo, "\t(AVISO): no se pudo obtner venta relacionada", LOG03);
                  lNumVenta=0;
             }
	}
	else 
	{
	     lNumVenta=FactDocuClie->lNumVenta;
	     vDTrazasLog(szModulo, " Asigna venta ", LOG03, szModulo);
	}
	if (lNumVenta)		
	{
	    if (bfnValidaVentaConcVarios(lNumVenta))	
	    {
		vDTrazasLog(szModulo, " Valida venta conceptos varios ", LOG03, szModulo);
		bIndEmiteCelular = TRUE;
	    }
	}
    }
    
    for ( i=0; i < stFaDetCons.iNumReg; i++ )
    {    
        if ( strncmp(stFaDetCons.stDetConsumo[i].szTip_ConcNoFact," ",1)==0 )
        {
            strcpy(szFacturaSN_KeyAcum,szCONCEP_FACTURABLE);
            iFacturaSN_KeyAcum=iCONCEP_FACTURABLE;
        }
        else
        {
            strcpy(szFacturaSN_KeyAcum,szCONCEP_NO_FACTURABLE);
            iFacturaSN_KeyAcum=iCONCEP_NO_FACTURABLE;
        }

	if ( bIndEmiteCelular) /* si emision por FACOVA se agrega agrupacion por celular */
	{
	     sprintf(szLlaveAcumulacion, "%s|%05d|%05d|%-20s|%05d|%05d|%05d",
	                                 szFacturaSN_KeyAcum,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenGr,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenSubGr,
	                                 stFaDetCons.stDetConsumo[i].szNum_Celular,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenConc,
	                                 stFaDetCons.stDetConsumo[i].iCodGrupo,
	                                 stFaDetCons.stDetConsumo[i].iCodConcepto);
	                
	     vDTrazasLog(szModulo, "\t(AVISO): venta conceptos varios llave [%s]", LOG05,szLlaveAcumulacion);
	}
	else 
	{
	     sprintf(szLlaveAcumulacion, "%s|%05d|%05d|%05d|%05d|%05d",
	                                 szFacturaSN_KeyAcum,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenGr,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenSubGr,
	                                 stFaDetCons.stDetConsumo[i].iNum_OrdenConc,
	                                 stFaDetCons.stDetConsumo[i].iCodGrupo,
	                                 stFaDetCons.stDetConsumo[i].iCodConcepto);
	}

        if ( strcmp(szLlaveAcumulacion,szLlaveAnterior)!=0 )
        {
            strcpy(szLlaveAnterior,szLlaveAcumulacion);

            if ( !bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG03);
                return(FALSE);
            }
            else
            {
                sthTablaAcum->dPorcPrimeraCategoria[iValor]  = dTotalPorcenPrimeraCateg;
                sthTablaAcum->dPorcSegundaCategoria[iValor]  = dTotalPorcenSegundaCateg;
            }
        }
        
        stFaDetCons.stDetConsumo[i].lSeg_Consumo;
        
        iValor = RetPos(szLlaveAcumulacion, &sthTabla);

        strcpy(sthTablaAcum->szKey[iValor],szLlaveAcumulacion);

        sthTablaAcum->lSegundos[iValor]           += stFaDetCons.stDetConsumo[i].lSeg_Consumo;
        sthTablaAcum->dCostoFacturaNeto[iValor]   += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
        sthTablaAcum->iUnidades[iValor]           += stFaDetCons.stDetConsumo[i].iNum_Unidades;
        sthTablaAcum->lCntLlamReal[iValor]        += stFaDetCons.stDetConsumo[i].lCntLlamReal;
        sthTablaAcum->lCntLlamDcto[iValor]        += stFaDetCons.stDetConsumo[i].lCntLlamDcto;
        sthTablaAcum->lCntLlamFAct[iValor]        += stFaDetCons.stDetConsumo[i].lCntLlamFAct;
        sthTablaAcum->lSegundosReal[iValor]       += stFaDetCons.stDetConsumo[i].lSeg_ConsumoReal;
        sthTablaAcum->lSegundosDcto[iValor]       += stFaDetCons.stDetConsumo[i].lSeg_ConsumoDcto;
        sthTablaAcum->dCostoFacturaReal[iValor]   += stFaDetCons.stDetConsumo[i].dTotalFacturableReal;
        sthTablaAcum->dCostoFacturaDcto[iValor]   += stFaDetCons.stDetConsumo[i].dTotalFacturableDcto;
        sthTablaAcum->iCodGrupo[iValor]            = stFaDetCons.stDetConsumo[i].iCodGrupo;
        sthTablaAcum->iCodConcepto[iValor]         = stFaDetCons.stDetConsumo[i].iCodConcepto;
        strcpy (sthTablaAcum->szDesGrupo[iValor]   , stFaDetCons.stDetConsumo[i].szGlosaGrupo);
        strcpy (sthTablaAcum->szDesConcepto[iValor], stFaDetCons.stDetConsumo[i].szDes_Concepto);
        strcpy(sthTablaAcum->szTipGrupo [iValor]   , stFaDetCons.stDetConsumo[i].szTipGrupo );
        strcpy(sthTablaAcum->szTipUnidad[iValor]   , stFaDetCons.stDetConsumo[i].szTipUnidad);
        sthTablaAcum->iNivelImpresion   [iValor]   = stFaDetCons.stDetConsumo[i].iNivelImpresion;
        sthTablaAcum->dImpValUnitario[iValor]     += stFaDetCons.stDetConsumo[i].dImpValUnitario;
        strcpy(sthTablaAcum->szNum_Celular[iValor], stFaDetCons.stDetConsumo[i].szNum_Celular);
        
        
        sthTablaAcum->dSumDescuentos[iValor]      += stFaDetCons.stDetConsumo[i].dSumDescuentos; /* ECU-10012 */
        sthTablaAcum->lCantDescuentos[iValor]     += stFaDetCons.stDetConsumo[i].lCantDescuentos; /* ECU-10012 */        

        if ( stFaDetCons.stDetConsumo[i].lSeg_Consumo > 0 )
        {
            sthTablaAcum->lTotalSeg  += stFaDetCons.stDetConsumo[i].lSeg_Consumo;
        }

        sthTablaAcum->iFacturable[iValor]=iFacturaSN_KeyAcum;

        if ( sthTablaAcum->iFacturable[iValor] == iCONCEP_FACTURABLE )
        {
            sthTablaAcum->dTotalCosto += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
            sthTablaAcum->iCantidad   += stFaDetCons.stDetConsumo[i].iNum_Unidades;
        }

        if ( stFaDetCons.stDetConsumo[i].iCodTipConce !=1 )
        {
            if ( !bfnTotImptosCateg(stFaDetCons.stDetConsumo[i].iCodConcepto, stFaDetCons.stDetConsumo[i].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG03);
                return(FALSE);
            }
            else
            {
                sthTablaAcum->dGravPrimeraCategoria[iValor]  += dTotalPrimeraCateg;
                sthTablaAcum->dGravSegundaCategoria[iValor]  += dTotalSegundaCateg;
            }
        }

        sprintf(szResultado,"%12.12ld",stFaDetCons.stDetConsumo[i].lSeg_Consumo); 

        vDTrazasLog(szModulo, "Put_A1900:ARREGLO DETCONSU (%s|%d|%s|%d|%s|%s|%s|%d|%15.4f|%15.4f|%10.10ld|%d|%d|%d)",
                    LOG03,
                    stFaDetCons.stDetConsumo[i].szTip_ConcNoFact,
                    stFaDetCons.stDetConsumo[i].iNum_OrdenGr,
                    stFaDetCons.stDetConsumo[i].szGlosaGrupo,
                    stFaDetCons.stDetConsumo[i].iNum_OrdenConc,
                    stFaDetCons.stDetConsumo[i].szDes_Concepto,
                    stFaDetCons.stDetConsumo[i].szTipGrupo ,
                    stFaDetCons.stDetConsumo[i].szTipUnidad,
                    stFaDetCons.stDetConsumo[i].iNivelImpresion,
                    stFaDetCons.stDetConsumo[i].dImpValUnitario,
                    stFaDetCons.stDetConsumo[i].dSumDescuentos,
                    stFaDetCons.stDetConsumo[i].lCantDescuentos,
                    stFaDetCons.stDetConsumo[i].iCodConcepto,
                    stFaDetCons.stDetConsumo[i].iColumna,
                    FactDocuClie->lIndOrdenTotal);
                    
                    
    } /* fin for */
  
  
    if ( !bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ) )
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG03);
        return(FALSE);
    }
    else
    {
        sthTablaAcum->dPorcPrimeraCategoria[iValor]  = dTotalPorcenPrimeraCateg;
        sthTablaAcum->dPorcSegundaCategoria[iValor]  = dTotalPorcenSegundaCateg;
    }

    if ( stStatus.LogNivel >= LOG06 )
    {
        for ( i=0; i<sthTabla.iLastPosition ;i++ )
        {
            vDTrazasLog(szModulo, "Put_A1900:ARREGLO CON GRUPOS ACUMULADOS(%d|%d|%s|%d|%s|%s)", LOG06,
                                  sthTablaAcum->iFacturable[i],
                                  sthTablaAcum->iCodGrupo[i],
                                  sthTablaAcum->szDesGrupo[i],
                                  sthTablaAcum->iCodConcepto[i],
                                  sthTablaAcum->szDesConcepto[i],
                                  sthTablaAcum->szNum_Celular[i]);
        }
    }

    /*------------------------------------------------------------------------------------
     ORDENA LOS CONCEPTOS YA ACUMULADOS :
    -------------------------------------------------------------------------------------*/
    
   vDTrazasLog(szModulo, " bfnOrdenaImpresionRC ", LOG03, szModulo);
    if ( !bfnOrdenaImpresionRC(sthTablaAcum, &pstTablaOrden, sthTabla.iLastPosition) )
    {
        vDTrazasLog(szModulo,"Funcion bfnOrdenaImpresionRC FALLO\n", LOG03);
        return (FALSE);
    }


    if ( stStatus.LogNivel >= LOG03 )
    {
        for ( i=0; i<sthTabla.iLastPosition ;i++ )
        {
            ix=pstTablaOrden.iSocalo[i];
            vDTrazasLog(szModulo, "Put_A1900:ARREGLO CON GRUPOS ORDENADOS key(%s)socalo(%d)(%d|%d|%s|%d|%s|%s|%s|%d|%15.4f|%s)", LOG03,
                                  pstTablaOrden.szKey[ix],
                                  ix,
                                  sthTablaAcum->iFacturable[ix],
                                  sthTablaAcum->iCodGrupo[ix],
                                  sthTablaAcum->szDesGrupo[ix],
                                  sthTablaAcum->iCodConcepto[ix],
                                  sthTablaAcum->szDesConcepto[ix],
                                  sthTablaAcum->szTipGrupo [ix],
                                  sthTablaAcum->szTipUnidad[ix],
                                  sthTablaAcum->iNivelImpresion[ix],
                                  sthTablaAcum->dImpValUnitario[ix],
                                  sthTablaAcum->szNum_Celular[ix]);
        }
    }

    /*------------------------------------------------------------------------------------
     IMPRIME LOS CONCEPTOS ACUMULADOS Y ORDENADOS FACTURABLES
    -------------------------------------------------------------------------------------*/
    iCod_GrupoAnt  = -666;
    Flg_CabeceraPie = FALSE;

    for ( i=0; i<sthTabla.iLastPosition ;i++ )
    {
        lPosicionReal = pstTablaOrden.iSocalo[i];
        if ( sthTablaAcum->iFacturable[lPosicionReal] == iCONCEP_FACTURABLE )
        {
            sprintf(szResultado,"%12.12ld",sthTablaAcum->lSegundos[lPosicionReal]);
            sprintf(szResultadoReal,"%12.12ld",sthTablaAcum->lSegundosReal[lPosicionReal]);
            sprintf(szResultadoDcto,"%12.12ld",sthTablaAcum->lSegundosDcto[lPosicionReal]);
  
            
            vDTrazasLog(szModulo, "Put_A1900:ARREGLO GRUPOS FACTURABLE (%d|%ld|%d|%s|%s|%15.4f|%d|%ld|%ld|%ld|%s|%s|%d|%15.4f|%15.4f|%10.10ld)"
                                , LOG03
                                , i 
                                , lPosicionReal
                                , sthTablaAcum->iCodGrupo[lPosicionReal]
                                , sthTablaAcum->szDesGrupo[lPosicionReal]
                                , szResultado
                                , sthTablaAcum->dCostoFacturaNeto[lPosicionReal]
                                , sthTablaAcum->iUnidades[lPosicionReal]
                                , sthTablaAcum->lCntLlamReal[lPosicionReal]
                                , sthTablaAcum->lCntLlamDcto[lPosicionReal]
                                , sthTablaAcum->lCntLlamFAct[lPosicionReal]
                                , sthTablaAcum->szTipGrupo [lPosicionReal]
                                , sthTablaAcum->szTipUnidad[lPosicionReal]
                                , sthTablaAcum->iNivelImpresion[lPosicionReal]
                                , sthTablaAcum->dImpValUnitario[lPosicionReal]
                                , sthTablaAcum->dSumDescuentos[lPosicionReal]
                                , sthTablaAcum->lCantDescuentos[lPosicionReal]);
                                

            switch ( sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                case COD_GRUPO_SALDANT:
                    if ( SaldoTot->dTotalSaldo < 0 )
                        break;
                    if ( !strcmp(szResultado,"000000000000") && SaldoTot->dTotalSaldo == 0 )
                        continue;
                    if ( BuscaMascara(pst_MascaraOper,"A1100",FactDocuClie->iCodTipDocum) )
                        continue;
                    break;
                case COD_GRUPO_CUOTA:
                    if ( dTotalCuotas < 0 )
                        break;
                    if ( !strcmp(szResultado,"000000000000") && dTotalCuotas == 0 )
                        continue;
                    break;
                default:
                    if ( sthTablaAcum->dCostoFacturaNeto[lPosicionReal] < 0 )
                        break;
                    if ( sthTablaAcum->iUnidades[lPosicionReal] < 0 )
                        break;
                    if ( !strcmp(szResultado,"000000000000") && sthTablaAcum->dCostoFacturaNeto[lPosicionReal]==0 && sthTablaAcum->iUnidades[lPosicionReal]== 0 )
                        continue;
                    break;
            }
                
            if ( iCod_GrupoAnt != sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                if ( Flg_CabeceraPie )
                {
                    strcpy(buffer_local,REG_1999);
                    buffer_local[_strlen(buffer_local)]=0;
                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                        return(FALSE);
                    memset(buffer_local,0,sizeof(buffer_local));

                    Flg_CabeceraPie = FALSE;
                    i--;
                    continue;
                }
                else
                {
                    sprintf (buffer_local,REG_1890,
                                          sthTablaAcum->iFacturable[lPosicionReal],
                                          sthTablaAcum->iCodGrupo[lPosicionReal],
                                          sthTablaAcum->szDesGrupo[lPosicionReal],
                                          sthTablaAcum->iNivelImpresion[lPosicionReal],
                                          sthTablaAcum->szTipUnidad[lPosicionReal],
                                          sthTablaAcum->szTipGrupo[lPosicionReal]);

                    buffer_local[_strlen(buffer_local)]=0;
                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                        return(FALSE);
                    memset(buffer_local,0,sizeof(buffer_local));
                    Flg_CabeceraPie = TRUE;
                }
            }

            switch ( sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                case COD_GRUPO_SALDANT:
                    {
                        SaldoTot->dTotalSaldo = SaldoTot->dTotalSaldo / FactDocuClie->dImpConversion;
                        vDTrazasLog(szModulo, "Put_A1900: Monto Final (SaldoTot->dTotalSaldo / FactDocuClie->dImpConversion) = [%f]\n", LOG03, SaldoTot->dTotalSaldo);                         
                         
                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(SaldoTot->dTotalSaldo,USOFACT),
                                szResultado,
                                0,
                                (long)0,
                                (long)0,
                                (long)0,
                                0.0,
                                0.0,
                                "",
                                "",
                                0.0,
                                "",
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                " ", /* numero de celular */
                                0.0, /* ECU-10012 */
                                0);  /* ECU-10012 */

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
                case COD_GRUPO_CUOTA:
                    {
                    
                        dTotalCuotas = dTotalCuotas / FactDocuClie->dImpConversion;
                        vDTrazasLog(szModulo, "Put_A1900: dTotalCuotas (dTotalCuotas / FactDocuClie->dImpConversion) = [%f]\n", LOG03, dTotalCuotas);

                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(dTotalCuotas,USOFACT),
                                szResultado,
                                0,
                                (long)0,
                                (long)0,
                                (long)0,
                                0.0,
                                0.0,
                                "",
                                "",
                                0.0,
                                "",
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                " ", /* numero de celular */
                                0.0, /* ECU-10012 */
                                0);  /* ECU-10012 */

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
                default:
                    {
                        sthTablaAcum->dCostoFacturaNeto[lPosicionReal] = sthTablaAcum->dCostoFacturaNeto[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dCostoFacturaReal[lPosicionReal] = sthTablaAcum->dCostoFacturaReal[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dCostoFacturaDcto[lPosicionReal] = sthTablaAcum->dCostoFacturaDcto[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dImpValUnitario  [lPosicionReal] = sthTablaAcum->dImpValUnitario  [lPosicionReal] / FactDocuClie->dImpConversion;

                        dTotalNetoImpto=sthTablaAcum->dCostoFacturaNeto[lPosicionReal] +
                                        sthTablaAcum->dGravPrimeraCategoria[lPosicionReal] +
                                        sthTablaAcum->dGravSegundaCategoria[lPosicionReal];
                         

                        if ( sthTablaAcum->iUnidades[lPosicionReal]<=0 )
                            dValUnitario= sthTablaAcum->dCostoFacturaNeto[lPosicionReal];
                        else
                            dValUnitario = sthTablaAcum->dCostoFacturaNeto[lPosicionReal]/(double)sthTablaAcum->iUnidades[lPosicionReal];
                        		                               

						if (bIndEmiteCelular)
						{
							if (atol (sthTablaAcum->szNum_Celular[lPosicionReal]) == 0)
							{
								strcpy (szNumCelular, " ");
							}
							else 
							{						
								sprintf (szNumCelular, "%20.20ld", atol(sthTablaAcum->szNum_Celular[lPosicionReal]));
							}
						}
						else 
						{
							strcpy (szNumCelular, " ");
						}             												
             /*  P-ECU-12002F2 */
                         
                    vDTrazasLog(szModulo, "CNT_AUX_3 ANTES DEL IF: POSISICION REAL CONCEPTO-COLUMNA-IMPORTE  = [%i|%i|%d|%ld]\n", LOG03, sthTablaAcum->iCodConcepto[lPosicionReal],iColumnaR,sthTablaAcum->dGravPrimeraCategoria[lPosicionReal],FactDocuClie->lCodCliente );
                   
								    /* EXEC SQL BEGIN DECLARE SECTION; */ 
        						
             	      int iIndOrdenAux2;  
             	      int iCodConceptoR2;         	
             	      float dTotalPorcPrimCat=0.0;			
             	      int iCodConcepRel2;
             	      
    								/* EXEC SQL END DECLARE SECTION; */ 

                   
                    iIndOrdenTotal=FactDocuClie->lIndOrdenTotal;
                    iCodConceptoR=sthTablaAcum->iCodConcepto[lPosicionReal];
                    iCodConceptoR2=sthTablaAcum->iCodConcepto[lPosicionReal];
                    lCodClienteR = FactDocuClie->lCodCliente;
                    dMontoDescConc=0.0;
                    iColumnaR = stFaDetCons.stDetConsumo[i].iColumna;
                    iNumSecurel=0;
                    iCodCiclo=0;
                    iIndOrdenAux=0;
                    iCodConcep=0; 
                    iCodConcepRel=0;
                    iExisteCiclo=0; 
                    iCodConcepRel2=0;

										/* EXEC SQL SELECT  I.PRC_IMPUESTO
										INTO :dTotalPorcPrimCat
										FROM   GE_IMPUESTOS I, GE_TIPIMPUES T
										WHERE  I.COD_TIPIMPUES= T.COD_TIPIMPUE
										AND  I.COD_CATIMPOS = (SELECT COD_CATIMPOS FROM GE_CATIMPCLIENTES WHERE COD_CLIENTE = :FactDocuClie->lCodCliente  AND SYSDATE BETWEEN FEC_DESDE AND  FEC_HASTA)
										AND  I.COD_TIPIMPUES in ( '2','3')
										AND  I.COD_GRPSERVI = (SELECT COD_GRPSERVI FROM FA_GRPSERCONC WHERE COD_CONCEPTO = :iCodConceptoR) 
										AND  SYSDATE BETWEEN I.FEC_DESDE AND I.FEC_HASTA; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 13;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "select I.PRC_IMPUESTO into :b0  from GE_IMPUESTOS I\
 ,GE_TIPIMPUES T where ((((I.COD_TIPIMPUES=T.COD_TIPIMPUE and I.COD_CATIMPOS=(\
select COD_CATIMPOS  from GE_CATIMPCLIENTES where (COD_CLIENTE=:b1 and SYSDATE\
 between FEC_DESDE and FEC_HASTA))) and I.COD_TIPIMPUES in ('2','3')) and I.CO\
D_GRPSERVI=(select COD_GRPSERVI  from FA_GRPSERCONC where COD_CONCEPTO=:b2)) a\
nd SYSDATE between I.FEC_DESDE and I.FEC_HASTA)";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )455;
          sqlstm.selerr = (unsigned short)1;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&dTotalPorcPrimCat;
          sqlstm.sqhstl[0] = (unsigned long )sizeof(float);
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)&(FactDocuClie->lCodCliente);
          sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (unsigned char  *)&iCodConceptoR;
          sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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



 								   if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
     								{
         							vDTrazasLog (szModulo,"Error en ejecucion de SELECT que obtiene porcentaje de impuesto  [%f]",LOG01, SQLERRM);
         							return(FALSE);
     								}
                     
                    dTotalPorcenPrimeraCateg=dTotalPorcPrimCat;                     
                    vDTrazasLog("TRAZA", "CNT: Porcentaje de Impuesto--> : [%f]",LOG03,dTotalPorcPrimCat);
                    
    								
                   if  ( FactDocuClie->iCodTipDocum == stDatosGener.iCodNotaCre )
                   {                              	
                    vDTrazasLog(szModulo, "CNT_AUX_3 Dentro del IF DE NOTA DE CREDITO   = [%i]\n", LOG03, FactDocuClie->iCodTipDocum);
                         	      
               								/* EXEC SQL SELECT NUM_SECUREL
               								INTO :iNumSecurel
               								FROM FA_FACTDOCU_NOCICLO 
               								WHERE IND_ORDENTOTAL = :iIndOrdenTotal      								
               								union
               								SELECT NUM_SECUREL	
               								FROM FA_HISTDOCU 
               								WHERE   IND_ORDENTOTAL = :iIndOrdenTotal; */ 

{
                       struct sqlexd sqlstm;
                       sqlstm.sqlvsn = 12;
                       sqlstm.arrsiz = 13;
                       sqlstm.sqladtp = &sqladt;
                       sqlstm.sqltdsp = &sqltds;
                       sqlstm.stmt = "select NUM_SECUREL into :b0  from FA_F\
ACTDOCU_NOCICLO where IND_ORDENTOTAL=:b1 union select NUM_SECUREL  from FA_HIS\
TDOCU where IND_ORDENTOTAL=:b1";
                       sqlstm.iters = (unsigned int  )1;
                       sqlstm.offset = (unsigned int  )482;
                       sqlstm.selerr = (unsigned short)1;
                       sqlstm.cud = sqlcud0;
                       sqlstm.sqlest = (unsigned char  *)&sqlca;
                       sqlstm.sqlety = (unsigned short)4352;
                       sqlstm.occurs = (unsigned int  )0;
                       sqlstm.sqhstv[0] = (unsigned char  *)&iNumSecurel;
                       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                       sqlstm.sqhsts[0] = (         int  )0;
                       sqlstm.sqindv[0] = (         short *)0;
                       sqlstm.sqinds[0] = (         int  )0;
                       sqlstm.sqharm[0] = (unsigned long )0;
                       sqlstm.sqadto[0] = (unsigned short )0;
                       sqlstm.sqtdso[0] = (unsigned short )0;
                       sqlstm.sqhstv[1] = (unsigned char  *)&iIndOrdenTotal;
                       sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                       sqlstm.sqhsts[1] = (         int  )0;
                       sqlstm.sqindv[1] = (         short *)0;
                       sqlstm.sqinds[1] = (         int  )0;
                       sqlstm.sqharm[1] = (unsigned long )0;
                       sqlstm.sqadto[1] = (unsigned short )0;
                       sqlstm.sqtdso[1] = (unsigned short )0;
                       sqlstm.sqhstv[2] = (unsigned char  *)&iIndOrdenTotal;
                       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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


          
           								    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
               								{
                   								vDTrazasLog (szModulo,"Error en ejecucion de SELECT que obtiene num_securel [%s]",LOG01, SQLERRM);
                   								return(FALSE);
               								}                                        
                              vDTrazasLog(szModulo, "CNT_AUX_3 VALOR SECUENCIA RELACIONADA  = [%i]\n", LOG06, iNumSecurel);
                              
          										/* EXEC SQL SELECT COD_CICLFACT, IND_ORDENTOTAL
          										INTO :iCodCiclo, :iIndOrdenAux
          										FROM FA_FACTDOCU_NOCICLO
          										WHERE NUM_SECUENCI = :iNumSecurel
          										AND COD_TIPDOCUM != 25
          										UNION
          										SELECT COD_CICLFACT , IND_ORDENTOTAL 
          										FROM FA_HISTDOCU
          										WHERE NUM_SECUENCI = :iNumSecurel
          										AND COD_TIPDOCUM != 25; */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 13;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.stmt = "select COD_CICLFACT ,IND_ORDENTOTAL into \
:b0,:b1  from FA_FACTDOCU_NOCICLO where (NUM_SECUENCI=:b2 and COD_TIPDOCUM<>25\
) union select COD_CICLFACT ,IND_ORDENTOTAL  from FA_HISTDOCU where (NUM_SECUE\
NCI=:b2 and COD_TIPDOCUM<>25)";
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )509;
                    sqlstm.selerr = (unsigned short)1;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)4352;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqhstv[0] = (unsigned char  *)&iCodCiclo;
                    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[0] = (         int  )0;
                    sqlstm.sqindv[0] = (         short *)0;
                    sqlstm.sqinds[0] = (         int  )0;
                    sqlstm.sqharm[0] = (unsigned long )0;
                    sqlstm.sqadto[0] = (unsigned short )0;
                    sqlstm.sqtdso[0] = (unsigned short )0;
                    sqlstm.sqhstv[1] = (unsigned char  *)&iIndOrdenAux;
                    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[1] = (         int  )0;
                    sqlstm.sqindv[1] = (         short *)0;
                    sqlstm.sqinds[1] = (         int  )0;
                    sqlstm.sqharm[1] = (unsigned long )0;
                    sqlstm.sqadto[1] = (unsigned short )0;
                    sqlstm.sqtdso[1] = (unsigned short )0;
                    sqlstm.sqhstv[2] = (unsigned char  *)&iNumSecurel;
                    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[2] = (         int  )0;
                    sqlstm.sqindv[2] = (         short *)0;
                    sqlstm.sqinds[2] = (         int  )0;
                    sqlstm.sqharm[2] = (unsigned long )0;
                    sqlstm.sqadto[2] = (unsigned short )0;
                    sqlstm.sqtdso[2] = (unsigned short )0;
                    sqlstm.sqhstv[3] = (unsigned char  *)&iNumSecurel;
                    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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


          	
           								    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
               								{
                   								vDTrazasLog (szModulo,"Error en ejecucion de SELECT que obtiene cod_ciclfact [%s]",LOG01, SQLERRM);
                   								return(FALSE);
               								}
                              vDTrazasLog(szModulo, "CNT_AUX_3 VALOR CICLO-ORDENTOTAL AUX  = [%i|%i]\n", LOG06, iCodCiclo, iIndOrdenAux);                    
           
                              iIndOrdenAux2=iIndOrdenAux;
                             
                             /* EXEC SQL SELECT COUNT(1)
                                      INTO   :iExisteCiclo
                                      FROM   FA_ENLACEHIST
                                      WHERE COD_CICLFACT = :iCodCiclo; */ 

{
                             struct sqlexd sqlstm;
                             sqlstm.sqlvsn = 12;
                             sqlstm.arrsiz = 13;
                             sqlstm.sqladtp = &sqladt;
                             sqlstm.sqltdsp = &sqltds;
                             sqlstm.stmt = "select count(1) into :b0  from F\
A_ENLACEHIST where COD_CICLFACT=:b1";
                             sqlstm.iters = (unsigned int  )1;
                             sqlstm.offset = (unsigned int  )540;
                             sqlstm.selerr = (unsigned short)1;
                             sqlstm.cud = sqlcud0;
                             sqlstm.sqlest = (unsigned char  *)&sqlca;
                             sqlstm.sqlety = (unsigned short)4352;
                             sqlstm.occurs = (unsigned int  )0;
                             sqlstm.sqhstv[0] = (unsigned char  *)&iExisteCiclo;
                             sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                             sqlstm.sqhsts[0] = (         int  )0;
                             sqlstm.sqindv[0] = (         short *)0;
                             sqlstm.sqinds[0] = (         int  )0;
                             sqlstm.sqharm[0] = (unsigned long )0;
                             sqlstm.sqadto[0] = (unsigned short )0;
                             sqlstm.sqtdso[0] = (unsigned short )0;
                             sqlstm.sqhstv[1] = (unsigned char  *)&iCodCiclo;
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

 	  
          
            							    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
               								{
                   								vDTrazasLog (szModulo,"Error en ejecucion de SELECT FA_ENLACEHIST que obtiene cod_ciclfact  [%s]",LOG01, SQLERRM);
                   								return(FALSE);
               								}
                                                                                                                         
                            cont=0;
                            icolum=0;
                            iContLeidos=0;                                                         
                            if ( iCodCiclo == 19010102 ) 
                            {                                                        
          
                              		/* EXEC SQL DECLARE Cursor_ConcRel CURSOR FOR
                               		SELECT COD_CONCEPTO, COD_CONCEREL, NUM_ABONADO
                              		FROM FA_FACTCONC_NOCICLO
                              		WHERE IND_ORDENTOTAL = :iIndOrdenAux
                                	AND   COD_CONCEREL   = :iCodConceptoR
                                	AND   COD_TIPCONCE   = 2
                                	union 
                                	SELECT COD_CONCEPTO, COD_CONCEREL, NUM_ABONADO
                                	FROM FA_HISTCONC_19010102
                                	WHERE IND_ORDENTOTAL = :iIndOrdenAux
                                	AND   COD_CONCEREL   = :iCodConceptoR
                                	AND   COD_TIPCONCE   = 2; */ 

          										
          		 								    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
              			 								{
                   										vDTrazasLog (szModulo,"Error en Declaracion del cursor Cursor_ConcRel [%s]",LOG01, SQLERRM);
                   									return(FALSE);
            												}												
          
                                   memset (&sthConcRel, 0, sizeof(sthConcRel));
          
                                   /* EXEC SQL OPEN Cursor_ConcRel; */ 

{
                                   struct sqlexd sqlstm;
                                   sqlstm.sqlvsn = 12;
                                   sqlstm.arrsiz = 13;
                                   sqlstm.sqladtp = &sqladt;
                                   sqlstm.sqltdsp = &sqltds;
                                   sqlstm.stmt = sq0016;
                                   sqlstm.iters = (unsigned int  )1;
                                   sqlstm.offset = (unsigned int  )563;
                                   sqlstm.selerr = (unsigned short)1;
                                   sqlstm.cud = sqlcud0;
                                   sqlstm.sqlest = (unsigned char  *)&sqlca;
                                   sqlstm.sqlety = (unsigned short)4352;
                                   sqlstm.occurs = (unsigned int  )0;
                                   sqlstm.sqcmod = (unsigned int )0;
                                   sqlstm.sqhstv[0] = (unsigned char  *)&iIndOrdenAux;
                                   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                                   sqlstm.sqhsts[0] = (         int  )0;
                                   sqlstm.sqindv[0] = (         short *)0;
                                   sqlstm.sqinds[0] = (         int  )0;
                                   sqlstm.sqharm[0] = (unsigned long )0;
                                   sqlstm.sqadto[0] = (unsigned short )0;
                                   sqlstm.sqtdso[0] = (unsigned short )0;
                                   sqlstm.sqhstv[1] = (unsigned char  *)&iCodConceptoR;
                                   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                                   sqlstm.sqhsts[1] = (         int  )0;
                                   sqlstm.sqindv[1] = (         short *)0;
                                   sqlstm.sqinds[1] = (         int  )0;
                                   sqlstm.sqharm[1] = (unsigned long )0;
                                   sqlstm.sqadto[1] = (unsigned short )0;
                                   sqlstm.sqtdso[1] = (unsigned short )0;
                                   sqlstm.sqhstv[2] = (unsigned char  *)&iIndOrdenAux;
                                   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                                   sqlstm.sqhsts[2] = (         int  )0;
                                   sqlstm.sqindv[2] = (         short *)0;
                                   sqlstm.sqinds[2] = (         int  )0;
                                   sqlstm.sqharm[2] = (unsigned long )0;
                                   sqlstm.sqadto[2] = (unsigned short )0;
                                   sqlstm.sqtdso[2] = (unsigned short )0;
                                   sqlstm.sqhstv[3] = (unsigned char  *)&iCodConceptoR;
                                   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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


          				 								 if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
              			 								{
                   										vDTrazasLog (szModulo,"Error en Declaracion del cursor Cursor_ConcRel [%s]",LOG01, SQLERRM);
                   										return(FALSE);
            												}
                                                                                                     
                         						/* EXEC SQL FETCH Cursor_ConcRel
                         			    	INTO	:sthConcRel; */ 

{
                               struct sqlexd sqlstm;
                               sqlstm.sqlvsn = 12;
                               sqlstm.arrsiz = 13;
                               sqlstm.sqladtp = &sqladt;
                               sqlstm.sqltdsp = &sqltds;
                               sqlstm.iters = (unsigned int  )135000;
                               sqlstm.offset = (unsigned int  )594;
                               sqlstm.selerr = (unsigned short)1;
                               sqlstm.cud = sqlcud0;
                               sqlstm.sqlest = (unsigned char  *)&sqlca;
                               sqlstm.sqlety = (unsigned short)4352;
                               sqlstm.occurs = (unsigned int  )0;
                               sqlstm.sqfoff = (         int )0;
                               sqlstm.sqfmod = (unsigned int )2;
                               sqlstm.sqhstv[0] = (unsigned char  *)&sthConcRel->iCodConcep;
                               sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                               sqlstm.sqhsts[0] = (         int  )sizeof(struct RegConcRel);
                               sqlstm.sqindv[0] = (         short *)0;
                               sqlstm.sqinds[0] = (         int  )0;
                               sqlstm.sqharm[0] = (unsigned long )0;
                               sqlstm.sqharc[0] = (unsigned long  *)0;
                               sqlstm.sqadto[0] = (unsigned short )0;
                               sqlstm.sqtdso[0] = (unsigned short )0;
                               sqlstm.sqhstv[1] = (unsigned char  *)&sthConcRel->iCodConcepRel;
                               sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                               sqlstm.sqhsts[1] = (         int  )sizeof(struct RegConcRel);
                               sqlstm.sqindv[1] = (         short *)0;
                               sqlstm.sqinds[1] = (         int  )0;
                               sqlstm.sqharm[1] = (unsigned long )0;
                               sqlstm.sqharc[1] = (unsigned long  *)0;
                               sqlstm.sqadto[1] = (unsigned short )0;
                               sqlstm.sqtdso[1] = (unsigned short )0;
                               sqlstm.sqhstv[2] = (unsigned char  *)&sthConcRel->lNumAbonadoAux;
                               sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                               sqlstm.sqhsts[2] = (         int  )sizeof(struct RegConcRel);
                               sqlstm.sqindv[2] = (         short *)0;
                               sqlstm.sqinds[2] = (         int  )0;
                               sqlstm.sqharm[2] = (unsigned long )0;
                               sqlstm.sqharc[2] = (unsigned long  *)0;
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


                         			    		
              			 							 if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
                			 								{
                    										vDTrazasLog (szModulo,"Error en Declaracion del cursor Cursor_ConcRel [%s]",LOG01, SQLERRM);
                    										return(FALSE);
            			  									}
          
                                    iContLeidos  = sqlca.sqlerrd[2];
          
                                    for ( cont = 0; cont< iContLeidos  ; cont++)
                   									{ 
                   									 	icolum= cont+1;                       
                                      vDTrazasLog(szModulo, "CNT_AUX_3 CANTIDAD REGISTROS iContLeidos-cont-columna = [%i|%i]\n", LOG03, iContLeidos,cont+1,icolum);   
          
               									      /* EXEC SQL	
                       								UPDATE FA_FACTCONC_NOCICLO SET COD_CONCEREL = :sthConcRel[cont].iCodConcepRel
                       								WHERE IND_ORDENTOTAL = :iIndOrdenTotal 
                       								AND COD_CONCEPTO     = :sthConcRel[cont].iCodConcep
                       								AND NUM_ABONADO      = :sthConcRel[cont].lNumAbonadoAux; */ 

{
                              struct sqlexd sqlstm;
                              sqlstm.sqlvsn = 12;
                              sqlstm.arrsiz = 13;
                              sqlstm.sqladtp = &sqladt;
                              sqlstm.sqltdsp = &sqltds;
                              sqlstm.stmt = "update FA_FACTCONC_NOCICLO  set\
 COD_CONCEREL=:b0 where ((IND_ORDENTOTAL=:b1 and COD_CONCEPTO=:b2) and NUM_ABO\
NADO=:b3)";
                              sqlstm.iters = (unsigned int  )1;
                              sqlstm.offset = (unsigned int  )621;
                              sqlstm.cud = sqlcud0;
                              sqlstm.sqlest = (unsigned char  *)&sqlca;
                              sqlstm.sqlety = (unsigned short)4352;
                              sqlstm.occurs = (unsigned int  )0;
                              sqlstm.sqhstv[0] = (unsigned char  *)&(sthConcRel[cont].iCodConcepRel);
                              sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                              sqlstm.sqhsts[0] = (         int  )0;
                              sqlstm.sqindv[0] = (         short *)0;
                              sqlstm.sqinds[0] = (         int  )0;
                              sqlstm.sqharm[0] = (unsigned long )0;
                              sqlstm.sqadto[0] = (unsigned short )0;
                              sqlstm.sqtdso[0] = (unsigned short )0;
                              sqlstm.sqhstv[1] = (unsigned char  *)&iIndOrdenTotal;
                              sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                              sqlstm.sqhsts[1] = (         int  )0;
                              sqlstm.sqindv[1] = (         short *)0;
                              sqlstm.sqinds[1] = (         int  )0;
                              sqlstm.sqharm[1] = (unsigned long )0;
                              sqlstm.sqadto[1] = (unsigned short )0;
                              sqlstm.sqtdso[1] = (unsigned short )0;
                              sqlstm.sqhstv[2] = (unsigned char  *)&(sthConcRel[cont].iCodConcep);
                              sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                              sqlstm.sqhsts[2] = (         int  )0;
                              sqlstm.sqindv[2] = (         short *)0;
                              sqlstm.sqinds[2] = (         int  )0;
                              sqlstm.sqharm[2] = (unsigned long )0;
                              sqlstm.sqadto[2] = (unsigned short )0;
                              sqlstm.sqtdso[2] = (unsigned short )0;
                              sqlstm.sqhstv[3] = (unsigned char  *)&(sthConcRel[cont].lNumAbonadoAux);
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


                       								                        										 	
          								 						if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
              							 					{
                   												vDTrazasLog (szModulo,"Error en update a FA_FACTCONC_NOCICLO para COD_CONREL  [%s]",LOG01, SQLERRM);
                   												return(FALSE);
            													}                       
            													/* EXEC SQL COMMIT; */ 

{
                         struct sqlexd sqlstm;
                         sqlstm.sqlvsn = 12;
                         sqlstm.arrsiz = 13;
                         sqlstm.sqladtp = &sqladt;
                         sqlstm.sqltdsp = &sqltds;
                         sqlstm.iters = (unsigned int  )1;
                         sqlstm.offset = (unsigned int  )652;
                         sqlstm.cud = sqlcud0;
                         sqlstm.sqlest = (unsigned char  *)&sqlca;
                         sqlstm.sqlety = (unsigned short)4352;
                         sqlstm.occurs = (unsigned int  )0;
                         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                                    }                                    
                               /* EXEC SQL CLOSE Cursor_ConcRel; */ 

{
                               struct sqlexd sqlstm;
                               sqlstm.sqlvsn = 12;
                               sqlstm.arrsiz = 13;
                               sqlstm.sqladtp = &sqladt;
                               sqlstm.sqltdsp = &sqltds;
                               sqlstm.iters = (unsigned int  )1;
                               sqlstm.offset = (unsigned int  )667;
                               sqlstm.cud = sqlcud0;
                               sqlstm.sqlest = (unsigned char  *)&sqlca;
                               sqlstm.sqlety = (unsigned short)4352;
                               sqlstm.occurs = (unsigned int  )0;
                               sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                               }
                               else 
                               {                                                 
                               if ( iExisteCiclo > 0 )                                	                               
                               {	                                                  
                                  sprintf(sztablaConcH,"SISCEL.FA_HISTCONC_%i",iCodCiclo);                                                        
             									    sprintf(szhSqlAux, "SELECT COD_CONCEPTO,COD_CONCEREL, NUM_ABONADO  "
             	                         "  FROM  %s "
             	                         "  WHERE IND_ORDENTOTAL = :iIndOrdenAux2  "
             	                         "  AND   COD_CONCEREL   = :iCodConceptoR2 "
             	                         "  AND   COD_TIPCONCE   = :iDosAux " ,sztablaConcH);
             	                                 	                         
                               }
                               else
                               {	
                                   sprintf(sztablaConc,"SISCEL.FA_FACTCONC_%i",iCodCiclo);                                      	
             									     sprintf(szhSqlAux, "SELECT COD_CONCEPTO,COD_CONCEREL, NUM_ABONADO \n "
             	                         "  FROM  %s \n "
             	                         "  WHERE IND_ORDENTOTAL = :iIndOrdenAux2  "
             	                         "  AND   COD_CONCEREL   = :iCodConceptoR2 "
             	                         "  AND   COD_TIPCONCE   = :iDosAux " ,sztablaConc);                                     	                         
                               }                    
                                  vDTrazasLog(szModulo, "CNT_AUX_3 Cadena SQL Select = [%s]\n", LOG03, szhSqlAux);                        
                                  vDTrazasLog(szModulo, "CNT_AUX_3 Cadena SQL Select = [%i|%i|%i]\n", LOG03, iIndOrdenAux2,iCodConceptoR2,iDosAux);                  
              
                                  memset (&sthConcRel, 0, sizeof(sthConcRel));	                               	                               	
              
             											/* EXEC SQL PREPARE sql_tabla_aux FROM :szhSqlAux; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 13;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.stmt = "";
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )682;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqhstv[0] = (unsigned char  *)szhSqlAux;
                        sqlstm.sqhstl[0] = (unsigned long )1000;
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


             		 								   if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
                 			 						 {
                      										vDTrazasLog (szModulo,"Error en PREPARE del cursor Cursor_ConcRel2 [%s]",LOG01, SQLERRM);
                        									return(FALSE);
               										 }												
             
                                 	/* EXEC SQL DECLARE Cursor_ConcRel2 CURSOR for sql_tabla_aux; */ 

             										
             		 								    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
                 			 								{
                      										vDTrazasLog (szModulo,"Error en DECLARE del cursor Cursor_ConcRel2 [%s]",LOG01, SQLERRM);
                      									return(FALSE);
               												}												
             
                                      /* EXEC SQL OPEN Cursor_ConcRel2 USING :iIndOrdenAux, :iCodConceptoR, :iDosAux; */ 

{
                                      struct sqlexd sqlstm;
                                      sqlstm.sqlvsn = 12;
                                      sqlstm.arrsiz = 13;
                                      sqlstm.sqladtp = &sqladt;
                                      sqlstm.sqltdsp = &sqltds;
                                      sqlstm.stmt = "";
                                      sqlstm.iters = (unsigned int  )1;
                                      sqlstm.offset = (unsigned int  )701;
                                      sqlstm.selerr = (unsigned short)1;
                                      sqlstm.cud = sqlcud0;
                                      sqlstm.sqlest = (unsigned char  *)&sqlca;
                                      sqlstm.sqlety = (unsigned short)4352;
                                      sqlstm.occurs = (unsigned int  )0;
                                      sqlstm.sqcmod = (unsigned int )0;
                                      sqlstm.sqhstv[0] = (unsigned char  *)&iIndOrdenAux;
                                      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                                      sqlstm.sqhsts[0] = (         int  )0;
                                      sqlstm.sqindv[0] = (         short *)0;
                                      sqlstm.sqinds[0] = (         int  )0;
                                      sqlstm.sqharm[0] = (unsigned long )0;
                                      sqlstm.sqadto[0] = (unsigned short )0;
                                      sqlstm.sqtdso[0] = (unsigned short )0;
                                      sqlstm.sqhstv[1] = (unsigned char  *)&iCodConceptoR;
                                      sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                                      sqlstm.sqhsts[1] = (         int  )0;
                                      sqlstm.sqindv[1] = (         short *)0;
                                      sqlstm.sqinds[1] = (         int  )0;
                                      sqlstm.sqharm[1] = (unsigned long )0;
                                      sqlstm.sqadto[1] = (unsigned short )0;
                                      sqlstm.sqtdso[1] = (unsigned short )0;
                                      sqlstm.sqhstv[2] = (unsigned char  *)&iDosAux;
                                      sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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


                                      
             				 								  if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
                 			 								{
                      										vDTrazasLog (szModulo,"Error en Declaracion del cursor Cursor_ConcRel2 [%s]",LOG01, SQLERRM);
                      										return(FALSE);
               												}
                                                                                                        
                            					/* EXEC SQL FETCH Cursor_ConcRel2                            			    
                            			    INTO	:sthConcRel; */ 

{
                                 struct sqlexd sqlstm;
                                 sqlstm.sqlvsn = 12;
                                 sqlstm.arrsiz = 13;
                                 sqlstm.sqladtp = &sqladt;
                                 sqlstm.sqltdsp = &sqltds;
                                 sqlstm.iters = (unsigned int  )135000;
                                 sqlstm.offset = (unsigned int  )728;
                                 sqlstm.selerr = (unsigned short)1;
                                 sqlstm.cud = sqlcud0;
                                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                                 sqlstm.sqlety = (unsigned short)4352;
                                 sqlstm.occurs = (unsigned int  )0;
                                 sqlstm.sqfoff = (         int )0;
                                 sqlstm.sqfmod = (unsigned int )2;
                                 sqlstm.sqhstv[0] = (unsigned char  *)&sthConcRel->iCodConcep;
                                 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                                 sqlstm.sqhsts[0] = (         int  )sizeof(struct RegConcRel);
                                 sqlstm.sqindv[0] = (         short *)0;
                                 sqlstm.sqinds[0] = (         int  )0;
                                 sqlstm.sqharm[0] = (unsigned long )0;
                                 sqlstm.sqharc[0] = (unsigned long  *)0;
                                 sqlstm.sqadto[0] = (unsigned short )0;
                                 sqlstm.sqtdso[0] = (unsigned short )0;
                                 sqlstm.sqhstv[1] = (unsigned char  *)&sthConcRel->iCodConcepRel;
                                 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                                 sqlstm.sqhsts[1] = (         int  )sizeof(struct RegConcRel);
                                 sqlstm.sqindv[1] = (         short *)0;
                                 sqlstm.sqinds[1] = (         int  )0;
                                 sqlstm.sqharm[1] = (unsigned long )0;
                                 sqlstm.sqharc[1] = (unsigned long  *)0;
                                 sqlstm.sqadto[1] = (unsigned short )0;
                                 sqlstm.sqtdso[1] = (unsigned short )0;
                                 sqlstm.sqhstv[2] = (unsigned char  *)&sthConcRel->lNumAbonadoAux;
                                 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                                 sqlstm.sqhsts[2] = (         int  )sizeof(struct RegConcRel);
                                 sqlstm.sqindv[2] = (         short *)0;
                                 sqlstm.sqinds[2] = (         int  )0;
                                 sqlstm.sqharm[2] = (unsigned long )0;
                                 sqlstm.sqharc[2] = (unsigned long  *)0;
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


                            			    		
                 			 							  if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
                   			 								{
                       										vDTrazasLog (szModulo,"Error en FETCH del cursor Cursor_ConcRel2 [%s]",LOG01, SQLERRM);
                       										return(FALSE);
               			  									}
             
                                       iContLeidos  = sqlca.sqlerrd[2];
                                      vDTrazasLog(szModulo, "CNT_AUX_3 CANTIDAD REGISTROS EN CURSOR = [%i] \n",LOG03,sqlca.sqlerrd[2]);
             
                                       for ( cont = 0; cont< iContLeidos  ; cont++)
                      									 { 
                      									 	 icolum= cont+1;                       
                                           vDTrazasLog(szModulo, "CNT_AUX_3 CANTIDAD REGISTROS iContLeidos-cont-columna = [%i|%i]\n", LOG03, iContLeidos,cont+1,icolum);   
                                           vDTrazasLog(szModulo, "CNT_AUX_3 CONCEPTO_REL, COD_CONCEPTO = [%i|%i|%ld|%i]\n", LOG03,
                                           sthConcRel[cont].iCodConcepRel,sthConcRel[cont].iCodConcep,sthConcRel[cont].lNumAbonadoAux,icolum);   
               									        	 /* EXEC SQL	
                       										 UPDATE FA_FACTCONC_NOCICLO SET COD_CONCEREL = :sthConcRel[cont].iCodConcepRel
                       										 WHERE IND_ORDENTOTAL = :iIndOrdenTotal 
                       										 AND COD_CONCEPTO     = :sthConcRel[cont].iCodConcep
                       										 AND NUM_ABONADO      = :sthConcRel[cont].lNumAbonadoAux; */ 

{
                                  struct sqlexd sqlstm;
                                  sqlstm.sqlvsn = 12;
                                  sqlstm.arrsiz = 13;
                                  sqlstm.sqladtp = &sqladt;
                                  sqlstm.sqltdsp = &sqltds;
                                  sqlstm.stmt = "update FA_FACTCONC_NOCICLO \
 set COD_CONCEREL=:b0 where ((IND_ORDENTOTAL=:b1 and COD_CONCEPTO=:b2) and NUM\
_ABONADO=:b3)";
                                  sqlstm.iters = (unsigned int  )1;
                                  sqlstm.offset = (unsigned int  )755;
                                  sqlstm.cud = sqlcud0;
                                  sqlstm.sqlest = (unsigned char  *)&sqlca;
                                  sqlstm.sqlety = (unsigned short)4352;
                                  sqlstm.occurs = (unsigned int  )0;
                                  sqlstm.sqhstv[0] = (unsigned char  *)&(sthConcRel[cont].iCodConcepRel);
                                  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                                  sqlstm.sqhsts[0] = (         int  )0;
                                  sqlstm.sqindv[0] = (         short *)0;
                                  sqlstm.sqinds[0] = (         int  )0;
                                  sqlstm.sqharm[0] = (unsigned long )0;
                                  sqlstm.sqadto[0] = (unsigned short )0;
                                  sqlstm.sqtdso[0] = (unsigned short )0;
                                  sqlstm.sqhstv[1] = (unsigned char  *)&iIndOrdenTotal;
                                  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                                  sqlstm.sqhsts[1] = (         int  )0;
                                  sqlstm.sqindv[1] = (         short *)0;
                                  sqlstm.sqinds[1] = (         int  )0;
                                  sqlstm.sqharm[1] = (unsigned long )0;
                                  sqlstm.sqadto[1] = (unsigned short )0;
                                  sqlstm.sqtdso[1] = (unsigned short )0;
                                  sqlstm.sqhstv[2] = (unsigned char  *)&(sthConcRel[cont].iCodConcep);
                                  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                                  sqlstm.sqhsts[2] = (         int  )0;
                                  sqlstm.sqindv[2] = (         short *)0;
                                  sqlstm.sqinds[2] = (         int  )0;
                                  sqlstm.sqharm[2] = (unsigned long )0;
                                  sqlstm.sqadto[2] = (unsigned short )0;
                                  sqlstm.sqtdso[2] = (unsigned short )0;
                                  sqlstm.sqhstv[3] = (unsigned char  *)&(sthConcRel[cont].lNumAbonadoAux);
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


                          										 	
           								 								 if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
             							 								{
                  															vDTrazasLog (szModulo,"Error en update a FA_FACTCONC_NOCICLO para COD_CONREL  [%s]",LOG01, SQLERRM);
                  															return(FALSE);
           																}
                                          /* EXEC SQL COMMIT; */ 

{
                                          struct sqlexd sqlstm;
                                          sqlstm.sqlvsn = 12;
                                          sqlstm.arrsiz = 13;
                                          sqlstm.sqladtp = &sqladt;
                                          sqlstm.sqltdsp = &sqltds;
                                          sqlstm.iters = (unsigned int  )1;
                                          sqlstm.offset = (unsigned int  )786;
                                          sqlstm.cud = sqlcud0;
                                          sqlstm.sqlest = (unsigned char  *)&sqlca;
                                          sqlstm.sqlety = (unsigned short)4352;
                                          sqlstm.occurs = (unsigned int  )0;
                                          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
                                        }                                        
                                        
                               /* EXEC SQL CLOSE Cursor_ConcRel2; */ 

{
                               struct sqlexd sqlstm;
                               sqlstm.sqlvsn = 12;
                               sqlstm.arrsiz = 13;
                               sqlstm.sqladtp = &sqladt;
                               sqlstm.sqltdsp = &sqltds;
                               sqlstm.iters = (unsigned int  )1;
                               sqlstm.offset = (unsigned int  )801;
                               sqlstm.cud = sqlcud0;
                               sqlstm.sqlest = (unsigned char  *)&sqlca;
                               sqlstm.sqlety = (unsigned short)4352;
                               sqlstm.occurs = (unsigned int  )0;
                               sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

                        	
                               }	                                    
                   } 
                             	
              /*  Aca finaliza el tratamiento de las Notas de crédito , por el error de descuento en el SRI   */                       
                  vDTrazasLog("TRAZA", "CNT: MONTO DESCUENTO ---> Valores pasados al select: [%i|%i]",LOG03,iIndOrdenTotal,iCodConceptoR);
                                                                                       
     								/* EXEC SQL SELECT NVL(SUM(IMP_FACTURABLE * -1),0) 
     								INTO :dMontoDescConc
     								FROM FA_FACTCONC_NOCICLO 
     								WHERE IND_ORDENTOTAL = :iIndOrdenTotal 
     								AND COD_CONCEREL = :iCodConceptoR
     								AND COD_TIPCONCE = 2; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 13;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "select NVL(sum((IMP_FACTURABLE* (-1))),0) into :\
b0  from FA_FACTCONC_NOCICLO where ((IND_ORDENTOTAL=:b1 and COD_CONCEREL=:b2) \
and COD_TIPCONCE=2)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )816;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (unsigned char  *)&dMontoDescConc;
             sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         short *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned long )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (unsigned char  *)&iIndOrdenTotal;
             sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         short *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned long )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (unsigned char  *)&iCodConceptoR;
             sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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


           
 								    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
     								{
         							vDTrazasLog (szModulo," Error en ejecucion de SELECT que obtiene descuento asociado a concepto [%s]",LOG01, SQLERRM);
         							return(FALSE);
     								}
 
     								if ( SQLCODE == SQLNOTFOUND )
     								{ 										
 											vDTrazasLog("TRAZA", "CNT: El select into no retorno valores -->  [%f]",LOG03,dMontoDescConc); 										
 										} 										 										                    
                    vDTrazasLog("TRAZA", "CNT: MONTO DESCUENTO PINTADO -->  [%f]",LOG03,dMontoDescConc); 
 									 										
                    /*  P-ECU-12002F2 */                               
                     
                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[lPosicionReal],USOFACT),
                                szResultado,
                                sthTablaAcum->iUnidades[lPosicionReal],
                                sthTablaAcum->lCntLlamReal[lPosicionReal],
                                sthTablaAcum->lCntLlamDcto[lPosicionReal],
                                sthTablaAcum->lCntLlamFAct[lPosicionReal],
                                fnCnvDouble(sthTablaAcum->dCostoFacturaReal[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dCostoFacturaDcto[lPosicionReal],USOFACT),
                                szResultadoReal,
                                szResultadoDcto,
                                fnCnvDouble(dValUnitario,USOFACT),
                                stFaDetCons.stDetConsumo[lPosicionReal].szGlsDescrip,
                                fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[lPosicionReal],USOFACT),
                                /*fnCnvDouble(sthTablaAcum->dPorcPrimeraCategoria[lPosicionReal],USOFACT), */
                                dTotalPorcPrimCat,
                                fnCnvDouble(sthTablaAcum->dPorcSegundaCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(dTotalNetoImpto,USOFACT),
                                szNumCelular,
                                fnCnvDouble(sthTablaAcum->dSumDescuentos[lPosicionReal],USOFACT), /* ECU-10012 */
                                sthTablaAcum->lCantDescuentos[lPosicionReal], /* ECU-10012 */
                                dMontoDescConc);  /* SChange ECU-12002-F2 */                                

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
            }
            iCod_GrupoAnt = sthTablaAcum->iCodGrupo[lPosicionReal];

			if (iIndReg1950 && fnCnvDouble(sthTablaAcum->dCostoFacturaDcto[lPosicionReal],USOFACT) != 0.0)
			{
		        if ( !Put_A1950(Fd_ArchImp, pstPromTrafClie, zsBufferImpresionArchivo, sthTablaAcum->iCodConcepto[lPosicionReal]) )
		        {
		            fnGrabaAnoProceso (FactDocuClie->lCodCliente, 0,47,"No Pudo Imprimir Registro A1950");
		            vDTrazasLog(szModulo, "Fallo Put_A1950", LOG03);
		            return(FALSE);
		        }
			}
        }
    }

    if ( Flg_CabeceraPie )
    {
        strcpy(buffer_local,REG_1999);
        buffer_local[_strlen(buffer_local)]=0;
        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
        memset(buffer_local,0,sizeof(buffer_local));
    }

    /*------------------------------------------------------------------------------------
     IMPRIME LOS CONCEPTOS ACUMULADOS Y ORDENADOS NO-FACTURABLES
    -------------------------------------------------------------------------------------*/
    iCod_GrupoAnt  = -666;
    Flg_CabeceraPie = FALSE;
    for ( i=0; i<sthTabla.iLastPosition ;i++ )
    {
        lPosicionReal = pstTablaOrden.iSocalo[i];
        if ( sthTablaAcum->iFacturable[lPosicionReal] == iCONCEP_NO_FACTURABLE )
        {
            sprintf(szResultado,"%12.12ld",sthTablaAcum->lSegundos[lPosicionReal]);
            sprintf(szResultadoReal,"%12.12ld",sthTablaAcum->lSegundosReal[lPosicionReal]);
            sprintf(szResultadoDcto,"%12.12ld",sthTablaAcum->lSegundosDcto[lPosicionReal]);

            vDTrazasLog(szModulo, "Put_A1900:ARREGLO IMPRESION DE GRUPOS NO_FACTURABLE (%d|%d|%s|%s|%15.4f|%d|%ld|%ld|%ld)", LOG03,i,
                        sthTablaAcum->iCodGrupo[lPosicionReal],
                        sthTablaAcum->szDesGrupo[lPosicionReal],
                        szResultado,
                        sthTablaAcum->dCostoFacturaNeto[lPosicionReal],
                        sthTablaAcum->iUnidades[lPosicionReal],
                        sthTablaAcum->lCntLlamReal[lPosicionReal],
                        sthTablaAcum->lCntLlamDcto[lPosicionReal],
                        sthTablaAcum->lCntLlamFAct[lPosicionReal]);

            switch ( sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                case COD_GRUPO_SALDANT:
                    if ( !strcmp(szResultado,"000000000000") && SaldoTot->dTotalSaldo == 0 )
                        continue;
                    if ( BuscaMascara(pst_MascaraOper,"A1100",FactDocuClie->iCodTipDocum))
                        continue;
                    break;
                case COD_GRUPO_CUOTA:
                    if ( !strcmp(szResultado,"000000000000") && dTotalCuotas == 0 )
                        continue;
                    break;
                default:
                    if ( !strcmp(szResultado,"000000000000") && sthTablaAcum->dCostoFacturaNeto[lPosicionReal]==0 && sthTablaAcum->iUnidades[lPosicionReal]== 0 )
                        continue;
                    break;
            }

            if ( iCod_GrupoAnt != sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                if ( Flg_CabeceraPie )
                {
                    strcpy(buffer_local,REG_1999);
                    buffer_local[_strlen(buffer_local)]=0;
                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                        return(FALSE);
                    memset(buffer_local,0,sizeof(buffer_local));

                    Flg_CabeceraPie = FALSE;
                    i--;
                    continue;
                }
                else
                {
                    sprintf (buffer_local,REG_1890,
                             sthTablaAcum->iFacturable[lPosicionReal],
                             sthTablaAcum->iCodGrupo[lPosicionReal],
                             sthTablaAcum->szDesGrupo[lPosicionReal],
                             sthTablaAcum->iNivelImpresion[lPosicionReal],
                             sthTablaAcum->szTipUnidad[lPosicionReal],
                             sthTablaAcum->szTipGrupo[lPosicionReal]);

                    buffer_local[_strlen(buffer_local)]=0;
                    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                        return(FALSE);
                    memset(buffer_local,0,sizeof(buffer_local));
                    Flg_CabeceraPie = TRUE;
                }
            }

            switch ( sthTablaAcum->iCodGrupo[lPosicionReal] )
            {
                case COD_GRUPO_SALDANT:
                    {
                        SaldoTot->dTotalSaldo = SaldoTot->dTotalSaldo / FactDocuClie->dImpConversion; /* P-TMM-03075 */

                        vDTrazasLog(szModulo, "Put_A1900: Monto Final (SaldoTot->dTotalSaldo / FactDocuClie->dImpConversion) = [%f]\n", LOG03, SaldoTot->dTotalSaldo);
                    
                       vDTrazasLog(szModulo, "CNT_AUX--> COD_GRUPO_SALDANT", LOG03);
                    
                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(SaldoTot->dTotalSaldo,USOFACT),
                                szResultado,
                                0,
                                (long)0,
                                (long)0,
                                (long)0,
                                0.0,
                                0.0,
                                "",
                                "",
                                0.0,
                                "",
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                " ", /* numero de celular */
                                0.0, /* ECU-10012 */
                                0);  /* ECU-10012 */

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
                case COD_GRUPO_CUOTA:
                    {
                        dTotalCuotas = dTotalCuotas / FactDocuClie->dImpConversion;

                        vDTrazasLog(szModulo, "Put_A1900: dTotalCuotas (dTotalCuotas / FactDocuClie->dImpConversion) = [%f]\n", LOG03, dTotalCuotas);

                        vDTrazasLog(szModulo, "CNT_AUX--> COD_GRUPO_SALDANT", LOG03);

                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(dTotalCuotas,USOFACT),
                                szResultado,
                                0,
                                (long)0,
                                (long)0,
                                (long)0,
                                0.0,
                                0.0,
                                "",
                                "",
                                0.0,
                                "",
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                0.0,
                                " ", /* numero de celular */
                                0.0, /* ECU-10012 */
                                0);  /* ECU-10012 */

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
                default:
                    {
                        sthTablaAcum->dCostoFacturaNeto[lPosicionReal] = sthTablaAcum->dCostoFacturaNeto[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dCostoFacturaReal[lPosicionReal] = sthTablaAcum->dCostoFacturaReal[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dCostoFacturaDcto[lPosicionReal] = sthTablaAcum->dCostoFacturaDcto[lPosicionReal] / FactDocuClie->dImpConversion;
                        sthTablaAcum->dImpValUnitario  [lPosicionReal] = sthTablaAcum->dImpValUnitario  [lPosicionReal] / FactDocuClie->dImpConversion;

                        dTotalNetoImpto=sthTablaAcum->dCostoFacturaNeto[lPosicionReal] +
                                        sthTablaAcum->dGravPrimeraCategoria[lPosicionReal] +
                                        sthTablaAcum->dGravSegundaCategoria[lPosicionReal];

                        if ( sthTablaAcum->iUnidades[lPosicionReal]<=0 )
                            dValUnitario = sthTablaAcum->dCostoFacturaNeto[lPosicionReal];
                        else
                            dValUnitario = sthTablaAcum->dCostoFacturaNeto[lPosicionReal]/
                                             (double)sthTablaAcum->iUnidades[lPosicionReal];

												if (bIndEmiteCelular)
												{
												    if (atol (sthTablaAcum->szNum_Celular[lPosicionReal]) == 0)
												    {
													strcpy (szNumCelular, " ");
												    }
												    else
												    { 
													sprintf (szNumCelular, "%20.20ld", atol(sthTablaAcum->szNum_Celular[lPosicionReal]));
												    }
												}
												else 
												{
												    strcpy (szNumCelular, " ");
												}
                       			
                        vDTrazasLog(szModulo, "CNT_AUX--> COD_GRUPO_SALDANT", LOG03);
			
                        sprintf(buffer_local,REG_1900,
                                sthTablaAcum->iCodConcepto[lPosicionReal],
                                sthTablaAcum->szDesConcepto[lPosicionReal],
                                fnCnvDouble(sthTablaAcum->dCostoFacturaNeto[lPosicionReal],USOFACT),
                                szResultado,
                                sthTablaAcum->iUnidades[lPosicionReal],
                                sthTablaAcum->lCntLlamReal[lPosicionReal],
                                sthTablaAcum->lCntLlamDcto[lPosicionReal],
                                sthTablaAcum->lCntLlamFAct[lPosicionReal],
                                fnCnvDouble(sthTablaAcum->dCostoFacturaReal[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dCostoFacturaDcto[lPosicionReal],USOFACT),
                                szResultadoReal,
                                szResultadoDcto,
                                fnCnvDouble(dValUnitario,USOFACT),
                                stFaDetCons.stDetConsumo[lPosicionReal].szGlsDescrip,
                                fnCnvDouble(sthTablaAcum->dGravPrimeraCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dGravSegundaCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dPorcPrimeraCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(sthTablaAcum->dPorcSegundaCategoria[lPosicionReal],USOFACT),
                                fnCnvDouble(dTotalNetoImpto,USOFACT),
                                szNumCelular,
                                fnCnvDouble(sthTablaAcum->dSumDescuentos[lPosicionReal],USOFACT), /* ECU-10012 */
                                sthTablaAcum->lCantDescuentos[lPosicionReal]); /* ECU-10012 */

                        buffer_local[_strlen(buffer_local)]=0;
                        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                            return(FALSE);
                        memset(buffer_local,0,sizeof(buffer_local));
                        break;
                    }
            }
            iCod_GrupoAnt = sthTablaAcum->iCodGrupo[lPosicionReal];
            
			if (iIndReg1950 && fnCnvDouble(sthTablaAcum->dCostoFacturaDcto[lPosicionReal],USOFACT) != 0.0)
			{
		        if ( !Put_A1950(Fd_ArchImp, pstPromTrafClie, zsBufferImpresionArchivo, sthTablaAcum->iCodConcepto[lPosicionReal]) )
		        {
		            fnGrabaAnoProceso (FactDocuClie->lCodCliente, 0,47,"No Pudo Imprimir Registro A1950");
		            vDTrazasLog(szModulo, "Fallo Put_A1950", LOG03);
		            return(FALSE);
		        }
			}
        }
    }


    if ( Flg_CabeceraPie )
    {
        strcpy(buffer_local,REG_1999);
        buffer_local[_strlen(buffer_local)]=0;
        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
        memset(buffer_local,0,sizeof(buffer_local));
    }

    return(TRUE);
}/*****************************Final Put_A1900 ***********************************/


/****************************************************************************************/
/* Funcion Put_A1960                                                                    */
/*  Descripcion : Imprime registro Put_A1960 (Numero de celular) en el  								*/
/*            archivo descrito por Fd_ArchImp.                                          */
/*  Entrada     : Fd_ArchImp, estructura FactDocuClie                                   */
/*      Salida      : Fd_ArchImp modificado                                             */
/*  Predecesor  : PutCaratula                                                           */
/****************************************************************************************/
int Put_A1960(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie, char *zsBufferImpresionArchivo)
{
    char buffer_local[MAX_BYTE_A1960];
    int  i;
    long lnum_abonado=0;
    
    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A1960");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);
                          
		for ( i=0; i < stFaDetCons.iNumReg; i++ ) {
		
			if (lnum_abonado != stFaDetCons.stDetConsumo[i].lNumAbonado) {
				if (stFaDetCons.stDetConsumo[i].lNumAbonado > 0) {
	    			sprintf(buffer_local,REG_1960, stFaDetCons.stDetConsumo[i].szNum_Celular);
	
				    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
				        return(FALSE);
				    
				    memset(buffer_local,0,sizeof(buffer_local));
				    buffer_local[_strlen(buffer_local)]=0;
	    	}
	    	lnum_abonado = stFaDetCons.stDetConsumo[i].lNumAbonado;
	    } 
		}
		
		memset(buffer_local,0,sizeof(buffer_local));
/*		strcpy(buffer_local,REG_1999);
		buffer_local[_strlen(buffer_local)]=0;
		if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
			return(FALSE);
		memset(buffer_local,0,sizeof(buffer_local)); */

		
    return(TRUE);
}/*****************************Final Put_A1960 ***********************************/ 


/****************************************************************************/
/* Funcion Put_A1950                                                        */
/*  Descripcion : Imprime registro A1950                                    */
/*                Registro Detalle promociones NIVEL2 (OPCIONAL)            */
/*  Predecesor  : Put_A1900                                               */
/****************************************************************************/
int Put_A1950(FILE *Fd_ArchImp, PROM_TRANFICOCLIE *pstPromTrafClie, char *zsBufferImpresionArchivo, int iCodCargo) /* P-TMM-03075 */
{
    char    buffer_local[MAX_BYTE_A1950];
	memset(buffer_local,0,sizeof(buffer_local));
	int iCont = 0;

	for(iCont=0;iCont<pstPromTrafClie->iNumPromClie;iCont++)
	{
		if(iCodCargo == pstPromTrafClie->stPromocionesClie[iCont].iCodCargo)
		{
    		sprintf(buffer_local, REG_1950
					    		, pstPromTrafClie->stPromocionesClie[iCont].iCodCargo
					    		, pstPromTrafClie->stPromocionesClie[iCont].szCodDcto
					    		, pstPromTrafClie->stPromocionesClie[iCont].dMtoReal     
					    		, pstPromTrafClie->stPromocionesClie[iCont].dMtoFact     
					    		, pstPromTrafClie->stPromocionesClie[iCont].dMtoDcto     
					    		, pstPromTrafClie->stPromocionesClie[iCont].lDurReal     
					    		, pstPromTrafClie->stPromocionesClie[iCont].lDurFact     
					    		, pstPromTrafClie->stPromocionesClie[iCont].lDurDcto     
					    		, pstPromTrafClie->stPromocionesClie[iCont].lCantLlamReal
					    		, pstPromTrafClie->stPromocionesClie[iCont].lCantLlamFact
					    		, pstPromTrafClie->stPromocionesClie[iCont].lCantLlamDcto);
			
			if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        		return(FALSE);
			
			break;
		}
	}
    return(TRUE);
}/*****************************Final Put_A1950 ***********************************/

/****************************************************************************/
/* Funcion Put_A2200                                                        */
/*  Descripcion : Imprime registro A2200 (Registro Total NO Facturado) en   */
/*            el archivo descrito por Fd_ArchImp.                           */
/*  Entrada     : Fd_ArchImp, estructuras SaldoTot y pstFaCuotas            */
/*      Salida      : Fd_ArchImp modificado                                 */
/*  Predecesor  : PutCaratula                                               */
/****************************************************************************/
int Put_A2200(FILE *Fd_ArchImp, STSALDO_ANTERIOR *SaldoTot, ST_CUOTAS *pstFaCuotas, char *zsBufferImpresionArchivo, double dFact_Conversion) /* P-TMM-03075 */
{
    double  dMontoAcumulado;
    char    buffer_local[MAX_BYTE_A2200];

    memset(buffer_local,0,sizeof(buffer_local));

    dMontoAcumulado =  pstFaCuotas->dTotalCuotas_venci + pstFaCuotas->dTotalCuotas_pven + SaldoTot->dTotalSaldo;
    /*-------------------------------------------------------------------------*/
    /* Se acumulan las cuotas que estan vencidas, y no Vencidas                */
    /* en la misma variable que se utiliza con el saldo anterior.              */
    /*-------------------------------------------------------------------------*/

    dMontoAcumulado = dMontoAcumulado / dFact_Conversion;

    sprintf(buffer_local,REG_2200,fnCnvDouble(dMontoAcumulado,USO0));
    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A2200 ***********************************/


/************************************************************************************/
/* Funcion Put_A2100                                                                */
/*  Descripcion : Imprime registro A2100 (Registro Total Facturado) en el archivo   */
/*            descrito por Fd_ArchImp.                                              */
/*  Entrada     : Fd_ArchImp estructura sthTablaAcum                                */
/*      Salida      : Fd_ArchImp modificado                                         */
/*  Predecesor  : PutCaratula                                                       */
/************************************************************************************/
int Put_A2100(FILE *Fd_ArchImp, ST_TABLA_ACUM sthTablaAcum, char *zsBufferImpresionArchivo, double dFact_Conversion) /* P-TMM-03075 */
{
    char szResultado[20];
    char        buffer_local[MAX_BYTE_A2100];

    memset(buffer_local,0,sizeof(buffer_local));

    sprintf(szResultado,"%12.12ld",sthTablaAcum.lTotalSeg);

    sthTablaAcum.dTotalCosto = sthTablaAcum.dTotalCosto / dFact_Conversion;

    sprintf(buffer_local,REG_2100,fnCnvDouble(sthTablaAcum.dTotalCosto,USO0),szResultado);
    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A2100 ***********************************/


/****************************************************************************/
/* Funcion Put_A2300                                                        */
/*  Descripcion : Imprime registro A2300 (Registro Mensajes Documentos no   */
/*            Ciclicos) en el archivo descrito por Fd_ArchImp.              */
/*  Entrada     : Fd_ArchImp, estructura Mensajes_NoCiclo                   */
/*      Salida      : Fd_ArchImp modificado                                 */
/*  Predecesor  : PutCaratula                                               */
/****************************************************************************/
int Put_A2300(FILE *Fd_ArchImp, ST_MENSAJES_NOCICLO *Mensajes_NoCiclo, char *zsBufferImpresionArchivo)
{
    char    buffer_local[MAX_BYTE_A2300];
    int     i;
    memset(buffer_local,0,sizeof(buffer_local));

    for ( i=0;i<Mensajes_NoCiclo->iCantLineas;i++ )
    {
        sprintf(buffer_local,REG_2300,Mensajes_NoCiclo->szMensajes[i]);

        if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            return(FALSE);
    }
    return(TRUE);
}/*****************************Final Put_A2300 ***********************************/


int Put_A2400   ( FILE *Fd_ArchImp
                  , ST_FACTCLIE *FactDocuClie
                  , STSALDO_ANTERIOR *SaldoTot
                  , ST_CUOTAS *pstFaCuotas
                  , char *zsBufferImpresionArchivo
                  , ST_BALANCE *stBalance)
{
    double  dTotalAPagar;
    double  dTotalCuotas;
    char    szMontoEscrito_Ingles [300];
    char    szMontoEscrito_Entero [150];
    char    szMontoEscrito_Decimal[70];
    char    buffer_local[MAX_BYTE_A2400];

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "Put_A2400");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    dTotalCuotas = fnCnvDouble(pstFaCuotas->dTotalCuotas_venci + pstFaCuotas->dTotalCuotas_pven, USO0);

    vDTrazasLog(szModulo, "SUMA SaldoTot->dTotalSaldo                [%ld]\n"
                          "SUMA stBalance->dMonto[iBALANCE_ANTERIOR] [%f] \n"
                          "SUMA FactDocuClie->dTotCargosMes          [%f] \n"
                          "SUMA dTotalCuotas                         [%ld]\n",LOG05,
                          SaldoTot->dTotalSaldo,
                          stBalance->dMonto[iBALANCE_ANTERIOR],
                          FactDocuClie->dTotCargosMes,
                          dTotalCuotas);

    dTotalAPagar =  fnCnvDouble(FactDocuClie->dTotCargosMes,USO0) ;

    if ( strcmp(FactDocuClie->szCod_Idioma,"1")==0 )
    {
        /* EXEC SQL
            SELECT PR_MONTO_ESCRITO.mto_escrito(:dTotalAPagar,2),
                   PR_MONTO_ESCRITO.mto_escrito(:dTotalAPagar,3)
              INTO :szMontoEscrito_Entero,
                   :szMontoEscrito_Decimal
              FROM DUAL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select PR_MONTO_ESCRITO.mto_escrito(:b0,2) ,PR_MONTO_\
ESCRITO.mto_escrito(:b0,3) into :b2,:b3  from DUAL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )843;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&dTotalAPagar;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&dTotalAPagar;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szMontoEscrito_Entero;
        sqlstm.sqhstl[2] = (unsigned long )150;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szMontoEscrito_Decimal;
        sqlstm.sqhstl[3] = (unsigned long )70;
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


	
        sprintf(buffer_local,REG_2400,szMontoEscrito_Entero,
                szMontoEscrito_Decimal,
                sthFadParametros.val_caracter[MONTO_ESCRITO_MONEDA],
                sthFadParametros.val_caracter[MONTO_ESCRITO_PREFIJO],
                sthFadParametros.val_caracter[MONTO_ESCRITO_POSFIJO]);
    }
    else
    {
        /* EXEC SQL SELECT NUMTOCHAR(:dTotalAPagar) INTO :szMontoEscrito_Ingles FROM DUAL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NUMTOCHAR(:b0) into :b1  from DUAL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )874;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&dTotalAPagar;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szMontoEscrito_Ingles;
        sqlstm.sqhstl[1] = (unsigned long )300;
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


        sprintf(buffer_local,REG_2400_Ingles,szMontoEscrito_Ingles);
    }

    if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
        return(FALSE);

    return(TRUE);
}/*****************************Final Put_A2400 ***********************************/


/******************************************************************************************************************
 * Funcion      :       Put_A2500
 * Descripcion  :       Impresion de los conceptos de cargo(3) y carrier(4) para el cliente en curso,
 *                      junto con sus series de venta y descuentos.
 * Parametros   :   ->  Fd_ArchImp
 *                          Puntero al archivo de Impresion.
 *                  ->  FactDocuClie
 *                          Puntero a estructura contenedora de datos del documento de cliente actual.
 *                  ->  sthFa_DetConsumo
 *                          Puntero a estructura contenedora de datos del detalle de consumo de cliente actual.
 *                  ->  iFlagMascaraA2600
 *                          Indicador de Impresion del registro interno A2600.
 *                  ->  iFlagMascaraA2700
 *                          Indicador de Impresion del registro interno A2600.
 *                  ->  zsBufferImpresionArchivo
 *                          Buffer contenedor de datos a imprimir a archivo.
 * Retorna          TRUE    Si la ejecucion ha sido totalmente exitosa.
 *                  FALSE   Si ha ocurrido algun problema interno en la funcion.
 *********************************************************************************************************************/
int Put_A2500(FILE *Fd_ArchImp
              , ST_FACTCLIE *FactDocuClie
              , int iFlagMascaraA2600
              , int iFlagMascaraA2700
              , char *zsBufferImpresionArchivo)
{
    register int i = 0;
    int     iPos;
    char    buffer_local[MAX_BYTE_A2500];
    double  dTotalNetoImpto       = 0.0;
    double  dGravPrimeraCategoria = 0.0;
    double  dGravSegundaCategoria = 0.0;
    double  dPorcPrimeraCategoria = 0.0;
    double  dPorcSegundaCategoria = 0.0;

    long    lDuracionReal         = 0L;
    long    lDuracionDcto         = 0L;

    strcpy (szModulo, "Put_A2500");

    /* Recorrer la estructura de detalle de consumo */
    for ( i=0; i < stOrden2DetConsumo.iNumRegs; i++ ) /* Se utiliza estructura de orden alterno */
    {
        iPos = stOrden2DetConsumo.stOrden[i].iPosicion; /* posicion en la estructura de consumo */

        /* Imprimir todos los codigos de tipo 3 (cargo) y 4 (carrier) */
        if ( stFaDetCons.stDetConsumo[iPos].iCodTipConce == 3 || stFaDetCons.stDetConsumo[iPos].iCodTipConce == 4 )
        {

            if ( !bfnTotImptosCateg(stFaDetCons.stDetConsumo[iPos].iCodConcepto, stFaDetCons.stDetConsumo[iPos].iColumna,&dGravPrimeraCategoria, &dGravSegundaCategoria ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
                return(FALSE);
            }

            dPorcPrimeraCategoria=0.0;
            dPorcSegundaCategoria=0.0;

            if ( !bfnPorcenImptosCateg(&dPorcPrimeraCategoria, &dPorcSegundaCategoria ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
                return(FALSE);
            }

            dTotalNetoImpto=0.0;
            dTotalNetoImpto = stFaDetCons.stDetConsumo[iPos].dTotalFacturableNet + dGravPrimeraCategoria + dGravSegundaCategoria;

            lDuracionReal = (stFaDetCons.stDetConsumo[iPos].lSeg_ConsumoReal)<0?0L:stFaDetCons.stDetConsumo[iPos].lSeg_ConsumoReal;
            lDuracionDcto = (stFaDetCons.stDetConsumo[iPos].lSeg_ConsumoDcto)<0?0L:stFaDetCons.stDetConsumo[iPos].lSeg_ConsumoDcto;

            /* Imprimir el concepto */
            sprintf(buffer_local,REG_2500,
                    stFaDetCons.stDetConsumo[iPos].iCodConcepto,
                    stFaDetCons.stDetConsumo[iPos].szDes_Concepto,
                    fnCnvDouble(stFaDetCons.stDetConsumo[iPos].dTotalFacturableNet,USOFACT),
                    stFaDetCons.stDetConsumo[iPos].lSeg_Consumo,                   /* szResultado */
                    stFaDetCons.stDetConsumo[iPos].iNum_Unidades,
                    stFaDetCons.stDetConsumo[iPos].lCntLlamReal,
                    stFaDetCons.stDetConsumo[iPos].lCntLlamDcto,
                    stFaDetCons.stDetConsumo[iPos].lCntLlamFAct,
                    fnCnvDouble(stFaDetCons.stDetConsumo[iPos].dTotalFacturableReal,USOFACT),
                    fnCnvDouble(stFaDetCons.stDetConsumo[iPos].dTotalFacturableDcto,USOFACT),
                    lDuracionReal,                                       /* szResultadoReal */
                    lDuracionDcto,                                       /* szResultadoDcto */
                    fnCnvDouble(stFaDetCons.stDetConsumo[iPos].dImpValUnitario,USOFACT),
                    stFaDetCons.stDetConsumo[iPos].szGlsDescrip,
                    fnCnvDouble(dGravPrimeraCategoria,USOFACT),
                    fnCnvDouble(dGravSegundaCategoria,USOFACT),
                    fnCnvDouble(dPorcPrimeraCategoria,USOFACT),
                    fnCnvDouble(dPorcSegundaCategoria,USOFACT),
                    fnCnvDouble(dTotalNetoImpto,USOFACT));

            buffer_local[_strlen(buffer_local)] = 0;
            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                return(FALSE);
            memset(buffer_local,0,sizeof(buffer_local));

            vDTrazasLog(szModulo, "(Put_A2500) stFaDetCons.stDetConsumo[%d].lNumVenta     : [%ld]"
                                  "\n(Put_A2500) stFaDetCons.stDetConsumo[%d].szDes_Concepto: [%s]"
                                  "\n(Put_A2500) stFaDetCons.stDetConsumo[%d].iCodConcepto  : [%d]"
                                  , LOG05,i,stFaDetCons.stDetConsumo[iPos].lNumVenta
                                  , i,stFaDetCons.stDetConsumo[iPos].szDes_Concepto
                                  , i,stFaDetCons.stDetConsumo[iPos].iCodConcepto);
            if ( iFlagMascaraA2600 )
            {
                if ( !Put_A2600(Fd_ArchImp,FactDocuClie,stFaDetCons.stDetConsumo[iPos].lNumVenta,stFaDetCons.stDetConsumo[iPos].iCodConcepto,stFaDetCons.stDetConsumo[iPos].lNumAbonado,stFaDetCons.stDetConsumo[iPos].szDes_Concepto,stFaDetCons.stDetConsumo[iPos].iColumna,zsBufferImpresionArchivo) )
                    vDTrazasLog(szModulo, "Fallo Put_A2600", LOG05);
            }
            if ( iFlagMascaraA2700)
            {
                if ( !Put_A2700(Fd_ArchImp, FactDocuClie, stFaDetCons.stDetConsumo[iPos].iCodConcepto,stFaDetCons.stDetConsumo[iPos].iColumna,zsBufferImpresionArchivo) )
                    vDTrazasLog(szModulo, "Fallo Put_A2700", LOG05);
            }
        } /* if(stFaDetCons.stDetConsumo[iPos].iCodTipConce == 3 || stFaDetCons.stDetConsumo[iPos].iCodTipConce == 4) */
    } /* for (i=0; i < sthFa_DetConsumo->CantidadConceptos; i++ ) */
    return (TRUE);
}


/*
 * Funcion      :       Put_A2600
 * Descripcion  :       Impresion de las series de venta asociadas al cliente actual y a la venta ingresada
 *                      por paramentro
 * Parametros   :   ->  Fd_ArchImp
 *                          Puntero al archivo de Impresion.
 *                  ->  FactDocuClie
 *                          Puntero a estructura contenedora de datos del documento de cliente actual.
 *                  ->  lNumVenta
 *                          Numero de venta a buscar.
 *                  ->  zsBufferImpresionArchivo
 *                          Buffer contenedor de datos a imprimir a archivo.
 * Retorna          TRUE    Si la ejecucion ha sido totalmente exitosa.
 *                  FALSE   Si ha ocurrido algun problema interno en la funcion.
 */
/* SE AGREGA int  iCodConcepto a la fx por XO-200510280974*/
int Put_A2600(FILE *Fd_ArchImp
              , ST_FACTCLIE *FactDocuClie
              , long lNumVenta
              , int  iCodConcepto
              , long lNumAbonado
              , char *pszDesConcepto
              , long lColumna
              , char *zsBufferImpresionArchivo)
{
    int     iControlFunciones = 0;
    char    buffer_local[MAX_BYTE_A2600];
    reg_entrada stEntrada;
    stSalida *pstAux = NULL;
    stSalida *pstAux2 = NULL;
    long lNumVentaAux = 0;

    strcpy (szModulo, "Put_A2600");

    vDTrazasLog(szModulo, "(INFO) ******** Entrando  a la funcion [%s] **********"
                          "\n Codigo Cliente  : [%ld]"
                          "\n Num. Venta      : [%ld]"
                          "\n Cod. Tip Docum. : [%d]"
                          ,LOG05
                          ,szModulo
                          ,FactDocuClie->lCodCliente
                          ,lNumVenta
                          ,FactDocuClie->iCodTipDocum);

    /* Evaluar si el documento es movimiento miscelaneo */
    vDTrazasLog(szModulo, "\t(INFO): stDatosGener.iCodMiscela: [%d] ", LOG05, stDatosGener.iCodMiscela);

    if ( (bfnEsMovMiscelaneo(FactDocuClie->iCodTipDocum, stDatosGener.iCodMiscela) == TRUE ) )
    {
        /* Cargar los datos necesarios para obtencion de datos para factura miscelanea */
        stEntrada.lNumProceso  = FactDocuClie->lNumProceso;
        stEntrada.lCodConcepto = iCodConcepto;
        stEntrada.iColumna     = lColumna;

        if ( pszDesConcepto!=NULL )
            strcpy(stEntrada.szDesConcepto, pszDesConcepto);
        else
            strcpy(stEntrada.szDesConcepto, "");

        ifnObtenerSeriesFactMiscela(&stEntrada);
    }
    else
    {   /* Si el concepto es de venta */
        vDTrazasLog(szModulo, "\t(INFO): VENTA [%ld] ", LOG05, lNumVenta);
        if ( lNumVenta > 0 )
        {

            vDTrazasLog(szModulo, "\t(INFO): TIPO DOCUMENTO [%d] NOTA DE CREDITO [%d]"
                                , LOG05
                                , FactDocuClie->iCodTipDocum
                                , stDatosGener.iCodNotaCre);

            if ( FactDocuClie->iCodTipDocum != stDatosGener.iCodNotaCre )
            {
                /* Cargar la estructura de entrada de la funcion */
                stEntrada.lCodCliente  = FactDocuClie->lCodCliente;
                stEntrada.lNumVenta    = lNumVenta;
                stEntrada.lNumProceso  = FactDocuClie->lNumProceso;
                strcpy(stEntrada.szTipoDocum,"F");

                lstSalida = NULL;
                /* Llamado a la funcion de llenado de la lista de series de venta */
                /* INICIO 76441 CJG */
                /*iControlFunciones = ifnLlenarSeriesDeVenta ( &stEntrada );*/
                iControlFunciones = ifnLlenarSeriesDeVenta ( &stEntrada,iCodConcepto );

                /* FIN 76441 CJG */

                vDTrazasLog(szModulo, "\t(INFO): iControlFunciones: [%d] "
                                    , LOG05
                                    , iControlFunciones);

                if ( !iControlFunciones )
                {
                    vDTrazasLog(szModulo, "\t(ERROR): En la funcion ifnLlenarSeriesDeVenta ", LOG05);
                    return (FALSE);
                }
            }
            else /* Corresponde a una Nota de Cr‰dito */
            {
                if ( bfnObtieneVentaRelacionada(FactDocuClie->lNumSecuRel      ,
                                                FactDocuClie->szLetraRel       ,
                                                FactDocuClie->iCodTipDocumRel  ,
                                                FactDocuClie->lCodVendedorAgRel,
                                                FactDocuClie->lCodCentrRel     ,
                                                &lNumVentaAux                  )==FALSE )
                {
                    vDTrazasLog(szModulo, "\t(AVISO): En la funcion bfnObtieneVentaRelacionada ", LOG05);
                    lNumVenta=0;
                }
                vDTrazasLog(szModulo, "\t(INFO): VENTA AUXILIAR[%ld]\n"
                                    , LOG05
                                    , lNumVentaAux);

                if ( lNumVentaAux > 0 )
                {
                    /* Cargar la estructura de entrada de la funcion */
                    stEntrada.lCodCliente  = FactDocuClie->lCodCliente;
                    stEntrada.lNumVenta    = lNumVentaAux;
                    stEntrada.lNumProceso  = FactDocuClie->lNumProceso;
                    strcpy(stEntrada.szTipoDocum,"N");

                    lstSalida = NULL;
                    iControlFunciones = ifnLlenarSeriesDeVenta ( &stEntrada,iCodConcepto );

                    vDTrazasLog(szModulo, "\t(INFO): iControlFunciones: [%d] "
                                        , LOG05
                                        , iControlFunciones);
                    if ( !iControlFunciones )
                    {
                        vDTrazasLog(szModulo, "\t(ERROR): En la funcion ifnLlenarSeriesDeVenta "
                                            , LOG05);
                        return (FALSE);
                    }
                }
            }
        }
    }

    /* Imprimir la lista enlazada <lstSalida> */
    pstAux = lstSalida;

    if ( lstSalida==NULL )
        vDTrazasLog(szModulo, "\t(Put_A2600) lstSalida es NULL... "
                            , LOG05);

    while ( lstSalida!=NULL )
    {
        vDTrazasLog(szModulo, "\n\tDentro de while A2600... "
                              "\n\t A2600==>lstSalida->lCodConcepto (%ld) "
                              "\n\t A2600==>iCodConcepto (%d) "
                              "\n\t A2600 lstSalida->lNumAbonado (%ld) "
                              "\n\t A2600 lNumAbonado (%ld) "
                            , LOG05
                            , lstSalida->lCodConcepto
                            , iCodConcepto
                            , lstSalida->lNumAbonado
                            , lNumAbonado);

        /*se agrega num_abonado XO-*974*/
        if ( lNumAbonado>0 )
        {
            if ( (iCodConcepto==(int)(lstSalida->lCodConcepto))&&(lstSalida->lNumAbonado==lNumAbonado) )/* SE AGREGA if por XO-200510280974*/
            {
                sprintf(buffer_local,REG_2600
                        ,lstSalida->lCodConcepto
                        ,lstSalida->szDesConcepto
                        ,lstSalida->szNumSerie
                        ,lstSalida->lNumCelular);

                vDTrazasLog(szModulo, "\n\tDentro if A2600... "
                                      "\n\t A2600==>iCodConcepto (%d) "
                                      "\n\t A2600 lstSalida->lCodConcepto (%ld) "
                                      "\n\t A2600 lstSalida->szNumSerie (%s) "
                                      "\n\t A2600 lstSalida->lNumAbonado (%ld) "
                                      "\n\t A2600 lNumAbonado (%ld) "
                                    , LOG05
                                    , iCodConcepto
                                    , lstSalida->lCodConcepto
                                    , lstSalida->szNumSerie
                                    , lstSalida->lNumAbonado
                                    , lNumAbonado);

                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                    return (FALSE);
            }
            /*INICIO 76441 CJG*/
        }
        else /**Si no viene abonado >0 dejo consulta anterior, solo por concepto XO-*974*/
        {
            if ( (iCodConcepto==(int)(lstSalida->lCodConcepto)) )
            {
                sprintf(buffer_local,REG_2600
                        ,lstSalida->lCodConcepto
                        ,lstSalida->szDesConcepto
                        ,lstSalida->szNumSerie
                        ,lstSalida->lNumCelular);

                vDTrazasLog(szModulo, "\n\tDentro if else A2600... "
                                      "\n\t A2600==>iCodConcepto (%d) "
                                      "\n\t A2600 lstSalida->lCodConcepto (%ld) "
                                      "\n\t A2600 lstSalida->szNumSerie (%s) "
                                      "\n\t A2600 lstSalida->lNumAbonado (%ld) "
                                      "\n\t A2600 lNumAbonado (%ld) "
                                    , LOG05
                                    , iCodConcepto
                                    , lstSalida->lCodConcepto
                                    , lstSalida->szNumSerie
                                    , lstSalida->lNumAbonado
                                    , lNumAbonado);

                if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
                    return (FALSE);
            }
        }
        /* Vamos al proximo nodo */
        lstSalida = lstSalida->sgte;
    }

    /* Liberar la memoria obtenida */
    while ( pstAux!=NULL )
    {
        pstAux2= pstAux;
        pstAux = pstAux->sgte;
        free(pstAux2);
    }

    return (TRUE);
}


/*
 * Funcion      :       Put_A2700
 * Descripcion  :       Impresion de los conceptos de descuento asociados al concepto de cargo ingresado
 *                      por paramentro.
 * Parametros   :   ->  Fd_ArchImp
 *                          Puntero al archivo de Impresion.
 *                  ->  FactDocuClie
 *                          Puntero a estructura contenedora de datos del documento de cliente actual.
 *                  ->  sthFa_DetConsumo
 *                          Puntero a estructura contenedora de datos del detalle de consumo de cliente actual.
 *                  ->  iCodConcepto
 *                          Codigo de concepto de cargo.
 *                  ->  iColumna
 *                          Columna del concepto de cargo.
 *                  ->  zsBufferImpresionArchivo
 *                          Buffer contenedor de datos a imprimir a archivo.
 * Retorna          TRUE    Si la ejecucion ha sido totalmente exitosa.
 *                  FALSE   Si ha ocurrido algun problema interno en la funcion.
 */
int Put_A2700(FILE *Fd_ArchImp
              , ST_FACTCLIE *FactDocuClie
              , int iCodConcepto
              , int iColumna
              , char *zsBufferImpresionArchivo)
{
    char    buffer_local[MAX_BYTE_A2700];
    int     i=0;
    double  dTotalNetoImpto       = 0.0;
    double  dGravPrimeraCategoria = 0.0;
    double  dGravSegundaCategoria = 0.0;
    double  dPorcPrimeraCategoria = 0.0;
    double  dPorcSegundaCategoria = 0.0;


    strcpy (szModulo, "Put_A2700");
    vDTrazasLog(szModulo, "(INFO) ******** Entrando  a la funcion [%s] **********", LOG05, szModulo);

    /* Recorrer la estructura de consumo en busqueda de conceptos de dcto. relacionados */
    for ( i=0;i < stFaDetCons.iNumReg;i++ )
    {
        if ( stFaDetCons.stDetConsumo[i].iCodConcerel == iCodConcepto && stFaDetCons.stDetConsumo[i].iColumnaRel == iColumna
             && stFaDetCons.stDetConsumo[i].iCodTipConce == 2 )
        {
            vDTrazasLog(szModulo, "\tDentro de if:... ", LOG06);
            /* Imprimir los conceptos de descuento */
            if ( !bfnTotImptosCateg(stFaDetCons.stDetConsumo[i].iCodConcepto, stFaDetCons.stDetConsumo[i].iColumna, &dGravPrimeraCategoria, &dGravSegundaCategoria ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
                return(FALSE);
            }

            if ( !bfnPorcenImptosCateg(&dPorcPrimeraCategoria, &dPorcSegundaCategoria ) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
                return(FALSE);
            }

            dTotalNetoImpto = stFaDetCons.stDetConsumo[i].dTotalFacturableNet + dGravPrimeraCategoria + dGravSegundaCategoria;

            /* Imprimir el concepto */
            sprintf(buffer_local,REG_2700,
                    stFaDetCons.stDetConsumo[i].iCodConcepto,
                    stFaDetCons.stDetConsumo[i].szDes_Concepto,
                    fnCnvDouble(stFaDetCons.stDetConsumo[i].dTotalFacturableNet,USOFACT),
                    stFaDetCons.stDetConsumo[i].lSeg_Consumo,
                    stFaDetCons.stDetConsumo[i].iNum_Unidades,
                    stFaDetCons.stDetConsumo[i].lCntLlamReal,
                    stFaDetCons.stDetConsumo[i].lCntLlamDcto,
                    stFaDetCons.stDetConsumo[i].lCntLlamFAct,
                    fnCnvDouble(stFaDetCons.stDetConsumo[i].dTotalFacturableReal,USOFACT),
                    fnCnvDouble(stFaDetCons.stDetConsumo[i].dTotalFacturableDcto,USOFACT),
                    stFaDetCons.stDetConsumo[i].lSeg_ConsumoReal,
                    stFaDetCons.stDetConsumo[i].lSeg_ConsumoDcto,
                    fnCnvDouble(stFaDetCons.stDetConsumo[i].dImpValUnitario ,USOFACT),
                    stFaDetCons.stDetConsumo[i].szGlsDescrip,
                    fnCnvDouble(dGravPrimeraCategoria,USOFACT),
                    fnCnvDouble(dGravSegundaCategoria,USOFACT),
                    fnCnvDouble(dPorcPrimeraCategoria,USOFACT),
                    fnCnvDouble(dPorcSegundaCategoria,USOFACT),
                    fnCnvDouble(dTotalNetoImpto,USOFACT));

            buffer_local[_strlen(buffer_local)] = 0;
            if ( !bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local) )
            {
                vDTrazasLog(szModulo, "\tError en regreso de funcion bEscribeEnArchivo ", LOG05);
                return(FALSE);
            }

            memset(buffer_local,0,sizeof(buffer_local));
        }
        else
        {
            vDTrazasLog(szModulo, "\tCondicion de ingreso a if no se cumple. ", LOG06);
        }
    }
    return (TRUE);
}

/****************************************************************************************/
/* Funcion Put_A2800                                                                    */
/****************************************************************************************/
int Put_A2800(FILE *Fd_ArchImp,ST_FACTCLIE *FactDocuClie,DET_TRANSACCIONES *pstDetTrans, char *zsBufferImpresionArchivo)
{
    char    buffer_local[MAX_BYTE_A2800];
    int 	iIdx;
    TIPDOC  stTipDoc;
    double  dTotalPaso = 0.0; /* Inc 139614 PPV 02/07/2010 */ 
    
    memset(buffer_local,0,sizeof(buffer_local));
    strcpy (szModulo, "Put_A2800");

    vDTrazasLog(szModulo, "\tEntro a %s "
                          "\tCant Registros [%d]"
                        , LOG05,szModulo,pstDetTrans->stMovimClie.iNumRegResMov);

    for(iIdx=0;iIdx<pstDetTrans->stMovimClie.iNumRegResMov;iIdx++)
    {
        if (!bfnFindTipDocum (pstDetTrans->stMovimClie.stResMovimClie[iIdx].iCodTipDocum, &stTipDoc))
            return FALSE;

		/* Inc 139614 PPV 02/07/2010 se incorpora traza para monitorear redondeo */
		vDTrazasLog(szModulo, "\t Traza PPV monto antes               [%015.4f] "
	    				      "\t Traza PPV monto en proceso USOFACT  [%015.4f] "
	                          "\t Traza PPV monto en proceso USO0     [%015.4f] "
	    					  , LOG05,szModulo,pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura
	    					  ,fnCnvDouble(pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura,USOFACT)
	    					  ,fnCnvDouble(pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura,USO0));
	    dTotalPaso = 0.0;
	    dTotalPaso = fnCnvDouble(pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura,USOFACT);
	    vDTrazasLog(szModulo, "\t Traza PPV monto en trnsformado con USOFACT  [%015.4f] ", LOG05,dTotalPaso);
	    dTotalPaso = 0.0;
	    dTotalPaso = fnCnvDouble(pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura,USO0);
	    vDTrazasLog(szModulo, "\t Traza PPV monto en trnsformado con USO0     [%015.4f] ", LOG05,dTotalPaso);

        sprintf(buffer_local,"A2800%-5.5s%-3.3s%5.5d%-40.40s%-10.10s%15.15ld%-8.8s%015.4f%15.15ld%-15.15s\n\0"
                            ,FactDocuClie->szCodOperadora
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].szCodOficina
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].iCodTipDocum
                            ,stTipDoc.szDesTipDocum
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].szCodPlaza
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].lNumFolio
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].szFecTrans
                            /* ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].dTotalFactura */
                            ,dTotalPaso
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].lNumFolioRel
                            ,pstDetTrans->stMovimClie.stResMovimClie[iIdx].szPrefPlazaRel);

        if (!bEscribeEnArchivo(Fd_ArchImp, zsBufferImpresionArchivo, buffer_local))
            return(FALSE);
    }
    return(TRUE);
}/*****************************Final Put_A2800 ***********************************/

int PutCaratula(ST_FACTCLIE         *FactDocuClie,
                FILE                *Fd_ArchImp,
                ST_MENSAJES         *Mensajes,
                ST_MENSAJES_NOCICLO *Mensajes_NoCiclo,
                STSALDO_ANTERIOR    *SaldoTot,
                ST_CUOTAS           *pstFaCuotas,
                ST_CICLOFACT        *sthFa_CicloFact,
                DETALLEOPER         *pst_MascaraOper,
                char                *zsBufferImpresionArchivo,
                ST_BALANCE          *stBalance,
                DET_TRANSACCIONES   *pstDetTrans,
                PROM_TRANFICOCLIE   *pstPromTrafClie,
                long                lCodigoCicloFacturacion,
                int                 esCiclo)
{
    ST_TABLA_ACUM   sthTablaAcum;
    int             i;
    struct timeb    tpi;
    int             iFlagCargaTrans=FALSE;

    strcpy (szModulo, "PutCaratula");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(stBalance, 0, sizeof (ST_BALANCE));
    memset(&sthTablaAcum, 0, sizeof (ST_TABLA_ACUM));


    if (BuscaMascara(pst_MascaraOper,"A2800",FactDocuClie->iCodTipDocum) > 0 ||
        BuscaMascara(pst_MascaraOper,"B5000",FactDocuClie->iCodTipDocum) > 0 ||
        BuscaMascara(pst_MascaraOper,"B5010",FactDocuClie->iCodTipDocum) > 0 ||
        BuscaMascara(pst_MascaraOper,"B5020",FactDocuClie->iCodTipDocum) > 0 ||
        BuscaMascara(pst_MascaraOper,"B5030",FactDocuClie->iCodTipDocum) > 0 ||
        BuscaMascara(pst_MascaraOper,"B5040",FactDocuClie->iCodTipDocum) > 0 )
            iFlagCargaTrans=TRUE;

    if(iFlagCargaTrans && !esCiclo)
    {
        /*-----------------------------------------------------------------------------
                        CARGA DETALLE DE TRANSACCIONES DEL CLIENTE
        -----------------------------------------------------------------------------*/
        if (!bfnCargaDetTransClie(pstDetTrans, sthFa_CicloFact,FactDocuClie->lCodCliente, FactDocuClie->lNumProceso, lCodigoCicloFacturacion))
        {
            vDTrazasLog(szModulo, "Error en ejecucion de bfnCargaDetTransClie", LOG01);
            return(FALSE);
        }
    }


    if ( BuscaMascara(pst_MascaraOper,"A1000", FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1000= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1000(Fd_ArchImp, FactDocuClie, sthFa_CicloFact, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,30,"No Pudo Imprimir Registro A1000");
            vDTrazasLog(szModulo, "Fallo Put_A1000", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1000= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1120",FactDocuClie->iCodTipDocum)
    	&& sthFa_CicloFact->cod_ciclo > 0 )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1120= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1120(Fd_ArchImp, FactDocuClie, sthFa_CicloFact, zsBufferImpresionArchivo, lCodigoCicloFacturacion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,31,"No Pudo Imprimir Registro A1120");
            vDTrazasLog(szModulo, "Fallo Put_A1120", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1120= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1130",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1130= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1130(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,32,"No Pudo Imprimir Registro A1130");
            vDTrazasLog(szModulo, "Fallo Put_A1130", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1130= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1150",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1150= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1150(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo, lCodigoCicloFacturacion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,33,"No Pudo Imprimir Registro A1150");
            vDTrazasLog(szModulo, "Fallo Put_A1150", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1150= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1010",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1010= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1010(Fd_ArchImp,FactDocuClie, zsBufferImpresionArchivo, lCodigoCicloFacturacion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,34,"No Pudo Imprimir Registro A1010");
            vDTrazasLog(szModulo, "Fallo Put_A1010", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1010= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1100",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1100= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1100(Fd_ArchImp, FactDocuClie, SaldoTot, pstFaCuotas, zsBufferImpresionArchivo, stBalance) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,35,"No Pudo Imprimir Registro A1100");
            vDTrazasLog(szModulo, "Fallo Put_A1100", LOG01);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1100= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    vDTrazasLog("", "stBalance->dMonto[iBALANCE_ANTERIOR] en PutCaratula [%f] ", LOG05, stBalance->dMonto[iBALANCE_ANTERIOR]);

    if ( BuscaMascara(pst_MascaraOper,"A1200",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1200= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1200(Fd_ArchImp, FactDocuClie, SaldoTot, pstFaCuotas, zsBufferImpresionArchivo, stBalance) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,36,"No Pudo Imprimir Registro A1200");
            vDTrazasLog(szModulo, "Fallo Put_A1200", LOG01);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1200= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1250",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1250= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1250(Fd_ArchImp, pstFaCuotas, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,37,"No Pudo Imprimir Registro A1250");
            vDTrazasLog(szModulo, "Fallo Put_A1250", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1250= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1300",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1300= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1300(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,38,"No Pudo Imprimir Registro A1300");
            vDTrazasLog(szModulo, "Fallo Put_A1300", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1300= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1400",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1400= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1400(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,39,"No Pudo Imprimir Registro A1400");
            vDTrazasLog(szModulo, "Fallo Put_A1400", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1400= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1410",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1410= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1410(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,40,"No Pudo Imprimir Registro A1410");
            vDTrazasLog(szModulo, "Fallo Put_A1410", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1410= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1420",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1420= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1420(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,41,"No Pudo Imprimir Registro A1420");
            vDTrazasLog(szModulo, "Fallo Put_A1420", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1420= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1430",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1430= %ld.%d",LOG03, tpi.time,tpi.millitm);


        if ( !Put_A1430(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,42,"No Pudo Imprimir Registro A1430");
            vDTrazasLog(szModulo, "Fallo Put_A1430", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1430= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1500",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1500= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1500(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,43,"No Pudo Imprimir Registro A1500");
            vDTrazasLog(szModulo, "Fallo Put_A1500", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1500= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1700",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1700= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1700(Fd_ArchImp, FactDocuClie->lCodCliente, sthFa_CicloFact, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,44,"No Pudo Imprimir Registro A1700");
            vDTrazasLog(szModulo, "Fallo Put_A1700", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1700= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A2000",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2000= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2000(Fd_ArchImp, Mensajes, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,45,"No Pudo Imprimir Registro A2000");
            vDTrazasLog(szModulo, "Fallo Put_A2000", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2000= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1800",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1800= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1800(Fd_ArchImp, &sthTablaAcum, SaldoTot, pstFaCuotas, zsBufferImpresionArchivo, FactDocuClie->dImpConversion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,46,"No Pudo Imprimir Registro A1800");
            vDTrazasLog(szModulo, "Fallo Put_A1800", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1800= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A1900",FactDocuClie->iCodTipDocum))
    {
        memset(&sthTablaAcum, 0, sizeof (ST_TABLA_ACUM));

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A1900= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A1900(Fd_ArchImp, 
        				&sthTablaAcum, 
        				SaldoTot, 
        				pstFaCuotas, 
        				zsBufferImpresionArchivo, 
        				pst_MascaraOper,
        				esCiclo,
        				FactDocuClie,/* se agrega ind de no ciclo */
        				pstPromTrafClie) ) 
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,47,"No Pudo Imprimir Registro A1900");
            vDTrazasLog(szModulo, "Fallo Put_A1900", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A1900= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }


    /* Inicio P-ECU_12002F2*/
    vDTrazasLog(szExeName,"\n Ingreso BuscaMascara con  A1960",LOG03);
    if ( BuscaMascara(pst_MascaraOper,"A1960",FactDocuClie->iCodTipDocum) )
    {
        vDTrazasLog(szExeName,"\n Ingreso a Put_1960",LOG03);

        if ( !Put_A1960(Fd_ArchImp, FactDocuClie, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, 0,48,"No Pudo Imprimir Registro A1960");
            vDTrazasLog(szModulo, "Fallo Put_A1960", LOG05);
            return(FALSE);
        }

        vDTrazasLog(szExeName,"\n Saliendo de Put_1960",LOG03);
    }

    /* Fin P-ECU_12002F2*/
    
    
    if ( BuscaMascara(pst_MascaraOper,"A2100",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2100= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2100(Fd_ArchImp, sthTablaAcum, zsBufferImpresionArchivo, FactDocuClie->dImpConversion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,48,"No Pudo Imprimir Registro A2100");
            vDTrazasLog(szModulo, "Fallo Put_A2100", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2100= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A2200",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2200= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2200(Fd_ArchImp, SaldoTot, pstFaCuotas, zsBufferImpresionArchivo, FactDocuClie->dImpConversion) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,49,"No Pudo Imprimir Registro A2200");
            vDTrazasLog(szModulo, "Fallo Put_A2200", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2200= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A2300",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2300= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2300(Fd_ArchImp, Mensajes_NoCiclo, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,50,"No Pudo Imprimir Registro A2300");
            vDTrazasLog(szModulo, "Fallo Put_A2300", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2300= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( BuscaMascara(pst_MascaraOper,"A2400", FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2400= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2400(Fd_ArchImp, FactDocuClie, SaldoTot, pstFaCuotas, zsBufferImpresionArchivo, stBalance) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,51,"No Pudo Imprimir Registro A2400");
            vDTrazasLog(szModulo, "Fallo Put_A2400", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2400= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    if ( stStatus.LogNivel >= LOG06 )
    {
        for ( i=0;i<stFaDetCons.iNumReg;i++ )
        {
            vDTrazasLog(szModulo,"|%ld|%s|%d|%d|%d|%d|%.4f|%.4f|%ld|",LOG06,
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
    }
    if ( BuscaMascara(pst_MascaraOper,"A2500",FactDocuClie->iCodTipDocum) )
    {
        int iMascaraA2600 = 0;
        int iMascaraA2700 = 0;

        /* Obtencion de la mascara para A2600 */
        iMascaraA2600    = BuscaMascara(pst_MascaraOper,"A2600",FactDocuClie->iCodTipDocum);

        /* Obtencion de la mascara para A2700 */
        iMascaraA2700    = BuscaMascara(pst_MascaraOper,"A2700",FactDocuClie->iCodTipDocum);

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2500(= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2500(Fd_ArchImp, FactDocuClie, iMascaraA2600, iMascaraA2700, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,52,"No Pudo Imprimir Registro A2500");
            vDTrazasLog(szModulo, "Fallo Put_A2500", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2500(= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( stStatus.LogNivel >= LOG06 )
        {
            for ( i=0;i < stFaDetCons.iNumReg;i++ )
            {
                vDTrazasLog(szModulo,"|%ld|%s|%d|%d|%d|%d|%.4f|%.4f|%ld|",LOG06,
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
        }
    }

    if ( BuscaMascara(pst_MascaraOper,"A2800",FactDocuClie->iCodTipDocum) )
    {
        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> INICIO Fx Put_A2800= %ld.%d",LOG03, tpi.time,tpi.millitm);

        if ( !Put_A2800(Fd_ArchImp, FactDocuClie, pstDetTrans, zsBufferImpresionArchivo) )
        {
            fnGrabaAnoProceso (FactDocuClie->lCodCliente, lCodigoCicloFacturacion,50,"No Pudo Imprimir Registro A2800");
            vDTrazasLog(szModulo, "Fallo Put_A2800", LOG05);
            return(FALSE);
        }

        ftime(&tpi);
        vDTrazasLog(szExeName,"\n <CONTROL> FIN Fx Put_A2800= %ld.%d",LOG03, tpi.time,tpi.millitm);
    }

    return(TRUE);
}


/***************************************************************************/
/* Procedimiento encargado de obtener los mensajes para cada cliente       */
/* facturado.                                                              */
/***************************************************************************/
int iGetMensajesCliente (long lCodCliente, char *szCodIdioma, ST_MENSAJES * psthFaMensajes, int *iNumLineasMensaje, int ihCodFormDetalle, char * szhIndFacturado)
{
    int iNumMensajesFetch=0;

    strcpy (szModulo, "iGetMensajesCliente");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    memset(psthFaMensajes,0,sizeof(ST_MENSAJES));

    lhCodClienteCur     = lCodCliente        ;
    ihCodFormDetalleCur = ihCodFormDetalle   ;
    strcpy(szhCodIdiomaCur, szCodIdioma    );
    strcpy(szhIndFacturCur, szhIndFacturado);


    /* EXEC SQL OPEN Cursor_Mensajes ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0004;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )897;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCodClienteCur;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodFormDetalleCur;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhCodIdiomaCur;
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhIndFacturCur;
    sqlstm.sqhstl[3] = (unsigned long )2;
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


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog(szModulo, "Error en OPEN Cur_GetMensajes. Error [%i][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
        /*return(sqlca.sqlcode); */
    }

    while ( 1 )
    {
        /* EXEC SQL FETCH Cursor_Mensajes
        INTO :psthFaMensajes; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )50;
        sqlstm.offset = (unsigned int  )928;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)psthFaMensajes->iCorrMensaje;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )sizeof(int);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)psthFaMensajes->iNumLinea;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )sizeof(int);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)psthFaMensajes->iCantCaract;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )sizeof(int);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)psthFaMensajes->zsCodIdioma;
        sqlstm.sqhstl[3] = (unsigned long )6;
        sqlstm.sqhsts[3] = (         int  )6;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
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



        if ( sqlca.sqlcode < SQLOK )
        {
            vDTrazasLog(szModulo, "Error en FETCH Cur_GetMensajes. Error [%i][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
            return(FALSE);
        }

        if ( (sqlca.sqlcode == SQLNOTFOUND) && (iNumMensajesFetch == sqlca.sqlerrd[2]) )
        {
            break;
        }

        iNumMensajesFetch = sqlca.sqlerrd[2];

        if ( sqlca.sqlcode == SQLNOTFOUND ) break;
    }
    *iNumLineasMensaje = sqlca.sqlerrd[2];


    /* EXEC SQL CLOSE Cursor_Mensajes; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )959;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog(szModulo, "Error en CLOSE Cur_GetMensajes. Error [%i][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }


    return(TRUE);
}/********************************* Final iGetMensajesCliente ************************************/
int iUpdateFactDocu (long lCodCiclFact, ST_FACTCLIE *FactDocuClie, ST_ACUMMTO *AcumMto )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int     ihInd_Impresa = 1;
    char    *szhRowid;
    char    szAux[524];
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "iUpdateFactDocu");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    szhRowid      = FactDocuClie->szRowid;
    ihInd_Impresa = 1;

    if ( lCodCiclFact )
    {
        sprintf(szAux, " UPDATE FA_FACTDOCU_%ld \n"
                        " SET IND_IMPRESA = :ihInd_Impresa \n"
                        " WHERE ROWID = :szhRowid "
                        ,lCodCiclFact);

        vDTrazasLog(szModulo,"\t\tUPDATE FA_FACTDOCU:[ %s ]",LOG05,szAux);


        /* EXEC SQL PREPARE sql_Update_FaFactDocu FROM :szAux; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )974;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szAux;
        sqlstm.sqhstl[0] = (unsigned long )524;
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
            vDTrazasLog  (szModulo,"\t\tError en SQL-PREPARE sql_Update_FaFactDocu **"
                          "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_Update_FaFactDocu **"
                          "\t\tError : [%s] [%d]  [%s] ",LOG01,szAux,SQLCODE,SQLERRM);
            return(SQLCODE);
        }

        /* EXEC SQL EXECUTE sql_Update_FaFactDocu USING :ihInd_Impresa,:szhRowid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )993;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihInd_Impresa;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhRowid;
        sqlstm.sqhstl[1] = (unsigned long )0;
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



    }
    else
    {
        /* EXEC SQL
        UPDATE FA_FACTDOCU_NOCICLO
        SET IND_IMPRESA = :ihInd_Impresa WHERE ROWID = :szhRowid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update FA_FACTDOCU_NOCICLO  set IND_IMPRESA=:b0 where\
 ROWID=:b1";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1016;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihInd_Impresa;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhRowid;
        sqlstm.sqhstl[1] = (unsigned long )0;
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


    }

    if ( sqlca.sqlcode != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en EXECUTE Cursor QueryFactDocu. Error [%i][%s]"
                    , LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }
    return(TRUE);
}/*********************************** Final iUpdateFactDocu  ***********************************/


int iUpdateFactDocu_MC (long lCodCiclFact, ST_FACTCLIE *FactDocuClie, STSALDO_ANTERIOR *SaldoTot, ST_CUOTAS *pstFaCuotas, ST_BALANCE *stBalance ,char * szArchivoFinal,int sema,int indicador)
{
    char    szUpdate[1024];
    char    buffer_local[1024];
    int     iDigVeriF_Total_Pagar;
    double  dTotalAPagar;
    double  dTotalCuotas;
    double  dTotalSaldo;
    char    total_pagar[17];
    char    total_cuotas[17];
    char    total_saldo[17];
    char    archivo[255];
    int     i=0;

    strcpy(szModulo, "iUpdateFactDocu_MC");
    vDTrazasLog(szModulo, "Entro a %s",LOG05,szModulo);

    dTotalAPagar = 0.0;
    dTotalCuotas = 0.0;
    dTotalSaldo  = 0.0;

    dTotalCuotas = pstFaCuotas->dTotalCuotas_pven;

    dTotalAPagar =  FactDocuClie->dTotCargosMes +
                    stBalance->dMonto[iAJUSTE_CREDITO] +
                    stBalance->dMonto[iBALANCE_ANTERIOR] +
                    stBalance->dMonto[iPAGOS_RECIBIDOS] +
                    stBalance->dMonto[iPAGOS_REVERTIDOS] +
                    stBalance->dMonto[iMISCELANEA] +
                    SaldoTot->dTotalSaldo +
                    dTotalCuotas;

    dTotalSaldo  = SaldoTot->dTotalSaldo;

    if ( CalculaDigVerif(dTotalAPagar,&iDigVeriF_Total_Pagar) !=  TRUE )
    {
        iDigVeriF_Total_Pagar = 999;
    }

    memset(buffer_local,'\0',sizeof(buffer_local));
    memset(archivo,'\0',sizeof(archivo));
    strncpy(archivo,szArchivoFinal,_strlen(szArchivoFinal));

    sprintf(buffer_local,REG_1200,
            FactDocuClie->dTotCargosMes,
            SaldoTot->dTotalSaldo,
            dTotalCuotas,
            dTotalAPagar,
            iDigVeriF_Total_Pagar,
            fnCnvDouble(SaldoTot->dTotalSaldo + FactDocuClie->dTotCargosMes,USO0));

    memset(total_pagar,'\0',sizeof(total_pagar));
    memset(total_cuotas,'\0',sizeof(total_cuotas));
    memset(total_saldo,'\0',sizeof(total_saldo));

    sprintf(total_pagar,"%f",dTotalAPagar);
    sprintf(total_cuotas,"%f",dTotalCuotas);
    sprintf(total_saldo,"%f",dTotalSaldo);

    memset(szUpdate,'\0',sizeof(szUpdate));

    if ( !lNroJob )
    {
        sprintf(szUpdate,"update FA_FACTDOCU_%ld set IND_IMPRESA=1 WHERE IND_ORDENTOTAL = %ld ",lCodCiclFact,FactDocuClie->lIndOrdenTotal);
    }
    else
    {
        sprintf(szUpdate,"update FA_FACTDOCU_%ld_%ld set IND_IMPRESA=1 WHERE IND_ORDENTOTAL = %ld ",lCodCiclFact, lNroJob, FactDocuClie->lIndOrdenTotal);
    }

    vDTrazasLog(szModulo,"UPDATE          [%s]\n"
    					 "Archivo         [%s]\n"
    					 "Tipo Documento  [%d]\n"
    					 "Codigo Despacho [%s]\n"
    					 "Codigo Zona     [%s]\n"
    					 "IndOrdenTotal   [%ld]"
    					 ,LOG05,szUpdate,archivo,FactDocuClie->iCodTipDocum
    					 ,FactDocuClie->szCodDespacho,FactDocuClie->szCodZona,FactDocuClie->lIndOrdenTotal);

    i = get_registro (sema);
	vDTrazasLog(szModulo,"Regristo MC obtenido [%d]\n" ,LOG05,i);
	
    memset(memoria[0].concatenador[i].szupdate,'\0',sizeof(memoria[0].concatenador[i].szupdate));
    memset(memoria[0].concatenador[i].sznomarchivo,'\0',sizeof(memoria[0].concatenador[i].sznomarchivo));
    memset(memoria[0].concatenador[i].szCod_Despacho,'\0',sizeof(memoria[0].concatenador[i].szCod_Despacho));
    memset(memoria[0].concatenador[i].szCod_Zona,'\0',sizeof(memoria[0].concatenador[i].szCod_Zona));

    strncpy(memoria[0].concatenador[i].szupdate,szUpdate,_strlen(szUpdate));
    strncpy(memoria[0].concatenador[i].sznomarchivo,archivo,_strlen(archivo));
    strncpy(memoria[0].concatenador[i].szCod_Despacho,FactDocuClie->szCodDespacho,_strlen(FactDocuClie->szCodDespacho));
    strncpy(memoria[0].concatenador[i].szCod_Zona,FactDocuClie->szCodZona,_strlen(FactDocuClie->szCodZona));

    memoria[0].concatenador[i].itipdocum = FactDocuClie->iCodTipDocum;
    memoria[0].concatenador[i].marcador = 2 ;
    memoria[0].concatenador[i].bueno = indicador ;

    return(TRUE);
}/*********************************** Final iUpdateFactDocu_MC  ***********************************/

/***************************************************************************/
/* Procedimiento encargado de recuperar los mensajes para el archivo       */
/***************************************************************************/
int   UnloadMensajes ( char * szPath, char * szhIndFacturado, int  ihCodFormDetalle, LINEACOMANDO * ParEntrada)
{
    int     iNum_Lineas=0, i=0;
    char    szArchMensajes[1000]=" ";
    char    szPathDir[1024];
    char    szCodIdioma[6];
    char    szNombreArchivo[220];
    FILE*   pfMens;


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    szhDesc_MensLin [1000][133]; /* EXEC SQL VAR szhDesc_MensLin IS STRING(133); */ 

    int     ihCorr_Mensaje  [1000]  ;
    int     ihNum_Linea     [1000]  ;
    int     ihCant_Caract   [1000]  ;
    char    ihCodIdioma     [1000][6];   /* EXEC SQL VAR ihCodIdioma IS STRING(6); */ 

    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "UnloadMensajes");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    sprintf(szNombreArchivo,"DetMsg_%d_%s_%s.dat"
            ,ParEntrada->iCodTipDocum
            ,ParEntrada->szCodDespacho
            ,(strcmp(szgHostId,"-1")==0)?"_":szgHostId);

    if ( iMakeDir(szPath)!=0 )
    {
        vDTrazasLog(szModulo, "Falla al crear el directorio [%s] ", LOG05, szPath);
        return(FALSE);
    }

    sprintf(szPathDir,"%s/",szPath);

    /*------------------------------------------------------------------------------*/
    /* Generacion del nombre del archivo de Detalle de Consumo y apertura del mismo.*/
    /*------------------------------------------------------------------------------*/
    sprintf(szArchMensajes, "%s%s\0", szPathDir, szNombreArchivo);

    vDTrazasLog(szModulo,"Archivo de Detalle de Mensajes   : [%s]\n", LOG05, szArchMensajes);

    if ( (pfMens = fopen(szArchMensajes, "w")) == (FILE *)NULL )
    {
        vDTrazasLog(szModulo, "\nArchivo [%s] no pudo ser abierto.[%s]"
                    "\nRevise su existencia."
                    "\nError Numero: %d     %s"
                    "\nProceso finalizado con error."
                    , LOG05, szArchMensajes, errno, strerror(errno));
        return(FALSE);
    }

    strcpy(szhIndFacturadoCur, szhIndFacturado);
    ihCodFormDetalleCur = ihCodFormDetalle;

    /* EXEC SQL OPEN Cursor_FaMensajesCiclo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0003;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1039;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihAValorUno;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodFormDetalleCur;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhIndFacturadoCur;
    sqlstm.sqhstl[2] = (unsigned long )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihAValorCero;
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


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog (szModulo,"Error en OPEN Cursor_FaMensajesCiclo. Error [%d][%s]\n", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    while ( 1 )
    {
        /* EXEC SQL FETCH Cursor_FaMensajesCiclo
        INTO    :ihCorr_Mensaje,
        :ihNum_Linea,
        :ihCant_Caract,
        :szhDesc_MensLin,
        :ihCodIdioma; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1000;
        sqlstm.offset = (unsigned int  )1078;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)ihCorr_Mensaje;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )sizeof(int);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)ihNum_Linea;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )sizeof(int);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)ihCant_Caract;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )sizeof(int);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhDesc_MensLin;
        sqlstm.sqhstl[3] = (unsigned long )133;
        sqlstm.sqhsts[3] = (         int  )133;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)ihCodIdioma;
        sqlstm.sqhstl[4] = (unsigned long )6;
        sqlstm.sqhsts[4] = (         int  )6;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
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



        if ( sqlca.sqlcode < SQLOK )
        {
            vDTrazasLog (szModulo,"Error en FETCH Cursor_FaMensajesCiclo. Error [%d][%s]\n", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
            return(FALSE);
        }

        iNum_Lineas=sqlca.sqlerrd[2];
        if ( sqlca.sqlcode == SQLNOTFOUND ) break;

    }

    vDTrazasLog (szModulo,"Cantidad de lineas de mensaje recuperadas: [%d]\n",LOG05, iNum_Lineas);

    for ( i=0;i<iNum_Lineas;i++ )
    {
        strcpy(szCodIdioma, ihCodIdioma[i]);
        FillCodIdioma(szCodIdioma);
        fprintf(pfMens ,"%8.8d%2.2d%3.3d%5.5s %-.132s\n",ihCorr_Mensaje[i],ihNum_Linea[i],ihCant_Caract[i],szCodIdioma,szhDesc_MensLin[i]);
    }

    /* EXEC SQL CLOSE Cursor_FaMensajesCiclo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1113;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog (szModulo,"Error en CLOSE Cursor_FaMensajesCiclo. Error [%i][%s]\n", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    fflush(pfMens);
    fclose(pfMens);

    return(TRUE);
}/*********************************** Final UnloadMensajes ***********************************/

int GetDireccion(ST_FACTCLIE *FactCli)
{
    char dir_noformateada[1000];
    OPERADORA   stOper;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* VARCHAR szDireccion [6][301]; */ 
struct { unsigned short len; unsigned char arr[302]; } szDireccion[6];

    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "GetDireccion");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    /* EXEC SQL SELECT GE_FN_OBTIENE_DIRCLIE(:FactCli->lCodCliente,1,1,3) INTO :szDireccion[iDIRECCION_FACTURACION] FROM DUAL ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select GE_FN_OBTIENE_DIRCLIE(:b0,1,1,3) into :b1  from DU\
AL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1128;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(FactCli->lCodCliente);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&szDireccion[iDIRECCION_FACTURACION];
    sqlstm.sqhstl[1] = (unsigned long )303;
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



    sprintf(dir_noformateada,"%.*s\0",szDireccion[iDIRECCION_FACTURACION].len, szDireccion[iDIRECCION_FACTURACION].arr);

    if ( !FormateaDireccion(dir_noformateada,FactCli->szDireccion[iDIRECCION_FACTURACION]) )
    {
        vDTrazasLog(szModulo,"Termino con error direccion(%s) IND_ORDENTOTAL(%ld)\n",LOG02,dir_noformateada,FactCli->lIndOrdenTotal);
    }
    vDTrazasLog(szModulo,"Direccion de Facturacion     [%s][%d]",LOG05,FactCli->szDireccion[iDIRECCION_FACTURACION],_strlen(FactCli->szDireccion[iDIRECCION_FACTURACION]));

    if ( !bfnFindOperadora (FactCli->szCodOperadora, &stOper ) )
        return (FALSE);

    sprintf(dir_noformateada,"%s\0",stOper.szDireccion);

    if ( !FormateaDireccion(dir_noformateada,FactCli->szDireccion[iDIRECCION_OPERADORA]) )
    {
        vDTrazasLog(szModulo,"Termino con error direccion(%s) IND_ORDENTOTAL(%ld)\n",LOG02,dir_noformateada,FactCli->lIndOrdenTotal);
    }
    vDTrazasLog(szModulo,"Direccion de Operadora       [%s][%d]",LOG05,FactCli->szDireccion[iDIRECCION_OPERADORA],_strlen(FactCli->szDireccion[iDIRECCION_OPERADORA]));

    /* EXEC SQL SELECT GE_FN_OBTIENE_DIRCLIE(:FactCli->iCodOperPlaza,13,0,3) INTO :szDireccion[iDIRECCION_PLAZA] FROM DUAL ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select GE_FN_OBTIENE_DIRCLIE(:b0,13,0,3) into :b1  from D\
UAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1151;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(FactCli->iCodOperPlaza);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&szDireccion[iDIRECCION_PLAZA];
    sqlstm.sqhstl[1] = (unsigned long )303;
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



    sprintf(dir_noformateada,"%.*s\0",szDireccion[iDIRECCION_PLAZA].len, szDireccion[iDIRECCION_PLAZA].arr);

    if ( !FormateaDireccion(dir_noformateada,FactCli->szDireccion[iDIRECCION_PLAZA]) )
    {
        vDTrazasLog(szModulo,"Termino con error direccion(%s) IND_ORDENTOTAL(%ld)\n",LOG02,dir_noformateada,FactCli->lIndOrdenTotal);
    }
    vDTrazasLog(szModulo,"Direccion de Plaza           [%s][%d]",LOG05,FactCli->szDireccion[iDIRECCION_PLAZA],_strlen(FactCli->szDireccion[iDIRECCION_PLAZA]));

    /* EXEC SQL SELECT GE_FN_OBTIENE_DIRCLIE(:FactCli->lCodCliente,1,3,3) INTO :szDireccion[iDIRECCION_CORRESPONDENCIA] FROM DUAL ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select GE_FN_OBTIENE_DIRCLIE(:b0,1,3,3) into :b1  from DU\
AL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1174;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(FactCli->lCodCliente);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&szDireccion[iDIRECCION_CORRESPONDENCIA];
    sqlstm.sqhstl[1] = (unsigned long )303;
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



    sprintf(dir_noformateada,"%.*s\0",szDireccion[iDIRECCION_CORRESPONDENCIA].len, szDireccion[iDIRECCION_CORRESPONDENCIA].arr);

    if ( !FormateaDireccion(dir_noformateada,FactCli->szDireccion[iDIRECCION_CORRESPONDENCIA]) )
    {
        vDTrazasLog(szModulo,"Termino con error direccion(%s) IND_ORDENTOTAL(%ld)\n",LOG02,dir_noformateada,FactCli->lIndOrdenTotal);
    }
    vDTrazasLog(szModulo,"Direccion de Correspondencia [%s][%d]",LOG05,FactCli->szDireccion[iDIRECCION_CORRESPONDENCIA],_strlen(FactCli->szDireccion[iDIRECCION_CORRESPONDENCIA]));

    /* EXEC SQL SELECT GE_FN_OBTIENE_DIRCLIE(:FactCli->szCod_Oficina,10,0,3) INTO :szDireccion[iDIRECCION_SUCURSAL] FROM DUAL ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select GE_FN_OBTIENE_DIRCLIE(:b0,10,0,3) into :b1  from D\
UAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1197;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)(FactCli->szCod_Oficina);
    sqlstm.sqhstl[0] = (unsigned long )3;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&szDireccion[iDIRECCION_SUCURSAL];
    sqlstm.sqhstl[1] = (unsigned long )303;
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



    sprintf(dir_noformateada,"%.*s\0",szDireccion[iDIRECCION_SUCURSAL].len, szDireccion[iDIRECCION_SUCURSAL].arr);

    if ( !FormateaDireccion(dir_noformateada,FactCli->szDireccion[iDIRECCION_SUCURSAL]) )
    {
        vDTrazasLog(szModulo,"Termino con error direccion(%s) IND_ORDENTOTAL(%ld)\n",LOG02,dir_noformateada,FactCli->lIndOrdenTotal);
    }
    vDTrazasLog(szModulo,"Direccion de Sucursal        [%s][%d]",LOG05,FactCli->szDireccion[iDIRECCION_SUCURSAL],_strlen(FactCli->szDireccion[iDIRECCION_SUCURSAL]));


    return(TRUE);
}
/****************************************************************************/
/* Funcion que recupera el Saldo Anterior por Concepto                       */
/****************************************************************************/
int SaldoAntConcepto(STSALDO_ANTERIOR  * SaldoTot, long lCodCliente, ST_CICLOFACT *CicloFact)
{
    int   conta,i=0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long     lhNum_Secuenci  [MAX_SALDOS];
    int      ihCod_Tipdocum  [MAX_SALDOS];
    long     lhNum_Folio     [MAX_SALDOS];
    double   dhTot_Saldo     [MAX_SALDOS];
    /* VARCHAR  szhNum_FolioCtc [MAX_SALDOS][12]; */ 
struct { unsigned short len; unsigned char arr[14]; } szhNum_FolioCtc[5000];

    /* VARCHAR  szhDes_Tipdocum [MAX_SALDOS][41]; */ 
struct { unsigned short len; unsigned char arr[42]; } szhDes_Tipdocum[5000];

    /* VARCHAR  shzFec_Efectiva [MAX_SALDOS][11]; */ 
struct { unsigned short len; unsigned char arr[14]; } shzFec_Efectiva[5000];

    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "SaldoAntConcepto");
    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);

    /*SETEO DE ESTRUCTURA A LLENAR*/

    SaldoTot->szFec_Emision [0]=0;
    SaldoTot->dTotalSaldo      =0.0;
    SaldoTot->iNum_RegSaldo    =0;

    for ( conta=0;conta<MAX_SALDOS;conta++ )
    {
        SaldoTot->stReg[conta].szDes_Saldo    [0]=0;
        SaldoTot->stReg[conta].szFechaEfectiva[0]=0;
        SaldoTot->stReg[conta].szNum_FolioCtc [0]=0;
        SaldoTot->stReg[conta].iCod_Tipdoc       =0;
        SaldoTot->stReg[conta].lNum_Folio        =0;
        SaldoTot->stReg[conta].lNum_Secuenci     =0;
        SaldoTot->stReg[conta].lNumAbonado       =0;
        SaldoTot->stReg[conta].dTotalSaldoAnt    =0;
    }

    lhCodClienteCur = lCodCliente;
    strcpy(szhFec_EmisionCur,CicloFact->szFec_Emision);

    strcpy(szhAFormatoFecha,"YYYYMMDD");
    strcpy(szhATabla,"CO_CARTERA");
    strcpy(szhAColumna,"COD_TIPDOCUM");
    ihAValorCero =0;
    ihAValorUno  =1;

    /* EXEC SQL OPEN Cursor_SaldoAnte ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0002;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1220;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhAFormatoFecha;
    sqlstm.sqhstl[0] = (unsigned long )9;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhCodClienteCur;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFec_EmisionCur;
    sqlstm.sqhstl[4] = (unsigned long )9;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhAFormatoFecha;
    sqlstm.sqhstl[5] = (unsigned long )9;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&ihAValorCero;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&ihAValorUno;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihAValorUno;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)szhATabla;
    sqlstm.sqhstl[9] = (unsigned long )11;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)szhAColumna;
    sqlstm.sqhstl[10] = (unsigned long )13;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
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


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog(szModulo, "Error en OPEN Cur_SaldoAnte. Error [%i][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    /* EXEC SQL FETCH Cursor_SaldoAnte
    INTO :szhNum_FolioCtc,
	     :shzFec_Efectiva,
	     :lhNum_Secuenci,
	     :ihCod_Tipdocum,
	     :lhNum_Folio,
	     :szhDes_Tipdocum,
	     :dhTot_Saldo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )5000;
    sqlstm.offset = (unsigned int  )1279;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)szhNum_FolioCtc;
    sqlstm.sqhstl[0] = (unsigned long )14;
    sqlstm.sqhsts[0] = (         int  )16;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)shzFec_Efectiva;
    sqlstm.sqhstl[1] = (unsigned long )13;
    sqlstm.sqhsts[1] = (         int  )16;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)lhNum_Secuenci;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )sizeof(long);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)ihCod_Tipdocum;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(int);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)lhNum_Folio;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )sizeof(long);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhDes_Tipdocum;
    sqlstm.sqhstl[5] = (unsigned long )43;
    sqlstm.sqhsts[5] = (         int  )44;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)dhTot_Saldo;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )sizeof(double);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
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



    if ( sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND)
    {
        vDTrazasLog(szModulo, "Error en FETCH Cur_SaldoAnte. Error [%i][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    SaldoTot->iNum_RegSaldo=sqlca.sqlerrd[2];


    if ( SaldoTot->iNum_RegSaldo<=0 )
    {
        vDTrazasLog(szModulo, "No se encontraron Saldos Anteriores", LOG03);
        return(FALSE);
    }

    if ( SaldoTot->iNum_RegSaldo>0 )
    {
        sprintf(SaldoTot->szFec_Emision,"%s\0",CicloFact->szFec_Emision);
        for ( i=0;i< SaldoTot->iNum_RegSaldo;i++ )
        {
            SaldoTot->stReg[i].lCod_Cliente    =   lhCodClienteCur;
            SaldoTot->stReg[i].lNum_Secuenci   =   lhNum_Secuenci[i];
            SaldoTot->stReg[i].lNum_Folio      =   lhNum_Folio[i];
            SaldoTot->stReg[i].iCod_Tipdoc     =   ihCod_Tipdocum[i];
            SaldoTot->stReg[i].dTotalSaldoAnt  =   dhTot_Saldo[i];

            sprintf(SaldoTot->stReg[i].szNum_FolioCtc,"%.*s\0", szhNum_FolioCtc[i].len, szhNum_FolioCtc[i].arr);
            sprintf(SaldoTot->stReg[i].szDes_Saldo,"%.*s\0",    szhDes_Tipdocum[i].len, szhDes_Tipdocum[i].arr);
            sprintf(SaldoTot->stReg[i].szFechaEfectiva,"%.*s\0",shzFec_Efectiva[i].len, shzFec_Efectiva[i].arr);

            SaldoTot->dTotalSaldo += dhTot_Saldo[i];
        }
    }

    if ( stStatus.LogNivel >= LOG05 )
    {
        vDTrazasLog (szModulo,"SaldoTot->iNum_RegSaldo [%d]\n",LOG05, SaldoTot->iNum_RegSaldo);
        for ( i=0;i< SaldoTot->iNum_RegSaldo;i++ )
            vDTrazasLog (szModulo,"SaldoTot->stReg[%d].dTotalSaldoAnt [%ld]\n",LOG05, i, SaldoTot->stReg[i].dTotalSaldoAnt);
    }

    /* EXEC SQL CLOSE Cursor_SaldoAnte; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1322;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( sqlca.sqlcode < SQLOK )
    {
        vDTrazasLog(szModulo, "Error en CLOSE Cur_SaldoAnte. Error [%d][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    return(TRUE);
}/********************************** Final SaldoAntConcepto **********************************/


int ifnCmpTipDocum(const void *cad1,const void *cad2)
{
    return((TIPDOC *)cad1)->iCodTipDocum - ((TIPDOC *)cad2)->iCodTipDocum;
}


BOOL bfnCargaTipDocum (TIPDOC **pstTipDoc, int *iNumTipDocs)
{
    int     rc = 0;
    int     iNumFilas;
    static  TIPDOC_HOSTS stTipDocHost;
    TIPDOC  *pstTipDocumTemp;
    int  iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Tipos de Documentos y sus Descripciones ", LOG06);

    *iNumTipDocs = 0;
    *pstTipDoc = NULL;

    if ( ifnOpenTipDocums() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchTipDocums (&stTipDocHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstTipDoc =(TIPDOC*) realloc(*pstTipDoc,(((*iNumTipDocs)+iNumFilas)*sizeof(TIPDOC)));

        if ( !*pstTipDoc )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Error bfnCargaTipDocum", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstTipDocumTemp = &(*pstTipDoc)[(*iNumTipDocs)];
        memset(pstTipDocumTemp, 0, sizeof(TIPDOC)*iNumFilas);
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy( pstTipDocumTemp[iCont].szDesTipDocum    ,stTipDocHost.szDesTipDocum[iCont]);
            pstTipDocumTemp[iCont].iCodTipDocum     = stTipDocHost.iCodTipDocum[iCont];
        }
        (*iNumTipDocs) += iNumFilas;
    }/* fin while */

    vDTrazasLog (szExeName,"\n\t\t* Tipos de documentos cargados [% d]", LOG06, *iNumTipDocs);

    rc = ifnCloseTipDocums();
    if ( rc != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaTipDocum", szfnORAerror ());
        return (FALSE);
    }

    qsort((void*)*pstTipDoc, *iNumTipDocs, sizeof(TIPDOC),ifnCmpTipDocum);

    vfnPrintTipDocums (*pstTipDoc, *iNumTipDocs);

    return(TRUE);
}/***************************** Final bfnCargaTipDocum *********************/

static int ifnOpenTipDocums(void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> Ge_Tipdocumen", LOG06);

    /* EXEC SQL DECLARE Cur_TipDocum CURSOR FOR
    SELECT DISTINCT COD_TIPDOCUM,
    DES_TIPDOCUM
    FROM   GE_TIPDOCUMEN; */ 


    /* EXEC SQL OPEN Cur_TipDocum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0031;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1337;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Ge_Tipdocumen",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenTipDocums **********************/

static BOOL bfnFetchTipDocums (TIPDOC_HOSTS *pstHost,int *piNumFilas)
{

    /* EXEC SQL FETCH Cur_TipDocum
    INTO  :pstHost->iCodTipDocum  ,
    :pstHost->szDesTipDocum ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )1352;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->iCodTipDocum);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szDesTipDocum);
    sqlstm.sqhstl[1] = (unsigned long )40;
    sqlstm.sqhsts[1] = (         int  )40;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> GE_TIPDOCUMEN", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchTipDocums ****************/


static int ifnCloseTipDocums(void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> Ge_Tipdocumen", LOG06);

    /* EXEC SQL CLOSE Cur_TipDocum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1375;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> Cursor=> GE_TIPDOCUMEN",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenTipDocums **********************/

void vfnPrintTipDocums (TIPDOC *pstTipDoc, int iNumTipDocs)
{
    int i = 0;

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szExeName,"\n\t\t* Carga Tabla Tipos de Documentos [%d]", LOG06, iNumTipDocs);

        for ( i=0;i<iNumTipDocs;i++ )
        {
            vDTrazasLog (szExeName,"\n\t\t=> [%d]: Codigo [%d] Descripcion [%s]"
			                         ,LOG06,i
			                         , pstTipDoc[i].iCodTipDocum
			                         , pstTipDoc[i].szDesTipDocum   );
        }
    }
}/*************************** vfnPrintTipDocums *****************************/


BOOL bfnFindTipDocum (int iCodTipDocum, TIPDOC *pstTipDoc )
{
    TIPDOC  stkey;
    TIPDOC  *pstAux = (TIPDOC *)NULL;

    vDTrazasLog (szExeName, "\n\t\t* Busca Tipo de Documento "
                 "\n\t\t=> Cod.TipDocum   [%d]"
                 , LOG05,iCodTipDocum);

    stkey.iCodTipDocum  = iCodTipDocum;

    if ( (pstAux = (TIPDOC *)bsearch (&stkey, pstTipDocum.stTipDocum , pstTipDocum.iNumTipDocum,
                                      sizeof (TIPDOC),ifnCmpTipDocum ))== (TIPDOC *)NULL )
    {
        vDTrazasLog(szExeName, "Tipo de Documento [%d] no encontrado ...", LOG01, iCodTipDocum);
        return(FALSE);
    }

    memcpy (pstTipDoc, pstAux, sizeof(TIPDOC));
    return(TRUE);
}


int ifnCmpOficinas2(const void *cad1,const void *cad2)
{
    return( strcmp (((OFICINA2  *)cad1)->szCodOficina,((OFICINA2  *)cad2)->szCodOficina) );

}

/**************************************************************************/
/*                             funcion : bfnFindOficina                   */
/**************************************************************************/
BOOL bfnFindOficina2 (char *szCodOficina, OFICINA2 *pstOficina )
{
    OFICINA2  stkey;
    OFICINA2  *pstAux = (OFICINA2 *)NULL;

    vDTrazasLog (szExeName, "\n\t\t* Busca Oficina "
                 "\n\t\t=> Cod.Oficina   [%s]"
                 "\n\t\t=> Num.Oficina   [%d]"
                 , LOG05,szCodOficina, pstOficinas2.iNumOficinas);


    strcpy (stkey.szCodOficina,szCodOficina);

    if ( (pstAux = (OFICINA2 *)bsearch (&stkey, pstOficinas2.stOficina, pstOficinas2.iNumOficinas,
                                        sizeof (OFICINA2),ifnCmpOficinas ))== (OFICINA2 *)NULL )
    {

        vDTrazasLog(szExeName, "Oficina [%s] no encontrada ...", LOG01, szCodOficina);
        return(FALSE);
    }

    memcpy (pstOficina, pstAux, sizeof(OFICINA2));

    return (TRUE);
}/**************************** Final bfnFindOficina2 *********************/

BOOL bfnCargaOficinas2 (OFICINA2 **pstOfici2, int *iNumOficinas)
{
    int     rc = 0;
    int     iNumFilas;
    static  OFICINA_HOSTS2 stOficinasHost;
    OFICINA2 *pstOficinasTemp;
    int     iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Oficinas ", LOG06);

    *iNumOficinas = 0;
    *pstOfici2 = NULL;

    if ( ifnOpenOficinas2() )
        return(FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchOficinas2 (&stOficinasHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return(FALSE);

        if ( !iNumFilas )
            break;

        *pstOfici2 =(OFICINA2*) realloc(*pstOfici2,(((*iNumOficinas)+iNumFilas)*sizeof(OFICINA2)));

        if ( !*pstOfici2 )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Error bfnCargaOficinas2", "no se pudo reservar memoria");
            return(FALSE);
        }

        pstOficinasTemp = &(*pstOfici2)[(*iNumOficinas)];
        memset(pstOficinasTemp, 0, sizeof(OFICINA2)*iNumFilas);
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy(pstOficinasTemp[iCont].szCodOficina  ,alltrim(stOficinasHost.szCodOficina    [iCont]));
            strcpy(pstOficinasTemp[iCont].szDesOficina  ,alltrim(stOficinasHost.szDesOficina    [iCont]));
        }
        (*iNumOficinas) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szExeName,"\n\t\t* Oficinas cargadas [%d]", LOG06, *iNumOficinas);

    rc = ifnCloseOficinas2();
    if ( rc != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaOficinas2", szfnORAerror ());
        return(FALSE);
    }

    qsort((void*)*pstOfici2, *iNumOficinas, sizeof(OFICINA2),ifnCmpOficinas);

    vfnPrintOficinas2 (*pstOfici2, *iNumOficinas);

    return(TRUE);
}/***************************** Final bfnCargaOficinas2 *********************/


static int ifnOpenOficinas2 (void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> Ge_Oficinas;Ge_Direcciones;Ge_Ciudades", LOG06);

    /* EXEC SQL DECLARE Cur_Oficinas CURSOR FOR
    SELECT DISTINCT COD_OFICINA, DES_OFICINA
    FROM GE_OFICINAS
    WHERE COD_OFICINA > ' '; */ 


    /* EXEC SQL OPEN Cur_Oficinas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0032;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1390;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Ge_Oficinas",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenOficinas2 **********************/


static BOOL bfnFetchOficinas2 (OFICINA_HOSTS2 *pstHost,int *piNumFilas)
{
    /* EXEC SQL FETCH Cur_Oficinas
    INTO    :pstHost->szCodOficina  ,
    :pstHost->szDesOficina  ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )1405;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->szCodOficina);
    sqlstm.sqhstl[0] = (unsigned long )3;
    sqlstm.sqhsts[0] = (         int  )3;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szDesOficina);
    sqlstm.sqhstl[1] = (unsigned long )41;
    sqlstm.sqhsts[1] = (         int  )41;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> Oficinas",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final bfnFetchOficinas2 ****************/


/****************************************************************************/
/*                           funcion : vfnPrintFaCiclFact                    */
/****************************************************************************/
void vfnPrintOficinas2 (OFICINA2 *pstOficina, int iNumOficinas)
{
    int i = 0;

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szExeName,"\n\t\t* Carga Tabla Oficinas [%d]", LOG06, iNumOficinas);

        for ( i=0;i<iNumOficinas;i++ )
        {
            vDTrazasLog (szExeName,"\n\t\t=> [%d]: Codigo Oficina      [%s]"
                                   "\n\t\t=> [%d]: Descripcion Oficina [%s]"
                                   ,LOG06
                                   ,i, pstOficina[i].szCodOficina
                                   ,i, pstOficina[i].szDesOficina );

        }
    }
}/*************************** vfnPrintOficinas2 *****************************/


int ifnCloseOficinas2 (void)
{
    vDTrazasLog (szExeName,"\n\t\t* Close=> Oficinas", LOG06);

    /* EXEC SQL CLOSE Cur_Oficinas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1428;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> Oficinas",szfnORAerror ());

    return (SQLCODE);
}/**************************** Final ifnCloseOficinas2 ******************/
int ifnCmpVendedores(const void *cad1,const void *cad2)
{
    return((VENDEDOR *)cad1)->lCodVendedor -
    ((VENDEDOR *)cad2)->lCodVendedor;
}
/***********************************************************************************/
BOOL bfnCargaVendedores (VENDEDOR **pstVendedor, int *iNumVendedores)
{
    int     rc = 0;
    int    iNumFilas;
    static  VENDEDOR_HOSTS stVendedorHost;
    VENDEDOR    *pstVendedorTemp;
    int  iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Codigos de Vendedores y sus Nombres", LOG06);

    *iNumVendedores = 0;
    *pstVendedor = NULL;

    if ( ifnOpenVendedores() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchVendedores(&stVendedorHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstVendedor =(VENDEDOR*) realloc(*pstVendedor,(((*iNumVendedores)+iNumFilas)*sizeof(VENDEDOR)));

        if ( !*pstVendedor )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Error bfnCargaVendedores", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstVendedorTemp = &(*pstVendedor)[(*iNumVendedores)];
        memset(pstVendedorTemp, 0, sizeof(VENDEDOR)*iNumFilas);
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy( pstVendedorTemp[iCont].szNomVendedor    ,stVendedorHost.szNomVendedor[iCont]);
            pstVendedorTemp[iCont].lCodVendedor     =stVendedorHost.lCodVendedor[iCont];
        }
        (*iNumVendedores) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szExeName,"\n\t\t* Codigos de Vendedores cargados [%d]", LOG06, *iNumVendedores);

    rc = ifnCloseVendedores();
    if ( rc != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaVendedores", szfnORAerror ());
        return (FALSE);
    }

    qsort((void*)*pstVendedor, *iNumVendedores, sizeof(VENDEDOR),ifnCmpVendedores);

    vfnPrintVendedores(*pstVendedor, *iNumVendedores);

    return(TRUE);
}/***************************** Final bfnCargaVendedores *********************/


static int ifnOpenVendedores(void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> VE_VENDEDORES", LOG06);

    /* EXEC SQL DECLARE Cur_Vendedores CURSOR for
        SELECT DISTINCT COD_VENDEDOR, NOM_VENDEDOR
        FROM   VE_VENDEDORES
        WHERE COD_VENDEDOR > 0; */ 


    /* EXEC SQL OPEN Cur_Vendedores; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0033;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1443;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> VE_VENDEDORES",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenVendedores **********************/


static BOOL bfnFetchVendedores (VENDEDOR_HOSTS *pstHost,int *piNumFilas)
{
    /* EXEC SQL FETCH Cur_Vendedores
    INTO  :pstHost->lCodVendedor  ,
    :pstHost->szNomVendedor ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )1458;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->lCodVendedor);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )sizeof(long);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szNomVendedor);
    sqlstm.sqhstl[1] = (unsigned long )41;
    sqlstm.sqhsts[1] = (         int  )41;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> VE_VENDEDORES", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchVendedores ****************/


static int ifnCloseVendedores(void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> VE_VENDEDORES", LOG06);

    /* EXEC SQL CLOSE Cur_Vendedores; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1481;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> Cursor=> VE_VENDEDORES",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnCloseVendedores **********************/

void vfnPrintVendedores (VENDEDOR *pstCodVend, int iNumVendedores)
{
    int i = 0;

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szExeName,"\n\t\t* Carga Tabla Codigos de Vendedores [%d]", LOG06, iNumVendedores);

        for ( i=0;i<iNumVendedores;i++ )
        {
            vDTrazasLog (szExeName, "\n\t\t=> [%d]: Nombre de Vendedor  [%s]"
                                    "\n\t\t=> [%d]: Codigo de Vendedor  [%ld]"
                                    ,LOG06
                                    ,i, pstCodVend[i].szNomVendedor
                                    ,i, pstCodVend[i].lCodVendedor    );

        }
    }
}/*************************** vfnPrintVendedores *****************************/


BOOL bfnFindVendedores (long lCodigoVendedor, VENDEDOR *pstCodVende, long lCodCiclFact)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long    lhCodVendedor;
    char    szhNomVendedor[41];
    /* EXEC SQL END DECLARE SECTION; */ 


    VENDEDOR  stkey;
    VENDEDOR  *pstAux = (VENDEDOR *)NULL;

    vDTrazasLog (szExeName, "\n\t\t* Busca Codigo de Vendedor "
			                "\n\t\t=> Cod.Vendedor   [%ld]"
			                , LOG05,lCodigoVendedor);

    stkey.lCodVendedor  = lCodigoVendedor;
    if ( lCodCiclFact )
    {
        if ( (pstAux = (VENDEDOR *)bsearch (&stkey, pstVendedores.stVendedores , pstVendedores.iNumVendedores,
                                            sizeof (VENDEDOR),ifnCmpVendedores ))== (VENDEDOR *)NULL )
        {
            vDTrazasLog(szExeName, "Codigo de Vendedor [%ld] no encontrado ...", LOG01, lCodigoVendedor);
            return(FALSE);
        }
        memcpy (pstCodVende, pstAux, sizeof(VENDEDOR));
    }
    else
    {
        lhCodVendedor = lCodigoVendedor;
        /* EXEC SQL SELECT NVL(NOM_VENDEDOR, '.')
        INTO :szhNomVendedor
        FROM   VE_VENDEDORES
        WHERE  COD_VENDEDOR =  :lhCodVendedor; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NVL(NOM_VENDEDOR,'.') into :b0  from VE_VENDED\
ORES where COD_VENDEDOR=:b1";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1496;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhNomVendedor;
        sqlstm.sqhstl[0] = (unsigned long )41;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodVendedor;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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


        if ( SQLCODE != SQLOK )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> VE_VENDEDORES",szfnORAerror ());
            return (FALSE);
        }
        else
        {
            pstCodVende->lCodVendedor = lhCodVendedor;
            strcpy (pstCodVende->szNomVendedor, szhNomVendedor);
        }
    }
    return(TRUE);
}


/**************************************************************************/
/*                             funcion : ifnCmpOperadoras                 */
/**************************************************************************/
int ifnCmpOperadoras(const void *cad1,const void *cad2)
{
    return( strcmp (((OPERADORA *)cad1)->szCodOperadora,((OPERADORA *)cad2)->szCodOperadora) );
}


/**************************************************************************/
/*                             funcion : bfnFindOficina                   */
/**************************************************************************/
BOOL bfnFindOperadora (char *szCodOper, OPERADORA *pstOper )
{
    OPERADORA  stkey;
    OPERADORA  *pstAux = (OPERADORA *)NULL;

    vDTrazasLog (szExeName, "\n\t\t* Busca Operadora "
                            "\n\t\t=> Cod.Operadora   [%s]"
                            "\n\t\t=> Num.Operadoras  [%d]"
                            , LOG05,szCodOper, pstOperadoras.iNumOperadoras);

    strcpy (stkey.szCodOperadora,szCodOper);

    if ( (pstAux = (OPERADORA *)bsearch (&stkey, pstOperadoras.stOperadora, pstOperadoras.iNumOperadoras,
                                         sizeof (OPERADORA),ifnCmpOperadoras ))== (OPERADORA *)NULL )
    {
        vDTrazasLog(szExeName, "Operadora [%s] no encontrada.", LOG01, szCodOper);
        return(FALSE)                                                   ;
    }

    memcpy (pstOper, pstAux, sizeof(OPERADORA));

    return (TRUE);
}/**************************** Final bfnFindOficina2 *********************/

BOOL bfnCargaOperadora (OPERADORA **pstOper, int *iNumOperadoras)
{
    int     rc = 0;
    int     iNumFilas;
    static  OPERADORA_HOSTS stOperadorasHost;
    OPERADORA *pstOperadoraTemp;
    int  iCont;

    vDTrazasLog (szExeName,"\n\t* Carga Operadoras ", LOG06);

    *iNumOperadoras = 0;
    *pstOper = NULL;

    if ( ifnOpenOperadoras() )
        return(FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchOperadoras (&stOperadorasHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return(FALSE);

        if ( !iNumFilas )
            break;

        *pstOper =(OPERADORA*) realloc(*pstOper,(((*iNumOperadoras)+iNumFilas)*sizeof(OPERADORA)));

        if ( !*pstOper )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Error bfnCargaOperadora", "no se pudo reservar memoria");
            return(FALSE);
        }

        pstOperadoraTemp = &(*pstOper)[(*iNumOperadoras)];
        memset(pstOperadoraTemp, 0, sizeof(OPERADORA)*iNumFilas);
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy(pstOperadoraTemp[iCont].szCodOperadora   ,alltrim(stOperadorasHost.szCodOperadora    [iCont]));
            pstOperadoraTemp[iCont].lCodClienteOperadora    = stOperadorasHost.lCodClienteOperadora [iCont];
            strcpy(pstOperadoraTemp[iCont].szNomOperadora   ,alltrim(stOperadorasHost.szNomOperadora    [iCont]));
            strcpy(pstOperadoraTemp[iCont].szNumIdenTRib    ,alltrim(stOperadorasHost.szNumIdenTRib [iCont]));
            strcpy(pstOperadoraTemp[iCont].szDireccion      , alltrim(stOperadorasHost.szDireccion[iCont]));
        }
        (*iNumOperadoras) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szExeName,"\n\t\t* Operadoras cargadas [%d]", LOG06, *iNumOperadoras);

    rc = ifnCloseOperadoras();
    if ( rc != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaOperadora", szfnORAerror ());
        return(FALSE);
    }

    qsort((void*)*pstOper, *iNumOperadoras, sizeof(OPERADORA),ifnCmpOperadoras);

    vfnPrintOperadoras (*pstOper, *iNumOperadoras);

    return(TRUE);
}/***************************** Final bfnCargaOperadora *********************/


static int ifnOpenOperadoras (void)
{
    vDTrazasLog (szExeName,"\n\t\t* Open=> GE_OPERADORA_SCL", LOG06);

    /* EXEC SQL DECLARE Cur_Operadoras CURSOR FOR
    SELECT  LTRIM(RTRIM(A.COD_OPERADORA_SCL)),
    A.COD_CLIENTE,
    B.NOM_CLIENTE,
    NVL(B.NUM_IDENTTRIB,'AAA'),
    GE_FN_OBTIENE_DIRCLIE(COD_OPERADORA_SCL,12,0,3)
    FROM    GE_OPERADORA_SCL A,GE_CLIENTES B
    WHERE   A.COD_CLIENTE=B.COD_CLIENTE
                          AND     A.COD_CLIENTE IS NOT NULL; */ 


    /* EXEC SQL OPEN Cur_Operadoras; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0035;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1519;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Ge_Oficinas",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenOficinas2 **********************/

static BOOL bfnFetchOperadoras (OPERADORA_HOSTS *pstHost,int *piNumFilas)
{
    /* EXEC SQL FETCH Cur_Operadoras
    INTO    :pstHost->szCodOperadora    ,
    :pstHost->lCodClienteOperadora  ,
    :pstHost->szNomOperadora,
    :pstHost->szNumIdenTRib ,
    :pstHost->szDireccion; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )100;
    sqlstm.offset = (unsigned int  )1534;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->szCodOperadora);
    sqlstm.sqhstl[0] = (unsigned long )6;
    sqlstm.sqhsts[0] = (         int  )6;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->lCodClienteOperadora);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )sizeof(long);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->szNomOperadora);
    sqlstm.sqhstl[2] = (unsigned long )51;
    sqlstm.sqhsts[2] = (         int  )51;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->szNumIdenTRib);
    sqlstm.sqhstl[3] = (unsigned long )21;
    sqlstm.sqhsts[3] = (         int  )21;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->szDireccion);
    sqlstm.sqhstl[4] = (unsigned long )301;
    sqlstm.sqhsts[4] = (         int  )301;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> Oficinas",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final bfnFetchOficinas2 ****************/

int ifnCloseOperadoras (void)
{
    vDTrazasLog (szExeName,"\n\t\t* Close=> Oficinas", LOG06);

    /* EXEC SQL CLOSE Cur_Operadoras; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1569;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> Oficinas",szfnORAerror ());

    return (SQLCODE);
}/**************************** Final ifnCloseOficinas2 ******************/

/****************************************************************************/
/*                           funcion : vfnPrintFaCiclFact                    */
/****************************************************************************/
void vfnPrintOperadoras (OPERADORA *pstOper, int iNumOper)
{
    int i = 0;

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szExeName,"\n\t\t* Carga Tabla Operadoras [%d]", LOG06, iNumOper);

        for ( i=0;i<iNumOper;i++ )
        {
            vDTrazasLog (szExeName, "\n\t\t=> [%d]: Codigo Operadora    [%s]"
                                    "\n\t\t=> [%d]: Nombre Operadora    [%ld]"
                                    "\n\t\t=> [%d]: Vendedor Operadora  [%s]"
                                    "\n\t\t=> [%d]: Iden.Trib Operadora [%s]"
                                    ,LOG06
                                    ,i, pstOper[i].szCodOperadora 
                                    ,i, pstOper[i].lCodClienteOperadora
                                    ,i, pstOper[i].szNomOperadora
                                    ,i, pstOper[i].szNumIdenTRib );
        }
    }
}/*************************** vfnPrintOficinas2 *****************************/


/******************************************************************************************/
/** Informacion de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** RevisiOn                                            : */
/**  %PR% */
/** Autor de la RevisiOn                                : */
/**  %AUTHOR% */
/** Estado de la RevisiOn ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creacion de la RevisiOn                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/
