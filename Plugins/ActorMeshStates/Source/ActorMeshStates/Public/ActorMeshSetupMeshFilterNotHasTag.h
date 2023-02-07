#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMeshFilter.h"
#include "ActorMeshSetupMeshFilterNotHasTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMeshFilterNotHasTag : public UActorMeshSetupMeshFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ComponentTag;
    
    UActorMeshSetupMeshFilterNotHasTag();
};

