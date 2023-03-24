#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightMasterComputeOnly.generated.h"

class UDayNightMasterComponent;

UCLASS(Blueprintable)
class DAYNIGHT_API ADayNightMasterComputeOnly : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDayNightMasterComponent* DayNightMaster;
    
    ADayNightMasterComputeOnly(const FObjectInitializer& ObjectInitializer);
};

