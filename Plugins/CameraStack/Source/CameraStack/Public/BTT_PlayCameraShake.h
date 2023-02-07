#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Templates/SubclassOf.h"
#include "BTT_PlayCameraShake.generated.h"

class UCameraShakeBase;

UCLASS(Blueprintable)
class UBTT_PlayCameraShake : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraShakeBase> CameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UBTT_PlayCameraShake();
};

