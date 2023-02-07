#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "LerpVolumesLevelName.h"
#include "ActorMeshSetupMatchInLevels.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupMatchInLevels : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    UActorMeshSetupMatchInLevels();
};

