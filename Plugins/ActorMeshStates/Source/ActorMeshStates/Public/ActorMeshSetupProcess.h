#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorMeshSetupProcess.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcess : public UObject {
    GENERATED_BODY()
public:
    UActorMeshSetupProcess();
};

