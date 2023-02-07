#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RagdollAudioBehaviorLayer.h"
#include "RagdollAudioBehaviorProfile.generated.h"

UCLASS(Blueprintable)
class RAGDOLL_API URagdollAudioBehaviorProfile : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRagdollAudioBehaviorLayer> BehaviorLayers;
    
    URagdollAudioBehaviorProfile();
};

