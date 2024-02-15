#include "__cf_DCM_3.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "DCM_3_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "DCM_3.h"
#include "DCM_3_capi.h"
#include "DCM_3_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"DCM_3/Dead Zone" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "DCM_3/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 2 , 0 , TARGET_STRING ( "DCM_3/DC Machine/Electrical model/Gain2" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Integrator" ) , TARGET_STRING ( "w" ) , 0
, 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Product" ) , TARGET_STRING ( "E fcem" ) ,
0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Product1" ) , TARGET_STRING ( "Te" ) , 0 ,
0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 7 , 0 , TARGET_STRING (
"DCM_3/DC Machine/iA/do not delete this gain" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"DCM_3/DC Machine/iF/do not delete this gain" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"DCM_3/DC Voltage Source/Model/DC" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 10 , 0 , TARGET_STRING ( "DCM_3/DC Voltage Source1/Model/DC" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "" ) , 1 ,
0 , 1 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Voltage constant KE/Field-armature mutual inductance"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Voltage constant KE/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Voltage constant KE/KE filter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Voltage constant KE/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 21 , TARGET_STRING ( "DCM_3/DC Machine" ) ,
TARGET_STRING ( "Ifinit" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"DCM_3/DC Voltage Source" ) , TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , {
23 , TARGET_STRING ( "DCM_3/DC Voltage Source1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"DCM_3/Repeating Sequence" ) , TARGET_STRING ( "rep_seq_y" ) , 0 , 2 , 0 } ,
{ 25 , TARGET_STRING ( "DCM_3/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 26 , TARGET_STRING ( "DCM_3/Dead Zone" ) , TARGET_STRING (
"LowerValue" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING ( "DCM_3/Dead Zone" ) ,
TARGET_STRING ( "UpperValue" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"DCM_3/Repeating Sequence/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 29 , TARGET_STRING ( "DCM_3/Repeating Sequence/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 2 , 0 } , { 30 ,
TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques"
) , TARGET_STRING ( "offset" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques"
) , TARGET_STRING ( "gain" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 33 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"DCM_3/DC Machine/iA/do not delete this gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 35 , TARGET_STRING (
"DCM_3/DC Machine/iF/do not delete this gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 36 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" ) , 0
, 3 , 0 } , { 37 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" ) , 0
, 4 , 0 } , { 38 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" ) , 0
, 0 , 0 } , { 39 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" ) , 0
, 5 , 0 } , { 40 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P1" ) , 0
, 6 , 0 } , { 41 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P2" ) , 0
, 4 , 0 } , { 42 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P3" ) , 0
, 0 , 0 } , { 43 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P4" ) , 0
, 7 , 0 } , { 44 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P5" ) , 0
, 1 , 0 } , { 45 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P6" ) , 0
, 0 , 0 } , { 46 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P7" ) , 0
, 0 , 0 } , { 47 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P8" ) , 0
, 0 , 0 } , { 48 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P9" ) , 0
, 0 , 0 } , { 49 , TARGET_STRING (
"DCM_3/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "P10" ) , 0
, 0 , 0 } , { 50 , TARGET_STRING (
 "DCM_3/DC Machine/Electrical model/Voltage constant KE/Field-armature mutual inductance"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"DCM_3/DC Machine/Electrical model/Voltage constant KE/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dav20jyvk3 , & rtB . h451ajn5pc ,
& rtB . ogaap0wcng , & rtB . dwpzvnyws1 , & rtB . noqxuuytub , & rtB .
n5upg3xxwm , & rtB . pjsgwedo55 , & rtB . dalxhvg1zf , & rtB . j1eypzh03i , &
rtB . ooxs3jjvtd , & rtB . nyl0zlk1x2 , & rtB . axmmhiccox , & rtB .
nhfuapoovh , & rtB . ct0taxgvv3 [ 0 ] , & rtB . g4p2xlgqdu , & rtB .
e3114yddje , & rtB . m0juatoz4z , & rtB . noffyg4nar , & rtB . dkw4zvirgz , &
rtB . fua0oio1qa , & rtB . iw2api0er3 , & rtP . DCMachine_Ifinit , & rtP .
DCVoltageSource_Amplitude , & rtP . DCVoltageSource1_Amplitude , & rtP .
RepeatingSequence_rep_seq_y [ 0 ] , & rtP . Constant_Value , & rtP .
DeadZone_Start , & rtP . DeadZone_End , & rtP . Constant_Value_knnilg5f2q , &
rtP . LookUpTable1_bp01Data [ 0 ] , & rtP .
CoulombTfViscousBmwFrictionTorques_offset , & rtP .
CoulombTfViscousBmwFrictionTorques_gain , & rtP . Gain2_Gain , & rtP .
Integrator_IC , & rtP . donotdeletethisgain_Gain , & rtP .
donotdeletethisgain_Gain_ijfdm1zi4o , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 , & rtP . StateSpace_P4 [ 0 ] , &
rtP . StateSpace_P1_e3cm2xon5j [ 0 ] , & rtP . StateSpace_P2_drr0oeq0oe [ 0 ]
, & rtP . StateSpace_P3_lk0jwa33xb , & rtP . StateSpace_P4_mncjstijua [ 0 ] ,
& rtP . StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 , & rtP . StateSpace_P7 ,
& rtP . StateSpace_P8 , & rtP . StateSpace_P9 , & rtP . StateSpace_P10 , &
rtP . Fieldarmaturemutualinductance_Gain , & rtP . Gain1_Gain , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 1 , 2
, 5 , 2 , 1 , 4 , 5 , 23 , 8 , 3 , 8 , 22 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
1 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void
* ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } }
; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 21 ,
( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 31 , rtModelParameters
, 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 3867164020U
, 1644783790U , 2590097787U , 1616282842U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * DCM_3_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void DCM_3_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void DCM_3_host_InitializeDataMapInfo ( DCM_3_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
