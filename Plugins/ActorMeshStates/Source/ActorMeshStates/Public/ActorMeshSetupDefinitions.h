#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActorMeshSetupAutoDefinition.h"
#include "ActorMeshSetupNamedDefinition.h"
#include "ActorMeshSetupDefinitions.generated.h"

UCLASS(Blueprintable)
class ACTORMESHSTATES_API UActorMeshSetupDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorMeshSetupAutoDefinition> AutoDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorMeshSetupNamedDefinition> NamedDefinitions;
    
    UActorMeshSetupDefinitions();
};

