#pragma once
#include "CoreMinimal.h"
#include "PoseSampler.h"
#include "PoseSampler_AmbientEyes.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UPoseSampler_AmbientEyes : public UPoseSampler {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LODThreshold;
    
    UPoseSampler_AmbientEyes();
private:
    UFUNCTION(BlueprintCallable)
    void OnDialogueLineAnimStarted(FName DialogueID, float WorldTime);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogueLineAnimFinished(bool bCancelled);
    
};

