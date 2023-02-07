#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "ActorMeshSetupMatchActorTag.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchActorTag : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorTag;
    
    UActorMeshSetupMatchActorTag();
};

