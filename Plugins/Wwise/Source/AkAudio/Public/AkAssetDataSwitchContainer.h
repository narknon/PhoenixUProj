#pragma once
#include "CoreMinimal.h"
#include "AkAssetDataWithMedia.h"
#include "AkAssetDataSwitchContainer.generated.h"

class UAkAssetDataSwitchContainerData;
class UAkGroupValue;

UCLASS(Blueprintable)
class AKAUDIO_API UAkAssetDataSwitchContainer : public UAkAssetDataWithMedia {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAssetDataSwitchContainerData*> SwitchContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkGroupValue* DefaultGroupValue;
    
    UAkAssetDataSwitchContainer();
};

