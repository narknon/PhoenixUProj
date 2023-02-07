#pragma once
#include "CoreMinimal.h"
#include "DialogueScriptCommand.h"
#include "DialogueScriptBlockImplicitRulesCommand.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UDialogueScriptBlockImplicitRulesCommand : public UDialogueScriptCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockLayeredAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BlockCameraChanges;
    
    UDialogueScriptBlockImplicitRulesCommand();
};

