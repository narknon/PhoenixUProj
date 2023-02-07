#pragma once
#include "CoreMinimal.h"
#include "MinimapBase.h"
#include "MinimapTutorial.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapTutorial : public UMinimapBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BlackTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MapTexture;
    
public:
    UMinimapTutorial();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

