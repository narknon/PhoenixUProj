#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessIgnoreLightLeaking.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessIgnoreLightLeaking : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreLightLeakingCorrection;
    
    UActorMeshSetupProcessIgnoreLightLeaking();
};

