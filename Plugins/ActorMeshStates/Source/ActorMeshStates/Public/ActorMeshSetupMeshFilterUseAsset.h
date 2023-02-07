#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMeshFilter.h"
#include "ActorMeshSetupMeshFilterUseAsset.generated.h"

class UActorMeshSetupMeshFilterAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterUseAsset : public UActorMeshSetupMeshFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorMeshSetupMeshFilterAsset* FilterAsset;
    
    UActorMeshSetupMeshFilterUseAsset();
};

