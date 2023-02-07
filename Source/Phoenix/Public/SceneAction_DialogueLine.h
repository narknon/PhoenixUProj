#pragma once
#include "CoreMinimal.h"
#include "AudioDialogueFlags.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_DialogueLine.generated.h"

class UDialogueLineProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_DialogueLine : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogueLineProvider* Line;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CutoffDialogueAtFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueFlags AudioDialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* AtLocation;
    
    USceneAction_DialogueLine();
};

