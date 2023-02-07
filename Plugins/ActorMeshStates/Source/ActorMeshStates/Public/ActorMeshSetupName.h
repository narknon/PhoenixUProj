#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupName.generated.h"

USTRUCT(BlueprintType)
struct FActorMeshSetupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    ACTORMESHSTATES_API FActorMeshSetupName();
};

