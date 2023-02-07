#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "LerpVolumesLevelName.h"
#include "ActorMeshSetupMatchNotInLevels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupMatchNotInLevels : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    UActorMeshSetupMatchNotInLevels();
};

