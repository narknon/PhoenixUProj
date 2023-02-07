#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerInstancedFoliageBVHTestEntry.h"
#include "OverlapEffectsHandlerMinimumSpeedBase.h"
#include "OverlapEffectsHandlerInstancedFoliageBVHTest.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerInstancedFoliageBVHTest : public UOverlapEffectsHandlerMinimumSpeedBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOverlapEffectsHandlerInstancedFoliageBVHTestEntry> TypeEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpdateRateMS;
    
    UOverlapEffectsHandlerInstancedFoliageBVHTest();
};

