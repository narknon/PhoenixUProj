#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerWithConditions.h"
#include "OverlapEffectsHandlerMinimumSpeedBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerMinimumSpeedBase : public UOverlapEffectsHandlerWithConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumSpeed;
    
    UOverlapEffectsHandlerMinimumSpeedBase();
};

