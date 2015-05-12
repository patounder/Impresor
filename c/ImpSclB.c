
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
    "./pc/ImpSclB.pc"
};


static unsigned int sqlctx = 1728651;


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
   unsigned char  *sqhstv[46];
   unsigned long  sqhstl[46];
            int   sqhsts[46];
            short *sqindv[46];
            int   sqinds[46];
   unsigned long  sqharm[46];
   unsigned long  *sqharc[46];
   unsigned short  sqadto[46];
   unsigned short  sqtdso[46];
} sqlstm = {12,46};

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
"D_COMUNA) and GENER.COD_PAIS=PAIS.COD_PAIS) and DIR.COD_ESTADO=EST.COD_ESTAD\
O(+)) and DIR.COD_PUEBLO=PUE.COD_PUEBLO(+)) and USU.COD_USUARIO=ABON.COD_USUAR\
IO) and ABON.NUM_ABONADO=G.NUM_ABONADO(+))           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,2,0,0,
5,0,0,2,0,0,17,166,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,3,0,0,17,190,0,0,1,1,0,1,0,1,97,0,0,
43,0,0,4,0,0,17,423,0,0,1,1,0,1,0,1,97,0,0,
62,0,0,4,0,0,45,443,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,
101,0,0,4,0,0,13,460,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
164,0,0,4,0,0,15,490,0,0,0,0,0,1,0,
179,0,0,5,0,0,17,791,0,0,1,1,0,1,0,1,97,0,0,
198,0,0,5,0,0,45,793,0,0,0,0,0,1,0,
213,0,0,5,0,0,13,794,0,0,1,0,0,1,0,2,3,0,0,
232,0,0,5,0,0,15,795,0,0,0,0,0,1,0,
247,0,0,6,0,0,17,950,0,0,1,1,0,1,0,1,97,0,0,
266,0,0,6,0,0,45,980,0,0,9,9,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,
317,0,0,6,0,0,13,1010,0,0,46,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,4,0,0,2,3,0,0,
516,0,0,6,0,0,15,1079,0,0,0,0,0,1,0,
531,0,0,2,0,0,21,1231,0,0,11,11,0,1,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
590,0,0,3,0,0,21,1249,0,0,10,10,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
645,0,0,2,0,0,21,1322,0,0,11,11,0,1,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
704,0,0,1,1231,0,9,2354,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,
731,0,0,1,0,0,13,2363,0,0,14,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,5,0,0,2,97,0,0,2,3,
0,0,
802,0,0,1,0,0,15,2388,0,0,0,0,0,1,0,
817,0,0,7,183,0,4,2392,0,0,3,2,0,1,0,2,97,0,0,1,3,0,0,1,3,0,0,
844,0,0,8,328,0,4,2410,0,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
867,0,0,9,387,0,4,2433,0,0,2,1,0,1,0,2,97,0,0,1,3,0,0,
890,0,0,10,83,0,4,3665,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
913,0,0,11,0,0,17,3814,0,0,1,1,0,1,0,1,97,0,0,
932,0,0,11,0,0,45,3836,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
963,0,0,11,0,0,13,3849,0,0,20,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
1058,0,0,11,0,0,15,3974,0,0,0,0,0,1,0,
1073,0,0,12,140,0,4,4104,0,0,4,3,0,1,0,2,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1104,0,0,13,251,0,4,4169,0,0,6,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,1,3,0,0,
1143,0,0,14,0,0,17,4272,0,0,1,1,0,1,0,1,97,0,0,
1162,0,0,14,0,0,45,4294,0,0,0,0,0,1,0,
1177,0,0,14,0,0,13,4311,0,0,7,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,5,0,0,
2,97,0,0,2,97,0,0,
1220,0,0,14,0,0,15,4360,0,0,0,0,0,1,0,
};


#include <ImpSclB.h>
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


/*-------------------------------------------------------------------------------*/
/* PGG SOPORTE 3-04-2008 - 64059 - Se modifica llamadas a la funcion fnCnvDouble */
/* eliminando el parametro 1 (USO0) por USOFACT (0) */
/* Antes        : fnCnvDouble(stBalance->dMonto[iCARGOS_MES],1) */
/* Despues  : fnCnvDouble(stBalance->dMonto[iCARGOS_MES],USOFACT) */
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
/* PGG SOPORTE 4-09-2008 - MA 70199 - Se modifica llamadas a la funcion fnCnvDouble */
/* Cambiando el parametro USO0 por USOFACT en algunos casos.    */
/*-------------------------------------------------------------------------------*/


/* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodClienteCur;
    int  ihBValorCero =0;
    long lhNumAbonado;
    long lhCodCiclFactCur;
    char szhACodTipDireccion[2];
    char szhFormato_Fecha[9];    
/* EXEC SQL END DECLARE SECTION; */ 


/* EXEC SQL DECLARE Cursor_GetDireccion CURSOR FOR
    SELECT
        USU.NUM_IDENT,
        DIR.NOM_CALLE,
        DIR.NUM_CALLE,
        DIR.NUM_PISO,
        COM.DES_COMUNA,
        CIU.DES_CIUDAD,
        DIR.ZIP,
        PAIS.DES_PAIS,
        NVL(EST.DES_ESTADO,'NO REGISTRA'),
        NVL(PUE.DES_PUEBLO,'NO REGISTRA'),
        TO_CHAR(ABON.FEC_ALTA,'YYYYMMDD'),  /o RA DEL P-ECU-12024o/
        G.ID_ACCESO, G.IND_TIPCLIENTE,  /o RA 189128 o/
        ABON.COD_CLIENTE
    FROM
        GA_DIRECUSUAR DIREC,
        GE_CIUDADES CIU,
        GE_COMUNAS COM,
        GE_DIRECCIONES DIR,
        GA_ABOCEL ABON,
        GE_DATOSGENER GENER,
        GE_PAISES PAIS,
        GE_ESTADOS EST,
        GE_PUEBLOS PUE,
        GA_USUARIOS USU,
			  (select a.id_acceso, b.ind_tipcliente, c.num_abonado
				from ga_detabodatos a, ge_clienteS b, ga_abocel c
				where a.num_abonado = c.num_abonado
				and b.cod_cliente = c.cod_cliente
				and a.num_abonado=:lhNumAbonado) G  /o RA 189128 o/
    WHERE ABON.NUM_ABONADO        = :lhNumAbonado
      AND DIREC.COD_USUARIO       = ABON.COD_USUARIO
      AND DIREC.COD_TIPDIRECCION  = :szhACodTipDireccion
      AND DIR.COD_DIRECCION       = DIREC.COD_DIRECCION
      AND CIU.COD_REGION          = DIR.COD_REGION
      AND CIU.COD_PROVINCIA       = DIR.COD_PROVINCIA
      AND CIU.COD_CIUDAD          = DIR.COD_CIUDAD
      AND DIR.COD_REGION          = COM.COD_REGION
      AND DIR.COD_PROVINCIA       = COM.COD_PROVINCIA
      AND DIR.COD_COMUNA          = COM.COD_COMUNA
      AND GENER.COD_PAIS          = PAIS.COD_PAIS
      AND DIR.COD_ESTADO          = EST.COD_ESTADO (+)
      AND DIR.COD_PUEBLO          = PUE.COD_PUEBLO (+)
      AND USU.COD_USUARIO         = ABON.COD_USUARIO
      AND ABON.NUM_ABONADO        = G.NUM_ABONADO(+); */ 
  /* RA 189128 */

		/* Inicio P-ECU-12026 */
		SERVSUPLPLANES servsuplan;
		int x=0;
		/* Fin P-ECU-12026 */
		
int ifnPreparaConsCuot (void)
{
	char *szModulo= "CargaFolioCtc";
	
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

/*   
    sprintf(szhSql,"\n SELECT A.ROWID,                                  "
			          "\n     A.COD_CONCEPTO,                           "
			          "\n     A.NUM_CUOTA,                              "
			          "\n     A.SEC_CUOTA,                              "
			          "\n     A.MTO_CUOTA,                              "
			          "\n     NVL(A.NUM_FOLIO,0),                       "
			          "\n     NUM_FOLIOCTC,                             "
			          "\n     TO_CHAR(A.FEC_COMPRA,:szhFormato_Fecha),  "
			          "\n     A.IND_FACTURADO,                          "
			          "\n     A.COD_TIPDOCUM,                           "
			          "\n     UPPER(B.DES_TIPDOCUM),                    "
			          "\n     TO_CHAR(A.FEC_VENCIMIE,:szhFormato_Fecha),"
			          "\n     A.PREF_PLAZA,                             "
			          "\n     NUM_ABONADO                               "
			         "\n FROM GE_TIPDOCUMEN B,     "
			          "\n     FA_CUOTCREDITO_%s A, "
			          "\n     FA_CICLFACT C        "
			         "\n WHERE A.COD_CLIENTE   = :lhCodClienteCur  "
			         "\n   AND C.COD_CICLFACT  = :lhCodCiclFactCur "
			         "\n   AND A.COD_TIPDOCUM  =  B.COD_TIPDOCUM   "
			         "\n   AND A.FEC_VENCIMIE <=  C.FEC_EMISION    "
			         "\n ORDER BY A.NUM_FOLIO,      "
			                  "\n A.FEC_VENCIMIE  , "
			                  "\n A.IND_FACTURADO , "
			                  "\n A.NUM_SECUENCI  , "
			                  "\n A.COD_TIPDOCUM  , "
			                  "\n A.COLUMNA       , "
			                  "\n A.SEC_CUOTA     , "
			                  "\n A.NUM_CUOTA "
			         ,gszSufTablasCiclo);
	
    EXEC SQL PREPARE Sel_Cuotas_JEM FROM :szhSql;
    vDTrazasLog(szModulo, "Cursor Sel_Cuotas_JEM. [%s]", LOG06,szhSql);
    if( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en PREPARE Sel_Cuotas_JEM. Error [%s]\n%s\n", LOG00, SQLERRM,szhSql);
        return(FALSE);
    }

    EXEC SQL DECLARE Cursor_Cuotas_JEM CURSOR FOR Sel_Cuotas_JEM;
    if( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en DECLARE Cursor_Cuotas_JEM. Error [%s]\n%s\n", LOG00, SQLERRM,szhSql);
        return(FALSE);
    }
*/
    sprintf(szhSql, "UPDATE FA_CUOTCREDITO_%s \n"
                    "   SET IND_ORDENTOTAL = :lhIndOrdenTotal, \n"
                    "       IND_IMPRESO   = 1, \n" 
                    "       IND_FACTURADO = 1, \n" 
                    "       NUM_FOLIOCTC  = :szhNumFolioCtc \n"
										" WHERE COD_CLIENTE = :lhCodCliente \n"
                    " AND NUM_SECUENCI = :lhNumSecuenci \n"
                    " AND COD_TIPDOCUM = :lhCodTipDocum \n"
                    " AND COD_VENDEDOR_AGENTE = :lhCodVendedorAgente \n"
                    " AND ((LETRA = :szhLetra) OR ('X' = :szhLetra)) \n"
                    " AND COD_CENTREMI = :lhCodCentremi \n"
                    " AND COD_CONCEPTO = :lhCodConcepto \n"
                    " AND COLUMNA = :lhColumna \n"   
        			, gszSufTablasCiclo);

    vDTrazasLog  ( szModulo ,"\t\t szhSql = [%s] ***",LOG05, szhSql);

    /* EXEC SQL PREPARE Upd_FACuotCred_FolioCTC FROM :szhSql; */ 

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



    if( sqlca.sqlcode != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en PREPARE Update_FacDocu. Error [%d][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }

    sprintf(szhSql, "UPDATE FA_CUOTCREDITO_%s \n"
                    "   SET IND_ORDENTOTAL = :lhIndOrdenTotal, \n"
                    "       IND_IMPRESO   = 1, \n" 
                    "       IND_FACTURADO = 1 \n" 
										" WHERE COD_CLIENTE = :lhCodCliente \n"
                    " AND NUM_SECUENCI = :lhNumSecuenci \n"
                    " AND COD_TIPDOCUM = :lhCodTipDocum \n"
                    " AND COD_VENDEDOR_AGENTE = :lhCodVendedorAgente \n"
                    " AND ((LETRA = :szhLetra) OR ('X' = :szhLetra)) \n"
                    " AND COD_CENTREMI = :lhCodCentremi \n"
                    " AND COD_CONCEPTO = :lhCodConcepto \n"
                    " AND COLUMNA = :lhColumna \n"                    
        			, gszSufTablasCiclo);

    vDTrazasLog  ( szModulo ,"\t\t szhSql = [%s] ***",LOG05, szhSql);

    /* EXEC SQL PREPARE Upd_FACuotCred FROM :szhSql; */ 

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



    if( sqlca.sqlcode != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en PREPARE Update_FacDocu. Error [%d][%s]", LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
        return(FALSE);
    }
	return TRUE;	
}


/*****************************************************************************/
/*  Funcion para cargar Folio CtC                                            */
/*****************************************************************************/
int CargaFolioCtc(ST_FACTCLIE * pstFactDocuClie, ST_CUOTAS * pstFaCuotas,  STSALDO_ANTERIOR *pstSaldoAnt)
{
    long lFechaSaldoAnt=0;
    long lFechaCuotasVe=0;
    long lFechaCuotasPv=0;

    strcpy (szModulo, "CargaFolioCtc");
    vDTrazasLog  ("","\n\t** Entrando a %s **"
                     "\n\t=> szNumCtc       [%s]"
                     "\n\t=> dTotFactura    [%f]"
                     ,LOG04,szModulo,pstFactDocuClie->szNumCtc, pstFactDocuClie->dTotFactura);

    if(pstFactDocuClie->dTotFactura == 0)
    {
        if((pstSaldoAnt->iNum_RegSaldo > 0) || (pstFaCuotas->iNum_RegCuotas_venci > 0) || (pstFaCuotas->iNum_RegCuotas_pven > 0))
        {
            lFechaSaldoAnt = (pstSaldoAnt->iNum_RegSaldo > 0   ? atol(pstSaldoAnt->stReg[pstSaldoAnt->iNum_RegSaldo-1].szFechaEfectiva) : 0);
            lFechaCuotasVe = (pstFaCuotas->iNum_RegCuotas_venci > 0 ? atol(pstFaCuotas->stReg_venci[pstFaCuotas->iNum_RegCuotas_venci-1].szFechaEfectiva) : 0);
            lFechaCuotasPv = (pstFaCuotas->iNum_RegCuotas_pven  > 0? atol(pstFaCuotas->stReg_pven[pstFaCuotas->iNum_RegCuotas_pven-1].szFechaEfectiva) : 0);

            vDTrazasLog(szModulo, "\tlFechaSaldoAnt  : [%ld]"
                                  "\tlFechaCuotasVe  : [%ld]"
                                  "\tlFechaCuotasPv  : [%ld]",LOG04,
                                  lFechaSaldoAnt,
                                  lFechaCuotasVe,
                                  lFechaCuotasPv);

            if(lFechaSaldoAnt >= lFechaCuotasVe )
            {
                sprintf(pstFactDocuClie->szNumCtcPago,"%s\0", pstSaldoAnt->stReg[pstSaldoAnt->iNum_RegSaldo-1].szNum_FolioCtc);
                vDTrazasLog(szModulo,"\tNumCtcPago de Saldo Ant.: [%s]",LOG04,pstFactDocuClie->szNumCtcPago);
            }
            else
            {
                if(lFechaCuotasVe > lFechaSaldoAnt )
                {
                    sprintf(pstFactDocuClie->szNumCtcPago,"%s\0", pstFaCuotas->stReg_venci[pstFaCuotas->iNum_RegCuotas_venci-1].szNum_FolioCtc);
                    vDTrazasLog(szModulo,"\tNumCtcPago de Cuotas Ven.: [%s]",LOG04,pstFactDocuClie->szNumCtcPago);
                }
            }
            if((lFechaCuotasVe == 0) && (lFechaSaldoAnt == 0) && (lFechaCuotasPv  > 0 ))
            {
                sprintf(pstFactDocuClie->szNumCtcPago,"%s\0", pstFaCuotas->stReg_pven[pstFaCuotas->iNum_RegCuotas_pven-1].szNum_FolioCtc);
                vDTrazasLog(szModulo,"\tNumCtcPago de Cuotas P.V.: [%s]",LOG04,pstFactDocuClie->szNumCtcPago);
            }
            if(strcmp(pstFactDocuClie->szNumCtcPago," ")!=0)
            {
                sprintf(pstFactDocuClie->szNumCtc,"%s\0", pstFactDocuClie->szNumCtcPago);
            }
        }
    }
    return (TRUE);
}
/***********************************************************************************/

int bfnCargaPromTraficoClie(long lCodCliente, 
							long lNumProceso,
							long lCodCiclFact, 
							PROM_CLIE **pstPromTrafClie,
							int *iNumPromClie)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

        long	lhCodCiclFact;
        long	lhCodCliente;
        long	lhNumProceso;
        int     rc = 0;
        int     iNumFilas,iCont;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    static  PROM_CLIE_HOST stPromClieHost;
    PROM_CLIE  *pstPromTrafClieTemp;
    
    strcpy (szModulo, "bfnCargaPromTraficoClie");
    
    if(!lNroJob)
    	lhNumProceso =lNumProceso;
    else
    	lhNumProceso = 0;
	
    vDTrazasLog(szModulo,"\t Entrando en bfnCargaPromTraficoClie"
    					 "\t lCodCliente  [%ld]"
    					 "\t lNumProceso  [%ld]"
    					 "\t lCodCiclFact [%ld]"
    				 	 ,LOG05
    				 	 ,lCodCliente
    				 	 ,lhNumProceso
    				 	 ,lCodCiclFact);
    				 	 
	lhCodCiclFact=lCodCiclFact;
	lhCodCliente =lCodCliente;
	
	*iNumPromClie    = 0;
    *pstPromTrafClie = NULL;
	
	
	if(!ifnOpenPromosClie(lhCodCliente,lhNumProceso,lhCodCiclFact))
		return (FALSE);	

    while ( rc != SQLNOTFOUND )
    {
        rc = ifnFetchPromosClie(&stPromClieHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstPromTrafClie =(PROM_CLIE*) realloc(*pstPromTrafClie,(int)(((*iNumPromClie)+iNumFilas)*sizeof(PROM_CLIE)));
        if ( !*pstPromTrafClie )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaPromTraficoClie", "No se pudo reservar memoria");
            return (FALSE);
        }

        pstPromTrafClieTemp = &(*pstPromTrafClie)[(*iNumPromClie)];
        memset(pstPromTrafClieTemp, 0, (int)(sizeof(PROM_CLIE)*iNumFilas));
        
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
			strcpy(pstPromTrafClieTemp[iCont].szTipoDcto, stPromClieHost.szTipoDcto[iCont]);                                                                                         
			strcpy(pstPromTrafClieTemp[iCont].szCodDcto , stPromClieHost.szCodDcto [iCont]);                                                                                         
			                                                                                                                                                                         
			pstPromTrafClieTemp[iCont].iCodCargo     = stPromClieHost.iCodCargo    [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].dMtoReal      = stPromClieHost.dMtoReal     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].dMtoFact      = stPromClieHost.dMtoFact     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].dMtoDcto      = stPromClieHost.dMtoDcto     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lDurReal      = stPromClieHost.lDurReal     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lDurFact      = stPromClieHost.lDurFact     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lDurDcto      = stPromClieHost.lDurDcto     [iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lCantLlamReal = stPromClieHost.lCantLlamReal[iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lCantLlamFact = stPromClieHost.lCantLlamFact[iCont];                                                                                          
			pstPromTrafClieTemp[iCont].lCantLlamDcto = stPromClieHost.lCantLlamDcto[iCont];                                                                                          
        }
        (*iNumPromClie) += iNumFilas;
    }/* fin while */        
    
	vDTrazasLog (szModulo,"\n\t\t* Promociones de Trafico Cargadas [%d]", LOG06, *iNumPromClie);
	
	if (!ifnClosePromosClie())
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error ifnClosePromosClie", szfnORAerror ());
        return (FALSE);
    }
	return(TRUE);    
}							

