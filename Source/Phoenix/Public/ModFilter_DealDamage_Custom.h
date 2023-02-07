#pragma once
#include "CoreMinimal.h"
#include "DamageInfo.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_Custom.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Custom : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
    UModFilter_DealDamage_Custom();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool BlueprintPassesDamageFilter(const UObject* InTargetObject, const FDamageInfo& DamageInfo) const;
    
};

