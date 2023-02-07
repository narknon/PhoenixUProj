#pragma once
#include "CoreMinimal.h"
#include "AkCodecId.h"
#include "AkExternalSourceInfo.generated.h"

class UAkExternalMediaAsset;

USTRUCT(BlueprintType)
struct FAkExternalSourceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ExternalSrcName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AkCodecId CodecID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Filename;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkExternalMediaAsset* ExternalSourceAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsStreamed;
    
    AKAUDIO_API FAkExternalSourceInfo();
};

