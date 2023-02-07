#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "ActorMeshSetupMatchOr.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupMatchOr : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorMeshSetupMatch*> OR;
    
    UActorMeshSetupMatchOr();
};

