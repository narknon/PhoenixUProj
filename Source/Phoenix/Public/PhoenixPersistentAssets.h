#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "PhoenixPersistentAssets.generated.h"

UCLASS(Blueprintable)
class UPhoenixPersistentAssets : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSoftObjectPath> AssetPaths;
    
    UPhoenixPersistentAssets();
};

