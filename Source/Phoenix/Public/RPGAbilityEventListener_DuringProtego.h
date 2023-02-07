#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_DuringProtego.generated.h"

class ASpellTool;
class AWandTool;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_DuringProtego : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWandTool* Wand;
    
public:
    URPGAbilityEventListener_DuringProtego();
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpellStop(ASpellTool* SpellTool);
    
    UFUNCTION(BlueprintCallable)
    void OnSpellCast(ASpellTool* SpellTool);
    
};

