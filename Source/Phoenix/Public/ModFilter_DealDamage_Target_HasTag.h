#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_Target_HasTag.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Target_HasTag : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
public:
    UModFilter_DealDamage_Target_HasTag();
};

