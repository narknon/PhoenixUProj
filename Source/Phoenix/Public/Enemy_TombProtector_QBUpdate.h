#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_TombProtector_QBUpdate.generated.h"

class UEnemy_TombProtector_QBUpdateDataAsset;

UCLASS(Blueprintable)
class UEnemy_TombProtector_QBUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_TombProtector_QBUpdate();
    UFUNCTION(BlueprintCallable)
    static void SetSpawnPoints(const TArray<FVector>& InLocArray);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpawnAnchor(const FVector& InLoc);
    
    UFUNCTION(BlueprintCallable)
    static void SetDataAsset(UEnemy_TombProtector_QBUpdateDataAsset* InDataAsset);
    
};

