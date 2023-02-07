#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HUDElementGroup.h"
#include "DamageIndicatorsBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UDamageIndicatorsBase : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UDamageIndicatorsBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNPC_Damaged(const FVector2D& ScreenPos, float Damage, bool IsVulnerableDamage);
    
};

