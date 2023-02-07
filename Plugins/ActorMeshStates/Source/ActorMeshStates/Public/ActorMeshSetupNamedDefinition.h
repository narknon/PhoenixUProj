#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupDefinition.h"
#include "ActorMeshSetupNamedDefinition.generated.h"

USTRUCT(BlueprintType)
struct ACTORMESHSTATES_API FActorMeshSetupNamedDefinition : public FActorMeshSetupDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FActorMeshSetupNamedDefinition();
};

