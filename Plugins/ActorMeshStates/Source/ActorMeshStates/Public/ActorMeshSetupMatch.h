#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorMeshSetupMatch.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatch : public UObject {
    GENERATED_BODY()
public:
    UActorMeshSetupMatch();
};

