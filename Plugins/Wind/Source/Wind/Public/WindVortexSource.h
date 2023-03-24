#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindVortexSource.generated.h"

class UWindSourceVortexComponent;

UCLASS(Blueprintable)
class WIND_API AWindVortexSource : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindSourceVortexComponent* Component;
    
public:
    AWindVortexSource(const FObjectInitializer& ObjectInitializer);
};