/****************************************************************************/
/*  Funcion: int iOpenPromosClie(long, int)                                 */
/*  Funcion que Abre el cursor de Promociones del Cliente                   */
/****************************************************************************/
int ifnOpenPromosClie( long lCodCliente,
					   long lNumProceso, 
					   long lCodCiclFact)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

        long	lhCodCiclFact ;
        long	lhCodCliente  ;
        long 	lhNumProceso  ;
        char    szhCodModulo  [3];
        char    szhNomTabla   [16];
        char    szhNomColumna [9];
        char    szCadenaSQL   [1500];
        char    szNomTablaDin [60];         
    /* EXEC SQL END DECLARE SECTION; */ 

    
    vDTrazasLog(szModulo,"\t Entrando en ifnOpenPromosClie"
    					 "\t lCodCliente  [%ld]"
    					 "\t lNumProceso  [%ld]"
    					 "\t iCodCiclFact [%ld]"
    				 	 ,LOG05
    				 	 ,lCodCliente
    				 	 ,lNumProceso
    				 	 ,lCodCiclFact);
    				 	 
	lhCodCiclFact=lCodCiclFact;
	lhCodCliente =lCodCliente;
	lhNumProceso =lNumProceso;
	strcpy(szhCodModulo,"FA");
	strcpy(szhNomTabla,"TOL_ACUMOPER_TO");
	strcpy(szhNomColumna,"TIP_DCTO");
	
	if(!lNroJob)
		sprintf(szNomTablaDin,"TOL_ACUMOPER_TO");
    else
    	sprintf(szNomTablaDin,"FA_ACUMOPER_%ld_%ld",lhCodCiclFact,lNroJob);
	
	sprintf(szCadenaSQL," SELECT COD_CARG, \n"
						"       TRIM(TIP_DCTO), \n"
						"       NVL(TRIM(COD_DCTO),' '), \n"
						"       SUM(MTO_REAL), \n"
						"       SUM(MTO_FACT), \n"
						"       SUM(MTO_DCTO), \n"
						"       SUM(DUR_REAL), \n"
						"       SUM(DUR_FACT), \n"
						"       SUM(DUR_DCTO), \n"
						"       SUM(CNT_LLAM_REAL), \n"
						"       SUM(CNT_LLAM_FACT), \n"
						"       SUM(CNT_LLAM_DCTO) \n"
						" FROM %s ACUM, \n"
						"       GED_CODIGOS COD \n"
						" WHERE ACUM.COD_CICLFACT = :lhCodCiclFact \n"
						"   AND ACUM.COD_CLIENTE  = :lhCodCliente \n"
						"   AND COD.COD_MODULO    = :szhCodModulo \n"
						"   AND COD.NOM_TABLA     = :szhNomTabla \n"
						"   AND COD.NOM_COLUMNA   = :szhNomColumna \n"
						"   AND ACUM.TIP_DCTO     = COD.COD_VALOR \n"
						"   AND exists (select 1 from %s VAL \n"
						"                where VAL.num_proceso  = :lhNumProceso \n"
						"                  and VAL.cod_ciclfact = acum.COD_CICLFACT \n"
						"                  and VAL.cod_cliente  = acum.cod_cliente \n"
						"                  and VAL.num_abonado  = acum.NUM_ABONADO \n"
						"                  and VAL.COD_OPERADOR = acum.COD_OPERADOR \n" 
						"                  and VAL.COD_REGI     = acum.COD_REGI \n"
						"                  and VAL.COD_GRUPO    = acum.COD_GRUPO \n"  
						"                  and VAL.IND_EXEDENTE = acum.IND_EXEDENTE \n" 
						"                  and VAL.COD_PLAN     = acum.COD_PLAN ) \n"
						"  GROUP BY ACUM.COD_CARG,TRIM(ACUM.TIP_DCTO),TRIM(ACUM.COD_DCTO) "
						,szNomTablaDin,szNomTablaDin);

	/* EXEC SQL PREPARE Query_PromosClie FROM :szCadenaSQL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
 sqlstm.sqhstl[0] = (unsigned long )1500;
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
        vDTrazasLog  (szModulo,"\t\tError en SQL-PREPARE CURSOR Query_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE CURSOR Query_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		return FALSE;                      
    }
    	
	/* EXEC SQL DECLARE Cur_PromosClie CURSOR FOR Query_PromosClie; */ 

    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE CURSOR Cur_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE CURSOR Cur_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		return FALSE;                      
    }	
    
	/* EXEC SQL OPEN Cur_PromosClie USING :lhCodCiclFact, :lhCodCliente, :szhCodModulo, :szhNomTabla, :szhNomColumna, :lhNumProceso; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )62;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCiclFact;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)szhCodModulo;
 sqlstm.sqhstl[2] = (unsigned long )3;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szhNomTabla;
 sqlstm.sqhstl[3] = (unsigned long )16;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)szhNomColumna;
 sqlstm.sqhstl[4] = (unsigned long )9;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&lhNumProceso;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR Cur_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR Cur_PromosClie **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
		return FALSE;                      
    }
    return TRUE;	     
}

/***************************** Inicio ifnFetchPromosClie ****************/
int ifnFetchPromosClie(PROM_CLIE_HOST * pst_PromClieHost, int *iCantPromos)
{
    char *szModulo="ifnFetchPromosClie";

    /* EXEC SQL FETCH Cur_PromosClie
    INTO    
    	:pst_PromClieHost->iCodCargo    ,
    	:pst_PromClieHost->szTipoDcto   ,
    	:pst_PromClieHost->szCodDcto    ,
    	:pst_PromClieHost->dMtoReal     ,
    	:pst_PromClieHost->dMtoFact     ,
    	:pst_PromClieHost->dMtoDcto     ,
    	:pst_PromClieHost->lDurReal     ,
    	:pst_PromClieHost->lDurFact     ,
    	:pst_PromClieHost->lDurDcto     ,
    	:pst_PromClieHost->lCantLlamReal,
    	:pst_PromClieHost->lCantLlamFact,
    	:pst_PromClieHost->lCantLlamDcto; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )5000;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pst_PromClieHost->iCodCargo);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pst_PromClieHost->szTipoDcto);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pst_PromClieHost->szCodDcto);
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )6;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pst_PromClieHost->dMtoReal);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[3] = (         int  )sizeof(double);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pst_PromClieHost->dMtoFact);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[4] = (         int  )sizeof(double);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pst_PromClieHost->dMtoDcto);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[5] = (         int  )sizeof(double);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pst_PromClieHost->lDurReal);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )sizeof(long);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pst_PromClieHost->lDurFact);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )sizeof(long);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pst_PromClieHost->lDurDcto);
    sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[8] = (         int  )sizeof(long);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pst_PromClieHost->lCantLlamReal);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[9] = (         int  )sizeof(long);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(pst_PromClieHost->lCantLlamFact);
    sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[10] = (         int  )sizeof(long);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(pst_PromClieHost->lCantLlamDcto);
    sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[11] = (         int  )sizeof(long);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
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



        
    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {   
		vDTrazasError(szModulo,"\t\tError en Fetch %s : %s", LOG01, szModulo, SQLERRM);
    }else{
        *iCantPromos = sqlca.sqlerrd[2];
    }
    return (SQLCODE);
}/***************************** Final ifnFetchPromosClie ****************/

int ifnClosePromosClie(void)                                                         
{
    strcpy (szModulo, "ifnClosePromosClie");
    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);

    /* EXEC SQL CLOSE Cur_PromosClie; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )164;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(SQLCODE != SQLOK) 
    {
        vDTrazasError(szModulo,"\t\tError al cerrar el Cursor Cur_PromosClie: %s",LOG01, SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}/****************Final de ifnClosePromosClie *******************/


/****************************************************************************/
/* Funcion: BOOL bfnCargaConcTrafico (FACTDOC *stHistD)                     */
/* Funcion que crea cursosr con conceptos de trafico facturado por abonado  */
/* luego para cada abonado genera un registro por Abonado que contiene los  */
/* datos por abonado : Num.Celular, indicadores de tablas de tarfico y      */
/* totales facturados                                                       */
/****************************************************************************/
int CargaConceptosDelCliente (ST_FACTCLIE    *pstFactDocuClie,
                              LINEACOMANDO   *pstLineaComando,
                              ST_INFGENERAL  *pstInfGeneral,
                              DETALLEOPER    *pstDetallOper)
{
    int  iSqlCodeConceptos ;
    char szCodSubGrup [11];
    long  i = 0;
    GRPMULTIIDIOMA pstIdiomaAux;
    static ST_DETCONSUMO_HOST pstFaDetConsumoHosts;
    int rc = 0;
    long lNumFilas = 0;
    STDETCONSUMO  *stDetConsumoTemp;
    ST_ORDEN  *stOrden2DetConsumoTemp;
    register int iCont=0;


    strcpy (szModulo, "CargaConceptosDelCliente");
    vDTrazasLog(szModulo,"\t**IndOrdenTotal  [%ld]",LOG05,pstFactDocuClie->lIndOrdenTotal);

    iSqlCodeConceptos = OpenConceptos ( pstFactDocuClie->lIndOrdenTotal,
                                        pstLineaComando->lCodCiclFact,
                                        pstInfGeneral->szCOD_SERVICIO,
                                        pstDetallOper->iCodFormulario,
                                        pstDetallOper,
                                        pstFactDocuClie->iCodTipDocum);

    vDTrazasLog(szModulo,"\t**iSqlCodeConceptos  [%d]",LOG05, iSqlCodeConceptos);

    if(iSqlCodeConceptos != SQLOK)
        return (FALSE);

    while (rc != SQLNOTFOUND)
    {
		
        rc = FetchConceptos(&pstFaDetConsumoHosts,&lNumFilas);
        if (rc != SQLOK  && rc != SQLNOTFOUND)
            return FALSE;

        if (!lNumFilas)
            break;

        /* Estructura global de detalle de conceptos */
        stFaDetCons.stDetConsumo =(STDETCONSUMO*) realloc(stFaDetCons.stDetConsumo,(((stFaDetCons.iNumReg) + lNumFilas )*sizeof(STDETCONSUMO)));
        if (!stFaDetCons.stDetConsumo)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Error CargaConceptosDelCliente","no se pudo reservar memoria");
            return FALSE;
        }

        stDetConsumoTemp = &(stFaDetCons.stDetConsumo)[(stFaDetCons.iNumReg)];
        memset(stDetConsumoTemp, 0, sizeof(STDETCONSUMO) * lNumFilas);

        /* estructura de orden alterno */
        stOrden2DetConsumo.stOrden =(ST_ORDEN*) realloc(stOrden2DetConsumo.stOrden,(((stOrden2DetConsumo.iNumRegs)+lNumFilas)*sizeof(ST_ORDEN)));
        if (!stOrden2DetConsumo.stOrden)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                          "Error CargaConceptosDelCliente", "no se pudo reservar memoria");
            return FALSE;
        }
        stOrden2DetConsumoTemp = &(stOrden2DetConsumo.stOrden)[(stOrden2DetConsumo.iNumRegs)];
        memset(stOrden2DetConsumoTemp, 0, sizeof(ST_ORDEN)*lNumFilas);

        if (stFaDetCons.iNumReg == 0) /* Es el primer registro leçdo, entonces se asignan valores del plan */
        {
			
           strcpy(szPlan,pstFaDetConsumoHosts.szCod_PlanTarif[0]);
           strcpy(sDescPlanTarif,pstFaDetConsumoHosts.szDesPlanTarif[0]);
        }

        for (iCont = 0; iCont < lNumFilas; iCont++)
        {
        	
        	
			vDTrazasLog("TRAZA TMAS","\t**Entra al FOR  [%d]",LOG05);
			
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iNum_OrdenGr);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iNum_OrdenConc);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCodGrupo);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iNum_OrdenSubGr);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCodSubGrupo);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCod_TipSubGrupo);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lNumAbonado);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCod_Producto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCodConcepto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iColumna);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCodTipConce);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lSeg_Consumo);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iNum_Unidades);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dTotalFacturableNet);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dTotalFacturableImp);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lSeg_ConsumoReal);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lSeg_ConsumoDcto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dTotalFacturableReal);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dTotalFacturableDcto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lCntLlamReal);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lCntLlamDcto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lCntLlamFAct);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dImpValUnitario);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iCodConcerel);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iColumnaRel);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dPrcImpuesto);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dImpMontoBase);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iTipConcep);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].iNivelImpresion);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lNumVenta);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].dSumDescuentos);
			vDTrazasLog("TRAZA TMAS","\t**-- [%d]",LOG05 , stDetConsumoTemp[iCont].lCantDescuentos);

            stDetConsumoTemp[iCont].iNum_OrdenGr               = pstFaDetConsumoHosts.iNum_OrdenGr        [iCont] ;
            stDetConsumoTemp[iCont].iNum_OrdenConc             = pstFaDetConsumoHosts.iNum_OrdenConc      [iCont] ;
            stDetConsumoTemp[iCont].iCodGrupo                  = pstFaDetConsumoHosts.iCodGrupo           [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szGlosaGrupo        , pstFaDetConsumoHosts.szGlosaGrupo        [iCont]);
            stDetConsumoTemp[iCont].iNum_OrdenSubGr            = pstFaDetConsumoHosts.iNum_OrdenSubGr     [iCont] ;
            stDetConsumoTemp[iCont].iCodSubGrupo               = pstFaDetConsumoHosts.iCodSubGrupo        [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szGlosaSubGrupo     , pstFaDetConsumoHosts.szGlosaSubGrupo     [iCont]);
            stDetConsumoTemp[iCont].iCod_TipSubGrupo           = pstFaDetConsumoHosts.iCod_TipSubGrupo    [iCont] ;
            stDetConsumoTemp[iCont].lNumAbonado                = pstFaDetConsumoHosts.lNumAbonado         [iCont] ;
            stDetConsumoTemp[iCont].iCod_Producto              = pstFaDetConsumoHosts.iCod_Producto       [iCont] ;
            stDetConsumoTemp[iCont].iCodConcepto               = pstFaDetConsumoHosts.iCodConcepto        [iCont] ;
            stDetConsumoTemp[iCont].iColumna                   = pstFaDetConsumoHosts.iColumna            [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szDes_Concepto      , pstFaDetConsumoHosts.szDes_Concepto      [iCont]);
            stDetConsumoTemp[iCont].iCodTipConce               = pstFaDetConsumoHosts.iCodTipConce        [iCont] ;
            stDetConsumoTemp[iCont].lSeg_Consumo               = pstFaDetConsumoHosts.lSeg_Consumo        [iCont] ;
            stDetConsumoTemp[iCont].iNum_Unidades              = pstFaDetConsumoHosts.iNum_Unidades       [iCont] ;
            stDetConsumoTemp[iCont].dTotalFacturableNet        = pstFaDetConsumoHosts.dTotalFacturableNet [iCont] ;
            stDetConsumoTemp[iCont].dTotalFacturableImp        = pstFaDetConsumoHosts.dTotalFacturableImp [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szNum_Celular       , pstFaDetConsumoHosts.szNum_Celular       [iCont]);
            strcpy(stDetConsumoTemp[iCont].szCod_Nivel         , pstFaDetConsumoHosts.szCod_Nivel         [iCont]);
            strcpy(stDetConsumoTemp[iCont].szFec_Pago          , pstFaDetConsumoHosts.szFec_Pago          [iCont]);
            strcpy(stDetConsumoTemp[iCont].szCod_CargoBasico   , pstFaDetConsumoHosts.szCod_CargoBasico   [iCont]);
            strcpy(stDetConsumoTemp[iCont].szTip_ConcNoFact    , pstFaDetConsumoHosts.szTip_ConcNoFact    [iCont]);
            strcpy(stDetConsumoTemp[iCont].szCod_PlanTarif     , pstFaDetConsumoHosts.szCod_PlanTarif     [iCont]);
            strcpy(stDetConsumoTemp[iCont].szFec_FinContrato   , pstFaDetConsumoHosts.szFec_FinContrato   [iCont]);
            stDetConsumoTemp[iCont].lSeg_ConsumoReal           = pstFaDetConsumoHosts.lSeg_ConsumoReal    [iCont] ;
            stDetConsumoTemp[iCont].lSeg_ConsumoDcto           = pstFaDetConsumoHosts.lSeg_ConsumoDcto    [iCont] ;
            stDetConsumoTemp[iCont].dTotalFacturableReal       = pstFaDetConsumoHosts.dTotalFacturableReal[iCont] ;
            stDetConsumoTemp[iCont].dTotalFacturableDcto       = pstFaDetConsumoHosts.dTotalFacturableDcto[iCont] ;
            stDetConsumoTemp[iCont].lCntLlamReal               = pstFaDetConsumoHosts.lCntLlamReal        [iCont] ;
            stDetConsumoTemp[iCont].lCntLlamDcto               = pstFaDetConsumoHosts.lCntLlamDcto        [iCont] ;
            stDetConsumoTemp[iCont].lCntLlamFAct               = pstFaDetConsumoHosts.lCntLlamFAct        [iCont] ;
            stDetConsumoTemp[iCont].dImpValUnitario            = pstFaDetConsumoHosts.dImpValUnitario     [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szGlsDescrip        , pstFaDetConsumoHosts.szGlsDescrip        [iCont]);
            stDetConsumoTemp[iCont].iCodConcerel               = pstFaDetConsumoHosts.iCodConcerel        [iCont] ;
            stDetConsumoTemp[iCont].iColumnaRel                = pstFaDetConsumoHosts.iColumnaRel         [iCont] ;
            stDetConsumoTemp[iCont].dPrcImpuesto               = pstFaDetConsumoHosts.dPrcImpuesto        [iCont] ;
            stDetConsumoTemp[iCont].dImpMontoBase              = pstFaDetConsumoHosts.dImpMontoBase       [iCont] ;
            stDetConsumoTemp[iCont].iTipConcep                 = pstFaDetConsumoHosts.iTipConcep          [iCont] ;
            stDetConsumoTemp[iCont].iNivelImpresion            = pstFaDetConsumoHosts.iNivelImpresion     [iCont] ;
            strcpy(stDetConsumoTemp[iCont].szTipUnidad         , pstFaDetConsumoHosts.szTipUnidad         [iCont]);
            strcpy(stDetConsumoTemp[iCont].szTipGrupo          , pstFaDetConsumoHosts.szTipGrupo          [iCont]);
            stDetConsumoTemp[iCont].lNumVenta                  = pstFaDetConsumoHosts.lNumVenta           [iCont] ;
            
            stDetConsumoTemp[iCont].dSumDescuentos             = pstFaDetConsumoHosts.dSumDescuentos      [iCont] ; /* ECU-10012 */
            stDetConsumoTemp[iCont].lCantDescuentos            = pstFaDetConsumoHosts.lCantDescuentos     [iCont] ; /* ECU-10012 */
            
            sprintf(szModulo, "Carga Nuevas columnas (%15.4f|%10.10ld)"
                            , stDetConsumoTemp[iCont].dSumDescuentos
                            , stDetConsumoTemp[iCont].lCantDescuentos);

            sprintf(stOrden2DetConsumoTemp[iCont].szKey, "%05d|%05d|%05d|%05d|%05d|%05d",
                                                         stDetConsumoTemp[iCont].iNum_OrdenGr,
                                                         stDetConsumoTemp[iCont].iNum_OrdenSubGr,
                                                         stDetConsumoTemp[iCont].iNum_OrdenConc,
                                                         stDetConsumoTemp[iCont].iCodGrupo,
                                                         stDetConsumoTemp[iCont].iCodSubGrupo,
                                                         stDetConsumoTemp[iCont].iCodConcepto );
            stOrden2DetConsumoTemp[iCont].iPosicion = stFaDetCons.iNumReg + iCont;
        }
        stFaDetCons.iNumReg += lNumFilas;
        stOrden2DetConsumo.iNumRegs += lNumFilas;
    }/*FIN WHILE*/

    if(!CloseConceptos())
        return (FALSE);

    vDTrazasLog(szModulo,"\t====> Cantidad de Conceptos por Cliente [%d]\n"
                         "\tIdioma Operadora [%s] Idioma Cliente [%s]\n",
                         LOG05,
                         stFaDetCons.iNumReg,
                         pstInfGeneral->szIdiomaOper,
                         pstFactDocuClie->szCod_Idioma);

    if(strcmp(pstInfGeneral->szIdiomaOper,pstFactDocuClie->szCod_Idioma) != 0)
    {
        for(i = 0; i < stFaDetCons.iNumReg ; i++)
        {
			
            sprintf(szCodSubGrup,"%04d%s",stFaDetCons.stDetConsumo[i].iCodSubGrupo,pstFactDocuClie->szCod_Idioma);
            vDTrazasLog(szModulo,"Concepto [%s]",LOG04,szCodSubGrup);
            if (BuscaMultiIdiomas(szCodSubGrup,&pstIdiomaAux))
            {
                strcpy(stFaDetCons.stDetConsumo[i].szGlosaGrupo,pstIdiomaAux.szGlosa_Grupo);
                strcpy(stFaDetCons.stDetConsumo[i].szGlosaSubGrupo,pstIdiomaAux.szGlosa_Subgrp);
            }
            else
            {
				
                vDTrazasLog(szModulo,"\tSubGrupo [%d] no encontrado en Ge_MultiIdioma con el idioma [%s]" ,LOG03,stFaDetCons.stDetConsumo[i].iCodSubGrupo,pstFactDocuClie->szCod_Idioma);
            }
        }
    }
    /* Se ordena la estructura de orden alterno */
    qsort((void*)stOrden2DetConsumo.stOrden, stOrden2DetConsumo.iNumRegs, sizeof(ST_ORDEN),ifnCmpOrden);

    return (TRUE);

}/************************* Fin CargaConceptosDelCliente ********************/


/****************************************************************************/
/*  Funcion: int ifnOpenConcTrafico(long, long)                             */
/*  Funcion que Abre el cursor de Conceptos de Trafico Facturados           */
/****************************************************************************/
int OpenConceptos ( long        lIndOrdenTotal,
                    long        lCodCiclFact,
                    char        *szCod_Servicio, 
                    int         iCodFormulario,
                    DETALLEOPER *pstDetallOper,
                    int         iCodTipDocum)
{
    char    szTablaConc [50]    ="";
    char    szTablaAbon [50]    ="";
    char    szFlagB06[200];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

         long lhIndOrdenTotal;
         char szhCod_Servicio[4];
         int  ihCodFormulario;
         int  ihNumTerminales;
         int  ihCodTipConce; /* ECU-10012 */
         char szCadenaSQL [32000];         
    /* EXEC SQL END DECLARE SECTION; */ 


    lhIndOrdenTotal = lIndOrdenTotal;
    strcpy(szhCod_Servicio,  szCod_Servicio);
    ihCodFormulario = iCodFormulario;
    ihCodTipConce = 2; /* DESCUENTOS */ /* ECU-10012 */

    strcpy (szModulo, "OpenConceptos");
    vDTrazasLog(szModulo,"\t** EN FUNCION ...(%s)", LOG06,szModulo);

    if (BuscaMascara(pstDetallOper,"A1100",iCodTipDocum))
        strcpy(szFlagB06,"\nAND COD_TIPSUBGRUPO != 6");
    else
        strcpy(szFlagB06,"");

    if ( !lCodCiclFact )
    {
        sprintf(szTablaAbon,"FA_FACTABON_NOCICLO");
        sprintf(szTablaConc,"FA_FACTCONC_NOCICLO");
    }
    else
    {
        if(!lNroJob)
        {
            sprintf(szTablaAbon,"FA_FACTABON_%ld",lCodCiclFact);
            sprintf(szTablaConc,"FA_FACTCONC_%ld",lCodCiclFact);
        }
        else
        {
            sprintf(szTablaAbon,"FA_FACTABON_%ld_%ld",lCodCiclFact,lNroJob);
            sprintf(szTablaConc,"FA_FACTCONC_%ld_%ld",lCodCiclFact,lNroJob);

        }
    }

    vDTrazasLog(szModulo,"\t******* Abriendo Conceptos de Trafico...(%ld) (%ld) *******", LOG06,lIndOrdenTotal,lCodCiclFact);

    memset(szCadenaSQL,'\0',sizeof(szCadenaSQL));

    sprintf(szCadenaSQL,
            "\n SELECT COUNT(DISTINCT NUM_ABONADO)"
            "\n FROM    %s A"
            "\n WHERE   IND_ORDENTOTAL = %ld"
            "\n AND     NUM_ABONADO    > 0"
            "\n AND     NUM_CELULAR  IS NOT NULL"
            "\n AND EXISTS (SELECT NULL"
            "\n             FROM %s B"
            "\n             WHERE A.IND_ORDENTOTAL = B.IND_ORDENTOTAL"
            "\n             AND A.NUM_ABONADO = B.NUM_ABONADO)", szTablaAbon,lhIndOrdenTotal,szTablaConc);


    /* EXEC SQL PREPARE QueryCantTerminales FROM :szCadenaSQL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )179;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
    sqlstm.sqhstl[0] = (unsigned long )32000;
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


    /* EXEC SQL DECLARE curCantTermionales CURSOR FOR QueryCantTerminales; */ 

    /* EXEC SQL OPEN curCantTermionales; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )198;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL FETCH curCantTermionales INTO :ihNumTerminales; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )213;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihNumTerminales;
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


    /* EXEC SQL CLOSE curCantTermionales ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )232;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    iNumTerminales = ihNumTerminales;

    vDTrazasLog(szModulo,"\t\t szCadenaSQL iNumTerminales:[%s] \n",LOG05,szCadenaSQL);

    vDTrazasLog(szModulo,"\t\t iNumTerminales:[%d] \n",LOG05,iNumTerminales);

    memset(szCadenaSQL,0,sizeof(szCadenaSQL));

    vDTrazasLog(szModulo,"\t\t TABLAS : iCodAbonoCel[%d],szTablaAbon [%s],szTablaConc [%s] \n",LOG05,iCodAbonoCel,szTablaAbon,szTablaConc);

    memset(szCadenaSQL,'\0',sizeof(szCadenaSQL));

    sprintf(szCadenaSQL,"SELECT"
                        "\n   D.NUM_ORDEN,"
                        "\n   D.COD_GRUPO,"
                        "\n   NVL(D.DES_GLOSA, ' ') DES_GLOSA,"
                        "\n   C.NUM_ORDEN NUM_ORDEN2,"
                        "\n   C.COD_SUBGRUPO,"
                        "\n   NVL(C.DES_GLOSA,' ') DES_GLOSA2,"
                        "\n   C.COD_TIPSUBGRUPO,"
                        "\n   A.NUM_ABONADO,"
                        "\n   A.COD_PRODUCTO,"
                        "\n   A.COD_CONCEPTO,"
                        "\n   A.COLUMNA,"
                        "\n   REPLACE(A.DES_CONCEPTO,'%%') DES_CONCEPTO,"
                        "\n   A.COD_TIPCONCE ,"
                        "\n   A.SEG_CONSUMIDO,"
                        "\n   NVL(A.NUM_UNIDADES,0) NUM_UNIDADES,"
                        "\n   A.IMP_FACTURABLE,"
                        "\n   0 CAMPO1,"
                        "\n   TO_CHAR(NVL(E.NUM_CELULAR,0)) NUM_CELULAR,"
                        "\n   G.COD_NIVEL,"
                        "\n   TO_CHAR(A.FEC_VALOR,'YYYYMMDD') FEC_VALOR,"
                        "\n   NVL(A.COD_CARGOBASICO,' ') COD_CARGOBASICO,"
                        "\n   ' ' TIP_CONCNOFACT,"
                        "\n   NVL(A.COD_PLANTARIF,' ') COD_PLANTARIF,"
                        "\n   NVL(TO_CHAR(E.FEC_FINCONTRA,'YYYYMMDD'),' ') FEC_FINCONTRA,"
                        "\n   B.NUM_ORDEN NUM_ORDEN3,"
                        "\n   NVL(A.DUR_REAL,0) DUR_REAL,"
                        "\n   NVL(A.DUR_DCTO,0) DUR_DCTO,"
                        "\n   NVL(A.IMP_REAL,0) IMP_REAL,"
                        "\n   NVL(A.IMP_DCTO,0) IMP_DCTO, "
                        "\n   NVL(A.CNT_LLAM_REAL,0) CNT_LLAM_REAL,"
                        "\n   NVL(A.CNT_LLAM_DCTO,0) CNT_LLAM_DCTO,"
                        "\n   NVL(A.CNT_LLAM_FACT,0) CNT_LLAM_FACT, "
                        "\n   A.IMP_VALUNITARIO, "
                        "\n   NVL(A.GLS_DESCRIP, ' ') GLS_DESCRIP, "
                        "\n   A.COD_CONCEREL,"
                        "\n   A.COLUMNA_REL,"
                        "\n   A.PRC_IMPUESTO,"
                        "\n   A.IMP_MONTOBASE,"
                        "\n   B.TIP_CONCEP,"
                        "\n   NVL(D.NIV_IMPRESION,0) NIV_IMPRESION,"
                        "\n   NVL(D.TIP_UNIDAD,'     ') TIP_UNIDAD,"
                        "\n   NVL(D.TIP_GRUPO,'     ') TIP_GRUPO,"
                        "\n   NVL(A.NUM_VENTA,0) NUM_VENTA,"
                        "\n   DECODE(A.COD_CONCEPTO, %d, NVL((SELECT DES_PLANTARIF FROM TA_PLANTARIF WHERE COD_PLANTARIF = A.COD_PLANTARIF),' '), 'XXX') DES_PLANTARIF, "                        
                        "\n   (SELECT NVL(SUM(IMP_FACTURABLE)*-1,0) " /* ECU-10012 */
                        "\n    FROM %s "
                        "\n    WHERE IND_ORDENTOTAL = :lhIndOrdenTotal "
                        "\n    AND COD_TIPCONCE = :ihCodTipConce "
                        "\n    AND COD_CONCEREL = A.COD_CONCEPTO "
                        "\n    AND COLUMNA_REL  = A.COLUMNA) SUM_DESCUENTOS," /* ECU-10012 */
                        "\n   (SELECT COUNT(1) " /* ECU-10012 */
                        "\n    FROM %s "
                        "\n    WHERE IND_ORDENTOTAL = :lhIndOrdenTotal "
                        "\n    AND COD_TIPCONCE = :ihCodTipConce "
                        "\n    AND COD_CONCEREL = A.COD_CONCEPTO "
                        "\n    AND COLUMNA_REL  = A.COLUMNA) CANT_DESCUENTOS " /* ECU-10012 */                        
                        "\nFROM"
                        "\n   FAD_IMPSERVIMPRES G,"
                        "\n   %s E,"
                        "\n   FAD_IMPGRUPOS D,"
                        "\n   FAD_IMPSUBGRUPOS C,"
                        "\n   FAD_IMPCONCEPTOS B,"
                        "\n   %s A "
                        "\nWHERE"
                        "\n    A.IND_ORDENTOTAL    = :lhIndOrdenTotal "
                        "\nAND A.IND_ORDENTOTAL    = E.IND_ORDENTOTAL(+) "
                        "\nAND A.NUM_ABONADO       = E.NUM_ABONADO(+) "
                        "\nAND A.COD_CONCEPTO      = B.COD_CONCEPTO "
                        "\nAND B.COD_SUBGRUPO      = C.COD_SUBGRUPO "
                        "\nAND C.COD_GRUPO         = D.COD_GRUPO "
                        "\nAND D.COD_FORMULARIO    = :ihCodFormulario "
                        "\nAND G.COD_SERVICIO      = TRIM(:szhCod_Servicio) "
                        "\nAND G.COD_FORMULARIO    = D.COD_FORMULARIO "
                        "\nAND G.COD_GRUPO         = D.COD_GRUPO "
                        "\nUNION ALL "
                        "\nSELECT"
                        "\n   %d NUM_ORDEN,"
                        "\n   AG.COD_GRUPO,"
                        "\n   NVL(AG.DES_GLOSA,' ') DES_GLOSA,"
                        "\n   BG.NUM_ORDEN NUM_ORDEN2,"
                        "\n   BG.COD_SUBGRUPO,"
                        "\n   NVL(BG.DES_GLOSA,' ') DES_GLOSA2,"
                        "\n   BG.COD_TIPSUBGRUPO,"
                        "\n   0 NUM_ABONADO,"
                        "\n   0 COD_PRODUCTO,"
                        "\n   0 COD_CONCEPTO,"
                        "\n   0 COLUMNA,"
                        "\n   ' ' DES_CONCEPTO,"
                        "\n   0 COD_TIPCONCE,"
                        "\n   -1 SEG_CONSUMIDO,"
                        "\n   0 NUM_UNIDADES,"
                        "\n   0 IMP_FACTURABLE,"
                        "\n   -1 CAMPO1,"
                        "\n   '0' NUM_CELULAR,"
                        "\n   DG.COD_NIVEL ,"
                        "\n   ' ' FEC_VALOR,"
                        "\n   ' ' COD_CARGOBASICO,"
                        "\n   CG.TIP_CONCNOFACT,"
                        "\n   ' ' COD_PLANTARIF,"
                        "\n   ' ' FEC_FINCONTRA,"
                        "\n   0 NUM_ORDEN3,"
                        "\n   0 DUR_REAL,"
                        "\n   0 DUR_DCTO,"
                        "\n   0 IMP_REAL,"
                        "\n   0 IMP_DCTO,"
                        "\n   0 CNT_LLAM_REAL,"
                        "\n   0 CNT_LLAM_DCTO,"
                        "\n   0 CNT_LLAM_FACT, "
                        "\n   0 IMP_VALUNITARIO, "
                        "\n   ' ' GLS_DESCRIP,"
                        "\n   0 COD_CONCEREL,"
                        "\n   0 COLUMNA_REL,"
                        "\n   0 PRC_IMPUESTO,"
                        "\n   0 IMP_MONTOBASE,"
                        "\n   0 TIP_CONCEP,"
                        "\n   0 NIV_IMPRESION,"
                        "\n  ' ' TIP_UNIDAD,"
                        "\n  ' ' TIP_GRUPO,"
                        "\n   0 NUM_VENTA,"
                        "\n  ' ' DES_PLANTARIF," /* ECU-10012 */
                        "\n   0 SUM_DESCUENTOS," /* ECU-10012 */
                        "\n   0 CANT_DESCUENTOS "
                        "\nFROM"
                        "\n   FAD_IMPGRUPOS AG,"
                        "\n   FAD_IMPSUBGRUPOS BG,"
                        "\n   FAD_IMPCONC_NOFACT CG,"
                        "\n   FAD_IMPSERVIMPRES DG "
                        "\nWHERE"
                        "\n    DG.COD_FORMULARIO = :ihCodFormulario "
                        "\nAND DG.COD_SERVICIO = TRIM(:szhCod_Servicio) "
                        "\nAND DG.COD_GRUPO = AG.COD_GRUPO "
                        "\nAND DG.COD_GRUPO = BG.COD_GRUPO "
                        "\nAND BG.COD_SUBGRUPO > 0 "
                        "\nAND BG.COD_SUBGRUPO = CG.COD_SUBGRUPO "
                        "%s"
                        "\nORDER BY 18,8,1,4,25,11 "                        
                        ,iCodAbonoCel,szTablaConc,szTablaConc,szTablaAbon,szTablaConc,NO_FACTURABLE,szFlagB06); /* ECU-10012 */

    vDTrazasLog(szModulo,"QRY OpenConceptos : [%s]\n",LOG05,szCadenaSQL);

    /* EXEC SQL PREPARE sql_Conceptos_DetLlam FROM :szCadenaSQL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )247;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
    sqlstm.sqhstl[0] = (unsigned long )32000;
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
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_Conceptos_DetLlam **"
                                        "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    /* EXEC SQL DECLARE curConcTrafico CURSOR FOR sql_Conceptos_DetLlam; */ 

    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE curConcTrafico **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE curConcTrafico **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    vDTrazasLog  ("ImpSclB:OpenConceptos", "\t\t ****** OPEN curConcTrafico using [%ld] [%d] [%ld] [%d] [%ld] [%d] [%s] [%d] [%s] **"
                                         , LOG05
                                         , lhIndOrdenTotal
                                         , ihCodTipConce
                                         , lhIndOrdenTotal
                                         , ihCodTipConce
                                         , lhIndOrdenTotal
                                         , ihCodFormulario
                                         , szhCod_Servicio
                                         , ihCodFormulario
                                         , szhCod_Servicio);

    /* EXEC SQL OPEN curConcTrafico USING :lhIndOrdenTotal,
                                       :ihCodTipConce,
                                       :lhIndOrdenTotal,
                                       :ihCodTipConce,
                                       :lhIndOrdenTotal, 
                                       :ihCodFormulario, 
                                       :szhCod_Servicio, 
                                       :ihCodFormulario, 
                                       :szhCod_Servicio; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )266;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhIndOrdenTotal;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodTipConce;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhIndOrdenTotal;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipConce;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhIndOrdenTotal;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihCodFormulario;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szhCod_Servicio;
    sqlstm.sqhstl[6] = (unsigned long )4;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&ihCodFormulario;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)szhCod_Servicio;
    sqlstm.sqhstl[8] = (unsigned long )4;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
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
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curConcTrafico **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curConcTrafico **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);                               
    }
    return (SQLCODE);
}/************************ Final de OpenConceptos ***********************/


