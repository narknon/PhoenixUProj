#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkMediaAssetData.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkMediaAssetData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsStreamed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseDeviceMemory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Language;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AssetPlatform;
    
    UAkMediaAssetData();
};

