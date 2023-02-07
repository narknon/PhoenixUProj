#pragma once
#include "CoreMinimal.h"
#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"
#include "CreatureMountItemTool.generated.h"

class ACreatureMountHandler;

UCLASS(Blueprintable)
class ACreatureMountItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACreatureMountHandler> MountHandlerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreatureMountHandler* MountHandler;
    
    ACreatureMountItemTool();
    UFUNCTION(BlueprintCallable)
    void SpawnAndMountCreature(bool bUseTransition, bool bInFlight);
    
};

