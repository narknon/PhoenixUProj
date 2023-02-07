#pragma once
#include "CoreMinimal.h"
#include "SceneRig.h"
#include "SceneRigStage_Name.h"
#include "SceneRig_SpellMinigame.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API USceneRig_SpellMinigame : public USceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Name AssignedSpell;
    
    USceneRig_SpellMinigame();
};

