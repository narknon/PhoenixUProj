#pragma once
#include "CoreMinimal.h"
#include "AkAssetDataWithMedia.h"
#include "AkPluginInfo.h"
#include "AkInitBankAssetData.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkInitBankAssetData : public UAkAssetDataWithMedia {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAkPluginInfo> PluginInfos;
    
    UAkInitBankAssetData();
};

