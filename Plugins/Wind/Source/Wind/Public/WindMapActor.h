#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindMapActor.generated.h"

class UWindMapComponent;

UCLASS(Blueprintable)
class WIND_API AWindMapActor : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindMapComponent* Component;
    
public:
    AWindMapActor(const FObjectInitializer& ObjectInitializer);
};

