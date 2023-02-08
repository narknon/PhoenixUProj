#pragma once
#include "CoreMinimal.h"
#include "AvaAudioDialogueEvent.h"

#include "RagdollBehaviorBase.h"
#include "RagdollAudioBehavior.generated.h"



UCLASS(Blueprintable)
class RAGDOLL_API URagdollAudioBehavior : public URagdollBehaviorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopOnExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysInterrupt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollAudioBehavior*> CanInterruptAudioBehaviors;
    
    URagdollAudioBehavior();
};

