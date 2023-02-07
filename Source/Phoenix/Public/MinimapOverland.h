#pragma once
#include "CoreMinimal.h"
#include "MinimapBase.h"
#include "MinimapOverland.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapOverland : public UMinimapBase {
    GENERATED_BODY()
public:
    UMinimapOverland();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
};

