#pragma once
#include "CoreMinimal.h"
#include "ConsumablePotionItemTool.h"
#include "IncompletePolyjuiceItemTool.generated.h"

UCLASS(Blueprintable)
class AIncompletePolyjuiceItemTool : public AConsumablePotionItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UsageDistance;
    
    AIncompletePolyjuiceItemTool(const FObjectInitializer& ObjectInitializer);
};

