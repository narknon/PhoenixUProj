#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PerceptionTextureCacheItem.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class UPerceptionTextureCacheItem : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPerceptionTextureCacheItem();
};

