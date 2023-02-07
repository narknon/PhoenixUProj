#pragma once
#include "CoreMinimal.h"
#include "ActionSelectionScreenBase.h"
#include "ActionSelectionScreenBase_Controller.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UActionSelectionScreenBase_Controller : public UActionSelectionScreenBase {
    GENERATED_BODY()
public:
    UActionSelectionScreenBase_Controller();
    UFUNCTION(BlueprintCallable)
    void OnSpellModifierRelease();
    
    UFUNCTION(BlueprintCallable)
    void OnSpellModifierPress();
    
};

