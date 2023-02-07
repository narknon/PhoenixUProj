#pragma once
#include "CoreMinimal.h"
#include "AkEventCallbackInfo.h"
#include "AkMarkerCallbackInfo.generated.h"

UCLASS(Blueprintable)
class UAkMarkerCallbackInfo : public UAkEventCallbackInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Identifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Label;
    
    UAkMarkerCallbackInfo();
};

