#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WindPointSourceWithEnvelope.generated.h"

class UWindPointSourceWithEnvelopeComponent;

UCLASS(Blueprintable)
class WIND_API AWindPointSourceWithEnvelope : public AInfo {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindPointSourceWithEnvelopeComponent* Component;
    
public:
    AWindPointSourceWithEnvelope();
};

