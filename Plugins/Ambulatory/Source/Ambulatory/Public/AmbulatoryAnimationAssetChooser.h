#pragma once
#include "CoreMinimal.h"
#include "AblAnimationAssetChooser.h"
#include "AmbulatoryAnimationAssetChooser.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class AMBULATORY_API UAmbulatoryAnimationAssetChooser : public UAblAnimationAssetChooser {
    GENERATED_BODY()
public:
    UAmbulatoryAnimationAssetChooser();
};

