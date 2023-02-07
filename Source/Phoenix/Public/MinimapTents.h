#pragma once
#include "CoreMinimal.h"
#include "MinimapBase.h"
#include "MinimapTents.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapTents : public UMinimapBase {
    GENERATED_BODY()
public:
    UMinimapTents();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

