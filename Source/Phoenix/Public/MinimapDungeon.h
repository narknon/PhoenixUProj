#pragma once
#include "CoreMinimal.h"
#include "MinimapBase.h"
#include "MinimapDungeon.generated.h"

class UMapDungeon;
class UObject;
class UTexture2D;
class UTextureUtil;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapDungeon : public UMinimapBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BlackTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapDungeon* DungeonMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureUtil* DungeonTextureBlitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MapTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RevealTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SeenTexture;
    
public:
    UMinimapDungeon();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

