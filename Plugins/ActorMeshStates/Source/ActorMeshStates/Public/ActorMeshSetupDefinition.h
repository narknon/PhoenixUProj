#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupDefinition.generated.h"

class UActorMeshSetupMatch;
class UActorMeshSetupProcess;

USTRUCT(BlueprintType)
struct ACTORMESHSTATES_API FActorMeshSetupDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorMeshSetupMatch* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorMeshSetupProcess*> MeshSetups;
    
    FActorMeshSetupDefinition();
};

