#pragma once
#include "CoreMinimal.h"
#include "EVolumeCenterlineMode.h"
#include "VolumeCenterlineSettings.generated.h"

USTRUCT(BlueprintType)
struct LERPVOLUMES_API FVolumeCenterlineSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVolumeCenterlineMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CeilingFlatness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FloorFlatness;
    
    FVolumeCenterlineSettings();
};

