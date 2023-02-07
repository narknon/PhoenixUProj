#pragma once
#include "CoreMinimal.h"
#include "LightSwitchFX.h"
#include "LightOnOffFX.generated.h"

USTRUCT(BlueprintType)
struct FLightOnOffFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightSwitchFX TurnOnFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightSwitchFX TurnOffFX;
    
    GLOBALLIGHTGROUPS_API FLightOnOffFX();
};

