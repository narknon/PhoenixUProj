#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapRules.h"
#include "MultiFX2_ActorMeshStates.h"
#include "MultiFX2_ActorMeshStatesRules.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ActorMeshStatesRules : public UMultiFX2_ActorMeshStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UMultiFX2_ActorMeshStatesRules();
};