/************************************************************************/
/* Fon: int ifnFetchConcTrafico(FACTDOC *)                              */
/* Fon que realiza Fetch en el cursor de curFactDoc                     */
/************************************************************************/
int FetchConceptos(ST_DETCONSUMO_HOST *pstConcTrafico, long *plNumFilas)
{
    strcpy (szModulo, "FetchConceptos");
    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG06,szModulo);

    /* EXEC SQL FETCH curConcTrafico
    INTO :pstConcTrafico->iNum_OrdenGr         ,
         :pstConcTrafico->iCodGrupo            ,
         :pstConcTrafico->szGlosaGrupo         ,
         :pstConcTrafico->iNum_OrdenSubGr      ,
         :pstConcTrafico->iCodSubGrupo         ,
         :pstConcTrafico->szGlosaSubGrupo      ,
         :pstConcTrafico->iCod_TipSubGrupo     ,
         :pstConcTrafico->lNumAbonado          ,
         :pstConcTrafico->iCod_Producto        ,
         :pstConcTrafico->iCodConcepto         ,
         :pstConcTrafico->iColumna             ,
         :pstConcTrafico->szDes_Concepto       ,
         :pstConcTrafico->iCodTipConce         ,
         :pstConcTrafico->lSeg_Consumo         ,
         :pstConcTrafico->iNum_Unidades        ,
         :pstConcTrafico->dTotalFacturableNet  ,
         :pstConcTrafico->dTotalFacturableImp  ,
         :pstConcTrafico->szNum_Celular        ,
         :pstConcTrafico->szCod_Nivel          ,
         :pstConcTrafico->szFec_Pago           ,
         :pstConcTrafico->szCod_CargoBasico    ,
         :pstConcTrafico->szTip_ConcNoFact     ,
         :pstConcTrafico->szCod_PlanTarif      ,
         :pstConcTrafico->szFec_FinContrato    ,
         :pstConcTrafico->iNum_OrdenConc       ,
         :pstConcTrafico->lSeg_ConsumoReal     ,
         :pstConcTrafico->lSeg_ConsumoDcto     ,
         :pstConcTrafico->dTotalFacturableReal ,
         :pstConcTrafico->dTotalFacturableDcto ,
         :pstConcTrafico->lCntLlamReal         ,
         :pstConcTrafico->lCntLlamDcto         ,
         :pstConcTrafico->lCntLlamFAct         ,
         :pstConcTrafico->dImpValUnitario      ,
         :pstConcTrafico->szGlsDescrip         ,
         :pstConcTrafico->iCodConcerel         ,
         :pstConcTrafico->iColumnaRel          ,
         :pstConcTrafico->dPrcImpuesto         ,
         :pstConcTrafico->dImpMontoBase        ,
         :pstConcTrafico->iTipConcep           ,
         :pstConcTrafico->iNivelImpresion      ,
         :pstConcTrafico->szTipUnidad          ,
         :pstConcTrafico->szTipGrupo           ,
         :pstConcTrafico->lNumVenta            ,
         :pstConcTrafico->szDesPlanTarif       ,
         :pstConcTrafico->dSumDescuentos       , /o ECU-10012 o/
         :pstConcTrafico->lCantDescuentos      ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )20000;
    sqlstm.offset = (unsigned int  )317;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstConcTrafico->iNum_OrdenGr);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstConcTrafico->iCodGrupo);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )sizeof(int);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstConcTrafico->szGlosaGrupo);
    sqlstm.sqhstl[2] = (unsigned long )51;
    sqlstm.sqhsts[2] = (         int  )51;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstConcTrafico->iNum_OrdenSubGr);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(int);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstConcTrafico->iCodSubGrupo);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(int);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstConcTrafico->szGlosaSubGrupo);
    sqlstm.sqhstl[5] = (unsigned long )51;
    sqlstm.sqhsts[5] = (         int  )51;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstConcTrafico->iCod_TipSubGrupo);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(int);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstConcTrafico->lNumAbonado);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )sizeof(long);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstConcTrafico->iCod_Producto);
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(int);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstConcTrafico->iCodConcepto);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(int);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(pstConcTrafico->iColumna);
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(int);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(pstConcTrafico->szDes_Concepto);
    sqlstm.sqhstl[11] = (unsigned long )61;
    sqlstm.sqhsts[11] = (         int  )61;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)(pstConcTrafico->iCodTipConce);
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )sizeof(int);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)(pstConcTrafico->lSeg_Consumo);
    sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[13] = (         int  )sizeof(long);
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)(pstConcTrafico->iNum_Unidades);
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )sizeof(int);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)(pstConcTrafico->dTotalFacturableNet);
    sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )sizeof(double);
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqharc[15] = (unsigned long  *)0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)(pstConcTrafico->dTotalFacturableImp);
    sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )sizeof(double);
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqharc[16] = (unsigned long  *)0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)(pstConcTrafico->szNum_Celular);
    sqlstm.sqhstl[17] = (unsigned long )21;
    sqlstm.sqhsts[17] = (         int  )21;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqharc[17] = (unsigned long  *)0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)(pstConcTrafico->szCod_Nivel);
    sqlstm.sqhstl[18] = (unsigned long )4;
    sqlstm.sqhsts[18] = (         int  )4;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqharc[18] = (unsigned long  *)0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)(pstConcTrafico->szFec_Pago);
    sqlstm.sqhstl[19] = (unsigned long )11;
    sqlstm.sqhsts[19] = (         int  )11;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqharc[19] = (unsigned long  *)0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)(pstConcTrafico->szCod_CargoBasico);
    sqlstm.sqhstl[20] = (unsigned long )4;
    sqlstm.sqhsts[20] = (         int  )4;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqharc[20] = (unsigned long  *)0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)(pstConcTrafico->szTip_ConcNoFact);
    sqlstm.sqhstl[21] = (unsigned long )6;
    sqlstm.sqhsts[21] = (         int  )6;
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqharc[21] = (unsigned long  *)0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)(pstConcTrafico->szCod_PlanTarif);
    sqlstm.sqhstl[22] = (unsigned long )4;
    sqlstm.sqhsts[22] = (         int  )4;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqharc[22] = (unsigned long  *)0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)(pstConcTrafico->szFec_FinContrato);
    sqlstm.sqhstl[23] = (unsigned long )11;
    sqlstm.sqhsts[23] = (         int  )11;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqharc[23] = (unsigned long  *)0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)(pstConcTrafico->iNum_OrdenConc);
    sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )sizeof(int);
    sqlstm.sqindv[24] = (         short *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqharc[24] = (unsigned long  *)0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)(pstConcTrafico->lSeg_ConsumoReal);
    sqlstm.sqhstl[25] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[25] = (         int  )sizeof(long);
    sqlstm.sqindv[25] = (         short *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqharc[25] = (unsigned long  *)0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)(pstConcTrafico->lSeg_ConsumoDcto);
    sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[26] = (         int  )sizeof(long);
    sqlstm.sqindv[26] = (         short *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqharc[26] = (unsigned long  *)0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)(pstConcTrafico->dTotalFacturableReal);
    sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[27] = (         int  )sizeof(double);
    sqlstm.sqindv[27] = (         short *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqharc[27] = (unsigned long  *)0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)(pstConcTrafico->dTotalFacturableDcto);
    sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[28] = (         int  )sizeof(double);
    sqlstm.sqindv[28] = (         short *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqharc[28] = (unsigned long  *)0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (unsigned char  *)(pstConcTrafico->lCntLlamReal);
    sqlstm.sqhstl[29] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[29] = (         int  )sizeof(long);
    sqlstm.sqindv[29] = (         short *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned long )0;
    sqlstm.sqharc[29] = (unsigned long  *)0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (unsigned char  *)(pstConcTrafico->lCntLlamDcto);
    sqlstm.sqhstl[30] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[30] = (         int  )sizeof(long);
    sqlstm.sqindv[30] = (         short *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned long )0;
    sqlstm.sqharc[30] = (unsigned long  *)0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (unsigned char  *)(pstConcTrafico->lCntLlamFAct);
    sqlstm.sqhstl[31] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[31] = (         int  )sizeof(long);
    sqlstm.sqindv[31] = (         short *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned long )0;
    sqlstm.sqharc[31] = (unsigned long  *)0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (unsigned char  *)(pstConcTrafico->dImpValUnitario);
    sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[32] = (         int  )sizeof(double);
    sqlstm.sqindv[32] = (         short *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned long )0;
    sqlstm.sqharc[32] = (unsigned long  *)0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (unsigned char  *)(pstConcTrafico->szGlsDescrip);
    sqlstm.sqhstl[33] = (unsigned long )100;
    sqlstm.sqhsts[33] = (         int  )100;
    sqlstm.sqindv[33] = (         short *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned long )0;
    sqlstm.sqharc[33] = (unsigned long  *)0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (unsigned char  *)(pstConcTrafico->iCodConcerel);
    sqlstm.sqhstl[34] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[34] = (         int  )sizeof(int);
    sqlstm.sqindv[34] = (         short *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned long )0;
    sqlstm.sqharc[34] = (unsigned long  *)0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (unsigned char  *)(pstConcTrafico->iColumnaRel);
    sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[35] = (         int  )sizeof(int);
    sqlstm.sqindv[35] = (         short *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned long )0;
    sqlstm.sqharc[35] = (unsigned long  *)0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (unsigned char  *)(pstConcTrafico->dPrcImpuesto);
    sqlstm.sqhstl[36] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[36] = (         int  )sizeof(double);
    sqlstm.sqindv[36] = (         short *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned long )0;
    sqlstm.sqharc[36] = (unsigned long  *)0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (unsigned char  *)(pstConcTrafico->dImpMontoBase);
    sqlstm.sqhstl[37] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )sizeof(double);
    sqlstm.sqindv[37] = (         short *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned long )0;
    sqlstm.sqharc[37] = (unsigned long  *)0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (unsigned char  *)(pstConcTrafico->iTipConcep);
    sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[38] = (         int  )sizeof(int);
    sqlstm.sqindv[38] = (         short *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned long )0;
    sqlstm.sqharc[38] = (unsigned long  *)0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (unsigned char  *)(pstConcTrafico->iNivelImpresion);
    sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[39] = (         int  )sizeof(int);
    sqlstm.sqindv[39] = (         short *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned long )0;
    sqlstm.sqharc[39] = (unsigned long  *)0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (unsigned char  *)(pstConcTrafico->szTipUnidad);
    sqlstm.sqhstl[40] = (unsigned long )10;
    sqlstm.sqhsts[40] = (         int  )10;
    sqlstm.sqindv[40] = (         short *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned long )0;
    sqlstm.sqharc[40] = (unsigned long  *)0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (unsigned char  *)(pstConcTrafico->szTipGrupo);
    sqlstm.sqhstl[41] = (unsigned long )10;
    sqlstm.sqhsts[41] = (         int  )10;
    sqlstm.sqindv[41] = (         short *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned long )0;
    sqlstm.sqharc[41] = (unsigned long  *)0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (unsigned char  *)(pstConcTrafico->lNumVenta);
    sqlstm.sqhstl[42] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[42] = (         int  )sizeof(long);
    sqlstm.sqindv[42] = (         short *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned long )0;
    sqlstm.sqharc[42] = (unsigned long  *)0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (unsigned char  *)(pstConcTrafico->szDesPlanTarif);
    sqlstm.sqhstl[43] = (unsigned long )50;
    sqlstm.sqhsts[43] = (         int  )50;
    sqlstm.sqindv[43] = (         short *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned long )0;
    sqlstm.sqharc[43] = (unsigned long  *)0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (unsigned char  *)(pstConcTrafico->dSumDescuentos);
    sqlstm.sqhstl[44] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[44] = (         int  )sizeof(double);
    sqlstm.sqindv[44] = (         short *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned long )0;
    sqlstm.sqharc[44] = (unsigned long  *)0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (unsigned char  *)(pstConcTrafico->lCantDescuentos);
    sqlstm.sqhstl[45] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[45] = (         int  )sizeof(long);
    sqlstm.sqindv[45] = (         short *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned long )0;
    sqlstm.sqharc[45] = (unsigned long  *)0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
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

 /* ECU-10012 */             

    vDTrazasLog(szModulo, "\t\tFetch FetchConceptos SQLCODE= %ld\n",LOG05, SQLCODE);
    vDTrazasLog(szModulo, "\t\tFetch FetchConceptos... cantidad retornada   = %ld\n",LOG05, sqlca.sqlerrd[2]);

    if (SQLCODE == SQLOK)
        *plNumFilas = MAX_CONCEPTOS_LOCAL_HOST;
    else
        if (SQLCODE == SQLNOTFOUND)
            *plNumFilas = sqlca.sqlerrd[2] % MAX_CONCEPTOS_LOCAL_HOST;

    return(SQLCODE);
}/*************************** Final de FetchConceptos ***************************/

/****************************************************************************/
/*  Funcion: int CloseConceptos(void)                                       */
/*  Funcion que cierra el cursor de Conceptos                               */
/****************************************************************************/
int CloseConceptos(void)
{
    strcpy (szModulo, "CloseConceptos");
    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);

    /* EXEC SQL CLOSE curConcTrafico; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )516;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(SQLCODE != SQLOK) {
        vDTrazasError(szModulo,"\t\tError al cerrar el Cursor FA_FACTDOCU_CICLO: %s",LOG01, SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}/****************Final de CloseConceptos *******************/

/****************************************************************************/
/*     Funcion CargaAbonadosdeCliente                                       */
/*     recupera todos los abonados de un cliente                            */
/****************************************************************************/
int CargaAbonadosdelCliente(ST_FACTCLIE * pstFactDocuClie,ST_ABONADO * pst_Abonados,LINEACOMANDO * pstLineaComando,DETALLEOPER *pst_MascaraOper)
{
    int  iSqlCodeAbonado ;

    strcpy (szModulo, "CargaAbonadosdelCliente");
    vDTrazasLog("","\t(Carga_Abonados) IndOrdenTotal  [%ld]",LOG04, pstFactDocuClie->lIndOrdenTotal);

    /************************************************************************************/
    /*    Recupera Conceptos de Trafico de la Factura Identificando el Tipo de Trafico  */
    /************************************************************************************/
    iSqlCodeAbonado = OpenAbonado( pstLineaComando->lCodCiclFact, pstFactDocuClie->lIndOrdenTotal,pst_MascaraOper);

    if(iSqlCodeAbonado == SQLOK)
    {
        iSqlCodeAbonado  = FetchAbonado( pst_Abonados );

        if(iSqlCodeAbonado == SQLOK)
        {
            if(pst_Abonados->CantidadAbonados >= BUFF_ABONADO)
            {
                vDTrazasLog  (szModulo, "\t\tCliente Sobrepaso Maximo de Abonados"
                                        "\t\t ==> Cliente [%ld]" "\t\t ==> Num. Abonados   [%d]"
                                        ,LOG01, pstFactDocuClie->lIndOrdenTotal,pst_Abonados->CantidadAbonados);
                vDTrazasError(szModulo, "\t\tCliente Sobrepaso Maximo de Abonados"
                                        "\t\t ==> Cliente [%ld]" "\t\t ==> Num. Abonados   [%d]"
                                        ,LOG01, pstFactDocuClie->lIndOrdenTotal,pst_Abonados->CantidadAbonados);
                return (FALSE);
            }
        }
    }
    if((iSqlCodeAbonado != SQLOK) && (iSqlCodeAbonado != SQLNOTFOUND))
    {
        vDTrazasError(szModulo,  "\n\t\t(CargaAbonados) Fetch\t\tIndOrdenTotal  [%ld]"
                                 "\n\t\t Error Oracle   [%s]",LOG01, pstFactDocuClie->lIndOrdenTotal,SQLERRM);
        vDTrazasLog(szModulo,    "\n\t\t(CargaAbonados) Fetch\t\tIndOrdenTotal  [%ld]"
                                 "\n\t\t Error Oracle   [%s]",LOG01, pstFactDocuClie->lIndOrdenTotal,SQLERRM);
      return (FALSE);
    }

    if (!CloseAbonado())
        return (FALSE);

   /* Cantidad de Abonados por Clientes o Factura      */
    vDTrazasLog(szModulo,"\t====> Cantidad de Abonados por Cliente [%d]",LOG04,pst_Abonados->CantidadAbonados);
    
    /* Inicio P-ECU-12024*/
    vDTrazasLog(szModulo,"\t====> Invocando Nueva funcion iCargaServSuplan...",LOG04);
    vDTrazasLog(szModulo,"\t====> pstFactDocuClie->lIndOrdenTotal...[%ld]",LOG04,pstFactDocuClie->lIndOrdenTotal);
    vDTrazasLog(szModulo,"\t====> pstLineaComando->lCodCiclFact.....[%ld]",LOG04,pstLineaComando->lCodCiclFact);
    vDTrazasLog(szModulo,"\t====> pstFactDocuClie->lCodCliente......[%ld]",LOG04,pstFactDocuClie->lCodCliente);
    if (iCargaServSuplan ( pstFactDocuClie->lIndOrdenTotal, pstLineaComando->lCodCiclFact, pstFactDocuClie->lCodCliente) != 0) {
    	 return (FALSE);
    }
    vDTrazasLog(szModulo,"\t====> Fin Invocacion de Nueva funcion iCargaServSuplan...\n\n",LOG04);
    /*Fin P-ECU-12024*/

    return (TRUE);
}/************************* Fin bfnCargaAbonados *************************/


/*****************************************************************************/
/* Funcion encargada de actualizar los campos pertinentes en la tabla de     */
/* cuotas del periodo, FA_CUOTCREDITO.                                       */
/*****************************************************************************/
int Update_CuotaCredito (ST_FACTCLIE * FactDocuClie,ST_CUOTAS *pstFaCuotas)
{
    int k = 0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char   szhNumFolioCtc[13]; /* EXEC SQL VAR szhNumFolioCtc IS STRING(12); */ 
 /* P-TMM-03075 Por Homologacin TM-200410271029*/
        char   szhRowid [20]; /* EXEC SQL VAR szhRowid IS STRING(20)   ; */ 


        long lhCodCliente;
        long lhNumSecuenci;
        long lhCodTipDocum;
        long lhCodVendedorAgente;
        char szhLetra[2]; /* EXEC SQL VAR szhLetra IS STRING(2); */ 

        long lhCodCentremi;
        long lhCodConcepto;
        long lhColumna;


        
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "Update_CuotaCredito");
    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);

    if(FactDocuClie->dTotFactura == 0)
    {
        sprintf(szhNumFolioCtc,"%11.11s\0",FactDocuClie->szNumCtcPago);
    }
    else
    {
        sprintf(szhNumFolioCtc,"%11.11s\0",FactDocuClie->szNumCtc);
    }
    
          

    
    
    vDTrazasLog(szModulo,"\t\tFec_Vencimiento : [%s] Folio ctc [%s]",LOG04, FactDocuClie->szFecVencimie,szhNumFolioCtc);

    vDTrazasLog(szModulo,"\t\t   Antes de for: pstFaCuotas->iNum_RegCuotas_venci [%d]",LOG05, pstFaCuotas->iNum_RegCuotas_venci);
    for(k=0; k < pstFaCuotas->iNum_RegCuotas_venci; k++)
    {
        strcpy(szhRowid, pstFaCuotas->stReg_venci[k].szRowid);


lhCodCliente=pstFaCuotas->stReg_venci[k].iCodCliente;
lhNumSecuenci= pstFaCuotas->stReg_venci[k].l_Num_Secuenci;
lhCodTipDocum=pstFaCuotas->stReg_venci[k].iCod_TipDocum;
lhCodVendedorAgente=pstFaCuotas->stReg_venci[k].l_Cod_Vendedor_Ag;
strcpy(szhLetra, pstFaCuotas->stReg_venci[k].sz_Letra);
lhCodCentremi= pstFaCuotas->stReg_venci[k].l_Cod_Centremi;
lhCodConcepto=pstFaCuotas->stReg_venci[k].iCod_Concepto;
lhColumna=pstFaCuotas->stReg_venci[k].l_Columna;    
    


        vDTrazasLog(szModulo,"\t\t   Vencido --> Previo actualizacion, Numero de Registro k:[%d] - pstFaCuotas->stReg_venci[k].iInd_Facturado: [%d]",LOG05, k, pstFaCuotas->stReg_venci[k].iInd_Facturado);
        
        vDTrazasLog(szModulo,"\t\t   lIndOrdenTotal[%d] szhNumFolioCtc[%s] lhCodCliente[%d] lhNumSecuenci[%d] lhCodTipDocum[%d] lhCodVendedorAgente[%d] szhLetra[%s] lhCodCentremi[%d] lhCodConcepto[%d] lhColumna[%d]",LOG05, 
                        FactDocuClie->lIndOrdenTotal,
                        szhNumFolioCtc,
                        lhCodCliente,
                        lhNumSecuenci,
                        lhCodTipDocum,
                        lhCodVendedorAgente,
                        szhLetra,
                        lhCodCentremi,
                        lhCodConcepto,
                        lhColumna
                      );
        
        

        if(pstFaCuotas->stReg_venci[k].iInd_Facturado == 0)/*Nunca debe entrar todas tienens ind_facturado=1*/
        {
            vDTrazasLog(szModulo,"\t\t   Vencido --> k:[%d] Dentro de if solo si pstFaCuotas->stReg_venci[k].iInd_Facturado == 0, iInd_Facturado:[%d]",LOG05,k,pstFaCuotas->stReg_venci[k].iInd_Facturado);
            
            /* EXEC SQL 
            	EXECUTE Upd_FACuotCred_FolioCTC
            	  USING :FactDocuClie->lIndOrdenTotal,
                        :szhNumFolioCtc,
                        :lhCodCliente,
                        :lhNumSecuenci,
                        :lhCodTipDocum,
                        :lhCodVendedorAgente,
                        :szhLetra,
                        :szhLetra,
                        :lhCodCentremi,
                        :lhCodConcepto,
                        :lhColumna; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )531;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(FactDocuClie->lIndOrdenTotal);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhNumFolioCtc;
            sqlstm.sqhstl[1] = (unsigned long )12;
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
            sqlstm.sqhstv[3] = (unsigned char  *)&lhNumSecuenci;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&lhCodTipDocum;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&lhCodVendedorAgente;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[6] = (unsigned long )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[7] = (unsigned long )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&lhCodCentremi;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&lhCodConcepto;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&lhColumna;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
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


                        
        }
        else
        {
            vDTrazasLog(szModulo,"\t\t   Vencido --> k:[%d] Dentro de else solo si pstFaCuotas->stReg_venci[k].iInd_Facturado !=0, iInd_Facturado:[%d]",LOG05,k,pstFaCuotas->stReg_venci[k].iInd_Facturado);
            /* EXEC SQL 
            	EXECUTE Upd_FACuotCred
            	  USING :FactDocuClie->lIndOrdenTotal,
                        :lhCodCliente,
                        :lhNumSecuenci,
                        :lhCodTipDocum,
                        :lhCodVendedorAgente,
                        :szhLetra,
                        :szhLetra,                        
                        :lhCodCentremi,
                        :lhCodConcepto,
                        :lhColumna; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )590;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(FactDocuClie->lIndOrdenTotal);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhNumSecuenci;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lhCodTipDocum;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&lhCodVendedorAgente;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[5] = (unsigned long )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[6] = (unsigned long )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&lhCodCentremi;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&lhCodConcepto;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&lhColumna;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
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



            vDTrazasLog(szModulo,"Dento del Update Vencidas :FEC_VENCI[%s],INDD_ORDENTOTAL[%ld]\n",LOG04, FactDocuClie->szFecVencimie,FactDocuClie->lIndOrdenTotal);/*RA-134*/
        }
        if(sqlca.sqlcode != SQLOK)
        {
            vDTrazasLog(szModulo,"Error en  UPDATE. (FA_CUOTCREDITO) Venci",LOG04);
            return(FALSE);
        }

        vDTrazasLog(szModulo,   "Cuota vencida         \n"
                                "Registro        : [%d]\n"
                                "Rowid           : [%s]\n"
                                "Ind_OrdenTotal  : [%d]\n"
                                "Num_FolioCtc    : [%s]\n"
                                ,LOG04, k,
                                szhRowid,
                                FactDocuClie->lIndOrdenTotal,
                                szhNumFolioCtc);

        if(pstFaCuotas->stReg_venci[k].iInd_Facturado == 0)
        {
            vDTrazasLog(szModulo," if ind_facturado=0 Fec_Vencimiento : [%s]",LOG04, FactDocuClie->szFecVencimie);
        }
    	vDTrazasLog(szModulo,"\t\t Cuota Venc.despues for,Fec_Vencimiento : [%s] Folio ctc [%s]",LOG04, FactDocuClie->szFecVencimie,szhNumFolioCtc);/*fph*/
    }

    vDTrazasLog(szModulo,"\t\t   Antes de for: pstFaCuotas->iNum_RegCuotas_pven [%d]",LOG05, pstFaCuotas->iNum_RegCuotas_pven);
    for(k=0; k < pstFaCuotas->iNum_RegCuotas_pven; k++)
    {
        strcpy(szhRowid, pstFaCuotas->stReg_pven[k].szRowid);/*estaba antes de RA-134*/

lhCodCliente=pstFaCuotas->stReg_pven[k].iCodCliente;
lhNumSecuenci= pstFaCuotas->stReg_pven[k].l_Num_Secuenci;
lhCodTipDocum=pstFaCuotas->stReg_pven[k].iCod_TipDocum;
lhCodVendedorAgente=pstFaCuotas->stReg_pven[k].l_Cod_Vendedor_Ag;
strcpy(szhLetra, pstFaCuotas->stReg_pven[k].sz_Letra);
lhCodCentremi= pstFaCuotas->stReg_pven[k].l_Cod_Centremi;
lhCodConcepto=pstFaCuotas->stReg_pven[k].iCod_Concepto;
lhColumna=pstFaCuotas->stReg_pven[k].l_Columna;    
    


        vDTrazasLog(szModulo,"\t\t   Por Vencer --> Previo actualizacion, Numero de Registro k:[%d] - stReg_pven[k].iInd_Facturado: [%d]",LOG05, k, pstFaCuotas->stReg_pven[k].iInd_Facturado);

        vDTrazasLog(szModulo,"\t\t   lIndOrdenTotal[%d] szhNumFolioCtc[%s] lhCodCliente[%d] lhNumSecuenci[%d] lhCodTipDocum[%d] lhCodVendedorAgente[%d] szhLetra[%s] lhCodCentremi[%d] lhCodConcepto[%d] lhColumna[%d]",LOG05, 
                        FactDocuClie->lIndOrdenTotal,
                        szhNumFolioCtc,
                        lhCodCliente,
                        lhNumSecuenci,
                        lhCodTipDocum,
                        lhCodVendedorAgente,
                        szhLetra,
                        lhCodCentremi,
                        lhCodConcepto,
                        lhColumna
                      );


        if(pstFaCuotas->stReg_pven[k].iInd_Facturado == 2)
        {
            vDTrazasLog(szModulo,"\t\t   Por Vencer --> k:[%d] Dentro de if solo si pstFaCuotas->stReg_pven[k].iInd_Facturado == 2, iInd_Facturado:[%d]",LOG05,k,pstFaCuotas->stReg_pven[k].iInd_Facturado);
            /* EXEC SQL
            	EXECUTE Upd_FACuotCred_FolioCTC
            	  USING :FactDocuClie->lIndOrdenTotal,
                        :szhNumFolioCtc,
                        :lhCodCliente,
                        :lhNumSecuenci,
                        :lhCodTipDocum,
                        :lhCodVendedorAgente,
                        :szhLetra,
                        :szhLetra,
                        :lhCodCentremi,
                        :lhCodConcepto,
                        :lhColumna; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )645;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(FactDocuClie->lIndOrdenTotal);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhNumFolioCtc;
            sqlstm.sqhstl[1] = (unsigned long )12;
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
            sqlstm.sqhstv[3] = (unsigned char  *)&lhNumSecuenci;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&lhCodTipDocum;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&lhCodVendedorAgente;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[6] = (unsigned long )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhLetra;
            sqlstm.sqhstl[7] = (unsigned long )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&lhCodCentremi;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&lhCodConcepto;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&lhColumna;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
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


                        
        }
        if(sqlca.sqlcode != SQLOK)
        {
            vDTrazasLog(szModulo,"Error en  UPDATE. (FA_CUOTCREDITO) pven [%d]",LOG04,sqlca.sqlcode);
            return(FALSE);
        }

        vDTrazasLog(szModulo,   "Cuota por vencer      \n"
                                "Registro        : [%d]\n"
                                "Rowid           : [%s]\n"
                                "Ind_OrdenTotal  : [%d]\n"
                                "Num_FolioCtc    : [%s]\n",
                                LOG04,k,
                                szhRowid,
                                FactDocuClie->lIndOrdenTotal,
                                szhNumFolioCtc);

        if(pstFaCuotas->stReg_pven[k].iInd_Facturado == 0)
        {
            vDTrazasLog(szModulo,"Fec_Vencimiento : [%s]",LOG04, FactDocuClie->szFecVencimie);
        }
    }
    return(TRUE);
}
/****************************************************************************************************/

int put_b5000(FILE *Fd_ArchImp,DET_TRANSACCIONES *pstDetTrans,int iFlagPagos, int iIdxPagos,int iFlagMovim,int iIdxMovim ,char * buffer)
{
    char buffer_local[100];
    double dMtoDebe  = 0.0;
    double dMtoHaber = 0.0;
    double dMtoTotal = 0.0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b5000");

    vDTrazasLog("put_b5000","**Entrando a funcion (%s):\n"
                            "\tiFlagPagos: [%d]\n"
                            "\tiIdxPagos : [%d]\n"
                            "\tiFlagMovim: [%d]\n"
                            "\tiIdxMovim : [%d]\n"
                            ,LOG06
                            ,szModulo
                            ,iFlagPagos
                            ,iIdxPagos
                            ,iFlagMovim
                            ,iIdxMovim);


    if (iFlagPagos)
    {
        dMtoDebe  += pstDetTrans->stPagosClie.stDetPagosClie[iIdxPagos].dMontoDetDebe;
        dMtoHaber += pstDetTrans->stPagosClie.stDetPagosClie[iIdxPagos].dMontoDetHaber;
    }

    if (iFlagMovim)
    {
        dMtoDebe  += pstDetTrans->stMovimClie.stDetMovimClie[iIdxMovim].dMontoDetDebe;
        dMtoHaber += pstDetTrans->stMovimClie.stDetMovimClie[iIdxMovim].dMontoDetHaber;
    }

    dMtoTotal = dMtoDebe - dMtoHaber;

    sprintf(buffer_local,"B5000%015.4f%015.4f%015.4f\n",
                         dMtoDebe,
                         dMtoHaber,
                         dMtoTotal);

    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
      vDTrazasLog("put_b5000","No pudo escribir en archivo",LOG01);
      return(FALSE);
    }
    return(TRUE);
}

int put_b5010(FILE *Fd_ArchImp,DET_MOVIM_CLIE  *stDetMovimClie,int iIdxMov,char * buffer)
{
    char buffer_local[200];
    double dMtoTotal = 0.0;
    long lIdxDet = 0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b5010");

    vDTrazasLog("put_b5010","**Entrando a funcion (%s):\n"
                            ,LOG06
                            ,szModulo);


    for (lIdxDet = 0 ; lIdxDet < stDetMovimClie[iIdxMov].lCantReg; lIdxDet++)
    {
        if(strcmp(stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodRegistro,"B5010") == 0)
        {
            dMtoTotal = stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetDebe - stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetHaber;

            sprintf(buffer_local,"B5010%8.8s%2.2d%2.2s%10.10s%-15.15ld%-10.10ld%-10.10ld%015.4f%015.4f%015.4f%015.4f\n"
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szFecTrans
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].iCodTipDocum
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodOficina
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodPlaza
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumFolio
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumCuota
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumTotalCuota
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetDebe
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetHaber
                                ,dMtoTotal
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetSaldo);


            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
              vDTrazasLog("put_b5010","No pudo escribir en archivo",LOG01);
              return(FALSE);
            }
        }
    }
    return(TRUE);
}


