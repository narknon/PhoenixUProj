#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "CharacterLightRigAdjustments.h"
#include "CharacterLightRigAdjustmentVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ACharacterLightRigAdjustmentVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterLightRigAdjustments Adjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float InterpolationDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    ACharacterLightRigAdjustmentVolume(const FObjectInitializer& ObjectInitializer);
};

