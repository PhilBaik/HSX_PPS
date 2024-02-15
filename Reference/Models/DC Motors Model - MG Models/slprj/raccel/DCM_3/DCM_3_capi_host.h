#include "__cf_DCM_3.h"
#ifndef RTW_HEADER_DCM_3_cap_host_h_
#define RTW_HEADER_DCM_3_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DCM_3_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void DCM_3_host_InitializeDataMapInfo ( DCM_3_host_DataMapInfo_T * dataMap ,
const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
