#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HoudiniAsset.generated.h"

class UThumbnailInfo;

UCLASS(Blueprintable, EditInlineNew)
class HOUDINIENGINERUNTIME_API UHoudiniAsset : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AssetFileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UThumbnailInfo* ThumbnailInfo;
    
    UHoudiniAsset();
};