int put_b5020(FILE *Fd_ArchImp,DET_PAGOS_CLIE  *stDetPagosClie,int IdxPag, char * buffer)
{
    char buffer_local[200];
    double dMtoTotal = 0.0;
    long lIdxDet = 0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b5020");

    vDTrazasLog("put_b5020","**Entrando a funcion (%s):\n"
                            ,LOG06
                            ,szModulo);


    for (lIdxDet = 0 ; lIdxDet < stDetPagosClie[IdxPag].lCantReg; lIdxDet++)
    {
        if(strcmp(stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodRegistro,"B5020") == 0)
        {
            dMtoTotal = stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetDebe - stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetHaber;

            sprintf(buffer_local,"B5020%8.8s%2.2d%2.2s%10.10s%-15.15ld%-10.10ld%-10.10ld%015.4f%015.4f%015.4f%015.4f\n"
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szFecTrans
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].iCodTipDocum
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodOficina
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodPlaza
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumFolio
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumCuota
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumTotalCuota
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetDebe
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetHaber
                                ,dMtoTotal
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetSaldo);


            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
              vDTrazasLog("put_b5020","No pudo escribir en archivo",LOG01);
              return(FALSE);
            }
        }
    }
    return(TRUE);
}

int put_b5030(FILE *Fd_ArchImp,DET_MOVIM_CLIE  *stDetMovimClie,int iIdxMov,char * buffer)
{
    char buffer_local[200];
    double dMtoTotal = 0.0;
    long lIdxDet = 0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b5030");

    vDTrazasLog("put_b5030","**Entrando a funcion (%s):\n"
                            ,LOG06
                            ,szModulo);


    for (lIdxDet = 0 ; lIdxDet < stDetMovimClie[iIdxMov].lCantReg; lIdxDet++)
    {
        if(strcmp(stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodRegistro,"B5030") == 0 &&
                  stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumCuota == 0 )
        {
            dMtoTotal = stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetDebe - stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetHaber;

            sprintf(buffer_local,"B5030%8.8s%2.2d%2.2s%10.10s%-15.15ld%-10.10ld%-10.10ld%015.4f%015.4f%015.4f%015.4f%15.15ld%-15.15s\n"
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szFecTrans
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].iCodTipDocum
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodOficina
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szCodPlaza
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumFolio
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumCuota
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumTotalCuota
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetDebe
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetHaber
                                ,dMtoTotal
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].dMontoDetSaldo
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].lNumFolioRel
                                ,stDetMovimClie[iIdxMov].stDetAbonMovimClie[lIdxDet].szPrefPlazaRel);


            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
              vDTrazasLog("put_b5030","No pudo escribir en archivo",LOG01);
              return(FALSE);
            }
        }
    }
    return(TRUE);
}

int put_b5040(FILE *Fd_ArchImp,DET_PAGOS_CLIE  *stDetPagosClie,int IdxPag, char * buffer)
{
    char buffer_local[200];
    double dMtoTotal = 0.0;
    long lIdxDet = 0;

    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b5040");

    vDTrazasLog("put_b5040","**Entrando a funcion (%s):\n"
                            ,LOG06
                            ,szModulo);


    for (lIdxDet = 0 ; lIdxDet < stDetPagosClie[IdxPag].lCantReg; lIdxDet++)
    {
        if(strcmp(stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodRegistro,"B5040") == 0 &&
                  stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumCuota > 0 )
        {
            dMtoTotal = stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetDebe - stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetHaber;

            sprintf(buffer_local,"B5040%8.8s%2.2d%2.2s%10.10s%-15.15ld%-10.10ld%-10.10ld%015.4f%015.4f%015.4f%015.4f%15.15ld%-15.15s\n"
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szFecTrans
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].iCodTipDocum
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodOficina
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szCodPlaza
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumFolio
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumCuota
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumTotalCuota
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetDebe
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetHaber
                                ,dMtoTotal
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].dMontoDetSaldo
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].lNumFolioRel
                                ,stDetPagosClie[IdxPag].stDetAbonPagosClie[lIdxDet].szPrefPlazaRel);


            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
              vDTrazasLog("put_b5040","No pudo escribir en archivo",LOG01);
              return(FALSE);
            }
        }
    }
    return(TRUE);
}

int put_b4008(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char buffer_local[210];
    int iCodTipoImpuesto;

    memset(buffer_local,0,sizeof(buffer_local));


    if(!bfnTipoImpuesto(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,&iCodTipoImpuesto,stFaDetCons.stDetConsumo[iRegConcep].dPrcImpuesto))
    {
        vDTrazasLog("bfnTipoImpuesto","No pudo encontrar el concepto con su Codigo de impuesto %d",LOG05,stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto);
        return(FALSE);
    }

    
    sprintf(buffer_local,"B4008%5.5d%5.5d%10.10d%-50.50s%-9.9d%015.4f%015.4f%2.2f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo   ,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                         iCodTipoImpuesto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dImpMontoBase,USOFACT),
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         stFaDetCons.stDetConsumo[iRegConcep].dPrcImpuesto);/* Inc-pre-189124  */

    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
      vDTrazasLog("put_b4008","No pudo escribir en archivo",LOG01);
      return(FALSE);
    }

    return(TRUE);
}

/**************************************************************************************************************************************/
int put_b4007(FILE *Fd_ArchImp,rg_cuotas *pstReg,int iRegConcep,int iNum_RegCuotas, int Tip_Cuota, long lNumAbonado, char * buffer)
{
    int iesCuota;
    int iRegCuotas;
    char buffer_local[250];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    double dMtoTotalDeuda  = 0.0;
    double dSaldoPendiente = 0.0;

    strcpy (szModulo, "put_b4007");
    memset(buffer_local,0,sizeof(buffer_local));

    vDTrazasLog("put_b4007","**Entrando a funcion (%s):\n"
                            "\tiRegConcep: [%d]\n"
                            "\tiNum_RegCuotas: [%d]\n"
                            "\tTip_Cuota: [%d]\n"
                            ,LOG03
                            ,szModulo
                            ,iRegConcep
                            ,iNum_RegCuotas
                            ,Tip_Cuota);

    iesCuota=(((atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA)||
             (atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)))? TRUE:FALSE;

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG03);
            return(FALSE);
        }
    }

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG03);
        return(FALSE);
    }

    vDTrazasLog("put_b4007","**Funcion (put_b4007), antes de for:\n"
                            "\tatoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact : [%d]\n"
                            "\tstFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact:       [%s]\n"
                            "\tTip_Cuota : [%d]\n"
                            ,LOG03
                            ,atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)
                            ,stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact
                            ,Tip_Cuota);


    for(iRegCuotas=0;(iRegCuotas<iNum_RegCuotas)&&(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==Tip_Cuota);iRegCuotas++)
    {
        vDTrazasLog("put_b4007","**Funcion (put_b4007), dentro de for:\n"
                                "\tiRegCuotas: [%d]\n"
                                "\tpstReg[iRegCuotas].iInd_Facturado: [%d]\n"
                                "\tNumAbonado                       : [%ld]\n"
                                "\tpstReg[iRegCuotas].lNumAbonado:    [%ld]\n"
                                "\tpstReg[iRegCuotas].IndAcelerada: [%s]\n"
                                ,LOG06
                                ,iRegCuotas
                                ,pstReg[iRegCuotas].iInd_Facturado
                                ,lNumAbonado
                                ,pstReg[iRegCuotas].lNumAbonado
                                ,pstReg[iRegCuotas].sz_IndAcelerada);

        if(pstReg[iRegCuotas].iInd_Facturado==2 && lNumAbonado==pstReg[iRegCuotas].lNumAbonado )
        {
            dTotalNetoImpto=pstReg[iRegCuotas].dMtoCuota + dTotalPrimeraCateg + dTotalSegundaCateg;
            ifnObtenerMontosTotalesCuota(pstReg[iRegCuotas], &dMtoTotalDeuda, &dSaldoPendiente);

            sprintf(buffer_local,"B4007%5.5d%5.5d%10.10d%-50.50s%015.4f%1s%-50.50s%3.3d%3.3d%-10.10s%9.9ld%-8.8s%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%s\n",
                                 stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                                 stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                                 stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                                 stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                                 pstReg[iRegCuotas].dMtoCuota,
                                 (iesCuota)?"C":"P",
                                 pstReg[iRegCuotas].szDes_Cuota,
                                 pstReg[iRegCuotas].iNumCuota,
                                 pstReg[iRegCuotas].iSecCuota,
                                 pstReg[iRegCuotas].szPrefPlaza,
                                 pstReg[iRegCuotas].lNum_Folio,
                                 pstReg[iRegCuotas].szFec_Emision,
                                 fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                                 fnCnvDouble(dTotalSegundaCateg,USOFACT),
                                 fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                                 fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                                 fnCnvDouble(dTotalNetoImpto,USOFACT),
                                 fnCnvDouble(dMtoTotalDeuda,USOFACT),
                                 fnCnvDouble(dSaldoPendiente,USOFACT),
                                 pstReg[iRegCuotas].sz_IndAcelerada);

            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
                vDTrazasLog(szModulo,"No pudo escribir en archivo",LOG01);
                return(FALSE);
            }
        }/* if() */
    }/* for() */

    return(TRUE);
}


/*********************************************************************************************/
int put_b4006(FILE *Fd_ArchImp,STSALDO_ANTERIOR *SaldoTot,int iRegConcep,char * buffer)
{
    int iRegSaldo;
    char buffer_local[250];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    strcpy (szModulo, "put_b4006");

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
       if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
       {
           vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
           return(FALSE);
       }
    }

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }

    for(iRegSaldo=0;iRegSaldo<SaldoTot->iNum_RegSaldo;iRegSaldo++)
    {
        dTotalNetoImpto=SaldoTot->stReg[iRegSaldo].dTotalSaldoAnt + dTotalPrimeraCateg + dTotalSegundaCateg;

        sprintf(buffer_local,"B4006%5.5d%5.5d%10.10d%-50.50s%015.4f%-50.50s%9.9ld%-8.8s%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                             stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                             stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                             stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                             stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                             fnCnvDouble(SaldoTot->stReg[iRegSaldo].dTotalSaldoAnt,USOFACT),
                             SaldoTot->stReg[iRegSaldo].szDes_Saldo,
                             SaldoTot->stReg[iRegSaldo].lNum_Folio,
                             SaldoTot->stReg[iRegSaldo].szFechaEfectiva,
                             fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                             fnCnvDouble(dTotalSegundaCateg,USOFACT),
                             fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                             fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                             fnCnvDouble(dTotalNetoImpto,USOFACT));
        buffer_local[_strlen(buffer_local)]=0;

        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
        {
            vDTrazasLog(szModulo,"No pudo escribir en archivo",LOG01);
            return(FALSE);
        }
    }
    return(TRUE);
}


/**************************************************************************************/
int put_b4005(FILE *Fd_ArchImp,int iRegConcep, char * buffer)
{
    char buffer_local[200];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }
    sprintf(buffer_local,"B4005%5.5d%5.5d%10.10d%-50.50s%015.4f%-8.8s%9.9d%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         stFaDetCons.stDetConsumo[iRegConcep].szFec_Pago,
                         0,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                         fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalNetoImpto,USOFACT));

    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b4005","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    return(TRUE);
}


/**************************************************************************************/
int put_b4004(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char buffer_local[200];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }
    sprintf(buffer_local,"B4004%5.5d%5.5d%10.10d%-50.50s%015.4f%7.7d%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo   ,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         stFaDetCons.stDetConsumo[iRegConcep].iNum_Unidades,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                         fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalNetoImpto,USOFACT));

    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b4004","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    return(TRUE);
}


int put_b4003(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char szResultado[13];
    char szSegundosReal[13];
    char szSegundosDcto[13];
    char buffer_local[350];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    sprintf(szResultado,"%12.12ld"   ,stFaDetCons.stDetConsumo[iRegConcep].lSeg_Consumo);
    sprintf(szSegundosReal,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_ConsumoReal);
    sprintf(szSegundosDcto,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_ConsumoDcto);

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }

    sprintf(buffer_local,"B4003%5.5d%5.5d%10.10d%-50.50s%015.4f%-12.12s%015.4f%-12.12s%-12.12s%015.4f%015.4f%6.6ld%6.6ld%6.6ld%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         szResultado,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                         szSegundosReal,
                         szSegundosDcto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableReal,USOFACT),
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableDcto,USOFACT),
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamReal,
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamDcto,
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamFAct,
                         fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalNetoImpto,USOFACT));

    buffer_local[_strlen(buffer_local)]=0;
    vDTrazasLog("put_b4003","\n\t\t[%d] iColumna=[%d] lNumAbonado=[%ld] iCodConcepto=[%d] lCntLlamReal=[%ld] lCntLlamDcto=[%ld] lCntLlamFAct=[%ld]"
                           ,LOG05
                           ,iRegConcep
                           ,stFaDetCons.stDetConsumo[iRegConcep].iColumna
                           ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                           ,stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamReal
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamDcto
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamFAct);

    vDTrazasLog("put_b4003","buffer_local[%s]",LOG05, buffer_local);

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
       vDTrazasLog("put_b4003","No pudo escribir en archivo",LOG01);
       return(FALSE);
    }

    return(TRUE);
}


int put_b4003_MC(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char szResultado[13];
    char szSegundosReal[13];
    char szSegundosDcto[13];
    char buffer_local[350];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    sprintf(szResultado,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_Consumo);
    sprintf(szSegundosReal,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_ConsumoReal);
    sprintf(szSegundosDcto,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_ConsumoDcto);

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }

    sprintf(buffer_local,"B4003%5.5d%5.5d%10.10d%-50.50s%015.4f%-12.12s%015.4f%-12.12s%-12.12s%015.4f%015.4f%6.6ld%6.6ld%6.6ld%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo ,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo  ,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto  ,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto    ,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         szResultado,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                         szSegundosReal,
                         szSegundosDcto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableReal,USOFACT),
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableDcto,USOFACT),
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamReal,
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamDcto,
                         stFaDetCons.stDetConsumo[iRegConcep].lCntLlamFAct,
                         fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalNetoImpto,USOFACT));

    buffer_local[_strlen(buffer_local)]=0;
    vDTrazasLog("put_b4003","\n\t\t[%d] iColumna=[%d] lNumAbonado=[%ld] iCodConcepto=[%d] lCntLlamReal=[%ld] lCntLlamDcto=[%ld] lCntLlamFAct=[%ld]"
                           ,LOG05
                           ,iRegConcep
                           ,stFaDetCons.stDetConsumo[iRegConcep].iColumna
                           ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                           ,stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamReal
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamDcto
                           ,stFaDetCons.stDetConsumo[iRegConcep].lCntLlamFAct);
    vDTrazasLog("put_b4003_MC","buffer_local[%s]",LOG05, buffer_local);

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b4003","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    return(TRUE);
}


int put_b4002(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char buffer_local[210];

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;
    memset(buffer_local,0,sizeof(buffer_local));

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce !=1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }
    
    sprintf(buffer_local,"B4002%5.5d%5.5d%10.10d%-50.50s%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%2.2f\n",
                         stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                         stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                         stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                         fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                         fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                         fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                         fnCnvDouble(dTotalNetoImpto,USOFACT), /*  dTotalNetoImpto); */
                         stFaDetCons.stDetConsumo[iRegConcep].dPrcImpuesto);/* Inc-pre-189124  */


    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b4002","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    return(TRUE);
}
/***************************************************************************************************************/

int put_b4001(FILE *Fd_ArchImp,int iRegConcep,char * buffer, ST_FACTCLIE *pst_Cliente)
{
    char buffer_EncabReg[200];
    char buffer_PieReg  [100];
    static long lCod_Cliente=0;
    static BOOL bPrimeraVez=TRUE;
    long lCod_Cliente_Actual;
    char szCodPlan[4];
    char szDesPlan[31];
    char szTipPlan[2];
    long lMinPlan;
    double dMtoPlan;
    int  iIdxConf = 0;
    int  iLargoBufer = 0;
    int  iPosicion = 0;
    char szResultado[13];

    char szBlanco[2];
    char szConcat[16];

    PLAN_TARIFARIO pstPlan;

    double dTotalPrimeraCateg=0.0;
    double dTotalSegundaCateg=0.0;
    double dTotalNetoImpto=0.0;
    double dTotalPorcenPrimeraCateg=0.0;
    double dTotalPorcenSegundaCateg=0.0;

    lCod_Cliente_Actual=pst_Cliente->lCodCliente;

    strcpy (szModulo, "put_b4001");

    memset(buffer_EncabReg,0,sizeof(buffer_EncabReg));
    memset(buffer_PieReg,0,sizeof(buffer_PieReg));

    memset(szCodPlan,0,sizeof(szCodPlan));
    strcpy(szDesPlan,NO_EXISTE_PLAN);
    lMinPlan = 0;
    dMtoPlan = 0;
    strcpy(szBlanco," ");

    /* INICIO ENCABEZADO DEL REGISTROS B4001*/

    sprintf(szResultado,"%12.12ld",stFaDetCons.stDetConsumo[iRegConcep].lSeg_Consumo);

    if (bfnFindCod_PlanTarif(stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif,&pstPlan))
    {
        strcpy(szCodPlan,pstPlan.szCod_Plantarif);
        strcpy(szDesPlan,pstPlan.szDes_Plantarif);
        strcpy(szTipPlan,pstPlan.szTip_Plantarif);
        lMinPlan = pstPlan.lMinutosPlan;
        dMtoPlan = pstPlan.dValorPlan;
    }

    sprintf(buffer_EncabReg , "B4001%5.5d%5.5d%10.10d%-50.50s%015.4f%-12.12s%015.4f%-3.3s%-3.3s%-30.30s%6.6ld%015.4f%-1.1s",
                               stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,
                               stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,
                               stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto,
                               stFaDetCons.stDetConsumo[iRegConcep].szDes_Concepto,
                               fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet,USOFACT),
                               szResultado,
                               fnCnvDouble(stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableImp,USOFACT),
                               stFaDetCons.stDetConsumo[iRegConcep].szCod_CargoBasico,
                               stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif,
                               szDesPlan,
                               lMinPlan,
                               dMtoPlan,
                               szTipPlan);

    /*FIN ENCABEZADO DEL REGISTROS B4001*/

    /* INICIO PIE DEL REGISTROS B4001*/

    bfnLimpiaFlag(&pstCatImpues);
    if (stFaDetCons.stDetConsumo[iRegConcep].iCodTipConce != 1)
    {
        if (!bfnTotImptosCateg(stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto, stFaDetCons.stDetConsumo[iRegConcep].iColumna, &dTotalPrimeraCateg, &dTotalSegundaCateg ))
        {
            vDTrazasLog(szModulo, "\tError en regreso de funcion bfnTotImptosCateg ", LOG05);
            return(FALSE);
        }
    }
    dTotalNetoImpto=stFaDetCons.stDetConsumo[iRegConcep].dTotalFacturableNet + dTotalPrimeraCateg + dTotalSegundaCateg;

    if (!bfnPorcenImptosCateg(&dTotalPorcenPrimeraCateg, &dTotalPorcenSegundaCateg ))
    {
        vDTrazasLog(szModulo, "\tError en regreso de funcion bfnPorcenImptosCateg ", LOG05);
        return(FALSE);
    }

    sprintf(buffer_PieReg , "%015.4f%015.4f%015.4f%015.4f%015.4f",
                            fnCnvDouble(dTotalPrimeraCateg,USOFACT),
                            fnCnvDouble(dTotalSegundaCateg,USOFACT),
                            fnCnvDouble(dTotalPorcenPrimeraCateg,USOFACT),
                            fnCnvDouble(dTotalPorcenSegundaCateg,USOFACT),
                            fnCnvDouble(dTotalNetoImpto,USOFACT));


    /* FIN PIE DEL REGISTROS B4001*/


    /*INICIO DINAMICO DEL REGISTROS B4001*/

    if (lCod_Cliente_Actual!=lCod_Cliente)
        bPrimeraVez=TRUE;
    else
        bPrimeraVez=FALSE;

    iLargoBufer = (pstConfB4001.iNumReg*15)+1;
    char buffer_Dinamico[iLargoBufer];
    memset(buffer_Dinamico,0,sizeof(buffer_Dinamico));

    for (iIdxConf = 0 ; iIdxConf < pstConfB4001.iNumReg ; iIdxConf++)
    {
        sprintf(szConcat,"%-15.15s",szBlanco);

/* PGG - 10-11-2011 - 177536 - SE SOLICITA SIEMPRE ESTA INFO EN EL REGISTRO B4001 */
/*        if ((strcmp(szTipPlan,EMPRESA)!=0)||(bPrimeraVez!=FALSE))
        {
*/        	
            iPosicion =-1;
            iPosicion = buscaMinutoAdicional(szCodPlan,pstConfB4001.stRegB4001[iIdxConf].szCodAgrullam);
            vDTrazasLog(szModulo,"B4001 iPosicion [%d]",LOG06,iPosicion);
            if(iPosicion < 0)
            {
                vDTrazasLog  (szModulo,"\n\t**  Plan [%s] - Agrullam [%s] ===> Error en buscaMinutoAdicional **",LOG04,szCodPlan,pstConfB4001.stRegB4001[iIdxConf].szCodAgrullam);
            }
            else
            {
                sprintf(szConcat,"%015.4f",sthMinutoAdicional.dMtoAdicional[iPosicion]);
            }
/*        } */ /* PGG - 10-11-2011 - 177536 - SE SOLICITA SIEMPRE ESTA INFO EN EL REGISTRO B4001 */
        strcat(buffer_Dinamico,szConcat);
    }

    /*FIN DINAMICO DEL REGISTROS B4001*/

    /*IMPRESION DE REGISTRO B4001 EN EL DAT*/

    char buffer_local[iLargoBufer+300];
    memset(buffer_local,0,sizeof(buffer_local));

    sprintf(buffer_local,"%s%s%s\n"
                        ,buffer_EncabReg
                        ,buffer_Dinamico
                        ,buffer_PieReg);

    lCod_Cliente=lCod_Cliente_Actual;
    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog(szModulo,"No pudo escribir en archivo",LOG01);
        return(FALSE);
    }
    return(TRUE);
}


