#include "__cf_DCM_3.h"
#include "rt_logging_mmi.h"
#include "DCM_3_capi.h"
#include <math.h>
#include "DCM_3.h"
#include "DCM_3_private.h"
#include "DCM_3_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.0 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\DCM_3\\DCM_3_Jpattern.mat" ; const int_T gblNumRootInportBlks
= 0 ; const int_T gblNumModelInputs = 0 ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; extern void *
gblAperiodicPartitionHitTimes ; const int_T gblInportDataTypeIdx [ ] = { - 1
} ; const int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [
] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1
} ; const char * raccelLoadInputsAndAperiodicHitTimes ( const char *
inportFileName , int * matFileFormat ) { return rt_RapidReadInportsMatFile (
inportFileName , matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ;
uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [
maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while
( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [
iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] )
* frac + table [ iLeft ] ; } void MdlInitialize ( void ) { { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtX . gstm2g4gvs = rtP .
Integrator_IC ; rtX . hh3oplhqb2 = rtP . DCMachine_Ifinit ; { SimStruct * rts
= ssGetSFunction ( rtS , 1 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlStart ( void ) {
{ void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL
) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize
= 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtB . nyl0zlk1x2 = rtP .
DCVoltageSource1_Amplitude ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnOutputs ( rts , 0 ) ; } rtB . dwpzvnyws1 = rtX . gstm2g4gvs ; rtB .
fua0oio1qa = rtX . hh3oplhqb2 ; rtB . noqxuuytub = rtB . dwpzvnyws1 * rtB .
fua0oio1qa ; { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnOutputs (
rts , 0 ) ; } rtB . dalxhvg1zf = rtP . donotdeletethisgain_Gain * rtB .
nhfuapoovh ; rtB . n5upg3xxwm = rtB . dalxhvg1zf * rtB . fua0oio1qa ; rtB .
j1eypzh03i = rtP . donotdeletethisgain_Gain_ijfdm1zi4o * rtB . axmmhiccox ;
rtB . h451ajn5pc = ( rtP . Constant_Value - rtB . dalxhvg1zf ) / rtP .
Constant_Value - look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) - 0.0 ,
rtP . Constant_Value_knnilg5f2q ) , rtP . LookUpTable1_bp01Data , rtP .
RepeatingSequence_rep_seq_y , 1U ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( rtB . h451ajn5pc > 0.0 ) { rtDW . m0sqzkayaq = 1 ; } else if ( rtB .
h451ajn5pc < 0.0 ) { rtDW . m0sqzkayaq = - 1 ; } else { rtDW . m0sqzkayaq = 0
; } if ( rtDW . m0sqzkayaq > rtP . DeadZone_End ) { rtB . dav20jyvk3 = (
real_T ) rtDW . m0sqzkayaq - rtP . DeadZone_End ; } else if ( rtDW .
m0sqzkayaq >= rtP . DeadZone_Start ) { rtB . dav20jyvk3 = 0.0 ; } else { rtB
. dav20jyvk3 = ( real_T ) rtDW . m0sqzkayaq - rtP . DeadZone_Start ; } } rtB
. g4p2xlgqdu = rtP . CoulombTfViscousBmwFrictionTorques_gain * rtB .
dwpzvnyws1 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . dwpzvnyws1 >
0.0 ) { rtDW . ifodo1eta0 = 1 ; } else if ( rtB . dwpzvnyws1 < 0.0 ) { rtDW .
ifodo1eta0 = - 1 ; } else { rtDW . ifodo1eta0 = 0 ; } rtB . e3114yddje = rtP
. CoulombTfViscousBmwFrictionTorques_offset * ( real_T ) rtDW . ifodo1eta0 ;
} rtB . m0juatoz4z = rtB . e3114yddje + rtB . g4p2xlgqdu ; rtB . pjsgwedo55 =
rtB . n5upg3xxwm - rtB . m0juatoz4z ; rtB . ogaap0wcng = rtP . Gain2_Gain *
rtB . pjsgwedo55 ; rtB . noffyg4nar = rtP .
Fieldarmaturemutualinductance_Gain * rtB . j1eypzh03i ; rtB . iw2api0er3 =
rtB . noffyg4nar - rtB . fua0oio1qa ; rtB . dkw4zvirgz = rtP . Gain1_Gain *
rtB . iw2api0er3 ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T
tid ) { rtB . ooxs3jjvtd = rtP . DCVoltageSource_Amplitude ; rtB . nyl0zlk1x2
= rtP . DCVoltageSource1_Amplitude ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ;
} { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnUpdate ( rts , 0 ) ;
if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } UNUSED_PARAMETER ( tid
) ; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; real_T * sfcndX_fx
= ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) -> mwapy0rjtv ; ssSetdX ( rts
, sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if ( ssGetErrorStatus ( rts ) != (
NULL ) ) return ; } _rtXdot -> gstm2g4gvs = rtB . ogaap0wcng ; _rtXdot ->
hh3oplhqb2 = rtB . dkw4zvirgz ; { SimStruct * rts = ssGetSFunction ( rtS , 1
) ; real_T * sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) ->
e4xjjpdmux ; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlProjection ( void
) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnProjection ( rts ) ;
if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnProjection ( rts ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; ssSetNonsampledZCs ( rts , & (
( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> dvbmyegzvg [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } _rtZCSV -> atnazhuttj = rtB . h451ajn5pc ; _rtZCSV -> jm2aun3v5i =
rtB . dwpzvnyws1 ; } void MdlTerminate ( void ) { { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnTerminate ( rts ) ; } if ( rt_slioCatalogue
( ) != ( NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 63 ) ; ssSetNumBlockIO ( rtS , 21 ) ;
ssSetNumBlockParams ( rtS , 389 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3867164020U ) ;
ssSetChecksumVal ( rtS , 1 , 1644783790U ) ; ssSetChecksumVal ( rtS , 2 ,
2590097787U ) ; ssSetChecksumVal ( rtS , 3 , 1616282842U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
DCM_3_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true
) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2
) ; ssSetModelName ( rtS , "DCM_3" ) ; ssSetPath ( rtS , "DCM_3" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 20.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT ( ssGetRTWLogInfo ( rtS )
, "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal
( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 4 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3 ;
static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 4 ] ; static real_T absTol [ 4 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 4 ] = { 0U , 0U , 0U , 0U
} ; static uint8_T zcAttributes [ 4 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 2 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
e3114yddje ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
dav20jyvk3 ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.4 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
2 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode23tb" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 1 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 1 ) ; ( void ) memset ( ( void * ) &
mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ; ssSetModelMethods2 ( rtS , &
mdlMethods2 ) ; ( void ) memset ( ( void * ) & mdlMethods3 , 0 , sizeof (
mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , & mdlMethods3 ) ;
ssSetModelProjection ( rtS , MdlProjection ) ; ssSetSolverMassMatrixType (
rtS , ( ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 4 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 0 ) ; ssSetSolverZcThreshold ( rtS ,
0.001 ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3867164020U ) ; ssSetChecksumVal ( rtS , 1 ,
1644783790U ) ; ssSetChecksumVal ( rtS , 2 , 2590097787U ) ; ssSetChecksumVal
( rtS , 3 , 1616282842U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
ssSetNumSFunctions ( rtS , 2 ) ; { static SimStruct childSFunctions [ 2 ] ;
static SimStruct * childSFunctionPtrs [ 2 ] ; ( void ) memset ( ( void * ) &
childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions (
rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , &
childSFunctions [ 0 ] ) ; ssSetSFunction ( rtS , 1 , & childSFunctions [ 1 ]
) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T sfcnPeriod
[ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; (
void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void
) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) + 0 ) ;
ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 0 ) ; } {
static struct _ssPortInputs inputPortInfo [ 1 ] ; _ssSetNumInputPorts ( rts ,
1 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; { static real_T
const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . nyl0zlk1x2 ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . axmmhiccox
) ) ; } } ssSetContStates ( rts , & rtX . mwapy0rjtv ) ;
ssSetContStateDisabled ( rts , & ( ( XDis * ) ssGetContStateDisabled ( rtS )
) -> mwapy0rjtv ) ; ssSetModelName ( rts , "State-Space" ) ; ssSetPath ( rts
, "DCM_3/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel ( rtS )
== ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS
( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . StateSpace_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . StateSpace_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . StateSpace_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . StateSpace_P4_Size ) ; }
ssSetRWork ( rts , ( real_T * ) & rtDW . gj1pm3tws0 [ 0 ] ) ; ssSetIWork (
rts , ( int_T * ) & rtDW . opv2pzumsy [ 0 ] ) ; ssSetPWork ( rts , ( void * *
) & rtDW . e0bjgobeax [ 0 ] ) ; { static struct _ssDWorkRecord dWorkRecord [
3 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork (
rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ;
_ssSetNumDWork ( rts , 3 ) ; ssSetDWorkWidth ( rts , 0 , 2 ) ;
ssSetDWorkDataType ( rts , 0 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts ,
0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . gj1pm3tws0 [ 0 ] ) ;
ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType ( rts , 1 , SS_INTEGER
) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW .
opv2pzumsy [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ; ssSetDWorkDataType (
rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork
( rts , 2 , & rtDW . e0bjgobeax [ 0 ] ) ; } sfun_spid_contc ( rts ) ;
sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 0 ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
0 , 1 ) ; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ;
ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) +
3 ) ; ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 3 )
; } { static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts (
rts , 2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = & rtB . ooxs3jjvtd ;
sfcnUPtrs [ 1 ] = & rtB . noqxuuytub ; ssSetInputPortSignalPtrs ( rts , 0 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0
, 1 ) ; ssSetInputPortWidth ( rts , 0 , 2 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . dav20jyvk3 ;
ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidth ( rts , 1
, 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 2 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . nhfuapoovh
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidth ( rts , 1 , 2 ) ; ssSetOutputPortSignal ( rts , 1 , ( (
real_T * ) rtB . ct0taxgvv3 ) ) ; } } ssSetContStates ( rts , & rtX .
e4xjjpdmux ) ; ssSetContStateDisabled ( rts , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> e4xjjpdmux ) ; ssSetModelName ( rts ,
"State-Space" ) ; ssSetPath ( rts ,
"DCM_3/powergui/EquivalentModel2/State-Space" ) ; if ( ssGetRTModel ( rtS )
== ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS
( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 10 ] ;
ssSetSFcnParamsCount ( rts , 10 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size_j03jomzcbw ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * )
rtP . StateSpace_P2_Size_ndoezivct2 ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . StateSpace_P3_Size_avrulq4hjb ) ; ssSetSFcnParam ( rts , 3 , (
mxArray * ) rtP . StateSpace_P4_Size_jcfjorwpgw ) ; ssSetSFcnParam ( rts , 4
, ( mxArray * ) rtP . StateSpace_P5_Size ) ; ssSetSFcnParam ( rts , 5 , (
mxArray * ) rtP . StateSpace_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray
* ) rtP . StateSpace_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP
. StateSpace_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
StateSpace_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
StateSpace_P10_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . pl2nkwidb2
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . jiw4bh1isx [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . i3xyhwkhup [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 4 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 4 ) ;
ssSetDWorkWidth ( rts , 0 , 2 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
perqcxtxaf [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 2 ) ; ssSetDWorkDataType (
rts , 1 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . pl2nkwidb2 [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 23 ) ;
ssSetDWorkDataType ( rts , 2 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . jiw4bh1isx [ 0 ] ) ;
ssSetDWorkWidth ( rts , 3 , 22 ) ; ssSetDWorkDataType ( rts , 3 , SS_POINTER
) ; ssSetDWorkComplexSignal ( rts , 3 , 0 ) ; ssSetDWork ( rts , 3 , & rtDW .
i3xyhwkhup [ 0 ] ) ; } ssSetModeVector ( rts , ( int_T * ) & rtDW .
perqcxtxaf [ 0 ] ) ; sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 2 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts
, 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
