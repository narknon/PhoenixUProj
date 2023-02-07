#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandler.h"
#include "OverlapEffectsHandlerConditions.h"
#include "OverlapEffectsHandlerWithConditions.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerWithConditions : public UOverlapEffectsHandler {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverlapEffectsHandlerConditions Conditions;
    
    UOverlapEffectsHandlerWithConditions();
};

