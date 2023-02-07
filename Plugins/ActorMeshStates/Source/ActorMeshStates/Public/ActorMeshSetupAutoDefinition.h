#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupDefinition.h"
#include "ActorMeshSetupAutoDefinition.generated.h"

USTRUCT(BlueprintType)
struct ACTORMESHSTATES_API FActorMeshSetupAutoDefinition : public FActorMeshSetupDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepProcessing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    FActorMeshSetupAutoDefinition();
};

