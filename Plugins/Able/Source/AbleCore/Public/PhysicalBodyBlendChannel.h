#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhysicalBodyBlendChannel.generated.h"

class UPhysicalBodyBlendInfo;

UCLASS(Blueprintable)
class UPhysicalBodyBlendChannel : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> ChannelBlendedWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> ChannelFadeWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalBodyBlendInfo*> PhysicalBodyBlendArray;
    
    UPhysicalBodyBlendChannel();
};

