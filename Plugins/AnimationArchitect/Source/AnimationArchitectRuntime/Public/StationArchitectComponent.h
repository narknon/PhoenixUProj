#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectComponent.h"
#include "StationArchitectComponent.generated.h"

class UStationArchitectAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATIONARCHITECTRUNTIME_API UStationArchitectComponent : public UBaseArchitectComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStationArchitectAsset>> HardSceneRigAssets;
    
public:
    UStationArchitectComponent();
};

