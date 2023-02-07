#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatchActorTag.h"
#include "ActorMeshSetupMatchActorNoTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchActorNoTag : public UActorMeshSetupMatchActorTag {
    GENERATED_BODY()
public:
    UActorMeshSetupMatchActorNoTag();
};

