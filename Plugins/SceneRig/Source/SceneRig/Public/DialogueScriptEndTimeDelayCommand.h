#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptCommand.h"
#include "DialogueScriptEndTimeDelayCommand.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptEndTimeDelayCommand : public UDialogueScriptCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayValue;
    
    UDialogueScriptEndTimeDelayCommand();
};

