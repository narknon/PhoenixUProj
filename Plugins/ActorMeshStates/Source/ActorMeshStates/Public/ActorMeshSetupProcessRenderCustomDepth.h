#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcessFiltered.h"
#include "ActorMeshSetupProcessRenderCustomDepth.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessRenderCustomDepth : public UActorMeshSetupProcessFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UActorMeshSetupProcessRenderCustomDepth();
};

