
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
           char  filnam[18];
};
static const struct sqlcxp sqlfpn =
{
    17,
    "./pc/ImpSclFnc.pc"
};


static unsigned int sqlctx = 6915283;


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
   unsigned char  *sqhstv[47];
   unsigned long  sqhstl[47];
            int   sqhsts[47];
            short *sqindv[47];
            int   sqinds[47];
   unsigned long  sqharm[47];
   unsigned long  *sqharc[47];
   unsigned short  sqadto[47];
   unsigned short  sqtdso[47];
} sqlstm = {12,47};

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
"select DESC_MENSLIN  from FA_MENSPROCESO A ,FA_MENSAJES B where (A.NUM_PROCE\
SO=:b0 and A.CORR_MENSAJE=B.CORR_MENSAJE) order by A.CORR_MENSAJE,B.NUM_LINEA \
           ";

 static const char *sq0002 = 
"select COD_CLIENTE ,COD_ABONADO ,COD_BOLSA ,VAL_BOLSA ,IND_UNIDAD ,VAL_ARRAS\
TRE ,VAL_EXPIRADO ,VAL_DISPONIBLE ,VAL_CONSUMO ,VAL_RESTO ,(SUBSTR(TO_CHAR(COD\
_CLIENTE,:b0),2)||SUBSTR(TO_CHAR(COD_ABONADO,:b0),2))  from TOL_HDARRASTRE_TH \
where COD_CICLFACT=:b2 order by COD_CLIENTE,COD_ABONADO            ";

 static const char *sq0045 = 
"select A.COD_PLAN ,A.COD_AGRULLAM ,NVL(A.MTO_MIN,0)  from TOL_ESTCOBRO A ,FA\
_CICLFACT B ,FA_AGRULLAM_B4001_VW C where (((((((((B.COD_CICLFACT=:b0 and A.CO\
D_OPERADOR>:b1) and A.COD_PLAN>:b1) and A.COD_TDIA=:b3) and B.FEC_DESDELLAM be\
tween A.FEC_INI_VIG and A.FEC_TER_VIG) and B.FEC_HASTALLAM between A.FEC_INI_V\
IG and A.FEC_TER_VIG) and A.COD_SFRAN=:b4) and C.COD_DOMINIO=:b5) and C.IND_ES\
TADO=:b6) and A.COD_AGRULLAM=C.DESCRIPCION_VALOR) order by A.COD_PLAN,A.COD_AG\
RULLAM            ";

 static const char *sq0046 = 
"select A.COD_PLANTARIF ,A.DES_PLANTARIF ,A.TIP_PLANTARIF ,A.NUM_UNIDADES ,B.\
IMP_CARGOBASICO ,A.IND_ARRASTRE  from TA_PLANTARIF A ,TA_CARGOSBASICO B where \
((A.COD_PRODUCTO=:b0 and A.COD_CARGOBASICO=B.COD_CARGOBASICO) and A.COD_PRODUC\
TO=B.COD_PRODUCTO)           ";

 static const char *sq0049 = 
"select TO_NUMBER(VALOR) ,DESCRIPCION_VALOR  from FA_AGRULLAM_B4001_VW where \
(COD_DOMINIO=:b0 and IND_ESTADO=:b1) order by TO_NUMBER(VALOR) asc            \
 ";

 static const char *sq0050 = 
"select POSICION ,COD_REGISTRO ,TIP_REGISTRO ,VALOR ,TIP_TRAF  from FA_REGDET\
LLAM_TD  order by POSICION asc             ";

 static const char *sq0052 = 
"select (substr(TO_CHAR(TO_NUMBER(substr(C.COD_CONCEPTO,1,4)),'0009'),2)||C.C\
OD_IDIOMA) CONCEPTO ,substr(B.DES_CONCEPTO,1,50) ,substr(C.DES_CONCEPTO,1,50) \
 from FAD_IMPSUBGRUPOS A ,GE_MULTIIDIOMA B ,GE_MULTIIDIOMA C where ((((((TO_CH\
AR(A.COD_GRUPO)=B.COD_CONCEPTO and B.NOM_TABLA='FAD_IMPGRUPOS') and B.NOM_CAMP\
O='COD_GRUPOS') and TO_CHAR(A.COD_SUBGRUPO)=C.COD_CONCEPTO) and C.NOM_TABLA='F\
AD_IMPSUBGRUPOS') and C.NOM_CAMPO='COD_SUBGRUPO') and B.COD_IDIOMA=C.COD_IDIOM\
A) order by CONCEPTO            ";

 static const char *sq0053 = 
"select C.NUM_ORDEN GRP ,B.NUM_ORDEN SGRP ,A.NUM_ORDEN CONC ,C.COD_GRUPO ,B.C\
OD_SUBGRUPO ,A.COD_CONCEPTO ,NVL(B.COD_REGISTRO,'D3001') ,NVL(B.CRIT_ORDEN,:b0\
) ,NVL(B.COD_TIPLLAMADA,:b0) ,B.COD_TIPSUBGRUPO  from FAD_IMPCONCEPTOS A ,FAD_\
IMPSUBGRUPOS B ,FAD_IMPGRUPOS C where (((A.COD_CONCEPTO>:b0 and A.COD_SUBGRUPO\
=B.COD_SUBGRUPO) and B.COD_GRUPO=C.COD_GRUPO) and C.COD_FORMULARIO=:b3) order \
by A.COD_CONCEPTO            ";

 static const char *sq0055 = 
"select val_numerico  from FAD_PARAMETROS where COD_PARAMETRO=:b0           ";

 static const char *sq0057 = 
"select distinct A.COD_CONCGENE ,B.COD_CATEIMP ,A.PRC_IMPUESTO ,A.COD_TIPIMPU\
ES  from GE_IMPUESTOS A ,GE_TIPIMPUES B where ((((A.COD_CATIMPOS>=:b0 and A.CO\
D_ZONAIMPO>=:b0) and A.COD_ZONAABON>=:b0) and A.COD_TIPIMPUES=B.COD_TIPIMPUE) \
and A.COD_GRPSERVI>=:b0) order by A.COD_CONCGENE asc             ";

 static const char *sq0059 = 
"select B.COD_PLAN ,A.COD_THOR ,B.SEG_INIC ,B.SEG_ADIC ,B.MTO_MIN ,B.MTO_ADIC\
  from TOL_AGRULLAM A ,TOL_ESTCOBRO B where (((((((((((((A.COD_SENTIDO='S' and\
 A.COD_LLAM=:b0) and A.COD_TDIR=:b1) and A.COD_THOR in (:b2,:b3,:b4)) and A.CO\
N_CLIENTE=:b5) and A.FEC_INI_VIG<=SYSDATE) and A.FEC_TER_VIG>=SYSDATE) and B.C\
OD_OPERADOR=:b6) and B.COD_PLAN<>' ') and B.COD_AGRULLAM=A.COD_AGRULLAM) and B\
.COD_TDIA=:b7) and B.COD_SFRAN=:b8) and B.FEC_INI_VIG<=SYSDATE) and B.FEC_TER_\
VIG>=SYSDATE)           ";

 static const char *sq0061 = 
"select COD_OPERADOR ,DES_OPERADOR  from TA_OPERADORES where COD_OPERADOR>=:b\
0           ";

 static const char *sq0003 = 
"select A.COD_OPERADORA ,A.COD_OFICINA ,A.COD_TIPDOCUM ,B.DES_TIPDOCUM ,A.PRE\
F_PLAZA ,A.NUM_FOLIO ,TO_CHAR(A.FEC_EMISION,:b0) ,A.TOT_FACTURA  from FA_HISTD\
OCU A ,GE_TIPDOCUMEN B where (((A.COD_TIPDOCUM=B.COD_TIPDOCUM and A.COD_CLIENT\
E=:b1) and A.FEC_EMISION>=TO_DATE(:b2,:b0)) and A.FEC_EMISION<=TO_DATE(:b4,:b0\
))           ";

 static const char *sq0064 = 
"select A.NUM_SERIE ,A.NUM_ABONADO ,A.COD_CONCEPTO ,B.DES_CONCEPTO  from GE_C\
ARGOS A ,FA_CONCEPTOS B where (((A.NUM_VENTA=:b0 and A.COD_CLIENTE=:b1) and A.\
COD_CONCEPTO=B.COD_CONCEPTO) and A.NUM_SERIE is  not null )           ";

 static const char *sq0065 = 
"select A.NUM_SERIE ,A.NUM_ABONADO ,A.COD_CONCEPTO ,B.DES_CONCEPTO  from FA_H\
ISTCARGOS A ,FA_CONCEPTOS B where (((A.NUM_VENTA=:b0 and A.COD_CLIENTE=:b1) an\
d A.COD_CONCEPTO=B.COD_CONCEPTO) and A.NUM_SERIE is  not null )           ";

 static const char *sq0069 = 
"select A.NUM_KIT ,D.NUM_ABONADO ,B.COD_CONCEPTO ,B.DES_CONCEPTO ,NVL(A.NUM_T\
ELEFONO,0)  from AL_COMPONENTE_KIT A ,FA_CONCEPTOS B ,AL_ARTICULOS C ,GA_EQUIP\
ABOSER D where (((((C.COD_ARTICULO=A.COD_KIT and A.NUM_SERIE=D.NUM_SERIE) and \
D.TIP_TERMINAL in (select E.VAL_PARAMETRO  from GED_PARAMETROS E where E.NOM_P\
ARAMETRO in ('TIP_DIGITAL','COD_SIMCARD_GSM'))) and D.NUM_ABONADO in (select F\
.NUM_ABONADO  from GA_ABOAMIST F where ((F.NUM_VENTA=:b0 and F.COD_CLIENTE=:b1\
) and TRUNC(F.FEC_ALTA) in (select TRUNC(G.FEC_VENTA)  from GA_VENTAS G where \
(G.NUM_VENTA=:b0 and G.COD_CLIENTE=:b1))))) and C.COD_CONCEPTOART=B.COD_CONCEP\
TO) and D.IND_PROCEQUI=:b4)           ";

 static const char *sq0070 = 
"select A.NUM_SERIE ,A.NUM_ABONADO ,B.COD_CONCEPTO ,B.DES_CONCEPTO ,D.NUM_CEL\
ULAR  from GA_EQUIPABOSER A ,FA_CONCEPTOS B ,AL_ARTICULOS C ,GA_ABOAMIST D whe\
re ((((A.NUM_ABONADO in (select D.NUM_ABONADO  from GA_ABOAMIST D where ((D.NU\
M_VENTA=:b0 and D.COD_CLIENTE=:b1) and TRUNC(D.FEC_ALTA) in (select TRUNC(E.FE\
C_VENTA)  from GA_VENTAS E where (E.NUM_VENTA=:b0 and E.COD_CLIENTE=:b1)))) an\
d C.COD_ARTICULO=A.COD_ARTICULO) and C.COD_CONCEPTOART=B.COD_CONCEPTO) and A.N\
UM_ABONADO=D.NUM_ABONADO) and A.IND_PROCEQUI=:b4) group by A.NUM_SERIE,A.NUM_A\
BONADO,B.COD_CONCEPTO,B.DES_CONCEPTO,D.NUM_CELULAR           ";

 static const char *sq0071 = 
"select A.NUM_SERIE ,A.NUM_ABONADO ,B.COD_CONCEPTO ,B.DES_CONCEPTO ,D.NUM_CEL\
ULAR  from GA_EQUIPABOSER A ,FA_CONCEPTOS B ,AL_ARTICULOS C ,GA_ABOCEL D where\
 ((((A.NUM_ABONADO in (select D.NUM_ABONADO  from GA_ABOCEL D where ((D.NUM_VE\
NTA=:b0 and D.COD_CLIENTE=:b1) and TRUNC(D.FEC_ALTA) in (select TRUNC(E.FEC_VE\
NTA)  from GA_VENTAS E where (E.NUM_VENTA=:b0 and E.COD_CLIENTE=:b1)))) and C.\
COD_ARTICULO=A.COD_ARTICULO) and C.COD_CONCEPTOART=B.COD_CONCEPTO) and A.NUM_A\
BONADO=D.NUM_ABONADO) and A.IND_PROCEQUI=:b4) group by A.NUM_SERIE,A.NUM_ABONA\
DO,B.COD_CONCEPTO,B.DES_CONCEPTO,D.NUM_CELULAR           ";

 static const char *sq0072 = 
"select A.NUM_SERIE ,A.NUM_ABONADO ,A.COD_CONCEPTO ,B.DES_CONCEPTO ,D.NUM_CEL\
ULAR  from FA_HISTCARGOS A ,FA_CONCEPTOS B ,GA_ABOCEL D where ((((A.NUM_VENTA=\
:b0 and A.COD_CLIENTE=:b1) and A.COD_CONCEPTO=B.COD_CONCEPTO) and A.NUM_ABONAD\
O=D.NUM_ABONADO) and A.NUM_SERIE is  not null )           ";

 static const char *sq0073 = 
"select A.NUM_SERIE ,A.NUM_PROCESO ,A.COD_CONCEPTO ,A.COLUMNA  from FA_SERIES\
_TO A where ((A.NUM_PROCESO=:b0 and A.COD_CONCEPTO=:b1) and A.COLUMNA=:b2)    \
       ";

 static const char *sq0004 = 
"select COD_REGISTRO ,COD_TIPDOCUM  from FA_REGISIMPRESION_TD where (COD_TIPD\
OCUM=:b0 and IND_IMPRESION=1) order by COD_REGISTRO            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,2,0,0,
5,0,0,5,107,0,6,151,0,0,3,3,0,1,0,1,3,0,0,2,97,0,0,2,97,0,0,
32,0,0,6,324,0,3,545,0,0,17,17,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,
115,0,0,7,0,0,29,587,0,0,0,0,0,1,0,
130,0,0,8,96,0,2,603,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,
157,0,0,9,0,0,29,615,0,0,0,0,0,1,0,
172,0,0,10,130,0,4,639,0,0,4,3,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
203,0,0,11,171,0,5,686,0,0,6,6,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
242,0,0,12,0,0,29,713,0,0,0,0,0,1,0,
257,0,0,13,171,0,4,765,0,0,7,6,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,
300,0,0,14,122,0,4,787,0,0,5,4,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
335,0,0,15,201,0,3,813,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,
374,0,0,16,164,0,3,825,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
405,0,0,17,0,0,29,837,0,0,0,0,0,1,0,
420,0,0,18,201,0,3,858,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,
459,0,0,19,0,0,29,874,0,0,0,0,0,1,0,
474,0,0,20,139,0,5,891,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
505,0,0,21,0,0,29,905,0,0,0,0,0,1,0,
520,0,0,22,184,0,5,951,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,
563,0,0,23,0,0,29,969,0,0,0,0,0,1,0,
578,0,0,24,107,0,4,1007,0,0,4,3,0,1,0,2,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
609,0,0,25,122,0,5,1052,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
640,0,0,26,0,0,29,1066,0,0,0,0,0,1,0,
655,0,0,27,78,0,5,1086,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
682,0,0,28,0,0,29,1102,0,0,0,0,0,1,0,
697,0,0,29,153,0,4,1131,0,0,6,5,0,1,0,2,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,3,0,0,
736,0,0,30,153,0,4,1173,0,0,6,5,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
775,0,0,31,183,0,5,1197,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,
818,0,0,32,0,0,29,1214,0,0,0,0,0,1,0,
833,0,0,1,165,0,9,1287,0,0,1,1,0,1,0,1,3,0,0,
852,0,0,1,0,0,13,1308,0,0,1,0,0,1,0,2,97,0,0,
871,0,0,1,0,0,15,1331,0,0,0,0,0,1,0,
886,0,0,33,84,0,4,1409,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,3,0,0,
913,0,0,34,165,0,4,1422,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,3,0,0,
940,0,0,35,139,0,4,1438,0,0,5,3,0,1,0,2,3,0,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
975,0,0,36,109,0,4,1470,0,0,4,3,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1006,0,0,37,78,0,5,1487,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
1033,0,0,38,0,0,29,1497,0,0,0,0,0,1,0,
1048,0,0,2,299,0,9,1515,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1075,0,0,2,0,0,13,1533,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,97,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
1134,0,0,2,0,0,15,1564,0,0,0,0,0,1,0,
1149,0,0,39,276,0,4,1762,0,0,12,5,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,1,97,0,0,
1212,0,0,40,713,0,4,1820,0,0,13,7,0,1,0,1,97,0,0,1,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1279,0,0,41,269,0,4,1880,0,0,6,3,0,1,0,1,97,0,0,1,97,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,1,3,0,0,
1318,0,0,42,269,0,4,1909,0,0,6,3,0,1,0,1,97,0,0,1,97,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,1,3,0,0,
1357,0,0,43,223,0,4,1944,0,0,5,2,0,1,0,1,97,0,0,1,97,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,
1392,0,0,44,0,0,17,2192,0,0,1,1,0,1,0,1,97,0,0,
1411,0,0,44,0,0,45,2208,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
1434,0,0,44,0,0,45,2213,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
1461,0,0,44,0,0,13,2339,0,0,47,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,2,97,0,
0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,3,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
1664,0,0,44,0,0,15,2468,0,0,0,0,0,1,0,
1679,0,0,45,484,0,9,2519,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
1722,0,0,45,0,0,13,2545,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,
1749,0,0,45,0,0,15,2577,0,0,0,0,0,1,0,
1764,0,0,46,261,0,9,2812,0,0,1,1,0,1,0,1,3,0,0,
1783,0,0,46,0,0,13,2825,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,4,0,
0,2,3,0,0,
1822,0,0,46,0,0,15,2850,0,0,0,0,0,1,0,
1837,0,0,47,0,0,17,3141,0,0,1,1,0,1,0,1,97,0,0,
1856,0,0,47,0,0,45,3157,0,0,31,31,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1995,0,0,48,0,0,17,3421,0,0,1,1,0,1,0,1,97,0,0,
2014,0,0,48,0,0,45,3436,0,0,31,31,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2153,0,0,47,0,0,13,3492,0,0,20,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2248,0,0,48,0,0,13,3514,0,0,20,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2343,0,0,47,0,0,15,3556,0,0,0,0,0,1,0,
2358,0,0,48,0,0,15,3558,0,0,0,0,0,1,0,
2373,0,0,49,155,0,9,3591,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
2396,0,0,50,119,0,9,3615,0,0,0,0,0,1,0,
2411,0,0,49,0,0,13,3632,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
2434,0,0,50,0,0,13,3652,0,0,5,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
2469,0,0,50,0,0,15,3676,0,0,0,0,0,1,0,
2484,0,0,49,0,0,15,3692,0,0,0,0,0,1,0,
2499,0,0,51,74,0,5,4278,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,
2526,0,0,52,498,0,9,4505,0,0,0,0,0,1,0,
2541,0,0,52,0,0,13,4527,0,0,3,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,
2568,0,0,52,0,0,15,4555,0,0,0,0,0,1,0,
2583,0,0,53,417,0,9,4741,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
2614,0,0,53,0,0,13,4763,0,0,10,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2669,0,0,53,0,0,15,4797,0,0,0,0,0,1,0,
2684,0,0,54,0,0,17,4972,0,0,1,1,0,1,0,1,97,0,0,
2703,0,0,54,0,0,45,4995,0,0,1,1,0,1,0,1,3,0,0,
2722,0,0,54,0,0,13,5017,0,0,15,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,
2797,0,0,54,0,0,15,5057,0,0,0,0,0,1,0,
2812,0,0,55,75,0,9,5106,0,0,1,1,0,1,0,1,3,0,0,
2831,0,0,55,0,0,13,5115,0,0,1,0,0,1,0,2,3,0,0,
2850,0,0,56,118,0,4,5238,0,0,4,3,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
2881,0,0,57,297,0,9,5283,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
2912,0,0,57,0,0,13,5293,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
2943,0,0,58,0,0,17,5641,0,0,1,1,0,1,0,1,97,0,0,
2962,0,0,58,0,0,45,5661,0,0,0,0,0,1,0,
2977,0,0,58,0,0,13,5682,0,0,7,0,0,1,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,
3020,0,0,58,0,0,15,5707,0,0,0,0,0,1,0,
3035,0,0,59,490,0,9,5869,0,0,9,9,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
3086,0,0,59,0,0,13,5881,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,4,0,
0,2,4,0,0,
3125,0,0,59,0,0,15,5906,0,0,0,0,0,1,0,
3140,0,0,60,52,0,4,5997,0,0,1,0,0,1,0,2,3,0,0,
3159,0,0,61,88,0,9,6105,0,0,1,1,0,1,0,1,3,0,0,
3178,0,0,61,0,0,13,6121,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
3201,0,0,61,0,0,15,6142,0,0,0,0,0,1,0,
3216,0,0,3,323,0,9,6284,0,0,6,6,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
3255,0,0,3,0,0,13,6298,0,0,8,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,4,0,0,
3302,0,0,3,0,0,15,6327,0,0,0,0,0,1,0,
3317,0,0,0,0,0,56,6418,0,0,1,1,0,1,0,3,102,0,0,
3336,0,0,0,0,0,15,6425,0,0,1,1,0,1,0,1,102,0,0,
3355,0,0,0,0,0,78,6426,0,0,1,1,0,1,0,3,102,0,0,
3374,0,0,62,174,0,6,6430,0,0,5,5,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,2,102,0,0,2,97,
0,0,
3409,0,0,0,0,0,15,6445,0,0,1,1,0,1,0,1,102,0,0,
3428,0,0,0,0,0,78,6446,0,0,1,1,0,1,0,3,102,0,0,
3447,0,0,0,0,0,13,6456,0,0,6,1,0,1,0,1,102,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,
3486,0,0,0,0,0,15,6471,0,0,1,1,0,1,0,1,102,0,0,
3505,0,0,0,0,0,78,6472,0,0,1,1,0,1,0,3,102,0,0,
3524,0,0,0,0,0,15,6517,0,0,1,1,0,1,0,1,102,0,0,
3543,0,0,0,0,0,78,6518,0,0,1,1,0,1,0,3,102,0,0,
3562,0,0,63,124,0,4,6532,0,0,4,2,0,1,0,2,5,0,0,2,5,0,0,1,3,0,0,1,3,0,0,
3593,0,0,64,224,0,9,6584,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
3616,0,0,65,228,0,9,6588,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
3639,0,0,64,0,0,13,6596,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
3670,0,0,65,0,0,13,6605,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
3701,0,0,66,123,0,4,6651,0,0,4,3,0,1,0,2,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
3732,0,0,67,112,0,4,6663,0,0,4,3,0,1,0,2,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
3763,0,0,64,0,0,15,6695,0,0,0,0,0,1,0,
3778,0,0,65,0,0,15,6699,0,0,0,0,0,1,0,
3793,0,0,68,303,0,4,6705,0,0,6,5,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,5,0,0,
3832,0,0,69,660,0,9,6797,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
3867,0,0,69,0,0,13,6802,0,0,5,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
3902,0,0,69,0,0,15,6839,0,0,0,0,0,1,0,
3917,0,0,70,605,0,9,6888,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
3952,0,0,70,0,0,13,6893,0,0,5,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
3987,0,0,70,0,0,15,6931,0,0,0,0,0,1,0,
4002,0,0,71,601,0,9,7001,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
4037,0,0,72,290,0,9,7005,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
4060,0,0,71,0,0,13,7012,0,0,5,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
4095,0,0,72,0,0,13,7022,0,0,5,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
4130,0,0,71,0,0,15,7061,0,0,0,0,0,1,0,
4145,0,0,72,0,0,15,7065,0,0,0,0,0,1,0,
4160,0,0,73,161,0,9,7127,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
4187,0,0,73,0,0,13,7132,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
4218,0,0,73,0,0,15,7171,0,0,0,0,0,1,0,
4233,0,0,74,197,0,4,7216,0,0,5,3,0,1,0,2,4,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
4268,0,0,75,175,0,4,7249,0,0,4,3,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
4299,0,0,76,215,0,4,7278,0,0,5,4,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,3,0,0,
4334,0,0,77,106,0,4,7344,0,0,3,2,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,
4361,0,0,78,100,0,4,7385,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
4388,0,0,79,357,0,4,7533,0,0,12,11,0,1,0,1,3,0,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
4451,0,0,80,1629,0,4,7615,0,0,31,29,0,1,0,2,3,0,0,2,97,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
4590,0,0,4,139,0,9,7754,0,0,1,1,0,1,0,1,3,0,0,
4609,0,0,4,0,0,13,7765,0,0,2,0,0,1,0,2,97,0,0,2,97,0,0,
4632,0,0,4,0,0,15,7780,0,0,0,0,0,1,0,
4647,0,0,81,545,0,4,7931,0,0,25,12,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,1,3,0,0,
4762,0,0,82,116,0,4,8081,0,0,4,3,0,1,0,2,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
4793,0,0,83,339,0,4,8188,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
4820,0,0,84,81,0,4,44,1,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,97,0,0,
};


/*  Version  FAC_DES_MAS ImpSclFnc.pc  7.000   */
#include <ImpSclFnc.h>
#include <math.h>
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

	long lhNumAbonado;
	long lhCodCilclFact;
	long lhIndOrdentotal;
	char szhStrCodCliente[9];
	long lhCodCliente;
	char szhFecDesde[10];
	char szhFecHasta[10];
	char szhFormato_Fecha[9];
	char szhFormato_Hora [9];
	int  ihZero;
	int  ihUno;
	char szhDesTipValor[14];
	int  gihCodTipDocum;
/* EXEC SQL END DECLARE SECTION  ; */ 


/* EXEC SQL DECLARE curMensNoCiclo CURSOR FOR
    SELECT DESC_MENSLIN
      FROM FA_MENSPROCESO A,
           FA_MENSAJES B
     WHERE A.NUM_PROCESO = :lhNumAbonado
       AND A.CORR_MENSAJE = B.CORR_MENSAJE
     ORDER BY A.CORR_MENSAJE,B.NUM_LINEA; */ 


/* EXEC SQL DECLARE  curArrastre CURSOR FOR
         SELECT   COD_CLIENTE ,
                  COD_ABONADO ,
                  COD_BOLSA  ,
                  VAL_BOLSA,
                  IND_UNIDAD,
                  VAL_ARRASTRE,
                  VAL_EXPIRADO,
                  VAL_DISPONIBLE,
                  VAL_CONSUMO,
                  VAL_RESTO,
                  SUBSTR(TO_CHAR(COD_CLIENTE, :szhStrCodCliente),2)||SUBSTR(TO_CHAR(COD_ABONADO, :szhStrCodCliente),2)
         FROM     TOL_HDARRASTRE_TH
         WHERE    COD_CICLFACT = :lhCodCilclFact
         ORDER BY COD_CLIENTE,COD_ABONADO ; */ 


/* EXEC SQL DECLARE curDocsPeriodo CURSOR FOR
         SELECT A.COD_OPERADORA,
                A.COD_OFICINA,
                A.COD_TIPDOCUM,
                B.DES_TIPDOCUM,
                A.PREF_PLAZA,
                A.NUM_FOLIO,
                TO_CHAR(A.FEC_EMISION,:szhFormato_Fecha),
                A.TOT_FACTURA
         FROM   FA_HISTDOCU A, GE_TIPDOCUMEN B
         WHERE  A.COD_TIPDOCUM = B.COD_TIPDOCUM
           AND  A.COD_CLIENTE = :lhCodCliente
           AND  A.FEC_EMISION >= TO_DATE(:szhFecDesde,:szhFormato_Fecha)
           AND  A.FEC_EMISION <= TO_DATE(:szhFecHasta,:szhFormato_Fecha); */ 


    /* EXEC SQL DECLARE cRegImpre CURSOR FOR
                SELECT COD_REGISTRO,COD_TIPDOCUM
                  FROM FA_REGISIMPRESION_TD
                 WHERE COD_TIPDOCUM  = :gihCodTipDocum
                   AND IND_IMPRESION = 1
                 ORDER BY COD_REGISTRO ; */ 



/* PGG SOPORTE 08-05-2006 Desde Aqui EC-042  */
/*****************************************************************************/
void trim (const char *c, char *result)
{
    char *l;
    char *r;
    for ( l=(char *)c;  *l==' '; l++ );
    for ( r=(char *)c+strlen(c)-1;  *r==' '; r-- );

    strncpy(result, l, (r>=l)?r-l+1:1);
    result[r-l+1]=0;
}

/*****************************************************************************/
int GetParam( int *iNumParam, char *argv[], char *szCadena,int chr)
{
    char    *p, *pant, c;
    int     cont;

    cont = 0;
    *iNumParam = 0;
    pant = p = szCadena;

    while ( 1 )
    {
        p=strchr(pant,chr);
        if ( p==NULL )
        {
            break;
        }
        else
        {
            c = *p;
            *p = 0;
            if ( ( argv[cont]  = malloc(_strlen(pant)+1) ) == NULL )
            {
                printf ("\n\t\t*** Error, No se puede reservar memoria \n");
                return(69);
            }
            strcpy(argv[cont],pant) ;
            pant = p  + 1;
            *p = c;
            cont++;
        }
    }
    if ( p==NULL )
    {
        if ( _strlen(pant)>0 )
        {
            if ( ( argv[cont]  = malloc(_strlen(pant)+1) ) == NULL )
            {
                printf ("\n\t\t*** Error, No se puede reservar memoria \n");
                return(69);
            }
            strcpy(argv[cont],pant) ;
            cont++;
        }
    }

    *iNumParam=cont;
    return(0);
}/************************ Final GetParam ***************************/

int CargaStringSuspension(long  lCodCiclfact)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhEN_Cod_ciclfact;
    char szhSV_Categoria[513];
    char szhSD_fecha    [1025];
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="CargaStringSuspension";

    vDTrazasLog(szModulo,"\tEntrando a %s con ciclo=%ld\n", LOG04, szModulo,lCodCiclfact);

    lhEN_Cod_ciclfact = lCodCiclfact;

    memset (szhSV_Categoria, 0, sizeof(szhSV_Categoria));
    memset (szhSD_fecha, 0, sizeof(szhSD_fecha));

    /* EXEC SQL EXECUTE
    BEGIN
    CO_DIAS_SUSP_PG.OBTIENE_FECHA_SUSP(:lhEN_Cod_ciclfact, :szhSV_Categoria, :szhSD_fecha);
    END;
    END-EXEC; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "begin CO_DIAS_SUSP_PG . OBTIENE_FECHA_SUSP ( :lhEN_Cod_ci\
clfact , :szhSV_Categoria , :szhSD_fecha ) ; END ;";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhEN_Cod_ciclfact;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhSV_Categoria;
    sqlstm.sqhstl[1] = (unsigned long )513;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhSD_fecha;
    sqlstm.sqhstl[2] = (unsigned long )1025;
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



    vDTrazasLog (szModulo,"\t===>>> CO_DIAS_SUSP_PG.OBTIENE_FECHA_SUSP [%d][%s] ",LOG04, SQLCODE, SQLERRM);
    if ( SQLCODE != SQLOK && SQLCODE == SQLNOTFOUND )
    {
        vDTrazasLog (szModulo,"Error en ejecucion de CO_DIAS_SUSP_PG.OBTIENE_FECHA_SUSP\n[%d][%s] ",LOG01, SQLCODE, SQLERRM);
        return(FALSE);
    }

    strcpy(SV_Categoria,szhSV_Categoria);
    strcpy(SD_fecha,szhSD_fecha);

    trim(SV_Categoria, SV_Categoria);
    trim(SD_fecha, SD_fecha);

    return(TRUE);
}
/*****************************************************************************/
int iCargaFechaSuspensionSt()
{
    char Dias_obtenidos[1000];
    char Categoria_obtenida[1000];
    int i=0;
    int  CmpPos,Pos,ARGC_DIR01,ARGC_DIR02;
    char *ARGV_DIR01[20],*ARGV_DIR02[20],CampoFormateado[1000];

    memset (Categoria_obtenida,0, sizeof(Categoria_obtenida));
    memset (Dias_obtenidos,0, sizeof(Dias_obtenidos));

    for ( i=0; i<2 ;i++ )
    {
        if ( i == 0 )
            GetParam(&ARGC_DIR01,ARGV_DIR01, SV_Categoria ,SEPARADOR_01);
        else
            GetParam(&ARGC_DIR01,ARGV_DIR01, SD_fecha ,SEPARADOR_01);

        stDias.iCantidadRegs = 0;
        for ( Pos=0;Pos<ARGC_DIR01;Pos++ )
        {
            GetParam(&ARGC_DIR02,ARGV_DIR02,ARGV_DIR01[Pos],SEPARADOR_02);

            memset (CampoFormateado,0, sizeof(CampoFormateado));
            if ( i == 0 )
            {
                sprintf(CampoFormateado,"%s" ,ARGV_DIR01[Pos]);
                strcat(Dias_obtenidos,CampoFormateado);
                stDias.iDias[Pos] = atoi(CampoFormateado);
            }
            else
            {
                sprintf(CampoFormateado,"%s" ,ARGV_DIR01[Pos]);
                strcat(Categoria_obtenida,CampoFormateado);
                strcpy(stDias.szCategoria[Pos], CampoFormateado);
            }

            for ( CmpPos=0;CmpPos<ARGC_DIR02;CmpPos++ )
            {
                free(ARGV_DIR02[CmpPos]);
            }
            stDias.iCantidadRegs ++;

        }
        for ( Pos=0;Pos<ARGC_DIR01;Pos++ )
        {
            free(ARGV_DIR01[Pos]);
        }
    }
    return(TRUE);
}


/* PGG SOPORTE 08-05-2006 Hasta Aqui EC-042  */

BOOL bfnOrdenaImpresionRC (ST_TABLA_ACUM  *pstTablaAcum, ST_TABLA_ORDEN *pstTablaOrden, int iUltimaPosicion)
{
    int         i,j,x;
    char        szKeyAux[60];
    int         iSocaloAux;

    for ( i=0; i<iUltimaPosicion; i++ )
    {
        strcpy(pstTablaOrden->szKey[i],pstTablaAcum->szKey[i]);
        pstTablaOrden->iSocalo[i]       = i;
    }
    for ( j = iUltimaPosicion; j > 0; j-- )
    {
        for ( i=0; i < j-1; i++ )
        {
            if ( strcmp(pstTablaOrden->szKey[i],pstTablaOrden->szKey[i+1])>0 )
            {
                strcpy(szKeyAux,pstTablaOrden->szKey[i+1]);
                iSocaloAux  = pstTablaOrden->iSocalo[i+1];

                strcpy(pstTablaOrden->szKey[i+1],pstTablaOrden->szKey[i]);
                pstTablaOrden->iSocalo[i+1]    = pstTablaOrden->iSocalo[i];

                strcpy(pstTablaOrden->szKey[i],szKeyAux);
                pstTablaOrden->iSocalo[i]      = iSocaloAux;
            }
        }
    }

    return(TRUE);
}

int CalculaDigVerif (double Inumero, int * DigVerif )
{
    int i       = 0;
    int j       = 2; /* j tomara los valores de 2 a 1 inclusives */
    int iDigito = 0;

    char szAux[2]   = "";
    char szNum[100] = "";
    long IValor;

    div_t stRes         ;

    if ( (long)Inumero != Inumero )
    {
        IValor = (long)Inumero*pow(10,atoi(szNumDecimal));
        if ( IValor<0 )
        {
            IValor*=-1;
        }
        sprintf (szNum ,"%ld",IValor );
    }
    else
    {
        sprintf (szNum,"%.0f",Inumero);
    }

    i = _strlen(szNum)-1;

    while ( i >= 0 )
    {
        if ( j <= 0 )
            j  = 2;

        strncpy (szAux, &szNum [i], 1);
        iDigito += (atoi (szAux) * j);
        j--;
        i--;
    }

    stRes = div (iDigito, 10);

    if ( stRes.rem == 0 )
        *DigVerif = 0;
    else
        *DigVerif = 10 - stRes.rem;

    return(TRUE);

} /**************************** Final CalculaDigVerif **********************/

BOOL bEscribeEnArchivo(FILE *Fd_ArchImp, char * zsBuffImpArch, char * buffer_local)
{
    int rc = 0;

    char *szModulo="bEscribeEnArchivo";


    if ( strncmp(buffer_local,FLUSH,_strlen(FLUSH))==0 )
    {
        if ( _strlen(zsBuffImpArch)>0 )
        {
            rc = fprintf(Fd_ArchImp,"%s",zsBuffImpArch);
            if ( rc<=0 )
            {
                vDTrazasLog(szModulo,"bEscribeEnArchivo RETORNO ERROR",LOG02);
                return(FALSE);
            }
            memset(zsBuffImpArch,0,sizeof(zsBuffImpArch));
        }
    }
    else
    {
        buffer_local[_strlen(buffer_local)]=0;
        if ( (_strlen(buffer_local) + _strlen(zsBuffImpArch)) < MAX_BYTES_BUFFER )
        {
            strcat(zsBuffImpArch,buffer_local);
            zsBuffImpArch[_strlen(zsBuffImpArch)]=0;
        }
        else
        {
            rc = fprintf(Fd_ArchImp,"%s",zsBuffImpArch);
            if ( rc<=0 )
            {
                vDTrazasLog(szModulo,"bEscribeEnArchivo RETORNO ERROR",LOG02);
                return(FALSE);
            }
            memset(zsBuffImpArch,0,sizeof(zsBuffImpArch));
            strcpy(zsBuffImpArch,buffer_local);
            zsBuffImpArch[_strlen(buffer_local)]=0;
        }
    }
    return(1);
}/****************** Final bEscribeEnArchivo *******************/


int FillCodIdioma(char *dat)
{
    int i;
    char aux[5+1];

    sprintf(aux,"%-5.5s\0",dat);
    for ( i=0;i<_strlen(aux);i++ )
    {
        if ( aux[i]==' ' )
        {
            aux[i]='0';
        }
    }
    sprintf(dat,"%5.5s\0",aux);
    return(0);

}

int RetPos(char *Cadena, ST_TABLA  *Tabla)
{
    int i;

    for ( i=0; i<Tabla->iLastPosition; i++ )
    {
        if ( !strcmp (Tabla->szDes[i], Cadena) )
            return(Tabla->iPosition[i]);
    }
    strcpy(Tabla->szDes[i],Cadena);
    Tabla->iPosition[i]  = i;
    Tabla->iLastPosition = i + 1;

    return(i);

}/**************************** Final RetPos **********************/

int FormatoHora(long lNumero, int iLargoNum , char *szFormato)
{
    ldiv_t  division;
    long    lDivisor=60;
    long    lMinutos;
    long    lSegundos;

    if ( lNumero < 0 ) lNumero = 0;
    division = ldiv (lNumero,lDivisor);
    lMinutos = division.quot;
    lSegundos= division.rem;

    sprintf (szFormato, "%*.*ld:%2.2ld",iLargoNum, iLargoNum,lMinutos, lSegundos);

    return(0);
}

int BuscaAbonado(ST_ABONADO *Abonado,int *pos,long NumAbo)
{
    int i;

    for ( i=0;i< Abonado->CantidadAbonados;i++ )
    {
        if ( NumAbo==Abonado->lNumAbonado[i] )
        {
            *pos=i;
            return(0);
        }
    }

    *pos=-1;
    return(0);
}

int FormateaDireccion(char *Direccion,char *dir_noformateada)
{
    int  rc,CmpPos,Pos,ARGC_DIR01,ARGC_DIR02;
    char *ARGV_DIR01[20],*ARGV_DIR02[20],CampoFormateado[2000];
    char *szModulo="FormateaDireccion";

    rc=TRUE;


    /*
    Separacion de campos segun delimitador asignados a arreglos
    */
    dir_noformateada[0]=0;

    RecupParam(&ARGC_DIR01,ARGV_DIR01,Direccion,SEPARADOR_01);

    vDTrazasLog(szModulo,"\tFormateaDireccion:Direccion:(%s)",LOG04,Direccion);
    for ( Pos=0;Pos<ARGC_DIR01;Pos++ )
    {
        /*printf("ARGV_DIR01|%s|\n",ARGV_DIR01[Pos]);*/
        RecupParam(&ARGC_DIR02,ARGV_DIR02,ARGV_DIR01[Pos],SEPARADOR_02);
        if ( ARGC_DIR02 <2 )
        {
            vDTrazasLog(szModulo, "\tFormateaDireccion:error numero regitros (%d):campo(%s)", LOG04, ARGC_DIR02,ARGV_DIR01[Pos]);
            rc=FALSE;
        }
        else
        {
            sprintf(CampoFormateado,"%-*.*s" ,atoi(ARGV_DIR02[1]),atoi(ARGV_DIR02[1]),((ARGC_DIR02<3)? "":ARGV_DIR02[2]));
            vDTrazasLog(szModulo,"\tFormateaDireccion:campo:(%s)",LOG06,CampoFormateado);
            strcat(dir_noformateada,CampoFormateado);
        }
        for ( CmpPos=0;CmpPos<ARGC_DIR02;CmpPos++ )
        {
            free(ARGV_DIR02[CmpPos]);
        }
    }
    for ( Pos=0;Pos<ARGC_DIR01;Pos++ )
    {
        free(ARGV_DIR01[Pos]);
    }

    vDTrazasLog(szModulo,"\tFormateaDireccion:dir_noformateada:(%s)",LOG04,dir_noformateada);

    return(rc);
}/*********************************** Final FormateaDireccion *************************************/


int bfnAcumulaMontos(ST_ACUMMTO      *AcumMto,
                     double          dTotFactura,
                     double          dTotalCuotas,
                     double          dTotalAPagar,
                     double          dTotalSaldo)
{
    char *szModulo="bfnAcumulaMontos";

    AcumMto->dTotFactura    =  AcumMto->dTotFactura  + dTotFactura;
    AcumMto->dTotCuotas     =  AcumMto->dTotCuotas   + dTotalCuotas;
    AcumMto->dTotPagar      =  AcumMto->dTotPagar    + dTotalAPagar;
    AcumMto->dTotSaldoAnt   =  AcumMto->dTotSaldoAnt + dTotalSaldo;

    vDTrazasLog (szModulo,"AcumMto->dTotFactura [%.4f] "
                 "AcumMto->dTotCuotas  [%.4f] "
                 "AcumMto->dTotPagar   [%.4f] "
                 "AcumMto->dTotSaldoAnt[%.4f] "
                 ,LOG04, AcumMto->dTotFactura
                 , AcumMto->dTotCuotas, AcumMto->dTotPagar
                 , AcumMto->dTotSaldoAnt);

    return(TRUE);
}/*********************************** Final bfnAcumulaMontos *************************************/

BOOL bfnInsertar_FadCTLImpres(  ST_ACUMMTO      *AcumMto,
                                LINEACOMANDO            *ParEntrada,
                                ST_INFGENERAL           *sthFa_InfGeneral,
                                char            *szNomArch
                             )
{
    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

    char   szhCodInforme   [7]  ;
    long   lhNumSecuInfo        ;
    int    ihCodTipImpres       ;
    char   szhCodDespacho  [6]  ;
    char   szhNomArchivo   [255];
    long   lhNumClientes        ;
    double dhTot_Factura         ;
    double dhTot_Cuotas          ;
    double dhTot_Pagar           ;

    double dhTot_SaldoAnt        ;
    /* EXEC SQL END DECLARE SECTION; */ 

    char *szModulo="bfnInsertar_FadCTLImpres";

    sprintf(szhCodInforme,"%s",szCODINFORME_GENERAR);
    lhNumSecuInfo  = ParEntrada->lNum_SecuInfo;
    ihCodTipImpres = COD_TIP_IMPRE;
    gihCodTipDocum  = ParEntrada->iCodTipDocum;
    sprintf(szhCodDespacho,"%s",ParEntrada->szCodDespacho);
    sprintf(szhNomArchivo,"%s",szNomArch);
    lhNumClientes  = (long) sthFa_InfGeneral->iContClientesProcesados;
    dhTot_Factura   = AcumMto->dTotFactura ;
    dhTot_Cuotas    = AcumMto->dTotCuotas  ;
    dhTot_Pagar     = AcumMto->dTotPagar   ;
    dhTot_SaldoAnt  = AcumMto->dTotSaldoAnt;
    ihZero = 0;

    vDTrazasLog(szModulo,"Proceso de Insercion en la FAD_CTLIMPRES(%s|%ld|%d|%d|%s|%s|%ld|%.4f|%.4f|%.4f|%.4f|)\n",
                LOG04,
                szhCodInforme,
                lhNumSecuInfo,
                ihCodTipImpres,
                gihCodTipDocum,
                szhCodDespacho,
                szhNomArchivo,
                lhNumClientes,
                dhTot_Factura,
                dhTot_Cuotas,
                dhTot_Pagar,
                dhTot_SaldoAnt
               );

    /* EXEC SQL INSERT
    INTO  FAD_CTLIMPRES (COD_INFORME,
                         NUM_SECUINFO,
                         COD_TIPIMPRES,
                         COD_TIPDOCUM,
                         COD_DESPACHO,
                         NOM_ARCHIVO,
                         NUM_CLIENTES,
                         TOT_FACTURAS,
                         TOT_CUOTAS,
                         TOT_PAGAR,
                         TOT_SALDOANT,
                         TOT_LOCALES,
                         TOT_INTERZONA,
                         TOT_ESPECIALES,
                         TOT_CARRIER,
                         TOT_ROAMING,
                         COD_ESTADO)
    VALUES ( :szhCodInforme,
             :lhNumSecuInfo,
             :ihCodTipImpres,
             :gihCodTipDocum,
             :szhCodDespacho,
             :szhNomArchivo,
             :lhNumClientes,
             :dhTot_Factura,
             :dhTot_Cuotas,
             :dhTot_Pagar,
             :dhTot_SaldoAnt,
             :ihZero,
             :ihZero,
             :ihZero,
             :ihZero,
             :ihZero,
             :ihZero); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into FAD_CTLIMPRES (COD_INFORME,NUM_SECUINFO,COD_T\
IPIMPRES,COD_TIPDOCUM,COD_DESPACHO,NOM_ARCHIVO,NUM_CLIENTES,TOT_FACTURAS,TOT_C\
UOTAS,TOT_PAGAR,TOT_SALDOANT,TOT_LOCALES,TOT_INTERZONA,TOT_ESPECIALES,TOT_CARR\
IER,TOT_ROAMING,COD_ESTADO) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b\
10,:b11,:b11,:b11,:b11,:b11,:b11)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )32;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodInforme;
    sqlstm.sqhstl[0] = (unsigned long )7;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhNumSecuInfo;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihCodTipImpres;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&gihCodTipDocum;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[4] = (unsigned long )6;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhNomArchivo;
    sqlstm.sqhstl[5] = (unsigned long )255;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&lhNumClientes;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&dhTot_Factura;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&dhTot_Cuotas;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&dhTot_Pagar;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&dhTot_SaldoAnt;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "\tError en INSERT de FAD_CTLIMPRES : %s ", LOG02,  SQLERRM);
        return(FALSE);
    }

    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )115;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "\tError en COMMIT al INSERT de FAD_CTLIMPRES : %s ", LOG02, SQLERRM);
        return(FALSE);
    }

    memset(AcumMto,0,sizeof(ST_ACUMMTO));
    return(TRUE);
}/************************************ Final bfnInsertar_FadCTLImpres **********************************************/

int bfnElimina_FadCTLImpres(LINEACOMANDO *ParEntrada)
{
    char *szModulo="bfnElimina_FadCTLImpres";

    /* EXEC SQL DELETE FROM FAD_CTLIMPRES
    WHERE
    NUM_SECUINFO = :ParEntrada->lNum_SecuInfo AND
                   COD_TIPDOCUM = :ParEntrada->iCodTipDocum  AND
                   COD_DESPACHO = :ParEntrada->szCodDespacho; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete  from FAD_CTLIMPRES  where ((NUM_SECUINFO=:b0 and \
COD_TIPDOCUM=:b1) and COD_DESPACHO=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )130;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(ParEntrada->lNum_SecuInfo);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(ParEntrada->iCodTipDocum);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(ParEntrada->szCodDespacho);
    sqlstm.sqhstl[2] = (unsigned long )6;
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
        vDTrazasLog(szModulo, "\tError en DELETE de FAD_CTLIMPRES : %s ", LOG01,  SQLERRM);
        return(FALSE);
    }

    /* EXEC SQL COMMIT; */ 

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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "\tError en COMMIT al DELETE de FAD_CTLIMPRES : %s ", LOG01, SQLERRM);
        return(FALSE);
    }

    return(TRUE);
}/************************************ Final bfnElimina_FadCTLImpres **********************************************/



int ifnGetSecReproceso(long lCicloFact,long lNroJob, long lNumProceso)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCicloFact=lCicloFact;
    long lhNroJob=lNroJob;
    long lhNumProceso=lNumProceso;
    long lhSecReProc;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="ifnGetSecReproceso";

    /* EXEC SQL
    SELECT NVL(MAX(SEC_REPROCESO),0)
      INTO :lhSecReProc
      FROM FA_TRAZAPROC_JOB_TO
     WHERE COD_CICLFACT = :lhCicloFact
       AND NUM_JOB      = :lhNroJob
       AND COD_PROCESO  = :lhNumProceso ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(max(SEC_REPROCESO),0) into :b0  from FA_TRAZAP\
ROC_JOB_TO where ((COD_CICLFACT=:b1 and NUM_JOB=:b2) and COD_PROCESO=:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )172;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhSecReProc;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCicloFact;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNroJob;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumProceso;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error Al Recuperar Secuencia de Proceso Job[%ld] Ciclo[%d] Proceso[%ld]\n[%s]\n",LOG01, lCicloFact, lNroJob, lNumProceso,SQLERRM);
        return(FALSE);
    }

    return(lhSecReProc);
}


BOOL bfnUpdTrazaJob(long lCodCiclo, int iCodEstado )
{
    /* EXEC SQL BEGIN DECLARE SECTION      ; */ 

    long    lhCodProceso        ;
    long    lhCodCiclo          ;
    int     ihCodEstado     ;
    char    szhGlsProceso   [50]    ;
    long    lhNroJob=lNroJob;
    int     ihSecProceso;
    /* EXEC SQL END DECLARE SECTION        ; */ 


    char *szModulo="bfnUpdTrazaJob";

    lhCodProceso = COD_PROCESO;
    lhCodCiclo   = lCodCiclo;
    ihSecProceso = iSecProceso ;

    if ( iCodEstado == TRUE )
    {
        ihCodEstado  = iPROC_EST_OK ;
        strcpy(szhGlsProceso, GLS_PROCFINOK);
    }
    else
    {
        ihCodEstado  = iPROC_EST_ERR ;
        strcpy(szhGlsProceso, GLS_PROCFINNOOK);
    }
    vDTrazasLog (szModulo,"Actualizacion de FA_TRAZAPROC_JOB_TO Flag=%d -> Estado=%d [%s]",LOG02, iCodEstado, ihCodEstado, szhGlsProceso);

    /* EXEC SQL
    UPDATE FA_TRAZAPROC_JOB_TO
       SET COD_ESTAPROC = :ihCodEstado ,
           GLS_PROCESO  = :szhGlsProceso,
           FEC_TERMINO  = SYSDATE
    WHERE NUM_JOB      = :lhNroJob
    AND COD_PROCESO  = :lhCodProceso
    AND COD_CICLFACT = :lhCodCiclo
    AND SEC_REPROCESO= :ihSecProceso; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_TRAZAPROC_JOB_TO  set COD_ESTAPROC=:b0,GLS_PROC\
ESO=:b1,FEC_TERMINO=SYSDATE where (((NUM_JOB=:b2 and COD_PROCESO=:b3) and COD_\
CICLFACT=:b4) and SEC_REPROCESO=:b5)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )203;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCodEstado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhGlsProceso;
    sqlstm.sqhstl[1] = (unsigned long )50;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNroJob;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhCodProceso;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhCodCiclo;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihSecProceso;
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



    vDTrazasLog(szModulo, "bfnUpdTrazaJob "
                "\nUPDATE FA_TRAZAPROC_JOB_TO           "
                "\n   SET COD_ESTAPROC = :ihCodEstado  =[%d], "
                "\n       GLS_PROCESO  = :szhGlsProceso=[%s],"
                "\n       FEC_TERMINO  = SYSDATE        "
                "\n WHERE NUM_JOB      = :lhNroJob    =[%d] "
                "\n   AND COD_PROCESO  = :lhCodProceso=[%d] "
                "\n   AND COD_CICLFACT = :lhCodCiclo  =[%d] "
                "\n   AND SEC_REPROCESO= :ihSecProceso=[%d]; ", LOG04,
                ihCodEstado, szhGlsProceso, lhNroJob, lhCodProceso, lhCodCiclo, ihSecProceso) ;

    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error Actualizacion de FA_TRAZAPROC_JOB_TO [%s]",LOG01, SQLERRM);
        return(FALSE);
    }

    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )242;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error COMMIT de FA_TRAZAPROC_JOB_TO [%s]",LOG01, SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}


BOOL bfnReg_Padre(LINEACOMANDO *ParEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    long    lhCodProceso        ;
	    long    lhCodCiclo          ;
	    int     ihCodEstado         ;
	    char    szhGlsProceso   [50];
	    long    lhNroJob=lNroJob;
	    int     ihSecProceso;
        char    szhHostId[11]       ;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="bfnReg_Padre";

    strcpy(szhHostId,szgHostId);

    lhCodProceso = COD_PROCESO;
    lhCodCiclo   = ParEntrada->lCodCiclFact;

    strcpy(szhGlsProceso, GLS_PROCINIT);

    if ( !bfnElimina_FadCTLImpres(ParEntrada) )
    {
        vDTrazasLog(szModulo,"Error en ejecucion de bfnElimina_FadCTLImpres ",LOG02);
        return(FALSE);
    }

    if ( lNroJob )
    {
        if ( iFlagSecReProc==FALSE )
        {
            iSecProceso=ifnGetSecReproceso(lhCodCiclo, lNroJob, lhCodProceso);
        }
        ihSecProceso=iSecProceso;
        if ( iSecProceso < 1 )
        {
            ihSecProceso=1;
        }

        vDTrazasLog (szModulo,"Se Recupero Secuencia de Ejecucion [%d] para Job [%ld] Ciclo [%d] Proceso [%ld].\n",LOG04, ihSecProceso, lhCodCiclo, lNroJob, lhCodProceso);

        /* EXEC SQL
        SELECT COD_ESTAPROC
          INTO :ihCodEstado
          FROM FA_TRAZAPROC_JOB_TO
         WHERE NUM_JOB       = :lhNroJob
           AND COD_PROCESO   = :lhCodProceso
           AND COD_CICLFACT  = :lhCodCiclo
           AND SEC_REPROCESO = :ihSecProceso
		   AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_TRAZAPROC_JOB_T\
O where ((((NUM_JOB=:b1 and COD_PROCESO=:b2) and COD_CICLFACT=:b3) and SEC_REP\
ROCESO=:b4) and (HOST_ID=:b5 or 1<>:b6))";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )257;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodEstado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNroJob;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodProceso;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclo;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&ihSecProceso;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szhHostId;
        sqlstm.sqhstl[5] = (unsigned long )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&igOpcionRango;
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



        vDTrazasLog(szModulo, "bfnReg_Padre       "
                    "\nSELECT COD_ESTAPROC "
                    "\nINTO :ihCodEstado =%d "
                    "\nFROM FA_TRAZAPROC_JOB_TO               "
                    "\nWHERE NUM_JOB       = :lhNroJob    =%d "
                    "\nAND   COD_PROCESO   = :lhCodProceso=%d "
                    "\nAND   COD_CICLFACT  = :lhCodCiclo  =%d "
                    "\nAND   SEC_REPROCESO = :ihSecProceso=%d;\n",LOG04,
                    ihCodEstado, lhNroJob, lhCodProceso, lhCodCiclo, ihSecProceso);
    }
    else
    {
        /* EXEC SQL SELECT COD_ESTAPROC
        INTO :ihCodEstado
        FROM FA_TRAZAPROC
        WHERE COD_PROCESO = :lhCodProceso
          AND COD_CICLFACT = :lhCodCiclo
          AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_TRAZAPROC where\
 ((COD_PROCESO=:b1 and COD_CICLFACT=:b2) and (HOST_ID=:b3 or 1<>:b4))";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )300;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodEstado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodProceso;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclo;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhHostId;
        sqlstm.sqhstl[3] = (unsigned long )11;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&igOpcionRango;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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


    }

    if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
    {
        vDTrazasLog (szModulo,"Error en ejecucion de SELECT de bfnReg_Padre [%s]",LOG01, SQLERRM);
        return(FALSE);
    }

    if ( SQLCODE == SQLNOTFOUND )
    {

        ihCodEstado=iPROC_EST_RUN;
        if ( lNroJob )
        {
            if ( iFlagSecReProc==FALSE )
            {
                iSecProceso++;
            }
            ihSecProceso=iSecProceso;

            /* EXEC SQL INSERT INTO FA_TRAZAPROC_JOB_TO (NUM_JOB, COD_CICLFACT, COD_PROCESO,
                                                      COD_ESTAPROC, SEC_REPROCESO, FEC_INICIO, GLS_PROCESO, COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS)
            VALUES (:lhNroJob, :lhCodCiclo, :lhCodProceso, :ihCodEstado, :ihSecProceso, SYSDATE,:szhGlsProceso, 0,0,0); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "insert into FA_TRAZAPROC_JOB_TO (NUM_JOB,COD_CICL\
FACT,COD_PROCESO,COD_ESTAPROC,SEC_REPROCESO,FEC_INICIO,GLS_PROCESO,COD_CLIENTE\
,NUM_ABONADO,NUM_REGISTROS) values (:b0,:b1,:b2,:b3,:b4,SYSDATE,:b5,0,0,0)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )335;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&lhNroJob;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclo;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhCodProceso;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&ihCodEstado;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihSecProceso;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhGlsProceso;
            sqlstm.sqhstl[5] = (unsigned long )50;
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



            vDTrazasLog(szModulo, "bfnReg_Padre 1 "
                        "\nINSERT INTO FA_TRAZAPROC_JOB_TO (NUM_JOB, COD_CICLFACT, COD_PROCESO,                                       "
                        "\n        COD_ESTAPROC, SEC_REPROCESO, FEC_INICIO, GLS_PROCESO, COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS)     "
                        "\nVALUES (:lhNroJob=[%d], :lhCodCiclo=[%d], :lhCodProceso=[%d], :ihCodEstado=[%d], :ihSecProceso=[%d], SYSDATE,:szhGlsProceso=[%s], 0,0,0);\n", LOG04,
                        lhNroJob, lhCodCiclo, lhCodProceso, ihCodEstado, ihSecProceso, szhGlsProceso);
        }
        else
        {
            /* EXEC SQL INSERT INTO FA_TRAZAPROC (COD_CICLFACT, COD_PROCESO,
                                               COD_ESTAPROC, FEC_INICIO, GLS_PROCESO,
                                               COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS)
            VALUES (:lhCodCiclo, :lhCodProceso, :ihCodEstado, SYSDATE,:szhGlsProceso, 0,0,0); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "insert into FA_TRAZAPROC (COD_CICLFACT,COD_PROCES\
O,COD_ESTAPROC,FEC_INICIO,GLS_PROCESO,COD_CLIENTE,NUM_ABONADO,NUM_REGISTROS) v\
alues (:b0,:b1,:b2,SYSDATE,:b3,0,0,0)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )374;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCiclo;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodProceso;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&ihCodEstado;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)szhGlsProceso;
            sqlstm.sqhstl[3] = (unsigned long )50;
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


        }

        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de INSERT de bfnReg_Padre [%s]",LOG01, SQLERRM);
            return(FALSE);
        }

        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )405;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnReg_Padre [%s]",LOG01, SQLERRM);
            return(FALSE);
        }

        return(TRUE);
    }

    if ( lNroJob )
    {
        if ( ihCodEstado == iPROC_EST_OK )
        {
            if ( iFlagSecReProc==FALSE )
            {
                iSecProceso++;
            }
            ihSecProceso=iSecProceso;
            ihCodEstado=iPROC_EST_RUN;

            /* EXEC SQL INSERT INTO FA_TRAZAPROC_JOB_TO (NUM_JOB, COD_CICLFACT, COD_PROCESO,
                                                      COD_ESTAPROC, SEC_REPROCESO, FEC_INICIO, GLS_PROCESO, COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS)
            VALUES (:lhNroJob, :lhCodCiclo, :lhCodProceso, :ihCodEstado, :ihSecProceso, SYSDATE,:szhGlsProceso, 0,0,0); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "insert into FA_TRAZAPROC_JOB_TO (NUM_JOB,COD_CICL\
FACT,COD_PROCESO,COD_ESTAPROC,SEC_REPROCESO,FEC_INICIO,GLS_PROCESO,COD_CLIENTE\
,NUM_ABONADO,NUM_REGISTROS) values (:b0,:b1,:b2,:b3,:b4,SYSDATE,:b5,0,0,0)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )420;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&lhNroJob;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclo;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhCodProceso;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&ihCodEstado;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihSecProceso;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhGlsProceso;
            sqlstm.sqhstl[5] = (unsigned long )50;
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



            vDTrazasLog(szModulo, "bfnReg_Padre 2 "
                        "\nINSERT INTO FA_TRAZAPROC_JOB_TO (NUM_JOB, COD_CICLFACT, COD_PROCESO,                                       "
                        "\n        COD_ESTAPROC, SEC_REPROCESO, FEC_INICIO, GLS_PROCESO, COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS)     "
                        "\nVALUES (:lhNroJob=[%d], :lhCodCiclo=[%d], :lhCodProceso=[%d], :ihCodEstado=[%d], :ihSecProceso=[%d], SYSDATE,:szhGlsProceso=[%s], 0,0,0);\n", LOG04,
                        lhNroJob, lhCodCiclo, lhCodProceso, ihCodEstado, ihSecProceso, szhGlsProceso);

            if ( SQLCODE != SQLOK )
            {
                vDTrazasLog (szModulo,"Error en ejecucion de INSERT de bfnReg_Padre [%s]",LOG01, SQLERRM);
                return(FALSE);
            }

            /* EXEC SQL COMMIT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )459;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            if ( SQLCODE != SQLOK )
            {
                vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnReg_Padre [%s]",LOG01, SQLERRM);
                return(FALSE);
            }
        }
        else if( iFlagSecReProc == FALSE )
        {
            vDTrazasLog (szModulo,"Error Proceso Anterior Ciclo[%d] Job[%d] Secuencia[%d] NO ha terminado Adecuadamente!\n",LOG01,lhCodCiclo,lNroJob,iSecProceso);
            return(FALSE);
        }
        return(TRUE);
    }
    if ( ihCodEstado != iPROC_EST_RUN )
    {
        ihCodEstado=iPROC_EST_RUN;
        /* EXEC SQL
        UPDATE FA_TRAZAPROC
        SET COD_ESTAPROC = :ihCodEstado ,
        GLS_PROCESO =  :szhGlsProceso,
        FEC_INICIO =  SYSDATE,
        FEC_TERMINO =  NULL
                       WHERE COD_PROCESO = :lhCodProceso
                       AND COD_CICLFACT = :lhCodCiclo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update FA_TRAZAPROC  set COD_ESTAPROC=:b0,GLS_PROCESO\
=:b1,FEC_INICIO=SYSDATE,FEC_TERMINO=null  where (COD_PROCESO=:b2 and COD_CICLF\
ACT=:b3)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )474;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodEstado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhGlsProceso;
        sqlstm.sqhstl[1] = (unsigned long )50;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodProceso;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclo;
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



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de bfnReg_Padre [%s]",LOG01, SQLERRM);
            return(FALSE);
        }
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )505;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnReg_Padre [%s]",LOG01, SQLERRM);
            return(FALSE);
        }
    }
    else if ( !lNroJob )
    {
        if ( !bfnChequeaEstado(ParEntrada) )
        {
            vDTrazasLog(szModulo,"Falla en la ejecucion de  bfnChequeaEstado ",LOG01);
            return(FALSE);
        }
    }
    return(TRUE);
}/************************************ Final bfnReg_Padre **********************************************/

BOOL bfnActualiza_ProcImpresion(LINEACOMANDO ParEntrada, BOOL bLlave)
{
    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

	    long    lhCodCiclo          ;
	    int     ihCodEstado         ;
	    char    szhglosa    [51]    ;
	    char    szhCodDespacho [6];
	    char    szhHostId[11]       ;
    /* EXEC SQL END DECLARE SECTION    ; */ 


    char *szModulo="bfnActualiza_ProcImpresion";

    gihCodTipDocum   = ParEntrada.iCodTipDocum;
    lhCodCiclo      = ParEntrada.lCodCiclFact;
    strcpy(szhCodDespacho, ParEntrada.szCodDespacho);
    strcpy(szhHostId,szgHostId);

    if ( bLlave )
    {
        ihCodEstado = iPROC_EST_OK;
        strcpy(szhglosa,szPROC_EST_OK);
    }
    else
    {
        ihCodEstado = iPROC_EST_ERR;
        strcpy(szhglosa,szPROC_EST_ERR);
    }
    /* EXEC SQL
    UPDATE FA_PROCIMPRESION_TD
       SET COD_ESTAPROC = :ihCodEstado ,
           FEC_TERMINO  = SYSDATE,
           GLS_ESTAPROC = :szhglosa
     WHERE COD_CICLFACT = :lhCodCiclo
       AND COD_TIPDOCUM = :gihCodTipDocum
       AND COD_DESPACHO = :szhCodDespacho
       AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_PROCIMPRESION_TD  set COD_ESTAPROC=:b0,FEC_TERM\
INO=SYSDATE,GLS_ESTAPROC=:b1 where (((COD_CICLFACT=:b2 and COD_TIPDOCUM=:b3) a\
nd COD_DESPACHO=:b4) and (HOST_ID=:b5 or 1<>:b6))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )520;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCodEstado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhglosa;
    sqlstm.sqhstl[1] = (unsigned long )51;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclo;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&gihCodTipDocum;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[4] = (unsigned long )6;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhHostId;
    sqlstm.sqhstl[5] = (unsigned long )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&igOpcionRango;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de bfnActualiza_ProcImpresion\n[%s]\n[ihCodEstado] = [%d]\n[szhglosa] = [%s]\n[lhCodCiclo] = [%ld]\n[gihCodTipDocum] = [%d]\n[szhCodDespacho] = [%s]\n[szhHostId] = [%s]\n[igOpcionRango] = [%d]\n"
                    ,LOG01, SQLERRM,ihCodEstado,szhglosa,lhCodCiclo,gihCodTipDocum,szhCodDespacho,szhHostId,igOpcionRango);
        return(FALSE);
    }
    else
    {
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )563;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnActualiza_ProcImpresion\n[%s]",LOG01,SQLERRM);
            return(FALSE);
        }
    }
    return(TRUE);
}/************************************ Final bfnActualiza_ProcImpresion **********************************************/

BOOL bfnActualiza_TrazaProceso(LINEACOMANDO ParEntrada,BOOL bLlave)
{
    int     NroRegsProcImp;
    int     i;
    int     TotalEstados=5;

    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

	    int     ihCod_Estaproc  [MAX_TRAZAPROC];
	    int     ihCod_Estado  ;
	    char    szhCodDespacho[6];
	    long    lhCodCiclo;
	    long    lhCodProceso;
	    char    szhGlsProceso[50];
	    char    szhHostId[11]    ;
    /* EXEC SQL END DECLARE SECTION    ; */ 


    int contador_estados[5];
    char *szModulo="bfnActualiza_TrazaProceso";

    vDTrazasLog(szModulo, "\tEntro a %s", LOG04,szModulo);

    lhCodCiclo      = ParEntrada.lCodCiclFact;
    lhCodProceso    = COD_PROCESO;
    strcpy(szhCodDespacho, ParEntrada.szCodDespacho);
    strcpy(szhHostId,szgHostId);

    if ( lhCodCiclo )
    {
        /* EXEC SQL
        SELECT COD_ESTAPROC
          INTO :ihCod_Estaproc
          FROM FA_PROCIMPRESION_TD
         WHERE COD_CICLFACT = :lhCodCiclo
           AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_PROCIMPRESION_T\
D where (COD_CICLFACT=:b1 and (HOST_ID=:b2 or 1<>:b3))";
        sqlstm.iters = (unsigned int  )100;
        sqlstm.offset = (unsigned int  )578;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)ihCod_Estaproc;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )sizeof(int);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclo;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )sizeof(long);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhHostId;
        sqlstm.sqhstl[2] = (unsigned long )11;
        sqlstm.sqhsts[2] = (         int  )11;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&igOpcionRango;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )sizeof(int);
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



        NroRegsProcImp = sqlca.sqlerrd[2];
        vDTrazasLog(szModulo, "query retorno registros SQLCODE(%d)NroRegsProcImp(%d)", LOG04,SQLCODE,NroRegsProcImp);

        if ( SQLCODE < SQLOK && NroRegsProcImp<=0 )
        {
            vDTrazasLog(szModulo, "Error en ejecucion del SELECT [%d][%s]", LOG00, SQLCODE,SQLERRM);
            return(FALSE);
        }

        for ( i=0;i<TotalEstados;i++ )
        {
            contador_estados[i]=0;
        }

        for ( i=0; i < NroRegsProcImp; i++ )
        {
            contador_estados[ihCod_Estaproc[i]]++;
        }

        /*ya no hay procesos sin ejecutarse o ejecutandose*/

        if ( !(contador_estados[0]>0 || contador_estados[iPROC_EST_RUN]>0) )
        {
            if ( contador_estados[iPROC_EST_ERR]>0 )
            {
                /*existen procesos que terminaron en error*/
                ihCod_Estado=iPROC_EST_ERR;
                strcpy(szhGlsProceso, GLS_PROCFINNOOK);
                vDTrazasLog (szModulo,"Existen subproceso terminados con error\n",LOG04);
            }
            else
            {
                /*todos procesos terminaron ok*/
                ihCod_Estado=iPROC_EST_OK;
                strcpy(szhGlsProceso, GLS_PROCFINOK);
                vDTrazasLog (szModulo,"todos los subprocesos terminaron y bien\n",LOG04);
            }

            /* EXEC SQL
            UPDATE FA_TRAZAPROC
            SET COD_ESTAPROC = :ihCod_Estado
            , FEC_TERMINO  = SYSDATE
            , GLS_PROCESO  = :szhGlsProceso
                             WHERE COD_CICLFACT = :lhCodCiclo
                             AND COD_PROCESO  = :lhCodProceso; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update FA_TRAZAPROC  set COD_ESTAPROC=:b0,FEC_TER\
MINO=SYSDATE,GLS_PROCESO=:b1 where (COD_CICLFACT=:b2 and COD_PROCESO=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )609;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&ihCod_Estado;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhGlsProceso;
            sqlstm.sqhstl[1] = (unsigned long )50;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclo;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lhCodProceso;
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



            if ( SQLCODE != SQLOK )
            {
                vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de bfnActualiza_TrazaProceso\n[%s]",LOG01,SQLERRM);
                return(FALSE);
            }

            /* EXEC SQL COMMIT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )640;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if ( SQLCODE != SQLOK )
            {
                vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnActualiza_TrazaProceso\n[%s]",LOG01,SQLERRM);
                return(FALSE);
            }
        }
        else
        {
            vDTrazasLog (szModulo,"Existe subproceso corriendo o por correr\n",LOG03);
        }
    }
    else
    {
        if ( !bLlave )
        {
            ihCod_Estado=iPROC_EST_ERR;

            vDTrazasLog (szModulo,"ejecucion de UPDATE de FA_INTERFACT por num_proceso",LOG04);
            /* EXEC SQL
            UPDATE FA_INTERFACT
            SET COD_ESTADOC=:ParEntrada.iCodSalida
            , COD_ESTPROC = :ihCod_Estado
                            WHERE NUM_PROCESO = :ParEntrada.lProceso; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update FA_INTERFACT  set COD_ESTADOC=:b0,COD_ESTP\
ROC=:b1 where NUM_PROCESO=:b2";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )655;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(ParEntrada.iCodSalida);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&ihCod_Estado;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&(ParEntrada.lProceso);
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
                vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de FA_INTERFACT\n[%s]",LOG01,SQLERRM);
                return(FALSE);
            }
        }
        else
        {
            ihCod_Estado=iPROC_EST_OK;
        }
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )682;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de FA_INTERFACT\n[%s]",LOG01,SQLERRM);
            return(FALSE);
        }
    }
    return(TRUE);

}/************************************ Final bfnActualiza_TrazaProceso **********************************************/


BOOL bfnChequeaEstado (LINEACOMANDO *ParEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    int     ihCod_Estaproc   ;
	    char    szhCodDespacho[6];
	    long    lhCodCiclo       ;
        char    szhHostId[11]    ;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="bfnChequeaEstado";

    lhCodCiclo      = ParEntrada->lCodCiclFact;
    strcpy(szhCodDespacho, ParEntrada->szCodDespacho);
    gihCodTipDocum   = ParEntrada->iCodTipDocum;
    strcpy(szhHostId,szgHostId);

    /* EXEC SQL
    	SELECT COD_ESTAPROC
    	  INTO :ihCod_Estaproc
    	  FROM FA_PROCIMPRESION_TD
    	 WHERE COD_CICLFACT  = :lhCodCiclo
           AND COD_DESPACHO  = :szhCodDespacho
           AND COD_TIPDOCUM  = :gihCodTipDocum
           AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_PROCIMPRESION_TD wh\
ere (((COD_CICLFACT=:b1 and COD_DESPACHO=:b2) and COD_TIPDOCUM=:b3) and (HOST_\
ID=:b4 or 1<>:b5))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )697;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCod_Estaproc;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclo;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&gihCodTipDocum;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhHostId;
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&igOpcionRango;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en SELECT de bfnChequeaEstado [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }
    if ( ihCod_Estaproc == 1 )
    {
        vDTrazasLog(szModulo, "Estado del proceso : En Proceso. El proceso actual se aborta", LOG01);
        return(FALSE);
    }

    return(TRUE);

}/********************* Final bfnChequeaEstado ****************************/


BOOL bfnActualizaRegprocImpres (LINEACOMANDO ParEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    int     ihCod_Estaproc     ;
	    char    szhCodDespacho  [6];
	    char    szhglosa    [51]   ;
	    long    lhCodCiclo         ;
        char    szhHostId[11]      ;
   /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="bfnActualizaRegprocImpres";

    lhCodCiclo = ParEntrada.lCodCiclFact;
    strcpy(szhCodDespacho, ParEntrada.szCodDespacho);
    gihCodTipDocum   = ParEntrada.iCodTipDocum;
    strcpy(szhHostId,szgHostId);

    /* EXEC SQL
    	SELECT COD_ESTAPROC
    	  INTO :ihCod_Estaproc
    	  FROM FA_PROCIMPRESION_TD
    	 WHERE COD_CICLFACT = :lhCodCiclo
       	   AND COD_TIPDOCUM = :gihCodTipDocum
       	   AND COD_DESPACHO = :szhCodDespacho
           AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_PROCIMPRESION_TD wh\
ere (((COD_CICLFACT=:b1 and COD_TIPDOCUM=:b2) and COD_DESPACHO=:b3) and (HOST_\
ID=:b4 or 1<>:b5))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )736;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCod_Estaproc;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclo;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&gihCodTipDocum;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[3] = (unsigned long )6;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhHostId;
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&igOpcionRango;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en SELECT de bfnActualizaRegprocImpres [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }

    if ( ihCod_Estaproc == 1 )
    {
        vDTrazasLog (szModulo, "Estado del proceso : En Proceso. Proceso nuevo se aborta", LOG01);
        return(FALSE);
    }

    ihCod_Estaproc=iPROC_EST_RUN;
    strcpy(szhglosa,szPROC_EST_RUN);

    /* EXEC SQL
    	UPDATE FA_PROCIMPRESION_TD
    	   SET COD_ESTAPROC = :ihCod_Estaproc ,
    		   GLS_ESTAPROC = :szhglosa ,
    		   FEC_INICIO   = SYSDATE
         WHERE COD_CICLFACT = :lhCodCiclo
           AND COD_TIPDOCUM = :gihCodTipDocum
           AND COD_DESPACHO = :szhCodDespacho
           AND ((HOST_ID =:szhHostId) OR (1 <> :igOpcionRango)); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_PROCIMPRESION_TD  set COD_ESTAPROC=:b0,GLS_ESTA\
PROC=:b1,FEC_INICIO=SYSDATE where (((COD_CICLFACT=:b2 and COD_TIPDOCUM=:b3) an\
d COD_DESPACHO=:b4) and (HOST_ID=:b5 or 1<>:b6))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )775;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCod_Estaproc;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhglosa;
    sqlstm.sqhstl[1] = (unsigned long )51;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclo;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&gihCodTipDocum;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[4] = (unsigned long )6;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhHostId;
    sqlstm.sqhstl[5] = (unsigned long )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&igOpcionRango;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de bfnActualizaRegprocImpres\n[%s]",LOG01,SQLERRM);
        return(FALSE);
    }
    else
    {
        /* EXEC SQL COMMIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )818;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de bfnActualizaRegprocImpres\n[%s]",LOG01,SQLERRM);
            return(FALSE);
        }
    }

    return(TRUE);
}/************************************ Final bfnActualizaRegprocImpres **********************************************/


/****************************************************************************/
/*  Funcion: int ObtieneIdiomaOperadora                                     */
/*  Funcion que Obtiene el Idioma de la Operadora                           */
/****************************************************************************/
int ObtieneIdiomaOperadora(ST_INFGENERAL *sthFa_InfGeneral)
{
    sprintf(sthFa_InfGeneral->szIdiomaOper ,"%-1.1s\0",szhIdiomaOper);

    return(TRUE);
}/****************Final de ObtieneIdiomaOperadora *******************/


/****************************************************************************/
/*  Funcion: int iGetMensajesNoCiclo                                        */
/*  Funcion que Obtiene los mensajes para documentos no ciclicos            */
/****************************************************************************/
int iGetMensajesNoCiclo(ST_MENSAJES_NOCICLO * stFaMensajes_NoCiclo,long lNumProceso)
{
    int  iSqlMensNoCiclo ;

    char *szModulo="iGetMensajesNoCiclo";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    iSqlMensNoCiclo = Open_MensNoCiclo(lNumProceso);

    if ( iSqlMensNoCiclo == SQLOK )
    {
        iSqlMensNoCiclo = Fetch_MensNoCiclo( stFaMensajes_NoCiclo );

        if ( iSqlMensNoCiclo == SQLOK && stFaMensajes_NoCiclo->iCantLineas >= MAX_LINEAS_MENSAJES )
        {
            vDTrazasLog  (szModulo,"\t\tMensajes No Ciclo Sobrepaso Maximo Posible" ,LOG01);
            vDTrazasError(szModulo,"\t\tMensajes No Ciclo Sobrepaso Maximo Posible" ,LOG01);
            return(FALSE);
        }
    }
    if ( (iSqlMensNoCiclo != SQLOK) && (iSqlMensNoCiclo != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo, "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        vDTrazasLog(szModulo,   "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        return(FALSE);
    }
    if ( !Close_MensNoCiclo() ) return(FALSE);

    /****************************************************/
    /* Cantidad de Mensajes no ciclo                    */
    vDTrazasLog(szModulo,"\t====> Cantidad de Mensajes no ciclo [%d]",LOG04,stFaMensajes_NoCiclo->iCantLineas);

    return(TRUE);
}/************************* Fin GetMensajesNoCiclo *************************/


int Open_MensNoCiclo ( long lNumeroProc )
{
    char *szModulo="Open_MensNoCiclo";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    lhNumAbonado= lNumeroProc; /* variagle global */

    /* EXEC SQL OPEN curMensNoCiclo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )833;
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
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curMensNoCiclo **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curMensNoCiclo **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
    }
    return(SQLCODE);
}/*********************** Final de Open_MensNoCiclo ***********************/

/****************************************************************************/
/* Funcion: int Fetch_MensNoCiclo                      */
/* Funcion que realiza Fetch en el cursor de curMensNoCiclo                 */
/****************************************************************************/
int Fetch_MensNoCiclo (ST_MENSAJES_NOCICLO * pstFaMensajes_NoCiclo)
{
    char *szModulo="Fetch_MensNoCiclo";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL
    FETCH curMensNoCiclo
    INTO :pstFaMensajes_NoCiclo->szMensajes ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )50;
    sqlstm.offset = (unsigned int  )852;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstFaMensajes_NoCiclo->szMensajes);
    sqlstm.sqhstl[0] = (unsigned long )201;
    sqlstm.sqhsts[0] = (         int  )201;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
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



    if ( (SQLCODE == SQLOK) && (SQLCODE != SQLNOTFOUND) )
        vDTrazasError(szModulo,"\t\tError en Fetch %s : %s", LOG01, szModulo, SQLERRM);
    else
        pstFaMensajes_NoCiclo->iCantLineas = sqlca.sqlerrd[2];

    return(SQLCODE);
}/*************************** Final de Fetch_MensNoCiclo ***************************/

/****************************************************************************/
/*  Funcion: int Close_MensNoCiclo(void)                                    */
/*  Funcion que cierra el cursor de curMensNoCiclo                          */
/****************************************************************************/

int Close_MensNoCiclo(void)
{
    char *szModulo="Close_MensNoCiclo";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL CLOSE curMensNoCiclo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )871;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor curMensNoCiclo: %s",LOG01, SQLERRM);
        return (FALSE);
    }
    return (TRUE);
}

/****************Final de Close_MensNoCiclo *******************/

/****************************************************************************/
/*  Funcion: int BuscaMascara                                               */
/*  Funcion que busca un Registro de la mascara                             */
/****************************************************************************/
BOOL BuscaMascara(DETALLEOPER *pstMascaraOper, char *szCodRegistro, int iTipDocum)
{
    register int x,iIndTipReg;

    char *szModulo="BuscaMascara";

    vDTrazasLog(szModulo,"\tEntrando a %s registro [%s]",LOG04,szModulo, szCodRegistro);

    switch(szCodRegistro[0]) /* primer caracter del codigo de registro */
    {
		case 'A':  /* caratula */
            iIndTipReg = 0;
        	break;
        case 'B':  /* abonados */
            iIndTipReg = 1;
            break;
        case 'D':  /* detalle de llamadas */
            iIndTipReg = 2;
            break;
    }

    vDTrazasLog(szModulo,"=> CODIGO[%s] Num_Registros [%d] Tipo Documento [%d] Tipo Ciclo [%d] Tipo Registro [%d]"
    					, LOG06, szCodRegistro
    					,pstMascaraOper->iMaxRegImp[iIndTipReg]
    					,iTipDocum
    					,iIndTipReg);

    for ( x=0; x < pstMascaraOper->iMaxRegImp[iIndTipReg] ; x++ )
    {
        vDTrazasLog(szModulo,"=> CODIGO Posicion [%d][%d][%s][%s]", 
        			LOG06,iIndTipReg,x, pstMascaraOper->szCodRegistro [iIndTipReg][x],
        			pstMascaraOper->szCodTipDocum [iIndTipReg][x]);
        if ( (strcmp(szCodRegistro,pstMascaraOper->szCodRegistro [iIndTipReg][x]) == 0) &&
             (iTipDocum == atoi (pstMascaraOper->szCodTipDocum [iIndTipReg][x])))
        {
            vDTrazasLog(szModulo,"=> CODIGO ENCONTRADO Posicion [%d][%d] ", LOG06,iIndTipReg,x);
            return(TRUE);
        }
    }

    vDTrazasLog(szModulo,"NO ENCONTRADO ", LOG04);
    return(FALSE);
}/****************Final de BuscaMascara *******************/


int BuscaCodInterfact(long lNumProceso,long lNumSecuencia,LINEACOMANDO *pst_ParamEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* varchar szCodAplic[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } szCodAplic;

    /* varchar szCodModGener[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } szCodModGener;

    /* EXEC SQL END DECLARE SECTION; */ 


    int  iCodEstadoSal;
    int  iCodEstadoEnt;
    int  iCodInterfact;

    char *szModulo="BuscaCodInterfact";

    vDTrazasLog(szModulo,"\tEntrando a %s  lNumProceso [%ld]",LOG04,szModulo,lNumProceso);

    iCodInterfact = COD_INTERFACT;
    if ( lNumProceso )
    {
        /* EXEC SQL SELECT COD_MODGENER,COD_APLIC
        INTO :szCodModGener,:szCodAplic
        FROM FA_INTERFACT
        WHERE NUM_PROCESO =:lNumProceso; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_MODGENER ,COD_APLIC into :b0,:b1  from FA_\
INTERFACT where NUM_PROCESO=:b2";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )886;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&szCodModGener;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&szCodAplic;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lNumProceso;
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
            vDTrazasLog(szModulo, "Error en SELECT de FA_INTERFACT [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
            return(FALSE);
        }
    }
    else
    {
        /* EXEC SQL SELECT DISTINCT COD_MODGENER,COD_APLIC
        INTO :szCodModGener,:szCodAplic
        FROM FA_INTERFACT
        WHERE NUM_PROCESO IN ( SELECT NUM_PROCESO
                                 FROM FA_PROCIMPRESLOTE_TD
                                WHERE NUM_SECUENCIAL = :lNumSecuencia
                             ); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select distinct COD_MODGENER ,COD_APLIC into :b0,:b1 \
 from FA_INTERFACT where NUM_PROCESO in (select NUM_PROCESO  from FA_PROCIMPRE\
SLOTE_TD where NUM_SECUENCIAL=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )913;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&szCodModGener;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&szCodAplic;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lNumSecuencia;
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
            vDTrazasLog(szModulo, "Error en SELECT de FA_PROCIMPRESLOTE_TD [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
            return(FALSE);
        }
    }


    /* EXEC SQL SELECT COD_ESTADOC_ENT,COD_ESTADOC_SAL
    INTO :iCodEstadoEnt,:iCodEstadoSal
    FROM FA_INTQUEUEPROC
    WHERE COD_MODGENER=:szCodModGener
      AND COD_PROCESO = :iCodInterfact
      AND COD_APLIC   = :szCodAplic; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_ESTADOC_ENT ,COD_ESTADOC_SAL into :b0,:b1  fro\
m FA_INTQUEUEPROC where ((COD_MODGENER=:b2 and COD_PROCESO=:b3) and COD_APLIC=\
:b4)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )940;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&iCodEstadoEnt;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&iCodEstadoSal;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&szCodModGener;
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iCodInterfact;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&szCodAplic;
    sqlstm.sqhstl[4] = (unsigned long )6;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en SELECT de FA_INTQUEUEPROC [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }

    pst_ParamEntrada->iCodEntrada = iCodEstadoEnt;
    pst_ParamEntrada->iCodSalida  = iCodEstadoSal;

    return(TRUE);
}/****************Final de BuscaCodInterfact *******************/

int ChequeaInterfact(LINEACOMANDO pst_ParamEntrada)
{
    int  iCodEstaRun;
    int  iCodEstaOk;
    int  iCantProc;

    char *szModulo="ChequeaInterfact";

    vDTrazasLog(szModulo,"\tEntrando a %s numero de proceso [%ld]"
    					,LOG04,szModulo,pst_ParamEntrada.lProceso);

    iCodEstaOk  = iPROC_EST_OK;

    /* EXEC SQL SELECT COUNT(1)
    INTO :iCantProc
    FROM FA_INTERFACT
    WHERE NUM_PROCESO = :pst_ParamEntrada.lProceso
      AND COD_ESTADOC = :pst_ParamEntrada.iCodEntrada
      AND COD_ESTPROC = :iCodEstaOk; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(1) into :b0  from FA_INTERFACT where ((NUM_P\
ROCESO=:b1 and COD_ESTADOC=:b2) and COD_ESTPROC=:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )975;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&iCantProc;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(pst_ParamEntrada.lProceso);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&(pst_ParamEntrada.iCodEntrada);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iCodEstaOk;
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



    if ( !iCantProc )
    {
        vDTrazasLog (szModulo,"numero de proceso [%ld] No esta en el estado correcto de ejecucion ",LOG04,pst_ParamEntrada.lProceso);
        return(FALSE);
    }

    vDTrazasLog (szModulo,"Entro por numero de proceso [%ld]",LOG04,pst_ParamEntrada.lProceso);

    iCodEstaRun = iPROC_EST_RUN;

    /* EXEC SQL UPDATE FA_INTERFACT
                SET COD_ESTADOC = :pst_ParamEntrada.iCodSalida, 
                    COD_ESTPROC = :iCodEstaRun
              WHERE NUM_PROCESO = :pst_ParamEntrada.lProceso; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_INTERFACT  set COD_ESTADOC=:b0,COD_ESTPROC=:b1 \
where NUM_PROCESO=:b2";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1006;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pst_ParamEntrada.iCodSalida);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&iCodEstaRun;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&(pst_ParamEntrada.lProceso);
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
        vDTrazasLog (szModulo,"Error en ejecucion de UPDATE de FA_INTERFACT [%d][%s]",LOG01,SQLCODE, SQLERRM);
        return(FALSE);
    }
    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1033;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"Error en ejecucion de COMMIT de FA_INTERFACT [%d][%s]",LOG01,SQLCODE, SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}

int OpenDetArrastre ( long lCodCiclFact )
{
    char *szModulo="OpenDetArrastre";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    lhCodCilclFact= lCodCiclFact;
    strcpy (szhStrCodCliente, "09999999");

    /* EXEC SQL OPEN curArrastre; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0002;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1048;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhStrCodCliente;
    sqlstm.sqhstl[0] = (unsigned long )9;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhStrCodCliente;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCilclFact;
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
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curArrastre **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curArrastre **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
    }
    return(SQLCODE);
}/*********************** Final de OpenDetArrastre ***********************/

/****************************************************************************/
int FetchDetArrastre ( void )
{
    char *szModulo="FetchDetArrastre";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL
    FETCH curArrastre
    INTO :sthCurArrastre.lCodCliente,
    :sthCurArrastre.lNumAbonado,
    :sthCurArrastre.szCodBolsa,
    :sthCurArrastre.dValBolsa,
    :sthCurArrastre.szIndUnidad,
    :sthCurArrastre.dValArrastre,
    :sthCurArrastre.dValExpirado,
    :sthCurArrastre.dValDisponible,
    :sthCurArrastre.dValConsumo,
    :sthCurArrastre.dValResto,
    :sthCurArrastre.szLlaveArrastre; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10000;
    sqlstm.offset = (unsigned int  )1075;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(sthCurArrastre.lCodCliente);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )sizeof(long);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(sthCurArrastre.lNumAbonado);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )sizeof(long);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(sthCurArrastre.szCodBolsa);
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )6;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(sthCurArrastre.dValBolsa);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[3] = (         int  )sizeof(double);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(sthCurArrastre.szIndUnidad);
    sqlstm.sqhstl[4] = (unsigned long )6;
    sqlstm.sqhsts[4] = (         int  )6;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(sthCurArrastre.dValArrastre);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[5] = (         int  )sizeof(double);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(sthCurArrastre.dValExpirado);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )sizeof(double);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(sthCurArrastre.dValDisponible);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )sizeof(double);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(sthCurArrastre.dValConsumo);
    sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[8] = (         int  )sizeof(double);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(sthCurArrastre.dValResto);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[9] = (         int  )sizeof(double);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(sthCurArrastre.szLlaveArrastre);
    sqlstm.sqhstl[10] = (unsigned long )17;
    sqlstm.sqhsts[10] = (         int  )17;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
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



    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo,"\t\tError en Fetch FetchDetArrastre : %s", LOG01, SQLERRM);
        return(SQLCODE);
    }
    sthCurArrastre.iCantidadArrastre = sqlca.sqlerrd[2];
    return(SQLCODE);
}
/*************************** Final de FetchDetArrastre ***************************/

/****************************************************************************/
int CloseDetArrastre(void)
{
    char *szModulo="CloseDetArrastre";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL CLOSE curArrastre; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1134;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor Arrastre: %s",LOG01, SQLERRM);
        return (FALSE);
    }
    return (TRUE);
}
/****************Final de CloseDetArrastre *******************/


/****************************************************************************/

/* SAAM-20040116 se modifica definicin funcin para que reciba el cdigo de ciclo de facturacion como parametro, proyecto TMM_DEIMP_03020 */
/* int CargaArrastre( void ) */
int CargaArrastre( long lhCodCiclFact )
{
    int  iSqlDetArrastre,i,j;
    int   rows_to_fetch  = MAX_ARRASTRE_CURSOR;  /* number of rows in each "batch" */
    int   rows_before    =  0;  /* previous value of sqlerrd[2] */
    int   rows_this_time = MAX_ARRASTRE_CURSOR;

    char *szModulo="CargaArrastre";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    iSqlDetArrastre = OpenDetArrastre(lhCodCiclFact);

    if ( iSqlDetArrastre == SQLOK )
    {
        while ( rows_this_time == rows_to_fetch )
        {
            iSqlDetArrastre = FetchDetArrastre();
            if ( (iSqlDetArrastre != SQLOK)&&(iSqlDetArrastre != SQLNOTFOUND) )
            {
                vDTrazasError(szModulo,"\t\tError en Fetch FetchDetArrastre : %s", LOG01, SQLERRM);
                return(SQLCODE);
            }

            j=0;
            for ( i=rows_before;i<sthCurArrastre.iCantidadArrastre ;i++ )
            {
                sthDetArrastre.lCodCliente[i]           = sthCurArrastre.lCodCliente[j];
                sthDetArrastre.lNumAbonado[i]           = sthCurArrastre.lNumAbonado[j];
                strcpy(sthDetArrastre.szCodBolsa[i]     , sthCurArrastre.szCodBolsa[j]);
                sthDetArrastre.dValBolsa[i]             = sthCurArrastre.dValBolsa[j];
                strcpy(sthDetArrastre.szIndUnidad[i]    , sthCurArrastre.szIndUnidad[j]);
                sthDetArrastre.dValArrastre[i]          = sthCurArrastre.dValArrastre[j];
                sthDetArrastre.dValExpirado[i]          = sthCurArrastre.dValExpirado[j];
                sthDetArrastre.dValDisponible[i]        = sthCurArrastre.dValDisponible[j];
                sthDetArrastre.dValConsumo[i]           = sthCurArrastre.dValConsumo[j];
                sthDetArrastre.dValResto[i]             = sthCurArrastre.dValResto[j];
                strcpy(sthDetArrastre.szLlaveArrastre[i], sthCurArrastre.szLlaveArrastre[j]);
                j++;
            }
            sthDetArrastre.iCantidadArrastre = i;
            if ( sthDetArrastre.iCantidadArrastre > MAX_ARRASTRE_ESTRUCTURA )
            {
                vDTrazasLog  (szModulo,"\t\tDetArrastre Sobrepaso Maximo Posible" ,LOG01);
                vDTrazasError(szModulo,"\t\tDetArrastre Sobrepaso Maximo Posible" ,LOG01);
                return(FALSE);
            }
            rows_this_time = sthCurArrastre.iCantidadArrastre - rows_before;
            rows_before = sthCurArrastre.iCantidadArrastre;
            vDTrazasLog(szModulo,"\t[%d]-[%d]-[%d]",LOG05,rows_this_time,rows_before,rows_to_fetch);
        }
    }
    if ( (iSqlDetArrastre != SQLOK) && (iSqlDetArrastre != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo, "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        vDTrazasLog(szModulo,   "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        return(FALSE);
    }
    if ( !CloseDetArrastre() ) return(FALSE);
    return(TRUE);
}/************************* Fin CargaArrastre *************************/

int Busca_RangoCliente(int iPosicion,int *iInicio,int *iTermino,int iFin)
{
    int iIndice;
    char szllave[17];
    char *szModulo="Busca_RangoCliente";

    iIndice = iPosicion;
    sprintf(szllave,"%s",sthDetArrastre.szLlaveArrastre[iPosicion]);
    vDTrazasLog(szModulo,"Busca_RangoCliente ENTRADA \t iIndice(%d) >= 0 && *iInicio(%d) == 0  Termino=%d Fin=%d llave=[%s]\n",LOG06,iIndice, *iInicio, *iTermino,iFin,szllave); /* P-TMM-03075 Por Homologacin TM-200410241013*/
    while ( iIndice >= 0 && *iInicio == 0 )
    {
        if ( strcmp(szllave,sthDetArrastre.szLlaveArrastre[iIndice])==0 )
        {
            sprintf(szllave,"%s",sthDetArrastre.szLlaveArrastre[iIndice]);
            iIndice --;
        }
        else
        {
            *iInicio = iIndice+1; break;
        }                                       /* P-TMM-03075 Por Homologacin TM-200410241013*/
    }
    if ( iIndice < 0 ) *iInicio = 0;

    iIndice = iPosicion;
    sprintf(szllave,"%s",sthDetArrastre.szLlaveArrastre[iPosicion]);
    vDTrazasLog(szModulo,"Busca_RangoCliente 2\tindice=%d Inicio=%d Termino=%d Fin=%d llave=[%s]\n",LOG06,iIndice,*iInicio,*iTermino,iFin,szllave); /* P-TMM-03075 Por Homologacin TM-200410241013*/
    while ( iIndice < iFin && *iTermino == 0 )
    {
        if ( strcmp(szllave,sthDetArrastre.szLlaveArrastre[iIndice])==0 )
        {
            sprintf(szllave,"%s",sthDetArrastre.szLlaveArrastre[iIndice]);
            iIndice ++;
        }
        else
        {
            *iTermino = iIndice-1; break;
        }                                      /* P-TMM-03075 Por Homologacin TM-200410241013*/
    }
    if ( iIndice >= iFin ) *iTermino = iFin-1;

    vDTrazasLog(szModulo,"Busca_RangoCliente SALIDA \tindice=%d Inicio=%d Termino=%d\n",LOG06,iIndice,iInicio,iTermino); /* P-TMM-03075 Por Homologacin TM-200410241013*/

    return(TRUE);
}/****************Final de Busca_RangoCliente ******************************************/

int BuscaCliente(char *szllave,int derecha)
{
    int centro;
    int izquierda;

    izquierda = 0;
    while ( izquierda <= derecha )
    {
        centro = (izquierda + derecha) / 2;
        if ( strcmp(szllave,sthDetArrastre.szLlaveArrastre[centro])<0 )
        {
            derecha = centro - 1;
        }
        else
        {
            if ( strcmp(szllave,sthDetArrastre.szLlaveArrastre[centro])>0 )
            {
                izquierda = centro + 1;
            }
            else
            {
                return(centro);
            }
        }
    }
    return(-1);
}/****************Final de BuscaCliente *******************/

int busca_arrastre(char *szllave,int *iInicio,int *iTermino)
{
    int iPosicionCliente;
    long lderecha;
    char *szModulo="busca_arrastre";

    lderecha = sthDetArrastre.iCantidadArrastre;
    vDTrazasLog(szModulo,"busca_arrastre ENTRADA \tCliente [%s] derecha=%ld",LOG06,szllave,lderecha);
    iPosicionCliente = BuscaCliente(szllave,lderecha);

    if ( iPosicionCliente != -1 )
    {
        vDTrazasLog(szModulo,"busca_arrastre 1\tPosicion del Cliente [%s] es [%d]",LOG06,szllave,iPosicionCliente);
        *iInicio=0;
        *iTermino=0;
        if ( !Busca_RangoCliente(iPosicionCliente,iInicio,iTermino,lderecha) )
        {
            vDTrazasLog(szModulo,"busca_arrastre\tCliente [%s] sin Arrastre ",LOG05,szllave);
            return(FALSE);
        }
        vDTrazasLog(szModulo,"busca_arrastre 2\tPosicion del Cliente [%s] es [%d]  Inicio=%d Termino=%d",LOG06,szllave,iPosicionCliente, *iInicio, *iTermino);
    }
    else
    {
        vDTrazasLog(szModulo,"busca_arrastre\tCliente [%s] sin Arrastre ",LOG06,szllave);
        return(FALSE);
    }
    vDTrazasLog(szModulo,"busca_arrastre SALIDA \tInicio=%d Termino=%d\n",LOG06,*iInicio, *iTermino); /* P-TMM-03075 Por Homologacin TM-200410241013*/
    return(TRUE);
}/****************Final de busca_arrastre *******************/


int CargaFadParametros( void )
{
    int i,j;
    char szTipParametro[7];
    char szCodModulo[3];
    char szValCaracter[2];

    char *szModulo="CargaFadParametros";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    ihZero = 0;
    strcpy(szTipParametro,"NUMBER");
    strcpy(szCodModulo,"FA");
    strcpy(szValCaracter,"0");

    /* EXEC SQL
    SELECT COD_PARAMETRO,
    DES_PARAMETRO,
    NVL(TIP_PARAMETRO,:szTipParametro),
    NVL(VAL_NUMERICO,:ihZero),
    NVL(VAL_CARACTER,:szValCaracter),
    NVL(VAL_FECHA,SYSDATE),
    vsize(NVL(VAL_CARACTER,:szValCaracter))
    INTO :sthFadParametros
    FROM FAD_PARAMETROS
    WHERE COD_MODULO= :szCodModulo
                      ORDER BY COD_MODULO,COD_PARAMETRO; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_PARAMETRO ,DES_PARAMETRO ,NVL(TIP_PARAMETRO,:b\
0) ,NVL(VAL_NUMERICO,:b1) ,NVL(VAL_CARACTER,:b2) ,NVL(VAL_FECHA,SYSDATE) ,vsiz\
e(NVL(VAL_CARACTER,:b2)) into :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7   from FAD_PAR\
AMETROS where COD_MODULO=:b5 order by COD_MODULO,COD_PARAMETRO ";
    sqlstm.iters = (unsigned int  )1001;
    sqlstm.offset = (unsigned int  )1149;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szTipParametro;
    sqlstm.sqhstl[0] = (unsigned long )7;
    sqlstm.sqhsts[0] = (         int  )7;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )sizeof(int);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szValCaracter;
    sqlstm.sqhstl[2] = (unsigned long )2;
    sqlstm.sqhsts[2] = (         int  )2;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szValCaracter;
    sqlstm.sqhstl[3] = (unsigned long )2;
    sqlstm.sqhsts[3] = (         int  )2;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)sthFadParametros.cod_parametro;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(int);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)sthFadParametros.des_parametro;
    sqlstm.sqhstl[5] = (unsigned long )1024;
    sqlstm.sqhsts[5] = (         int  )1024;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)sthFadParametros.tip_parametro;
    sqlstm.sqhstl[6] = (unsigned long )32;
    sqlstm.sqhsts[6] = (         int  )32;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)sthFadParametros.val_numerico;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(int);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)sthFadParametros.val_caracter;
    sqlstm.sqhstl[8] = (unsigned long )512;
    sqlstm.sqhsts[8] = (         int  )512;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)sthFadParametros.val_fecha;
    sqlstm.sqhstl[9] = (unsigned long )9;
    sqlstm.sqhsts[9] = (         int  )9;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)sthFadParametros.val_cantidad;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(int);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)szCodModulo;
    sqlstm.sqhstl[11] = (unsigned long )3;
    sqlstm.sqhsts[11] = (         int  )3;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
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



    if ( ((SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND)) || (sqlca.sqlerrd[2]==0) )
    {
        vDTrazasLog(szModulo, "Error en SELECT de FAD_PARAMETROS [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }

    for ( i = 1;i <= sqlca.sqlerrd[2];i++ )
    {
        j = sthFadParametros.cod_parametro[sqlca.sqlerrd[2]-i];
        sthFadParametros.cod_parametro[j] = sthFadParametros.cod_parametro[sqlca.sqlerrd[2]-i];
        strcpy(sthFadParametros.des_parametro[j], sthFadParametros.des_parametro[sqlca.sqlerrd[2]-i]);
        strcpy(sthFadParametros.tip_parametro[j], sthFadParametros.tip_parametro[sqlca.sqlerrd[2]-i]);
        sthFadParametros.val_numerico[j] = sthFadParametros.val_numerico[sqlca.sqlerrd[2]-i];
        strcpy(sthFadParametros.val_caracter[j], sthFadParametros.val_caracter[sqlca.sqlerrd[2]-i]);
        strcpy(sthFadParametros.val_fecha[j], sthFadParametros.val_fecha[sqlca.sqlerrd[2]-i]);
        sthFadParametros.val_cantidad[j] = sthFadParametros.val_cantidad[sqlca.sqlerrd[2]-i];

        sthFadParametros.cod_parametro[sqlca.sqlerrd[2]-i] = 0;
        memset(sthFadParametros.des_parametro[sqlca.sqlerrd[2]-i],0,sizeof(sthFadParametros.des_parametro[sqlca.sqlerrd[2]-i]));
        memset(sthFadParametros.tip_parametro[sqlca.sqlerrd[2]-i],0,sizeof(sthFadParametros.tip_parametro[sqlca.sqlerrd[2]-i]));
        sthFadParametros.val_numerico[sqlca.sqlerrd[2]-i] = 0;
        memset(sthFadParametros.val_caracter[sqlca.sqlerrd[2]-i],0,sizeof(sthFadParametros.val_caracter[sqlca.sqlerrd[2]-i]));
        memset(sthFadParametros.val_fecha[sqlca.sqlerrd[2]-i],0,sizeof(sthFadParametros.val_fecha[sqlca.sqlerrd[2]-i]));
        sthFadParametros.val_cantidad[sqlca.sqlerrd[2]-i] = 0;
    }
    return(TRUE);
}
/***********************************************************************************/
int GargaGedParametros( void )
{
    /* Modificacin Proyecto Ecu-05002 Codigo de Autorizacin.
      Se agrega SQL para obtener el campo para saber si aplica el codigo de autorizacion. Las variables
del select into estan definidas en el ImpSclSt.h. Se modifica el SQL para que en este mismo se rescate el valor
de la tabla y saber si aplica el cod autirizacion (se agrega alias F para ged_parametros).
    */

    char *szModulo="GargaGedParametros";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    strcpy(szhFormato_Hora,"HH24MISS");
    strcpy(szhFormato_Fecha,"YYYYMMDD");
    ihUno = 1;


    /* EXEC SQL
    SELECT NVL(A.VAL_PARAMETRO,:szhFormato_Hora),
    NVL(B.VAL_PARAMETRO,:szhFormato_Fecha),
    SUBSTR(C.VAL_PARAMETRO,1,5) ,
    D.VAL_PARAMETRO,
    E.COD_ABONOCEL,
    F.VAL_PARAMETRO
    INTO :szformato_hora,:szformato_fecha,:szhIdiomaOper,:szNumDecimal,:iCodAbonoCel,
    :szAplica_Cod_Autorizacion
    FROM GED_PARAMETROS A,GED_PARAMETROS B,GED_PARAMETROS C,GED_PARAMETROS D, FA_DATOSGENER E,
    GED_PARAMETROS F
    WHERE A.COD_MODULO = 'GE'   AND A.COD_PRODUCTO= :ihUno
                         AND A.NOM_PARAMETRO ='FORMATO_SEL20'
                         AND B.COD_MODULO= 'GE'   AND B.COD_PRODUCTO= :ihUno
                         AND B.NOM_PARAMETRO ='FORMATO_SEL6'
                         AND C.COD_MODULO= 'GE'   AND C.COD_PRODUCTO= :ihUno
                         AND C.NOM_PARAMETRO ='IDIOMA_LOCAL'
                         AND D.COD_MODULO= 'GE'   AND D.COD_PRODUCTO= :ihUno
                         AND D.NOM_PARAMETRO ='NUM_DECIMAL'
                         AND F.NOM_PARAMETRO = 'APLICA_CODAUTORIZA'
                         AND F.COD_MODULO = 'FA'
                         AND F.COD_PRODUCTO = :ihUno; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(A.VAL_PARAMETRO,:b0) ,NVL(B.VAL_PARAMETRO,:b1)\
 ,SUBSTR(C.VAL_PARAMETRO,1,5) ,D.VAL_PARAMETRO ,E.COD_ABONOCEL ,F.VAL_PARAMETR\
O into :b2,:b3,:b4,:b5,:b6,:b7  from GED_PARAMETROS A ,GED_PARAMETROS B ,GED_P\
ARAMETROS C ,GED_PARAMETROS D ,FA_DATOSGENER E ,GED_PARAMETROS F where (((((((\
(((((((A.COD_MODULO='GE' and A.COD_PRODUCTO=:b8) and A.NOM_PARAMETRO='FORMATO_\
SEL20') and B.COD_MODULO='GE') and B.COD_PRODUCTO=:b8) and B.NOM_PARAMETRO='FO\
RMATO_SEL6') and C.COD_MODULO='GE') and C.COD_PRODUCTO=:b8) and C.NOM_PARAMETR\
O='IDIOMA_LOCAL') and D.COD_MODULO='GE') and D.COD_PRODUCTO=:b8) and D.NOM_PAR\
AMETRO='NUM_DECIMAL') and F.NOM_PARAMETRO='APLICA_CODAUTORIZA') and F.COD_MODU\
LO='FA') and F.COD_PRODUCTO=:b8)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1212;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhFormato_Hora;
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
    sqlstm.sqhstv[2] = (unsigned char  *)szformato_hora;
    sqlstm.sqhstl[2] = (unsigned long )9;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szformato_fecha;
    sqlstm.sqhstl[3] = (unsigned long )22;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhIdiomaOper;
    sqlstm.sqhstl[4] = (unsigned long )6;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szNumDecimal;
    sqlstm.sqhstl[5] = (unsigned long )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&iCodAbonoCel;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)szAplica_Cod_Autorizacion;
    sqlstm.sqhstl[7] = (unsigned long )2;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
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
        vDTrazasLog(szModulo, "Error en SELECT de GED_PARAMETROS [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}

/*Modificación Proyecto Ecu-05002 Codigo de Autorización.
  Se crea funcion szfnObtiene Cod_autorizacion que es llamada cuando aplica Codigo Autorizacion. 
  Esta funcion rescata el valor del codigo de autorizacion y dejarlo disponible para imprimirlo 
  en el documento.
  Se debe diferenciar entre los documentos ciclicos y los no ciclicos.
  ECU-10012 Se modifica función para recuperar Fecha Inicio Código Autorización.
*/
/***********************************************************************************/
int szfnObtieneCod_autorizacion (LINEACOMANDO * ParametrosEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long    lhCodCiclFact;
    char    szhCodAutorizacion[11];/* EXEC SQL VAR szhCodAutorizacion IS STRING(11); */ 

    char    szhFecVencimiento [10];/* EXEC SQL VAR szhFecVencimiento  IS STRING(10); */ 

    char    szhFecInicio      [10];/* EXEC SQL VAR szhFecInicio       IS STRING(10); */ 
 /* ECU-10012 */
    /* EXEC SQL END DECLARE SECTION; */ 


    int iCont = 0;

    char *szModulo="ObtieneCod_autorizacion";

    vDTrazasLog(szModulo,"\tEntrando a [%s] ",LOG04,szModulo);

    strcpy(szhFormato_Fecha,"YYYYMMDD");

    if ( ParametrosEntrada->lCodCiclFact )
    {
        lhCodCiclFact = ParametrosEntrada->lCodCiclFact;

        /* EXEC SQL
        SELECT 
			A.COD_AUTORIZACION, 
			NVL((TO_CHAR(A.FEC_TERMINO,:szhFormato_Fecha)),' '),
			NVL((TO_CHAR(A.FEC_DESDE,:szhFormato_Fecha)),' ')    /o ECU-10012 o/
        INTO
			:szhCodAutorizacion,
			:szhFecVencimiento,
			:szhFecInicio       /o ECU-10012 o/
        FROM
			AL_AUTORIZACION_FOLIO_TD A,
			FA_CICLFACT B
        WHERE 
			B.COD_CICLFACT = :lhCodCiclFact
			AND B.FEC_EMISION BETWEEN A.FEC_DESDE AND A.FEC_TERMINO                         
			AND A.COD_SISTEMA = 'E'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select A.COD_AUTORIZACION ,NVL(TO_CHAR(A.FEC_TERMINO,\
:b0),' ') ,NVL(TO_CHAR(A.FEC_DESDE,:b0),' ') into :b2,:b3,:b4  from AL_AUTORIZ\
ACION_FOLIO_TD A ,FA_CICLFACT B where ((B.COD_CICLFACT=:b5 and B.FEC_EMISION b\
etween A.FEC_DESDE and A.FEC_TERMINO) and A.COD_SISTEMA='E')";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1279;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
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
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodAutorizacion;
        sqlstm.sqhstl[2] = (unsigned long )11;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhFecVencimiento;
        sqlstm.sqhstl[3] = (unsigned long )10;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhFecInicio;
        sqlstm.sqhstl[4] = (unsigned long )10;
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



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog(szModulo, "No se encontro Cod_autorizacion Electronico\n", LOG04);
        }
        else
	{
	    strcpy(stAutorizFolio_E.szCodAutorizacion,szhCodAutorizacion);
	    strcpy(stAutorizFolio_E.szFechaVencimiento,szhFecVencimiento);
	    strcpy(stAutorizFolio_E.szFechaInicio,szhFecInicio); /* ECU-10012 */		
	    iCont ++;
	}

	/* EXEC SQL
	     SELECT
			A.COD_AUTORIZACION,
			NVL((TO_CHAR(A.FEC_TERMINO,:szhFormato_Fecha)),' '),
			NVL((TO_CHAR(A.FEC_DESDE,:szhFormato_Fecha)),' ')   /o ECU-10012 o/
		INTO
			:szhCodAutorizacion,
			:szhFecVencimiento,
			:szhFecInicio       /o ECU-10012 o/
		FROM
			AL_AUTORIZACION_FOLIO_TD A,
			FA_CICLFACT B
		WHERE
			B.COD_CICLFACT = :lhCodCiclFact
			AND B.FEC_EMISION BETWEEN A.FEC_DESDE AND A.FEC_TERMINO
			AND A.COD_SISTEMA = 'F'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select A.COD_AUTORIZACION ,NVL(TO_CHAR(A.FEC_TERMINO,:b0),' \
') ,NVL(TO_CHAR(A.FEC_DESDE,:b0),' ') into :b2,:b3,:b4  from AL_AUTORIZACION_F\
OLIO_TD A ,FA_CICLFACT B where ((B.COD_CICLFACT=:b5 and B.FEC_EMISION between \
A.FEC_DESDE and A.FEC_TERMINO) and A.COD_SISTEMA='F')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1318;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
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
 sqlstm.sqhstv[2] = (unsigned char  *)szhCodAutorizacion;
 sqlstm.sqhstl[2] = (unsigned long )11;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szhFecVencimiento;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)szhFecInicio;
 sqlstm.sqhstl[4] = (unsigned long )10;
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



	if ( SQLCODE != SQLOK )
	{
             vDTrazasLog(szModulo, "No se encontro Cod_autorizacion Fisico\n", LOG04);	     
	}
	else
	{
	     strcpy(stAutorizFolio.szCodAutorizacion,szhCodAutorizacion);
	     strcpy(stAutorizFolio.szFechaVencimiento,szhFecVencimiento);
	     strcpy(stAutorizFolio.szFechaInicio,szhFecInicio); /* ECU-10012 */			
	     iCont++;
	}
       
        if (iCont == 0) return (FALSE);

        return(TRUE);
    }
    else
    {
        /* EXEC SQL
        SELECT
			A.COD_AUTORIZACION,
			NVL((TO_CHAR(A.FEC_TERMINO,:szhFormato_Fecha)),' '),
			NVL((TO_CHAR(A.FEC_DESDE,:szhFormato_Fecha)),' ')   /o ECU-10012 o/
        INTO
			:szhCodAutorizacion,
			:szhFecVencimiento,
			:szhFecInicio		/o ECU-10012 o/
        FROM
			AL_AUTORIZACION_FOLIO_TD A
        WHERE
			SYSDATE BETWEEN A.FEC_DESDE AND A.FEC_TERMINO
			AND A.COD_SISTEMA = 'F'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select A.COD_AUTORIZACION ,NVL(TO_CHAR(A.FEC_TERMINO,\
:b0),' ') ,NVL(TO_CHAR(A.FEC_DESDE,:b0),' ') into :b2,:b3,:b4  from AL_AUTORIZ\
ACION_FOLIO_TD A where (SYSDATE between A.FEC_DESDE and A.FEC_TERMINO and A.CO\
D_SISTEMA='F')";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1357;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
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
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodAutorizacion;
        sqlstm.sqhstl[2] = (unsigned long )11;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhFecVencimiento;
        sqlstm.sqhstl[3] = (unsigned long )10;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhFecInicio;
        sqlstm.sqhstl[4] = (unsigned long )10;
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



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog(szModulo, "Else: Error en SELECT de ObtieneCod_autorizacion [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
            return(FALSE);
        }

        strcpy(stAutorizFolio.szCodAutorizacion,szhCodAutorizacion);
        strcpy(stAutorizFolio.szFechaVencimiento,szhFecVencimiento);
        strcpy(stAutorizFolio.szFechaInicio,szhFecInicio); /* ECU-10012 */

        return(TRUE);

    }

}

/***********************************************************************************/
int OpenFactDocuClie (LINEACOMANDO *ParEnt)
{
    char  szTabla1    [50]    ="";
    char  szTabla2    [50]    ="";
    char  szTabla3    [350]   ="";
    char  szCadenaSQL [2500]  ="";
    char  szJoinJob   [350]   ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char  *szhCodDespacho;
    int   ihCodSalida;
    long  lhProceso;
    int   ihCodEstProc;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="OpenFactDocuClie";

    gihCodTipDocum  = ParEnt->iCodTipDocum ;
    szhCodDespacho = ParEnt->szCodDespacho;
    ihCodSalida    = ParEnt->iCodSalida;
    lhProceso      = ParEnt->lProceso;

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    if ( !ParEnt->iTipoCiclo )
    {
        if ( !lNroJob )
        {
            sprintf(szTabla1,"FA_FACTDOCU_%ld",ParEnt->lCodCiclFact);
            sprintf(szTabla2,"FA_FACTCLIE_%ld",ParEnt->lCodCiclFact);
        }
        else
        {
            sprintf(szTabla1,"FA_FACTDOCU_%ld_%ld",ParEnt->lCodCiclFact,lNroJob);
            sprintf(szTabla2,"FA_FACTCLIE_%ld_%ld",ParEnt->lCodCiclFact,lNroJob);
	        sprintf(szJoinJob,"\n  AND EXISTS (SELECT 1 FROM FA_CLIENTEJOB_TO J "
	                          "\n               WHERE J.NUM_JOB         = %ld   "
	                          "\n                 AND J.COD_CLIENTE    = A.COD_CLIENTE )"
	                ,lNroJob);
        }

        sprintf(szCadenaSQL,"SELECT"
                "\n A.ROWID,"
                "\n A.IND_ORDENTOTAL,"
                "\n A.COD_CLIENTE,"
                "\n NVL(A.NUM_CTC,0),"
                "\n TO_CHAR(A.FEC_EMISION,'YYYYMMDD'),"
                "\n TO_CHAR(NVL(A.FEC_VENCIMIE,SYSDATE),'YYYYMMDD'),"
                "\n NVL(A.COD_DESPACHO,'DESNO'),"
                "\n NVL(D.NOM_HEADER,' '),"
                "\n A.COD_TIPDOCUM,"
                "\n A.NUM_FOLIO,"
                "\n C.COD_GENARCH,"
                "\n C.COD_PRIORIDAD,"
                "\n A.TOT_FACTURA,"
                "\n NVL(B.NUM_IDENTTRIB,''),"
                "\n B.NOM_CLIENTE||' '||B.NOM_APECLIEN1||' '||B.NOM_APECLIEN2,"
                "\n A.TOT_CARGOSME,"
                "\n NVL(A.IMP_SALDOANT,0),"
                "\n A.TOT_PAGAR,"
                "\n DECODE(B.IND_DEBITO,'A','1','0'),"
                "\n A.TOT_CUOTAS,"
                "\n NVL(TRIM(B.COD_IDIOMA),'1'),"
                "\n A.NUM_PROCESO,"
                "\n A.PREF_PLAZA,"
                "\n A.COD_OPERADORA,"
                "\n A.COD_PLAZA,"
                "\n A.COD_OFICINA,"
                "\n A.COD_VENDEDOR,"
                "\n A.NOM_USUARORA,"
                "\n E.COD_OPERPLAZA,"
                "\n A.COD_MONEDAIMP, "
                "\n A.IMP_CONVERSION, "
                "\n NVL(A.NUM_SECUREL,0), "
                "\n A.LETRAREL, "
                "\n NVL(A.COD_TIPDOCUMREL,0), "
                "\n NVL(A.COD_VENDEDOR_AGENTEREL,0), "
                "\n NVL(A.COD_CENTRREL,0), "
                "\n NVL(A.NUM_VENTA,0), "
                "\n G.COD_CATEGORIA, "
                "\n NVL(G.NOM_APODERADO,'.'), "
                "\n NVL(H.COD_ZONA,'.'), "
                "\n NVL(G.COD_SISPAGO, 1), "
               /*P-ECU-10004BE*/
	               "\n       NVL(A.TIP_DISTRIBUCION,'F'), "
	               "\n       NVL(A.EMAIL_PRINCIPAL,'SIN INFORMACION'), "
	               "\n       NVL(A.EMAIL_ALTERNO,'SIN INFORMACION'), "
	               "\n       NVL(G.ID_SEGMENTO, 0), "
	               "\n       TO_CHAR(NVL(G.FEC_ALTA,SYSDATE),'YYYYMMDD'), "
               /*P-ECU-10004BE*/
               "G.COD_TIPIDENT " /* Inc-pre-189124  */
                "\nFROM"
                "\n %s A,"
                "\n %s B,"
                "\n FA_CODESPACHO C,"
                "\n FA_PARGENARCH D,"
                "\n GE_OPERPLAZA_TD E,"
                "\n GE_CLIENTES G, "
                "\n FA_ZONACOURIER_TD H "
                "\nWHERE A.TOT_FACTURA   >= 0"
                "\n  AND A.COD_CLIENTE   >= 0"
                "\n  AND A.NUM_FOLIO     >= 0"
                "\n  AND A.IND_SUPERTEL   = 0"
                "\n  AND A.IND_ANULADA    = 0"
                "\n  AND A.IND_FACTUR     = 1"
                "\n  AND A.IND_IMPRESA    = 0"
                "\n  AND A.COD_TIPDOCUM   = :gihCodTipDocum"
                "\n  AND A.COD_DESPACHO   = :szhCodDespacho"
                "\n  AND B.IND_ORDENTOTAL = A.IND_ORDENTOTAL"
                "\n  AND C.COD_DESPACHO   = NVL(A.COD_DESPACHO,'DESNO')"
                "\n  AND D.COD_GENARCH(+) = C.COD_GENARCH"
                "\n  AND A.COD_OPERADORA  = E.COD_OPERADORA_SCL"
                "\n  AND A.COD_PLAZA      = E.COD_PLAZA"
                "\n  AND G.COD_CLIENTE    = A.COD_CLIENTE "
                "\n  AND H.COD_CLIENTE(+) = A.COD_CLIENTE "
                "%s"
                "\nORDER BY"
                "\n A.COD_TIPDOCUM,"
                "\n C.COD_GENARCH,"
                "\n A.COD_DESPACHO,"
                "\n NVL(H.COD_ZONA,'.'),"
                "\n A.COD_CLIENTE,"
                "\n A.IND_ORDENTOTAL"
                ,szTabla1
                ,szTabla2
                ,szJoinJob);
    }
    else
    {
        sprintf(szTabla1,"FA_FACTDOCU_NOCICLO");
        sprintf(szTabla2,"FA_FACTCLIE_NOCICLO");
        sprintf(szTabla3,"(SELECT NUM_PROCESO FROM FA_INTERFACT "
                "\n WHERE COD_ESTADOC=:ihCodSalida AND COD_ESTPROC=:ihCodEstProd "
                "\n AND NUM_PROCESO = :lhProceso )"
               );

        sprintf(szCadenaSQL,"SELECT"
                "\n A.ROWID,"
                "\n A.IND_ORDENTOTAL,"
                "\n A.COD_CLIENTE,"
                "\n NVL(A.NUM_CTC,0),"
                "\n TO_CHAR(A.FEC_EMISION,'YYYYMMDD'),"
                "\n TO_CHAR(NVL(A.FEC_VENCIMIE,SYSDATE),'YYYYMMDD'),"
                "\n NVL(A.COD_DESPACHO,'DESNO'),"
                "\n NVL(D.NOM_HEADER,' '),"
                "\n A.COD_TIPDOCUM,"
                "\n A.NUM_FOLIO,"
                "\n C.COD_GENARCH,"
                "\n C.COD_PRIORIDAD,"
                "\n A.TOT_FACTURA,"
                "\n NVL(B.NUM_IDENTTRIB,''),"
                "\n B.NOM_CLIENTE||' '||B.NOM_APECLIEN1||' '||B.NOM_APECLIEN2,"
                "\n A.TOT_CARGOSME,"
                "\n NVL(A.IMP_SALDOANT,0),"
                "\n A.TOT_PAGAR,"
                "\n DECODE(B.IND_DEBITO,'A','1','0'),"
                "\n A.TOT_CUOTAS,"
                "\n NVL(B.COD_IDIOMA,'1'),"
                "\n A.NUM_PROCESO,"
                "\n A.PREF_PLAZA, "                 /* P-TMM-03083*/
                "\n A.COD_OPERADORA,"
                "\n A.COD_PLAZA,"
                "\n A.COD_OFICINA,"
                "\n A.COD_VENDEDOR,"
                "\n A.NOM_USUARORA,"
                "\n F.COD_OPERPLAZA,"
                "\n A.COD_MONEDAIMP, "
                "\n NVL(A.IMP_CONVERSION,1), "
                "\n NVL(A.NUM_SECUREL,0), "
                "\n NVL(A.LETRAREL,' '), "
                "\n NVL(A.COD_TIPDOCUMREL,0), "
                "\n NVL(A.COD_VENDEDOR_AGENTEREL,0), "
                "\n NVL(A.COD_CENTRREL,0), "
                "\n NVL(A.NUM_VENTA,0), "
                "\n G.COD_CATEGORIA, "
                "\n NVL(G.NOM_APODERADO,'.'), "
                "\n NVL(H.COD_ZONA,'.'), "
                "\n NVL(G.COD_SISPAGO, 1), "
           /*P-ECU-10004BE*/
               "\n       NVL(A.TIP_DISTRIBUCION,'F'), "
               "\n       NVL(A.EMAIL_PRINCIPAL,'SIN INFORMACION'), "
               "\n       NVL(A.EMAIL_ALTERNO,'SIN INFORMACION'), "
               "\n       NVL(G.ID_SEGMENTO, 0), "
               "\n       TO_CHAR(NVL(G.FEC_ALTA,SYSDATE),'YYYYMMDD'), "
           /*P-ECU-10004BE*/
               "G.COD_TIPIDENT " /* Inc-pre-189124  */
                "\nFROM"
                "\n %s A,"
                "\n %s B,"
                "\n FA_CODESPACHO C,"
                "\n FA_PARGENARCH D,"
                "\n %s E,"
                "\n GE_OPERPLAZA_TD F, "
                "\n GE_CLIENTES G, "
                "\n FA_ZONACOURIER_TD H "
                "\nWHERE A.NUM_PROCESO = E.NUM_PROCESO"
                "\n  AND B.IND_ORDENTOTAL = A.IND_ORDENTOTAL"
                "\n  AND C.COD_DESPACHO   = NVL(A.COD_DESPACHO,'DESNO')"
                "\n  AND D.COD_GENARCH(+) = C.COD_GENARCH"
                "\n  AND A.COD_OPERADORA  = F.COD_OPERADORA_SCL"
                "\n  AND A.COD_PLAZA      = F.COD_PLAZA"
                "\n  AND G.COD_CLIENTE    = A.COD_CLIENTE "
                "\n  AND H.COD_CLIENTE(+) = A.COD_CLIENTE "
                "\nORDER BY"
                "\n A.COD_TIPDOCUM,"
                "\n C.COD_GENARCH,"
                "\n A.COD_DESPACHO,"
                "\n NVL(H.COD_ZONA,'.'),"
                "\n A.COD_CLIENTE,"
                "\n A.IND_ORDENTOTAL"
                ,szTabla1
                ,szTabla2
                ,szTabla3);
    }
    vDTrazasLog( szModulo,"=> query(\n%s\n)",LOG05,szCadenaSQL);

    /* EXEC SQL PREPARE sql_Facturas_DetLlam FROM :szCadenaSQL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1392;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
    sqlstm.sqhstl[0] = (unsigned long )2500;
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
        vDTrazasLog (szModulo, "Error en PREPARE sql_Facturas_DetLlam. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
        return(FALSE);
    }

    /* EXEC SQL DECLARE curFactDocu2 CURSOR FOR sql_Facturas_DetLlam; */ 

    if ( SQLCODE < SQLOK )
    {
        vDTrazasLog (szModulo, "Error en DECLARE. curFactDocu2. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
        return(FALSE);
    }

    if ( !ParEnt->iTipoCiclo )
    {
        /* EXEC SQL OPEN curFactDocu2 USING :gihCodTipDocum, :szhCodDespacho ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1411;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&gihCodTipDocum;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhCodDespacho;
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
        ihCodEstProc=iPROC_EST_RUN;
        /* EXEC SQL OPEN curFactDocu2 USING :ihCodSalida, :ihCodEstProc, :lhProceso; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1434;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodSalida;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&ihCodEstProc;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhProceso;
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


    }

    if ( SQLCODE < SQLOK )
    {
        vDTrazasLog (szModulo, "Error en OPEN curFactDocu2. Error [%i][%s]",LOG00,  SQLCODE, SQLERRM);
        return(FALSE);
    }
    return(TRUE);

}/**************************** Final OpenFactDocuClie ****************************/


int FetchFactDocuClie( int * iPaso, int * iLeidos)
{
    int i;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char    szhRowid              [BUFF_CLIENTE] [19];
    static long    lhIndOrdenTotal       [BUFF_CLIENTE]     ;
    static long    lhCodCliente          [BUFF_CLIENTE]     ;
    static char    szhNumCtc             [BUFF_CLIENTE] [13];
    static char    szhFecEmision         [BUFF_CLIENTE] [9] ;
    static char    szhFecVencimie        [BUFF_CLIENTE] [9] ;
    static char    szhCodDespacho        [BUFF_CLIENTE] [6] ;
    static char    szhNomHeader          [BUFF_CLIENTE] [6] ;
    static int     ihCodTipDocum         [BUFF_CLIENTE]     ;
    static long    lhNum_Folio           [BUFF_CLIENTE]     ;
    static char    szhCodGenArch         [BUFF_CLIENTE] [3] ;
    static int     ihCodPrioridad        [BUFF_CLIENTE]     ;
    static double  dhTotFactura          [BUFF_CLIENTE]     ;
    static char    szhRut_Cliente        [BUFF_CLIENTE] [21];
    static char    szhNom_Cliente        [BUFF_CLIENTE] [93];
    static double  dhTotCargosMes        [BUFF_CLIENTE]     ;
    static double  dhImpSaldoAnt         [BUFF_CLIENTE]     ;
    static double  dhTotPagar            [BUFF_CLIENTE]     ;
    static char    szhIndDebito          [BUFF_CLIENTE] [20];
    static double  dhTotCuotas           [BUFF_CLIENTE]     ;
    static char    szhCodIdioma          [BUFF_CLIENTE] [6] ;
    static long    lhNumProceso          [BUFF_CLIENTE]     ;
    static char    szhPrefPlaza          [BUFF_CLIENTE] [11];
    static char    szhCodOperadora       [BUFF_CLIENTE] [6] ;
    static char    szhCodPlaza           [BUFF_CLIENTE] [6] ;
    static char    szhCodOficina         [BUFF_CLIENTE] [3] ;
    static long    lhCodVendedor         [BUFF_CLIENTE]     ;
    static char    szhNomUsuarora        [BUFF_CLIENTE] [31];
    static int     ihCodOperPlaza        [BUFF_CLIENTE]     ;
    static char    szhCodMonedaImp       [BUFF_CLIENTE][3]  ;
    static double  dhImpConversion       [BUFF_CLIENTE]     ;
    static long    lhNumSecuRel          [BUFF_CLIENTE]     ;
    static char    szhLetraRel           [BUFF_CLIENTE][2]  ;
    static int     ihCodTipDocumRel      [BUFF_CLIENTE]     ;
    static long    lhCodVendedorAgRel    [BUFF_CLIENTE]     ;
    static long    lhCodCentrRel         [BUFF_CLIENTE]     ;
    static long    lhNumVenta            [BUFF_CLIENTE]     ;
    static long    lhCodCategoria        [BUFF_CLIENTE]     ;
    static char    szhNomApoderado       [BUFF_CLIENTE][40] ;
    static char    szhCodZona            [BUFF_CLIENTE][15] ;
    short          i_hIndLetraRel        [BUFF_CLIENTE]     ;
    static int     ihCodSisPago          [BUFF_CLIENTE]     ;
    /*ecu 10004 PCRV*/
	    static char    szhTipDistribucion    [BUFF_CLIENTE][2]  ;
	    static char    szhEmailPrincipal     [BUFF_CLIENTE][256];
	    static char    szhEmailAlterno       [BUFF_CLIENTE][256];
	    static long		 lIdSegmento           [BUFF_CLIENTE]     ;
	    static char		 szFecAlta             [BUFF_CLIENTE][15];
    /*ecu 10004 PCRV*/
    char           szhCod_tipident           [BUFF_CLIENTE][3]; /* Inc-pre-189124  */
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="FetchFactDocuClie";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    memset(szhRowid             ,0,sizeof( szhRowid             ));
    memset(lhIndOrdenTotal      ,0,sizeof( lhIndOrdenTotal      ));
    memset(lhCodCliente         ,0,sizeof( lhCodCliente         ));
    memset(szhNumCtc            ,0,sizeof( szhNumCtc            ));
    memset(szhFecEmision        ,0,sizeof( szhFecEmision        ));
    memset(szhFecVencimie       ,0,sizeof( szhFecVencimie       ));
    memset(szhCodDespacho       ,0,sizeof( szhCodDespacho       ));
    memset(szhNomHeader         ,0,sizeof( szhNomHeader         ));
    memset(ihCodTipDocum        ,0,sizeof( ihCodTipDocum        ));
    memset(lhNum_Folio          ,0,sizeof( lhNum_Folio          ));
    memset(szhCodGenArch        ,0,sizeof( szhCodGenArch        ));
    memset(ihCodPrioridad       ,0,sizeof( ihCodPrioridad       ));
    memset(dhTotFactura         ,0,sizeof( dhTotFactura         ));
    memset(szhRut_Cliente       ,0,sizeof( szhRut_Cliente       ));
    memset(szhNom_Cliente       ,0,sizeof( szhNom_Cliente       ));
    memset(dhTotCargosMes       ,0,sizeof( dhTotCargosMes       ));
    memset(dhImpSaldoAnt        ,0,sizeof( dhImpSaldoAnt        ));
    memset(dhTotPagar           ,0,sizeof( dhTotPagar           ));
    memset(szhIndDebito         ,0,sizeof( szhIndDebito         ));
    memset(dhTotCuotas          ,0,sizeof( dhTotCuotas          ));
    memset(szhCodIdioma         ,0,sizeof( szhCodIdioma         ));
    memset(lhNumProceso         ,0,sizeof( lhNumProceso         ));
    memset(szhPrefPlaza         ,0,sizeof( szhPrefPlaza         ));
    memset(szhCodOperadora      ,0,sizeof( szhCodOperadora      ));
    memset(szhCodPlaza          ,0,sizeof( szhCodPlaza          ));
    memset(szhCodOficina        ,0,sizeof( szhCodOficina        ));
    memset(lhCodVendedor        ,0,sizeof( lhCodVendedor        ));
    memset(szhNomUsuarora       ,0,sizeof( szhNomUsuarora       ));
    memset(ihCodOperPlaza       ,0,sizeof( ihCodOperPlaza       ));
    memset(ihCodOperPlaza       ,0,sizeof( ihCodOperPlaza       ));
    memset(szhCodMonedaImp      ,0,sizeof( szhCodMonedaImp      ));
    memset(dhImpConversion      ,0,sizeof( dhImpConversion      ));
    memset(lhNumSecuRel         ,0,sizeof( lhNumSecuRel         ));
    memset(szhLetraRel          ,0,sizeof( szhLetraRel          ));
    memset(ihCodTipDocumRel     ,0,sizeof( ihCodTipDocumRel     ));
    memset(lhCodVendedorAgRel   ,0,sizeof( lhCodVendedorAgRel   ));
    memset(lhCodCentrRel        ,0,sizeof( lhCodCentrRel        ));
    memset(lhNumVenta           ,0,sizeof( lhNumVenta           ));
    memset(lhCodCategoria       ,0,sizeof( lhCodCategoria       ));
    memset(szhNomApoderado      ,0,sizeof( szhNomApoderado      ));
    memset(szhCodZona           ,0,sizeof( szhCodZona           ));
    memset(ihCodSisPago         ,0,sizeof( ihCodSisPago         ));

   /*ecu 10004 PCRV*/
    memset(szhTipDistribucion   ,0,sizeof( szhTipDistribucion   ));
    memset(szhEmailPrincipal    ,0,sizeof( szhEmailPrincipal    ));
    memset(szhEmailAlterno      ,0,sizeof( szhEmailAlterno      ));
    memset(lIdSegmento          ,0,sizeof( lIdSegmento      ));
    memset(szFecAlta    		,0,sizeof( szFecAlta      ));
   /*ecu 10004 PCRV*/
    memset(szhCod_tipident      ,0,sizeof( szhCod_tipident      )); /* Inc-pre-189124  */
    
    /* EXEC SQL FETCH curFactDocu2
    INTO    :szhRowid        ,
    :lhIndOrdenTotal ,
    :lhCodCliente    ,
    :szhNumCtc       ,
    :szhFecEmision   ,
    :szhFecVencimie  ,
    :szhCodDespacho  ,
    :szhNomHeader    ,
    :ihCodTipDocum   ,
    :lhNum_Folio     ,
    :szhCodGenArch   ,
    :ihCodPrioridad  ,
    :dhTotFactura    ,
    :szhRut_Cliente  ,
    :szhNom_Cliente  ,
    :dhTotCargosMes  ,
    :dhImpSaldoAnt   ,
    :dhTotPagar      ,
    :szhIndDebito    ,
    :dhTotCuotas     ,
    :szhCodIdioma    ,
    :lhNumProceso    ,
    :szhPrefPlaza    ,
    :szhCodOperadora ,
    :szhCodPlaza     ,
    :szhCodOficina   ,
    :lhCodVendedor   ,
    :szhNomUsuarora  ,
    :ihCodOperPlaza  ,
    :szhCodMonedaImp ,
    :dhImpConversion ,
    :lhNumSecuRel    ,
    :szhLetraRel :i_hIndLetraRel,
    :ihCodTipDocumRel,
    :lhCodVendedorAgRel,
    :lhCodCentrRel,
    :lhNumVenta,
    :lhCodCategoria,
    :szhNomApoderado,
    :szhCodZona,
    :ihCodSisPago,
    /oecu 10004 PCRVo/
	    :szhTipDistribucion,
	    :szhEmailPrincipal,
	    :szhEmailAlterno,
	    :lIdSegmento,
	    :szFecAlta,
    /oecu 10004 PCRVo/
    :szhCod_tipident; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )5000;
    sqlstm.offset = (unsigned int  )1461;
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
    sqlstm.sqhstv[1] = (unsigned char  *)lhIndOrdenTotal;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )sizeof(long);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)lhCodCliente;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )sizeof(long);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhNumCtc;
    sqlstm.sqhstl[3] = (unsigned long )13;
    sqlstm.sqhsts[3] = (         int  )13;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecEmision;
    sqlstm.sqhstl[4] = (unsigned long )9;
    sqlstm.sqhsts[4] = (         int  )9;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhFecVencimie;
    sqlstm.sqhstl[5] = (unsigned long )9;
    sqlstm.sqhsts[5] = (         int  )9;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[6] = (unsigned long )6;
    sqlstm.sqhsts[6] = (         int  )6;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)szhNomHeader;
    sqlstm.sqhstl[7] = (unsigned long )6;
    sqlstm.sqhsts[7] = (         int  )6;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)ihCodTipDocum;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(int);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)lhNum_Folio;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[9] = (         int  )sizeof(long);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)szhCodGenArch;
    sqlstm.sqhstl[10] = (unsigned long )3;
    sqlstm.sqhsts[10] = (         int  )3;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)ihCodPrioridad;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(int);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)dhTotFactura;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )sizeof(double);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)szhRut_Cliente;
    sqlstm.sqhstl[13] = (unsigned long )21;
    sqlstm.sqhsts[13] = (         int  )21;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)szhNom_Cliente;
    sqlstm.sqhstl[14] = (unsigned long )93;
    sqlstm.sqhsts[14] = (         int  )93;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)dhTotCargosMes;
    sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )sizeof(double);
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqharc[15] = (unsigned long  *)0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)dhImpSaldoAnt;
    sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )sizeof(double);
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqharc[16] = (unsigned long  *)0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)dhTotPagar;
    sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[17] = (         int  )sizeof(double);
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqharc[17] = (unsigned long  *)0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)szhIndDebito;
    sqlstm.sqhstl[18] = (unsigned long )20;
    sqlstm.sqhsts[18] = (         int  )20;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqharc[18] = (unsigned long  *)0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)dhTotCuotas;
    sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[19] = (         int  )sizeof(double);
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqharc[19] = (unsigned long  *)0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)szhCodIdioma;
    sqlstm.sqhstl[20] = (unsigned long )6;
    sqlstm.sqhsts[20] = (         int  )6;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqharc[20] = (unsigned long  *)0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)lhNumProceso;
    sqlstm.sqhstl[21] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[21] = (         int  )sizeof(long);
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqharc[21] = (unsigned long  *)0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[22] = (unsigned long )11;
    sqlstm.sqhsts[22] = (         int  )11;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqharc[22] = (unsigned long  *)0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)szhCodOperadora;
    sqlstm.sqhstl[23] = (unsigned long )6;
    sqlstm.sqhsts[23] = (         int  )6;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqharc[23] = (unsigned long  *)0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)szhCodPlaza;
    sqlstm.sqhstl[24] = (unsigned long )6;
    sqlstm.sqhsts[24] = (         int  )6;
    sqlstm.sqindv[24] = (         short *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqharc[24] = (unsigned long  *)0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)szhCodOficina;
    sqlstm.sqhstl[25] = (unsigned long )3;
    sqlstm.sqhsts[25] = (         int  )3;
    sqlstm.sqindv[25] = (         short *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqharc[25] = (unsigned long  *)0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)lhCodVendedor;
    sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[26] = (         int  )sizeof(long);
    sqlstm.sqindv[26] = (         short *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqharc[26] = (unsigned long  *)0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)szhNomUsuarora;
    sqlstm.sqhstl[27] = (unsigned long )31;
    sqlstm.sqhsts[27] = (         int  )31;
    sqlstm.sqindv[27] = (         short *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqharc[27] = (unsigned long  *)0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)ihCodOperPlaza;
    sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )sizeof(int);
    sqlstm.sqindv[28] = (         short *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqharc[28] = (unsigned long  *)0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (unsigned char  *)szhCodMonedaImp;
    sqlstm.sqhstl[29] = (unsigned long )3;
    sqlstm.sqhsts[29] = (         int  )3;
    sqlstm.sqindv[29] = (         short *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned long )0;
    sqlstm.sqharc[29] = (unsigned long  *)0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (unsigned char  *)dhImpConversion;
    sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[30] = (         int  )sizeof(double);
    sqlstm.sqindv[30] = (         short *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned long )0;
    sqlstm.sqharc[30] = (unsigned long  *)0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (unsigned char  *)lhNumSecuRel;
    sqlstm.sqhstl[31] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[31] = (         int  )sizeof(long);
    sqlstm.sqindv[31] = (         short *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned long )0;
    sqlstm.sqharc[31] = (unsigned long  *)0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (unsigned char  *)szhLetraRel;
    sqlstm.sqhstl[32] = (unsigned long )2;
    sqlstm.sqhsts[32] = (         int  )2;
    sqlstm.sqindv[32] = (         short *)i_hIndLetraRel;
    sqlstm.sqinds[32] = (         int  )sizeof(short);
    sqlstm.sqharm[32] = (unsigned long )0;
    sqlstm.sqharc[32] = (unsigned long  *)0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (unsigned char  *)ihCodTipDocumRel;
    sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[33] = (         int  )sizeof(int);
    sqlstm.sqindv[33] = (         short *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned long )0;
    sqlstm.sqharc[33] = (unsigned long  *)0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (unsigned char  *)lhCodVendedorAgRel;
    sqlstm.sqhstl[34] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[34] = (         int  )sizeof(long);
    sqlstm.sqindv[34] = (         short *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned long )0;
    sqlstm.sqharc[34] = (unsigned long  *)0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (unsigned char  *)lhCodCentrRel;
    sqlstm.sqhstl[35] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[35] = (         int  )sizeof(long);
    sqlstm.sqindv[35] = (         short *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned long )0;
    sqlstm.sqharc[35] = (unsigned long  *)0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (unsigned char  *)lhNumVenta;
    sqlstm.sqhstl[36] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[36] = (         int  )sizeof(long);
    sqlstm.sqindv[36] = (         short *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned long )0;
    sqlstm.sqharc[36] = (unsigned long  *)0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (unsigned char  *)lhCodCategoria;
    sqlstm.sqhstl[37] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[37] = (         int  )sizeof(long);
    sqlstm.sqindv[37] = (         short *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned long )0;
    sqlstm.sqharc[37] = (unsigned long  *)0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (unsigned char  *)szhNomApoderado;
    sqlstm.sqhstl[38] = (unsigned long )40;
    sqlstm.sqhsts[38] = (         int  )40;
    sqlstm.sqindv[38] = (         short *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned long )0;
    sqlstm.sqharc[38] = (unsigned long  *)0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (unsigned char  *)szhCodZona;
    sqlstm.sqhstl[39] = (unsigned long )15;
    sqlstm.sqhsts[39] = (         int  )15;
    sqlstm.sqindv[39] = (         short *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned long )0;
    sqlstm.sqharc[39] = (unsigned long  *)0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (unsigned char  *)ihCodSisPago;
    sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[40] = (         int  )sizeof(int);
    sqlstm.sqindv[40] = (         short *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned long )0;
    sqlstm.sqharc[40] = (unsigned long  *)0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (unsigned char  *)szhTipDistribucion;
    sqlstm.sqhstl[41] = (unsigned long )2;
    sqlstm.sqhsts[41] = (         int  )2;
    sqlstm.sqindv[41] = (         short *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned long )0;
    sqlstm.sqharc[41] = (unsigned long  *)0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (unsigned char  *)szhEmailPrincipal;
    sqlstm.sqhstl[42] = (unsigned long )256;
    sqlstm.sqhsts[42] = (         int  )256;
    sqlstm.sqindv[42] = (         short *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned long )0;
    sqlstm.sqharc[42] = (unsigned long  *)0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (unsigned char  *)szhEmailAlterno;
    sqlstm.sqhstl[43] = (unsigned long )256;
    sqlstm.sqhsts[43] = (         int  )256;
    sqlstm.sqindv[43] = (         short *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned long )0;
    sqlstm.sqharc[43] = (unsigned long  *)0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (unsigned char  *)lIdSegmento;
    sqlstm.sqhstl[44] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[44] = (         int  )sizeof(long);
    sqlstm.sqindv[44] = (         short *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned long )0;
    sqlstm.sqharc[44] = (unsigned long  *)0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (unsigned char  *)szFecAlta;
    sqlstm.sqhstl[45] = (unsigned long )15;
    sqlstm.sqhsts[45] = (         int  )15;
    sqlstm.sqindv[45] = (         short *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned long )0;
    sqlstm.sqharc[45] = (unsigned long  *)0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (unsigned char  *)szhCod_tipident;
    sqlstm.sqhstl[46] = (unsigned long )3;
    sqlstm.sqhsts[46] = (         int  )3;
    sqlstm.sqindv[46] = (         short *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned long )0;
    sqlstm.sqharc[46] = (unsigned long  *)0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
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

  /* Inc-pre-189124  */

    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {
        vDTrazasLog(szModulo,"\t\tError en Fetch FetchFactDocuClie : %s", LOG01, SQLERRM);
        vDTrazasError(szModulo,"\t\tError en Fetch FetchFactDocuClie : %s", LOG01, SQLERRM);
        return(SQLCODE);
    }
    if ( *iLeidos == 0 )
        *iLeidos = sqlca.sqlerrd[2];
    else
        *iLeidos = sqlca.sqlerrd[2] - *iPaso;

    *iPaso = sqlca.sqlerrd[2];

    for ( i =0 ; i < *iLeidos; i++ )
    {
        FacturaCliente[i].lIndOrdenTotal     = lhIndOrdenTotal[i];
        FacturaCliente[i].lCodCliente        = lhCodCliente[i];
        FacturaCliente[i].iCodTipDocum       = ihCodTipDocum[i];
        FacturaCliente[i].lNum_Folio         = lhNum_Folio[i];
        FacturaCliente[i].iCodPrioridad      = ihCodPrioridad[i];
        FacturaCliente[i].dTotFactura        = dhTotFactura[i];
        FacturaCliente[i].dTotCargosMes      = dhTotCargosMes[i];
        FacturaCliente[i].dImpSaldoAnt       = dhImpSaldoAnt[i];
        FacturaCliente[i].dTotPagar          = dhTotPagar[i];
        FacturaCliente[i].dTotCuotas         = dhTotCuotas[i];
        FacturaCliente[i].lNumProceso        = lhNumProceso[i];
        FacturaCliente[i].lCodVendedor       = lhCodVendedor[i];
        FacturaCliente[i].iCodOperPlaza      = ihCodOperPlaza[i];
        FacturaCliente[i].lNumSecuRel        = lhNumSecuRel[i];
        FacturaCliente[i].iCodTipDocumRel    = ihCodTipDocumRel[i];
        FacturaCliente[i].lCodVendedorAgRel  = lhCodVendedorAgRel[i];
        FacturaCliente[i].lCodCentrRel       = lhCodCentrRel[i];
        FacturaCliente[i].lNumVenta          = lhNumVenta[i];
        FacturaCliente[i].lCodCategoria      = lhCodCategoria[i];
        FacturaCliente[i].dImpConversion     = ((dhImpConversion[i] == 0)? 1:dhImpConversion[i]);
        FacturaCliente[i].iCodSisPago        = ihCodSisPago[i];


        strcpy(FacturaCliente[i].szIndDebito     , alltrim(szhIndDebito[i]));
        strcpy(FacturaCliente[i].szRowid         , alltrim(szhRowid[i]));
        strcpy(FacturaCliente[i].szRut_Cliente   , alltrim(szhRut_Cliente[i]));
        strcpy(FacturaCliente[i].szNombre_Clie   , alltrim(szhNom_Cliente[i]));
        strcpy(FacturaCliente[i].szNumCtc        , alltrim(szhNumCtc[i]));
        strcpy(FacturaCliente[i].szCodDespacho   , alltrim(szhCodDespacho[i]));
        strcpy(FacturaCliente[i].szNomHeader     , alltrim(szhNomHeader[i]));
        strcpy(FacturaCliente[i].szCodGenArch    , alltrim(szhCodGenArch[i]));
        strcpy(FacturaCliente[i].szCod_Idioma    , alltrim(szhCodIdioma[i]));
        strcpy(FacturaCliente[i].szFecEmision    , alltrim(szhFecEmision[i]));
        strcpy(FacturaCliente[i].szFecVencimie   , alltrim(szhFecVencimie[i]));
        strcpy(FacturaCliente[i].szPrefPlaza     , alltrim(szhPrefPlaza[i]));
        strcpy(FacturaCliente[i].szCodOperadora  , alltrim(szhCodOperadora[i]));
        strcpy(FacturaCliente[i].szCodPlaza      , alltrim(szhCodPlaza[i]));
        strcpy(FacturaCliente[i].szCod_Oficina   , alltrim(szhCodOficina[i]));
        strcpy(FacturaCliente[i].szNomUsuarora   , alltrim(szhNomUsuarora[i]));
        strcpy(FacturaCliente[i].szCodMonedaImp  , alltrim(szhCodMonedaImp[i]));
        strcpy(FacturaCliente[i].szNomApoderado  , alltrim(szhNomApoderado[i]));
        strcpy(FacturaCliente[i].szCodZona       , alltrim(szhCodZona[i]));

        /*ecu 10004 PCRV*/
	        strcpy(FacturaCliente[i].szTipDistribucion, alltrim(szhTipDistribucion[i]));
	        strcpy(FacturaCliente[i].szEmailPrincipal , alltrim(szhEmailPrincipal[i]));
	        strcpy(FacturaCliente[i].szEmailAlterno   , alltrim(szhEmailAlterno[i]));
	        FacturaCliente[i].lIdSegmento  = lIdSegmento[i];
	        strcpy(FacturaCliente[i].szFecAlta        , alltrim(szFecAlta[i]));
        /*ecu 10004 PCRV*/
        if ( i_hIndLetraRel[i]!=ORA_NULL )
            strcpy(FacturaCliente[i].szLetraRel      , alltrim(szhLetraRel[i]));
        
        strcpy(FacturaCliente[i].szCod_tipident      , szhCod_tipident[i]); /* Inc-pre-189124  */
    }
    return(TRUE);
}

int CloseFactDocuClie (void)
{
    char *szModulo="CloseFactDocuClie";

    vDTrazasLog(szModulo, "Entro a iCloseFactDocuClie ", LOG05);
    /* EXEC SQL CLOSE curFactDocu2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1664;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo, "Error en CLOSE curFactDocu2. Error [%i][%s]",LOG00,  SQLCODE, SQLERRM);
        return (FALSE);
    }
    return(1);
}/************************ Final iCloseFactDocuClie ******************************/


int OpenMinutoAdicional( long lCodCiclFact )
{
    char *szModulo="OpenMinutoAdicional";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhVacio       [2] ;
    char szhUno         [2] ;
    char szhFCA         [4] ;
    char szhCodDominio  [15];
    char szhV           [2] ;
    long lhCod_Ciclfact     ;

    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy(szhVacio," ");
    strcpy(szhUno  ,"1");
    strcpy(szhFCA  ,"FCA");
    strcpy(szhCodDominio  ,"AGRULLAM_B4001");
    strcpy(szhV  ,"V");
    lhCod_Ciclfact = lCodCiclFact;

    /* EXEC SQL DECLARE curMinAdicional CURSOR FOR

            SELECT A.COD_PLAN,
                        A.COD_AGRULLAM,
                        NVL(A.MTO_MIN,0)
            FROM TOL_ESTCOBRO A, FA_CICLFACT B, FA_AGRULLAM_B4001_VW C
            WHERE B.COD_CICLFACT = :lhCod_Ciclfact
            AND A.COD_OPERADOR > :szhVacio
            AND A.COD_PLAN > :szhVacio
            AND A.COD_TDIA = :szhUno
            AND B.FEC_DESDELLAM BETWEEN A.FEC_INI_VIG AND A.FEC_TER_VIG
            AND B.FEC_HASTALLAM BETWEEN A.FEC_INI_VIG AND A.FEC_TER_VIG
            AND A.COD_SFRAN = :szhFCA
            AND C.COD_DOMINIO = :szhCodDominio
            AND C.IND_ESTADO  = :szhV
            AND A.COD_AGRULLAM = C.DESCRIPCION_VALOR
            ORDER BY A.COD_PLAN, A.COD_AGRULLAM; */ 


    /* EXEC SQL OPEN curMinAdicional; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0045;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1679;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCod_Ciclfact;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhVacio;
    sqlstm.sqhstl[1] = (unsigned long )2;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhVacio;
    sqlstm.sqhstl[2] = (unsigned long )2;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhUno;
    sqlstm.sqhstl[3] = (unsigned long )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFCA;
    sqlstm.sqhstl[4] = (unsigned long )4;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhCodDominio;
    sqlstm.sqhstl[5] = (unsigned long )15;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szhV;
    sqlstm.sqhstl[6] = (unsigned long )2;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curMinAdicional **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curMinAdicional **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
    }
    return(SQLCODE);
}

/*********************** Final de OpenMinutoAdicional***********************/
/****************************************************************************/
int FetchMinutoAdicional ( void )
{
    int i;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* VARCHAR szhCodPlan              [MAX_MINUTOADICIONAL][6] ; */ 
struct { unsigned short len; unsigned char arr[6]; } szhCodPlan[8001];

    /* VARCHAR szhLlaveMinutoAdicional [MAX_MINUTOADICIONAL][7] ; */ 
struct { unsigned short len; unsigned char arr[10]; } szhLlaveMinutoAdicional[8001];

    double  dhMtoAdicional          [MAX_MINUTOADICIONAL]    ;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="FetchMinutoAdicional";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL
    FETCH curMinAdicional
    INTO :szhCodPlan,
    :szhLlaveMinutoAdicional,
    :dhMtoAdicional; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )8001;
    sqlstm.offset = (unsigned int  )1722;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodPlan;
    sqlstm.sqhstl[0] = (unsigned long )8;
    sqlstm.sqhsts[0] = (         int  )8;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhLlaveMinutoAdicional;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )12;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)dhMtoAdicional;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[2] = (         int  )sizeof(double);
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



    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo,"\t\tError en Fetch FetchMinutoAdicional : %s", LOG01, SQLERRM);
        return(SQLCODE);
    }

    sthMinutoAdicional.iCantidadMinutoAdicional = sqlca.sqlerrd[2];

    for ( i =0 ; i < sthMinutoAdicional.iCantidadMinutoAdicional; i++ )
    {
        sthMinutoAdicional.dMtoAdicional[i] = dhMtoAdicional[i];

        sprintf(sthMinutoAdicional.szCodPlan[i]             ,"%.*s\0",szhCodPlan[i].len,szhCodPlan[i].arr);
        sprintf(sthMinutoAdicional.szLlaveMinutoAdicional[i],"%.*s\0",szhLlaveMinutoAdicional[i].len,szhLlaveMinutoAdicional[i].arr);
    }
    return(SQLCODE);
}

/*************************** Final de FetchMinutoAdicional ***************************/
/****************************************************************************/
int CloseMinutoAdicional(void)
{
    char *szModulo="CloseMinutoAdicional";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL CLOSE curMinAdicional; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1749;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor Minuto Adicional: %s",LOG01, SQLERRM);
        return (FALSE);
    }
    return (TRUE);
}
/****************Final de CloseMinutoAdicional *******************/
int CargaMinutoAdicional( long lCodCiclFact ) /* PGG SOPORTE - 82815 - 16-03-2009 */
{
    int  iSqlDetMinutoAdicional;
    int  rows_to_fetch  = MAX_MINUTOADICIONAL;
    int  rows_before    =  0;
    int  rows_this_time = MAX_MINUTOADICIONAL;

    char *szModulo="CargaMinutoAdicional";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    iSqlDetMinutoAdicional = OpenMinutoAdicional(lCodCiclFact);

    if ( iSqlDetMinutoAdicional == SQLOK )
    {
        while ( rows_this_time == rows_to_fetch )
        {
            iSqlDetMinutoAdicional = FetchMinutoAdicional();
            if ( (iSqlDetMinutoAdicional != SQLOK)&&(iSqlDetMinutoAdicional != SQLNOTFOUND) )
            {
                vDTrazasError(szModulo,"\t\tError en Fetch FetchMinutoAdicional : %s", LOG01, SQLERRM);
                return(SQLCODE);
            }

            sthMinutoAdicional.iCantidadMinutoAdicional = sqlca.sqlerrd[2];
            if ( sthMinutoAdicional.iCantidadMinutoAdicional > MAX_MINUTOADICIONAL )
            {
                vDTrazasLog  (szModulo,"\tsthMinutoAdicional Sobrepaso Maximo Posible" ,LOG01);
                vDTrazasError(szModulo,"\tsthMinutoAdicional Sobrepaso Maximo Posible" ,LOG01);
                return(FALSE);
            }
            rows_this_time = sthMinutoAdicional.iCantidadMinutoAdicional - rows_before;
            rows_before = sthMinutoAdicional.iCantidadMinutoAdicional;
            vDTrazasLog(szModulo,"\t[%d]-[%d]-[%d]",LOG05,rows_this_time,rows_before,rows_to_fetch);
        }
    }
    if ( (iSqlDetMinutoAdicional != SQLOK) && (iSqlDetMinutoAdicional != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo,  "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        vDTrazasLog(szModulo,    "\t\t Error Oracle   [%s]",LOG01, SQLERRM);
        return(FALSE);
    }
    if ( !CloseMinutoAdicional() ) return(FALSE);
    return(TRUE);
}
/************************* Fin CargaMinutoAdicional *************************/


int Busca_RangoPlanes(int iPosicion,int *ihInicio,int *ihTermino,int iFin)
{
    int iIndice;
    int iInicio;
    int iTermino;
    char szllave[6];

    iIndice = iPosicion;
    iInicio = *ihInicio;
    iTermino = *ihTermino;

    sprintf(szllave,"%s",sthMinutoAdicional.szCodPlan[iPosicion]);
    while ( iIndice >= 0 && iInicio == 0 )
    {
        if ( strcmp(szllave,sthMinutoAdicional.szCodPlan[iIndice])==0 )
        {
            sprintf(szllave,"%s",sthMinutoAdicional.szCodPlan[iIndice]);
            iIndice--;
        }
        else
        {
            iInicio = iIndice+1;
        }
    }
    if ( iIndice < 0 ) iInicio = 0;

    iIndice = iPosicion;
    sprintf(szllave,"%s",sthMinutoAdicional.szCodPlan[iPosicion]);
    while ( iIndice < iFin && iTermino == 0 && iIndice > 0 )
    {
        if ( strcmp(szllave,sthMinutoAdicional.szCodPlan[iIndice])==0 )
        {
            sprintf(szllave,"%s",sthMinutoAdicional.szCodPlan[iIndice]);
            iIndice ++;
        }
        else
        {
            iTermino = iIndice-1;
        }
    }
    if ( iIndice >= iFin ) iTermino = iFin-1;

    *ihInicio = iInicio;
    *ihTermino = iTermino;

    return(TRUE);
}/****************Final de Busca_RangoPlanes ******************************************/

int BuscaEstrucPlanes(char *szllave,int iDerecha)
{
    int iCentro;
    int iIzquierda;
    char *szModulo="BuscaEstrucPlanes";

    iIzquierda = 0;
    while ( iIzquierda <= iDerecha )
    {
        iCentro = (iIzquierda + iDerecha) / 2;
        vDTrazasLog(szModulo,"\tPlan [%s]-[%s]",LOG06,szllave,sthMinutoAdicional.szCodPlan[iCentro]);
        if ( strcmp(szllave,sthMinutoAdicional.szCodPlan[iCentro])<0 )
        {
            iDerecha = iCentro - 1;
        }
        else
        {
            if ( strcmp(szllave,sthMinutoAdicional.szCodPlan[iCentro])>0 )
            {
                iIzquierda = iCentro + 1;
            }
            else
            {
                return(iCentro);
            }
        }
    }
    return(-1);
}/****************Final de BuscaEstrucPlanes *******************/


int BuscaValorMinuto(char *szllave,int iIzquierda, int iDerecha)
{
    int iCentro;
    char *szModulo="BuscaValorMinuto";

    while ( iIzquierda <= iDerecha )
    {
        iCentro = (iIzquierda + iDerecha) / 2;
        vDTrazasLog(szModulo,"\tPlan [%s]-[%s]",LOG06,szllave,sthMinutoAdicional.szLlaveMinutoAdicional[iCentro]);
        if ( strcmp(szllave,sthMinutoAdicional.szLlaveMinutoAdicional[iCentro])<0 )
        {
            iDerecha = iCentro - 1;
        }
        else
        {
            if ( strcmp(szllave,sthMinutoAdicional.szLlaveMinutoAdicional[iCentro])>0 )
            {
                iIzquierda = iCentro + 1;
            }
            else
            {
                return(iCentro);
            }
        }
    }
    return(-1);
}/****************Final de BuscaValorMinuto *******************/


int buscaMinutoAdicional(char *szCodPlan,char *szllave)
{
    int iPosicionEstrucPlanes;
    int iPosicionValorMinutos;
    int iDerecha;
    int iInicio;
    int iTermino;

    char *szModulo="buscaMinutoAdicional";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    iPosicionValorMinutos=-1;
    iDerecha = sthMinutoAdicional.iCantidadMinutoAdicional;
    vDTrazasLog(szModulo,"\tPlan [%s] es [%s]",LOG05,szCodPlan,szllave);
    iPosicionEstrucPlanes = BuscaEstrucPlanes(szCodPlan,iDerecha);
    if ( iPosicionEstrucPlanes != -1 )
    {
        vDTrazasLog(szModulo,"\tPlan [%s] es [%d]",LOG06,szCodPlan,iPosicionEstrucPlanes);
        iInicio=0;
        iTermino=0;
        if ( !Busca_RangoPlanes(iPosicionEstrucPlanes,&iInicio,&iTermino,iDerecha) )
        {
            return(FALSE);
        }
        vDTrazasLog(szModulo,"\tPlan [%s] Inicio [%d] Termino [%d] ", LOG06,szCodPlan,iInicio,iTermino);
        iPosicionValorMinutos = BuscaValorMinuto(szllave,iInicio,iTermino);
        if ( iPosicionValorMinutos != -1 )
        {
            return(iPosicionValorMinutos);
        }
    }
    return(iPosicionValorMinutos);
}/****************Final de busca_arrastre *******************/


int ifnCmpCodCliente(const void *cad1,const void *cad2)
{
    int rc = 0;

    return
    ( (rc =     ((CODCLI *)cad1)->lCodCliente-
       ((CODCLI *)cad2)->lCodCliente) != 0)?rc:
    ( (rc = strcmp  (((CODCLI *)cad1)->szFecDesde,
                     ((CODCLI *)cad2)->szFecDesde)) < 0)?rc:
    ( (rc = strcmp  (((CODCLI *)cad1)->szFecHasta,
                     ((CODCLI *)cad2)->szFecHasta)) > 0)?rc:0;
}/****************Final de ifnCmpCodCliente *******************/

int ifnOpenCod_Plantarif()
{
    char *szModulo="ifnOpenCod_Plantarif";

    vDTrazasLog (szModulo,"\n\t\t* Open=> TA_PLANTARIF, TA_CARGOSBASICO", LOG06);

    ihUno = 1;

    /* EXEC SQL DECLARE Cur_Cod_Plantarif CURSOR for
        SELECT  A.COD_PLANTARIF,
        A.DES_PLANTARIF,
        A.TIP_PLANTARIF,
        A.NUM_UNIDADES,
        B.IMP_CARGOBASICO,
        A.IND_ARRASTRE
        FROM  TA_PLANTARIF A,
        TA_CARGOSBASICO B
        WHERE A.COD_PRODUCTO = :ihUno
                               AND A.COD_CARGOBASICO = B.COD_CARGOBASICO
                               AND A.COD_PRODUCTO    = B.COD_PRODUCTO; */ 


    /* EXEC SQL OPEN Cur_Cod_Plantarif; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0046;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1764;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihUno;
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



    if ( SQLCODE != SQLOK )
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> TA_PLANTARIF, TA_CARGOSBASICO",szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenCod_Plantarif **********************/


BOOL bfnFetchCod_Plantarif(PLAN_TARIFARIO_HOSTS * pst_PlanTarifario, int *iCantPlanes)                             
{                                                                                                                  
    char *szModulo="bfnFetchCod_Plantarif";                                                                        
                                                                                                                   
    /* EXEC SQL FETCH Cur_Cod_Plantarif                                                                               
    INTO    :pst_PlanTarifario->szCod_Plantarif    ,                                                               
    :pst_PlanTarifario->szDes_Plantarif    ,                                                                       
    :pst_PlanTarifario->szTip_Plantarif    ,                                                                       
    :pst_PlanTarifario->lMinutosPlan       ,                                                                       
    :pst_PlanTarifario->dValorPlan         ,                                                                       
    :pst_PlanTarifario->iInd_Arrastre      ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )5000;
    sqlstm.offset = (unsigned int  )1783;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pst_PlanTarifario->szCod_Plantarif);
    sqlstm.sqhstl[0] = (unsigned long )4;
    sqlstm.sqhsts[0] = (         int  )4;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pst_PlanTarifario->szDes_Plantarif);
    sqlstm.sqhstl[1] = (unsigned long )31;
    sqlstm.sqhsts[1] = (         int  )31;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pst_PlanTarifario->szTip_Plantarif);
    sqlstm.sqhstl[2] = (unsigned long )2;
    sqlstm.sqhsts[2] = (         int  )2;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pst_PlanTarifario->lMinutosPlan);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )sizeof(long);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pst_PlanTarifario->dValorPlan);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[4] = (         int  )sizeof(double);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pst_PlanTarifario->iInd_Arrastre);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(int);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
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

                                                                       
                                                                                                                   
    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )                                                          
    {                                                                                                              
            vDTrazasError(szModulo,"\t\tError en Fetch %s : %s", LOG01, szModulo, SQLERRM);                        
    }                                                                                                              
    else                                                                                                           
    {                                                                                                              
        *iCantPlanes = sqlca.sqlerrd[2];                                                                           
    }                                                                                                              
    return (SQLCODE);                                                                                              
}/***************************** Final bfnFetchCod_Plantarif ****************/                                      


int ifnCloseCod_Plantarif(void)
{
    char *szModulo="ifnCloseCod_Plantarif";
    vDTrazasLog (szModulo,"\n\t\t* Open=> TA_PLANTARIF, TA_CARGOSBASICO", LOG06);

    /* EXEC SQL CLOSE Cur_Cod_Plantarif; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1822;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
            iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> TA_PLANTARIF, TA_CARGOSBASICO",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnCloseFetchCod_Plantarif **********************/


BOOL bfnCargaCod_Plantarif (PLAN_TARIFARIO **pstCodPlanTarif, int *iNumCodPlanes)
{
    int     rc = 0;
    int    iNumFilas;
    static  PLAN_TARIFARIO_HOSTS stCodPlanTarifHost;
    PLAN_TARIFARIO  *pstCodPlanTarifTemp;
    int iCont;
    char *szModulo="bfnCargaCod_Plantarif";

    vDTrazasLog (szModulo,"\n\t* Carga Planes tarifarios ", LOG06);

    *iNumCodPlanes = 0;
    *pstCodPlanTarif = NULL;

    if ( ifnOpenCod_Plantarif() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchCod_Plantarif(&stCodPlanTarifHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstCodPlanTarif =(PLAN_TARIFARIO*) realloc(*pstCodPlanTarif,(int)(((*iNumCodPlanes)+iNumFilas)*sizeof(PLAN_TARIFARIO)));

        if ( !*pstCodPlanTarif )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaCod_Plantarif", "No se pudo reservar memoria");
            return (FALSE);
        }

        pstCodPlanTarifTemp = &(*pstCodPlanTarif)[(*iNumCodPlanes)];
        memset(pstCodPlanTarifTemp, 0, (int)(sizeof(PLAN_TARIFARIO)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy( pstCodPlanTarifTemp[iCont].szCod_Plantarif,alltrim(stCodPlanTarifHost.szCod_Plantarif[iCont]));
            strcpy( pstCodPlanTarifTemp[iCont].szDes_Plantarif,stCodPlanTarifHost.szDes_Plantarif[iCont]);
            strcpy( pstCodPlanTarifTemp[iCont].szTip_Plantarif,stCodPlanTarifHost.szTip_Plantarif[iCont]);
            pstCodPlanTarifTemp[iCont].lMinutosPlan   = stCodPlanTarifHost.lMinutosPlan   [iCont];
            pstCodPlanTarifTemp[iCont].dValorPlan     = stCodPlanTarifHost.dValorPlan     [iCont];
            pstCodPlanTarifTemp[iCont].iInd_Arrastre  = stCodPlanTarifHost.iInd_Arrastre  [iCont];
        }
        (*iNumCodPlanes) += iNumFilas;
    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Codigos de Planes Tarifarios cargados [%ld]", LOG06, *iNumCodPlanes);

    rc = ifnCloseCod_Plantarif();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaCod_Plantarif", szfnORAerror ());
        return (FALSE);
    }

    qsort((void*)*pstCodPlanTarif, *iNumCodPlanes, sizeof(PLAN_TARIFARIO),ifnCmpCod_PlanTarif);

    vfnPrintCod_PlanTarif (*pstCodPlanTarif, *iNumCodPlanes);

    return(TRUE);
}/***************************** Final bfnCargaCod_Plantarif *********************/



/*************************************/
/*  FUNCION : ifnOpenDetTransClie() */
/*************************************/
static int ifnOpenDetTransClie(ST_CICLOFACT *sthFa_CicloFact ,long lCodCliente, long lCodCiclFact)
{
    long lhCodCiclFact;
    int  iUno  = 1;
    int  iCero = 0;
    char szhFormatoFecha[17];
    char szhFechadesde[15];
    char szhFechahasta[15];
    char szhFormatoFechaCorto[9];
    char szTablaBalan  [50] ="";
    char szTablaDetBalan  [50] ="";
    char szTablaCuotCredito  [50] ="";
    char szCadenaSQL [10000] ="";

    lhCodCliente = lCodCliente;
    lhCodCiclFact = lCodCiclFact;
    strcpy(szhFormatoFecha,"YYYYMMDDHH24MISS");
    strcpy(szhFormatoFechaCorto,"YYYYMMDD");

    sprintf(szhFechadesde,"%s000000",sthFa_CicloFact->fec_desde);
    sprintf(szhFechahasta,"%s235959",sthFa_CicloFact->fec_hasta);

/* P-ECU-09005 */

    if ( !lNroJob )
    {
         strcpy(szTablaBalan,"FA_BALANCE_TO");
         strcpy(szTablaDetBalan,"FA_DETBALANCE_TO");
         //strcpy(szTablaCuotCredito,"FA_CUOTCREDITO"); /* parece que tiene el ciclo asociado */
         sprintf(szTablaCuotCredito,"FA_CUOTCREDITO_%ld",lhCodCiclFact);

          sprintf(szCadenaSQL,"SELECT"
                    "\n 'CANCE', "
                    "\n A.NUM_ABONADO,"
                    "\n B.IND_DETALLE,"
                    "\n A.COD_TIPDOCUM,"
                    "\n ' ' as COD_OFICINA,"
                    "\n A.PREF_PLAZA,"
                    "\n A.NUM_FOLIO,"
            		"\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
                    "\n A.SEC_CUOTA,"
                    "\n A.NUM_CUOTA,"
                    "\n SUM(DECODE(A.COD_TIPDOCUM,25,(ABS(A.IMPORTE_DEBE) * -1),A.IMPORTE_DEBE)), "
                    "\n SUM(DECODE(A.COD_TIPDOCUM,25,(ABS(A.IMPORTE_HABER) * -1),A.IMPORTE_HABER)),"
                    "\n 0 as MTO_SALDO, "
                    "\n 0 as MTO_AJUSTE,"
                    "\n 0 as TOT_BALANCE,"
                    "\n 0 as IND_PAGO, "
                    "\n DECODE(B.COD_REGISTRO,'B5020','B5010','B5030'), "
                    "\n DECODE(A.COD_TIPDOCUM,53,'FDOCU',48,'FDOCU',B.COD_ORIGEN), "
                    "\n 0, "
                    "\n 'N' " /* para acelerada */
                    "\n FROM "
                    "\n  CO_CANCELADOS A, "
                    "\n  FA_NEWCONFBALANCE_TD B, "
                    "\n  FA_TIPDOCUMEN C "
                    "\n WHERE A.COD_CLIENTE = :lhCodCliente"
                    "\n  AND B.COD_ORIGEN       = 'CARUP' "
                    "\n  AND B.COD_REGISTRO     IN ('B5020','B5040') "
                    "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
                    "\n  AND B.IND_IMPRESION    = :iUno"
                    "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
                    "\n  AND C.IND_CICLO        = :iCero"
                    "\n  AND A.FEC_PAGO >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
                    "\n  AND A.FEC_PAGO <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
                    "\n  AND A.NUM_CUOTA > 0"
                    "\n  AND A.IND_FACTURADO = 0"
                    "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					"\n	      A.FEC_EFECTIVIDAD,  A.SEC_CUOTA,  A.NUM_CUOTA,  "
 					"\n	      B.COD_REGISTRO, B.COD_ORIGEN"
                    "\n UNION   "  /*-------------------------------------------------------------------------*/
                    "\n SELECT  "
                  	"\n ROWIDTOCHAR(A.ROWID),"
                    "\n B.NUM_ABONADO,"
                    "\n C.IND_DETALLE,"
                    "\n A.COD_TIPDOCUM,"
                    "\n A.COD_OFICINA,"
                    "\n A.PREF_PLAZA,"
                    "\n A.NUM_FOLIO,"
                    "\n TO_CHAR(A.FEC_TRANSACCION,:szhFormatoFechaCorto),"
                    "\n B.NUM_CUOTA,"
                    "\n B.NUM_TOTCUOTA,"
                    "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_DEBE) * -1),B.MTO_DEBE),"
                    "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_HABER) * -1),B.MTO_HABER),"
                    "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_SALDO) * -1),B.MTO_SALDO),"
                    "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.MTO_AJUSTE) * -1),A.MTO_AJUSTE),"
                    "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.TOT_BALANCE) * -1),A.TOT_BALANCE),"
                    "\n C.IND_PAGO, "
                    "\n C.COD_REGISTRO, "
                    "\n C.COD_ORIGEN, "
                    "\n NVL((SELECT 1 FROM FA_NEWCONFBALANCE_TD Z WHERE A.COD_TIPDOCUM=25 AND A.COD_TIPDOCUMREL= Z.COD_TIPDOCUM AND Z.COD_ORIGEN='CARUP'),0), "
                    "\n J.IND_ACELERADA " /* para acelerada */
                        "\nFROM"
                        "\n %s A,"
                        "\n %s B,"
                    "\n FA_NEWCONFBALANCE_TD C,"
                    "\n FA_TIPDOCUMEN D, "
                    "\n (  SELECT  DISTINCT H.NUM_ABONADO, H.SEC_CUOTA, H.IND_ACELERADA , H.NUM_CUOTA, I.SEC_BALANCE " /* para acelerada */
                    "\n FROM %s H, %s I " /* para acelerada */
                    "\n WHERE H.COD_CLIENTE      = :lhCodCliente " /* para acelerada */
                    "\n AND   H.NUM_ABONADO = I.NUM_ABONADO " /* para acelerada */
                    "\n AND   H.SEC_CUOTA = I.NUM_CUOTA "
                    "\n AND   H.NUM_CUOTA = I.NUM_TOTCUOTA) J " /* para acelerada */
                    "\n WHERE A.COD_CLIENTE     = :lhCodCliente"
                    "\n AND B.SEC_BALANCE      = A.SEC_BALANCE"
                    "\n AND C.COD_ORIGEN       = A.ORIGEN"
                    "\n AND C.COD_TIPDOCUM     = A.COD_TIPDOCUM"
                    "\n AND C.IND_IMPRESION    = :iUno"
                    "\n AND D.COD_TIPDOCUMMOV  = C.COD_TIPDOCUM"
                    "\n AND D.IND_CICLO        = :iCero"
					"\n AND A.FEC_TRANSACCION >= C.FEC_DESDE"  /* PGG - SE VUELVE ATRAS ESTAS LINEAS COMENTADAS. 137177 */
                    "\n AND A.FEC_TRANSACCION <= C.FEC_HASTA" /* PGG - SE VUELVE ATRAS ESTAS LINEAS COMENTADAS. 137177 */
                    "\n AND J.NUM_ABONADO = B.NUM_ABONADO " /* para acelerada */
                    "\n AND J.SEC_CUOTA = B.NUM_CUOTA " /* para acelerada */
                    "\n AND J.SEC_BALANCE = B.SEC_BALANCE " /* para acelerada */
                    "\n AND   J.NUM_CUOTA = B.NUM_TOTCUOTA "
                    /* "\n AND A.FEC_TRANSACCION >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"  */ /* PGG 1.1 - 138693 - 23-06-2010 */
                    "\n AND A.FEC_TRANSACCION <= TO_DATE (:szhFechahasta,:szhFormatoFecha) "  /* Inc 132916 (se fue en inc 137918) PPV Se deja tope final para que no tome cuotas insertadas por el trigger que deben ser facturadar el proximo ciclo */
            "\nUNION " /* --------------- De aqui en adelante solo cuotas de NC ----------------- */
						"\nSELECT"
            "\n 'CANCE', "
            "\n A.NUM_ABONADO,"
            "\n B.IND_DETALLE,"
            "\n A.COD_TIPDOCUM,"
            "\n ' ' as COD_OFICINA,"
            "\n A.PREF_PLAZA,"
            "\n A.NUM_FOLIO,"
            "\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
            "\n 0 , " /* A.SEC_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n 0 , " /* A.NUM_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n SUM(ABS(A.IMPORTE_DEBE) * -1), "
            "\n SUM(ABS(A.IMPORTE_HABER) * -1),"
            "\n 0 as MTO_SALDO, "
            "\n 0 as MTO_AJUSTE,"
            "\n 0 as TOT_BALANCE,"
            "\n 0 as IND_PAGO, "
            "\n B.COD_REGISTRO, "
            "\n B.COD_ORIGEN, "
            "\n 0, "
            "\n 'N' " /* para acelerada */
            "\n FROM "
            "\n  CO_CANCELADOS A, "
            "\n  FA_NEWCONFBALANCE_TD B, "
            "\n  FA_TIPDOCUMEN C "
            "\n WHERE A.COD_CLIENTE = :lhCodCliente"
            "\n  AND B.COD_ORIGEN       = 'FDOCU' "
            "\n  AND B.COD_REGISTRO     = 'B5030' "
            "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
            "\n  AND B.IND_IMPRESION    = :iUno"
            "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
            "\n  AND C.IND_CICLO        = :iCero"
            "\n  AND A.FEC_EFECTIVIDAD >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
            "\n  AND A.FEC_EFECTIVIDAD <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
            "\n  AND A.NUM_CUOTA > 0"
            "\n  AND A.IND_FACTURADO = 1"
            "\n  AND A.COD_TIPDOCUM = 25"
            "\n AND EXISTS (SELECT 1 FROM FAD_CONFBALANCE Z WHERE Z.COD_ITEM = 4 AND Z.COD_ORIGEN IN ('CRED1','CREDI') AND Z.COD_TIPDOCUM = A.COD_TIPDOCUM)"
            "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					  "\n	      A.FEC_EFECTIVIDAD, "
 					  "\n	      B.COD_REGISTRO, B.COD_ORIGEN "
            "\nUNION "
						"\nSELECT"
            "\n 'CANCE', "
            "\n A.NUM_ABONADO,"
            "\n B.IND_DETALLE,"
            "\n A.COD_TIPDOCUM,"
            "\n ' ' as COD_OFICINA,"
            "\n A.PREF_PLAZA,"
            "\n A.NUM_FOLIO,"
            "\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
            "\n 0," /* A.SEC_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n 0," /* A.NUM_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n SUM(ABS(A.IMPORTE_HABER) * -1), "  /* Se considera el haber por que en la cartera solo hay haber */
            "\n SUM(ABS(A.IMPORTE_HABER) * -1), "  /* Se considera el haber por que en la cartera solo hay haber */
            "\n 0 as MTO_SALDO, "
            "\n 0 as MTO_AJUSTE,"
            "\n 0 as TOT_BALANCE,"
            "\n 0 as IND_PAGO, "
            "\n B.COD_REGISTRO, "
            "\n B.COD_ORIGEN, "
            "\n 0, "
            "\n 'N' " /* para acelerada */
            "\n FROM "
            "\n  CO_CARTERA A, "
            "\n  FA_NEWCONFBALANCE_TD B, "
            "\n  FA_TIPDOCUMEN C "
            "\n WHERE A.COD_CLIENTE = :lhCodCliente"
            "\n  AND B.COD_ORIGEN       = 'FDOCU' "
            "\n  AND B.COD_REGISTRO     = 'B5030' "
            "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
            "\n  AND B.IND_IMPRESION    = :iUno"
            "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
            "\n  AND C.IND_CICLO        = :iCero"
            "\n  AND A.FEC_EFECTIVIDAD >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
            "\n  AND A.FEC_EFECTIVIDAD <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
            "\n  AND A.NUM_CUOTA > 0"
            "\n  AND A.IND_FACTURADO = 1"
            "\n  AND A.COD_TIPDOCUM = 25"
            "\n AND EXISTS (SELECT 1 FROM FAD_CONFBALANCE Z WHERE Z.COD_ITEM = 4 AND Z.COD_ORIGEN IN ('CRED1','CREDI') AND Z.COD_TIPDOCUM = A.COD_TIPDOCUM)"
            "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					  "\n	      A.FEC_EFECTIVIDAD, "
 					  "\n	      B.COD_REGISTRO, B.COD_ORIGEN "
                      "\n ORDER BY 2,4,6,7,9, 20 DESC"
          ,szTablaBalan
          ,szTablaDetBalan
          ,szTablaCuotCredito
          ,szTablaDetBalan);


            vDTrazasLog( szModulo,"=> query (\n%s\n)",LOG05,szCadenaSQL);

            /* EXEC SQL PREPARE Cur_Balance FROM :szCadenaSQL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1837;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
            sqlstm.sqhstl[0] = (unsigned long )10000;
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
                vDTrazasLog (szModulo, "Error en PREPARE Cur_Balance. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
                return(FALSE);
            }

            /* EXEC SQL DECLARE curFacBalance CURSOR FOR Cur_Balance; */ 

            if ( SQLCODE < SQLOK )
            {
                vDTrazasLog (szModulo, "Error en DECLARE. curFacBalance. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
                return(FALSE);
            }


            /* EXEC SQL OPEN curFacBalance USING :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechadesde,
                                              :szhFormatoFecha,
                                              :szhFechahasta,
                                              :szhFormatoFecha,
                                              :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechahasta, /o Inc 139216 PPV 30/06/2010 Se agrega fecha tope o/
                                              :szhFormatoFecha, /o Inc 139216 PPV 30/06/2010 Se agrega fecha tope o/
											  :szhFormatoFechaCorto, /o Inc 137918 PPV 02/07/2010 o/
                                              :lhCodCliente, /o Inc 137918 PPV 02/07/2010 o/
                                              :iUno, /o Inc 137918 PPV 02/07/2010 o/
                                              :iCero, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFechadesde, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFormatoFecha, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFechahasta, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFormatoFecha, /o Inc 137918 PPV 02/07/2010 o/
										      :szhFormatoFechaCorto, /o Inc 137918 PPV 02/07/2010 o/
                                              :lhCodCliente, /o Inc 137918 PPV 02/07/2010 o/
                                              :iUno, /o Inc 137918 PPV 02/07/2010 o/
                                              :iCero, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFechadesde, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFormatoFecha, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFechahasta, /o Inc 137918 PPV 02/07/2010 o/
                                              :szhFormatoFecha; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1856;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[0] = (unsigned long )9;
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
            sqlstm.sqhstv[2] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[4] = (unsigned long )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[6] = (unsigned long )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[7] = (unsigned long )17;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[8] = (unsigned long )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         short *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[13] = (unsigned long )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         short *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[14] = (unsigned long )17;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         short *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned long )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[15] = (unsigned long )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         short *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned long )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         short *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned long )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         short *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned long )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         short *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned long )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[19] = (unsigned long )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         short *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned long )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[20] = (unsigned long )17;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         short *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned long )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[21] = (unsigned long )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         short *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned long )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[22] = (unsigned long )17;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         short *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned long )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[23] = (unsigned long )9;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         short *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned long )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         short *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned long )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         short *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned long )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         short *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned long )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[27] = (unsigned long )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         short *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned long )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[28] = (unsigned long )17;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         short *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned long )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[29] = (unsigned long )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         short *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned long )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[30] = (unsigned long )17;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         short *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned long )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
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

 /* Inc 137918 PPV 02/07/2010 */

    }
    else
    {
         sprintf(szTablaBalan,"FA_BALANCE_%ld_%ld",lhCodCiclFact,lNroJob);
         sprintf(szTablaDetBalan,"FA_DETBALANCE_%ld_%ld",lhCodCiclFact,lNroJob);
         sprintf(szTablaCuotCredito,"FA_CUOTCREDITO_%ld_%ld",lhCodCiclFact,lNroJob);

				 /* Inc 137918 PPV 24/06/2010 */
         sprintf(szCadenaSQL,"SELECT"
                    "\n 'CANCE', "
                    "\n A.NUM_ABONADO,"
                    "\n B.IND_DETALLE,"
                    "\n A.COD_TIPDOCUM,"
                    "\n ' ' as COD_OFICINA,"
                    "\n A.PREF_PLAZA,"
                    "\n A.NUM_FOLIO,"
            		"\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
                    "\n A.SEC_CUOTA,"
                    "\n A.NUM_CUOTA,"
                    "\n SUM(DECODE(A.COD_TIPDOCUM,25,(ABS(A.IMPORTE_DEBE) * -1),A.IMPORTE_DEBE)), "
                    "\n SUM(DECODE(A.COD_TIPDOCUM,25,(ABS(A.IMPORTE_HABER) * -1),A.IMPORTE_HABER)),"
                    "\n 0 as MTO_SALDO, "
                    "\n 0 as MTO_AJUSTE,"
                    "\n 0 as TOT_BALANCE,"
                    "\n 0 as IND_PAGO, "
                    "\n DECODE(B.COD_REGISTRO,'B5020','B5010','B5030'), "
                    "\n DECODE(A.COD_TIPDOCUM,53,'FDOCU',48,'FDOCU',B.COD_ORIGEN), "
                    "\n 0, "
                    "\n 'N' " /* para acelerada */
                    "\n FROM "
                    "\n  CO_CANCELADOS A, "
                    "\n  FA_NEWCONFBALANCE_TD B, "
                    "\n  FA_TIPDOCUMEN C "
                    "\n WHERE A.COD_CLIENTE = :lhCodCliente"
                    "\n  AND B.COD_ORIGEN       = 'CARUP' "
                    "\n  AND B.COD_REGISTRO     IN ('B5020','B5040') "
                    "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
                    "\n  AND B.IND_IMPRESION    = :iUno"
                    "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
                    "\n  AND C.IND_CICLO        = :iCero"
                    "\n  AND A.FEC_PAGO >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
                    "\n  AND A.FEC_PAGO <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
                    "\n  AND A.NUM_CUOTA > 0"
                    "\n  AND A.IND_FACTURADO = 0"
                    "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					"\n	      A.FEC_EFECTIVIDAD,  A.SEC_CUOTA,  A.NUM_CUOTA,  "
 					"\n	      B.COD_REGISTRO, B.COD_ORIGEN"
                    "\n UNION   "
                    "\n SELECT  "
		            "\n ROWIDTOCHAR(A.ROWID),"
		            "\n B.NUM_ABONADO,"
		            "\n C.IND_DETALLE,"
		            "\n A.COD_TIPDOCUM,"
		            "\n A.COD_OFICINA,"
		            "\n A.PREF_PLAZA,"
		            "\n A.NUM_FOLIO,"
		            "\n TO_CHAR(A.FEC_TRANSACCION,:szhFormatoFechaCorto),"
		            "\n B.NUM_CUOTA,"
		            "\n B.NUM_TOTCUOTA,"
		            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_DEBE) * -1),B.MTO_DEBE),"
		            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_HABER) * -1),B.MTO_HABER),"
		            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_SALDO) * -1),B.MTO_SALDO),"
		            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.MTO_AJUSTE) * -1),A.MTO_AJUSTE),"
		            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.TOT_BALANCE) * -1),A.TOT_BALANCE),"
		            "\n C.IND_PAGO, "
		            "\n C.COD_REGISTRO, "
		            "\n C.COD_ORIGEN, "
		            "\n NVL((SELECT 1 FROM FA_NEWCONFBALANCE_TD Z WHERE A.COD_TIPDOCUM=25 AND A.COD_TIPDOCUMREL= Z.COD_TIPDOCUM AND Z.COD_ORIGEN='CARUP'),0), "
                    "\n J.IND_ACELERADA " /* para acelerada */
	                "\nFROM"
	                "\n %s A,"
	                "\n %s B,"
	            "\n FA_NEWCONFBALANCE_TD C,"
	            "\n FA_TIPDOCUMEN D, "
                "\n (  SELECT  DISTINCT H.NUM_ABONADO, H.SEC_CUOTA, H.IND_ACELERADA , H.NUM_CUOTA, I.SEC_BALANCE " /* para acelerada */
                "\n FROM %s H, %s I " /* para acelerada */
                "\n WHERE H.COD_CLIENTE      = :lhCodCliente " /* para acelerada */
                "\n AND   H.NUM_ABONADO = I.NUM_ABONADO " /* para acelerada */
                "\n AND   H.SEC_CUOTA = I.NUM_CUOTA "
                "\n AND   H.NUM_CUOTA = I.NUM_TOTCUOTA) J " /* para acelerada */
	            "\nWHERE A.COD_CLIENTE      = :lhCodCliente"
	            "\n AND B.SEC_BALANCE      = A.SEC_BALANCE"
	            "\n AND C.COD_ORIGEN       = A.ORIGEN"
	            "\n AND C.COD_TIPDOCUM     = A.COD_TIPDOCUM"
	            "\n AND C.IND_IMPRESION    = :iUno"
	            "\n AND D.COD_TIPDOCUMMOV  = C.COD_TIPDOCUM"
	            "\n AND D.IND_CICLO        = :iCero"
	            "\n AND A.FEC_TRANSACCION >= C.FEC_DESDE"
	            "\n AND A.FEC_TRANSACCION <= C.FEC_HASTA "
                "\n AND J.NUM_ABONADO = B.NUM_ABONADO " /* para acelerada */
                "\n AND J.SEC_CUOTA = B.NUM_CUOTA " /* para acelerada */
                "\n AND J.SEC_BALANCE = B.SEC_BALANCE " /* para acelerada */
                "\n AND   J.NUM_CUOTA = B.NUM_TOTCUOTA "
                /* "\n AND A.FEC_TRANSACCION >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"  */ /* PGG 1.1 - 138693 - 23-06-2010 */
                "\n AND A.FEC_TRANSACCION <= TO_DATE (:szhFechahasta,:szhFormatoFecha) "  /* Inc 132916 (se fue en inc 137918) PPV Se deja tope final para que no tome cuotas insertadas por el trigger que deben ser facturadar el proximo ciclo */
//	            "\nUNION "
//	                "\n SELECT"
//	                "\n ROWIDTOCHAR(A.ROWID),"
//	            "\n B.NUM_ABONADO,"
//	            "\n C.IND_DETALLE,"
//	            "\n A.COD_TIPDOCUM,"
//	            "\n A.COD_OFICINA,"
//	            "\n A.PREF_PLAZA,"
//	            "\n A.NUM_FOLIO,"
//	            "\n TO_CHAR(A.FEC_TRANSACCION,:szhFormatoFechaCorto),"
//	            "\n B.NUM_CUOTA,"
//	            "\n B.NUM_TOTCUOTA,"
//	            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_DEBE) * -1),B.MTO_DEBE),"
//	            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_HABER) * -1),B.MTO_HABER),"
//	            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(B.MTO_SALDO) * -1),B.MTO_SALDO),"
//	            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.MTO_AJUSTE) * -1),A.MTO_AJUSTE),"
//	            "\n DECODE(A.COD_TIPDOCUM,25,(ABS(A.TOT_BALANCE) * -1),A.TOT_BALANCE),"
//	            "\n C.IND_PAGO, "
//	            "\n C.COD_REGISTRO, "
//	            "\n C.COD_ORIGEN, "
//	            "\n NVL((SELECT 1 FROM FA_NEWCONFBALANCE_TD Z WHERE A.COD_TIPDOCUM=25 AND A.COD_TIPDOCUMREL= Z.COD_TIPDOCUM AND Z.COD_ORIGEN='CARUP'),0), "
//                "\n J.IND_ACELERADA " /* para acelerada */
//	                "\nFROM"
//	                "\n FA_BALANCE_TO A,"
//	                "\n FA_DETBALANCE_TO B,"
//	            "\n FA_NEWCONFBALANCE_TD C,"
//	            "\n FA_TIPDOCUMEN D, " /* para acelerada */
//                "\n (  SELECT  DISTINCT H.NUM_ABONADO, H.SEC_CUOTA, H.IND_ACELERADA , I.SEC_BALANCE " /* para acelerada */
//                "\n FROM %s H, FA_DETBALANCE_TO I " /* para acelerada */
//                "\n WHERE H.COD_CLIENTE      = :lhCodCliente " /* para acelerada */
//                "\n AND   H.NUM_ABONADO = I.NUM_ABONADO " /* para acelerada */
//                "\n AND   H.SEC_CUOTA = I.NUM_CUOTA) J " /* para acelerada */
//	            "\nWHERE A.COD_CLIENTE      = :lhCodCliente"
//	            "\n AND B.SEC_BALANCE      = A.SEC_BALANCE"
//	            "\n AND C.COD_ORIGEN       = A.ORIGEN"
//	            "\n AND C.COD_TIPDOCUM     = A.COD_TIPDOCUM"
//	            "\n AND C.IND_IMPRESION    = :iUno"
//	            "\n AND D.COD_TIPDOCUMMOV  = C.COD_TIPDOCUM"
//	            "\n AND D.IND_CICLO        = :iCero"
//	            "\n AND A.FEC_TRANSACCION >= C.FEC_DESDE"
//	            "\n AND A.FEC_TRANSACCION <= C.FEC_HASTA "
//                "\n AND J.NUM_ABONADO = B.NUM_ABONADO " /* para acelerada */
//                "\n AND J.SEC_CUOTA = B.NUM_CUOTA " /* para acelerada */
//                "\n AND J.SEC_BALANCE = B.SEC_BALANCE " /* para acelerada */
	            "\nUNION " /* --------------- De aqui en adelante solo cuotas de NC ----------------- */
						"\nSELECT"
            "\n 'CANCE', "
            "\n A.NUM_ABONADO,"
            "\n B.IND_DETALLE,"
            "\n A.COD_TIPDOCUM,"
            "\n ' ' as COD_OFICINA,"
            "\n A.PREF_PLAZA,"
            "\n A.NUM_FOLIO,"
            "\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
            "\n 0 , " /* A.SEC_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n 0 , " /* A.NUM_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n SUM(ABS(A.IMPORTE_DEBE) * -1), "
            "\n SUM(ABS(A.IMPORTE_HABER) * -1),"
            "\n 0 as MTO_SALDO, "
            "\n 0 as MTO_AJUSTE,"
            "\n 0 as TOT_BALANCE,"
            "\n 0 as IND_PAGO, "
            "\n B.COD_REGISTRO, "
            "\n B.COD_ORIGEN, "
            "\n 0, "
            "\n 'N' " /*para acelerada */
            "\n FROM "
            "\n  CO_CANCELADOS A, "
            "\n  FA_NEWCONFBALANCE_TD B, "
            "\n  FA_TIPDOCUMEN C "
            "\n WHERE A.COD_CLIENTE = :lhCodCliente"
            "\n  AND B.COD_ORIGEN       = 'FDOCU' "
            "\n  AND B.COD_REGISTRO     = 'B5030' "
            "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
            "\n  AND B.IND_IMPRESION    = :iUno"
            "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
            "\n  AND C.IND_CICLO        = :iCero"
            "\n  AND A.FEC_EFECTIVIDAD >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
            "\n  AND A.FEC_EFECTIVIDAD <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
            "\n  AND A.NUM_CUOTA > 0"
            "\n  AND A.IND_FACTURADO = 1"
            "\n  AND A.COD_TIPDOCUM = 25"
            "\n AND EXISTS (SELECT 1 FROM FAD_CONFBALANCE Z WHERE Z.COD_ITEM = 4 AND Z.COD_ORIGEN IN ('CRED1','CREDI') AND Z.COD_TIPDOCUM = A.COD_TIPDOCUM)"
            "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					  "\n	      A.FEC_EFECTIVIDAD, "
 					  "\n	      B.COD_REGISTRO, B.COD_ORIGEN "
            "\nUNION "
						"\nSELECT"
            "\n 'CANCE', "
            "\n A.NUM_ABONADO,"
            "\n B.IND_DETALLE,"
            "\n A.COD_TIPDOCUM,"
            "\n ' ' as COD_OFICINA,"
            "\n A.PREF_PLAZA,"
            "\n A.NUM_FOLIO,"
            "\n TO_CHAR(A.FEC_EFECTIVIDAD,:szhFormatoFechaCorto),"
            "\n 0," /* A.SEC_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n 0," /* A.NUM_CUOTA Se pone siempre 0 para que salga en el B5030 */
            "\n SUM(ABS(A.IMPORTE_HABER) * -1), "  /* Se considera el haber por que en la cartera solo hay haber */
            "\n SUM(ABS(A.IMPORTE_HABER) * -1), "  /* Se considera el haber por que en la cartera solo hay haber */
            "\n 0 as MTO_SALDO, "
            "\n 0 as MTO_AJUSTE,"
            "\n 0 as TOT_BALANCE,"
            "\n 0 as IND_PAGO, "
            "\n B.COD_REGISTRO, "
            "\n B.COD_ORIGEN, "
            "\n 0, "
            "\n 'N' " /*para acelerada */
            "\n FROM "
            "\n  CO_CARTERA A, "
            "\n  FA_NEWCONFBALANCE_TD B, "
            "\n  FA_TIPDOCUMEN C "
            "\n WHERE A.COD_CLIENTE = :lhCodCliente"
            "\n  AND B.COD_ORIGEN       = 'FDOCU' "
            "\n  AND B.COD_REGISTRO     = 'B5030' "
            "\n  AND B.COD_TIPDOCUM     = A.COD_TIPDOCUM"
            "\n  AND B.IND_IMPRESION    = :iUno"
            "\n  AND C.COD_TIPDOCUMMOV  = B.COD_TIPDOCUM"
            "\n  AND C.IND_CICLO        = :iCero"
            "\n  AND A.FEC_EFECTIVIDAD >= TO_DATE (:szhFechadesde,:szhFormatoFecha)"
            "\n  AND A.FEC_EFECTIVIDAD <= TO_DATE (:szhFechahasta,:szhFormatoFecha)"
            "\n  AND A.NUM_CUOTA > 0"
            "\n  AND A.IND_FACTURADO = 1"
            "\n  AND A.COD_TIPDOCUM = 25"
            "\n AND EXISTS (SELECT 1 FROM FAD_CONFBALANCE Z WHERE Z.COD_ITEM = 4 AND Z.COD_ORIGEN IN ('CRED1','CREDI') AND Z.COD_TIPDOCUM = A.COD_TIPDOCUM)"
            "\n GROUP BY A.NUM_ABONADO,  B.IND_DETALLE,  A.COD_TIPDOCUM,  A.PREF_PLAZA,  A.NUM_FOLIO,  "
 					  "\n	      A.FEC_EFECTIVIDAD, "
 					  "\n	      B.COD_REGISTRO, B.COD_ORIGEN "
                      "\n ORDER BY 2,4,6,7,9, 20 DESC"
          ,szTablaBalan
          ,szTablaDetBalan
          ,szTablaCuotCredito
          ,szTablaDetBalan
          /*,szTablaCuotCredito*/);

            vDTrazasLog( szModulo,"=> query JOB (\n%s\n)",LOG05,szCadenaSQL);

            /* EXEC SQL PREPARE Cur_BalanceJOB FROM :szCadenaSQL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1995;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
            sqlstm.sqhstl[0] = (unsigned long )10000;
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
                vDTrazasLog (szModulo, "Error en PREPARE Cur_BalanceJOB. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
                return(FALSE);
            }

            /* EXEC SQL DECLARE curFacBalanceJOB CURSOR FOR Cur_BalanceJOB; */ 

            if ( SQLCODE < SQLOK )
            {
                vDTrazasLog (szModulo, "Error en DECLARE. curFacBalanceJOB. Error [%d][%s]",LOG00,  SQLCODE, SQLERRM);
                return(FALSE);
            }

            /* EXEC SQL OPEN curFacBalanceJOB USING :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechadesde,
                                              :szhFormatoFecha,
                                              :szhFechahasta,
                                              :szhFormatoFecha,
                                              :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechahasta, /o Inc 139216 PPV 30/06/2010 Se agrega fecha tope o/
                                              :szhFormatoFecha, /o Inc 139216 PPV 30/06/2010 Se agrega fecha tope o/
                                              :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechadesde,
                                              :szhFormatoFecha,
                                              :szhFechahasta,
                                              :szhFormatoFecha,
                                              :szhFormatoFechaCorto,
                                              :lhCodCliente,
                                              :iUno,
                                              :iCero,
                                              :szhFechadesde,
                                              :szhFormatoFecha,
                                              :szhFechahasta,
                                              :szhFormatoFecha; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2014;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[0] = (unsigned long )9;
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
            sqlstm.sqhstv[2] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[4] = (unsigned long )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[6] = (unsigned long )15;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[7] = (unsigned long )17;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[8] = (unsigned long )9;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         short *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[13] = (unsigned long )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         short *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[14] = (unsigned long )17;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         short *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned long )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[15] = (unsigned long )9;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         short *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned long )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         short *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned long )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         short *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned long )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         short *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned long )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[19] = (unsigned long )15;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         short *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned long )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[20] = (unsigned long )17;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         short *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned long )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[21] = (unsigned long )15;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         short *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned long )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[22] = (unsigned long )17;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         short *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned long )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (unsigned char  *)szhFormatoFechaCorto;
            sqlstm.sqhstl[23] = (unsigned long )9;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         short *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned long )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (unsigned char  *)&lhCodCliente;
            sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         short *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned long )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (unsigned char  *)&iUno;
            sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         short *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned long )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         short *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned long )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (unsigned char  *)szhFechadesde;
            sqlstm.sqhstl[27] = (unsigned long )15;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         short *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned long )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[28] = (unsigned long )17;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         short *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned long )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (unsigned char  *)szhFechahasta;
            sqlstm.sqhstl[29] = (unsigned long )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         short *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned long )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (unsigned char  *)szhFormatoFecha;
            sqlstm.sqhstl[30] = (unsigned long )17;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         short *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned long )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
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



    if ( SQLCODE < SQLOK )
    {
        vDTrazasLog (szModulo, "Error en OPEN curFacBalance. Error [%i][%s]",LOG00,  SQLCODE, SQLERRM);
        return(FALSE);
    }

    vDTrazasLog (szExeName,"\n\t\t* Open=> curFacBalance", LOG06);

/* P-ECU-09005 */

    return SQLCODE;
}/** END ifnOpenDetTransClie **/

/*************************************************************************************************/
/*  FUNCION : BOOL bfnFetchDetTransClie(DET_TRANSACCIONES_CLIE_HOST * pst_DetTransClie, long *lCantDetTrans) */
/*************************************************************************************************/
static BOOL bfnFetchDetTransClie(DET_TRANSACCIONES_CLIE_HOST * pst_DetTransClie, long *lCantDetTrans)
{

    if ( !lNroJob )
    {
        /* EXEC SQL FETCH curFacBalance
            INTO :pst_DetTransClie->szRowId            ,
                 :pst_DetTransClie->lNumAbonado        ,
                 :pst_DetTransClie->iIndDetalle        ,
                 :pst_DetTransClie->iCodTipDocum       ,
                 :pst_DetTransClie->szCodOficina       ,
                 :pst_DetTransClie->szCodPlaza         ,
                 :pst_DetTransClie->lNumFolio          ,
                 :pst_DetTransClie->szFecTrans         ,
                 :pst_DetTransClie->lNumCuota          ,
                 :pst_DetTransClie->lNumTotalCuota     ,
                 :pst_DetTransClie->dMontoDebe         ,
                 :pst_DetTransClie->dMontoHaber        ,
                 :pst_DetTransClie->dMontoSaldo        ,
                 :pst_DetTransClie->dMontoAjuste       ,
                 :pst_DetTransClie->dMontoTotBalance   ,
                 :pst_DetTransClie->iIndPago           ,
                 :pst_DetTransClie->szCodRegistro      ,
                 :pst_DetTransClie->szCodOrigen        ,
                 :pst_DetTransClie->iIndCaratula       ,
                 :pst_DetTransClie->sz_IndAcelerada    ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )20000;
        sqlstm.offset = (unsigned int  )2153;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)(pst_DetTransClie->szRowId);
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )19;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)(pst_DetTransClie->lNumAbonado);
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )sizeof(long);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)(pst_DetTransClie->iIndDetalle);
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )sizeof(int);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)(pst_DetTransClie->iCodTipDocum);
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )sizeof(int);
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)(pst_DetTransClie->szCodOficina);
        sqlstm.sqhstl[4] = (unsigned long )3;
        sqlstm.sqhsts[4] = (         int  )3;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)(pst_DetTransClie->szCodPlaza);
        sqlstm.sqhstl[5] = (unsigned long )11;
        sqlstm.sqhsts[5] = (         int  )11;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqharc[5] = (unsigned long  *)0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)(pst_DetTransClie->lNumFolio);
        sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[6] = (         int  )sizeof(long);
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqharc[6] = (unsigned long  *)0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)(pst_DetTransClie->szFecTrans);
        sqlstm.sqhstl[7] = (unsigned long )9;
        sqlstm.sqhsts[7] = (         int  )9;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqharc[7] = (unsigned long  *)0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)(pst_DetTransClie->lNumCuota);
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )sizeof(long);
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqharc[8] = (unsigned long  *)0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)(pst_DetTransClie->lNumTotalCuota);
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )sizeof(long);
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqharc[9] = (unsigned long  *)0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)(pst_DetTransClie->dMontoDebe);
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )sizeof(double);
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqharc[10] = (unsigned long  *)0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)(pst_DetTransClie->dMontoHaber);
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )sizeof(double);
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqharc[11] = (unsigned long  *)0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)(pst_DetTransClie->dMontoSaldo);
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )sizeof(double);
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqharc[12] = (unsigned long  *)0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)(pst_DetTransClie->dMontoAjuste);
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )sizeof(double);
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqharc[13] = (unsigned long  *)0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)(pst_DetTransClie->dMontoTotBalance);
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )sizeof(double);
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqharc[14] = (unsigned long  *)0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)(pst_DetTransClie->iIndPago);
        sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[15] = (         int  )sizeof(int);
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqharc[15] = (unsigned long  *)0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)(pst_DetTransClie->szCodRegistro);
        sqlstm.sqhstl[16] = (unsigned long )6;
        sqlstm.sqhsts[16] = (         int  )6;
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqharc[16] = (unsigned long  *)0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)(pst_DetTransClie->szCodOrigen);
        sqlstm.sqhstl[17] = (unsigned long )6;
        sqlstm.sqhsts[17] = (         int  )6;
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqharc[17] = (unsigned long  *)0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)(pst_DetTransClie->iIndCaratula);
        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[18] = (         int  )sizeof(int);
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqharc[18] = (unsigned long  *)0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)(pst_DetTransClie->sz_IndAcelerada);
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


    }else{
                /* EXEC SQL FETCH curFacBalanceJOB
            INTO :pst_DetTransClie->szRowId            ,
                 :pst_DetTransClie->lNumAbonado        ,
                 :pst_DetTransClie->iIndDetalle        ,
                 :pst_DetTransClie->iCodTipDocum       ,
                 :pst_DetTransClie->szCodOficina       ,
                 :pst_DetTransClie->szCodPlaza         ,
                 :pst_DetTransClie->lNumFolio          ,
                 :pst_DetTransClie->szFecTrans         ,
                 :pst_DetTransClie->lNumCuota          ,
                 :pst_DetTransClie->lNumTotalCuota     ,
                 :pst_DetTransClie->dMontoDebe         ,
                 :pst_DetTransClie->dMontoHaber        ,
                 :pst_DetTransClie->dMontoSaldo        ,
                 :pst_DetTransClie->dMontoAjuste       ,
                 :pst_DetTransClie->dMontoTotBalance   ,
                 :pst_DetTransClie->iIndPago           ,
                 :pst_DetTransClie->szCodRegistro      ,
                 :pst_DetTransClie->szCodOrigen        ,
                 :pst_DetTransClie->iIndCaratula       ,
                 :pst_DetTransClie->sz_IndAcelerada    ; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )20000;
                sqlstm.offset = (unsigned int  )2248;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)(pst_DetTransClie->szRowId);
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )19;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqharc[0] = (unsigned long  *)0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)(pst_DetTransClie->lNumAbonado);
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[1] = (         int  )sizeof(long);
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqharc[1] = (unsigned long  *)0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)(pst_DetTransClie->iIndDetalle);
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )sizeof(int);
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqharc[2] = (unsigned long  *)0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)(pst_DetTransClie->iCodTipDocum);
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )sizeof(int);
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqharc[3] = (unsigned long  *)0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)(pst_DetTransClie->szCodOficina);
                sqlstm.sqhstl[4] = (unsigned long )3;
                sqlstm.sqhsts[4] = (         int  )3;
                sqlstm.sqindv[4] = (         short *)0;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqharc[4] = (unsigned long  *)0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)(pst_DetTransClie->szCodPlaza);
                sqlstm.sqhstl[5] = (unsigned long )11;
                sqlstm.sqhsts[5] = (         int  )11;
                sqlstm.sqindv[5] = (         short *)0;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqharc[5] = (unsigned long  *)0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)(pst_DetTransClie->lNumFolio);
                sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[6] = (         int  )sizeof(long);
                sqlstm.sqindv[6] = (         short *)0;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqharc[6] = (unsigned long  *)0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)(pst_DetTransClie->szFecTrans);
                sqlstm.sqhstl[7] = (unsigned long )9;
                sqlstm.sqhsts[7] = (         int  )9;
                sqlstm.sqindv[7] = (         short *)0;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqharc[7] = (unsigned long  *)0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)(pst_DetTransClie->lNumCuota);
                sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[8] = (         int  )sizeof(long);
                sqlstm.sqindv[8] = (         short *)0;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqharc[8] = (unsigned long  *)0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)(pst_DetTransClie->lNumTotalCuota);
                sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[9] = (         int  )sizeof(long);
                sqlstm.sqindv[9] = (         short *)0;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqharc[9] = (unsigned long  *)0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)(pst_DetTransClie->dMontoDebe);
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )sizeof(double);
                sqlstm.sqindv[10] = (         short *)0;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqharc[10] = (unsigned long  *)0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)(pst_DetTransClie->dMontoHaber);
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )sizeof(double);
                sqlstm.sqindv[11] = (         short *)0;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqharc[11] = (unsigned long  *)0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)(pst_DetTransClie->dMontoSaldo);
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )sizeof(double);
                sqlstm.sqindv[12] = (         short *)0;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqharc[12] = (unsigned long  *)0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)(pst_DetTransClie->dMontoAjuste);
                sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[13] = (         int  )sizeof(double);
                sqlstm.sqindv[13] = (         short *)0;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqharc[13] = (unsigned long  *)0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)(pst_DetTransClie->dMontoTotBalance);
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )sizeof(double);
                sqlstm.sqindv[14] = (         short *)0;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqharc[14] = (unsigned long  *)0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)(pst_DetTransClie->iIndPago);
                sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[15] = (         int  )sizeof(int);
                sqlstm.sqindv[15] = (         short *)0;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqharc[15] = (unsigned long  *)0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)(pst_DetTransClie->szCodRegistro);
                sqlstm.sqhstl[16] = (unsigned long )6;
                sqlstm.sqhsts[16] = (         int  )6;
                sqlstm.sqindv[16] = (         short *)0;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqharc[16] = (unsigned long  *)0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)(pst_DetTransClie->szCodOrigen);
                sqlstm.sqhstl[17] = (unsigned long )6;
                sqlstm.sqhsts[17] = (         int  )6;
                sqlstm.sqindv[17] = (         short *)0;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqharc[17] = (unsigned long  *)0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)(pst_DetTransClie->iIndCaratula);
                sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[18] = (         int  )sizeof(int);
                sqlstm.sqindv[18] = (         short *)0;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqharc[18] = (unsigned long  *)0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)(pst_DetTransClie->sz_IndAcelerada);
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



    }

    if((SQLCODE == SQLOK) && (SQLCODE != SQLNOTFOUND))
        vDTrazasError(szModulo,"\t\tError en Fetch %s : %s", LOG01, szModulo, SQLERRM);
    else
    {
        *lCantDetTrans = sqlca.sqlerrd[2];
    }
    return SQLCODE;
}/** END bfnFetchDetTransClie **/

/******************************************/
/*  FUNCION : ifnCloseDetTransClie(void) */
/******************************************/
static int ifnCloseDetTransClie(void)
{
    vDTrazasLog (szExeName,"\n\t\t* Close=> curFacBalance", LOG06);

    if ( !lNroJob )
    {
        /* EXEC SQL CLOSE curFacBalance; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2343;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }else{
        /* EXEC SQL CLOSE curFacBalanceJOB; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2358;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }

    if (SQLCODE != SQLOK)
       iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> curFacBalance",
                 szfnORAerror ());

    return SQLCODE;
}/** END ifnCloseDetTransClie **/



static int ifnOpenConfB4001(void)
{
    char *szModulo="ifnOpenConfB4001";

    char szhCodDominio  [15];
    char szhV           [2];

    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnOpenConfB4001", LOG06);

    strcpy(szhCodDominio  ,"AGRULLAM_B4001");
    strcpy(szhV  ,"V");

    /* EXEC SQL DECLARE Cur_RegB4001 CURSOR for
        SELECT
                TO_NUMBER(VALOR),
                DESCRIPCION_VALOR
        FROM FA_AGRULLAM_B4001_VW
        WHERE COD_DOMINIO = :szhCodDominio
          AND IND_ESTADO  = :szhV
        ORDER BY TO_NUMBER(VALOR) ASC; */ 


    /* EXEC SQL OPEN Cur_RegB4001; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0049;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2373;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodDominio;
    sqlstm.sqhstl[0] = (unsigned long )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhV;
    sqlstm.sqhstl[1] = (unsigned long )2;
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
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> FA_AGRULLAM_B4001_VW",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnOpenConfB4001 **********************/


static int ifnOpenRegistrosTipoD(void)
{
    char *szModulo="ifnOpenRegistrosTipoD";


    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnOpenRegistrosTipoD", LOG06);


    /* EXEC SQL DECLARE Cur_ConfRegTipD CURSOR for
        SELECT POSICION, COD_REGISTRO, TIP_REGISTRO, VALOR, TIP_TRAF /oMLA 123425o/
        FROM FA_REGDETLLAM_TD
        ORDER BY POSICION ASC; */ 


    /* EXEC SQL OPEN Cur_ConfRegTipD; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0050;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2396;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> Cur_ConfRegTipD",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnOpenConfB4001 **********************/


static BOOL bfnFetchConfB4001 (REG_B4001_HOST *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchConfB4001";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion bfnFetchConfB4001", LOG06);

    /* EXEC SQL FETCH Cur_RegB4001
    INTO :pstHost->iPosicion ,
         :pstHost->szCodAgrullam; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )2411;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->iPosicion);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szCodAgrullam);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
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
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> FA_AGRULLAM_B4001_VW", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchConfB4001 ****************/

static BOOL bfnFetchRegistrosTipoD (REGTIP_D_HOST *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchRegistrosTipoD";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion bfnFetchRegistrosTipoD", LOG06);

    /* EXEC SQL FETCH Cur_ConfRegTipD
    INTO :pstHost->iPosicion ,
         :pstHost->szCodRegistro,
         :pstHost->szCodTipLlam,
         :pstHost->szCodValor,
         :pstHost->szTipTraf; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )2434;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->iPosicion);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szCodRegistro);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->szCodTipLlam);
    sqlstm.sqhstl[2] = (unsigned long )4;
    sqlstm.sqhsts[2] = (         int  )4;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->szCodValor);
    sqlstm.sqhstl[3] = (unsigned long )6;
    sqlstm.sqhsts[3] = (         int  )6;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->szTipTraf);
    sqlstm.sqhstl[4] = (unsigned long )4;
    sqlstm.sqhsts[4] = (         int  )4;
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

 /*MLA 123425*/

    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> Cur_ConfRegTipD", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchRegistrosTipoD ****************/


static int ifnCloseRegistrosTipoD(void)
{
    char *szModulo="ifnCloseRegistrosTipoD";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnCloseRegistrosTipoD", LOG06);

    /* EXEC SQL CLOSE Cur_ConfRegTipD; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2469;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cur_ConfRegTipD",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnCloseRegistrosTipoD **********************/

static int ifnCloseConfB4001(void)
{
    char *szModulo="ifnCloseConfB4001";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnCloseConfB4001", LOG06);

    /* EXEC SQL CLOSE Cur_RegB4001; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2484;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> FA_AGRULLAM_B4001_VW",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnCloseConfB4001 **********************/

BOOL bfnCargaConfB4001 (REG_B4001 **stRegB4001, int *iNumRegB4001)
{
    int     rc = 0;
    int     iNumFilas;
    static  REG_B4001_HOST stRegB4001Host;
    REG_B4001 *stRegB4001Temp;
    int     iCont;
    char *szModulo="CargaConfB4001";

    vDTrazasLog (szModulo,"\n\t* Carga Configuracion Registro B4001 ", LOG06);

    *iNumRegB4001 = 0;
    *stRegB4001 = NULL;

    if ( ifnOpenConfB4001() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchConfB4001(&stRegB4001Host,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *stRegB4001 =(REG_B4001*) realloc(*stRegB4001,(int)(((*iNumRegB4001)+iNumFilas)*sizeof(REG_B4001)));

        if ( !*stRegB4001 )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bCargaConfB4001", "no se pudo reservar memoria");
            return (FALSE);
        }

        stRegB4001Temp = &(*stRegB4001)[(*iNumRegB4001)];
        memset(stRegB4001Temp, 0, (int)(sizeof(REG_B4001)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
                    stRegB4001Temp[iCont].iPosicion      = stRegB4001Host.iPosicion[iCont];
            strcpy( stRegB4001Temp[iCont].szCodAgrullam  , stRegB4001Host.szCodAgrullam[iCont]);
        }
        (*iNumRegB4001) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Configuracion de Registros B4001 cargados :[%d]", LOG04, *iNumRegB4001);

    rc = ifnCloseConfB4001();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bCargaConfB4001", szfnORAerror ());
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\t\t* (bCargaConfB4001) Saliendo de la funcion...", LOG06);

    return(TRUE);
}/***************************** Final bCargaConfB4001 *********************/

BOOL bfnCargaRegistrosTipoD (REGTIP_D **stRegTipD, int *iNumRegD)
{
    int     rc = 0;
    int     iNumFilas;
    static  REGTIP_D_HOST stRegTipDHost;
    REGTIP_D *stRegTipDTemp;
    int     iCont;
    char *szModulo="bfnCargaRegistrosTipoD";

    vDTrazasLog (szModulo,"\n\t* Carga Configuracion Registro D ", LOG06);

    *iNumRegD  = 0;
    *stRegTipD = NULL;

    if ( ifnOpenRegistrosTipoD() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchRegistrosTipoD(&stRegTipDHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *stRegTipD =(REGTIP_D*) realloc(*stRegTipD,(int)(((*iNumRegD)+iNumFilas)*sizeof(REGTIP_D)));

        if ( !*stRegTipD )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargaRegistrosTipoD", "no se pudo reservar memoria");
            return (FALSE);
        }

        stRegTipDTemp = &(*stRegTipD)[(*iNumRegD)];
        memset(stRegTipDTemp, 0, (int)(sizeof(REGTIP_D)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
                    stRegTipDTemp[iCont].iPosicion      = stRegTipDHost.iPosicion[iCont];
            strcpy( stRegTipDTemp[iCont].szCodRegistro  , alltrim(stRegTipDHost.szCodRegistro[iCont]));
            strcpy( stRegTipDTemp[iCont].szCodTipLlam   , alltrim(stRegTipDHost.szCodTipLlam[iCont]));
            strcpy( stRegTipDTemp[iCont].szCodValor     , alltrim(stRegTipDHost.szCodValor[iCont]));
            strcpy( stRegTipDTemp[iCont].szTipTraf      , alltrim(stRegTipDHost.szTipTraf[iCont])); /*MLA 123425*/
        }
        (*iNumRegD) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Configuracion de Registros D cargados :[%d]", LOG04, *iNumRegD);

    rc = ifnCloseRegistrosTipoD();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaRegistrosTipoD", szfnORAerror ());
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\t\t* (bfnCargaRegistrosTipoD) Saliendo de la funcion...", LOG06);

    return(TRUE);
}/***************************** Final bfnCargaRegistrosTipoD *********************/


/*******************************************************************************************/
/*  FUNCION : bfnCargaDetTransClie (DET_TRANSACCIONES_CLIE **pstDetTransClie, int *iNumDetTrans, long lCodCliente) */
/*******************************************************************************************/

BOOL bfnCargaDetTransClie (DET_TRANSACCIONES *pstDetTrans,
                           ST_CICLOFACT      *sthFa_CicloFact,
                           long              lCodCliente,
                           long              lNumProceso,
                           long              lCodCiclFact)
{
    int                  rc = 0;
    int                  ihNumRegTrans=0;
    int                  iFlagTrans = FALSE;
    int                  iIdxTrans = 0;
    long                 lNumFilas;
    static  DET_TRANSACCIONES_CLIE_HOST stDetTransClieHost;
    MOVIM_CLIE           *pstMovimClieTemp;
    PAGOS_CLIE           *pstPagosClieTemp;
    RES_MOVIM_CLIE       *pstResMovimClieTemp;
    RES_PAGOS_CLIE       *pstResPagosClieTemp;
    DET_MOVIM_CLIE       *pstDetMovimClieTemp;
    DET_PAGOS_CLIE       *pstDetPagosClieTemp;
    DET_ABON_MOVIM_CLIE  *pstDetAbonMovimClieTemp;
    DET_ABON_PAGOS_CLIE  *pstDetAbonPagosClieTemp;
    long                 lCont;
    long   			     lNum_Folio_Rel;
    char   				 szPrefPlaza_Rel[11];

    vDTrazasLog (szExeName,"\n\t* Carga Detalle de Transacciones del Cliente [%ld] ", LOG06,lCodCliente);

    strcpy(pstDetTrans->szFecDesde,sthFa_CicloFact->fec_desde);
    strcpy(pstDetTrans->szFecHasta,sthFa_CicloFact->fec_hasta);
    pstDetTrans->dTotalTransDebe   = 0;
    pstDetTrans->dTotalTransHaber  = 0;
    pstDetTrans->dTotalTransSaldo  = 0;

    /*Inicio Movimientos del Cliente*/
    pstMovimClieTemp = &pstDetTrans->stMovimClie;
    memset(pstMovimClieTemp, 0, sizeof(MOVIM_CLIE)*1);

    pstMovimClieTemp->iNumRegResMov  = 0;
    pstMovimClieTemp->iNumRegDetMov  = 0;
    /*Fin Movimientos del Cliente*/

    /*Inicio Pagos del Cliente*/
    pstPagosClieTemp = &pstDetTrans->stPagosClie;
    memset(pstPagosClieTemp, 0, sizeof(PAGOS_CLIE)*1);

    pstPagosClieTemp->iNumRegResPag  = 0;
    pstPagosClieTemp->iNumRegDetPag  = 0;
    /*Fin Pagos del Cliente*/

    if (ifnOpenDetTransClie(sthFa_CicloFact,lCodCliente,lCodCiclFact))
        return FALSE;

    while (rc != SQLNOTFOUND)
    {
        rc = bfnFetchDetTransClie(&stDetTransClieHost,&lNumFilas);
        if (rc != SQLOK  && rc != SQLNOTFOUND)
        return FALSE;

        vDTrazasLog (szExeName,"\n\t* lNumFilas [%ld] ", LOG06,lNumFilas);
        if (!lNumFilas)
            break;

        for (lCont = 0 ; lCont < lNumFilas ; lCont++)
        {
            /*INICIO TOTALES TRANSACCIONES*/
            pstDetTrans->dTotalTransDebe  +=stDetTransClieHost.dMontoDebe      [lCont];
            pstDetTrans->dTotalTransHaber +=stDetTransClieHost.dMontoHaber     [lCont];
            pstDetTrans->dTotalTransSaldo +=stDetTransClieHost.dMontoSaldo     [lCont];
            /*FIN TOTALES TRANSACCIONES*/
            if (stDetTransClieHost.iIndPago[lCont]== 0) /*Movimiento*/
            {
                /* INICIO DETALLE DE MOVIEMIENTOS*/
                if(stDetTransClieHost.iIndDetalle[lCont] == 1 )
                {
                    ihNumRegTrans = pstMovimClieTemp->iNumRegDetMov;
                    iFlagTrans = FALSE;

                    for (iIdxTrans = 0 ; iIdxTrans < ihNumRegTrans; iIdxTrans++)
                    {
                        if ( pstMovimClieTemp->stDetMovimClie[iIdxTrans].lNumAbonado == stDetTransClieHost.lNumAbonado[lCont] )
                        {
                            pstDetMovimClieTemp = &pstMovimClieTemp->stDetMovimClie[iIdxTrans];

                            pstDetMovimClieTemp->dMontoDetDebe  += stDetTransClieHost.dMontoDebe      [lCont];
                            pstDetMovimClieTemp->dMontoDetHaber += stDetTransClieHost.dMontoHaber     [lCont];

                            pstDetMovimClieTemp->stDetAbonMovimClie = (DET_ABON_MOVIM_CLIE*) realloc(pstDetMovimClieTemp->stDetAbonMovimClie,((pstDetMovimClieTemp->lCantReg + 1)*sizeof(DET_ABON_MOVIM_CLIE)));
                            if (!pstDetMovimClieTemp->stDetAbonMovimClie)
                            {
                                iDError (szExeName,ERR000,vInsertarIncidencia,
                                              "Error pstDetMovimClieTemp->stDetAbonMovimClie", "No se pudo reservar memoria");
                                return FALSE;
                            }
                            pstDetAbonMovimClieTemp = &pstDetMovimClieTemp->stDetAbonMovimClie[(pstDetMovimClieTemp->lCantReg)];
                            memset(pstDetAbonMovimClieTemp, 0, sizeof(DET_ABON_MOVIM_CLIE)*1);

                            strcpy(pstDetAbonMovimClieTemp->szFecTrans   , stDetTransClieHost.szFecTrans      [lCont]);
                            strcpy(pstDetAbonMovimClieTemp->szCodOficina , stDetTransClieHost.szCodOficina    [lCont]);
                            strcpy(pstDetAbonMovimClieTemp->szCodPlaza   , stDetTransClieHost.szCodPlaza      [lCont]);
                            pstDetAbonMovimClieTemp->iCodTipDocum        = stDetTransClieHost.iCodTipDocum    [lCont];
                            pstDetAbonMovimClieTemp->lNumFolio           = stDetTransClieHost.lNumFolio       [lCont];
                            pstDetAbonMovimClieTemp->lNumCuota           = stDetTransClieHost.lNumCuota       [lCont];
                            pstDetAbonMovimClieTemp->lNumTotalCuota      = stDetTransClieHost.lNumTotalCuota  [lCont];
                            pstDetAbonMovimClieTemp->dMontoDetDebe       = stDetTransClieHost.dMontoDebe      [lCont];
                            pstDetAbonMovimClieTemp->dMontoDetHaber      = stDetTransClieHost.dMontoHaber     [lCont];
                            pstDetAbonMovimClieTemp->dMontoDetSaldo      = stDetTransClieHost.dMontoSaldo     [lCont];
							
							strcpy(pstDetAbonMovimClieTemp->sz_IndAcelerada, stDetTransClieHost.sz_IndAcelerada[lCont]); /*para acelerada */

                            strcpy(pstDetAbonMovimClieTemp->szCodRegistro , stDetTransClieHost.szCodRegistro   [lCont]);

							if ( pstDetAbonMovimClieTemp->iCodTipDocum == stDatosGener.iCodNotaCre )
							{
				                if ( !bfnFolioRelacionado(lCodCliente,
		                                          pstDetAbonMovimClieTemp->lNumFolio,
		                                          pstDetAbonMovimClieTemp->szCodPlaza,
		                                          &lNum_Folio_Rel,
		                                          szPrefPlaza_Rel) )
		                        {
		                            iDError (szExeName,ERR000,vInsertarIncidencia,
		                                          "Error No se pudo obtener detalle documento de origen"
		                                          , "Obtiene folio rel");
		                            return FALSE;
		                        }

		                        pstDetAbonMovimClieTemp->lNumFolioRel = lNum_Folio_Rel;
		                        strcpy (pstDetAbonMovimClieTemp->szPrefPlazaRel, szPrefPlaza_Rel);

		                        stDetTransClieHost.lNumFolioRel           [lCont] = lNum_Folio_Rel;
	                        	strcpy (stDetTransClieHost.szPrefPlazaRel [lCont], szPrefPlaza_Rel);
	    					}

                            pstDetMovimClieTemp->lCantReg++;

                            iFlagTrans = TRUE;

                            break;
                        }
                    }

                    if (!iFlagTrans)
                    {
                        pstMovimClieTemp->stDetMovimClie =(DET_MOVIM_CLIE*) realloc(pstMovimClieTemp->stDetMovimClie,((ihNumRegTrans + 1)*sizeof(DET_MOVIM_CLIE)));
                        if (!pstMovimClieTemp->stDetMovimClie)
                        {
                            iDError (szExeName,ERR000,vInsertarIncidencia,
                                          "Error pstMovimClieTemp->stDetMovimClie", "No se pudo reservar memoria");
                            return FALSE;
                        }
                        pstDetMovimClieTemp = &pstMovimClieTemp->stDetMovimClie[ihNumRegTrans];
                        memset(pstDetMovimClieTemp, 0, sizeof(DET_MOVIM_CLIE)*1);

                        pstDetMovimClieTemp->lCantReg=0;
                        pstDetMovimClieTemp->lNumAbonado    = stDetTransClieHost.lNumAbonado [lCont];
                        pstDetMovimClieTemp->dMontoDetDebe  = stDetTransClieHost.dMontoDebe  [lCont];
                        pstDetMovimClieTemp->dMontoDetHaber = stDetTransClieHost.dMontoHaber [lCont];


                        pstDetMovimClieTemp->stDetAbonMovimClie =(DET_ABON_MOVIM_CLIE*) realloc(pstDetMovimClieTemp->stDetAbonMovimClie,((pstDetMovimClieTemp->lCantReg + 1)*sizeof(DET_ABON_MOVIM_CLIE)));
                        if (!pstDetMovimClieTemp->stDetAbonMovimClie)
                        {
                            iDError (szExeName,ERR000,vInsertarIncidencia,
                                          "Error pstDetMovimClieTemp->stDetAbonMovimClie", "No se pudo reservar memoria");
                            return FALSE;
                        }
                        pstDetAbonMovimClieTemp = &pstDetMovimClieTemp->stDetAbonMovimClie[(pstDetMovimClieTemp->lCantReg)];
                        memset(pstDetAbonMovimClieTemp, 0, sizeof(DET_ABON_MOVIM_CLIE)*1);

                        strcpy(pstDetAbonMovimClieTemp->szFecTrans   , stDetTransClieHost.szFecTrans      [lCont]);
                        strcpy(pstDetAbonMovimClieTemp->szCodOficina , stDetTransClieHost.szCodOficina    [lCont]);
                        strcpy(pstDetAbonMovimClieTemp->szCodPlaza   , stDetTransClieHost.szCodPlaza      [lCont]);
                        pstDetAbonMovimClieTemp->iCodTipDocum        = stDetTransClieHost.iCodTipDocum    [lCont];
                        pstDetAbonMovimClieTemp->lNumFolio           = stDetTransClieHost.lNumFolio       [lCont];
                        pstDetAbonMovimClieTemp->lNumCuota           = stDetTransClieHost.lNumCuota       [lCont];
                        pstDetAbonMovimClieTemp->lNumTotalCuota      = stDetTransClieHost.lNumTotalCuota  [lCont];
                        pstDetAbonMovimClieTemp->dMontoDetDebe       = stDetTransClieHost.dMontoDebe      [lCont];
                        pstDetAbonMovimClieTemp->dMontoDetHaber      = stDetTransClieHost.dMontoHaber     [lCont];
                        pstDetAbonMovimClieTemp->dMontoDetSaldo      = stDetTransClieHost.dMontoSaldo     [lCont];
						
						strcpy(pstDetAbonMovimClieTemp->sz_IndAcelerada, stDetTransClieHost.sz_IndAcelerada[lCont]); /*para acelerada */

                        strcpy(pstDetAbonMovimClieTemp->szCodRegistro, stDetTransClieHost.szCodRegistro   [lCont]);

                        if ( pstDetAbonMovimClieTemp->iCodTipDocum == stDatosGener.iCodNotaCre )
						{
			                if ( !bfnFolioRelacionado(lCodCliente,
	                                          pstDetAbonMovimClieTemp->lNumFolio,
	                                          pstDetAbonMovimClieTemp->szCodPlaza,
	                                          &lNum_Folio_Rel,
	                                          szPrefPlaza_Rel) )
	                        {
	                            iDError (szExeName,ERR000,vInsertarIncidencia,
	                                          "Error No se pudo obtener detalle documento de origen"
	                                          , "Obtiene folio rel");
	                            return FALSE;
	                        }

	                        pstDetAbonMovimClieTemp->lNumFolioRel = lNum_Folio_Rel;
	                        strcpy (pstDetAbonMovimClieTemp->szPrefPlazaRel, szPrefPlaza_Rel);

	                        stDetTransClieHost.lNumFolioRel           [lCont] = lNum_Folio_Rel;
	                        strcpy (stDetTransClieHost.szPrefPlazaRel [lCont], szPrefPlaza_Rel);
    					}

                        pstDetMovimClieTemp->lCantReg++;

                        pstMovimClieTemp->iNumRegDetMov++;
                    }
                }
                /* FIN DETALLE DE MOVIEMIENTOS*/

                /* INICIO RESUMEN DE MOVIEMIENTOS*/
                if(strcmp(stDetTransClieHost.szCodOrigen [lCont],"FDOCU")==0 &&
                          stDetTransClieHost.iIndCaratula[lCont] == 0)
                {
                    ihNumRegTrans = pstMovimClieTemp->iNumRegResMov;
                    iFlagTrans = FALSE;

                    for (iIdxTrans = 0 ; iIdxTrans < ihNumRegTrans; iIdxTrans++)
                    {
                        if ( pstMovimClieTemp->stResMovimClie[iIdxTrans].iCodTipDocum    == stDetTransClieHost.iCodTipDocum[lCont] &&
                             strcmp(pstMovimClieTemp->stResMovimClie[iIdxTrans].szCodPlaza, stDetTransClieHost.szCodPlaza[lCont])==0 &&
                             pstMovimClieTemp->stResMovimClie[iIdxTrans].lNumFolio       == stDetTransClieHost.lNumFolio[lCont])
                        {
                            pstMovimClieTemp->stResMovimClie[iIdxTrans].dTotalFactura += stDetTransClieHost.dMontoDebe[lCont];
                            iFlagTrans = TRUE;
                        }
                    }

                    if (!iFlagTrans)
                    {
                        pstMovimClieTemp->stResMovimClie =(RES_MOVIM_CLIE*) realloc(pstMovimClieTemp->stResMovimClie,((ihNumRegTrans + 1)*sizeof(RES_MOVIM_CLIE)));
                        if (!pstMovimClieTemp->stResMovimClie)
                        {
                            iDError (szExeName,ERR000,vInsertarIncidencia,
                                          "Error pstMovimClieTemp->stResMovimClie", "No se pudo reservar memoria");
                            return FALSE;
                        }
                        pstResMovimClieTemp = &pstMovimClieTemp->stResMovimClie[ihNumRegTrans];
                        memset(pstResMovimClieTemp, 0, sizeof(RES_MOVIM_CLIE)*1);

                        strcpy(pstResMovimClieTemp->szCodOficina, stDetTransClieHost.szCodOficina [lCont]);
                        pstResMovimClieTemp->iCodTipDocum       = stDetTransClieHost.iCodTipDocum [lCont];
                        strcpy(pstResMovimClieTemp->szCodPlaza  , stDetTransClieHost.szCodPlaza   [lCont]);
                        pstResMovimClieTemp->lNumFolio          = stDetTransClieHost.lNumFolio    [lCont];
                        strcpy(pstResMovimClieTemp->szFecTrans  , stDetTransClieHost.szFecTrans   [lCont]);
                        pstResMovimClieTemp->dTotalFactura      = stDetTransClieHost.dMontoDebe[lCont];

						/* para notas de credito se obtiene info dcumento de origen */
						if ( pstResMovimClieTemp->iCodTipDocum == stDatosGener.iCodNotaCre )
						{
							pstResMovimClieTemp->lNumFolioRel          = stDetTransClieHost.lNumFolioRel   [lCont];
	                        strcpy (pstResMovimClieTemp->szPrefPlazaRel, stDetTransClieHost.szPrefPlazaRel [lCont]);
    					}

                        pstMovimClieTemp->iNumRegResMov++;
                    }
                }
                /* FIN RESUMEN DE MOVIEMIENTOS*/

            }else{ /*Pagos*/

                /* INICIO DETALLE DE PAGOS*/
                if(stDetTransClieHost.iIndDetalle[lCont] == 1 )
                {
                    ihNumRegTrans = pstPagosClieTemp->iNumRegDetPag;
                    iFlagTrans = FALSE;

                    for (iIdxTrans = 0 ; iIdxTrans < ihNumRegTrans; iIdxTrans++)
                    {
                        if ( pstPagosClieTemp->stDetPagosClie[iIdxTrans].lNumAbonado == stDetTransClieHost.lNumAbonado[lCont] )
                        {

                            pstDetPagosClieTemp = &pstPagosClieTemp->stDetPagosClie[iIdxTrans];

                            pstDetPagosClieTemp->dMontoDetDebe  += stDetTransClieHost.dMontoDebe      [lCont];
                            pstDetPagosClieTemp->dMontoDetHaber += stDetTransClieHost.dMontoHaber     [lCont];


                            pstDetPagosClieTemp->stDetAbonPagosClie =(DET_ABON_PAGOS_CLIE*) realloc(pstDetPagosClieTemp->stDetAbonPagosClie,((pstDetPagosClieTemp->lCantReg + 1)*sizeof(DET_ABON_PAGOS_CLIE)));
                            if (!pstDetPagosClieTemp->stDetAbonPagosClie)
                            {
                                iDError (szExeName,ERR000,vInsertarIncidencia,
                                              "Error pstDetPagosClieTemp->stDetAbonPagosClie", "No se pudo reservar memoria");
                                return FALSE;
                            }

                            pstDetAbonPagosClieTemp = &pstDetPagosClieTemp->stDetAbonPagosClie[(pstDetPagosClieTemp->lCantReg)];
                            memset(pstDetAbonPagosClieTemp, 0, sizeof(DET_ABON_PAGOS_CLIE)*1);

                            strcpy(pstDetAbonPagosClieTemp->szFecTrans   , stDetTransClieHost.szFecTrans      [lCont]);
                            strcpy(pstDetAbonPagosClieTemp->szCodOficina , stDetTransClieHost.szCodOficina    [lCont]);
                            strcpy(pstDetAbonPagosClieTemp->szCodPlaza   , stDetTransClieHost.szCodPlaza      [lCont]);
                            pstDetAbonPagosClieTemp->iCodTipDocum        = stDetTransClieHost.iCodTipDocum    [lCont];
                            pstDetAbonPagosClieTemp->lNumFolio           = stDetTransClieHost.lNumFolio       [lCont];
                            pstDetAbonPagosClieTemp->lNumCuota           = stDetTransClieHost.lNumCuota       [lCont];
                            pstDetAbonPagosClieTemp->lNumTotalCuota      = stDetTransClieHost.lNumTotalCuota  [lCont];
                            pstDetAbonPagosClieTemp->dMontoDetDebe       = stDetTransClieHost.dMontoDebe      [lCont];
                            pstDetAbonPagosClieTemp->dMontoDetHaber      = stDetTransClieHost.dMontoHaber     [lCont];
                            pstDetAbonPagosClieTemp->dMontoDetSaldo      = stDetTransClieHost.dMontoSaldo     [lCont];
							
							strcpy(pstDetAbonPagosClieTemp->sz_IndAcelerada, stDetTransClieHost.sz_IndAcelerada[lCont]); /*para acelerada */

                            strcpy(pstDetAbonPagosClieTemp->szCodRegistro, stDetTransClieHost.szCodRegistro   [lCont]);

							if ( pstDetAbonPagosClieTemp->iCodTipDocum == stDatosGener.iCodNotaCre )
							{
				                if ( !bfnFolioRelacionado(lCodCliente,
		                                          pstDetAbonPagosClieTemp->lNumFolio,
		                                          pstDetAbonPagosClieTemp->szCodPlaza,
		                                          &lNum_Folio_Rel,
		                                          szPrefPlaza_Rel) )
		                        {
		                            iDError (szExeName,ERR000,vInsertarIncidencia,
		                                          "Error No se pudo obtener detalle documento de origen"
		                                          , "Obtiene folio rel");
		                            return FALSE;
		                        }

		                        pstDetAbonPagosClieTemp->lNumFolioRel = lNum_Folio_Rel;
		                        strcpy (pstDetAbonPagosClieTemp->szPrefPlazaRel, szPrefPlaza_Rel);

		                        stDetTransClieHost.lNumFolioRel           [lCont] = lNum_Folio_Rel;
	                        	strcpy (stDetTransClieHost.szPrefPlazaRel [lCont], szPrefPlaza_Rel);
	    					}

                            pstDetPagosClieTemp->lCantReg++;

                            iFlagTrans = TRUE;

                            break;
                        }
                    }

                    if (!iFlagTrans)
                    {

                        pstPagosClieTemp->stDetPagosClie =(DET_PAGOS_CLIE*) realloc(pstPagosClieTemp->stDetPagosClie,((ihNumRegTrans + 1)*sizeof(DET_PAGOS_CLIE)));
                        if (!pstPagosClieTemp->stDetPagosClie)
                        {
                            iDError (szExeName,ERR000,vInsertarIncidencia,
                                          "Error pstPagosClieTemp->stDetPagosClie", "No se pudo reservar memoria");
                            return FALSE;
                        }
                        pstDetPagosClieTemp = &pstPagosClieTemp->stDetPagosClie[ihNumRegTrans];
                        memset(pstDetPagosClieTemp, 0, sizeof(DET_PAGOS_CLIE)*1);

                        pstDetPagosClieTemp->lCantReg=0;
                        pstDetPagosClieTemp->lNumAbonado    = stDetTransClieHost.lNumAbonado [lCont];
                        pstDetPagosClieTemp->dMontoDetDebe  = stDetTransClieHost.dMontoDebe  [lCont];
                        pstDetPagosClieTemp->dMontoDetHaber = stDetTransClieHost.dMontoHaber [lCont];

                        pstDetPagosClieTemp->stDetAbonPagosClie =(DET_ABON_PAGOS_CLIE*) realloc(pstDetPagosClieTemp->stDetAbonPagosClie,((pstDetPagosClieTemp->lCantReg + 1)*sizeof(DET_ABON_PAGOS_CLIE)));
                        if (!pstDetPagosClieTemp->stDetAbonPagosClie)
                        {
                            iDError (szExeName,ERR000,vInsertarIncidencia,
                                          "Error pstDetPagosClieTemp->stDetAbonPagosClie", "No se pudo reservar memoria");
                            return FALSE;
                        }
                        pstDetAbonPagosClieTemp = &pstDetPagosClieTemp->stDetAbonPagosClie[(pstDetPagosClieTemp->lCantReg)];
                        memset(pstDetAbonPagosClieTemp, 0, sizeof(DET_ABON_PAGOS_CLIE)*1);

                        strcpy(pstDetAbonPagosClieTemp->szFecTrans   , stDetTransClieHost.szFecTrans      [lCont]);
                        strcpy(pstDetAbonPagosClieTemp->szCodOficina , stDetTransClieHost.szCodOficina    [lCont]);
                        strcpy(pstDetAbonPagosClieTemp->szCodPlaza   , stDetTransClieHost.szCodPlaza      [lCont]);
                        pstDetAbonPagosClieTemp->iCodTipDocum        = stDetTransClieHost.iCodTipDocum    [lCont];
                        pstDetAbonPagosClieTemp->lNumFolio           = stDetTransClieHost.lNumFolio       [lCont];
                        pstDetAbonPagosClieTemp->lNumCuota           = stDetTransClieHost.lNumCuota       [lCont];
                        pstDetAbonPagosClieTemp->lNumTotalCuota      = stDetTransClieHost.lNumTotalCuota  [lCont];
                        pstDetAbonPagosClieTemp->dMontoDetDebe       = stDetTransClieHost.dMontoDebe      [lCont];
                        pstDetAbonPagosClieTemp->dMontoDetHaber      = stDetTransClieHost.dMontoHaber     [lCont];
                        pstDetAbonPagosClieTemp->dMontoDetSaldo      = stDetTransClieHost.dMontoSaldo     [lCont];

                        strcpy(pstDetAbonPagosClieTemp->sz_IndAcelerada, stDetTransClieHost.sz_IndAcelerada[lCont]); /*para acelerada */

                        strcpy(pstDetAbonPagosClieTemp->szCodRegistro, stDetTransClieHost.szCodRegistro   [lCont]);


						if ( pstDetAbonPagosClieTemp->iCodTipDocum == stDatosGener.iCodNotaCre )
						{
			                if ( !bfnFolioRelacionado(lCodCliente,
	                                          pstDetAbonPagosClieTemp->lNumFolio,
	                                          pstDetAbonPagosClieTemp->szCodPlaza,
	                                          &lNum_Folio_Rel,
	                                          szPrefPlaza_Rel) )
	                        {
	                            iDError (szExeName,ERR000,vInsertarIncidencia,
	                                          "Error No se pudo obtener detalle documento de origen"
	                                          , "Obtiene folio rel");
	                            return FALSE;
	                        }

	                        pstDetAbonPagosClieTemp->lNumFolioRel = lNum_Folio_Rel;
	                        strcpy (pstDetAbonPagosClieTemp->szPrefPlazaRel, szPrefPlaza_Rel);

		                    stDetTransClieHost.lNumFolioRel           [lCont] = lNum_Folio_Rel;
	                        strcpy (stDetTransClieHost.szPrefPlazaRel [lCont], szPrefPlaza_Rel);
    					}

                        pstDetPagosClieTemp->lCantReg++;

                        pstPagosClieTemp->iNumRegDetPag++;
                    }
                }
                /* FIN DETALLE DE PAGOS*/


                /* INICIO RESUMEN DE PAGOS*/
                ihNumRegTrans = pstPagosClieTemp->iNumRegResPag;
                iFlagTrans = FALSE;

                for (iIdxTrans = 0 ; iIdxTrans < ihNumRegTrans; iIdxTrans++)
                {
                    if ( pstPagosClieTemp->stResPagosClie[iIdxTrans].iCodTipDocum == stDetTransClieHost.iCodTipDocum[lCont] )
                    {
                        pstPagosClieTemp->stResPagosClie[iIdxTrans].dTotalResDebe  += stDetTransClieHost.dMontoDebe      [lCont];
                        pstPagosClieTemp->stResPagosClie[iIdxTrans].dTotalResHaber += stDetTransClieHost.dMontoHaber     [lCont];
                        iFlagTrans = TRUE;
                    }
                }

                if (!iFlagTrans)
                {
                    pstPagosClieTemp->stResPagosClie =(RES_PAGOS_CLIE*) realloc(pstPagosClieTemp->stResPagosClie,((ihNumRegTrans + 1)*sizeof(RES_PAGOS_CLIE)));
                    if (!pstPagosClieTemp->stResPagosClie)
                    {
                        iDError (szExeName,ERR000,vInsertarIncidencia,
                                      "Error pstPagosClieTemp->stResPagosClie", "No se pudo reservar memoria");
                        return FALSE;
                    }
                    pstResPagosClieTemp = &pstPagosClieTemp->stResPagosClie[ihNumRegTrans];
                    memset(pstResPagosClieTemp, 0, sizeof(RES_PAGOS_CLIE)*1);

                    pstResPagosClieTemp->iCodTipDocum   = stDetTransClieHost.iCodTipDocum    [lCont];
                    pstResPagosClieTemp->dTotalResDebe  = stDetTransClieHost.dMontoDebe      [lCont];
                    pstResPagosClieTemp->dTotalResHaber = stDetTransClieHost.dMontoHaber     [lCont];

                    pstPagosClieTemp->iNumRegResPag++;
                }
                /* FIN RESUMEN DE PAGOS*/
            }
			/* P-ECU-09005 */
        	/* Inc 137275 PPV 10/06/2010 */
        	vDTrazasLog(szModulo,"\t\t lcont ==> [%ld]  stDetTransClieHost.szRowId[lCont] ==> [ %s ]",LOG05,lCont, stDetTransClieHost.szRowId[lCont]);
        	trim(stDetTransClieHost.szRowId[lCont],stDetTransClieHost.szRowId[lCont]);
        	/* Fin Inc 137275 PPV 10/06/2010 */

        	if (!lNroJob && strcmp(stDetTransClieHost.szRowId[lCont],"CANCE")!=0)
            {
            	    /* EXEC SQL
            	   		UPDATE FA_BALANCE_TO
            	   		   SET NUM_PROCESO  = :lNumProceso,
                        	   COD_CICLFACT = :lCodCiclFact
                         WHERE ROWID = :stDetTransClieHost.szRowId[lCont]; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 47;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.stmt = "update FA_BALANCE_TO  set NUM_PROCESO=:b0,CO\
D_CICLFACT=:b1 where ROWID=:b2";
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )2499;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqhstv[0] = (unsigned char  *)&lNumProceso;
                 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)0;
                 sqlstm.sqinds[0] = (         int  )0;
                 sqlstm.sqharm[0] = (unsigned long )0;
                 sqlstm.sqadto[0] = (unsigned short )0;
                 sqlstm.sqtdso[0] = (unsigned short )0;
                 sqlstm.sqhstv[1] = (unsigned char  *)&lCodCiclFact;
                 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                 sqlstm.sqhsts[1] = (         int  )0;
                 sqlstm.sqindv[1] = (         short *)0;
                 sqlstm.sqinds[1] = (         int  )0;
                 sqlstm.sqharm[1] = (unsigned long )0;
                 sqlstm.sqadto[1] = (unsigned short )0;
                 sqlstm.sqtdso[1] = (unsigned short )0;
                 sqlstm.sqhstv[2] = (unsigned char  *)(stDetTransClieHost.szRowId)[lCont];
                 sqlstm.sqhstl[2] = (unsigned long )19;
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
                     vDTrazasLog(szModulo, "Error en EXECUTE sql_Update_FaBalanceTo. Error [%i][%s]"
                                         , LOG00, sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
                     return(FALSE);
                }
            }
/* P-ECU-09005 */
        } /* fin for */

    }/* fin while */

    vDTrazasLog (szExeName,"\n\t\t* FIN Detalle de Transacciones del Cliente -> CanRegistros[%ld]", LOG06, lNumFilas);

    rc = ifnCloseDetTransClie();
    if (rc != SQLOK)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Error bfnCargaDetTransClie", szfnORAerror ());
        return FALSE;
    }
    return (TRUE);
}/** END bfnCargaDetTransClie **/



void vfnPrintCod_PlanTarif (PLAN_TARIFARIO *pstCodPlanTarif, int iNumCodPlanes)
{
    int i = 0;
    char *szModulo="vfnPrintCod_PlanTarif";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Planes Tarifarios [%d]", LOG06, iNumCodPlanes);

        for ( i=0;i<iNumCodPlanes;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Codigo de Plan        [%s]"
                         "\n\t\t=> [%d]: Descripcion del Plan  [%s]"
                         "\n\t\t=> [%d]: Tipo del Plan         [%s]"
                         "\n\t\t=> [%d]: Minutos del Plan      [%ld]"
                         "\n\t\t=> [%d]: Valor Plan            [%f]"
                         "\n\t\t=> [%d]: Indicador de Arrastre [%ld]"
                         ,LOG06
                         ,i, pstCodPlanTarif[i].szCod_Plantarif
                         ,i, pstCodPlanTarif[i].szDes_Plantarif
                         ,i, pstCodPlanTarif[i].szTip_Plantarif
                         ,i, pstCodPlanTarif[i].lMinutosPlan
                         ,i, pstCodPlanTarif[i].dValorPlan
                         ,i, pstCodPlanTarif[i].iInd_Arrastre   );
        }
    }
}/*************************** vfnPrintCod_PlanTarif *****************************/


int ifnCmpCod_PlanTarif(const void *cad1,const void *cad2)
{
    return( strcmp (((PLAN_TARIFARIO  *)cad1)->szCod_Plantarif,((PLAN_TARIFARIO  *)cad2)->szCod_Plantarif) );

}/*************************** ifnCmpCod_PlanTarif *****************************/


BOOL bfnFindCod_PlanTarif (char *szCodPlanTarif, PLAN_TARIFARIO *pstCodPlanTarif)
{
    char *szModulo="bfnFindCod_PlanTarif" ;
    PLAN_TARIFARIO  stkey;
    PLAN_TARIFARIO  *pstAux = (PLAN_TARIFARIO *)NULL;

    if ( strcmp(szCodPlanTarif,"")!= 0 )
    {
        strcpy(szCodPlanTarif,alltrim(szCodPlanTarif));
    }

    vDTrazasLog (szModulo, "\n\t\t* Busca Codigo de Plan Tarifario "
                 "\n\t\t=> Cod. Plan Tarifario   [%s]"
                 , LOG05,szCodPlanTarif );

    strcpy(stkey.szCod_Plantarif, szCodPlanTarif);

    if ( pstPlanes.iNumRegPlanTarif > 0 )
    {
        if ( (pstAux = (PLAN_TARIFARIO *)bsearch(&stkey, pstPlanes.stPlanesTarifarios , pstPlanes.iNumRegPlanTarif,
                                                 sizeof (PLAN_TARIFARIO),ifnCmpCod_PlanTarif ))== (PLAN_TARIFARIO *)NULL )
        {
            vDTrazasLog(szModulo, "Codigo de Plan Tarifario [%s] no encontrado ...", LOG01, szCodPlanTarif);
            return(FALSE);
        }
        memcpy (pstCodPlanTarif, pstAux, sizeof(PLAN_TARIFARIO));
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Planes tarifarios ...", LOG01);
    }
    return(TRUE);
}


#ifndef isnull
    #define isnull(name) (name==(char )NULL )
#endif
#ifndef strnull
    #define strnull(name) (name==(char *)NULL || name[0]==(char)NULL)
#endif

char *ltrim(char *s)
{
    char *p=s;
    if ( strnull(s) )
        return(s);
    while ( *p<=32 && *p>1 ) p++;
    strcpy(s,p);
    return(s);
}

char *rtrim(char *s)
{
    char *p=NULL;
    if ( strnull(s) )
        return(s);
    p=(s+_strlen(s)-1);
    while ( *p<=32 && *p>1 )  p--;
    *(++p)=0;
    return(s);
}

char *alltrim(char *s)
{
    return(ltrim(rtrim(s)));
}

/****************************************************************************/
/*                             funcion : CargaMultiIdiomas                  */
/****************************************************************************/
BOOL CargaMultiIdiomas (GRPMULTIIDIOMA **pstGrpMulti, int *iNumGrpMulti)
{
    int     rc = 0;
    int    iNumFilas;
    static  GRPMULTIIDIOMAS_HOSTS stGrpMultiHost;
    GRPMULTIIDIOMA *pstGrpMultiTemp;
    int  iCont;

    char *szModulo="CargaMultiIdiomas";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG06,szModulo);

    *iNumGrpMulti = 0;
    *pstGrpMulti = NULL;

    if ( OpenMultiIdiomas() )
        return(FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = FetchMultiIdiomas (&stGrpMultiHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return(FALSE);

        if ( !iNumFilas )
            break;

        *pstGrpMulti =(GRPMULTIIDIOMA*) realloc(*pstGrpMulti,(int)(((*iNumGrpMulti)+iNumFilas)*sizeof(GRPMULTIIDIOMA)));

        if ( !*pstGrpMulti )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,"Error CargaMultiIdiomas", "no se pudo reservar memoria");
            return(FALSE);
        }

        pstGrpMultiTemp = &(*pstGrpMulti)[(*iNumGrpMulti)];
        memset(pstGrpMultiTemp, 0, (int)(sizeof(GRPMULTIIDIOMA)*iNumFilas));

        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy(pstGrpMultiTemp[iCont].szCod_Idioma_Grupos   ,alltrim(stGrpMultiHost.szCod_Idioma_Grupos [iCont]));
            strcpy(pstGrpMultiTemp[iCont].szGlosa_Grupo         ,stGrpMultiHost.szGlosa_Grupo   [iCont]);
            strcpy(pstGrpMultiTemp[iCont].szGlosa_Subgrp        ,alltrim(stGrpMultiHost.szGlosa_Subgrp  [iCont]));
        }
        (*iNumGrpMulti) += iNumFilas;
    }/* fin while */

    rc = CloseMultiIdiomas();
    if ( rc == SQLNOTFOUND )
        return (TRUE);

    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error CargaMultiIdiomas", szfnORAerror ());
        return(FALSE);
    }
    if ( *iNumGrpMulti > 0 )
    {
        qsort((void*)*pstGrpMulti, *iNumGrpMulti, sizeof(GRPMULTIIDIOMA),ifnCmpGrpMulti);
        vfnPrintGrpMulti (*pstGrpMulti, *iNumGrpMulti);
    }
    return(TRUE);
}/***************************** Final CargaMultiIdiomas *********************/


/****************************************************************************/
/*                             funcion : OpenMultiIdiomas                   */
/****************************************************************************/
int OpenMultiIdiomas ( void )
{
    char *szModulo="OpenMultiIdiomas";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL DECLARE curMultiIdiomas CURSOR FOR
    SELECT substr(TO_CHAR(TO_NUMBER(substr(C.COD_CONCEPTO,1,4)),'0009'),2) || C.COD_IDIOMA CONCEPTO,
           substr(B.DES_CONCEPTO,1,50),
           substr(C.DES_CONCEPTO,1,50)
    FROM FAD_IMPSUBGRUPOS A,
         GE_MULTIIDIOMA B,
         GE_MULTIIDIOMA C
    WHERE TO_CHAR(A.COD_GRUPO)=B.COD_CONCEPTO
      AND B.NOM_TABLA='FAD_IMPGRUPOS' AND B.NOM_CAMPO='COD_GRUPOS'
      AND TO_CHAR(A.COD_SUBGRUPO)=C.COD_CONCEPTO
      AND C.NOM_TABLA='FAD_IMPSUBGRUPOS' AND C.NOM_CAMPO='COD_SUBGRUPO'
      AND B.COD_IDIOMA=C.COD_IDIOMA
    ORDER BY CONCEPTO; */ 


    /* EXEC SQL OPEN curMultiIdiomas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0052;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2526;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curMultiIdiomas **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curMultiIdiomas **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return(SQLCODE);
    }
    return(SQLCODE);
}/*********************** Final de OpenMultiIdiomas ***********************/


/****************************************************************************/
/* Funcion: int FetchMultiIdiomas                                           */
/* Funcion que realiza Fetch en el cursor de curMultiIdiomas                     */
/****************************************************************************/
BOOL FetchMultiIdiomas (GRPMULTIIDIOMAS_HOSTS *pstHost,int  *piNumFilas)
{
    char *szModulo="FetchMultiIdiomas";

    /* EXEC SQL FETCH curMultiIdiomas
    INTO    :pstHost->szCod_Idioma_Grupos,
    :pstHost->szGlosa_Grupo ,
    :pstHost->szGlosa_Subgrp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )2541;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->szCod_Idioma_Grupos);
    sqlstm.sqhstl[0] = (unsigned long )6;
    sqlstm.sqhsts[0] = (         int  )6;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szGlosa_Grupo);
    sqlstm.sqhstl[1] = (unsigned long )51;
    sqlstm.sqhsts[1] = (         int  )51;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->szGlosa_Subgrp);
    sqlstm.sqhstl[2] = (unsigned long )51;
    sqlstm.sqhsts[2] = (         int  )51;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> Oficinas",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final FetchMultiIdiomas ****************/


/****************************************************************************/
/*  Funcion: int CloseMultiIdiomas(void)                                   */
/*  Funcion que cierra el cursor de curMultiIdiomas                           */
/****************************************************************************/
int CloseMultiIdiomas(void)
{
    char *szModulo="CloseMultiIdiomas";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL CLOSE curMultiIdiomas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2568;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor curMultiIdiomas: %s",LOG01, SQLERRM);
    }
    return(SQLCODE);
}/****************Final de CloseMultiIdiomas *******************/


/****************************************************************************/
/*                           funcion : vfnPrintFaCiclFact                   */
/****************************************************************************/
void vfnPrintGrpMulti (GRPMULTIIDIOMA *pstEstruc, int iNumRegs)
{
    int i = 0;
    char *szModulo="vfnPrintGrpMulti";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Grupos Multiidiomas [%d]", LOG06, iNumRegs);

        for ( i=0;i<iNumRegs;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Codigo Idioma   [%s]"
                         "\n\t\t=> [%d]: Glosa Grupo     [%s]"
                         "\n\t\t=> [%d]: Glosa SubGrupo  [%s]"
                         ,LOG06
                         ,i, pstEstruc[i].szCod_Idioma_Grupos
                         ,i, pstEstruc[i].szGlosa_Grupo
                         ,i, pstEstruc[i].szGlosa_Subgrp);
        }
    }
}/*************************** vfnPrintOperadoras *****************************/


/****************************************************************************/
/*                             funcion : ifnCmpGrpMulti                     */
/****************************************************************************/
int ifnCmpGrpMulti (const void *cad1,const void *cad2)
{
    return( strcmp (((GRPMULTIIDIOMA *)cad1)->szCod_Idioma_Grupos
                    ,((GRPMULTIIDIOMA *)cad2)->szCod_Idioma_Grupos) );

}/*********************** Final de ifnCmpGrpMulti ***************************/


/****************************************************************************/
/*  Funcion: int BuscaMultiIdiomas                                          */
/*  Funcion que busca un Concepto                                           */
/****************************************************************************/
BOOL BuscaMultiIdiomas (char *szCod_Multiidioma, GRPMULTIIDIOMA *pstGrpMulti )
{
    GRPMULTIIDIOMA  stkey;
    GRPMULTIIDIOMA  *pstAux = (GRPMULTIIDIOMA *)NULL;
    char *szModulo="BuscaMultiIdiomas";

    vDTrazasLog (szModulo, "\n\t\t* Busca Grupo Multiidioma "
                 "\n\t\t=> Codigo      [%s]"
                 "\n\t\t=> Num.Grupos  [%d]"
                 , LOG05,szCod_Multiidioma, stGrpMultiidiomas.iNumRegs);

    strcpy (stkey.szCod_Idioma_Grupos,szCod_Multiidioma);

    if ( stGrpMultiidiomas.iNumRegs > 0 )
    {
        if ( (pstAux = (GRPMULTIIDIOMA *)bsearch (&stkey, stGrpMultiidiomas.stGrpIdiomas, stGrpMultiidiomas.iNumRegs,
                                                  sizeof (GRPMULTIIDIOMA),ifnCmpGrpMulti ))== (GRPMULTIIDIOMA *)NULL )
        {
            vDTrazasLog(szModulo, "Codigo [%s] no encontrado ", LOG01, szCod_Multiidioma);
            return(FALSE);
        }
        memcpy (pstGrpMulti, pstAux, sizeof(GRPMULTIIDIOMA));
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Multiidiomas ...", LOG01);
    }
    return (TRUE);
}/**************************** Final BuscaMultiIdiomas *********************/


/****************************************************************************/
/*                     funcion : CargaNumOrden                              */
/*  recupera los Numero de Orden de los Grupos, SubGrupos y Conceptos       */
/****************************************************************************/
BOOL CargaNumOrden (NUMORDEN **pstNumOrden, int *iNumRegs, int iCodFormulario )
{
    int     rc = 0;
    int    iNumFilas;
    static  NUMORDENES_HOSTS stNumOrdenHost;
    NUMORDEN *pstNumOrdenTemp;
    int  iCont;

    char *szModulo="CargaNumOrden";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG06,szModulo);

    *iNumRegs = 0;
    *pstNumOrden = NULL;

    if ( OpenNumOrden(iCodFormulario) )
        return(FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = FetchNumOrden (&stNumOrdenHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return(FALSE);

        if ( !iNumFilas )
            break;

        *pstNumOrden =(NUMORDEN*) realloc(*pstNumOrden,(int)(((*iNumRegs)+iNumFilas)*sizeof(NUMORDEN)));

        if ( !*pstNumOrden )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error CargaNumOrden", "no se pudo reservar memoria");
            return(FALSE);
        }

        pstNumOrdenTemp = &(*pstNumOrden)[(*iNumRegs)];
        memset(pstNumOrdenTemp, 0, (int)(sizeof(NUMORDEN)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            pstNumOrdenTemp[iCont].iNum_OrdenGr     = stNumOrdenHost.iNum_OrdenGr[iCont];
            pstNumOrdenTemp[iCont].iNum_OrdenSubGr  = stNumOrdenHost.iNum_OrdenSubGr[iCont];
            pstNumOrdenTemp[iCont].iNum_OrdenConc   = stNumOrdenHost.iNum_OrdenConc[iCont];
            pstNumOrdenTemp[iCont].iCodGrupo        = stNumOrdenHost.iCodGrupo[iCont];
            pstNumOrdenTemp[iCont].iCodSubGrupo     = stNumOrdenHost.iCodSubGrupo[iCont];
            pstNumOrdenTemp[iCont].iCodConcepto     = stNumOrdenHost.iCodConcepto[iCont];
            strcpy(pstNumOrdenTemp[iCont].szCodRegistro ,alltrim(stNumOrdenHost.szCodRegistro[iCont]));
            pstNumOrdenTemp[iCont].iCodCriterio = stNumOrdenHost.iCodCriterio[iCont];
            pstNumOrdenTemp[iCont].iTipo_Llamada    = stNumOrdenHost.iTipo_Llamada[iCont];
            pstNumOrdenTemp[iCont].iTipo_SubGrupo   = stNumOrdenHost.iTipo_SubGrupo[iCont];
        }
        (*iNumRegs) += iNumFilas;
    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Numeros de Orden cargados [%ld]", LOG06, *iNumRegs);

    rc = CloseNumOrden();

    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error CargaNumOrden", szfnORAerror ());
        return(FALSE);
    }

    qsort((void*)*pstNumOrden, *iNumRegs, sizeof(NUMORDEN),ifnCmpNumOrden);
    vfnPrintNumOrden (*pstNumOrden, *iNumRegs);
    return(TRUE);
}/***************************** Final CargaNumOrden *************************/


/****************************************************************************/
/*                             funcion : OpenNumOrden                   */
/****************************************************************************/
int OpenNumOrden ( int iCodFormulario )
{
    char *szModulo="OpenNumOrden";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    ihZero = 0;

    /* EXEC SQL DECLARE curNumOrden CURSOR FOR
    SELECT  C.NUM_ORDEN GRP     ,
    B.NUM_ORDEN SGRP    ,
    A.NUM_ORDEN CONC    ,
    C.COD_GRUPO     ,
    B.COD_SUBGRUPO      ,
    A.COD_CONCEPTO      ,
    NVL(B.COD_REGISTRO,'D3001') ,
    NVL(B.CRIT_ORDEN,:ihZero) ,
    NVL(B.COD_TIPLLAMADA,:ihZero) ,
    B.COD_TIPSUBGRUPO
    FROM    FAD_IMPCONCEPTOS A  ,
    FAD_IMPSUBGRUPOS B  ,
    FAD_IMPGRUPOS C
    WHERE   A.COD_CONCEPTO  > :ihZero
    AND     A.COD_SUBGRUPO  = B.COD_SUBGRUPO
                              AND     B.COD_GRUPO     = C.COD_GRUPO
                              AND     C.COD_FORMULARIO= :iCodFormulario
                              ORDER BY A.COD_CONCEPTO; */ 


    /* EXEC SQL OPEN curNumOrden; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0053;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2583;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iCodFormulario;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-OPEN CURSOR curNumOrden **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-OPEN CURSOR curNumOrden **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return(SQLCODE);
    }
    return(SQLCODE);
}/*********************** Final de OpenNumOrden ***********************/


/****************************************************************************/
/* Funcion: int FetchNumOrden                                               */
/* Funcion que realiza Fetch en el cursor de curNumOrden                    */
/****************************************************************************/
BOOL FetchNumOrden (NUMORDENES_HOSTS *pstHost,int *piNumFilas)
{
    char *szModulo="FetchNumOrden";

    /* EXEC SQL FETCH curNumOrden
    INTO    :pstHost->iNum_OrdenGr      ,
    :pstHost->iNum_OrdenSubGr   ,
    :pstHost->iNum_OrdenConc    ,
    :pstHost->iCodGrupo     ,
    :pstHost->iCodSubGrupo      ,
    :pstHost->iCodConcepto      ,
    :pstHost->szCodRegistro     ,
    :pstHost->iCodCriterio      ,
    :pstHost->iTipo_Llamada     ,
    :pstHost->iTipo_SubGrupo    ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )2614;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->iNum_OrdenGr);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->iNum_OrdenSubGr);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )sizeof(int);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->iNum_OrdenConc);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )sizeof(int);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->iCodGrupo);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(int);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->iCodSubGrupo);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(int);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstHost->iCodConcepto);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(int);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstHost->szCodRegistro);
    sqlstm.sqhstl[6] = (unsigned long )6;
    sqlstm.sqhsts[6] = (         int  )6;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstHost->iCodCriterio);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(int);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstHost->iTipo_Llamada);
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(int);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstHost->iTipo_SubGrupo);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(int);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> Num.Orden", szfnORAerror ());

    return (SQLCODE);
}/***************************** Final FetchNumOrden *********************/


/****************************************************************************/
/*  Funcion: int CloseNumOrden(void)                                        */
/*  Funcion que cierra el cursor de CloseNumOrden                           */
/****************************************************************************/
int CloseNumOrden(void)
{
    char *szModulo="CloseNumOrden";

    vDTrazasLog(szModulo,"\tEntrando a %s ",LOG04,szModulo);

    /* EXEC SQL CLOSE curNumOrden; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2669;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor curNumOrden: %s",LOG01, SQLERRM);
    }
    return(SQLCODE);
}/****************Final de CloseNumOrden *******************/


/****************************************************************************/
/*                             funcion : ifnCmpNumOrden                     */
/****************************************************************************/
int ifnCmpNumOrden (const void *cad1,const void *cad2)
{
    return( ((NUMORDEN *)cad1)->iCodConcepto -((NUMORDEN *)cad2)->iCodConcepto) ;

}/*********************** Final de ifnCmpNumOrden ***************************/


/****************************************************************************/
/*  Funcion: int BuscaNumOrden                                              */
/*  Funcion que busca para un Concepto el orden de impresion                */
/****************************************************************************/
BOOL BuscaNumOrden (int iCodConcepto, NUMORDEN *pstNumOrden )
{
    NUMORDEN  stkey;
    NUMORDEN  *pstAux = (NUMORDEN *)NULL;
    char *szModulo="BuscaNumOrden";

    vDTrazasLog (szModulo, "\n\t\t* Busca Num. Orden "
                 "\n\t\t=> Concepto  [%d]"
                 "\n\t\t=> Registros     [%d]"
                 , LOG05,iCodConcepto, stNumOrdenes.iNumRegs);

    stkey.iCodConcepto=iCodConcepto;
    if ( stNumOrdenes.iNumRegs )
    {
        if ( (pstAux = (NUMORDEN *)bsearch (&stkey, stNumOrdenes.stNumOrden, stNumOrdenes.iNumRegs,
                                            sizeof (NUMORDEN),ifnCmpNumOrden ))== (NUMORDEN *)NULL )
        {
            vDTrazasLog(szModulo, "Codigo [%d] no encontrado ", LOG01, iCodConcepto);
            return(FALSE);
        }
        memcpy (pstNumOrden, pstAux, sizeof(NUMORDEN));
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Orden ...", LOG01);
    }
    return (TRUE);
}/**************************** Final BuscaNumOrden  *************************/


/****************************************************************************/
/*                           funcion : vfnPrintNumOrden                     */
/****************************************************************************/
void vfnPrintNumOrden (NUMORDEN *pstEstruc, int iNumRegs)
{
    int i = 0;
    char *szModulo="vfnPrintNumOrden";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Tabla Numeros de Orden [%d]", LOG06, iNumRegs);

        for ( i=0;i<iNumRegs;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Orden Grupo     [%d]"
                         "\n\t\t=> [%d]: Orden subGrupo  [%d]"
                         "\n\t\t=> [%d]: Orden Concepto  [%d]"
                         "\n\t\t=> [%d]: Codigo Grupo    [%d]"
                         "\n\t\t=> [%d]: Codigo SubGrupo [%d]"
                         "\n\t\t=> [%d]: Codigo Concepto [%d]"
                         "\n\t\t=> [%d]: Codigo Registro [%s]"
                         "\n\t\t=> [%d]: Codigo Criterio [%d]"
                         ,LOG06
                         ,i, pstEstruc[i].iNum_OrdenGr
                         ,i, pstEstruc[i].iNum_OrdenSubGr
                         ,i, pstEstruc[i].iNum_OrdenConc
                         ,i, pstEstruc[i].iCodGrupo
                         ,i, pstEstruc[i].iCodSubGrupo
                         ,i, pstEstruc[i].iCodConcepto
                         ,i, pstEstruc[i].szCodRegistro
                         ,i, pstEstruc[i].iCodCriterio);
        }
    }
}/*************************** vfnPrintNumOrden *****************************/


extern BOOL CargaEstructuraInicial(NUMORDEN *pstNumOrden, int iCantOrdenes)
{
    int i;
    DETCELULAR_AGRUP  *stDetCelularTemp;

    for ( i=0; i < iCantOrdenes; i++ )
    {
        if ( pstNumOrden[i].iTipo_SubGrupo == 3 )
        {
            stDetCelular.stAgrupacion = (DETCELULAR_AGRUP*) realloc(stDetCelular.stAgrupacion, (int) (sizeof(DETCELULAR_AGRUP) * (stDetCelular.iCantEstructuras + 1)) );
            stDetCelularTemp = &(stDetCelular.stAgrupacion)[(stDetCelular.iCantEstructuras)];
            memset(stDetCelularTemp, 0, sizeof(DETCELULAR_AGRUP));

            stDetCelularTemp->iNum_OrdenGr      =  pstNumOrden[i].iNum_OrdenGr;
            stDetCelularTemp->iNum_OrdenSubGr   =  pstNumOrden[i].iNum_OrdenSubGr;
            stDetCelularTemp->iCodGrupo         =  pstNumOrden[i].iCodGrupo;
            stDetCelularTemp->iCodSubGrupo      =  pstNumOrden[i].iCodSubGrupo;
            stDetCelularTemp->iCriterio         =  pstNumOrden[i].iCodCriterio;
            stDetCelularTemp->iTipo_Llamada     =  pstNumOrden[i].iTipo_Llamada;
            strcpy(stDetCelularTemp->szCodRegistro,pstNumOrden[i].szCodRegistro);
            stDetCelular.iCantEstructuras++;
        }
    }
    return(TRUE);
}


/******************************************************************************************/
int OpenAbonado (long lCiclFact, long lIndOrden,DETALLEOPER *pst_MascaraOper)
{
    char szTablaAbon [40];
    char szQry       [2000];

    char *szModulo="OpenAbonado";

    vDTrazasLog(szModulo,"\t**Entrando a %s "
                "\n\t=> Ind.Ordentotal [%ld]"
                , LOG04, szModulo,lIndOrden);

    memset (szTablaAbon,0,sizeof(szTablaAbon));
    memset(szQry,0,sizeof(szQry));

		lhCodCilclFact= lCiclFact;

    if ( !lCiclFact )
    {
        sprintf(szTablaAbon,"FA_FACTABON_NOCICLO");
    }
    else
    {
        if ( !lNroJob )
        {
            sprintf(szTablaAbon,"FA_FACTABON_%ld",lCiclFact);
        }
        else
        {
            sprintf(szTablaAbon,"FA_FACTABON_%ld_%ld",lCiclFact, lNroJob);
        }
    }
    
    sprintf(szQry,
            "\n SELECT F.NUM_ABONADO ,"
            "\n        F.NUM_CELULAR ,"
            "\n        F.COD_DETFACT ,"
            "\n        F.COD_PRODUCTO,"
            "\n        NVL(REPLACE(F.NOM_USUARIO,'%%','N'),' '),"
            "\n        NVL(F.NOM_APELLIDO1,' '),"
            "\n        NVL(F.NOM_APELLIDO2,' '),"
            "\n        DECODE(F.NUM_ABONADO,0,0,F.COD_DETFACT) COD_DETFACT,"
            "\n        DECODE(F.COD_DETFACT,0,0,%d) IND_INTERZONA  ,"
            "\n        DECODE(F.COD_DETFACT,0,0,%d) IND_LDI        ,"
            "\n        DECODE(F.COD_DETFACT,0,0,%d) IND_ESPECIALES ,"
            "\n        DECODE(F.COD_DETFACT,0,0,%d) IND_CARRIER ,"
            "\n        DECODE(F.COD_DETFACT,0,0,%d) IND_LOCAL,"
            "\n        1 IND_ROAMING,"
            "\n        NVL (F.COD_DETFACT, 0)"
            "\n FROM    %s F "            
            "\n WHERE   F.IND_ORDENTOTAL = :lhIndOrdentotal"
            "\n AND     F.NUM_ABONADO    >= 0"
            "\n AND     F.NUM_CELULAR  IS NOT NULL"            
            "\n ORDER BY F.NUM_CELULAR" , pst_MascaraOper->iIndInterzona,
            pst_MascaraOper->iIndLDI,pst_MascaraOper->iIndEspeciales,
            pst_MascaraOper->iIndCarrier, pst_MascaraOper->iIndLocal,szTablaAbon);

    vDTrazasLog(szModulo,"\t\tQRY ABONADOS:[ %s ]",LOG05,szQry);

    /* EXEC SQL PREPARE sql_Cur_Abonado FROM :szQry; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2684;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szQry;
    sqlstm.sqhstl[0] = (unsigned long )2000;
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
        vDTrazasLog  (szModulo,"\t\tError en SQL-PREPARE sql_Abonados_DetLlam **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE sql_Abonados_DetLlam **"
                      "\t\tError : [%s] [%d]  [%s] ",LOG01,szQry,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    /* EXEC SQL DECLARE curAbonadoFact CURSOR FOR sql_Cur_Abonado; */ 


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE curAbonadoFact **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE curAbonadoFact **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return(SQLCODE);
    }

    lhIndOrdentotal = lIndOrden;

    /* EXEC SQL OPEN curAbonadoFact USING :lhIndOrdentotal; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2703;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhIndOrdentotal;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\n\t\tError en SQL-OPEN CURSOR curAbonadoFact **"
                      "\n\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t\tError en SQL-OPEN CURSOR curAbonadoFact **"
                      "\n\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
    }

    return(SQLCODE);
}/*********************** Final de OpenAbonado ***********************/


/****************************************************************************/
/* Funcion: int FetchAbonado(ST_ABONADO *)                              */
/* Funcion que realiza Fetch en el cursor de curFactDoc                     */
/****************************************************************************/
int FetchAbonado (ST_ABONADO *pstAbonadoFact)
{
    char *szModulo="FetchAbonado";

    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);
    /* EXEC SQL
    FETCH curAbonadoFact
    INTO :pstAbonadoFact->lNumAbonado    ,
    :pstAbonadoFact->lNumCelular    ,
    :pstAbonadoFact->iIndDetFact    ,
    :pstAbonadoFact->iCodProducto   ,
    :pstAbonadoFact->sznom_usuario  ,
    :pstAbonadoFact->sznom_apellido1,
    :pstAbonadoFact->sznom_apellido2,
    :pstAbonadoFact->iIndDetFact    ,
    :pstAbonadoFact->iIndInterzona  ,
    :pstAbonadoFact->iIndLdi        ,
    :pstAbonadoFact->iIndEspeciales ,
    :pstAbonadoFact->iIndCarrier    ,
    :pstAbonadoFact->iIndLocal      ,
    :pstAbonadoFact->iIndRoaming,
    :pstAbonadoFact->iIndDetLlam; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )20000;
    sqlstm.offset = (unsigned int  )2722;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstAbonadoFact->lNumAbonado);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )sizeof(long);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstAbonadoFact->lNumCelular);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )sizeof(long);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstAbonadoFact->iIndDetFact);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )sizeof(int);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstAbonadoFact->iCodProducto);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(int);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstAbonadoFact->sznom_usuario);
    sqlstm.sqhstl[4] = (unsigned long )21;
    sqlstm.sqhsts[4] = (         int  )21;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstAbonadoFact->sznom_apellido1);
    sqlstm.sqhstl[5] = (unsigned long )21;
    sqlstm.sqhsts[5] = (         int  )21;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstAbonadoFact->sznom_apellido2);
    sqlstm.sqhstl[6] = (unsigned long )21;
    sqlstm.sqhsts[6] = (         int  )21;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstAbonadoFact->iIndDetFact);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(int);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstAbonadoFact->iIndInterzona);
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(int);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstAbonadoFact->iIndLdi);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(int);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(pstAbonadoFact->iIndEspeciales);
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(int);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(pstAbonadoFact->iIndCarrier);
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(int);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)(pstAbonadoFact->iIndLocal);
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )sizeof(int);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)(pstAbonadoFact->iIndRoaming);
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )sizeof(int);
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)(pstAbonadoFact->iIndDetLlam);
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )sizeof(int);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
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

 /*P-ECU-10012 Se agrega ind_detalle*/

    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {
        vDTrazasError(szModulo,"\t\tError en Fetch FetchAbonado : %s", LOG01, SQLERRM);
    }
    else
        pstAbonadoFact->CantidadAbonados = sqlca.sqlerrd[2];
    vDTrazasLog(szModulo,"\n\t\tCantidad Abonados  [%s]   : [%d]" ,LOG05, szModulo,pstAbonadoFact->CantidadAbonados);
    vDTrazasLog(szModulo,"\n\t\tCantidad Abonados  [%s]   : [%ld]",LOG05, szModulo,pstAbonadoFact->CantidadAbonados);

    return(SQLCODE);
}/*************************** Final de FetchAbonado ***************************/


/****************************************************************************/
/*  Funcion: int CloseAbonado(void)                                      */
/*  Funcion que cierra el cursor de AbonadoFact                             */
/****************************************************************************/
int CloseAbonado(void)
{
    char *szModulo="CloseAbonado";

    vDTrazasLog(szModulo,"\t** Entrando en %s", LOG04,szModulo);
    /* EXEC SQL CLOSE curAbonadoFact; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2797;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if ( SQLCODE != SQLOK )
    {
        vDTrazasError(szModulo,"\tError al cerrar el Cursor FA_FACTABON_CICLO: %s",LOG01, SQLERRM);
        return(FALSE);
    }
    return(TRUE);
}/****************Final de bfnCloseFactTrafico *******************/


/*P-COL-05001 FC3  SCL - FACTURACIÔN - GAP IMPRESIÔN (2 Ô 1) 2005/05/17
Se agrega funcion iCargaFechaSuspension para rescatar la fecha de suspension de un cliente; este dato sera
imprimido en registro A1000.
*/
int iCargaFechaSuspension(long lCodCateg, char *sFVencim, char *sFecSuspen)
{
    int i;

    for ( i=0; i<stDias.iCantidadRegs ; i++ )
    {
        if ( lCodCateg == stDias.iDias[i] )
        {
            strcpy(sFecSuspen,stDias.szCategoria[i]);
            return(TRUE);
        }
    }

    return(FALSE);
}


/*********************************************************************************************/
/*P-COL-05001 FC3  SCL - FACTURACIÔN - GAP IMPRESIÔN (2 Ô 1) 2005/05/28
Se agrega funcion bfnCargaCodImptoFact para rescatar y poner estructura los datos de codigos de concepto*/
BOOL bfnCargaCodImptoFact(CODIMPTOSFACT *stImp_Fact)
{
    COD_IMPTOFACT *stImp_FactTemp;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lCod_Imp_fact;
    int  ihCodParametro = 207;
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy(szModulo,"bfnCargaCodImptoFact");
    /* EXEC SQL DECLARE cImpFactura CURSOR FOR
    SELECT val_numerico
    FROM FAD_PARAMETROS
    WHERE COD_PARAMETRO = :ihCodParametro; */ 


    /* EXEC SQL OPEN cImpFactura; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0055;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2812;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCodParametro;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo, "\n\t**  Error : En Open Cursor cImpFactura \n%s\n",LOG01,SQLERRM);
        return(FALSE);
    }
    memset(stImp_Fact,0,sizeof(stImp_Fact));
    while ( SQLCODE != SQLNOTFOUND )
    {
        /* EXEC SQL FETCH cImpFactura INTO
        :lCod_Imp_fact; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2831;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&lCod_Imp_fact;
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



        if ( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
        {
            vDTrazasLog  (szModulo, "Error en Fetch de Cursor cImpFactura[%d]: %s",LOG01, SQLCODE, SQLERRM);
            return(FALSE);
        }
        if ( SQLCODE == SQLOK )
        {
            stImp_Fact->stCodImptosFact =(COD_IMPTOFACT *) realloc(stImp_Fact->stCodImptosFact,(int)((stImp_Fact->iNumReg + 1) * sizeof(COD_IMPTOFACT)));
            if ( stImp_Fact->stCodImptosFact == NULL )
            {
                iDError (szModulo,ERR000,vInsertarIncidencia,
                         "Error bfnCargaCodImptoFact", "no se pudo reservar memoria");
                return (FALSE);
            }

            stImp_FactTemp = &(stImp_Fact->stCodImptosFact)[(stImp_Fact->iNumReg )];
            memset(stImp_FactTemp, 0, (int)(sizeof(COD_IMPTOFACT)));
            stImp_FactTemp->lCodImptoFact = lCod_Imp_fact;
            stImp_Fact->iNumReg ++ ;
        }
    }
    stImp_Fact->iNumReg= sqlca.sqlerrd[2];
    return(TRUE);
}/********************************************* bfnCargaCodImptoFact *********************************************/


BOOL bfnCargaGedPar()
{
    char szNomParam [21];
    char szValParam [21];
    char szCodModulo[3];

    memset(&stGedParametros,0,sizeof(stGedParametros));

    strcpy(szCodModulo, "FA");

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_TDIA");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodTDia,szValParam);


    sprintf(szNomParam, "%20.20s\0", "TOL_COD_LLAM");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodLlam    ,szValParam    );


    sprintf(szNomParam, "%20.20s\0", "TOL_COD_TDIR");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodTDir    ,szValParam    );

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_THOR");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodTHor    ,szValParam);

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_THOR_ALTA");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodTHorAlta,szValParam);

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_THOR_BAJA");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodTHorBaja,szValParam);

    sprintf(szNomParam, "%20.20s\0", "TOL_CON_CLIENTE");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolConCliente ,szValParam );

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_OPERADOR");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodOperador,szValParam);

    sprintf(szNomParam, "%20.20s\0", "TOL_COD_SFRAN");
    if ( !bfnGetGedParam(szNomParam, szCodModulo, szValParam) )
    {
        return(FALSE);
    }
    strcpy (stGedParametros.szTolCodSFran   ,szValParam   );

    return(TRUE);
}/********************************************* bfnCargaGedPar *********************************************/


BOOL bfnGetGedParam(char * pszNomParam, char *pszCodModulo, char *pszValParam)
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhNomParametro[21];
    char szhValParametro[21];
    char szhCodModulo[3];
    int  ihCodProducto;
    /* EXEC SQL END DECLARE SECTION; */ 

    char *szModulo="bfnGetGedParam";

    strcpy(szhNomParametro, alltrim(pszNomParam));
    strcpy(szhCodModulo, alltrim(pszCodModulo));
    ihCodProducto = 1;

    /* EXEC SQL
    SELECT VAL_PARAMETRO
    INTO :szhValParametro
    FROM GED_PARAMETROS
    WHERE NOM_PARAMETRO = :szhNomParametro
      AND COD_MODULO    = :szhCodModulo
      AND COD_PRODUCTO  = :ihCodProducto; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select VAL_PARAMETRO into :b0  from GED_PARAMETROS where \
((NOM_PARAMETRO=:b1 and COD_MODULO=:b2) and COD_PRODUCTO=:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2850;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhValParametro;
    sqlstm.sqhstl[0] = (unsigned long )21;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhNomParametro;
    sqlstm.sqhstl[1] = (unsigned long )21;
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
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCodProducto;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo, "\n\t**Error : En consulta parametro %s \n[%s]\n",LOG01,pszNomParam,SQLERRM);
        return(FALSE);
    }

    strcpy (pszValParam, szhValParametro);
    return(TRUE);

}/********************************************* bfnGetGedParam *********************************************/


BOOL bfnCargaCodImptoCateg(CATIMPUESTOS *st_catImpuestos)
{
    int j;
    CATIMPUES *stCatImpuestosTemp;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lcod_conc;
    int  icod_cat;
    int  iCodTipImpto;
    double dprc_imp;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="bfnCargaCodImptoCateg";

    ihZero = 0;

    /* EXEC SQL DECLARE cCodImpCateg CURSOR FOR
    SELECT  DISTINCT (A.COD_CONCGENE),B.COD_CATEIMP, A.PRC_IMPUESTO, A.COD_TIPIMPUES
    FROM GE_IMPUESTOS A, GE_TIPIMPUES B
    WHERE A.COD_CATIMPOS >= :ihZero
    AND A.COD_ZONAIMPO >= :ihZero
    AND A.COD_ZONAABON >= :ihZero
    AND A.COD_TIPIMPUES = B.COD_TIPIMPUE
    AND A.COD_GRPSERVI >= :ihZero
    ORDER BY A.COD_CONCGENE ASC; */ 


    /* EXEC SQL OPEN cCodImpCateg; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0057;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2881;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihZero;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo, "\n\t**  Error : En Open Cursor cCodImpCateg \n%s\n",LOG01,SQLERRM);
        return(FALSE);
    }
    memset(st_catImpuestos,0,sizeof(st_catImpuestos));
    st_catImpuestos->iNumRegs= sqlca.sqlerrd[2];
    while ( SQLCODE != SQLNOTFOUND )
    {
        /* EXEC SQL FETCH cCodImpCateg INTO
        :lcod_conc,:icod_cat,:dprc_imp,:iCodTipImpto; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2912;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&lcod_conc;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&icod_cat;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&dprc_imp;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&iCodTipImpto;
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



        if ( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
        {
            vDTrazasLog  (szModulo, "Error en Fetch de Cursor cCodImpCateg[%ld]: %s",LOG01, SQLCODE, SQLERRM);
            return(FALSE);
        }

        st_catImpuestos->stCatImpuesto =(CATIMPUES *) realloc(st_catImpuestos->stCatImpuesto,((st_catImpuestos->iNumRegs + 1 ) * sizeof(CATIMPUES) ));

        if ( st_catImpuestos->stCatImpuesto == NULL )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargaCodImptoCateg", "no se pudo reservar memoria");
            return (FALSE);
        }
        stCatImpuestosTemp = &(st_catImpuestos->stCatImpuesto)[(st_catImpuestos->iNumRegs )];
        memset(stCatImpuestosTemp, 0, (int)(sizeof(CATIMPUES)));
        stCatImpuestosTemp->lCodConcepto    =lcod_conc;
        stCatImpuestosTemp->iCodCategoria   =icod_cat;
        stCatImpuestosTemp->dPrcImpuesto    =dprc_imp;
        stCatImpuestosTemp->iCodTipImpto    =iCodTipImpto;
        strcpy(stCatImpuestosTemp->szFlagImpto,"");
        st_catImpuestos->iNumRegs++;
    }

    vDTrazasLog(szModulo,"\n\tConjunto de Categorias Impositivas"
    					 "\n\t\tCONCEPTO|CATEGORIA|PORCENTAJE|TIPO IMPUESTO|FLAG",LOG05);
    for ( j=0;j<st_catImpuestos->iNumRegs;j++ )
    {
        vDTrazasLog(szModulo,"\t\t[%d] %ld|%d|%f|%d|%s|",LOG05,j
                    ,st_catImpuestos->stCatImpuesto[j].lCodConcepto
                    ,st_catImpuestos->stCatImpuesto[j].iCodCategoria
                    ,st_catImpuestos->stCatImpuesto[j].dPrcImpuesto
                    ,st_catImpuestos->stCatImpuesto[j].iCodTipImpto
                    ,st_catImpuestos->stCatImpuesto[j].szFlagImpto);
    }
    return(TRUE);
}/********************************************* bfnCargaCodImptoCateg *********************************************/


/***********************************************************************************/
BOOL bfnTotImptosCateg(int iCodConcepto,int iColumna, double *pdTotalPrimeraCategoria, double *pdTotalSegundaCategoria )
{
    int i;
    char szLlaveBusqueda[10];
    char szLlaveDetConsumo[10];
    int iCategoria;
    double dAcumPrimeraCategoria=0;
    double dAcumSegundaCategoria=0;

    /*------------------------------------------------------------------------------------
     ACUMULA CONCEPTOS RELACIONADOS
    -------------------------------------------------------------------------------------*/
    char *szModulo="bfnTotImptosCateg";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);
    sprintf(szLlaveBusqueda,"%04d|%06d",iCodConcepto,iColumna);
    vDTrazasLog(szModulo, "\t\t\tLlave de Busqueda [%s] ", LOG05, szLlaveBusqueda);

    for ( i=0; i < stFaDetCons.iNumReg; i++ )
    {
        sprintf(szLlaveDetConsumo,"%04d|%06d", stFaDetCons.stDetConsumo[i].iCodConcerel,stFaDetCons.stDetConsumo[i].iColumnaRel);

        if ( strcmp(szLlaveBusqueda,szLlaveDetConsumo)==0 && stFaDetCons.stDetConsumo[i].iCodTipConce ==1 && strcmp(szLlaveBusqueda,"0000|000000")!=0 )
        {
            if ( !bfnCategImpto(stFaDetCons.stDetConsumo[i].iCodConcepto,&iCategoria,stFaDetCons.stDetConsumo[i].dPrcImpuesto) )
            {
                vDTrazasLog(szModulo,"No pudo encontrar el concepto con su categoria [%d][%f]",LOG05,stFaDetCons.stDetConsumo[i].iCodConcepto, stFaDetCons.stDetConsumo[i].dPrcImpuesto);
            }
            else
            {
                vDTrazasLog(szModulo,"\n\tConcepto         [%d] Porcentaje       [%f]"
                					 "\n\tCategoria Actual [%d] Primera categoria [%d]"
                					 ,LOG05,stFaDetCons.stDetConsumo[i].iCodConcepto,stFaDetCons.stDetConsumo[i].dPrcImpuesto,iCategoria,iGPrimCateg);
                if ( iCategoria == iGPrimCateg )
                {
                    dAcumPrimeraCategoria +=stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                }
                else
                {
                    dAcumSegundaCategoria +=stFaDetCons.stDetConsumo[i].dTotalFacturableNet;
                }
            }
        }
    }
    *pdTotalPrimeraCategoria=dAcumPrimeraCategoria;
    *pdTotalSegundaCategoria=dAcumSegundaCategoria;

    return(TRUE);
}
/*********************************************************************************************/
BOOL bfnCategImpto(int iCodConcepto, int *iCodCategoria,double dPrcImpto)
{
    CATIMPUES  stkey;
    CATIMPUES *elementoPtr = (CATIMPUES *)NULL;
    char *szModulo="bfnCategImpto";

    vDTrazasLog (szModulo, "\n\t* Busca Categoria del Impuesto \n\t Cod. Concepto [%d] \n\t Porcentaje [%f]", LOG05,iCodConcepto,dPrcImpto);
    stkey.lCodConcepto=iCodConcepto;
    stkey.dPrcImpuesto=dPrcImpto;

    if ( pstCatImpues.iNumRegs > 0 )
    {
        if ( (elementoPtr = (CATIMPUES *)bsearch (&stkey, pstCatImpues.stCatImpuesto , pstCatImpues.iNumRegs,
                                                  sizeof (CATIMPUES),ifnCmpCodImptos )) == (CATIMPUES *)NULL )
        {
            return(FALSE);
        }
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Categorias de impuestos ...", LOG01);
        return(FALSE);
    }

    *iCodCategoria=elementoPtr->iCodCategoria;
    strcpy(elementoPtr->szFlagImpto,"S");            /* Marco el Impuesto para determinar que porcentajes  debo sumar */

    return(TRUE);
}
/***********************************************************************************/
int ifnCmpCodImptos (const void *cad1,const void *cad2)
{
    if ( ((CATIMPUES *)cad1)->lCodConcepto < ((CATIMPUES *)cad2)->lCodConcepto ) return (-1);
    else if ( ((CATIMPUES  *)cad1)->lCodConcepto > ((CATIMPUES  *)cad2)->lCodConcepto ) return (1);
    else if ( ((CATIMPUES  *)cad1)->dPrcImpuesto < ((CATIMPUES  *)cad2)->dPrcImpuesto ) return (-1);
    else if ( ((CATIMPUES  *)cad1)->dPrcImpuesto > ((CATIMPUES  *)cad2)->dPrcImpuesto ) return (1);
    return (0);

}
/***********************************************************************************/
BOOL bfnPorcenImptosCateg(double *pdTotalPorcenPrimeraCateg, double *pdTotalPorcenSegundaCateg )
{
    int i;
    double dPorcenPrimeraCategoria=0;
    double dPorcenSegundaCategoria=0;

    /*------------------------------------------------------------------------------------
     ACUMULA POCENTAJES DE IMPUESTOS
    -------------------------------------------------------------------------------------*/
    char *szModulo="bfnPorcenImptosCateg";

    vDTrazasLog(szModulo, "\tEntro a %s ", LOG05, szModulo);
    for ( i=0; i < pstCatImpues.iNumRegs; i++ )
    {
        if ( strcmp(pstCatImpues.stCatImpuesto[i].szFlagImpto,"S")==0 )
        {
            if ( pstCatImpues.stCatImpuesto[i].iCodCategoria == iGPrimCateg )
            {
                dPorcenPrimeraCategoria +=pstCatImpues.stCatImpuesto[i].dPrcImpuesto;
            }
            else
            {
                dPorcenSegundaCategoria +=pstCatImpues.stCatImpuesto[i].dPrcImpuesto;
            }
            strcpy(pstCatImpues.stCatImpuesto[i].szFlagImpto," ");
        }
    }
    *pdTotalPorcenPrimeraCateg=dPorcenPrimeraCategoria;
    *pdTotalPorcenSegundaCateg=dPorcenSegundaCategoria;
    return(TRUE);
}
/***********************************************************************************/
BOOL bfnTipoImpuesto(int iCodConcepto, int *iCodTipoImpuesto,double dPrcImpto)
{

    CATIMPUES  stkey;
    CATIMPUES *elementoPtr = (CATIMPUES *)NULL;
    char *szModulo="bfnTipoImpuesto";

    vDTrazasLog (szModulo, "\n\t\t* Busca Tipo Impuesto \n\t Cod. Concepto [%d]", LOG05,iCodConcepto);
    stkey.lCodConcepto=iCodConcepto;
    stkey.dPrcImpuesto=dPrcImpto;

    if ( pstCatImpues.iNumRegs > 0 )
    {
        if ( (elementoPtr = (CATIMPUES *)bsearch (&stkey, pstCatImpues.stCatImpuesto , pstCatImpues.iNumRegs,sizeof (CATIMPUES),ifnCmpCodImptos )) == (CATIMPUES *)NULL )
        {
            return(FALSE);
        }
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Tipos de impuestos ...", LOG01);
    }

    *iCodTipoImpuesto=elementoPtr->iCodTipImpto;

    return(TRUE);
}

/***********************************************************************************/
BOOL bfnBuscaCategImpto(int iCodConcepto, int *iCodCategoria, double dPrcImpto)
{

    CATIMPUES  stkey;
    CATIMPUES *elementoPtr = (CATIMPUES *)NULL;
    char *szModulo="bfnBuscaCategImpto";

    vDTrazasLog (szModulo, "Funcion bfnBuscaCategImpto * Busca Categoria del Impuesto \n\t Cod. Concepto [%d]", LOG05,iCodConcepto);
    stkey.lCodConcepto=iCodConcepto;
    stkey.dPrcImpuesto=dPrcImpto;

    if ( pstCatImpues.iNumRegs > 0 )
    {
        if ( (elementoPtr = (CATIMPUES *)bsearch (&stkey, pstCatImpues.stCatImpuesto , pstCatImpues.iNumRegs,
                                                  sizeof (CATIMPUES),ifnCmpCodImptos )) == (CATIMPUES *)NULL )
        {
            vDTrazasLog ("bfnBuscaCategImpto", "No encuentra categoria para  [%d]", LOG05,iCodConcepto);
            return(FALSE);
        }
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Categ. de impuestos ...", LOG01);
        return(FALSE);
    }

    *iCodCategoria=elementoPtr->iCodCategoria;
    return(TRUE);
}


BOOL bfnLimpiaFlag(CATIMPUESTOS *st_catImpuestos)
{
    int i;
    for ( i=0; i < st_catImpuestos->iNumRegs; i++ )
    {
        strcpy(st_catImpuestos->stCatImpuesto[i].szFlagImpto," ");
    }
    return(TRUE);
}

/***********************************************************************************/
BOOL bfnCargaUltsPagos (PAGO **pstPago, int *iNumRegs, long lCodCliente, long lCodCicloFact)
{
    int     rc = 0;
    int    iNumFilas;
    static  PAGO_HOSTS stPagoHost;
    PAGO    *pstPagoTemp;
    int    iCont;
    char *szModulo="bfnCargaUltsPagos";

    vDTrazasLog (szModulo,"\n\t* Carga Pagos ", LOG06);

    *iNumRegs = 0;
    *pstPago = (PAGO *)NULL;

    /* JHTO */
    if ( ifnOpenPagos(lCodCliente,lCodCicloFact) )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchPagos(&stPagoHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstPago =(PAGO*) realloc(*pstPago,(int)(((*iNumRegs)+iNumFilas)*sizeof(PAGO)));

        if ( !*pstPago )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargaUltsPagos", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstPagoTemp = &(*pstPago)[(*iNumRegs)];
        memset(pstPagoTemp, 0, (int)(sizeof(PAGO)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            pstPagoTemp[iCont].dMonto       = stPagoHost.dMonto[iCont];
            strcpy( pstPagoTemp[iCont].szFecha     , stPagoHost.szFecha[iCont]);
            strcpy( pstPagoTemp[iCont].szDecrip    , stPagoHost.szDecrip[iCont]);
            strcpy( pstPagoTemp[iCont].szModPago, stPagoHost.szModPago[iCont]);
            pstPagoTemp[iCont].iTipPago     =  stPagoHost.iTipPago[iCont];                  /* P-ECU-05021 */
            strcpy( pstPagoTemp[iCont].szCodOperadora,  stPagoHost.szCodOperadora[iCont]);  /* P-ECU-05021 */
            pstPagoTemp[iCont].iCodTipDocum = stPagoHost.iCodTipDocum[iCont];               /* P-ECU-05021 */
        }
        (*iNumRegs) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Pagos del cliente cargados [%ld]", LOG06, *iNumRegs);

    rc = ifnClosePagos();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaUltsPagos", szfnORAerror ());
        return (FALSE);
    }

    vfnPrintPagos (*pstPago, *iNumRegs);

    return(TRUE);
}
/***************************** Final bfnCargaUltsPagos *********************/

/****************************************************************************/
/*  Funcion: int ifnOpenPagos                                               */
/****************************************************************************/
int ifnOpenPagos (long lCodCliente, long lCodCiclFact)
{
    char  szCadenaSQL  [16000]  ="";
    char  szTablaPagos [50]="";

    lhCodCliente = lCodCliente;
    strcpy(szhFormato_Fecha,"YYYYMMDD");
    strcpy(szhDesTipValor,"NO REGISTRADO");
    ihZero=0;

    strcpy (szModulo, "ifnOpenPagos");
    vDTrazasLog(szModulo,"\t** EN FUNCION ..(%s)", LOG06,szModulo);

    if (!lNroJob)
    {
         sprintf(szTablaPagos,"CO_ULTPAGO_TT_%ld", lCodCiclFact);
         vDTrazasLog (szModulo,"\n\t\t* Open=> CO_ULTPAGO_TT", LOG06);
    }
    else
    {
         sprintf(szTablaPagos,"CO_ULTPAGO_TT_%ld_%ld",lCodCiclFact,lNroJob);
         vDTrazasLog (szModulo,"\n\t\t* Open=> CO_ULTPAGO_TT_%ld_%ld", LOG06,lCodCiclFact,lNroJob);
    }

    memset(szCadenaSQL,'\0',sizeof(szCadenaSQL));

    sprintf(szCadenaSQL," SELECT"
                        "\nMONTO, "
                        "\nTO_CHAR(FECHA, 'YYYYMMDD'),"
                        "\nDESCRIPCION,"
                        "\nNVL(DES_TIPVALOR, 'NO REGISTRADO'), "
                        "\nNVL(A.TIP_PAGO,%d), "
                        "\nNVL(COD_OPERADORA,' '), "
                        "\nNVL(COD_TIPDOCUM,%d) "
                        "\nFROM %s A,"
                        "\n     CO_TIPVALOR B"
                        "\nWHERE B.TIP_VALOR (+) = A.COD_MODPAGO "
                        "\n  AND COD_CLIENTE     = %ld"
                        ,ihZero,ihZero,szTablaPagos,lhCodCliente);

    vDTrazasLog(szModulo,"\n\tQUERY PAGOS : [%s] ",LOG06,szCadenaSQL);

    /* EXEC SQL PREPARE curPagos FROM :szCadenaSQL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2943;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadenaSQL;
    sqlstm.sqhstl[0] = (unsigned long )16000;
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



    if (SQLCODE != SQLOK)
    {
        vDTrazasError(szModulo,"\t\tError en SQL-PREPARE curPagos.. **"
                                        "\t\tError : [%s] [%d]  [%s] ",LOG01,szCadenaSQL,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    /* EXEC SQL DECLARE curUltPagos CURSOR FOR curPagos; */ 


    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-DECLARE curUltPagos **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-DECLARE curUltPagos **"
                               "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (SQLCODE);
    }

    /* EXEC SQL OPEN curUltPagos; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2962;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE !=  SQLOK)
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN CURSOR curUltPagos **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN CURSOR curUltPagos **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }
	vDTrazasLog(szModulo,"\n\t\t retornando de funcion ifnOpenPagos: [%d] ",LOG05,SQLCODE);
    return (SQLCODE);
}/************************ Final de ifnOpenPagos ***********************/

/**************************************************************/
/*  FUNCION : bfnFetchPagos                                   */
/**************************************************************/
static BOOL bfnFetchPagos (PAGO_HOSTS *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchPagos";

    /* EXEC SQL FETCH curUltPagos
    INTO  :pstHost->dMonto   ,
    :pstHost->szFecha        ,
    :pstHost->szDecrip       ,
    :pstHost->szModPago      ,
    :pstHost->iTipPago       ,
    :pstHost->szCodOperadora ,
    :pstHost->iCodTipDocum   ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )2977;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->dMonto);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )sizeof(double);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szFecha);
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )9;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->szDecrip);
    sqlstm.sqhstl[2] = (unsigned long )41;
    sqlstm.sqhsts[2] = (         int  )41;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->szModPago);
    sqlstm.sqhstl[3] = (unsigned long )21;
    sqlstm.sqhsts[3] = (         int  )21;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->iTipPago);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(int);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstHost->szCodOperadora);
    sqlstm.sqhstl[5] = (unsigned long )6;
    sqlstm.sqhsts[5] = (         int  )6;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstHost->iCodTipDocum);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(int);
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> CO_ULTPAGO_TT", szfnORAerror ());
    return (SQLCODE);
}
/***************************** Final bfnFetchPagos ****************/
int ifnClosePagos(void)
{
    char *szModulo="ifnClosePagos";

    vDTrazasLog (szModulo,"\n\t\t* Open=> CO_ULTPAGO_TT", LOG06);

    /* EXEC SQL CLOSE curUltPagos; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3020;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> CO_ULTPAGO_TT",
                 szfnORAerror ());

    return (SQLCODE);
}
/***************************** Final ifnClosePagos **********************/
void vfnPrintPagos (PAGO *pstPago, int iNumRegs)
{
    int i = 0;
    char *szModulo="vfnPrintPagos";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Tabla Pagos [%d]", LOG06, iNumRegs);

        for ( i=0;i<iNumRegs;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Monto Pago          [%f]"
		                          "\n\t\t=> [%d]: Fecha Pago          [%s]"
		                          "\n\t\t=> [%d]: Descripcion         [%s]"
		                          "\n\t\t=> [%d]: Cod. Modalidad Pago [%s]"
		                          "\n\t\t=> [%d]: Tipo de Pago        [%d]"
		                          ,LOG06
		                          ,i, pstPago[i].dMonto
		                          ,i, pstPago[i].szFecha
		                          ,i, pstPago[i].szDecrip
		                          ,i, pstPago[i].szModPago
		                          ,i, pstPago[i].iTipPago  );
        }
    }
}
/*************************** vfnPrintPagos *****************************/
BOOL bfnCargaMinutosPlanes (MINPLAN **pstMinPlan, int *iNumRegs)
{
    int     rc = 0;
    int     iNumFilas;
    static  MINPLAN_HOSTS stMinPlanHost;
    MINPLAN     *pstMinPlanTemp;
    int  iCont;
    char *szModulo="bfnCargaMinutosPlanes";

    vDTrazasLog (szModulo,"\n\t* Carga Valor de minutos por plan ", LOG06);

    *iNumRegs = 0;
    *pstMinPlan = (MINPLAN *)NULL;

    if ( ifnOpenMinPlanes() )
        return (FALSE);

/* rao: se elimina ya que no se entiende el uso
    rc == SQLNOTFOUND; */ /*Para que no cargue*/

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchMinPlanes(&stMinPlanHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstMinPlan =(MINPLAN*) realloc(*pstMinPlan,((*iNumRegs)+iNumFilas)*sizeof(MINPLAN));

        if ( !*pstMinPlan )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargaMinutosPlanes", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstMinPlanTemp = &(*pstMinPlan)[(*iNumRegs)];
        memset(pstMinPlanTemp, 0, (int)(sizeof(MINPLAN)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            strcpy( pstMinPlanTemp[iCont].szCod_Plan       , alltrim(stMinPlanHost.szCod_Plan[iCont]));
            strcpy( pstMinPlanTemp[iCont].szCod_Thor       , alltrim(stMinPlanHost.szCod_Thor[iCont]));
            pstMinPlanTemp[iCont].lSeg_Inic       = stMinPlanHost.lSeg_Inic[iCont];
            pstMinPlanTemp[iCont].lSeg_Adic       = stMinPlanHost.lSeg_Adic[iCont];
            pstMinPlanTemp[iCont].dMto_Inic       = stMinPlanHost.dMto_Inic[iCont];
            pstMinPlanTemp[iCont].dMto_Adic       = stMinPlanHost.dMto_Adic[iCont];
        }
        (*iNumRegs) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* minutos por planes  [%d]", LOG06, *iNumRegs);

    rc = ifnCloseMinPlanes();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaMinutosPlanes", szfnORAerror ());
        return (FALSE);
    }

    if ( *iNumRegs >0 )
    {
        qsort((void*)*pstMinPlan, *iNumRegs, sizeof(MINPLAN),ifnCmpMinPlanes);
        vfnPrintMinPlanes (*pstMinPlan, *iNumRegs);
    }

    return(TRUE);
}
/***************************** Final bfnCargaMinutosPlanes *********************/
static int ifnOpenMinPlanes( void )
{
    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

    char szhTolCodLlam  [21];
    char szhTolCodTDir  [21];
    char szhTolCodTHor  [21];
    char szhTolCodTHorAlta  [21];
    char szhTolCodTHorBaja  [21];
    char szhTolConCliente[21];
    char szhTolCodOperador[21];
    char szhTolCodTDia  [21];
    char szhTolCodSFran [21];
    /* EXEC SQL END DECLARE SECTION  ; */ 

    char *szModulo="ifnOpenMinPlanes";

    vDTrazasLog (szModulo,"\n\t\t* Open=> TOL_AGRULLAM / TOL_ESTCOBRO", LOG06);

    strcpy (szhTolCodLlam       ,alltrim(stGedParametros.szTolCodLlam)    );
    strcpy (szhTolCodTDir       ,alltrim(stGedParametros.szTolCodTDir)    );
    strcpy (szhTolCodTHor       ,alltrim(stGedParametros.szTolCodTHor)    );
    strcpy (szhTolCodTHorAlta   ,alltrim(stGedParametros.szTolCodTHorAlta) );
    strcpy (szhTolCodTHorBaja   ,alltrim(stGedParametros.szTolCodTHorBaja) );
    strcpy (szhTolConCliente    ,alltrim(stGedParametros.szTolConCliente ) );
    strcpy (szhTolCodOperador   ,alltrim(stGedParametros.szTolCodOperador) );
    strcpy (szhTolCodTDia       ,alltrim(stGedParametros.szTolCodTDia    ) );
    strcpy (szhTolCodSFran      ,alltrim(stGedParametros.szTolCodSFran   ) );

    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodLlam);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodTDir);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodTHor);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodTHorAlta);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodTHorBaja);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolConCliente);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodOperador);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodTDia);
    vDTrazasLog (szModulo,"\n\t\t* Open=> [%s]", LOG06, szhTolCodSFran);

    /* EXEC SQL DECLARE cCurMinPlan CURSOR FOR
    SELECT B.COD_PLAN, A.COD_THOR, B.SEG_INIC, B.SEG_ADIC, B.MTO_MIN, B.MTO_ADIC          /o RA-200512270421 o/
    FROM TOL_AGRULLAM A, TOL_ESTCOBRO B
    WHERE A.COD_SENTIDO = 'S'
                          AND A.COD_LLAM = :szhTolCodLlam
                          AND A.COD_TDIR = :szhTolCodTDir
                          AND A.COD_THOR IN (:szhTolCodTHor, :szhTolCodTHorAlta, :szhTolCodTHorBaja)
                          AND A.CON_CLIENTE = :szhTolConCliente
                                              AND A.FEC_INI_VIG <= SYSDATE
                                              AND A.FEC_TER_VIG >= SYSDATE
                                              AND B.COD_OPERADOR = :szhTolCodOperador
                                              AND B.COD_PLAN <> ' '
                                              AND B.COD_AGRULLAM = A.COD_AGRULLAM
                                              AND B.COD_TDIA = :szhTolCodTDia
                                              AND B.COD_SFRAN = :szhTolCodSFran
                                              AND B.FEC_INI_VIG <= SYSDATE
                                              AND B.FEC_TER_VIG >= SYSDATE; */ 



    /* EXEC SQL OPEN cCurMinPlan; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0059;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3035;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhTolCodLlam;
    sqlstm.sqhstl[0] = (unsigned long )21;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhTolCodTDir;
    sqlstm.sqhstl[1] = (unsigned long )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhTolCodTHor;
    sqlstm.sqhstl[2] = (unsigned long )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhTolCodTHorAlta;
    sqlstm.sqhstl[3] = (unsigned long )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhTolCodTHorBaja;
    sqlstm.sqhstl[4] = (unsigned long )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhTolConCliente;
    sqlstm.sqhstl[5] = (unsigned long )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szhTolCodOperador;
    sqlstm.sqhstl[6] = (unsigned long )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)szhTolCodTDia;
    sqlstm.sqhstl[7] = (unsigned long )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)szhTolCodSFran;
    sqlstm.sqhstl[8] = (unsigned long )21;
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



    if ( SQLCODE != SQLOK )
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> TOL_AGRULLAM/ TOL_ESTCOBRO",szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnOpenMinPlanes **********************/

static BOOL bfnFetchMinPlanes(MINPLAN_HOSTS *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchMinPlanes";

    /* EXEC SQL FETCH cCurMinPlan
    INTO  :pstHost->szCod_Plan,
    :pstHost->szCod_Thor,
    :pstHost->lSeg_Inic ,
    :pstHost->lSeg_Adic ,
    :pstHost->dMto_Inic ,
    :pstHost->dMto_Adic; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )3086;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->szCod_Plan);
    sqlstm.sqhstl[0] = (unsigned long )6;
    sqlstm.sqhsts[0] = (         int  )6;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szCod_Thor);
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->lSeg_Inic);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )sizeof(long);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->lSeg_Adic);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )sizeof(long);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->dMto_Inic);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[4] = (         int  )sizeof(double);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstHost->dMto_Adic);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[5] = (         int  )sizeof(double);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
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



    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> TOL_AGRULLAM / TOL_ESTCOBRO", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchMinPlanes ****************/


static int ifnCloseMinPlanes(void)
{
    char *szModulo="ifnCloseMinPlanes";

    vDTrazasLog (szModulo,"\n\t\t* Close => TOL_AGRULLAM / TOL_ESTCOBRO", LOG06);

    /* EXEC SQL CLOSE cCurMinPlan; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3125;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> TOL_AGRULLAM / TOL_ESTCOBRO",
                 szfnORAerror ());

    return (SQLCODE);
}/***************************** Final ifnCloseMinPlanes **********************/

void vfnPrintMinPlanes (MINPLAN *pstMinPlan, int iNumRegs)
{
    int i = 0;
    char *szModulo="vfnPrintMinPlanes";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Minutos Planes [%d]", LOG06, iNumRegs);

        for ( i=0;i<iNumRegs;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Cod Plan    [%s]"
                         "\n\t\t=> [%d]: Cod THor    [%s]"
                         "\n\t\t=> [%d]: Seg Inic    [%ld]"
                         "\n\t\t=> [%d]: Seg Adic    [%ld]"
                         "\n\t\t=> [%d]: Mto Inic    [%f]"
                         "\n\t\t=> [%d]: Mto Adic    [%f]"
                         ,LOG06
                         ,i, pstMinPlan[i].szCod_Plan
                         ,i, pstMinPlan[i].szCod_Thor
                         ,i, pstMinPlan[i].lSeg_Inic
                         ,i, pstMinPlan[i].lSeg_Adic
                         ,i, pstMinPlan[i].dMto_Inic
                         ,i, pstMinPlan[i].dMto_Adic );


        }
    }
}/*************************** vfnPrintMinPlanes *****************************/

int ifnCmpMinPlanes(const void *cad1,const void *cad2)
{
    int rc;
    return( (rc = strcmp  (((MINPLAN *)cad1)->szCod_Plan,
                           ((MINPLAN *)cad2)->szCod_Plan)) != 0)?rc:
    ( (rc = strcmp  (((MINPLAN *)cad1)->szCod_Thor,
                     ((MINPLAN *)cad2)->szCod_Thor)) != 0)?rc:0;
}/*************************** ifnCmpCod_PlanTarif *****************************/

BOOL  bfnFindMinPlan (char *szCodPlanTarif, char *szCodThor, MINPLAN *pstMinPlan)
{
    char *szModulo="bfnFindMinPlan";
    MINPLAN  stkey;
    MINPLAN  *pstAux = (MINPLAN *)NULL;

    vDTrazasLog (szModulo, "\n\t\t* Busca Minutos de Plan Tarifario "
                 "\n\t\t=> Cod. Plan Tarifario   [%s]"
                 "\n\t\t=> Cod. T Hor            [%s]"
                 , LOG05,szCodPlanTarif
                 , szCodThor);

    strcpy(stkey.szCod_Plan, szCodPlanTarif);
    strcpy(stkey.szCod_Thor, szCodThor);

    if ( stMinutosPlanes.iNumRegs > 0 )
    {
        if ( (pstAux = (MINPLAN *)bsearch (&stkey, stMinutosPlanes.stMinPlan , stMinutosPlanes.iNumRegs,
                                           sizeof (MINPLAN), ifnCmpMinPlanes ))== (MINPLAN *)NULL )
        {

            vDTrazasLog(szModulo, "Codigo de Plan Tarifario [%s] no encontrado ...", LOG01, szCodPlanTarif);
            return(FALSE);
        }
        memcpy (pstMinPlan, pstAux, sizeof(MINPLAN));
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Minutos Planes ...", LOG01);
    }

    return(TRUE);
}


BOOL bfnCargaPrimCateg (void)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int     ihCodCateg =0 ;
    /* EXEC SQL END DECLARE SECTION; */ 


    char *szModulo="bfnCargaPrimCateg";

    /* EXEC SQL
    SELECT MIN(COD_CATEIMP)
    INTO :ihCodCateg
    FROM GE_TIPIMPUES; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select min(COD_CATEIMP) into :b0  from GE_TIPIMPUES ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3140;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCodCateg;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog(szModulo, "Error en SELECT de bfnCargaPrimCateg [%d]\n[%s]", LOG02, SQLCODE,SQLERRM);
        return(FALSE);
    }

    iGPrimCateg=ihCodCateg;
    vDTrazasLog(szModulo, "Primera Categoria [%d]", LOG05, iGPrimCateg);

    return(TRUE);

}/************************************ Final bfnCargaPrimCateg **********************************************/

int ifnCmpOperadores(const void *cad1,const void *cad2)
{
    int rc = 0;

    return
    ( (rc = ((CODOPER *)cad1)->iCodOperador-
       ((CODOPER *)cad2)->iCodOperador) != 0)?rc:0;

}

BOOL bfnCargaOperadores (CODOPER **pstOper, int *iNumOperadores)
{
    int     rc = 0;
    int     iNumFilas;
    static  CODOPER_HOSTS stOperHost;
    CODOPER *pstOperTemp;
    int     iCont;
    char *szModulo="bfnCargaOperadores";

    vDTrazasLog (szModulo,"\n\t* Carga Operadores ", LOG06);

    *iNumOperadores = 0;
    *pstOper = NULL;

    if ( ifnOpenOperadores() )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchOperadores(&stOperHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstOper =(CODOPER*) realloc(*pstOper,(int)(((*iNumOperadores)+iNumFilas)*sizeof(CODOPER)));

        if ( !*pstOper )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargaOperadores", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstOperTemp = &(*pstOper)[(*iNumOperadores)];
        memset(pstOperTemp, 0, (int)(sizeof(CODOPER)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            pstOperTemp[iCont].iCodOperador       = stOperHost.iCodOperador[iCont];
            strcpy( pstOperTemp[iCont].szDesOperador    ,stOperHost.szDesOperador[iCont]);
        }
        (*iNumOperadores) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Codigos de Operadores cargados [%d]", LOG06, *iNumOperadores);

    rc = ifnCloseOperadores();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargaOperadores", szfnORAerror ());
        return (FALSE);
    }

    qsort((void*)*pstOper, *iNumOperadores, sizeof(CODOPER),ifnCmpOperadores);

    /*vfnPrintOperadores (*pstOper, *iNumOperadores);*/
    vDTrazasLog (szModulo,"\n\t\t* (bfnCargaOperadores) Saliendo de la funcion...", LOG06);

    return(TRUE);
}/***************************** Final bfnCargaOperadores *********************/

static int ifnOpenOperadores(void)
{
    char *szModulo="ifnOpenOperadores";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnOpenOperadores", LOG06);

/*EXEC SQL DECLARE Cur_Operadores CURSOR for
SELECT COD_OPERADOR, DES_OPERADOR
FROM  TA_OPERADORES;*//*AFGS - 38935*/

    ihZero = 0;

    /* EXEC SQL DECLARE Cur_Operadores CURSOR for
        SELECT COD_OPERADOR, DES_OPERADOR
        FROM  TA_OPERADORES
        WHERE COD_OPERADOR >= :ihZero; */ 


    /* EXEC SQL OPEN Cur_Operadores; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0061;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3159;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihZero;
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



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> TA_OPERADORES",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnOpenOperadores **********************/

static BOOL bfnFetchOperadores (CODOPER_HOSTS *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchOperadores";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion bfnFetchOperadores", LOG06);

    /* EXEC SQL FETCH Cur_Operadores
    INTO :pstHost->iCodOperador ,
    :pstHost->szDesOperador; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )3178;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->iCodOperador);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szDesOperador);
    sqlstm.sqhstl[1] = (unsigned long )31;
    sqlstm.sqhsts[1] = (         int  )31;
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
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> TA_OPERADORES", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchOperadores ****************/


static int ifnCloseOperadores(void)
{
    char *szModulo="ifnCloseOperadores";

    vDTrazasLog (szModulo,"\n\t\t* En la funcion ifnCloseOperadores", LOG06);

    /* EXEC SQL CLOSE Cur_Operadores; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3201;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> TA_OPERADORES",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnCloseOperadores **********************/

void vfnPrintOperadores (CODOPER *pstCodOper, int iNumFilas)
{
    int i = 0;
    char *szModulo="vfnPrintOperadores";

    if ( stStatus.LogNivel >= LOG06 )
    {
        vDTrazasLog (szModulo,"\n\t\t* Carga Tabla Operadores [%d]", LOG06, iNumFilas);

        for ( i=0;i<iNumFilas;i++ )
        {
            vDTrazasLog (szModulo,"\n\t\t=> [%d]: Codigo de Operador [%d]"
                                  "\n\t\t=> [%d]: Desc. Operador     [%s]"
                         ,LOG06
                         ,i, pstCodOper[i].iCodOperador
                         ,i, pstCodOper[i].szDesOperador);
        }

    }
}/*************************** vfnPrintOperadores *****************************/


BOOL bfnFindCod_Operador (int iCodOperador, CODOPER *pstOper)
{
    CODOPER  stkey;
    CODOPER  *pstAux = (CODOPER *)NULL;
    char *szModulo="bfnFindCod_Operador";

    vDTrazasLog (szModulo, "\n\t\t* Busca Operador "
                           "\n\t\t=> Cod. Operador   [%d]"
                 , LOG05,iCodOperador );

    stkey.iCodOperador = iCodOperador;

    if ( stOperadores.iNumRegs )
    {
        if ( (pstAux = (CODOPER *)bsearch (&stkey, stOperadores.stOper , stOperadores.iNumRegs,
                                           sizeof (CODOPER),ifnCmpOperadores ))== (CODOPER *)NULL )
        {

            vDTrazasLog(szModulo, "Codigo Operador [%d] no encontrado ...", LOG01, iCodOperador);
            return(FALSE);
        }
        memcpy (pstOper, pstAux, sizeof(CODOPER));
    }
    else
    {
        vDTrazasLog(szModulo, "No existen datos para buscar en estructura de Operadores...", LOG01);
    }

    return(TRUE);
}

/* Funciones relacionadas con documentos del periodo */
BOOL bfnCargarDocsPeriodo (DOCPERIODO **pstDocPeriodo, int *iNumRegs, long lCodCliente, char *pszFecDesde, char *pszFecHasta)
{
    int     rc = 0;
    int    iNumFilas;
    static  DOCPERIODO_HOSTS stDocPeriodoHost;
    DOCPERIODO      *pstDocPeriodoTemp;
    int    iCont;
    char *szModulo="bfnCargarDocsPeriodo";

    vDTrazasLog (szModulo,"\n\t* Carga Pagos ", LOG06);

    *iNumRegs = 0;
    *pstDocPeriodo = (DOCPERIODO *)NULL;

    if ( ifnOpenDocsPeriodo(lCodCliente,pszFecDesde,pszFecHasta) )
        return (FALSE);

    while ( rc != SQLNOTFOUND )
    {
        rc = bfnFetchDocsPeriodo(&stDocPeriodoHost,&iNumFilas);
        if ( rc != SQLOK  && rc != SQLNOTFOUND )
            return (FALSE);

        if ( !iNumFilas )
            break;

        *pstDocPeriodo =(DOCPERIODO*) realloc(*pstDocPeriodo,(int)(((*iNumRegs)+iNumFilas)*sizeof(DOCPERIODO)));

        if ( !*pstDocPeriodo )
        {
            iDError (szModulo,ERR000,vInsertarIncidencia,
                     "Error bfnCargarDocsPeriodo()", "no se pudo reservar memoria");
            return (FALSE);
        }

        pstDocPeriodoTemp = &(*pstDocPeriodo)[(*iNumRegs)];
        memset(pstDocPeriodoTemp, 0, (int)(sizeof(DOCPERIODO)*iNumFilas));
        for ( iCont = 0 ; iCont < iNumFilas ; iCont++ )
        {
            pstDocPeriodoTemp[iCont].iCodTipDocum       = stDocPeriodoHost.iCodTipDocum[iCont];
            pstDocPeriodoTemp[iCont].lNumFolio          = stDocPeriodoHost.lNumFolio[iCont];
            pstDocPeriodoTemp[iCont].dTotFactura       = stDocPeriodoHost.dTotFactura[iCont];

            strcpy( pstDocPeriodoTemp[iCont].szCodOperadora  , stDocPeriodoHost.szCodOperadora[iCont]);
            strcpy( pstDocPeriodoTemp[iCont].szCodOficina    , stDocPeriodoHost.szCodOficina[iCont]);
            strcpy( pstDocPeriodoTemp[iCont].szDesTipDocum   , stDocPeriodoHost.szDesTipDocum[iCont]);
            strcpy( pstDocPeriodoTemp[iCont].szPrefPlaza     , stDocPeriodoHost.szPrefPlaza[iCont]);
            strcpy( pstDocPeriodoTemp[iCont].szFecEmision    , stDocPeriodoHost.szFecEmision[iCont]);
        }
        (*iNumRegs) += iNumFilas;

    }/* fin while */

    vDTrazasLog (szModulo,"\n\t\t* Documentos del periodo cargados: [%ld]", LOG05, *iNumRegs);

    rc = ifnCloseDocsPeriodo();
    if ( rc != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Error bfnCargarDocsPeriodo", szfnORAerror ());
        return (FALSE);
    }

    /*vfnPrintPagos (*pstPago, *iNumRegs);*/

    return(TRUE);
}/***************************** Final bfnCargarDocsPeriodo *********************/

static int ifnOpenDocsPeriodo(long lCodCliente, char *pszFecDesde, char *pszFecHasta)
{
    char *szModulo="ifnOpenDocsPeriodo";

    lhCodCliente = lCodCliente;
    strcpy(szhFecDesde,pszFecDesde);
    strcpy(szhFecHasta,pszFecHasta);
    strcpy(szhFormato_Fecha,"YYYYMMDD");

    vDTrazasLog (szModulo,"\n\t\t* Open=> FA_HISTDOCU, GE_TIPDOCUMEN", LOG06);

    /* EXEC SQL OPEN curDocsPeriodo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0003;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3216;
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
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhFecDesde;
    sqlstm.sqhstl[2] = (unsigned long )10;
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
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecHasta;
    sqlstm.sqhstl[4] = (unsigned long )10;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhFormato_Fecha;
    sqlstm.sqhstl[5] = (unsigned long )9;
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
        iDError (szModulo,ERR000,vInsertarIncidencia,"Open=> FA_HISTDOCU, GE_TIPDOCUMEN",szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnOpenDocsPeriodo **********************/

static BOOL bfnFetchDocsPeriodo(DOCPERIODO_HOSTS *pstHost,int *piNumFilas)
{
    char *szModulo="bfnFetchDocsPeriodo";

    /* EXEC SQL FETCH curDocsPeriodo
    INTO  :pstHost->szCodOperadora  ,
    :pstHost->szCodOficina    ,
    :pstHost->iCodTipDocum    ,
    :pstHost->szDesTipDocum   ,
    :pstHost->szPrefPlaza     ,
    :pstHost->lNumFolio       ,
    :pstHost->szFecEmision    ,
    :pstHost->dTotFactura    ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )2000;
    sqlstm.offset = (unsigned int  )3255;
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
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->szCodOficina);
    sqlstm.sqhstl[1] = (unsigned long )3;
    sqlstm.sqhsts[1] = (         int  )3;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->iCodTipDocum);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )sizeof(int);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->szDesTipDocum);
    sqlstm.sqhstl[3] = (unsigned long )41;
    sqlstm.sqhsts[3] = (         int  )41;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstHost->szPrefPlaza);
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )11;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(pstHost->lNumFolio);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )sizeof(long);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstHost->szFecEmision);
    sqlstm.sqhstl[6] = (unsigned long )11;
    sqlstm.sqhsts[6] = (         int  )11;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstHost->dTotFactura);
    sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )sizeof(double);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
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





    if ( SQLCODE==SQLOK )
        *piNumFilas = TAM_HOSTS_PEQ;
    else
        if ( SQLCODE==SQLNOTFOUND )
        *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS_PEQ;
    else
        iDError (szModulo,ERR000,vInsertarIncidencia,"Fetch=> FA_HISTDOCU, GE_TIPDOCUMEN", szfnORAerror ());
    return (SQLCODE);
}/***************************** Final bfnFetchPagos ****************/


static int ifnCloseDocsPeriodo(void)
{
    char *szModulo="ifnCloseDocsPeriodo";

    vDTrazasLog (szModulo,"\n\t\t* Open=> FA_HISTDOCU, GE_TIPDOCUMEN", LOG06);

    /* EXEC SQL CLOSE curDocsPeriodo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3302;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if ( SQLCODE != SQLOK )
    {
        iDError (szModulo,ERR000,vInsertarIncidencia,"Close=> Cursor=> FA_HISTDOCU, GE_TIPDOCUMEN", szfnORAerror ());
    }

    return (SQLCODE);
}/***************************** Final ifnClosePagos **********************/



/* FUNCION QUE RESCATA DATOS PARA EL REGISTRO A2600 (VENTAS) */
/*---------------------------------------------------------------------------*/
/* Funcion: ifnLlenarSeriesDeVenta y Notas de Cr‰dito                        */
/*---------------------------------------------------------------------------*/
/*int ifnLlenarSeriesDeVenta ( reg_entrada *pstEntrada ) INICIO 76441 CJG*/
int ifnLlenarSeriesDeVenta ( reg_entrada *pstEntrada, int iCodConcepto )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char       szTip_Docu[1+1]     ;
    static long       lhNum_venta         ;
    static long       lhCod_cliente       ;
    static long       lhNum_proceso       ;
    static int        ihTipoVenta         ;

    struct
    {
        char       szhNumSerie[25+1]   ;
        long       lhNumAbonado        ;
        long       lhCodConcepto       ;
        char       szhDesConcepto[60+1];
        long       lhNumCelular        ;
    } est_series;

    struct
    {
        short      i_szhNumSerie       ;
        short      i_lhNumAbonado      ;
        short      i_szhDesConcepto    ;
        short      i_lhNumCelular      ;
    } i_est_series;

    static SQL_CURSOR cursor_series       ;
    static short      i_cursor_series     ;
    static char       szMensError[1026+1] ;
    static short      i_szMensError       ;

    static char szFecVenta   [9]   ; /* EXEC SQL VAR szFecVenta IS STRING (9); */ 

    static char szIndVenta   [2]   ; /* EXEC SQL VAR szIndVenta IS STRING (2); */ 

    static char szhNumSerie[25+1]  ; /* EXEC SQL VAR szhNumSerie    IS STRING(25+1); */ 

    static long lhNumAbonado        ;
    static long lhCodConcepto       ;
    static char szhDesConcepto[60+1]; /* EXEC SQL VAR szhDesConcepto IS STRING(60+1); */ 

    static char chString1[1+1]     ; /* EXEC SQL VAR chString1 IS STRING (1+1); */ 

    static long lhNumCelular = 0L   ;

    /* EXEC SQL END DECLARE SECTION; */ 


    char *modulo="ifnLlenarSeriesDeVenta";
    stSalida * paux;
    long lContador = 0l;
    /* INICIO 76441 CJG */
    int ihCodConcepto = 0;
    /* int ihCountKit = 0; */
    /* FIN 76441 CJG */

    paux = NULL;

/*INICIO 71757 CJG*/
    int     i;
    char    szNum_Celular[21];
    memset(szNum_Celular,0,sizeof(szNum_Celular));
/*FIN 71757 CJG*/

    /* INICIO 76441 CJG */
    ihCodConcepto = iCodConcepto;
    /* FIN 76441 CJG */

    lhNum_venta   = pstEntrada->lNumVenta;
    lhCod_cliente = pstEntrada->lCodCliente;
    lhNum_proceso = pstEntrada->lNumProceso;
    strcpy(szTip_Docu,pstEntrada->szTipoDocum);

    memset(szMensError,0,sizeof(szMensError));

    vDTrazasLog (modulo,"\tCONCEPTO         [%ld]"
						"\n\tPROCESO        [%ld]"
    	                "\n\tTIPO DOCUMENTO [%s]"
                        "\n\tVENTA          [%ld]" ,LOG05,ihCodConcepto,lhNum_proceso,szTip_Docu,lhNum_venta);

    /* EXEC SQL ALLOCATE :cursor_series; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3317;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-ALLOCATE Cursor de Series **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-ALLOCATE Cursor de Series **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        /* EXEC SQL CLOSE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3336;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


        /* EXEC SQL FREE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3355;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


        return(SQLCODE);
    }

    /* EXEC SQL EXECUTE
    BEGIN
    NP_TRANSACCIONES_WEB_PG.NP_INFORMA_SERIES_NPW_PR(:lhNum_proceso,
                                                     :szTip_Docu,
                                                     :lhNum_venta,
                                                     :cursor_series :i_cursor_series,
                                                     :szMensError :i_szMensError);
    END;
    END-EXEC; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "begin NP_TRANSACCIONES_WEB_PG . NP_INFORMA_SERIES_NPW_PR \
( :lhNum_proceso , :szTip_Docu , :lhNum_venta , :cursor_series:i_cursor_series\
 , :szMensError:i_szMensError ) ; END ;";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3374;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_proceso;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szTip_Docu;
    sqlstm.sqhstl[1] = (unsigned long )2;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNum_venta;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&cursor_series;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)&i_cursor_series;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szMensError;
    sqlstm.sqhstl[4] = (unsigned long )1027;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)&i_szMensError;
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


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\t\tError en SQL-EXECUTE NP_TRANSACCIONES_WEB_PG **"
                      "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\t\tError en SQL-EXECUTE NP_TRANSACCIONES_WEB_PG **"
                      "\t\tError : [%s] [%d]  [%s] ",LOG01,"NP_TRANSACCIONES_WEB_PG",SQLCODE,SQLERRM);
        /* EXEC SQL CLOSE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3409;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


        /* EXEC SQL FREE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3428;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


        return(SQLCODE);
    }

    vDTrazasLog(szModulo,"\tResultado de NP_TRANSACCIONES_WEB_PG.NP_INFORMA_SERIES_NPW_PR [%d : %s] Cursor [%d]",LOG04, i_szMensError,alltrim(szMensError),i_cursor_series);

    if ( strcmp(alltrim(szMensError),"No facturado por NPW")!=0 )
    {
        for ( ;; )
        {
            /* EXEC SQL FETCH :cursor_series INTO  :est_series.szhNumSerie    :i_est_series.i_szhNumSerie
            ,:est_series.lhNumAbonado   :i_est_series.i_lhNumAbonado
            ,:est_series.lhCodConcepto
            ,:est_series.szhDesConcepto :i_est_series.i_szhDesConcepto
            ,:est_series.lhNumCelular   :i_est_series.i_lhNumCelular; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3447;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)(est_series.szhNumSerie);
            sqlstm.sqhstl[1] = (unsigned long )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&(i_est_series.i_szhNumSerie);
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&(est_series.lhNumAbonado);
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&(i_est_series.i_lhNumAbonado);
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&(est_series.lhCodConcepto);
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)(est_series.szhDesConcepto);
            sqlstm.sqhstl[4] = (unsigned long )61;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&(i_est_series.i_szhDesConcepto);
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&(est_series.lhNumCelular);
            sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&(i_est_series.i_lhNumCelular);
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



            if ( SQLCODE == SQLNOTFOUND )
                break;
            else
                if ( SQLCODE != SQLOK )
            {
                vDTrazasLog  (szModulo,"\t\tError en SQL-FETCH Cursor de Series **"
                              "\t\tError : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
                vDTrazasError(szModulo,"\t\tError en SQL-FETCH Cursor de Series **"
                              "\t\tError : [%s] [%d]  [%s] ",LOG01,"CURSOR DE SERIES",SQLCODE,SQLERRM);
                /* EXEC SQL CLOSE :cursor_series; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3486;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


                /* EXEC SQL FREE :cursor_series; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3505;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


                return(SQLCODE);
            }

            vDTrazasLog (modulo,"\tNUMERO SERIE    [%s]"
                                "\tNUMERO ABONADO  [%ld]"
                                "\tCODIGO CONCEPTO [%ld]"
                                "\tDESCRIPCION     [%s]"
                                "\tNUMERO CELULAR  [%ld]"
                               ,LOG05,alltrim(est_series.szhNumSerie)
                               ,est_series.lhNumAbonado
                               ,est_series.lhCodConcepto
                               ,alltrim(est_series.szhDesConcepto),est_series.lhNumCelular);

            paux = (stSalida *) malloc(sizeof(stSalida));

            if ( paux == NULL )
                {
                vDTrazasLog (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                vDTrazasError (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                return(FALSE);
                }

            if ( i_est_series.i_szhNumSerie!=ORA_NULL )
                sprintf(paux->szNumSerie,"%s",alltrim(est_series.szhNumSerie));

            if ( i_est_series.i_lhNumAbonado!=ORA_NULL )
                paux->lNumAbonado = est_series.lhNumAbonado;

            paux->lCodConcepto = est_series.lhCodConcepto;

            if ( i_est_series.i_szhDesConcepto!=ORA_NULL )
                sprintf(paux->szDesConcepto,"%s",alltrim(est_series.szhDesConcepto));


            if ( i_est_series.i_lhNumCelular!=ORA_NULL )
                paux->lNumCelular  = est_series.lhNumCelular;
            else
                paux->lNumCelular = 0;

            paux->sgte  = lstSalida;
            lstSalida   = paux;
            lContador++;
        }
        /* Cerrar cursor */
        /* EXEC SQL CLOSE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3524;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


        /* EXEC SQL FREE :cursor_series; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3543;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&cursor_series;
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


    }
    else
    {
        strcpy(chString1,"I");

        lhNum_venta   = pstEntrada->lNumVenta;
        lhCod_cliente = pstEntrada->lCodCliente;

        /* ----------------------------------------------*/
        /* Verificamos si la venta es prepago o postpago */
        /* ----------------------------------------------*/
        ihTipoVenta = 0;

        /* EXEC SQL
        SELECT TO_CHAR (FEC_VENTA, 'DDMMYYYY'), IND_VENTA
        INTO :szFecVenta, :szIndVenta
        FROM GA_VENTAS C
        WHERE C.NUM_VENTA   = :lhNum_venta
          AND C.COD_CLIENTE = :lhCod_cliente; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TO_CHAR(FEC_VENTA,'DDMMYYYY') ,IND_VENTA into \
:b0,:b1  from GA_VENTAS C where (C.NUM_VENTA=:b2 and C.COD_CLIENTE=:b3)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3562;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szFecVenta;
        sqlstm.sqhstl[0] = (unsigned long )9;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szIndVenta;
        sqlstm.sqhstl[1] = (unsigned long )2;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhNum_venta;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhCod_cliente;
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



        if ( SQLCODE != SQLOK )
        {
            vDTrazasLog (modulo,"\n\tERROR, al obtener procedencia de la venta. SQLCODE [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
            return (FALSE);
        }

        vDTrazasLog (modulo,"\tIND_VENTA     [%s]",LOG05,szIndVenta);
        /*if ( strcmp (szIndVenta,"E")==0 )venta por OOSS / INICIO 71757 CJG*/
        if (( strcmp (szIndVenta,"E")==0 )||( strcmp (szIndVenta,"B")==0 ))
           {
           /* Inc 140733 PPV 23/07/2010 */
           if (strcmp(szTip_Docu,"N")!=0)
           {
           	vDTrazasLog (modulo,"\n\t Se fue por distinto de NC \n", LOG05);
            /* EXEC SQL DECLARE cursorCargosOOSS_1 CURSOR FOR
            SELECT  A.NUM_SERIE,
            A.NUM_ABONADO,
            A.COD_CONCEPTO,
            B.DES_CONCEPTO
            FROM GE_CARGOS A,
            FA_CONCEPTOS B
            WHERE A.NUM_VENTA = :lhNum_venta
              AND A.COD_CLIENTE = :lhCod_cliente
              AND A.COD_CONCEPTO=B.COD_CONCEPTO
              AND A.NUM_SERIE IS NOT NULL; */ 

           }
           else /* Inc 140733 PPV 23/07/2010  se agrega consulta para NC ya que no esta el dato en la ge_cargos */
           {
            vDTrazasLog (modulo,"\n\t Se fue por NC: lhNum_venta[%ld] lhCod_cliente[%ld] \n", LOG05,lhNum_venta,lhCod_cliente);
            /* EXEC SQL DECLARE cursorCargosOOSS_2 CURSOR FOR
            SELECT  A.NUM_SERIE,
            A.NUM_ABONADO,
            A.COD_CONCEPTO,
            B.DES_CONCEPTO
            FROM FA_HISTCARGOS A,
            FA_CONCEPTOS B
            WHERE A.NUM_VENTA = :lhNum_venta
              AND A.COD_CLIENTE = :lhCod_cliente
              AND A.COD_CONCEPTO=B.COD_CONCEPTO
              AND A.NUM_SERIE IS NOT NULL; */ 

           }
           
           
           if (strcmp(szTip_Docu,"N")!=0)
           {            /* Abrir cursor */
            /* EXEC SQL OPEN cursorCargosOOSS_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0064;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3593;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
           		/* EXEC SQL OPEN cursorCargosOOSS_2; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 47;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = sq0065;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )3616;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqcmod = (unsigned int )0;
             sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
             sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
            lContador = 0;

            while ( 1 )
            {
				if (strcmp(szTip_Docu,"N")!=0)
			   {
					/* EXEC SQL
					FETCH cursorCargosOOSS_1
					INTO :szhNumSerie,
					:lhNumAbonado,
					:lhCodConcepto,
					:szhDesConcepto; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )3639;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
     sqlstm.sqhstl[0] = (unsigned long )26;
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
     sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
     sqlstm.sqhstl[3] = (unsigned long )61;
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


				}
				else
            	{
                /* EXEC SQL
                FETCH cursorCargosOOSS_2
                INTO :szhNumSerie,
                :lhNumAbonado,
                :lhCodConcepto,
                :szhDesConcepto; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3670;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
                sqlstm.sqhstl[0] = (unsigned long )26;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
                sqlstm.sqhstl[3] = (unsigned long )61;
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

            		
            	}    

                if ( SQLCODE == SQLNOTFOUND )
                    break;
                else if ( SQLCODE !=  SQLOK )
                {
                    vDTrazasLog (modulo,"\n\tERROR, al leer cursor CARGOS OOSS .SQLCODE [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
                    return (FALSE);
                }

                paux = (stSalida *) malloc(sizeof(stSalida));
                if ( paux == NULL )
                {
                    vDTrazasLog (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                    vDTrazasError (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                    return(FALSE);
                }

                strcpy(paux->szNumSerie,szhNumSerie);
                paux->lNumAbonado = lhNumAbonado;
                paux->lCodConcepto = lhCodConcepto;
                strcpy(paux->szDesConcepto,szhDesConcepto);
/*INICIO 71757 CJG*/
                if ( strcmp (szIndVenta,"E")==0 )
                {
                    for ( i=0;i < stFaDetCons.iNumReg ;i++ )
                    {
                        if ( strcmp(fnQuitaBlancos(stFaDetCons.stDetConsumo[i].szNum_Celular),"0") )
                        {
                            strcpy(szNum_Celular, stFaDetCons.stDetConsumo[i].szNum_Celular);
                            break;
                        }
                    }
                 }
                 else if ( strcmp (szIndVenta,"B")==0 )
                 {
                    /* Inc 140733 PPV 23/07/2010 */
					if (strcmp(szTip_Docu,"N")!=0)
					{
                      vDTrazasLog (modulo,"\n\t Se fue por distinto de NC \n", LOG05);				 
                      /* EXEC SQL
                         SELECT NUM_TERMINAL
                         INTO   :szNum_Celular
                         FROM GE_CARGOS
                         WHERE NUM_VENTA = :lhNum_venta
                         AND COD_CLIENTE = :lhCod_cliente
                         AND NUM_ABONADO = :lhNumAbonado
                         AND ROWNUM=1; */ 

{
                      struct sqlexd sqlstm;
                      sqlstm.sqlvsn = 12;
                      sqlstm.arrsiz = 47;
                      sqlstm.sqladtp = &sqladt;
                      sqlstm.sqltdsp = &sqltds;
                      sqlstm.stmt = "select NUM_TERMINAL into :b0  from GE_C\
ARGOS where (((NUM_VENTA=:b1 and COD_CLIENTE=:b2) and NUM_ABONADO=:b3) and ROW\
NUM=1)";
                      sqlstm.iters = (unsigned int  )1;
                      sqlstm.offset = (unsigned int  )3701;
                      sqlstm.selerr = (unsigned short)1;
                      sqlstm.cud = sqlcud0;
                      sqlstm.sqlest = (unsigned char  *)&sqlca;
                      sqlstm.sqlety = (unsigned short)4352;
                      sqlstm.occurs = (unsigned int  )0;
                      sqlstm.sqhstv[0] = (unsigned char  *)szNum_Celular;
                      sqlstm.sqhstl[0] = (unsigned long )21;
                      sqlstm.sqhsts[0] = (         int  )0;
                      sqlstm.sqindv[0] = (         short *)0;
                      sqlstm.sqinds[0] = (         int  )0;
                      sqlstm.sqharm[0] = (unsigned long )0;
                      sqlstm.sqadto[0] = (unsigned short )0;
                      sqlstm.sqtdso[0] = (unsigned short )0;
                      sqlstm.sqhstv[1] = (unsigned char  *)&lhNum_venta;
                      sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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

 /*modificado a peticion de Mario Torres*/
                     }
                     else /* Inc 140733 PPV 23/07/2010  se agrega consulta para NC ya que no esta el dato en la ge_cargos */
                     {
                     	 vDTrazasLog (modulo,"\n\t Se fue por NC \n", LOG05);
                     	 /* EXEC SQL  
                     	   SELECT NUM_TERMINAL
                         INTO   :szNum_Celular
                         FROM FA_HISTCARGOS
                         WHERE NUM_VENTA = :lhNum_venta
                         AND COD_CLIENTE = :lhCod_cliente
                         AND NUM_ABONADO = :lhNumAbonado; */ 

{
                       struct sqlexd sqlstm;
                       sqlstm.sqlvsn = 12;
                       sqlstm.arrsiz = 47;
                       sqlstm.sqladtp = &sqladt;
                       sqlstm.sqltdsp = &sqltds;
                       sqlstm.stmt = "select NUM_TERMINAL into :b0  from FA_\
HISTCARGOS where ((NUM_VENTA=:b1 and COD_CLIENTE=:b2) and NUM_ABONADO=:b3)";
                       sqlstm.iters = (unsigned int  )1;
                       sqlstm.offset = (unsigned int  )3732;
                       sqlstm.selerr = (unsigned short)1;
                       sqlstm.cud = sqlcud0;
                       sqlstm.sqlest = (unsigned char  *)&sqlca;
                       sqlstm.sqlety = (unsigned short)4352;
                       sqlstm.occurs = (unsigned int  )0;
                       sqlstm.sqhstv[0] = (unsigned char  *)szNum_Celular;
                       sqlstm.sqhstl[0] = (unsigned long )21;
                       sqlstm.sqhsts[0] = (         int  )0;
                       sqlstm.sqindv[0] = (         short *)0;
                       sqlstm.sqinds[0] = (         int  )0;
                       sqlstm.sqharm[0] = (unsigned long )0;
                       sqlstm.sqadto[0] = (unsigned short )0;
                       sqlstm.sqtdso[0] = (unsigned short )0;
                       sqlstm.sqhstv[1] = (unsigned char  *)&lhNum_venta;
                       sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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


                     }
					 
                      if(SQLCODE != SQLOK)
                      {
                         vDTrazasLog(modulo ,"\n\t**  En Select de NUM_TERMINAL  [%s] **"
                        ,LOG01,sqlca.sqlerrm.sqlerrmc);
                         vDTrazasError(modulo ,"\n\t**  En Select de NUM_TERMINAL  [%s] **"
                        ,LOG01,sqlca.sqlerrm.sqlerrmc);
                         return FALSE;
                      }

                 }
                paux->lNumCelular  =atol(szNum_Celular);
                vDTrazasLog (modulo,"\tCELULAR VTA OOSS       [%ld]",LOG05,paux->lNumCelular);

/*FIN 71757 CJG*/
                paux->sgte  = lstSalida;
                lstSalida   = paux;
                lContador++;

            }    /* while (1) */

     		if (strcmp(szTip_Docu,"N")!=0)
           	{
            		/* Cerrar cursor */
            	/* EXEC SQL CLOSE cursorCargosOOSS_1; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 47;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )3763;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            }
            else
			{
				/* EXEC SQL CLOSE cursorCargosOOSS_2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3778;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


			}

        }/*(szIndVenta,"E")(szIndVenta,"B")*/
        else
        {
            /* EXEC SQL
            SELECT COUNT(1)
            INTO :ihTipoVenta
            FROM GA_EQUIPABOSER A
            WHERE A.NUM_ABONADO IN (  SELECT B.NUM_ABONADO
                                      FROM GA_ABOAMIST B
                                      WHERE B.NUM_VENTA   = :lhNum_venta
                                      AND B.COD_CLIENTE = :lhCod_cliente
                                      AND TRUNC(B.FEC_ALTA) IN ( SELECT TRUNC(C.FEC_VENTA)
                                                                 FROM GA_VENTAS C
                                                                 WHERE C.NUM_VENTA    = :lhNum_venta
                                                                 AND C.COD_CLIENTE = :lhCod_cliente))
            AND A.IND_PROCEQUI = :chString1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 47;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(1) into :b0  from GA_EQUIPABOSER A w\
here (A.NUM_ABONADO in (select B.NUM_ABONADO  from GA_ABOAMIST B where ((B.NUM\
_VENTA=:b1 and B.COD_CLIENTE=:b2) and TRUNC(B.FEC_ALTA) in (select TRUNC(C.FEC\
_VENTA)  from GA_VENTAS C where (C.NUM_VENTA=:b1 and C.COD_CLIENTE=:b2)))) and\
 A.IND_PROCEQUI=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3793;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&ihTipoVenta;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNum_venta;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
            sqlstm.sqhstv[3] = (unsigned char  *)&lhNum_venta;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&lhCod_cliente;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)chString1;
            sqlstm.sqhstl[5] = (unsigned long )2;
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
                vDTrazasLog (modulo,"\n\tERROR, al obtener procedencia de la venta. SQLCODE [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
                return (FALSE);
            }

            if ( ihTipoVenta > 0 )
            {
                /* ----------------------------------------------*/
                /* VENTA PREPAGO                                 */
                /* ----------------------------------------------*/
                vDTrazasLog (modulo,"\n\tProcedencia es prepago KIT...", LOG05);

                /* INICIO 76441 CJG */
/* PGG SOPORTE VOLVIENDO ATRAS (COMENYANDO DESDE)- 76441 - 09-02-2009 */
/*                EXEC SQL
                SELECT COUNT(1)
                INTO :ihCountKit
                FROM AL_COMPONENTE_KIT A, AL_ARTICULOS B, GA_ABOAMIST C
                WHERE A.NUM_SERIE = C.NUM_SERIE
                AND A.COD_KIT = B.COD_ARTICULO
                AND B.COD_CONCEPTOART = :ihCodConcepto
                AND C.NUM_VENTA       = :lhNum_venta
                AND C.COD_CLIENTE     = :lhCod_cliente;

                vDTrazasLog (modulo,"\n\t prepago KIT ihCountKit==>[%ld]", LOG05,ihCountKit);
                if (ihCountKit==0)
                {
                   return (FALSE);
                }
*/
/* PGG SOPORTE VOLVIENDO ATRAS (COMENTANDO HASTA)- 76441 - 09-02-2009 */
                /* FIN 76441 CJG */


                /* Declaramos cursor */

/* PGG SOPORTE COMENTADO DESDE ACA - INC. 60409 1-1 14-12-2007  */
/* PGG SOPORTE VOLVIENDO ATRAS (DESCOMENTANDO DESDE)- 76441 - 09-02-2009 */
                /* EXEC SQL DECLARE cursorAbonadoPrePagoKIT CURSOR FOR
                    SELECT
                        A.NUM_KIT,
                        D.NUM_ABONADO,
                        B.COD_CONCEPTO,
                        B.DES_CONCEPTO,
                        NVL(A.NUM_TELEFONO,0)
                    FROM
                        AL_COMPONENTE_KIT A,
                        FA_CONCEPTOS B,
                        AL_ARTICULOS C,
                        GA_EQUIPABOSER D
                    WHERE
                        C.COD_ARTICULO  = A.COD_KIT
                        AND A.NUM_SERIE = D.NUM_SERIE
                        AND D.TIP_TERMINAL IN ( SELECT
                                                    E.VAL_PARAMETRO
                                                FROM
                                                    GED_PARAMETROS E
                                                WHERE
                                                    E.NOM_PARAMETRO IN ('TIP_DIGITAL', 'COD_SIMCARD_GSM'))
                        AND D.NUM_ABONADO IN (  SELECT
                                                    F.NUM_ABONADO
                                                FROM
                                                    GA_ABOAMIST F
                                                WHERE
                                                    F.NUM_VENTA       = :lhNum_venta
                                                    AND F.COD_CLIENTE = :lhCod_cliente
                                                    AND TRUNC(F.FEC_ALTA) IN (  SELECT
                                                                                    TRUNC(G.FEC_VENTA)
                                                                                FROM
                                                                                    GA_VENTAS G
                                                                                WHERE
                                                                                    G.NUM_VENTA       = :lhNum_venta
                                                                                    AND G.COD_CLIENTE = :lhCod_cliente))
                        AND C.COD_CONCEPTOART = B.COD_CONCEPTO
                        AND D.IND_PROCEQUI    = :chString1; */ 



                /* EXEC SQL OPEN cursorAbonadoPrePagoKIT; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = sq0069;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3832;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqcmod = (unsigned int )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
                sqlstm.sqhstv[2] = (unsigned char  *)&lhNum_venta;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&lhCod_cliente;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)chString1;
                sqlstm.sqhstl[4] = (unsigned long )2;
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


                lContador = 0;

                while (1)
                {
                    /* EXEC SQL
                        FETCH cursorAbonadoPrePagoKIT
                         INTO :szhNumSerie,
                              :lhNumAbonado,
                              :lhCodConcepto,
                              :szhDesConcepto,
                              :lhNumCelular; */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 47;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )3867;
                    sqlstm.selerr = (unsigned short)1;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)4352;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqfoff = (         int )0;
                    sqlstm.sqfmod = (unsigned int )2;
                    sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
                    sqlstm.sqhstl[0] = (unsigned long )26;
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
                    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
                    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                    sqlstm.sqhsts[2] = (         int  )0;
                    sqlstm.sqindv[2] = (         short *)0;
                    sqlstm.sqinds[2] = (         int  )0;
                    sqlstm.sqharm[2] = (unsigned long )0;
                    sqlstm.sqadto[2] = (unsigned short )0;
                    sqlstm.sqtdso[2] = (unsigned short )0;
                    sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
                    sqlstm.sqhstl[3] = (unsigned long )61;
                    sqlstm.sqhsts[3] = (         int  )0;
                    sqlstm.sqindv[3] = (         short *)0;
                    sqlstm.sqinds[3] = (         int  )0;
                    sqlstm.sqharm[3] = (unsigned long )0;
                    sqlstm.sqadto[3] = (unsigned short )0;
                    sqlstm.sqtdso[3] = (unsigned short )0;
                    sqlstm.sqhstv[4] = (unsigned char  *)&lhNumCelular;
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



                    if (SQLCODE == SQLNOTFOUND)
                        break;
                    else if (SQLCODE != SQLOK)
                    {
                        vDTrazasLog (modulo,"\n\tERROR, al leer cursor Abonado PrePago KIT.SQLCODE [%d]", LOG01,SQLCODE);
                        return FALSE;
                    }

                    paux = (stSalida *) malloc(sizeof(stSalida));
                    if(paux == NULL)
                    {
                        vDTrazasLog (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                        vDTrazasError (modulo,"\n\nERROR:1:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                        return (FALSE);
                    }


                    strcpy(paux->szNumSerie,szhNumSerie);
                    paux->lNumAbonado = lhNumAbonado;
                    paux->lCodConcepto = lhCodConcepto;
                    strcpy(paux->szDesConcepto,szhDesConcepto);
                    paux->lNumCelular  = lhNumCelular;

                    paux->sgte  = lstSalida;
                    lstSalida   = paux;
                    lContador++;

                }

                /* EXEC SQL CLOSE cursorAbonadoPrePagoKIT; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 47;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3902;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



                if (lContador == 0)
                {

            /* PGG SOPORTE VOLVIENDO ATRAS (DESCOMENTANDO HASTA)- 76441 - 09-02-2009 */
            /* PGG SOPORTE COMENTADO HASTA ACA - INC. 60409 1-1 14-12-2007  */

                            vDTrazasLog (modulo,"\n\tProcedencia es prepago...", LOG05);

                            /* Declaramos cursor */
                            /* EXEC SQL DECLARE cursorAbonadoPrePago CURSOR FOR
                            SELECT
                            A.NUM_SERIE,
                            A.NUM_ABONADO,
                            B.COD_CONCEPTO,
                            B.DES_CONCEPTO,
                            D.NUM_CELULAR             /o P-ECU-05021 o/
                            FROM
                            GA_EQUIPABOSER A,
                            FA_CONCEPTOS   B,
                            AL_ARTICULOS   C,
                            GA_ABOAMIST    D          /o P-ECU-05021 o/
                            WHERE
                            A.NUM_ABONADO IN (SELECT
                                              D.NUM_ABONADO
                                              FROM
                                              GA_ABOAMIST D
                                              WHERE
                                              D.NUM_VENTA       = :lhNum_venta
                                              AND D.COD_CLIENTE = :lhCod_cliente
                                              AND TRUNC(D.FEC_ALTA) IN (SELECT
                                                                        TRUNC(E.FEC_VENTA)
                                                                        FROM
                                                                        GA_VENTAS E
                                                                        WHERE
                                                                        E.NUM_VENTA       = :lhNum_venta
                                                                        AND E.COD_CLIENTE = :lhCod_cliente))
                            AND C.COD_ARTICULO    = A.COD_ARTICULO
                            AND C.COD_CONCEPTOART = B.COD_CONCEPTO
                            AND A.NUM_ABONADO     = D.NUM_ABONADO  /o P-ECU-05021 o/
                            AND A.IND_PROCEQUI    = :chString1
                            GROUP BY A.NUM_SERIE,
                            A.NUM_ABONADO,                           /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
                            B.COD_CONCEPTO,                          /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
                            B.DES_CONCEPTO,                          /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
                            D.NUM_CELULAR  ; */ 
                         /*FPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTAS*/

                            /* Abrir cursor */
                            /* EXEC SQL OPEN cursorAbonadoPrePago; */ 

{
                            struct sqlexd sqlstm;
                            sqlstm.sqlvsn = 12;
                            sqlstm.arrsiz = 47;
                            sqlstm.sqladtp = &sqladt;
                            sqlstm.sqltdsp = &sqltds;
                            sqlstm.stmt = sq0070;
                            sqlstm.iters = (unsigned int  )1;
                            sqlstm.offset = (unsigned int  )3917;
                            sqlstm.selerr = (unsigned short)1;
                            sqlstm.cud = sqlcud0;
                            sqlstm.sqlest = (unsigned char  *)&sqlca;
                            sqlstm.sqlety = (unsigned short)4352;
                            sqlstm.occurs = (unsigned int  )0;
                            sqlstm.sqcmod = (unsigned int )0;
                            sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
                            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
                            sqlstm.sqhstv[2] = (unsigned char  *)&lhNum_venta;
                            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                            sqlstm.sqhsts[2] = (         int  )0;
                            sqlstm.sqindv[2] = (         short *)0;
                            sqlstm.sqinds[2] = (         int  )0;
                            sqlstm.sqharm[2] = (unsigned long )0;
                            sqlstm.sqadto[2] = (unsigned short )0;
                            sqlstm.sqtdso[2] = (unsigned short )0;
                            sqlstm.sqhstv[3] = (unsigned char  *)&lhCod_cliente;
                            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
                            sqlstm.sqhsts[3] = (         int  )0;
                            sqlstm.sqindv[3] = (         short *)0;
                            sqlstm.sqinds[3] = (         int  )0;
                            sqlstm.sqharm[3] = (unsigned long )0;
                            sqlstm.sqadto[3] = (unsigned short )0;
                            sqlstm.sqtdso[3] = (unsigned short )0;
                            sqlstm.sqhstv[4] = (unsigned char  *)chString1;
                            sqlstm.sqhstl[4] = (unsigned long )2;
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




                            while ( 1 )
                            {
                                /* EXEC SQL
                                FETCH cursorAbonadoPrePago
                                INTO :szhNumSerie,
                                :lhNumAbonado,
                                :lhCodConcepto,
                                :szhDesConcepto,
                                :lhNumCelular; */ 

{
                                struct sqlexd sqlstm;
                                sqlstm.sqlvsn = 12;
                                sqlstm.arrsiz = 47;
                                sqlstm.sqladtp = &sqladt;
                                sqlstm.sqltdsp = &sqltds;
                                sqlstm.iters = (unsigned int  )1;
                                sqlstm.offset = (unsigned int  )3952;
                                sqlstm.selerr = (unsigned short)1;
                                sqlstm.cud = sqlcud0;
                                sqlstm.sqlest = (unsigned char  *)&sqlca;
                                sqlstm.sqlety = (unsigned short)4352;
                                sqlstm.occurs = (unsigned int  )0;
                                sqlstm.sqfoff = (         int )0;
                                sqlstm.sqfmod = (unsigned int )2;
                                sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
                                sqlstm.sqhstl[0] = (unsigned long )26;
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
                                sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
                                sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                                sqlstm.sqhsts[2] = (         int  )0;
                                sqlstm.sqindv[2] = (         short *)0;
                                sqlstm.sqinds[2] = (         int  )0;
                                sqlstm.sqharm[2] = (unsigned long )0;
                                sqlstm.sqadto[2] = (unsigned short )0;
                                sqlstm.sqtdso[2] = (unsigned short )0;
                                sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
                                sqlstm.sqhstl[3] = (unsigned long )61;
                                sqlstm.sqhsts[3] = (         int  )0;
                                sqlstm.sqindv[3] = (         short *)0;
                                sqlstm.sqinds[3] = (         int  )0;
                                sqlstm.sqharm[3] = (unsigned long )0;
                                sqlstm.sqadto[3] = (unsigned short )0;
                                sqlstm.sqtdso[3] = (unsigned short )0;
                                sqlstm.sqhstv[4] = (unsigned char  *)&lhNumCelular;
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



                                if ( SQLCODE == SQLNOTFOUND )
                                    break;
                                else if ( SQLCODE != SQLOK )
                                {
                                    vDTrazasLog (modulo,"\n\tERROR, Al leer cursor Abonado PrePago. SQLCODE [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
                                    return (FALSE);
                                }

                                paux = (stSalida *) malloc(sizeof(stSalida));
                                if ( paux == NULL )
                                {
                                    vDTrazasLog (modulo,"\n\nERROR:2:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                                    vDTrazasError (modulo,"\n\nERROR:2:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                                    return(FALSE);
                                }


                                strcpy(paux->szNumSerie,szhNumSerie);
                                paux->lNumAbonado = lhNumAbonado;
                                paux->lCodConcepto = lhCodConcepto;
                                strcpy(paux->szDesConcepto,szhDesConcepto);
                                paux->lNumCelular  = lhNumCelular;     /* P-ECU-05021 */

                                paux->sgte  = lstSalida;
                                lstSalida   = paux;


                            }    /* while (1) */

                            /* Cerrar cursor */
                            /* EXEC SQL CLOSE cursorAbonadoPrePago; */ 

{
                            struct sqlexd sqlstm;
                            sqlstm.sqlvsn = 12;
                            sqlstm.arrsiz = 47;
                            sqlstm.sqladtp = &sqladt;
                            sqlstm.sqltdsp = &sqltds;
                            sqlstm.iters = (unsigned int  )1;
                            sqlstm.offset = (unsigned int  )3987;
                            sqlstm.cud = sqlcud0;
                            sqlstm.sqlest = (unsigned char  *)&sqlca;
                            sqlstm.sqlety = (unsigned short)4352;
                            sqlstm.occurs = (unsigned int  )0;
                            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                } /* if (lContador = 0) */ /* PGG SOPORTE SE ELIMINA EL CIERRE DEL IF. INC. 60409 1-1 14-12-2007 */ /* PGG SOPORTE VOLVIENDO ATRAS - 76441 - 09-02-2009 */
            }
            else
            {
                /* ----------------------------------------------*/
                /* VENTA POSTPAGO                                */
                /* ----------------------------------------------*/
                vDTrazasLog (modulo,"\n\tProcedencia es postpago...", LOG05);

                /* Inc 140733 PPV 23/07/2010 */
           		if (strcmp(szTip_Docu,"N")!=0)
           		{
					vDTrazasLog (modulo,"\n\t Se fue por distinto de NC \n", LOG05);
					/* Declaramos cursor */
					/* EXEC SQL DECLARE cursorAbonadoPostPago_1 CURSOR FOR
					
					SELECT
					A.NUM_SERIE
					,A.NUM_ABONADO
					,B.COD_CONCEPTO
					,B.DES_CONCEPTO
					,D.NUM_CELULAR             /o P-ECU-05021 o/
					FROM
					GA_EQUIPABOSER A
					,FA_CONCEPTOS B
					,AL_ARTICULOS C
					,GA_ABOCEL     D           /o P-ECU-05021 o/
					WHERE
					A.NUM_ABONADO IN (SELECT
									  D.NUM_ABONADO
									  FROM
									  GA_ABOCEL D
									  WHERE
									  D.NUM_VENTA       = :lhNum_venta
									  AND D.COD_CLIENTE = :lhCod_cliente
									  AND TRUNC(D.FEC_ALTA) IN (SELECT
																TRUNC(E.FEC_VENTA)
																FROM
																GA_VENTAS E
																WHERE
																E.NUM_VENTA       = :lhNum_venta
																AND E.COD_CLIENTE = :lhCod_cliente))
					AND C.COD_ARTICULO    = A.COD_ARTICULO
											AND C.COD_CONCEPTOART = B.COD_CONCEPTO
											AND A.NUM_ABONADO     = D.NUM_ABONADO  /o P-ECU-05021 o/
											AND A.IND_PROCEQUI    = :chString1
											GROUP BY A.NUM_SERIE,
					A.NUM_ABONADO,                           /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
					B.COD_CONCEPTO,                          /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
					B.DES_CONCEPTO,                          /oFPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTASo/
					D.NUM_CELULAR  ; */ 
                         /*FPH 38244 SE AGRUPA PARA EVITAR SERIES REPETIDAS ASOCIADAS A VENTAS*/
				}
				else
				{
				   vDTrazasLog (modulo,"\n\t Se fue por NC \n", LOG05);
					/* Declaramos cursor */
					/* EXEC SQL DECLARE cursorAbonadoPostPago_2 CURSOR FOR
									SELECT  A.NUM_SERIE,A.NUM_ABONADO,A.COD_CONCEPTO,B.DES_CONCEPTO, D.NUM_CELULAR
									FROM FA_HISTCARGOS A,FA_CONCEPTOS B, GA_ABOCEL D
									WHERE A.NUM_VENTA = :lhNum_venta
									AND A.COD_CLIENTE = :lhCod_cliente
									AND A.COD_CONCEPTO=B.COD_CONCEPTO
									AND A.NUM_ABONADO     = D.NUM_ABONADO
									AND A.NUM_SERIE IS NOT NULL; */ 

				}

                /* Abrir cursor */
                if (strcmp(szTip_Docu,"N")!=0)
           		{
					/* EXEC SQL OPEN cursorAbonadoPostPago_1; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0071;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4002;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
     sqlstm.sqhstv[2] = (unsigned char  *)&lhNum_venta;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&lhCod_cliente;
     sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)chString1;
     sqlstm.sqhstl[4] = (unsigned long )2;
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


				}
				else
				{
					/* EXEC SQL OPEN cursorAbonadoPostPago_2; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0072;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4037;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&lhNum_venta;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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

                while ( 1 )
                {
				  if (strcmp(szTip_Docu,"N")!=0)
				  {
					/* EXEC SQL
					FETCH cursorAbonadoPostPago_1
					INTO :szhNumSerie
					,:lhNumAbonado
					,:lhCodConcepto
					,:szhDesConcepto
					,:lhNumCelular; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4060;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
     sqlstm.sqhstl[0] = (unsigned long )26;
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
     sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
     sqlstm.sqhstl[3] = (unsigned long )61;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)&lhNumCelular;
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


				   }
				   else
				   {
					/* EXEC SQL
					FETCH cursorAbonadoPostPago_2
					INTO :szhNumSerie
					,:lhNumAbonado
					,:lhCodConcepto
					,:szhDesConcepto
					,:lhNumCelular; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4095;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerie;
     sqlstm.sqhstl[0] = (unsigned long )26;
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
     sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConcepto;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)szhDesConcepto;
     sqlstm.sqhstl[3] = (unsigned long )61;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)&lhNumCelular;
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

                   	
				   }

                    if ( SQLCODE == SQLNOTFOUND )
                        break;
                    else if ( SQLCODE != SQLOK )
                    {
                        vDTrazasLog (modulo,"\n\tERROR, al leer cursor Abonado PostPago. SQLCODE[%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
                        return (FALSE);
                    }

                    paux = (stSalida *) malloc(sizeof(stSalida));
                    if ( paux == NULL )
                    {
                        vDTrazasLog (modulo,"\n\nERROR:3:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                        vDTrazasError (modulo,"\n\nERROR:3:(%s): En asignacion de memoria a paux.", LOG05,modulo );
                        return(FALSE);
                    }

                    strcpy(paux->szNumSerie,szhNumSerie);
                    paux->lNumAbonado = lhNumAbonado;
                    paux->lCodConcepto = lhCodConcepto;
                    strcpy(paux->szDesConcepto,szhDesConcepto);
                    paux->lNumCelular  = lhNumCelular; /* P-ECU-05021 */

                    paux->sgte  = lstSalida;
                    lstSalida   = paux;

                }/* while (1) */

                /* Cerrar cursor */
				if (strcmp(szTip_Docu,"N")!=0)
				{
					/* EXEC SQL CLOSE cursorAbonadoPostPago_1; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4130;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				}
				else
				{
					/* EXEC SQL CLOSE cursorAbonadoPostPago_2; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 47;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )4145;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


				}

            }/* if (ihTipoVenta > 0) */
        } /* if OOSS */

    }

    return (TRUE);
} /* ifnLlenarSeriesDeVenta */


int ifnObtenerSeriesFactMiscela(reg_entrada *pstEntrada)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long    lhNumProceso     = 0L;
    long    lhCodConcepto    = 0L;
    long    lhColumna        = 0L;
    char    szhNumSerieResp  [30];   /* EXEC SQL VAR szhNumSerieResp IS STRING(30); */ 

    long    lhNumProcesoResp = 0L;
    long    lhCodConceptoResp= 0L;
    long    lhColumnaResp    = 0L;
    /* EXEC SQL END   DECLARE SECTION; */ 


    char    szhDesConcepto[60+1];

    char *pszModulo="ifnObtenerSeriesFactMiscela";

    stSalida *paux;

    lhNumProceso     = pstEntrada->lNumProceso;
    lhCodConcepto    = pstEntrada->lCodConcepto;
    lhColumna        = pstEntrada->iColumna;
    strcpy(szhDesConcepto,pstEntrada->szDesConcepto);

    paux = NULL;

    vDTrazasLog (pszModulo,"\n\tProceso: [%ld]", LOG05,lhNumProceso);
    vDTrazasLog (pszModulo,"\n\tConcepto: [%ld]", LOG05,lhCodConcepto);
    vDTrazasLog (pszModulo,"\n\tColumna: [%ld]", LOG05,lhColumna);


    /* EXEC SQL DECLARE curSeriesMiscelaneas CURSOR FOR
    SELECT
    A.NUM_SERIE,
    A.NUM_PROCESO,
    A.COD_CONCEPTO,
    A.COLUMNA
    FROM
    FA_SERIES_TO A
    WHERE
    A.NUM_PROCESO      = :lhNumProceso
                         AND A.COD_CONCEPTO = :lhCodConcepto
                         AND A.COLUMNA      = :lhColumna; */ 


    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (pszModulo,"\n\tERROR, En DECLARE de cursor curSeriesMiscelaneas, sqlcode: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    /* Apertura del cursor */
    /* EXEC SQL OPEN curSeriesMiscelaneas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0073;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4160;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodConcepto;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhColumna;
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



    for ( ;; )
    {

        /* EXEC SQL
        FETCH
        curSeriesMiscelaneas
        INTO
        :szhNumSerieResp,
        :lhNumProcesoResp,
        :lhCodConceptoResp,
        :lhColumnaResp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 47;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4187;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhNumSerieResp;
        sqlstm.sqhstl[0] = (unsigned long )30;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNumProcesoResp;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodConceptoResp;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhColumnaResp;
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



        if ( SQLCODE == SQLNOTFOUND )
            break;

        if ( SQLCODE !=SQLOK )
        {
            vDTrazasLog (pszModulo,"\n\tERROR, En FETCH de cursor curSeriesMiscelaneas, sqlcode: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
            return (FALSE);
        }


        paux = (stSalida *) malloc(sizeof(stSalida));
        if ( paux == NULL )
        {
            vDTrazasLog (pszModulo,"\n\nERROR:(%s): En asignacion de memoria a paux.", LOG05,pszModulo );
            vDTrazasError (pszModulo,"\n\nERROR:(%s): En asignacion de memoria a paux.", LOG05,pszModulo );
            return(FALSE);
        }

        strcpy(paux->szNumSerie,szhNumSerieResp);
        paux->lNumAbonado  = 0L;
        paux->lCodConcepto = lhCodConceptoResp;
        strcpy(paux->szDesConcepto,szhDesConcepto);
        paux->lNumCelular  = 0L;

        paux->sgte  = lstSalida;
        lstSalida   = paux;

    }    /* for(;;) */

    /* Cierre del cursor */
    /* EXEC SQL CLOSE curSeriesMiscelaneas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4218;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}




    return (TRUE);
}

/*
 * Obtener Valor total de la deuda financiada y saldo pendiente para la cuota ingresada
 * por parametro.
 */

int ifnObtenerMontosTotalesCuota( rg_cuotas pstCuota, double *pdMtoTotDeuda, double *pdMtoSaldoPend)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int    ihCodCliente        = 0;
    int    ihValorUno          = 1;
    long   lhNumFolio          = 0L;
    double dhMtoDeudaCartera   = 0.0;
    double dhMtoPagadoCartera  = 0.0;
    double dhTotalCancelado    = 0.0;
    double dhMtoInformado      = 0.0;
    char   szhPrefPlaza[11]    = "" ; /* EXEC SQL VAR szhPrefPlaza IS STRING(11); */ 

    /* EXEC SQL END   DECLARE SECTION; */ 


    double dMontoTotalDeuda = 0.0;
    double dSaldoPendiente  = 0.0;

    char *pszModulo="ifnObtenerMontosTotalesCuota";

    vDTrazasLog (pszModulo,"\tDentro de la funcion(%s):  \n"
                 "\t\tCodigo de Cliente : [%d] \n"
                 "\t\tNumero de folio   : [%ld]"
                 "\t\tPrefijo plaza     : [%s]"
                 , LOG05
                 , pszModulo
                 , pstCuota.iCodCliente
                 , pstCuota.lNum_Folio
                 , pstCuota.szPrefPlaza);


    ihCodCliente  = pstCuota.iCodCliente;
    lhNumFolio    = pstCuota.lNum_Folio;
    strcpy(szhPrefPlaza, pstCuota.szPrefPlaza);

    /* Consultar Monto Total y pagado a la fecha en CO_CARTERA */
    /* EXEC SQL
    SELECT
    SUM(A.IMPORTE_DEBE),
    SUM(A.IMPORTE_HABER)
    INTO
    :dhMtoDeudaCartera,
    :dhMtoPagadoCartera
    FROM
    CO_CARTERA A
    WHERE
    A.COD_CLIENTE      = :ihCodCliente
                         AND A.NUM_FOLIO    = :lhNumFolio
                         AND A.PREF_PLAZA   = :szhPrefPlaza
                         GROUP BY
                         A.COD_CLIENTE,
    A.NUM_FOLIO,
    A.PREF_PLAZA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select sum(A.IMPORTE_DEBE) ,sum(A.IMPORTE_HABER) into :b0\
,:b1  from CO_CARTERA A where ((A.COD_CLIENTE=:b2 and A.NUM_FOLIO=:b3) and A.P\
REF_PLAZA=:b4) group by A.COD_CLIENTE,A.NUM_FOLIO,A.PREF_PLAZA";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4233;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dhMtoDeudaCartera;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&dhMtoPagadoCartera;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
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



    if ( SQLCODE!=SQLOK && SQLCODE!=SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nERROR:(%s): En SELECT A CO_CARTERA, SQLCODE: [%d]\n[%s].", LOG01,pszModulo,SQLCODE,SQLERRM);
        return (FALSE);
    }

    if ( SQLCODE == SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nATENCION:(%s): No se encuentran datos en CO_CARTERA, Numero de registros: [%d].", LOG05,pszModulo,sqlca.sqlerrd[2]);

        dhMtoDeudaCartera  = 0.0;
        dhMtoPagadoCartera = 0.0;
    }

    /* Obtencion de Monto de cuotas existentes en CO_CANCELADAS */
    /* EXEC SQL
    SELECT
    SUM(A.IMPORTE_HABER)
    INTO
    :dhTotalCancelado
    FROM
    CO_CANCELADOS A
    WHERE
    A.COD_CLIENTE      = :ihCodCliente
                         AND A.NUM_FOLIO    = :lhNumFolio
                         AND A.PREF_PLAZA   = :szhPrefPlaza
                         GROUP BY
                         A.COD_CLIENTE,
    A.NUM_FOLIO,
    A.PREF_PLAZA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select sum(A.IMPORTE_HABER) into :b0  from CO_CANCELADOS \
A where ((A.COD_CLIENTE=:b1 and A.NUM_FOLIO=:b2) and A.PREF_PLAZA=:b3) group b\
y A.COD_CLIENTE,A.NUM_FOLIO,A.PREF_PLAZA";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4268;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dhTotalCancelado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[3] = (unsigned long )11;
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



    if ( SQLCODE!=SQLOK && SQLCODE!=SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nERROR:(%s): En SELECT A CO_CANCELADOS, SQLCODE: [%d]\n[%s].", LOG01,pszModulo,SQLCODE,SQLERRM);
        return (FALSE);
    }

    if ( SQLCODE == SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nATENCION:(%s): No se encuentran datos en CO_CANCELADOS, Numero de registros: [%d].", LOG05,pszModulo,sqlca.sqlerrd[2]);
        dhTotalCancelado = 0.0;
    }

    /* 20060705: Obtencion de la suma de coutas informadas desde CO_CARTERA */
    /* EXEC SQL
    SELECT
    SUM(A.IMPORTE_DEBE - A.IMPORTE_HABER)
    INTO
    :dhMtoInformado
    FROM
    CO_CARTERA A
    WHERE
    A.COD_CLIENTE       = :ihCodCliente
                          AND A.NUM_FOLIO     = :lhNumFolio
                          AND A.PREF_PLAZA    = :szhPrefPlaza
                          AND A.IND_FACTURADO = :ihValorUno
                          GROUP BY
                          A.COD_CLIENTE,
    A.NUM_FOLIO,
    A.PREF_PLAZA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select sum((A.IMPORTE_DEBE-A.IMPORTE_HABER)) into :b0  fr\
om CO_CARTERA A where (((A.COD_CLIENTE=:b1 and A.NUM_FOLIO=:b2) and A.PREF_PLA\
ZA=:b3) and A.IND_FACTURADO=:b4) group by A.COD_CLIENTE,A.NUM_FOLIO,A.PREF_PLA\
ZA";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4299;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dhMtoInformado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[3] = (unsigned long )11;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&ihValorUno;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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



    if ( SQLCODE!=SQLOK && SQLCODE!=SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nERROR:(%s): En SELECT de cuotas informadas CO_CARTERA, SQLCODE: [%d]\n[%s].", LOG01,pszModulo,SQLCODE,SQLERRM);
        return (FALSE);
    }

    if ( SQLCODE == SQLNOTFOUND )
    {
        vDTrazasLog (pszModulo,"\n\nATENCION:(%s): No se encuentran datos de cuotas informadas en CO_CARTERA, Numero de registros: [%d].", LOG05,pszModulo,sqlca.sqlerrd[2]);
        dhMtoInformado = 0.0;
    }

    vDTrazasLog (pszModulo,"\n\nINFO:(%s): dhMtoInformado: [%015.4f].", LOG06,pszModulo,SQLCODE);

    /* Calculo del Monto Total y del saldo pendiente */
    dMontoTotalDeuda = dhMtoDeudaCartera + dhTotalCancelado;
    /*dSaldoPendiente  = dMontoTotalDeuda - (dhMtoPagadoCartera + dhTotalCancelado + dhMtoInformado);    */ /* PGG SOPORTE 7-07-2006 CUOTAS MALAS */
    dSaldoPendiente  = dMontoTotalDeuda - (dhMtoPagadoCartera + dhTotalCancelado + pstCuota.dMtoCuota);     /* PGG SOPORTE 7-07-2006 CUOTAS MALAS */


    vDTrazasLog("ifnObtenerMontosTotalesCuota", "\t(ifnObtenerMontosTotalesCuota): Monto Total deuda : [%015.4f]\n"
                "\t(ifnObtenerMontosTotalesCuota): Saldo Pendiente   : [%015.4f]"
                , LOG06, dMontoTotalDeuda, dSaldoPendiente);


    /* Traspaso a las variables por referencia */
    *pdMtoTotDeuda = dMontoTotalDeuda;
    *pdMtoSaldoPend= dSaldoPendiente;

    return (TRUE);
}



/* FUNCION QUE RESCATA EL PLAN TARIFARIO DEL ABONADO DE LA GA_INFACCEL*/
/*---------------------------------------------------------------------------*/
/* Funcion: bfnGetPlanTarifAbo                                            */
/*---------------------------------------------------------------------------*/
BOOL bfnGetPlanTarifAbo(long lNumAbonado, long lCodcliente, char *szCodPlanTarifAbo)
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhCodPlanTarif[4]; /* EXEC SQL VAR szhCodPlanTarif IS STRING(4); */ 

    long lhNumAbonado;
    /* EXEC SQL END   DECLARE SECTION; */ 


    lhCodCliente = lCodcliente;
    lhNumAbonado = lNumAbonado;

    /* EXEC SQL
    SELECT COD_PLANTARIF
    INTO :szhCodPlanTarif
    FROM GA_INTARCEL
    WHERE COD_CLIENTE  = :lhCodCliente
      AND NUM_ABONADO  = :lhNumAbonado
      AND ROWNUM < 2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_PLANTARIF into :b0  from GA_INTARCEL where ((C\
OD_CLIENTE=:b1 and NUM_ABONADO=:b2) and ROWNUM<2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4334;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodPlanTarif;
    sqlstm.sqhstl[0] = (unsigned long )4;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog ("bfnGetPlanTarifAbo","\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }
    strcpy (szCodPlanTarifAbo, szhCodPlanTarif);
    return(TRUE);
}
/***********************************************************************************/
/**
 * Funcion      : bfnEsMovMiscelaneo
 * Descripcion  : Verfica que el documento pasado por parametro sea un movmiento miscelaneo.
 * Parametros   : iCodTipDocum      Codigo de tipo de documento.
 *                iCodMiscela       Codigo de documento miscelaneo almacenado en FA_DATOSGENER
 * Retorna      : TRUE              Es movimiento miscelaneo.
 *              : FALSE             No es movimiento miscelaneo.
 */
BOOL bfnEsMovMiscelaneo(int iCodTipDocum, int iCodMiscela)
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int ihCodMiscela  = 0;
    int ihContador    = 0;
    /* EXEC SQL END   DECLARE SECTION; */ 

    char *szModulo="bfnEsMovMiscelaneo";


    vDTrazasLog (szModulo,"\n\t\t* Dentro de la funcion bfnEsMovMiscelaneo()", LOG05);

    /* Asignacion de los parametros a las variables Host */
    gihCodTipDocum = iCodTipDocum;
    ihCodMiscela  = iCodMiscela;

    /* EXEC SQL
    SELECT COUNT(1)
    INTO   :ihContador
    FROM   FA_TIPMOVIMIEN A
    WHERE  A.COD_TIPMOVIMIEN  = :ihCodMiscela
      AND  A.COD_TIPDOCUM = :gihCodTipDocum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(1) into :b0  from FA_TIPMOVIMIEN A where (A.\
COD_TIPMOVIMIEN=:b1 and A.COD_TIPDOCUM=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4361;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihContador;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodMiscela;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&gihCodTipDocum;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\t\t* (bfnEsMovMiscelaneo) Valor devuelto por SELECT, ihContador :[%d]", LOG05, ihContador);

    /* Si existe movimiento miscelaneo para el documento, se retorna TRUE */
    if ( ihContador > 0 )
        return (TRUE);
    else
        return (FALSE);
}

/***********************************************************************************/
/**
 * Funcion      : ifnAgruparCuotas
 * Descripcion  : Verfica que el documento pasado por parametro sea un movmiento miscelaneo.
 * Parametros   : stCuotasNoAgrup   Registro de cuotas no agrupadas.
 *                iNumCuotasNoAgrup Numero de cuotas no agrupadas.
 *                stCuotasAgrup     Estructura de cuotas agrupadas.
 * Retorna      : El numero de cuotas agrupadas.
 */
int ifnAgruparCuotas(rg_cuotas *stCuotasNoAgrup, int iNumCuotasNoAgrup, rg_cuotas *stCuotasAgrup)
{
    register int i = 0;
    register int iInd = 0;
    register int j = 0;
    int iFlagAcum;
    char *szModulo="ifnAgruparCuotas";
    char sz_IndAcelerada[2];

    /* Comienzo de agrupacion de cuotas */

    vDTrazasLog (szModulo,"\n\t\t* Dentro de la funcion ifnAgruparCuotas()", LOG05);
    
    for ( i=0; i<iNumCuotasNoAgrup ; i++ )/*FPH se saca el -1al control del icon la variable EC-218*/
    {
        /* Si es el primero, se copia */
        if ( i==0 )
        {
            memcpy(&stCuotasAgrup[iInd], &stCuotasNoAgrup[i], sizeof(stCuotasNoAgrup[i]));
            iInd++;
		}else{
	        iFlagAcum = FALSE;
	        for(j = 0; j < iInd; j++)
	        {
		        if ( (stCuotasAgrup[j].lNum_Folio           == stCuotasNoAgrup[i].lNum_Folio)          &&
		              strcmp(stCuotasAgrup[j].szPrefPlaza ,    stCuotasNoAgrup[i].szPrefPlaza     )==0 &&
		             (stCuotasAgrup[j].iSecCuota            == stCuotasNoAgrup[i].iSecCuota       )    &&
		             (stCuotasAgrup[j].iNumCuota            == stCuotasNoAgrup[i].iNumCuota       )    &&
		              strcmp(stCuotasAgrup[j].szFechaEfectiva, stCuotasNoAgrup[i].szFechaEfectiva )==0 &&
		             (stCuotasAgrup[j].iInd_Facturado       == stCuotasNoAgrup[i].iInd_Facturado  )    &&
                     strcmp(stCuotasAgrup[j].sz_IndAcelerada , stCuotasNoAgrup[i].sz_IndAcelerada) == 0
		           )
		        {
		            stCuotasAgrup[j].dMtoCuota += stCuotasNoAgrup[i].dMtoCuota;
		            iFlagAcum = TRUE;
		            break;
		        }
	        }
	        
	        if(!iFlagAcum)
	        {
	            memcpy(&stCuotasAgrup[iInd], &stCuotasNoAgrup[i], sizeof(stCuotasNoAgrup[i]));
	            iInd++;
	        }
    	}
    }

    vDTrazasLog (szModulo,"\n\t\t* (ifnAgruparCuotas) Se devuelve de la funcion j: [%d]", LOG05, iInd);

    /* Se devuelve el numero de cuotas agrupadas */
    return(iInd);
}


/***********************************************************************************/
int ifnCmpOrden(const void *cad1,const void *cad2)
{
    return( strcmp (((ST_ORDEN  *)cad1)->szKey,((ST_ORDEN  *)cad2)->szKey) );
}


/***********************************************************************************/
int ifnLiberaDetCons (void)
{
    free(stFaDetCons.stDetConsumo);
    memset (&stFaDetCons,0,sizeof(stFaDetCons));

    /* estructura de indice de orden alterno */
    free(stOrden2DetConsumo.stOrden);
    memset(&stOrden2DetConsumo, 0, sizeof (stOrden2DetConsumo));

    /* estructura de indice de orden alterno de Cargos*/
    free(stOrden2DetConsumo_Cargos.stOrden);
    memset(&stOrden2DetConsumo_Cargos, 0, sizeof (stOrden2DetConsumo_Cargos));
    
    /* estructura de Promociones de Trafico*/
	if(pstPromTrafClie.iNumPromClie > 0)
	{
    	free(pstPromTrafClie.stPromocionesClie);
    	memset(&pstPromTrafClie, 0, sizeof (pstPromTrafClie));
    }
    
    return (1);
}


/**
 * Funcion      : bfnObtieneVentaRelacionada
 * Descripcion  : Obtiene Venta relacionada con un documentos Nota de Cr‰dito
 * Parametros   : lNumSecuRel       Numero de Secuencia relacionada
                  szLetraRel        Letra relacionada
                  iCodTipDocumRel   Tipo de Documento relacionado
                  lCodVendedorAgRel Vendedor relacionado
                  lCodCentrRel      Centro Emisor relacionado
                  lNumVenta         Numero de Venta entregado
 * Retorna      : TRUE o FALSE seg”n corresponda
 */
BOOL bfnObtieneVentaRelacionada(long lNumSecuRel,char szLetraRel[2],int iCodTipDocumRel,long lCodVendedorAgRel,long lCodCentrRel,long *lNumVenta)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long     lhNumSecuRel       ;
    char     szhLetraRel[2]     ;
    int      ihCodTipDocumRel   ;
    long     lhCodVendedorAgRel ;
    long     lhCodCentrRel      ;
    long     lhNumVenta         ;
    /* EXEC SQL END   DECLARE SECTION; */ 

    char *szModulo="bfnObtieneVentaRelacionada";


    lhNumSecuRel       = lNumSecuRel      ;
    strcpy(szhLetraRel , szLetraRel)      ;
    ihCodTipDocumRel   = iCodTipDocumRel  ;
    lhCodVendedorAgRel = lCodVendedorAgRel;
    lhCodCentrRel      = lCodCentrRel     ;
    ihZero             = 0;

    /* EXEC SQL
    SELECT NVL(NUM_VENTA,:ihZero)
    INTO :lhNumVenta
    FROM (
         SELECT NUM_VENTA FROM FA_FACTDOCU_NOCICLO
         WHERE NUM_SECUENCI = :lhNumSecuRel
         AND COD_TIPDOCUM = :ihCodTipDocumRel
         AND COD_VENDEDOR_AGENTE = :lhCodVendedorAgRel
         AND LETRA = :szhLetraRel
         AND COD_CENTREMI = :lhCodCentrRel
         UNION
         SELECT NUM_VENTA FROM FA_HISTDOCU
         WHERE NUM_SECUENCI = :lhNumSecuRel
         AND COD_TIPDOCUM = :ihCodTipDocumRel
         AND COD_VENDEDOR_AGENTE = :lhCodVendedorAgRel
         AND LETRA = :szhLetraRel
         AND COD_CENTREMI = :lhCodCentrRel); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(NUM_VENTA,:b0) into :b1  from (select NUM_VENT\
A  from FA_FACTDOCU_NOCICLO where ((((NUM_SECUENCI=:b2 and COD_TIPDOCUM=:b3) a\
nd COD_VENDEDOR_AGENTE=:b4) and LETRA=:b5) and COD_CENTREMI=:b6) union select \
NUM_VENTA  from FA_HISTDOCU where ((((NUM_SECUENCI=:b2 and COD_TIPDOCUM=:b3) a\
nd COD_VENDEDOR_AGENTE=:b4) and LETRA=:b5) and COD_CENTREMI=:b6)) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4388;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihZero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhNumVenta;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumSecuRel;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipDocumRel;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhCodVendedorAgRel;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhLetraRel;
    sqlstm.sqhstl[5] = (unsigned long )2;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&lhCodCentrRel;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&lhNumSecuRel;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihCodTipDocumRel;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&lhCodVendedorAgRel;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)szhLetraRel;
    sqlstm.sqhstl[10] = (unsigned long )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&lhCodCentrRel;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    *lNumVenta = lhNumVenta;
    return (TRUE);
}

/**
 * Funcion      : bfnFolioRelacionado
 * Descripcion  : Obtiene Folio y Prefijo Plaza Relaciado
 * Parametros   : iCodCliente       Codigo de Cliente
                  lNumFolio         Numero de Folio
                  szPrefPlaza       Prefijo Plaza
                  lNumFolioRel      Numero de Folio Relacionado
                  szPrefPlazaRel    Prefijo Plaza Relacionado
 * Retorna      : TRUE o FALSE seg”n corresponda
 */
BOOL bfnFolioRelacionado(int iCodCliente,long lNumFolio,char *szPrefPlaza,long *lNumFolioRel,char *szPrefPlazaRel)
{
    char *modulo="bfnFolioRelacionado";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int  ihCodCliente;
    long lhNumFolio;
    char szhPrefPlaza[11];
    long lhNumFolioRel;
    char szhPrefPlazaRel[11];
    long lCodCiclFact;
    int iNotaCred;
    int iValorCero;
    char szCadenaVacia[2];
    /* EXEC SQL END   DECLARE SECTION; */ 


    vDTrazasLog (modulo,"\n\t* Entra en Funcion %s", LOG06,modulo);

    lCodCiclFact  = 19010102;
    iNotaCred     = stDatosGener.iCodNotaCre;
    iValorCero    = 0;
    strcpy(szCadenaVacia," ");

    ihCodCliente = iCodCliente;
    lhNumFolio   = lNumFolio;
    strcpy(szhPrefPlaza,alltrim(szPrefPlaza));

    vDTrazasLog (modulo,"\n\t* Cliente      [%d] \n"
                          "\t* Folio        [%ld]\n"
                          "\t* Pref Plaza   [%s] \n"
                          "\t* Ciclo        [%ld]\n"
                          "\t* Nota Credito [%d] \n"
                          "\t* Pref Plaza   [%s] \n"
                          "\t* Valor Cero   [%d] \n"
                          "\t* Cadena Vacia [%s] \n" , LOG06,
                          ihCodCliente
                          , lNumFolio
                          , szhPrefPlaza
                          , lCodCiclFact
                          , iNotaCred
                          , szhPrefPlaza
                          , iValorCero
                          , szCadenaVacia);

    /* EXEC SQL
    SELECT NUM_FOLIO,
           PREF_PLAZA
      INTO :lhNumFolioRel,
           :szhPrefPlazaRel
      FROM ( SELECT B.NUM_FOLIO  NUM_FOLIO,
                    B.PREF_PLAZA PREF_PLAZA
               FROM FA_FACTDOCU_NOCICLO A,
                    FA_FACTDOCU_NOCICLO B
              WHERE A.COD_TIPDOCUM = :iNotaCred
                AND B.NUM_SECUENCI = A.NUM_SECUREL
                AND B.COD_TIPDOCUM = A.COD_TIPDOCUMREL
                AND B.COD_VENDEDOR_AGENTE = A.COD_VENDEDOR_AGENTEREL
                AND B.LETRA = A.LETRAREL
                AND B.COD_CENTREMI = A.COD_CENTRREL
                AND A.NUM_SECUENCI > :iValorCero
                AND A.COD_TIPDOCUM > :iValorCero
                AND A.COD_VENDEDOR_AGENTE > :iValorCero
                AND A.LETRA > : szCadenaVacia
                AND A.COD_CENTREMI > :iValorCero
                AND A.COD_CLIENTE = :ihCodCliente
                AND A.NUM_FOLIO = :lhNumFolio
                AND A.PREF_PLAZA = :szhPrefPlaza
            UNION
             SELECT B.NUM_FOLIO  NUM_FOLIO,
                    B.PREF_PLAZA PREF_PLAZA
               FROM FA_FACTDOCU_NOCICLO A,
                    FA_HISTDOCU         B
              WHERE A.COD_TIPDOCUM = :iNotaCred
                AND B.NUM_SECUENCI = A.NUM_SECUREL
                AND B.COD_TIPDOCUM = A.COD_TIPDOCUMREL
                AND B.COD_VENDEDOR_AGENTE = A.COD_VENDEDOR_AGENTEREL
                AND B.LETRA = A.LETRAREL
                AND B.COD_CENTREMI = A.COD_CENTRREL
                AND A.COD_CICLFACT = :lCodCiclFact
                AND A.NUM_SECUENCI > :iValorCero
                AND A.COD_TIPDOCUM > :iValorCero
                AND A.COD_VENDEDOR_AGENTE > :iValorCero
                AND A.LETRA > :szCadenaVacia
                AND A.COD_CENTREMI > :iValorCero
                AND A.COD_CLIENTE = :ihCodCliente
                AND A.NUM_FOLIO = :lhNumFolio
                AND A.PREF_PLAZA = :szhPrefPlaza
            UNION
             SELECT B.NUM_FOLIO  NUM_FOLIO,
                    B.PREF_PLAZA PREF_PLAZA
               FROM FA_HISTDOCU  A,
                    FA_HISTDOCU  B
              WHERE A.COD_TIPDOCUM = :iNotaCred
                AND B.NUM_SECUENCI = A.NUM_SECUREL
                AND B.COD_TIPDOCUM = A.COD_TIPDOCUMREL
                AND B.COD_VENDEDOR_AGENTE = A.COD_VENDEDOR_AGENTEREL
                AND B.LETRA = A.LETRAREL
                AND B.COD_CENTREMI = A.COD_CENTRREL
                AND A.COD_CICLFACT = :lCodCiclFact
                AND A.NUM_SECUENCI > :iValorCero
                AND A.COD_TIPDOCUM > :iValorCero
                AND A.COD_VENDEDOR_AGENTE > :iValorCero
                AND A.LETRA > :szCadenaVacia
                AND A.COD_CENTREMI > :iValorCero
                AND A.COD_CLIENTE = :ihCodCliente
                AND A.NUM_FOLIO = :lhNumFolio
                AND A.PREF_PLAZA = :szhPrefPlaza); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0, 
      "select NUM_FOLIO ,PREF_PLAZA into :b0,:b1  from (select B.NUM_FOLIO N\
UM_FOLIO ,B.PREF_PLAZA PREF_PLAZA  from FA_FACTDOCU_NOCICLO A ,FA_FACTDOCU_N\
OCICLO B where (((((((((((((A.COD_TIPDOCUM=:b2 and B.NUM_SECUENCI=A.NUM_SECU\
REL) and B.COD_TIPDOCUM=A.COD_TIPDOCUMREL) and B.COD_VENDEDOR_AGENTE=A.COD_V\
ENDEDOR_AGENTEREL) and B.LETRA=A.LETRAREL) and B.COD_CENTREMI=A.COD_CENTRREL\
) and A.NUM_SECUENCI>:b3) and A.COD_TIPDOCUM>:b3) and A.COD_VENDEDOR_AGENTE>\
:b3) and A.LETRA>:b6) and A.COD_CENTREMI>:b3) and A.COD_CLIENTE=:b8) and A.N\
UM_FOLIO=:b9) and A.PREF_PLAZA=:b10) union select B.NUM_FOLIO NUM_FOLIO ,B.P\
REF_PLAZA PREF_PLAZA  from FA_FACTDOCU_NOCICLO A ,FA_HISTDOCU B where ((((((\
((((((((A.COD_TIPDOCUM=:b2 and B.NUM_SECUENCI=A.NUM_SECUREL) and B.COD_TIPDO\
CUM=A.COD_TIPDOCUMREL) and B.COD_VENDEDOR_AGENTE=A.COD_VENDEDOR_AGENTEREL) a\
nd B.LETRA=A.LETRAREL) and B.COD_CENTREMI=A.COD_CENTRREL) and A.COD_CICLFACT\
=:b12) and A.NUM_SECUENCI>:b3) and A.COD_TIPDOCUM>:b3) and A.COD_VENDEDOR_AG\
ENTE>:b3) and A.LETRA>:b6) and A.COD_CENTRE");
    sqlstm.stmt = "MI>:b3) and A.COD_CLIENTE=:b8) and A.NUM_FOLIO=:b9) and A\
.PREF_PLAZA=:b10) union select B.NUM_FOLIO NUM_FOLIO ,B.PREF_PLAZA PREF_PLAZA \
 from FA_HISTDOCU A ,FA_HISTDOCU B where ((((((((((((((A.COD_TIPDOCUM=:b2 and \
B.NUM_SECUENCI=A.NUM_SECUREL) and B.COD_TIPDOCUM=A.COD_TIPDOCUMREL) and B.COD_\
VENDEDOR_AGENTE=A.COD_VENDEDOR_AGENTEREL) and B.LETRA=A.LETRAREL) and B.COD_CE\
NTREMI=A.COD_CENTRREL) and A.COD_CICLFACT=:b12) and A.NUM_SECUENCI>:b3) and A.\
COD_TIPDOCUM>:b3) and A.COD_VENDEDOR_AGENTE>:b3) and A.LETRA>:b6) and A.COD_CE\
NTREMI>:b3) and A.COD_CLIENTE=:b8) and A.NUM_FOLIO=:b9) and A.PREF_PLAZA=:b10)\
) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4451;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhNumFolioRel;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhPrefPlazaRel;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&iNotaCred;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szCadenaVacia;
    sqlstm.sqhstl[6] = (unsigned long )2;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[10] = (unsigned long )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&iNotaCred;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&lCodCiclFact;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)szCadenaVacia;
    sqlstm.sqhstl[16] = (unsigned long )2;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[20] = (unsigned long )11;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)&iNotaCred;
    sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)&lCodCiclFact;
    sqlstm.sqhstl[22] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         short *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         short *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)szCadenaVacia;
    sqlstm.sqhstl[26] = (unsigned long )2;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         short *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)&iValorCero;
    sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         short *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)&ihCodCliente;
    sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         short *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (unsigned char  *)&lhNumFolio;
    sqlstm.sqhstl[29] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         short *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned long )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (unsigned char  *)szhPrefPlaza;
    sqlstm.sqhstl[30] = (unsigned long )11;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         short *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned long )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
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
        vDTrazasLog (modulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    *lNumFolioRel = lhNumFolioRel;
    strcpy(szPrefPlazaRel,szhPrefPlazaRel);
    return (TRUE);
} /* Fin Funcion bfnFolioRelacionado */


BOOL fnGrabaAnoProceso (long lCod_Cliente, long lCod_CiclFact, int iCod_Anomalia, char *szObs_Anomalia)
{
    static int  iTitulo;
    static long lsCod_Cliente;
    char modulo[]   ="fnGrabaAnomaliaImpresion";

    char    szhDes_Proceso  [41];
    char    szhObs_Anomalia[101];

    strncpy(szhDes_Proceso,"ImpresionScl",40);
    strncpy(szhObs_Anomalia,szObs_Anomalia,100);

    vDTrazasLog (modulo,"\tDentro de la funcion(%s):  ",LOG03,modulo);
    vDTrazasLog (modulo,"\n\t\t* Valores de Anomalia:"
                 "\n\t\t* Proceso        [%ld]"
                 "\n\t\t* Cliente        [%ld]"
                 "\n\t\t* Ciclo de Fact. [%ld]"
                 "\n\t\t* Desc. Proceso  [%s]"
                 "\n\t\t* Cod. Anomalia  [%d]"
                 "\n\t\t* Desc. Anomalia [%s]"
                 , LOG04,lgNum_Proceso
                 , lCod_Cliente
                 , lCod_CiclFact
                 , szhDes_Proceso
                 , iCod_Anomalia
                 , szhObs_Anomalia);

    if ( iTitulo != 1 )
    {
        fprintf(fpAnomalias,"PROCESO ANOMALIA|CLIENTE|CICLO DE FACT|DESC PROCESO|COD ANOMALIA|DESC ANOMALIA|\n");
        fprintf(fpAnomalias,"----------------|-------|-------------|------------|------------|-------------|\n");
        iTitulo = 1;
    }

    if ( lsCod_Cliente != lCod_Cliente )
    {
        fprintf(fpAnomalias,"%ld|%ld|%ld|%s|%d|%s|\n"
                ,lgNum_Proceso
                ,lCod_Cliente
                ,lCod_CiclFact
                ,szhDes_Proceso
                ,iCod_Anomalia
                ,szhObs_Anomalia);
        lsCod_Cliente = lCod_Cliente;
    }
    return(TRUE);
}


BOOL bfnObtieneRegsImpresion(DETALLEOPER *pstMascaraOper,int iTipDoc)
{
	int iIndTipReg, iTotal, i;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char  szCodRegistro [1000][6]; /* max registros estimados */
    char  szCodTipDocum [1000][6]; /* max registros estimados */
    /* EXEC SQL END   DECLARE SECTION; */ 


    char *szModulo="bfnObtieneRegsImpresion";

    gihCodTipDocum = iTipDoc;
	vDTrazasLog  ("","\n\t** Entrada en [%s][%d] **" ,LOG06,szModulo, gihCodTipDocum);

    /* EXEC SQL OPEN cRegImpre ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0004;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4590;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&gihCodTipDocum;
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



    if (SQLCODE != SQLOK )
    {
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-OPEN Cursor_DetalleOper **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-OPEN Cursor_DetalleOper **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    /* EXEC SQL
    	FETCH cRegImpre
    	 INTO :szCodRegistro,
              :szCodTipDocum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1000;
    sqlstm.offset = (unsigned int  )4609;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)szCodRegistro;
    sqlstm.sqhstl[0] = (unsigned long )6;
    sqlstm.sqhsts[0] = (         int  )6;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szCodTipDocum;
    sqlstm.sqhstl[1] = (unsigned long )6;
    sqlstm.sqhsts[1] = (         int  )6;
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
        vDTrazasLog  (szModulo,"\n\t**  Error en SQL-FETCH Cursor_DetalleOper **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(szModulo,"\n\t**  Error en SQL-FETCH Cursor_DetalleOper **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    iTotal =  sqlca.sqlerrd[2];
    /* EXEC SQL CLOSE cRegImpre ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4632;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	pstMascaraOper->iMaxRegImp [0] = 0;
	pstMascaraOper->iMaxRegImp [2] = 0;
	pstMascaraOper->iMaxRegImp [3] = 0;

    vDTrazasLog  ("","\n\t** Total registros %d **" ,LOG06,iTotal);

    for ( i=0; i < iTotal ; i++ )
    {
    	vDTrazasLog  ("","\n\t** Carga registro [%s][%c] **" ,LOG06,szCodRegistro[i], szCodRegistro[i][0]);
        switch(szCodRegistro[i][0]) /* primer caracter del codigo de registro */
        {
			case 'A':
                iIndTipReg = 0;
            	break;
	        case 'B':
	            iIndTipReg = 1;
	            break;
	        case 'D':
	            iIndTipReg = 2;
	            break;
	    }

        strcpy (pstMascaraOper->szCodRegistro [iIndTipReg][pstMascaraOper->iMaxRegImp[iIndTipReg]], szCodRegistro[i]);
    	vDTrazasLog  ("","\t** iMaxRegImp [%d] **" ,LOG06,pstMascaraOper->iMaxRegImp[iIndTipReg]);
    	vDTrazasLog  ("","\t** Registro cargado [%s] **" ,LOG06
    	                ,pstMascaraOper->szCodRegistro [iIndTipReg][pstMascaraOper->iMaxRegImp[iIndTipReg]]);

        strcpy (pstMascaraOper->szCodTipDocum [iIndTipReg][pstMascaraOper->iMaxRegImp[iIndTipReg]], szCodTipDocum[i]);
        pstMascaraOper->iMaxRegImp    [iIndTipReg]++;
    }

    return (TRUE);
}


/**************************************************************************************/
/*  Funcion que obtiene Mascara de impresion de detalle de llamados por Operadora     */
/**************************************************************************************/
BOOL bCargaMascaraOperadora(DETALLEOPER *pst_MascaraOper,int iTipDoc)
{
int  i, x;
int  iExisteMascara = 0;

    strcpy (szModulo, "bCargaMascaraOperadora");
    vDTrazasLog  ("","\n\t** Entrando a %s **" ,LOG04,szModulo);

    sprintf(pst_MascaraOper->szWhere_Local,"%*.*s\0",sthFadParametros.val_numerico[COD_MASK_WHERE_LOCALES],
    sthFadParametros.val_numerico[COD_MASK_WHERE_LOCALES],sthFadParametros.val_caracter[COD_MASK_WHERE_LOCALES]);

    sprintf(pst_MascaraOper->szWhere_Interzona,"%*.*s\0",sthFadParametros.val_numerico[COD_MASK_WHERE_INTERZONA],
    sthFadParametros.val_numerico[COD_MASK_WHERE_INTERZONA],sthFadParametros.val_caracter[COD_MASK_WHERE_INTERZONA]);

    sprintf(pst_MascaraOper->szWhere_LDI,"%*.*s\0",sthFadParametros.val_numerico[COD_MASK_WHERE_LDI],
    sthFadParametros.val_numerico[COD_MASK_WHERE_LDI],sthFadParametros.val_caracter[COD_MASK_WHERE_LDI]);

    sprintf(pst_MascaraOper->szWhere_Especiales,"%*.*s\0",sthFadParametros.val_numerico[COD_MASK_WHERE_ESPECIALES],
    sthFadParametros.val_numerico[COD_MASK_WHERE_ESPECIALES],sthFadParametros.val_caracter[COD_MASK_WHERE_ESPECIALES]);

    sprintf(pst_MascaraOper->szWhere_Especiales_data,"%*.*s\0",sthFadParametros.val_numerico[COD_MASK_WHERE_ESPECIALESDATA],
    sthFadParametros.val_numerico[COD_MASK_WHERE_ESPECIALESDATA],sthFadParametros.val_caracter[COD_MASK_WHERE_ESPECIALESDATA]);

    sprintf(pst_MascaraOper->szIndFacturado,"%1.1s\0", sthFadParametros.val_caracter[COD_MASK_INDFACTURADO]);
    sprintf(pst_MascaraOper->szServicio,"%-3.3s\0", sthFadParametros.val_caracter[COD_MASK_SERVICIO]);

    pst_MascaraOper->iCodFormulario  = sthFadParametros.val_numerico[COD_MASK_FORMULARIO];
    pst_MascaraOper->iCtesXArchivo   = sthFadParametros.val_numerico[COD_MASK_CLIENTESXFILE];
    pst_MascaraOper->iIndLocal       = sthFadParametros.val_numerico[COD_MASK_LOCAL];
    pst_MascaraOper->iIndEspeciales  = sthFadParametros.val_numerico[COD_MASK_ESPECIALES];
    pst_MascaraOper->iIndInterzona   = sthFadParametros.val_numerico[COD_MASK_INTERZONA];
    pst_MascaraOper->iIndRoaming     = sthFadParametros.val_numerico[COD_MASK_ROAMING];
    pst_MascaraOper->iIndCarrier     = sthFadParametros.val_numerico[COD_MASK_CARRIER];
    pst_MascaraOper->iIndLDI         = sthFadParametros.val_numerico[COD_MASK_LDI];
    pst_MascaraOper->iInd_Agrupacion = sthFadParametros.val_numerico[COD_MASK_INDAGRUPACION];

    vDTrazasLog  (szModulo,"\n\t\t MascaraOperadora :\n"
                           "\n\t\t Locales          [%s]"
                           "\n\t\t Interzona        [%s]"
                           "\n\t\t Ldi              [%s]"
                           "\n\t\t Especiales       [%s]"
                           "\n\t\t Data             [%s]"
                           "\n\t\t Formulario       [%d]"
                           "\n\t\t ClientesXArchivo [%d]"
                           "\n\t\t IndFacturado     [%s]"
                           "\n\t\t iIndLocal        [%d]"
                           "\n\t\t iIndInterzona    [%d]"
                           "\n\t\t iIndRoaming      [%d]"
                           "\n\t\t iIndCarrier      [%d]"
                           "\n\t\t iIndEspeciales   [%d]"
                           "\n\t\t iIndLDI          [%d]"
                           "\n\t\t iTipdoc          [%d]"
                           ,LOG04
                           ,pst_MascaraOper->szWhere_Local
                           ,pst_MascaraOper->szWhere_Interzona
                           ,pst_MascaraOper->szWhere_LDI
                           ,pst_MascaraOper->szWhere_Especiales
                           ,pst_MascaraOper->szWhere_Especiales_data
                           ,pst_MascaraOper->iCodFormulario
                           ,pst_MascaraOper->iCtesXArchivo
                           ,pst_MascaraOper->szIndFacturado
                           ,pst_MascaraOper->iIndLocal
                           ,pst_MascaraOper->iIndInterzona
                           ,pst_MascaraOper->iIndRoaming
                           ,pst_MascaraOper->iIndCarrier
                           ,pst_MascaraOper->iIndEspeciales
                           ,pst_MascaraOper->iIndLDI
                           ,iTipDoc);

	/* se agrega carga y clasificacion de registros de impresion */
	if (!bfnObtieneRegsImpresion(pst_MascaraOper,iTipDoc))
	{
        vDTrazasLog  (szModulo,"\t\t MascaraOperadora: Error al cargar tipos de registros de impresion"
        			 ,LOG01);
        return (FALSE);
	}

    for ( i=0; i < MAX_TIPOS_REGISTROS ; i++ ) /* A, B y D */
    {
        if ( stStatus.LogNivel >= LOG06 )
        {
		    for ( x=0; x < pst_MascaraOper->iMaxRegImp[i] ; x++ )
		    {
		        vDTrazasLog  (szModulo,"\t\t MascaraOperadora: [%s] [%s]",LOG06
		                              ,pst_MascaraOper->szCodRegistro[i][x]
		                              ,pst_MascaraOper->szCodTipDocum[i][x]);
		    }
		}
        iExisteMascara+=pst_MascaraOper->iMaxRegImp[i];
	}
    if(!iExisteMascara)
    {
        vDTrazasLog  (szModulo,"\t\t MascaraOperadora: No Configurada",LOG01);
        return (FALSE);
    }
    return TRUE;

}/* bCargaMascaraOperadora */

/***************************************************************************************/
int GetCiclFact(ST_CICLOFACT * pstCicFact,long lCodCiclFact)
{
    char szFormato_Fecha_Corto[7];

    strcpy (szModulo, "GetCiclFact");
    vDTrazasLog(szModulo,"\t** Entrando en %s"
                         "\t*** Inicio de Ciclo de Facturacion (%ld)***"
                         ,LOG04,szModulo,lCodCiclFact);
    strcpy(szhFormato_Fecha,"YYYYMMDD");
    strcpy(szFormato_Fecha_Corto,"YYYYMM");

       /* EXEC SQL
       SELECT COD_CICLO,
              TO_CHAR(FEC_DESDELLAM,:szhFormato_Fecha)            ,
              TO_CHAR(FEC_HASTALLAM,:szhFormato_Fecha)            ,
              TO_CHAR(FEC_EMISION,:szhFormato_Fecha)                ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-1),:szFormato_Fecha_Corto)   ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-2),:szFormato_Fecha_Corto)   ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-3),:szFormato_Fecha_Corto)   ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-4),:szFormato_Fecha_Corto)   ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-5),:szFormato_Fecha_Corto)   ,
              TO_CHAR(ADD_MONTHS(FEC_EMISION,-6),:szFormato_Fecha_Corto)   ,
              IND_TASADOR,
              TO_CHAR(FEC_DESDECFIJOS,:szhFormato_Fecha)            ,
              TO_CHAR(FEC_HASTACFIJOS,:szhFormato_Fecha)
         INTO :pstCicFact
         FROM FA_CICLFACT
        WHERE COD_CICLFACT = :lCodCiclFact; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 47;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "select COD_CICLO ,TO_CHAR(FEC_DESDELLAM,:b0) ,TO_CHAR(\
FEC_HASTALLAM,:b0) ,TO_CHAR(FEC_EMISION,:b0) ,TO_CHAR(ADD_MONTHS(FEC_EMISION,(\
-1)),:b3) ,TO_CHAR(ADD_MONTHS(FEC_EMISION,(-2)),:b3) ,TO_CHAR(ADD_MONTHS(FEC_E\
MISION,(-3)),:b3) ,TO_CHAR(ADD_MONTHS(FEC_EMISION,(-4)),:b3) ,TO_CHAR(ADD_MONT\
HS(FEC_EMISION,(-5)),:b3) ,TO_CHAR(ADD_MONTHS(FEC_EMISION,(-6)),:b3) ,IND_TASA\
DOR ,TO_CHAR(FEC_DESDECFIJOS,:b0) ,TO_CHAR(FEC_HASTACFIJOS,:b0) into :s1 ,:s2 \
,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13   from FA_CICLFACT \
where COD_CICLFACT=:b12";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )4647;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
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
       sqlstm.sqhstv[2] = (unsigned char  *)szhFormato_Fecha;
       sqlstm.sqhstl[2] = (unsigned long )9;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[3] = (unsigned long )7;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[4] = (unsigned long )7;
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[5] = (unsigned long )7;
       sqlstm.sqhsts[5] = (         int  )0;
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[6] = (unsigned long )7;
       sqlstm.sqhsts[6] = (         int  )0;
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[7] = (unsigned long )7;
       sqlstm.sqhsts[7] = (         int  )0;
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)szFormato_Fecha_Corto;
       sqlstm.sqhstl[8] = (unsigned long )7;
       sqlstm.sqhsts[8] = (         int  )0;
       sqlstm.sqindv[8] = (         short *)0;
       sqlstm.sqinds[8] = (         int  )0;
       sqlstm.sqharm[8] = (unsigned long )0;
       sqlstm.sqadto[8] = (unsigned short )0;
       sqlstm.sqtdso[8] = (unsigned short )0;
       sqlstm.sqhstv[9] = (unsigned char  *)szhFormato_Fecha;
       sqlstm.sqhstl[9] = (unsigned long )9;
       sqlstm.sqhsts[9] = (         int  )0;
       sqlstm.sqindv[9] = (         short *)0;
       sqlstm.sqinds[9] = (         int  )0;
       sqlstm.sqharm[9] = (unsigned long )0;
       sqlstm.sqadto[9] = (unsigned short )0;
       sqlstm.sqtdso[9] = (unsigned short )0;
       sqlstm.sqhstv[10] = (unsigned char  *)szhFormato_Fecha;
       sqlstm.sqhstl[10] = (unsigned long )9;
       sqlstm.sqhsts[10] = (         int  )0;
       sqlstm.sqindv[10] = (         short *)0;
       sqlstm.sqinds[10] = (         int  )0;
       sqlstm.sqharm[10] = (unsigned long )0;
       sqlstm.sqadto[10] = (unsigned short )0;
       sqlstm.sqtdso[10] = (unsigned short )0;
       sqlstm.sqhstv[11] = (unsigned char  *)&pstCicFact->cod_ciclo;
       sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[11] = (         int  )0;
       sqlstm.sqindv[11] = (         short *)0;
       sqlstm.sqinds[11] = (         int  )0;
       sqlstm.sqharm[11] = (unsigned long )0;
       sqlstm.sqadto[11] = (unsigned short )0;
       sqlstm.sqtdso[11] = (unsigned short )0;
       sqlstm.sqhstv[12] = (unsigned char  *)pstCicFact->fec_desde;
       sqlstm.sqhstl[12] = (unsigned long )9;
       sqlstm.sqhsts[12] = (         int  )0;
       sqlstm.sqindv[12] = (         short *)0;
       sqlstm.sqinds[12] = (         int  )0;
       sqlstm.sqharm[12] = (unsigned long )0;
       sqlstm.sqadto[12] = (unsigned short )0;
       sqlstm.sqtdso[12] = (unsigned short )0;
       sqlstm.sqhstv[13] = (unsigned char  *)pstCicFact->fec_hasta;
       sqlstm.sqhstl[13] = (unsigned long )9;
       sqlstm.sqhsts[13] = (         int  )0;
       sqlstm.sqindv[13] = (         short *)0;
       sqlstm.sqinds[13] = (         int  )0;
       sqlstm.sqharm[13] = (unsigned long )0;
       sqlstm.sqadto[13] = (unsigned short )0;
       sqlstm.sqtdso[13] = (unsigned short )0;
       sqlstm.sqhstv[14] = (unsigned char  *)pstCicFact->szFec_Emision;
       sqlstm.sqhstl[14] = (unsigned long )9;
       sqlstm.sqhsts[14] = (         int  )0;
       sqlstm.sqindv[14] = (         short *)0;
       sqlstm.sqinds[14] = (         int  )0;
       sqlstm.sqharm[14] = (unsigned long )0;
       sqlstm.sqadto[14] = (unsigned short )0;
       sqlstm.sqtdso[14] = (unsigned short )0;
       sqlstm.sqhstv[15] = (unsigned char  *)pstCicFact->szMesCiclo_0;
       sqlstm.sqhstl[15] = (unsigned long )7;
       sqlstm.sqhsts[15] = (         int  )0;
       sqlstm.sqindv[15] = (         short *)0;
       sqlstm.sqinds[15] = (         int  )0;
       sqlstm.sqharm[15] = (unsigned long )0;
       sqlstm.sqadto[15] = (unsigned short )0;
       sqlstm.sqtdso[15] = (unsigned short )0;
       sqlstm.sqhstv[16] = (unsigned char  *)pstCicFact->szMesCiclo_1;
       sqlstm.sqhstl[16] = (unsigned long )7;
       sqlstm.sqhsts[16] = (         int  )0;
       sqlstm.sqindv[16] = (         short *)0;
       sqlstm.sqinds[16] = (         int  )0;
       sqlstm.sqharm[16] = (unsigned long )0;
       sqlstm.sqadto[16] = (unsigned short )0;
       sqlstm.sqtdso[16] = (unsigned short )0;
       sqlstm.sqhstv[17] = (unsigned char  *)pstCicFact->szMesCiclo_2;
       sqlstm.sqhstl[17] = (unsigned long )7;
       sqlstm.sqhsts[17] = (         int  )0;
       sqlstm.sqindv[17] = (         short *)0;
       sqlstm.sqinds[17] = (         int  )0;
       sqlstm.sqharm[17] = (unsigned long )0;
       sqlstm.sqadto[17] = (unsigned short )0;
       sqlstm.sqtdso[17] = (unsigned short )0;
       sqlstm.sqhstv[18] = (unsigned char  *)pstCicFact->szMesCiclo_3;
       sqlstm.sqhstl[18] = (unsigned long )7;
       sqlstm.sqhsts[18] = (         int  )0;
       sqlstm.sqindv[18] = (         short *)0;
       sqlstm.sqinds[18] = (         int  )0;
       sqlstm.sqharm[18] = (unsigned long )0;
       sqlstm.sqadto[18] = (unsigned short )0;
       sqlstm.sqtdso[18] = (unsigned short )0;
       sqlstm.sqhstv[19] = (unsigned char  *)pstCicFact->szMesCiclo_4;
       sqlstm.sqhstl[19] = (unsigned long )7;
       sqlstm.sqhsts[19] = (         int  )0;
       sqlstm.sqindv[19] = (         short *)0;
       sqlstm.sqinds[19] = (         int  )0;
       sqlstm.sqharm[19] = (unsigned long )0;
       sqlstm.sqadto[19] = (unsigned short )0;
       sqlstm.sqtdso[19] = (unsigned short )0;
       sqlstm.sqhstv[20] = (unsigned char  *)pstCicFact->szMesCiclo_5;
       sqlstm.sqhstl[20] = (unsigned long )7;
       sqlstm.sqhsts[20] = (         int  )0;
       sqlstm.sqindv[20] = (         short *)0;
       sqlstm.sqinds[20] = (         int  )0;
       sqlstm.sqharm[20] = (unsigned long )0;
       sqlstm.sqadto[20] = (unsigned short )0;
       sqlstm.sqtdso[20] = (unsigned short )0;
       sqlstm.sqhstv[21] = (unsigned char  *)&pstCicFact->iIndTasador;
       sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[21] = (         int  )0;
       sqlstm.sqindv[21] = (         short *)0;
       sqlstm.sqinds[21] = (         int  )0;
       sqlstm.sqharm[21] = (unsigned long )0;
       sqlstm.sqadto[21] = (unsigned short )0;
       sqlstm.sqtdso[21] = (unsigned short )0;
       sqlstm.sqhstv[22] = (unsigned char  *)pstCicFact->szFec_Desde;
       sqlstm.sqhstl[22] = (unsigned long )9;
       sqlstm.sqhsts[22] = (         int  )0;
       sqlstm.sqindv[22] = (         short *)0;
       sqlstm.sqinds[22] = (         int  )0;
       sqlstm.sqharm[22] = (unsigned long )0;
       sqlstm.sqadto[22] = (unsigned short )0;
       sqlstm.sqtdso[22] = (unsigned short )0;
       sqlstm.sqhstv[23] = (unsigned char  *)pstCicFact->szFec_Hasta;
       sqlstm.sqhstl[23] = (unsigned long )9;
       sqlstm.sqhsts[23] = (         int  )0;
       sqlstm.sqindv[23] = (         short *)0;
       sqlstm.sqinds[23] = (         int  )0;
       sqlstm.sqharm[23] = (unsigned long )0;
       sqlstm.sqadto[23] = (unsigned short )0;
       sqlstm.sqtdso[23] = (unsigned short )0;
       sqlstm.sqhstv[24] = (unsigned char  *)&lCodCiclFact;
       sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
       sqlstm.sqhsts[24] = (         int  )0;
       sqlstm.sqindv[24] = (         short *)0;
       sqlstm.sqinds[24] = (         int  )0;
       sqlstm.sqharm[24] = (unsigned long )0;
       sqlstm.sqadto[24] = (unsigned short )0;
       sqlstm.sqtdso[24] = (unsigned short )0;
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



    /*if((SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND))    */
    if(SQLCODE != SQLOK)
    {
      vDTrazasError(szModulo,"\t\tError en Ciclo Facturacion : %s", LOG01, SQLERRM);
      return(FALSE);
    }
    strcpy(szFec_Desde,pstCicFact->szFec_Desde);
    strcpy(szFec_Hasta,pstCicFact->szFec_Hasta);

    return(TRUE);
}

int ManejoArchImp(LINEACOMANDO         *ParEntrada,
                  ST_INFGENERAL        *sthFa_InfGeneral,
                  DETALLEOPER          *stMascaraOper,
                  FILE                 **Fd_ArchImp ,
                  ST_ACUMMTO           *AcumMto,
                  char                 *szNombreArchivo)
{
char szCodIdioma[6];

    strcpy (szModulo, "ManejoArchImp");
    vDTrazasLog(szModulo,"\n\t** Entrada en %s"
                         "\n\t->iSecuencial [%d]"
                         "\n\t->szPathDir   [%s]"
                         ,LOG04, szModulo, sthFa_InfGeneral->iSecuencial, sthFa_InfGeneral->szPathDir);

   if (sthFa_InfGeneral->iSecuencial == 0 )
   {
        sthFa_InfGeneral->iSecuencial = 1;
        strcpy(szCodIdioma,ParEntrada->szCodIdioma); FillCodIdioma(szCodIdioma);
        if(!ParEntrada->iTipoCiclo)
        {
            sprintf(szNombreArchivo,"%s/ImprScl_%02d_%d_%s_%ld_%s.dat"
                                   ,sthFa_InfGeneral->szPathDir
                                   ,sthFa_InfGeneral->iSecuencial
                                   ,ParEntrada->iCodTipDocum
                                   ,ParEntrada->szCodDespacho
                                   ,ParEntrada->lCodCiclFact
                                   ,(strcmp(szgHostId,"-1")==0)?"_":szgHostId);
        }
        else
        {
            sprintf(szNombreArchivo,"%s/00_%015ld.dat"
                                   ,sthFa_InfGeneral->szPathDir
                                   ,ParEntrada->lProceso);
        }
        printf("\tManejoArchImp-> entro por 1era vez [%s]\n",szNombreArchivo);
        vDTrazasLog(szModulo,"NMFILE: OPEN1|%d|%d|%s|",LOG06
                            , sthFa_InfGeneral->iContClientesProcesados
                            , sthFa_InfGeneral->iSecuencial,szNombreArchivo);
        if((*Fd_ArchImp = fopen(szNombreArchivo, "w")) == (FILE *)NULL)
        {
            vDTrazasLog(szModulo,"\n\t\tError al abrir archivo-> [%s]\n" ,LOG01,szNombreArchivo);
            vDTrazasError(szModulo,"\n\t\tError al abrir archivo-> [%s]\n" ,LOG01,szNombreArchivo);
            return FALSE;
        }

        return TRUE;
    }

    vDTrazasLog(szModulo,"\t\tsthFa_InfGeneral->iContClientesProcesados [%d]"
                         "\t\tstMascaraOper->iCtesXArchivo [%d]"
                         ,LOG05, sthFa_InfGeneral->iContClientesProcesados
                         ,stMascaraOper->iCtesXArchivo);

    if ( sthFa_InfGeneral->iContClientesProcesados >= stMascaraOper->iCtesXArchivo)
    {
        /* Cerrar archivo y crear otro */
        vDTrazasLog(szModulo,"NMFILE: CLOSE|%d|%d|%s|"
                            ,LOG06, sthFa_InfGeneral->iContClientesProcesados
                            ,sthFa_InfGeneral->iSecuencial,szNombreArchivo);
        fclose(*Fd_ArchImp);
        if(!ParEntrada->iTipoCiclo)
        {
            if (!bfnInsertar_FadCTLImpres(AcumMto, ParEntrada, sthFa_InfGeneral, szNombreArchivo))
            {
                vDTrazasLog(szModulo,"Error en ejecucion de bfnInsertar_FadCTLImpres ",LOG01);
                return (FALSE);
            }
        }
        sthFa_InfGeneral->iContClientesProcesados = 0;
        sthFa_InfGeneral->iSecuencial++;

        strcpy(szCodIdioma,ParEntrada->szCodIdioma); FillCodIdioma(szCodIdioma);
        if(!ParEntrada->iTipoCiclo)
        {
            sprintf(szNombreArchivo,"%s/ImprScl_%02d_%d_%s_%ld_%s.dat"
                                   ,sthFa_InfGeneral->szPathDir
                                   ,sthFa_InfGeneral->iSecuencial
                                   ,ParEntrada->iCodTipDocum
                                   ,ParEntrada->szCodDespacho
                                   ,ParEntrada->lCodCiclFact
                                   ,(strcmp(szgHostId,"-1")==0)?"_":szgHostId);
        }
        else
        {
            sprintf(szNombreArchivo,"%s/00_%015ld.dat",sthFa_InfGeneral->szPathDir,ParEntrada->lProceso);
        }
        vDTrazasLog(szModulo,"NMFILE: OPEN2|%d|%d|%s|"
                            ,LOG06, sthFa_InfGeneral->iContClientesProcesados,sthFa_InfGeneral->iSecuencial,szNombreArchivo);
        if( (*Fd_ArchImp = fopen(szNombreArchivo, "w")) == (FILE *)NULL)
        {
            vDTrazasLog(szModulo,  "\n\t\tError al abrir archivo-> [%s]\n",LOG01,szNombreArchivo);
            vDTrazasError(szModulo,"\n\t\tError al abrir archivo-> [%s]\n",LOG01,szNombreArchivo);

            return FALSE;
        }
    }

    return TRUE;
}


BOOL bfnValidaDespHostID (long lCodCiclFact, char *szCodDespacho, char *szHostId)
{
    char *szModulo="bfnValidaDespHostID";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int ihContador  = 0;
    long lhCodCiclFact = 0;
    char szhCodDespacho [6];
    char szhHostId [21];
    /* EXEC SQL END   DECLARE SECTION; */ 


    vDTrazasLog (szModulo,"\n\t\t* Dentro de la funcion %s", LOG05, szModulo);

    /* Asignacion de los parametros a las variables Host */
	strcpy (szhCodDespacho, szCodDespacho);
	strcpy (szhHostId, szHostId);
    lhCodCiclFact = lCodCiclFact;

    /* EXEC SQL
    SELECT COUNT(1)
      INTO :ihContador
      FROM FA_RANGOSDESPHOST_TO
     WHERE COD_CICLOFACT = :lhCodCiclFact
       AND COD_DESPACHO = :szhCodDespacho
       AND HOST_ID      = :szhHostId; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(1) into :b0  from FA_RANGOSDESPHOST_TO where\
 ((COD_CICLOFACT=:b1 and COD_DESPACHO=:b2) and HOST_ID=:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4762;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihContador;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclFact;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhCodDespacho;
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhHostId;
    sqlstm.sqhstl[3] = (unsigned long )21;
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



    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\t\t* %s: Valor devuelto por SELECT, ihContador :[%d]", LOG05, szModulo, ihContador);

    /* Si existe Codigo de despacho para el Host_ID, se retorna TRUE */
    if ( ihContador > 0 )
        return (TRUE);

    return (FALSE);
}


/**************************************************************************/
/* Funcion que genera mascara de impresion de detalle de llamado          */
/**************************************************************************/
BOOL bObtieneMascara(ST_ABONADO     *pst_Abonados
                     ,CONCEPTOS_TAR  *stConceptosTar
                     ,DETALLEOPER    *pst_MascaraOper)
{
long i,j,k;

    strcpy (szModulo, "bObtieneMascara");

    vDTrazasLog(szModulo,"\n\t Entrada en %s "
                         "\n\t\tCantidad Abonados     : [%d]"
                         "\n\t\tCantidad de Conceptos : [%d]"
                        ,LOG05, szModulo
                        ,pst_Abonados->CantidadAbonados
                        ,stFaDetCons.iNumReg);

    if (pst_Abonados->CantidadAbonados > 0 && stConceptosTar->iNumConceptos > 0 && stFaDetCons.iNumReg > 0){/*AFGS - 38935*/
        for (i = 0; i < stFaDetCons.iNumReg; i++)
        {
            vDTrazasLog(szModulo,"\t\t Cod Concepto[%d] : [%d]", LOG05,i,stFaDetCons.stDetConsumo[i].iCodConcepto);

            for (j = 0 ; j < stConceptosTar->iNumConceptos ; j++)
            {
                if (stFaDetCons.stDetConsumo[i].iCodConcepto == stConceptosTar->iCodConcepto[j])
                {
                    /* Busca abonado y activa flag de impresion */
                    for (k = 0; k < pst_Abonados->CantidadAbonados; k++)
                        if (pst_Abonados->lNumAbonado[k] == stFaDetCons.stDetConsumo[i].lNumAbonado)
                            break; /* Termina el for */

                    if (pst_Abonados->iIndDetFact[k] == 1)
                    {
                        switch (stConceptosTar->iIndTabla[j])
                        {
                            case    iIND_TABLA_INTERZONA_ESPECIAL :
                                    if(pst_MascaraOper->iIndInterzona)
                                    {
                                        pst_Abonados->iIndInterzona[k]  = iIND_IMPRIME_TRAFICO_SI;
                                    }
                                    if(pst_MascaraOper->iIndLDI)
                                    {
                                        pst_Abonados->iIndLdi[k]  = iIND_IMPRIME_TRAFICO_SI;
                                    }
                                    if ( pst_MascaraOper->iIndEspeciales)
                                    {
                                        pst_Abonados->iIndEspeciales[k] = iIND_IMPRIME_TRAFICO_SI;
                                    }

                                break;
                            case    iIND_TABLA_CARRIER :
                                if ( pst_MascaraOper->iIndCarrier)
                                            pst_Abonados->iIndCarrier[k]    = iIND_IMPRIME_TRAFICO_SI;
                                        break;
                            default :
                                break;
                        }
                    }
                }
            }/* For conceptos de tarificacion */
        }/* For conceptos facturados */
	}
    return TRUE;
}/* End bObtieneMascara */

/**************************************************************************/
/* Funcion que consulta el ultimo ciclo facturado del cliente             */
/**************************************************************************/
BOOL bfnValidaCiclFactClie (long lCodCliente, long *lCodCiclFact)
{
    char *szModulo="bfnValidaCiclFactClie";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCiclFact = 0L;
    long lhCodCliente  = 0L;
    /* EXEC SQL END   DECLARE SECTION; */ 


    vDTrazasLog (szModulo,"\n\t\t* Dentro de la funcion %s", LOG05, szModulo);

    /* Asignacion de los parametros a las variables Host */
	lhCodCliente = lCodCliente;

    /* EXEC SQL
    	SELECT COD_CICLFACT  
    	  INTO :lhCodCiclFact
    	  FROM FA_CICLFACT 
    	 WHERE FEC_EMISION IN ( SELECT MAX(FEC_EMISION) 
 								  FROM FA_CICLFACT A
 								 WHERE EXISTS ( SELECT 1 
                        						  FROM GA_INFACCEL B 
                        					     WHERE B.COD_CLIENTE = :lhCodCliente
                                                   AND A.COD_CICLFACT = B.COD_CICLFACT )
                                   AND EXISTS  ( SELECT 1 
							                       FROM FA_CICLOCLI B 
							                      WHERE B.COD_CLIENTE = :lhCodCliente
							                        AND A.COD_CICLO = B.COD_CICLO )
							       AND IND_FACTURACION > 0 ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_CICLFACT into :b0  from FA_CICLFACT where FEC_\
EMISION in (select max(FEC_EMISION)  from FA_CICLFACT A where ((exists (select\
 1  from GA_INFACCEL B where (B.COD_CLIENTE=:b1 and A.COD_CICLFACT=B.COD_CICLF\
ACT)) and exists (select 1  from FA_CICLOCLI B where (B.COD_CLIENTE=:b1 and A.\
COD_CICLO=B.COD_CICLO))) and IND_FACTURACION>0))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4793;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
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



	if (SQLCODE == SQLNOTFOUND)
	{
        vDTrazasLog (szModulo,"\n\t\t* No se encontro ciclo facturado para el cliente : [%ld]", LOG03,lhCodCliente);
        return (FALSE);
	}

    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    vDTrazasLog (szModulo,"\n\t\t* Ciclo encontrado para el cliente :[%ld]", LOG05, lhCodCiclFact);

	*lCodCiclFact = lhCodCiclFact;
	
    return (TRUE);
}

BOOL bfnValidaVentaConcVarios(long lNumVenta)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    long lhNumVenta;
	    char szhNomUsuario [31];
	    int  ihIndicador;
    /* EXEC SQL END   DECLARE SECTION; */ 

    char *szModulo="bfnValidaVentaConcVarios";

    vDTrazasLog (szModulo,"\n\t\t* Entrada en %s [%ld]", LOG05, szModulo,lNumVenta);
    
    lhNumVenta = lNumVenta;
	strcpy (szhNomUsuario, "FACOVA"); /* validar si es configurable */
    /* EXEC SQL
    	SELECT 1 
    	  INTO :ihIndicador
    	  FROM GA_VENTAS 
    	 WHERE NUM_VENTA = :lhNumVenta
           AND NOM_USUAR_RECPROV = :szhNomUsuario; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 47;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select 1 into :b0  from GA_VENTAS where (NUM_VENTA=:b1 an\
d NOM_USUAR_RECPROV=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4820;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihIndicador;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhNumVenta;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhNomUsuario;
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



	if (SQLCODE == SQLNOTFOUND)
	{
        vDTrazasLog (szModulo,"\n\t\t* No se encontro venta asociada a conceptos varios [%ld]", LOG03,lhNumVenta);
        return (FALSE);
	}
    if ( SQLCODE != SQLOK )
    {
        vDTrazasLog (szModulo,"\n\t\t* En sentenia SELECT, Codigo: [%d]\n[%s]", LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }

    return (TRUE);
}


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
