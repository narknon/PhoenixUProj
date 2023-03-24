#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightMaster.generated.h"

class UDayNightMasterComponent;

UCLASS(Blueprintable)
class DAYNIGHT_API ADayNightMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDayNightMasterComponent* DayNightMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoFindSkyActor;
    
    ADayNightMaster(const FObjectInitializer& ObjectInitializer);
};

