#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MinimapBase.h"
#include "MinimapHogsmeade.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapHogsmeade : public UMinimapBase {
    GENERATED_BODY()
public:
    UMinimapHogsmeade();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetTopLeftBound();
    
    UFUNCTION(BlueprintCallable)
    FVector GetDebugPlayerOffset();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetBottomRightBound();
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

