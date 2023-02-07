#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessCastShadow.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupProcessCastShadow : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastShadow;
    
    UActorMeshSetupProcessCastShadow();
};

