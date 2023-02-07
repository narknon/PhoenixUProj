#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryMiniMapType.h"
#include "MinimapBase.h"
#include "MinimapSanctuary.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapSanctuary : public UMinimapBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BlackTexture;
    
public:
    UMinimapSanctuary();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void SetMapType(ESanctuaryMiniMapType::Type MapType, bool LoadNavMesh, bool fromInit);
    
    UFUNCTION(BlueprintCallable)
    void SetHubLevelUnlock(const FString& NameOfUnlock, bool LoadTexture, bool FromLoadGame);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

