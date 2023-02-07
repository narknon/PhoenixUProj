#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "ActorMeshSetupMatchActorTags.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchActorTags : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ActorTags;
    
    UActorMeshSetupMatchActorTags();
};

