#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "PerformTaskAITeleportToTransform.generated.h"

class ATargetPoint;

UCLASS(Blueprintable, EditInlineNew)
class UPerformTaskAITeleportToTransform : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATargetPoint* TeleportTargetPoint;
    
    UPerformTaskAITeleportToTransform();
};

