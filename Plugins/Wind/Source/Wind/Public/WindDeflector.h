#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindDeflector.generated.h"

class UWindDeflectorComponent;

UCLASS(Blueprintable)
class WIND_API AWindDeflector : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindDeflectorComponent* Component;
    
public:
    AWindDeflector(const FObjectInitializer& ObjectInitializer);
};

