#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "LerpVolumesLevelName.h"
#include "ActorMeshSetupMatchInLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupMatchInLevel : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName Level;
    
    UActorMeshSetupMatchInLevel();
};

