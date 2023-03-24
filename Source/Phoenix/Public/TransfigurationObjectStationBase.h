#pragma once
#include "CoreMinimal.h"
#include "Station.h"
#include "TransfigurationObjectStationBase.generated.h"

class UCognitionStimuliSourceComponent;

UCLASS(Abstract, Blueprintable)
class ATransfigurationObjectStationBase : public AStation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CogSourceComponent;
    
    ATransfigurationObjectStationBase(const FObjectInitializer& ObjectInitializer);
};

