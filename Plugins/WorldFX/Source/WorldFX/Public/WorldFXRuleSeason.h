#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleSeasonBase.h"
#include "WorldFXRuleSeason.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSeason : public UWorldFXRuleSeasonBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seasons;
    
    UWorldFXRuleSeason();
};

