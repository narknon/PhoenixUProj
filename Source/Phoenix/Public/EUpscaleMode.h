#pragma once
#include "CoreMinimal.h"
#include "EUpscaleMode.generated.h"

UENUM(BlueprintType)
enum class EUpscaleMode : uint8 {
    None,
    DLSS_Off,
    DLSS_Auto,
    DLSS_UltraPerformance,
    DLSS_Performance,
    DLSS_Balanced,
    DLSS_Quality,
    DLSS_UltraQuality,
    AMD_FSR_Performance,
    AMD_FSR_Balanced,
    AMD_FSR_Quality,
    AMD_FSR_UltraQuality,
    NIS_Performance,
    NIS_Balanced,
    NIS_Quality,
    NIS_UltraQuality,
    AMD_FSR2_UltraPerformance,
    AMD_FSR2_Performance,
    AMD_FSR2_Balanced,
    AMD_FSR2_Quality,
    Intel_XeSS_Performance,
    Intel_XeSS_Balanced,
    Intel_XeSS_Quality,
    Intel_XeSS_UltraQuality,
    DLSS_Min = 0x1,
    DLSS_Max = 0x7,
    AMD_FSR_Min,
    AMD_FSR_Max = 0xB,
    NIS_Min,
    NIS_Max = 0xF,
    AMD_FSR2_Min,
    AMD_FSR2_Max = 0x13,
    Intel_XeSS_Min,
    Intel_XeSS_Max = 0x17,
};

