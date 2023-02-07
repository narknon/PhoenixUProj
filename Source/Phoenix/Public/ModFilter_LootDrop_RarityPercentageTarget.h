#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "ModFilter_LootDrop_Base.h"
#include "ModFilter_LootDrop_RarityPercentageTarget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_LootDrop_RarityPercentageTarget : public UModFilter_LootDrop_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetPercent;
    
public:
    UModFilter_LootDrop_RarityPercentageTarget();
};

