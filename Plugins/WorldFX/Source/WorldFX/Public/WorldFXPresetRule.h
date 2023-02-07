#pragma once
#include "CoreMinimal.h"
#include "WorldFXPresetRuleName.h"
#include "WorldFXRule.h"
#include "WorldFXPresetRule.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WORLDFX_API UWorldFXPresetRule : public UWorldFXRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXPresetRuleName Preset;
    
    UWorldFXPresetRule();
};

