#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "InventoryItemTool.h"
#include "PortkeyInventoryItemTool.generated.h"

UCLASS(Blueprintable)
class APortkeyInventoryItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TargetFastTravelLocation;
    
    APortkeyInventoryItemTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Transport();
    
};

