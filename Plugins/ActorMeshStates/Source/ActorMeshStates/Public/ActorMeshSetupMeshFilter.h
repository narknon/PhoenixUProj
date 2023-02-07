#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorMeshSetupMeshFilter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilter : public UObject {
    GENERATED_BODY()
public:
    UActorMeshSetupMeshFilter();
};