/******************************************************************************************/
int put_b1000(ST_ABONADO *Abonado,FILE *Fd_ArchImp,int iRegConcep,int AbonadoEncontrado, long Abonado_Cero,char * buffer)
{
	/*EXEC SQL BEGIN DECLARE SECTION;            
      int	Ind_Detllam;         
	EXEC SQL END DECLARE SECTION;*/
	            	
    char buffer_local[600];

    memset(buffer_local,0,sizeof(buffer_local));
    sprintf(buffer_local,"H1000\n\0");
    buffer_local[_strlen(buffer_local)]=0;

    strcpy(szhACodTipDireccion,"2");

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b1000","No pudo escribir en archivo ",LOG01);
        return(FALSE);
    }

    if( stFaDetCons.iNumReg == 0 )
    {
        lhNumAbonado = 0;
    }else{
        lhNumAbonado = stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado;
    }

    vDTrazasLog("put_b1000","Num Abonado [%ld]",LOG06,lhNumAbonado);

			
		    if (lhNumAbonado != 0)
		    {
		        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		            char Num_ident[21];
		            char Nom_calle[51];
		            char Num_calle[11];
		            char Num_piso[11];
		            char Des_comuna[31];
		            char Des_ciudad[31];
		            char Zip[16];
		            char Des_pais[31];
		            char Des_estado[31];
		            char Des_pueblo[31];
		            char Fec_alta_abo[9];/* RA DEL P-ECU-12024*/
		            char shId_Acceso[13]; /* EXEC SQL VAR shId_Acceso IS STRING(13); */ 
 /* RA 189128 */
		            char shIndTipcliente[2]; /* RA 189128 */
		            long lCodClie; /* MA_194292 */
		            char Fec_contrato[9]; /* MA_194292 */
                char Nueva_direcc[191];
                char Ciudad_provincia[66];

		            
		        /* EXEC SQL END DECLARE SECTION; */ 

		
		        /* EXEC SQL OPEN Cursor_GetDireccion; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 46;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlbuft((void **)0, 
            "select USU.NUM_IDENT ,DIR.NOM_CALLE ,DIR.NUM_CALLE ,DIR.NUM_PIS\
O ,COM.DES_COMUNA ,CIU.DES_CIUDAD ,DIR.ZIP ,PAIS.DES_PAIS ,NVL(EST.DES_ESTAD\
O,'NO REGISTRA') ,NVL(PUE.DES_PUEBLO,'NO REGISTRA') ,TO_CHAR(ABON.FEC_ALTA,'\
YYYYMMDD') ,G.ID_ACCESO ,G.IND_TIPCLIENTE ,ABON.COD_CLIENTE  from GA_DIRECUS\
UAR DIREC ,GE_CIUDADES CIU ,GE_COMUNAS COM ,GE_DIRECCIONES DIR ,GA_ABOCEL AB\
ON ,GE_DATOSGENER GENER ,GE_PAISES PAIS ,GE_ESTADOS EST ,GE_PUEBLOS PUE ,GA_\
USUARIOS USU ,(select a.id_acceso ,b.ind_tipcliente ,c.num_abonado  from ga_\
detabodatos a ,ge_clienteS b ,ga_abocel c where ((a.num_abonado=c.num_abonad\
o and b.cod_cliente=c.cod_cliente) and a.num_abonado=:b0)) G where (((((((((\
(((((ABON.NUM_ABONADO=:b0 and DIREC.COD_USUARIO=ABON.COD_USUARIO) and DIREC.\
COD_TIPDIRECCION=:b2) and DIR.COD_DIRECCION=DIREC.COD_DIRECCION) and CIU.COD\
_REGION=DIR.COD_REGION) and CIU.COD_PROVINCIA=DIR.COD_PROVINCIA) and CIU.COD\
_CIUDAD=DIR.COD_CIUDAD) and DIR.COD_REGION=COM.COD_REGION) and DIR.COD_PROVI\
NCIA=COM.COD_PROVINCIA) and DIR.COD_COMUNA=COM.CO");
          sqlstm.stmt = sq0001;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )704;
          sqlstm.selerr = (unsigned short)1;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqcmod = (unsigned int )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
          sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
          sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (unsigned char  *)szhACodTipDireccion;
          sqlstm.sqhstl[2] = (unsigned long )2;
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


		        
		
		        if(SQLCODE != SQLOK)
		        {
		            vDTrazasError("put_b1000","Error en OPEN Cursor_GetDireccion %s", LOG01, SQLERRM);
		            return(FALSE);
		        }
		
		        /* EXEC SQL FETCH Cursor_GetDireccion
		            INTO :Num_ident,
		                 :Nom_calle,
		                 :Num_calle,
		                 :Num_piso,
		                 :Des_comuna,
		                 :Des_ciudad,
		                 :Zip,
		                 :Des_pais,
		                 :Des_estado,
		                 :Des_pueblo,
		                 :Fec_alta_abo, /o RA DEL P-ECU-12024o/
		                 :shId_Acceso, 			/o RA 189128 o/
		                 :shIndTipcliente,  /o RA 189128 o/
		                 :lCodClie; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 46;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )731;
          sqlstm.selerr = (unsigned short)1;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqfoff = (         int )0;
          sqlstm.sqfmod = (unsigned int )2;
          sqlstm.sqhstv[0] = (unsigned char  *)Num_ident;
          sqlstm.sqhstl[0] = (unsigned long )21;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)Nom_calle;
          sqlstm.sqhstl[1] = (unsigned long )51;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (unsigned char  *)Num_calle;
          sqlstm.sqhstl[2] = (unsigned long )11;
          sqlstm.sqhsts[2] = (         int  )0;
          sqlstm.sqindv[2] = (         short *)0;
          sqlstm.sqinds[2] = (         int  )0;
          sqlstm.sqharm[2] = (unsigned long )0;
          sqlstm.sqadto[2] = (unsigned short )0;
          sqlstm.sqtdso[2] = (unsigned short )0;
          sqlstm.sqhstv[3] = (unsigned char  *)Num_piso;
          sqlstm.sqhstl[3] = (unsigned long )11;
          sqlstm.sqhsts[3] = (         int  )0;
          sqlstm.sqindv[3] = (         short *)0;
          sqlstm.sqinds[3] = (         int  )0;
          sqlstm.sqharm[3] = (unsigned long )0;
          sqlstm.sqadto[3] = (unsigned short )0;
          sqlstm.sqtdso[3] = (unsigned short )0;
          sqlstm.sqhstv[4] = (unsigned char  *)Des_comuna;
          sqlstm.sqhstl[4] = (unsigned long )31;
          sqlstm.sqhsts[4] = (         int  )0;
          sqlstm.sqindv[4] = (         short *)0;
          sqlstm.sqinds[4] = (         int  )0;
          sqlstm.sqharm[4] = (unsigned long )0;
          sqlstm.sqadto[4] = (unsigned short )0;
          sqlstm.sqtdso[4] = (unsigned short )0;
          sqlstm.sqhstv[5] = (unsigned char  *)Des_ciudad;
          sqlstm.sqhstl[5] = (unsigned long )31;
          sqlstm.sqhsts[5] = (         int  )0;
          sqlstm.sqindv[5] = (         short *)0;
          sqlstm.sqinds[5] = (         int  )0;
          sqlstm.sqharm[5] = (unsigned long )0;
          sqlstm.sqadto[5] = (unsigned short )0;
          sqlstm.sqtdso[5] = (unsigned short )0;
          sqlstm.sqhstv[6] = (unsigned char  *)Zip;
          sqlstm.sqhstl[6] = (unsigned long )16;
          sqlstm.sqhsts[6] = (         int  )0;
          sqlstm.sqindv[6] = (         short *)0;
          sqlstm.sqinds[6] = (         int  )0;
          sqlstm.sqharm[6] = (unsigned long )0;
          sqlstm.sqadto[6] = (unsigned short )0;
          sqlstm.sqtdso[6] = (unsigned short )0;
          sqlstm.sqhstv[7] = (unsigned char  *)Des_pais;
          sqlstm.sqhstl[7] = (unsigned long )31;
          sqlstm.sqhsts[7] = (         int  )0;
          sqlstm.sqindv[7] = (         short *)0;
          sqlstm.sqinds[7] = (         int  )0;
          sqlstm.sqharm[7] = (unsigned long )0;
          sqlstm.sqadto[7] = (unsigned short )0;
          sqlstm.sqtdso[7] = (unsigned short )0;
          sqlstm.sqhstv[8] = (unsigned char  *)Des_estado;
          sqlstm.sqhstl[8] = (unsigned long )31;
          sqlstm.sqhsts[8] = (         int  )0;
          sqlstm.sqindv[8] = (         short *)0;
          sqlstm.sqinds[8] = (         int  )0;
          sqlstm.sqharm[8] = (unsigned long )0;
          sqlstm.sqadto[8] = (unsigned short )0;
          sqlstm.sqtdso[8] = (unsigned short )0;
          sqlstm.sqhstv[9] = (unsigned char  *)Des_pueblo;
          sqlstm.sqhstl[9] = (unsigned long )31;
          sqlstm.sqhsts[9] = (         int  )0;
          sqlstm.sqindv[9] = (         short *)0;
          sqlstm.sqinds[9] = (         int  )0;
          sqlstm.sqharm[9] = (unsigned long )0;
          sqlstm.sqadto[9] = (unsigned short )0;
          sqlstm.sqtdso[9] = (unsigned short )0;
          sqlstm.sqhstv[10] = (unsigned char  *)Fec_alta_abo;
          sqlstm.sqhstl[10] = (unsigned long )9;
          sqlstm.sqhsts[10] = (         int  )0;
          sqlstm.sqindv[10] = (         short *)0;
          sqlstm.sqinds[10] = (         int  )0;
          sqlstm.sqharm[10] = (unsigned long )0;
          sqlstm.sqadto[10] = (unsigned short )0;
          sqlstm.sqtdso[10] = (unsigned short )0;
          sqlstm.sqhstv[11] = (unsigned char  *)shId_Acceso;
          sqlstm.sqhstl[11] = (unsigned long )13;
          sqlstm.sqhsts[11] = (         int  )0;
          sqlstm.sqindv[11] = (         short *)0;
          sqlstm.sqinds[11] = (         int  )0;
          sqlstm.sqharm[11] = (unsigned long )0;
          sqlstm.sqadto[11] = (unsigned short )0;
          sqlstm.sqtdso[11] = (unsigned short )0;
          sqlstm.sqhstv[12] = (unsigned char  *)shIndTipcliente;
          sqlstm.sqhstl[12] = (unsigned long )2;
          sqlstm.sqhsts[12] = (         int  )0;
          sqlstm.sqindv[12] = (         short *)0;
          sqlstm.sqinds[12] = (         int  )0;
          sqlstm.sqharm[12] = (unsigned long )0;
          sqlstm.sqadto[12] = (unsigned short )0;
          sqlstm.sqtdso[12] = (unsigned short )0;
          sqlstm.sqhstv[13] = (unsigned char  *)&lCodClie;
          sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[13] = (         int  )0;
          sqlstm.sqindv[13] = (         short *)0;
          sqlstm.sqinds[13] = (         int  )0;
          sqlstm.sqharm[13] = (unsigned long )0;
          sqlstm.sqadto[13] = (unsigned short )0;
          sqlstm.sqtdso[13] = (unsigned short )0;
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

			    /* MA_194292 */
		
		        if (sqlca.sqlcode == SQLNOTFOUND )
		        {
		            vDTrazasLog("put_b1000", "SQLNOTFOUND Cursor_GetDireccion. Error[%d][%s] ", LOG05, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
		            vDTrazasLog("put_b1000", "SQLNOTFOUND Numero de abonado: [%ld]", LOG05,lhNumAbonado);
		            return (FALSE);
		        }

              vDTrazasLog("put_b1000", "INFORMACION ACCESO-TIPO CLIENTE : [%s|%s]", LOG03,shId_Acceso,shIndTipcliente);
                        
		        /* EXEC SQL CLOSE Cursor_GetDireccion; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 46;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )802;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				    
						/* INI MA_194292 */

            /* EXEC SQL
            /o TO_CHAR(ABON.FEC_ALTA,'YYYYMMDD') o/
						SELECT TO_CHAR(FEC_CONTRATACION, 'YYYYMMDD')
						INTO  :Fec_contrato
						FROM  GA_FECCONTRATACION_TD  
						WHERE COD_CLIENTE = :lCodClie
						AND   NUM_ABONADO   = :lhNumAbonado 
						AND   SYSDATE BETWEEN FEC_DESDE AND NVL(FEC_HASTA,SYSDATE); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select TO_CHAR(FEC_CONTRATACION,'YYYYMMDD') into \
:b0  from GA_FECCONTRATACION_TD where ((COD_CLIENTE=:b1 and NUM_ABONADO=:b2) a\
nd SYSDATE between FEC_DESDE and NVL(FEC_HASTA,SYSDATE))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )817;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Fec_contrato;
            sqlstm.sqhstl[0] = (unsigned long )9;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lCodClie;
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

                             

		        if (sqlca.sqlcode == SQLOK && sqlca.sqlcode != SQLNOTFOUND)
		        {
		            vDTrazasLog("put_b1000", "Asignando Fecha de contratacion: [%s]", LOG03,Fec_contrato);
                strcpy(Fec_alta_abo,Fec_contrato);

		        }

						/* FIN MA_194292 */				    

            /* EXEC SQL
						SELECT A.NOM_CALLE || ' ' || A.NUM_CALLE  || ' ' ||  A.OBS_DIRECCION   || ' ' ||  A.DES_DIREC1  || ' ' ||  A.DES_DIREC2  || ' ' || A.NUM_PISO  AS DIRECCION
						INTO :Nueva_direcc
						FROM GE_DIRECCIONES A , GA_ABOCEL B, GA_DIRECUSUAR C
						WHERE A.COD_DIRECCION = C.COD_DIRECCION
						AND C.COD_TIPDIRECCION = 3
						AND C.COD_USUARIO  = B.COD_USUARIO
						AND B.NUM_ABONADO = :lhNumAbonado; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ((((((((((A.NOM_CALLE||' ')||A.NUM_CALLE)|\
|' ')||A.OBS_DIRECCION)||' ')||A.DES_DIREC1)||' ')||A.DES_DIREC2)||' ')||A.NUM\
_PISO) DIRECCION into :b0  from GE_DIRECCIONES A ,GA_ABOCEL B ,GA_DIRECUSUAR C\
 where (((A.COD_DIRECCION=C.COD_DIRECCION and C.COD_TIPDIRECCION=3) and C.COD_\
USUARIO=B.COD_USUARIO) and B.NUM_ABONADO=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )844;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Nueva_direcc;
            sqlstm.sqhstl[0] = (unsigned long )191;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
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


                        
		        if (sqlca.sqlcode == SQLOK && sqlca.sqlcode != SQLNOTFOUND)
		        {
		            vDTrazasLog("put_b1000", "Asignando Nueva DirecciÛn", LOG03);
		        }

           if (sqlca.sqlcode == SQLNOTFOUND )
           {
		            vDTrazasLog("put_b1000", "SQLNOTFOUND Nueva Direccion. Error[%d][%s] ", LOG05, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
		            strcpy(Nueva_direcc," ");
		            
		        }	 

		       vDTrazasLog("put_b1000", "Valor nueva direccion : [%s]", LOG03,Nueva_direcc);

            /* EXEC SQL
						SELECT C.DES_COMUNA || ', ' || B.DES_PROVINCIA AS CIUDAD_PROVINCIA 
						INTO :Ciudad_provincia
						FROM GE_DIRECCIONES A, GA_DIRECUSUAR E, GE_PROVINCIAS B, GE_COMUNAS C, GA_ABOCEL D
						WHERE A.COD_DIRECCION = E.COD_DIRECCION
						AND E.COD_TIPDIRECCION = 3
						AND E.COD_USUARIO  = D.COD_USUARIO
						AND D.NUM_ABONADO = :lhNumAbonado
						AND A.COD_PROVINCIA = B.COD_PROVINCIA
						AND A.COD_COMUNA = C.COD_COMUNA
						AND B.COD_PROVINCIA = C.COD_PROVINCIA; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 46;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ((C.DES_COMUNA||', ')||B.DES_PROVINCIA) CI\
UDAD_PROVINCIA into :b0  from GE_DIRECCIONES A ,GA_DIRECUSUAR E ,GE_PROVINCIAS\
 B ,GE_COMUNAS C ,GA_ABOCEL D where ((((((A.COD_DIRECCION=E.COD_DIRECCION and \
E.COD_TIPDIRECCION=3) and E.COD_USUARIO=D.COD_USUARIO) and D.NUM_ABONADO=:b1) \
and A.COD_PROVINCIA=B.COD_PROVINCIA) and A.COD_COMUNA=C.COD_COMUNA) and B.COD_\
PROVINCIA=C.COD_PROVINCIA)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )867;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Ciudad_provincia;
            sqlstm.sqhstl[0] = (unsigned long )66;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
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

                        
						
		        if (sqlca.sqlcode == SQLOK && sqlca.sqlcode != SQLNOTFOUND)
		        {
		            vDTrazasLog("put_b1000", "Asignando Ciudad y provincia: ", LOG03);
		        }

           if (sqlca.sqlcode == SQLNOTFOUND )
           {
		            vDTrazasLog("put_b1000", "SQLNOTFOUND Nueva Direccion. Error[%d][%s] ", LOG05, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
		            strcpy(Ciudad_provincia," ");
		            
		        }	 		        
				        		        		       		        
           vDTrazasLog("put_b1000", "Valor Ciudad-Provincia : [%s]", LOG03,Ciudad_provincia);    
				        		        		       		        
		        if (strcmp(shIndTipcliente,"D")==0)  {
				        /* sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s\n", */
				        /* sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s%-20.20s%1s\n",  RA 189128 */
				           sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s%-20.20s%1s%-190.190s%-65.65s\n", 
				                             (Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado),
				                             stFaDetCons.stDetConsumo[iRegConcep].szNum_Celular,
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_usuario[AbonadoEncontrado]),
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido1[AbonadoEncontrado]),
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido2[AbonadoEncontrado]),
				                             Nom_calle, Num_calle,
				                             Num_piso, Des_comuna,
				                             Des_pais,
				                             Des_estado,
				                             Des_ciudad,
				                             Des_pueblo,
				                             Zip,
				                             Abonado->iIndDetLlam[AbonadoEncontrado],   /*P-ECU-10012 " ", */
				                             " ",
				                             " ",
				                             Num_ident,
				                             Fec_alta_abo,  /*RA-188849*/ 
				                             shId_Acceso,				/* RA 189128 */
				                             shIndTipcliente,	/* RA 189128 */
				                             Nueva_direcc,
				                             Ciudad_provincia);
		        } else {
				        /* sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s\n", */
				        /* sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s%-20.20s%1s\n",  RA 189128 */
                   sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s%-20.20s%1s%-190.190s%-65.65s\n", 
				                             (Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado),
				                             stFaDetCons.stDetConsumo[iRegConcep].szNum_Celular,
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_usuario[AbonadoEncontrado]),
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido1[AbonadoEncontrado]),
				                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido2[AbonadoEncontrado]),
				                             Nom_calle, Num_calle,
				                             Num_piso, Des_comuna,
				                             Des_pais,
				                             Des_estado,
				                             Des_ciudad,
				                             Des_pueblo,
				                             Zip,
				                             Abonado->iIndDetLlam[AbonadoEncontrado],   /*P-ECU-10012 " ", */
				                             " ",
				                             " ",
				                             Num_ident,
				                             Fec_alta_abo,  /*RA-188849*/ 
				                             shId_Acceso,				 /*RA 189128 */
				                             shIndTipcliente,    /*RA 189128 */
				                             " ",
				                             " ");	 
		    		}
		    }
		    else
		    {
		             sprintf(buffer_local,"B1000%8.8ld%-20.20s%-20.20s%-20.20s%-20.20s%-15.15s%-15.15s%-15.15s%-15.15s%-30.30s%-30.30s%-30.30s%-30.30s%-15.15s%-1.1d%-1.1s%-1.1s%-20.20s%-8s\n", 
		                             (Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado),
		                             (Abonado_Cero==0)? ""          :stFaDetCons.stDetConsumo[iRegConcep].szNum_Celular,
		                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_usuario[AbonadoEncontrado]),
		                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido1[AbonadoEncontrado]),
		                             (AbonadoEncontrado==-1)? "":(Abonado->sznom_apellido2[AbonadoEncontrado]),
		                             "",
		                             "",
		                             "",
		                             "",
		                             "",
		                             "",
		                             "",
		                             "",
		                             "",
		                             (AbonadoEncontrado==-1)? 0:Abonado->iIndDetLlam[AbonadoEncontrado],  /*P-ECU-10012 "",*/
		                             "",
		                             "",
		                             "",
		                             "");
		        buffer_local[_strlen(buffer_local)]=0;
		    }
		
		    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
		    {
		        vDTrazasLog("put_b1000","No pudo escribir en archivo",LOG01);
		        return(FALSE);
		    }
		
			
    return(TRUE);
}


int put_b1100(ST_FACTCLIE *pst_Cliente,FILE *Fd_ArchImp,int iRegConcep,long Abonado_Cero,char * buffer)
{
    char buffer_local[200];
    char szllave[17];
    int  iInicio,iTermino,ArrastreEncontrado;

    ArrastreEncontrado = 0;
    iInicio = 0;
    iTermino = 0;

    vDTrazasLog("put_b1100","put_b1100 ENTRADA CLIENTE/ABONADO=%ld - %ld\n",LOG05,pst_Cliente->lCodCliente, (Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado)); /* P-TMM-03075 Por Homologacin TM-200410241013*/

    memset(buffer_local,0,sizeof(buffer_local));

    sprintf(szllave,"%08ld%08ld\0",pst_Cliente->lCodCliente,(Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado));

    vDTrazasLog("put_b1100","put_b1100 \t a busca_arrastre Llave=[%s]\n",LOG06,szllave); /* P-TMM-03075 Por Homologacin TM-200410241013*/
    if(!busca_arrastre(szllave,&iInicio,&iTermino))
    {
        sprintf(buffer_local,"B1100%-8.8s%015.4f%015.4f%015.4f%015.4f%015.4f\n","     ",0.0,0.0,0.0,0.0,0.0);
    }
    vDTrazasLog("put_b1100","put_b1100 \t Inicio=%d Termino=%d total=%d\n",LOG06,iInicio,iTermino, sthDetArrastre.iCantidadArrastre); /* P-TMM-03075 Por Homologacin TM-200410241013*/

    for(ArrastreEncontrado=iInicio;ArrastreEncontrado<=iTermino && ArrastreEncontrado<=sthDetArrastre.iCantidadArrastre;ArrastreEncontrado++) /* P-TMM-03075 Por Homologacin TM-200410241013*/
    {
        vDTrazasLog("put_b1100","put_b1100 \t indice Arrastre =%d <= iTermino=%d\n",LOG06,ArrastreEncontrado,iTermino); /* P-TMM-03075 Por Homologacin TM-200410241013*/
        sprintf(buffer_local,"B1100%-8.8s%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                            sthDetArrastre.szIndUnidad[ArrastreEncontrado],
                            sthDetArrastre.dValArrastre[ArrastreEncontrado],
                            sthDetArrastre.dValExpirado[ArrastreEncontrado],
                            sthDetArrastre.dValDisponible[ArrastreEncontrado],
                            sthDetArrastre.dValConsumo[ArrastreEncontrado],
                            sthDetArrastre.dValResto[ArrastreEncontrado]);
    }
    buffer_local[_strlen(buffer_local)]=0;

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b1100","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    vDTrazasLog("put_b1100","put_b1100 SALIDA CLIENTE/ABONADO=%ld - %ld\n",LOG05,pst_Cliente->lCodCliente, (Abonado_Cero==0)? Abonado_Cero:(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado)); /* P-TMM-03075 Por Homologacin TM-200410241013*/
    return(TRUE);
}


int put_b1200(FILE *Fd_ArchImp,int iRegConcep, ST_FACTCLIE *pst_Cliente, long lCodCiclFact, char * buffer)
{
	char *szModulo="put_b1200";
    char           buffer_local[200];
    PLAN_TARIFARIO *pstAux = (PLAN_TARIFARIO *)NULL;
    PLAN_TARIFARIO stkey;
    double         dValorHorAlta=0.0;
    double         dValorHorNorm=0.0;
    double         dValorHorBaja=0.0;
    MINPLAN        pstMinPlanAux;
    char           szCodThor[21];
    int            piRegConcep = 0;
    long           iIdx = 0; /*AFGS - 38935*/

    char           szValorPlan[30]   ="";
    char           szValorHorAlta[30]="";
    char           szValorHorNorm[30]="";
    char           szValorHorBaja[30]="";

    char           szCodPlanTarifAbo [4]="";

    vDTrazasLog(szModulo,"Entrando a funcion",LOG06);

    if (  stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado > 0)
    {
        if (stFaDetCons.stDetConsumo[iRegConcep].iCodConcepto == iCodAbonoCel) /* corresponde a carga basico */
        {
            piRegConcep = iRegConcep;
        }
        else
        { /* busca cargo basico del abonado */
            for(iIdx = 0; iIdx < stFaDetCons.iNumReg; iIdx++)
            {
                if (stFaDetCons.stDetConsumo[iIdx].lNumAbonado == stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado && stFaDetCons.stDetConsumo[iIdx].iCodConcepto == iCodAbonoCel)
                {
                    piRegConcep = iIdx;
                }
            }
        }
        if (stFaDetCons.stDetConsumo[piRegConcep].iCodConcepto != iCodAbonoCel) /* No es cargo basico Error */
        {
            vDTrazasLog(szModulo,"No existe Cargo basico para el abonado, se consulta ",LOG05);
            if (!bfnGetPlanTarifAbo(stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado, pst_Cliente->lCodCliente, szCodPlanTarifAbo))
            {
                vDTrazasLog(szExeName, "Put_B1200:No se encontro plan tarifario para el abonado [%ld] en GA_INTARCEL", LOG01, stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado);
                return (FALSE);
            }
            strcpy (stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif, szCodPlanTarifAbo);
            piRegConcep = iRegConcep;
        }
    }
    else
    {
        if(pst_Cliente->szPlanTarif == NULL)
        {
            vDTrazasLog(szModulo,"(put_b1200)Por primer if(NULL), abonado 0",LOG05);
            strcpy (stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif,"   ");  /* RA-200601030476 */
        }
        else
        {
            vDTrazasLog(szModulo,"(put_b1200)Por else (not NULL), abonado 0 Plan [%s]",LOG05,pst_Cliente->szPlanTarif);
            strcpy (stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif, szPlan); /*AFGS - 38935*/
        }

        vDTrazasLog(szModulo,"(put_b1200)Abonado 0, stFaDetCons.stDetConsumo[%d].szCod_PlanTarif: [%s]"
                        ,LOG05
                        ,iRegConcep
                        ,stFaDetCons.stDetConsumo[iRegConcep].szCod_PlanTarif);

        piRegConcep = iRegConcep;
    }

    strcpy(stkey.szCod_Plantarif,alltrim(stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif));

    if ( (pstAux = (PLAN_TARIFARIO *)bsearch (&stkey, pstPlanes.stPlanesTarifarios , pstPlanes.iNumRegPlanTarif,
        sizeof (PLAN_TARIFARIO),ifnCmpCod_PlanTarif ))== (PLAN_TARIFARIO *)NULL)
    {
        vDTrazasLog(szExeName, "Put_B1200: Codigo Plan Tarifario [%s] no encontrado ...", LOG05, stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif);
        return  (TRUE);
    }

    dValorHorAlta = 0.0;
    dValorHorNorm = 0.0;
    dValorHorBaja = 0.0;

    /* Horaio Alto */
    memset(&pstMinPlanAux,'\0', sizeof(MINPLAN));
    strcpy (szCodThor, stGedParametros.szTolCodTHorAlta );
    vDTrazasLog(szExeName, "Put_B1200: Horario Alto THor [%s]", LOG05,szCodThor);

    if (bfnFindMinPlan(stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif, szCodThor, &pstMinPlanAux))
    {
        dValorHorAlta = pstMinPlanAux.dMto_Inic;
    }

    /* Horario Normal */
    memset(&pstMinPlanAux,'\0', sizeof(pstMinPlanAux));
    strcpy (szCodThor, stGedParametros.szTolCodTHor );
    vDTrazasLog(szExeName, "Put_B1200: Horario Normal THor [%s]", LOG05,szCodThor);

    if (bfnFindMinPlan (stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif, szCodThor, &pstMinPlanAux))
    {
        dValorHorNorm = pstMinPlanAux.dMto_Inic;
    }

    /* Horario Reducido */
    memset(&pstMinPlanAux,'\0', sizeof(pstMinPlanAux));
    strcpy (szCodThor, stGedParametros.szTolCodTHorBaja );
    vDTrazasLog(szExeName, "Put_B1200: Horario Reducido THor [%s]", LOG05,szCodThor);
    if (bfnFindMinPlan (stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif, szCodThor, &pstMinPlanAux))
    {
        dValorHorBaja = pstMinPlanAux.dMto_Inic;
    }

    /*if(pstAux->dValorPlan==0.0)
        sprintf(szValorPlan,"%s"," ");
    else*FPH 70327 que aparezcan los 0's*/
    sprintf(szValorPlan,"%015.4f",pstAux->dValorPlan);

    if(dValorHorAlta==0.0)
    {
        vDTrazasLog(szExeName, "Put_B1200: No se encontro tarifa Alta plan [%s] se deja blanco ", LOG01, stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif);
        sprintf(szValorHorAlta,"%s"," ");
    }
    else
        sprintf(szValorHorAlta,"%015.4f",dValorHorAlta);

    if(dValorHorNorm==0.0)
    {
        vDTrazasLog(szExeName, "Put_B1200: No se encontro tarifa Normal plan [%s] se deja blanco ", LOG01, stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif);
        sprintf(szValorHorNorm,"%s"," ");
    }
    else
        sprintf(szValorHorNorm,"%015.4f",dValorHorNorm);

    if(dValorHorBaja==0.0)
    {
        vDTrazasLog(szExeName, "Put_B1200: No se encontro tarifa Baja plan [%s] se deja blanco ", LOG01, stFaDetCons.stDetConsumo[piRegConcep].szCod_PlanTarif);
        sprintf(szValorHorBaja,"%s"," ");
    }
    else
        sprintf(szValorHorBaja,"%015.4f",dValorHorBaja);

    sprintf(buffer_local,   "B1200%-5.5s%-30.30s%-15.15s%-10.10ld%-15.15s%-15.15s%-15.15s%-8.8s%-8.8s\n",
                        pstAux->szCod_Plantarif,
                        pstAux->szDes_Plantarif,
                        szValorPlan,
                        pstAux->lMinutosPlan,
                        szValorHorAlta,/*Valor Horario Alta*/
                        szValorHorNorm,/*Valor horario Normal*/
                        szValorHorBaja,/*Valor horario Reducido*/
                        szFec_Desde,
                        szFec_Hasta);

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog(szModulo,"No pudo escribir en archivo",LOG01);
        return(FALSE);
    }
    return  (TRUE);
}


