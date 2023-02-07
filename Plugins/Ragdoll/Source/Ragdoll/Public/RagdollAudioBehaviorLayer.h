#pragma once
#include "CoreMinimal.h"
#include "RagdollAudioBehaviorLayer.generated.h"

class URagdollAudioBehavior;

USTRUCT(BlueprintType)
struct FRagdollAudioBehaviorLayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URagdollAudioBehavior*> AudioBehaviors;
    
    RAGDOLL_API FRagdollAudioBehaviorLayer();
};

