#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindTrueNorth.generated.h"

class UWindTrueNorthComponent;

UCLASS(Blueprintable)
class WIND_API AWindTrueNorth : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindTrueNorthComponent* Component;
    
public:
    AWindTrueNorth();
};

