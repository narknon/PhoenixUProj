#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_CharacterTurnToFace.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CharacterTurnToFace : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* WorldSpaceTransform;
    
    USceneAction_CharacterTurnToFace();
};