int put_b1300(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char    buffer_local[200];
    int     i;
    int     iCategoria;
    long    lTotMinTrafico      = 0;
    double  dTotMtoCargoTrafico = 0.0;
    double  dTotMtoCargoBasico  = 0.0;
    double  dTotMtoServicios    = 0.0;
    double  dTotMtoOtrosCargos  = 0.0;
    double  dTotCargosNetos     = 0.0;
    double  dTotPrimCateg       = 0.0;
    double  dTotSegCateg        = 0.0;
    double  dTotAbonado         = 0.0;
    long    lhNumAbonado;

    strcpy (szModulo, "put_b1300");
    vDTrazasLog(szModulo,"Entrando a funcion %s",LOG05, szModulo);

    lhNumAbonado = stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado;

    vDTrazasLog(szModulo,"abonado [%ld]",LOG05, lhNumAbonado);
    vDTrazasLog(szModulo,"Cantidad de Conceptos [%d]",LOG05, stFaDetCons.iNumReg);

    for (i=0;i < stFaDetCons.iNumReg ;i++)
    {
        if (stFaDetCons.stDetConsumo[i].lNumAbonado == lhNumAbonado)
        {
            lTotMinTrafico = lTotMinTrafico + stFaDetCons.stDetConsumo[i].iNum_Unidades;
            vDTrazasLog(szModulo,"iTipConcep [%d]",LOG05, stFaDetCons.stDetConsumo[i].iTipConcep);
            switch(stFaDetCons.stDetConsumo[i].iTipConcep)
            {
                 case 1:
                     dTotMtoCargoTrafico += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                     break;
                 case 2:
                     dTotMtoCargoBasico  += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                     break;
                 case 3:
                     dTotMtoServicios    += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                     break;
                 case 4:
                     dTotMtoOtrosCargos  += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                     break;
            }
            vDTrazasLog(szModulo,"iCodTipConce [%d]",LOG05, stFaDetCons.stDetConsumo[i].iCodTipConce);
            vDTrazasLog(szModulo,"dTotalFacturableNet [%15.4f]",LOG05, stFaDetCons.stDetConsumo[i].dTotalFacturableNet);
            if (stFaDetCons.stDetConsumo[i].iCodTipConce != 1)
            {
                dTotCargosNetos += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
            }
            else
            {
                if(bfnBuscaCategImpto(stFaDetCons.stDetConsumo[i].iCodConcepto,&iCategoria,stFaDetCons.stDetConsumo[i].dPrcImpuesto))
                {
                    if (iCategoria == iGPrimCateg)
                    {
                        dTotPrimCateg += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                    }
                    else
                    {
                        dTotSegCateg += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                    }
                }
            }
        }
    }

    dTotAbonado=dTotCargosNetos + dTotPrimCateg + dTotSegCateg;
    vDTrazasLog(szModulo,"dTotAbonado [%15.4f]",LOG05, dTotAbonado);

    sprintf(buffer_local,"B1300%010.10ld%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f%015.4f\n",
                         lTotMinTrafico,
                         dTotMtoCargoTrafico,
                         dTotMtoCargoBasico,
                         dTotMtoServicios,
                         dTotMtoOtrosCargos,
                         dTotCargosNetos,
                         dTotPrimCateg,
                         dTotSegCateg,
                         dTotAbonado);

    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b1300","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }

    return(TRUE);
}

/* Inicio P-ECU-12024*/
int put_b1500(FILE *Fd_ArchImp,int iRegConcep,char * buffer)
{
    char    buffer_local[200];
    int     i;
    long    lhNumAbonado;


    strcpy (szModulo, "put_b1500");
    vDTrazasLog(szModulo,"Entrando a funcion %s",LOG05, szModulo);
    lhNumAbonado = stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado;

    vDTrazasLog(szModulo,"Generando B1500 %s",LOG05, szModulo);
    sprintf(buffer_local,"B1500\n");
    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b1500","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }
    
    memset(buffer_local,'\0',sizeof(buffer_local));
    vDTrazasLog(szModulo,"Generando B1550 %s",LOG05, szModulo);
    vDTrazasLog(szModulo,"iContRegSS   [%d]",LOG05, iContRegSS);
    vDTrazasLog(szModulo,"lhNumAbonado [%ld]",LOG05, lhNumAbonado);

    for (i=0;i < iContRegSS ;i++)
    {
        
       if (lhNumAbonado==servsuplan.lNum_Abonado[i]) {
			    vDTrazasLog(szModulo,"<< lNum_Abonado >>  [%d]",LOG05, servsuplan.lNum_Abonado[i]);
			    vDTrazasLog(szModulo,"iTip_serv      [%d]",LOG05, servsuplan.iTip_serv[i]);
			    vDTrazasLog(szModulo,"szCod_categoria[%s]",LOG05, servsuplan.szCod_categoria[i]);
			    vDTrazasLog(szModulo,"iCod_concepto  [%d]",LOG05, servsuplan.iCod_concepto[i]);
			    vDTrazasLog(szModulo,"szDes_concepto [%s]",LOG05, servsuplan.szDes_concepto[i]);
			    vDTrazasLog(szModulo,"szFec_altacen  [%s]",LOG05, servsuplan.szFec_altacen[i]);
			    vDTrazasLog(szModulo,"szFec_bajabd   [%s]\n",LOG05, servsuplan.szFec_bajabd[i]);
			    sprintf(buffer_local,"B1550%1d%1s%010d%-50s%8s%8s\n",
			                         servsuplan.iTip_serv[i],
			                         servsuplan.szCod_categoria[i],
			                         servsuplan.iCod_concepto[i],
			                         servsuplan.szDes_concepto[i],
			                         servsuplan.szFec_altacen[i],
			                         servsuplan.szFec_bajabd[i]);
			    
			    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
			    {
			        vDTrazasLog("put_b1500","No pudo escribir en archivo",LOG01);
			        return(FALSE);
			    }
		  }
    }


    memset(buffer_local,'\0',sizeof(buffer_local));
    vDTrazasLog(szModulo,"Generando B1590 %s",LOG05, szModulo);
    sprintf(buffer_local,"B1590\n");
    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
    {
        vDTrazasLog("put_b1500","No pudo escribir en archivo",LOG01);
        return(FALSE);
    }
    
    return(TRUE);
}
 /*Fin P-ECU-12024*/


int put_b2000_b3000(FILE *Fd_ArchImp, int iRegConcep,int breg23, int *impb2000,int *impb3000,char * buffer)
{
    char buffer_local[200];
    register int i = 0;
    long lDuracion = 0L;
    double dCosto = 0.0;

    memset(buffer_local,0,sizeof(buffer_local));

    if(breg23==2 || breg23==0)
    {
        for(i=0;i<stFaDetCons.iNumReg;i++)
        {
            if( (stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo == stFaDetCons.stDetConsumo[i].iCodGrupo)
             && (stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado == stFaDetCons.stDetConsumo[i].lNumAbonado) )
            {
                lDuracion += stFaDetCons.stDetConsumo[i].lSeg_Consumo;
                dCosto    += stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
            }
        }

        sprintf(buffer_local,"B2000%05.5d%-50.50s%1.1s%012.12ld%1.1d%-5.5s%-5.5s%015.4f\n"
                            ,stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo
                            ,stFaDetCons.stDetConsumo[iRegConcep].szGlosaGrupo
                            ,stFaDetCons.stDetConsumo[iRegConcep].szCod_Nivel
                            ,lDuracion
                            ,stFaDetCons.stDetConsumo[iRegConcep].iNivelImpresion
                            ,stFaDetCons.stDetConsumo[iRegConcep].szTipUnidad
                            ,stFaDetCons.stDetConsumo[iRegConcep].szTipGrupo
                            ,fnCnvDouble(dCosto,USOFACT));


        *impb2000 = TRUE;
        buffer_local[_strlen(buffer_local)]=0;

        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
        {
            vDTrazasLog("put_b2000_b3000:2","No pudo escribir en archivo",LOG01);
            return(FALSE);
        }
    }
    if(breg23 == 3 || breg23==0)
    {
        sprintf(buffer_local,"B3000%05.5d%05.5d%-50.50s\n",stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo,stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo,stFaDetCons.stDetConsumo[iRegConcep].szGlosaSubGrupo);
        *impb3000 = TRUE;
        buffer_local[_strlen(buffer_local)]=0;

        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
        {
            vDTrazasLog("put_b2000_b3000:3","No pudo escribir en archivo",LOG01);
            return(FALSE);
        }
    }

    return(TRUE);
}


int hay_b2000_b3000(FILE *Fd_ArchImp,int iRegConcep,int ihayRegistros_7,int ihayRegistros_6,int breg23,int *impb2000,int *impb3000,char * buffer)
{
    int itipo_7;
    int itipo_6;
    int iesCuota;

    itipo_7=(stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo==CUOTAS_PAGARES)?TRUE:FALSE;
    itipo_6=(stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo==6)?TRUE:FALSE;
    iesCuota=(((atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA)||(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)))? TRUE:FALSE;


    

    if(((itipo_7&&ihayRegistros_7&&iesCuota)||(itipo_6&&ihayRegistros_6))||(!itipo_7&&!itipo_6))
    {
      if(!put_b2000_b3000(Fd_ArchImp,iRegConcep,breg23,impb2000,impb3000,buffer)) return(FALSE);
    }
    return(TRUE);
}


