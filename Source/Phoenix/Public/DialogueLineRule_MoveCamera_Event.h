#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "UObject/Object.h"
#include "SceneRigStage_ActorReference.h"
#include "DialogLineRule_CameraAnimation.h"
#include "DialogLineRule_CameraFixup.h"
#include "DialogueLineRule_MoveCamera_Event.generated.h"

class UTransformProvider;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class UDialogueLineRule_MoveCamera_Event : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ActorReference Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogLineRule_CameraAnimation> Animations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogLineRule_CameraFixup CameraFixup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* PlacementTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference PlacementLayer;
    
    UDialogueLineRule_MoveCamera_Event();
};

