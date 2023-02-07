#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AmbientGhost_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAmbientGhost_AnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaveEnabled;
    
    UAmbientGhost_AnimInstance();
    UFUNCTION(BlueprintCallable)
    void WaveCompleted();
    
};

