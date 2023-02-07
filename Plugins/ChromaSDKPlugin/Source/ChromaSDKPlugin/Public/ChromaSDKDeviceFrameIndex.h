#pragma once
#include "CoreMinimal.h"
#include "ChromaSDKDeviceFrameIndex.generated.h"

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKDeviceFrameIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> FrameIndex;
    
    FChromaSDKDeviceFrameIndex();
};

