#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "PoseNamesAssetUserData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class CUSTOMIZABLECHARACTER_API UPoseNamesAssetUserData : public UAssetUserData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PoseNames;
    
    UPoseNamesAssetUserData();
};

