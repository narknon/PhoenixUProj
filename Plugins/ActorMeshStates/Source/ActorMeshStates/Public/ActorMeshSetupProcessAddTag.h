#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupProcess.h"
#include "ActorMeshSetupProcessAddTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ACTORMESHSTATES_API UActorMeshSetupProcessAddTag : public UActorMeshSetupProcess {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorTag;
    
    UActorMeshSetupProcessAddTag();
};

