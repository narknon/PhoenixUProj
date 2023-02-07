#pragma once
#include "CoreMinimal.h"
#include "ELightOnOffFXTargetMode.h"
#include "ELightOnOffFXTargetType.h"
#include "LightGroupBoundComponentSettings.generated.h"

USTRUCT(BlueprintType)
struct FLightGroupBoundComponentSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FXName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightOnOffFXTargetType FXType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightOnOffFXTargetMode FXMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bInvertOnOff: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPropagateToChildren: 1;
    
    GLOBALLIGHTGROUPS_API FLightGroupBoundComponentSettings();
};

