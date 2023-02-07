#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueScriptCommand.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class SCENERIG_API UDialogueScriptCommand : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UDialogueScriptCommand();
};

