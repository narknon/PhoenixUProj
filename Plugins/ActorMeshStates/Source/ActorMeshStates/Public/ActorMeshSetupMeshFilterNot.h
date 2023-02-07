#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMeshFilter.h"
#include "ActorMeshSetupMeshFilterNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterNot : public UActorMeshSetupMeshFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorMeshSetupMeshFilter* MeshFilter;
    
    UActorMeshSetupMeshFilterNot();
};