/************************************************************************************/
int PutDetConsu(ST_ABONADO             *Abonado,
                FILE                   *Fd_ArchImp,
                ST_CUOTAS              *pstFaCuotas,
                STSALDO_ANTERIOR       *SaldoTot,
                ST_FACTCLIE            *pst_Cliente,
                char                   * buffer,
                DETALLEOPER            *st_MascaraOper,
                DET_TRANSACCIONES      *pstDetTrans,
                int                    iTasador,
                long                   lCodCiclFact,
                BOOL                   Flag_ExisCarrier)
{
    char  *szModulo= "PutDetConsu";
    int   iRegConcep;
    long  lhayAbonado;
    int   ihayGrupo;
    int   ihaySubGrupo;
    int   ihayRegistros_7;
    int   ihayRegistros_6;
    int   iesCuota;
    int   iInicio=TRUE;
    int   iesAbonado_0;
    int   itipo;
    int   AbonadoEncontrado;
    int   impb2000=FALSE;
    int   impb3000=FALSE;
    int   iIdxPagos = 0;
    int   iIdxMovim = 0;
    int   iFlagPagos = FALSE;
    int   iFlagMovim = FALSE;
    int   impb1000 = 0; /*MLA 125396*/
    long  lNumAbonadoAux = 0L;
    int   iImprimioB4007 = FALSE;
    register int   i=0;

    char  buffer_local[200];

    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);

    memset(buffer_local,0,sizeof(buffer_local));

    vDTrazasLog(szModulo,"***** Detalle Consumo *****",LOG04);
    ihayRegistros_7= ((pstFaCuotas->iNum_RegCuotas_venci>0)||(pstFaCuotas->iNum_RegCuotas_pven>0))? TRUE:FALSE;
    ihayRegistros_6= (SaldoTot->iNum_RegSaldo>0)? TRUE:FALSE;
    iesAbonado_0=(Abonado->lNumAbonado[0]==0)?FALSE:TRUE;

  /*---------------------------------------------------------------
    SOLO IMPRIME SI EXITEN REGISTROS B4006 O B4007 :
    SI ABONADO CERO:
    NO EXISTE CREARLO Y COLOCAR DENTRO B4006 Y B4007
    SI EXISTE COLOCAR B4006 Y B4007 NORMALMENTE EN EL SWITCH
    ---------------------------------------------------------------*/

    vDTrazasLog(szModulo,"\tAntes de if-%s():\n"
                        "\t\tihayRegistros_7: [%d]\n"
                        "\t\tihayRegistros_6: [%d]\n"
                        "\t\tiesAbonado_0   : [%d]\n"
                        ,LOG06,szModulo
                        ,ihayRegistros_7
                        ,ihayRegistros_6
                        ,iesAbonado_0);

    if((ihayRegistros_7&&iesAbonado_0)||(ihayRegistros_6&&iesAbonado_0))
    {
        vDTrazasLog(szModulo,"Dentro de if %s():\n"
                           "\tstFaDetCons.iNumReg: [%d]"
                           ,LOG06,szModulo
                           ,stFaDetCons.iNumReg);

        for(iRegConcep=0;iRegConcep<stFaDetCons.iNumReg;iRegConcep++)
        {
            vDTrazasLog(szModulo,"Dentro de for de abonado cero: iRegConcep: [%d]",LOG03,iRegConcep);
            /*---------------------------------------------------------------
              REGISTRO B4007
              ---------------------------------------------------------------*/
            if(stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo==CUOTAS_PAGARES)
            {
                iesCuota=(((atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA)||(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)))? TRUE:FALSE;
                if(iesCuota)
                {
                    vDTrazasLog(szModulo,"TipSubGrupo : [%d] Cuota: [%d] Vencida :[%d] Por Vencer :[%d]"
                                 ,LOG04, stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo,atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact), pstFaCuotas->iNum_RegCuotas_venci,pstFaCuotas->iNum_RegCuotas_pven);
                    if(iInicio)
                    {
                        iInicio=FALSE;

                        if(!put_b1000(Abonado,Fd_ArchImp,iRegConcep,-1,0,buffer))
                            return(FALSE);

                        impb1000 = 1; /*MLA 125396*/

                        if (BuscaMascara(st_MascaraOper,"B1100",pst_Cliente->iCodTipDocum))
                        {
                            if(!put_b1100(pst_Cliente,Fd_ArchImp,iRegConcep,0,buffer))
                               return(FALSE);
                        }

                        if(!put_b1200(Fd_ArchImp,iRegConcep,pst_Cliente, lCodCiclFact, buffer))
                            return(FALSE);
                        if(!put_b1300(Fd_ArchImp,iRegConcep,buffer))
                            return(FALSE);
                        /* Inicio P-ECU-12024*/
                        if(!put_b1500(Fd_ArchImp,iRegConcep,buffer))
                            return(FALSE);
                         /*Fin P-ECU-12024*/
                    }
                    /*---------------------------------------------------------------
                      CUOTA_VENCIDA
                      ---------------------------------------------------------------*/
                    if(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA)
                    {
                        ihayRegistros_7= (pstFaCuotas->iNum_RegCuotas_venci>0)? TRUE:FALSE;
                        if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,0,&impb2000,&impb3000,buffer)) return(FALSE);
                    }

                    if (BuscaMascara(st_MascaraOper,"B4007",pst_Cliente->iCodTipDocum))
                    {
                        vDTrazasLog(szModulo,"\t****%s: Se va a entrar a put_b4007(), Desde abonado cero, cuota vencida...",LOG06,szModulo);
                        if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_venci,iRegConcep,pstFaCuotas->iNum_RegCuotas_venci,CUOTA_VENCIDA, stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado,buffer))
                        return(FALSE);
                    }

                    if(impb3000==TRUE)
                    {
                        sprintf(buffer_local,"B3333\n\0");
                        impb3000 = FALSE ;
                        buffer_local[_strlen(buffer_local)]=0;
                        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                        {
                            vDTrazasLog(szModulo," B3333 No pudo escribir en archivo",LOG01);
                            return(FALSE);
                        }
                    }
                    if(impb2000==TRUE)
                    {
                        sprintf(buffer_local,"B2222\n");
                        impb2000 = FALSE ;
                        buffer_local[_strlen(buffer_local)]=0;
                        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                        {
                            vDTrazasLog(szModulo,"B2222 No pudo escribir en archivo",LOG01);
                            return(FALSE);
                        }
                    }

                    /*---------------------------------------------------------------
                      CUOTA_PORVENCER
                      ---------------------------------------------------------------*/
                    if(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)
                    {
                        ihayRegistros_7= (pstFaCuotas->iNum_RegCuotas_pven>0)? TRUE:FALSE;
                        if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,0,&impb2000,&impb3000,buffer)) return(FALSE);
                    }

                    if (BuscaMascara(st_MascaraOper,"B4007",pst_Cliente->iCodTipDocum))
                    {
                        vDTrazasLog(szModulo,"\t****%s: Se va a entrar a put_b4007(), Desde abonado cero, cuota por vencer...",LOG06,szModulo);
                        if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_pven,iRegConcep,pstFaCuotas->iNum_RegCuotas_pven,CUOTA_PORVENCER, stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado,buffer)) return(FALSE);
                    }

                    if(impb3000==TRUE)
                    {
                        sprintf(buffer_local,"B3333\n");
                        impb3000 = FALSE ;
                        buffer_local[_strlen(buffer_local)]=0;
                        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                        {
                            vDTrazasLog(szModulo,"B3333 No pudo escribir en archivo",LOG01);
                            return(FALSE);
                        }
                    }
                    if(impb2000==TRUE)
                    {
                        sprintf(buffer_local,"B2222\n");
                        impb2000 = FALSE ;
                        buffer_local[_strlen(buffer_local)]=0;
                        if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                        {
                            vDTrazasLog(szModulo,"B2222 No pudo escribir en archivo",LOG01);
                            return(FALSE);
                        }
                    }


                } /*  Es Cuota*/

            }  /* Subtipo 7 */
            /*---------------------------------------------------------------
              REGISTRO B4006
              ---------------------------------------------------------------*/
            if(stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo==SALDO_ANTERIOR)
            {
                if(iInicio)
                {
                  iInicio=FALSE;
                  if(!put_b1000(Abonado,Fd_ArchImp,iRegConcep,AbonadoEncontrado,0,buffer)) return(FALSE);

                  impb1000 = 1; /*MLA 125396*/

                  if (BuscaMascara(st_MascaraOper,"B1100",pst_Cliente->iCodTipDocum))
                  {
                      if(!put_b1100(pst_Cliente,Fd_ArchImp,iRegConcep,0,buffer))
                         return(FALSE);
                  }

                  if(!put_b1200(Fd_ArchImp,iRegConcep,pst_Cliente, lCodCiclFact, buffer)) return(FALSE);
                  if(!put_b1300(Fd_ArchImp,iRegConcep,buffer)) return(FALSE);
                  /* Inicio P-ECU-12024*/
                  if(!put_b1500(Fd_ArchImp,iRegConcep,buffer)) return(FALSE);
                   /*Fin P-ECU-12024*/
                  
                }
                if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,0,&impb2000,&impb3000,buffer))
                    return(FALSE);
                if(!put_b4006(Fd_ArchImp,SaldoTot,iRegConcep,buffer))
                    return(FALSE);

                if(impb3000==TRUE)
                {
                    sprintf(buffer_local,"B3333\n");
                    impb3000 = FALSE ;
                    buffer_local[_strlen(buffer_local)]=0;
                    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                    {
                        vDTrazasLog(szModulo,"B3333 No pudo escribir en archivo",LOG01);
                        return(FALSE);
                    }
                }
                if(impb2000==TRUE)
                {
                    sprintf(buffer_local,"B2222\n");
                    impb2000 = FALSE ;
                    buffer_local[_strlen(buffer_local)]=0;
                    if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                    {
                        vDTrazasLog(szModulo,"B2222 No pudo escribir en archivo",LOG01);
                        return(FALSE);
                    }
                }
            }  /* Subtipo 6 */
        }  /* For Conceptos */

         /* Inicio Registros B50XX*/
         iFlagPagos = FALSE;
         for(iIdxPagos=0;iIdxPagos<pstDetTrans->stPagosClie.iNumRegDetPag;iIdxPagos++)
         {
            if (pstDetTrans->stPagosClie.stDetPagosClie[iIdxPagos].lNumAbonado == 0)
            {
                iFlagPagos = TRUE;
                break;
            }

         }
         iFlagMovim = FALSE;
         for(iIdxMovim=0;iIdxMovim<pstDetTrans->stMovimClie.iNumRegDetMov;iIdxMovim++)
         {
            if (pstDetTrans->stMovimClie.stDetMovimClie[iIdxMovim].lNumAbonado == 0)
            {
                iFlagMovim = TRUE;
                break;
            }

         }

         if (BuscaMascara(st_MascaraOper,"B5000",pst_Cliente->iCodTipDocum) 
         	&& (iFlagPagos || iFlagMovim) )
         {
             if ( impb1000 == 0 ) /*MLA 125396*/
             {
                   if(!put_b1000(Abonado,Fd_ArchImp,0,-1,0,buffer))
                     return(FALSE);

                   impb1000 = 1;
                   iInicio=FALSE;
             }

             if(!put_b5000(Fd_ArchImp,pstDetTrans,iFlagPagos,iIdxPagos,iFlagMovim,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5010",pst_Cliente->iCodTipDocum)
         	 && iFlagMovim  )
         {
             if(!put_b5010(Fd_ArchImp,pstDetTrans->stMovimClie.stDetMovimClie,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5020",pst_Cliente->iCodTipDocum)
             && iFlagPagos )
         {
             if(!put_b5020(Fd_ArchImp,pstDetTrans->stPagosClie.stDetPagosClie,iIdxPagos,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5030",pst_Cliente->iCodTipDocum)
          	 && iFlagMovim )
         {
             if(!put_b5030(Fd_ArchImp,pstDetTrans->stMovimClie.stDetMovimClie,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5040",pst_Cliente->iCodTipDocum)
         	 && iFlagPagos )
         {
             if(!put_b5040(Fd_ArchImp,pstDetTrans->stPagosClie.stDetPagosClie,iIdxPagos,buffer))
                 return(FALSE);
         }
         /* Fin Registros B50XX*/

        if(!iInicio)
        {
            iInicio=FALSE;
            sprintf(buffer_local,"B1111\n");
            buffer_local[_strlen(buffer_local)]=0;

            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
                vDTrazasLog(szModulo,"B1111 No pudo escribir en archivo",LOG01);
                return(FALSE);
            }
            sprintf(buffer_local,"H1111\n\0");
            buffer_local[_strlen(buffer_local)]=0;
            if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
            {
                vDTrazasLog(szModulo,"H1111 No pudo escribir en archivo",LOG01);
                return(FALSE);
            }
        }
    }
   /*****************************************/
    iRegConcep=0;
    impb2000=FALSE;
    impb3000=FALSE;

    while(iRegConcep < stFaDetCons.iNumReg)
    {
         vDTrazasLog(szModulo,"\t****%s: Dentro de while de stFaDetCons.iNumReg\n"
                              "\t    stFaDetCons.iNumReg:                        [%d]\n"
                              "\t    iRegConcep:                                 [%d]\n"
                              "\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]\n"
                              "\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado      :[%ld]"
                               ,LOG06,szModulo
                               ,stFaDetCons.iNumReg
                               ,iRegConcep
                               ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo
                               ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado);

         itipo=stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo;
         if(!(itipo==CARGOS_BASICOS||itipo==CARGOS_VARIOS||itipo==TRAFICO||itipo==ARRIENDO_VENTA||itipo==COBRANZA||itipo==SALDO_ANTERIOR||itipo==CUOTAS_PAGARES))
         {
             iRegConcep++;
             continue;
         }
         vDTrazasLog(szModulo,"\t****%s: Dentro de while de stFaDetCons.iNumReg, Paso if(itipo)",LOG06,szModulo);
       /*---------------------------------------------------------------
         BUSCAR ABONADO :
         ---------------------------------------------------------------*/
         if(BuscaAbonado(Abonado,&AbonadoEncontrado,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado))
             return(FALSE);
         vDTrazasLog(szModulo,"\t****%s: Dentro de while de stFaDetCons.iNumReg, Paso BuscaAbonado()"
                              "\t****             AbonadoEncontrado: [%d]",LOG06,szModulo,AbonadoEncontrado);
       /*---------------------------------------------------------------
         PRINT B1000 :
         ---------------------------------------------------------------*/
         if(AbonadoEncontrado == -1)
         {
             iRegConcep++;
             continue;
         }

         vDTrazasLog(szModulo,"\t****%s: Dentro de while de stFaDetCons.iNumReg, Antes de put_b1000()",LOG06,szModulo);
         if(!put_b1000(Abonado,Fd_ArchImp,iRegConcep,AbonadoEncontrado,1,buffer))
             return(FALSE);

         if (BuscaMascara(st_MascaraOper,"B1100",pst_Cliente->iCodTipDocum))
         {
             if(!put_b1100(pst_Cliente,Fd_ArchImp,iRegConcep,1,buffer))
                return(FALSE);
         }

         if(!put_b1200(Fd_ArchImp,iRegConcep,pst_Cliente, lCodCiclFact,buffer))
             return(FALSE);
         if(!put_b1300(Fd_ArchImp,iRegConcep,buffer))
             return(FALSE);
         /* Inicio P-ECU-12024*/
         if(!put_b1500(Fd_ArchImp,iRegConcep,buffer))
             return(FALSE);
          /*Fin P-ECU-12024*/

       /*---------------------------------------------------------------
         WHILE ABONADO :
         ---------------------------------------------------------------*/
         lhayAbonado=stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado;
         vDTrazasLog(szModulo,"\t\t****%s: Antes de while de ABONADO...\n"
                              "\t\t    iRegConcep:                                 [%d]\n"
                              "\t\t    lhayAbonado:                                [%ld]\n"
                              "\t\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado :     [%ld]\n"
                              "\t\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]"
                             ,LOG06,szModulo
                             ,iRegConcep
                             ,lhayAbonado
                             ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                             ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo);

         while((lhayAbonado==stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado)&&
              (iRegConcep < stFaDetCons.iNumReg))
         {
              vDTrazasLog(szModulo,"\t\t****%s: Dentro de while de ABONADO...\n"
                                   "\t\t    iRegConcep:                                 [%d]\n"
                                   "\t\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado :     [%ld]\n"
                                   "\t\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]"
                                  ,LOG06,szModulo
                                  ,iRegConcep
                                  ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                                  ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo);

              ihayRegistros_7= (((pstFaCuotas->iNum_RegCuotas_venci>0)&&(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA))||
                               ((pstFaCuotas->iNum_RegCuotas_pven>0  )&&(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)))? TRUE:FALSE;

              if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,2,&impb2000,&impb3000,buffer)) return(FALSE);
            /*---------------------------------------------------------------
              WHILE GRUPO :
              ---------------------------------------------------------------*/
              ihayGrupo = stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo;

              while((lhayAbonado==stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado)&&
                    (iRegConcep < stFaDetCons.iNumReg)&&
                    (ihayGrupo == stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo))
              {
                   vDTrazasLog(szModulo,"\t\t****%s: Dentro de while de GRUPO...\n"
                                        "\t\t    iRegConcep:                                 [%d]\n"
                                        "\t\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado :     [%ld]\n"
                                        "\t\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]"
                                         ,LOG06,szModulo
                                         ,iRegConcep
                                         ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                                         ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo);

                   ihayRegistros_7= (((pstFaCuotas->iNum_RegCuotas_venci>0)&&(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_VENCIDA))||
                                    ((pstFaCuotas->iNum_RegCuotas_pven>0  )&&(atoi(stFaDetCons.stDetConsumo[iRegConcep].szTip_ConcNoFact)==CUOTA_PORVENCER)))? TRUE:FALSE;
                   if(impb2000==FALSE)
                   {
                     if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,2,&impb2000,&impb3000,buffer))
                         return(FALSE);
                   }
                   if(!hay_b2000_b3000(Fd_ArchImp,iRegConcep,ihayRegistros_7,ihayRegistros_6,3,&impb2000,&impb3000,buffer))
                       return(FALSE);
                   ihaySubGrupo = stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo;

                   vDTrazasLog(szModulo,"\t\t****%s: Antes de while de SUBGRUPO...\n"
                                        "\t\t    iRegConcep:                                 [%d]\n"
                                        "\t\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado :     [%ld]\n"
                                        "\t\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]"
                                        ,LOG06,szModulo
                                        ,iRegConcep
                                        ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                                        ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo);
                 /*---------------------------------------------------------------
                   WHILE SUBGRUPO :
                   ---------------------------------------------------------------*/
                   while((lhayAbonado== stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado)&&
                        (iRegConcep  <  stFaDetCons.iNumReg)&&
                        (ihayGrupo   == stFaDetCons.stDetConsumo[iRegConcep].iCodGrupo)&&
                        (ihaySubGrupo== stFaDetCons.stDetConsumo[iRegConcep].iCodSubGrupo))
                   {
                        vDTrazasLog(szModulo,"\t\t****%s: Dentro de while de SUBGRUPO...\n"
                                             "\t\t    iRegConcep:                                 [%d]\n"
                                             "\t\t    stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado :     [%ld]\n"
                                             "\t\t    stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo :[%d]"
                                            ,LOG06,szModulo
                                            ,iRegConcep
                                            ,stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado
                                            ,stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo);

                        switch(stFaDetCons.stDetConsumo[iRegConcep].iCod_TipSubGrupo)
                        {
                            case CARGOS_BASICOS:
                                if(!put_b4001(Fd_ArchImp,iRegConcep,buffer,pst_Cliente))
                                    return(FALSE);
                                break;
                            case CARGOS_VARIOS:
                                if(!put_b4002(Fd_ArchImp,iRegConcep,buffer))
                                    return(FALSE);
                                break;
                            case TRAFICO:
                                if(!put_b4003(Fd_ArchImp,iRegConcep,buffer))
                                    return(FALSE);
                                break;
                            case ARRIENDO_VENTA:
                                if(!put_b4004(Fd_ArchImp,iRegConcep,buffer))
                                    return(FALSE);
                                break;
                            case COBRANZA:
                                if(!put_b4005(Fd_ArchImp,iRegConcep,buffer))
                                    return(FALSE);
                                break;
                            case SALDO_ANTERIOR:
                                if(!put_b4006(Fd_ArchImp,SaldoTot,iRegConcep,buffer))
                                    return(FALSE);
                                break;
                            case CUOTAS_PAGARES:
                                if (BuscaMascara(st_MascaraOper,"B4007",pst_Cliente->iCodTipDocum))
                                {
                                    vDTrazasLog(szModulo,"\t****%s: Se va a entrar a put_b4007(), Desde WHILE SUBGRUPO...",LOG06,szModulo);
                                    if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_venci,iRegConcep,pstFaCuotas->iNum_RegCuotas_venci,CUOTA_VENCIDA, stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado,buffer))
                                        return(FALSE);
                                    if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_pven, iRegConcep,pstFaCuotas->iNum_RegCuotas_pven, CUOTA_PORVENCER, stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado,buffer))
                                        return(FALSE);
                                }
                                break;
                            case IMPUESTOS:
                                if(!put_b4008(Fd_ArchImp,iRegConcep,buffer))
                                     return(FALSE);
                                break;
                        }

                        lNumAbonadoAux = stFaDetCons.stDetConsumo[iRegConcep].lNumAbonado;

                        iRegConcep++;
                   }

                   if(impb3000==TRUE)
                   {
                       vDTrazasLog(szModulo,"\t****%s: Se va a entrar a put_b4007(), Desde if(impb3000==TRUE)...",LOG06,szModulo);
                       /* Desde aqui llamar a put_b4007 */
                       if(iImprimioB4007==FALSE)
                       {
                          for(i=0;i<stFaDetCons.iNumReg;i++)
                          {
                              if(stFaDetCons.stDetConsumo[i].iCod_TipSubGrupo==CUOTAS_PAGARES && ( atoi(stFaDetCons.stDetConsumo[i].szTip_ConcNoFact)==CUOTA_VENCIDA )  )
                              {
                                  if (BuscaMascara(st_MascaraOper,"B4007",pst_Cliente->iCodTipDocum))
                                  {
                                      if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_venci, i,pstFaCuotas->iNum_RegCuotas_venci,CUOTA_VENCIDA,lNumAbonadoAux,buffer))
                                          return(FALSE);
                                  }
                              }
                              if(stFaDetCons.stDetConsumo[i].iCod_TipSubGrupo==CUOTAS_PAGARES && ( atoi(stFaDetCons.stDetConsumo[i].szTip_ConcNoFact)==CUOTA_PORVENCER )  )
                              {
                                  if (BuscaMascara(st_MascaraOper,"B4007",pst_Cliente->iCodTipDocum))
                                  {
                                      if(!put_b4007(Fd_ArchImp,pstFaCuotas->stReg_pven, i,pstFaCuotas->iNum_RegCuotas_pven, CUOTA_PORVENCER,lNumAbonadoAux,buffer))
                                          return(FALSE);
                                  }
                              }
                          }
                          iImprimioB4007=TRUE;
                       }
                       sprintf(buffer_local,"B3333\n\0");
                       impb3000 = FALSE ;
                       buffer_local[_strlen(buffer_local)]=0;

                       if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                       {
                           vDTrazasLog(szModulo,"B3333, No pudo escribir en archivo",LOG01);
                           return(FALSE);
                       }
                   }
              }
              if(impb2000==TRUE)
              {
                  sprintf(buffer_local,"B2222\n");
                  impb2000 = FALSE ;
                  buffer_local[_strlen(buffer_local)]=0;

                  if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
                  {
                      vDTrazasLog(szModulo,"B2222,No pudo escribir en archivo",LOG01);
                      return(FALSE);
                  }
              }
         }

         /* Inicio Registros B50XX*/
         iFlagPagos = FALSE;
         for(iIdxPagos=0;iIdxPagos<pstDetTrans->stPagosClie.iNumRegDetPag;iIdxPagos++)
         {
            if (pstDetTrans->stPagosClie.stDetPagosClie[iIdxPagos].lNumAbonado == lhayAbonado)
            {
                iFlagPagos = TRUE;
                break;
            }

         }
         iFlagMovim = FALSE;
         for(iIdxMovim=0;iIdxMovim<pstDetTrans->stMovimClie.iNumRegDetMov;iIdxMovim++)
         {
            if (pstDetTrans->stMovimClie.stDetMovimClie[iIdxMovim].lNumAbonado == lhayAbonado)
            {
                iFlagMovim = TRUE;
                break;
            }

         }

         if (BuscaMascara(st_MascaraOper,"B5000",pst_Cliente->iCodTipDocum)
         	&& (iFlagPagos || iFlagMovim) )
         {
             if(!put_b5000(Fd_ArchImp,pstDetTrans,iFlagPagos,iIdxPagos,iFlagMovim,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5010",pst_Cliente->iCodTipDocum)
         	 && iFlagMovim)
         {
             if(!put_b5010(Fd_ArchImp,pstDetTrans->stMovimClie.stDetMovimClie,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5020",pst_Cliente->iCodTipDocum)
         	&& iFlagPagos)
         {
             if(!put_b5020(Fd_ArchImp,pstDetTrans->stPagosClie.stDetPagosClie,iIdxPagos,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5030",pst_Cliente->iCodTipDocum)
         	 && iFlagMovim)
         {
             if(!put_b5030(Fd_ArchImp,pstDetTrans->stMovimClie.stDetMovimClie,iIdxMovim,buffer))
                 return(FALSE);
         }

         if (BuscaMascara(st_MascaraOper,"B5040",pst_Cliente->iCodTipDocum)
         	 && iFlagPagos)
         {
             if(!put_b5040(Fd_ArchImp,pstDetTrans->stPagosClie.stDetPagosClie,iIdxPagos,buffer))
                 return(FALSE);
         }
         /* Fin Registros B50XX*/

         sprintf(buffer_local,"B1111\n");
         buffer_local[_strlen(buffer_local)]=0;

         if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
         {
             vDTrazasLog(szModulo,"B1111, No pudo escribir en archivo",LOG01);
             return(FALSE);
         }
         if(!bfnTrataFactTrafico(Abonado,pst_Cliente,Fd_ArchImp,AbonadoEncontrado,buffer, st_MascaraOper,iTasador, Flag_ExisCarrier))
         {
             vDTrazasLog(szModulo,"Sin Registros de trafico ",LOG03);
         }
         sprintf(buffer_local,"H1111\n\0");
         buffer_local[_strlen(buffer_local)]=0;
         if(!bEscribeEnArchivo(Fd_ArchImp,buffer,buffer_local))
         {
             vDTrazasLog(szModulo,"H1111, No pudo escribir en archivo",LOG01);
             return(FALSE);
         }
         iImprimioB4007=FALSE; /* ECU-05021 */
    }
    return(TRUE);
}


/************************************************************************/
/*  Funcion: int bfnGetNumProcesoCiclo(LINEACOMANDO)                    */
/*  Funcion que recupera Numero de Proceso para Ciclo de Facturacion    */
/************************************************************************/
int GetNumProcesoCiclo(LINEACOMANDO *pstLineaComando)
{
   /****************************************************************************/
   /*  Selecciona Numero de Proceso para el Ciclo de Facturacion               */
   /****************************************************************************/
    strcpy (szModulo, "GetNumProcesoCiclo");
    vDTrazasLog(szModulo,"\t** Entrando en %s"
                         "\n\t\tCodigo de Ciclo Fact.     [%ld]"
                         "\n\t\tCodigo de Tipo Doc.       [%d]"
                         ,LOG04,szModulo, pstLineaComando->lCodCiclFact,pstLineaComando->iCodTipDocum);
    /* EXEC SQL
      SELECT NUM_PROCESO
        INTO :pstLineaComando->lNumProceso
        FROM FA_PROCESOS
       WHERE COD_CICLFACT = :pstLineaComando->lCodCiclFact
         AND ROWNUM < 2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NUM_PROCESO into :b0  from FA_PROCESOS where (COD_\
CICLFACT=:b1 and ROWNUM<2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )890;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pstLineaComando->lNumProceso);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(pstLineaComando->lCodCiclFact);
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




    if(SQLCODE == SQLNOTFOUND)
    {
      vDTrazasLog  (szModulo,"\tNo Existen Datos en FA_PROCESOS **"
                             "\tPara el Cod_CiclFact     [%ld]"
                             "\tCodigo de Tipo Doc.       [%d]"
                             ,LOG04,pstLineaComando->lCodCiclFact,pstLineaComando->iCodTipDocum);
      vDTrazasError(szModulo,"\tNo Existen Datos en FA_PROCESOS  **"
                             "\tPara el Cod_CiclFact     [%ld]"
                             "\tCodigo de Tipo Doc.       [%d]"
                             ,LOG04,pstLineaComando->lCodCiclFact,pstLineaComando->iCodTipDocum);
      return(FALSE);
    }
    if(SQLCODE != SQLOK)
    {
      vDTrazasLog  (szModulo,"\tNo Existen Datos en FA_PROCESOS **"
                             "\tPara el Cod_CiclFact     [%ld]"
                             ,LOG01,pstLineaComando->lCodCiclFact);
      vDTrazasError(szModulo,"\tNo Existen Datos en FA_PROCESOS  **"
                             "\tPara el Cod_CiclFact     [%ld]"
                             ,LOG01,pstLineaComando->lCodCiclFact);
      return(FALSE);
    }
    return(TRUE);
}

int GetCuotas(ST_CUOTAS * pstFaCuotas,long lCicloFact,long lCodCliente,char *szFec_Vencimi)
{
    int   i = 0, x = 0, k = 0;
    long  lNumCuotas = 0L;

    long lNumFolioAnterior = 0L;
    int  iSecCuotaAnterior = 0;

	  char gszSufTablasCiclo2[15]; /* ej: 150109_123 ciclo_job */
    int rc = 0;
	
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    
    char  szhSql2[5000] = "";
    
    int         ihValorUno = 1 ;
    char        szhRowid        [MAX_CUOTAS_LOCAL][19];/* EXEC SQL VAR szhRowid IS STRING(19); */ 

    int         ihCod_Concepto  [MAX_CUOTAS_LOCAL]    ;
    int         ihNumCuota      [MAX_CUOTAS_LOCAL]    ;
    int         ihSecCuota      [MAX_CUOTAS_LOCAL]    ;
    double      dhMtoCuota      [MAX_CUOTAS_LOCAL]    ;
    long        lhNum_Folio     [MAX_CUOTAS_LOCAL]    ;
    char        szhNum_FolioCtc [MAX_CUOTAS_LOCAL][12];/* EXEC SQL VAR szhNum_FolioCtc IS STRING(12); */ 

    char        szhFecEmision   [MAX_CUOTAS_LOCAL][11];/* EXEC SQL VAR szhFecEmision   IS STRING(11); */ 

    char        szhDes_Cuota    [MAX_CUOTAS_LOCAL][51];/* EXEC SQL VAR szhDes_Cuota    IS STRING(51); */ 

    char        shzFechaEfec    [MAX_CUOTAS_LOCAL][9] ;/* EXEC SQL VAR shzFechaEfec    IS STRING(9); */ 

    int         ihInd_Facturado [MAX_CUOTAS_LOCAL]    ;
    char        szhPrefPlaza    [MAX_CUOTAS_LOCAL][11];/* EXEC SQL VAR szhPrefPlaza    IS STRING(11); */ 
 /* RA-200511230187 */
    long        lhNumAbonado    [MAX_CUOTAS_LOCAL]    ; /* P-ECU-05021 */
    int         ihCod_TipDocum  [MAX_CUOTAS_LOCAL]    ;  /* SAAM-20070423 P-ECU-06034 RF 127 */
    
    long 				l_Num_Secuenci    [MAX_CUOTAS_LOCAL]    ;
    long 				l_Cod_Vendedor_Ag [MAX_CUOTAS_LOCAL]    ;
    char			  sz_Letra          [MAX_CUOTAS_LOCAL][2] ;/* EXEC SQL VAR sz_Letra IS STRING(2); */ 

    long 				l_Cod_Centremi    [MAX_CUOTAS_LOCAL]    ;
    long 				l_Columna         [MAX_CUOTAS_LOCAL]    ;
    char        sz_IndAcelerada   [MAX_CUOTAS_LOCAL][2] ;/* EXEC SQL VAR sz_IndAcelerada IS STRING(2); */ 
 /* P-ECU-12019 */    
    
    
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (szModulo, "GetCuotas");

    /*SETEO DE ESTRUCTURA A LLENAR :*/
    pstFaCuotas->dTotalCuotas_venci    = 0;
    pstFaCuotas->iNum_RegCuotas_venci  = 0;
    pstFaCuotas->dTotalCuotas_pven     = 0;
    pstFaCuotas->iNum_RegCuotas_pven   = 0;
    pstFaCuotas->dTotalCuotas          = 0;

    memset(&pstFaCuotas->stReg_venci,0,sizeof(pstFaCuotas->stReg_venci));
    memset(&pstFaCuotas->stReg_pven ,0,sizeof(pstFaCuotas->stReg_pven ));
    memset(gszSufTablasCiclo2,0,sizeof(gszSufTablasCiclo2));
    

    lhCodClienteCur  = lCodCliente;
    lhCodCiclFactCur = lCicloFact;
    strcpy(szhFormato_Fecha,"YYYYMMDD");

    vDTrazasLog(szModulo,"\t\tInicio GetCuotas \n"
    					 "\t\tCliente [%ld] Ciclo de Facturacion [%ld] \n", LOG03,lhCodClienteCur,lhCodCiclFactCur);


/* INICIO PARCHE */

    
    if( lNroJob )
    {
        /* Modo JOB proforma */
        /* prepara sufijo para tablas ciclo+job */
        sprintf (gszSufTablasCiclo2, "%ld_%ld", lhCodCiclFactCur, lNroJob);
    }
    else
    {
        /*Modo Normal*/
        /* prepara sufijo para tablas ciclo */
        sprintf (gszSufTablasCiclo2, "%ld", lhCodCiclFactCur);
    }/* if (iEjecutaJob!=0) */

    sprintf(szhSql2,  "\n SELECT A.ROWID,                                  "
			          "\n     A.COD_CONCEPTO,                           "
			          "\n     A.NUM_CUOTA,                              "
			          "\n     A.SEC_CUOTA,                              "
			          "\n     A.MTO_CUOTA,                              "
			          "\n     NVL(A.NUM_FOLIO,0),                       "
			          "\n     NUM_FOLIOCTC,                             "
			          "\n     TO_CHAR(A.FEC_COMPRA,:szhFormato_Fecha),  "
			          "\n     A.IND_FACTURADO,                          "
			          "\n     A.COD_TIPDOCUM,                           "
			          "\n     UPPER(B.DES_TIPDOCUM),                    "
			          "\n     TO_CHAR(A.FEC_VENCIMIE,:szhFormato_Fecha),"
			          "\n     A.PREF_PLAZA,                             "
			          "\n     NUM_ABONADO,         "
			          "\n     A.NUM_SECUENCI,                           " /* by PGG - 3-09-2011 - 174956 */
			          "\n     A.COD_VENDEDOR_AGENTE,                    " /* by PGG - 3-09-2011 - 174956 */
			          "\n     NVL(A.LETRA, 'X'),                        " /* by PGG - 3-09-2011 - 174956 */
			          "\n     A.COD_CENTREMI,                           " /* by PGG - 3-09-2011 - 174956 */
			          "\n     A.COLUMNA,                                " /* by PGG - 3-09-2011 - 174956 */
			          "\n     A.IND_ACELERADA                           " /* P-ECU-12019 */			          
			         "\n FROM GE_TIPDOCUMEN B,     "
			          "\n     FA_CUOTCREDITO_%s A, "
			          "\n     FA_CICLFACT C        "
			         "\n WHERE A.COD_CLIENTE   = :lhCodClienteCur  "
			         "\n   AND C.COD_CICLFACT  = :lhCodCiclFactCur "
			         "\n   AND A.COD_TIPDOCUM  =  B.COD_TIPDOCUM   "
			         "\n   AND A.FEC_VENCIMIE <=  C.FEC_EMISION    "
			         "\n ORDER BY A.NUM_FOLIO,      "
			                  "\n A.FEC_VENCIMIE  , "
			                  "\n A.IND_FACTURADO , "
			                  "\n A.NUM_SECUENCI  , "
			                  "\n A.COD_TIPDOCUM  , "
			                  "\n A.COLUMNA       , "
			                  "\n A.SEC_CUOTA     , "
			                  "\n A.NUM_CUOTA "
			         ,gszSufTablasCiclo2);
	
    /* EXEC SQL PREPARE Sel_Cuotas_JEM FROM :szhSql2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )913;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhSql2;
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


    /*vDTrazasLog(szModulo, "PREPARE Cursor Sel_Cuotas_JEM. [%s][%ld][%s]", LOG03,szhSql2,lhCodClienteCur,SQLERRM);*/
    
    if( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en PREPARE Sel_Cuotas_JEM. Error [%s]\n%s\n", LOG00, SQLERRM,szhSql2);
        return(FALSE);
    }
    
    sqlca.sqlcode = 0;
    
    /* EXEC SQL DECLARE Cursor_Cuotas_JEM CURSOR FOR Sel_Cuotas_JEM; */ 

    /*vDTrazasLog(szModulo, "DECLARE Cursor Sel_Cuotas_JEM. [%ld][%s]", LOG03,lhCodClienteCur,SQLERRM);*/
    if( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en DECLARE Cursor_Cuotas_JEM. Error [%s]\n%s\n", LOG00, SQLERRM,szhSql2);
        return(FALSE);
    }

/* FIN PARCHE */
    sqlca.sqlcode = 0;
    
    /* EXEC SQL OPEN Cursor_Cuotas_JEM USING :szhFormato_Fecha, :szhFormato_Fecha, :lhCodClienteCur, :lhCodCiclFactCur ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )932;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhFormato_Fecha;
    sqlstm.sqhstl[0] = (unsigned long )9;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhFormato_Fecha;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodClienteCur;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclFactCur;
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


    /*vDTrazasLog(szModulo, "OPEN Cursor Sel_Cuotas_JEM. [%ld][%d][%s]", LOG03,lhCodClienteCur,sqlca.sqlcode, SQLERRM);*/
    if(sqlca.sqlcode != SQLOK)
    {
        vDTrazasError(szModulo,"\n\t\tError en OPEN Cursor_Cuotas_JEM (FA_CUOTCREDITO):%s\n", LOG01, SQLERRM);
        return(FALSE);
    }

  	rc = SQLOK;
    while(rc != SQLNOTFOUND)
    {
    	  sqlca.sqlcode = 0;

        /* EXEC SQL FETCH Cursor_Cuotas_JEM
        INTO :szhRowid       ,	
             :ihCod_Concepto ,  
             :ihNumCuota     ,  
             :ihSecCuota     ,  
             :dhMtoCuota     ,  
             :lhNum_Folio    ,  
             :szhNum_FolioCtc,  
             :szhFecEmision  ,  
             :ihInd_Facturado,  
             :ihCod_TipDocum ,  
             :szhDes_Cuota   ,  
             :shzFechaEfec   ,   
             :szhPrefPlaza   ,   
             :lhNumAbonado   ,   
             :l_Num_Secuenci    , /o By PGG - 3-09-2011 - 174956 o/
						 :l_Cod_Vendedor_Ag , /o By PGG - 3-09-2011 - 174956 o/
						 :sz_Letra     ,      /o By PGG - 3-09-2011 - 174956 o/
						 :l_Cod_Centremi,     /o By PGG - 3-09-2011 - 174956 o/
						 :l_Columna ,        /o By PGG - 3-09-2011 - 174956 o/
						 :sz_IndAcelerada ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 46;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )5000;
        sqlstm.offset = (unsigned int  )963;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )19;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)ihCod_Concepto;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )sizeof(int);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)ihNumCuota;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )sizeof(int);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)ihSecCuota;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )sizeof(int);
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)dhMtoCuota;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[4] = (         int  )sizeof(double);
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)lhNum_Folio;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )sizeof(long);
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqharc[5] = (unsigned long  *)0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szhNum_FolioCtc;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )12;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqharc[6] = (unsigned long  *)0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)szhFecEmision;
        sqlstm.sqhstl[7] = (unsigned long )11;
        sqlstm.sqhsts[7] = (         int  )11;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqharc[7] = (unsigned long  *)0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)ihInd_Facturado;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )sizeof(int);
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqharc[8] = (unsigned long  *)0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)ihCod_TipDocum;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )sizeof(int);
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqharc[9] = (unsigned long  *)0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)szhDes_Cuota;
        sqlstm.sqhstl[10] = (unsigned long )51;
        sqlstm.sqhsts[10] = (         int  )51;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqharc[10] = (unsigned long  *)0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)shzFechaEfec;
        sqlstm.sqhstl[11] = (unsigned long )9;
        sqlstm.sqhsts[11] = (         int  )9;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqharc[11] = (unsigned long  *)0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)szhPrefPlaza;
        sqlstm.sqhstl[12] = (unsigned long )11;
        sqlstm.sqhsts[12] = (         int  )11;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqharc[12] = (unsigned long  *)0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)lhNumAbonado;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[13] = (         int  )sizeof(long);
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqharc[13] = (unsigned long  *)0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)l_Num_Secuenci;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[14] = (         int  )sizeof(long);
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqharc[14] = (unsigned long  *)0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)l_Cod_Vendedor_Ag;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[15] = (         int  )sizeof(long);
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqharc[15] = (unsigned long  *)0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)sz_Letra;
        sqlstm.sqhstl[16] = (unsigned long )2;
        sqlstm.sqhsts[16] = (         int  )2;
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqharc[16] = (unsigned long  *)0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)l_Cod_Centremi;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[17] = (         int  )sizeof(long);
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqharc[17] = (unsigned long  *)0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)l_Columna;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[18] = (         int  )sizeof(long);
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqharc[18] = (unsigned long  *)0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)sz_IndAcelerada;
        sqlstm.sqhstl[19] = (unsigned long )2;
        sqlstm.sqhsts[19] = (         int  )2;
        sqlstm.sqindv[19] = (         short *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqharc[19] = (unsigned long  *)0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
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

         /* P-ECU-12019 */
             
		   rc = sqlca.sqlcode;
             
         /*vDTrazasLog(szModulo, "FETCH Cursor Sel_Cuotas_JEM. [%ld][%d][%s]", LOG03,lhCodClienteCur,rc, SQLERRM);*/

         if(rc != SQLOK && rc != SQLNOTFOUND)
         {
             vDTrazasError(szModulo,"\n\t\tError en FETCH Cursor_Cuotas_JEM (FA_CUOTCREDITO):%s\n", LOG01, SQLERRM);
             return(FALSE);
         }

         if (rc == SQLOK)
        	  lNumCuotas = MAX_CUOTAS_LOCAL;
    	   else
    	   	  if (rc == SQLNOTFOUND)
               lNumCuotas = sqlca.sqlerrd[2] % MAX_CUOTAS_LOCAL;
         
         if(!lNumCuotas)
         {
             lNumCuotas = sqlca.sqlerrd[2];
             break;
         }

         for(i = 0; i < lNumCuotas; i++)
         {
         	
        vDTrazasLog(szModulo,"\t\t GetCuotas  lhCodClienteCur[%d] ihCod_Concepto[i][%d] ihNumCuota[i][%d] l_Num_Secuenci[i][%d] l_Cod_Vendedor_Ag[i][%d] sz_Letra[i][%s] l_Cod_Centremi[i][%d] l_Columna[i][%d] sz_IndAcelerada[i][%s] ",LOG05, 
                        lhCodClienteCur,
                        ihCod_Concepto[i],
                        ihNumCuota[i],
                        l_Num_Secuenci[i],
                        l_Cod_Vendedor_Ag[i],
                        sz_Letra[i],
                        l_Cod_Centremi[i],
                        l_Columna[i],
                        sz_IndAcelerada[i]    /* P-ECU-12019 */
                      );         	
         	
             if( ihInd_Facturado[i] == ihValorUno)
             {
                 pstFaCuotas->stReg_venci[x].iCodCliente    =   lhCodClienteCur;
                 pstFaCuotas->stReg_venci[x].iCod_Concepto  =   ihCod_Concepto[i];
                 pstFaCuotas->stReg_venci[x].iNumCuota      =   ihNumCuota[i];
                 pstFaCuotas->stReg_venci[x].iSecCuota      =   ihSecCuota[i];
                 pstFaCuotas->stReg_venci[x].dMtoCuota      =   dhMtoCuota[i];
                 pstFaCuotas->stReg_venci[x].lNum_Folio     =   lhNum_Folio[i];
                 pstFaCuotas->stReg_venci[x].iInd_Facturado =   2;
                 strcpy(pstFaCuotas->stReg_venci[x].szNum_FolioCtc ,szhNum_FolioCtc[i]);
                 strcpy(pstFaCuotas->stReg_venci[x].szRowid        ,szhRowid[i]);
                 strcpy(pstFaCuotas->stReg_venci[x].szFechaEfectiva,shzFechaEfec[i]);
                 strcpy(pstFaCuotas->stReg_venci[x].szFec_Emision  ,szhFecEmision[i]);
                 strcpy(pstFaCuotas->stReg_venci[x].szDes_Cuota    ,szhDes_Cuota[i]);
                 strcpy(pstFaCuotas->stReg_venci[x].szPrefPlaza    ,szhPrefPlaza[i]);
                 pstFaCuotas->stReg_venci[x].iCod_TipDocum =   ihCod_TipDocum[i];
                 pstFaCuotas->stReg_venci[x].lNumAbonado   =   lhNumAbonado[i];
                 /* By PGG - 3-09-2011 - 174956 */
                 pstFaCuotas->stReg_venci[x].l_Num_Secuenci   =   l_Num_Secuenci[i];
                 pstFaCuotas->stReg_venci[x].l_Cod_Vendedor_Ag   =   l_Cod_Vendedor_Ag[i];
                 strcpy(pstFaCuotas->stReg_venci[x].sz_Letra    ,sz_Letra[i]);
                 pstFaCuotas->stReg_venci[x].l_Cod_Centremi   =   l_Cod_Centremi[i];
                 pstFaCuotas->stReg_venci[x].l_Columna   =   l_Columna[i];
                 strcpy(pstFaCuotas->stReg_venci[x].sz_IndAcelerada ,sz_IndAcelerada[i]);    /* P-ECU-12019 */                 
                                                   
                 pstFaCuotas->iNum_RegCuotas_venci++;
                 pstFaCuotas->dTotalCuotas_venci += dhMtoCuota[i];
                 x++;
             }
             else
             {
                 pstFaCuotas->stReg_pven[k].iCodCliente   =   lhCodClienteCur;
                 pstFaCuotas->stReg_pven[k].iCod_Concepto =   ihCod_Concepto[i];
                 pstFaCuotas->stReg_pven[k].iNumCuota     =   ihNumCuota[i];
                 pstFaCuotas->stReg_pven[k].iSecCuota     =   ihSecCuota[i];
                 pstFaCuotas->stReg_pven[k].dMtoCuota     =   dhMtoCuota[i];
                 pstFaCuotas->stReg_pven[k].lNum_Folio    =   lhNum_Folio[i];
                 pstFaCuotas->stReg_pven[k].iInd_Facturado=   ihInd_Facturado[i];
                 strcpy(pstFaCuotas->stReg_pven[k].szNum_FolioCtc ,szhNum_FolioCtc[i]);
                 strcpy(pstFaCuotas->stReg_pven[k].szRowid        ,szhRowid[i]);
                 strcpy(pstFaCuotas->stReg_pven[k].szFechaEfectiva,shzFechaEfec[i]);
                 strcpy(pstFaCuotas->stReg_pven[k].szFec_Emision  ,szhFecEmision[i]);
                 strcpy(pstFaCuotas->stReg_pven[k].szDes_Cuota    ,szhDes_Cuota[i]);
                 strcpy(pstFaCuotas->stReg_pven[k].szPrefPlaza    ,szhPrefPlaza[i]);
                 pstFaCuotas->stReg_pven[k].iCod_TipDocum =   ihCod_TipDocum[i];
                 pstFaCuotas->stReg_pven[k].lNumAbonado   =   lhNumAbonado[i];
                 /* By PGG - 3-09-2011 - 174956 x->k LIA */
                 pstFaCuotas->stReg_pven[k].l_Num_Secuenci   =   l_Num_Secuenci[i];
                 pstFaCuotas->stReg_pven[k].l_Cod_Vendedor_Ag   =   l_Cod_Vendedor_Ag[i];
                 strcpy(pstFaCuotas->stReg_pven[k].sz_Letra    ,sz_Letra[i]);
                 pstFaCuotas->stReg_pven[k].l_Cod_Centremi   =   l_Cod_Centremi[i];
                 pstFaCuotas->stReg_pven[k].l_Columna   =   l_Columna[i];
                 strcpy(pstFaCuotas->stReg_pven[k].sz_IndAcelerada ,sz_IndAcelerada[i]);  /* P-ECU-12019 */                 
                                  
                 
                 pstFaCuotas->iNum_RegCuotas_pven++;
                 pstFaCuotas->dTotalCuotas_pven += dhMtoCuota[i];
                 k++;
             }
         }
         /*P-ECU-10033 AFGS*/
         if(lNumCuotas != MAX_CUOTAS_LOCAL)
         	  break;
    }
    sqlca.sqlcode = 0;

    /* EXEC SQL CLOSE Cursor_Cuotas_JEM; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1058;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /*vDTrazasLog(szModulo, "CLOSE Cursor Sel_Cuotas_JEM. [%ld][%s]", LOG03,lhCodClienteCur,SQLERRM);*/
    if(sqlca.sqlcode != SQLOK)
    {
      vDTrazasError(szModulo,"\n\t\tError en CLOSE Cursor_Cuotas_JEM (FA_CUOTCREDITO):%s\n", LOG01, SQLERRM);
      return(FALSE);
    }
    
    pstFaCuotas->dTotalCuotas = (pstFaCuotas->dTotalCuotas_venci + pstFaCuotas->dTotalCuotas_pven);

    vDTrazasLog(szModulo,"\t N.de  Cuotas en FA_CUOTCREDITO [%ld]",LOG05,lNumCuotas);


    /* Se deben imprimir las cuotas mas vencidas de cada uno de los folios del cliente */
    for(k = 0; k < pstFaCuotas->iNum_RegCuotas_pven; k++)
    {
        if(k == 0) /* Primera vez que se entra al ciclo. */
        {
            pstFaCuotas->stReg_pven[k].iInd_Facturado = 2;
            strcpy(pstFaCuotas->stReg_pven[k].szFechaEfectiva,szFec_Vencimi);
            lNumFolioAnterior = pstFaCuotas->stReg_pven[k].lNum_Folio;
            iSecCuotaAnterior = pstFaCuotas->stReg_pven[k].iSecCuota;
        }
        else
        {
            /* Si el folio actual es distinto al anterior, se marca. */
            if(pstFaCuotas->stReg_pven[k].lNum_Folio != lNumFolioAnterior)
            {
                pstFaCuotas->stReg_pven[k].iInd_Facturado = 2;
                strcpy(pstFaCuotas->stReg_pven[k].szFechaEfectiva,szFec_Vencimi);
                lNumFolioAnterior = pstFaCuotas->stReg_pven[k].lNum_Folio;
                iSecCuotaAnterior = pstFaCuotas->stReg_pven[k].iSecCuota;
            }
            else
            {
                /* Si es igual, verificar sec_cuota. */
                if(pstFaCuotas->stReg_pven[k].iSecCuota == iSecCuotaAnterior)
                {
                    pstFaCuotas->stReg_pven[k].iInd_Facturado = 2;
                    strcpy(pstFaCuotas->stReg_pven[k].szFechaEfectiva,szFec_Vencimi);
                    lNumFolioAnterior = pstFaCuotas->stReg_pven[k].lNum_Folio;
                    iSecCuotaAnterior = pstFaCuotas->stReg_pven[k].iSecCuota;
                }
                else
                {
                    /* Solo se actualiza el folio anterior */
                    lNumFolioAnterior = pstFaCuotas->stReg_pven[k].lNum_Folio;
                }
            }
        }
    }

if ( stStatus.LogNivel >= LOG06 )
	{
	    vDTrazasLog(szModulo,"\t----------Cuotas Vencidas -------------------",LOG06);
	    for(i=0;i< pstFaCuotas->iNum_RegCuotas_venci;i++)
	    {
	        vDTrazasLog(szModulo,"\t [%d] Cliente      [%d] ",LOG06,i,pstFaCuotas->stReg_venci[i].iCodCliente    );
	        vDTrazasLog(szModulo,"\t      Concepto     [%d] ",LOG06,pstFaCuotas->stReg_venci[i].iCod_Concepto  );
	        vDTrazasLog(szModulo,"\t      Nó Cuotas    [%d] ",LOG06,pstFaCuotas->stReg_venci[i].iNumCuota      );
	        vDTrazasLog(szModulo,"\t      Sec Cuotas   [%d] ",LOG06,pstFaCuotas->stReg_venci[i].iSecCuota      );
	        vDTrazasLog(szModulo,"\t      Monto        [%f] ",LOG06,pstFaCuotas->stReg_venci[i].dMtoCuota      );
	        vDTrazasLog(szModulo,"\t      Folio        [%ld]",LOG06,pstFaCuotas->stReg_venci[i].lNum_Folio     );
	        vDTrazasLog(szModulo,"\t      Ind Factura  [%d] ",LOG06,pstFaCuotas->stReg_venci[i].iInd_Facturado );
	        vDTrazasLog(szModulo,"\t      Folio CTC    [%s] ",LOG06,pstFaCuotas->stReg_venci[i].szNum_FolioCtc );
	        vDTrazasLog(szModulo,"\t      Fec Efectiva [%s] ",LOG06,pstFaCuotas->stReg_venci[i].szFechaEfectiva);
	        vDTrazasLog(szModulo,"\t      Fec Eemision [%s] ",LOG06,pstFaCuotas->stReg_venci[i].szFec_Emision  );
	        vDTrazasLog(szModulo,"\t      Tipo Doc     [%d] ",LOG06,pstFaCuotas->stReg_venci[i].iCod_TipDocum  );
	        vDTrazasLog(szModulo,"\t      Descipcion   [%s] ",LOG06,pstFaCuotas->stReg_venci[i].szDes_Cuota    );
	        vDTrazasLog(szModulo,"\t      Pref Plaza   [%s] ",LOG06,pstFaCuotas->stReg_venci[i].szPrefPlaza    );
	        vDTrazasLog(szModulo,"\t      Abonado      [%ld]",LOG06,pstFaCuotas->stReg_venci[i].lNumAbonado    );

	        
	        vDTrazasLog(szModulo,"\t l_Num_Secuenci      [%ld]",LOG06,pstFaCuotas->stReg_venci[i].l_Num_Secuenci    );
	        vDTrazasLog(szModulo,"\t l_Cod_Vendedor_Ag      [%ld]",LOG06,pstFaCuotas->stReg_venci[i].l_Cod_Vendedor_Ag    );
	        vDTrazasLog(szModulo,"\t sz_Letra [%s] ",LOG06,pstFaCuotas->stReg_venci[i].sz_Letra);
	        vDTrazasLog(szModulo,"\t l_Cod_Centremi      [%ld]",LOG06,pstFaCuotas->stReg_venci[i].l_Cod_Centremi    );
	        vDTrazasLog(szModulo,"\t l_Columna      [%ld]",LOG06,pstFaCuotas->stReg_venci[i].l_Columna    );

	        vDTrazasLog(szModulo,"\t sz_IndAcelerada [%s] ",LOG06,pstFaCuotas->stReg_venci[i].sz_IndAcelerada); /* P-ECU-12019 */
	        
	    }
	    vDTrazasLog(szModulo,"\t----------Cuotas Por Vencer------------------",LOG06);
	    for(i=0;i< pstFaCuotas->iNum_RegCuotas_pven;i++)
	    {
	        vDTrazasLog(szModulo,"\t [%d]Cliente   [%d] ",LOG06,i,pstFaCuotas->stReg_pven[i].iCodCliente    );
	        vDTrazasLog(szModulo,"\t Concepto     [%d] ",LOG06,pstFaCuotas->stReg_pven[i].iCod_Concepto  );
	        vDTrazasLog(szModulo,"\t Nó Cuotas    [%d] ",LOG06,pstFaCuotas->stReg_pven[i].iNumCuota      );
	        vDTrazasLog(szModulo,"\t Sec Cuotas   [%d] ",LOG06,pstFaCuotas->stReg_pven[i].iSecCuota      );
	        vDTrazasLog(szModulo,"\t Monto        [%f] ",LOG06,pstFaCuotas->stReg_pven[i].dMtoCuota      );
	        vDTrazasLog(szModulo,"\t Folio        [%ld]",LOG06,pstFaCuotas->stReg_pven[i].lNum_Folio     );
	        vDTrazasLog(szModulo,"\t Ind Factura  [%d] ",LOG06,pstFaCuotas->stReg_pven[i].iInd_Facturado );
	        vDTrazasLog(szModulo,"\t Folio CTC    [%s] ",LOG06,pstFaCuotas->stReg_pven[i].szNum_FolioCtc );
	        vDTrazasLog(szModulo,"\t Fec Efectiva [%s] ",LOG06,pstFaCuotas->stReg_pven[i].szFechaEfectiva);
	        vDTrazasLog(szModulo,"\t Fec Eemision [%s] ",LOG06,pstFaCuotas->stReg_pven[i].szFec_Emision  );
	        vDTrazasLog(szModulo,"\t Tipo Doc     [%d] ",LOG06,pstFaCuotas->stReg_pven[i].iCod_TipDocum  );
	        vDTrazasLog(szModulo,"\t Descipcion   [%s] ",LOG06,pstFaCuotas->stReg_pven[i].szDes_Cuota    );
	        vDTrazasLog(szModulo,"\t Pref Plaza   [%s] ",LOG06,pstFaCuotas->stReg_pven[i].szPrefPlaza    );
	        vDTrazasLog(szModulo,"\t Abonado      [%ld]",LOG06,pstFaCuotas->stReg_pven[i].lNumAbonado    );
	        
	        vDTrazasLog(szModulo,"\t l_Num_Secuenci      [%ld]",LOG06,pstFaCuotas->stReg_pven[i].l_Num_Secuenci    );
	        vDTrazasLog(szModulo,"\t l_Cod_Vendedor_Ag      [%ld]",LOG06,pstFaCuotas->stReg_pven[i].l_Cod_Vendedor_Ag    );
	        vDTrazasLog(szModulo,"\t sz_Letra [%s] ",LOG06,pstFaCuotas->stReg_pven[i].sz_Letra);
	        vDTrazasLog(szModulo,"\t l_Cod_Centremi      [%ld]",LOG06,pstFaCuotas->stReg_pven[i].l_Cod_Centremi    );
	        vDTrazasLog(szModulo,"\t l_Columna      [%ld]",LOG06,pstFaCuotas->stReg_pven[i].l_Columna    );

          vDTrazasLog(szModulo,"\t sz_IndAcelerada [%s] ",LOG06,pstFaCuotas->stReg_pven[i].sz_IndAcelerada ); /* P-ECU-12019 */
	        
	    }
	    vDTrazasLog(szModulo,"\t---------------------------------------------",LOG06);
	}	



    vDTrazasLog(szModulo,"\t\t Fin GetCuotas \n", LOG05);

    return(TRUE);
}

/*****************************************************************************/
/*  Funcion para cargar codigo de servicio del cliente                       */
/*****************************************************************************/
int CargaCodigoServicio(ST_FACTCLIE *pstFactDocuClie,
                        ST_INFGENERAL * pstInfGeneral,
                        char * pstCodServicio)
{
    vDTrazasLog("CargaCodigoServicio","\t\tInicio Codigo Carga Servicio [%s]", LOG04,pstFactDocuClie->szFecEmision);

    strcpy(szhFormato_Fecha,"YYYYMMDD");

    /* EXEC SQL
    SELECT NVL(COD_SERVICIO,'1')
    INTO   :pstInfGeneral->szCOD_SERVICIO
    FROM   FAD_IMPSERVCLIE
    WHERE  COD_CLIENTE   = :pstFactDocuClie->lCodCliente
    AND    TO_DATE(:pstFactDocuClie->szFecEmision,:szhFormato_Fecha) BETWEEN FECHA_DESDE AND FECHA_HASTA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(COD_SERVICIO,'1') into :b0  from FAD_IMPSERVCL\
IE where (COD_CLIENTE=:b1 and TO_DATE(:b2,:b3) between FECHA_DESDE and FECHA_H\
ASTA)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1073;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstInfGeneral->szCOD_SERVICIO);
    sqlstm.sqhstl[0] = (unsigned long )4;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(pstFactDocuClie->lCodCliente);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstFactDocuClie->szFecEmision);
    sqlstm.sqhstl[2] = (unsigned long )12;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhFormato_Fecha;
    sqlstm.sqhstl[3] = (unsigned long )9;
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



    if(sqlca.sqlcode == SQLNOTFOUND)
    {
      sprintf(pstInfGeneral->szCOD_SERVICIO,"%3s",pstCodServicio);
      vDTrazasLog("CargaCodigoServicio","\t\tNo Existe Codigo de Servicio. Se Asumira el Codigo por Defecto [%s]." ,LOG04,pstInfGeneral->szCOD_SERVICIO);
      return(TRUE);
    }
    if(sqlca.sqlcode < SQLOK)
    {
      vDTrazasLog("CargaCodigoServicio","\t\tError en Carga de Codigo de Servicio.",LOG04);
      return(FALSE);
    }
    return(TRUE);
}


/* Inicio P-ECU-12024*/
int iCargaServSuplan ( long lIndOrdenTotal, long lCodCiclFact, long lCod_cliente)
{
    char  szTablaConc [50]    ="";
    char  szTablaFact [50]    ="";
		long  lRowsThisLoop = 0, lRowsProcessed = 0, lTotalRows=0;
		int   iRetSQLCODE = 0;
		int    i, x=0;    
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

         long lhIndOrdenTotal;
         char szhFec_desde[20];
         char szhFec_hasta [20];
         char szhFec_emision[20];
         char szhFec_limite [20];
         long lhCod_cliente;
         long lhCodCiclFact;
         int  ihCod_ciclo;
         char szCadenaSQL [82000];         
         long  lNum_Abonado   [NUMHOST]   ;
				 int   iTip_serv      [NUMHOST]   ;
				 char  szCod_categoria[NUMHOST][2];
				 int   iCod_concepto  [NUMHOST]   ;
				 char  szDes_concepto [NUMHOST][61]; /* EXEC SQL VAR szDes_concepto IS STRING(61); */ 

				 char  szFec_altacen  [NUMHOST][9];
				 char  szFec_bajabd   [NUMHOST][9];

    /* EXEC SQL END DECLARE SECTION; */ 

   
    
    
    vDTrazasLog(szModulo,"\t** EN FUNCION ...(%s)", LOG06,szModulo);
    

    lhIndOrdenTotal = lIndOrdenTotal;
    lhCodCiclFact=lCodCiclFact;
    lhCod_cliente=lCod_cliente;

    strcpy (szModulo, "iCargaServSuplan");
    vDTrazasLog(szModulo,"\t** EN FUNCION ...(%s)", LOG06,szModulo);
    iContRegSS=0;
   
    

		/* EXEC SQL               
		SELECT TO_CHAR(FEC_EMISION,'DD-MM-YYYY HH24:MI:SS'),
		       TO_CHAR(FEC_DESDECFIJOS,'DD-MM-YYYY HH24:MI:SS'),
		       TO_CHAR(FEC_HASTACFIJOS,'DD-MM-YYYY HH24:MI:SS'),
		       '31-12-3000 23:59:59',
		       COD_CICLO
		INTO   :szhFec_emision,
			     :szhFec_desde,
			     :szhFec_hasta,
			     :szhFec_limite,
			     :ihCod_ciclo
		FROM FA_CICLFACT
		WHERE COD_CICLFACT = :lhCodCiclFact; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 46;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select TO_CHAR(FEC_EMISION,'DD-MM-YYYY HH24:MI:SS') ,TO_CHA\
R(FEC_DESDECFIJOS,'DD-MM-YYYY HH24:MI:SS') ,TO_CHAR(FEC_HASTACFIJOS,'DD-MM-YYY\
Y HH24:MI:SS') ,'31-12-3000 23:59:59' ,COD_CICLO into :b0,:b1,:b2,:b3,:b4  fro\
m FA_CICLFACT where COD_CICLFACT=:b5";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1104;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhFec_emision;
  sqlstm.sqhstl[0] = (unsigned long )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhFec_desde;
  sqlstm.sqhstl[1] = (unsigned long )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhFec_hasta;
  sqlstm.sqhstl[2] = (unsigned long )20;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)szhFec_limite;
  sqlstm.sqhstl[3] = (unsigned long )20;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&ihCod_ciclo;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&lhCodCiclFact;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
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

   
    
    if(SQLCODE == SQLNOTFOUND)    {
      vDTrazasLog  (szModulo,"\tNo Existen Datos en FA_CICLFACT **"
                             "\tPara el Cod_CiclFact     [%ld]",LOG04,lhCodCiclFact);
      vDTrazasError(szModulo,"\tNo Existen Datos en FA_CICLFACT  **"
                             "\tPara el Cod_CiclFact     [%ld]",LOG04,lhCodCiclFact);
      return(FALSE);
    }
    if(SQLCODE != SQLOK)    {
      vDTrazasLog  (szModulo,"\tError en select a FA_CICLFACT **",LOG01);
      vDTrazasError(szModulo,"\tError en select a FA_CICLFACT  **",LOG01);
      return(FALSE);
    }    
    
 
    
    if(!lNroJob)
    {
        sprintf(szTablaFact,"FA_FACTABON_%ld",lhCodCiclFact);
        sprintf(szTablaConc,"FA_FACTCONC_%ld",lhCodCiclFact);
    }
    else
    {
        sprintf(szTablaFact,"FA_FACTABON_%ld_%ld",lhCodCiclFact,lNroJob);
        sprintf(szTablaConc,"FA_FACTCONC_%ld_%ld",lhCodCiclFact,lNroJob);

    }    
    
    vDTrazasLog(szModulo,"\t******* Abriendo Servicios Suplementarios...(%ld) (%ld) *******", LOG06,lIndOrdenTotal,lCodCiclFact);

    vDTrazasLog  (szModulo,"\t szTablaConc      [%s]",LOG05,szTablaConc);
    vDTrazasLog  (szModulo,"\t lhIndOrdenTotal  [%ld]",LOG05,lhIndOrdenTotal);
    vDTrazasLog  (szModulo,"\t szhFec_hasta     [%s]",LOG05,szhFec_hasta);
    vDTrazasLog  (szModulo,"\t szhFec_limite    [%s]",LOG05,szhFec_limite);
    vDTrazasLog  (szModulo,"\t szhFec_desde     [%s]",LOG05,szhFec_desde);
    vDTrazasLog  (szModulo,"\t szhFec_emision   [%s]",LOG05,szhFec_emision);
    vDTrazasLog  (szModulo,"\t iCodAbonoCel     [%d]",LOG05,iCodAbonoCel);
    vDTrazasLog  (szModulo,"\t ihCod_ciclo      [%d]",LOG05,ihCod_ciclo);

    memset(szCadenaSQL,'\0',sizeof(szCadenaSQL));
    sprintf(szCadenaSQL,
            "\n SELECT DISTINCT B.NUM_ABONADO,"
            "\n DECODE(c.COD_SUBGRUPO,45,1,0) as TIP_SERV,"
            "\n 'S' AS CATEGORIA,"
            "\n A.COD_CONCEPTO,"
            "\n B.DES_CONCEPTO,"
            "\n NVL(TO_CHAR (A.FEC_ALTACEN, 'yyyymmdd'),' '),"
            "\n NVL(TO_CHAR (A.FEC_BAJABD,'yyyymmdd' ),' ')"
            "\n FROM  %s B, GA_SERVSUPLABO A, FAD_IMPCONCEPTOS C, GA_ACTUASERV D"
            "\n WHERE B.IND_ORDENTOTAL = %ld"
            "\n AND B.NUM_ABONADO = a.NUM_ABONADO" 
            "\n AND B.COD_CONCEPTO = A.COD_CONCEPTO "
            "\n AND B.COD_CONCEPTO = C.COD_CONCEPTO"
            "\n AND B.COD_CONCEPTO = D.COD_CONCEPTO"
            "\n AND A.FEC_ALTACEN   IS NOT NULL"
            "\n AND A.COD_PRODUCTO  = 1"
            "\n AND A.COD_PRODUCTO = D.COD_PRODUCTO"
            "\n AND A.COD_SERVICIO = D.COD_SERVICIO"
            "\n AND D.COD_ACTABO in ('FA','SS')"
            "\n AND A.FEC_ALTACEN  <= TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')"
            "\n AND NVL(A.FEC_BAJABD, TO_DATE('%s', 'dd-mm-yyyy hh24:mi:ss')) >= TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')  "
            "\n AND A.FEC_ALTACEN  <=  TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')"
            "\n UNION "
            "\n SELECT B.NUM_ABONADO,"
            "\n DECODE(c.COD_SUBGRUPO,45,1,0) as TIP_SERV,"
            "\n 'P' AS CATEGORIA,"
            "\n B.COD_CONCEPTO,"
            "\n B.DES_CONCEPTO,"
            "\n NVL(TO_CHAR (A.FEC_DESDE, 'yyyymmdd'),' '),"
            "\n DECODE(TO_CHAR(A.FEC_HASTA, 'yyyymmdd' ),'30001231',' ', NVL(TO_CHAR(A.FEC_HASTA,'yyyymmdd' ),' ')) "
            "\n FROM  %s B, GA_INTARCEL A, FAD_IMPCONCEPTOS C, %s D"
            "\n WHERE B.IND_ORDENTOTAL = %ld"
            "\n AND B.NUM_ABONADO = A.NUM_ABONADO"
            "\n AND B.IND_ORDENTOTAL = D.IND_ORDENTOTAL"
            "\n AND D.COD_CLIENTE = A.COD_CLIENTE"
            "\n AND B.COD_CONCEPTO = %d "
            "\n AND B.COD_CONCEPTO = C.COD_CONCEPTO"
            "\n AND B.COD_PLANTARIF = A.COD_PLANTARIF"
            "\n AND B.COD_CARGOBASICO = A.COD_CARGOBASICO"
            "\n AND A.IND_NUMERO  = 0 "
            "\n AND A.COD_CICLO     = %d "
            "\n AND A.FEC_DESDE  <  TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')"
            "\n AND A.FEC_HASTA  >= TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')"
            "\n AND A.FEC_DESDE  <= TO_DATE('%s','dd-mm-yyyy hh24:mi:ss')"
            "\n ORDER BY 1,2,3,5,6 desc ", szTablaConc,lhIndOrdenTotal,szhFec_hasta,szhFec_limite,szhFec_desde,szhFec_emision,szTablaConc,szTablaFact, lhIndOrdenTotal,iCodAbonoCel, ihCod_ciclo, szhFec_hasta,szhFec_desde,szhFec_emision);

    vDTrazasLog  (szModulo,"\t strlen(szCadenaSQL)      [%d]",LOG05,strlen(szCadenaSQL));

    vDTrazasLog(szModulo,"QRY iCargaServSuplan : [%s]\n",LOG05,szCadenaSQL);

    /* EXEC SQL PREPARE sql_ServSupl FROM :szCadenaSQL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1143;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
    sqlstm.sqhstl[0] = (unsigned long )82000;
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
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_ServSupl **"
                                        "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }
    vDTrazasLog(szModulo,"Fin PREPARE sql_ServSupl\n",LOG06);

    /* EXEC SQL DECLARE curServSupl CURSOR FOR sql_ServSupl; */ 

    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE curServSupl **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE curServSupl **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }
    vDTrazasLog(szModulo,"Fin DECLARE curServSupl\n",LOG06);

    vDTrazasLog  ("ImpSclB:iCargaServSuplan", "\t\t ****** OPEN curServSupl using [%s] [%d]**", LOG05, szTablaConc, lhIndOrdenTotal);
    
    /* EXEC SQL OPEN curServSupl; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1162;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curServSupl **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curServSupl **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);  
        return  (SQLCODE);                                           
    }
    vDTrazasLog(szModulo,"Fin OPEN curServSupl\n",LOG06);
    
    
		lRowsProcessed=0;
		
		while( 1 ) 
		{
			vDTrazasLog( szModulo, "Ingresando al FETCH\n", LOG06 );
			/* EXEC SQL FETCH curServSupl
			INTO :lNum_Abonado   ,
					 :iTip_serv      ,
					 :szCod_categoria,
					 :iCod_concepto  ,
					 :szDes_concepto ,
					 :szFec_altacen  ,
					 :szFec_bajabd   ; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 46;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )30000;
   sqlstm.offset = (unsigned int  )1177;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)lNum_Abonado;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[0] = (         int  )sizeof(long);
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqharc[0] = (unsigned long  *)0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)iTip_serv;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )sizeof(int);
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqharc[1] = (unsigned long  *)0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)szCod_categoria;
   sqlstm.sqhstl[2] = (unsigned long )2;
   sqlstm.sqhsts[2] = (         int  )2;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqharc[2] = (unsigned long  *)0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)iCod_concepto;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )sizeof(int);
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqharc[3] = (unsigned long  *)0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)szDes_concepto;
   sqlstm.sqhstl[4] = (unsigned long )61;
   sqlstm.sqhsts[4] = (         int  )61;
   sqlstm.sqindv[4] = (         short *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqharc[4] = (unsigned long  *)0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)szFec_altacen;
   sqlstm.sqhstl[5] = (unsigned long )9;
   sqlstm.sqhsts[5] = (         int  )9;
   sqlstm.sqindv[5] = (         short *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqharc[5] = (unsigned long  *)0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)szFec_bajabd;
   sqlstm.sqhstl[6] = (unsigned long )9;
   sqlstm.sqhsts[6] = (         int  )9;
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



			
			if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND ) {
				vDTrazasLog( szModulo, "\tEn FETCH curServSupl\n\t %s", LOG01, SQLERRM );
				break;
			}
			
			lTotalRows = SQLROWS;    
			iRetSQLCODE = SQLCODE;
			lRowsThisLoop = ( lTotalRows - lRowsProcessed );   
			vDTrazasLog( szModulo, "\tlTotalRows = [%ld], lRowsThisLoop = [%ld]\n\t", LOG03, lTotalRows, lRowsThisLoop );
			
			for( i = 0; i < lRowsThisLoop; i++ ) {
				
					servsuplan.lNum_Abonado[x]  = lNum_Abonado   [i];
					servsuplan.iTip_serv[x]     = iTip_serv      [i];
					servsuplan.iCod_concepto[x] = iCod_concepto  [i];
					strcpy(servsuplan.szCod_categoria[x],szCod_categoria[i]);
					strcpy(servsuplan.szDes_concepto[x],szDes_concepto [i]);
					strcpy(servsuplan.szFec_altacen[x],szFec_altacen  [i]);
					strcpy(servsuplan.szFec_bajabd[x],szFec_bajabd   [i]);
				  vDTrazasLog( szModulo, "\t lNum_Abonado   [%ld]", LOG06, servsuplan.lNum_Abonado[x] );
				  vDTrazasLog( szModulo, "\t iTip_serv      [%d]", LOG06, servsuplan.iTip_serv[x] );
				  vDTrazasLog( szModulo, "\t iCod_concepto  [%d]", LOG06, servsuplan.iCod_concepto[x] );
				  vDTrazasLog( szModulo, "\t szCod_categoria[%s]", LOG06, servsuplan.szCod_categoria[x] );
				  vDTrazasLog( szModulo, "\t szDes_concepto [%s]", LOG06, servsuplan.szDes_concepto[x] );
				  vDTrazasLog( szModulo, "\t szFec_altacen  [%s]", LOG06, servsuplan.szFec_altacen[x] );
				  vDTrazasLog( szModulo, "\t szFec_bajabd   [%s]\n", LOG06, servsuplan.szFec_bajabd[x] );
				  x++;
				  iContRegSS++;
			}
			
			lRowsProcessed = lTotalRows; 
			if( iRetSQLCODE == SQLNOTFOUND )  {
				vDTrazasLog( szModulo, "\tFin de Datos curServSupl.\n", LOG03 );
				break;
			}
		}     
    vDTrazasLog(szModulo,"iContRegSS [%d]",LOG06,iContRegSS);
    vDTrazasLog(szModulo,"Fin FETCH curServSupl\n",LOG06);

    /* EXEC SQL CLOSE curServSupl; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 46;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1220;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(SQLCODE != SQLOK) {
        vDTrazasError(szModulo,"\t\tError al cerrar el Cursor curServSupl: %s",LOG01, SQLERRM);
        return(FALSE);
    }
    
    return 0;
}/************************ Final de iCargaServSuplan ***********************/
/* Fin P-ECU-12024*/



