#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MiniMapPerceptionIcons.generated.h"

class UMapSubSystem;
class UMinimapBase;
class UMinimapManager;
class UPerceptionDrawQueueItem;
class UPerceptionIconData;
class UPerceptionTextureCacheItem;
class UTexture2D;
class UTextureUtil;

UCLASS(Blueprintable)
class UMiniMapPerceptionIcons : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPerceptionIconData*> PerceptionIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPerceptionTextureCacheItem*> PerceptionTextureCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPerceptionDrawQueueItem*> DrawQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureUtil* TextureBlitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* OverlayTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapSubSystem* MapSubSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapManager* MinimapManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapBase* Minimap;
    
public:
    UMiniMapPerceptionIcons();
};

