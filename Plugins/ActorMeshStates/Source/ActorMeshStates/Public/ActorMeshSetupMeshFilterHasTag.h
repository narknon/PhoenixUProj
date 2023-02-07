#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMeshFilter.h"
#include "ActorMeshSetupMeshFilterHasTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterHasTag : public UActorMeshSetupMeshFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ComponentTag;
    
    UActorMeshSetupMeshFilterHasTag();
};

