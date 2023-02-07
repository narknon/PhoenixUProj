#pragma once
#include "CoreMinimal.h"
#include "AkAssetData.h"
#include "AkAssetDataWithMedia.generated.h"

class UAkMediaAsset;

UCLASS(Blueprintable)
class AKAUDIO_API UAkAssetDataWithMedia : public UAkAssetData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkMediaAsset*> MediaList;
    
    UAkAssetDataWithMedia();
};

