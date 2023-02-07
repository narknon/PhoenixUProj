#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkCallbackInfo.generated.h"

class UAkComponent;

UCLASS(Blueprintable)
class AKAUDIO_API UAkCallbackInfo : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UAkCallbackInfo();
};

