#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "ImperiusSpellTool.generated.h"

class UGameplayPropertyMod;
class UMultiFX2_Base;
class UStateEffectComponent;

UCLASS(Blueprintable)
class AImperiusSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ImperiusFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameplayPropertyMod* Mod;
    
    AImperiusSpellTool();
    UFUNCTION(BlueprintCallable)
    void DoSpellComponentSetup(UStateEffectComponent* StateEffectComponent);
    
};

