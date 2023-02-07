#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TextureFilterRow.h"
#include "TextureFilterDataAsset.generated.h"

class UTexture;

UCLASS(Blueprintable)
class UTextureFilterDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UTexture>, FTextureFilterRow> Filters;
    
    UTextureFilterDataAsset();
};

