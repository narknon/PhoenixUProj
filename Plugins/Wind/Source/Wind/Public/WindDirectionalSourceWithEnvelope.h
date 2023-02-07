#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindDirectionalSourceWithEnvelope.generated.h"

class UWindDirectionalSourceWithEnvelopeComponent;

UCLASS(Blueprintable)
class WIND_API AWindDirectionalSourceWithEnvelope : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindDirectionalSourceWithEnvelopeComponent* Component;
    
public:
    AWindDirectionalSourceWithEnvelope();
};

