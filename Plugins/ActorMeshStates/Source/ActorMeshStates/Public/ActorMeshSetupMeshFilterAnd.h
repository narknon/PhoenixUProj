#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMeshFilter.h"
#include "ActorMeshSetupMeshFilterAnd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterAnd : public UActorMeshSetupMeshFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorMeshSetupMeshFilter*> MeshFilters;
    
    UActorMeshSetupMeshFilterAnd();
};

