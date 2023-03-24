#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"
#include "ChompingCabbage_InvTool.generated.h"

class AEnemy_Character;

UCLASS(Blueprintable)
class AChompingCabbage_InvTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AEnemy_Character> CabbageEnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SpawnOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ThrowVelocity;
    
    AChompingCabbage_InvTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnChompingCabbageEnemy();
    
};

