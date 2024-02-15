#include "__cf_DCM_3.h"
#ifndef RTW_HEADER_DCM_3_h_
#define RTW_HEADER_DCM_3_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef DCM_3_COMMON_INCLUDES_
#define DCM_3_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "DCM_3_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME DCM_3
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (21) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T axmmhiccox ; real_T dwpzvnyws1 ; real_T fua0oio1qa ;
real_T noqxuuytub ; real_T nhfuapoovh ; real_T ct0taxgvv3 [ 2 ] ; real_T
dalxhvg1zf ; real_T n5upg3xxwm ; real_T j1eypzh03i ; real_T h451ajn5pc ;
real_T dav20jyvk3 ; real_T g4p2xlgqdu ; real_T e3114yddje ; real_T m0juatoz4z
; real_T pjsgwedo55 ; real_T ogaap0wcng ; real_T noffyg4nar ; real_T
iw2api0er3 ; real_T dkw4zvirgz ; real_T ooxs3jjvtd ; real_T nyl0zlk1x2 ; } B
; typedef struct { real_T gj1pm3tws0 [ 2 ] ; real_T pl2nkwidb2 [ 2 ] ; void *
e0bjgobeax [ 22 ] ; void * i3xyhwkhup [ 22 ] ; struct { void * LoggedData ; }
ktifmyvz3q ; struct { void * LoggedData ; } ktn12s1iuj ; struct { void *
LoggedData ; } kpdwoqm44m ; struct { void * LoggedData ; } pdi0yga5qo ;
struct { void * LoggedData ; } kx0nbvf0s5 ; int_T opv2pzumsy [ 23 ] ; int_T
jiw4bh1isx [ 23 ] ; int_T perqcxtxaf [ 2 ] ; int_T m0sqzkayaq ; int_T
ifodo1eta0 ; } DW ; typedef struct { real_T mwapy0rjtv ; real_T gstm2g4gvs ;
real_T hh3oplhqb2 ; real_T e4xjjpdmux ; } X ; typedef struct { real_T
mwapy0rjtv ; real_T gstm2g4gvs ; real_T hh3oplhqb2 ; real_T e4xjjpdmux ; }
XDot ; typedef struct { boolean_T mwapy0rjtv ; boolean_T gstm2g4gvs ;
boolean_T hh3oplhqb2 ; boolean_T e4xjjpdmux ; } XDis ; typedef struct {
real_T mwapy0rjtv ; real_T gstm2g4gvs ; real_T hh3oplhqb2 ; real_T e4xjjpdmux
; } CStateAbsTol ; typedef struct { real_T dvbmyegzvg [ 2 ] ; real_T
atnazhuttj ; real_T jm2aun3v5i ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
DCVoltageSource_Amplitude ; real_T DCVoltageSource1_Amplitude ; real_T
DCMachine_Ifinit ; real_T CoulombTfViscousBmwFrictionTorques_gain ; real_T
CoulombTfViscousBmwFrictionTorques_offset ; real_T
RepeatingSequence_rep_seq_y [ 2 ] ; real_T StateSpace_P1_Size [ 2 ] ; real_T
StateSpace_P1 [ 10 ] ; real_T StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2
[ 4 ] ; real_T StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 115 ] ; real_T
Integrator_IC ; real_T StateSpace_P1_Size_j03jomzcbw [ 2 ] ; real_T
StateSpace_P1_e3cm2xon5j [ 24 ] ; real_T StateSpace_P2_Size_ndoezivct2 [ 2 ]
; real_T StateSpace_P2_drr0oeq0oe [ 4 ] ; real_T
StateSpace_P3_Size_avrulq4hjb [ 2 ] ; real_T StateSpace_P3_lk0jwa33xb ;
real_T StateSpace_P4_Size_jcfjorwpgw [ 2 ] ; real_T StateSpace_P4_mncjstijua
[ 176 ] ; real_T StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 2 ] ;
real_T StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 ; real_T StateSpace_P8_Size [
2 ] ; real_T StateSpace_P8 ; real_T StateSpace_P9_Size [ 2 ] ; real_T
StateSpace_P9 ; real_T StateSpace_P10_Size [ 2 ] ; real_T StateSpace_P10 ;
real_T donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_ijfdm1zi4o
; real_T LookUpTable1_bp01Data [ 2 ] ; real_T DeadZone_Start ; real_T
DeadZone_End ; real_T Gain2_Gain ; real_T Fieldarmaturemutualinductance_Gain
; real_T Gain1_Gain ; real_T Constant_Value ; real_T
Constant_Value_knnilg5f2q ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
DCM_3_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern const
int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
