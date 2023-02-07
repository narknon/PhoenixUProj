#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessHiddenShadow.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupProcessHiddenShadow : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastHiddenShadow;
    
    UActorMeshSetupProcessHiddenShadow();
};

