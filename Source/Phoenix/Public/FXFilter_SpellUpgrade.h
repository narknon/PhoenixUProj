#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "ESpellUpgrades.h"
#include "FXFilter_SpellUpgrade.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_SpellUpgrade : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpellUpgrades SpellUpgrade;
    
public:
    UFXFilter_SpellUpgrade();
};

