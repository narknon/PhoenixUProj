#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "AnimLayersAssetUserData.generated.h"

class UAnimLayersAsset;

UCLASS(Blueprintable, EditInlineNew)
class AVAANIMATION_API UAnimLayersAssetUserData : public UAssetUserData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimLayersAsset* AnimLayers;
    
    UAnimLayersAssetUserData();
};

