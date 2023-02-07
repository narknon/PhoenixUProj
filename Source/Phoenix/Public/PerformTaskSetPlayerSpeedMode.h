#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "AIPerformTaskBase.h"
#include "PerformTaskSetPlayerSpeedMode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPerformTaskSetPlayerSpeedMode : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> SpeedMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> SpeedModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldRevertToDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float changePlayerSpeedRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float revertRadius;
    
    UPerformTaskSetPlayerSpeedMode();
};

