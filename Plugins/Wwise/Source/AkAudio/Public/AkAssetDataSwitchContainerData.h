#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAssetDataSwitchContainerData.generated.h"

class UAkAssetDataSwitchContainerData;
class UAkGroupValue;
class UAkMediaAsset;

UCLASS(Blueprintable, EditInlineNew)
class AKAUDIO_API UAkAssetDataSwitchContainerData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAkGroupValue> GroupValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkGroupValue* DefaultGroupValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkMediaAsset*> MediaList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAkAssetDataSwitchContainerData*> Children;
    
    UAkAssetDataSwitchContainerData();
};

