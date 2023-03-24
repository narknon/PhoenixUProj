#pragma once
#include "CoreMinimal.h"
#include "InventoryItemTool.h"
#include "ThrowableInventoryItemTool.generated.h"

UCLASS(Blueprintable)
class AThrowableInventoryItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
public:
    AThrowableInventoryItemTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    float GetMaxDistance();
    
};

