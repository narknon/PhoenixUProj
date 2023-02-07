#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcess.h"
#include "ActorMeshSetupProcessRemoveTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessRemoveTag : public UActorMeshSetupProcess {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorTag;
    
    UActorMeshSetupProcessRemoveTag();
};

