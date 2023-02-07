#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HousePointsHourglass.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class AHousePointsHourglass : public AActor {
    GENERATED_BODY()
public:
    AHousePointsHourglass();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateFinalHouseScore(TMap<FString, UStaticMeshComponent*> Houses);
    
    UFUNCTION(BlueprintCallable)
    void CheckHousesScore(TMap<FString, UStaticMeshComponent*> Houses);
    
};

