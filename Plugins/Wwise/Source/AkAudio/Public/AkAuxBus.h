#pragma once
#include "CoreMinimal.h"
#include "AkAssetBase.h"
#include "AkAuxBus.generated.h"

class UAkAudioBank;

UCLASS(Blueprintable)
class AKAUDIO_API UAkAuxBus : public UAkAssetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioBank* RequiredBank;
    
    UAkAuxBus();
};

