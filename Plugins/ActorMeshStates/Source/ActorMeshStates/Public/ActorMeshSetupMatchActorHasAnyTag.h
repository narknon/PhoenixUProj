#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatchActorTags.h"
#include "ActorMeshSetupMatchActorHasAnyTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchActorHasAnyTag : public UActorMeshSetupMatchActorTags {
    GENERATED_BODY()
public:
    UActorMeshSetupMatchActorHasAnyTag();
};

