#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_ActorMeshStates.h"
#include "MultiFX2_ActorMeshStatesSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ActorMeshStatesSimple : public UMultiFX2_ActorMeshStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildren;
    
    UMultiFX2_ActorMeshStatesSimple();
};

