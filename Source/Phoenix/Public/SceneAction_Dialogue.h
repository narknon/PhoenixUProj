#pragma once
#include "CoreMinimal.h"
#include "ActionParameter_DialogueEvent.h"
#include "AudioDialogueFlags.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_Dialogue.generated.h"

class UDialogueLineProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_Dialogue : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogueLineProvider* Line;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> AdditionalParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopWhenAttachedToDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioDialogueFlags AudioDialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CutoffDialogueAtFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_DialogueEvent Event;
    
    USceneAction_Dialogue();
};

