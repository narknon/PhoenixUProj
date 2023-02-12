#pragma once
#include "CoreMinimal.h"
#include "AkCallbackInfo.h"
#include "AkEventCallbackInfo.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkEventCallbackInfo : public UAkCallbackInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayingID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EventID;
    
    UAkEventCallbackInfo();
};

