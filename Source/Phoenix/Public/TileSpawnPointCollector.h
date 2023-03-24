#pragma once
#include "CoreMinimal.h"
#include "CustomButtonWidget.h"
#include "GameFramework/Actor.h"
#include "TileSpawnPointCollector.generated.h"

UCLASS(Blueprintable)
class ATileSpawnPointCollector : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomButtonWidget UpdateSpawnLocationsDBButton;
    
    ATileSpawnPointCollector(const FObjectInitializer& ObjectInitializer);
};

