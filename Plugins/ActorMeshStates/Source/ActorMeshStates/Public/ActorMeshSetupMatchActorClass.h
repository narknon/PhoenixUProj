#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "ActorMeshSetupMatchActorClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchActorClass : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeSubclasses;
    
    UActorMeshSetupMatchActorClass();
};

