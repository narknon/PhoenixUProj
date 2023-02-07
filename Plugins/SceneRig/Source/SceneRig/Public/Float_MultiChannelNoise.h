#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "FloatMultiChannelNoiseChannel.h"
#include "Float_MultiChannelNoise.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UFloat_MultiChannelNoise : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFloatMultiChannelNoiseChannel> Channels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UFloat_MultiChannelNoise();
};

