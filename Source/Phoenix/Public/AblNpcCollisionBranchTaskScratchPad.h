#pragma once
#include "CoreMinimal.h"
#include "AblBranchTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AblNpcCollisionBranchTaskScratchPad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblNpcCollisionBranchTaskScratchPad : public UAblBranchTaskScratchPad {
    GENERATED_BODY()
public:
    UAblNpcCollisionBranchTaskScratchPad();
    UFUNCTION(BlueprintCallable)
    void OnNpcCapsuleHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
};

