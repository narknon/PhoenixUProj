#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessLightingChannelTwo.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessLightingChannelTwo : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLightingChannelTwo;
    
    UActorMeshSetupProcessLightingChannelTwo();
};

