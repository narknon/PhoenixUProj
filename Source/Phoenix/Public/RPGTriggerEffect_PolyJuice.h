#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_PolyJuice.generated.h"

class AActor;
class ASpellTool;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_PolyJuice : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
public:
    URPGTriggerEffect_PolyJuice();
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpellCast(ASpellTool* SpellTool);
    
};

