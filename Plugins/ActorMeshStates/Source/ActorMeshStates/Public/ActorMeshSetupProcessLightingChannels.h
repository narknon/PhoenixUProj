#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessLightingChannels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessLightingChannels : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightingChannels LightingChannels;
    
    UActorMeshSetupProcessLightingChannels();
};

